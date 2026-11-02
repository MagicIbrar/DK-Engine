// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x890000-0x89ffff

// ==== FUN_00890060 @ 0x00890060 ====

void FUN_00890060(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_00a14fd8;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_00890080 @ 0x00890080 ====

undefined4 FUN_00890080(void)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  int *local_10;
  int local_c;
  undefined4 *local_8;
  int local_4;
  
  iVar1 = *(int *)(in_ECX + 8);
  local_10 = (int *)0x0;
  if (0 < *(int *)(iVar1 + 0x40)) {
    local_c = 0;
    iVar6 = iVar1 + 0x60;
    iVar5 = iVar1;
    local_4 = in_ECX;
    do {
      iVar5 = local_c + iVar5;
      *(undefined4 *)(iVar5 + 0x10) = 0;
      *(undefined4 *)(iVar5 + 0x18) = 0;
      local_8 = (undefined4 *)(iVar5 + 0x1c);
      *(undefined4 *)(iVar5 + 0x14) = 0;
      *local_8 = 0;
      if ((*(int *)(iVar6 + -8) != 0) &&
         (cVar3 = FUN_00890d30(*(undefined4 *)(iVar1 + 0x44),*(undefined4 *)(iVar1 + 0x48),0,2,
                               (undefined4 *)(iVar5 + 0x10),iVar6 + -4,iVar6,iVar5), cVar3 == '\0'))
      {
        return 0;
      }
      if ((*(int *)(iVar6 + 4) != 0) &&
         (cVar3 = FUN_00890d30(*(undefined4 *)(iVar1 + 0x4c),*(undefined4 *)(iVar1 + 0x50),0,2,
                               (undefined4 *)(iVar5 + 0x14),iVar6 + 8,iVar6 + 0xc,iVar5 + 4),
         cVar3 == '\0')) {
        return 0;
      }
      if ((*(int *)(iVar6 + 0x10) != 0) &&
         (cVar3 = FUN_00890d30(*(undefined4 *)(iVar1 + 0x4c),*(undefined4 *)(iVar1 + 0x50),0,2,
                               iVar5 + 0x18,iVar6 + 0x14,iVar6 + 0x18,iVar5 + 8), cVar3 == '\0')) {
        return 0;
      }
      if ((*(int *)(iVar6 + 0x1c) != 0) &&
         (cVar3 = FUN_00890d30(*(undefined4 *)(iVar1 + 0x44),*(undefined4 *)(iVar1 + 0x48),0,2,
                               local_8,iVar6 + 0x20,iVar6 + 0x24,iVar5 + 0xc), cVar3 == '\0')) {
        return 0;
      }
      iVar5 = *(int *)(local_4 + 8);
      local_10 = (int *)((int)local_10 + 1);
      local_c = local_c + 0x20;
      iVar6 = iVar6 + 0x30;
      in_ECX = local_4;
    } while ((int)local_10 < *(int *)(iVar5 + 0x40));
  }
  iVar6 = *(int *)(in_ECX + 8);
  *(undefined4 *)(iVar6 + 200) = 0;
  *(undefined4 *)(iVar6 + 0xd0) = 0;
  *(undefined4 *)(iVar6 + 0xcc) = 0;
  *(undefined4 *)(iVar6 + 0xd4) = 0;
  if (*(int *)(iVar1 + 0x58) != 0) {
    local_c = *(int *)(iVar1 + 0x48);
    iVar5 = *(int *)(iVar1 + 0x44);
    piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    local_10 = (int *)0x0;
    iVar4 = (**(code **)(*piVar2 + 0x5c))(piVar2,iVar5,local_c,1,0x200,0x32,0,&local_10,0);
    if (iVar4 < 0) goto LAB_00890331;
    *(int **)(iVar6 + 200) = local_10;
    *(int *)(iVar6 + 0xb8) = iVar5 * local_c;
  }
  if (*(int *)(iVar1 + 100) != 0) {
    local_c = *(int *)(iVar1 + 0x50);
    iVar5 = *(int *)(iVar1 + 0x4c);
    piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    local_10 = (int *)0x0;
    iVar4 = (**(code **)(*piVar2 + 0x5c))(piVar2,iVar5,local_c,1,0x200,0x32,0,&local_10,0);
    if (iVar4 < 0) goto LAB_00890331;
    *(int **)(iVar6 + 0xcc) = local_10;
    *(int *)(iVar6 + 0xbc) = iVar5 * local_c;
  }
  if (*(int *)(iVar1 + 0x70) != 0) {
    local_c = *(int *)(iVar1 + 0x50);
    iVar5 = *(int *)(iVar1 + 0x4c);
    piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    local_10 = (int *)0x0;
    iVar4 = (**(code **)(*piVar2 + 0x5c))(piVar2,iVar5,local_c,1,0x200,0x32,0,&local_10,0);
    if (iVar4 < 0) goto LAB_00890331;
    *(int **)(iVar6 + 0xd0) = local_10;
    *(int *)(iVar6 + 0xc0) = iVar5 * local_c;
  }
  if (*(int *)(iVar1 + 0x7c) != 0) {
    iVar5 = *(int *)(iVar1 + 0x48);
    iVar1 = *(int *)(iVar1 + 0x44);
    piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    local_10 = (int *)0x0;
    iVar4 = (**(code **)(*piVar2 + 0x5c))(piVar2,iVar1,iVar5,1,0x200,0x32,0,&local_10,0);
    if (iVar4 < 0) {
LAB_00890331:
      if (local_10 != (int *)0x0) {
        (**(code **)(*local_10 + 8))(local_10);
      }
      return 0;
    }
    *(int **)(iVar6 + 0xd4) = local_10;
    *(int *)(iVar6 + 0xc4) = iVar1 * iVar5;
  }
  return 1;
}


// ==== FUN_00890350 @ 0x00890350 ====

void FUN_00890350(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  int local_c [3];
  
  local_c[0] = *(int *)(in_ECX + 8);
  local_c[1] = local_c[0] + 0x20;
  local_c[2] = local_c[0] + 0xb8;
  uVar3 = 0;
  do {
    iVar1 = local_c[uVar3];
    piVar2 = *(int **)(iVar1 + 0x10);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(iVar1 + 0x10) = 0;
    }
    piVar2 = *(int **)(iVar1 + 0x14);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(iVar1 + 0x14) = 0;
    }
    piVar2 = *(int **)(iVar1 + 0x18);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(iVar1 + 0x18) = 0;
    }
    piVar2 = *(int **)(iVar1 + 0x1c);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 3);
  return;
}


// ==== FUN_008903d0 @ 0x008903d0 ====

void FUN_008903d0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 unaff_ESI;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uStack_38;
  undefined4 *puStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined1 auStack_1e [2];
  undefined4 local_10;
  undefined4 uStack_c;
  undefined1 auStack_8 [4];
  
  iVar2 = *(int *)(in_ECX + 8);
  iVar1 = *(int *)(iVar2 + 0x54);
  iVar3 = 0;
  if (0 < *(int *)(iVar2 + 0x40)) {
    puVar6 = (undefined4 *)(iVar2 + 0x14);
    puVar4 = (undefined4 *)(iVar2 + 0x60);
    do {
      puStack_34 = &local_10;
      iVar5 = (-(uint)(iVar3 != iVar1) & 0xffff8010) + 0x8000;
      uStack_30 = 0;
      uStack_38 = 0;
      iStack_2c = iVar5;
      iVar2 = (**(code **)(*(int *)puVar6[-1] + 0x4c))((int *)puVar6[-1]);
      if (-1 < iVar2) {
        puVar4[-1] = auStack_8 + 4;
        *puVar4 = unaff_ESI;
      }
      iVar2 = (**(code **)(*(int *)*puVar6 + 0x4c))((int *)*puVar6,0,auStack_1e + -6,0,iVar5);
      if (-1 < iVar2) {
        puVar4[2] = puStack_34;
        puVar4[3] = uStack_38;
      }
      iVar2 = (**(code **)(*(int *)puVar6[1] + 0x4c))((int *)puVar6[1],0,&uStack_38,0,iVar5);
      if (-1 < iVar2) {
        puVar4[5] = uStack_c;
        puVar4[6] = local_10;
      }
      if (puVar6[2] != 0) {
        uStack_30 = 0;
        puStack_34 = &local_10;
        uStack_38 = 0;
        iStack_2c = iVar5;
        iVar2 = (**(code **)(*(int *)puVar6[2] + 0x4c))((int *)puVar6[2]);
        if (-1 < iVar2) {
          puVar4[8] = uStack_c;
          puVar4[9] = local_10;
        }
      }
      iVar3 = iVar3 + 1;
      puVar6 = puVar6 + 8;
      puVar4 = puVar4 + 0xc;
    } while (iVar3 < *(int *)(*(int *)(in_ECX + 8) + 0x40));
  }
  return;
}


// ==== FUN_008904d0 @ 0x008904d0 ====

void FUN_008904d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    _BinkClose_4(*(int *)(in_ECX + 0xc));
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  if (*(int *)(in_ECX + 8) != 0) {
    FUN_00890350();
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_00890500 @ 0x00890500 ====

void FUN_00890500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14fd8;
  if (in_ECX[3] != 0) {
    _BinkClose_4(in_ECX[3]);
    in_ECX[3] = 0;
  }
  if (in_ECX[2] != 0) {
    FUN_00890350();
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_FUN_00a14f38;
  return;
}


// ==== FUN_00890540 @ 0x00890540 ====

undefined4
FUN_00890540(uint param_1,void *param_2,uint param_3,undefined4 param_4,uint param_5,
            undefined4 param_6,uint param_7)

{
  char cVar1;
  undefined4 extraout_EAX;
  int iVar2;
  undefined4 extraout_EAX_00;
  undefined4 *puVar3;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  int in_ECX;
  void *unaff_EBX;
  undefined4 *puVar4;
  undefined1 *unaff_retaddr;
  code *_Memory;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    if (param_7 < 0x10) {
      return 0;
    }
    _free(param_2);
    return extraout_EAX;
  }
  _Memory = _BinkOpenDirectSound_4_exref;
  _BinkSetSoundSystem_8(_BinkOpenDirectSound_4_exref,0);
  if (param_5 < 0x10) {
    unaff_retaddr = (undefined1 *)register0x00000010;
  }
  iVar2 = _BinkOpen_8(unaff_retaddr,0x4400);
  *(int *)(in_ECX + 0xc) = iVar2;
  if (iVar2 == 0) {
    if (0xf < param_3) {
      _free(unaff_EBX);
      return extraout_EAX_00;
    }
  }
  else {
    FUN_0088feb0();
    puVar3 = operator_new(0xd8);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar4 = puVar3;
      for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
    *(undefined4 **)(in_ECX + 8) = puVar3;
    _BinkGetFrameBuffersInfo_8(*(undefined4 *)(in_ECX + 0xc),puVar3 + 0x10);
    cVar1 = FUN_00890080();
    if (cVar1 != '\0') {
      if (param_1 < 0x10) {
        return 1;
      }
      _free(_Memory);
      return extraout_EAX_02;
    }
    if (0xf < param_1) {
      _free(_Memory);
      return extraout_EAX_01;
    }
  }
  return 0;
}


// ==== FUN_00890630 @ 0x00890630 ====

void FUN_00890630(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int unaff_EBX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uStack_1c;
  int local_18;
  int local_14;
  int iStack_10;
  int iStack_c;
  
  local_14 = FUN_0049b670();
  iVar2 = *(int *)(in_ECX + 8);
  iVar3 = 0;
  if (0 < *(int *)(iVar2 + 0x40)) {
    puVar5 = (undefined4 *)(iVar2 + 0x68);
    puVar4 = (undefined4 *)(iVar2 + 0x14);
    do {
      (**(code **)(*(int *)puVar4[-1] + 0x50))((int *)puVar4[-1],0);
      puVar5[-3] = 0;
      (**(code **)(*(int *)*puVar4 + 0x50))((int *)*puVar4,0);
      *puVar5 = 0;
      (**(code **)(*(int *)puVar4[1] + 0x50))((int *)puVar4[1],0);
      puVar5[3] = 0;
      if (puVar4[2] != 0) {
        (**(code **)(*(int *)puVar4[2] + 0x50))((int *)puVar4[2],0);
        puVar5[6] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 8;
      puVar5 = puVar5 + 0xc;
    } while (iVar3 < *(int *)(*(int *)(in_ECX + 8) + 0x40));
  }
  local_18 = *(int *)(in_ECX + 8);
  iVar3 = *(int *)(local_18 + 0x54) * 0x20 + local_18;
  iVar2 = _BinkGetRects_8(*(undefined4 *)(in_ECX + 0xc),0);
  if (0 < iVar2) {
    iVar6 = 0;
    do {
      piVar1 = (int *)(iVar6 + 0x34 + *(int *)(in_ECX + 0xc));
      local_18 = *piVar1;
      local_14 = piVar1[1];
      iStack_10 = piVar1[2] + local_18;
      iStack_c = piVar1[3] + local_14;
      (**(code **)(**(int **)(iVar3 + 0x10) + 0x54))(*(int **)(iVar3 + 0x10),&local_18);
      if (*(int *)(iVar3 + 0x1c) != 0) {
        (**(code **)(**(int **)(iVar3 + 0x1c) + 0x54))
                  (*(int **)(iVar3 + 0x1c),(int)register0x00000010 + -0x20);
      }
      unaff_EBX = unaff_EBX >> 1;
      uStack_1c = (int *)((int)uStack_1c >> 1);
      local_18 = local_18 >> 1;
      local_14 = local_14 >> 1;
      (**(code **)(**(int **)(iVar3 + 0x14) + 0x54))
                (*(int **)(iVar3 + 0x14),(int)register0x00000010 + -0x20);
      (**(code **)(**(int **)(iVar3 + 0x18) + 0x54))
                (*(int **)(iVar3 + 0x18),(int)register0x00000010 + -0x28);
      iVar6 = iVar6 + 0x10;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    (**(code **)(*uStack_1c + 0x7c))
              (uStack_1c,*(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(unaff_EBX + 200));
    (**(code **)(*uStack_1c + 0x7c))
              (uStack_1c,*(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(unaff_EBX + 0xcc));
    (**(code **)(*uStack_1c + 0x7c))
              (uStack_1c,*(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(unaff_EBX + 0xd0));
    if (*(int *)(iVar3 + 0x1c) != 0) {
      (**(code **)(*uStack_1c + 0x7c))
                (uStack_1c,*(int *)(iVar3 + 0x1c),*(undefined4 *)(unaff_EBX + 0xd4));
    }
  }
  return;
}


// ==== FUN_008907c0 @ 0x008907c0 ====

void FUN_008907c0(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_008903d0();
  _BinkRegisterFrameBuffers_8(*(undefined4 *)(in_ECX + 0xc),*(int *)(in_ECX + 8) + 0x40);
  _BinkDoFrame_4(*(undefined4 *)(in_ECX + 0xc));
  iVar1 = _BinkShouldSkip_4(*(undefined4 *)(in_ECX + 0xc));
  if (iVar1 != 0) {
    _BinkNextFrame_4(*(undefined4 *)(in_ECX + 0xc));
    _BinkDoFrame_4(*(undefined4 *)(in_ECX + 0xc));
  }
  FUN_00890630();
  _BinkNextFrame_4(*(undefined4 *)(in_ECX + 0xc));
  return;
}


// ==== FUN_00890820 @ 0x00890820 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00890820(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  float fStack_34;
  undefined4 uStack_30;
  
  uStack_30 = 0x10;
  fStack_34 = 1.2584417e-38;
  iVar2 = FUN_0085e3a0();
  uStack_30 = 0x89084c;
  piVar3 = (int *)FUN_0049b670();
  iVar4 = *(int *)(in_ECX + 8);
  uStack_30 = *(undefined4 *)(iVar4 + 200);
  iVar5 = *(int *)(iVar2 + 0x28);
  if ((iVar5 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar5 >> 2) < 0x86)) {
                    /* WARNING: Subroutine does not return */
    uStack_30 = 0x890888;
    FUN_0085b340();
  }
  fStack_34 = *(float *)(iVar5 + 0x214);
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0xd0))(*(int **)(iVar2 + 0x1c));
  iVar5 = *(int *)(iVar2 + 0x28);
  if ((iVar5 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar5 >> 2) < 0x87)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0xd0))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar5 + 0x218),*(undefined4 *)(iVar4 + 0xcc));
  iVar5 = *(int *)(iVar2 + 0x28);
  uStack_30 = *(undefined4 *)(iVar4 + 0xd0);
  if ((iVar5 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar5 >> 2) < 0x88)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  iVar5 = *(int *)(iVar5 + 0x21c);
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0xd0))(*(int **)(iVar2 + 0x1c),iVar5,uStack_30);
  fStack_34 = DAT_0099d080;
  uStack_30 = 0;
  if ((*(int *)(iVar2 + 0x28) == 0) ||
     ((uint)(*(int *)(iVar2 + 0x2c) - *(int *)(iVar2 + 0x28) >> 2) < 0x8d)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x88))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(*(int *)(iVar2 + 0x28) + 0x230),&fStack_34);
  if (*(int *)(iVar5 + 0x1c) == 0) {
    (**(code **)(**(int **)(iVar2 + 0x1c) + 0xf0))
              (*(int **)(iVar2 + 0x1c),s_YCrCbToRGBNoAlpha_00a14fa0);
  }
  else {
    iVar5 = *(int *)(iVar2 + 0x28);
    if ((iVar5 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar5 >> 2) < 0x89)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar2 + 0x1c) + 0xd0))
              (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar5 + 0x220),*(undefined4 *)(iVar4 + 0xd4))
    ;
    iVar4 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar4 + 0x114) != 2) ||
        ((*(int *)(iVar4 + 0x118) != 5 || (*(int *)(iVar4 + 0x11c) != 6)))) &&
       (*(int *)(iVar4 + 100) == 0)) {
      (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x1b,1);
      (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0xf,1);
      (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x19,5);
      (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x18,1);
      (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x13,5);
      (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x14,6);
      *(undefined4 *)(iVar4 + 0x114) = 2;
      *(undefined4 *)(iVar4 + 0x118) = 5;
      *(undefined4 *)(iVar4 + 0x11c) = 6;
    }
    (**(code **)(**(int **)(iVar2 + 0x1c) + 0xf0))(*(int **)(iVar2 + 0x1c),s_YCrCbToRGB_00a14fb4);
  }
  iVar4 = *(int *)(DAT_00b5ac04 + 0x28);
  if (fStack_34 < _DAT_00a14fec) {
    if ((((*(int *)(iVar4 + 0x114) == 2) && (*(int *)(iVar4 + 0x118) == 5)) &&
        (*(int *)(iVar4 + 0x11c) == 6)) || (*(int *)(iVar4 + 100) != 0)) goto LAB_00890bfd;
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x14,6);
    *(undefined4 *)(iVar4 + 0x114) = 2;
  }
  else {
    if ((((*(int *)(iVar4 + 0x114) == 0) && (*(int *)(iVar4 + 0x118) == 5)) &&
        (*(int *)(iVar4 + 0x11c) == 6)) || (*(int *)(iVar4 + 100) != 0)) goto LAB_00890bfd;
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x1b,0);
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0xf,0);
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x14,6);
    *(undefined4 *)(iVar4 + 0x114) = 0;
  }
  *(undefined4 *)(iVar4 + 0x118) = 5;
  *(undefined4 *)(iVar4 + 0x11c) = 6;
LAB_00890bfd:
  FUN_00858a60();
  iVar4 = 0x104;
  (**(code **)(*piVar3 + 0x164))(piVar3,0x104);
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x104))(*(int **)(iVar2 + 0x1c),0,0);
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x108))(*(int **)(iVar2 + 0x1c),0);
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0x14c))(piVar1,5,2,iVar4 + 0x10,0x18);
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x110))(*(int **)(iVar2 + 0x1c));
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x114))(*(int **)(iVar2 + 0x1c));
  (**(code **)(*piVar3 + 0x164))(piVar3,0);
  FUN_00858b90();
  (**(code **)(*piVar3 + 0x104))(piVar3,0,0);
  iVar4 = 1;
  (**(code **)(*piVar3 + 0x104))(piVar3,1,0);
  (**(code **)(*piVar3 + 0x104))(piVar3,2,0);
  if (*(int *)(iVar4 + 0x1c) != 0) {
    (**(code **)(*piVar3 + 0x104))(piVar3,3,0);
  }
  return;
}


// ==== FUN_00890ce0 @ 0x00890ce0 ====

void FUN_00890ce0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = _BinkWait_4(*(undefined4 *)(in_ECX + 0xc));
  if (iVar1 == 0) {
    piVar2 = (int *)FUN_0049b670();
    (**(code **)(*piVar2 + 0xac))(piVar2,0,0,1,0xffffffff,0x3f800000,0);
    FUN_008907c0();
    FUN_00890820(0x3f800000);
  }
  return;
}


// ==== FUN_00890d30 @ 0x00890d30 ====

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_00890d30(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 *unaff_ESI;
  undefined4 uVar3;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 **ppuStack_1c;
  undefined4 uStack_18;
  undefined4 *local_c;
  undefined4 *puStack_8;
  int *piStack_4;
  
  uStack_18 = 0;
  ppuStack_1c = &local_c;
  uStack_20 = param_4;
  uStack_24 = 0x32;
  uStack_28 = param_3;
  iStack_2c = 1;
  local_c = (undefined4 *)0x0;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x90) + 0x5c))(*(int **)(in_ECX + 0x90),param_1);
  puVar1 = local_c;
  if (iVar2 < 0) {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
    return 0;
  }
  *unaff_ESI = param_2;
  *piStack_4 = param_1 * (int)param_2;
  if ((local_c != (undefined4 *)0x0) && (puStack_8 != (undefined4 *)0x0)) {
    uVar3 = 0;
    iVar2 = (**(code **)(*param_2 + 0x4c))(param_2,0);
    if (iVar2 < 0) {
      return 0;
    }
    *puStack_8 = 0;
    *puVar1 = uVar3;
    (**(code **)(iStack_2c + 0x50))(&iStack_2c,0);
  }
  return 1;
}


// ==== FUN_00890de0 @ 0x00890de0 ====

void FUN_00890de0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14fd8;
  if (in_ECX[3] != 0) {
    _BinkClose_4(in_ECX[3]);
    in_ECX[3] = 0;
  }
  if (in_ECX[2] != 0) {
    FUN_00890350();
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_FUN_00a14f38;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00890e30 @ 0x00890e30 ====

void FUN_00890e30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15044;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00890e50 @ 0x00890e50 ====

float10 FUN_00890e50(int param_1,int param_2)

{
  return (float10)param_1 / (float10)param_2;
}


// ==== FUN_00890e60 @ 0x00890e60 ====

int FUN_00890e60(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00890e70 @ 0x00890e70 ====

void FUN_00890e70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15054;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_00a15044;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00890eb0 @ 0x00890eb0 ====

void FUN_00890eb0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  int in_ECX;
  int *piVar7;
  int *piStack_9c;
  float fStack_80;
  float fStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  float fStack_64;
  float fStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  float fStack_48;
  float fStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_c;
  float fStack_8;
  float fStack_4;
  
  piVar6 = (int *)FUN_0049b670();
  (**(code **)(*piVar6 + 0x10c))(piVar6,0,1,3);
  uVar5 = DAT_009a09bc;
  uVar4 = DAT_0099d080;
  piVar7 = *(int **)(in_ECX + 8);
  piVar1 = *(int **)(in_ECX + 0xc);
  if (piVar7 != piVar1) {
    do {
      iVar2 = *piVar7;
      uStack_78 = uVar5;
      uStack_74 = uVar4;
      uStack_70 = uStack_c;
      fStack_80 = (float)piVar7[1] + fStack_8;
      fStack_7c = (float)piVar7[2] + fStack_4;
      uStack_6c = *(undefined4 *)(iVar2 + 8);
      uStack_68 = *(undefined4 *)(iVar2 + 0xc);
      fStack_64 = (float)piVar7[3] + fStack_8;
      fStack_60 = (float)piVar7[2] + fStack_4;
      uStack_5c = uVar5;
      uStack_58 = uVar4;
      uStack_54 = uStack_c;
      uStack_50 = *(undefined4 *)(iVar2 + 0x10);
      uStack_4c = *(undefined4 *)(iVar2 + 0xc);
      fStack_48 = (float)piVar7[3] + fStack_8;
      fStack_44 = (float)piVar7[4] + fStack_4;
      uStack_40 = uVar5;
      uStack_3c = uVar4;
      uStack_38 = uStack_c;
      uStack_34 = *(undefined4 *)(iVar2 + 0x10);
      uStack_30 = *(undefined4 *)(iVar2 + 0x14);
      fStack_2c = (float)piVar7[1] + fStack_8;
      fStack_28 = (float)piVar7[4] + fStack_4;
      uStack_24 = uVar5;
      uStack_20 = uVar4;
      uStack_1c = uStack_c;
      uStack_18 = *(undefined4 *)(iVar2 + 8);
      uStack_14 = *(undefined4 *)(iVar2 + 0x14);
      iVar3 = *(int *)(DAT_00b5ac04 + 0x28);
      iVar2 = *(int *)(iVar2 + 4);
      if (*(int *)(iVar3 + 0x134) != iVar2) {
        *(int *)(iVar3 + 0x134) = iVar2;
        (**(code **)(**(int **)(iVar3 + 0x90) + 0x104))(*(int **)(iVar3 + 0x90),0,iVar2);
      }
      piVar6 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar6 + 0x14c))(piVar6,6,2,&fStack_80,0x1c);
      piVar7 = piVar7 + 5;
    } while (piVar7 != piVar1);
    piVar6 = piStack_9c;
  }
  (**(code **)(*piVar6 + 0x10c))(piVar6,0,1,4);
  return;
}


// ==== FUN_00891180 @ 0x00891180 ====

undefined4 * FUN_00891180(undefined4 param_1,int param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  undefined4 *in_ECX;
  int iVar10;
  undefined4 *puStack_3c;
  undefined1 local_38;
  undefined1 uStack_37;
  undefined2 uStack_36;
  undefined1 uStack_34;
  
  *in_ECX = &PTR_FUN_00a15054;
  iVar10 = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  uStack_36 = (undefined2)((uint)in_ECX >> 0x10);
  piVar7 = (int *)(**(code **)(*DAT_00b5d980 + 8))(param_1);
  if (0 < *(int *)(param_2 + 0x14)) {
    piVar1 = (int *)(param_2 + 4);
    do {
      cVar6 = FUN_00403d70();
      if (cVar6 == '\0') {
        local_38 = 0;
        if (*(uint *)(param_2 + 0x18) < 0x10) {
          piVar8 = piVar1;
        }
        else {
          piVar8 = (int *)*piVar1;
        }
        uStack_37 = *(undefined1 *)((int)piVar8 + iVar10);
      }
      else {
        if (*(uint *)(param_2 + 0x18) < 0x10) {
          piVar8 = piVar1;
        }
        else {
          piVar8 = (int *)*piVar1;
        }
        local_38 = *(undefined1 *)((int)piVar8 + iVar10);
        iVar10 = iVar10 + 1;
        if (*(uint *)(param_2 + 0x18) < 0x10) {
          uStack_37 = *(undefined1 *)((int)piVar1 + iVar10);
        }
        else {
          uStack_37 = *(undefined1 *)(*piVar1 + iVar10);
        }
      }
      iVar9 = (**(code **)(*DAT_00b5d988 + 4))
                        (CONCAT22(uStack_36,CONCAT11(uStack_37,local_38)),
                         CONCAT13(uStack_34,CONCAT21(uStack_36,uStack_37)),0);
      if (iVar9 != 0) {
        iVar4 = *piVar7;
        iVar5 = piVar7[1];
        fVar2 = *(float *)(iVar9 + 0x18);
        fVar3 = *(float *)(iVar9 + 0x1c);
        FUN_008918a0();
        piVar8 = DAT_00b5d980;
        FUN_008043d0((double)((fVar2 / fVar3) * (float)iVar4 * ((float)iVar5 / (float)iVar4)));
        (**(code **)(*piVar8 + 0xc))();
        in_ECX = puStack_3c;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(param_2 + 0x14));
  }
  if ((in_ECX[2] == 0) || ((int)(in_ECX[3] - in_ECX[2]) / 0x14 == 0)) {
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    return in_ECX;
  }
  in_ECX[5] = *(undefined4 *)(in_ECX[3] + -8);
  in_ECX[6] = *(undefined4 *)(in_ECX[3] + -4);
  return in_ECX;
}


// ==== FUN_008913a0 @ 0x008913a0 ====

int FUN_008913a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x14;
}


// ==== FUN_008913c0 @ 0x008913c0 ====

void FUN_008913c0(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
  }
  return;
}


// ==== FUN_008913f0 @ 0x008913f0 ====

int FUN_008913f0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a7d0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x14) {
    FUN_008913c0(param_3,param_1);
    param_3 = param_3 + 0x14;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00891456 @ 0x00891456 ====

void Catch_00891456(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00891460 @ 0x00891460 ====

void FUN_00891460(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a7e0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_008913c0(param_1,param_3);
    param_1 = param_1 + 0x14;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008914c6 @ 0x008914c6 ====

void Catch_008914c6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008914d0 @ 0x008914d0 ====

void FUN_008914d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008913f0(param_1,param_2,param_3);
  return;
}


// ==== FUN_008914f0 @ 0x008914f0 ====

int FUN_008914f0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00891460(param_1,param_2,param_3);
  return param_1 + param_2 * 0x14;
}


// ==== FUN_00891520 @ 0x00891520 ====

void FUN_00891520(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15054;
  if ((void *)in_ECX[2] != (void *)0x0) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_00a15044;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00891570 @ 0x00891570 ====

void FUN_00891570(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint extraout_ECX;
  undefined4 local_4c;
  undefined4 local_48;
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
  puStack_c = &LAB_0099a7f0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x58);
  local_4c = *param_3;
  local_48 = param_3[1];
  local_44 = param_3[2];
  local_40 = param_3[3];
  local_3c = param_3[4];
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x14;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x14;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x58);
    if (0xcccccccU - iVar2 < param_2) {
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
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x14;
    }
    if (local_20 < iVar2 + param_2) {
      if (0xccccccc - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x14;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_008913a0();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0x14;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_008914d0(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_008914f0(local_1c,param_2,&local_4c);
      FUN_008914d0(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x14;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0x14);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0x14) < param_2) {
      local_24 = param_2 * 0x14;
      FUN_008913f0(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_008914f0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x14,&local_4c)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_00433d80(param_1,*(int *)(in_ECX + 8) - local_24,&local_4c);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x14;
    uVar4 = FUN_008913f0(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00433df0(param_1,local_2c,local_28,local_38);
    FUN_00433d80(param_1,param_2 * 0x14 + param_1,&local_4c);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00891729 @ 0x00891729 ====

void Catch_00891729(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00891830 @ 0x00891830 ====

void FUN_00891830(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x14 != 0) {
      iVar1 = (param_2 - iVar1) / 0x14;
      goto LAB_00891875;
    }
  }
  iVar1 = 0;
LAB_00891875:
  FUN_00891570(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x14;
  return;
}


// ==== FUN_008918a0 @ 0x008918a0 ====

void FUN_008918a0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x14) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x14))) {
    FUN_00891830(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00891460(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x14;
  return;
}


// ==== FUN_00891930 @ 0x00891930 ====

int FUN_00891930(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00891940 @ 0x00891940 ====

void FUN_00891940(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a150b4;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_00a15044;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00891980 @ 0x00891980 ====

void FUN_00891980(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  int in_ECX;
  int *piVar7;
  int *piStack_9c;
  float fStack_80;
  float fStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  float fStack_64;
  float fStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  float fStack_48;
  float fStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_c;
  float fStack_8;
  float fStack_4;
  
  piVar6 = (int *)FUN_0049b670();
  (**(code **)(*piVar6 + 0x10c))(piVar6,0,1,3);
  uVar5 = DAT_009a09bc;
  uVar4 = DAT_0099d080;
  piVar7 = *(int **)(in_ECX + 8);
  piVar1 = *(int **)(in_ECX + 0xc);
  if (piVar7 != piVar1) {
    do {
      iVar2 = *piVar7;
      uStack_78 = uVar5;
      uStack_74 = uVar4;
      uStack_70 = uStack_c;
      fStack_80 = (float)piVar7[1] + fStack_8;
      fStack_7c = (float)piVar7[2] + fStack_4;
      uStack_6c = *(undefined4 *)(iVar2 + 8);
      uStack_68 = *(undefined4 *)(iVar2 + 0xc);
      fStack_64 = (float)piVar7[3] + fStack_8;
      fStack_60 = (float)piVar7[2] + fStack_4;
      uStack_5c = uVar5;
      uStack_58 = uVar4;
      uStack_54 = uStack_c;
      uStack_50 = *(undefined4 *)(iVar2 + 0x10);
      uStack_4c = *(undefined4 *)(iVar2 + 0xc);
      fStack_48 = (float)piVar7[3] + fStack_8;
      fStack_44 = (float)piVar7[4] + fStack_4;
      uStack_40 = uVar5;
      uStack_3c = uVar4;
      uStack_38 = uStack_c;
      uStack_34 = *(undefined4 *)(iVar2 + 0x10);
      uStack_30 = *(undefined4 *)(iVar2 + 0x14);
      fStack_2c = (float)piVar7[1] + fStack_8;
      fStack_28 = (float)piVar7[4] + fStack_4;
      uStack_24 = uVar5;
      uStack_20 = uVar4;
      uStack_1c = uStack_c;
      uStack_18 = *(undefined4 *)(iVar2 + 8);
      uStack_14 = *(undefined4 *)(iVar2 + 0x14);
      iVar3 = *(int *)(DAT_00b5ac04 + 0x28);
      iVar2 = *(int *)(iVar2 + 4);
      if (*(int *)(iVar3 + 0x134) != iVar2) {
        *(int *)(iVar3 + 0x134) = iVar2;
        (**(code **)(**(int **)(iVar3 + 0x90) + 0x104))(*(int **)(iVar3 + 0x90),0,iVar2);
      }
      piVar6 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar6 + 0x14c))(piVar6,6,2,&fStack_80,0x1c);
      piVar7 = piVar7 + 5;
    } while (piVar7 != piVar1);
    piVar6 = piStack_9c;
  }
  (**(code **)(*piVar6 + 0x10c))(piVar6,0,1,4);
  return;
}


// ==== FUN_00891c50 @ 0x00891c50 ====

undefined4 * FUN_00891c50(int param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char cVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined4 *in_ECX;
  undefined4 *puVar9;
  int iVar10;
  float10 fVar11;
  undefined4 *puStack_3c;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined2 uStack_2e;
  undefined1 uStack_2c;
  
  *in_ECX = &PTR_FUN_00a150b4;
  iVar10 = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  piVar6 = (int *)(**(code **)(*DAT_00b5d980 + 8))(param_1);
  puVar9 = in_ECX;
  if (0 < *(int *)(param_1 + 0x14)) {
    piVar1 = (int *)(param_1 + 4);
    do {
      cVar5 = FUN_00403d70();
      if (cVar5 == '\0') {
        uStack_30 = 0;
        if (*(uint *)(param_1 + 0x18) < 0x10) {
          piVar7 = piVar1;
        }
        else {
          piVar7 = (int *)*piVar1;
        }
        uStack_2f = *(undefined1 *)((int)piVar7 + iVar10);
      }
      else {
        if (*(uint *)(param_1 + 0x18) < 0x10) {
          piVar7 = piVar1;
        }
        else {
          piVar7 = (int *)*piVar1;
        }
        uStack_30 = *(undefined1 *)((int)piVar7 + iVar10);
        iVar10 = iVar10 + 1;
        if (*(uint *)(param_1 + 0x18) < 0x10) {
          uStack_2f = *(undefined1 *)((int)piVar1 + iVar10);
        }
        else {
          uStack_2f = *(undefined1 *)(*piVar1 + iVar10);
        }
      }
      iVar8 = (**(code **)(*DAT_00b5d988 + 4))
                        (CONCAT22(uStack_2e,CONCAT11(uStack_2f,uStack_30)),
                         CONCAT13(uStack_2c,CONCAT21(uStack_2e,uStack_2f)),1);
      if (iVar8 != 0) {
        fVar11 = (float10)FUN_00890e50(piVar6[1],*piVar6);
        iVar4 = *piVar6;
        fVar2 = *(float *)(iVar8 + 0x18);
        fVar3 = *(float *)(iVar8 + 0x1c);
        FUN_008918a0();
        piVar7 = DAT_00b5d980;
        FUN_008043d0((double)((fVar2 / fVar3) * (float)iVar4 * (float)fVar11));
        (**(code **)(*piVar7 + 0xc))();
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(param_1 + 0x14));
    puVar9 = puStack_3c;
  }
  if ((in_ECX[2] == 0) || ((int)(in_ECX[3] - in_ECX[2]) / 0x14 == 0)) {
    puVar9[5] = 0;
    puVar9[6] = 0;
    return puVar9;
  }
  puVar9[5] = *(undefined4 *)(puVar9[3] + -8);
  puVar9[6] = *(undefined4 *)(puVar9[3] + -4);
  return puVar9;
}


// ==== FUN_00891ed0 @ 0x00891ed0 ====

void FUN_00891ed0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a150b4;
  if ((void *)in_ECX[2] != (void *)0x0) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_00a15044;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00891f20 @ 0x00891f20 ====

void FUN_00891f20(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = DAT_009b0120;
  *(undefined4 *)(in_ECX + 0x1c) = DAT_009b4bc4;
  uVar1 = DAT_0099de78;
  *(undefined4 *)(in_ECX + 0x20) = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = uVar1;
  return;
}


// ==== FUN_00891f80 @ 0x00891f80 ====

/* WARNING: Removing unreachable block (ram,0x00891fa3) */
/* WARNING: Removing unreachable block (ram,0x00891fa8) */
/* WARNING: Removing unreachable block (ram,0x00891fed) */

void FUN_00891f80(void)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_4 [4];
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x58) + 0x1c);
  (**(code **)(*piVar1 + 0x104))(piVar1,local_4);
  piVar1 = *(int **)(*(int *)(in_ECX + 0x58) + 0x1c);
  (**(code **)(*piVar1 + 0x114))(piVar1);
  return;
}


