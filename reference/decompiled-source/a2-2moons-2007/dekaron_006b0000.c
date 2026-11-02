// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x6b0000-0x6bffff

// ==== FUN_006b0090 @ 0x006b0090 ====

undefined1 FUN_006b0090(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x2c);
}


// ==== FUN_006b00a0 @ 0x006b00a0 ====

void FUN_006b00a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006ae1c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006b00c0 @ 0x006b00c0 ====

void FUN_006b00c0(void)

{
  return;
}


// ==== FUN_006b0100 @ 0x006b0100 ====

void FUN_006b0100(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e0d10;
  if ((undefined4 *)in_ECX[0x22] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x22])(1);
    in_ECX[0x22] = 0;
  }
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006b0140 @ 0x006b0140 ====

undefined1 FUN_006b0140(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x88) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x88))(1);
    *(undefined4 *)(in_ECX + 0x88) = 0;
    return 1;
  }
  cVar1 = (**(code **)(*DAT_00b5ae98 + 4))();
  if (cVar1 == '\x01') {
    *(undefined1 *)(in_ECX + 0x9a) = 0;
    return 1;
  }
  return 0;
}


// ==== FUN_006b0280 @ 0x006b0280 ====

uint FUN_006b0280(int *param_1)

{
  uint in_EAX;
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x2c))();
    in_EAX = *(uint *)(iVar1 + 8);
    if ((((int3)(in_EAX >> 8) == 4) && (in_EAX != 0x40f)) && (in_EAX != 0x410)) {
      return CONCAT31(4,in_EAX != 0x40e);
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_006b02c0 @ 0x006b02c0 ====

void FUN_006b02c0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 8 + param_1 * 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_0055a260(param_2);
  }
  return;
}


// ==== FUN_006b0360 @ 0x006b0360 ====

void FUN_006b0360(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_a [10];
  
  piVar1 = *(int **)(in_ECX + 8 + param_1 * 4);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    (**(code **)(*DAT_00b5a7c0 + 8))(param_2);
    FUN_00587d40(auStack_a + -6);
  }
  return;
}


// ==== FUN_006b03d0 @ 0x006b03d0 ====

undefined4 FUN_006b03d0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_statpoint_009e0be0,0xd);
    if (iVar2 == 0) {
      if (*(int *)(in_ECX + 0x88) == 0) {
        pvVar3 = operator_new(0x58);
        if (pvVar3 == (void *)0x0) {
          uVar4 = 0;
        }
        else {
          uVar4 = FUN_006e3b90();
        }
        *(undefined4 *)(in_ECX + 0x88) = uVar4;
        FUN_006e2520(in_ECX + 0x8c);
      }
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_exit_009e0bf0);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5ae98 + 4))();
      *(undefined1 *)(in_ECX + 0x9a) = 0;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006b0480 @ 0x006b0480 ====

void FUN_006b0480(void)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  float *pfVar10;
  void *_Memory;
  int *piVar11;
  int in_ECX;
  void *unaff_EBP;
  undefined4 unaff_EDI;
  undefined4 *puVar12;
  uint uVar13;
  undefined1 *puVar14;
  uint uVar15;
  void **ppvVar16;
  uint in_stack_ffffff04;
  undefined4 uStack_d8;
  undefined4 uStack_c4;
  uint uStack_c0;
  float *pfStack_bc;
  uint uStack_b8;
  float fStack_b4;
  uint uStack_b0;
  void *pvStack_a0;
  void *pvStack_9c;
  void *pvStack_98;
  int iStack_94;
  uint uStack_8c;
  uint uStack_88;
  uint uStack_84;
  int iStack_80;
  int iStack_7c;
  int *piStack_78;
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  void *pvStack_68;
  undefined4 uStack_5c;
  uint uStack_58;
  uint uStack_54;
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  char acStack_34 [34];
  undefined2 uStack_12;
  undefined2 uStack_10;
  
  uStack_d8 = 0x6b0497;
  piVar4 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
  if (piVar4 == (int *)0x0) {
    return;
  }
  uStack_d8 = piVar4[0x2b];
  piStack_78 = piVar4;
  (**(code **)(*DAT_00b5ad1c + 0x20))();
  uStack_84 = 0xf;
  uStack_88 = 0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  FUN_00401740(s_guildbg_009e0bfc,7);
  FUN_006b0360(1,&pvStack_9c,uStack_10);
  if (0xf < uStack_84) {
    _free(pvStack_98);
    return;
  }
  uStack_84 = 0xf;
  uStack_88 = 0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  FUN_00401740(s_guildicon_009e0c04,9);
  FUN_006b0360(0,&pvStack_9c,uStack_12);
  if (0xf < uStack_84) {
    _free(pvStack_98);
    return;
  }
  pcVar5 = acStack_34;
  uStack_84 = 0xf;
  uStack_88 = 0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  do {
    cVar3 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar3 != '\0');
  FUN_00401740(acStack_34,(int)pcVar5 - (int)(acStack_34 + 1));
  if (*(int **)(in_ECX + 0x10) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x30))();
    FUN_0055a260(&pvStack_9c);
  }
  if (0xf < uStack_84) {
    _free(pvStack_98);
    return;
  }
  pcVar6 = (char *)(**(code **)(*piVar4 + 0x70))();
  uStack_84 = 0xf;
  uStack_88 = 0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  pcVar5 = pcVar6;
  do {
    cVar3 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar3 != '\0');
  FUN_00401740(pcVar6,(int)pcVar5 - (int)(pcVar6 + 1));
  if (*(int **)(in_ECX + 0x14) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x14) + 0x30))();
    FUN_0055a260(&pvStack_9c);
  }
  if (0xf < uStack_84) {
    _free(pvStack_98);
    return;
  }
  piVar4 = *(int **)(iStack_80 + 0x48);
  piVar7 = (int *)(**(code **)(*piVar4 + 0x28))();
  (**(code **)(*piVar7 + 8))();
  FUN_00401740(&DAT_009e0c10,2);
  ppvVar16 = &pvStack_6c;
  uVar8 = FUN_00404230(ppvVar16);
  if (*(int **)(in_ECX + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x18) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_54) {
    _free(pvStack_68);
    return;
  }
  piVar7 = (int *)(**(code **)(*DAT_00b5abb0 + 8))();
  (**(code **)(*piVar7 + 4))();
  in_stack_ffffff04 = in_stack_ffffff04 & 0xffffff00;
  FUN_00401740(&DAT_009e0c14,2);
  uVar8 = FUN_00404230(auStack_70 + -0x58,ppvVar16,in_stack_ffffff04);
  (**(code **)(*piVar4 + 0x14))(&DAT_009e0c18,uVar8);
  FUN_00401740(&DAT_009e0c1c,2);
  uVar8 = FUN_00404230(auStack_70);
  uVar8 = FUN_00402220(&uStack_54,uVar8);
  uVar8 = FUN_00405bd0(&pvStack_a0,uVar8);
  if (*(int **)(in_ECX + 0x1c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_88) {
    _free(pvStack_9c);
    return;
  }
  uStack_88 = 0xf;
  uStack_8c = 0;
  pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
  if (0xf < uStack_3c) {
    _free(pvStack_50);
    return;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  if (0xf < uStack_58) {
    _free(pvStack_6c);
    return;
  }
  uStack_58 = 0xf;
  uStack_5c = 0;
  pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
  if (0xf < uStack_b0) {
    _free(uStack_c4);
    return;
  }
  in_stack_ffffff04 = in_stack_ffffff04 & 0xffffff00;
  FUN_00401740(&DAT_009e0c20,2);
  uVar8 = FUN_00404230(auStack_70 + -0x58,ppvVar16,in_stack_ffffff04);
  if (*(int **)(in_ECX + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x20) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_b0) {
    _free(uStack_c4);
    return;
  }
  (**(code **)(*DAT_00b5ad1c + 0x94))();
  in_stack_ffffff04 = in_stack_ffffff04 & 0xffffff00;
  FUN_00401740(&DAT_009e0c24,2);
  uVar8 = FUN_00404230(auStack_70 + -0x58,ppvVar16,in_stack_ffffff04);
  if (*(int **)(in_ECX + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x24) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_b0) {
    _free(uStack_c4);
    return;
  }
  (**(code **)(**(int **)(uStack_84 + 0xc) + 0x14))();
  in_stack_ffffff04 = in_stack_ffffff04 & 0xffffff00;
  FUN_00401740(&DAT_009e0c28,2);
  uVar8 = FUN_00404230(auStack_70 + -0x58,ppvVar16,in_stack_ffffff04);
  if (*(int **)(in_ECX + 0x28) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x28) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_b0) {
    _free(uStack_c4);
    return;
  }
  uStack_88 = 0xf;
  uStack_8c = 0;
  pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
  FUN_00401740(s_btn_statpoint_009e0c2c,0xd);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_a0);
  if (((piVar4 != (int *)0x0) && (iVar9 = (**(code **)(*piVar4 + 0x30))(), iVar9 != 0)) &&
     (*(char *)(iVar9 + 0x10b) != (char)unaff_EDI)) {
    FUN_00558130(unaff_EDI);
  }
  if (0xf < uStack_8c) {
    _free(pvStack_a0);
    return;
  }
  iVar9 = **(int **)(uStack_88 + 0x50);
  uVar8 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar4 = (int *)(**(code **)(iVar9 + 0x14))(uVar8);
  (**(code **)(*piVar4 + 0x14))();
  uStack_d8 = (**(code **)(*piVar4 + 0x1c))();
  (**(code **)(*piVar4 + 0x34))();
  uStack_84 = (**(code **)(*piVar4 + 0x20))();
  pfVar10 = (float *)(**(code **)(*piVar4 + 0x18))();
  _Memory = (void *)(**(code **)(*piVar4 + 0x24))();
  iStack_80 = (int)*pfVar10;
  iStack_7c = (int)pfVar10[3];
  uStack_88 = (uint)pfVar10[4];
  FUN_00401740(&DAT_009e0c3c,2);
  uVar8 = FUN_00404230(auStack_70 + -0x60);
  if (*(int **)(in_ECX + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x2c) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_b8) {
    _free(unaff_EBP);
    return;
  }
  FUN_00401740(&DAT_009e0c40,2);
  uVar8 = FUN_00404230(auStack_70 + -0x60);
  if (*(int **)(in_ECX + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x30) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_b8) {
    _free(unaff_EBP);
    return;
  }
  FUN_00401740(&DAT_009e0c44,2);
  uVar8 = FUN_00404230(auStack_70 + -0x60);
  if (*(int **)(in_ECX + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x34) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_b8) {
    _free(unaff_EBP);
    return;
  }
  FUN_00401740(&DAT_009e0c48,2);
  puVar14 = auStack_70 + -0x60;
  uVar13 = 0x6b0b32;
  uVar8 = FUN_00404230(puVar14);
  if (*(int **)(in_ECX + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x38) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_b8) {
    _free(unaff_EBP);
    return;
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5a78c + 0x44))(4);
  piVar7 = (int *)(**(code **)(*DAT_00b5a78c + 0x44))(5);
  if (piVar4 == (int *)0x0) {
LAB_006b0bae:
    cVar3 = FUN_006b0280(piVar7);
    if (cVar3 == '\0') {
      FUN_00401830(s__d__d_009e0c5c);
LAB_006b0ec2:
      uVar8 = FUN_00404230(&uStack_d8);
      if (*(int **)(in_ECX + 0x3c) != (int *)0x0) {
        (**(code **)(**(int **)(in_ECX + 0x3c) + 0x30))();
        FUN_0055a260(uVar8);
      }
      goto joined_r0x006b0ee5;
    }
    piVar4 = (int *)(**(code **)(*piVar7 + 0x48))();
    iVar9 = (**(code **)(*piVar4 + 4))();
    if (*(int *)(iVar9 + 0xc) != 0x40a) {
      piVar4 = (int *)(**(code **)(*piVar7 + 0x48))();
      iVar9 = (**(code **)(*piVar4 + 4))();
      if (*(int *)(iVar9 + 0xc) != 0x40b) {
        piVar4 = (int *)(**(code **)(*piVar7 + 0x48))();
        iVar9 = (**(code **)(*piVar4 + 4))();
        if (*(int *)(iVar9 + 0xc) != 0x40f) {
          piVar4 = (int *)(**(code **)(*piVar7 + 0x48))();
          iVar9 = (**(code **)(*piVar4 + 4))();
          if (*(int *)(iVar9 + 0xc) != 0x412) {
            FUN_00401830(s__d__d_009e0c54);
            uVar8 = FUN_00404230(&uStack_d8);
            FUN_006b02c0(0xd,uVar8);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
        }
      }
    }
    pcVar5 = s__d__d_009e0c4c;
  }
  else {
    iVar9 = (**(code **)(*piVar4 + 0x2c))();
    uVar15 = *(uint *)(iVar9 + 8);
    if (((uVar15 >> 8 != 4) || (uVar15 == 0x40f)) || ((uVar15 == 0x410 || (uVar15 == 0x40e))))
    goto LAB_006b0bae;
    cVar3 = FUN_006b0280(piVar7);
    if (cVar3 != '\0') {
      piVar11 = (int *)(**(code **)(*piVar4 + 0x48))();
      iVar9 = (**(code **)(*piVar11 + 4))();
      if (*(int *)(iVar9 + 0xc) != 0x40a) {
        piVar11 = (int *)(**(code **)(*piVar7 + 0x48))();
        iVar9 = (**(code **)(*piVar11 + 4))();
        if (*(int *)(iVar9 + 0xc) != 0x40a) {
          piVar11 = (int *)(**(code **)(*piVar4 + 0x48))();
          iVar9 = (**(code **)(*piVar11 + 4))();
          if (*(int *)(iVar9 + 0xc) != 0x40b) {
            piVar11 = (int *)(**(code **)(*piVar7 + 0x48))();
            iVar9 = (**(code **)(*piVar11 + 4))();
            if (*(int *)(iVar9 + 0xc) != 0x40b) {
              piVar11 = (int *)(**(code **)(*piVar4 + 0x48))();
              iVar9 = (**(code **)(*piVar11 + 4))();
              if (*(int *)(iVar9 + 0xc) != 0x40f) {
                piVar11 = (int *)(**(code **)(*piVar7 + 0x48))();
                iVar9 = (**(code **)(*piVar11 + 4))();
                if (*(int *)(iVar9 + 0xc) != 0x40f) {
                  piVar4 = (int *)(**(code **)(*piVar4 + 0x48))();
                  iVar9 = (**(code **)(*piVar4 + 4))();
                  if (*(int *)(iVar9 + 0xc) != 0x412) {
                    piVar4 = (int *)(**(code **)(*piVar7 + 0x48))();
                    iVar9 = (**(code **)(*piVar4 + 4))();
                    if (*(int *)(iVar9 + 0xc) != 0x412) {
                      FUN_00401830(s__d__d_009e0c7c);
                      goto LAB_006b0d32;
                    }
                  }
                }
              }
            }
          }
        }
      }
      FUN_00401830(s__d__d_009e0c74);
      goto LAB_006b0ec2;
    }
    piVar7 = (int *)(**(code **)(*piVar4 + 0x48))();
    iVar9 = (**(code **)(*piVar7 + 4))();
    if (*(int *)(iVar9 + 0xc) != 0x40a) {
      piVar7 = (int *)(**(code **)(*piVar4 + 0x48))();
      iVar9 = (**(code **)(*piVar7 + 4))();
      if (*(int *)(iVar9 + 0xc) != 0x40b) {
        piVar7 = (int *)(**(code **)(*piVar4 + 0x48))();
        iVar9 = (**(code **)(*piVar7 + 4))();
        if (*(int *)(iVar9 + 0xc) != 0x40f) {
          piVar4 = (int *)(**(code **)(*piVar4 + 0x48))();
          iVar9 = (**(code **)(*piVar4 + 4))();
          if (*(int *)(iVar9 + 0xc) != 0x412) {
            FUN_00401830(s__d__d_009e0c6c);
LAB_006b0d32:
            uVar8 = FUN_00404230(&uStack_d8);
            FUN_006b02c0(0xd,uVar8);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
        }
      }
    }
    pcVar5 = s__d__d_009e0c64;
  }
  FUN_00401830(pcVar5);
  uVar8 = FUN_00404230(&uStack_d8);
  if (*(int **)(in_ECX + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x3c) + 0x30))();
    FUN_0055a260(uVar8);
  }
joined_r0x006b0ee5:
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  uVar13 = uVar13 & 0xffffff00;
  FUN_00401740(s__d__d_009e0c84,5);
  uVar8 = FUN_00404230(&uStack_d8);
  if (*(int **)(in_ECX + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  uVar15 = (uint)puVar14 & 0xffffff00;
  FUN_00401740(&DAT_009e0c8c,2);
  puVar12 = &uStack_d8;
  uVar8 = FUN_00404230(puVar12,uVar13,uVar15);
  if (*(int **)(in_ECX + 0x44) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x44) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  uVar13 = uVar13 & 0xffffff00;
  FUN_00401740(s__d__d_009e0c90,5);
  uVar8 = FUN_00404230(&uStack_d8,puVar12,uVar13);
  if (*(int **)(in_ECX + 0x48) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x48) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  uVar13 = uVar13 & 0xffffff00;
  FUN_00401740(s__d__d_009e0c98,5);
  uVar8 = FUN_00404230(&uStack_d8,puVar12,uVar13);
  if (*(int **)(in_ECX + 0x4c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x4c) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  uVar13 = uVar13 & 0xffffff00;
  FUN_00401740(s__d__d_009e0ca0,5);
  uVar8 = FUN_00404230(&uStack_d8,puVar12,uVar13);
  if (*(int **)(in_ECX + 0x50) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x50) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  uVar13 = uVar13 & 0xffffff00;
  FUN_00401740(&DAT_009e0cac,4);
  uVar8 = FUN_00404230(&uStack_d8,puVar12,uVar13);
  if (*(int **)(in_ECX + 0x54) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x54) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  uVar13 = uVar13 & 0xffffff00;
  FUN_00401740(&DAT_009e0cb8,4);
  uVar8 = FUN_00404230(&uStack_d8,puVar12,uVar13);
  if (*(int **)(in_ECX + 0x58) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x58) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  FUN_00401830(&DAT_009e0cc4);
  uVar8 = FUN_00404230(&uStack_d8);
  if (*(int **)(in_ECX + 0x5c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x5c) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  FUN_00401830(&DAT_009e0cd0);
  uVar8 = FUN_00404230(&uStack_d8);
  if (*(int **)(in_ECX + 0x60) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x60) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  FUN_00401830(&DAT_009e0cdc);
  uVar8 = FUN_00404230(&uStack_d8);
  if (*(int **)(in_ECX + 100) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 100) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  FUN_00401830(&DAT_009e0ce8);
  uVar8 = FUN_00404230(&uStack_d8);
  if (*(int **)(in_ECX + 0x68) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x68) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  fVar1 = *pfStack_bc;
  fVar2 = pfStack_bc[3];
  if ((DAT_009e0d04 <= fVar2) && (*(int **)(in_ECX + 0x6c) != (int *)0x0)) {
    (**(code **)(**(int **)(in_ECX + 0x6c) + 0x30))();
    FUN_00587ba0((fVar1 / fVar2) * DAT_0099de78);
  }
  fVar1 = pfStack_bc[1];
  fVar2 = pfStack_bc[4];
  if ((DAT_009e0d04 <= fVar2) && (*(int **)(in_ECX + 0x70) != (int *)0x0)) {
    (**(code **)(**(int **)(in_ECX + 0x70) + 0x30))();
    FUN_00587ba0((fVar1 / fVar2) * DAT_0099de78);
  }
  fStack_b4 = 0.0;
  pfStack_bc = (float *)0x0;
  cVar3 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if ((cVar3 == '\x01') &&
     (pfVar10 = (float *)(**(code **)(*DAT_00b5ad04 + 0x18))(*(undefined4 *)(iStack_94 + 0xac)),
     pfVar10 != (float *)0x0)) {
    fStack_b4 = *pfVar10;
    pfStack_bc = (float *)pfVar10[1];
  }
  (**(code **)(*DAT_00b5ad98 + 0x10))();
  FUN_00401830(&DAT_009e0cf0);
  uVar8 = FUN_00404230(&uStack_d8);
  if (*(int **)(in_ECX + 0x80) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x80) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  FUN_00401830(&DAT_009e0cf4);
  uVar8 = FUN_00404230(&uStack_d8);
  if (*(int **)(in_ECX + 0x78) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x78) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  FUN_00401830(&DAT_009e0cf8);
  uVar8 = FUN_00404230(&uStack_d8);
  if (*(int **)(in_ECX + 0x7c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x7c) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  FUN_00401830(s__u__u_009e0cfc);
  uVar8 = FUN_00404230(&uStack_d8);
  if (*(int **)(in_ECX + 0x84) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x84) + 0x30))();
    FUN_0055a260(uVar8);
  }
  if (0xf < uStack_c0) {
    _free(_Memory);
    return;
  }
  if (*(int **)(in_ECX + 0x74) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x74) + 0x30))();
    FUN_00587ba0((fStack_b4 / (float)pfStack_bc) * DAT_0099de78);
  }
  if ((*(char *)(in_ECX + 0x98) != '\0') &&
     (iVar9 = (**(code **)(*DAT_00b5a6ac + 0x20))(), 1000 < (uint)(iVar9 - *(int *)(in_ECX + 0x94)))
     ) {
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    uVar8 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(undefined4 *)(in_ECX + 0x94) = uVar8;
    if (4 < *(byte *)(in_ECX + 0x99)) {
      *(undefined1 *)(in_ECX + 0x98) = 0;
      *(undefined1 *)(in_ECX + 0x99) = 0;
      return;
    }
    *(byte *)(in_ECX + 0x99) = *(byte *)(in_ECX + 0x99) + 1;
  }
  return;
}


// ==== FUN_006b1600 @ 0x006b1600 ====

/* WARNING: Removing unreachable block (ram,0x006b181f) */
/* WARNING: Removing unreachable block (ram,0x006b17a1) */
/* WARNING: Removing unreachable block (ram,0x006b17e0) */
/* WARNING: Removing unreachable block (ram,0x006b185e) */
/* WARNING: Removing unreachable block (ram,0x006b1762) */
/* WARNING: Removing unreachable block (ram,0x006b16e4) */
/* WARNING: Removing unreachable block (ram,0x006b16a6) */
/* WARNING: Removing unreachable block (ram,0x006b1723) */
/* WARNING: Removing unreachable block (ram,0x006b1648) */

void FUN_006b1600(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint in_ECX;
  undefined1 auStackY_140 [128];
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *_Memory;
  uint *_Memory_00;
  undefined4 *_Memory_01;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  uint uVar15;
  undefined1 auStack_1e [30];
  
  uStack_38 = s_UI_Game2_CharWindow_ui_statewnd__009e0a4c;
  uStack_3c = 0x6b162c;
  FUN_00401740();
  uStack_38 = (char *)0x6b1636;
  iVar1 = FUN_00410500();
  uStack_38 = (char *)(iVar1 + 0x3c);
  uStack_3c = 0x6b1669;
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar2;
  uStack_40 = (undefined1 *)0x6b1674;
  uStack_3c = in_ECX;
  (**(code **)(*piVar2 + 0x40))();
  uStack_40 = (undefined1 *)0xd;
  FUN_00401740();
  uStack_40 = auStack_1e + -10;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 8) = uVar3;
  FUN_00401740();
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0xc) = uVar3;
  FUN_00401740();
  puVar6 = auStack_1e + -0x12;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  FUN_00401740();
  puVar5 = auStack_1e + -0x16;
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
  puVar8 = auStack_1e + -0x26;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x24) = uVar3;
  uVar15 = 0;
  FUN_00401740();
  puVar7 = auStack_1e + -0x2a;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  if (0xf < uVar15) {
    _free(puVar6);
    return;
  }
  uStack_38 = (char *)0x0;
  FUN_00401740();
  puVar6 = auStack_1e + -0x2e;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x2c) = uVar3;
  if (0xf < uStack_38) {
    _free(puVar5);
    return;
  }
  uStack_38 = (char *)0xf;
  uStack_3c = 0;
  FUN_00401740();
  puVar5 = auStack_1e + -0x32;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x30) = uVar3;
  if (0xf < uStack_3c) {
    _free(_Memory_01);
    return;
  }
  uStack_3c = 0xf;
  uStack_40 = (undefined1 *)0x0;
  FUN_00401740();
  puVar4 = auStack_1e + -0x36;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x34) = uVar3;
  if (0xf < uStack_40) {
    _free(_Memory_00);
    return;
  }
  uStack_40 = (undefined1 *)0xf;
  uVar15 = 0;
  FUN_00401740();
  puVar10 = auStack_1e + -0x3a;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x38) = uVar3;
  if (0xf < uVar15) {
    _free(_Memory);
    return;
  }
  uVar15 = 0;
  FUN_00401740();
  puVar9 = auStack_1e + -0x3e;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x3c) = uVar3;
  if (0xf < uVar15) {
    _free(puVar8);
    return;
  }
  uVar15 = 0;
  FUN_00401740();
  puVar8 = auStack_1e + -0x42;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x40) = uVar3;
  if (0xf < uVar15) {
    _free(puVar7);
    return;
  }
  uVar15 = 0;
  FUN_00401740();
  puVar7 = auStack_1e + -0x46;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x44) = uVar3;
  if (0xf < uVar15) {
    _free(puVar6);
    return;
  }
  uVar15 = 0;
  FUN_00401740();
  puVar6 = auStack_1e + -0x4a;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x48) = uVar3;
  if (0xf < uVar15) {
    _free(puVar5);
    return;
  }
  uVar15 = 0;
  FUN_00401740();
  puVar5 = auStack_1e + -0x4e;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x4c) = uVar3;
  if (0xf < uVar15) {
    _free(puVar4);
    return;
  }
  uVar15 = 0;
  FUN_00401740();
  puVar4 = auStackY_140 + 0xd0;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x50) = uVar3;
  if (0xf < uVar15) {
    _free(puVar10);
    return;
  }
  uVar15 = 0;
  FUN_00401740();
  puVar10 = auStackY_140 + 0xcc;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x54) = uVar3;
  if (0xf < uVar15) {
    _free(puVar9);
    return;
  }
  uVar15 = 0;
  FUN_00401740();
  puVar9 = auStackY_140 + 200;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x58) = uVar3;
  if (0xf < uVar15) {
    _free(puVar8);
    return;
  }
  uVar15 = 0;
  FUN_00401740();
  puVar8 = auStackY_140 + 0xc4;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x5c) = uVar3;
  if (0xf < uVar15) {
    _free(puVar7);
    return;
  }
  uVar15 = 0;
  FUN_00401740();
  puVar7 = auStackY_140 + 0xc0;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x60) = uVar3;
  if (0xf < uVar15) {
    _free(puVar6);
    return;
  }
  uVar15 = 0;
  FUN_00401740();
  puVar6 = auStackY_140 + 0xbc;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 100) = uVar3;
  if (0xf < uVar15) {
    _free(puVar5);
    return;
  }
  uVar14 = 0;
  uVar15 = (uint)puVar5 & 0xffffff00;
  FUN_00401740();
  puVar5 = auStackY_140 + 0xb8;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x68) = uVar3;
  if (0xf < uVar14) {
    _free(puVar4);
    return;
  }
  uVar13 = 0;
  uVar14 = (uint)puVar4 & 0xffffff00;
  FUN_00401740(s_pro_hp_009e0b98);
  puVar4 = auStackY_140 + 0xb4;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x6c) = uVar3;
  if (0xf < uVar13) {
    _free(puVar10);
    return;
  }
  uVar12 = 0;
  uVar13 = (uint)puVar10 & 0xffffff00;
  FUN_00401740(s_pro_mp_009e0ba0,6);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_140 + 0xb0);
  *(undefined4 *)(in_ECX + 0x70) = uVar3;
  if (0xf < uVar12) {
    _free(puVar9);
    return;
  }
  uVar11 = 0;
  uVar12 = (uint)puVar9 & 0xffffff00;
  FUN_00401740(s_pro_shield_009e0ba8,10);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_140 + 0xac);
  *(undefined4 *)(in_ECX + 0x74) = uVar3;
  if (0xf < uVar11) {
    _free(puVar8);
    return;
  }
  FUN_00401830(s_lbl_disposition_009e0bb4);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_140 + 0xa8);
  *(undefined4 *)(in_ECX + 0x78) = uVar3;
  if (0xf < uVar15) {
    _free(puVar7);
    return;
  }
  FUN_00401830(s_lbl_pk_009e0bc4);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_140 + 0xa4);
  *(undefined4 *)(in_ECX + 0x7c) = uVar3;
  if (0xf < uVar14) {
    _free(puVar6);
    return;
  }
  FUN_00401830(s_lbl_pvp_009e0bcc);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_140 + 0xa0);
  *(undefined4 *)(in_ECX + 0x80) = uVar3;
  if (0xf < uVar13) {
    _free(puVar5);
    return;
  }
  FUN_00401830(s_lbl_shield_009e0bd4);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_140 + 0x9c);
  *(undefined4 *)(in_ECX + 0x84) = uVar3;
  if (uVar12 < 0x10) {
    FUN_006b0480();
    return;
  }
  _free(puVar4);
  return;
}


// ==== FUN_006b1e40 @ 0x006b1e40 ====

void FUN_006b1e40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e0d10;
  in_ECX[1] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x25] = 0;
  *(undefined1 *)(in_ECX + 0x26) = 0;
  *(undefined1 *)((int)in_ECX + 0x99) = 0;
  *(undefined1 *)((int)in_ECX + 0x9a) = 1;
  in_ECX[0x23] = 0x134;
  in_ECX[0x24] = 0xa5;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  FUN_006b1600();
  return;
}


// ==== FUN_006b1f00 @ 0x006b1f00 ====

undefined4 FUN_006b1f00(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    FUN_006b0480();
  }
  else {
    if (iVar2 == 0x70130005) {
      FUN_006b0480();
      if (*(undefined4 **)(in_ECX + 0x88) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x88))(1);
      }
      *(undefined4 *)(in_ECX + 0x88) = 0;
      *(undefined1 *)(in_ECX + 0x98) = 1;
      return 1;
    }
    if (iVar2 == 0x70130006) {
      if (*(undefined4 **)(in_ECX + 0x88) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x88))(1);
      }
      *(undefined4 *)(in_ECX + 0x88) = 0;
      return 1;
    }
  }
  if ((*(int **)(in_ECX + 0x88) == (int *)0x0) ||
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x88) + 8))(param_1), cVar1 == '\0')) {
    return 0;
  }
  return 1;
}


// ==== FUN_006b1fa0 @ 0x006b1fa0 ====

undefined1 FUN_006b1fa0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x9a);
}


// ==== FUN_006b1fb0 @ 0x006b1fb0 ====

void FUN_006b1fb0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e0d10;
  if ((undefined4 *)in_ECX[0x22] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x22])(1);
    in_ECX[0x22] = 0;
  }
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006b2000 @ 0x006b2000 ====

void FUN_006b2000(void)

{
  return;
}


// ==== FUN_006b2010 @ 0x006b2010 ====

undefined1 FUN_006b2010(void)

{
  return 0;
}


// ==== FUN_006b2020 @ 0x006b2020 ====

undefined1 FUN_006b2020(void)

{
  return 0;
}


// ==== FUN_006b2040 @ 0x006b2040 ====

void FUN_006b2040(undefined4 param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  undefined1 auStack_a [6];
  int iStack_4;
  
  if (param_3 == '\x01') {
    iVar5 = 0x66;
  }
  else {
    cVar1 = (**(code **)(*DAT_00b5ad9c + 0xc))(in_ECX + 0x58);
    if (cVar1 == '\x01') {
      iVar5 = 0x67;
    }
    else {
      iVar5 = (**(code **)(*DAT_00b5a7b8 + 0x38))(in_ECX + 0x58);
      iVar5 = (iVar5 != 0) + 100;
    }
  }
  uVar2 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  cVar1 = (**(code **)(*DAT_00b5add0 + 0x3c))(uVar2);
  if (cVar1 == '\x01') {
    uVar2 = (**(code **)(*DAT_00b5ac98 + 0x8c))(param_1);
    switch(uVar2) {
    case 0:
    case 4:
      iVar5 = 0x69;
      break;
    case 1:
      iVar5 = 0x68;
      break;
    case 2:
    case 3:
      iVar5 = 0x67;
    }
  }
  else {
    cVar1 = (**(code **)(*DAT_00b5add0 + 0x44))(uVar2);
    if ((cVar1 != '\0') &&
       (pbVar3 = (byte *)(**(code **)(*DAT_00b5ada8 + 0xc))(in_ECX + 0x58), pbVar3 != (byte *)0x0))
    {
      iVar5 = *pbVar3 + 0x6a;
    }
  }
  iVar4 = (**(code **)(**(int **)(iStack_4 + 0xc) + 0x30))();
  if (*(int *)(iVar4 + 0x94) != iVar5) {
    FUN_00587d40(auStack_a + -10);
  }
  return;
}


// ==== FUN_006b2160 @ 0x006b2160 ====

void FUN_006b2160(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined4 auStack_a8 [10];
  undefined4 uStack_80;
  undefined4 *puStack_7c;
  undefined4 *puStack_78;
  undefined1 *puStack_74;
  undefined4 uStack_70;
  undefined2 uStack_5a;
  undefined4 auStack_58 [7];
  ushort uStack_3a;
  undefined4 auStack_34 [2];
  undefined1 local_2c [40];
  int iStack_4;
  
  uStack_70 = *(undefined4 *)(param_1 + 4);
  puStack_74 = local_2c;
  puStack_78 = (undefined4 *)0x6b2184;
  (**(code **)(*DAT_00b5ad1c + 0x20))();
  puVar2 = auStack_34;
  puVar6 = auStack_58 + -2;
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar6 = puVar6 + 1;
  }
  puStack_7c = auStack_58 + -3;
  *(undefined2 *)puVar6 = *(undefined2 *)puVar2;
  uStack_80 = 0x6b21a3;
  puStack_78 = (undefined4 *)(param_1 + 4);
  FUN_006b4fa0();
  if ((unaff_EBP != *(int *)(in_ECX + 0x10)) &&
     (piVar1 = *(int **)(unaff_EBP + 0x80), piVar1 != (int *)0x0)) {
    if ((uStack_3a == 0) || (*(short *)(iStack_4 + 8) != 0)) {
      puStack_78 = (undefined4 *)0x6b2234;
      puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puStack_78 = (undefined4 *)0x6b2241;
        uVar3 = (**(code **)(*piVar1 + 4))();
        *puVar2 = &PTR_FUN_009bba08;
        puVar2[1] = uVar3;
        puVar2[3] = 1;
        puVar2[5] = 0;
        *(undefined1 *)(puVar2 + 6) = 0;
      }
      *(undefined1 *)((int)puVar2 + 0x19) = 1;
      puVar2[2] = (uint)*(ushort *)(iStack_4 + 8);
      puVar2[3] = 1;
      puVar2[4] = 1000;
      *(undefined1 *)(puVar2 + 6) = 0;
      puStack_7c = (undefined4 *)0x6b2287;
      puStack_78 = puVar2;
      (**(code **)(*DAT_00b5ad24 + 4))();
      puStack_7c = (undefined4 *)0x1;
      uStack_80 = 0x6b228f;
      (**(code **)*puVar2)();
    }
    else {
      puStack_78 = (undefined4 *)0x6b21dc;
      iVar4 = (**(code **)(*DAT_00b5a6a8 + 4))();
      if (iVar4 == 0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puStack_78 = (undefined4 *)0x6b21e9;
        puStack_78 = (undefined4 *)(**(code **)(*piVar1 + 4))();
        puStack_7c = (undefined4 *)0x6b21f1;
        puVar2 = (undefined4 *)FUN_00558dc0();
      }
      *(undefined1 *)((int)puVar2 + 0x19) = 0;
      puVar2[2] = (uint)uStack_3a;
      puVar2[3] = 1;
      puVar2[4] = 1000;
      *(undefined1 *)(puVar2 + 6) = 0;
      puStack_7c = (undefined4 *)0x6b221f;
      puStack_78 = puVar2;
      (**(code **)(*DAT_00b5ad24 + 4))();
      puStack_7c = (undefined4 *)0x1;
      uStack_80 = 0x6b2227;
      (**(code **)*puVar2)();
    }
    iVar4 = *DAT_00b5ad1c;
    puVar2 = auStack_58 + -4;
    puVar6 = auStack_a8;
    for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar6 = puVar6 + 1;
    }
    uVar3 = *(undefined4 *)(param_1 + 4);
    *(undefined2 *)puVar6 = *(undefined2 *)puVar2;
    (**(code **)(iVar4 + 0x24))(uVar3);
  }
  return;
}


// ==== FUN_006b22d0 @ 0x006b22d0 ====

void FUN_006b22d0(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_retaddr;
  undefined1 auStack_ae [2];
  undefined4 auStack_ac [9];
  undefined1 auStack_88 [8];
  undefined4 uStack_80;
  undefined4 uStack_7c;
  int iStack_78;
  int iStack_74;
  void *pvStack_68;
  uint uStack_54;
  undefined1 auStack_50 [8];
  int iStack_48;
  int iStack_44;
  int iStack_40;
  void *pvStack_3c;
  uint uStack_28;
  void *pvStack_c;
  int local_8;
  
  local_8 = param_3 - param_5;
  uVar3 = (**(code **)(*(int *)param_1[3] + 0x10))();
  FUN_005041e0(uVar3);
  uStack_80 = 0;
  uStack_7c = 0;
  iStack_74 = param_3;
  iStack_78 = param_4;
  (**(code **)(*(int *)param_1[3] + 0xc))(auStack_88);
  if (0xf < uStack_54) {
    _free(pvStack_68);
    return;
  }
  piVar1 = (int *)param_1[1];
  (**(code **)(*piVar1 + 0x30))();
  uVar3 = (**(code **)(*piVar1 + 0x10))();
  FUN_005041e0(uVar3);
  iStack_48 = param_5;
  pvStack_3c = pvStack_c;
  iStack_44 = param_5;
  iStack_40 = param_4 - param_5;
  (**(code **)(*piVar1 + 0xc))(auStack_50);
  FUN_005569f0(unaff_retaddr,0);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*param_1 + 0x14))();
  piVar2 = (int *)*param_1;
  puVar6 = (undefined4 *)(auStack_ae + -6);
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  (**(code **)(*piVar2 + 0x18))(auStack_ae + -6);
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    uVar3 = (**(code **)(*piVar1 + 4))();
    *puVar4 = &PTR_FUN_009bcd68;
    puVar4[1] = uVar3;
  }
  *(undefined1 *)(puVar4 + 2) = 0;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar4);
  (**(code **)*puVar4)(1);
  if (uStack_28 < 0x10) {
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_006b2460 @ 0x006b2460 ====

void FUN_006b2460(int *param_1,undefined4 *param_2)

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
  FUN_00401740(s_textbox_009e0f28,7);
  uVar1 = (**(code **)(*param_1 + 0x34))(&local_1c);
  param_2[1] = uVar1;
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_pan_mark_009e0f30,8);
  uVar1 = (**(code **)(*param_1 + 0x34))((int)register0x00000010 + -0x20);
  param_2[2] = uVar1;
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740(s_pan_middle_009e0f3c,10);
  uVar1 = (**(code **)(*param_1 + 0x34))((int)register0x00000010 + -0x24);
  param_2[3] = uVar1;
  if (uStack_10 < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_006b2550 @ 0x006b2550 ====

void FUN_006b2550(void)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = local_5;
  uVar1 = FUN_006b4df0();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  local_4 = *(undefined4 *)(in_ECX + 8);
  FUN_006b53d0(9,&local_4);
  *(undefined4 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 1;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  return;
}


// ==== FUN_006b25b0 @ 0x006b25b0 ====

void FUN_006b25b0(void)

{
  int in_ECX;
  undefined4 local_4;
  
  FUN_0059c2f0();
  local_4 = *(undefined4 *)(in_ECX + 8);
  FUN_006b54f0(9,&local_4);
  *(undefined4 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 1;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  return;
}


// ==== FUN_006b25f0 @ 0x006b25f0 ====

/* WARNING: Removing unreachable block (ram,0x006b2683) */

void FUN_006b25f0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int in_ECX;
  undefined1 auStack_2a [42];
  
  FUN_0041ec50();
  if (param_1 != *(int *)(in_ECX + 8)) {
    *param_2 = *(undefined4 *)(param_1 + 0x24);
    *param_3 = *(undefined4 *)(param_1 + 0x28);
    return;
  }
  if (0x100 < *(uint *)(in_ECX + 0x28)) {
    FUN_006b25b0();
  }
  (**(code **)(*DAT_00b5a688 + 0x34))(2,param_1,param_2,param_3);
  FUN_00401660(param_1,0,0xffffffff);
  FUN_006b5770(auStack_2a + -0x12,auStack_2a + -10);
  *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + 1;
  return;
}


// ==== FUN_006b26c0 @ 0x006b26c0 ====

void FUN_006b26c0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  FUN_006b25f0(param_1,&local_8,&local_4);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = local_8;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = local_4;
  }
  return;
}


// ==== FUN_006b2710 @ 0x006b2710 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_006b2710(int *param_1,undefined4 param_2,uint *param_3,int *param_4,int param_5,
                 char *param_6,undefined4 *param_7)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *******pppppppuVar7;
  undefined4 *puVar8;
  int in_ECX;
  undefined1 *puVar9;
  char *pcVar10;
  uint uStack_e0;
  undefined1 auStack_dc [4];
  void *pvStack_d8;
  undefined4 uStack_c8;
  uint uStack_c4;
  undefined1 local_c0 [4];
  undefined4 *******local_bc [4];
  int local_ac;
  uint local_a8;
  undefined1 auStack_a4 [4];
  undefined4 *******apppppppuStack_a0 [4];
  int iStack_90;
  uint uStack_8c;
  undefined4 uStack_88;
  int *local_84;
  undefined1 local_80 [4];
  undefined4 *******local_7c [4];
  int local_6c;
  uint local_68;
  undefined4 uStack_64;
  void *pvStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 auStack_48 [4];
  void *pvStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  char acStack_2c [30];
  short sStack_e;
  short sStack_c;
  short sStack_a;
  short sStack_8;
  char cStack_4;
  
  local_68 = 0xf;
  local_6c = 0;
  local_7c[0] = (undefined4 *******)((uint)local_7c[0] & 0xffffff00);
  FUN_00401660(param_1 + 0xc,0,0xffffffff);
  if (local_6c != 0) {
    pppppppuVar7 = local_7c[0];
    if (local_68 < 0x10) {
      pppppppuVar7 = local_7c;
    }
    iVar3 = FUN_00403620(0,*(undefined4 *)(in_ECX + 0x2c),pppppppuVar7,local_6c);
    if (iVar3 == 0) {
      FUN_00401660(in_ECX + 0x34,0,0xffffffff);
      uVar5 = *(uint *)(in_ECX + 0x50);
    }
    else {
      uVar6 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x6e0055);
      uStack_30 = 0xf;
      uStack_34 = 0;
      pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
      FUN_00401660(uVar6,0,0xffffffff);
      uStack_4c = 0xf;
      uStack_50 = 0;
      pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
      FUN_00401660(auStack_48,0,0xffffffff);
      uVar6 = FUN_00405bd0(auStack_dc,&uStack_64,local_80);
      FUN_00401660(uVar6,0,0xffffffff);
      if (0xf < uStack_c4) {
        _free(pvStack_d8);
        return;
      }
      uStack_c4 = 0xf;
      uStack_c8 = 0;
      pvStack_d8 = (void *)((uint)pvStack_d8 & 0xffffff00);
      if (0xf < uStack_4c) {
        _free(pvStack_60);
        return;
      }
      uStack_e0 = 0;
      uStack_88 = 0;
      FUN_006b25f0(local_80,&uStack_e0,&uStack_88);
      uVar5 = uStack_e0;
      uVar6 = FUN_004022a0(&uStack_64,s_<center><color_BBBBFF>_009e0dc4,local_80,s_<_color>_009e0db8
                          );
      uVar6 = FUN_00402220(auStack_dc,uVar6);
      FUN_00401660(uVar6,0,0xffffffff);
      if (0xf < uStack_c4) {
        _free(pvStack_d8);
        return;
      }
      uStack_c4 = 0xf;
      uStack_c8 = 0;
      pvStack_d8 = (void *)((uint)pvStack_d8 & 0xffffff00);
      if (0xf < uStack_4c) {
        _free(pvStack_60);
        return;
      }
      FUN_00401660(param_1 + 0xc,0,0xffffffff);
      FUN_00401660(local_80,0,0xffffffff);
      *(uint *)(in_ECX + 0x50) = uVar5;
      *(int *)(in_ECX + 0x54) = *param_1;
      if (0xf < uStack_30) {
        _free(pvStack_44);
        return;
      }
      uVar5 = uStack_e0;
    }
    FUN_00406720(local_80);
    uVar4 = *param_3;
    if (*param_3 <= uVar5) {
      uVar4 = uVar5;
    }
    *param_3 = uVar4;
    *param_4 = *param_4 + 0x10;
  }
  local_84 = param_1 + 5;
  local_a8 = 0xf;
  local_ac = 0;
  local_bc[0] = (undefined4 *******)((uint)local_bc[0] & 0xffffff00);
  FUN_00401660(local_84,0,0xffffffff);
  if (local_ac == 0) {
    if (0xf < local_a8) {
      _free(local_bc[0]);
      return;
    }
  }
  else {
    uVar5 = param_1[3];
    cVar2 = (**(code **)(*DAT_00b5ac1c + 0x24))();
    if ((cVar2 == '\x01') && ((param_5 == 0 || (param_5 == 2)))) {
      uVar5 = (**(code **)(*DAT_00b5acf8 + 4))(*param_1);
    }
    if ((uVar5 & 0xffffff) != 0xffffff) {
      pcVar10 = s_<_color>_009e0ddc;
      puVar9 = local_c0;
      FUN_00401740(s_<color__6X>_009e0de8,0xb);
      uVar6 = FUN_00404230(&uStack_64);
      uVar6 = FUN_00405bd0(auStack_48,uVar6,puVar9,pcVar10);
      uVar6 = FUN_00402220(auStack_dc,uVar6);
      FUN_00401660(uVar6,0,0xffffffff);
      if (0xf < uStack_c4) {
        _free(pvStack_d8);
        return;
      }
      uStack_c4 = 0xf;
      uStack_c8 = 0;
      pvStack_d8 = (void *)((uint)pvStack_d8 & 0xffffff00);
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
    pppppppuVar7 = local_bc[0];
    if (local_a8 < 0x10) {
      pppppppuVar7 = local_bc;
    }
    iVar3 = FUN_00403620(0,*(undefined4 *)(in_ECX + 0x88),pppppppuVar7,local_ac);
    piVar1 = local_84;
    if ((iVar3 == 0) && (*(int *)(in_ECX + 0x94) == *param_1)) {
      uVar5 = *(uint *)(in_ECX + 0x90);
    }
    else {
      uStack_e0 = 0;
      uStack_88 = 0;
      FUN_006b25f0(local_84,&uStack_e0,&uStack_88);
      uVar5 = uStack_e0;
      FUN_00401660(piVar1,0,0xffffffff);
      *(int *)(in_ECX + 0x94) = *param_1;
      FUN_00401660(local_c0,0,0xffffffff);
      *(uint *)(in_ECX + 0x90) = uVar5;
    }
    FUN_006b2040(param_1 + 0x1a,*param_1,(char)param_1[0x13]);
    if (uVar5 < *param_3) {
      uVar5 = *param_3;
    }
    *param_3 = uVar5;
    *param_4 = *param_4 + 0x10;
    (**(code **)(*DAT_00b5ad1c + 0x20))(acStack_2c,*param_1);
    pcVar10 = acStack_2c;
    uStack_8c = 0xf;
    iStack_90 = 0;
    apppppppuStack_a0[0] = (undefined4 *******)((uint)apppppppuStack_a0[0] & 0xffffff00);
    do {
      cVar2 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar2 != '\0');
    FUN_00401740(acStack_2c,(int)pcVar10 - (int)(acStack_2c + 1));
    if (iStack_90 == 0) {
      FUN_00406720(local_c0);
      if (*param_6 == '\x01') {
        (**(code **)(*DAT_00b5ac6c + 0x14))(*param_1,*param_7);
        *param_7 = 0xffffffff;
        *param_6 = '\0';
      }
      piVar1 = (int *)param_1[0x1c];
      if ((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar1 + 0x28))(), cVar2 != '\0')) {
        (**(code **)(*piVar1 + 0x24))(0);
      }
      if (0xf < uStack_8c) {
        _free(apppppppuStack_a0[0]);
        return;
      }
      uStack_8c = 0xf;
      iStack_90 = 0;
      apppppppuStack_a0[0] = (undefined4 *******)((uint)apppppppuStack_a0[0] & 0xffffff00);
      if (0xf < local_a8) {
        _free(local_bc[0]);
        return;
      }
    }
    else {
      uVar5 = (**(code **)(*DAT_00b5ae14 + 0x18))();
      pcVar10 = acStack_2c;
      do {
        cVar2 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar2 != '\0');
      uStack_e0 = uVar5;
      FUN_00401740(acStack_2c,(int)pcVar10 - (int)(acStack_2c + 1));
      if (cStack_4 == '\x01') {
        cVar2 = (**(code **)(*DAT_00b5acac + 0x44))(*param_1);
        if (cVar2 == '\0') {
          FUN_00401830(s_<img_screen_siege_index__d_width_009e0e24);
          uVar6 = FUN_00404230(&uStack_e0);
          FUN_00401660(uVar6,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_00401830(s_<img_screen_siege_index__d_width_009e0df4);
        uVar6 = FUN_00404230(&uStack_e0);
        FUN_00401660(uVar6,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar2 = (**(code **)(*DAT_00b5add0 + 0x3c))(uVar5);
      if ((cVar2 == '\x01') && (cVar2 = (**(code **)(*DAT_00b5ac98 + 0x44))(), cVar2 == '\x01')) {
        FUN_00401830(s_<img_screen_siege_index__d_width_009e0e54);
        uVar6 = FUN_00404230(auStack_dc);
        FUN_00401660(uVar6,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_004bdb90();
      *(undefined4 *)(in_ECX + 0x110) = 0;
      pppppppuVar7 = apppppppuStack_a0[0];
      if (uStack_8c < 0x10) {
        pppppppuVar7 = apppppppuStack_a0;
      }
      iVar3 = FUN_00403620(0,*(undefined4 *)(in_ECX + 0xac),pppppppuVar7,iStack_90);
      if (iVar3 == 0) {
        FUN_00401660(in_ECX + 0xf4,0,0xffffffff);
        FUN_00401ff0(in_ECX + 0xb4,0,0xffffffff);
        uStack_e0 = *(uint *)(in_ECX + 0xd0);
      }
      else {
        uStack_e0 = 0;
        local_84 = (int *)0x0;
        FUN_006b25f0(auStack_a4,&uStack_e0,&local_84);
        uVar5 = uStack_e0;
        pcVar10 = acStack_2c;
        do {
          cVar2 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar2 != '\0');
        FUN_00401740(acStack_2c,(int)pcVar10 - (int)(acStack_2c + 1));
        FUN_00401660(auStack_a4,0,0xffffffff);
        *(uint *)(in_ECX + 0xd0) = uVar5;
        uVar6 = FUN_00405bd0(auStack_dc,in_ECX + 0xf4,auStack_a4);
        FUN_00401660(uVar6,0,0xffffffff);
        if (0xf < uStack_c4) {
          _free(pvStack_d8);
          return;
        }
      }
      uVar5 = *(int *)(in_ECX + 0x110) + uStack_e0;
      if (uVar5 < *param_3) {
        uVar5 = *param_3;
      }
      *param_3 = uVar5;
      *param_4 = *param_4 + 0x10;
      if ((sStack_8 == 0) && (sStack_a == 0)) {
        if ((int *)param_1[0x1c] != (int *)0x0) {
          (**(code **)(*(int *)param_1[0x1c] + 0x24))(0);
        }
        uVar6 = FUN_004022a0(auStack_48,s_<color_C8FFC8>_009e0ed8,auStack_a4,s_<_color>_009e0ecc);
        uVar6 = FUN_00402220(auStack_dc,uVar6);
        FUN_00401660(uVar6,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      piVar1 = (int *)param_1[0x1c];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x24))(1);
        puVar8 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puVar8 == (undefined4 *)0x0) {
          puVar8 = (undefined4 *)0x0;
        }
        else {
          *puVar8 = &PTR_FUN_009bdce4;
          puVar8[3] = 0;
          puVar8[4] = 0;
          puVar8[5] = 0;
        }
        uVar6 = (**(code **)(*piVar1 + 4))();
        puVar8[1] = uVar6;
        pvStack_60 = (void *)0x18;
        uStack_5c = 0x18;
        local_68 = 0;
        uStack_64 = 0;
        if (sStack_c != 0) {
          FUN_00401830(s_guildbg_s_009e0e84);
          uStack_5c = (**(code **)(*DAT_00b5a7c0 + 8))(&uStack_e0);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        if (sStack_e != 0) {
          FUN_00401830(s_guildicon_s_009e0e90);
          uStack_5c = (**(code **)(*DAT_00b5a7c0 + 8))(&uStack_e0);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        (**(code **)(*DAT_00b5ad24 + 4))(puVar8);
        (**(code **)*puVar8)(1);
      }
      *param_3 = *param_3 + 0x25;
      uVar6 = FUN_004022a0(auStack_48,s_<set_37><color_C8FFC8>_009e0ea8,auStack_a4,
                           s_<_color>_009e0e9c);
      uVar6 = FUN_00402220(auStack_dc,uVar6);
      FUN_00401660(uVar6,0,0xffffffff);
      if (0xf < uStack_c4) {
        _free(pvStack_d8);
        return;
      }
      uStack_c4 = 0xf;
      uStack_c8 = 0;
      pvStack_d8 = (void *)((uint)pvStack_d8 & 0xffffff00);
      if (0xf < uStack_30) {
        _free(pvStack_44);
        return;
      }
      FUN_00406720(auStack_a4);
      uVar6 = FUN_004022a0(auStack_dc,s_<set_37>_009e0ec0,local_c0);
      FUN_00401660(uVar6,0,0xffffffff);
      if (0xf < uStack_c4) {
        _free(pvStack_d8);
        return;
      }
      FUN_00406720(local_c0);
      if (0xf < uStack_8c) {
        _free(apppppppuStack_a0[0]);
        return;
      }
      uStack_8c = 0xf;
      iStack_90 = 0;
      apppppppuStack_a0[0] = (undefined4 *******)((uint)apppppppuStack_a0[0] & 0xffffff00);
      if (0xf < local_a8) {
        _free(local_bc[0]);
        return;
      }
    }
    uStack_8c = 0xf;
    iStack_90 = 0;
  }
  if (local_68 < 0x10) {
    return;
  }
  local_a8 = 0xf;
  local_ac = 0;
  local_bc[0] = (undefined4 *******)((uint)local_bc[0] & 0xffffff00);
  _free(local_7c[0]);
  return;
}


// ==== FUN_006b3300 @ 0x006b3300 ====

void FUN_006b3300(int *param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  uint uVar14;
  undefined4 unaff_EDI;
  undefined2 uVar17;
  int **ppiVar15;
  int *piVar16;
  float10 fVar18;
  float10 fVar19;
  float fVar20;
  char cStack_13d;
  char cVar21;
  void *pvVar22;
  undefined1 local_122 [2];
  int aiStack_120 [3];
  uint uStack_114;
  undefined1 auStack_110 [4];
  void *pvStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  void *pvStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  void *local_ec;
  undefined4 uStack_e8;
  undefined1 auStack_d8 [4];
  float fStack_d4;
  float fStack_d0;
  undefined4 uStack_cc;
  void *pvStack_c8;
  float fStack_c4;
  undefined4 uStack_c0;
  void *pvStack_bc;
  undefined4 uStack_b8;
  uint uStack_b4;
  float fStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  undefined4 uStack_a0;
  void *pvStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  uint uStack_88;
  void *pvStack_80;
  undefined4 uStack_7c;
  undefined1 auStack_78 [8];
  undefined4 uStack_70;
  uint uStack_6c;
  undefined1 auStack_50 [12];
  int *apiStack_44 [14];
  int iStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar17 = (undefined2)((uint)unaff_EDI >> 0x10);
  cVar2 = (**(code **)(*DAT_00b5ae58 + 8))();
  if ((cVar2 == '\0') || (iVar3 = (**(code **)(*DAT_00b5a97c + 0xc))(), *param_1 != iVar3)) {
    if ((param_1[0x15] != 0) &&
       (aiStack_120[0] = (param_1[0x16] - param_1[0x15]) / 0x1c, aiStack_120[0] != 0)) {
      (**(code **)(*DAT_00b5a6ac + 0x20))();
    }
    if (DAT_00b5acd8 != (int *)0x0) {
      iVar3 = *param_1;
      piVar4 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(iVar3);
      if (piVar4 != (int *)0x0) {
        iVar5 = (**(code **)(*piVar4 + 0x1c))();
        if (iVar5 != 0) {
          FUN_00511d60();
        }
        puVar6 = (uint *)(**(code **)(*piVar4 + 0x28))();
        aiStack_120[1] = *puVar6;
        aiStack_120[2] = puVar6[1];
        fVar18 = (float10)(**(code **)(*piVar4 + 0x34))();
        fVar19 = (float10)(**(code **)(*piVar4 + 0x30))();
        uStack_b4 = aiStack_120[1];
        uStack_ac = aiStack_120[2];
        fStack_b0 = (float)(fVar19 + (float10)(float)fVar18 + (float10)DAT_0099d0b4);
        puVar12 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
        ppiVar15 = apiStack_44;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *ppiVar15 = (int *)*puVar12;
          puVar12 = puVar12 + 1;
          ppiVar15 = ppiVar15 + 1;
        }
        thunk_FUN_0079e43e(&fStack_8c);
        iVar5 = iStack_c;
        fVar20 = DAT_0099d080 / fStack_8c;
        fStack_98 = fStack_98 * fVar20;
        fStack_94 = fStack_94 * fVar20;
        fStack_90 = fVar20 * fStack_90;
        fStack_8c = fVar20 * fStack_8c;
        if ((fStack_90 < 0.0) || (DAT_0099d080 < fStack_90)) {
          uVar17 = 0;
        }
        puVar12 = (undefined4 *)(iStack_c + 0x68);
        iVar7 = (**(code **)(**(int **)(iStack_c + 0x68) + 0x14))();
        cVar2 = (char)uVar17;
        if (cVar2 != *(char *)(iVar7 + 0xc)) {
          piVar8 = (int *)(**(code **)(*(int *)*puVar12 + 0x14))();
          piVar16 = aiStack_120;
          for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar16 = *piVar8;
            piVar8 = piVar8 + 1;
            piVar16 = piVar16 + 1;
          }
          uStack_114 = CONCAT31(uStack_114._1_3_,cVar2);
          (**(code **)(**(int **)(iStack_c + 0x68) + 0x18))(aiStack_120);
          iVar5 = iStack_c;
        }
        iVar7 = (**(code **)(**(int **)(iVar5 + 0x98) + 0x14))();
        cVar21 = (char)((ushort)uVar17 >> 8);
        if (cVar21 != *(char *)(iVar7 + 0xc)) {
          piVar8 = (int *)(**(code **)(**(int **)(iVar5 + 0x98) + 0x14))();
          piVar16 = aiStack_120;
          for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar16 = *piVar8;
            piVar8 = piVar8 + 1;
            piVar16 = piVar16 + 1;
          }
          uStack_114 = CONCAT31(uStack_114._1_3_,cVar21);
          (**(code **)(**(int **)(iVar5 + 0x98) + 0x18))(aiStack_120);
          iVar5 = iStack_c;
        }
        if (cVar2 != '\0') {
          fStack_d4 = 0.0;
          fStack_d0 = 0.0;
          uStack_cc = 0;
          pvVar22 = (void *)0x1;
          uVar9 = (**(code **)(*piVar4 + 0xc))(uStack_8,uStack_4);
          FUN_006b2710(iVar5,auStack_d8,local_122 + -6,local_122 + -10,uVar9,uStack_8,uStack_4);
          fVar1 = fStack_d0;
          pvStack_9c = (void *)0xf;
          uStack_a0 = 0;
          fStack_b0 = (float)((uint)fStack_b0 & 0xffffff00);
          for (fVar20 = fStack_d4; fVar20 != fVar1; fVar20 = (float)((int)fVar20 + 0x1c)) {
            FUN_00401ff0(fVar20,0,0xffffffff);
            FUN_004020e0(&DAT_009e0d98,1);
          }
          FUN_0040f1e0(&pvStack_c8,uStack_c0,pvStack_bc,uStack_b8,auStack_50,
                       *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0),
                       *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c));
          FUN_006b22d0((undefined4 *)(iVar5 + 0x68),&uStack_b4,4,9,4);
          uVar9 = 1;
          (**(code **)(**(int **)(iVar5 + 0x68) + 0x54))
                    ((int)(float)pvStack_c8 + -4,(int)fStack_c4 + 0x1a,1);
          cStack_13d = (char)((uint)&uStack_b4 >> 0x18);
          if (cStack_13d == '\0') {
            if (uStack_a8 < 0x10) {
              uStack_a8 = 0xf;
              uStack_ac = 0;
              pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
              FUN_00406250();
              return;
            }
            _free(pvStack_bc);
            return;
          }
          iVar7 = *(int *)(iVar5 + 0x58);
          iVar13 = *(int *)(iVar5 + 0x54);
          uStack_7c = 0xf;
          pvStack_80 = (void *)0x0;
          fStack_90 = (float)((uint)fStack_90 & 0xffffff00);
          iVar11 = 4;
          for (; iVar13 != iVar7; iVar13 = iVar13 + 0x1c) {
            uVar10 = FUN_00402220(local_122 + -10,iVar13,&DAT_009e0d9c);
            FUN_00401ff0(uVar10,0,0xffffffff);
            if (0xf < uStack_114) {
              _free(pvVar22);
              return;
            }
            iVar11 = iVar11 + 0x10;
            uStack_114 = 0xf;
            aiStack_120[2] = 0;
            pvVar22 = (void *)0x0;
          }
          uVar14 = *(int *)(iVar5 + 0x60) + 8;
          uStack_f0 = 0;
          local_ec = (void *)0x0;
          uStack_e8 = 0;
          uStack_100 = 0;
          pvStack_fc = (void *)0x0;
          uStack_f8 = 0;
          uStack_114 = 0xf;
          aiStack_120[2] = 0;
          FUN_00401740(s___GT___009e0da0,6);
          FUN_00406720(local_122 + -10);
          if (0xf < uStack_114) {
            _free((void *)0x0);
            return;
          }
          uStack_114 = 0xf;
          aiStack_120[2] = 0;
          FUN_00401740(&DAT_009e0da8,1);
          FUN_00406720(local_122 + -10);
          if (0xf < uStack_114) {
            _free((void *)0x0);
            return;
          }
          uStack_114 = 0xf;
          aiStack_120[2] = 0;
          FUN_00401740(s___LT___009e0dac,6);
          FUN_00406720(local_122 + -10);
          if (0xf < uStack_114) {
            _free((void *)0x0);
            return;
          }
          uStack_114 = 0xf;
          aiStack_120[2] = 0;
          FUN_00401740(&DAT_009e0db4,1);
          FUN_00406720(local_122 + -10);
          if (0xf < uStack_114) {
            _free((void *)0x0);
            return;
          }
          FUN_00404a40(auStack_78,&fStack_94,&uStack_104,&uStack_f4);
          FUN_006b22d0(apiStack_44,auStack_78,iVar11,uVar14,4);
          (**(code **)(*apiStack_44[0] + 0x54))
                    ((int)fStack_d4 - (uVar14 >> 1),(((int)fStack_d0 - iVar11) - iVar3) + 0x1c,1);
          pvVar22 = local_ec;
          if (0xf < uStack_6c) {
            _free(pvStack_80);
            return;
          }
          uStack_6c = 0xf;
          uStack_70 = 0;
          pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
          if (pvStack_10c != (void *)0x0) {
            FUN_00405de0(pvStack_10c,uStack_108,auStack_110,uVar9);
            _free(pvStack_10c);
            return;
          }
          pvStack_10c = (void *)0x0;
          uStack_108 = 0;
          uStack_104 = 0;
          if (pvStack_fc != (void *)0x0) {
            FUN_00405de0(pvStack_fc,uStack_f8,&uStack_100,uVar9);
            _free(pvStack_fc);
            return;
          }
          pvStack_fc = (void *)0x0;
          uStack_f8 = 0;
          uStack_f4 = 0;
          if (0xf < uStack_88) {
            _free(pvStack_9c);
            return;
          }
          uStack_88 = 0xf;
          fStack_8c = 0.0;
          pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
          if (0xf < uStack_b4) {
            _free(pvStack_c8);
            return;
          }
          uStack_b4 = 0xf;
          uStack_b8 = 0;
          pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
          if (local_ec != (void *)0x0) {
            FUN_00405de0(local_ec,uStack_e8,&uStack_f0,uVar9);
            _free(pvVar22);
            return;
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_006b3a80 @ 0x006b3a80 ====

void FUN_006b3a80(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int in_ECX;
  
  cVar4 = (**(code **)(*DAT_00b5ae58 + 8))();
  iVar3 = (int)param_1;
  if (cVar4 != '\0') {
    piVar1 = (int *)((int)param_1 + 0xc);
    iVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
    if (*piVar1 == iVar5) {
      FUN_006b4fa0(&param_1,piVar1);
      if (param_1 == (undefined4 *)*(int *)(in_ECX + 0x10)) {
        return;
      }
      *(undefined1 *)((int)param_1 + 0x15) = 0;
      FUN_006b3300((int)param_1 + 0x10,(int)param_1 + 0xd8,(int)param_1 + 0xdc);
      return;
    }
  }
  if (*(int *)(iVar3 + 0xc) == 0) {
    if (*(int *)(iVar3 + 4) == 0) {
      *(undefined1 *)(in_ECX + 9) = *(undefined1 *)(iVar3 + 8);
    }
    else if (*(int *)(iVar3 + 4) == 1) {
      *(undefined1 *)(in_ECX + 8) = *(undefined1 *)(iVar3 + 8);
    }
    puVar2 = *(undefined4 **)(in_ECX + 0x10);
    param_1 = (undefined4 *)*puVar2;
    while (param_1 != puVar2) {
      FUN_006b3300(param_1 + 4,param_1 + 0x36,param_1 + 0x37);
      FUN_006b4c50();
    }
  }
  else {
    FUN_006b4fa0(&param_1,iVar3 + 0xc);
    if (param_1 != (undefined4 *)*(int *)(in_ECX + 0x10)) {
      *(undefined1 *)((int)param_1 + 0x15) = *(undefined1 *)(iVar3 + 8);
      FUN_006b3300((int)param_1 + 0x10,(int)param_1 + 0xd8,(int)param_1 + 0xdc);
      return;
    }
  }
  return;
}


// ==== FUN_006b3b90 @ 0x006b3b90 ====

void FUN_006b3b90(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  char *******pppppppcVar6;
  char *******pppppppcVar7;
  undefined4 *******pppppppuVar8;
  uint uVar9;
  undefined4 uVar10;
  int in_ECX;
  undefined4 *******pppppppuVar11;
  uint local_80;
  undefined4 uStack_7c;
  int local_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [4];
  void *pvStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 auStack_54 [4];
  char *******apppppppcStack_50 [4];
  int iStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  undefined4 *******apppppppuStack_34 [4];
  int iStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if ((*(int *)(param_1 + 0x1c) != 0) &&
     (local_78 = in_ECX, FUN_006b4fa0(&local_80,param_1 + 4), uVar3 = local_80,
     local_80 != *(uint *)(in_ECX + 0x10))) {
    iVar1 = local_80 + 0x10;
    iVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(int *)(uVar3 + 0x74) = iVar5 + 10000;
    FUN_00406250();
    pvStack_60 = (void *)0x0;
    uStack_5c = 0;
    uStack_58 = 0;
    pvStack_70 = (void *)0x0;
    uStack_6c = 0;
    uStack_68 = 0;
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s___BS___009e0f04,6);
    FUN_00406720(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(&DAT_009e0f0c,1);
    FUN_00406720(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s___GT___009e0f10,6);
    FUN_00406720(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(&DAT_009e0f18,1);
    FUN_00406720(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s___LT___009e0f1c,6);
    FUN_00406720(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(&DAT_009e0f24,1);
    FUN_00406720(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    FUN_00404a40(auStack_54,param_1 + 8,auStack_64,auStack_74);
    uStack_20 = 0xf;
    iStack_24 = 0;
    apppppppuStack_34[0] = (undefined4 *******)((uint)apppppppuStack_34[0] & 0xffffff00);
    if (iStack_40 != 0) {
      do {
        if (iStack_40 == 1) {
          FUN_00401ff0(auStack_54,0,1);
          pppppppcVar7 = apppppppcStack_50[0];
          if (uStack_3c < 0x10) {
            pppppppcVar7 = (char *******)apppppppcStack_50;
          }
          pppppppcVar6 = apppppppcStack_50[0];
          if (uStack_3c < 0x10) {
            pppppppcVar6 = (char *******)apppppppcStack_50;
          }
          FUN_004bdb30(&uStack_7c,pppppppcVar6,(char *)((int)pppppppcVar7 + iStack_40));
        }
        else {
          pppppppcVar7 = apppppppcStack_50[0];
          if (uStack_3c < 0x10) {
            pppppppcVar7 = (char *******)apppppppcStack_50;
          }
          cVar4 = FUN_00403d70((int)*(char *)pppppppcVar7);
          if (cVar4 == '\x01') {
            FUN_00401ff0(auStack_54,0,2);
            FUN_00401390(0,1);
          }
          else {
            FUN_00401ff0(auStack_54,0,1);
          }
          FUN_00401390(0,1);
        }
        local_80 = 0;
        uStack_7c = 0;
        FUN_006b25f0(auStack_38,&local_80,&uStack_7c);
        if (99 < local_80) {
          FUN_00406720(auStack_38);
          pppppppuVar8 = apppppppuStack_34[0];
          if (uStack_20 < 0x10) {
            pppppppuVar8 = apppppppuStack_34;
          }
          pppppppuVar11 = apppppppuStack_34[0];
          if (uStack_20 < 0x10) {
            pppppppuVar11 = apppppppuStack_34;
          }
          FUN_004bdb30(&uStack_7c,pppppppuVar11,(int)pppppppuVar8 + iStack_24);
        }
      } while (iStack_40 != 0);
      if (iStack_24 != 0) {
        FUN_00406720(auStack_38);
      }
    }
    iVar5 = *(int *)(uVar3 + 100);
    iVar2 = *(int *)(uVar3 + 0x68);
    *(undefined4 *)(uVar3 + 0x70) = 1;
    for (; iVar5 != iVar2; iVar5 = iVar5 + 0x1c) {
      local_80 = 0;
      uStack_7c = 0;
      FUN_006b25f0(iVar5,&local_80,&uStack_7c);
      uVar9 = *(uint *)(uVar3 + 0x70);
      if (*(uint *)(uVar3 + 0x70) <= local_80) {
        uVar9 = local_80;
      }
      *(uint *)(uVar3 + 0x70) = uVar9;
    }
    iVar2 = *(int *)(uVar3 + 0x68);
    for (iVar5 = *(int *)(uVar3 + 100); iVar5 != iVar2; iVar5 = iVar5 + 0x1c) {
      uVar10 = FUN_00404a40(auStack_1c,iVar5,auStack_74,auStack_64);
      FUN_00401660(uVar10,0,0xffffffff);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    }
    FUN_006b3300(iVar1,uVar3 + 0xd8,uVar3 + 0xdc);
    if (0xf < uStack_20) {
      _free(apppppppuStack_34[0]);
      return;
    }
    uStack_20 = 0xf;
    iStack_24 = 0;
    apppppppuStack_34[0] = (undefined4 *******)((uint)apppppppuStack_34[0] & 0xffffff00);
    if (0xf < uStack_3c) {
      _free(apppppppcStack_50[0]);
      return;
    }
    uStack_3c = 0xf;
    iStack_40 = 0;
    apppppppcStack_50[0] = (char *******)((uint)apppppppcStack_50[0] & 0xffffff00);
    if (pvStack_70 != (void *)0x0) {
      FUN_00405de0(pvStack_70,uStack_6c,auStack_74,local_78);
      _free(pvStack_70);
      return;
    }
    pvStack_70 = (void *)0x0;
    uStack_6c = 0;
    uStack_68 = 0;
    if (pvStack_60 != (void *)0x0) {
      FUN_00405de0(pvStack_60,uStack_5c,auStack_64,local_78);
      _free(pvStack_60);
      return;
    }
  }
  return;
}


// ==== FUN_006b40f0 @ 0x006b40f0 ====

void FUN_006b40f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar2 = param_1;
  FUN_006b4fa0(&param_1,param_1 + 4);
  iVar3 = param_1;
  if (param_1 != *(int *)(in_ECX + 0x10)) {
    iVar1 = param_1 + 0x10;
    FUN_00401660(iVar2 + 8,0,0xffffffff);
    *(undefined1 *)(iVar3 + 0x5c) = *(undefined1 *)(iVar2 + 0x24);
    FUN_006b3300(iVar1,iVar3 + 0xd8,iVar3 + 0xdc);
  }
  return;
}


// ==== FUN_006b4150 @ 0x006b4150 ====

void FUN_006b4150(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar2 = param_1;
  FUN_006b4fa0(&param_1,param_1 + 0xc);
  iVar3 = param_1;
  if (param_1 != *(int *)(in_ECX + 0x10)) {
    iVar1 = param_1 + 0x10;
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar2 + 0x14);
    FUN_00401660(iVar2 + 0x18,0,0xffffffff);
    *(undefined1 *)(iVar3 + 0x15) = 1;
    FUN_006b3300(iVar1,iVar3 + 0xd8,iVar3 + 0xdc);
  }
  return;
}


// ==== FUN_006b41c0 @ 0x006b41c0 ====

void FUN_006b41c0(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x10);
  piVar2 = (int *)*piVar1;
  do {
    if (piVar2 == piVar1) {
      return;
    }
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    if ((uint)piVar2[0x1d] < uVar3) {
      if (piVar2[0x19] != 0) {
        FUN_00405de0(piVar2[0x19],piVar2[0x1a],piVar2 + 0x18,piVar2);
        _free((void *)piVar2[0x19]);
        return;
      }
      piVar2[0x19] = 0;
      piVar2[0x1a] = 0;
      piVar2[0x1b] = 0;
    }
    FUN_006b3300(piVar2 + 4,piVar2 + 0x36,piVar2 + 0x37);
    FUN_006b4c50();
  } while( true );
}


// ==== FUN_006b4250 @ 0x006b4250 ====

undefined4 FUN_006b4250(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint in_ECX;
  uint uStack_4;
  
  piVar2 = param_1;
  uStack_4 = in_ECX;
  param_1 = (int *)(**(code **)(*param_1 + 0x10))();
  iVar1 = piVar2[2];
  if ((iVar1 != 7) && (iVar1 != 8)) {
    return 0;
  }
  FUN_006b4fa0(&uStack_4,&param_1);
  if (uStack_4 == *(uint *)(in_ECX + 0x10)) {
    return 0;
  }
  if (iVar1 == 7) {
    *(undefined1 *)(uStack_4 + 0x14) = 1;
  }
  else {
    if (iVar1 != 8) {
      return 1;
    }
    *(undefined1 *)(uStack_4 + 0x14) = 0;
  }
  FUN_006b3300(uStack_4 + 0x10,uStack_4 + 0xd8,uStack_4 + 0xdc);
  return 1;
}


// ==== FUN_006b42d0 @ 0x006b42d0 ====

void FUN_006b42d0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  char *pcVar6;
  int in_ECX;
  char *pcVar7;
  undefined1 auStack_204 [4];
  int iVar8;
  int iStack_1e4;
  void *pvStack_1d8;
  void *pvStack_1d4;
  undefined4 uStack_1c8;
  uint uStack_1c4;
  uint uStack_1c0;
  undefined4 uStack_1bc;
  undefined1 uStack_1b7;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_158;
  undefined1 auStack_154 [48];
  undefined1 auStack_124 [48];
  undefined1 auStack_f4 [4];
  undefined1 auStack_f0 [4];
  undefined4 auStack_ec [59];
  
  (**(code **)(*DAT_00b5a97c + 0xc))();
  FUN_006b4fa0();
  if (iStack_1e4 == *(int *)(in_ECX + 0x10)) {
    uStack_1c4 = 0xf;
    uStack_1c8 = 0;
    pvStack_1d8 = (void *)((uint)pvStack_1d8 & 0xffffff00);
    FUN_00401740(s_UI_Game2_ui_ChatBubble_txt_009e0d7c);
    iVar2 = FUN_00410500();
    if (0xf < uStack_1c4) {
      _free(pvStack_1d8);
      return;
    }
    iVar8 = iVar2 + 0x3c;
    piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
    (**(code **)(*piVar3 + 0x40))();
    piVar4 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar2 + 0x3c,0);
    (**(code **)(*piVar4 + 0x40))();
    piVar5 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
    pcVar6 = (char *)(**(code **)(*piVar5 + 0x70))();
    uStack_1c0 = 0xf;
    uStack_1c4 = 0;
    pvStack_1d4 = (void *)((uint)pvStack_1d4 & 0xffffff00);
    pcVar7 = pcVar6;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(pcVar6,(int)pcVar7 - (int)(pcVar6 + 1));
    FUN_006b5610();
    uStack_1bc = (**(code **)(*DAT_00b5a97c + 0xc))();
    uStack_1b4 = 0;
    uStack_1b0 = 0xffffff;
    uStack_1ac = 0x38;
    FUN_00401660(&pvStack_1d8,0,0xffffffff);
    uStack_158 = 0;
    cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
    if (cVar1 != '\0') {
      uStack_1b7 = 0;
    }
    FUN_006b2460(piVar3,auStack_154);
    FUN_006b2460(piVar4,auStack_124);
    auStack_ec[0] = uStack_1bc;
    FUN_006b5540(&uStack_1bc);
    FUN_006b5dd0(auStack_204 + 8,auStack_ec);
    FUN_006b56f0();
    FUN_006b3300(&uStack_1bc,auStack_f4,auStack_f0);
    if (iVar8 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar8);
    }
    FUN_006b56f0();
    if (0xf < uStack_1c0) {
      _free(pvStack_1d4);
      return;
    }
  }
  return;
}


// ==== FUN_006b44e0 @ 0x006b44e0 ====

void FUN_006b44e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  int iStack_1cc;
  undefined1 auStack_1c8 [4];
  void *apvStack_1c4 [2];
  undefined4 uStack_1bc;
  undefined1 uStack_1b7;
  undefined4 uStack_1b4;
  uint uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_158;
  undefined1 auStack_154 [48];
  undefined1 auStack_124 [48];
  undefined1 auStack_f4 [4];
  undefined1 auStack_f0 [4];
  undefined4 auStack_ec [59];
  
  iVar1 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iVar1 != *(int *)(param_1 + 0xc)) {
    FUN_006b4fa0(&iStack_1cc,(int *)(param_1 + 0xc));
    if (iStack_1cc == *(int *)(in_ECX + 0x10)) {
      uStack_1b0 = 0xf;
      uStack_1b4 = 0;
      apvStack_1c4[0] = (void *)((uint)apvStack_1c4[0] & 0xffffff00);
      FUN_00401740(s_UI_Game2_ui_ChatBubble_txt_009e0ee8,0x1a);
      iStack_1cc = FUN_00410500(auStack_1c8);
      if (0xf < uStack_1b0) {
        _free(apvStack_1c4[0]);
        return;
      }
      iVar4 = iStack_1cc + 0x3c;
      iVar1 = iVar4;
      piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar4,0);
      (**(code **)(*piVar2 + 0x40))();
      piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar4,0);
      (**(code **)(*piVar3 + 0x40))();
      FUN_006b5610();
      uStack_1b4 = *(undefined4 *)(param_1 + 4);
      uStack_1bc = *(undefined4 *)(param_1 + 0xc);
      uStack_1b0 = *(undefined4 *)(param_1 + 0x10);
      uStack_1ac = *(undefined4 *)(param_1 + 0x14);
      FUN_00401660(param_1 + 0x18,0,0xffffffff);
      uStack_1b7 = *(undefined1 *)(param_1 + 8);
      uStack_158 = 0;
      FUN_006b2460(piVar2,auStack_154);
      FUN_006b2460(piVar3,auStack_124);
      auStack_ec[0] = uStack_1bc;
      FUN_006b5540(&uStack_1bc);
      FUN_006b5dd0(apvStack_1c4,auStack_ec);
      FUN_006b56f0();
      FUN_006b3300(&uStack_1bc,auStack_f4,auStack_f0);
      if (iVar1 != 0) {
        (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
      }
      FUN_006b56f0();
    }
  }
  return;
}