// ==== FUN_00892010 @ 0x00892010 ====

void FUN_00892010(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  char cVar2;
  
  cVar2 = (char)param_1;
  if ((cVar2 != *(char *)(in_ECX + 0x54)) &&
     (*(char *)(in_ECX + 0x54) = cVar2, cVar2 != *(char *)(in_ECX + 0x2c))) {
    if (*(undefined4 **)(in_ECX + 0x50) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x50))(1);
    }
    *(undefined4 *)(in_ECX + 0x50) = 0;
    piVar1 = (int *)FUN_00899f40(in_ECX + 4);
    *(int **)(in_ECX + 0x50) = piVar1;
    (**(code **)(*piVar1 + 4))(param_1,10000);
  }
  return;
}


// ==== FUN_00892060 @ 0x00892060 ====

void FUN_00892060(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x38) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  if (*(undefined4 **)(in_ECX + 0x50) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x50))(1);
  }
  *(undefined4 *)(in_ECX + 0x50) = 0;
  return;
}


// ==== FUN_008920a0 @ 0x008920a0 ====

void FUN_008920a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1511c;
  if ((void *)in_ECX[0xe] != (void *)0x0) {
    _free((void *)in_ECX[0xe]);
    return;
  }
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  if ((undefined4 *)in_ECX[0x14] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x14])(1);
  }
  in_ECX[0x14] = 0;
  if ((void *)in_ECX[0xe] == (void *)0x0) {
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    *in_ECX = &PTR_FUN_00a13f50;
    return;
  }
  _free((void *)in_ECX[0xe]);
  return;
}


// ==== FUN_00892100 @ 0x00892100 ====

void FUN_00892100(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  
  iVar2 = (**(code **)(**(int **)(DAT_00b5ac04 + 0x6c) + 0x1c))(2,param_1);
  iVar1 = *(int *)(in_ECX + 0x58);
  uVar3 = 0;
  if (iVar2 != 0) {
    piVar4 = (int *)FUN_004af750();
    uVar3 = (**(code **)(*piVar4 + 4))();
  }
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 99)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x188),uVar3);
  iVar1 = *(int *)(in_ECX + 0x58);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 100)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x18c),0);
  return;
}


// ==== FUN_008921a0 @ 0x008921a0 ====

void FUN_008921a0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  uVar3 = DAT_009b0120;
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_00a1511c;
  in_ECX[0xc] = uVar1;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  *(undefined1 *)((int)in_ECX + 0x2d) = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  uVar2 = DAT_0099de78;
  in_ECX[0x11] = 0;
  in_ECX[0x14] = 0;
  *(undefined1 *)(in_ECX + 0x15) = 0;
  in_ECX[0x16] = 0;
  in_ECX[6] = uVar3;
  in_ECX[7] = DAT_009b4bc4;
  in_ECX[8] = uVar1;
  in_ECX[9] = 0;
  in_ECX[10] = uVar2;
  return;
}


// ==== FUN_00892220 @ 0x00892220 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00892220(undefined4 *param_1)

{
  float fVar1;
  float *pfVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  undefined4 **ppuVar7;
  int *piVar8;
  float fVar9;
  float fVar10;
  int aiStack_60 [5];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 *apuStack_20 [8];
  
  *param_1 = 0;
  if (*(void **)(in_ECX + 0x38) != (void *)0x0) {
    uStack_48 = 0x892241;
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  iVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar6 = iVar4 - *(int *)(in_ECX + 0x44);
  *(int *)(in_ECX + 0x44) = iVar4;
  fVar1 = (float)iVar6;
  if (iVar6 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar1 = fVar1 * *(float *)(in_ECX + 0x1c) * DAT_009b4bc4;
  fVar9 = *(float *)(in_ECX + 0x20) * fVar1 + *(float *)(in_ECX + 0x48);
  *(float *)(in_ECX + 0x4c) = *(float *)(in_ECX + 0x24) * fVar1 + *(float *)(in_ECX + 0x4c);
  fVar1 = DAT_0099d080;
  *(float *)(in_ECX + 0x48) = fVar9;
  if (fVar1 < fVar9) {
    *(undefined4 *)(in_ECX + 0x48) = 0;
  }
  if (*(float *)(in_ECX + 0x48) <= 0.0 && *(float *)(in_ECX + 0x48) != 0.0) {
    *(float *)(in_ECX + 0x48) = fVar1;
  }
  if (fVar1 < *(float *)(in_ECX + 0x4c)) {
    *(undefined4 *)(in_ECX + 0x4c) = 0;
  }
  if (*(float *)(in_ECX + 0x4c) <= 0.0 && *(float *)(in_ECX + 0x4c) != 0.0) {
    *(float *)(in_ECX + 0x4c) = fVar1;
  }
  apuStack_20[0] = (undefined4 *)0x0;
  apuStack_20[1] = (undefined4 *)0x0;
  apuStack_20[2] = (undefined4 *)0x0;
  apuStack_20[3] = (undefined4 *)0x0;
  apuStack_20[4] = (undefined4 *)0x0;
  apuStack_20[5] = (undefined4 *)0x0;
  apuStack_20[6] = (undefined4 *)0x0;
  apuStack_20[7] = (undefined4 *)0xffffffff;
  ppuVar7 = apuStack_20;
  piVar8 = aiStack_60;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar8 = (int)*ppuVar7;
    ppuVar7 = ppuVar7 + 1;
    piVar8 = piVar8 + 1;
  }
  FUN_00892c40(4);
  pfVar2 = *(float **)(in_ECX + 0x38);
  fVar9 = *(float *)(in_ECX + 0x28) * DAT_0099d0b4;
  fVar1 = *(float *)(in_ECX + 0x18);
  fVar10 = 0.0 - fVar9;
  if ((pfVar2 == (float *)0x0) || (*(int *)(in_ECX + 0x3c) - (int)pfVar2 >> 5 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *pfVar2 = fVar10;
  pfVar2[1] = fVar1;
  pfVar2[2] = fVar10;
  iVar4 = *(int *)(in_ECX + 0x38);
  uVar5 = *(undefined4 *)(in_ECX + 0x18);
  if ((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x3c) - iVar4 >> 5) < 2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(float *)(iVar4 + 0x20) = fVar9;
  *(undefined4 *)(iVar4 + 0x24) = uVar5;
  *(float *)(iVar4 + 0x28) = fVar10;
  iVar4 = *(int *)(in_ECX + 0x38);
  uVar5 = *(undefined4 *)(in_ECX + 0x18);
  if ((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x3c) - iVar4 >> 5) < 3)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(float *)(iVar4 + 0x40) = fVar10;
  *(undefined4 *)(iVar4 + 0x44) = uVar5;
  *(float *)(iVar4 + 0x48) = fVar9;
  iVar4 = *(int *)(in_ECX + 0x38);
  uVar5 = *(undefined4 *)(in_ECX + 0x18);
  if ((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x3c) - iVar4 >> 5) < 4)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(float *)(iVar4 + 0x60) = fVar9;
  *(undefined4 *)(iVar4 + 100) = uVar5;
  *(float *)(iVar4 + 0x68) = fVar9;
  fVar1 = DAT_0099d080;
  iVar4 = *(int *)(in_ECX + 0x38);
  fVar9 = *(float *)(in_ECX + 0x4c) + DAT_0099d080;
  if ((iVar4 == 0) || (*(int *)(in_ECX + 0x3c) - iVar4 >> 5 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(in_ECX + 0x48);
  *(float *)(iVar4 + 0x10) = fVar9;
  iVar4 = *(int *)(in_ECX + 0x38);
  fVar9 = *(float *)(in_ECX + 0x4c);
  if ((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x3c) - iVar4 >> 5) < 2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(float *)(iVar4 + 0x2c) = *(float *)(in_ECX + 0x48) + fVar1;
  *(float *)(iVar4 + 0x30) = fVar9 + fVar1;
  iVar4 = *(int *)(in_ECX + 0x38);
  if ((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x3c) - iVar4 >> 5) < 3)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar4 + 0x4c) = *(undefined4 *)(in_ECX + 0x48);
  *(undefined4 *)(iVar4 + 0x50) = *(undefined4 *)(in_ECX + 0x4c);
  iVar4 = *(int *)(in_ECX + 0x38);
  uVar5 = *(undefined4 *)(in_ECX + 0x4c);
  if ((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x3c) - iVar4 >> 5) < 4)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(float *)(iVar4 + 0x6c) = *(float *)(in_ECX + 0x48) + fVar1;
  *(undefined4 *)(iVar4 + 0x70) = uVar5;
  piVar8 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  if (*(int *)(in_ECX + 0x38) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(in_ECX + 0x3c) - *(int *)(in_ECX + 0x38) >> 5;
  }
  uStack_48 = 0x20;
  uStack_4c = 0x892590;
  cVar3 = FUN_00881000();
  if (cVar3 == '\0') {
    (**(code **)(*piVar8 + 0xc))();
  }
  uStack_48 = 0x20;
  uStack_4c = 0x8925a5;
  uVar5 = (**(code **)(*piVar8 + 0x1c))();
  *apuStack_20[7] = uVar5;
  uStack_4c = *(undefined4 *)(in_ECX + 0x38);
  aiStack_60[3] = 0x8925b7;
  aiStack_60[4] = iVar4 << 5;
  (**(code **)(*piVar8 + 0x14))();
  aiStack_60[3] = 0x8925be;
  FUN_00881060();
  aiStack_60[1] = *(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4);
  piVar8 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  aiStack_60[3] = 0x20;
  aiStack_60[2] = 0;
  aiStack_60[0] = 0;
  (**(code **)(*piVar8 + 400))(piVar8);
  return;
}


// ==== FUN_008925f0 @ 0x008925f0 ====

void FUN_008925f0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 extraout_ECX;
  int *piStack_3c;
  int *piStack_38;
  int *piStack_34;
  int *piStack_30;
  int *piStack_2c;
  int *piStack_28;
  int *piStack_24;
  
  if ((*(char *)(in_ECX + 0x54) != '\0') &&
     (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x75) != '\0')) {
    uVar3 = FUN_0085e3a0();
    *(undefined4 *)(in_ECX + 0x58) = uVar3;
    if (*(int **)(in_ECX + 0x50) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0x50) + 8))();
    }
    iVar4 = *(int *)(DAT_00b5ac04 + 0x28);
    if ((((*(int *)(iVar4 + 0x114) != 2) || (*(int *)(iVar4 + 0x118) != 5)) ||
        (*(int *)(iVar4 + 0x11c) != 2)) && (*(int *)(iVar4 + 100) == 0)) {
      piStack_2c = *(int **)(iVar4 + 0x90);
      piStack_24 = (int *)0x1;
      piStack_28 = (int *)0x1b;
      piStack_30 = (int *)0x892674;
      (**(code **)(*piStack_2c + 0xe4))();
      piStack_38 = *(int **)(iVar4 + 0x90);
      piStack_30 = (int *)0x1;
      piStack_34 = (int *)0xf;
      piStack_3c = (int *)0x892687;
      (**(code **)(*piStack_38 + 0xe4))();
      piStack_3c = (int *)0x5;
      (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x19);
      (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x18,1);
      (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x13,5);
      (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x14,2);
      *(undefined4 *)(iVar4 + 0x114) = 2;
      *(undefined4 *)(iVar4 + 0x118) = 5;
      *(undefined4 *)(iVar4 + 0x11c) = 2;
    }
    piStack_24 = (int *)0xa;
    piStack_28 = (int *)0x8926f7;
    iVar4 = FUN_0085e3a0();
    piStack_24 = (int *)CONCAT31((int3)((uint)extraout_ECX >> 8),*(undefined1 *)(in_ECX + 0x2c));
    piStack_28 = (int *)0x892704;
    FUN_00892100();
    piStack_24 = *(int **)(iVar4 + 0x20);
    piStack_28 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    piStack_2c = (int *)0x892720;
    (**(code **)(*piStack_28 + 0x15c))();
    piStack_30 = *(int **)(*(int *)(in_ECX + 0x58) + 0x1c);
    piStack_2c = (int *)s_Skybox_00a150fc;
    piStack_34 = (int *)0x892734;
    (**(code **)(*piStack_30 + 0xf0))();
    iVar4 = *(int *)(in_ECX + 0x58);
    iVar1 = *(int *)(iVar4 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x61)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    piStack_38 = *(int **)(iVar1 + 0x180);
    piStack_3c = *(int **)(iVar4 + 0x1c);
    piStack_34 = (int *)(*(int *)(DAT_00b5ac04 + 0x78) + 0x108);
    (**(code **)(*piStack_3c + 0x98))();
    iVar4 = *(int *)(in_ECX + 0x58);
    piStack_2c = DAT_0099d080;
    piStack_28 = DAT_0099d080;
    piStack_24 = DAT_0099d080;
    iVar1 = *(int *)(iVar4 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x62)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar4 + 0x1c) + 0x88))
              (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar1 + 0x184),&piStack_2c);
    FUN_00892220(&piStack_3c);
    piVar2 = piStack_3c;
    FUN_00891f80(piStack_3c);
    if (*(char *)(in_ECX + 0x2d) != '\0') {
      FUN_00892100(*(char *)(in_ECX + 0x2d));
      piStack_38 = DAT_0099d080;
      piStack_34 = DAT_0099d080;
      piStack_30 = DAT_0099d080;
      piStack_2c = (int *)((float)DAT_0099d080 - *(float *)(in_ECX + 0x30));
      FUN_00869060(0x61,&piStack_38);
      FUN_00891f80(piVar2);
    }
  }
  return;
}


// ==== FUN_00892840 @ 0x00892840 ====

int FUN_00892840(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a800;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    FUN_005d2840(param_3,param_1);
    param_3 = param_3 + 0x20;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@008928a6 @ 0x008928a6 ====

void Catch_008928a6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008928b0 @ 0x008928b0 ====

void FUN_008928b0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a810;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005d2840(param_1,param_3);
    param_1 = param_1 + 0x20;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00892916 @ 0x00892916 ====

void Catch_00892916(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00892920 @ 0x00892920 ====

void FUN_00892920(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00892840(param_1,param_2,param_3);
  return;
}


// ==== FUN_00892940 @ 0x00892940 ====

int FUN_00892940(int param_1,int param_2,undefined4 param_3)

{
  FUN_008928b0(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_00892970 @ 0x00892970 ====

void FUN_00892970(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_2 != param_3) {
    puVar1 = *(undefined4 **)(in_ECX + 8);
    puVar5 = param_2;
    puVar4 = param_2;
    if (param_3 != puVar1) {
      do {
        puVar2 = param_3 + 8;
        puVar5 = puVar4 + 8;
        for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = *param_3;
          param_3 = param_3 + 1;
          puVar4 = puVar4 + 1;
        }
        param_3 = puVar2;
        puVar4 = puVar5;
      } while (puVar2 != puVar1);
    }
    *(undefined4 **)(in_ECX + 8) = puVar5;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_008929c0 @ 0x008929c0 ====

undefined1 FUN_008929c0(void)

{
  return 2;
}


// ==== FUN_008929d0 @ 0x008929d0 ====

void FUN_008929d0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 local_50;
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
  puStack_c = &LAB_0099a820;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
  puVar5 = &local_50;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_3;
    param_3 = param_3 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar4 >> 5;
  }
  uVar6 = CONCAT44(iVar4,iVar1);
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 5;
    }
    ExceptionList = &local_10;
    if (0x7ffffffU - iVar4 < param_2) {
      ExceptionList = &local_10;
      uVar6 = FUN_0085b3b0();
    }
    iVar4 = (int)((ulonglong)uVar6 >> 0x20);
    local_20 = (uint)uVar6;
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar4 >> 5;
    }
    if (local_20 < iVar1 + param_2) {
      if (0x7ffffff - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar4 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar4 >> 5;
      }
      if (local_20 < iVar1 + param_2) {
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 5;
        }
        local_20 = iVar4 + param_2;
      }
      local_20 = local_20 << 5;
      pvVar2 = operator_new(local_20);
      local_8 = 0;
      local_24 = pvVar2;
      local_1c = FUN_00892920(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      local_1c = FUN_00892940(local_1c,param_2,&local_50);
      FUN_00892920(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - (int)_Memory >> 5;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)pvVar2;
        *(void **)(in_ECX + 8) = (void *)((param_2 + iVar4) * 0x20 + (int)pvVar2);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)(local_28 - param_1 >> 5) < param_2) {
      local_18 = param_2 * 0x20;
      FUN_00892840(param_1,local_28,local_18 + param_1);
      local_8 = 2;
      FUN_00892940(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),&local_50);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_005d27e0(param_1,*(int *)(in_ECX + 8) - local_18,&local_50);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x20;
    iVar4 = local_28 + param_2 * -0x20;
    uVar3 = FUN_00892840(iVar4,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_005d2810(param_1,iVar4,local_28);
    FUN_005d27e0(param_1,local_18 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00892b34 @ 0x00892b34 ====

void Catch_00892b34(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_00892c20 @ 0x00892c20 ====

void FUN_00892c20(byte param_1)

{
  void *in_ECX;
  
  FUN_008920a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00892c40 @ 0x00892c40 ====

void FUN_00892c40(uint param_1,undefined1 param_2)

{
  int in_ECX;
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 5;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 5;
    }
    FUN_008929d0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 5))) {
    FUN_00892970(&param_1,param_1 * 0x20 + iVar2,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00892cf0 @ 0x00892cf0 ====

/* WARNING: Removing unreachable block (ram,0x00892d17) */
/* WARNING: Removing unreachable block (ram,0x00892d20) */
/* WARNING: Removing unreachable block (ram,0x00892d3b) */
/* WARNING: Removing unreachable block (ram,0x00892d37) */
/* WARNING: Removing unreachable block (ram,0x00892d42) */
/* WARNING: Removing unreachable block (ram,0x00892d4d) */
/* WARNING: Removing unreachable block (ram,0x00892d49) */
/* WARNING: Removing unreachable block (ram,0x00892d55) */
/* WARNING: Removing unreachable block (ram,0x00892d9d) */

void FUN_00892cf0(void)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_4 [4];
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x5c) + 0x1c);
  (**(code **)(*piVar1 + 0x104))(piVar1,local_4);
  piVar1 = *(int **)(*(int *)(in_ECX + 0x5c) + 0x1c);
  (**(code **)(*piVar1 + 0x114))(piVar1);
  return;
}


// ==== FUN_00892dc0 @ 0x00892dc0 ====

void FUN_00892dc0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  char cVar2;
  
  cVar2 = (char)param_1;
  if ((cVar2 != *(char *)(in_ECX + 0x58)) &&
     (*(char *)(in_ECX + 0x58) = cVar2, cVar2 != *(char *)(in_ECX + 0x2c))) {
    if (*(undefined4 **)(in_ECX + 0x54) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x54))(1);
    }
    *(undefined4 *)(in_ECX + 0x54) = 0;
    piVar1 = (int *)FUN_00899f40(in_ECX + 4);
    *(int **)(in_ECX + 0x54) = piVar1;
    (**(code **)(*piVar1 + 4))(param_1,10000);
  }
  return;
}


// ==== FUN_00892e10 @ 0x00892e10 ====

void FUN_00892e10(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x38) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  if (*(void **)(in_ECX + 0x48) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x48));
    return;
  }
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  if (*(undefined4 **)(in_ECX + 0x54) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x54))(1);
  }
  *(undefined4 *)(in_ECX + 0x54) = 0;
  return;
}


// ==== FUN_00892e60 @ 0x00892e60 ====

void FUN_00892e60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15190;
  if ((void *)in_ECX[0xe] != (void *)0x0) {
    _free((void *)in_ECX[0xe]);
    return;
  }
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  if ((void *)in_ECX[0x12] != (void *)0x0) {
    _free((void *)in_ECX[0x12]);
    return;
  }
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  if ((undefined4 *)in_ECX[0x15] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x15])(1);
  }
  in_ECX[0x15] = 0;
  if ((void *)in_ECX[0x12] != (void *)0x0) {
    _free((void *)in_ECX[0x12]);
    return;
  }
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  if ((void *)in_ECX[0xe] == (void *)0x0) {
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    *in_ECX = &PTR_FUN_00a13f50;
    return;
  }
  _free((void *)in_ECX[0xe]);
  return;
}


// ==== FUN_00892ef0 @ 0x00892ef0 ====

void FUN_00892ef0(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 *unaff_ESI;
  int iVar5;
  
  *param_1 = 0;
  *param_2 = 0;
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  if (*(int *)(in_ECX + 0x38) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(in_ECX + 0x3c) - *(int *)(in_ECX + 0x38) >> 5;
  }
  iVar3 = iVar3 << 5;
  cVar2 = FUN_00881000(0x20,iVar3);
  if (cVar2 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  uVar4 = (**(code **)(*piVar1 + 0x1c))(0x20,iVar3);
  *param_1 = uVar4;
  (**(code **)(*piVar1 + 0x14))(iVar3,*(undefined4 *)(in_ECX + 0x38));
  FUN_00881060();
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  if (*(int *)(in_ECX + 0x48) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(in_ECX + 0x4c) - *(int *)(in_ECX + 0x48) >> 1;
  }
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar3 * 2)) {
    (**(code **)(*piVar1 + 0x10))();
  }
  uVar4 = (**(code **)(*piVar1 + 0x20))(iVar3 * 2);
  *unaff_ESI = uVar4;
  iVar3 = *(int *)(in_ECX + 0x48);
  if (iVar3 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(in_ECX + 0x4c) - iVar3 >> 1;
  }
  (**(code **)(*piVar1 + 0x18))(iVar5,iVar3);
  FUN_00881080();
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x20)
  ;
  FUN_0084b7f0(*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 0x18));
  return;
}


// ==== FUN_00893010 @ 0x00893010 ====

void FUN_00893010(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  
  iVar2 = (**(code **)(**(int **)(DAT_00b5ac04 + 0x6c) + 0x1c))(1,param_1);
  iVar1 = *(int *)(in_ECX + 0x5c);
  uVar3 = 0;
  if (iVar2 != 0) {
    piVar4 = (int *)FUN_004af750();
    uVar3 = (**(code **)(*piVar4 + 4))();
  }
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 99)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x188),uVar3);
  iVar1 = *(int *)(in_ECX + 0x5c);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 100)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x18c),0);
  return;
}


// ==== FUN_008930b0 @ 0x008930b0 ====

void FUN_008930b0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 uStack_40;
  int *piStack_3c;
  int *piStack_38;
  int *piStack_34;
  int *piStack_30;
  int *piStack_2c;
  
  if ((*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x75) != '\0') &&
     (*(char *)(in_ECX + 0x58) != '\0')) {
    uVar3 = FUN_0085e3a0();
    *(undefined4 *)(in_ECX + 0x5c) = uVar3;
    if (*(int **)(in_ECX + 0x54) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0x54) + 8))();
    }
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    iVar4 = DAT_00b5ac04;
    if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
        (*(int *)(iVar1 + 0x11c) != 6)) && (*(int *)(iVar1 + 100) == 0)) {
      piStack_30 = *(int **)(iVar1 + 0x90);
      piStack_2c = (int *)0x1b;
      piStack_34 = (int *)0x893135;
      (**(code **)(*piStack_30 + 0xe4))();
      piStack_3c = *(int **)(iVar1 + 0x90);
      piStack_34 = (int *)0x1;
      piStack_38 = (int *)0xf;
      uStack_40 = 0x893148;
      (**(code **)(*piStack_3c + 0xe4))();
      uStack_40 = 5;
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
      iVar4 = (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
      *(undefined4 *)(iVar1 + 0x114) = 2;
      *(undefined4 *)(iVar1 + 0x118) = 5;
      *(undefined4 *)(iVar1 + 0x11c) = 6;
    }
    piStack_2c = (int *)CONCAT31((int3)((uint)iVar4 >> 8),*(undefined1 *)(in_ECX + 0x2c));
    piStack_30 = (int *)0x8931ba;
    FUN_00893010();
    piStack_2c = *(int **)(*(int *)(in_ECX + 0x5c) + 0x20);
    piStack_30 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    piStack_34 = (int *)0x8931d9;
    (**(code **)(*piStack_30 + 0x15c))();
    piStack_38 = *(int **)(*(int *)(in_ECX + 0x5c) + 0x1c);
    piStack_34 = (int *)s_Skybox_00a15170;
    piStack_3c = (int *)0x8931ed;
    (**(code **)(*piStack_38 + 0xf0))();
    iVar1 = *(int *)(in_ECX + 0x5c);
    iVar4 = *(int *)(iVar1 + 0x28);
    if ((iVar4 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar4 >> 2) < 0x61)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    uStack_40 = *(undefined4 *)(iVar4 + 0x180);
    piStack_3c = (int *)(*(int *)(DAT_00b5ac04 + 0x78) + 0x108);
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x98))(*(int **)(iVar1 + 0x1c));
    iVar1 = *(int *)(in_ECX + 0x5c);
    piStack_2c = DAT_0099d080;
    iVar4 = *(int *)(iVar1 + 0x28);
    if ((iVar4 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar4 >> 2) < 0x62)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x88))
              (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar4 + 0x184),&piStack_2c);
    FUN_00892ef0(&uStack_40,&piStack_3c);
    piVar2 = piStack_3c;
    FUN_00892cf0(uStack_40,piStack_3c);
    if (*(char *)(in_ECX + 0x2d) != '\0') {
      iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
      if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
          (*(int *)(iVar1 + 0x11c) != 6)) && (*(int *)(iVar1 + 100) == 0)) {
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
        *(undefined4 *)(iVar1 + 0x114) = 2;
        *(undefined4 *)(iVar1 + 0x118) = 5;
        *(undefined4 *)(iVar1 + 0x11c) = 6;
      }
      piStack_38 = DAT_0099d080;
      piStack_34 = DAT_0099d080;
      piStack_30 = DAT_0099d080;
      piStack_2c = (int *)((float)DAT_0099d080 - *(float *)(in_ECX + 0x30));
      FUN_00869060(0x61,&piStack_38);
      FUN_00893010(*(undefined1 *)(in_ECX + 0x2d));
      FUN_00892cf0(uStack_40,piVar2);
    }
  }
  return;
}


// ==== FUN_008933d0 @ 0x008933d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008933d0(void)