// ==== FUN_006b4690 @ 0x006b4690 ====

void FUN_006b4690(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iStack_4;
  
  iVar2 = param_1;
  iVar1 = *(int *)(param_1 + 4);
  iStack_4 = in_ECX;
  iVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iVar3 != iVar1) {
    param_1 = *(undefined4 *)(iVar2 + 4);
    FUN_006b4fa0(&iStack_4,&param_1);
    if (iStack_4 != *(int *)(in_ECX + 0x10)) {
      (**(code **)(*DAT_00b5a7a4 + 8))(*(undefined4 *)(iStack_4 + 0x78));
      (**(code **)(*DAT_00b5a7a4 + 8))(*(undefined4 *)(iStack_4 + 0xa8));
      FUN_006b5e90(&iStack_4,iStack_4);
    }
  }
  return;
}


// ==== FUN_006b4710 @ 0x006b4710 ====

undefined4 FUN_006b4710(int *param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 < 0x7004000d) {
    if (uVar2 == 0x7004000c) {
      FUN_006b3a80(param_1);
      return 1;
    }
    if (uVar2 < 0x7004000b) {
      if (uVar2 == 0x7004000a) {
        FUN_006b44e0(param_1);
        return 1;
      }
      if (uVar2 == 0x10001) {
        cVar1 = FUN_006b4250(param_1);
        if (cVar1 != '\0') {
          return 1;
        }
      }
      else if (uVar2 == 0x40001) {
        FUN_006b41c0(param_1);
      }
    }
    else if (uVar2 == 0x7004000b) {
      FUN_006b4690(param_1);
      return 1;
    }
  }
  else {
    switch(uVar2 + 0x8ffbfff3) {
    case 0:
      FUN_006b3b90(param_1);
      return 1;
    case 1:
      FUN_006b40f0(param_1);
      return 1;
    case 2:
      FUN_006b4150(param_1);
      return 1;
    case 8:
      FUN_006b2160(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006b4810 @ 0x006b4810 ====

void FUN_006b4810(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_ECX;
  int *local_4;
  
  piVar1 = (int *)in_ECX[4];
  *in_ECX = &PTR_FUN_009e0f90;
  piVar2 = (int *)*piVar1;
  while (local_4 = piVar2, piVar2 != piVar1) {
    if (piVar2[0x1e] != 0) {
      (**(code **)(*DAT_00b5a7a4 + 8))(piVar2[0x1e]);
    }
    if (piVar2[0x2a] != 0) {
      (**(code **)(*DAT_00b5a7a4 + 8))(piVar2[0x2a]);
    }
    FUN_006b4c50();
    piVar2 = local_4;
  }
  FUN_006b61e0(*(undefined4 *)(in_ECX[4] + 4));
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  in_ECX[5] = 0;
  *(undefined4 *)in_ECX[4] = in_ECX[4];
  *(undefined4 *)(in_ECX[4] + 8) = in_ECX[4];
  if (0xf < (uint)in_ECX[0x43]) {
    _free((void *)in_ECX[0x3e]);
    return;
  }
  in_ECX[0x43] = 0xf;
  in_ECX[0x42] = 0;
  *(undefined1 *)(in_ECX + 0x3e) = 0;
  if (0xf < (uint)in_ECX[0x3c]) {
    _free((void *)in_ECX[0x37]);
    return;
  }
  in_ECX[0x3c] = 0xf;
  in_ECX[0x3b] = 0;
  *(undefined1 *)(in_ECX + 0x37) = 0;
  if (0xf < (uint)in_ECX[0x33]) {
    _free((void *)in_ECX[0x2e]);
    return;
  }
  in_ECX[0x33] = 0xf;
  in_ECX[0x32] = 0;
  *(undefined1 *)(in_ECX + 0x2e) = 0;
  if (0xf < (uint)in_ECX[0x2c]) {
    _free((void *)in_ECX[0x27]);
    return;
  }
  in_ECX[0x2c] = 0xf;
  in_ECX[0x2b] = 0;
  *(undefined1 *)(in_ECX + 0x27) = 0;
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
  if (0xf < (uint)in_ECX[0x13]) {
    _free((void *)in_ECX[0xe]);
    return;
  }
  in_ECX[0x13] = 0xf;
  in_ECX[0x12] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  if ((uint)in_ECX[0xc] < 0x10) {
    in_ECX[0xc] = 0xf;
    in_ECX[0xb] = 0;
    *(undefined1 *)(in_ECX + 7) = 0;
    FUN_006b6230(&local_4,*(undefined4 *)in_ECX[4],(undefined4 *)in_ECX[4]);
    _free((void *)in_ECX[4]);
    return;
  }
  _free((void *)in_ECX[7]);
  return;
}


// ==== FUN_006b4a00 @ 0x006b4a00 ====

void FUN_006b4a00(void)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009e0f90;
  iVar1 = FUN_006b4e80();
  in_ECX[4] = iVar1;
  *(undefined1 *)(iVar1 + 0xe1) = 1;
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  *(undefined4 *)in_ECX[4] = in_ECX[4];
  *(undefined4 *)(in_ECX[4] + 8) = in_ECX[4];
  in_ECX[5] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0xf;
  *(undefined1 *)(in_ECX + 7) = 0;
  in_ECX[0x13] = 0xf;
  in_ECX[0x12] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  in_ECX[0x1c] = 0xf;
  in_ECX[0x1b] = 0;
  *(undefined1 *)(in_ECX + 0x17) = 0;
  in_ECX[0x23] = 0xf;
  in_ECX[0x22] = 0;
  *(undefined1 *)(in_ECX + 0x1e) = 0;
  in_ECX[0x2c] = 0xf;
  in_ECX[0x2b] = 0;
  *(undefined1 *)(in_ECX + 0x27) = 0;
  in_ECX[0x33] = 0xf;
  in_ECX[0x32] = 0;
  *(undefined1 *)(in_ECX + 0x2e) = 0;
  in_ECX[0x3c] = 0xf;
  in_ECX[0x3b] = 0;
  *(undefined1 *)(in_ECX + 0x37) = 0;
  in_ECX[0x43] = 0xf;
  in_ECX[0x42] = 0;
  *(undefined1 *)(in_ECX + 0x3e) = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 1;
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
  if ((uint)in_ECX[0x1c] < 0x10) {
    puVar3 = in_ECX + 0x17;
  }
  else {
    puVar3 = (undefined4 *)in_ECX[0x17];
  }
  if ((uint)in_ECX[0x1c] < 0x10) {
    puVar2 = in_ECX + 0x17;
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x17];
  }
  FUN_004bdb30(local_4,puVar2,in_ECX[0x1b] + (int)puVar3);
  piVar4 = in_ECX + 0x27;
  if ((uint)in_ECX[0x2c] < 0x10) {
    piVar5 = piVar4;
  }
  else {
    piVar5 = (int *)*piVar4;
  }
  if (0xf < (uint)in_ECX[0x2c]) {
    piVar4 = (int *)*piVar4;
  }
  FUN_004bdb30(local_4,piVar4,in_ECX[0x2b] + (int)piVar5);
  piVar4 = in_ECX + 0x37;
  if ((uint)in_ECX[0x3c] < 0x10) {
    piVar5 = piVar4;
  }
  else {
    piVar5 = (int *)*piVar4;
  }
  if (0xf < (uint)in_ECX[0x3c]) {
    piVar4 = (int *)*piVar4;
  }
  FUN_004bdb30(local_4,piVar4,in_ECX[0x3b] + (int)piVar5);
  piVar4 = in_ECX + 0x3e;
  if ((uint)in_ECX[0x43] < 0x10) {
    piVar5 = piVar4;
  }
  else {
    piVar5 = (int *)*piVar4;
  }
  if (0xf < (uint)in_ECX[0x43]) {
    piVar4 = (int *)*piVar4;
  }
  FUN_004bdb30(local_4,piVar4,in_ECX[0x42] + (int)piVar5);
  in_ECX[0x44] = 0;
  return;
}


// ==== FUN_006b4bb0 @ 0x006b4bb0 ====

void FUN_006b4bb0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0xe1);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0xe1);
  }
  return;
}


// ==== FUN_006b4bd0 @ 0x006b4bd0 ====

void FUN_006b4bd0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0xe1);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0xe1);
  }
  return;
}


// ==== FUN_006b4bf0 @ 0x006b4bf0 ====

void FUN_006b4bf0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0xe1) == '\0') {
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


// ==== FUN_006b4c50 @ 0x006b4c50 ====

void FUN_006b4c50(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0xe1) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0xe1) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0xe1);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0xe1);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0xe1);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0xe1);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_006b4cb0 @ 0x006b4cb0 ====

void FUN_006b4cb0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0xe1) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0xe1) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0xe1);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0xe1);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0xe1) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0xe1) == '\0');
    if (*(char *)((int)piVar4 + 0xe1) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_006b4d20 @ 0x006b4d20 ====

void FUN_006b4d20(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0xe1) == '\0') {
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


// ==== FUN_006b4d80 @ 0x006b4d80 ====

int FUN_006b4d80(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c780;
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


// ==== Catch@006b4de6 @ 0x006b4de6 ====

void Catch_006b4de6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006b4df0 @ 0x006b4df0 ====

void FUN_006b4df0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c790;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x2c);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006b4e5f @ 0x006b4e5f ====

void Catch_006b4e5f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006b4e80 @ 0x006b4e80 ====

void FUN_006b4e80(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c7a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0xe4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x38) = 1;
  *(undefined1 *)((int)puVar1 + 0xe1) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@006b4f13 @ 0x006b4f13 ====

void Catch_006b4f13(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_006b4f30 @ 0x006b4f30 ====

void FUN_006b4f30(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c7b0;
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


// ==== Catch@006b4f96 @ 0x006b4f96 ====

void Catch_006b4f96(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006b4fa0 @ 0x006b4fa0 ====

void FUN_006b4fa0(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0xe1) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0xe1) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_006b5010 @ 0x006b5010 ====

void FUN_006b5010(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_006b4d80(param_1,param_2,param_3);
  return;
}


// ==== FUN_006b5030 @ 0x006b5030 ====

int FUN_006b5030(int param_1,int param_2,undefined4 param_3)

{
  FUN_006b4f30(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_006b5060 @ 0x006b5060 ====

void FUN_006b5060(uint param_1)

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
  
  if (0x71c71c7U - *(int *)(in_ECX + 8) < param_1) {
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


// ==== FUN_006b50f0 @ 0x006b50f0 ====

void FUN_006b50f0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0098c7c0;
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
      uVar5 = FUN_006b5010(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_006b5030(uVar5,param_2,&local_18);
      FUN_006b5010(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_006b4d80(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_006b5030(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_006b4d80(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006b5251 @ 0x006b5251 ====

void Catch_006b5251(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_006b5340 @ 0x006b5340 ====

void * FUN_006b5340(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c7d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x2c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_008736f0(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@006b53ad @ 0x006b53ad ====

void Catch_006b53ad(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006b53d0 @ 0x006b53d0 ====

void FUN_006b53d0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c7e0;
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
    uVar2 = FUN_006b5030(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006b5464 @ 0x006b5464 ====

void Catch_006b5464(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006b5480 @ 0x006b5480 ====

void FUN_006b5480(uint param_1,undefined1 param_2)

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
    FUN_006b50f0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_006b54f0 @ 0x006b54f0 ====

/* WARNING: Removing unreachable block (ram,0x006b550b) */
/* WARNING: Removing unreachable block (ram,0x006b5510) */
/* WARNING: Removing unreachable block (ram,0x006b551e) */

void FUN_006b54f0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_006b50f0(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_006b5540 @ 0x006b5540 ====

void FUN_006b5540(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *in_ECX = *param_1;
  *(undefined1 *)(in_ECX + 1) = *(undefined1 *)(param_1 + 1);
  *(undefined1 *)((int)in_ECX + 5) = *(undefined1 *)((int)param_1 + 5);
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  FUN_00401660(param_1 + 5,0,0xffffffff);
  in_ECX[0x12] = 0xf;
  in_ECX[0x11] = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  FUN_00401660(param_1 + 0xc,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x13) = *(undefined1 *)(param_1 + 0x13);
  FUN_00406600(param_1 + 0x14);
  in_ECX[0x18] = param_1[0x18];
  in_ECX[0x19] = param_1[0x19];
  puVar2 = param_1 + 0x1a;
  puVar3 = in_ECX + 0x1a;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = param_1 + 0x26;
  puVar3 = in_ECX + 0x26;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)(in_ECX + 0x32) = *(undefined1 *)(param_1 + 0x32);
  in_ECX[0x33] = param_1[0x33];
  return;
}


// ==== FUN_006b5610 @ 0x006b5610 ====

void FUN_006b5610(void)

{
  undefined4 *in_ECX;
  
  in_ECX[10] = 0;
  in_ECX[0xb] = 0xf;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[0x12] = 0xf;
  in_ECX[0x11] = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  *in_ECX = 0xffffffff;
  in_ECX[0x33] = 0xffffffff;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[0x19] = 0;
  in_ECX[3] = 0xffffff;
  in_ECX[4] = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)(in_ECX + 0x32) = 0;
  *(undefined1 *)(in_ECX + 0x13) = 0;
  return;
}


// ==== FUN_006b56f0 @ 0x006b56f0 ====

void FUN_006b56f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x54),*(undefined4 *)(in_ECX + 0x58),in_ECX + 0x50);
    _free(*(void **)(in_ECX + 0x54));
    return;
  }
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  if (0xf < *(uint *)(in_ECX + 0x48)) {
    _free(*(void **)(in_ECX + 0x34));
    return;
  }
  *(undefined4 *)(in_ECX + 0x48) = 0xf;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined1 *)(in_ECX + 0x34) = 0;
  if (*(uint *)(in_ECX + 0x2c) < 0x10) {
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0xf;
    *(undefined1 *)(in_ECX + 0x18) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_006b5770 @ 0x006b5770 ====

/* WARNING: Removing unreachable block (ram,0x006b588b) */
/* WARNING: Removing unreachable block (ram,0x006b5a7f) */

void FUN_006b5770(int *param_1,int param_2)

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
      FUN_006b5480(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
LAB_006b59d4:
        if ((uint)piVar11[7] <= uVar9) {
          bVar15 = false;
          goto LAB_006b59e4;
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
        if (iVar6 == 0) goto LAB_006b59d4;
LAB_006b59e4:
        if (!bVar15) {
          if (*(uint *)(param_2 + 0x18) < 0x10) {
            pbVar14 = (byte *)(param_2 + 4);
          }
          else {
            pbVar14 = *(byte **)(param_2 + 4);
          }
          uVar9 = piVar11[7];
          if (uVar9 == 0) goto LAB_006b5aac;
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
          goto code_r0x006b5a9f;
        }
      }
    } while (piVar11 != *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  goto LAB_006b59f5;
  while( true ) {
    uVar7 = uVar7 - 1;
    bVar15 = *pbVar13 < *pbVar14;
    bVar16 = *pbVar13 == *pbVar14;
    pbVar13 = pbVar13 + 1;
    pbVar14 = pbVar14 + 1;
    if (!bVar16) break;
code_r0x006b5a9f:
    if (uVar7 == 0) break;
  }
  if (!bVar16) {
    iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
  }
  bVar15 = iVar6 < 0;
  if (iVar6 == 0) {
LAB_006b5aac:
    if (uVar5 <= uVar9) {
      bVar15 = false;
      goto LAB_006b5abd;
    }
  }
  else {
LAB_006b5abd:
    if (!bVar15) {
      *param_1 = (int)piVar11;
      *(undefined1 *)(param_1 + 1) = 0;
      return;
    }
  }
  piVar11 = (int *)*piVar11;
LAB_006b59f5:
  iVar6 = FUN_006b5340(piVar11,piVar11[1],param_2);
  FUN_006b5060(1);
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


// ==== FUN_006b5ae0 @ 0x006b5ae0 ====

void FUN_006b5ae0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  FUN_006b5540(param_4 + 1);
  *(undefined1 *)(in_ECX + 0x38) = param_5;
  *(undefined1 *)((int)in_ECX + 0xe1) = 0;
  return;
}


// ==== FUN_006b5b30 @ 0x006b5b30 ====

void * FUN_006b5b30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c7f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0xe4);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_006b5ae0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@006b5ba8 @ 0x006b5ba8 ====

void Catch_006b5ba8(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006b5bc0 @ 0x006b5bc0 ====

void FUN_006b5bc0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x13521cd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_006b5b30(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0xe0);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0xe0) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x38] == '\0') {
LAB_006b5cc8:
        *(undefined1 *)(*piVar5 + 0xe0) = 1;
        *(undefined1 *)(piVar6 + 0x38) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0xe0) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_006b4d20(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0xe0) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0xe0) = 0;
        FUN_006b4bf0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x38] == '\0') goto LAB_006b5cc8;
      if (piVar7 == (int *)*piVar2) {
        FUN_006b4bf0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0xe0) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0xe0) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0xe1) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0xe0);
  } while( true );
}


// ==== FUN_006b5dd0 @ 0x006b5dd0 ====

void FUN_006b5dd0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0xe1) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0xe1) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_006b5bc0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_006b4cb0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_006b5bc0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_006b5e90 @ 0x006b5e90 ====

/* WARNING: Removing unreachable block (ram,0x006b5fc2) */
/* WARNING: Removing unreachable block (ram,0x006b5fd2) */
/* WARNING: Removing unreachable block (ram,0x006b5fde) */
/* WARNING: Removing unreachable block (ram,0x006b5fe1) */
/* WARNING: Removing unreachable block (ram,0x006b5fce) */
/* WARNING: Removing unreachable block (ram,0x006b5fef) */
/* WARNING: Removing unreachable block (ram,0x006b5ffc) */
/* WARNING: Removing unreachable block (ram,0x006b6007) */
/* WARNING: Removing unreachable block (ram,0x006b6003) */
/* WARNING: Removing unreachable block (ram,0x006b5ff7) */
/* WARNING: Removing unreachable block (ram,0x006b600a) */

void FUN_006b5e90(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0xe1) != '\0') {
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
  FUN_006b4c50();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0xe1) == '\0') {
    if (*(char *)(param_2[2] + 0xe1) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0xe1) == '\0') {
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
    if (*(char *)((int)piVar6 + 0xe1) == '\0') {
      piVar3 = (int *)FUN_006b4bd0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0xe1) == '\0') {
      uVar4 = FUN_006b4bb0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x38] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x38] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x38] == '\0') {
            *(undefined1 *)(piVar5 + 0x38) = 1;
            *(undefined1 *)(piVar3 + 0x38) = 0;
            FUN_006b4d20(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0xe1) == '\0') {
            if ((*(char *)(*piVar5 + 0xe0) == '\x01') && (*(char *)(piVar5[2] + 0xe0) == '\x01'))
            goto LAB_006b613b;
            if (*(char *)(piVar5[2] + 0xe0) == '\x01') {
              *(undefined1 *)(*piVar5 + 0xe0) = 1;
              *(undefined1 *)(piVar5 + 0x38) = 0;
              FUN_006b4bf0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x38) = (char)piVar3[0x38];
            *(undefined1 *)(piVar3 + 0x38) = 1;
            *(undefined1 *)(piVar5[2] + 0xe0) = 1;
            FUN_006b4d20(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x38] == '\0') {
            *(undefined1 *)(piVar5 + 0x38) = 1;
            *(undefined1 *)(piVar3 + 0x38) = 0;
            FUN_006b4bf0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0xe1) == '\0') {
            if ((*(char *)(piVar5[2] + 0xe0) != '\x01') || (*(char *)(*piVar5 + 0xe0) != '\x01')) {
              if (*(char *)(*piVar5 + 0xe0) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0xe0) = 1;
                *(undefined1 *)(piVar5 + 0x38) = 0;
                FUN_006b4d20(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x38) = (char)piVar3[0x38];
              *(undefined1 *)(piVar3 + 0x38) = 1;
              *(undefined1 *)(*piVar5 + 0xe0) = 1;
              FUN_006b4bf0(piVar3);
              break;
            }
LAB_006b613b:
            *(undefined1 *)(piVar5 + 0x38) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x38) = 1;
  }
  FUN_006b56f0();
  _free(param_2);
  return;
}


// ==== FUN_006b61e0 @ 0x006b61e0 ====

void FUN_006b61e0(void *param_1)

{
  if (*(char *)((int)param_1 + 0xe1) == '\0') {
    FUN_006b61e0(*(undefined4 *)((int)param_1 + 8));
    FUN_006b56f0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_006b6230 @ 0x006b6230 ====

void FUN_006b6230(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = param_3;
  piVar1 = *(int **)(in_ECX + 4);
  if ((param_2 == (int *)*piVar1) && (param_3 == piVar1)) {
    FUN_006b61e0(piVar1[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (param_2 != piVar2) {
    FUN_006b4c50();
    FUN_006b5e90(&param_3,param_2);
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_006b62b0 @ 0x006b62b0 ====

void FUN_006b62b0(byte param_1)

{
  void *in_ECX;
  
  FUN_006b4810();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006b62d0 @ 0x006b62d0 ====

void FUN_006b62d0(void)

{
  return;
}


// ==== FUN_006b62e0 @ 0x006b62e0 ====

undefined1 FUN_006b62e0(void)

{
  return 0;
}


// ==== FUN_006b62f0 @ 0x006b62f0 ====

undefined1 FUN_006b62f0(void)

{
  return 0;
}


// ==== FUN_006b6300 @ 0x006b6300 ====

void FUN_006b6300(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e10a0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006b6320 @ 0x006b6320 ====

void FUN_006b6320(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  char *pcVar4;
  char *pcVar5;
  undefined4 *puStack_b8;
  undefined4 local_a4;
  uint local_a0;
  undefined1 auStack_9c [8];
  undefined4 uStack_94;
  uint uStack_90;
  undefined4 auStack_8c [7];
  undefined1 auStack_70 [4];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 auStack_44 [4];
  undefined1 uStack_40;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_24;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  puStack_b8 = &local_a4;
  local_a0 = 0;
  local_a4 = (void *)0x0;
  (**(code **)(*DAT_00b5ad1c + 0x88))(&local_a0);
  if ((*(int *)(in_ECX + 8) != unaff_EBX) || (*(int *)(in_ECX + 0xc) != unaff_EBP)) {
    auStack_8c[0] = 0xf;
    uStack_90 = 0;
    local_a0 = local_a0 & 0xffffff00;
    FUN_00401740(s_textbox_009e101c,7);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_a4);
    if (0xf < uStack_90) {
      _free(local_a4);
      return;
    }
    uStack_90 = 0xf;
    uStack_94 = 0;
    local_a4 = (void *)((uint)local_a4 & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x30))();
      if (iVar2 != 0) {
        *(undefined4 *)(in_ECX + 0xc) = unaff_ESI;
        *(int *)(in_ECX + 8) = unaff_EBP;
        uStack_6c = 0;
        uStack_68 = 0;
        uStack_64 = 0;
        uStack_2c = 0xf;
        uStack_30 = 0;
        uStack_40 = 0;
        uStack_10 = 0xf;
        uStack_14 = 0;
        uStack_24 = 0;
        FUN_00401740(s_<TIME>_009e1024,6);
        FUN_00401830(s__02d__02d_009e102c);
        uVar3 = FUN_00404230(auStack_9c + -0xc);
        FUN_00401660(uVar3,0,0xffffffff);
        if (0xf < uStack_90) {
          _free(local_a4);
          return;
        }
        FUN_004e6c20(auStack_44);
        (**(code **)(*DAT_00b5a794 + 8))(auStack_8c,0,0x6e00ff,auStack_70);
        if (*(uint *)(in_ECX + 8) < 5) {
          uVar3 = FUN_004022a0(auStack_70,s_<color_0xFFB400>_009e1044,auStack_9c,s_<_color>_009e1038
                              );
          uVar3 = FUN_00402220(&puStack_b8,uVar3);
          FUN_00401660(uVar3,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        if (*(uint *)(in_ECX + 8) < 10) {
          pcVar5 = s_<_color>_009e1058;
          pcVar4 = s_<color_0xFF0000>_009e1064;
        }
        else {
          pcVar5 = s_<_color>_009e1078;
          pcVar4 = s_<color_0xFFFFFF>_009e1084;
        }
        uVar3 = FUN_004022a0(&puStack_b8,pcVar4,auStack_9c,pcVar5);
        uVar3 = FUN_00402220(auStack_70,uVar3);
        FUN_00401660(uVar3,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  return;
}


// ==== FUN_006b6590 @ 0x006b6590 ====

void FUN_006b6590(void)

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
  FUN_00401740(s_UI_Game2_ui_portaltimewnd_txt_009e0ffc,0x1d);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006b6320();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006b6610 @ 0x006b6610 ====

uint FUN_006b6610(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_006b6320();
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006b6630 @ 0x006b6630 ====

void FUN_006b6630(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e10a0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  FUN_006b6590();
  return;
}


// ==== FUN_006b6650 @ 0x006b6650 ====

undefined4 FUN_006b6650(void)

{
  return 0x43;
}


// ==== FUN_006b6660 @ 0x006b6660 ====

void FUN_006b6660(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e10a0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006b66a0 @ 0x006b66a0 ====

void FUN_006b66a0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_006b66b0 @ 0x006b66b0 ====

undefined4 FUN_006b66b0(void)

{
  undefined2 uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined2 *puVar6;
  undefined4 uVar7;
  
  uVar3 = (**(code **)(*DAT_00b5adb8 + 0x24))();
  if ((short)uVar3 != 0) {
    iVar4 = (**(code **)(*DAT_00b5adc0 + 0x1c))();
    if ((iVar4 == 0) || (iVar4 == 2)) {
      cVar2 = (**(code **)(*DAT_00b5ac1c + 0x24))();
      if (cVar2 != '\0') {
        uVar3 = (**(code **)(*DAT_00b5adb8 + 0x20))();
        uVar3 = (**(code **)(*DAT_00b5acf8 + 4))(uVar3);
        return uVar3;
      }
    }
    else {
      iVar4 = (**(code **)(*DAT_00b5ac1c + 0x14))();
      if (iVar4 != 0) {
        piVar5 = (int *)(**(code **)(**(int **)(iVar4 + 0x48) + 0x24))();
        puVar6 = (undefined2 *)(**(code **)(*piVar5 + 8))();
        uVar1 = *puVar6;
        uVar7 = (**(code **)(*DAT_00b5ac1c + 0x38))();
        piVar5 = (int *)(**(code **)(*DAT_00b5ab1c + 8))(uVar7);
        if (piVar5 == (int *)0x0) {
          return 0xffffffff;
        }
        iVar4 = (**(code **)(*piVar5 + 4))(uVar1,uVar3);
        return *(undefined4 *)(iVar4 + 0x14);
      }
    }
  }
  return 0xffffffff;
}


// ==== FUN_006b6760 @ 0x006b6760 ====

void FUN_006b6760(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5af00 + 0x24))();
  if (cVar1 == '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x006b6777. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5af00 + 0x1c))();
  return;
}


// ==== FUN_006b6780 @ 0x006b6780 ====

void FUN_006b6780(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  cVar2 = (**(code **)(*DAT_00b5adb8 + 0x14))();
  if (cVar2 != '\0') {
    iVar1 = *DAT_00b5af00;
    uVar3 = (**(code **)(*DAT_00b5adb8 + 0x20))();
    (**(code **)(iVar1 + 0xc))(uVar3);
  }
  return;
}


// ==== FUN_006b67b0 @ 0x006b67b0 ====

void FUN_006b67b0(void)

{
  char cVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e12e8;
  cVar1 = (**(code **)(*DAT_00b5af00 + 0x24))();
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5af00 + 0x1c))();
  }
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006b67f0 @ 0x006b67f0 ====

undefined4 FUN_006b67f0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_showpcpop_009e12c0,0xd);
    if (iVar2 == 0) {
      FUN_006b6780();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_closepcpop_009e12d0);
    if (cVar1 != '\0') {
      FUN_006b6760();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006b6860 @ 0x006b6860 ====

void FUN_006b6860(void *param_1)

{
  int *piVar1;
  int in_ECX;
  void *unaff_retaddr;
  uint in_stack_00000014;
  uint in_stack_00000018;
  undefined4 in_stack_0000001c;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&param_1);
  if (piVar1 == (int *)0x0) {
    if (0xf < in_stack_00000018) {
      _free(param_1);
      return;
    }
  }
  else {
    (**(code **)(*piVar1 + 0x24))(in_stack_0000001c);
    if (0xf < in_stack_00000014) {
      _free(unaff_retaddr);
      return;
    }
  }
  return;
}


// ==== FUN_006b68b0 @ 0x006b68b0 ====

void FUN_006b68b0(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  void *local_54;
  undefined1 local_50;
  undefined4 uStack_44;
  uint local_40;
  void *local_3c [5];
  uint uStack_28;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_3c[0] = (void *)0xf;
  local_40 = 0;
  local_50 = 0;
  FUN_00401740(s_lbl_name_009e1128,8);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_54);
  if (0xf < local_40) {
    _free(local_54);
    return;
  }
  local_40 = 0xf;
  uStack_44 = 0;
  local_54 = (void *)((uint)local_54 & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pComposite_009e1134,10);
    FUN_00406880(auStack_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 != 0) {
    uVar4 = FUN_006b66b0();
    (**(code **)(*DAT_00b5adb8 + 0x1c))(local_3c);
    FUN_00559170(uVar4);
    FUN_0055a260(&local_40);
    if (uStack_28 < 0x10) {
      return;
    }
    _free(local_3c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_pLabel_009e1140,6);
  FUN_00406880(auStack_20);
  if (uStack_8 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006b69f0 @ 0x006b69f0 ====

void FUN_006b69f0(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
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
  FUN_00401740(s_lbl_name_009e1148,8);
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
    FUN_00401740(s_pComposite_009e1154,10);
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
  if (iVar3 != 0) {
    FUN_00559170(unaff_retaddr);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_pLabel_009e1160,6);
  FUN_00406880(&local_20);
  if (uStack_8 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006b6af0 @ 0x006b6af0 ====

void FUN_006b6af0(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  cVar1 = (**(code **)(*DAT_00b5add0 + 0x3c))(uVar2);
  if (cVar1 != '\0') {
    uVar2 = (**(code **)(*DAT_00b5adc0 + 0x18))();
    FUN_00401740(s_pan_ownerBg_009e1168,0xb);
    uVar3 = 0x6b6b4c;
    FUN_006b6860();
    uVar2 = (**(code **)(*DAT_00b5ac98 + 0x8c))(uVar2);
    switch(uVar2) {
    case 0:
    case 4:
      FUN_00401830(s_pan_owner5_009e1174);
      FUN_006b6860(uVar3);
      FUN_00401830(s_pan_owner4_009e1180);
      FUN_006b6860(uVar3);
      FUN_00401830(s_pan_owner3_009e118c);
      FUN_006b6860(uVar3);
      FUN_006b69f0(0xff64caff);
      return;
    case 1:
      FUN_00401830(s_pan_owner2_009e11bc);
      FUN_006b6860(uVar3);
      FUN_00401830(s_pan_owner5_009e11c8);
      FUN_006b6860(uVar3);
      FUN_00401830(s_pan_owner4_009e11d4);
      FUN_006b6860(uVar3);
      FUN_006b69f0(0xfffefe00);
      break;
    case 2:
    case 3:
      FUN_00401830(s_pan_owner4_009e1198);
      FUN_006b6860(uVar3);
      FUN_00401830(s_pan_owner5_009e11a4);
      FUN_006b6860(uVar3);
      FUN_00401830(s_pan_owner3_009e11b0);
      FUN_006b6860(uVar3);
      FUN_006b69f0(0xffff8080);
      return;
    }
  }
  return;
}


// ==== FUN_006b6c90 @ 0x006b6c90 ====

void FUN_006b6c90(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_showpcpop_009e124c,0xd);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(0);
  }
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  cVar1 = (**(code **)(*DAT_00b5adb8 + 0x14))();
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5af00 + 0x24))();
    FUN_00401740(s_pan_showpcpop_009e125c,0xd);
    FUN_006b6860();
    FUN_00401740(s_btn_showpcpop_009e126c,0xd);
    FUN_006b6860();
    FUN_00401740(s_btn_closepcpop_009e127c,0xe);
    FUN_006b6860();
  }
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 != '\0') {
    FUN_00401740(s_btn_showpcpop_009e128c,0xd);
    FUN_006b6860();
    FUN_00401740(s_btn_closepcpop_009e129c,0xe);
    FUN_006b6860();
  }
  return;
}


// ==== FUN_006b6de0 @ 0x006b6de0 ====

/* WARNING: Removing unreachable block (ram,0x006b6e25) */

void FUN_006b6de0(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint uStack_c0;
  undefined2 uStack_bc;
  undefined1 uStack_ba;
  undefined1 uStack_b9;
  undefined4 uStack_b8;
  int iVar5;
  uint uStack_8c;
  void *pvStack_4c;
  uint uStack_38;
  undefined1 uStack_34;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  byte bStack_10;
  char cStack_4;
  
  FUN_00401740();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  uStack_24 = 0xf;
  uStack_28 = 0;
  uStack_38 = uStack_38 & 0xffffff00;
  uStack_b8 = 0x6b6e60;
  FUN_00401740();
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < uStack_28) {
    uStack_b8 = 0x6b6e83;
    _free((void *)0xf);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  if (((piVar1 != (int *)0x0) && (piVar2 != (int *)0x0)) && (cStack_4 != '\0')) {
    uStack_b8 = 0x6b6ebe;
    (**(code **)(*piVar1 + 0x24))();
    uStack_b8 = 0x6b6ec5;
    (**(code **)(*piVar1 + 0x20))();
    uStack_b8 = 1;
    _uStack_bc = 0x6b6ece;
    (**(code **)(*piVar2 + 0x24))();
    _uStack_bc = 0x6b6ed5;
    (**(code **)(*piVar2 + 0x20))();
    _uStack_bc = 1;
    uStack_c0 = 0x6b6ede;
    (**(code **)(*piVar1 + 0x24))();
    uStack_c0 = 0x6b6ee5;
    (**(code **)(*piVar1 + 0x30))();
    uStack_c0 = bStack_10 | 0x3e70000;
    uVar4 = 0;
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
    uStack_20 = 0xf;
    uStack_24 = 0;
    uStack_34 = 0;
    FUN_00401660(uVar3,0,0xffffffff);
    FUN_005569f0(&uStack_38,0);
    (**(code **)(*DAT_00b5a688 + 0x34))(2,&uStack_38,(int)register0x00000010 + -0xb4);
    _uStack_bc = CONCAT12(1,uStack_bc);
    uStack_b8 = 0;
    iVar5 = 0;
    uVar3 = (**(code **)(*piVar1 + 0x10))();
    FUN_004fed70(uVar3);
    uStack_c0 = uVar4 / (uint)-iVar5 + 1;
    (**(code **)(*piVar2 + 0x24))(1);
    uVar3 = (**(code **)(*piVar2 + 0x10))();
    FUN_004fed70(uVar3);
    (**(code **)(*piVar2 + 0xc))(&uStack_c0);
    if (0xf < uStack_8c) {
      _free((void *)0x0);
      return;
    }
    if (0xf < uStack_38) {
      _free(pvStack_4c);
      return;
    }
  }
  return;
}


// ==== FUN_006b7060 @ 0x006b7060 ====

void FUN_006b7060(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  float10 fVar8;
  char *pcVar9;
  uint uVar10;
  undefined1 auStack_26 [2];
  undefined1 auStack_24 [4];
  void *pvStack_20;
  void *apvStack_1c [3];
  undefined4 uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  iVar7 = 0;
  if ((DAT_00b5a97c != (int *)0x0) && (cVar1 = (**(code **)(*DAT_00b5ae58 + 8))(), cVar1 == '\0')) {
    iVar3 = (**(code **)(*DAT_00b5adc0 + 0x1c))();
    pcVar9 = s_pan_ownerBg_009e11e0;
    FUN_00401740(s_pan_ownerBg_009e11e0,0xb);
    uVar10 = 0x6b70c5;
    FUN_006b6860();
    if (iVar3 == 0) {
      FUN_006b6af0();
      return;
    }
    if (iVar3 == 2) {
      FUN_006b6af0();
    }
    FUN_00401830(s_processbar_hp_009e11ec);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_1c);
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
    (**(code **)(*piVar4 + 0x24))(1);
    iVar3 = (**(code **)(*piVar4 + 0x30))();
    if (iVar3 == 0) {
      FUN_00401830(s_pProcessBar_009e11fc);
      FUN_00406880(auStack_24);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    fVar8 = (float10)(**(code **)(*DAT_00b5adb8 + 0x18))();
    FUN_00587ba0((float)(fVar8 * (float10)DAT_0099de78));
    cVar1 = (**(code **)(*DAT_00b5adc0 + 0x20))();
    iVar3 = (**(code **)(*DAT_00b5adc0 + 0x24))();
    iVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
    if ((((iVar3 == iVar5) || (iVar5 = (**(code **)(*DAT_00b5af10 + 0xc))(), iVar3 == iVar5)) ||
        (cVar2 = (**(code **)(*DAT_00b5a7b8 + 0x3c))(iVar3), cVar2 != '\0')) ||
       (cVar2 = (**(code **)(*DAT_00b5a7b8 + 0x40))(iVar3), cVar2 != '\0')) {
      if (cVar1 == '\x01') {
        FUN_00401830(s_pan_owner2_009e1208);
        FUN_006b6860(pcVar9,uVar10);
        FUN_006b6de0(2);
        *(undefined1 *)(in_ECX + 0x10) = 2;
      }
      else if (cVar1 == '\x02') {
        FUN_00401830(s_pan_owner1_009e1214);
        FUN_006b6860(pcVar9,uVar10);
        FUN_006b6de0(1);
        *(undefined1 *)(in_ECX + 0x10) = 1;
      }
    }
    else if (cVar1 == '\x01') {
      FUN_00401830(s_pan_owner3_009e1220);
      FUN_006b6860(pcVar9,uVar10);
      FUN_006b6de0(3);
      *(undefined1 *)(in_ECX + 0x10) = 3;
    }
    else if (cVar1 == '\x02') {
      FUN_00401830(s_pan_owner4_009e122c);
      FUN_006b6860(pcVar9,uVar10);
      FUN_006b6de0(4);
      *(undefined1 *)(in_ECX + 0x10) = 4;
    }
    do {
      uVar10 = uVar10 & 0xffffff00;
      FUN_00401740(s_pan_tp_status__d_009e1238,0x10);
      uVar6 = FUN_00404230(auStack_24,pcVar9,uVar10);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar6);
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
      uStack_c = 0xf;
      uStack_10 = 0;
      pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
      if (piVar4 != (int *)0x0) {
        cVar1 = (**(code **)(*DAT_00b5adc0 + 0x28))(iVar7);
        if (cVar1 == '\0') {
          (**(code **)(*piVar4 + 0x24))(0);
        }
        else {
          iVar3 = (**(code **)(*piVar4 + 0x30))();
          if (iVar3 != 0) {
            FUN_00587d40(auStack_26 + -10);
            (**(code **)(*piVar4 + 0x24))(1);
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 8);
  }
  return;
}


// ==== FUN_006b73b0 @ 0x006b73b0 ====

undefined4 FUN_006b73b0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    FUN_006b7060();
  }
  else {
    if (iVar1 == 0x70190002) {
      FUN_006b68b0();
      FUN_006b7060();
      FUN_006b6c90();
      return 1;
    }
    if (iVar1 == 0x70190003) {
      FUN_006b7060();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006b7410 @ 0x006b7410 ====

void FUN_006b7410(void)

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
  FUN_00401740(s_UI_Game2_ui_targetpop_txt_009e110c,0x19);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006b68b0();
    FUN_006b7060();
    FUN_006b6c90();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006b74a0 @ 0x006b74a0 ====

void FUN_006b74a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e12e8;
  in_ECX[1] = 0;
  FUN_006b7410();
  return;
}


// ==== FUN_006b74c0 @ 0x006b74c0 ====

void FUN_006b74c0(void)

{
  char cVar1;
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e12e8;
  cVar1 = (**(code **)(*DAT_00b5af00 + 0x24))();
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5af00 + 0x1c))();
  }
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006b7510 @ 0x006b7510 ====

void FUN_006b7510(void)

{
  return;
}


// ==== FUN_006b7530 @ 0x006b7530 ====

undefined4 FUN_006b7530(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_trade_009e13cc,9);
    if (iVar2 == 0) {
      (**(code **)(*DAT_00b5af00 + 4))(0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_whisper_009e13d8);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5af00 + 4))(2);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_friend_009e13e4);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5af00 + 4))(3);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_party_009e13f0);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5af00 + 4))(1);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_follow_009e13fc);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5af00 + 4))(4);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_inviteguild_009e1408);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5af00 + 4))(5);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_pvp_009e1418);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5af00 + 4))(6);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_recall_009e1420);
    if (cVar1 != '\0') {
      iVar2 = *DAT_00b5b180;
      uVar3 = (**(code **)(*DAT_00b5adc0 + 0x18))();
      (**(code **)(iVar2 + 4))(uVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006b76d0 @ 0x006b76d0 ====

undefined4 FUN_006b76d0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70004) {
    iVar1 = FUN_00403620(0,param_1[7],s_follow_009e142c,6);
    if (iVar1 == 0) {
      (**(code **)(*DAT_00b5af00 + 4))(4);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006b7720 @ 0x006b7720 ====

/* WARNING: Removing unreachable block (ram,0x006b7774) */

void FUN_006b7720(void)

{
  undefined4 *in_ECX;
  undefined1 auStack_1a [26];
  
  *in_ECX = &PTR_FUN_009e143c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  FUN_00401740(s_follow_009e135c,6);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_1a + -6);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006b7790 @ 0x006b7790 ====

/* WARNING: Removing unreachable block (ram,0x006b77dd) */

void FUN_006b7790(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_1a [26];
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar2 == (int *)0x0) {
    FUN_00401740(s_pComposite____NULL_009e13b8,0x12);
    FUN_00406880(auStack_1a + -6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  (**(code **)(*piVar2 + 0x24))(param_1);
  return;
}


// ==== FUN_006b7800 @ 0x006b7800 ====

void FUN_006b7800(void)

{
  int iVar1;
  int *piVar2;
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
  FUN_00401740(s_UI_Game2_ui_pcpopwnd_txt_009e1364,0x18);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  iVar1 = (**(code **)(*DAT_00b5adc0 + 0x1c))();
  if (iVar1 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    FUN_00401740(s_pan_pcpop_009e1380,9);
    FUN_006b7790(local_1c + -0xc,1);
    if (0xf < uStack_10) {
      _free((void *)((unaff_EBP >> 8) << 8));
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    FUN_00401740(s_pan_sentrypop_009e138c,0xd);
    FUN_006b7790(local_1c + -0xc,0);
    if (0xf < uStack_10) {
      _free((void *)((unaff_EBP >> 8) << 8));
      return;
    }
  }
  else {
    iVar1 = (**(code **)(*DAT_00b5adc0 + 0x1c))();
    if (iVar1 == 6) {
      uStack_10 = 0xf;
      uStack_14 = 0;
      FUN_00401740(s_pan_pcpop_009e139c,9);
      FUN_006b7790(local_1c + -0xc,0);
      if (0xf < uStack_10) {
        _free((void *)((unaff_EBP >> 8) << 8));
        return;
      }
      uStack_10 = 0xf;
      uStack_14 = 0;
      FUN_00401740(s_pan_sentrypop_009e13a8,0xd);
      FUN_006b7790(local_1c + -0xc,1);
      if (0xf < uStack_10) {
        _free((void *)((unaff_EBP >> 8) << 8));
        return;
      }
    }
  }
  return;
}


// ==== FUN_006b79a0 @ 0x006b79a0 ====

void FUN_006b79a0(void)

{
  undefined4 *in_ECX;
  void *unaff_ESI;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009e143c;
  FUN_006b7800();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_follow_009e1354,6);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_1c,0);
  if (uStack_c < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_006b7a10 @ 0x006b7a10 ====

void FUN_006b7a10(byte param_1)

{
  void *in_ECX;
  
  FUN_006b7720();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006b7a30 @ 0x006b7a30 ====

void FUN_006b7a30(void)

{
  return;
}


// ==== FUN_006b7ab0 @ 0x006b7ab0 ====

undefined1 FUN_006b7ab0(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5b114 + 0x14))();
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(*DAT_00b5b114 + 0x3c))();
  FUN_004dd240(0xf,0,4,0,0);
  return 1;
}


// ==== FUN_006b7ae0 @ 0x006b7ae0 ====

undefined4 FUN_006b7ae0(int param_1,short param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar1) {
    return 0;
  }
  if ((param_3 == 1) && (param_2 == 1)) {
    iVar1 = *DAT_00b5b114;
    uVar2 = thunk_FUN_00796fb0(param_4);
    (**(code **)(iVar1 + 0x38))(uVar2);
  }
  return 1;
}


// ==== FUN_006b7b30 @ 0x006b7b30 ====

undefined4 FUN_006b7b30(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int *piVar3;
  int in_ECX;
  undefined2 uStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a78c + 0x48))();
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x2c))();
    uVar2 = *(undefined1 *)(in_ECX + 0x28);
    uVar1 = FUN_00802534();
    uStack_4 = CONCAT11(uVar1,uVar2);
    uVar2 = FUN_00802534();
    (**(code **)(*DAT_00b5b114 + 0x30))(CONCAT12(uVar2,uStack_4));
  }
  return 1;
}


// ==== FUN_006b7c30 @ 0x006b7c30 ====

void FUN_006b7c30(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = &PTR_FUN_009e1568;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  iVar1 = 2;
  puVar2 = in_ECX + 0xb;
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


// ==== FUN_006b7c80 @ 0x006b7c80 ====

void FUN_006b7c80(void)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  uint *puVar4;
  int *piVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined4 unaff_EBX;
  char *pcVar7;
  undefined1 auStack_2a [2];
  uint uStack_28;
  void *local_24;
  void *pvStack_20;
  uint uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  (**(code **)(*DAT_00b5b114 + 0x18))(&local_24);
  if (local_24 != (void *)0x0) {
    uStack_14 = 0xffffffff;
    do {
      uStack_1c = uStack_28 >> 8 & 0xff;
      iVar3 = (uStack_28 & 0xff) * 0x10;
      iVar1 = *(int *)(iVar3 + 0xc + in_ECX);
      uStack_18 = uStack_28 >> 0x10 & 0xff;
      iVar3 = iVar3 + 8 + in_ECX;
      pvStack_20 = local_24;
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(iVar3 + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(iVar3 + 8) - iVar1 >> 4))) {
        FUN_00680c50(*(undefined4 *)(iVar3 + 8),1,&pvStack_20);
      }
      else {
        iVar1 = *(int *)(iVar3 + 8);
        FUN_00680b80(iVar1,1,&pvStack_20,iVar3,unaff_EBX);
        *(int *)(iVar3 + 8) = iVar1 + 0x10;
      }
      puVar4 = (uint *)(**(code **)(*DAT_00b5b114 + 0x1c))(auStack_2a + -6);
      uStack_28 = *puVar4;
      local_24 = (void *)puVar4[1];
    } while (local_24 != (void *)0x0);
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = uStack_1c & 0xffffff00;
  FUN_00401740(s_slotitem_009e14d0,8);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  (**(code **)(*piVar5 + 0x30))();
  uVar2 = (**(code **)(*DAT_00b5b114 + 0x24))();
  *(undefined1 *)(in_ECX + 0x28) = uVar2;
  FUN_00401740(s_btn_tab_d_009e14dc,9);
  uVar6 = FUN_00404230(&local_24);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar6);
  (**(code **)(*piVar5 + 0x30))();
  FUN_00558730(1);
  if (0xf < uStack_10) {
    _free(local_24);
    return;
  }
  if (*(char *)(in_ECX + 0x28) == '\0') {
    pcVar7 = s_btn_tab1_009e14e8;
  }
  else {
    if (*(char *)(in_ECX + 0x28) != '\x01') goto LAB_006b7e71;
    pcVar7 = s_btn_tab0_009e14f4;
  }
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  uStack_14 = 0;
  uStack_10 = 0xf;
  FUN_00401740(pcVar7,8);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_28);
  (**(code **)(*piVar5 + 0x30))();
  FUN_00558730(0);
  if (0xf < uStack_10) {
    _free(local_24);
    return;
  }
LAB_006b7e71:
  FUN_005817e0((uint)*(byte *)(in_ECX + 0x28) * 0x10 + 8 + in_ECX,0);
  return;
}


// ==== FUN_006b7e90 @ 0x006b7e90 ====

undefined4 FUN_006b7e90(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  int in_ECX;
  char *pcVar7;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar4 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009e1500,8);
      if (iVar4 == 0) {
        (**(code **)(*DAT_00b5b114 + 0x3c))();
        FUN_004dd240(0xf,0,4,0,0);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_tab0_009e150c);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5b114 + 0x28))(0);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_tab1_009e1518);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5b114 + 0x28))(1);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_payment_009e1524);
      if (cVar1 != '\0') {
        pvVar5 = operator_new(0x58);
        if (pvVar5 != (void *)0x0) {
          FUN_00505380();
        }
        FUN_00401830(s_ui_paymentmoney_txt_009e1530);
        FUN_00401660(local_1c,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  else if (param_1 == 10) {
    if (param_3 == 1) {
      FUN_006b7b30(param_2,param_4);
      return 0;
    }
  }
  else if ((param_1 == 0xf) && (param_3 == 1)) {
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    FUN_00404fb0(param_2,0x5f,local_1c);
    pcVar7 = s_slotitem_009e1544;
    uVar6 = FUN_00405d30(0);
    cVar1 = FUN_004036a0(uVar6,pcVar7);
    if (cVar1 != '\0') {
      uVar6 = FUN_00405d30(1);
      uVar2 = thunk_FUN_00796f50(uVar6);
      uVar6 = FUN_00405d30(2);
      uVar3 = thunk_FUN_00796f50(uVar6);
      param_3._0_2_ = CONCAT11(uVar2,*(undefined1 *)(in_ECX + 0x28));
      (**(code **)(*DAT_00b5b114 + 0x30))(CONCAT12(uVar3,(undefined2)param_3));
      FUN_00406250();
      return 1;
    }
    FUN_00406250();
  }
  return 0;
}


// ==== FUN_006b80b0 @ 0x006b80b0 ====

void FUN_006b80b0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  if (*(void **)(in_ECX + 0xc) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0xc));
    return;
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  if (*(void **)(in_ECX + 0x1c) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x1c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  FUN_006b7c80();
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_lbl_money_009e14c4,9);
  uVar1 = (**(code **)(*DAT_00b5b114 + 0x20))();
  uVar1 = FUN_004041a0(apvStack_1c,uVar1);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  (**(code **)(*piVar2 + 0x30))();
  FUN_0055a260(uVar1);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  uStack_8 = 0xf;
  if (local_24 < 0x10) {
    return;
  }
  _free(local_38);
  return;
}


// ==== FUN_006b8190 @ 0x006b8190 ====

void FUN_006b8190(void)

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
  FUN_00401740(s_UI_Game2_ui_storagewnd_txt_009e14a8,0x1a);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006b80b0();
    FUN_004dd240(0xf,0,3,0,0);
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006b8220 @ 0x006b8220 ====

uint FUN_006b8220(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x70090002) {
    uVar1 = FUN_006b80b0();
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006b8240 @ 0x006b8240 ====

void FUN_006b8240(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e1568;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  in_ECX[1] = 0;
  FUN_006b8190();
  return;
}


// ==== FUN_006b8280 @ 0x006b8280 ====

void FUN_006b8280(byte param_1)

{
  void *in_ECX;
  
  FUN_006b7c30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006b82a0 @ 0x006b82a0 ====

void FUN_006b82a0(void)

{
  return;
}


// ==== FUN_006b8370 @ 0x006b8370 ====

undefined4 FUN_006b8370(void)

{
  (**(code **)(*DAT_00b5aef4 + 4))();
  return 1;
}


// ==== FUN_006b8380 @ 0x006b8380 ====

undefined4 FUN_006b8380(int param_1)

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


// ==== FUN_006b8400 @ 0x006b8400 ====

void FUN_006b8400(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5a78c + 0x1c))
            (CONCAT13((char)((uint)(in_ECX + 0xbc) >> 0x18),*(undefined3 *)(in_ECX + 0xbc)),param_1)
  ;
  return;
}


// ==== FUN_006b8430 @ 0x006b8430 ====

undefined4 FUN_006b8430(int param_1,ushort param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar1) {
    return 0;
  }
  if (param_3 == 1) {
    switch(param_2 - 1) {
    case 0:
      iVar1 = *DAT_00b5a78c;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x28))(uVar2);
      return 1;
    case 1:
      iVar1 = *DAT_00b5aef4;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x10))(uVar2);
      return 1;
    case 2:
      iVar1 = *DAT_00b5b114;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x34))(uVar2);
      return 1;
    case 3:
      (**(code **)(*DAT_00b5a78c + 4))((int3)in_ECX[0x2f]);
      return 1;
    case 4:
      uVar2 = thunk_FUN_00796f80(param_4);
      FUN_006b8400(uVar2);
    }
  }
  return 1;
}


// ==== FUN_006b8540 @ 0x006b8540 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006b8540(int param_1)

{
  uint uVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  void *unaff_EBX;
  undefined4 local_1c;
  void *local_18;
  undefined4 uStack_10;
  uint uStack_c;
  uint local_8;
  uint local_4;
  
  uVar1 = *(uint *)(in_ECX + 0xc4);
  if (uVar1 != 0) {
    if (uVar1 < 0x1389) {
      *(uint *)(in_ECX + 0xc4) = *(int *)(param_1 + 4) + uVar1;
    }
    else {
      *(undefined4 *)(in_ECX + 0xc4) = 0;
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401740(s_lbl_itemmessage_009e15f8,0xf);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(0);
      }
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
    }
  }
  uVar1 = *(uint *)(in_ECX + 200);
  if (uVar1 != 0) {
    if (uVar1 < 0x1389) {
      *(uint *)(in_ECX + 200) = *(int *)(param_1 + 4) + uVar1;
    }
    else {
      *(undefined4 *)(in_ECX + 200) = 0;
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401740(s_lbl_moneymessage_009e1608,0x10);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(0);
      }
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
    }
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_slotbag_009e161c,7);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  (**(code **)(*piVar3 + 0x30))();
  FUN_005811f0();
  if (*(int *)(in_ECX + 0xcc) != 0) {
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401740(s_processbar_009e1624,10);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
    if (0xf < uStack_c) {
      _free(unaff_EBX);
      return;
    }
    uStack_c = 0xf;
    uStack_10 = 0;
    if (piVar3 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar3 + 0x30))();
      if (*(uint *)(local_4 + 4) < *(uint *)(in_ECX + 0xcc)) {
        iVar5 = *(uint *)(in_ECX + 0xcc) - *(uint *)(local_4 + 4);
        *(int *)(in_ECX + 0xcc) = iVar5;
        if (iVar4 != 0) {
          local_4 = 2000 - iVar5;
          fVar2 = (float)(int)local_4;
          if ((int)local_4 < 0) {
            fVar2 = fVar2 + _DAT_0099d104;
          }
          FUN_00587ba0(fVar2 * _DAT_009b18d4 * DAT_0099de78);
          return;
        }
      }
      else {
        FUN_00587ba0(0);
        *(undefined4 *)(in_ECX + 0xcc) = 0;
      }
    }
  }
  return;
}


// ==== FUN_006b8760 @ 0x006b8760 ====

void FUN_006b8760(byte param_1)

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
      FUN_00401740(s_btn_changebag__d_009e17f0,0x10);
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
  FUN_00401740(s_btn_changebag_2_009e1804,0xf);
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
  FUN_00401740(s_btn_changebag_3_009e1814,0xf);
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


// ==== FUN_006b88e0 @ 0x006b88e0 ====

void FUN_006b88e0(void)

{
  char cVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int in_ECX;
  int iVar7;
  int *piVar8;
  uint auStack_3c [3];
  uint uStack_30;
  undefined4 uStack_2c;
  void *apvStack_28 [4];
  undefined4 uStack_18;
  uint uStack_14;
  
  uVar3 = 0;
  iVar7 = 0;
  piVar8 = (int *)(in_ECX + 0x68);
  do {
    if ((uVar3 < 0xd) || (0x12 < uVar3)) {
      iVar4 = (**(code **)(*DAT_00b5a78c + 0x44))(iVar7);
      *piVar8 = iVar4;
      FUN_00401740(s_suititem__d_009e1850,0xb);
      uVar5 = FUN_00404230(apvStack_28);
      piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar5);
      if (0xf < uStack_14) {
        _free(apvStack_28[0]);
        return;
      }
      uStack_14 = 0xf;
      uStack_18 = 0;
      apvStack_28[0] = (void *)((uint)apvStack_28[0] & 0xffffff00);
      (**(code **)(*piVar6 + 0x30))();
      if ((int *)*piVar8 == (int *)0x0) {
        uStack_2c = 1;
        apvStack_28[0] = (void *)0x1;
        auStack_3c[1] = 0;
        FUN_005802c0(auStack_3c + 1,&uStack_2c);
        FUN_00580870(0,1);
      }
      else {
        auStack_3c[0] = (**(code **)(*(int *)*piVar8 + 0x1c))();
        auStack_3c[0] = auStack_3c[0] & 0xffff;
        iVar4 = (**(code **)(*(int *)*piVar8 + 0x2c))();
        uStack_30 = (uint)*(byte *)(iVar4 + 0x31);
        auStack_3c[2] = (uint)*(byte *)(iVar4 + 0x30);
        FUN_005802c0(auStack_3c,auStack_3c + 2);
        FUN_00580870(*piVar8,1);
        iVar4 = FUN_0057f270();
        if (iVar4 != 0) {
          piVar6 = (int *)FUN_0057f270();
          cVar1 = (**(code **)(*piVar6 + 0x5c))();
          if (cVar1 == '\x01') {
            FUN_0057f430(0xaa333333);
          }
          else {
            FUN_0057f430(0xffffffff);
          }
        }
      }
    }
    uVar3 = uVar3 + 1;
    iVar7 = iVar7 + 1;
    piVar8 = piVar8 + 1;
  } while (uVar3 < 0x15);
  uVar2 = (**(code **)(*DAT_00b5a78c + 0x54))();
  *(undefined1 *)(in_ECX + 0xc0) = uVar2;
  return;
}