{
  undefined2 *puVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  float fVar7;
  undefined2 in_FPUControlWord;
  float10 fVar8;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  int local_38;
  int local_34;
  int local_30;
  float local_2c;
  int local_28;
  int local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar4 = in_ECX + 0x34;
  if (*(void **)(in_ECX + 0x38) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  fVar7 = _DAT_00a151b0;
  if (*(void **)(in_ECX + 0x48) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x48));
    return;
  }
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  local_64 = (float)CONCAT22(local_64._2_2_,in_FPUControlWord);
  *(undefined4 *)(in_ECX + 0x50) = 0;
  local_40 = *(float *)(in_ECX + 0xc);
  local_44 = *(float *)(in_ECX + 8);
  local_4c = *(float *)(in_ECX + 0x10);
  local_48 = *(float *)(in_ECX + 0x14);
  local_60 = *(float *)(in_ECX + 4);
  local_30 = (int)ROUND((DAT_009b341c / local_44) * (fVar7 / local_40) * DAT_009b0ec8);
  local_24 = in_ECX;
  FUN_00894170(local_30);
  local_28 = 0x78 - (int)local_40;
  local_20 = 0.0;
  local_1c = 0.0;
  local_18 = 0.0;
  local_14 = 0.0;
  local_10 = 0.0;
  local_c = 0;
  local_8 = 0;
  local_34 = 0;
  if (-1 < local_28) {
    local_30 = 0x168 - (int)local_44;
    local_4 = 0xffffffff;
    do {
      local_58 = (float)local_34;
      local_38 = 0;
      if (-1 < local_30) {
        local_54 = local_58 + local_40;
        do {
          local_50 = (float)local_38;
          if (*(int *)(in_ECX + 0x38) == 0) {
            fVar7 = 0.0;
          }
          else {
            fVar7 = (float)(*(int *)(in_ECX + 0x3c) - *(int *)(in_ECX + 0x38) >> 5);
          }
          iVar5 = *(int *)(in_ECX + 0x48);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x50) - iVar5 >> 1) <=
              (uint)(*(int *)(in_ECX + 0x4c) - iVar5 >> 1))) {
            local_64 = fVar7;
            FUN_00427290(*(undefined4 *)(in_ECX + 0x4c),1,&local_64);
          }
          else {
            puVar1 = *(undefined2 **)(in_ECX + 0x4c);
            *puVar1 = SUB42(fVar7,0);
            *(undefined2 **)(in_ECX + 0x4c) = puVar1 + 1;
          }
          iVar5 = *(int *)(in_ECX + 0x48);
          local_64 = (float)((int)fVar7 + 1);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x50) - iVar5 >> 1) <=
              (uint)(*(int *)(in_ECX + 0x4c) - iVar5 >> 1))) {
            FUN_00427290(*(undefined4 *)(in_ECX + 0x4c),1,&local_64);
          }
          else {
            puVar1 = *(undefined2 **)(in_ECX + 0x4c);
            *puVar1 = SUB42(local_64,0);
            *(undefined2 **)(in_ECX + 0x4c) = puVar1 + 1;
          }
          iVar5 = *(int *)(in_ECX + 0x48);
          local_64 = (float)((int)fVar7 + 2);
          local_2c = local_64;
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x50) - iVar5 >> 1) <=
              (uint)(*(int *)(in_ECX + 0x4c) - iVar5 >> 1))) {
            FUN_00427290(*(undefined4 *)(in_ECX + 0x4c),1,&local_64);
          }
          else {
            puVar1 = *(undefined2 **)(in_ECX + 0x4c);
            *puVar1 = SUB42(local_64,0);
            *(undefined2 **)(in_ECX + 0x4c) = puVar1 + 1;
          }
          iVar5 = *(int *)(in_ECX + 0x48);
          local_64 = (float)((int)fVar7 + 1);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x50) - iVar5 >> 1) <=
              (uint)(*(int *)(in_ECX + 0x4c) - iVar5 >> 1))) {
            FUN_00427290(*(undefined4 *)(in_ECX + 0x4c),1,&local_64);
          }
          else {
            puVar1 = *(undefined2 **)(in_ECX + 0x4c);
            *puVar1 = SUB42(local_64,0);
            *(undefined2 **)(in_ECX + 0x4c) = puVar1 + 1;
          }
          iVar5 = *(int *)(in_ECX + 0x48);
          local_64 = (float)((int)fVar7 + 3);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x50) - iVar5 >> 1) <=
              (uint)(*(int *)(in_ECX + 0x4c) - iVar5 >> 1))) {
            FUN_00427290(*(undefined4 *)(in_ECX + 0x4c),1,&local_64);
          }
          else {
            puVar1 = *(undefined2 **)(in_ECX + 0x4c);
            *puVar1 = SUB42(local_64,0);
            *(undefined2 **)(in_ECX + 0x4c) = puVar1 + 1;
          }
          iVar5 = *(int *)(in_ECX + 0x48);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x50) - iVar5 >> 1) <=
              (uint)(*(int *)(in_ECX + 0x4c) - iVar5 >> 1))) {
            FUN_00427290(*(undefined4 *)(in_ECX + 0x4c),1,&local_2c);
          }
          else {
            puVar1 = *(undefined2 **)(in_ECX + 0x4c);
            *puVar1 = SUB42(local_2c,0);
            *(undefined2 **)(in_ECX + 0x4c) = puVar1 + 1;
          }
          fVar8 = (float10)FUN_0040d4c0(DAT_00b52cd4 * local_58);
          local_2c = (float)fVar8;
          fVar8 = (float10)FUN_0040d4d0(DAT_00b52cd4 * local_50);
          local_20 = (float)(fVar8 * (float10)local_2c * (float10)local_60);
          fVar8 = (float10)FUN_0040d4c0(DAT_00b52cd4 * local_58);
          local_2c = (float)fVar8;
          fVar8 = (float10)FUN_0040d4c0(DAT_00b52cd4 * local_50);
          local_18 = (float)(fVar8 * (float10)local_2c * (float10)local_60);
          fVar8 = (float10)FUN_0040d4d0(DAT_00b52cd4 * local_58);
          local_1c = (float)(fVar8 * (float10)local_60);
          fVar8 = (float10)FUN_0040d540((float)((float10)local_20 * (float10)local_20 +
                                               (float10)local_18 * (float10)local_18 +
                                               fVar8 * (float10)local_60 * (float10)local_1c));
          local_64 = (float)fVar8;
          local_5c = DAT_0099d080 / local_64;
          fVar8 = (float10)FUN_0040d520(local_5c * local_20,local_5c * local_18);
          local_14 = (float)(fVar8 * (float10)_DAT_00a151ac * (float10)local_4c +
                            (float10)DAT_0099d0b4);
          fVar8 = (float10)FUN_0040d4f0(local_5c * local_1c);
          local_10 = (float)(((float10)DAT_009b9f98 - fVar8 * (float10)_DAT_00a151a8) *
                            (float10)local_48);
          if (DAT_0099d080 < local_10) {
            local_10 = DAT_0099d0f8 - local_10;
          }
          iVar5 = *(int *)(in_ECX + 0x38);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x40) - iVar5 >> 5) <=
              (uint)(*(int *)(in_ECX + 0x3c) - iVar5 >> 5))) {
            FUN_008929d0(*(undefined4 *)(in_ECX + 0x3c),1,&local_20);
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x3c);
            FUN_008928b0(iVar5,1,&local_20,iVar4,local_24);
            *(int *)(in_ECX + 0x3c) = iVar5 + 0x20;
          }
          fVar8 = (float10)FUN_0040d4c0(local_54 * DAT_00b52cd4);
          local_2c = (float)fVar8;
          fVar8 = (float10)FUN_0040d4d0(DAT_00b52cd4 * local_50);
          local_20 = (float)(fVar8 * (float10)local_2c * (float10)local_60);
          fVar8 = (float10)FUN_0040d4c0(local_54 * DAT_00b52cd4);
          local_2c = (float)fVar8;
          fVar8 = (float10)FUN_0040d4c0(DAT_00b52cd4 * local_50);
          local_18 = (float)(fVar8 * (float10)local_2c * (float10)local_60);
          fVar8 = (float10)FUN_0040d4d0(local_54 * DAT_00b52cd4);
          local_1c = (float)(fVar8 * (float10)local_60);
          fVar8 = (float10)FUN_0040d540((float)((float10)local_20 * (float10)local_20 +
                                               (float10)local_18 * (float10)local_18 +
                                               fVar8 * (float10)local_60 * (float10)local_1c));
          local_64 = (float)fVar8;
          local_5c = DAT_0099d080 / local_64;
          fVar8 = (float10)FUN_0040d520(local_5c * local_20,local_5c * local_18);
          local_14 = (float)(fVar8 * (float10)_DAT_00a151ac * (float10)local_4c +
                            (float10)DAT_0099d0b4);
          fVar8 = (float10)FUN_0040d4f0(local_5c * local_1c);
          local_10 = (float)(((float10)DAT_009b9f98 - fVar8 * (float10)_DAT_00a151a8) *
                            (float10)local_48);
          if (DAT_0099d080 < local_10) {
            local_10 = DAT_0099d0f8 - local_10;
          }
          iVar5 = *(int *)(in_ECX + 0x38);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x40) - iVar5 >> 5) <=
              (uint)(*(int *)(in_ECX + 0x3c) - iVar5 >> 5))) {
            FUN_008929d0(*(undefined4 *)(in_ECX + 0x3c),1,&local_20);
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x3c);
            FUN_008928b0(iVar5,1,&local_20,iVar4,local_24);
            *(int *)(in_ECX + 0x3c) = iVar5 + 0x20;
          }
          fVar8 = (float10)FUN_0040d4c0(DAT_00b52cd4 * local_58);
          local_2c = (float)fVar8;
          local_3c = local_50 + local_44;
          fVar8 = (float10)FUN_0040d4d0(local_3c * DAT_00b52cd4);
          local_20 = (float)(fVar8 * (float10)local_2c * (float10)local_60);
          fVar8 = (float10)FUN_0040d4c0(DAT_00b52cd4 * local_58);
          local_2c = (float)fVar8;
          fVar8 = (float10)FUN_0040d4c0(local_3c * DAT_00b52cd4);
          local_18 = (float)(fVar8 * (float10)local_2c * (float10)local_60);
          fVar8 = (float10)FUN_0040d4d0(DAT_00b52cd4 * local_58);
          local_1c = (float)(fVar8 * (float10)local_60);
          fVar8 = (float10)FUN_0040d540((float)((float10)local_20 * (float10)local_20 +
                                               (float10)local_18 * (float10)local_18 +
                                               fVar8 * (float10)local_60 * (float10)local_1c));
          local_64 = (float)fVar8;
          local_5c = DAT_0099d080 / local_64;
          fVar8 = (float10)FUN_0040d520(local_5c * local_20,local_5c * local_18);
          local_14 = (float)(fVar8 * (float10)_DAT_00a151ac * (float10)local_4c +
                            (float10)DAT_0099d0b4);
          fVar8 = (float10)FUN_0040d4f0(local_5c * local_1c);
          local_10 = (float)(((float10)DAT_009b9f98 - fVar8 * (float10)_DAT_00a151a8) *
                            (float10)local_48);
          if (DAT_0099d080 < local_10) {
            local_10 = DAT_0099d0f8 - local_10;
          }
          iVar5 = *(int *)(in_ECX + 0x38);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x40) - iVar5 >> 5) <=
              (uint)(*(int *)(in_ECX + 0x3c) - iVar5 >> 5))) {
            FUN_008929d0(*(undefined4 *)(in_ECX + 0x3c),1,&local_20);
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x3c);
            FUN_008928b0(iVar5,1,&local_20,iVar4,local_24);
            *(int *)(in_ECX + 0x3c) = iVar5 + 0x20;
          }
          fVar8 = (float10)FUN_0040d4c0(local_54 * DAT_00b52cd4);
          local_2c = (float)fVar8;
          fVar8 = (float10)FUN_0040d4d0(local_3c * DAT_00b52cd4);
          local_20 = (float)(fVar8 * (float10)local_2c * (float10)local_60);
          fVar8 = (float10)FUN_0040d4c0(local_54 * DAT_00b52cd4);
          local_2c = (float)fVar8;
          fVar8 = (float10)FUN_0040d4c0(local_3c * DAT_00b52cd4);
          local_18 = (float)(fVar8 * (float10)local_2c * (float10)local_60);
          fVar8 = (float10)FUN_0040d4d0(local_54 * DAT_00b52cd4);
          local_1c = (float)(fVar8 * (float10)local_60);
          fVar8 = (float10)FUN_0040d540((float)((float10)local_20 * (float10)local_20 +
                                               (float10)local_18 * (float10)local_18 +
                                               fVar8 * (float10)local_60 * (float10)local_1c));
          local_64 = (float)fVar8;
          local_5c = DAT_0099d080 / local_64;
          fVar8 = (float10)FUN_0040d520(local_5c * local_20,local_5c * local_18);
          local_14 = (float)(fVar8 * (float10)_DAT_00a151ac * (float10)local_4c +
                            (float10)DAT_0099d0b4);
          fVar8 = (float10)FUN_0040d4f0(local_5c * local_1c);
          local_10 = (float)(((float10)DAT_009b9f98 - fVar8 * (float10)_DAT_00a151a8) *
                            (float10)local_48);
          if (DAT_0099d080 < local_10) {
            local_10 = DAT_0099d0f8 - local_10;
          }
          iVar5 = *(int *)(in_ECX + 0x38);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x40) - iVar5 >> 5) <=
              (uint)(*(int *)(in_ECX + 0x3c) - iVar5 >> 5))) {
            FUN_008929d0(*(undefined4 *)(in_ECX + 0x3c),1,&local_20);
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x3c);
            FUN_008928b0(iVar5,1,&local_20,iVar4,local_24);
            *(int *)(in_ECX + 0x3c) = iVar5 + 0x20;
          }
          local_38 = local_38 + (int)local_44;
        } while (local_38 <= local_30);
      }
      local_34 = local_34 + (int)local_40;
    } while (local_34 <= local_28);
  }
  fVar3 = DAT_009be92c;
  fVar7 = DAT_009b2dbc;
  uVar6 = 0;
  iVar4 = 0;
  while( true ) {
    fVar2 = DAT_0099d080;
    if (*(int *)(in_ECX + 0x38) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 0x3c) - *(int *)(in_ECX + 0x38) >> 5;
    }
    if (iVar5 - 3U <= uVar6) break;
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar3 < *(float *)(iVar5 + 0xc + iVar4) - *(float *)(iVar5 + 0x2c + iVar4)) {
      *(float *)(iVar5 + iVar4 + 0x2c) = *(float *)(iVar5 + iVar4 + 0x2c) + DAT_0099d080;
    }
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar3 < *(float *)(iVar4 + 0x2c + iVar5) - *(float *)(iVar4 + 0xc + iVar5)) {
      *(float *)(iVar4 + iVar5 + 0xc) = *(float *)(iVar4 + iVar5 + 0xc) + fVar2;
    }
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar3 < *(float *)(iVar5 + 0xc + iVar4) - *(float *)(iVar5 + 0x4c + iVar4)) {
      *(float *)(iVar5 + iVar4 + 0x4c) = *(float *)(iVar5 + iVar4 + 0x4c) + fVar2;
    }
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar3 < *(float *)(iVar4 + 0x4c + iVar5) - *(float *)(iVar4 + 0xc + iVar5)) {
      *(float *)(iVar4 + iVar5 + 0xc) = *(float *)(iVar4 + iVar5 + 0xc) + fVar2;
    }
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar3 < *(float *)(iVar5 + 0x2c + iVar4) - *(float *)(iVar5 + 0x4c + iVar4)) {
      *(float *)(iVar5 + iVar4 + 0x4c) = *(float *)(iVar5 + iVar4 + 0x4c) + fVar2;
    }
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar3 < *(float *)(iVar4 + 0x4c + iVar5) - *(float *)(iVar4 + 0x2c + iVar5)) {
      *(float *)(iVar4 + iVar5 + 0x2c) = *(float *)(iVar4 + iVar5 + 0x2c) + fVar2;
    }
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar7 < *(float *)(iVar5 + 0x10 + iVar4) - *(float *)(iVar5 + 0x30 + iVar4)) {
      *(float *)(iVar5 + iVar4 + 0x30) = *(float *)(iVar5 + iVar4 + 0x30) + fVar2;
    }
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar7 < *(float *)(iVar4 + 0x30 + iVar5) - *(float *)(iVar4 + 0x10 + iVar5)) {
      *(float *)(iVar4 + iVar5 + 0x10) = *(float *)(iVar4 + iVar5 + 0x10) + fVar2;
    }
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar7 < *(float *)(iVar5 + 0x10 + iVar4) - *(float *)(iVar5 + 0x50 + iVar4)) {
      *(float *)(iVar5 + iVar4 + 0x50) = *(float *)(iVar5 + iVar4 + 0x50) + fVar2;
    }
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar7 < *(float *)(iVar4 + 0x50 + iVar5) - *(float *)(iVar4 + 0x10 + iVar5)) {
      *(float *)(iVar4 + iVar5 + 0x10) = *(float *)(iVar4 + iVar5 + 0x10) + fVar2;
    }
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar7 < *(float *)(iVar5 + 0x30 + iVar4) - *(float *)(iVar5 + 0x50 + iVar4)) {
      *(float *)(iVar5 + iVar4 + 0x50) = *(float *)(iVar5 + iVar4 + 0x50) + fVar2;
    }
    iVar5 = *(int *)(local_24 + 0x38);
    if (fVar7 < *(float *)(iVar4 + 0x50 + iVar5) - *(float *)(iVar4 + 0x30 + iVar5)) {
      *(float *)(iVar4 + iVar5 + 0x30) = *(float *)(iVar4 + iVar5 + 0x30) + fVar2;
    }
    uVar6 = uVar6 + 1;
    iVar4 = iVar4 + 0x20;
  }
  return;
}


// ==== FUN_00894050 @ 0x00894050 ====

void FUN_00894050(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar2 = DAT_0099d100;
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_00a15190;
  in_ECX[0xc] = uVar1;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  *(undefined1 *)((int)in_ECX + 0x2d) = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[4] = uVar1;
  in_ECX[5] = uVar1;
  uVar1 = DAT_0099de80;
  in_ECX[0x15] = 0;
  *(undefined1 *)(in_ECX + 0x16) = 0;
  in_ECX[0x17] = 0;
  in_ECX[2] = uVar2;
  in_ECX[3] = uVar2;
  in_ECX[1] = uVar1;
  FUN_008933d0();
  return;
}


// ==== FUN_008940c0 @ 0x008940c0 ====

int FUN_008940c0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a830;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    FUN_005d2840(param_3,param_1);
    param_3 = param_3 + 0x20;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00894126 @ 0x00894126 ====

void Catch_00894126(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00894130 @ 0x00894130 ====

void FUN_00894130(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008940c0(param_1,param_2,param_3);
  return;
}


// ==== FUN_00894150 @ 0x00894150 ====

void FUN_00894150(byte param_1)

{
  void *in_ECX;
  
  FUN_00892e60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00894170 @ 0x00894170 ====

void FUN_00894170(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  uint extraout_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a840;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x7ffffff < param_1) {
    ExceptionList = &local_10;
    FUN_0085b3b0();
    param_1 = extraout_EDX;
  }
  if (*(int *)(in_ECX + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4) >> 5;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x20);
    local_8 = 0;
    FUN_00894130(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    local_8 = 0xffffffff;
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x20 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00894238 @ 0x00894238 ====

void Catch_00894238(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00894250 @ 0x00894250 ====

void FUN_00894250(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15208;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00894280 @ 0x00894280 ====

int FUN_00894280(undefined4 param_1,undefined4 param_2,void *param_3)

{
  int extraout_EAX;
  undefined4 uStack_28;
  void *pvStack_24;
  undefined1 local_1c [12];
  uint uStack_10;
  int iStack_8;
  
  pvStack_24 = param_3;
  uStack_28 = param_2;
  (**(code **)(*DAT_00b5acec + 0x1c))(local_1c);
  *(undefined4 *)(iStack_8 + 0x14) = 0;
  *(undefined4 *)(iStack_8 + 0x18) = 0xf;
  *(undefined1 *)(iStack_8 + 4) = 0;
  FUN_00401660(&uStack_28,0,0xffffffff);
  if (uStack_10 < 0x10) {
    return iStack_8;
  }
  _free(pvStack_24);
  return extraout_EAX;
}


// ==== FUN_008942e0 @ 0x008942e0 ====

undefined4 FUN_008942e0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  char cVar3;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  iVar1 = param_2;
  cVar3 = (char)param_2;
  if (cVar3 == '\0') {
    return 0;
  }
  local_30 = param_1;
  local_2c._0_1_ = cVar3;
  FUN_00894800(&param_2,&local_30);
  if (param_2 != *(int *)(in_ECX + 8)) {
    return *(undefined4 *)(param_2 + 0x14);
  }
  FUN_00894280(local_1c,param_1,iVar1);
  uVar2 = FUN_004b4e70(local_1c);
  local_2c = CONCAT31(local_2c._1_3_,cVar3);
  local_24 = local_2c;
  local_28 = param_1;
  local_20 = uVar2;
  FUN_00894a40(&local_30,&local_28);
  if (local_4 < 0x10) {
    return uVar2;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_008943a0 @ 0x008943a0 ====

void FUN_008943a0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *_Memory;
  undefined4 *puVar5;
  undefined4 *in_ECX;
  undefined1 auStack_4 [4];
  
  puVar2 = (undefined4 *)in_ECX[2];
  *in_ECX = &PTR_FUN_00a15214;
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (puVar3[5] != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(puVar3[5]);
    }
    if (*(char *)((int)puVar3 + 0x19) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x19) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x19);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x19);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x19);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x19);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  _Memory = *(void **)(in_ECX[2] + 4);
  if (*(char *)((int)_Memory + 0x19) == '\0') {
    FUN_008945f0(*(undefined4 *)((int)_Memory + 8));
    _free(_Memory);
    return;
  }
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  in_ECX[3] = 0;
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  FUN_00894f10(auStack_4,*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5]);
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_008944c0 @ 0x008944c0 ====

void FUN_008944c0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15214;
  iVar1 = FUN_008946c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  iVar1 = FUN_00894760();
  in_ECX[5] = iVar1;
  *(undefined1 *)(iVar1 + 0x31) = 1;
  *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
  *(undefined4 *)in_ECX[5] = in_ECX[5];
  *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  in_ECX[6] = 0;
  return;
}


// ==== FUN_00894530 @ 0x00894530 ====

undefined4 FUN_00894530(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_008944c0();
  return uVar2;
}


// ==== FUN_00894550 @ 0x00894550 ====

void FUN_00894550(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x19);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x19);
  }
  return;
}


// ==== FUN_00894570 @ 0x00894570 ====

void FUN_00894570(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  in_ECX[4] = param_4[1];
  in_ECX[5] = param_4[2];
  *(undefined1 *)(in_ECX + 6) = param_5;
  *(undefined1 *)((int)in_ECX + 0x19) = 0;
  return;
}


// ==== FUN_008945b0 @ 0x008945b0 ====

undefined4 * FUN_008945b0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x19) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if (((int)puVar2[3] < *param_1) ||
         (((int)puVar2[3] <= *param_1 && (*(byte *)(puVar2 + 4) < *(byte *)(param_1 + 1))))) {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x19) == '\0');
  }
  return puVar2;
}


// ==== FUN_008945f0 @ 0x008945f0 ====

void FUN_008945f0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    FUN_008945f0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00894630 @ 0x00894630 ====

void * FUN_00894630(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a850;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x1c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00894570(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@008946a5 @ 0x008946a5 ====

void Catch_008946a5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008946c0 @ 0x008946c0 ====

void FUN_008946c0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a860;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
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
  *(undefined1 *)(puVar1 + 6) = 1;
  *(undefined1 *)((int)puVar1 + 0x19) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0089474a @ 0x0089474a ====

void Catch_0089474a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00894760 @ 0x00894760 ====

void FUN_00894760(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a870;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x34);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xc) = 1;
  *(undefined1 *)((int)puVar1 + 0x31) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@008947ea @ 0x008947ea ====

void Catch_008947ea(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00894800 @ 0x00894800 ====

void FUN_00894800(int *param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008945b0(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if ((*(int *)(iVar1 + 0xc) <= *param_2) &&
       ((*(int *)(iVar1 + 0xc) < *param_2 || (*(byte *)(iVar1 + 0x10) <= *(byte *)(param_2 + 1)))))
    {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_00894860 @ 0x00894860 ====

void FUN_00894860(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x15555553 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00894630(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x18);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x18) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[6] == '\0') {
LAB_00894965:
        *(undefined1 *)(*piVar5 + 0x18) = 1;
        *(undefined1 *)(piVar6 + 6) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x18) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0058b7a0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x18) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;
        FUN_004b8340(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[6] == '\0') goto LAB_00894965;
      if (piVar7 == (int *)*piVar2) {
        FUN_004b8340(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x18) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x19) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x18);
  } while( true );
}


// ==== FUN_00894a40 @ 0x00894a40 ====

void FUN_00894a40(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_4;
  
  piVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar1 = true;
  local_4 = 1;
  if (*(char *)((int)puVar4[1] + 0x19) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if ((*param_2 < (int)puVar4[3]) ||
         ((*param_2 <= (int)puVar4[3] && (*(byte *)(param_2 + 1) < *(byte *)(puVar4 + 4))))) {
        puVar3 = (undefined4 *)*puVar4;
        bVar1 = true;
        local_4 = 1;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
        bVar1 = false;
        local_4 = 0;
      }
    } while (*(char *)((int)puVar3 + 0x19) == '\0');
  }
  param_2 = puVar4;
  if (bVar1) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      local_4 = 1;
      goto LAB_00894a95;
    }
    FUN_004b83a0();
  }
  if ((*piVar2 <= param_2[3]) &&
     ((*piVar2 < param_2[3] || (*(byte *)(piVar2 + 1) <= *(byte *)(param_2 + 4))))) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_00894a95:
  puVar4 = (undefined4 *)FUN_00894860(&param_2,local_4,puVar4,piVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00894bd0 @ 0x00894bd0 ====

/* WARNING: Removing unreachable block (ram,0x00894ce9) */
/* WARNING: Removing unreachable block (ram,0x00894cfa) */
/* WARNING: Removing unreachable block (ram,0x00894d03) */
/* WARNING: Removing unreachable block (ram,0x00894d06) */
/* WARNING: Removing unreachable block (ram,0x00894cf6) */
/* WARNING: Removing unreachable block (ram,0x00894d14) */
/* WARNING: Removing unreachable block (ram,0x00894d21) */
/* WARNING: Removing unreachable block (ram,0x00894d2c) */
/* WARNING: Removing unreachable block (ram,0x00894d28) */
/* WARNING: Removing unreachable block (ram,0x00894d1c) */
/* WARNING: Removing unreachable block (ram,0x00894d2f) */

void FUN_00894bd0(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x31) != '\0') {
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
  FUN_00884fb0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x31) == '\0') {
    if (*(char *)(param_2[2] + 0x31) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x31) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x31) == '\0') {
      piVar3 = (int *)FUN_00446e00(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x31) == '\0') {
      uVar4 = FUN_0049ff70(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xc] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xc] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xc] == '\0') {
            *(undefined1 *)(piVar5 + 0xc) = 1;
            *(undefined1 *)(piVar3 + 0xc) = 0;
            FUN_00821aa0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x31) == '\0') {
            if ((*(char *)(*piVar5 + 0x30) == '\x01') && (*(char *)(piVar5[2] + 0x30) == '\x01'))
            goto LAB_00894e04;
            if (*(char *)(piVar5[2] + 0x30) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x30) = 1;
              *(undefined1 *)(piVar5 + 0xc) = 0;
              FUN_0049ff90(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xc) = (char)piVar3[0xc];
            *(undefined1 *)(piVar3 + 0xc) = 1;
            *(undefined1 *)(piVar5[2] + 0x30) = 1;
            FUN_00821aa0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xc] == '\0') {
            *(undefined1 *)(piVar5 + 0xc) = 1;
            *(undefined1 *)(piVar3 + 0xc) = 0;
            FUN_0049ff90(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x31) == '\0') {
            if ((*(char *)(piVar5[2] + 0x30) != '\x01') || (*(char *)(*piVar5 + 0x30) != '\x01')) {
              if (*(char *)(*piVar5 + 0x30) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x30) = 1;
                *(undefined1 *)(piVar5 + 0xc) = 0;
                FUN_00821aa0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xc) = (char)piVar3[0xc];
              *(undefined1 *)(piVar3 + 0xc) = 1;
              *(undefined1 *)(*piVar5 + 0x30) = 1;
              FUN_0049ff90(piVar3);
              break;
            }
LAB_00894e04:
            *(undefined1 *)(piVar5 + 0xc) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xc) = 1;
  }
  if ((uint)param_2[0xb] < 0x10) {
    param_2[0xb] = 0xf;
    param_2[10] = 0;
    *(undefined1 *)(param_2 + 6) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[6]);
  return;
}


// ==== FUN_00894eb0 @ 0x00894eb0 ====

void FUN_00894eb0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x31) != '\0') {
    return;
  }
  FUN_00894eb0(*(undefined4 *)((int)param_1 + 8));
  if (*(uint *)((int)param_1 + 0x2c) < 0x10) {
    *(undefined4 *)((int)param_1 + 0x2c) = 0xf;
    *(undefined4 *)((int)param_1 + 0x28) = 0;
    *(undefined1 *)((int)param_1 + 0x18) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x18));
  return;
}


// ==== FUN_00894f10 @ 0x00894f10 ====

void FUN_00894f10(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00894eb0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x31) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x31) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x31);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x31);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x31);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x31);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00894bd0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00894fd0 @ 0x00894fd0 ====

void FUN_00894fd0(byte param_1)

{
  void *in_ECX;
  
  FUN_008943a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00894ff0 @ 0x00894ff0 ====

void FUN_00894ff0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_40 [16];
  
  puVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_00895010 @ 0x00895010 ====

void FUN_00895010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15290;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00895030 @ 0x00895030 ====

undefined4 FUN_00895030(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x74);
}


// ==== FUN_00895040 @ 0x00895040 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00895040(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar3 = DAT_009b0318;
  uVar2 = DAT_0099d080;
  fVar1 = (float)*(int *)(in_ECX + 0x7c);
  *(undefined4 *)(in_ECX + 4) = DAT_009b0318;
  *(undefined4 *)(in_ECX + 8) = uVar3;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  *(undefined4 *)(in_ECX + 0x14) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  if (*(int *)(in_ECX + 0x7c) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar1 = fVar1 - DAT_0099d0b4;
  *(float *)(in_ECX + 0x20) = fVar1;
  *(undefined4 *)(in_ECX + 0x24) = uVar3;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = uVar2;
  *(undefined4 *)(in_ECX + 0x3c) = uVar3;
  *(float *)(in_ECX + 0x40) = fVar1;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = uVar2;
  *(float *)(in_ECX + 0x58) = fVar1;
  *(float *)(in_ECX + 0x5c) = fVar1;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = uVar2;
  *(undefined4 *)(in_ECX + 0x30) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x34) = uVar2;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = uVar2;
  *(undefined4 *)(in_ECX + 0x68) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x6c) = uVar2;
  *(undefined4 *)(in_ECX + 0x70) = uVar2;
  return;
}


// ==== FUN_00895190 @ 0x00895190 ====

void FUN_00895190(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x74);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x74) = 0;
  }
  return;
}


// ==== FUN_008951b0 @ 0x008951b0 ====

void FUN_008951b0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a152bc;
  in_ECX[0x1f] = 0x100;
  in_ECX[0x36] = 0xf;
  in_ECX[0x35] = 0;
  *(undefined1 *)(in_ECX + 0x31) = 0;
  *(undefined1 *)(in_ECX + 0x37) = 0;
  *(undefined1 *)(in_ECX + 0x39) = 1;
  in_ECX[0x2e] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x21] = 0;
  uVar1 = DAT_0099d080;
  in_ECX[0x2f] = DAT_0099d080;
  in_ECX[0x2a] = uVar1;
  in_ECX[0x25] = uVar1;
  in_ECX[0x20] = uVar1;
  return;
}


// ==== FUN_00895270 @ 0x00895270 ====

void FUN_00895270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a152bc;
  if (in_ECX[0x1e] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x1e]);
    in_ECX[0x1e] = 0;
  }
  if ((uint)in_ECX[0x36] < 0x10) {
    in_ECX[0x36] = 0xf;
    in_ECX[0x35] = 0;
    *(undefined1 *)(in_ECX + 0x31) = 0;
    *in_ECX = &PTR_FUN_00a15290;
    return;
  }
  _free((void *)in_ECX[0x31]);
  return;
}


// ==== FUN_008952d0 @ 0x008952d0 ====

void FUN_008952d0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uStack_5c;
  void *pvStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  int *piStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int *piStack_14;
  
  uStack_2c = 0x15;
  uStack_30 = 3;
  uStack_34 = 1;
  uStack_38 = param_4;
  uStack_3c = param_5;
  uStack_40 = param_3;
  *(undefined4 *)(in_ECX + 0x7c) = 0x100;
  piStack_44 = param_1;
  uStack_48 = 0x8952fe;
  (**(code **)(*param_1 + 0x28))();
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_54 = 0x15;
  pvStack_58 = (void *)0x1;
  uStack_5c = 1;
  iStack_4c = in_ECX + 0x74;
  iVar1 = (**(code **)(*piStack_14 + 0x5c))
                    (piStack_14,*(undefined4 *)(in_ECX + 0x7c),*(undefined4 *)(in_ECX + 0x7c));
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x7c) = 0x100;
    (**(code **)(*piStack_14 + 0x5c))(piStack_14,0x100,0x100,1,1,0x15,0,in_ECX + 0x74,0);
  }
  FUN_00895040();
  piStack_44 = (int *)0xf;
  uStack_48 = 0;
  pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
  FUN_00401740(s_ad_main_dds_00a15258,0xb);
  uVar2 = FUN_004b4e70(&uStack_5c);
  *(undefined4 *)(in_ECX + 0x78) = uVar2;
  if (piStack_44 < 0x10) {
    return;
  }
  _free(pvStack_58);
  return;
}


// ==== FUN_008953a0 @ 0x008953a0 ====

void FUN_008953a0(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  undefined4 uVar7;
  
  if (*(char *)(in_ECX + 0xe4) != '\0') {
    piVar4 = (int *)FUN_0049b670();
    piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
    cVar3 = FUN_00881000(0x1c,0x70);
    if (cVar3 == '\0') {
      (**(code **)(*piVar1 + 0xc))();
    }
    (**(code **)(*piVar1 + 0x1c))(0x1c,0x70);
    (**(code **)(*piVar1 + 0x14))(0x70,in_ECX + 4);
    FUN_00881060();
    (**(code **)(*piVar4 + 0xac))(piVar4,0,0,3,0,0x3f800000,0);
    FUN_00858a60();
    (**(code **)(*piVar4 + 0x164))(piVar4,0x144);
    iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
    iVar5 = 0;
    if (*(int *)(in_ECX + 0x78) != 0) {
      piVar6 = (int *)FUN_004af750();
      iVar5 = (**(code **)(*piVar6 + 4))();
    }
    if (*(int *)(iVar2 + 0x134) != iVar5) {
      *(int *)(iVar2 + 0x134) = iVar5;
      (**(code **)(**(int **)(iVar2 + 0x90) + 0x104))(*(int **)(iVar2 + 0x90),0,iVar5);
    }
    piVar6 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    uVar7 = 0x1c;
    (**(code **)(*piVar6 + 400))(piVar6,0,piVar1[1],0,0x1c);
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 0x144))(piVar1,5,uVar7,2);
    (**(code **)(*piVar4 + 0x164))(piVar4,0);
    FUN_00858b90();
    *(undefined1 *)(in_ECX + 0xe4) = 0;
  }
  return;
}


// ==== FUN_00895640 @ 0x00895640 ====

void FUN_00895640(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0xdc) == '\0') {
    FUN_008953a0();
    return;
  }
  (**(code **)(**(int **)(DAT_00b5ac04 + 0x70) + 4))();
  return;
}


// ==== FUN_00895670 @ 0x00895670 ====

undefined4 FUN_00895670(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x7c);
}


// ==== FUN_00895680 @ 0x00895680 ====

void FUN_00895680(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x80);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_008956a0 @ 0x008956a0 ====

void FUN_008956a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00895270();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008956c0 @ 0x008956c0 ====

void FUN_008956c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1547c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00895740 @ 0x00895740 ====

void FUN_00895740(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = *(int **)(in_ECX + 8);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  piVar2 = *(int **)(in_ECX + 4);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x14);
  for (piVar2 = *(int **)(in_ECX + 0x10); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
    }
  }
  return;
}


// ==== FUN_00895790 @ 0x00895790 ====

void FUN_00895790(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a154c4;
  FUN_00895740();
  FUN_004eb890(in_ECX + 3);
  DAT_00b5af70 = 0;
  if ((void *)in_ECX[4] == (void *)0x0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    *in_ECX = &PTR_FUN_00a1547c;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_008957e0 @ 0x008957e0 ====

void FUN_008957e0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  uint uStack_48;
  undefined4 auStack_38 [14];
  
  iVar4 = (**(code **)(*DAT_00b5ac00 + 8))();
  *(bool *)(in_ECX + 0x20) = 2 < *(byte *)(iVar4 + 9);
  if (**(int **)(in_ECX + 0x10) == 0) {
    pvVar5 = operator_new(0x9c);
    if (pvVar5 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0089c700();
    }
    **(undefined4 **)(in_ECX + 0x10) = uVar6;
    pvVar5 = operator_new(0xf4);
    if (pvVar5 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0089bea0();
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + 4) = uVar6;
    pvVar5 = operator_new(0xdc);
    if (pvVar5 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0089b570();
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + 8) = uVar6;
    pvVar5 = operator_new(0x154);
    if (pvVar5 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0089ac70();
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0xc) = uVar6;
    pvVar5 = operator_new(0x8c);
    if (pvVar5 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0089a800();
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x10) = uVar6;
    pvVar5 = operator_new(0xe8);
    if (pvVar5 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_008951b0();
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x14) = uVar6;
    if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xea) == '\x01') {
      pvVar5 = operator_new(0x8c);
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0089a450();
      }
      *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x18) = uVar6;
      pvVar5 = operator_new(0x50);
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0089a130();
      }
      *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x1c) = uVar6;
    }
  }
  uVar6 = *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x8c);
  uVar7 = FUN_0049b670();
  uVar1 = *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xac);
  puVar8 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x28);
  puVar10 = auStack_38;
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar10 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar10 = puVar10 + 1;
  }
  iVar4 = *(int *)(DAT_00b5ac04 + 0x28);
  uVar2 = *(undefined4 *)(iVar4 + 0x10c);
  uStack_48 = *(uint *)(iVar4 + 0x9c);
  if (*(uint *)(iVar4 + 0xa0) <= *(uint *)(iVar4 + 0x9c)) {
    uStack_48 = *(uint *)(iVar4 + 0xa0);
  }
  piVar3 = *(int **)(in_ECX + 0x14);
  for (piVar9 = *(int **)(in_ECX + 0x10); piVar9 != piVar3; piVar9 = piVar9 + 1) {
    if ((int *)*piVar9 != (int *)0x0) {
      (**(code **)(*(int *)*piVar9 + 8))(uVar6,uVar7,uVar1,auStack_38[2],uVar2,uStack_48);
    }
  }
  return;
}


// ==== FUN_008959d0 @ 0x008959d0 ====

void FUN_008959d0(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  void *unaff_EBX;
  undefined1 local_54 [4];
  undefined1 local_50;
  uint uStack_44;
  undefined4 local_40;
  void *local_3c;
  undefined1 auStack_38 [12];
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  uint uStack_c;
  
  local_3c = (void *)0xf;
  local_40 = 0;
  local_50 = 0;
  pcVar2 = PTR_s_RealDataPath_00b52e48;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_RealDataPath_00b52e48,(int)pcVar2 - (int)(PTR_s_RealDataPath_00b52e48 + 1));
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar4 = (**(code **)(*piVar3 + 8))(auStack_38,local_54,s_Warfog_dds_00a15438);
  FUN_00402220(auStack_24,uVar4);
  if (0xf < uStack_28) {
    _free(local_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  if (0xf < uStack_44) {
    _free(unaff_EBX);
    return;
  }
  FUN_0089afd0(auStack_24);
  if (uStack_c < 0x10) {
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_00895ab0 @ 0x00895ab0 ====

void FUN_00895ab0(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  void *unaff_EBX;
  undefined1 local_54 [4];
  undefined1 local_50;
  uint uStack_44;
  undefined4 local_40;
  void *local_3c;
  undefined1 auStack_38 [12];
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  uint uStack_c;
  
  local_3c = (void *)0xf;
  local_40 = 0;
  local_50 = 0;
  pcVar2 = PTR_s_RealDataPath_00b52e48;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_RealDataPath_00b52e48,(int)pcVar2 - (int)(PTR_s_RealDataPath_00b52e48 + 1));
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar4 = (**(code **)(*piVar3 + 8))(auStack_38,local_54,s_Warfog_dds_00a15444);
  FUN_00402220(auStack_24,uVar4);
  if (0xf < uStack_28) {
    _free(local_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  if (0xf < uStack_44) {
    _free(unaff_EBX);
    return;
  }
  uVar4 = FUN_0049b670();
  FUN_0089b2f0(uVar4,auStack_24);
  if (uStack_c < 0x10) {
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_00895b90 @ 0x00895b90 ====

void FUN_00895b90(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 auStack_38 [14];
  
  iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (2 < *(byte *)(iVar3 + 9) != (bool)*(char *)(in_ECX + 0x20)) {
    (**(code **)(*(int *)**(undefined4 **)(in_ECX + 0x10) + 0xc))();
    uVar1 = *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x8c);
    uVar4 = FUN_0049b670();
    uVar2 = *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xac);
    puVar6 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x28);
    puVar7 = auStack_38;
    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    iVar3 = *(int *)(DAT_00b5ac04 + 0x28);
    uVar8 = *(undefined4 *)(iVar3 + 0x10c);
    uVar5 = *(uint *)(iVar3 + 0x9c);
    if (*(uint *)(iVar3 + 0xa0) <= *(uint *)(iVar3 + 0x9c)) {
      uVar5 = *(uint *)(iVar3 + 0xa0);
    }
    (**(code **)(*(int *)**(undefined4 **)(in_ECX + 0x10) + 8))
              (uVar1,uVar4,uVar2,auStack_38[2],uVar8,uVar5);
    *(char *)(in_ECX + 0x20) = (char)((uint)uVar8 >> 0x18);
  }
  return;
}


// ==== FUN_00895c40 @ 0x00895c40 ====

void FUN_00895c40(uint param_1)

{
  int iVar1;
  code *pcVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  if (*(int *)(iVar1 + param_1 * 4) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_vecRenderUnit_at__i_eType______00a15320,0x25);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_18);
    return;
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + param_1 * 4) + 4))();
  return;
}


// ==== FUN_00895ce0 @ 0x00895ce0 ====

undefined4 FUN_00895ce0(undefined4 param_1,uint param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  if (*(int *)(iVar1 + param_2 * 4) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_vecRenderUnit_at__i_eType______00a15348,0x25);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    _free(local_18);
    return extraout_EAX;
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + param_2 * 4) + 0x18))(param_1);
  return param_1;
}


// ==== FUN_00895d90 @ 0x00895d90 ====

undefined4 FUN_00895d90(undefined4 param_1,uint param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  if (*(int *)(iVar1 + param_2 * 4) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_vecRenderUnit_at__i_eType______00a15370,0x25);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    _free(local_18);
    return extraout_EAX;
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + param_2 * 4) + 0x14))(param_1);
  return param_1;
}


// ==== FUN_00895e40 @ 0x00895e40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00895e40(uint param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  float10 extraout_ST0;
  float10 fVar3;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar2 = *(int *)(in_ECX + 0x10);
  if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar2 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  if (*(int *)(iVar2 + param_1 * 4) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_vecRenderUnit_at__i_eType______00a15398,0x25);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      fVar3 = (float10)(*pcVar1)();
      return fVar3;
    }
    _free(local_18);
    return extraout_ST0;
  }
  iVar2 = *(int *)(in_ECX + 0x10);
  if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar2 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  iVar2 = (**(code **)(**(int **)(iVar2 + param_1 * 4) + 0x1c))();
  fVar3 = (float10)iVar2;
  if (iVar2 < 0) {
    fVar3 = fVar3 + (float10)_DAT_0099d104;
  }
  return fVar3;
}


// ==== FUN_00895ef0 @ 0x00895ef0 ====

undefined4 FUN_00895ef0(uint param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  if (*(int *)(iVar1 + param_1 * 4) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_vecRenderUnit_at__i_eType______00a153c0,0x25);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    _free(local_18);
    return extraout_EAX;
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}


// ==== FUN_00895f90 @ 0x00895f90 ====

void FUN_00895f90(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  uint unaff_EBX;
  
  (**(code **)(*param_1 + 0x98))(param_1,0,in_ECX + 4);
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= unaff_EBX)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + unaff_EBX * 4) + 4))();
  (**(code **)(*piVar2 + 0x48))(piVar2,0,(undefined4 *)(in_ECX + 8));
  (**(code **)(*param_1 + 0x94))(param_1,0,*(undefined4 *)(in_ECX + 8));
  (**(code **)(*param_1 + 0xa4))(param_1);
  return;
}


// ==== FUN_00896000 @ 0x00896000 ====

void FUN_00896000(uint param_1)

{
  int iVar1;
  code *pcVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  if (*(int *)(iVar1 + param_1 * 4) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_vecRenderUnit_at__i_eType______00a15410,0x25);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_18);
    return;
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + param_1 * 4) + 0x24))();
  return;
}


// ==== FUN_008960a0 @ 0x008960a0 ====

void FUN_008960a0(void)

{
  undefined4 *in_ECX;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a154c4;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5af70 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5af70 = in_ECX;
  }
  local_4 = 0;
  FUN_00896280(in_ECX[4],9,&local_4);
  return;
}


// ==== FUN_00896100 @ 0x00896100 ====

void FUN_00896100(uint param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  if (*(int *)(iVar1 + param_1 * 4) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_vecRenderUnit_at__i_eType______00a153e8,0x25);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_18);
    return;
  }
  piVar3 = (int *)FUN_0049b670();
  FUN_00895f90(piVar3,param_1);
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + param_1 * 4) + 0x10))(piVar3);
  (**(code **)(*piVar3 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x94))(piVar3,0,*(undefined4 *)(in_ECX + 4));
  piVar3 = *(int **)(in_ECX + 4);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  piVar3 = *(int **)(in_ECX + 8);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_00896200 @ 0x00896200 ====

float10 FUN_00896200(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x1c);
}


// ==== FUN_00896210 @ 0x00896210 ====

void FUN_00896210(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== FUN_00896220 @ 0x00896220 ====

void FUN_00896220(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a154c4;
  FUN_00895740();
  FUN_004eb890(in_ECX + 3);
  DAT_00b5af70 = 0;
  if ((void *)in_ECX[4] != (void *)0x0) {
    _free((void *)in_ECX[4]);
    return;
  }
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  *in_ECX = &PTR_FUN_00a1547c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00896280 @ 0x00896280 ====

void FUN_00896280(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a880;
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


// ==== Catch@008963e1 @ 0x008963e1 ====

void Catch_008963e1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_008964d0 @ 0x008964d0 ====

void FUN_008964d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1558c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008964f0 @ 0x008964f0 ====

undefined4 FUN_008964f0(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x10) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_environment_cube_test__dds_00a15540,0x1a);
    uVar1 = FUN_004b4e70(local_1c);
    *(undefined4 *)(in_ECX + 0x10) = uVar1;
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00896550 @ 0x00896550 ====

undefined4 FUN_00896550(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_empty_dds_00a1555c,9);
    uVar1 = FUN_004b4e70(local_1c);
    *(undefined4 *)(in_ECX + 0x14) = uVar1;
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_008965b0 @ 0x008965b0 ====

undefined4 FUN_008965b0(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x18) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_white_dds_00a15568,9);
    uVar1 = FUN_004b4e70(local_1c);
    *(undefined4 *)(in_ECX + 0x18) = uVar1;
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  return *(undefined4 *)(in_ECX + 0x18);
}


// ==== FUN_00896610 @ 0x00896610 ====

void FUN_00896610(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 8);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (puVar3[10] != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(puVar3[10]);
    }
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
  FUN_004ad020(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  if (*(int *)(in_ECX + 0x10) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x10));
    *(undefined4 *)(in_ECX + 0x10) = 0;
  }
  if (*(int *)(in_ECX + 0x14) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x14));
    *(undefined4 *)(in_ECX + 0x14) = 0;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x18));
    *(undefined4 *)(in_ECX + 0x18) = 0;
  }
  return;
}


// ==== FUN_008966f0 @ 0x008966f0 ====

undefined4 FUN_008966f0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  int aiStack_28 [2];
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  iVar1 = (**(code **)(*DAT_00b5af74 + 4))();
  iVar1 = iVar1 + 0x10;
  FUN_0069a470(aiStack_28,iVar1);
  if (aiStack_28[0] != *(int *)(in_ECX + 8)) {
    return *(undefined4 *)(aiStack_28[0] + 0x28);
  }
  uVar2 = FUN_004b4e70(iVar1);
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  uStack_4 = uVar2;
  FUN_004d4e50(aiStack_28,auStack_20);
  if (uStack_8 < 0x10) {
    return uVar2;
  }
  _free(pvStack_1c);
  return extraout_EAX;
}


// ==== FUN_00896790 @ 0x00896790 ====

void FUN_00896790(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a155a4;
  FUN_00896610();
  DAT_00b5d98c = 0;
  FUN_004ad0e0(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_008967f0 @ 0x008967f0 ====

void FUN_008967f0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a155a4;
  iVar1 = FUN_004a37b0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d98c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d98c = in_ECX;
  return;
}


// ==== FUN_00896850 @ 0x00896850 ====

void FUN_00896850(byte param_1)

{
  void *in_ECX;
  
  FUN_00896790();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00896870 @ 0x00896870 ====

void FUN_00896870(void)

{
  undefined1 *in_ECX;
  
  *in_ECX = 1;
  return;
}


// ==== FUN_008968a0 @ 0x008968a0 ====

void FUN_008968a0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x54);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x54) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x60);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x60) = 0;
  }
  return;
}


// ==== FUN_00896920 @ 0x00896920 ====

void FUN_00896920(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x54);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x54) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x60);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x60) = 0;
  }
  if (*(void **)(in_ECX + 0x40) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x40) = 0;
    *(undefined4 *)(in_ECX + 0x44) = 0;
    *(undefined4 *)(in_ECX + 0x48) = 0;
    FUN_00897490();
    _free(*(void **)(in_ECX + 0x34));
    return;
  }
  _free(*(void **)(in_ECX + 0x40));
  return;
}


// ==== FUN_008969a0 @ 0x008969a0 ====

void FUN_008969a0(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_30;
  int *piStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  
  iVar2 = (-(uint)(*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe8) != '\0') & 0xfffffff0) + 0x218;
  uStack_14 = 0x8969c6;
  piVar1 = (int *)FUN_0049b670();
  uStack_14 = 0;
  iStack_18 = in_ECX + 0x54;
  uStack_1c = 0;
  uStack_20 = 0;
  uStack_28 = 0x100000;
  uStack_30 = 0x8969de;
  piStack_2c = piVar1;
  iStack_24 = iVar2;
  (**(code **)(*piVar1 + 0x68))();
  uStack_30 = 0;
  iStack_34 = in_ECX + 0x60;
  uStack_38 = 0;
  uStack_3c = 0x65;
  *(undefined4 *)(in_ECX + 0x58) = 0x100000;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  (**(code **)(*piVar1 + 0x6c))(piVar1,0x40000,iVar2);
  *(undefined4 *)(in_ECX + 100) = 0x40000;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  FUN_00897b60();
  FUN_00897490();
  uStack_3c = *(undefined4 *)(in_ECX + 0x34);
  FUN_008977a0(9,&uStack_3c);
  *(undefined4 *)(in_ECX + 0x4c) = 1;
  *(undefined4 *)(in_ECX + 0x50) = 1;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  *(uint *)(in_ECX + 0x6c) = (-(uint)(*(int *)(iVar2 + 8) != 0) & 0xc) + 0x24;
  return;
}


// ==== FUN_00896a70 @ 0x00896a70 ====

void FUN_00896a70(void)

{
  int in_ECX;
  undefined4 local_4;
  
  FUN_00897b60();
  FUN_00897490();
  local_4 = *(undefined4 *)(in_ECX + 0x34);
  FUN_008977a0(9,&local_4);
  *(undefined4 *)(in_ECX + 0x4c) = 1;
  *(undefined4 *)(in_ECX + 0x50) = 1;
  return;
}


// ==== FUN_00896ab0 @ 0x00896ab0 ====

uint FUN_00896ab0(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puStack_28;
  undefined4 *apuStack_14 [5];
  
  puStack_28 = (undefined4 *)0x896ac4;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  puStack_28 = (undefined4 *)0x896acb;
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  if (*(int *)(iVar2 + 8) == 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0xc4) + 0x20);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(*(int *)(param_1 + 0xc4) + 0x24) - iVar2) / 0x24;
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0xc4) + 0x10);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(*(int *)(param_1 + 0xc4) + 0x14) - iVar2) / 0x30;
    }
  }
  uVar6 = *(int *)(in_ECX + 0x6c) * iVar2;
  piVar1 = *(int **)(in_ECX + 0x54);
  if (*(int *)(in_ECX + 0x5c) + uVar6 < *(uint *)(in_ECX + 0x58)) {
    puStack_28 = (undefined4 *)0x1000;
    (**(code **)(*piVar1 + 0x2c))(piVar1,*(int *)(in_ECX + 0x5c),uVar6,apuStack_14);
    uVar3 = *(uint *)(in_ECX + 0x5c) / *(uint *)(in_ECX + 0x6c);
    *(uint *)(in_ECX + 0x5c) = *(uint *)(in_ECX + 0x5c) + uVar6;
  }
  else {
    puStack_28 = (undefined4 *)0x2000;
    (**(code **)(*piVar1 + 0x2c))(piVar1,0,uVar6,apuStack_14);
    uVar3 = 0;
    *(uint *)(in_ECX + 0x5c) = uVar6;
    FUN_00897b60();
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  uVar4 = uVar6 >> 2;
  puVar7 = puStack_28;
  if (*(int *)(iVar2 + 8) == 0) {
    puVar5 = *(undefined4 **)(*(int *)(param_1 + 0xc4) + 0x20);
  }
  else {
    puVar5 = *(undefined4 **)(*(int *)(param_1 + 0xc4) + 0x10);
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  (**(code **)(**(int **)(in_ECX + 0x54) + 0x30))(*(int **)(in_ECX + 0x54));
  puStack_28 = apuStack_14[0];
  FUN_00897930(apuStack_14 + -3,&puStack_28);
  return uVar3;
}


// ==== FUN_00896c00 @ 0x00896c00 ====

void FUN_00896c00(void)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = 1;
  in_ECX[4] = local_5;
  uVar1 = FUN_00897100();
  *(undefined4 *)(in_ECX + 0xc) = uVar1;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  local_4 = *(undefined4 *)(in_ECX + 0xc);
  FUN_008977f0(9,&local_4);
  *(undefined4 *)(in_ECX + 0x24) = 1;
  *(undefined4 *)(in_ECX + 0x28) = 1;
  in_ECX[0x2c] = local_5;
  uVar1 = FUN_00897220();
  *(undefined4 *)(in_ECX + 0x34) = uVar1;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  local_4 = *(undefined4 *)(in_ECX + 0x34);
  FUN_008977f0(9,&local_4);
  *(undefined4 *)(in_ECX + 0x4c) = 1;
  *(undefined4 *)(in_ECX + 0x50) = 1;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  FUN_008969a0();
  return;
}


// ==== FUN_00896ca0 @ 0x00896ca0 ====

/* WARNING: Removing unreachable block (ram,0x00896d99) */
/* WARNING: Removing unreachable block (ram,0x00896da0) */

undefined4 FUN_00896ca0(undefined4 param_1,int param_2)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int *unaff_ESI;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *unaff_EDI;
  undefined4 *puVar13;
  void *_Memory;
  undefined4 uStack_4c;
  undefined1 auStack_36 [2];
  void *local_34;
  uint *local_30;
  int aiStack_2c [2];
  void *pvStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  
  local_30 = *(uint **)(*(int *)(param_2 + 0xc4) + 0x30);
  puVar2 = (uint *)*local_30;
  iVar11 = 0;
  while (puVar2 != local_30) {
    if (puVar2[8] == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = (int)(puVar2[9] - puVar2[8]) >> 1;
    }
    iVar11 = iVar11 + iVar8 * 2;
    if (*(char *)((int)puVar2 + 0x2d) == '\0') {
      puVar3 = (uint *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x2d);
        puVar2 = puVar3;
        puVar3 = (uint *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x2d);
          puVar2 = puVar3;
          puVar3 = (uint *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x2d);
        puVar5 = (uint *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar5, cVar1 == '\0' && (puVar3 == (uint *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x2d);
          puVar5 = (uint *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  if ((uint)(*(int *)(in_ECX + 0x68) + iVar11) < *(uint *)(in_ECX + 100)) {
    uStack_4c = 0x1000;
    (**(code **)(**(int **)(in_ECX + 0x60) + 0x2c))
              (*(int **)(in_ECX + 0x60),*(int *)(in_ECX + 0x68),iVar11,&local_34);
    uStack_4c = *(uint *)(in_ECX + 0x68) >> 1;
    *(uint *)(in_ECX + 0x68) = *(uint *)(in_ECX + 0x68) + iVar11;
  }
  else {
    uStack_4c = 0x2000;
    (**(code **)(**(int **)(in_ECX + 0x60) + 0x2c))(*(int **)(in_ECX + 0x60),0,iVar11,&local_34);
    uStack_4c = 0;
    *(int *)(in_ECX + 0x68) = iVar11;
    FUN_00897490();
    if (*(int *)(in_ECX + 0x40) != *(int *)(in_ECX + 0x44)) {
      *(int *)(in_ECX + 0x44) = *(int *)(in_ECX + 0x40);
    }
    FUN_00897550(*(undefined4 *)(in_ECX + 0x40),9,auStack_36 + -10);
    *(undefined4 *)(in_ECX + 0x4c) = 1;
    *(undefined4 *)(in_ECX + 0x50) = 1;
  }
  piVar10 = (int *)**(int **)(*(int *)(iStack_c + 0xc4) + 0x30);
  _Memory = (void *)0x0;
  if (piVar10 != unaff_ESI) {
    do {
      if (piVar10[8] == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = piVar10[9] - piVar10[8] >> 1;
      }
      puVar12 = (undefined4 *)piVar10[8];
      puVar13 = unaff_EDI;
      for (uVar9 = (uVar7 & 0x7fffffff) >> 1; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar13 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar13 = puVar13 + 1;
      }
      for (uVar7 = uVar7 * 2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
        puVar12 = (undefined4 *)((int)puVar12 + 1);
        puVar13 = (undefined4 *)((int)puVar13 + 1);
      }
      if (piVar10[8] == 0) {
        iVar11 = 0;
      }
      else {
        iVar11 = piVar10[9] - piVar10[8] >> 1;
      }
      unaff_EDI = (undefined4 *)((int)unaff_EDI + iVar11 * 2);
      if ((local_34 == (void *)0x0) ||
         ((uint)(aiStack_2c[0] - (int)local_34 >> 2) <= (uint)((int)local_30 - (int)local_34 >> 2)))
      {
        FUN_0042f3e0(local_30,1,&uStack_4c);
      }
      else {
        *local_30 = uStack_4c;
        local_30 = local_30 + 1;
      }
      if (piVar10[8] == 0) {
        iVar11 = 0;
      }
      else {
        iVar11 = piVar10[9] - piVar10[8] >> 1;
      }
      uStack_4c = uStack_4c + iVar11;
      if (*(char *)((int)piVar10 + 0x2d) == '\0') {
        piVar4 = (int *)piVar10[2];
        if (*(char *)((int)piVar4 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar4 + 0x2d);
          piVar10 = piVar4;
          piVar4 = (int *)*piVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x2d);
            piVar10 = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar1 = *(char *)(piVar10[1] + 0x2d);
          piVar6 = (int *)piVar10[1];
          piVar4 = piVar10;
          while ((piVar10 = piVar6, cVar1 == '\0' && (piVar4 == (int *)piVar10[2]))) {
            cVar1 = *(char *)(piVar10[1] + 0x2d);
            piVar6 = (int *)piVar10[1];
            piVar4 = piVar10;
          }
        }
      }
    } while (piVar10 != unaff_ESI);
    _Memory = local_34;
  }
  (**(code **)(**(int **)(in_ECX + 0x60) + 0x30))(*(int **)(in_ECX + 0x60));
  aiStack_2c[0] = iStack_10;
  FUN_00430c20(auStack_36 + -6);
  FUN_00897bc0(auStack_36 + -0xe,aiStack_2c);
  if (pvStack_24 != (void *)0x0) {
    _free(pvStack_24);
    return extraout_EAX;
  }
  FUN_00430c20(auStack_36 + -6);
  if (_Memory == (void *)0x0) {
    return uStack_14;
  }
  _free(_Memory);
  return extraout_EAX_00;
}


// ==== FUN_00896f50 @ 0x00896f50 ====

undefined4 * FUN_00896f50(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  char *in_ECX;
  int local_28;
  undefined1 local_24 [4];
  void *local_20;
  undefined4 local_14;
  undefined1 local_10 [4];
  void *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = (void *)0x0;
  local_8 = 0;
  local_4 = 0;
  FUN_00897340(&local_28,&param_2);
  uVar2 = param_2;
  if (local_28 == *(int *)(in_ECX + 0xc)) {
    local_14 = FUN_00896ab0(param_2);
  }
  else {
    local_14 = *(undefined4 *)(local_28 + 0xc);
  }
  FUN_00897340(&local_28,&param_2);
  if (local_28 == *(int *)(in_ECX + 0x34)) {
    uVar2 = FUN_00896ca0(local_24,uVar2);
    FUN_00430ad0(uVar2);
    if (local_20 != (void *)0x0) {
      _free(local_20);
      return extraout_EAX;
    }
  }
  else {
    FUN_00430ad0(local_28 + 0xc);
  }
  if (*in_ECX != '\0') {
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 400))
              (piVar1,0,*(undefined4 *)(in_ECX + 0x54),0,*(undefined4 *)(in_ECX + 0x6c));
    FUN_0084b7f0(*(undefined4 *)(in_ECX + 0x60));
    *in_ECX = '\0';
  }
  *param_1 = local_14;
  FUN_00430c20(local_10);
  if (local_c == (void *)0x0) {
    return param_1;
  }
  _free(local_c);
  return extraout_EAX_00;
}


// ==== FUN_00897070 @ 0x00897070 ====

void FUN_00897070(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
  }
  return;
}


// ==== FUN_00897090 @ 0x00897090 ====

int FUN_00897090(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a890;
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


// ==== Catch@008970f6 @ 0x008970f6 ====

void Catch_008970f6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00897100 @ 0x00897100 ====

void FUN_00897100(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a8a0;
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


// ==== Catch@0089716f @ 0x0089716f ====

void Catch_0089716f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00897190 @ 0x00897190 ====

void * FUN_00897190(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a8b0;
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


// ==== Catch@008971fd @ 0x008971fd ====

void Catch_008971fd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00897220 @ 0x00897220 ====

void FUN_00897220(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a8c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0089728f @ 0x0089728f ====

void Catch_0089728f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008972b0 @ 0x008972b0 ====

void FUN_008972b0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a8d0;
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


// ==== Catch@00897316 @ 0x00897316 ====

void Catch_00897316(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00897320 @ 0x00897320 ====

void FUN_00897320(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00897090(param_1,param_2,param_3);
  return;
}


// ==== FUN_00897340 @ 0x00897340 ====

void FUN_00897340(undefined4 *param_1,uint *param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int in_ECX;
  
  uVar2 = *param_2;
  uVar3 = (uVar2 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar3) {
    uVar3 = uVar3 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  piVar1 = (int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4);
  piVar4 = (int *)*piVar1;
  if (piVar4 != (int *)piVar1[1]) {
    do {
      if (uVar2 <= (uint)piVar4[2]) {
        if (uVar2 < (uint)piVar4[2]) {
          *param_1 = *(undefined4 *)(in_ECX + 8);
          return;
        }
        *param_1 = piVar4;
        return;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)piVar1[1]);
  }
  *param_1 = *(undefined4 *)(in_ECX + 8);
  return;
}


// ==== FUN_008973d0 @ 0x008973d0 ====

int FUN_008973d0(int param_1,int param_2,undefined4 param_3)

{
  FUN_008972b0(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_00897400 @ 0x00897400 ====

void FUN_00897400(uint param_1)

{
  int in_ECX;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (0xcccccccU - *(int *)(in_ECX + 8) < param_1) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_list<T>_too_long_0099d1d0,0x10);
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
  *(uint *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return;
}


// ==== FUN_00897490 @ 0x00897490 ====

void FUN_00897490(void)

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
  if (*(void **)((int)_Memory + 0x10) == (void *)0x0) {
    *(undefined4 *)((int)_Memory + 0x10) = 0;
    *(undefined4 *)((int)_Memory + 0x14) = 0;
    *(undefined4 *)((int)_Memory + 0x18) = 0;
    _free(_Memory);
    return;
  }
  _free(*(void **)((int)_Memory + 0x10));
  return;
}


// ==== FUN_008974e0 @ 0x008974e0 ====

void FUN_008974e0(uint param_1,undefined1 param_2)

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
    FUN_00897550(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00897550 @ 0x00897550 ====

void FUN_00897550(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a8e0;
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
      uVar5 = FUN_00897320(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_008973d0(uVar5,param_2,&local_18);
      FUN_00897320(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_00897090(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_008973d0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_00897090(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008976b1 @ 0x008976b1 ====

void Catch_008976b1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_008977a0 @ 0x008977a0 ====

/* WARNING: Removing unreachable block (ram,0x008977bb) */
/* WARNING: Removing unreachable block (ram,0x008977c0) */
/* WARNING: Removing unreachable block (ram,0x008977ce) */

void FUN_008977a0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_00897550(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_008977f0 @ 0x008977f0 ====

void FUN_008977f0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a8f0;
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
    uVar2 = FUN_008973d0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00897884 @ 0x00897884 ====

void Catch_00897884(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008978a0 @ 0x008978a0 ====

void * FUN_008978a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a900;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x1c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_005ce180(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0089790d @ 0x0089790d ====

void Catch_0089790d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00897930 @ 0x00897930 ====

/* WARNING: Removing unreachable block (ram,0x00897a18) */

void FUN_00897930(int *param_1,uint *param_2)

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
      FUN_008974e0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_00897190(puVar7,puVar7[1],param_2);
  FUN_00833ae0(1);
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


// ==== FUN_00897b60 @ 0x00897b60 ====

void FUN_00897b60(void)

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
    FUN_008977a0(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00897bc0 @ 0x00897bc0 ====

/* WARNING: Removing unreachable block (ram,0x00897ca8) */

void FUN_00897bc0(int *param_1,uint *param_2)

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
      FUN_008974e0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_008978a0(puVar7,puVar7[1],param_2);
  FUN_00897400(1);
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


// ==== FUN_00897df0 @ 0x00897df0 ====

void FUN_00897df0(void)

{
  undefined1 *in_ECX;
  
  *in_ECX = 1;
  return;
}


// ==== FUN_00897e20 @ 0x00897e20 ====

void FUN_00897e20(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x54);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x54) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x60);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x60) = 0;
  }
  return;
}


// ==== FUN_00897e80 @ 0x00897e80 ====

void FUN_00897e80(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int local_4;
  
  uVar1 = param_1;
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0xc)) {
    FUN_00598f60(&param_1,local_4);
  }
  param_1 = uVar1;
  FUN_00897340(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0x34)) {
    FUN_00598f60(&param_1,local_4);
  }
  return;
}


// ==== FUN_00897f10 @ 0x00897f10 ====

void FUN_00897f10(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x54);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x54) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x60);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x60) = 0;
  }
  if (*(void **)(in_ECX + 0x40) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x40));
    return;
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  FUN_008984a0();
  if (*(void **)(in_ECX + 0x18) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    FUN_008984a0();
    return;
  }
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_00897f80 @ 0x00897f80 ====

void FUN_00897f80(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = (-(uint)(*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe8) != '\0') & 0xfffffff0) + 0x218;
  piVar1 = (int *)FUN_0049b670();
  (**(code **)(*piVar1 + 0x68))(piVar1,0x400000,iVar2,0,0,in_ECX + 0x54,0);
  *(undefined4 *)(in_ECX + 0x58) = 0x400000;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  (**(code **)(*piVar1 + 0x6c))(piVar1,0x80000,iVar2,0x65,0,in_ECX + 0x60,0);
  *(undefined4 *)(in_ECX + 100) = 0x80000;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  FUN_00898cc0();
  FUN_00898cc0();
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  *(uint *)(in_ECX + 0x6c) = (-(uint)(*(int *)(iVar2 + 8) != 0) & 0x10) + 0x38;
  return;
}


// ==== FUN_00898030 @ 0x00898030 ====

undefined4 * FUN_00898030(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uStack_28;
  undefined1 local_14 [20];
  
  iVar7 = *(int *)(param_1 + 0x88) * *(int *)(in_ECX + 0x6c);
  piVar2 = *(int **)(in_ECX + 0x54);
  if ((uint)(*(int *)(in_ECX + 0x5c) + iVar7) < *(uint *)(in_ECX + 0x58)) {
    uStack_28 = (undefined4 *)0x1000;
    (**(code **)(*piVar2 + 0x2c))(piVar2,*(int *)(in_ECX + 0x5c),iVar7,local_14);
    *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x5c) + iVar7;
  }
  else {
    uStack_28 = (undefined4 *)0x2000;
    (**(code **)(*piVar2 + 0x2c))(piVar2,0,iVar7,local_14);
    *(int *)(in_ECX + 0x5c) = iVar7;
    FUN_00898cc0();
  }
  iVar7 = FUN_004b9c10();
  iVar6 = 0;
  if (0 < iVar7) {
    do {
      iVar1 = FUN_004ba010(iVar6);
      piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
      iVar3 = (**(code **)(*piVar2 + 0x1c))();
      if (*(int *)(iVar3 + 8) == 0) {
        if (*(int *)(iVar1 + 0x3c) == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = (*(int *)(iVar1 + 0x40) - *(int *)(iVar1 + 0x3c)) / 0x38;
        }
        puVar8 = *(undefined4 **)(iVar1 + 0x3c);
      }
      else if (*(int *)(iVar1 + 0x4c) == 0) {
        iVar3 = 0;
        puVar8 = (undefined4 *)0x0;
      }
      else {
        puVar8 = *(undefined4 **)(iVar1 + 0x4c);
        iVar3 = (*(int *)(iVar1 + 0x50) - *(int *)(iVar1 + 0x4c)) / 0x48;
      }
      uVar4 = *(int *)(in_ECX + 0x6c) * iVar3;
      puVar9 = uStack_28;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      uStack_28 = (undefined4 *)((int)uStack_28 + uVar4);
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar7);
  }
  (**(code **)(**(int **)(in_ECX + 0x54) + 0x30))(*(int **)(in_ECX + 0x54));
  puVar8 = uStack_28;
  FUN_00898a90(&uStack_28,local_14 + -0xc);
  return puVar8;
}


// ==== FUN_00898190 @ 0x00898190 ====

uint FUN_00898190(int param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int unaff_EBP;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uStack_30;
  int iVar10;
  undefined4 local_1c;
  
  iVar10 = *(int *)(param_1 + 0x8c) * 2;
  piVar2 = *(int **)(in_ECX + 0x60);
  if ((uint)(*(int *)(in_ECX + 0x68) + iVar10) < *(uint *)(in_ECX + 100)) {
    uStack_30 = (undefined4 *)0x1000;
    (**(code **)(*piVar2 + 0x2c))(piVar2,*(int *)(in_ECX + 0x68),iVar10,&local_1c);
    uVar6 = *(uint *)(in_ECX + 0x68) >> 1;
    *(uint *)(in_ECX + 0x68) = *(uint *)(in_ECX + 0x68) + iVar10;
  }
  else {
    uStack_30 = (undefined4 *)0x2000;
    (**(code **)(*piVar2 + 0x2c))(piVar2,0,iVar10,&local_1c);
    uVar6 = 0;
    *(int *)(in_ECX + 0x68) = iVar10;
    FUN_00898cc0();
  }
  local_1c = FUN_004b9c10();
  iVar10 = 0;
  if (0 < (int)local_1c) {
    do {
      iVar1 = FUN_004ba010(iVar10);
      iVar7 = *(int *)(iVar1 + 0x2c);
      iVar1 = *(int *)(iVar1 + 0x30);
      if (iVar7 != iVar1) {
        piVar2 = (int *)(iVar7 + 0x18);
        do {
          puVar8 = (undefined4 *)*piVar2;
          if (puVar8 == (undefined4 *)0x0) {
            uVar3 = 0;
          }
          else {
            uVar3 = piVar2[1] - (int)puVar8 >> 1;
          }
          puVar9 = uStack_30;
          for (uVar4 = (uVar3 & 0x7fffffff) >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          for (uVar3 = uVar3 * 2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          if (*piVar2 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = piVar2[1] - *piVar2 >> 1;
          }
          iVar7 = iVar7 + 0x24;
          uStack_30 = (undefined4 *)((int)uStack_30 + iVar5 * 2);
          piVar2 = piVar2 + 9;
        } while (iVar7 != iVar1);
        in_ECX = unaff_EBP;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)local_1c);
  }
  (**(code **)(**(int **)(in_ECX + 0x60) + 0x30))(*(int **)(in_ECX + 0x60));
  local_1c = uVar6;
  FUN_00898a90((int)register0x00000010 + -0x28,(int)register0x00000010 + -0x20);
  return uVar6;
}


// ==== FUN_008982e0 @ 0x008982e0 ====

void FUN_008982e0(void)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = 1;
  in_ECX[4] = local_5;
  uVar1 = FUN_008984f0();
  *(undefined4 *)(in_ECX + 0xc) = uVar1;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  local_4 = *(undefined4 *)(in_ECX + 0xc);
  FUN_00898920(9,&local_4);
  *(undefined4 *)(in_ECX + 0x24) = 1;
  *(undefined4 *)(in_ECX + 0x28) = 1;
  in_ECX[0x2c] = local_5;
  uVar1 = FUN_008984f0();
  *(undefined4 *)(in_ECX + 0x34) = uVar1;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  local_4 = *(undefined4 *)(in_ECX + 0x34);
  FUN_00898920(9,&local_4);
  *(undefined4 *)(in_ECX + 0x4c) = 1;
  *(undefined4 *)(in_ECX + 0x50) = 1;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  FUN_00897f80();
  return;
}


// ==== FUN_00898380 @ 0x00898380 ====

void FUN_00898380(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *in_ECX;
  char *local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_2);
  uVar3 = param_2;
  if (local_4 == *(char **)(in_ECX + 0xc)) {
    uVar2 = FUN_00898030(param_2);
  }
  else {
    uVar2 = *(undefined4 *)(local_4 + 0xc);
  }
  FUN_00897340(&local_4,&param_2);
  if (local_4 == *(char **)(in_ECX + 0x34)) {
    uVar3 = FUN_00898190(uVar3);
  }
  else {
    uVar3 = *(undefined4 *)(local_4 + 0xc);
  }
  if (*in_ECX != '\0') {
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 400))
              (piVar1,0,*(undefined4 *)(in_ECX + 0x54),0,*(undefined4 *)(in_ECX + 0x6c));
    FUN_0084b7f0(*(undefined4 *)(in_ECX + 0x60));
    *in_ECX = '\0';
  }
  param_1[1] = uVar3;
  *param_1 = uVar2;
  return;
}


// ==== FUN_00898430 @ 0x00898430 ====