// ==== FUN_006b8a70 @ 0x006b8a70 ====

void FUN_006b8a70(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  void *pvStack_1c;
  undefined1 uStack_18;
  uint uStack_8;
  undefined4 uStack_4;
  
  (**(code **)(*DAT_00b5aef4 + 0x28))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_btn_confirm_009e1870,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00558730(unaff_ESI);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006b8ae0 @ 0x006b8ae0 ====

undefined4 FUN_006b8ae0(float param_1,float param_2)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar5;
  undefined4 uStack_20;
  void *pvStack_1c;
  uint uStack_8;
  
  uVar5 = (uint)param_1;
  iVar3 = FUN_00403620(0,*(undefined4 *)((int)param_1 + 0x14),s_slotme_009e1980,6);
  if (iVar3 == 0) {
    piVar4 = (int *)(**(code **)(*DAT_00b5a78c + 0x48))();
    if (piVar4 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar4 + 0x2c))();
      bVar1 = *(byte *)(iVar3 + 0x31);
      uVar5 = (uint)param_2 & 0xffff;
      param_2 = (float)((uint)param_2 >> 0x10) * DAT_009a09bc -
                (float)(*(byte *)(iVar3 + 0x30) >> 1);
      uStack_20 = (float)uVar5 * DAT_009a09bc - (float)(bVar1 >> 1);
      if (*(byte *)(iVar3 + 0x30) == 2) {
        if (param_2 <= 0.0) {
          param_2 = 0.0;
        }
        param_2 = param_2 + DAT_0099d0b4;
      }
      if ((bVar1 == 2) || (bVar1 == 4)) {
        if (uStack_20 <= 0.0) {
          uStack_20 = 0.0;
        }
        uStack_20 = uStack_20 + DAT_0099d0b4;
      }
      param_1 = (float)((uint)param_1 & 0xffffff00);
      uVar2 = FUN_00802534();
      param_1._0_2_ = CONCAT11(uVar2,param_1._0_1_);
      uVar2 = FUN_00802534();
      param_1._0_3_ = CONCAT12(uVar2,param_1._0_2_);
      (**(code **)(*DAT_00b5aef4 + 0x14))(&param_1);
      return 1;
    }
  }
  else {
    iVar3 = FUN_00403620(0,*(undefined4 *)(uVar5 + 0x14),s_slotbag_009e1988,7);
    if (iVar3 != 0) {
      return 0;
    }
    piVar4 = (int *)(**(code **)(*DAT_00b5a78c + 0x48))();
    if (piVar4 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar4 + 0x2c))();
      bVar1 = *(byte *)(iVar3 + 0x31);
      uVar5 = (uint)param_2 & 0xffff;
      param_2 = (float)((uint)param_2 >> 0x10) * DAT_009a09bc -
                (float)(*(byte *)(iVar3 + 0x30) >> 1);
      param_1 = (float)uVar5 * DAT_009a09bc - (float)(bVar1 >> 1);
      if (*(byte *)(iVar3 + 0x30) == 2) {
        if (param_2 <= 0.0) {
          param_2 = 0.0;
        }
        param_2 = param_2 + DAT_0099d0b4;
      }
      if ((bVar1 == 2) || (bVar1 == 4)) {
        if (param_1 <= 0.0) {
          param_1 = 0.0;
        }
        param_1 = param_1 + DAT_0099d0b4;
      }
      uStack_20 = (float)CONCAT31(uStack_20._1_3_,*(undefined1 *)(in_ECX + 0xbf));
      uVar2 = FUN_00802534();
      uStack_20._0_2_ = CONCAT11(uVar2,(undefined1)uStack_20);
      uVar2 = FUN_00802534();
      (**(code **)(*DAT_00b5a78c + 4))(CONCAT12(uVar2,(undefined2)uStack_20));
      FUN_00401830(s_Call_________IINVEN__IUIHANDLER__009e1990);
      FUN_00796d50(&uStack_20);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return extraout_EAX;
      }
    }
  }
  return 1;
}


// ==== FUN_006b8d30 @ 0x006b8d30 ====

void FUN_006b8d30(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = &PTR_FUN_009e19d8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  iVar1 = 4;
  puVar2 = in_ECX + 0x1b;
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
  if ((void *)in_ECX[7] != (void *)0x0) {
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


// ==== FUN_006b8dc0 @ 0x006b8dc0 ====

/* WARNING: Removing unreachable block (ram,0x006b97a9) */
/* WARNING: Removing unreachable block (ram,0x006b975d) */

void FUN_006b8dc0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  void *unaff_EBX;
  void *unaff_ESI;
  int unaff_EDI;
  undefined *puVar4;
  void **ppvStack_238;
  uint uStack_234;
  undefined4 *puStack_230;
  void *pvStack_22c;
  undefined4 local_218;
  uint uStack_214;
  uint uStack_210;
  undefined4 uStack_20c;
  void *pvStack_208;
  uint uStack_204;
  void *pvStack_200;
  void *pvStack_1fc;
  uint uStack_1f8;
  uint uStack_1f4;
  uint uStack_1f0;
  uint uStack_1ec;
  uint uStack_1e8;
  undefined4 uStack_1e4;
  void *pvStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d0;
  uint uStack_1cc;
  void *apvStack_1c4 [4];
  undefined4 uStack_1b4;
  uint uStack_1b0;
  void *apvStack_1a8 [4];
  undefined4 uStack_198;
  uint uStack_194;
  void *apvStack_18c [4];
  undefined4 uStack_17c;
  uint uStack_178;
  void *apvStack_170 [4];
  undefined4 uStack_160;
  uint uStack_15c;
  void *apvStack_154 [4];
  undefined4 uStack_144;
  uint uStack_140;
  void *apvStack_138 [4];
  undefined4 uStack_128;
  uint uStack_124;
  void *apvStack_11c [4];
  undefined4 uStack_10c;
  uint uStack_108;
  void *apvStack_100 [4];
  undefined4 uStack_f0;
  uint uStack_ec;
  void *apvStack_e4 [4];
  undefined4 uStack_d4;
  uint uStack_d0;
  void *apvStack_c8 [4];
  undefined4 uStack_b8;
  uint uStack_b4;
  void *apvStack_ac [4];
  undefined4 uStack_9c;
  uint uStack_98;
  void *apvStack_90 [4];
  undefined4 uStack_80;
  uint uStack_7c;
  void *apvStack_74 [4];
  undefined4 uStack_64;
  uint uStack_60;
  void *pvStack_5c;
  undefined1 auStack_58 [12];
  undefined4 uStack_4c;
  uint uStack_48;
  void *pvStack_40;
  undefined1 auStack_3c [16];
  uint uStack_2c;
  undefined4 local_1c [6];
  uint uStack_4;
  
  pvStack_22c = (void *)param_2;
  puStack_230 = local_1c;
  uStack_234 = 0x6b8de9;
  (**(code **)(*DAT_00b5ad20 + 0x48))();
  uStack_234 = uStack_4;
  ppvStack_238 = &pvStack_40;
  (**(code **)(*DAT_00b5ad20 + 0x48))();
  iVar1 = (**(code **)(*DAT_00b5aef4 + 0x1c))();
  if (iVar1 == 0) {
    if (param_2 == 0) {
      uStack_20c = 0xf;
      uStack_210 = 0;
      FUN_00401740(&DAT_009e1759,0);
      uStack_1f0 = 0xf;
      uStack_1f4 = 0;
      uStack_204 = uStack_204 & 0xffffff00;
      FUN_00401740(s_lbl_moneymessage_009e175c,0x10);
      piVar3 = (int *)(**(code **)(**(int **)(unaff_EDI + 4) + 0x34))(&pvStack_208);
      (**(code **)(*piVar3 + 0x30))();
      FUN_0055a260(apvStack_1c4 + -0x19);
      if (0xf < uStack_1f4) {
        _free(pvStack_208);
        return;
      }
      uStack_1f4 = 0xf;
      uStack_1f8 = 0;
      pvStack_208 = (void *)((uint)pvStack_208 & 0xffffff00);
      if (0xf < uStack_210) {
        _free(unaff_ESI);
        return;
      }
      uStack_210 = 0xf;
      uStack_214 = 0;
      FUN_00401740(s_lbl_moneymessage_009e1770,0x10);
      piVar3 = (int *)(**(code **)(**(int **)(unaff_EDI + 4) + 0x34))(apvStack_1c4 + -0x19);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(0);
      }
      if (0xf < ((uint)unaff_ESI & 0xffffff00)) {
        _free(ppvStack_238);
        return;
      }
      *(undefined4 *)(unaff_EDI + 200) = 0;
    }
    else {
      puVar4 = &DAT_006e00a8;
      uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
      uStack_1dc = 0xf;
      pvStack_1e0 = (void *)0x0;
      uStack_1f0 = uStack_1f0 & 0xffffff00;
      FUN_00401660(uVar2,0,0xffffffff);
      uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,&DAT_006e00a9);
      pvStack_200 = (void *)0xf;
      uStack_204 = 0;
      uStack_214 = uStack_214 & 0xffffff00;
      FUN_00401660(uVar2,0,0xffffffff);
      puStack_230 = (undefined4 *)((uint)puStack_230 & 0xffffff00);
      FUN_00401740(s_lbl_moneymessage_009e1734,0x10);
      uVar2 = FUN_004041a0(apvStack_1a8,local_1c[0],s_<_color>_009e1700,&local_218);
      uVar2 = FUN_004041a0(apvStack_90,param_2,s_<_color>_009e171c,&pvStack_1fc,&DAT_009e1718,
                           s_<color__009e1710,auStack_58,&DAT_009e170c,uVar2);
      uVar2 = FUN_004022a0(apvStack_170,s_<color__009e172c,auStack_3c,&DAT_009e1728,uVar2);
      uVar2 = FUN_00402220(apvStack_138,uVar2);
      uVar2 = FUN_00405bd0(&pvStack_1e0,uVar2);
      uVar2 = FUN_00402220(apvStack_11c,uVar2);
      uVar2 = FUN_00405bd0(apvStack_100,uVar2);
      uVar2 = FUN_00402220(apvStack_1c4,uVar2);
      uVar2 = FUN_00402220(apvStack_18c,uVar2);
      uVar2 = FUN_00405bd0(apvStack_154,uVar2);
      uVar2 = FUN_00402220(apvStack_e4,uVar2);
      uVar2 = FUN_00405bd0(apvStack_ac,uVar2);
      uVar2 = FUN_00402220(apvStack_74,uVar2);
      uVar2 = FUN_00405bd0(apvStack_c8,uVar2);
      piVar3 = (int *)(**(code **)(*(int *)ppvStack_238[1] + 0x34))(&uStack_234);
      (**(code **)(*piVar3 + 0x30))();
      FUN_0055a260(uVar2);
      if (0xf < uStack_b4) {
        _free(apvStack_c8[0]);
        return;
      }
      uStack_b4 = 0xf;
      uStack_b8 = 0;
      apvStack_c8[0] = (void *)((uint)apvStack_c8[0] & 0xffffff00);
      if (0xf < uStack_60) {
        _free(apvStack_74[0]);
        return;
      }
      uStack_60 = 0xf;
      uStack_64 = 0;
      apvStack_74[0] = (void *)((uint)apvStack_74[0] & 0xffffff00);
      if (0xf < uStack_98) {
        _free(apvStack_ac[0]);
        return;
      }
      uStack_98 = 0xf;
      uStack_9c = 0;
      apvStack_ac[0] = (void *)((uint)apvStack_ac[0] & 0xffffff00);
      if (0xf < uStack_d0) {
        _free(apvStack_e4[0]);
        return;
      }
      uStack_d0 = 0xf;
      uStack_d4 = 0;
      apvStack_e4[0] = (void *)((uint)apvStack_e4[0] & 0xffffff00);
      if (0xf < uStack_140) {
        _free(apvStack_154[0]);
        return;
      }
      uStack_140 = 0xf;
      uStack_144 = 0;
      apvStack_154[0] = (void *)((uint)apvStack_154[0] & 0xffffff00);
      if (0xf < uStack_178) {
        _free(apvStack_18c[0]);
        return;
      }
      uStack_178 = 0xf;
      uStack_17c = 0;
      apvStack_18c[0] = (void *)((uint)apvStack_18c[0] & 0xffffff00);
      if (0xf < uStack_1b0) {
        _free(apvStack_1c4[0]);
        return;
      }
      uStack_1b0 = 0xf;
      uStack_1b4 = 0;
      apvStack_1c4[0] = (void *)((uint)apvStack_1c4[0] & 0xffffff00);
      if (0xf < uStack_ec) {
        _free(apvStack_100[0]);
        return;
      }
      uStack_ec = 0xf;
      uStack_f0 = 0;
      apvStack_100[0] = (void *)((uint)apvStack_100[0] & 0xffffff00);
      if (0xf < uStack_108) {
        _free(apvStack_11c[0]);
        return;
      }
      uStack_108 = 0xf;
      uStack_10c = 0;
      apvStack_11c[0] = (void *)((uint)apvStack_11c[0] & 0xffffff00);
      if (0xf < uStack_1cc) {
        _free(pvStack_1e0);
        return;
      }
      uStack_1cc = 0xf;
      uStack_1d0 = 0;
      pvStack_1e0 = (void *)((uint)pvStack_1e0 & 0xffffff00);
      if (0xf < uStack_124) {
        _free(apvStack_138[0]);
        return;
      }
      uStack_124 = 0xf;
      uStack_128 = 0;
      apvStack_138[0] = (void *)((uint)apvStack_138[0] & 0xffffff00);
      if (0xf < uStack_15c) {
        _free(apvStack_170[0]);
        return;
      }
      uStack_15c = 0xf;
      uStack_160 = 0;
      apvStack_170[0] = (void *)((uint)apvStack_170[0] & 0xffffff00);
      if (0xf < uStack_7c) {
        _free(apvStack_90[0]);
        return;
      }
      uStack_7c = 0xf;
      uStack_80 = 0;
      apvStack_90[0] = (void *)((uint)apvStack_90[0] & 0xffffff00);
      if (0xf < uStack_194) {
        _free(apvStack_1a8[0]);
        return;
      }
      uStack_194 = 0xf;
      uStack_198 = 0;
      apvStack_1a8[0] = (void *)((uint)apvStack_1a8[0] & 0xffffff00);
      uStack_234 = uStack_234 & 0xffffff00;
      FUN_00401740(s_lbl_moneymessage_009e1748,0x10);
      piVar3 = (int *)(**(code **)(**(int **)(puVar4 + 4) + 0x34))(&ppvStack_238);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(1);
      }
      *(undefined4 *)(puVar4 + 200) = 1;
      if ((void *)0xf < pvStack_208) {
        _free((void *)0xf);
        return;
      }
      pvStack_208 = (void *)0xf;
      uStack_20c = 0;
      if (0xf < uStack_1ec) {
        _free(pvStack_200);
        return;
      }
    }
  }
  else {
    puVar4 = &DAT_006e00a8;
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
    uStack_214 = 0xf;
    local_218 = 0;
    FUN_00401660(uVar2,0,0xffffffff);
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,&DAT_006e00a9);
    pvStack_200 = (void *)0xf;
    uStack_204 = 0;
    uStack_214 = uStack_214 & 0xffffff00;
    FUN_00401660(uVar2,0,0xffffffff);
    uStack_1e4 = 0xf;
    uStack_1e8 = 0;
    uStack_1f8 = uStack_1f8 & 0xffffff00;
    FUN_00401740(s_lbl_moneymessage_009e16d8,0x10);
    uVar2 = FUN_004041a0(apvStack_c8,local_1c[0],s_<_color>_009e16a4,&local_218);
    uVar2 = FUN_004041a0(apvStack_74,param_2,s_<_color>_009e16c0,&uStack_234,&DAT_009e16bc,
                         s_<color__009e16b4,auStack_58,&DAT_009e16b0,uVar2);
    uVar2 = FUN_004022a0(apvStack_ac,s_<color__009e16d0,auStack_3c,&DAT_009e16cc,uVar2);
    uVar2 = FUN_00402220(apvStack_e4,uVar2);
    uVar2 = FUN_00405bd0(apvStack_154,uVar2);
    uVar2 = FUN_00402220(apvStack_18c,uVar2);
    uVar2 = FUN_00405bd0(apvStack_1c4,uVar2);
    uVar2 = FUN_00402220(apvStack_100,uVar2);
    uVar2 = FUN_00402220(apvStack_11c,uVar2);
    uVar2 = FUN_00405bd0(&pvStack_1e0,uVar2);
    uVar2 = FUN_00402220(apvStack_138,uVar2);
    uVar2 = FUN_00405bd0(apvStack_170,uVar2);
    uVar2 = FUN_00402220(apvStack_90,uVar2);
    uVar2 = FUN_00405bd0(apvStack_1a8,uVar2);
    piVar3 = (int *)(**(code **)(*(int *)ppvStack_238[1] + 0x34))(&pvStack_1fc);
    (**(code **)(*piVar3 + 0x30))();
    FUN_0055a260(uVar2);
    if (0xf < uStack_194) {
      _free(apvStack_1a8[0]);
      return;
    }
    uStack_194 = 0xf;
    uStack_198 = 0;
    apvStack_1a8[0] = (void *)((uint)apvStack_1a8[0] & 0xffffff00);
    if (0xf < uStack_7c) {
      _free(apvStack_90[0]);
      return;
    }
    uStack_7c = 0xf;
    uStack_80 = 0;
    apvStack_90[0] = (void *)((uint)apvStack_90[0] & 0xffffff00);
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
    if (0xf < uStack_1cc) {
      _free(pvStack_1e0);
      return;
    }
    uStack_1cc = 0xf;
    uStack_1d0 = 0;
    pvStack_1e0 = (void *)((uint)pvStack_1e0 & 0xffffff00);
    if (0xf < uStack_108) {
      _free(apvStack_11c[0]);
      return;
    }
    uStack_108 = 0xf;
    uStack_10c = 0;
    apvStack_11c[0] = (void *)((uint)apvStack_11c[0] & 0xffffff00);
    if (0xf < uStack_ec) {
      _free(apvStack_100[0]);
      return;
    }
    uStack_ec = 0xf;
    uStack_f0 = 0;
    apvStack_100[0] = (void *)((uint)apvStack_100[0] & 0xffffff00);
    if (0xf < uStack_1b0) {
      _free(apvStack_1c4[0]);
      return;
    }
    uStack_1b0 = 0xf;
    uStack_1b4 = 0;
    apvStack_1c4[0] = (void *)((uint)apvStack_1c4[0] & 0xffffff00);
    if (0xf < uStack_178) {
      _free(apvStack_18c[0]);
      return;
    }
    uStack_178 = 0xf;
    uStack_17c = 0;
    apvStack_18c[0] = (void *)((uint)apvStack_18c[0] & 0xffffff00);
    if (0xf < uStack_140) {
      _free(apvStack_154[0]);
      return;
    }
    uStack_140 = 0xf;
    uStack_144 = 0;
    apvStack_154[0] = (void *)((uint)apvStack_154[0] & 0xffffff00);
    if (0xf < uStack_d0) {
      _free(apvStack_e4[0]);
      return;
    }
    uStack_d0 = 0xf;
    uStack_d4 = 0;
    apvStack_e4[0] = (void *)((uint)apvStack_e4[0] & 0xffffff00);
    if (0xf < uStack_98) {
      _free(apvStack_ac[0]);
      return;
    }
    uStack_98 = 0xf;
    uStack_9c = 0;
    apvStack_ac[0] = (void *)((uint)apvStack_ac[0] & 0xffffff00);
    if (0xf < uStack_60) {
      _free(apvStack_74[0]);
      return;
    }
    uStack_60 = 0xf;
    uStack_64 = 0;
    apvStack_74[0] = (void *)((uint)apvStack_74[0] & 0xffffff00);
    if (0xf < uStack_b4) {
      _free(apvStack_c8[0]);
      return;
    }
    uStack_b4 = 0xf;
    uStack_b8 = 0;
    apvStack_c8[0] = (void *)((uint)apvStack_c8[0] & 0xffffff00);
    if (0xf < uStack_1e8) {
      _free(pvStack_1fc);
      return;
    }
    uStack_1e8 = 0xf;
    uStack_1ec = 0;
    pvStack_1fc = (void *)((uint)pvStack_1fc & 0xffffff00);
    FUN_00401740(s_lbl_moneymessage_009e16ec,0x10);
    piVar3 = (int *)(**(code **)(**(int **)(puVar4 + 4) + 0x34))(&pvStack_200);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(1);
    }
    if (0xf < uStack_1ec) {
      _free(pvStack_200);
      return;
    }
    *(undefined4 *)(puVar4 + 200) = 1;
    if ((void *)0xf < pvStack_208) {
      _free(unaff_EBX);
      return;
    }
    pvStack_208 = (void *)0xf;
    uStack_20c = 0;
    if ((void *)0xf < unaff_ESI) {
      _free(ppvStack_238);
      return;
    }
  }
  if (0xf < uStack_48) {
    _free(pvStack_5c);
    return;
  }
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_006b9940 @ 0x006b9940 ====

void FUN_006b9940(char param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *pvStack_70;
  undefined1 auStack_6c [4];
  uint uStack_68;
  uint uStack_64;
  void *pvStack_60;
  uint auStack_5c [3];
  undefined1 uStack_50;
  uint uStack_4c;
  void *pvStack_44;
  int iStack_40;
  uint uStack_3c;
  void *pvStack_38;
  undefined1 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  undefined4 uStack_20;
  undefined4 uStack_14;
  uint uStack_10;
  
  uVar1 = (**(code **)(*DAT_00b5aef4 + 0x44))();
  uStack_3c = 0xf;
  iStack_40 = 0;
  uStack_50 = 0;
  FUN_00401660(uVar1,0,0xffffffff);
  if (iStack_40 == 0) {
    uStack_20 = 0xf;
    pvStack_24 = (void *)0x0;
    uStack_34 = 0;
    FUN_00401740(&DAT_009e17a4,0);
    auStack_5c[1] = 0xf;
    auStack_5c[0] = 0;
    auStack_6c[0] = 0;
    FUN_00401740(s_lbl_itemmessage_009e17a8,0xf);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_70);
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(&uStack_3c);
    if (0xf < auStack_5c[0]) {
      _free(pvStack_70);
      return;
    }
    auStack_5c[0] = 0xf;
    pvStack_60 = (void *)0x0;
    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
    if ((void *)0xf < pvStack_24) {
      _free(pvStack_38);
      return;
    }
    pvStack_24 = (void *)0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    FUN_00401740(s_lbl_itemmessage_009e17b8,0xf);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_3c);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if (0xf < uStack_30) {
      _free(pvStack_44);
      return;
    }
    *(undefined4 *)(in_ECX + 0xc4) = 0;
  }
  else {
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,&DAT_006e00a6 + (param_1 != '\x01'));
    uStack_28 = 0xf;
    uStack_2c = 0;
    uStack_3c = uStack_3c & 0xffffff00;
    FUN_00401660(uVar1,0,0xffffffff);
    pvStack_60 = (void *)0xf;
    uStack_64 = 0;
    FUN_00401740(s_lbl_itemmessage_009e1784,0xf);
    uVar1 = FUN_00405bd0(&pvStack_24,auStack_5c,&iStack_40);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_5c + -7);
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(uVar1);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    if (0xf < uStack_64) {
      _free(unaff_EBP);
      return;
    }
    uStack_64 = 0xf;
    uStack_68 = 0;
    FUN_00401740(s_lbl_itemmessage_009e1794,0xf);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_5c + -8);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(1);
    }
    if (0xf < uStack_68) {
      _free(unaff_ESI);
      return;
    }
    *(undefined4 *)(in_ECX + 0xc4) = 1;
    if (0xf < uStack_30) {
      _free(pvStack_44);
      return;
    }
  }
  if (uStack_4c < 0x10) {
    return;
  }
  _free(pvStack_60);
  return;
}


// ==== FUN_006b9bb0 @ 0x006b9bb0 ====

/* WARNING: Removing unreachable block (ram,0x006b9cb1) */
/* WARNING: Removing unreachable block (ram,0x006b9c1d) */

void FUN_006b9bb0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_aa [18];
  undefined1 auStack_98 [4];
  void *pvStack_94;
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
  undefined1 auStack_38 [12];
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  
  uVar1 = (**(code **)(*DAT_00b5aef4 + 0x30))();
  (**(code **)(*DAT_00b5ad20 + 0x48))(auStack_38,uVar1);
  FUN_00401740(s_lbl_money_009e1824,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_aa + -10);
  (**(code **)(*piVar2 + 0x30))();
  uVar1 = FUN_004041a0(auStack_28,uVar1,s_<_color>_009e1830);
  uVar1 = FUN_004022a0(auStack_7c,s_<color__009e1840,auStack_44,&DAT_009e183c,uVar1);
  uVar1 = FUN_00402220(auStack_98,uVar1);
  uVar1 = FUN_00405bd0(auStack_60,uVar1);
  uVar1 = FUN_00402220(auStack_aa + -0xe,uVar1);
  FUN_0055a260(uVar1);
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
  uRam000000db = 2000;
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_006b9d80 @ 0x006b9d80 ====

void FUN_006b9d80(void)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  int *piVar4;
  int in_ECX;
  uint unaff_EBX;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uStack_2c;
  byte bStack_28;
  byte bStack_27;
  byte bStack_26;
  int *local_24;
  int *piStack_20;
  uint uStack_1c;
  uint uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  puVar6 = (undefined4 *)(in_ECX + 0x2c);
  iVar5 = 4;
  do {
    if ((void *)*puVar6 != (void *)0x0) {
      _free((void *)*puVar6);
      return;
    }
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6 = puVar6 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  (**(code **)(*DAT_00b5a78c + 0x38))(&local_24);
  iStack_14 = -1;
  if (local_24 != (int *)0x0) {
    uStack_1c = (uint)bStack_27;
    uStack_18 = (uint)bStack_26;
    piStack_20 = local_24;
    cVar2 = (**(code **)(*local_24 + 0x5c))();
    iStack_14 = (-(uint)(cVar2 != '\x01') & 0x55cccccc) + 0xaa333333;
    iVar5 = (uint)bStack_28 * 0x10 + 0x28 + in_ECX;
    iVar1 = *(int *)(iVar5 + 4);
    if ((iVar1 == 0) ||
       ((uint)(*(int *)(iVar5 + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(iVar5 + 8) - iVar1 >> 4))) {
      FUN_00680c50(*(undefined4 *)(iVar5 + 8),1,&piStack_20);
    }
    else {
      iVar1 = *(int *)(iVar5 + 8);
      FUN_00680b80(iVar1,1,&piStack_20,iVar5,unaff_EBX);
      *(int *)(iVar5 + 8) = iVar1 + 0x10;
    }
    (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    while (uStack_2c != (int *)0x0) {
      uStack_1c = unaff_EBX >> 8 & 0xff;
      uStack_18 = unaff_EBX >> 0x10 & 0xff;
      piStack_20 = uStack_2c;
      cVar2 = (**(code **)(*uStack_2c + 0x5c))();
      iStack_14 = (-(uint)(cVar2 != '\x01') & 0x55cccccc) + 0xaa333333;
      iVar5 = (unaff_EBX & 0xff) * 0x10 + 0x28 + in_ECX;
      iVar1 = *(int *)(iVar5 + 4);
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(iVar5 + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(iVar5 + 8) - iVar1 >> 4))) {
        FUN_00680c50(*(undefined4 *)(iVar5 + 8),1,&piStack_20);
      }
      else {
        iVar1 = *(int *)(iVar5 + 8);
        FUN_00680b80(iVar1,1,&piStack_20,iVar5,unaff_EBX);
        *(int *)(iVar5 + 8) = iVar1 + 0x10;
      }
      (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    }
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = uStack_1c & 0xffffff00;
  FUN_00401740(s_slotbag_009e1848,7);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&piStack_20);
  if (uStack_c < 0x10) {
    uStack_c = 0xf;
    uStack_10 = 0;
    piStack_20 = (int *)((uint)piStack_20 & 0xffffff00);
    (**(code **)(*piVar4 + 0x30))();
    bVar3 = (**(code **)(*DAT_00b5a78c + 0x50))();
    *(byte *)(in_ECX + 0xbf) = bVar3;
    FUN_005817e0((uint)bVar3 * 0x10 + 0x28 + in_ECX,1);
    return;
  }
  _free(piStack_20);
  return;
}


// ==== FUN_006b9fd0 @ 0x006b9fd0 ====

void FUN_006b9fd0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int in_ECX;
  int unaff_EBX;
  uint uVar5;
  void *pvStack_1c;
  uint uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  uint uStack_8;
  undefined4 uStack_4;
  
  if (*(void **)(in_ECX + 0x1c) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x1c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  uVar2 = (**(code **)(*DAT_00b5aef4 + 0x20))();
  uVar5 = 0;
  if (uVar2 != 0) {
    uStack_10 = 0xffffffff;
    do {
      puVar3 = (undefined4 *)(**(code **)(*DAT_00b5aef4 + 0x24))(uVar5);
      pvStack_1c = (void *)*puVar3;
      uStack_18 = (uint)*(byte *)((int)puVar3 + 5);
      uStack_14 = (uint)*(byte *)((int)puVar3 + 6);
      iVar1 = *(int *)(in_ECX + 0x1c);
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(in_ECX + 0x24) - iVar1 >> 4) <=
          (uint)(*(int *)(in_ECX + 0x20) - iVar1 >> 4))) {
        FUN_00680c50(*(undefined4 *)(in_ECX + 0x20),1,&pvStack_1c);
      }
      else {
        iVar1 = *(int *)(in_ECX + 0x20);
        FUN_00680b80(iVar1,1,&pvStack_1c,in_ECX + 0x18,uVar2);
        *(int *)(in_ECX + 0x20) = iVar1 + 0x10;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar2);
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = uStack_18 & 0xffffff00;
  FUN_00401740(s_slottrader_009e185c,10);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  (**(code **)(*piVar4 + 0x30))();
  if (uStack_8 < 0x10) {
    FUN_005817e0(in_ECX + 0x18,0);
    *(undefined4 *)(unaff_EBX + 0xcc) = 2000;
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006ba120 @ 0x006ba120 ====

void FUN_006ba120(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int in_ECX;
  int unaff_EBX;
  uint uVar5;
  void *pvStack_1c;
  uint uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  uint uStack_8;
  undefined4 uStack_4;
  
  if (*(void **)(in_ECX + 0xc) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0xc));
    return;
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  uVar2 = (**(code **)(*DAT_00b5aef4 + 0x38))();
  uVar5 = 0;
  if (uVar2 != 0) {
    uStack_10 = 0xffffffff;
    do {
      puVar3 = (undefined4 *)(**(code **)(*DAT_00b5aef4 + 0x3c))(uVar5);
      pvStack_1c = (void *)*puVar3;
      uStack_18 = (uint)*(byte *)((int)puVar3 + 5);
      uStack_14 = (uint)*(byte *)((int)puVar3 + 6);
      iVar1 = *(int *)(in_ECX + 0xc);
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 4) <=
          (uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 4))) {
        FUN_00680c50(*(undefined4 *)(in_ECX + 0x10),1,&pvStack_1c);
      }
      else {
        iVar1 = *(int *)(in_ECX + 0x10);
        FUN_00680b80(iVar1,1,&pvStack_1c,in_ECX + 8,uVar2);
        *(int *)(in_ECX + 0x10) = iVar1 + 0x10;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar2);
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = uStack_18 & 0xffffff00;
  FUN_00401740(s_slotme_009e1868,6);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  (**(code **)(*piVar4 + 0x30))();
  if (uStack_8 < 0x10) {
    FUN_005817e0(in_ECX + 8,0);
    *(undefined4 *)(unaff_EBX + 0xcc) = 2000;
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006ba270 @ 0x006ba270 ====

/* WARNING: Removing unreachable block (ram,0x006ba2f7) */

void FUN_006ba270(undefined4 param_1,byte *param_2,ushort param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
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
  if (0xff < param_3) {
    param_3 = 0xff;
  }
  *(ushort *)(puVar1 + 0x13) = (ushort)*param_2 << 8 | param_3;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_006ba320 @ 0x006ba320 ====

void FUN_006ba320(void)

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
  
  FUN_006b9bb0();
  FUN_006b9d80();
  FUN_006b88e0();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_tab_chang_shield_009e17c8,0x10);
  local_20 = (void *)CONCAT31(local_20._1_3_,*(undefined1 *)(in_ECX + 0xc0));
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
  FUN_00401740(s_tab_chang_weapon_009e17dc,0x10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_20);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00582440(unaff_ESI);
  if (uStack_c < 0x10) {
    FUN_006b8760(*(undefined1 *)(in_ECX + 0xbf));
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_006ba410 @ 0x006ba410 ====

/* WARNING: Removing unreachable block (ram,0x006ba844) */
/* WARNING: Removing unreachable block (ram,0x006ba88b) */
/* WARNING: Removing unreachable block (ram,0x006ba7d1) */

void FUN_006ba410(void)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EBP;
  undefined4 unaff_EDI;
  char cVar5;
  undefined1 *puVar6;
  undefined4 uStack_e8;
  void **ppvStack_e0;
  undefined1 auStack_ca [2];
  void *local_c8;
  void *local_c4;
  void *pvStack_c0;
  undefined4 uStack_bc;
  void *pvStack_b8;
  int *local_b4;
  uint local_b0;
  uint uStack_ac;
  undefined4 uStack_a8;
  void *apvStack_a4 [3];
  void *pvStack_98;
  undefined4 uStack_94;
  uint uStack_90;
  void *pvStack_88;
  uint uStack_84;
  void *pvStack_7c;
  undefined4 uStack_78;
  uint uStack_74;
  void *pvStack_6c;
  uint uStack_68;
  void *pvStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  void *pvStack_50;
  uint uStack_4c;
  void *pvStack_44;
  void *pvStack_40;
  uint uStack_3c;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  ppvStack_e0 = (void **)0xe;
  local_b0 = 0xf;
  local_b4 = (int *)0x0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  uStack_e8 = (undefined1 *)0x6ba43e;
  FUN_00401740();
  ppvStack_e0 = (void **)0x6ba449;
  (**(code **)(*DAT_00b5aef4 + 0x18))();
  ppvStack_e0 = &local_c8;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  (**(code **)(*piVar2 + 0x30))();
  uStack_e8 = (undefined1 *)0x6ba467;
  FUN_0055a260();
  if (0xf < local_b4) {
    uStack_e8 = (undefined1 *)0x6ba47c;
    _free(local_c8);
    return;
  }
  uVar3 = (**(code **)(*DAT_00b5aef4 + 0x1c))();
  (**(code **)(*DAT_00b5aef4 + 0x34))();
  uStack_e8 = auStack_20;
  uVar4 = uVar3;
  (**(code **)(*DAT_00b5ad20 + 0x48))();
  uStack_bc = 0xf;
  pvStack_c0 = (void *)0x0;
  FUN_00401740(s_lbl_tradermoney_009e1658,0xf);
  uVar3 = FUN_004041a0(&pvStack_b8,uVar3,s_<_color>_009e1640);
  uVar3 = FUN_004022a0(&pvStack_7c,s_<color__009e1650,auStack_28,&DAT_009e164c,uVar3);
  uVar3 = FUN_00402220(&pvStack_44,uVar3);
  uVar3 = FUN_00405bd0(&pvStack_98,uVar3);
  uVar3 = FUN_00402220(&pvStack_60,uVar3);
  puVar6 = auStack_ca + -10;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(puVar6);
  (**(code **)(*piVar2 + 0x30))();
  FUN_0055a260(uVar3);
  if (0xf < uStack_4c) {
    _free(pvStack_60);
    return;
  }
  uStack_4c = 0xf;
  pvStack_50 = (void *)0x0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  if (0xf < uStack_84) {
    _free(pvStack_98);
    return;
  }
  uStack_84 = 0xf;
  pvStack_88 = (void *)0x0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  if (0xf < uStack_68) {
    _free(pvStack_7c);
    return;
  }
  uStack_68 = 0xf;
  pvStack_6c = (void *)0x0;
  pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
  if ((void *)0xf < apvStack_a4[0]) {
    _free(pvStack_b8);
    return;
  }
  apvStack_a4[0] = (void *)0xf;
  uStack_a8 = 0;
  pvStack_b8 = (void *)((uint)pvStack_b8 & 0xffffff00);
  if ((void *)0xf < pvStack_c0) {
    _free(unaff_EBP);
    return;
  }
  uVar3 = (**(code **)(*DAT_00b5ad20 + 0x48))(&uStack_bc,unaff_EDI);
  cVar5 = (char)unaff_EDI;
  FUN_00401660(uVar3,0,0xffffffff);
  if (0xf < uStack_ac) {
    _free(pvStack_c0);
    return;
  }
  local_c8 = (void *)0xf;
  FUN_00401740(s_lbl_mymoney_009e1680,0xb);
  uVar4 = FUN_004041a0(&pvStack_6c,uVar4,s_<_color>_009e1668);
  uVar4 = FUN_004022a0(apvStack_a4,s_<color__009e1678,&uStack_34,&DAT_009e1674,uVar4);
  uVar4 = FUN_00402220(&pvStack_50,uVar4);
  uVar4 = FUN_00405bd0(&pvStack_88,uVar4);
  FUN_00402220(&local_c4,uVar4);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&ppvStack_e0);
  (**(code **)(*piVar2 + 0x30))();
  FUN_0055a260(uStack_e8);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = 0xf;
  local_b4 = (int *)0x0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uStack_74 = 0xf;
  uStack_78 = 0;
  pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
  if (0xf < uStack_3c) {
    _free(pvStack_50);
    return;
  }
  uStack_3c = 0xf;
  pvStack_40 = (void *)0x0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  if (0xf < uStack_90) {
    _free(apvStack_a4[0]);
    return;
  }
  uStack_90 = 0xf;
  uStack_94 = 0;
  apvStack_a4[0] = (void *)((uint)apvStack_a4[0] & 0xffffff00);
  if (0xf < uStack_58) {
    _free(pvStack_6c);
    return;
  }
  uStack_58 = 0xf;
  uStack_5c = 0;
  pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
  FUN_006ba120();
  FUN_006b9fd0();
  FUN_006b8a70();
  uVar1 = (**(code **)(*DAT_00b5aef4 + 0x40))();
  uStack_e8 = (undefined1 *)CONCAT31(uStack_e8._1_3_,uVar1);
  ppvStack_e0 = (void **)((uint)ppvStack_e0 & 0xffffff00);
  FUN_00401740(s_btn_myConfirm_009e168c,0xd);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_ca + -0x1a);
  (**(code **)(*piVar2 + 0x30))();
  FUN_00558730(puVar6);
  FUN_00401740(s_btn_ok_009e169c,6);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_e8);
  local_b4 = (int *)(**(code **)(*piVar2 + 0x30))();
  uStack_e8 = (undefined1 *)((uint)uStack_e8 & 0xffffff00);
  (**(code **)(*local_b4 + 0x28))(cVar5 == '\0');
  FUN_006ba320();
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_006ba8f0 @ 0x006ba8f0 ====