int FUN_00898430(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a910;
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


// ==== Catch@00898496 @ 0x00898496 ====

void Catch_00898496(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008984a0 @ 0x008984a0 ====

void FUN_008984a0(void)

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
    _free(*(void **)(in_ECX + 4));
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_008984f0 @ 0x008984f0 ====

void FUN_008984f0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a920;
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


// ==== Catch@0089855f @ 0x0089855f ====

void Catch_0089855f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00898580 @ 0x00898580 ====

void * FUN_00898580(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a930;
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


// ==== Catch@008985ed @ 0x008985ed ====

void Catch_008985ed(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00898610 @ 0x00898610 ====

void FUN_00898610(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a940;
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


// ==== Catch@00898676 @ 0x00898676 ====

void Catch_00898676(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00898680 @ 0x00898680 ====

void FUN_00898680(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00898430(param_1,param_2,param_3);
  return;
}


// ==== FUN_008986a0 @ 0x008986a0 ====

int FUN_008986a0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00898610(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_008986d0 @ 0x008986d0 ====

void FUN_008986d0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a950;
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
      uVar5 = FUN_00898680(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_008986a0(uVar5,param_2,&local_18);
      FUN_00898680(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_00898430(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_008986a0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_00898430(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00898831 @ 0x00898831 ====

void Catch_00898831(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00898920 @ 0x00898920 ====

void FUN_00898920(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a960;
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
    uVar2 = FUN_008986a0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008989b4 @ 0x008989b4 ====

void Catch_008989b4(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008989d0 @ 0x008989d0 ====

void FUN_008989d0(uint param_1,undefined1 param_2)

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
    FUN_008986d0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00898a40 @ 0x00898a40 ====

/* WARNING: Removing unreachable block (ram,0x00898a5b) */
/* WARNING: Removing unreachable block (ram,0x00898a60) */
/* WARNING: Removing unreachable block (ram,0x00898a6e) */

void FUN_00898a40(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_008986d0(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_00898a90 @ 0x00898a90 ====

/* WARNING: Removing unreachable block (ram,0x00898b78) */

void FUN_00898a90(int *param_1,uint *param_2)

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
      FUN_008989d0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_00898580(puVar7,puVar7[1],param_2);
  FUN_00833ae0(1);
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


// ==== FUN_00898cc0 @ 0x00898cc0 ====

void FUN_00898cc0(void)

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
    FUN_00898a40(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00898d20 @ 0x00898d20 ====

void FUN_00898d20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a156ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00898d40 @ 0x00898d40 ====

uint FUN_00898d40(void)

{
  uint in_EAX;
  
  if (in_EAX < 0x11) {
    if (4 < in_EAX) {
      return (-(uint)(8 < in_EAX) & 8) + 8;
    }
    if (2 < in_EAX) {
      in_EAX = 4;
    }
    return in_EAX;
  }
  if (in_EAX < 0x41) {
    return (-(uint)(0x20 < in_EAX) & 0x20) + 0x20;
  }
  if (in_EAX < 0x81) {
    return 0x80;
  }
  if (in_EAX < 0x101) {
    return 0x100;
  }
  return (-(uint)(0x200 < in_EAX) & 0x200) + 0x200;
}


// ==== FUN_00898da0 @ 0x00898da0 ====

void FUN_00898da0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = uVar1;
  *(undefined4 *)(in_ECX + 0x20) = uVar1;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = uVar1;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = uVar1;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = uVar1;
  *(undefined4 *)(in_ECX + 0x50) = uVar1;
  *(undefined4 *)(in_ECX + 0x54) = uVar1;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = uVar1;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = uVar1;
  *(undefined4 *)(in_ECX + 0x5c) = uVar1;
  *(undefined4 *)(in_ECX + 0x60) = uVar1;
  *(undefined4 *)(in_ECX + 100) = uVar1;
  return;
}


// ==== FUN_00898eb0 @ 0x00898eb0 ====

void FUN_00898eb0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(*(int *)(in_ECX + 4) + 0x44) + -4 +
                    *(int *)(*(int *)(in_ECX + 4) + 0x18) * 4);
  (**(code **)(*piVar1 + 0x50))(piVar1,0);
  return;
}


// ==== FUN_00898ed0 @ 0x00898ed0 ====

undefined4 FUN_00898ed0(void)

{
  undefined4 *in_ECX;
  undefined4 extraout_ECX;
  
  *in_ECX = &PTR_FUN_00a156c8;
  in_ECX[1] = 0;
  FUN_00898da0();
  return extraout_ECX;
}


// ==== FUN_00898ef0 @ 0x00898ef0 ====

void FUN_00898ef0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  
  if (*(int *)(*(int *)(in_ECX + 4) + 0x44) == 0) {
    return;
  }
  uVar3 = 0;
  if (*(int *)(*(int *)(in_ECX + 4) + 0x24) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 4) + 0x44);
      if (*(int *)(iVar1 + uVar3 * 4) != 0) {
        piVar2 = *(int **)(iVar1 + uVar3 * 4);
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(*(int *)(in_ECX + 4) + 0x24));
  }
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x44) = 0;
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00898f50 @ 0x00898f50 ====

uint FUN_00898f50(uint param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,uint param_6
                 )

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *in_ECX;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_1c;
  
  if (param_5 == 0) {
    local_1c = *(int *)(param_1 + 0x10);
  }
  else {
    local_1c = *(int *)(param_1 + 0xc);
  }
  uVar1 = FUN_00898d40();
  uVar2 = FUN_00898d40();
  puVar3 = operator_new(0x48);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar7 = puVar3;
    for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
  }
  uVar6 = 0;
  in_ECX[1] = (int)puVar3;
  if (puVar3 == (undefined4 *)0x0) {
LAB_008991f1:
    return uVar6 & 0xffffff00;
  }
  for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(int *)(in_ECX[1] + 0x44) = in_ECX[1] + 0x48;
  *(uint *)(in_ECX[1] + 0x24) =
       (((param_3 - 1) + param_6) / param_6) * (((param_4 - 1) + param_6) / param_6);
  *(uint *)(in_ECX[1] + 0x20) = local_1c * param_3 + 0xf & 0xfffffff0;
  *(uint *)(in_ECX[1] + 0x10) = param_3;
  *(uint *)(in_ECX[1] + 0x14) = param_4;
  *(int *)(in_ECX[1] + 8) = param_5;
  *(int *)(in_ECX[1] + 0xc) = local_1c;
  *(uint *)(in_ECX[1] + 0x28) = param_3 / param_6;
  *(uint *)(in_ECX[1] + 0x2c) = param_4 / param_6;
  *(undefined4 *)(in_ECX[1] + 0x30) = uVar1;
  *(undefined4 *)(in_ECX[1] + 0x34) = uVar2;
  *(uint *)(in_ECX[1] + 0x38) = param_3 % param_6;
  *(uint *)(in_ECX[1] + 0x3c) = param_4 % param_6;
  *(uint *)(in_ECX[1] + 0x40) = param_6;
  if (param_5 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x18);
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
  }
  *(undefined4 *)(in_ECX[1] + 4) = uVar1;
  if (param_5 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 4);
  }
  *(undefined4 *)in_ECX[1] = uVar1;
  puVar3 = *(undefined4 **)(in_ECX[1] + 0x44);
  param_1 = 0;
  if (*(int *)(in_ECX[1] + 0x2c) != 0) {
    do {
      if (*(int *)(in_ECX[1] + 0x28) != 0) {
        uVar6 = 0;
        do {
          puVar7 = (undefined4 *)in_ECX[1];
          uVar1 = FUN_00899620(param_2,*puVar7,puVar7[8],puVar7[3],puVar7[0x10],puVar7[0x10]);
          *puVar3 = uVar1;
          uVar6 = uVar6 + 1;
          puVar3 = puVar3 + 1;
        } while (uVar6 < *(uint *)(in_ECX[1] + 0x28));
      }
      puVar7 = (undefined4 *)in_ECX[1];
      if (puVar7[0xc] != 0) {
        uVar1 = FUN_00899620(param_2,*puVar7,puVar7[8],puVar7[3],puVar7[0xc],puVar7[0x10]);
        *puVar3 = uVar1;
        puVar3 = puVar3 + 1;
      }
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX[1] + 0x2c));
  }
  if (*(int *)(in_ECX[1] + 0x34) != 0) {
    uVar6 = 0;
    if (*(int *)(in_ECX[1] + 0x28) != 0) {
      do {
        puVar7 = (undefined4 *)in_ECX[1];
        uVar1 = FUN_00899620(param_2,*puVar7,puVar7[8],puVar7[3],puVar7[0x10],puVar7[0xd]);
        *puVar3 = uVar1;
        uVar6 = uVar6 + 1;
        puVar3 = puVar3 + 1;
      } while (uVar6 < *(uint *)(in_ECX[1] + 0x28));
    }
    puVar7 = (undefined4 *)in_ECX[1];
    if (puVar7[0xc] != 0) {
      uVar1 = FUN_00899620(param_2,*puVar7,puVar7[8],puVar7[3],puVar7[0xc],puVar7[0xd]);
      *puVar3 = uVar1;
    }
  }
  iVar4 = in_ECX[1];
  uVar6 = 0;
  if (*(int *)(iVar4 + 0x24) != 0) {
    piVar5 = *(int **)(iVar4 + 0x44);
    do {
      if (*piVar5 == 0) {
        uVar6 = (**(code **)(*in_ECX + 0xc))();
        goto LAB_008991f1;
      }
      uVar6 = uVar6 + 1;
      piVar5 = piVar5 + 1;
    } while (uVar6 < *(uint *)(in_ECX[1] + 0x24));
  }
  *(undefined4 *)(iVar4 + 0x1c) = 0;
  return CONCAT31((int3)(uVar6 >> 8),1);
}


// ==== FUN_00899200 @ 0x00899200 ====

uint FUN_00899200(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  int *piVar5;
  undefined4 *unaff_ESI;
  int *unaff_retaddr;
  int in_stack_00000020;
  undefined4 uVar6;
  undefined4 **ppuVar7;
  undefined4 *local_8;
  int *piStack_4;
  
  uVar3 = *(uint *)(in_ECX + 4);
  if (*(uint *)(uVar3 + 0x18) < *(uint *)(uVar3 + 0x24)) {
    piVar1 = *(int **)(*(int *)(uVar3 + 0x44) + *(int *)(uVar3 + 0x18) * 4);
    piVar5 = (int *)(-(uint)(in_stack_00000020 != 0) & 0x2000);
    ppuVar7 = &local_8;
    uVar6 = 0;
    iVar2 = (**(code **)(*piVar1 + 0x4c))(piVar1,0,ppuVar7,0);
    if (-1 < iVar2) {
      if (piVar5 != (int *)0x0) {
        *piVar5 = (int)ppuVar7;
      }
      if (unaff_ESI != (undefined4 *)0x0) {
        *unaff_ESI = uVar6;
      }
      if (local_8 != (undefined4 *)0x0) {
        *local_8 = *(undefined4 *)(*(int *)(in_ECX + 4) + 4);
      }
      iVar2 = *(int *)(in_ECX + 4);
      uVar4 = (uint)(*(int *)(iVar2 + 0x30) != 0) + *(int *)(iVar2 + 0x28);
      uVar3 = *(uint *)(iVar2 + 0x18) / uVar4;
      uVar4 = *(uint *)(iVar2 + 0x18) - uVar3 * uVar4;
      if (piStack_4 != (int *)0x0) {
        *piStack_4 = *(int *)(*(int *)(in_ECX + 4) + 0x40) * uVar4;
      }
      if (unaff_retaddr != (int *)0x0) {
        *unaff_retaddr = *(int *)(*(int *)(in_ECX + 4) + 0x40) * uVar3;
      }
      if (param_1 != (undefined4 *)0x0) {
        iVar2 = *(int *)(in_ECX + 4);
        if (uVar4 < *(uint *)(iVar2 + 0x28)) {
          uVar6 = *(undefined4 *)(iVar2 + 0x40);
        }
        else {
          uVar6 = *(undefined4 *)(iVar2 + 0x30);
        }
        *param_1 = uVar6;
      }
      if (param_2 != (undefined4 *)0x0) {
        iVar2 = *(int *)(in_ECX + 4);
        if (*(uint *)(iVar2 + 0x2c) <= uVar3) {
          *param_2 = *(undefined4 *)(iVar2 + 0x34);
          piVar1 = (int *)(*(int *)(in_ECX + 4) + 0x18);
          *piVar1 = *piVar1 + 1;
          return 1;
        }
        *param_2 = *(undefined4 *)(iVar2 + 0x40);
      }
      piVar1 = (int *)(*(int *)(in_ECX + 4) + 0x18);
      *piVar1 = *piVar1 + 1;
      return 1;
    }
    uVar3 = *(uint *)(in_ECX + 4);
  }
  *(undefined4 *)(uVar3 + 0x18) = 0;
  return uVar3 & 0xffffff00;
}


// ==== FUN_00899320 @ 0x00899320 ====

void FUN_00899320(undefined4 param_1,float param_2,float param_3)

{
  int *piVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  int in_ECX;
  
  uVar4 = DAT_009b0318;
  fVar3 = DAT_0099d0b4;
  uVar2 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 8) = DAT_009b0318;
  *(float *)(in_ECX + 0xc) = fVar3;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  *(float *)(in_ECX + 0x20) = param_2 - fVar3;
  *(float *)(in_ECX + 0x24) = fVar3;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = uVar2;
  *(undefined4 *)(in_ECX + 0x38) = uVar4;
  *(float *)(in_ECX + 0x3c) = param_3 + fVar3;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = uVar2;
  *(float *)(in_ECX + 0x50) = param_2 - fVar3;
  *(float *)(in_ECX + 0x54) = param_3 + fVar3;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = uVar2;
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0x14c))(piVar1,5,2,(undefined4 *)(in_ECX + 8),0x18);
  return;
}


// ==== FUN_00899460 @ 0x00899460 ====

void FUN_00899460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a156c8;
  FUN_00898ef0();
  *in_ECX = &PTR_FUN_00a156ac;
  return;
}


// ==== FUN_00899480 @ 0x00899480 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00899480(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 unaff_retaddr;
  uint local_8;
  
  iVar2 = param_1;
  iVar3 = *(int *)(in_ECX + 4);
  param_2 = (float)*(int *)(iVar3 + 0x30);
  puVar4 = *(undefined4 **)(iVar3 + 0x44);
  if (*(int *)(iVar3 + 0x30) < 0) {
    param_2 = param_2 + _DAT_0099d104;
  }
  param_3 = (float)*(int *)(iVar3 + 0x34);
  if (*(int *)(iVar3 + 0x34) < 0) {
    param_3 = param_3 + _DAT_0099d104;
  }
  fVar1 = (float)*(int *)(iVar3 + 0x40);
  if (*(int *)(iVar3 + 0x40) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  iVar3 = *(int *)(in_ECX + 4);
  local_8 = 0;
  if (*(int *)(iVar3 + 0x2c) != 0) {
    do {
      param_1 = 0;
      if (*(int *)(iVar3 + 0x28) != 0) {
        do {
          (**(code **)(**(int **)(iVar2 + 0x24) + 0x104))(*(int **)(iVar2 + 0x24),0,*puVar4);
          puVar4 = puVar4 + 1;
          FUN_00899320(*(undefined4 *)(iVar2 + 0x24),fVar1,fVar1,param_4);
          param_1 = param_1 + 1;
        } while (param_1 < *(uint *)(*(int *)(in_ECX + 4) + 0x28));
      }
      if (*(int *)(*(int *)(in_ECX + 4) + 0x30) != 0) {
        (**(code **)(**(int **)(iVar2 + 0x24) + 0x104))(*(int **)(iVar2 + 0x24),0,*puVar4);
        puVar4 = puVar4 + 1;
        FUN_00899320(*(undefined4 *)(iVar2 + 0x24),param_2,fVar1,param_4);
      }
      iVar3 = *(int *)(in_ECX + 4);
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(iVar3 + 0x2c));
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x34) != 0) {
    param_1 = 0;
    if (*(int *)(*(int *)(in_ECX + 4) + 0x28) != 0) {
      do {
        (**(code **)(**(int **)(iVar2 + 0x24) + 0x104))(*(int **)(iVar2 + 0x24),0,*puVar4);
        puVar4 = puVar4 + 1;
        FUN_00899320(*(undefined4 *)(iVar2 + 0x24),fVar1,param_3,param_4);
        param_1 = param_1 + 1;
      } while (param_1 < *(uint *)(*(int *)(in_ECX + 4) + 0x28));
    }
    if (*(int *)(*(int *)(in_ECX + 4) + 0x30) != 0) {
      (**(code **)(**(int **)(iVar2 + 0x24) + 0x104))(*(int **)(iVar2 + 0x24),0,*puVar4);
      FUN_00899320(*(undefined4 *)(iVar2 + 0x24),fVar1,unaff_retaddr,param_1);
    }
  }
  return;
}


// ==== FUN_00899620 @ 0x00899620 ====

int * FUN_00899620(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 *param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int *piStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 *puStack_24;
  undefined4 uStack_20;
  undefined4 local_c [3];
  
  uStack_20 = 0;
  puStack_24 = local_c;
  iStack_28 = 0;
  uStack_2c = param_2;
  piStack_30 = (int *)0x200;
  local_c[0] = 0;
  piVar6 = param_1;
  puVar3 = param_5;
  iVar1 = (**(code **)(*param_1 + 0x5c))(param_1,param_5,param_6,1);
  if ((iVar1 < 0) &&
     (iVar1 = (**(code **)(*param_1 + 0x5c))(param_1,param_5,param_6,1,0,param_2,1,&piStack_30,0),
     iVar1 < 0)) {
    return (int *)0x0;
  }
  piVar5 = (int *)0x0;
  iVar1 = (**(code **)(*piStack_30 + 0x4c))(piStack_30,0,&uStack_2c,0);
  if (-1 < iVar1) {
    if (param_6 != 0) {
      do {
        puVar4 = puVar3;
        for (uVar2 = (uint)(iStack_28 * (int)param_5) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        for (uVar2 = iStack_28 * (int)param_5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar4 = 0;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        puVar3 = (undefined4 *)((int)puVar3 + (int)piVar6);
        param_6 = param_6 + -1;
      } while (param_6 != 0);
    }
    (**(code **)(*piVar5 + 0x50))(piVar5,0);
  }
  return piVar5;
}


// ==== FUN_008996f0 @ 0x008996f0 ====

void FUN_008996f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a156c8;
  FUN_00898ef0();
  *in_ECX = &PTR_FUN_00a156ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00899720 @ 0x00899720 ====

void FUN_00899720(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = uVar1;
  *(undefined4 *)(in_ECX + 0x20) = uVar1;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = uVar1;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = uVar1;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = uVar1;
  *(undefined4 *)(in_ECX + 0x50) = uVar1;
  *(undefined4 *)(in_ECX + 0x54) = uVar1;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = uVar1;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = uVar1;
  *(undefined4 *)(in_ECX + 0x5c) = uVar1;
  *(undefined4 *)(in_ECX + 0x60) = uVar1;
  *(undefined4 *)(in_ECX + 100) = uVar1;
  return;
}


// ==== FUN_00899830 @ 0x00899830 ====

void FUN_00899830(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x20);
  (**(code **)(*piVar1 + 0x50))(piVar1,0);
  return;
}


// ==== FUN_00899840 @ 0x00899840 ====

undefined4 FUN_00899840(void)

{
  undefined4 *in_ECX;
  undefined4 extraout_ECX;
  
  *in_ECX = &PTR_FUN_00a15734;
  in_ECX[1] = 0;
  FUN_00899720();
  return extraout_ECX;
}


// ==== FUN_00899860 @ 0x00899860 ====

void FUN_00899860(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 4) + 0x20) != 0) {
    piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x20);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00899890 @ 0x00899890 ====

uint FUN_00899890(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int *in_ECX;
  
  puVar2 = operator_new(0x24);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[8] = 0;
  }
  in_ECX[1] = (int)puVar2;
  uVar4 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[8] = 0;
    if (param_5 == 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x10);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0xc);
    }
    *(undefined4 *)(in_ECX[1] + 0x10) = param_3;
    *(undefined4 *)(in_ECX[1] + 0x14) = param_4;
    *(int *)(in_ECX[1] + 8) = param_5;
    *(undefined4 *)(in_ECX[1] + 0xc) = uVar3;
    if (param_5 == 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x18);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x14);
    }
    *(undefined4 *)(in_ECX[1] + 4) = uVar3;
    if (param_5 == 0) {
      uVar3 = *(undefined4 *)(param_1 + 8);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 4);
    }
    *(undefined4 *)in_ECX[1] = uVar3;
    *(undefined4 *)(in_ECX[1] + 0x18) = 0;
    uVar3 = FUN_00899620(param_2,*(undefined4 *)in_ECX[1],0,((undefined4 *)in_ECX[1])[3],param_3,
                         param_4);
    *(undefined4 *)(in_ECX[1] + 0x20) = uVar3;
    iVar1 = in_ECX[1];
    if (*(int *)(iVar1 + 0x20) != 0) {
      *(undefined4 *)(iVar1 + 0x1c) = 1;
      return CONCAT31((int3)((uint)iVar1 >> 8),1);
    }
    uVar4 = (**(code **)(*in_ECX + 0xc))();
  }
  return uVar4 & 0xffffff00;
}


// ==== FUN_008999a0 @ 0x008999a0 ====

void FUN_008999a0(undefined4 param_1,float param_2,float param_3)

{
  int *piVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  int in_ECX;
  
  uVar4 = DAT_009b0318;
  fVar3 = DAT_0099d0b4;
  uVar2 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 8) = DAT_009b0318;
  *(float *)(in_ECX + 0xc) = fVar3;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  *(float *)(in_ECX + 0x20) = param_2 - fVar3;
  *(float *)(in_ECX + 0x24) = fVar3;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = uVar2;
  *(undefined4 *)(in_ECX + 0x38) = uVar4;
  *(float *)(in_ECX + 0x3c) = param_3 + fVar3;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = uVar2;
  *(float *)(in_ECX + 0x50) = param_2 - fVar3;
  *(float *)(in_ECX + 0x54) = param_3 + fVar3;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = uVar2;
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0x14c))(piVar1,5,2,(undefined4 *)(in_ECX + 8),0x18);
  return;
}


// ==== FUN_00899ae0 @ 0x00899ae0 ====

void FUN_00899ae0(int param_1)

{
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  (**(code **)(**(int **)(param_1 + 0x24) + 0x104))
            (*(int **)(param_1 + 0x24),0,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x20));
  FUN_008999a0(*(undefined4 *)(param_1 + 0x24),unaff_ESI,unaff_retaddr,param_1);
  return;
}


// ==== FUN_00899b20 @ 0x00899b20 ====

uint FUN_00899b20(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,int param_8)

{
  int *piVar1;
  uint uVar2;
  int in_ECX;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uVar2 = *(uint *)(in_ECX + 4);
  if (*(int *)(uVar2 + 0x18) != 0) {
    *(undefined4 *)(uVar2 + 0x18) = 0;
    return uVar2 & 0xffffff00;
  }
  if ((param_1 != (undefined4 *)0x0) || (param_2 != (undefined4 *)0x0)) {
    piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x20);
    uVar2 = (**(code **)(*piVar1 + 0x4c))(piVar1,0,&local_8,0,-(uint)(param_8 != 0) & 0x2000);
    if ((int)uVar2 < 0) {
      return uVar2 & 0xffffff00;
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = uStack_4;
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = local_8;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = *(undefined4 *)(*(int *)(in_ECX + 4) + 0x10);
    }
    if (param_7 != (undefined4 *)0x0) {
      *param_7 = *(undefined4 *)(*(int *)(in_ECX + 4) + 0x14);
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(*(int *)(in_ECX + 4) + 4);
  }
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x18) = 1;
  return 1;
}


// ==== FUN_00899c00 @ 0x00899c00 ====

void FUN_00899c00(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15734;
  if (*(int *)(in_ECX[1] + 0x20) != 0) {
    piVar1 = *(int **)(in_ECX[1] + 0x20);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_00899c40 @ 0x00899c40 ====

void FUN_00899c40(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15734;
  if (*(int *)(in_ECX[1] + 0x20) != 0) {
    piVar1 = *(int **)(in_ECX[1] + 0x20);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_00899c90 @ 0x00899c90 ====

void FUN_00899c90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15750;
  return;
}


// ==== FUN_00899cb0 @ 0x00899cb0 ====

bool FUN_00899cb0(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint *puVar5;
  uint local_70 [28];
  
  uVar4 = 0;
  local_70[6] = 3;
  local_70[9] = 3;
  local_70[0] = 0x16;
  local_70[1] = 0;
  local_70[2] = 4;
  local_70[3] = 0;
  local_70[4] = 0x14;
  local_70[5] = 8;
  local_70[7] = 0;
  local_70[8] = 0x17;
  local_70[10] = 2;
  local_70[0xb] = 0;
  local_70[0xc] = 0x18;
  local_70[0xd] = 2;
  local_70[0xe] = 2;
  local_70[0xf] = 0;
  local_70[0x10] = 0x15;
  local_70[0x11] = 1;
  local_70[0x12] = 4;
  local_70[0x13] = 1;
  local_70[0x14] = 0x1a;
  local_70[0x15] = 5;
  local_70[0x16] = 2;
  local_70[0x17] = 1;
  local_70[0x18] = 0x19;
  local_70[0x19] = 4;
  local_70[0x1a] = 2;
  local_70[0x1b] = 1;
  puVar5 = local_70;
  do {
    iVar3 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x28))
                      (*(int **)(in_ECX + 0x20),0,1,param_1,0,3,*puVar5);
    if (-1 < iVar3) {
      uVar1 = local_70[uVar4 * 4 + 1];
      uVar2 = local_70[uVar4 * 4 + 2];
      *(uint *)(in_ECX + 8) = local_70[uVar4 * 4];
      *(uint *)(in_ECX + 0x18) = uVar1;
      *(uint *)(in_ECX + 0x10) = uVar2;
      break;
    }
    uVar4 = uVar4 + 1;
    puVar5 = puVar5 + 4;
  } while (uVar4 < 7);
  if (uVar4 == 7) {
    return false;
  }
  uVar4 = 0;
  puVar5 = local_70 + -4;
  while ((puVar5[7] == 0 ||
         (iVar3 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x28))
                            (*(int **)(in_ECX + 0x20),0,1,param_1,0,3,puVar5[4]), iVar3 < 0))) {
    uVar4 = uVar4 + 1;
    puVar5 = puVar5 + 4;
    if (6 < uVar4) {
      return uVar4 != 7;
    }
  }
  uVar1 = local_70[uVar4 * 4];
  uVar2 = local_70[uVar4 * 4 + 1];
  *(uint *)(in_ECX + 0xc) = local_70[uVar4 * 4 + 2];
  *(uint *)(in_ECX + 4) = uVar1;
  *(uint *)(in_ECX + 0x14) = uVar2;
  return uVar4 != 7;
}


// ==== FUN_00899e30 @ 0x00899e30 ====

uint FUN_00899e30(int *param_1)

{
  uint uVar1;
  int in_ECX;
  undefined4 local_140;
  undefined1 auStack_13c [52];
  uint uStack_108;
  undefined4 uStack_4;
  
  uVar1 = (**(code **)(*param_1 + 0x20))(param_1,0,&local_140);
  if (-1 < (int)uVar1) {
    *(int **)(in_ECX + 0x20) = param_1;
    *(undefined4 *)(in_ECX + 0x24) = uStack_4;
    uVar1 = FUN_00899cb0(local_140);
    if ((char)uVar1 != '\0') {
      (**(code **)(**(int **)(in_ECX + 0x24) + 0x1c))(*(int **)(in_ECX + 0x24),auStack_13c);
      *(uint *)(in_ECX + 0x1c) = uStack_108 >> 8 & 1;
      return 1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00899eb0 @ 0x00899eb0 ====

void FUN_00899eb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15750;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00899ed0 @ 0x00899ed0 ====

void FUN_00899ed0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a157a8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00899f40 @ 0x00899f40 ====

undefined4 * FUN_00899f40(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_00a157b8;
  puVar1[1] = 1;
  puVar1[2] = 0;
  puVar1[3] = param_1;
  *(undefined1 *)(puVar1 + 4) = 0;
  return puVar1;
}


// ==== FUN_00899f70 @ 0x00899f70 ====

void FUN_00899f70(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 4) = param_1;
  *(undefined1 *)(in_ECX + 0x10) = 1;
  return;
}


// ==== FUN_00899f90 @ 0x00899f90 ====

void FUN_00899f90(char param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar2 = DAT_0099d080;
  if (param_2 == 0) {
    param_2 = 1;
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  if (param_1 == '\0') {
    *(undefined1 *)(iVar1 + 0x28) = 0;
    *(undefined1 *)(*(int *)(in_ECX + 0xc) + 0x29) = 0;
    return;
  }
  if (*(char *)(iVar1 + 0x28) == '\0') {
    if (*(char *)(iVar1 + 0x29) == '\0') {
      *(char *)(iVar1 + 0x28) = param_1;
      *(undefined4 *)(*(int *)(in_ECX + 0xc) + 0x2c) = uVar2;
      return;
    }
  }
  else {
    if (*(char *)(iVar1 + 0x29) == '\0') {
      *(undefined4 *)(iVar1 + 0x2c) = DAT_0099d080;
      *(char *)(*(int *)(in_ECX + 0xc) + 0x29) = param_1;
      uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      *(int *)(in_ECX + 4) = param_2;
      *(undefined4 *)(in_ECX + 8) = uVar2;
      *(undefined1 *)(in_ECX + 0x10) = 1;
      return;
    }
    if ((*(char *)(iVar1 + 0x28) != '\0') && (*(char *)(iVar1 + 0x29) != '\0')) {
      *(char *)(iVar1 + 0x28) = *(char *)(iVar1 + 0x29);
      *(char *)(*(int *)(in_ECX + 0xc) + 0x29) = param_1;
      *(undefined4 *)(*(int *)(in_ECX + 0xc) + 0x2c) = uVar2;
      FUN_00899f70(param_2);
      return;
    }
  }
  *(char *)(iVar1 + 0x28) = param_1;
  *(undefined1 *)(*(int *)(in_ECX + 0xc) + 0x29) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 0xc) + 0x2c) = uVar2;
  return;
}


// ==== FUN_0089a070 @ 0x0089a070 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089a070(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x10) != '\0') {
    iVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    fVar4 = DAT_0099d080;
    iVar5 = iVar5 - *(int *)(in_ECX + 8);
    fVar2 = (float)iVar5;
    if (iVar5 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar3 = (float)*(int *)(in_ECX + 4);
    if (*(int *)(in_ECX + 4) < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    if (DAT_0099d080 <= fVar2 / fVar3) {
      *(undefined1 *)(*(int *)(in_ECX + 0xc) + 0x28) =
           *(undefined1 *)(*(int *)(in_ECX + 0xc) + 0x29);
      *(undefined1 *)(*(int *)(in_ECX + 0xc) + 0x29) = 0;
      *(float *)(*(int *)(in_ECX + 0xc) + 0x2c) = fVar4;
      *(undefined1 *)(in_ECX + 0x10) = 0;
      return;
    }
    *(float *)(*(int *)(in_ECX + 0xc) + 0x2c) = DAT_0099d080 - fVar2 / fVar3;
    pfVar1 = (float *)(*(int *)(in_ECX + 0xc) + 0x2c);
    if (*pfVar1 <= 0.0 && *pfVar1 != 0.0) {
      *(undefined4 *)(*(int *)(in_ECX + 0xc) + 0x2c) = 0;
    }
  }
  return;
}


// ==== FUN_0089a120 @ 0x0089a120 ====

undefined4 FUN_0089a120(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0089a130 @ 0x0089a130 ====

void FUN_0089a130(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15818;
  in_ECX[1] = 0;
  in_ECX[2] = 0x100;
  in_ECX[0x11] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xb] = 0;
  in_ECX[10] = 0;
  in_ECX[9] = 0;
  in_ECX[7] = 0;
  in_ECX[6] = 0;
  in_ECX[5] = 0;
  in_ECX[4] = 0;
  uVar1 = DAT_0099d080;
  in_ECX[0x12] = DAT_0099d080;
  in_ECX[0xd] = uVar1;
  in_ECX[8] = uVar1;
  in_ECX[3] = uVar1;
  return;
}


// ==== FUN_0089a1b0 @ 0x0089a1b0 ====

void FUN_0089a1b0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0089a1d0 @ 0x0089a1d0 ====

void FUN_0089a1d0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = (int *)0x3;
  *(undefined4 *)(in_ECX + 8) = 0x200;
  (**(code **)(*param_1 + 0x28))(param_1,param_3,param_5,param_4,1,3,0x16);
  iVar1 = (**(code **)(*piVar2 + 0x5c))
                    (piVar2,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 8),1,1,0x16,0,
                     in_ECX + 4,0);
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 8) = 0x100;
    (**(code **)(*piVar2 + 0x5c))(piVar2,0x100,0x100,1,1,0x16,0,in_ECX + 4,0);
  }
  return;
}


// ==== FUN_0089a250 @ 0x0089a250 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089a250(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puStack_128;
  undefined4 *puStack_124;
  undefined1 auStack_10c [12];
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 auStack_c0 [16];
  undefined4 auStack_80 [13];
  undefined1 auStack_4c [12];
  undefined1 auStack_40 [64];
  
  puStack_124 = (undefined4 *)0x89a266;
  (**(code **)(*DAT_00b5af70 + 0x10))();
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 8);
  puVar3 = auStack_c0;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 0x48);
  puVar3 = auStack_80;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puStack_124 = auStack_80;
  puStack_128 = auStack_c0;
  uStack_fc = 0;
  uStack_f8 = 0;
  uStack_f4 = 0;
  uStack_f0 = 0;
  uStack_e8 = 0;
  uStack_e4 = 0;
  uStack_e0 = 0;
  uStack_dc = 0;
  uStack_d8 = 0;
  uStack_d4 = 0;
  uStack_100 = DAT_0099d0b4;
  uStack_ec = DAT_009b0318;
  uStack_d0 = DAT_0099d0b4;
  uStack_cc = DAT_0099d0b4;
  uStack_c8 = DAT_0099d080;
  uStack_c4 = DAT_0099d080;
  thunk_FUN_0079ee7b(auStack_40);
  thunk_FUN_0079ee7b(in_ECX + 0xc,auStack_4c,auStack_10c);
  puStack_128 = (undefined4 *)0x0;
  if (*(char *)(DAT_00b5ac04 + 0xcc) == '\0') {
    puStack_124 = (undefined4 *)DAT_0099d0dc;
  }
  else {
    puStack_124 = (undefined4 *)DAT_0099d080;
  }
  FUN_00862530(&puStack_128);
  return;
}


// ==== FUN_0089a3c0 @ 0x0089a3c0 ====

void FUN_0089a3c0(int *param_1)

{
  (**(code **)(*param_1 + 0xac))(param_1,0,0,3,*(undefined4 *)(DAT_00b5ac04 + 0xa4),0x3f800000,0);
  FUN_0089a250(param_1);
  if (*(char *)(DAT_00b5ac04 + 0xcc) == '\0') {
    FUN_00849da0();
    FUN_00863ed0();
    return;
  }
  FUN_00848ff0();
  FUN_00863ed0();
  return;
}


// ==== FUN_0089a440 @ 0x0089a440 ====

undefined4 FUN_0089a440(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0089a450 @ 0x0089a450 ====

void FUN_0089a450(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15898;
  in_ECX[1] = 0;
  in_ECX[2] = 0x100;
  in_ECX[0x11] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xb] = 0;
  in_ECX[10] = 0;
  in_ECX[9] = 0;
  in_ECX[7] = 0;
  in_ECX[6] = 0;
  in_ECX[5] = 0;
  in_ECX[4] = 0;
  uVar1 = DAT_0099d080;
  in_ECX[0x12] = DAT_0099d080;
  in_ECX[0xd] = uVar1;
  in_ECX[8] = uVar1;
  in_ECX[3] = uVar1;
  return;
}


// ==== FUN_0089a4d0 @ 0x0089a4d0 ====

void FUN_0089a4d0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0089a4f0 @ 0x0089a4f0 ====

void FUN_0089a4f0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = (int *)0x3;
  *(undefined4 *)(in_ECX + 8) = 0x200;
  (**(code **)(*param_1 + 0x28))(param_1,param_3,param_5,param_4,1,3,0x16);
  iVar1 = (**(code **)(*piVar2 + 0x5c))
                    (piVar2,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 8),1,1,0x16,0,
                     in_ECX + 4,0);
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 8) = 0x100;
    (**(code **)(*piVar2 + 0x5c))(piVar2,0x100,0x100,1,1,0x16,0,in_ECX + 4,0);
  }
  return;
}


// ==== FUN_0089a570 @ 0x0089a570 ====

void FUN_0089a570(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float10 fVar4;
  undefined1 *puVar5;
  float *pfStack_174;
  undefined1 *puStack_170;
  undefined1 *puStack_16c;
  undefined4 *puStack_168;
  undefined4 *puStack_164;
  undefined1 auStack_152 [82];
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  float afStack_cc [3];
  undefined1 auStack_c0 [52];
  undefined1 auStack_8c [12];
  undefined4 auStack_80 [10];
  undefined1 auStack_58 [12];
  undefined1 auStack_4c [76];
  
  puStack_164 = (undefined4 *)0x89a586;
  fVar4 = (float10)(**(code **)(*DAT_00b5af70 + 0x10))();
  puStack_164 = (undefined4 *)(in_ECX + 0x4c);
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 8);
  puVar3 = puStack_164;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 0x48);
  puVar3 = auStack_80;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  afStack_cc[1] = 0.0;
  uStack_d0 = 0;
  uStack_d4 = 0;
  uStack_dc = 0;
  uStack_e0 = 0;
  uStack_e4 = 0;
  uStack_e8 = 0;
  uStack_f0 = 0;
  uStack_f4 = 0;
  uStack_f8 = 0;
  uStack_fc = 0;
  afStack_cc[2] = (float)DAT_0099d080;
  uStack_d8 = DAT_0099d080;
  uStack_100 = DAT_0099d080;
  puStack_168 = &uStack_100;
  uStack_ec = DAT_0099d0dc;
  afStack_cc[0] = (float)fVar4 * DAT_0099d0f8;
  puStack_16c = auStack_c0;
  puStack_170 = (undefined1 *)0x89a668;
  thunk_FUN_0079ee7b();
  puStack_170 = auStack_8c;
  pfStack_174 = afStack_cc;
  puVar5 = auStack_4c;
  thunk_FUN_0079ee7b(puVar5);
  thunk_FUN_0079ee7b(in_ECX + 0xc,auStack_58,auStack_152 + -6);
  FUN_008624b0(&uStack_e4);
  pfStack_174 = (float *)0x0;
  puStack_16c = (undefined1 *)0x0;
  puStack_168 = (undefined4 *)(0.0 - (float)puVar5);
  puStack_170 = (undefined1 *)DAT_0099d080;
  FUN_00862530(&pfStack_174);
  return;
}


// ==== FUN_0089a780 @ 0x0089a780 ====

void FUN_0089a780(int *param_1)

{
  (**(code **)(*param_1 + 0xac))(param_1,0,0,3,*(undefined4 *)(DAT_00b5ac04 + 0xa4),0x3f800000,0);
  if (*(char *)(DAT_00b5ac04 + 0xcc) == '\0') {
    FUN_0089a570(param_1);
    FUN_00848ff0();
    FUN_00863ed0();
  }
  return;
}


// ==== FUN_0089a7f0 @ 0x0089a7f0 ====

undefined4 FUN_0089a7f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0089a800 @ 0x0089a800 ====

void FUN_0089a800(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15914;
  in_ECX[1] = 0;
  in_ECX[2] = 0x100;
  in_ECX[0x11] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xb] = 0;
  in_ECX[10] = 0;
  in_ECX[9] = 0;
  in_ECX[7] = 0;
  in_ECX[6] = 0;
  in_ECX[5] = 0;
  in_ECX[4] = 0;
  uVar1 = DAT_0099d080;
  in_ECX[0x12] = DAT_0099d080;
  in_ECX[0xd] = uVar1;
  in_ECX[8] = uVar1;
  in_ECX[3] = uVar1;
  return;
}


// ==== FUN_0089a880 @ 0x0089a880 ====

void FUN_0089a880(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0089a8a0 @ 0x0089a8a0 ====

void FUN_0089a8a0(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4,undefined4 param_5
                 )

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0x17e;
  (**(code **)(*param_1 + 0x28))(param_1,param_3,param_5,param_4,1,3);
  iVar1 = (**(code **)(*param_4 + 0x5c))
                    (param_4,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 8),1,1,param_4,0,
                     in_ECX + 4,0);
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 8) = 0x100;
    (**(code **)(*param_4 + 0x5c))(param_4,0x100,0x100,1,1,0x16,0,in_ECX + 4,0);
  }
  return;
}


// ==== FUN_0089a920 @ 0x0089a920 ====

void FUN_0089a920(int *param_1)

{
  (**(code **)(*param_1 + 0xac))(param_1,0,0,3,0,0x3f800000,0);
  FUN_00849260();
  return;
}


// ==== FUN_0089a950 @ 0x0089a950 ====

undefined4 FUN_0089a950(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0089a960 @ 0x0089a960 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089a960(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  
  uVar4 = DAT_00a1599c;
  uVar3 = DAT_009b0318;
  uVar2 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x60) = DAT_009b0318;
  *(undefined4 *)(in_ECX + 100) = uVar3;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = uVar2;
  *(undefined4 *)(in_ECX + 0x7c) = uVar4;
  *(undefined4 *)(in_ECX + 0x80) = uVar3;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)(in_ECX + 0x88) = uVar2;
  *(undefined4 *)(in_ECX + 0x98) = uVar3;
  *(undefined4 *)(in_ECX + 0x9c) = uVar4;
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  *(undefined4 *)(in_ECX + 0xa4) = uVar2;
  *(undefined4 *)(in_ECX + 0xb4) = uVar4;
  *(undefined4 *)(in_ECX + 0xb8) = uVar4;
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = uVar2;
  *(undefined4 *)(in_ECX + 0xd0) = uVar3;
  *(undefined4 *)(in_ECX + 0xd4) = uVar3;
  *(undefined4 *)(in_ECX + 0x70) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x78) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x90) = uVar2;
  *(undefined4 *)(in_ECX + 0x94) = 0;
  *(undefined4 *)(in_ECX + 0xa8) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(undefined4 *)(in_ECX + 0xb0) = uVar2;
  *(undefined4 *)(in_ECX + 0xc4) = 0xffffffff;
  *(undefined4 *)(in_ECX + 200) = uVar2;
  *(undefined4 *)(in_ECX + 0xcc) = uVar2;
  *(undefined4 *)(in_ECX + 0xd8) = 0;
  fVar1 = (float)*(int *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0xdc) = uVar2;
  *(undefined4 *)(in_ECX + 0xe0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xe4) = 0;
  *(undefined4 *)(in_ECX + 0xe8) = 0;
  if (*(int *)(in_ECX + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar1 = fVar1 - DAT_0099d0b4;
  *(float *)(in_ECX + 0xec) = fVar1;
  *(undefined4 *)(in_ECX + 0xf0) = uVar3;
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  *(undefined4 *)(in_ECX + 0xf8) = uVar2;
  *(undefined4 *)(in_ECX + 0xfc) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x108) = uVar3;
  *(float *)(in_ECX + 0x10c) = fVar1;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  *(undefined4 *)(in_ECX + 0x114) = uVar2;
  *(float *)(in_ECX + 0x124) = fVar1;
  *(float *)(in_ECX + 0x128) = fVar1;
  *(undefined4 *)(in_ECX + 300) = 0;
  *(undefined4 *)(in_ECX + 0x130) = uVar2;
  *(undefined4 *)(in_ECX + 0x100) = uVar2;
  *(undefined4 *)(in_ECX + 0x104) = 0;
  *(undefined4 *)(in_ECX + 0x118) = 0x90ffffff;
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined4 *)(in_ECX + 0x120) = uVar2;
  *(undefined4 *)(in_ECX + 0x134) = 0x90ffffff;
  *(undefined4 *)(in_ECX + 0x138) = uVar2;
  *(undefined4 *)(in_ECX + 0x13c) = uVar2;
  return;
}


// ==== FUN_0089ac20 @ 0x0089ac20 ====

void FUN_0089ac20(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x150) != '\0') {
    *(undefined1 *)(in_ECX + 0x150) = 0;
  }
  return;
}


// ==== FUN_0089ac70 @ 0x0089ac70 ====

void FUN_0089ac70(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_00a159a4;
  in_ECX[3] = 0x200;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x53] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xb] = 0;
  in_ECX[10] = 0;
  in_ECX[8] = 0;
  in_ECX[7] = 0;
  in_ECX[6] = 0;
  in_ECX[5] = 0;
  in_ECX[0x13] = uVar1;
  in_ECX[0xe] = uVar1;
  in_ECX[9] = uVar1;
  in_ECX[4] = uVar1;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  *(undefined1 *)(in_ECX + 0x54) = 0;
  *(undefined1 *)((int)in_ECX + 0x151) = 0;
  return;
}


// ==== FUN_0089ad20 @ 0x0089ad20 ====

void FUN_0089ad20(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0089ad40 @ 0x0089ad40 ====

void FUN_0089ad40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a159a4;
  if (in_ECX[0x53] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x53]);
    in_ECX[0x53] = 0;
  }
  if (in_ECX[2] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[2]);
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_FUN_00a15290;
  return;
}


// ==== FUN_0089ad90 @ 0x0089ad90 ====

void FUN_0089ad90(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = (int *)0x1;
  *(undefined1 *)(in_ECX + 0x150) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0x200;
  (**(code **)(*param_1 + 0x28))(param_1,param_3,param_5,param_4,1,3,0x16);
  if ((*(int *)(in_ECX + 4) == 0) &&
     (iVar1 = (**(code **)(*piVar2 + 0x5c))
                        (piVar2,*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0xc),1,1,0x16
                         ,0,in_ECX + 4,0), iVar1 < 0)) {
    *(undefined4 *)(in_ECX + 0xc) = 0x100;
    (**(code **)(*piVar2 + 0x5c))(piVar2,0x100,0x100,1,1,0x16,0,in_ECX + 4,0);
  }
  FUN_0089a960();
  return;
}


// ==== FUN_0089ae20 @ 0x0089ae20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089ae20(void)

{
  float fVar1;
  float *pfVar2;
  int in_ECX;
  float fVar3;
  float fVar4;
  float fVar5;
  
  pfVar2 = (float *)(**(code **)(**(int **)(DAT_00b5ac04 + 0xd0) + 0x5c))();
  fVar5 = DAT_00a159d0;
  fVar3 = pfVar2[1] - _DAT_00a15978;
  fVar4 = *pfVar2 - _DAT_00a15978;
  if (0.0 <= fVar3) {
    if (DAT_00a159d0 <= fVar3) {
      fVar3 = DAT_00a159d0;
    }
  }
  else {
    fVar3 = 0.0;
  }
  *(float *)(in_ECX + 0x50) = fVar3;
  fVar1 = DAT_00a159cc;
  if (0.0 <= fVar4) {
    if (fVar5 <= fVar4) {
      fVar4 = fVar5;
    }
  }
  else {
    fVar4 = 0.0;
  }
  *(float *)(in_ECX + 0x54) = fVar4;
  *(float *)(in_ECX + 100) = fVar4;
  *(float *)(in_ECX + 0x80) = fVar4;
  *(float *)(in_ECX + 0x60) = fVar3;
  fVar5 = fVar3 + fVar1;
  *(float *)(in_ECX + 0x7c) = fVar5;
  *(float *)(in_ECX + 0x98) = fVar3;
  fVar4 = fVar4 + fVar1;
  *(float *)(in_ECX + 0x9c) = fVar4;
  *(float *)(in_ECX + 0xb4) = fVar5;
  *(float *)(in_ECX + 0xb8) = fVar4;
  *(float *)(in_ECX + 0x58) = *pfVar2;
  *(float *)(in_ECX + 0x5c) = pfVar2[1];
  return;
}


// ==== FUN_0089aef0 @ 0x0089aef0 ====

void FUN_0089aef0(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  int *unaff_ESI;
  
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  cVar3 = FUN_00881000(0x1c,0x70);
  if (cVar3 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  uVar4 = (**(code **)(*piVar1 + 0x1c))(0x1c,0x70);
  (**(code **)(*piVar1 + 0x14))(0x70,in_ECX + 0xd0);
  FUN_00881060();
  (**(code **)(*unaff_ESI + 0x164))(unaff_ESI,0x144);
  iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar5 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    piVar6 = (int *)FUN_004af750();
    iVar5 = (**(code **)(*piVar6 + 4))();
  }
  if (*(int *)(iVar2 + 0x134) != iVar5) {
    *(int *)(iVar2 + 0x134) = iVar5;
    (**(code **)(**(int **)(iVar2 + 0x90) + 0x104))(*(int **)(iVar2 + 0x90),0,iVar5);
  }
  piVar6 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar6 + 400))(piVar6,0,piVar1[1],0,0x1c);
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0x144))(piVar1,5,uVar4,2);
  return;
}


// ==== FUN_0089afd0 @ 0x0089afd0 ====

void FUN_0089afd0(void)

{
  int iVar1;
  int in_ECX;
  undefined1 *unaff_retaddr;
  uint in_stack_00000014;
  int *piVar2;
  
  piVar2 = *(int **)(in_ECX + 4);
  iVar1 = (**(code **)(*piVar2 + 0x48))(piVar2,0);
  if (-1 < iVar1) {
    if (0xf < in_stack_00000014) {
      register0x00000010 = (BADSPACEBASE *)unaff_retaddr;
    }
    FUN_008a018e(register0x00000010,4,piVar2,0,0);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return;
}


// ==== FUN_0089b020 @ 0x0089b020 ====

undefined4 FUN_0089b020(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x14c) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Acircle_dds_00a1597b + 1,10);
    uVar1 = FUN_004b4e70(local_1c);
    *(undefined4 *)(in_ECX + 0x14c) = uVar1;
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  return *(undefined4 *)(in_ECX + 0x14c);
}


// ==== FUN_0089b090 @ 0x0089b090 ====

void FUN_0089b090(int *param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  float *pfVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int in_ECX;
  
  pfVar6 = (float *)(**(code **)(**(int **)(DAT_00b5ac04 + 0xd0) + 0x5c))();
  fVar3 = *pfVar6 - *(float *)(in_ECX + 0x58);
  fVar4 = pfVar6[1] - *(float *)(in_ECX + 0x5c);
  if (SQRT(fVar3 * fVar3 + fVar4 * fVar4) < DAT_0099d0f8) {
    return;
  }
  FUN_0089ae20();
  FUN_00858a60();
  if (*(char *)(in_ECX + 0x151) == '\x01') {
    (**(code **)(*param_1 + 0xac))(param_1,0,0,3,0,0x3f800000,0);
    FUN_0089aef0(param_1);
    *(undefined1 *)(in_ECX + 0x151) = 0;
  }
  else {
    if (*(char *)(in_ECX + 0x150) != '\0') goto LAB_0089b145;
    (**(code **)(*param_1 + 0xac))(param_1,0,0,3,0,0x3f800000,0);
  }
  *(undefined1 *)(in_ECX + 0x150) = 1;
LAB_0089b145:
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  cVar5 = FUN_00881000(0x1c,0x70);
  if (cVar5 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  uVar7 = (**(code **)(*piVar1 + 0x1c))(0x1c,0x70);
  (**(code **)(*piVar1 + 0x14))(0x70,in_ECX + 0xd0);
  FUN_00881060();
  (**(code **)(*param_1 + 0x164))(param_1,0x144);
  iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar8 = *(int *)(in_ECX + 4);
  if (*(int *)(iVar2 + 0x134) != iVar8) {
    *(int *)(iVar2 + 0x134) = iVar8;
    (**(code **)(**(int **)(iVar2 + 0x90) + 0x104))(*(int **)(iVar2 + 0x90),0,iVar8);
  }
  piVar10 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar10 + 400))(piVar10,0,piVar1[1],0,0x1c);
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0x144))(piVar1,5,uVar7,2);
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  cVar5 = FUN_00881000(0x1c,0x70);
  if (cVar5 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  (**(code **)(*piVar1 + 0x1c))(0x1c,0x70);
  uVar7 = 0x70;
  (**(code **)(*piVar1 + 0x14))(0x70,in_ECX + 0x60);
  FUN_00881060();
  iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar8 = FUN_0089b020();
  iVar9 = 0;
  if (iVar8 != 0) {
    piVar10 = (int *)FUN_004af750();
    iVar9 = (**(code **)(*piVar10 + 4))();
  }
  if (*(int *)(iVar2 + 0x134) != iVar9) {
    *(int *)(iVar2 + 0x134) = iVar9;
    (**(code **)(**(int **)(iVar2 + 0x90) + 0x104))(*(int **)(iVar2 + 0x90),0,iVar9);
  }
  piVar10 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar10 + 400))(piVar10,0,piVar1[1],0,0x1c);
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0x144))(piVar1,5,uVar7,2);
  (**(code **)(*param_1 + 0x164))(param_1,0);
  FUN_00858b90();
  return;
}


// ==== FUN_0089b2f0 @ 0x0089b2f0 ====

void FUN_0089b2f0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 4))();
    *(undefined4 *)(iVar1 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(*(undefined4 *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  iVar1 = FUN_004b4e70(param_2);
  *(int *)(in_ECX + 8) = iVar1;
  if (iVar1 != 0) {
    *(undefined1 *)(in_ECX + 0x151) = 1;
  }
  return;
}


// ==== FUN_0089b340 @ 0x0089b340 ====

void FUN_0089b340(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x10);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_0089b360 @ 0x0089b360 ====

void FUN_0089b360(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a159a4;
  if (in_ECX[0x53] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x53]);
    in_ECX[0x53] = 0;
  }
  if (in_ECX[2] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[2]);
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_FUN_00a15290;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089b3c0 @ 0x0089b3c0 ====

undefined4 FUN_0089b3c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0089b3d0 @ 0x0089b3d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089b3d0(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar3 = DAT_009b0318;
  uVar2 = DAT_0099d080;
  fVar1 = (float)*(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0x4c) = DAT_009b0318;
  *(undefined4 *)(in_ECX + 0x50) = uVar3;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = uVar2;
  *(undefined4 *)(in_ECX + 0x5c) = 0x90ffffff;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  if (*(int *)(in_ECX + 8) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar1 = fVar1 - DAT_0099d0b4;
  *(float *)(in_ECX + 0x68) = fVar1;
  *(undefined4 *)(in_ECX + 0x6c) = uVar3;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined4 *)(in_ECX + 0x74) = uVar2;
  *(undefined4 *)(in_ECX + 0x84) = uVar3;
  *(float *)(in_ECX + 0x88) = fVar1;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x90) = uVar2;
  *(float *)(in_ECX + 0xa0) = fVar1;
  *(float *)(in_ECX + 0xa4) = fVar1;
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined4 *)(in_ECX + 0xac) = uVar2;
  *(undefined4 *)(in_ECX + 0x78) = 0x90ffffff;
  *(undefined4 *)(in_ECX + 0x7c) = uVar2;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x94) = 0x90ffffff;
  *(undefined4 *)(in_ECX + 0x98) = 0;
  *(undefined4 *)(in_ECX + 0x9c) = uVar2;
  *(undefined4 *)(in_ECX + 0xb0) = 0x90ffffff;
  *(undefined4 *)(in_ECX + 0xb4) = uVar2;
  *(undefined4 *)(in_ECX + 0xb8) = uVar2;
  return;
}


// ==== FUN_0089b570 @ 0x0089b570 ====

void FUN_0089b570(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_00a15a3c;
  in_ECX[2] = 0x100;
  in_ECX[0x2f] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xb] = 0;
  in_ECX[10] = 0;
  in_ECX[9] = 0;
  in_ECX[7] = 0;
  in_ECX[6] = 0;
  in_ECX[5] = 0;
  in_ECX[4] = 0;
  in_ECX[0x12] = uVar1;
  in_ECX[0xd] = uVar1;
  in_ECX[8] = uVar1;
  in_ECX[3] = uVar1;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x31] = 0;
  return;
}


// ==== FUN_0089b630 @ 0x0089b630 ====

void FUN_0089b630(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0089b650 @ 0x0089b650 ====

void FUN_0089b650(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15a3c;
  if (in_ECX[0x32] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x32]);
    in_ECX[0x32] = 0;
  }
  *in_ECX = &PTR_FUN_00a15290;
  return;
}


// ==== FUN_0089b690 @ 0x0089b690 ====

void FUN_0089b690(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = (int *)0x3;
  *(undefined4 *)(in_ECX + 8) = 0x200;
  (**(code **)(*param_1 + 0x28))(param_1,param_3,param_5,param_4,1,3,0x16);
  iVar1 = (**(code **)(*piVar2 + 0x5c))
                    (piVar2,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 8),1,1,0x16,0,
                     in_ECX + 4,0);
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 8) = 0x100;
    (**(code **)(*piVar2 + 0x5c))(piVar2,0x100,0x100,1,1,0x16,0,in_ECX + 4,0);
  }
  FUN_0089b3d0();
  return;
}


// ==== FUN_0089b710 @ 0x0089b710 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089b710(void)

{
  float fVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  float local_c4 [6];
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  float local_94;
  float local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  fVar1 = (float)*(int *)(in_ECX + 8);
  local_c4[0] = DAT_0099d0b4;
  local_c4[5] = (float)DAT_009b0318;
  local_c4[1] = 0.0;
  local_c4[2] = 0.0;
  local_c4[3] = 0.0;
  local_c4[4] = 0.0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = DAT_0099d080;
  local_98 = 0;
  if (*(int *)(in_ECX + 8) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  local_8c = 0;
  local_88 = DAT_0099d080;
  local_94 = DAT_0099d0b4 / fVar1 + *(float *)(in_ECX + 0xd4) + DAT_0099d0b4;
  local_90 = DAT_0099d0b4 / fVar1 + *(float *)(in_ECX + 0xd8) + DAT_0099d0b4;
  puVar2 = (undefined4 *)FUN_00862170(local_40,0x42a00000);
  puVar4 = local_80;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079ee7b(in_ECX + 0xc,local_80,local_c4);
  return;
}


// ==== FUN_0089b810 @ 0x0089b810 ====

void FUN_0089b810(uint param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 200) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_effect_cloud_tpack_00a15a10,0x12);
    uVar1 = FUN_00839580(local_1c);
    *(undefined4 *)(in_ECX + 200) = uVar1;
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    uVar1 = FUN_004b3b40();
    *(undefined4 *)(in_ECX + 0xc0) = uVar1;
  }
  if (*(uint *)(in_ECX + 0xc0) < param_1) {
    param_1 = *(uint *)(in_ECX + 0xc0);
  }
  FUN_004b3ff0(param_1);
  return;
}


// ==== FUN_0089b8a0 @ 0x0089b8a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089b8a0(void)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int in_ECX;
  float10 fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar4 = (**(code **)(**(int **)(DAT_00b5ac04 + 0xd0) + 0x54))();
  iVar1 = *(int *)(in_ECX + 0xbc);
  iVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar5 = iVar5 - iVar1;
  if (iVar1 == 0) {
    iVar5 = 0;
  }
  uVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(undefined4 *)(in_ECX + 0xbc) = uVar6;
  FUN_0040d600(&fStack_18,(float)*(byte *)(iVar4 + 2) * DAT_0099d0b4 * _DAT_00b532c0);
  fVar12 = (float)iVar5;
  if (iVar5 < 0) {
    fVar12 = fVar12 + _DAT_0099d104;
  }
  fVar10 = (float)*(byte *)(iVar4 + 1) * DAT_009a09b8 * fVar12 * DAT_0099d0ec;
  *(float *)(in_ECX + 0xd4) = fStack_18 * fVar10 + *(float *)(in_ECX + 0xd4);
  *(float *)(in_ECX + 0xd8) = *(float *)(in_ECX + 0xd8) + fStack_14 * fVar10;
  fVar9 = (float10)FUN_008044f0((double)*(float *)(in_ECX + 0xd4));
  *(float *)(in_ECX + 0xd4) = (float)((float10)*(float *)(in_ECX + 0xd4) - fVar9);
  fVar9 = (float10)FUN_008044f0((double)*(float *)(in_ECX + 0xd8));
  *(float *)(in_ECX + 0xd8) = (float)((float10)*(float *)(in_ECX + 0xd8) - fVar9);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar5 = FUN_0089b810();
  iVar7 = 0;
  if (iVar5 != 0) {
    piVar8 = (int *)FUN_004af750();
    iVar7 = (**(code **)(*piVar8 + 4))();
  }
  if (*(int *)(iVar1 + 0x134) != iVar7) {
    *(int *)(iVar1 + 0x134) = iVar7;
    (**(code **)(**(int **)(iVar1 + 0x90) + 0x104))(*(int **)(iVar1 + 0x90),0,iVar7);
  }
  fVar10 = (float)*(byte *)(iVar4 + 3) * DAT_0099d0b0;
  if (*(char *)(iVar4 + 4) == '\0') {
    *(float *)(in_ECX + 0xcc) = fVar10;
  }
  fVar11 = fVar10;
  if (fVar10 == *(float *)(in_ECX + 0xcc)) {
    *(undefined4 *)(in_ECX + 0xc4) = 0;
  }
  else {
    bVar2 = fVar10 == *(float *)(in_ECX + 0xcc);
    bVar3 = fVar10 < *(float *)(in_ECX + 0xcc);
    fVar12 = fVar12 * _DAT_009fc7b8 + *(float *)(in_ECX + 0xc4);
    *(float *)(in_ECX + 0xc4) = fVar12;
    if (bVar3 || bVar2) {
      if (!bVar3 && !bVar2) goto LAB_0089babb;
      fVar12 = *(float *)(in_ECX + 0xcc) - fVar12;
      if (fVar10 <= fVar12) goto LAB_0089bab0;
    }
    else {
      fVar12 = *(float *)(in_ECX + 0xcc) + fVar12;
      if (fVar12 < fVar10) {
LAB_0089bab0:
        fVar11 = fVar12;
      }
    }
  }
  *(float *)(in_ECX + 0xd0) = fVar11;
LAB_0089babb:
  uStack_10 = DAT_0099d080;
  uStack_c = DAT_0099d080;
  uStack_8 = DAT_0099d080;
  uStack_4 = *(undefined4 *)(in_ECX + 0xd0);
  uVar6 = FUN_0040ead0();
  *(undefined4 *)(in_ECX + 0xb0) = uVar6;
  *(undefined4 *)(in_ECX + 0x94) = uVar6;
  *(undefined4 *)(in_ECX + 0x78) = uVar6;
  *(undefined4 *)(in_ECX + 0x5c) = uVar6;
  if (*(float *)(in_ECX + 0xd0) == fVar10) {
    *(float *)(in_ECX + 0xcc) = fVar10;
    *(undefined4 *)(in_ECX + 0xc4) = 0;
  }
  return;
}


// ==== FUN_0089bb40 @ 0x0089bb40 ====

void FUN_0089bb40(int *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int in_ECX;
  
  FUN_0089b710();
  FUN_0089b8a0();
  FUN_00858a60();
  (**(code **)(*param_1 + 0xac))(param_1,0,0,3,0xffffffff,0x3f800000,0);
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  cVar3 = FUN_00881000(0x1c,0x70);
  if (cVar3 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  uVar4 = (**(code **)(*piVar1 + 0x1c))(0x1c,0x70);
  (**(code **)(*piVar1 + 0x14))(0x70,in_ECX + 0x4c);
  FUN_00881060();
  (**(code **)(*param_1 + 0x164))(param_1,0x144);
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x1c)
  ;
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0x144))(piVar1,5,uVar4,2);
  (**(code **)(*param_1 + 0x164))(param_1,0);
  iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar2 + 0x112) != '\x01') {
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),7,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0xe,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x17,4);
    *(undefined1 *)(iVar2 + 0x112) = 1;
  }
  FUN_00858b90();
  return;
}


// ==== FUN_0089bc90 @ 0x0089bc90 ====

void FUN_0089bc90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15a3c;
  if (in_ECX[0x32] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x32]);
    in_ECX[0x32] = 0;
  }
  *in_ECX = &PTR_FUN_00a15290;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089bce0 @ 0x0089bce0 ====

undefined4 FUN_0089bce0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0089bcf0 @ 0x0089bcf0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089bcf0(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar3 = DAT_009b0318;
  uVar2 = DAT_0099d080;
  fVar1 = (float)*(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0x58) = DAT_009b0318;
  *(undefined4 *)(in_ECX + 0x5c) = uVar3;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = uVar2;
  *(undefined4 *)(in_ECX + 0x68) = 0x70ffffff;
  if (*(int *)(in_ECX + 8) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar1 = fVar1 - DAT_0099d0b4;
  *(float *)(in_ECX + 0x7c) = fVar1;
  *(undefined4 *)(in_ECX + 0x80) = uVar3;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)(in_ECX + 0x88) = uVar2;
  *(undefined4 *)(in_ECX + 0xa0) = uVar3;
  *(float *)(in_ECX + 0xa4) = fVar1;
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined4 *)(in_ECX + 0xac) = uVar2;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 0x70) = uVar2;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x78) = uVar2;
  *(float *)(in_ECX + 0xc4) = fVar1;
  *(float *)(in_ECX + 200) = fVar1;
  *(undefined4 *)(in_ECX + 0xcc) = 0;
  *(undefined4 *)(in_ECX + 0xd0) = uVar2;
  *(undefined4 *)(in_ECX + 0x8c) = 0x70ffffff;
  *(undefined4 *)(in_ECX + 0xb0) = 0x70ffffff;
  *(undefined4 *)(in_ECX + 0xd4) = 0x70ffffff;
  *(undefined4 *)(in_ECX + 0xd8) = uVar2;
  *(undefined4 *)(in_ECX + 0xdc) = uVar2;
  *(undefined4 *)(in_ECX + 0xe0) = uVar2;
  *(undefined4 *)(in_ECX + 0xe4) = uVar2;
  return;
}


// ==== FUN_0089bea0 @ 0x0089bea0 ====

void FUN_0089bea0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_00a15ae8;
  in_ECX[2] = 0x100;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xb] = 0;
  in_ECX[10] = 0;
  in_ECX[9] = 0;
  in_ECX[7] = 0;
  in_ECX[6] = 0;
  in_ECX[5] = 0;
  in_ECX[4] = 0;
  in_ECX[0x12] = uVar1;
  in_ECX[0xd] = uVar1;
  in_ECX[8] = uVar1;
  in_ECX[3] = uVar1;
  in_ECX[0x15] = 0x5a;
  in_ECX[0x3a] = 0;
  in_ECX[0x3b] = 0;
  return;
}


// ==== FUN_0089bf50 @ 0x0089bf50 ====

void FUN_0089bf50(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0089bf70 @ 0x0089bf70 ====

void FUN_0089bf70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15ae8;
  if (in_ECX[0x3c] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x3c]);
    in_ECX[0x3c] = 0;
  }
  *in_ECX = &PTR_FUN_00a15290;
  return;
}


// ==== FUN_0089bfb0 @ 0x0089bfb0 ====

void FUN_0089bfb0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = (int *)0x3;
  *(undefined4 *)(in_ECX + 8) = 0x200;
  (**(code **)(*param_1 + 0x28))(param_1,param_3,param_5,param_4,1,3,0x16);
  iVar1 = (**(code **)(*piVar2 + 0x5c))
                    (piVar2,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 8),1,1,0x16,0,
                     in_ECX + 4,0);
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 8) = 0x100;
    (**(code **)(*piVar2 + 0x5c))(piVar2,0x100,0x100,1,1,0x16,0,in_ECX + 4,0);
  }
  FUN_0089bcf0();
  return;
}


// ==== FUN_0089c030 @ 0x0089c030 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089c030(void)

{
  float fVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  float local_c4 [6];
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  float local_94;
  float local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  fVar1 = (float)*(int *)(in_ECX + 8);
  local_c4[0] = DAT_0099d0b4;
  local_c4[5] = (float)DAT_009b0318;
  local_c4[1] = 0.0;
  local_c4[2] = 0.0;
  local_c4[3] = 0.0;
  local_c4[4] = 0.0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = DAT_0099d080;
  local_98 = 0;
  if (*(int *)(in_ECX + 8) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  local_8c = 0;
  local_88 = DAT_0099d080;
  local_94 = DAT_0099d0b4 / fVar1 + *(float *)(in_ECX + 0xe8) + DAT_0099d0b4;
  local_90 = DAT_0099d0b4 / fVar1 + *(float *)(in_ECX + 0xec) + DAT_0099d0b4;
  puVar2 = (undefined4 *)FUN_00862170(local_40,0x41000000);
  puVar4 = local_80;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079ee7b(in_ECX + 0xc,local_80,local_c4);
  return;
}


// ==== FUN_0089c130 @ 0x0089c130 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089c130(void)

{
  int iVar1;
  float *pfVar2;
  int in_ECX;
  float10 fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fStack_10;
  float fStack_c;
  
  iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  fVar7 = (float)iVar1;
  *(int *)(in_ECX + 0x4c) = iVar1;
  if (iVar1 < 0) {
    fVar7 = fVar7 + _DAT_0099d104;
  }
  fVar7 = fVar7 * DAT_0099d0ec;
  fVar4 = fVar7 * DAT_009a09b8;
  pfVar2 = (float *)FUN_0040d600(&fStack_10,DAT_00b53310 * DAT_009b2dc0);
  fVar5 = pfVar2[1];
  *(float *)(in_ECX + 0xe8) = *pfVar2 * fVar4;
  *(float *)(in_ECX + 0xec) = fVar5 * fVar4;
  fVar3 = (float10)FUN_008044f0((double)*(float *)(in_ECX + 0xe8));
  *(float *)(in_ECX + 0xe8) = (float)((float10)*(float *)(in_ECX + 0xe8) - fVar3);
  fVar3 = (float10)FUN_008044f0((double)*(float *)(in_ECX + 0xec));
  fVar4 = fVar7 * _DAT_00a15b10;
  fVar5 = DAT_00b53310 * DAT_009b02a8;
  *(float *)(in_ECX + 0xec) = (float)((float10)*(float *)(in_ECX + 0xec) - fVar3);
  pfVar2 = (float *)FUN_0040d600(&fStack_10,fVar5);
  fVar5 = *pfVar2 * fVar4;
  fVar4 = pfVar2[1] * fVar4;
  fVar3 = (float10)FUN_008044f0((double)fVar5);
  fStack_10 = (float)((float10)fVar5 - fVar3);
  fVar3 = (float10)FUN_008044f0((double)fVar4);
  fVar5 = DAT_009a000c;
  fVar6 = fStack_10 + DAT_0099d0b4;
  fStack_c = (float)((float10)fVar4 - fVar3);
  fVar8 = fStack_c + DAT_0099d0b4;
  *(float *)(in_ECX + 0x6c) = fVar6;
  *(float *)(in_ECX + 0x70) = fVar8;
  fVar9 = fStack_10 + fVar5;
  *(float *)(in_ECX + 0xb4) = fVar6;
  fVar7 = fVar7 * DAT_009c3038;
  fVar4 = DAT_00b53310 * DAT_009b6df8;
  fVar5 = fStack_c + fVar5;
  *(float *)(in_ECX + 0x90) = fVar9;
  *(float *)(in_ECX + 0x94) = fVar8;
  *(float *)(in_ECX + 0xb8) = fVar5;
  *(float *)(in_ECX + 0xd8) = fVar9;
  *(float *)(in_ECX + 0xdc) = fVar5;
  pfVar2 = (float *)FUN_0040d600(&fStack_10,fVar4);
  fVar5 = *pfVar2 * fVar7;
  fVar7 = pfVar2[1] * fVar7;
  fVar3 = (float10)FUN_008044f0((double)fVar5);
  fStack_10 = (float)((float10)fVar5 - fVar3);
  fVar3 = (float10)FUN_008044f0((double)fVar7);
  fVar5 = fStack_10 + DAT_0099d0b4;
  fVar7 = (float)((float10)fVar7 - fVar3);
  fVar4 = fVar7 + DAT_0099d0b4;
  fStack_10 = fStack_10 + DAT_009a000c;
  fVar7 = fVar7 + DAT_009a000c;
  *(float *)(in_ECX + 0x74) = fVar5;
  *(float *)(in_ECX + 0x78) = fVar4;
  *(float *)(in_ECX + 0x98) = fStack_10;
  *(float *)(in_ECX + 0x9c) = fVar4;
  *(float *)(in_ECX + 0xbc) = fVar5;
  *(float *)(in_ECX + 0xc0) = fVar7;
  *(float *)(in_ECX + 0xe0) = fStack_10;
  *(float *)(in_ECX + 0xe4) = fVar7;
  return;
}


// ==== FUN_0089c3f0 @ 0x0089c3f0 ====

void FUN_0089c3f0(uint param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0xf0) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_effect_caustic_tpack_00a15aa0,0x14);
    uVar2 = FUN_00839580(local_1c);
    *(undefined4 *)(in_ECX + 0xf0) = uVar2;
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    uVar2 = FUN_004b3b40();
    *(undefined4 *)(in_ECX + 0x50) = uVar2;
  }
  if (param_1 < *(uint *)(in_ECX + 0x50)) {
    FUN_004b3ff0(param_1);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_dwIndex_<_m_dwMaxTex_00a15ab8,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0089c4c0 @ 0x0089c4c0 ====

void FUN_0089c4c0(int *param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  
  FUN_0089c130();
  FUN_0089c030();
  (**(code **)(*param_1 + 0xac))(param_1,0,0,3,0xffffffff,0x3f800000,0);
  FUN_00859ee0();
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar4 = FUN_0089c3f0(1);
  iVar5 = 0;
  if (iVar4 != 0) {
    piVar6 = (int *)FUN_004af750();
    iVar5 = (**(code **)(*piVar6 + 4))();
  }
  if (*(int *)(iVar1 + 0x134) != iVar5) {
    *(int *)(iVar1 + 0x134) = iVar5;
    (**(code **)(**(int **)(iVar1 + 0x90) + 0x104))(*(int **)(iVar1 + 0x90),0,iVar5);
  }
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar4 = FUN_0089c3f0(0);
  iVar5 = 0;
  if (iVar4 != 0) {
    piVar6 = (int *)FUN_004af750();
    iVar5 = (**(code **)(*piVar6 + 4))();
  }
  if (*(int *)(iVar1 + 0x138) != iVar5) {
    *(int *)(iVar1 + 0x138) = iVar5;
    (**(code **)(**(int **)(iVar1 + 0x90) + 0x104))(*(int **)(iVar1 + 0x90),1,iVar5);
  }
  piVar6 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  cVar3 = FUN_00881000(0x24,0x90);
  if (cVar3 == '\0') {
    (**(code **)(*piVar6 + 0xc))();
  }
  uVar7 = (**(code **)(*piVar6 + 0x1c))(0x24,0x90);
  (**(code **)(*piVar6 + 0x14))(0x90,in_ECX + 0x58);
  FUN_00881060();
  (**(code **)(*param_1 + 0x164))(param_1,0x344);
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 400))(piVar2,0,piVar6[1],0,0x24);
  piVar6 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar6 + 0x144))(piVar6,5,uVar7,2);
  (**(code **)(*param_1 + 0x164))(param_1,0);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(int *)(iVar1 + 0x138) != 0) {
    *(undefined4 *)(iVar1 + 0x138) = 0;
    (**(code **)(**(int **)(iVar1 + 0x90) + 0x104))(*(int **)(iVar1 + 0x90),1,0);
  }
  FUN_0085a050();
  return;
}