undefined4 FUN_006ba8f0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  int *in_ECX;
  char *pcVar8;
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 auStack_24 [8];
  undefined1 local_1c [28];
  
  iVar2 = param_2;
  if (param_1 == 1) {
    if (param_3 != 1) {
      return 0;
    }
    iVar6 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_ok_009e187c,6);
    if (iVar6 == 0) {
      if (in_ECX[0x33] != 0) {
        uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x28001d);
        FUN_00765c50(uVar7);
        iVar2 = *DAT_00b5ad0c;
        FUN_00765c50(&local_40);
        (**(code **)(iVar2 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*DAT_00b5aef4 + 8))();
      return 1;
    }
    cVar3 = FUN_004036a0(iVar2,s_btn_exit_009e1884);
    if (cVar3 != '\0') {
      (**(code **)(*in_ECX + 0x10))();
      return 1;
    }
    cVar3 = FUN_004036a0(iVar2,s_btn_cancel_009e1890);
    if (cVar3 != '\0') {
      (**(code **)(*DAT_00b5aef4 + 0xc))();
      return 1;
    }
    cVar3 = FUN_004036a0(iVar2,s_btn_drop_009e189c);
    if (cVar3 != '\0') {
      param_3 = CONCAT31(param_3._1_3_,3);
      FUN_00401830(s_ui_sendmoney_txt_009e18a8);
      FUN_006ba270(local_38,&param_3,2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    FUN_00404fb0(iVar2,0x5f,local_48);
    pcVar8 = s_changebag_009e18bc;
    uVar7 = FUN_00405d30(1);
    cVar3 = FUN_004036a0(uVar7,pcVar8);
    if (cVar3 != '\0') {
      uVar7 = FUN_00405d30(2);
      uVar7 = thunk_FUN_00796f50(uVar7);
      *(char *)((int)in_ECX + 0xbf) = (char)uVar7;
      (**(code **)(*DAT_00b5a78c + 0x30))(uVar7);
      FUN_006ba410();
      FUN_00406250();
      return 1;
    }
LAB_006bae61:
    FUN_00406250();
    return 0;
  }
  if (param_1 == 10) {
    if (param_3 != 1) {
      return 0;
    }
    cVar3 = FUN_006b8ae0(param_2,param_4);
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
      cVar3 = FUN_004036a0(param_2,s_tab_chang_weapon_009e1958);
      if ((cVar3 != '\0') ||
         (cVar3 = FUN_004036a0(iVar2,s_tab_chang_shield_009e196c), cVar3 != '\0')) {
        uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x280006);
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
      pcVar8 = s_suititem_009e18c8;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        uVar7 = FUN_00405d30(1);
        uVar4 = thunk_FUN_00796f50(uVar7);
        (**(code **)(*DAT_00b5a78c + 0xc))(uVar4);
        FUN_00406250();
        return 1;
      }
      pcVar8 = s_slotbag_009e18d4;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        uVar7 = FUN_00405d30(1);
        uVar4 = thunk_FUN_00796f50(uVar7);
        uVar7 = FUN_00405d30(2);
        uVar5 = thunk_FUN_00796f50(uVar7);
        piVar1 = in_ECX + 0x2f;
        *(undefined1 *)piVar1 = *(undefined1 *)((int)in_ECX + 0xbf);
        *(undefined1 *)((int)in_ECX + 0xbd) = uVar4;
        *(undefined1 *)((int)in_ECX + 0xbe) = uVar5;
        cVar3 = (**(code **)(*DAT_00b5a78c + 0x34))(piVar1);
        if (cVar3 == '\0') {
          (**(code **)(*DAT_00b5a78c + 4))((int3)*piVar1);
          FUN_00401830(s_Call_________IINVEN__IUIHANDLER__009e18ec);
          FUN_00796d50(&local_40);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        param_2 = CONCAT31(param_2._1_3_,3);
        FUN_00401830(s_ui_socket_txt_009e18dc);
        FUN_006ba270(&local_3c,&param_2,4);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      pcVar8 = s_slotme_009e192c;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        uVar7 = FUN_00405d30(1);
        uVar4 = thunk_FUN_00796f50(uVar7);
        param_3 = CONCAT31(param_3._1_3_,uVar4);
        uVar7 = FUN_00405d30(2);
        uVar4 = thunk_FUN_00796f50(uVar7);
        param_2 = (uint)CONCAT12(param_2._3_1_,CONCAT11(uVar4,(undefined1)param_3)) << 8;
        (**(code **)(*DAT_00b5aef4 + 0x14))(&param_2);
        FUN_00406250();
        return 1;
      }
      goto LAB_006bae61;
    }
    if (param_3 == 2) {
      pcVar8 = s_slotbag_009e1934;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        local_34 = 0;
        local_30 = 0;
        local_2c = 0;
        FUN_00404fb0(iVar2,0x5f,local_38);
        uVar7 = FUN_00405d30(1);
        uVar4 = thunk_FUN_00796f50(uVar7);
        uVar7 = FUN_00405d30(2);
        uVar5 = thunk_FUN_00796f50(uVar7);
        param_3._0_2_ = CONCAT11(uVar4,*(undefined1 *)((int)in_ECX + 0xbf));
        (**(code **)(*DAT_00b5a78c + 8))(CONCAT12(uVar5,(undefined2)param_3));
        FUN_00406250();
      }
    }
    else if (param_3 == 0xd) {
      pcVar8 = s_slotbag_009e193c;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        param_3 = CONCAT31(param_3._1_3_,4);
        FUN_00401830(s_ui_stackcount_txt_009e1944);
        FUN_006ba270(local_1c,&param_3,5);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else if (((param_3 != 4) && (param_3 != 5)) ||
            (cVar3 = FUN_006b8380(iVar2,param_3,param_4), cVar3 == '\0')) goto LAB_006bae61;
    FUN_00406250();
  }
  return 1;
}


// ==== FUN_006baf00 @ 0x006baf00 ====

void FUN_006baf00(void)

{
  int iVar1;
  int *piVar2;
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
  FUN_00401740(s_UI_Game2_ui_tradewnd_txt_009e15d4,0x18);
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
  FUN_00401740(s_slotbag_009e15f0,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_34 + 0xc);
  if (uStack_14 < 0x10) {
    uStack_14 = 0xf;
    local_18 = (void *)0x0;
    (**(code **)(*piVar2 + 0x30))();
    FUN_00580be0(1);
    FUN_006ba410();
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_006bafe0 @ 0x006bafe0 ====

undefined4 FUN_006bafe0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x70110005) {
    if (uVar1 == 0x70110004) {
      FUN_006b8dc0(param_1[2],param_1[1]);
      return 1;
    }
    if (uVar1 == 0x40001) {
      FUN_006b8540(param_1);
      return 0;
    }
    if (uVar1 == 0x70110002) {
      FUN_006ba410();
      return 1;
    }
  }
  else if (uVar1 == 0x70110005) {
    FUN_006b9940(CONCAT31(0x701100,(char)param_1[1]));
    return 1;
  }
  return 0;
}


// ==== FUN_006bb060 @ 0x006bb060 ====

void FUN_006bb060(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e19d8;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  *(undefined1 *)(in_ECX + 0x2f) = 0;
  *(undefined1 *)((int)in_ECX + 0xbd) = 0;
  *(undefined1 *)((int)in_ECX + 0xbe) = 0;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)((int)in_ECX + 0xbf) = 0;
  *(undefined1 *)(in_ECX + 0x2f) = 0;
  *(undefined1 *)((int)in_ECX + 0xbd) = 0;
  *(undefined1 *)((int)in_ECX + 0xbe) = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  FUN_006baf00();
  return;
}


// ==== FUN_006bb100 @ 0x006bb100 ====

void FUN_006bb100(byte param_1)

{
  void *in_ECX;
  
  FUN_006b8d30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006bb120 @ 0x006bb120 ====

void FUN_006bb120(void)

{
  return;
}


// ==== FUN_006bb160 @ 0x006bb160 ====

bool FUN_006bb160(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5b11c + 0x18))();
  return cVar1 == '\x01';
}


// ==== FUN_006bb190 @ 0x006bb190 ====

void FUN_006bb190(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 local_10;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined4 local_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  if (puVar1 != *(undefined4 **)(in_ECX + 0x14)) {
    while( true ) {
      local_10 = *puVar1;
      local_4 = puVar1[3];
      if ((puVar1[1] == (uint)*(byte *)(in_ECX + 10)) &&
         (puVar1[2] == (uint)*(byte *)(in_ECX + 0xb))) break;
      puVar1 = puVar1 + 4;
      if (puVar1 == *(undefined4 **)(in_ECX + 0x14)) {
        return;
      }
    }
    local_c = *(undefined1 *)(in_ECX + 8);
    local_b = *(undefined1 *)(in_ECX + 10);
    local_a = *(undefined1 *)(in_ECX + 0xb);
    (**(code **)(*DAT_00b5b11c + 0x10))(&local_10,param_1);
  }
  return;
}


// ==== FUN_006bb210 @ 0x006bb210 ====

void FUN_006bb210(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  undefined4 *local_3c;
  undefined4 local_38;
  undefined1 local_34;
  byte local_33;
  byte local_32;
  undefined4 local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  local_3c = *(undefined4 **)(in_ECX + 0x10);
  if (local_3c != *(undefined4 **)(in_ECX + 0x14)) {
    do {
      local_38 = *local_3c;
      local_20 = local_3c[3];
      local_33 = *(byte *)(in_ECX + 10);
      if ((local_3c[1] == (uint)local_33) &&
         (local_32 = *(byte *)(in_ECX + 0xb), local_3c[2] == (uint)local_32)) {
        local_34 = *(undefined1 *)(in_ECX + 8);
        (**(code **)(*DAT_00b5b11c + 0xc))(&local_38,param_1);
        iVar1 = (**(code **)(*DAT_00b5a78c + 0x48))();
        if (iVar1 != 0) {
          FUN_00401740(s_slotitemlist__d__d_009e1b18,0x12);
          uVar2 = FUN_00404230(auStack_1c);
          piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
          iVar1 = (**(code **)(*piVar3 + 0x30))();
          if (0xf < uStack_4) {
            _free(pvStack_18);
            return;
          }
          uStack_4 = 0xf;
          uStack_8 = 0;
          pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
          if (iVar1 == 0) {
            return;
          }
          FUN_0057f670(0);
        }
      }
      local_3c = local_3c + 4;
    } while (local_3c != *(undefined4 **)(in_ECX + 0x14));
  }
  return;
}


// ==== FUN_006bb330 @ 0x006bb330 ====

void FUN_006bb330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e1b5c;
  if ((void *)in_ECX[4] != (void *)0x0) {
    _free((void *)in_ECX[4]);
    return;
  }
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((void *)in_ECX[4] == (void *)0x0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_006bb390 @ 0x006bb390 ====

undefined4 FUN_006bb390(int param_1,short param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar1) {
    return 0;
  }
  if (param_3 == 1) {
    if (param_2 == 1) {
      uVar2 = thunk_FUN_00796f80(param_4);
      if ((ushort)uVar2 != 0) {
        if (0xff < (ushort)uVar2) {
          uVar2 = 0xff;
        }
        FUN_006bb190(uVar2);
      }
    }
    else {
      if (param_2 == 2) {
        (**(code **)(*DAT_00b5b11c + 0x14))();
        return 1;
      }
      if (param_2 == 3) {
        FUN_006bb210(1);
        return 1;
      }
    }
  }
  return 1;
}


// ==== FUN_006bb410 @ 0x006bb410 ====

void FUN_006bb410(undefined4 *param_1)

{
  undefined4 local_10;
  uint local_c;
  uint local_8;
  undefined4 local_4;
  
  local_c = (uint)*(byte *)((int)param_1 + 5);
  local_8 = (uint)*(byte *)((int)param_1 + 6);
  local_10 = *param_1;
  local_4 = 0xffffffff;
  FUN_00680ed0(&local_10);
  return;
}


// ==== FUN_006bb450 @ 0x006bb450 ====

void FUN_006bb450(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int *in_ECX;
  undefined1 uStack_5c;
  undefined1 uStack_5b;
  undefined1 uStack_5a;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint auStack_3c [5];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  iVar1 = (**(code **)(*DAT_00b5a78c + 0x48))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    if ((iVar1 != 0) && (*(int **)(iVar1 + 0x30) != (int *)0x0)) {
      uStack_5c = (undefined1)in_ECX[2];
      uStack_5b = *(undefined1 *)((int)in_ECX + 10);
      uStack_5a = *(undefined1 *)((int)in_ECX + 0xb);
      piVar4 = (int *)(**(code **)(**(int **)(iVar1 + 0x30) + 0x14))(&uStack_5c);
      if (piVar4 != (int *)0x0) {
        uStack_40 = 0xf;
        uStack_44 = 0;
        auStack_54[0] = 0;
        iVar1 = (**(code **)(*piVar4 + 0x14))();
        if ((*(char *)(iVar1 + 0x21) == '\0') ||
           (iVar1 = (**(code **)(*piVar4 + 0x14))(), *(ushort *)(iVar1 + 0xc) < 2)) {
          (**(code **)(*DAT_00b5ad20 + 0x40))(auStack_3c,piVar4);
          FUN_00401830(&DAT_009e1ae8);
          uVar3 = FUN_00404230(auStack_28);
          FUN_00401660(uVar3,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        (**(code **)(*DAT_00b5ad20 + 0x40))(auStack_20,piVar4);
        (**(code **)(*piVar4 + 0x14))();
        FUN_00401830(s__s____d___009e1adc);
        uVar3 = FUN_00404230(&uStack_44);
        FUN_00401660(uVar3,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    return;
  }
  puVar2 = operator_new(0x58);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009b5340;
    puVar2[7] = 0xf;
    puVar2[6] = 0;
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
  auStack_3c[0] = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  FUN_00401740(s_ui_sellitem_txt_009e1acc,0xf);
  FUN_00401660(auStack_54,0,0xffffffff);
  if (auStack_3c[0] < 0x10) {
    uVar3 = (**(code **)(*in_ECX + 0x14))();
    puVar2[0x14] = uVar3;
    *(undefined2 *)(puVar2 + 0x13) = 0x902;
    FUN_00797a20(puVar2);
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_006bb750 @ 0x006bb750 ====

undefined4 FUN_006bb750(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_slotitemlist_009e1b2c,0xc);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = (**(code **)(*DAT_00b5a78c + 0x48))();
  if (iVar1 != 0) {
    FUN_006bb450();
  }
  return 1;
}


// ==== FUN_006bb790 @ 0x006bb790 ====

void FUN_006bb790(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int in_ECX;
  uint uVar6;
  void *pvStack_1c;
  uint uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  *(char *)(in_ECX + 8) = (char)param_1;
  if (*(void **)(in_ECX + 0x10) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x10));
    return;
  }
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  uVar3 = (**(code **)(*DAT_00b5b11c + 4))();
  uVar6 = 0;
  if (uVar3 != 0) {
    do {
      puVar4 = (undefined4 *)(**(code **)(*DAT_00b5b11c + 8))(uVar6);
      uVar1 = puVar4[1];
      if ((char)uVar1 == (char)param_1) {
        uStack_18 = uVar1 >> 8 & 0xff;
        iVar2 = *(int *)(in_ECX + 0x10);
        uStack_14 = uVar1 >> 0x10 & 0xff;
        uStack_10 = 0xffffffff;
        pvStack_1c = (void *)*puVar4;
        if ((iVar2 == 0) ||
           ((uint)(*(int *)(in_ECX + 0x18) - iVar2 >> 4) <=
            (uint)(*(int *)(in_ECX + 0x14) - iVar2 >> 4))) {
          FUN_00680c50(*(undefined4 *)(in_ECX + 0x14),1,&pvStack_1c);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x14);
          FUN_00680b80(iVar2,1,&pvStack_1c,in_ECX + 0xc,param_1);
          *(int *)(in_ECX + 0x14) = iVar2 + 0x10;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar3);
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = uStack_18 & 0xffffff00;
  FUN_00401740(s_slotitemlist_009e1a84,0xc);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  if (uStack_8 < 0x10) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    (**(code **)(*piVar5 + 0x30))();
    FUN_005817e0(in_ECX + 0xc,0);
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006bb900 @ 0x006bb900 ====

undefined4 FUN_006bb900(int param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined4 extraout_EAX;
  int *piVar4;
  undefined4 extraout_EAX_00;
  int in_ECX;
  uint uVar5;
  byte bVar6;
  byte ****ppppbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  byte local_25;
  undefined1 local_1c [4];
  byte ****local_18 [4];
  uint local_8;
  uint local_4;
  
  bVar2 = 0xff;
  local_25 = 0;
  do {
    FUN_00401740(s_btn_tab_u_009e1b3c,9);
    FUN_00404230(local_1c);
    uVar1 = *(uint *)(param_1 + 0x14);
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      pbVar8 = (byte *)(param_1 + 4);
    }
    else {
      pbVar8 = *(byte **)(param_1 + 4);
    }
    if (local_8 == 0) {
LAB_006bb996:
      if ((uVar1 <= local_8) && (local_8 == uVar1)) {
        bVar2 = local_25;
      }
    }
    else {
      uVar5 = local_8;
      if (uVar1 <= local_8) {
        uVar5 = uVar1;
      }
      ppppbVar7 = local_18[0];
      if (local_4 < 0x10) {
        ppppbVar7 = (byte ****)local_18;
      }
      bVar9 = false;
      iVar3 = 0;
      bVar10 = true;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        bVar9 = *(byte *)ppppbVar7 < *pbVar8;
        bVar10 = *(byte *)ppppbVar7 == *pbVar8;
        ppppbVar7 = (byte ****)((int)ppppbVar7 + 1);
        pbVar8 = pbVar8 + 1;
      } while (bVar10);
      if (!bVar10) {
        iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      }
      if (iVar3 == 0) goto LAB_006bb996;
    }
    if (0xf < local_4) {
      _free(local_18[0]);
      return extraout_EAX;
    }
    local_25 = local_25 + 1;
    local_4 = 0xf;
    local_8 = 0;
    local_18[0] = (byte ****)((uint)local_18[0] & 0xffffff00);
    if (4 < local_25) {
      if (bVar2 == 0xff) {
        return 0;
      }
      bVar6 = 0;
      do {
        local_4 = 0xf;
        local_8 = 0;
        FUN_00401740(s_btn_tab_u_009e1b48,9);
        FUN_00404230(local_1c);
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
        (**(code **)(*piVar4 + 0x30))();
        FUN_00558730(bVar6 == bVar2);
        if (0xf < local_4) {
          _free(local_18[0]);
          return extraout_EAX_00;
        }
        bVar6 = bVar6 + 1;
        local_4 = 0xf;
        local_8 = 0;
        local_18[0] = (byte ****)((uint)local_18[0] & 0xffffff00);
      } while (bVar6 < 5);
      FUN_006bb790(bVar2);
      return 1;
    }
  } while( true );
}


// ==== FUN_006bbab0 @ 0x006bbab0 ====

undefined4 FUN_006bbab0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70100002) {
    FUN_006bb790(*(undefined1 *)(in_ECX + 8));
    return 1;
  }
  return 0;
}


// ==== FUN_006bbae0 @ 0x006bbae0 ====

undefined4 FUN_006bbae0(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int *in_ECX;
  char *pcVar5;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      cVar1 = FUN_006bb900(param_2);
      if (cVar1 == '\x01') {
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_exit_009e1a94);
      if ((cVar1 == '\0') && (cVar1 = FUN_004036a0(param_2,s_btn_close_009e1aa0), cVar1 == '\0')) {
        return 0;
      }
      (**(code **)(*in_ECX + 0x10))();
      return 1;
    }
  }
  else if (param_1 == 10) {
    if ((param_3 == 1) && (cVar1 = FUN_006bb750(param_2,param_4), cVar1 != '\0')) {
      return 1;
    }
  }
  else if (param_1 == 0xf) {
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_00404fb0(param_2,0x5f,local_10);
    if (param_3 == 1) {
      pcVar5 = s_slotitemlist_009e1aac;
      uVar4 = FUN_00405d30(0);
      cVar1 = FUN_004036a0(uVar4,pcVar5);
      if (cVar1 != '\0') {
        uVar4 = FUN_00405d30(1);
        uVar2 = thunk_FUN_00796f50(uVar4);
        uVar4 = FUN_00405d30(2);
        uVar3 = thunk_FUN_00796f50(uVar4);
        *(char *)((int)in_ECX + 9) = (char)in_ECX[2];
        *(undefined1 *)((int)in_ECX + 10) = uVar2;
        *(undefined1 *)((int)in_ECX + 0xb) = uVar3;
        FUN_006bb450();
        FUN_00406250();
        return 1;
      }
    }
    else if (param_3 == 2) {
      pcVar5 = s_slotitemlist_009e1abc;
      uVar4 = FUN_00405d30(0);
      cVar1 = FUN_004036a0(uVar4,pcVar5);
      if (cVar1 != '\0') {
        uVar4 = FUN_00405d30(1);
        uVar2 = thunk_FUN_00796f50(uVar4);
        uVar4 = FUN_00405d30(2);
        uVar3 = thunk_FUN_00796f50(uVar4);
        *(char *)((int)in_ECX + 9) = (char)in_ECX[2];
        *(undefined1 *)((int)in_ECX + 10) = uVar2;
        *(undefined1 *)((int)in_ECX + 0xb) = uVar3;
        FUN_006bb210(1);
      }
      FUN_00406250();
      return 1;
    }
    FUN_00406250();
  }
  return 0;
}


// ==== FUN_006bbcb0 @ 0x006bbcb0 ====

/* WARNING: Removing unreachable block (ram,0x006bbdcf) */

void FUN_006bbcb0(ushort param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  uint unaff_retaddr;
  undefined4 uStack_4b0;
  void *pvStack_494;
  void *local_484;
  uint uStack_480;
  undefined1 auStack_478 [8];
  uint uStack_470;
  
  uStack_4b0 = (void **)(uint)param_1;
  FUN_00401740(s_btn_tab_d_009e1a78,9);
  FUN_00404230(&local_484);
  uStack_4b0 = &local_484;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 == (int *)0x0) {
    if (0xf < uStack_470) {
      _free(local_484);
      return;
    }
  }
  else {
    (**(code **)(*piVar1 + 0x24))();
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,unaff_retaddr | 0x7d20000);
    FUN_00401660(uVar2,0,0xffffffff);
    FUN_00505f10();
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
    FUN_00505cc0(piVar1 + 0x32);
    FUN_00505850(auStack_478 + -0x3c);
    FUN_00401660(&uStack_4b0,0,0xffffffff);
    (**(code **)(*piVar1 + 0x24))(auStack_478);
    FUN_00505d80();
    uStack_4b0 = (void **)((uint)uStack_4b0 & 0xffffff00);
    if (0xf < uStack_480) {
      _free(pvStack_494);
      return;
    }
  }
  return;
}


// ==== FUN_006bbe10 @ 0x006bbe10 ====

void FUN_006bbe10(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  int *piVar9;
  int iStack_48;
  int iStack_44;
  ushort local_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar5 = *DAT_00b5aa2c;
  uVar3 = (**(code **)(*DAT_00b5b120 + 0x18))();
  piVar4 = (int *)(**(code **)(iVar5 + 8))(uVar3);
  iVar5 = (**(code **)(*piVar4 + 4))();
  uVar3 = *(undefined4 *)(iVar5 + 0x1ec);
  iVar5 = 0;
  iStack_48 = 0;
  do {
    local_40 = (ushort)uVar3;
    if ((ushort)iVar5 < local_40) {
      iVar6 = (**(code **)(*piVar4 + 4))();
      pcVar1 = (char *)(iVar6 + 0xc + iStack_48);
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      pcVar7 = pcVar1;
      do {
        cVar2 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      FUN_00401740(pcVar1,(int)pcVar7 - (int)(pcVar1 + 1));
      uVar8 = thunk_FUN_00796fb0(auStack_20);
      FUN_006bbcb0(iVar5,uVar8);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    }
    else {
      FUN_00401740(s_btn_tab_d_009e1a6c,9);
      FUN_00404230(auStack_3c);
      piVar9 = (int *)(**(code **)(**(int **)(iStack_44 + 4) + 0x34))(auStack_3c);
      if (piVar9 != (int *)0x0) {
        (**(code **)(*piVar9 + 0x24))(0);
      }
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    }
    iStack_48 = iStack_48 + 0x60;
    iVar5 = iVar5 + 1;
    if (4 < (ushort)iVar5) {
      return;
    }
  } while( true );
}


// ==== FUN_006bbf80 @ 0x006bbf80 ====

void FUN_006bbf80(void)

{
  int iVar1;
  int *piVar2;
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
  FUN_00401740(s_UI_Game2_ui_storewnd_txt_009e1a44,0x18);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  FUN_006bbe10();
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_btn_tab0_009e1a60,8);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_34 + 0xc);
  (**(code **)(*piVar2 + 0x30))();
  FUN_00558730(1);
  if (uStack_14 < 0x10) {
    FUN_006bb790(0);
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_006bc050 @ 0x006bc050 ====

/* WARNING: Removing unreachable block (ram,0x006bc077) */

void FUN_006bc050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e1b5c;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  *(undefined1 *)((int)in_ECX + 0xb) = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[1] = 0;
  FUN_006bbf80();
  return;
}


// ==== FUN_006bc0a0 @ 0x006bc0a0 ====

void FUN_006bc0a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006bb330();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006bc0c0 @ 0x006bc0c0 ====

void FUN_006bc0c0(void)

{
  return;
}


// ==== FUN_006bc0d0 @ 0x006bc0d0 ====

void FUN_006bc0d0(void)

{
  FUN_005811f0();
  return;
}


// ==== FUN_006bc180 @ 0x006bc180 ====

uint FUN_006bc180(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x5c))();
  if ((char)uVar1 == '\x01') {
    uVar1 = (**(code **)(*DAT_00b5a78c + 0x24))();
    if ((char)uVar1 == '\x01') {
      *(undefined1 *)(in_ECX + 0x57) = 0;
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006bc1b0 @ 0x006bc1b0 ====

void FUN_006bc1b0(undefined4 param_1)

{
  int in_ECX;
  
  if ((short)param_1 != 0) {
    (**(code **)(*DAT_00b5a78c + 0x1c))
              (CONCAT13((char)((uint)(in_ECX + 0x50) >> 0x18),*(undefined3 *)(in_ECX + 0x50)),
               param_1);
  }
  return;
}


// ==== FUN_006bc210 @ 0x006bc210 ====

undefined4 FUN_006bc210(int param_1,ushort param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar1) {
    return 0;
  }
  if (param_3 == 1) {
    switch(param_2 - 1) {
    case 0:
      iVar1 = *DAT_00b5a78c;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x28))(uVar2);
      return 1;
    case 1:
      iVar1 = *DAT_00b5aef4;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x10))(uVar2);
      return 1;
    case 2:
      iVar1 = *DAT_00b5b114;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x34))(uVar2);
      return 1;
    case 3:
      (**(code **)(*DAT_00b5a78c + 4))((int3)in_ECX[0x14]);
      return 1;
    case 4:
      uVar2 = thunk_FUN_00796f80(param_4);
      FUN_006bc1b0(uVar2);
    }
  }
  return 1;
}


// ==== FUN_006bc310 @ 0x006bc310 ====

void FUN_006bc310(undefined2 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_22 [2];
  void *apvStack_20 [4];
  undefined4 uStack_10;
  uint uStack_c;
  uint uStack_4;
  
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x44))(param_1);
  *(undefined4 *)(in_ECX + 0x48) = uVar1;
  FUN_00401740(s_suititem__d_009e1c30,0xb);
  uVar1 = FUN_00404230(apvStack_20);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
  if (0xf < uStack_c) {
    _free(apvStack_20[0]);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  apvStack_20[0] = (void *)((uint)apvStack_20[0] & 0xffffff00);
  (**(code **)(*piVar2 + 0x30))();
  if (*(int **)(in_ECX + 0x48) == (int *)0x0) {
    uStack_4 = 0;
    FUN_005802c0(&uStack_4,auStack_22 + -10);
    FUN_00580870(0,1);
    return;
  }
  uStack_4 = (**(code **)(**(int **)(in_ECX + 0x48) + 0x1c))();
  uStack_4 = uStack_4 & 0xffff;
  (**(code **)(**(int **)(in_ECX + 0x48) + 0x2c))();
  FUN_005802c0(&uStack_4,auStack_22 + -10);
  FUN_00580870(*(undefined4 *)(in_ECX + 0x48),1);
  return;
}


// ==== FUN_006bc420 @ 0x006bc420 ====

void FUN_006bc420(void)