// ==== FUN_0089c670 @ 0x0089c670 ====

void FUN_0089c670(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0xc);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_0089c690 @ 0x0089c690 ====

void FUN_0089c690(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15ae8;
  if (in_ECX[0x3c] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x3c]);
    in_ECX[0x3c] = 0;
  }
  *in_ECX = &PTR_FUN_00a15290;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089c6f0 @ 0x0089c6f0 ====

undefined4 FUN_0089c6f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0089c700 @ 0x0089c700 ====

void FUN_0089c700(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15b68;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[5] = 0x100;
  in_ECX[6] = 0x100;
  in_ECX[0x15] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xb] = 0;
  in_ECX[10] = 0;
  in_ECX[9] = 0;
  in_ECX[8] = 0;
  uVar1 = DAT_0099d080;
  in_ECX[0x16] = DAT_0099d080;
  in_ECX[0x11] = uVar1;
  in_ECX[0xc] = uVar1;
  in_ECX[7] = uVar1;
  return;
}


// ==== FUN_0089c780 @ 0x0089c780 ====

void FUN_0089c780(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  piVar1 = *(int **)(in_ECX + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_0089c7d0 @ 0x0089c7d0 ====

void FUN_0089c7d0(int *param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_30;
  
  *(undefined4 *)(in_ECX + 0x18) = 0x200;
  *(undefined4 *)(in_ECX + 0x14) = 0x200;
  iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (2 < *(byte *)(iVar1 + 9)) {
    *(undefined4 *)(in_ECX + 0x14) = 0x400;
    *(undefined4 *)(in_ECX + 0x18) = 0x400;
  }
  iVar1 = (**(code **)(*param_1 + 0x28))();
  if (iVar1 < 0) {
    *(undefined1 *)(in_ECX + 0x10) = 1;
    return;
  }
  uStack_48 = *(undefined4 *)(in_ECX + 0x18);
  uStack_30 = 0;
  iStack_34 = in_ECX + 4;
  uStack_38 = 0;
  uStack_3c = 0x16;
  uStack_40 = 1;
  uStack_44 = 1;
  (**(code **)(iRam00000003 + 0x5c))(3,*(undefined4 *)(in_ECX + 0x14));
  FUN_008560c0(&uStack_44,&uStack_48);
  (**(code **)(iRam00000003 + 0x74))
            (3,*(undefined4 *)(in_ECX + 0x14),*(undefined4 *)(in_ECX + 0x18),uStack_48,0,0,0,
             in_ECX + 0xc,0);
  return;
}


// ==== FUN_0089c890 @ 0x0089c890 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089c890(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined4 *puVar7;
  float local_80 [6];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 auStack_40 [64];
  
  fVar4 = (float)*(int *)(in_ECX + 0x14);
  local_80[0] = DAT_0099d0b4;
  local_80[5] = (float)DAT_009b0318;
  local_80[1] = 0.0;
  local_80[2] = 0.0;
  local_80[3] = 0.0;
  local_80[4] = 0.0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = DAT_0099d080;
  local_54 = 0;
  if (*(int *)(in_ECX + 0x14) < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  local_50 = DAT_0099d0b4 / fVar4 + DAT_0099d0b4;
  fVar4 = (float)*(int *)(in_ECX + 0x18);
  if (*(int *)(in_ECX + 0x18) < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  local_48 = 0;
  local_44 = DAT_0099d080;
  local_4c = DAT_0099d0b4 / fVar4 + DAT_0099d0b4;
  iVar5 = *(int *)(DAT_00b5ac04 + 0x74);
  uVar1 = *(undefined4 *)(iVar5 + 0x1c);
  uVar2 = *(undefined4 *)(iVar5 + 0x20);
  uVar3 = *(undefined4 *)(iVar5 + 0x24);
  iVar5 = (**(code **)(*DAT_00b5ac00 + 8))();
  puVar6 = (undefined4 *)FUN_008647e0(auStack_40,uVar1,uVar2,uVar3,*(byte *)(iVar5 + 9) < 3);
  puVar7 = (undefined4 *)(in_ECX + 0x5c);
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  thunk_FUN_0079ee7b(in_ECX + 0x1c,(undefined4 *)(in_ECX + 0x5c),local_80);
  return;
}


// ==== FUN_0089c9c0 @ 0x0089c9c0 ====

void FUN_0089c9c0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  
  iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
  if ((*(char *)(iVar3 + 9) != '\0') && (*(char *)(in_ECX + 0x10) == '\0')) {
    iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
    piVar1 = (int *)(in_ECX + 8);
    if (*(char *)(iVar3 + 9) == '\x01') {
      (**(code **)(*param_1 + 0xa0))();
      (**(code **)(*param_1 + 0x9c))(param_1,0);
      FUN_0089c890();
      uVar4 = 1;
    }
    else {
      (**(code **)(*param_1 + 0xa0))(param_1,piVar1);
      (**(code **)(*param_1 + 0x9c))(param_1,*(undefined4 *)(in_ECX + 0xc));
      FUN_0089c890();
      uVar4 = 3;
    }
    (**(code **)(*param_1 + 0xac))(param_1,0,0,uVar4,0xffffffff,0x3f800000,0);
    FUN_0085a4d0();
    (**(code **)(*param_1 + 0x9c))(param_1,*piVar1);
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *piVar1 = 0;
    }
  }
  return;
}


// ==== FUN_0089ca90 @ 0x0089ca90 ====

void FUN_0089ca90(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x5c);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_0089cab0 @ 0x0089cab0 ====

void FUN_0089cab0(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x1c);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_0089caf0 @ 0x0089caf0 ====

void FUN_0089caf0(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  char acStack_20a [258];
  undefined1 auStack_108 [260];
  undefined4 uStack_4;
  
  puVar2 = (undefined4 *)FUN_0049c740();
  iVar5 = **(int **)(param_2 + 0x100);
  iVar3 = FUN_0049c740(*puVar2);
  uVar4 = (**(code **)(iVar5 + 8))(*(undefined4 *)(iVar3 + 4));
  iVar5 = FUN_0049c740();
  if (*(uint *)(iVar5 + 4) <= uVar4) {
    do {
      auStack_108[0] = 0;
      uVar6 = FUN_0044a580(auStack_108,s_Expand_Buffer____s_00a15b94,param_2);
      FUN_00797b80(uVar6);
      (**(code **)(**(int **)(param_2 + 0x100) + 4))(0,0);
      FUN_0049c7e0();
      puVar2 = (undefined4 *)FUN_0049c740();
      iVar5 = **(int **)(param_2 + 0x100);
      iVar3 = FUN_0049c740(*puVar2);
      uVar4 = (**(code **)(iVar5 + 8))(*(undefined4 *)(iVar3 + 4));
      iVar5 = FUN_0049c740();
    } while (*(uint *)(iVar5 + 4) <= uVar4);
  }
  piVar7 = (int *)FUN_0049c740();
  *(undefined1 *)(*piVar7 + uVar4) = 0;
  uVar4 = 0;
  do {
    cVar1 = (acStack_20a + (uVar4 - 10))[param_2 - (int)(acStack_20a + -10)];
    acStack_20a[uVar4 - 10] = cVar1;
    if (cVar1 == '\0') break;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  FUN_0049c740();
  FUN_0089cce0(uStack_4,acStack_20a + -10);
  return;
}


// ==== FUN_0089cc50 @ 0x0089cc50 ====

void FUN_0089cc50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15bb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089cce0 @ 0x0089cce0 ====

void FUN_0089cce0(int *param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int local_134;
  int local_130;
  uint local_12c;
  int iStack_128;
  int iStack_124;
  int iStack_120;
  int iStack_11c;
  undefined1 uStack_118;
  int iStack_114;
  int iStack_110;
  int iStack_10c;
  int iStack_108;
  undefined1 uStack_104;
  undefined1 auStack_100 [256];
  
  iVar8 = 0;
  if (DAT_00b5a6b0 != (int *)0x0) {
    iVar6 = (**(code **)(*DAT_00b5a6b0 + 8))();
    bVar2 = false;
    if (iVar6 != 0) goto LAB_0089cd08;
  }
  bVar2 = true;
LAB_0089cd08:
  iVar6 = 0;
  local_130 = 0;
  local_134 = 0;
  bVar3 = false;
  local_12c = 0;
  if (*(int *)(param_2 + 0x104) != 0) {
    do {
      cVar1 = *(char *)(local_12c + *(int *)(param_2 + 0x100));
      if (cVar1 == '\0') {
        auStack_100[0] = 0;
        uVar7 = FUN_0044a580(auStack_100,s_I_Wrong_Length____s_00a15c2e + 2,param_2);
        FUN_00797b80(uVar7);
        break;
      }
      if (iVar8 == 0) {
        local_130 = local_12c + *(int *)(param_2 + 0x100);
      }
      if (bVar3) {
        bVar3 = false;
LAB_0089cd58:
        iVar8 = iVar8 + 1;
      }
      else {
        if (bVar2) {
          if (cVar1 < '\0') goto LAB_0089cd8a;
LAB_0089cd96:
          bVar4 = false;
        }
        else {
          cVar5 = FUN_00403d70((int)cVar1);
          if (cVar5 == '\0') goto LAB_0089cd96;
LAB_0089cd8a:
          bVar4 = true;
          if (bVar3) goto LAB_0089cd96;
        }
        bVar3 = bVar4;
        if (cVar1 == *(char *)(param_2 + 0x109)) {
          if (iVar8 != 0) {
            uStack_104 = *(undefined1 *)(param_2 + 0x10a);
            iStack_10c = local_130;
            iStack_114 = local_134;
            iStack_110 = iVar6;
            iStack_108 = iVar8;
            (**(code **)(*param_1 + 0x14))(&iStack_114);
          }
          iVar6 = iVar6 + 1;
          iVar8 = 0;
        }
        else {
          if (cVar1 != *(char *)(param_2 + 0x108)) goto LAB_0089cd58;
          if (iVar8 != 0) {
            uStack_118 = *(undefined1 *)(param_2 + 0x10a);
            iStack_120 = local_130;
            iStack_128 = local_134;
            iStack_124 = iVar6;
            iStack_11c = iVar8;
            (**(code **)(*param_1 + 0x14))(&iStack_128);
          }
          local_134 = local_134 + 1;
          iVar8 = 0;
          iVar6 = 0;
        }
      }
      local_12c = local_12c + 1;
    } while (local_12c < *(uint *)(param_2 + 0x104));
    if (iVar8 != 0) {
      uStack_118 = *(undefined1 *)(param_2 + 0x10a);
      iStack_128 = local_134;
      iStack_120 = local_130;
      iStack_124 = iVar6;
      iStack_11c = iVar8;
      (**(code **)(*param_1 + 0x14))(&iStack_128);
    }
  }
  return;
}


// ==== FUN_0089cea0 @ 0x0089cea0 ====

void FUN_0089cea0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15c58;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089cec0 @ 0x0089cec0 ====

void FUN_0089cec0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_0089cf10 @ 0x0089cf10 ====

bool FUN_0089cf10(void)

{
  _MEMORYSTATUS local_20;
  
  GlobalMemoryStatus(&local_20);
  return local_20.dwAvailPhys < 0x6400000;
}


// ==== FUN_0089cf30 @ 0x0089cf30 ====

void FUN_0089cf30(int param_1)

{
  int *in_ECX;
  _MEMORYSTATUS local_20;
  
  if (600000 < (uint)(param_1 - in_ECX[1])) {
    (**(code **)(*DAT_00b5a7cc + 0x20))(600000);
    in_ECX[1] = param_1;
    *in_ECX = param_1;
  }
  if (60000 < (uint)(param_1 - *in_ECX)) {
    GlobalMemoryStatus(&local_20);
    if (local_20.dwAvailPhys < 0x6400000) {
      (**(code **)(*DAT_00b5a7cc + 0x20))(60000);
    }
    *in_ECX = param_1;
  }
  return;
}


// ==== FUN_0089cfb0 @ 0x0089cfb0 ====

/* WARNING: Removing unreachable block (ram,0x0089d24a) */
/* WARNING: Removing unreachable block (ram,0x0089d1db) */
/* WARNING: Removing unreachable block (ram,0x0089d22a) */

undefined4 FUN_0089cfb0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  HWND pHVar8;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  BOOL BVar9;
  LPSTR pCVar10;
  int in_ECX;
  int unaff_EBP;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  void *pvStack_28c;
  undefined1 local_288 [4];
  undefined1 local_284;
  uint uStack_278;
  tagOFNA local_274;
  undefined4 uStack_214;
  uint uStack_210;
  CHAR aCStack_20c [8];
  char local_204 [248];
  char acStack_10c [268];
  
  iVar2 = *(int *)(in_ECX + 0x48);
  iVar11 = *(int *)(in_ECX + 0x44);
  iVar12 = 0;
  if (iVar11 != iVar2) {
    puVar13 = (undefined4 *)(iVar11 + 0x20);
    do {
      if ((uint)puVar13[-2] < 0x10) {
        puVar4 = puVar13 + -7;
      }
      else {
        puVar4 = (undefined4 *)puVar13[-7];
      }
      iVar3 = __snprintf(local_204 + iVar12,0xff - iVar12,&DAT_00a15cc0,puVar4);
      if (iVar3 < 0) break;
      iVar12 = iVar12 + 1 + iVar3;
      if ((uint)puVar13[5] < 0x10) {
        puVar4 = puVar13;
      }
      else {
        puVar4 = (undefined4 *)*puVar13;
      }
      iVar3 = __snprintf(local_204 + iVar12,0xff - iVar12,&DAT_00a15cc4,puVar4);
      if (iVar3 < 0) break;
      iVar11 = iVar11 + 0x38;
      puVar13 = puVar13 + 0xe;
      iVar12 = iVar12 + 1 + iVar3;
    } while (iVar11 != iVar2);
  }
  local_204[iVar12] = '\0';
  local_274.hwndOwner = (HWND)0xf;
  local_274.lStructSize = 0;
  local_284 = 0;
  pcVar5 = PTR_s_WindowHandle_00b5343c;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_WindowHandle_00b5343c,(int)pcVar5 - (int)(PTR_s_WindowHandle_00b5343c + 1));
  piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar7 = (**(code **)(*piVar6 + 8))(&local_274.FlagsEx,local_288);
  pHVar8 = (HWND)thunk_FUN_00796e90(uVar7);
  if (0xf < uStack_210) {
    _free((void *)local_274.dwReserved);
    return extraout_EAX;
  }
  uStack_210 = 0xf;
  uStack_214 = 0;
  local_274.dwReserved = local_274.dwReserved & 0xffffff00;
  if (0xf < uStack_278) {
    _free(pvStack_28c);
    return extraout_EAX_00;
  }
  FUN_00401740(&DAT_00a15cc7,0);
  FUN_00403ea0(&local_274,0,0x4c);
  local_274.lpstrFilter = aCStack_20c;
  local_274.lpstrFile = acStack_10c;
  local_274.lStructSize = 0x4c;
  acStack_10c[0] = '\0';
  local_274.nMaxFile = 0x104;
  local_274.nFilterIndex = 0;
  local_274.lpstrFileTitle = (LPSTR)0x0;
  if (*(uint *)(unaff_EBP + 0x1c) < 0x10) {
    local_274.lpstrTitle = (LPCSTR)(unaff_EBP + 8);
  }
  else {
    local_274.lpstrTitle = *(LPCSTR *)(unaff_EBP + 8);
  }
  local_274.nMaxFileTitle = 0;
  if (*(uint *)(unaff_EBP + 0x38) < 0x10) {
    local_274.lpstrInitialDir = (LPCSTR)(unaff_EBP + 0x24);
  }
  else {
    local_274.lpstrInitialDir = *(LPCSTR *)(unaff_EBP + 0x24);
  }
  local_274.Flags = 0x1800;
  local_274.hwndOwner = pHVar8;
  if (*(int *)(unaff_EBP + 0x3c) == 1) {
    BVar9 = GetOpenFileNameA(&local_274);
    if (BVar9 != 1) {
      return 0;
    }
    pCVar10 = local_274.lpstrFile;
    do {
      cVar1 = *pCVar10;
      pCVar10 = pCVar10 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(local_274.lpstrFile,(int)pCVar10 - (int)(local_274.lpstrFile + 1));
  }
  else {
    BVar9 = GetSaveFileNameA(&local_274);
    if (BVar9 != 1) {
      return 0;
    }
    pCVar10 = local_274.lpstrFile;
    do {
      cVar1 = *pCVar10;
      pCVar10 = pCVar10 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(local_274.lpstrFile,(int)pCVar10 - (int)(local_274.lpstrFile + 1));
  }
  return 1;
}


// ==== FUN_0089d270 @ 0x0089d270 ====

int FUN_0089d270(int param_1,undefined1 param_2,void *param_3)

{
  int iVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int in_ECX;
  int iVar2;
  int in_stack_0000001c;
  uint in_stack_00000020;
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
  FUN_00401660(in_ECX + 0x20,0,0xffffffff);
  iVar1 = FUN_004041d0(local_1c,&param_2);
  FUN_004041d0(local_38,local_54);
  if (*(uint *)(iVar1 + 0x18) < 0x10) {
    iVar2 = iVar1 + 4;
  }
  else {
    iVar2 = *(int *)(iVar1 + 4);
  }
  iVar1 = FUN_00405850(iVar2,0,*(undefined4 *)(iVar1 + 0x14));
  if (0xf < local_20) {
    _free(local_34);
    return extraout_EAX;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_00;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (iVar1 == -1) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(local_54,0,0xffffffff);
    if (0xf < local_3c) {
      _free(local_50);
      return extraout_EAX_02;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(local_54,in_stack_0000001c + iVar1,0xffffffff);
    if (0xf < local_3c) {
      _free(local_50);
      return extraout_EAX_01;
    }
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  if (in_stack_00000020 < 0x10) {
    return param_1;
  }
  _free(param_3);
  return extraout_EAX_03;
}


// ==== FUN_0089d3c0 @ 0x0089d3c0 ====

void FUN_0089d3c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15cfc;
  if (in_ECX[0x11] != 0) {
    FUN_004e65b0(in_ECX[0x11],in_ECX[0x12],in_ECX + 0x10);
    _free((void *)in_ECX[0x11]);
    return;
  }
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
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
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0089d450 @ 0x0089d450 ====

void FUN_0089d450(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00401660(param_2,0,0xffffffff);
  FUN_0089dd50(&param_1,*(undefined4 *)(in_ECX + 0x44),local_38);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_4 = 0xf;
  if (local_20 < 0x10) {
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_0089d500 @ 0x0089d500 ====

void FUN_0089d500(void)

{
  undefined *_Memory;
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  undefined1 local_70 [4];
  undefined1 local_6c;
  uint uStack_60;
  undefined4 local_5c;
  void *local_58;
  undefined1 auStack_54 [12];
  undefined4 uStack_48;
  uint uStack_44;
  undefined1 auStack_40 [4];
  void *pvStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  *in_ECX = &PTR_FUN_00a15cfc;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  FUN_00401740(s_File_open_00a15ca0,9);
  _Memory = PTR_s_DataPath_00b53440 + 1;
  local_58 = (void *)0xf;
  local_5c = 0;
  local_6c = 0;
  pcVar2 = PTR_s_DataPath_00b53440;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_DataPath_00b53440,(int)pcVar2 - (int)_Memory);
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar4 = (**(code **)(*piVar3 + 8))(auStack_54,local_70);
  FUN_00401660(uVar4,0,0xffffffff);
  if (0xf < uStack_44) {
    _free(local_58);
    return;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  if (0xf < uStack_60) {
    _free(_Memory);
    return;
  }
  in_ECX[0xf] = 1;
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  FUN_00401740(s_All_Files______00a15cac,0xe);
  FUN_00401740(&DAT_00a15cbc,3);
  FUN_0089ddf0(auStack_40);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  if (uStack_28 < 0x10) {
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_0089d680 @ 0x0089d680 ====

void FUN_0089d680(void)

{
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x44) != 0) {
    FUN_004e65b0(*(int *)(in_ECX + 0x44),*(undefined4 *)(in_ECX + 0x48),in_ECX + 0x40);
    _free(*(void **)(in_ECX + 0x44));
    return;
  }
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_All_Files______00a15cc8,0xe);
  FUN_00401740(&DAT_00a15cd8,3);
  FUN_0089ddf0(local_38);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_4 = 0xf;
  if (local_20 < 0x10) {
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_0089d750 @ 0x0089d750 ====

void FUN_0089d750(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x34)) {
    _free(*(void **)(param_1 + 0x20));
    return;
  }
  *(undefined4 *)(param_1 + 0x34) = 0xf;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined1 *)(param_1 + 4) = 0;
    return;
  }
  _free(*(void **)(param_1 + 4));
  return;
}


// ==== FUN_0089d7a0 @ 0x0089d7a0 ====

void FUN_0089d7a0(int param_1,int param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2,0,0xffffffff);
    *(undefined4 *)(param_1 + 0x34) = 0xf;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined1 *)(param_1 + 0x20) = 0;
    FUN_00401660(param_2 + 0x1c,0,0xffffffff);
  }
  return;
}


// ==== FUN_0089d7f0 @ 0x0089d7f0 ====

int FUN_0089d7f0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a970;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x38) {
    FUN_0089d7a0(param_3,param_1);
    param_3 = param_3 + 0x38;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0089d85a @ 0x0089d85a ====

void Catch_0089d85a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x38) {
    FUN_0089d750(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0089d880 @ 0x0089d880 ====

void FUN_0089d880(int param_1,int param_2,int param_3)

{
  if (param_1 != param_2) {
    do {
      FUN_00401660(param_3,0,0xffffffff);
      FUN_00401660(param_3 + 0x1c,0,0xffffffff);
      param_1 = param_1 + 0x38;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0089d8c0 @ 0x0089d8c0 ====

void FUN_0089d8c0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a980;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0089d7a0(param_1,param_3);
    param_1 = param_1 + 0x38;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0089d92a @ 0x0089d92a ====

void Catch_0089d92a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x38) {
    FUN_0089d750(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0089d950 @ 0x0089d950 ====

void FUN_0089d950(undefined4 param_1,undefined4 param_2)

{
  FUN_004e65b0(param_1,param_2);
  return;
}


// ==== FUN_0089d970 @ 0x0089d970 ====

void FUN_0089d970(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0089d7f0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0089d990 @ 0x0089d990 ====

int FUN_0089d990(int param_1,int param_2,undefined4 param_3)

{
  FUN_0089d8c0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x38;
}


// ==== FUN_0089d9c0 @ 0x0089d9c0 ====

void FUN_0089d9c0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined1 local_84 [2];
  undefined1 auStack_82 [2];
  void *local_80;
  undefined4 local_70;
  uint local_6c;
  void *local_64;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  void *local_20;
  int local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a990;
  local_10 = ExceptionList;
  local_14 = local_84 + -0xc;
  local_6c = 0xf;
  local_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_50 = 0xf;
  local_54 = 0;
  local_64 = (void *)((uint)local_64 & 0xffffff00);
  FUN_00401660(param_3 + 0x1c,0,0xffffffff);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x38;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      local_28 = *(int *)(in_ECX + 8) - iVar2;
      iVar1 = local_28 / 0x38;
    }
    if (0x4924924U - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      local_2c = *(int *)(in_ECX + 8) - iVar2;
      iVar1 = local_2c / 0x38;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x4924924 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        local_30 = *(int *)(in_ECX + 8) - iVar2;
        iVar2 = local_30 / 0x38;
      }
      if (uVar4 < iVar2 + param_2) {
        iVar2 = FUN_00875fa0();
        uVar4 = iVar2 + param_2;
      }
      local_34 = uVar4 * 0x38;
      local_20 = operator_new(local_34);
      local_8 = 0;
      local_18 = local_20;
      local_18 = (void *)FUN_0089d970(*(undefined4 *)(in_ECX + 4),param_1,local_20);
      local_18 = (void *)FUN_0089d990(local_18,param_2,local_84);
      FUN_0089d970(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x38;
      }
      if (iVar2 != 0) {
        FUN_004e65b0(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_34 + (int)local_20;
      *(void **)(in_ECX + 8) = (void *)((int)local_20 + (param_2 + iVar1) * 0x38);
      *(void **)(in_ECX + 4) = local_20;
    }
    else {
      local_3c = *(int *)(in_ECX + 8);
      local_38 = local_3c - param_1;
      if ((uint)(local_38 / 0x38) < param_2) {
        local_1c = param_2 * 0x38;
        FUN_0089d7f0(param_1,local_3c,local_1c + param_1);
        local_8 = 2;
        FUN_0089d990(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x38,
                     local_84);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_1c;
        FUN_0089d880(param_1,*(int *)(in_ECX + 8) - local_1c,local_84);
      }
      else {
        local_1c = param_2 * 0x38;
        iVar2 = local_3c + param_2 * -0x38;
        uVar3 = FUN_0089d7f0(iVar2,local_3c,local_3c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_004e6610(param_1,iVar2,local_3c,local_4c);
        FUN_0089d880(param_1,local_1c + param_1,local_84);
      }
    }
  }
  if (0xf < local_50) {
    _free(local_64);
    return;
  }
  local_50 = 0xf;
  local_54 = 0;
  local_64 = (void *)((uint)local_64 & 0xffffff00);
  if (local_6c < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_80);
  return;
}


// ==== Catch@0089dbc3 @ 0x0089dbc3 ====

void Catch_0089dbc3(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x1c);
  FUN_0089d950(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@0089dc88 @ 0x0089dc88 ====

void Catch_0089dc88(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x38;
  FUN_0089d950(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x20) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0089dd50 @ 0x0089dd50 ====

void FUN_0089dd50(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x38 != 0) {
      iVar1 = (param_2 - iVar1) / 0x38;
      goto LAB_0089dd99;
    }
  }
  iVar1 = 0;
LAB_0089dd99:
  FUN_0089d9c0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x38;
  return;
}


// ==== FUN_0089ddd0 @ 0x0089ddd0 ====

void FUN_0089ddd0(byte param_1)

{
  void *in_ECX;
  
  FUN_0089d3c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089ddf0 @ 0x0089ddf0 ====

void FUN_0089ddf0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x38) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x38))) {
    FUN_0089dd50(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0089d8c0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x38;
  return;
}


// ==== FUN_0089de80 @ 0x0089de80 ====

void FUN_0089de80(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  if (*(int *)(in_ECX + 0x38) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x38));
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  return;
}


// ==== FUN_0089deb0 @ 0x0089deb0 ====

bool FUN_0089deb0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x40) != 0;
}


// ==== FUN_0089dec0 @ 0x0089dec0 ====

void FUN_0089dec0(int *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 != (int *)0x0) {
    if (*(int *)(in_ECX + 0x38) != 0) {
      *(undefined4 *)(in_ECX + 0x3c) = 0;
      *(undefined4 *)(in_ECX + 0x40) = 0;
      (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x38));
      *(undefined4 *)(in_ECX + 0x38) = 0;
    }
    *(int **)(in_ECX + 0x38) = param_1;
    (**(code **)(*param_1 + 0x1c))();
    uVar1 = FUN_004b9df0(in_ECX);
    *(undefined4 *)(in_ECX + 0x3c) = uVar1;
    uVar1 = FUN_004b9df0(in_ECX + 0x1c);
    *(undefined4 *)(in_ECX + 0x40) = uVar1;
  }
  return;
}


// ==== FUN_0089df20 @ 0x0089df20 ====

void FUN_0089df20(void)

{
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099a9b3;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  if (*(int *)(in_ECX + 0x38) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x38));
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  if (0xf < *(uint *)(in_ECX + 0x34)) {
    _free(*(void **)(in_ECX + 0x20));
    return;
  }
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    ExceptionList = pvStack_c;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0089dfc0 @ 0x0089dfc0 ====

void FUN_0089dfc0(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099a9c5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401740(s_picking_00a15d3c,7);
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  FUN_00401740(s_ground_00a15d44,6);
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0089e040 @ 0x0089e040 ====

uint FUN_0089e040(int param_1,float *param_2,float *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  uint uVar9;
  ushort *puVar10;
  uint extraout_EAX;
  uint extraout_EAX_00;
  ushort *puVar11;
  ushort *puVar12;
  undefined1 local_2c [4];
  undefined1 local_28 [16];
  float *local_18;
  float *local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099a9d7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar9 = FUN_0040dfb0(param_2,param_1 + 0x1c,param_1 + 0x28,local_2c);
  if ((char)uVar9 == '\0') {
    ExceptionList = local_c;
    return uVar9;
  }
  puVar2 = *(ushort **)(param_1 + 0x4c);
  puVar11 = *(ushort **)(param_1 + 0x48);
  local_18 = (float *)0x0;
  local_14 = (float *)0x0;
  local_10 = 0;
  local_4 = 0;
  puVar10 = puVar2;
  if (puVar11 != puVar2) {
    do {
      iVar3 = *(int *)(param_1 + 0x38);
      uVar1 = *puVar11;
      puVar10 = puVar11 + 1;
      if ((iVar3 == 0) || ((uint)((*(int *)(param_1 + 0x3c) - iVar3) / 0x28) <= (uint)uVar1)) {
LAB_0089e189:
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      puVar12 = puVar11 + 2;
      if ((iVar3 == 0) || ((uint)((*(int *)(param_1 + 0x3c) - iVar3) / 0x28) <= (uint)*puVar10))
      goto LAB_0089e189;
      iVar4 = *(int *)(param_1 + 0x38);
      puVar11 = puVar11 + 3;
      if ((iVar4 == 0) || ((uint)((*(int *)(param_1 + 0x3c) - iVar4) / 0x28) <= (uint)*puVar12))
      goto LAB_0089e189;
      puVar10 = (ushort *)
                FUN_0040e5f0(param_2,iVar3 + (uint)uVar1 * 0x28,iVar3 + (uint)*puVar10 * 0x28,
                             iVar4 + (uint)*puVar12 * 0x28,local_28);
      if ((char)puVar10 != '\0') {
        puVar10 = (ushort *)FUN_005c2400(local_28);
      }
    } while (puVar11 != puVar2);
    if (local_18 != (float *)0x0) {
      if (((int)local_14 - (int)local_18) / 0xc == 0) {
        _free(local_18);
        return extraout_EAX;
      }
      *param_3 = *local_18;
      param_3[1] = local_18[1];
      param_3[2] = local_18[2];
      fVar6 = SQRT((*param_3 - *param_2) * (*param_3 - *param_2) +
                   (param_3[1] - param_2[1]) * (param_3[1] - param_2[1]) +
                   (param_3[2] - param_2[2]) * (param_3[2] - param_2[2]));
      pfVar8 = local_18;
      while (pfVar7 = pfVar8, pfVar8 = pfVar7 + 3, pfVar8 != local_14) {
        fVar5 = SQRT((*pfVar8 - *param_2) * (*pfVar8 - *param_2) +
                     (pfVar7[4] - param_2[1]) * (pfVar7[4] - param_2[1]) +
                     (pfVar7[5] - param_2[2]) * (pfVar7[5] - param_2[2]));
        if (fVar5 < fVar6) {
          *param_3 = *pfVar8;
          param_3[1] = pfVar7[4];
          param_3[2] = pfVar7[5];
          fVar6 = fVar5;
        }
      }
      _free(local_18);
      return extraout_EAX_00;
    }
  }
  ExceptionList = local_c;
  return (uint)puVar10 & 0xffffff00;
}


// ==== FUN_0089e2b0 @ 0x0089e2b0 ====

undefined4 FUN_0089e2b0(byte *param_1,undefined4 *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  char cVar9;
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar8 = param_2;
  pbVar7 = param_1;
  if ((*param_1 & 0xc) == 0) {
    return 0;
  }
  if (*(int *)(in_ECX + 0x3c) == 0) {
    iVar6 = *(int *)(in_ECX + 0x38);
    local_c = *(undefined4 *)(iVar6 + 0x70);
    local_8 = *(undefined4 *)(iVar6 + 0x74);
    local_4 = *(undefined4 *)(iVar6 + 0x78);
    local_18 = *(undefined4 *)(iVar6 + 0x7c);
    local_14 = *(undefined4 *)(iVar6 + 0x80);
    local_10 = *(undefined4 *)(iVar6 + 0x84);
    pfVar1 = (float *)(param_1 + 0xc);
    cVar9 = FUN_0040dfb0(pfVar1,&local_c,&local_18,&param_1);
    if (cVar9 != '\0') {
      fVar2 = *(float *)(pbVar7 + 0x1c);
      fVar3 = *(float *)(pbVar7 + 0x20);
      fVar4 = *(float *)(pbVar7 + 0x10);
      fVar5 = *(float *)(pbVar7 + 0x14);
      param_2[2] = *pfVar1 + *(float *)(pbVar7 + 0x18) * (float)param_1;
      param_2[3] = fVar4 + fVar2 * (float)param_1;
      *param_2 = 1;
      param_2[4] = fVar5 + fVar3 * (float)param_1;
      return 1;
    }
  }
  else {
    cVar9 = FUN_0089e040(*(int *)(in_ECX + 0x3c),param_1 + 0xc,param_2 + 2);
    if (cVar9 != '\0') {
      *puVar8 = 1;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0089e410 @ 0x0089e410 ====

undefined4 FUN_0089e410(byte *param_1,undefined4 *param_2)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_0089e2b0(param_1,param_2);
  if (cVar1 == '\x01') {
    return 1;
  }
  if ((((*param_1 & 2) == 0) || (*(int *)(in_ECX + 0x40) == 0)) ||
     (cVar1 = FUN_0089e040(*(int *)(in_ECX + 0x40),param_1 + 0xc,param_2 + 2), cVar1 == '\0')) {
    return 0;
  }
  *param_2 = 2;
  return 1;
}


// ==== FUN_0089e480 @ 0x0089e480 ====

void FUN_0089e480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15d54;
  if ((void *)in_ECX[0xc] != (void *)0x0) {
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  if ((void *)in_ECX[8] == (void *)0x0) {
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    *in_ECX = &PTR_FUN_009c248c;
    return;
  }
  _free((void *)in_ECX[8]);
  return;
}


// ==== FUN_0089e4d0 @ 0x0089e4d0 ====

void FUN_0089e4d0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x20) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x20));
    return;
  }
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  if (*(void **)(in_ECX + 0x30) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x30) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x30));
  return;
}


// ==== FUN_0089e570 @ 0x0089e570 ====

void FUN_0089e570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15d54;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  return;
}


// ==== FUN_0089e590 @ 0x0089e590 ====

void FUN_0089e590(float *param_1,float *param_2)

{
  float *pfVar1;
  int in_ECX;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_18 = *param_1;
  local_14 = param_1[1];
  local_10 = param_1[2];
  pfVar2 = *(float **)(in_ECX + 0x20);
  pfVar1 = *(float **)(in_ECX + 0x24);
  local_c = *param_2;
  local_8 = param_2[1];
  local_4 = param_2[2];
  while( true ) {
    if (pfVar2 == pfVar1) {
      fVar4 = local_4;
      if ((*(int *)(in_ECX + 0x20) == 0) ||
         ((*(int *)(in_ECX + 0x24) - *(int *)(in_ECX + 0x20)) / 0x18 == 0)) {
        *(float *)(in_ECX + 4) = local_18;
        *(float *)(in_ECX + 8) = local_14;
        *(float *)(in_ECX + 0xc) = local_10;
        *(float *)(in_ECX + 0x10) = local_c;
        *(float *)(in_ECX + 0x14) = local_8;
      }
      else {
        fVar3 = local_18;
        if (*(float *)(in_ECX + 4) <= local_18 && local_18 != *(float *)(in_ECX + 4)) {
          fVar3 = *(float *)(in_ECX + 4);
        }
        *(float *)(in_ECX + 4) = fVar3;
        fVar3 = local_14;
        if (*(float *)(in_ECX + 8) <= local_14 && local_14 != *(float *)(in_ECX + 8)) {
          fVar3 = *(float *)(in_ECX + 8);
        }
        *(float *)(in_ECX + 8) = fVar3;
        fVar3 = local_10;
        if (*(float *)(in_ECX + 0xc) <= local_10 && local_10 != *(float *)(in_ECX + 0xc)) {
          fVar3 = *(float *)(in_ECX + 0xc);
        }
        *(float *)(in_ECX + 0xc) = fVar3;
        fVar3 = local_c;
        if (*(float *)(in_ECX + 0x10) <= local_c && local_c != *(float *)(in_ECX + 0x10)) {
          fVar3 = *(float *)(in_ECX + 0x10);
        }
        *(float *)(in_ECX + 0x10) = fVar3;
        fVar3 = local_8;
        if (*(float *)(in_ECX + 0x14) <= local_8 && local_8 != *(float *)(in_ECX + 0x14)) {
          fVar3 = *(float *)(in_ECX + 0x14);
        }
        *(float *)(in_ECX + 0x14) = fVar3;
        if (*(float *)(in_ECX + 0x18) <= local_4 && local_4 != *(float *)(in_ECX + 0x18)) {
          fVar4 = *(float *)(in_ECX + 0x18);
        }
      }
      *(float *)(in_ECX + 0x18) = fVar4;
      FUN_0089ee60(&local_18);
      return;
    }
    if ((((*pfVar2 <= local_18) && (pfVar2[1] <= local_14)) && (pfVar2[2] <= local_10)) &&
       (((local_c <= pfVar2[3] && (local_8 <= pfVar2[4])) && (local_4 <= pfVar2[5])))) break;
    if (((*pfVar2 < local_18) || (pfVar2[1] < local_14)) ||
       ((pfVar2[2] < local_10 ||
        (((local_c < pfVar2[3] || (local_8 < pfVar2[4])) || (local_4 < pfVar2[5])))))) {
      pfVar2 = pfVar2 + 6;
    }
    else {
      FUN_0085d550(pfVar2 + 6,*(undefined4 *)(in_ECX + 0x24),pfVar2,param_1);
      *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + -0x18;
    }
  }
  return;
}


// ==== FUN_0089e7a0 @ 0x0089e7a0 ====

void FUN_0089e7a0(int *param_1)

{
  int *piVar1;
  char cVar2;
  
  piVar1 = param_1;
  if (param_1 != (int *)0x0) {
    cVar2 = (**(code **)(*param_1 + 0x2c))();
    if (cVar2 != '\0') {
      FUN_0089e590(piVar1 + 0x1c,piVar1 + 0x1f);
      return;
    }
    FUN_005c2480(&param_1);
  }
  return;
}


// ==== FUN_0089e7e0 @ 0x0089e7e0 ====

uint FUN_0089e7e0(void)

{
  int *piVar1;
  char cVar2;
  int *_Dst;
  int in_ECX;
  int *_Src;
  int *local_4;
  
  _Dst = *(int **)(in_ECX + 0x30);
  if ((_Dst != (int *)0x0) && (*(int *)(in_ECX + 0x34) - (int)_Dst >> 2 != 0)) {
    local_4 = *(int **)(in_ECX + 0x34);
    if (_Dst != local_4) {
      _Src = _Dst + 1;
      do {
        piVar1 = (int *)*_Dst;
        cVar2 = (**(code **)(*piVar1 + 0x2c))();
        if (cVar2 == '\0') {
          _Dst = _Dst + 1;
          _Src = _Src + 1;
        }
        else {
          _memmove(_Dst,_Src,(*(int *)(in_ECX + 0x34) - (int)_Src >> 2) * 4);
          *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + -4;
          local_4 = *(int **)(in_ECX + 0x34);
          FUN_0089e590(piVar1 + 0x1c,piVar1 + 0x1f);
        }
      } while (_Dst != local_4);
    }
    _Dst = *(int **)(in_ECX + 0x30);
    if ((_Dst != (int *)0x0) && (*(int *)(in_ECX + 0x34) - (int)_Dst >> 2 != 0)) {
      return (uint)_Dst & 0xffffff00;
    }
  }
  return CONCAT31((int3)((uint)_Dst >> 8),1);
}


// ==== FUN_0089e890 @ 0x0089e890 ====

uint FUN_0089e890(float param_1,undefined4 *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float fVar7;
  uint uVar8;
  int in_ECX;
  int iVar9;
  undefined1 local_10 [16];
  
  uVar8 = FUN_0089e7e0();
  fVar7 = param_1;
  if ((char)uVar8 == '\0') {
    return uVar8;
  }
  pfVar1 = (float *)((int)param_1 + 0xc);
  uVar8 = FUN_0040dfb0(pfVar1,in_ECX + 4,in_ECX + 0x10,local_10);
  if ((char)uVar8 == '\0') {
    return uVar8;
  }
  iVar9 = *(int *)(in_ECX + 0x20);
  iVar6 = *(int *)(in_ECX + 0x24);
  while( true ) {
    if (iVar9 == iVar6) {
      return uVar8 & 0xffffff00;
    }
    uVar8 = FUN_0040dfb0(pfVar1,iVar9,iVar9 + 0xc,&param_1);
    if ((char)uVar8 != '\0') break;
    iVar9 = iVar9 + 0x18;
  }
  *param_2 = 1;
  fVar2 = *(float *)((int)fVar7 + 0x1c);
  fVar3 = *(float *)((int)fVar7 + 0x20);
  fVar4 = *(float *)((int)fVar7 + 0x10);
  fVar5 = *(float *)((int)fVar7 + 0x14);
  param_2[2] = *pfVar1 + *(float *)((int)fVar7 + 0x18) * param_1;
  param_2[3] = fVar4 + fVar2 * param_1;
  param_2[4] = fVar5 + fVar3 * param_1;
  return CONCAT31((int3)((uint)(param_2 + 2) >> 8),1);
}


// ==== FUN_0089e990 @ 0x0089e990 ====

int FUN_0089e990(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a9f0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x18) {
    FUN_0057e010(param_3,param_1);
    param_3 = param_3 + 0x18;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0089e9f6 @ 0x0089e9f6 ====

void Catch_0089e9f6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0089ea00 @ 0x0089ea00 ====

void FUN_0089ea00(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099aa00;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0057e010(param_1,param_3);
    param_1 = param_1 + 0x18;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0089ea66 @ 0x0089ea66 ====

void Catch_0089ea66(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0089ea70 @ 0x0089ea70 ====

void FUN_0089ea70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0089e990(param_1,param_2,param_3);
  return;
}


// ==== FUN_0089ea90 @ 0x0089ea90 ====

int FUN_0089ea90(int param_1,int param_2,undefined4 param_3)

{
  FUN_0089ea00(param_1,param_2,param_3);
  return param_1 + param_2 * 0x18;
}


// ==== FUN_0089eac0 @ 0x0089eac0 ====

void FUN_0089eac0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15d54;
  if ((void *)in_ECX[0xc] != (void *)0x0) {
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  if ((void *)in_ECX[8] != (void *)0x0) {
    _free((void *)in_ECX[8]);
    return;
  }
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  *in_ECX = &PTR_FUN_009c248c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089eb20 @ 0x0089eb20 ====

void FUN_0089eb20(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint extraout_ECX;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
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
  puStack_c = &LAB_0099aa10;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
  local_50 = *param_3;
  local_4c = param_3[1];
  local_48 = param_3[2];
  local_44 = param_3[3];
  local_40 = param_3[4];
  local_3c = param_3[5];
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x18;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x5c);
    if (0xaaaaaaaU - iVar2 < param_2) {
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
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
    }
    if (local_20 < iVar2 + param_2) {
      if (0xaaaaaaa - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_0057dfd0();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0x18;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_0089ea70(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_0089ea90(local_1c,param_2,&local_50);
      FUN_0089ea70(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x18;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0x18);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0x18) < param_2) {
      local_24 = param_2 * 0x18;
      FUN_0089e990(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_0089ea90(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x18,&local_50)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_004dcf10(param_1,*(int *)(in_ECX + 8) - local_24,&local_50);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x18;
    uVar4 = FUN_0089e990(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_0085d5a0(param_1,local_2c,local_28,local_38);
    FUN_004dcf10(param_1,param_2 * 0x18 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0089ece1 @ 0x0089ece1 ====

void Catch_0089ece1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0089edf0 @ 0x0089edf0 ====

void FUN_0089edf0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x18 != 0) {
      iVar1 = (param_2 - iVar1) / 0x18;
      goto LAB_0089ee35;
    }
  }
  iVar1 = 0;
LAB_0089ee35:
  FUN_0089eb20(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x18;
  return;
}


// ==== FUN_0089ee60 @ 0x0089ee60 ====

void FUN_0089ee60(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x18) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x18))) {
    FUN_0089edf0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0089ea00(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x18;
  return;
}


// ==== FUN_0089eef0 @ 0x0089eef0 ====

void FUN_0089eef0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15d6c;
  return;
}


// ==== FUN_0089ef00 @ 0x0089ef00 ====

void FUN_0089ef00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15d6c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089ef40 @ 0x0089ef40 ====

void FUN_0089ef40(undefined4 *param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\x01') {
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    *(undefined1 *)(in_ECX + 0x40) = 0;
    *(undefined1 *)(in_ECX + 0x41) = 0;
    *(undefined1 *)(in_ECX + 0x42) = 0;
    *(undefined1 *)(in_ECX + 4) = 1;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x34) = *param_1;
    *(undefined4 *)(in_ECX + 0x38) = param_1[1];
    *(undefined4 *)(in_ECX + 0x3c) = param_1[2];
    *(undefined4 *)(in_ECX + 0x40) = param_1[3];
  }
  return;
}


// ==== FUN_0089ef80 @ 0x0089ef80 ====

void FUN_0089ef80(void)

{
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\0') {
    return;
  }
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  *(undefined1 *)((int)in_ECX + 0x41) = 0;
  *(undefined1 *)((int)in_ECX + 0x42) = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
                    /* WARNING: Could not recover jumptable at 0x0089ef9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x10))();
  return;
}


// ==== FUN_0089efb0 @ 0x0089efb0 ====

undefined1 FUN_0089efb0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_0089efc0 @ 0x0089efc0 ====

int FUN_0089efc0(void)

{
  int in_ECX;
  
  return in_ECX + 0x34;
}


// ==== FUN_0089efd0 @ 0x0089efd0 ====

void FUN_0089efd0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x34) = param_1;
  return;
}


// ==== FUN_0089efe0 @ 0x0089efe0 ====

void FUN_0089efe0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x38) = param_1;
  return;
}


// ==== FUN_0089eff0 @ 0x0089eff0 ====

void FUN_0089eff0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_0089f000 @ 0x0089f000 ====

void FUN_0089f000(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x41) = param_1;
  return;
}


// ==== FUN_0089f010 @ 0x0089f010 ====

void FUN_0089f010(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x40) = 1;
  return;
}


// ==== FUN_0089f020 @ 0x0089f020 ====

undefined4 FUN_0089f020(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x44);
}


// ==== FUN_0089f030 @ 0x0089f030 ====

undefined4 FUN_0089f030(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x48);
}


// ==== FUN_0089f040 @ 0x0089f040 ====

undefined1 FUN_0089f040(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x42);
}


// ==== FUN_0089f050 @ 0x0089f050 ====

void FUN_0089f050(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x42) = param_1;
  return;
}


// ==== FUN_0089f070 @ 0x0089f070 ====

void FUN_0089f070(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099aa3e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_00a15dc4;
  in_ECX[2] = &PTR_FUN_00a15dbc;
  in_ECX[0xc] = 0;
  in_ECX[0xc] = in_ECX[0xc] + 3;
  local_4 = 1;
  in_ECX[0x11] = 0;
  pvVar1 = operator_new(0x600);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0089f790();
  }
  in_ECX[0x12] = uVar2;
  local_4 = CONCAT31(local_4._1_3_,1);
  uVar2 = (**(code **)(*DAT_00b5abf4 + 4))();
  in_ECX[0x11] = uVar2;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  *(undefined1 *)((int)in_ECX + 0x41) = 0;
  *(undefined1 *)((int)in_ECX + 0x42) = 0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0089f120 @ 0x0089f120 ====

void FUN_0089f120(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099aa5b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_00a15dc4;
  local_4 = 1;
  (**(code **)(*DAT_00b5abf4 + 8))(in_ECX[0x11]);
  if ((undefined4 *)in_ECX[0x12] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x12])(1);
  }
  in_ECX[0x12] = 0;
  in_ECX[0xc] = in_ECX[0xc] + -3;
  in_ECX[2] = &PTR_FUN_00a15dbc;
  *in_ECX = &PTR_FUN_00a15d6c;
  ExceptionList = in_ECX;
  return;
}


// ==== FUN_0089f1d0 @ 0x0089f1d0 ====

void FUN_0089f1d0(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  uint uVar4;
  uint uStack_c;
  undefined1 uStack_8;
  undefined4 uStack_4;
  
  iVar2 = (**(code **)(*DAT_00b5ac9c + 0x10))();
  while (iVar2 != 0) {
    (**(code **)(*DAT_00b5aca0 + 8))(iVar2);
    iVar2 = (**(code **)(*DAT_00b5ac9c + 0x14))();
  }
  (**(code **)(*DAT_00b5ac9c + 0x1c))();
  iVar2 = (**(code **)(*DAT_00b5abec + 0x10))();
  while (iVar2 != 0) {
    (**(code **)(*DAT_00b5abf0 + 8))(iVar2);
    iVar2 = (**(code **)(*DAT_00b5abec + 0x14))();
  }
  (**(code **)(*DAT_00b5abec + 0x1c))();
  if (in_ECX[0x11] != 0) {
    iVar2 = (**(code **)(*(int *)in_ECX[0x11] + 0xc))();
    while (iVar2 != 0) {
      (**(code **)(*DAT_00b5abf8 + 8))(iVar2);
      iVar2 = (**(code **)(*(int *)in_ECX[0x11] + 0x10))();
    }
    (**(code **)(*(int *)in_ECX[0x11] + 0x18))();
  }
  uVar1 = in_ECX[0xc];
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      uStack_8 = 0;
      uStack_4 = 0;
      uStack_c = uVar4;
      (**(code **)(*in_ECX + 0x30))(&uStack_c);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5aaf8 + 0xc))();
  while (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(0);
    piVar3 = (int *)(**(code **)(*DAT_00b5aaf8 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5ab00 + 4))();
  (**(code **)(*piVar3 + 0x14))();
  return;
}


// ==== FUN_0089f2f0 @ 0x0089f2f0 ====

void FUN_0089f2f0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *in_ECX;
  uint uVar5;
  undefined1 auStack_a [10];
  
  iVar2 = (**(code **)(*DAT_00b5abec + 0x10))();
  while (iVar2 != 0) {
    (**(code **)(*DAT_00b5abf0 + 8))(iVar2);
    iVar2 = (**(code **)(*DAT_00b5abec + 0x14))();
  }
  (**(code **)(*DAT_00b5abec + 0x1c))();
  uVar1 = in_ECX[0xc];
  uVar5 = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  if (uVar1 != 0) {
    do {
      (**(code **)(*in_ECX + 0x34))(uVar5);
      (**(code **)(*in_ECX + 0x30))(auStack_a + -6);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  uVar3 = (**(code **)(*DAT_00b5ac9c + 0x10))();
  piVar4 = (int *)(**(code **)(*DAT_00b5aaf8 + 0xc))();
  while (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(uVar3);
    piVar4 = (int *)(**(code **)(*DAT_00b5aaf8 + 0x10))();
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5ab00 + 4))();
  (**(code **)(*piVar4 + 0x14))();
  return;
}


// ==== FUN_0089f3d0 @ 0x0089f3d0 ====

void FUN_0089f3d0(int *param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + (*param_1 + 1) * 0xc);
  *piVar1 = *param_1;
  piVar1[1] = param_1[1];
  piVar1[2] = param_1[2];
  return;
}


// ==== FUN_0089f400 @ 0x0089f400 ====

int FUN_0089f400(int param_1)

{
  int in_ECX;
  
  return in_ECX + (param_1 * 3 + 3) * 4;
}


// ==== FUN_0089f410 @ 0x0089f410 ====

undefined4 FUN_0089f410(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}


// ==== FUN_0089f420 @ 0x0089f420 ====

void FUN_0089f420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15dbc;
  return;
}


// ==== FUN_0089f430 @ 0x0089f430 ====

void FUN_0089f430(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15dbc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089f450 @ 0x0089f450 ====

void FUN_0089f450(byte param_1)

{
  void *in_ECX;
  
  FUN_0089f120();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089f470 @ 0x0089f470 ====

void FUN_0089f470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15e14;
  return;
}


// ==== FUN_0089f480 @ 0x0089f480 ====

void FUN_0089f480(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15e14;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089f4a0 @ 0x0089f4a0 ====

void FUN_0089f4a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0089f4a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x238) + 8))();
  return;
}


// ==== FUN_0089f4b0 @ 0x0089f4b0 ====

int FUN_0089f4b0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0089f4c0 @ 0x0089f4c0 ====

int FUN_0089f4c0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0089f4d0 @ 0x0089f4d0 ====

undefined4 FUN_0089f4d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x238);
}


// ==== FUN_0089f4e0 @ 0x0089f4e0 ====

void FUN_0089f4e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099aa78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a15e30;
  local_4 = 0;
  if ((undefined4 *)in_ECX[0x8e] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x8e])(1);
  }
  in_ECX[0x8e] = 0;
  *in_ECX = &PTR_FUN_00a15e14;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0089f540 @ 0x0089f540 ====

void FUN_0089f540(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099aa95;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a15e30;
  *(undefined1 *)(in_ECX + 1) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x81) = 0;
  FUN_00797a50(in_ECX + 1,0,0x234);
  pvVar1 = operator_new(0xc);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0089fa30();
  }
  in_ECX[0x8e] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0089f5d0 @ 0x0089f5d0 ====

void FUN_0089f5d0(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x238) + 4))();
  FUN_0089f610(param_1);
  return;
}


// ==== FUN_0089f5f0 @ 0x0089f5f0 ====

void FUN_0089f5f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0089f4e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089f610 @ 0x0089f610 ====

void FUN_0089f610(int param_1)

{
  char cVar1;
  char *in_ECX;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  pcVar2 = in_ECX;
  do {
    cVar1 = pcVar2[param_1 - (int)in_ECX];
    *pcVar2 = cVar1;
    if (cVar1 == '\0') goto LAB_0089f63a;
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x200);
  *in_ECX = '\0';
LAB_0089f63a:
  uVar3 = 0;
  do {
    cVar1 = *(char *)(param_1 + 0x200 + uVar3);
    in_ECX[uVar3 + 0x200] = cVar1;
    if (cVar1 == '\0') goto LAB_0089f661;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x21);
  in_ECX[0x200] = '\0';
LAB_0089f661:
  *(undefined2 *)(in_ECX + 0x222) = *(undefined2 *)(param_1 + 0x222);
  *(undefined4 *)(in_ECX + 0x224) = *(undefined4 *)(param_1 + 0x224);
  *(undefined2 *)(in_ECX + 0x228) = *(undefined2 *)(param_1 + 0x228);
  *(undefined2 *)(in_ECX + 0x22a) = *(undefined2 *)(param_1 + 0x22a);
  *(undefined2 *)(in_ECX + 0x22c) = *(undefined2 *)(param_1 + 0x22c);
  *(undefined4 *)(in_ECX + 0x230) = *(undefined4 *)(param_1 + 0x230);
  return;
}


// ==== FUN_0089f6c0 @ 0x0089f6c0 ====

void FUN_0089f6c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15e4c;
  return;
}


// ==== FUN_0089f6d0 @ 0x0089f6d0 ====

void FUN_0089f6d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15e4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089f6f0 @ 0x0089f6f0 ====

int FUN_0089f6f0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0089f700 @ 0x0089f700 ====

int FUN_0089f700(void)

{
  int in_ECX;
  
  return in_ECX + 0x3a8;
}


// ==== FUN_0089f710 @ 0x0089f710 ====

void FUN_0089f710(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x3a8);
  for (iVar1 = 0x96; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_0089f730 @ 0x0089f730 ====

void FUN_0089f730(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099aaa8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a15e64;
  local_4 = 0;
  _eh_vector_destructor_iterator_(in_ECX + 9,0xb4,5,FUN_006ef6d0);
  *in_ECX = &PTR_FUN_00a15e4c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0089f790 @ 0x0089f790 ====

void FUN_0089f790(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099aac5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a15e64;
  _eh_vector_constructor_iterator_
            (in_ECX + 9,0xb4,5,(_func_void_void_ptr *)&LAB_007137d0,FUN_006ef6d0);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00797a50(in_ECX + 1,0,0x3a4);
  FUN_00797a50(in_ECX + 0xea,0,600);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0089f820 @ 0x0089f820 ====

void FUN_0089f820(void)

{
  FUN_0089f950();
  return;
}


// ==== FUN_0089f830 @ 0x0089f830 ====

char * FUN_0089f830(int param_1)

{
  char cVar1;
  char *in_ECX;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  
  iVar2 = param_1 - (int)in_ECX;
  param_1 = 4;
  pcVar4 = in_ECX;
  do {
    uVar5 = 0;
    pcVar3 = pcVar4;
    do {
      cVar1 = pcVar3[iVar2];
      *pcVar3 = cVar1;
      if (cVar1 == '\0') goto LAB_0089f877;
      uVar5 = uVar5 + 1;
      pcVar3 = pcVar3 + 1;
    } while (uVar5 < 0x21);
    *pcVar4 = '\0';
LAB_0089f877:
    pcVar4[0x21] = pcVar4[iVar2 + 0x21];
    pcVar4 = pcVar4 + 0x22;
    param_1 = param_1 + -1;
    if (param_1 == 0) {
      return in_ECX;
    }
  } while( true );
}


// ==== FUN_0089f8a0 @ 0x0089f8a0 ====

void FUN_0089f8a0(undefined4 *param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 4);
    *(char *)(uVar2 + 4 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0089f8c8;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x21);
  *(undefined1 *)(in_ECX + 1) = 0;
LAB_0089f8c8:
  *(undefined2 *)((int)in_ECX + 0x26) = *(undefined2 *)((int)param_1 + 0x26);
  *(undefined2 *)(in_ECX + 10) = *(undefined2 *)(param_1 + 10);
  *(undefined1 *)((int)in_ECX + 0x2a) = *(undefined1 *)((int)param_1 + 0x2a);
  FUN_0089f830((int)param_1 + 0x2b);
  return;
}


// ==== FUN_0089f8f0 @ 0x0089f8f0 ====

void FUN_0089f8f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0089f730();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089f910 @ 0x0089f910 ====

void FUN_0089f910(int param_1)

{
  int in_ECX;
  int iVar1;
  
  param_1 = param_1 - in_ECX;
  iVar1 = 5;
  do {
    FUN_0089f8a0(param_1 + in_ECX);
    in_ECX = in_ECX + 0xb4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ==== FUN_0089f950 @ 0x0089f950 ====

void FUN_0089f950(undefined1 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = *param_1;
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  in_ECX[0x1c] = param_1[0x1c];
  FUN_0089f910(param_1 + 0x20);
  return;
}


// ==== FUN_0089f9a0 @ 0x0089f9a0 ====

void FUN_0089f9a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15e7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089f9c0 @ 0x0089f9c0 ====

void FUN_0089f9c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15e7c;
  return;
}


// ==== FUN_0089f9d0 @ 0x0089f9d0 ====

void FUN_0089f9d0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_0089f9e0 @ 0x0089f9e0 ====

void FUN_0089f9e0(void)

{
  return;
}


// ==== FUN_0089f9f0 @ 0x0089f9f0 ====

void FUN_0089f9f0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0089fa00 @ 0x0089fa00 ====

undefined4 FUN_0089fa00(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0089fa10 @ 0x0089fa10 ====

void FUN_0089fa10(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0089fa20 @ 0x0089fa20 ====

undefined1 FUN_0089fa20(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_0089fa30 @ 0x0089fa30 ====

void FUN_0089fa30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15e9c;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  return;
}


// ==== FUN_0089fa50 @ 0x0089fa50 ====

void FUN_0089fa50(byte param_1)

{
  void *in_ECX;
  
  FUN_0089f9c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0089fa70 @ 0x0089fa70 ====

void FUN_0089fa70(void)

{
  return;
}


// ==== FUN_0089fa80 @ 0x0089fa80 ====

undefined1 FUN_0089fa80(void)

{
  return 0;
}


// ==== FUN_0089fa90 @ 0x0089fa90 ====

void FUN_0089fa90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15f50;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0089fae0 @ 0x0089fae0 ====

void FUN_0089fae0(void)

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
  FUN_00401740(s_UI_Game2_GMTool_ui_gmmessagewnd__00a15ef4,0x23);
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


// ==== FUN_0089fb60 @ 0x0089fb60 ====

void FUN_0089fb60(int param_1)

{
  int *piVar1;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + *(int *)(param_1 + 4);
  if (40000 < *(uint *)(in_ECX + 8)) {
    *(undefined1 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401740(s_pan_back_00a15f18,8);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x24))(0);
    }
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
  }
  return;
}


// ==== FUN_0089fbe0 @ 0x0089fbe0 ====

void FUN_0089fbe0(void)

{
  int *piVar1;
  int in_ECX;
  void *unaff_EBX;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0xc) = 1;
  *(undefined4 *)(in_ECX + 8) = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_back_00a15f24,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(1);
  }
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_textbox_00a15f30,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(1);
    (**(code **)(*piVar1 + 0x30))();
    FUN_005569f0(local_8,0);
  }
  return;
}


// ==== FUN_0089fcc0 @ 0x0089fcc0 ====

void FUN_0089fcc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15f50;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_0089fae0();
  return;
}


// ==== FUN_0089fce0 @ 0x0089fce0 ====

uint FUN_0089fce0(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if ((uVar1 == 0x40001) && (*(char *)(in_ECX + 0xc) == '\x01')) {
    uVar1 = FUN_0089fb60(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0089fd10 @ 0x0089fd10 ====

undefined4 FUN_0089fd10(void)

{
  return 0x21;
}


// ==== FUN_0089fd20 @ 0x0089fd20 ====

void FUN_0089fd20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a15f50;
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


// ==== FUN_0089fd60 @ 0x0089fd60 ====

int * FUN_0089fd60(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_00a15fa8;
  while( true ) {
    if (PTR_DAT_00b536a4 <= piVar1) {
      return &DAT_00a15f80;
    }
    if (param_1 == *piVar1) break;
    piVar1 = piVar1 + 9;
  }
  return piVar1;
}


// ==== FUN_0089fd8b @ 0x0089fd8b ====

uint FUN_0089fd8b(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  uint *puVar5;
  uint local_8;
  
  uVar3 = 0;
  if (*(int *)(&DAT_00a167b0 + (*(int *)(in_ECX + 4) * 5 + *(int *)(in_EDX + 4)) * 4) != 0) {
    local_8 = 0;
    puVar5 = (uint *)(in_ECX + 0xc);
    iVar4 = 5;
    do {
      uVar1 = *puVar5;
      if (uVar1 != 0) {
        local_8 = local_8 + 1;
      }
      uVar2 = *(uint *)((in_EDX - in_ECX) + (int)puVar5);
      if (uVar1 < uVar2) {
        if (uVar1 == 0) {
          uVar3 = uVar3 + 0x100;
        }
        else {
          uVar3 = uVar3 + (uVar2 - uVar1);
        }
      }
      else if (uVar2 < uVar1) {
        if (uVar2 == 0) {
          uVar3 = uVar3 + 0x1000000;
        }
        else {
          uVar3 = uVar3 + (uVar1 - uVar2) * 0x10000;
        }
      }
      puVar5 = puVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (local_8 != uVar3 >> 0x18) {
      return uVar3;
    }
  }
  return 0xffffffff;
}


// ==== FUN_0089fe02 @ 0x0089fe02 ====

int FUN_0089fe02(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  uVar3 = 0xffffffff;
  piVar4 = &DAT_00a15f80;
  do {
    if (*param_1 == 0) {
      return *piVar4;
    }
    piVar1 = (int *)FUN_0089fd60(*param_1);
    if ((*piVar1 != 0) && ((piVar1[1] != 1 || (param_2 != 0)))) {
      if (*param_3 == *piVar1) {
        return *param_3;
      }
      uVar2 = FUN_0089fd8b();
      if (((uVar2 != 0xffffffff) && (uVar2 <= uVar3)) &&
         ((uVar2 != uVar3 || ((uint)piVar1[2] < (uint)piVar4[2])))) {
        uVar3 = uVar2;
        piVar4 = piVar1;
      }
    }
    param_1 = param_1 + 1;
  } while( true );
}


// ==== FUN_0089fe73 @ 0x0089fe73 ====

int FUN_0089fe73(int *param_1,uint param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 local_158;
  undefined4 local_154;
  undefined1 local_28 [12];
  undefined4 local_1c;
  undefined1 local_18 [12];
  byte local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  FUN_007a41ff(1);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x18))(param_1,&local_8);
    (**(code **)(*param_1 + 0x1c))(param_1,&local_158);
    (**(code **)(*param_1 + 0x20))(param_1,0,local_28);
    if (((param_2 & 0x100000) != 0) &&
       ((**(code **)(*param_1 + 0x24))(param_1,local_18), (local_c & 0x20) != 0)) {
      param_2 = param_2 | 0x10;
    }
  }
  uVar3 = 0xffffffff;
  piVar5 = &DAT_00a15f80;
  piVar4 = &DAT_00a15fa8;
  if (&DAT_00a15fa8 < PTR_DAT_00b536a4) {
    do {
      if ((*piVar4 != 0) &&
         ((local_8 == (int *)0x0 ||
          (iVar1 = (**(code **)(*local_8 + 0x28))
                             (local_8,local_154,local_158,local_1c,param_2,param_3,*piVar4),
          -1 < iVar1)))) {
        if (*param_4 == *piVar4) {
          piVar5 = piVar4;
          break;
        }
        if ((((piVar4[8] != 0) && (uVar2 = FUN_0089fd8b(), uVar2 != 0xffffffff)) && (uVar2 <= uVar3)
            ) && ((uVar2 != uVar3 || ((uint)piVar4[2] < (uint)piVar5[2])))) {
          uVar3 = uVar2;
          piVar5 = piVar4;
        }
      }
      piVar4 = piVar4 + 9;
    } while (piVar4 < PTR_DAT_00b536a4);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
    local_8 = (int *)0x0;
  }
  FUN_007a41ff(0);
  return *piVar5;
}


// ==== FUN_0089ff71 @ 0x0089ff71 ====

int FUN_0089ff71(int param_1)

{
  int iStack_8;
  
  if (param_1 == 0x36314c41) {
    iStack_8 = 0x33;
  }
  else {
    if (param_1 != 0x36315220) {
      return param_1;
    }
    iStack_8 = 0x24;
  }
  return iStack_8;
}


// ==== FUN_0089ff92 @ 0x0089ff92 ====

int FUN_0089ff92(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_008a1c00();
  iVar1 = FUN_008a61eb(param_1,param_2,param_3,0);
  iVar2 = 0;
  if (iVar1 < 0) {
    iVar2 = iVar1;
  }
  FUN_008a1c19();
  return iVar2;
}


// ==== FUN_0089ffcc @ 0x0089ffcc ====

int FUN_0089ffcc(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 *param_8,int param_9,
                undefined4 param_10)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 local_cc [72];
  undefined4 local_84;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [8];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  FUN_008a6876();
  FUN_008aa201();
  if (param_1 == 0) {
    iVar2 = -0x7789f794;
  }
  else if ((param_4 == 0) || (param_8 == (undefined4 *)0x0)) {
    iVar2 = -0x7789f794;
  }
  else {
    if (param_9 == -1) {
      param_9 = 0x80004;
    }
    iVar1 = FUN_008aa3d5(local_cc,param_1,param_2,param_3,0,0);
    if (-1 < iVar1) {
      local_60 = param_5;
      local_5c = param_6;
      local_64 = param_4;
      local_58 = 0;
      local_54[0] = *param_8;
      local_54[1] = param_8[1];
      local_54[2] = param_8[2];
      local_54[3] = param_8[3];
      local_44 = 0;
      local_40 = 1;
      puVar3 = local_54;
      puVar4 = local_3c;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      local_1c = local_84;
      local_18 = param_10;
      local_14 = param_7;
      iVar1 = FUN_008aa0c4(local_cc,&local_64,param_9);
      iVar2 = 0;
      if (-1 < iVar1) goto LAB_008a009d;
    }
    iVar2 = iVar1;
  }
LAB_008a009d:
  thunk_FUN_008aa2f3();
  FUN_008a6880();
  return iVar2;
}