{
  uint uVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int in_ECX;
  undefined4 unaff_EBX;
  uint unaff_EBP;
  uint uVar8;
  undefined4 uStack_24;
  void *pvStack_20;
  void *pvStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_10;
  uint uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  uVar2 = (**(code **)(*DAT_00b5ad1c + 0x7c))();
  uStack_24._0_3_ = CONCAT12(uVar2,(undefined2)uStack_24);
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_btn_changebag_2_009e1c64,0xf);
  pvStack_20 = (void *)CONCAT31(pvStack_20._1_3_,2 < uStack_24._2_1_);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  if (piVar5 != (int *)0x0) {
    cVar3 = (**(code **)(*piVar5 + 0x28))();
    if (cVar3 != (char)uStack_24) {
      (**(code **)(*piVar5 + 0x24))(uStack_24);
    }
  }
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_btn_changebag_3_009e1c74,0xf);
  uStack_24 = CONCAT31(uStack_24._1_3_,3 < (byte)((uint)unaff_EBX >> 0x10));
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
  if ((piVar5 != (int *)0x0) && (cVar3 = (**(code **)(*piVar5 + 0x28))(), cVar3 != (char)unaff_EBX))
  {
    (**(code **)(*piVar5 + 0x24))(unaff_EBX);
  }
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  bVar4 = (byte)(unaff_EBP >> 0x10);
  if (((byte)uStack_4 < bVar4) && (uVar8 = unaff_EBP & 0xffffff, bVar4 != 0)) {
    do {
      FUN_00401740(s_btn_changebag__d_009e1c84,0x10);
      uVar6 = FUN_00404230(&uStack_24);
      piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar6);
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
      uStack_c = 0xf;
      uStack_10 = 0;
      pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
      cVar3 = (char)(uVar8 >> 0x18);
      if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
        FUN_00558730(cVar3 == (byte)uStack_4);
      }
      bVar4 = cVar3 + 1;
      uVar1 = uVar8 >> 0x10;
      uVar8 = CONCAT13(bVar4,(int3)uVar8);
    } while (bVar4 < (byte)uVar1);
  }
  return;
}


// ==== FUN_006bc5d0 @ 0x006bc5d0 ====

undefined4 FUN_006bc5d0(void)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined2 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a78c + 0x48))();
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x2c))();
    uStack_20 = CONCAT11(uStack_20._1_1_,*(undefined1 *)(in_ECX + 0x53));
    uVar1 = FUN_00802534();
    uStack_20 = CONCAT11(uVar1,(undefined1)uStack_20);
    uVar1 = FUN_00802534();
    (**(code **)(*DAT_00b5a78c + 4))(CONCAT12(uVar1,uStack_20));
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_Call_________IINVEN__IUIHANDLER__009e1e74,0x3c);
    FUN_00796d50(&uStack_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_006bc710 @ 0x006bc710 ====

void FUN_006bc710(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = &PTR_FUN_009e1ec8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  iVar1 = 4;
  puVar2 = in_ECX + 0x13;
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


// ==== FUN_006bc760 @ 0x006bc760 ====

/* WARNING: Removing unreachable block (ram,0x006bc8f5) */

void FUN_006bc760(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_c2 [18];
  void *apvStack_b0 [4];
  undefined4 uStack_a0;
  uint uStack_9c;
  void *apvStack_94 [4];
  undefined4 uStack_84;
  uint uStack_80;
  void *apvStack_78 [4];
  undefined4 uStack_68;
  uint uStack_64;
  void *apvStack_5c [4];
  undefined4 uStack_4c;
  uint uStack_48;
  void *apvStack_40 [4];
  undefined4 uStack_30;
  uint uStack_2c;
  void *apvStack_24 [2];
  undefined1 auStack_1c [12];
  uint uStack_10;
  
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x40))();
  (**(code **)(*DAT_00b5ad20 + 0x48))(auStack_1c,uVar1);
  FUN_00401740(s_lbl_money_009e1c24,9);
  uVar1 = FUN_004041a0(apvStack_5c,uVar1,s_<_color>_009e1c0c);
  uVar1 = FUN_004022a0(apvStack_94,s_<color__009e1c1c,apvStack_24,&DAT_009e1c18,uVar1);
  uVar1 = FUN_00402220(apvStack_b0,uVar1);
  uVar1 = FUN_00405bd0(apvStack_78,uVar1);
  uVar1 = FUN_00402220(apvStack_40,uVar1);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_c2 + -10);
  (**(code **)(*piVar2 + 0x30))();
  FUN_0055a260(uVar1);
  if (0xf < uStack_2c) {
    _free(apvStack_40[0]);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  apvStack_40[0] = (void *)((uint)apvStack_40[0] & 0xffffff00);
  if (0xf < uStack_64) {
    _free(apvStack_78[0]);
    return;
  }
  uStack_64 = 0xf;
  uStack_68 = 0;
  apvStack_78[0] = (void *)((uint)apvStack_78[0] & 0xffffff00);
  if (0xf < uStack_9c) {
    _free(apvStack_b0[0]);
    return;
  }
  uStack_9c = 0xf;
  uStack_a0 = 0;
  apvStack_b0[0] = (void *)((uint)apvStack_b0[0] & 0xffffff00);
  if (0xf < uStack_80) {
    _free(apvStack_94[0]);
    return;
  }
  uStack_80 = 0xf;
  uStack_84 = 0;
  apvStack_94[0] = (void *)((uint)apvStack_94[0] & 0xffffff00);
  if (0xf < uStack_48) {
    _free(apvStack_5c[0]);
    return;
  }
  uStack_48 = 0xf;
  uStack_4c = 0;
  apvStack_5c[0] = (void *)((uint)apvStack_5c[0] & 0xffffff00);
  if (uStack_10 < 0x10) {
    return;
  }
  _free(apvStack_24[0]);
  return;
}


// ==== FUN_006bc930 @ 0x006bc930 ====

void FUN_006bc930(void)

{
  undefined1 uVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = 0;
  if (*(char *)(in_ECX + 0x55) != '\0') {
    FUN_006bc310(0x12);
    uVar1 = (**(code **)(*DAT_00b5a78c + 0x54))();
    *(undefined1 *)(in_ECX + 0x54) = uVar1;
    return;
  }
  do {
    if (((ushort)iVar2 < 0xd) || (0x12 < (ushort)iVar2)) {
      FUN_006bc310(iVar2);
    }
    iVar2 = iVar2 + 1;
  } while ((ushort)iVar2 < 0x15);
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x54))();
  *(undefined1 *)(in_ECX + 0x54) = uVar1;
  return;
}


// ==== FUN_006bc990 @ 0x006bc990 ====

void FUN_006bc990(void)

{
  int iVar1;
  byte bVar2;
  uint *puVar3;
  int in_ECX;
  uint unaff_EBX;
  undefined4 *puVar4;
  int iVar5;
  uint local_20;
  undefined1 auStack_1c [8];
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  puVar4 = (undefined4 *)(in_ECX + 0xc);
  iVar5 = 4;
  do {
    if ((void *)*puVar4 != (void *)0x0) {
      _free((void *)*puVar4);
      return;
    }
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4 = puVar4 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  (**(code **)(*DAT_00b5a78c + 0x38))(&local_20);
  uStack_8 = 0xffffffff;
  if (local_20 != 0) {
    do {
      uStack_10 = unaff_EBX >> 8 & 0xff;
      iVar5 = (unaff_EBX & 0xff) * 0x10;
      iVar1 = *(int *)(iVar5 + 0xc + in_ECX);
      uStack_c = unaff_EBX >> 0x10 & 0xff;
      iVar5 = iVar5 + 8 + in_ECX;
      uStack_14 = local_20;
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(iVar5 + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(iVar5 + 8) - iVar1 >> 4))) {
        FUN_00680c50(*(undefined4 *)(iVar5 + 8),1,&uStack_14);
      }
      else {
        iVar1 = *(int *)(iVar5 + 8);
        FUN_00680b80(iVar1,1,&uStack_14,iVar5,unaff_EBX);
        *(int *)(iVar5 + 8) = iVar1 + 0x10;
      }
      puVar3 = (uint *)(**(code **)(*DAT_00b5a78c + 0x3c))(auStack_1c);
      unaff_EBX = *puVar3;
      local_20 = puVar3[1];
    } while (local_20 != 0);
  }
  bVar2 = (**(code **)(*DAT_00b5a78c + 0x50))();
  *(byte *)(in_ECX + 0x53) = bVar2;
  FUN_005817e0((uint)bVar2 * 0x10 + 8 + in_ECX,0);
  return;
}


// ==== FUN_006bcac0 @ 0x006bcac0 ====

/* WARNING: Removing unreachable block (ram,0x006bcb47) */

void FUN_006bcac0(undefined4 param_1,byte *param_2,ushort param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
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
  if (0xff < param_3) {
    param_3 = 0xff;
  }
  *(ushort *)(puVar1 + 0x13) = (ushort)*param_2 << 8 | param_3;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_006bcb70 @ 0x006bcb70 ====

undefined4 FUN_006bcb70(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  char *pcVar6;
  undefined1 auStack_e [14];
  
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  iVar4 = (**(code **)(*piVar3 + 0x30))();
  if (iVar4 != 0) {
    if (param_1 != 4) {
      return 0;
    }
    iVar4 = (**(code **)(*DAT_00b5a78c + 0x48))();
    if (iVar4 != 0) {
      FUN_00404fb0(4,0x5f,auStack_e + -6);
      pcVar6 = s_suititem_009e1eb4;
      uVar5 = FUN_00405d30(0);
      cVar1 = FUN_004036a0(uVar5,pcVar6);
      if (cVar1 == '\0') {
        cVar1 = (**(code **)(*DAT_00b5ad20 + 0x34))(iVar4);
        if (cVar1 != '\0') {
          FUN_0057f390(0x40000060);
          FUN_00406250();
          return 1;
        }
      }
      else {
        uVar5 = FUN_00405d30(1);
        uVar2 = thunk_FUN_00796f50(uVar5);
        cVar1 = (**(code **)(*DAT_00b5ad20 + 0x30))(uVar2,iVar4);
        *(char *)(in_ECX + 0x56) = cVar1;
        if (cVar1 != '\0') {
          FUN_0057f390(0x40000060);
          FUN_00406250();
          return 1;
        }
      }
      FUN_0057f390(0x60b00000);
      FUN_00406250();
      return 1;
    }
    *(undefined1 *)(in_ECX + 0x56) = 1;
    FUN_0057f390(0x40000060);
  }
  return 1;
}


// ==== FUN_006bccc0 @ 0x006bccc0 ====

undefined4 FUN_006bccc0(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar4;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  iVar4 = param_1;
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_btn_exit_009e1d84,8);
  if (iVar2 == 0) {
    (**(code **)(*DAT_00b5a78c + 0x24))();
    *(undefined1 *)(in_ECX + 0x57) = 0;
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(iVar4 + 0x14),s_btn_equip_item_009e1d90,0xe);
  if (iVar2 == 0) {
    *(undefined1 *)(in_ECX + 0x55) = 0;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = local_18 & 0xffffff00;
    FUN_00401740(s_pan_equip_009e1da0,9);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
    if ((piVar3 != (int *)0x0) && (cVar1 = (**(code **)(*piVar3 + 0x28))(), cVar1 != '\x01')) {
      (**(code **)(*piVar3 + 0x24))(1);
    }
    if (0xf < local_8) {
      _free(local_1c);
      return extraout_EAX;
    }
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401740(s_pan_bg_cos_009e1dac,10);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
    if ((piVar3 != (int *)0x0) && (cVar1 = (**(code **)(*piVar3 + 0x28))(), cVar1 != '\0')) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
    if (0xf < uStack_c) {
      _free(unaff_EBX);
      return extraout_EAX_00;
    }
    uStack_c = 0xf;
    local_10 = 0;
    FUN_00401740(s_btn_equip_item_009e1db8,0xe);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x24);
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
      FUN_00558730(1);
    }
    if (0xf < local_10) {
      _free(unaff_ESI);
      return extraout_EAX_01;
    }
    local_10 = 0xf;
    local_14 = 0;
    FUN_00401740(s_btn_cos_item_009e1dc8,0xc);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x28);
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
      FUN_00558730(0);
    }
  }
  else {
    iVar2 = FUN_00403620(0,*(undefined4 *)(iVar4 + 0x14),s_btn_cos_item_009e1dd8,0xc);
    if (iVar2 != 0) {
      cVar1 = FUN_004036a0(iVar4,s_btn_drop_009e1e20);
      if (cVar1 == '\0') {
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
        FUN_00404fb0(iVar4,0x5f,&local_1c);
        pcVar6 = s_changebag_009e1e68;
        uVar5 = FUN_00405d30(1);
        cVar1 = FUN_004036a0(uVar5,pcVar6);
        if (cVar1 == '\0') {
          FUN_00406250();
          return 0;
        }
        uVar5 = FUN_00405d30(2);
        uVar5 = thunk_FUN_00796f50(uVar5);
        *(char *)(in_ECX + 0x53) = (char)uVar5;
        (**(code **)(*DAT_00b5a78c + 0x30))(uVar5);
        FUN_00406250();
        return 1;
      }
      iVar4 = (**(code **)(*DAT_00b5a78c + 100))();
      if (iVar4 == 0) {
        param_1 = CONCAT31(param_1._1_3_,5);
        FUN_00401830(s_ui_dropmoney_txt_009e1e2c);
        uVar5 = 1;
      }
      else {
        iVar4 = (**(code **)(*DAT_00b5a78c + 100))();
        if (iVar4 == 2) {
          param_1 = CONCAT31(param_1._1_3_,3);
          FUN_00401830(s_ui_sendmoney_txt_009e1e40);
          uVar5 = 2;
        }
        else {
          iVar4 = (**(code **)(*DAT_00b5a78c + 100))();
          if (iVar4 != 3) {
            return 1;
          }
          param_1 = CONCAT31(param_1._1_3_,3);
          FUN_00401830(s_ui_savemoney_txt_009e1e54);
          uVar5 = 3;
        }
      }
      FUN_006bcac0(&local_1c,&param_1,uVar5);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    *(undefined1 *)(in_ECX + 0x55) = 1;
    FUN_00401830(s_pan_equip_009e1de8);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
    if ((piVar3 != (int *)0x0) && (cVar1 = (**(code **)(*piVar3 + 0x28))(), cVar1 != '\0')) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
    if (0xf < local_8) {
      _free(local_1c);
      return extraout_EAX_03;
    }
    FUN_00401830(s_pan_bg_cos_009e1df4);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
    if ((piVar3 != (int *)0x0) && (cVar1 = (**(code **)(*piVar3 + 0x28))(), cVar1 != '\x01')) {
      (**(code **)(*piVar3 + 0x24))(1);
    }
    if (0xf < uStack_c) {
      _free(unaff_EBX);
      return extraout_EAX_04;
    }
    FUN_00401830(s_btn_equip_item_009e1e00);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x24);
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
      FUN_00558730(0);
    }
    if (0xf < local_10) {
      _free(unaff_ESI);
      return extraout_EAX_05;
    }
    FUN_00401830(s_btn_cos_item_009e1e10);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x28);
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
      FUN_00558730(1);
    }
  }
  if (local_14 < 0x10) {
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    return 0;
  }
  _free(unaff_EDI);
  return extraout_EAX_02;
}


// ==== FUN_006bd100 @ 0x006bd100 ====

undefined4 FUN_006bd100(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined3 *puVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int in_ECX;
  char *pcVar7;
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_1c [28];
  
  uVar5 = param_2;
  if (param_1 == 1) {
    if ((param_3 == 1) && (cVar2 = FUN_006bccc0(param_2), cVar2 != '\0')) {
      return 1;
    }
  }
  else if (param_1 == 10) {
    if ((param_3 == 1) && (cVar2 = FUN_006bc5d0(param_2,param_4), cVar2 != '\0')) {
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
        pcVar7 = s_suititem_009e1cd4;
        uVar5 = FUN_00405d30(0);
        cVar2 = FUN_004036a0(uVar5,pcVar7);
        if (cVar2 == '\0') {
          pcVar7 = s_slotbag_009e1ce0;
          uVar5 = FUN_00405d30(0);
          cVar2 = FUN_004036a0(uVar5,pcVar7);
          if (cVar2 != '\0') {
            uVar5 = FUN_00405d30(1);
            uVar3 = thunk_FUN_00796f50(uVar5);
            uVar5 = FUN_00405d30(2);
            uVar4 = thunk_FUN_00796f50(uVar5);
            puVar1 = (undefined3 *)(in_ECX + 0x50);
            *(undefined1 *)puVar1 = *(undefined1 *)(in_ECX + 0x53);
            *(undefined1 *)(in_ECX + 0x51) = uVar3;
            *(undefined1 *)(in_ECX + 0x52) = uVar4;
            cVar2 = (**(code **)(*DAT_00b5a78c + 0x34))(puVar1);
            if (cVar2 == '\0') {
              (**(code **)(*DAT_00b5a78c + 4))(*puVar1);
              FUN_00401830(s_Call_________IINVEN__IUIHANDLER__009e1cf8);
              FUN_00796d50(&local_40);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            param_2 = CONCAT31(param_2._1_3_,3);
            FUN_00401830(s_ui_socket_txt_009e1ce8);
            FUN_006bcac0(&local_3c,&param_2,4);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
LAB_006bd452:
          FUN_00406250();
          return 0;
        }
        if (*(char *)(in_ECX + 0x56) != '\0') {
          uVar5 = FUN_00405d30(1);
          uVar3 = thunk_FUN_00796f50(uVar5);
          (**(code **)(*DAT_00b5a78c + 0xc))(uVar3);
          FUN_00406250();
          return 1;
        }
      }
      else if (param_3 == 2) {
        pcVar7 = s_slotbag_009e1d38;
        uVar6 = FUN_00405d30(0);
        cVar2 = FUN_004036a0(uVar6,pcVar7);
        if (cVar2 != '\0') {
          local_34 = 0;
          local_30 = 0;
          local_2c = 0;
          FUN_00404fb0(uVar5,0x5f,local_38);
          uVar5 = FUN_00405d30(1);
          uVar3 = thunk_FUN_00796f50(uVar5);
          uVar5 = FUN_00405d30(2);
          uVar4 = thunk_FUN_00796f50(uVar5);
          param_3._0_2_ = CONCAT11(uVar3,*(undefined1 *)(in_ECX + 0x53));
          (**(code **)(*DAT_00b5a78c + 8))(CONCAT12(uVar4,(undefined2)param_3));
          FUN_00406250();
        }
      }
      else if (param_3 == 0xd) {
        pcVar7 = s_slotbag_009e1d40;
        uVar5 = FUN_00405d30(0);
        cVar2 = FUN_004036a0(uVar5,pcVar7);
        if (cVar2 != '\0') {
          param_3 = CONCAT31(param_3._1_3_,4);
          FUN_00401830(s_ui_stackcount_txt_009e1d48);
          FUN_006bcac0(local_1c,&param_3,5);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
      else if (((param_3 != 4) && (param_3 != 5)) ||
              (cVar2 = FUN_006bcb70(uVar5,param_3,param_4), cVar2 == '\0')) goto LAB_006bd452;
      FUN_00406250();
      return 1;
    }
    if (((param_1 == 0xb) && (param_3 == 1)) &&
       ((cVar2 = FUN_004036a0(param_2,s_tab_chang_weapon_009e1d5c), cVar2 != '\0' ||
        (cVar2 = FUN_004036a0(uVar5,s_tab_chang_shield_009e1d70), cVar2 != '\0')))) {
      *(char *)(in_ECX + 0x54) = (char)param_4;
      (**(code **)(*DAT_00b5a78c + 0x10))(param_4);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006bd4d0 @ 0x006bd4d0 ====

void FUN_006bd4d0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  int *piVar5;
  void *in_ECX;
  int unaff_EBX;
  undefined4 uVar6;
  undefined1 auStack_51e [18];
  uint uStack_50c;
  undefined4 *puStack_504;
  void *local_4f8;
  undefined1 uStack_4f4;
  undefined4 uStack_4e8;
  uint uStack_4e4;
  undefined4 uStack_4e0;
  void *pvStack_4dc;
  undefined1 uStack_4d8;
  undefined4 uStack_4cc;
  uint uStack_4c8;
  undefined4 uStack_4c4;
  void *local_4bc;
  undefined1 local_4b8;
  undefined4 uStack_4ac;
  uint local_4a8;
  void *local_4a4;
  undefined1 uStack_4a0;
  undefined4 uStack_494;
  uint uStack_490;
  undefined4 uStack_48c;
  void *pvStack_488;
  undefined1 uStack_484;
  uint uStack_474;
  undefined4 uStack_470;
  undefined1 auStack_3a8 [936];
  
  iVar2 = FUN_00503b60();
  *(undefined1 *)(iVar2 + 0x1d) = 1;
  *(int *)(iVar2 + 4) = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(iVar2 + 8) = iVar2;
  local_4f8 = (void *)0x0;
  local_4a4 = (void *)0xf;
  local_4a8 = 0;
  local_4b8 = 0;
  FUN_00401740(s_btn_drop_009e1c98,8);
  piVar3 = (int *)(**(code **)(**(int **)((int)in_ECX + 4) + 0x34))(&local_4bc);
  piVar3 = (int *)(**(code **)(*piVar3 + 0x30))();
  if (0xf < local_4a8) {
    _free(local_4bc);
    return;
  }
  local_4a8 = 0xf;
  uStack_4ac = 0;
  local_4bc = (void *)((uint)local_4bc & 0xffffff00);
  FUN_00505f10();
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    pvVar4 = (void *)0x0;
  }
  else {
    pvVar4 = (void *)FUN_00505f10();
  }
  FUN_00505cc0(piVar3 + 0x32);
  FUN_00505cc0(auStack_3a8);
  iVar2 = (**(code **)(*DAT_00b5a78c + 100))();
  if (iVar2 == 0) {
    uStack_48c = 0xf;
    uStack_490 = 0;
    uStack_4a0 = 0;
    FUN_00401740(s_btn_drop_009e1ca4,8);
    piVar5 = (int *)(**(code **)(**(int **)(unaff_EBX + 4) + 0x34))(&local_4a4);
    if ((piVar5 != (int *)0x0) && (cVar1 = (**(code **)(*piVar5 + 0x28))(), cVar1 != '\x01')) {
      (**(code **)(*piVar5 + 0x24))(1);
    }
    if (0xf < uStack_490) {
      _free(local_4a4);
      return;
    }
    uStack_490 = 0xf;
    uStack_494 = 0;
    local_4a4 = (void *)((uint)local_4a4 & 0xffffff00);
    uVar6 = 0x1040007;
  }
  else if (iVar2 == 2) {
    uStack_4e0 = 0xf;
    uStack_4e4 = 0;
    uStack_4f4 = 0;
    FUN_00401740(s_btn_drop_009e1cb0,8);
    piVar5 = (int *)(**(code **)(**(int **)(unaff_EBX + 4) + 0x34))(&local_4f8);
    if ((piVar5 != (int *)0x0) && (cVar1 = (**(code **)(*piVar5 + 0x28))(), cVar1 != '\x01')) {
      (**(code **)(*piVar5 + 0x24))(1);
    }
    if (0xf < uStack_4e4) {
      _free(local_4f8);
      return;
    }
    uStack_4e4 = 0xf;
    uStack_4e8 = 0;
    local_4f8 = (void *)((uint)local_4f8 & 0xffffff00);
    uVar6 = 0x1040008;
  }
  else {
    if (iVar2 != 3) {
      uStack_470 = 0xf;
      uStack_474 = 0;
      uStack_484 = 0;
      FUN_00401740(s_btn_drop_009e1cc8,8);
      piVar3 = (int *)(**(code **)(**(int **)(unaff_EBX + 4) + 0x34))(&pvStack_488);
      if ((piVar3 != (int *)0x0) && (cVar1 = (**(code **)(*piVar3 + 0x28))(), cVar1 != '\0')) {
        (**(code **)(*piVar3 + 0x24))(0);
      }
      if (uStack_474 < 0x10) goto LAB_006bd89f;
      goto LAB_006bd897;
    }
    uStack_4c4 = 0xf;
    uStack_4c8 = 0;
    uStack_4d8 = 0;
    FUN_00401740(s_btn_drop_009e1cbc,8);
    piVar5 = (int *)(**(code **)(**(int **)(unaff_EBX + 4) + 0x34))(&pvStack_4dc);
    if ((piVar5 != (int *)0x0) && (cVar1 = (**(code **)(*piVar5 + 0x28))(), cVar1 != '\x01')) {
      (**(code **)(*piVar5 + 0x24))(1);
    }
    if (0xf < uStack_4c8) {
      _free(pvStack_4dc);
      return;
    }
    uStack_4c8 = 0xf;
    uStack_4cc = 0;
    pvStack_4dc = (void *)((uint)pvStack_4dc & 0xffffff00);
    uVar6 = 0x1040009;
  }
  uVar6 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar6);
  FUN_00401660(uVar6,0,0xffffffff);
  *(undefined1 *)((int)pvVar4 + 0x106) = 1;
  FUN_00505850(auStack_51e + -0x12);
  FUN_00401660(auStack_51e + -0xe,0,0xffffffff);
  FUN_00505850(auStack_51e + -0x12);
  FUN_00401660(auStack_51e + -0xe,0,0xffffffff);
  FUN_00505850(auStack_51e + -0x12);
  FUN_00401660(auStack_51e + -0xe,0,0xffffffff);
  (**(code **)(*piVar3 + 0x24))(pvVar4);
  if (uStack_50c < 0x10) {
LAB_006bd89f:
    if (pvVar4 == (void *)0x0) {
      FUN_00505d80();
      FUN_00504490(auStack_51e + -10,*puStack_504,puStack_504);
      _free(puStack_504);
      return;
    }
    FUN_00505d80();
    _free(pvVar4);
    return;
  }
  pvStack_488 = in_ECX;
LAB_006bd897:
  _free(pvStack_488);
  return;
}


// ==== FUN_006bd8f0 @ 0x006bd8f0 ====

void FUN_006bd8f0(void)

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
  
  FUN_006bc760();
  FUN_006bc990();
  FUN_006bc930();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_tab_chang_shield_009e1c3c,0x10);
  local_20 = (void *)CONCAT31(local_20._1_3_,*(undefined1 *)(in_ECX + 0x54));
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
  FUN_00401740(s_tab_chang_weapon_009e1c50,0x10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_20);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00582440(unaff_ESI);
  if (uStack_c < 0x10) {
    FUN_006bc420(*(undefined1 *)(in_ECX + 0x53));
    FUN_006bd4d0();
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_006bd9e0 @ 0x006bd9e0 ====

/* WARNING: Removing unreachable block (ram,0x006bdaf7) */
/* WARNING: Removing unreachable block (ram,0x006bda7c) */
/* WARNING: Removing unreachable block (ram,0x006bdb4a) */
/* WARNING: Removing unreachable block (ram,0x006bda22) */

void FUN_006bd9e0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 auStack_38 [4];
  undefined1 auStack_1a [26];
  
  FUN_00401740(s_UI_Game2_ui_invenwnd_txt_009e1bc8);
  iVar1 = FUN_00410500();
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  FUN_00401740(s_slotbag_009e1be4,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38 + 0x10);
  uVar3 = (**(code **)(*piVar2 + 0x30))();
  *(undefined4 *)(in_ECX + 0x4c) = uVar3;
  FUN_00580be0(1);
  *(undefined1 *)(in_ECX + 0x55) = 0;
  FUN_00401740(s_btn_equip_item_009e1bec,0xe);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38 + 0xc);
  if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 0x30))(), iVar1 != 0)) {
    FUN_00558730(1);
  }
  FUN_00401740(s_btn_cos_item_009e1bfc,0xc);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38 + 8);
  if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 0x30))(), iVar1 != 0)) {
    FUN_00558730(0);
  }
  FUN_006bd8f0();
  return;
}


// ==== FUN_006bdb70 @ 0x006bdb70 ====

undefined4 FUN_006bdb70(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    (**(code **)(*in_ECX + 0x30))(param_1);
  }
  else {
    if (iVar1 == 0x70080002) {
      FUN_006bd8f0();
      return 1;
    }
    if (iVar1 == 0x70080004) {
      (**(code **)(*in_ECX + 0x10))();
      return 0;
    }
  }
  return 0;
}


// ==== FUN_006bdbc0 @ 0x006bdbc0 ====

void FUN_006bdbc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e1ec8;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)((int)in_ECX + 0x51) = 0;
  *(undefined1 *)((int)in_ECX + 0x52) = 0;
  *(undefined1 *)(in_ECX + 0x15) = 0;
  *(undefined1 *)((int)in_ECX + 0x53) = 0;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)((int)in_ECX + 0x51) = 0;
  *(undefined1 *)((int)in_ECX + 0x52) = 0;
  *(undefined1 *)((int)in_ECX + 0x56) = 0;
  *(undefined1 *)((int)in_ECX + 0x57) = 1;
  FUN_006bd9e0();
  return;
}


// ==== FUN_006bdc30 @ 0x006bdc30 ====

undefined1 FUN_006bdc30(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x57);
}


// ==== FUN_006bdc40 @ 0x006bdc40 ====

void FUN_006bdc40(byte param_1)

{
  void *in_ECX;
  
  FUN_006bc710();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006bdc60 @ 0x006bdc60 ====

void FUN_006bdc60(void)

{
  return;
}


// ==== FUN_006bdd00 @ 0x006bdd00 ====

void FUN_006bdd00(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x28))();
    if (cVar1 != (char)param_1) {
      (**(code **)(*piVar2 + 0x24))(param_1);
    }
  }
  return;
}


// ==== FUN_006bdd30 @ 0x006bdd30 ====

/* WARNING: Removing unreachable block (ram,0x006bdd74) */

void FUN_006bdd30(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  
  iVar1 = *(int *)(in_ECX + 0x9c);
  iVar8 = *(int *)(in_ECX + 0x98);
  do {
    if (iVar8 == iVar1) {
      return;
    }
    uVar2 = *(uint *)(iVar8 + 0x14);
    cVar4 = '\0';
    if (*(uint *)(iVar8 + 0x18) < 0x10) {
      pbVar10 = (byte *)(iVar8 + 4);
    }
    else {
      pbVar10 = *(byte **)(iVar8 + 4);
    }
    uVar3 = *(uint *)(param_1 + 0x14);
    if (uVar3 == 0) {
LAB_006bdda4:
      if ((((uVar2 <= uVar3) && (uVar3 == uVar2)) &&
          (cVar4 = '\x01', *(char *)(in_ECX + 0xb) == '\0')) &&
         (iVar5 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_btn_guildmember_009e23a0,0xf),
         iVar5 == 0)) {
        cVar4 = '\0';
      }
    }
    else {
      uVar7 = uVar3;
      if (uVar2 <= uVar3) {
        uVar7 = uVar2;
      }
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        pbVar9 = (byte *)(param_1 + 4);
      }
      else {
        pbVar9 = *(byte **)(param_1 + 4);
      }
      bVar11 = false;
      iVar5 = 0;
      bVar12 = true;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar11 = *pbVar9 < *pbVar10;
        bVar12 = *pbVar9 == *pbVar10;
        pbVar9 = pbVar9 + 1;
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (!bVar12) {
        iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      }
      if (iVar5 == 0) goto LAB_006bdda4;
    }
    piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(iVar8);
    if (((piVar6 != (int *)0x0) && (iVar5 = (**(code **)(*piVar6 + 0x30))(), iVar5 != 0)) &&
       ((cVar4 != '\0' || (*(char *)(iVar5 + 0x72) != '\0')))) {
      FUN_00558730(cVar4);
    }
    iVar8 = iVar8 + 0x1c;
  } while( true );
}


// ==== FUN_006bde30 @ 0x006bde30 ====

undefined1 FUN_006bde30(void)

{
  char cVar1;
  int in_ECX;
  undefined1 auStack_1d0 [66];
  ushort uStack_18e;
  uint auStack_18a [98];
  
  *(undefined1 *)(in_ECX + 0xb) = 0;
  cVar1 = (**(code **)(*DAT_00b5aca8 + 0x10))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5aca8 + 0x18))(auStack_1d0);
    *(bool *)(in_ECX + 0xb) = (*(uint *)((int)auStack_18a + (uint)uStack_18e * 0x27) & 0x80) != 0;
    FUN_00537c20();
  }
  return *(undefined1 *)(in_ECX + 0xb);
}


// ==== FUN_006bdf50 @ 0x006bdf50 ====

void FUN_006bdf50(void)

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
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_textview_scroll_009e20cc,0xf);
  local_20 = (void *)CONCAT31(local_20._1_3_,*(char *)(in_ECX + 10) == '\0');
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(unaff_EBX);
    (**(code **)(*piVar1 + 0x20))();
  }
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_textview_scroll_endbtn_009e20dc,0x16);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(unaff_ESI);
    (**(code **)(*piVar1 + 0x20))();
  }
  if (uStack_c < 0x10) {
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_006be030 @ 0x006be030 ====

/* WARNING: Removing unreachable block (ram,0x006be1a7) */

void FUN_006be030(void)

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
  FUN_00401740(s_lbl_type_009e2110,8);
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
    FUN_00401740(s_pLabel_009e211c,6);
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
    FUN_00401740(&DAT_009e2124,1);
    FUN_0055a260(auStack_28);
  }
  if (uStack_10 < 0x10) {
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_006be1c0 @ 0x006be1c0 ====

/* WARNING: Removing unreachable block (ram,0x006be2c0) */
/* WARNING: Removing unreachable block (ram,0x006be229) */

void FUN_006be1c0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 auStack_1a [22];
  undefined4 uStack_4;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&DAT_00b329d4);
  if ((piVar2 != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 0x28))(), cVar1 != '\x01')) {
    (**(code **)(*piVar2 + 0x24))(1);
  }
  FUN_00401740(s_edit_text_009e2128,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1a + -6);
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
  (**(code **)(*piVar2 + 0x30))();
  FUN_00551410(uStack_4);
  FUN_00401740(s_btn_normal_009e2134,10);
  FUN_006bdd30(auStack_1a + -10);
  return;
}


// ==== FUN_006be2e0 @ 0x006be2e0 ====

void FUN_006be2e0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_EBX;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  uint uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  cVar1 = (**(code **)(*DAT_00b5adc4 + 0x38))();
  if (cVar1 == '\x01') {
    iVar2 = (**(code **)(*DAT_00b5adc4 + 8))();
    uStack_18 = 0;
    uStack_8 = 0;
    uStack_4 = 0xf;
    if (iVar2 == 0) {
      pcVar5 = s_btn_pcstore_009e2198;
      goto LAB_006be364;
    }
    FUN_00401740(s_btn_pcstore_009e218c,0xb);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c);
    if (piVar3 != (int *)0x0) {
      uVar4 = 1;
      goto LAB_006be37b;
    }
  }
  else {
    pcVar5 = s_btn_pcstore_009e21a4;
LAB_006be364:
    uStack_4 = 0xf;
    uStack_8 = 0;
    uStack_18 = 0;
    FUN_00401740(pcVar5,0xb);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c);
    if (piVar3 != (int *)0x0) {
      uVar4 = 0;
LAB_006be37b:
      (**(code **)(*piVar3 + 0x44))(uVar4);
    }
  }
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  cVar1 = FUN_006bde30();
  if (cVar1 == '\0') {
    if (*(int *)(in_ECX + 0x54) == 4) {
      *(undefined4 *)(in_ECX + 0x50) = 0;
      *(undefined4 *)(in_ECX + 0x54) = 1;
      uStack_8 = 0xf;
      uStack_c = 0;
      uStack_1c = (void *)((uint)uStack_1c._1_3_ << 8);
      FUN_00401740(s_btn_normal_009e21c0,10);
      FUN_006bdd30((int)register0x00000010 + -0x20);
      if (0xf < uStack_8) {
        _free(uStack_1c);
        return;
      }
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
    FUN_00401740(s_btn_guildmember_009e21cc,0xf);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
    if (piVar3 == (int *)0x0) goto LAB_006be458;
    uVar4 = 0;
  }
  else {
    uStack_8 = 0xf;
    uStack_c = 0;
    uStack_1c = (void *)((uint)uStack_1c._1_3_ << 8);
    FUN_00401740(s_btn_guildmember_009e21b0,0xf);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
    if (piVar3 == (int *)0x0) goto LAB_006be458;
    uVar4 = 1;
  }
  (**(code **)(*piVar3 + 0x44))(uVar4);
LAB_006be458:
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if ((cVar1 != '\0') && (iVar2 = *(int *)(in_ECX + 0x98), iVar2 != *(int *)(in_ECX + 0x9c))) {
    do {
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(iVar2);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x44))(0);
      }
      iVar2 = iVar2 + 0x1c;
    } while (iVar2 != *(int *)(in_ECX + 0x9c));
  }
  return;
}


// ==== FUN_006be4b0 @ 0x006be4b0 ====

void FUN_006be4b0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_sld_alpha_009e237c,9);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*DAT_00b5a6e4 + 8))();
    (**(code **)(*piVar1 + 0x30))();
    FUN_00579b40(*(undefined1 *)(iVar2 + 0x5a));
  }
  return;
}


// ==== FUN_006be540 @ 0x006be540 ====

void FUN_006be540(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  float unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 *puVar4;
  void *pvStack_90;
  void *local_8c;
  undefined1 local_88;
  undefined4 uStack_80;
  uint uStack_7c;
  uint local_78;
  undefined4 local_74;
  undefined4 auStack_70 [22];
  undefined1 uStack_16;
  char cStack_8;
  
  local_74 = 0xf;
  local_78 = 0;
  local_88 = 0;
  FUN_00401740(s_sld_alpha_009e2388,9);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_8c);
  if (0xf < local_78) {
    _free(local_8c);
    return;
  }
  local_78 = 0xf;
  uStack_7c = 0;
  local_8c = (void *)((uint)local_8c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_005796c0();
    local_78 = 0xf;
    uStack_7c = 0;
    local_8c = (void *)((uint)local_8c & 0xffffff00);
    FUN_00401740(s_pan_color_009e2394,9);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_90);
    if (0xf < uStack_7c) {
      _free(pvStack_90);
      return;
    }
    uStack_7c = 0xf;
    uStack_80 = 0;
    pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x30))();
      local_78 = *(uint *)(iVar2 + 0x8c);
      local_74 = *(undefined4 *)(iVar2 + 0x90);
      auStack_70[0] = *(undefined4 *)(iVar2 + 0x94);
      if (unaff_EBX <= DAT_009b2d80) {
        iVar2 = FUN_00802534();
        local_78 = iVar2 << 0x18 | 0x10101;
        FUN_00587d40(&local_78);
        (**(code **)(*piVar1 + 0x20))();
        if (cStack_8 != '\0') {
          puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
          puVar4 = auStack_70;
          for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar4 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar4 = puVar4 + 1;
          }
          uStack_16 = (char)((uint)unaff_ESI >> 0x18);
          (**(code **)(*DAT_00b5a6e4 + 0x10))(auStack_70);
          (**(code **)(*DAT_00b5a6e4 + 0x14))();
        }
      }
    }
  }
  return;
}


// ==== FUN_006be6d0 @ 0x006be6d0 ====

void FUN_006be6d0(void)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  void *unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined1 auStack_5a [2];
  void *local_58;
  undefined1 local_54;
  uint uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  uint local_44;
  undefined4 local_40 [3];
  int iStack_34;
  int iStack_2c;
  void *pvStack_28;
  uint uStack_14;
  
  local_40[0] = 0xf;
  local_44 = 0;
  local_54 = 0;
  FUN_00401740(s_textview_009e23b0,8);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_58);
  if (0xf < local_44) {
    _free(local_58);
    return;
  }
  local_44 = 0xf;
  uStack_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  if (piVar3 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar3 + 0x10))();
    FUN_005041e0(uVar4);
    iStack_2c = (uint)*(ushort *)(in_ECX + 0xa8) + iStack_34 + (uint)*(byte *)(in_ECX + 10) * 0x18;
    (**(code **)(*piVar3 + 0xc))(local_40);
    iVar5 = (**(code **)(*piVar3 + 0x30))();
    FUN_00552560();
    *(undefined1 *)(iVar5 + 0x179) = 1;
    FUN_005569f0(in_ECX + 0x34,0);
    uStack_48 = 0xf;
    uStack_4c = 0;
    FUN_00401740(s_pan_back_009e23bc,8);
    cVar1 = *(char *)(in_ECX + 10);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_5a + -6);
    if (piVar3 != (int *)0x0) {
      cVar2 = (**(code **)(*piVar3 + 0x28))();
      if (cVar2 != (char)unaff_ESI) {
        (**(code **)(*piVar3 + 0x24))(unaff_ESI);
      }
    }
    if (0xf < uStack_4c) {
      _free(unaff_EBX);
      return;
    }
    uStack_4c = 0xf;
    uStack_50 = 0;
    FUN_00401740(s_pan_back_small_009e23c8,0xe);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_5a + -10);
    if (piVar3 != (int *)0x0) {
      cVar2 = (**(code **)(*piVar3 + 0x28))();
      if (cVar2 != (char)unaff_EDI) {
        (**(code **)(*piVar3 + 0x24))(unaff_EDI);
      }
    }
    if (0xf < uStack_50) {
      _free((void *)CONCAT31((int3)((uint)unaff_EBP >> 8),cVar1 == '\0'));
      return;
    }
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
  }
  return;
}


// ==== FUN_006be880 @ 0x006be880 ====

/* WARNING: Removing unreachable block (ram,0x006be8eb) */

void FUN_006be880(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 auStack_1a [26];
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&DAT_00b329d4);
  if ((piVar2 != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 0x28))(), cVar1 != '\x01')) {
    (**(code **)(*piVar2 + 0x24))(1);
  }
  *(undefined1 *)(in_ECX + 8) = 1;
  FUN_00401740(s_edit_text_009e23d8,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1a + -6);
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
  return;
}


// ==== FUN_006be940 @ 0x006be940 ====

void FUN_006be940(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
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
  FUN_00401740(s_pan_effect_009e2534,10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
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
  puVar2[2] = unaff_retaddr;
  *(undefined1 *)((int)puVar2 + 0x19) = 1;
  puVar2[3] = param_1;
  puVar2[4] = param_2;
  *(undefined1 *)(puVar2 + 6) = param_3;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar2);
  (**(code **)*puVar2)(1);
  return;
}


// ==== FUN_006bea10 @ 0x006bea10 ====

/* WARNING: Removing unreachable block (ram,0x006beb0c) */
/* WARNING: Removing unreachable block (ram,0x006beb6f) */
/* WARNING: Removing unreachable block (ram,0x006bea79) */

void FUN_006bea10(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 auStack_36 [18];
  undefined4 uStack_24;
  void *pvStack_20;
  uint uStack_c;
  undefined4 uStack_4;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&DAT_00b329d4);
  if ((piVar2 != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 0x28))(), cVar1 != '\x01')) {
    (**(code **)(*piVar2 + 0x24))(1);
  }
  uStack_24 = 0xf;
  FUN_00401740(s_edit_text_009e2140,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_36 + -6);
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
  (**(code **)(*piVar2 + 0x30))();
  uVar4 = FUN_004022a0(&uStack_24,&DAT_009e2150,uStack_4,&DAT_009e214c);
  uVar4 = FUN_00402220(auStack_36 + -10,uVar4);
  FUN_00551410(uVar4);
  if (uStack_c < 0x10) {
    FUN_00401740(s_btn_normal_009e2154,10);
    FUN_006bdd30(auStack_36 + -10);
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_006beb90 @ 0x006beb90 ====

/* WARNING: Removing unreachable block (ram,0x006bec8c) */
/* WARNING: Removing unreachable block (ram,0x006becef) */
/* WARNING: Removing unreachable block (ram,0x006bebf9) */

void FUN_006beb90(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 auStack_36 [18];
  undefined4 uStack_24;
  void *pvStack_20;
  uint uStack_c;
  undefined4 uStack_4;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&DAT_00b329d4);
  if ((piVar2 != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 0x28))(), cVar1 != '\x01')) {
    (**(code **)(*piVar2 + 0x24))(1);
  }
  uStack_24 = 0xf;
  FUN_00401740(s_edit_text_009e2160,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_36 + -6);
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
  (**(code **)(*piVar2 + 0x30))();
  uVar4 = FUN_004022a0(&uStack_24,&DAT_009e2170,uStack_4,&DAT_009e216c);
  uVar4 = FUN_00402220(auStack_36 + -10,uVar4);
  FUN_00551410(uVar4);
  if (uStack_c < 0x10) {
    FUN_00401740(s_btn_normal_009e2174,10);
    FUN_006bdd30(auStack_36 + -10);
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_006bed10 @ 0x006bed10 ====

uint FUN_006bed10(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_70 [28];
  undefined1 local_54 [28];
  undefined1 local_38 [28];
  undefined1 local_1c [28];
  
  if (*(int *)(param_1 + 4) == 0x26) {
    uVar1 = 0;
    if (*(char *)(in_ECX + 8) == '\x01') {
      if (*(char *)(in_ECX + 0xc) == '\x01') {
        uVar2 = (**(code **)(*DAT_00b5ad0c + 0x54))(local_38);
        FUN_006bea10(uVar2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      uVar2 = (**(code **)(*DAT_00b5ad0c + 100))(local_1c);
      FUN_006be1c0(uVar2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  else {
    uVar1 = *(int *)(param_1 + 4) - 0x28;
    if ((uVar1 == 0) && (*(char *)(in_ECX + 8) == '\x01')) {
      if (*(char *)(in_ECX + 0xc) == '\x01') {
        uVar2 = (**(code **)(*DAT_00b5ad0c + 0x58))(local_70);
        FUN_006bea10(uVar2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      uVar2 = (**(code **)(*DAT_00b5ad0c + 0x68))(local_54);
      FUN_006be1c0(uVar2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006bedf0 @ 0x006bedf0 ====

void FUN_006bedf0(int param_1)

{
  undefined4 ***pppuVar1;
  int *piVar2;
  int *piVar3;
  undefined4 ***pppuVar4;
  undefined4 ***local_18 [4];
  undefined4 local_8;
  uint local_4;
  
  if (0xff < *(uint *)(param_1 + 0x14)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18[0] = (undefined4 ***)((uint)local_18[0] & 0xffffff00);
    FUN_00401660(param_1,0,0xffffffff);
    pppuVar1 = local_18[0];
    if (local_4 < 0x10) {
      pppuVar1 = local_18;
    }
    pppuVar4 = local_18[0];
    if (local_4 < 0x10) {
      pppuVar4 = local_18;
    }
    piVar2 = (int *)(param_1 + 4);
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      piVar3 = piVar2;
    }
    else {
      piVar3 = (int *)*piVar2;
    }
    if (0xf < *(uint *)(param_1 + 0x18)) {
      piVar2 = (int *)*piVar2;
    }
    FUN_00430560(piVar2,*(int *)(param_1 + 0x14) + (int)piVar3,pppuVar4,(int)pppuVar1 + 0xfe,param_1
                );
    if (0xf < local_4) {
      _free(local_18[0]);
      return;
    }
  }
  return;
}


// ==== FUN_006beea0 @ 0x006beea0 ====

void FUN_006beea0(void)

{
  undefined4 *in_ECX;
  undefined4 unaff_EBX;
  
  *in_ECX = &PTR_FUN_009e2548;
  if (in_ECX[0x26] != 0) {
    FUN_00405de0(in_ECX[0x26],in_ECX[0x27],in_ECX + 0x25);
    _free((void *)in_ECX[0x26]);
    return;
  }
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (in_ECX[0x26] != 0) {
    FUN_00405de0(in_ECX[0x26],in_ECX[0x27],in_ECX + 0x25,unaff_EBX);
    _free((void *)in_ECX[0x26]);
    return;
  }
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  FUN_0046cfc0();
  if ((void *)in_ECX[0x1b] == (void *)0x0) {
    in_ECX[0x1b] = 0;
    in_ECX[0x1c] = 0;
    in_ECX[0x1d] = 0;
    FUN_006c1f70();
    _free((void *)in_ECX[0x18]);
    return;
  }
  _free((void *)in_ECX[0x1b]);
  return;
}


// ==== FUN_006befb0 @ 0x006befb0 ====

int FUN_006befb0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  char cVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  undefined4 uVar2;
  int extraout_EAX_05;
  int iVar3;
  undefined4 *****pppppuVar4;
  undefined4 *****pppppuVar5;
  int extraout_EAX_06;
  int extraout_EAX_07;
  int extraout_EAX_08;
  int extraout_EAX_09;
  int extraout_EAX_10;
  int extraout_EAX_11;
  int extraout_EAX_12;
  int extraout_EAX_13;
  int extraout_EAX_14;
  int extraout_EAX_15;
  int extraout_EAX_16;
  int extraout_EAX_17;
  int extraout_EAX_18;
  int extraout_EAX_19;
  int extraout_EAX_20;
  int extraout_EAX_21;
  int extraout_EAX_22;
  int extraout_EAX_23;
  int extraout_EAX_24;
  int extraout_EAX_25;
  int extraout_EAX_26;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  undefined1 auStack_158 [4];
  undefined4 *****local_154 [4];
  int local_144;
  uint local_140;
  undefined1 local_13c [4];
  void *local_138;
  undefined4 local_128;
  uint local_124;
  undefined4 uStack_120;
  uint local_11c;
  undefined1 auStack_118 [4];
  void *pvStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined1 auStack_108 [4];
  void *pvStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 *****local_f4 [4];
  uint local_e4;
  uint local_e0;
  undefined1 local_dc [4];
  void *local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined1 local_cc [4];
  void *local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined1 local_bc [4];
  void *local_b8;
  undefined4 uStack_a8;
  uint local_a4;
  uint local_a0;
  undefined1 local_9c [4];
  void *local_98;
  undefined4 local_88;
  uint local_84;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
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
  
  local_e0 = 0xf;
  local_e4 = 0;
  local_f4[0] = (undefined4 *****)((uint)local_f4[0] & 0xffffff00);
  local_d8 = (void *)0x0;
  local_d4 = 0;
  local_d0 = 0;
  local_c8 = (void *)0x0;
  local_c4 = 0;
  local_c0 = 0;
  local_124 = 0xf;
  local_128 = 0;
  local_138 = (void *)((uint)local_138 & 0xffffff00);
  FUN_00401740(s___BS___009e2414,6);
  FUN_00406720(local_13c);
  if (0xf < local_124) {
    _free(local_138);
    return extraout_EAX;
  }
  local_124 = 0xf;
  local_128 = 0;
  local_138 = (void *)((uint)local_138 & 0xffffff00);
  FUN_00401740(&DAT_009e241c,1);
  FUN_00406720(local_13c);
  if (0xf < local_124) {
    _free(local_138);
    return extraout_EAX_00;
  }
  local_124 = 0xf;
  local_128 = 0;
  local_138 = (void *)((uint)local_138 & 0xffffff00);
  FUN_00401740(s___GT___009e2420,6);
  FUN_00406720(local_13c);
  if (0xf < local_124) {
    _free(local_138);
    return extraout_EAX_01;
  }
  local_124 = 0xf;
  local_128 = 0;
  local_138 = (void *)((uint)local_138 & 0xffffff00);
  FUN_00401740(&DAT_009e2428,1);
  FUN_00406720(local_13c);
  if (0xf < local_124) {
    _free(local_138);
    return extraout_EAX_02;
  }
  local_124 = 0xf;
  local_128 = 0;
  local_138 = (void *)((uint)local_138 & 0xffffff00);
  FUN_00401740(s___LT___009e242c,6);
  FUN_00406720(local_13c);
  if (0xf < local_124) {
    _free(local_138);
    return extraout_EAX_03;
  }
  local_124 = 0xf;
  local_128 = 0;
  local_138 = (void *)((uint)local_138 & 0xffffff00);
  FUN_00401740(&DAT_009e2434,1);
  FUN_00406720(local_13c);
  if (0xf < local_124) {
    _free(local_138);
    return extraout_EAX_04;
  }
  if (param_5 == '\0') {
    uVar2 = FUN_00404a40(local_bc,param_2,local_dc,local_cc);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < local_a4) {
      _free(local_b8);
      return extraout_EAX_05;
    }
  }
  else {
    FUN_00401660(param_2,0,0xffffffff);
  }
  local_84 = 0xf;
  local_88 = 0;
  local_98 = (void *)((uint)local_98 & 0xffffff00);
  local_140 = 0xf;
  local_144 = 0;
  local_154[0] = (undefined4 *****)((uint)local_154[0] & 0xffffff00);
  local_a0 = local_e4;
  local_11c = 0;
  if (local_e4 != 0) {
    do {
      uVar6 = local_11c;
      if (local_e4 <= local_11c) {
        FUN_0079dba3();
      }
      pppppuVar4 = local_f4[0];
      if (local_e0 < 0x10) {
        pppppuVar4 = local_f4;
      }
      cVar1 = FUN_00403d70((int)*(char *)((int)pppppuVar4 + uVar6));
      if (cVar1 == '\0') {
        if (local_e4 <= uVar6) {
          FUN_0079dba3();
        }
        pppppuVar4 = local_f4[0];
        if (local_e0 < 0x10) {
          pppppuVar4 = local_f4;
        }
        uStack_78 = CONCAT31(uStack_78._1_3_,*(undefined1 *)((int)pppppuVar4 + uVar6));
        pppppuVar4 = local_154[0];
        if (local_140 < 0x10) {
          pppppuVar4 = local_154;
        }
        pppppuVar5 = local_154[0];
        if (local_140 < 0x10) {
          pppppuVar5 = local_154;
        }
        if ((int)pppppuVar4 + local_144 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = ((int)pppppuVar4 + local_144) - (int)pppppuVar5;
        }
        uVar2 = uStack_78;
      }
      else {
        if (local_e4 <= uVar6) {
          FUN_0079dba3();
        }
        pppppuVar4 = local_f4[0];
        if (local_e0 < 0x10) {
          pppppuVar4 = local_f4;
        }
        uStack_74 = CONCAT31(uStack_74._1_3_,*(undefined1 *)((int)pppppuVar4 + uVar6));
        pppppuVar4 = local_154[0];
        if (local_140 < 0x10) {
          pppppuVar4 = local_154;
        }
        pppppuVar5 = local_154[0];
        if (local_140 < 0x10) {
          pppppuVar5 = local_154;
        }
        if ((int)pppppuVar4 + local_144 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = ((int)pppppuVar4 + local_144) - (int)pppppuVar5;
        }
        FUN_00557c50(iVar3,1,uStack_74);
        uVar6 = uVar6 + 1;
        local_11c = uVar6;
        if (uVar6 == local_a0) break;
        if (local_e4 <= uVar6) {
          FUN_0079dba3();
        }
        pppppuVar4 = local_f4[0];
        if (local_e0 < 0x10) {
          pppppuVar4 = local_f4;
        }
        uStack_80 = CONCAT31(uStack_80._1_3_,*(undefined1 *)((int)pppppuVar4 + uVar6));
        pppppuVar4 = local_154[0];
        if (local_140 < 0x10) {
          pppppuVar4 = local_154;
        }
        pppppuVar5 = local_154[0];
        if (local_140 < 0x10) {
          pppppuVar5 = local_154;
        }
        uVar2 = uStack_80;
        if ((int)pppppuVar4 + local_144 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = ((int)pppppuVar4 + local_144) - (int)pppppuVar5;
        }
      }
      FUN_00557c50(iVar3,1,uVar2);
      if (param_5 == '\0') {
LAB_006bf437:
        (**(code **)(*DAT_00b5a688 + 0x34))(param_3,auStack_158,&uStack_7c,&uStack_120);
        if (300 < uStack_7c) {
          if (param_5 == '\0') {
            uVar2 = FUN_00404a40(auStack_70,auStack_158,local_cc,local_dc);
            FUN_00401660(uVar2,0,0xffffffff);
            if (0xf < uStack_58) {
              _free(pvStack_6c);
              return extraout_EAX_06;
            }
            uStack_58 = 0xf;
            uStack_5c = 0;
            pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
            FUN_00401740(s_<font__u>_s_s<_color><_font>__009e2438,0x1d);
            uVar2 = FUN_00404230(auStack_1c);
            FUN_00401ff0(uVar2,0,0xffffffff);
            if (0xf < uStack_4) {
              _free(pvStack_18);
              return extraout_EAX_07;
            }
            uStack_4 = 0xf;
            uStack_8 = 0;
            pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
          }
          else {
            pvStack_114 = (void *)0x0;
            uStack_110 = 0;
            uStack_10c = 0;
            local_124 = 0xf;
            local_128 = 0;
            local_138 = (void *)((uint)local_138 & 0xffffff00);
            FUN_00401740(&DAT_009e2458,1);
            FUN_00406720(local_13c);
            if (0xf < local_124) {
              _free(local_138);
              return extraout_EAX_08;
            }
            local_124 = 0xf;
            local_128 = 0;
            local_138 = (void *)((uint)local_138 & 0xffffff00);
            pvStack_104 = (void *)0x0;
            uStack_100 = 0;
            uStack_fc = 0;
            FUN_00401740(s_<_color><_font>_<font__u>_s_009e245c,0x1b);
            puVar7 = auStack_38;
            uVar2 = FUN_00404230(puVar7);
            FUN_00406720(uVar2);
            if (0xf < uStack_20) {
              _free(pvStack_34);
              return extraout_EAX_09;
            }
            uStack_20 = 0xf;
            uStack_24 = 0;
            pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
            uVar2 = FUN_00404a40(auStack_54,auStack_158,auStack_118,auStack_108);
            FUN_00401660(uVar2,0,0xffffffff);
            if (0xf < uStack_3c) {
              _free(pvStack_50);
              return extraout_EAX_10;
            }
            uStack_3c = 0xf;
            uStack_40 = 0;
            pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
            uVar8 = 0;
            FUN_00401740(s_<font__u>_s_s<_color><_font>__009e2478,0x1d);
            uVar2 = FUN_00404230(local_bc,puVar7,uVar8);
            FUN_00401ff0(uVar2,0,0xffffffff);
            if (0xf < local_a4) {
              _free(local_b8);
              return extraout_EAX_11;
            }
            local_a4 = 0xf;
            uStack_a8 = 0;
            local_b8 = (void *)((uint)local_b8 & 0xffffff00);
            if (pvStack_104 != (void *)0x0) {
              FUN_00405de0(pvStack_104,uStack_100,auStack_108,uStack_120);
              _free(pvStack_104);
              return extraout_EAX_12;
            }
            pvStack_104 = (void *)0x0;
            uStack_100 = 0;
            uStack_fc = 0;
            if (pvStack_114 != (void *)0x0) {
              FUN_00405de0(pvStack_114,uStack_110,auStack_118,uStack_120);
              _free(pvStack_114);
              return extraout_EAX_13;
            }
            pvStack_114 = (void *)0x0;
            uStack_110 = 0;
            uStack_10c = 0;
          }
          pppppuVar4 = local_154[0];
          if (local_140 < 0x10) {
            pppppuVar4 = local_154;
          }
          if (local_140 < 0x10) {
            pppppuVar5 = local_154;
          }
          else {
            pppppuVar5 = local_154[0];
          }
          if (local_144 + (int)pppppuVar4 == 0) {
            iVar3 = 0;
          }
          else {
            iVar3 = (local_144 + (int)pppppuVar4) - (int)pppppuVar5;
          }
          FUN_00401390(0,iVar3);
          uVar6 = local_11c;
        }
      }
      else {
        if (local_e4 <= uVar6) {
          FUN_0079dba3();
        }
        pppppuVar4 = local_f4[0];
        if (local_e0 < 0x10) {
          pppppuVar4 = local_f4;
        }
        if (*(char *)((int)pppppuVar4 + uVar6) != '\\') goto LAB_006bf437;
        FUN_00401ff0(auStack_158,0,0xffffffff);
        pppppuVar4 = local_154[0];
        if (local_140 < 0x10) {
          pppppuVar4 = local_154;
        }
        pppppuVar5 = local_154[0];
        if (local_140 < 0x10) {
          pppppuVar5 = local_154;
        }
        FUN_004bdb30(&local_11c,pppppuVar5,(int)pppppuVar4 + local_144);
      }
      local_11c = uVar6 + 1;
    } while (local_11c < local_a0);
    if (local_144 != 0) {
      if (param_5 == '\0') {
        uVar2 = FUN_00404a40(local_bc,auStack_158,local_cc,local_dc);
        FUN_00401660(uVar2,0,0xffffffff);
        if (0xf < local_a4) {
          _free(local_b8);
          return extraout_EAX_14;
        }
        FUN_00401740(s_<font__u>_s_s<_color><_font>__009e2498,0x1d);
        uVar2 = FUN_00404230(local_bc);
        FUN_00401ff0(uVar2,0,0xffffffff);
        if (0xf < local_a4) {
          _free(local_b8);
          return extraout_EAX_15;
        }
      }
      else {
        pvStack_104 = (void *)0x0;
        uStack_100 = 0;
        uStack_fc = 0;
        local_124 = 0xf;
        local_128 = 0;
        local_138 = (void *)((uint)local_138 & 0xffffff00);
        FUN_00401740(&DAT_009e24b8,1);
        FUN_00406720(local_13c);
        if (0xf < local_124) {
          _free(local_138);
          return extraout_EAX_16;
        }
        pvStack_114 = (void *)0x0;
        uStack_110 = 0;
        uStack_10c = 0;
        FUN_00401740(s_<_color><_font>_<font__u>_s_009e24bc,0x1b);
        puVar7 = local_bc;
        uVar2 = FUN_00404230(puVar7);
        FUN_00406720(uVar2);
        if (0xf < local_a4) {
          _free(local_b8);
          return extraout_EAX_17;
        }
        uVar2 = FUN_00404a40(local_bc,auStack_158,auStack_108,auStack_118);
        FUN_00401660(uVar2,0,0xffffffff);
        if (0xf < local_a4) {
          _free(local_b8);
          return extraout_EAX_18;
        }
        uVar8 = 0;
        FUN_00401740(s_<font__u>_s_s<_color><_font>__009e24d8,0x1d);
        uVar2 = FUN_00404230(local_bc,puVar7,uVar8);
        FUN_00401ff0(uVar2,0,0xffffffff);
        if (0xf < local_a4) {
          _free(local_b8);
          return extraout_EAX_19;
        }
        if (pvStack_114 != (void *)0x0) {
          FUN_00405de0(pvStack_114,uStack_110,auStack_118,uStack_120);
          _free(pvStack_114);
          return extraout_EAX_20;
        }
        pvStack_114 = (void *)0x0;
        uStack_110 = 0;
        uStack_10c = 0;
        if (pvStack_104 != (void *)0x0) {
          FUN_00405de0(pvStack_104,uStack_100,auStack_108,uStack_120);
          _free(pvStack_104);
          return extraout_EAX_21;
        }
      }
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_9c,0,0xffffffff);
  if (0xf < local_140) {
    _free(local_154[0]);
    return extraout_EAX_22;
  }
  local_140 = 0xf;
  local_144 = 0;
  local_154[0] = (undefined4 *****)((uint)local_154[0] & 0xffffff00);
  if (0xf < local_84) {
    _free(local_98);
    return extraout_EAX_23;
  }
  local_84 = 0xf;
  local_88 = 0;
  local_98 = (void *)((uint)local_98 & 0xffffff00);
  if (local_c8 != (void *)0x0) {
    FUN_00405de0(local_c8,local_c4,local_cc,uStack_120);
    _free(local_c8);
    return extraout_EAX_24;
  }
  local_c8 = (void *)0x0;
  local_c4 = 0;
  local_c0 = 0;
  if (local_d8 != (void *)0x0) {
    FUN_00405de0(local_d8,local_d4,local_dc,uStack_120);
    _free(local_d8);
    return extraout_EAX_25;
  }
  local_d8 = (void *)0x0;
  local_d4 = 0;
  local_d0 = 0;
  if (local_e0 < 0x10) {
    return param_1;
  }
  _free(local_f4[0]);
  return extraout_EAX_26;
}


// ==== FUN_006bfc20 @ 0x006bfc20 ====

undefined4 FUN_006bfc20(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 extraout_EAX;
  undefined *puVar1;
  undefined4 uVar2;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401660(&DAT_00b328a0,0,0xffffffff);
  switch(param_3) {
  case 0:
    puVar1 = &DAT_00b328a0;
    break;
  case 1:
    puVar1 = &DAT_00b32948;
    break;
  case 2:
    puVar1 = &DAT_00b32980;
    break;
  case 3:
    puVar1 = &DAT_00b32964;
    break;
  case 4:
    puVar1 = &DAT_00b328bc;
    break;
  default:
    if (param_3 == 0xb) {
      uVar2 = 1;
      goto LAB_006bfc76;
    }
    goto LAB_006bfc74;
  case 7:
    puVar1 = &DAT_00b328d8;
    break;
  case 8:
    puVar1 = &DAT_00b3292c;
    break;
  case 9:
    puVar1 = &DAT_00b328f4;
    break;
  case 10:
    puVar1 = &DAT_00b32910;
    break;
  case 0xb:
    FUN_00401660(&DAT_00b3299c,0,0xffffffff);
    uVar2 = 1;
    goto LAB_006bfc76;
  case 0xc:
    puVar1 = &DAT_00b329b8;
  }
  FUN_00401660(puVar1,0,0xffffffff);
LAB_006bfc74:
  uVar2 = 0;
LAB_006bfc76:
  FUN_006befb0(param_1,param_2,2,local_1c,uVar2);
  if (local_4 < 0x10) {
    return param_1;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_006bfd80 @ 0x006bfd80 ====

void FUN_006bfd80(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_28 [8];
  undefined4 local_20 [2];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20[0] = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401660(param_2,0,0xffffffff);
  FUN_006c2280(local_28,local_20);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00846af0(&param_1);
  if (500 < *(uint *)(in_ECX + 0x38)) {
    uVar1 = *(uint *)(in_ECX + 0x34) >> 2;
    iVar2 = uVar1 * -4;
    if (*(uint *)(in_ECX + 0x30) <= uVar1) {
      uVar1 = uVar1 - *(uint *)(in_ECX + 0x30);
    }
    param_1 = *(undefined4 *)
               (*(int *)(*(int *)(in_ECX + 0x2c) + uVar1 * 4) +
               (*(uint *)(in_ECX + 0x34) + iVar2) * 4);
    FUN_006c25a0(&param_1);
    if (*(int *)(in_ECX + 0x38) != 0) {
      *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 1;
      if ((uint)(*(int *)(in_ECX + 0x30) * 4) <= *(uint *)(in_ECX + 0x34)) {
        *(undefined4 *)(in_ECX + 0x34) = 0;
      }
      iVar2 = *(int *)(in_ECX + 0x38) + -1;
      *(int *)(in_ECX + 0x38) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(in_ECX + 0x34) = 0;
      }
    }
  }
  return;
}


// ==== FUN_006bfe60 @ 0x006bfe60 ====

void FUN_006bfe60(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  uint uVar8;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int *piStack_40;
  int *piStack_3c;
  void *pvStack_38;
  undefined4 uStack_30;
  uint uStack_2c;
  int iStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ad10 + 4))();
  piStack_3c = piVar1;
  piVar2 = (int *)(**(code **)(*piVar1 + 8))(*(undefined4 *)(in_ECX + 0x54));
  if (*(uint *)(in_ECX + 0x4c) < 0x10) {
    iVar3 = in_ECX + 0x38;
  }
  else {
    iVar3 = *(int *)(in_ECX + 0x38);
  }
  if (*(uint *)(in_ECX + 0x4c) < 0x10) {
    iVar7 = in_ECX + 0x38;
  }
  else {
    iVar7 = *(int *)(in_ECX + 0x38);
  }
  FUN_004bdb30(&iStack_44,iVar7,*(int *)(in_ECX + 0x48) + iVar3);
  uVar8 = 0;
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  if (iVar3 != 0) {
    do {
      puVar4 = (undefined4 *)(**(code **)(*piVar2 + 4))();
      iStack_50 = puVar4[1];
      iStack_48 = iStack_50;
      if (iStack_50 == 0) {
LAB_006bff35:
        FUN_006bfc20(&piStack_3c,puVar4 + 2,*puVar4);
        FUN_006bfd80(puVar4[1],&piStack_3c);
        FUN_00401ff0(&piStack_3c,0,0xffffffff);
        if (0xf < uStack_24) {
          _free(pvStack_38);
          return;
        }
        uStack_24 = 0xf;
        iStack_28 = 0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      }
      else {
        FUN_00897340(&iStack_4c,&iStack_50);
        if (iStack_4c == *(int *)(in_ECX + 0x60)) goto LAB_006bff35;
        FUN_00897340(&iStack_44,&iStack_48);
        FUN_00401ff0(iStack_44 + 0xc,0,0xffffffff);
      }
      (**(code **)(*piVar2 + 0xc))();
      uVar8 = uVar8 + 1;
      uVar5 = (**(code **)(*piVar2 + 0x10))();
    } while (uVar8 < uVar5);
    piVar1 = piStack_40;
  }
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  if (iVar3 == 0) {
    uStack_24 = 0xf;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    iStack_28 = iVar3;
    FUN_00401740(&DAT_009e217f,0);
    uVar6 = FUN_006bfc20(auStack_20,&piStack_3c,*(undefined4 *)(in_ECX + 0x50));
    FUN_00401ff0(uVar6,0,0xffffffff);
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
  (**(code **)(*piVar1 + 0xc))(piVar2);
  iStack_28 = 0xf;
  uStack_2c = 0;
  piStack_3c = (int *)((uint)piStack_3c & 0xffffff00);
  FUN_00401740(s_textview_009e2180,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&piStack_40);
  if (0xf < uStack_2c) {
    _free(piStack_40);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  piStack_40 = (int *)((uint)piStack_40 & 0xffffff00);
  iVar3 = (**(code **)(*piVar1 + 0x30))();
  *(undefined1 *)(iVar3 + 0x179) = 1;
  FUN_005569f0(in_ECX + 0x34,0);
  if (*(char *)(in_ECX + 10) != '\x01') {
    FUN_006be2e0();
  }
  return;
}


