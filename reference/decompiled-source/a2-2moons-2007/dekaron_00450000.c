// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x450000-0x45ffff

// ==== FUN_00450170 @ 0x00450170 ====

void FUN_00450170(int param_1,int *param_2)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 in_ECX;
  undefined1 uStack00000000;
  int *piStack_8;
  int iStack_4;
  
  if ((param_2 != (int *)0x0) && (piVar3 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar3 != 0x12)
     ) {
    piVar3 = (int *)(**(code **)(*param_2 + 0x10))();
    piVar3 = (int *)*piVar3;
    piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
    piVar4 = (int *)(**(code **)(*piVar4 + 0x54))();
    piStack_8 = piVar4;
    piVar5 = (int *)FUN_0044f820(piVar4);
    if (piVar5 == (int *)0x0) {
      iStack_4 = param_1 + -1;
      piStack_8 = piVar5;
      (**(code **)(*param_2 + 0x2c))(&piStack_8);
      (**(code **)(*param_2 + 0x3c))(&uStack00000000);
      (**(code **)(*param_2 + 0x34))(1);
      piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
      (**(code **)(*piVar3 + 0x48))(0);
      iVar8 = *param_2;
      uVar6 = (**(code **)(*DAT_00b5a708 + 4))(1,param_1,0);
      (**(code **)(iVar8 + 0x1c))(uVar6);
      return;
    }
    piVar7 = (int *)(**(code **)(*piVar5 + 0x30))();
    if (*piVar7 == 0xe) {
      iStack_4 = param_1 + -1;
      piStack_8 = (int *)0x0;
      (**(code **)(*param_2 + 0x2c))(&piStack_8);
      (**(code **)(*param_2 + 0x34))(1);
      iStack_4 = 0;
      (**(code **)(*param_2 + 0x3c))(&iStack_4);
      piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
      (**(code **)(*piVar4 + 0x48))(0);
      piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
      uVar6 = (**(code **)(*piVar4 + 0x54))();
      FUN_004574e0(param_1,piVar3,uVar6);
      piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
      (**(code **)(*piVar3 + 0x50))(0);
      return;
    }
    iVar8 = (**(code **)(*param_2 + 0x10))();
    if ((piVar3 != piVar4) && (*(int **)(iVar8 + 4) != piVar4)) {
      cVar1 = (**(code **)(*DAT_00b5a804 + 0x1c))();
      if ((cVar1 == '\0') &&
         ((iVar8 = (**(code **)(*param_2 + 0x14))(), *(int *)(iVar8 + 4) == 0 &&
          (iVar8 = (**(code **)(*piVar5 + 0x14))(), *(int *)(iVar8 + 4) == 0)))) {
        iVar8 = (**(code **)(*piVar5 + 0x14))();
        iVar9 = (**(code **)(*param_2 + 0x14))();
        if (*(int *)(iVar9 + 0x38) == *(int *)(iVar8 + 0x38)) {
          piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
          (**(code **)(*piVar3 + 0x48))(0);
          FUN_004574e0(_uStack00000000,in_ECX,piVar4);
          return;
        }
      }
      piVar7 = (int *)(**(code **)(*param_2 + 0x18))();
      iVar8 = *piVar7;
      iVar9 = (**(code **)(*param_2 + 0x14))();
      if ((*(int *)(iVar9 + 4) == 0) &&
         (iVar9 = (**(code **)(*piVar5 + 0x14))(), *(int *)(iVar9 + 4) == 3)) {
        cVar1 = FUN_0044ee60(param_2,piVar5,iVar8);
        if (cVar1 == '\x01') {
LAB_00450374:
          FUN_00457350(param_1,piVar3,piVar4);
          return;
        }
      }
      else {
        cVar1 = FUN_0044f750(param_2,piVar5,iVar8);
        if ((cVar1 == '\x01') && (iVar8 != 0)) goto LAB_00450374;
      }
      iVar9 = (**(code **)(*param_2 + 0x14))();
      iVar10 = (**(code **)(*piVar5 + 0x14))();
      iVar8 = (**(code **)(*param_2 + 0x18))();
      iVar8 = *(int *)(iVar8 + 0x18);
      cVar1 = FUN_0044fbf0(iVar9 + 0x18,iVar10 + 0x18);
      cVar2 = FUN_0044f750(param_2,piVar5,iVar8);
      iVar9 = (**(code **)(*param_2 + 0x14))();
      if ((*(int *)(iVar9 + 4) == 0) &&
         (iVar9 = (**(code **)(*piVar5 + 0x14))(), *(int *)(iVar9 + 4) == 3)) {
        cVar1 = FUN_0044ee60(param_2,piVar5,iVar8);
        if (cVar1 == '\x01') {
          FUN_004573f0(param_1,piVar3,piStack_8);
          return;
        }
      }
      else if ((cVar1 != '\0') && ((cVar2 == '\x01' && (iVar8 != 0)))) {
        FUN_004573f0(param_1,piVar3,piStack_8);
        return;
      }
      piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
      iVar8 = (**(code **)(*piVar4 + 100))();
      iVar9 = (**(code **)(*param_2 + 0x10))();
      iVar9 = FUN_0044f820(*(undefined4 *)(iVar9 + 4));
      if (iVar9 == 0) {
        iVar8 = FUN_0044f860(param_2,iVar8,param_1);
        cVar1 = FUN_0044f750(param_2,piVar5,iVar8);
      }
      else {
        iVar10 = (**(code **)(*param_2 + 0x48))();
        cVar1 = FUN_0044f750(iVar9,piVar5,*(undefined4 *)(iVar10 + 0x20));
      }
      if ((((cVar1 != '\x01') || (iVar8 == 0)) &&
          (piVar4 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar4 != 0x10)) &&
         ((piVar4 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar4 != 0xf &&
          (piVar4 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar4 != 0x11)))) {
        piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
        (**(code **)(*piVar4 + 0x48))(0);
        FUN_004574e0(param_1,in_ECX,piVar3);
        return;
      }
      FUN_00457490(param_1,piVar3,piStack_8);
    }
  }
  return;
}


// ==== FUN_00450550 @ 0x00450550 ====

bool FUN_00450550(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2 != (int *)0x0) {
    iVar2 = (**(code **)(*param_2 + 0x14))();
    if (*(int *)(iVar2 + 4) == 2) {
      iVar2 = (**(code **)(*param_2 + 0x10))();
      uVar1 = *(undefined4 *)(iVar2 + 4);
      piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
      (**(code **)(*piVar3 + 0x50))(uVar1);
      piVar3 = (int *)FUN_0044f820(uVar1);
      if (piVar3 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar3 + 0x14))();
        if (*(int *)(iVar2 + 4) == 0) {
          iVar2 = (**(code **)(*piVar3 + 0x14))();
          return *(char *)(iVar2 + 0x34) != '\0';
        }
      }
    }
  }
  return false;
}


// ==== FUN_004505c0 @ 0x004505c0 ====

void FUN_004505c0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  
  if ((param_3 != (int *)0x0) && (iVar6 = FUN_0044f820(param_2), iVar6 != 0)) {
    iVar7 = (**(code **)(*param_3 + 0x48))();
    cVar2 = FUN_0044f750(param_3,iVar6,*(undefined4 *)(iVar7 + 0x24));
    cVar3 = FUN_0044f750(param_3,iVar6,*(int *)(iVar7 + 0x24) + 2);
    cVar4 = FUN_0044f750(param_3,iVar6,*(undefined4 *)(iVar7 + 0x20));
    cVar5 = FUN_0044f750(param_3,iVar6,*(undefined4 *)(iVar7 + 0x28));
    puVar8 = (undefined4 *)(**(code **)(*param_3 + 0x10))();
    uVar1 = *puVar8;
    if ((cVar2 == '\x01') || ((cVar3 == '\x01' || (cVar4 == '\x01')))) {
      piVar9 = (int *)(**(code **)(*param_3 + 0x30))();
      if (((*piVar9 != 7) &&
          (((piVar9 = (int *)(**(code **)(*param_3 + 0x30))(), *piVar9 != 5 &&
            (piVar9 = (int *)(**(code **)(*param_3 + 0x30))(), *piVar9 != 0xc)) &&
           (piVar9 = (int *)(**(code **)(*param_3 + 0x30))(), *piVar9 != 0x12)))) &&
         (((piVar9 = (int *)(**(code **)(*param_3 + 0x30))(), *piVar9 != 0x10 &&
           (piVar9 = (int *)(**(code **)(*param_3 + 0x30))(), *piVar9 != 0xf)) &&
          (piVar9 = (int *)(**(code **)(*param_3 + 0x30))(), *piVar9 != 0x11)))) {
        FUN_004577b0(param_1,uVar1,param_2);
      }
    }
    else {
      if ((cVar4 != '\0') || (cVar5 != '\x01')) {
        FUN_00457800(param_1,uVar1,param_2);
        return;
      }
      piVar9 = (int *)(**(code **)(*param_3 + 0x30))();
      if ((((*piVar9 != 0x12) && (piVar9 = (int *)(**(code **)(*param_3 + 0x30))(), *piVar9 != 0x10)
           ) && (piVar9 = (int *)(**(code **)(*param_3 + 0x30))(), *piVar9 != 0xf)) &&
         (piVar9 = (int *)(**(code **)(*param_3 + 0x30))(), *piVar9 != 0x11)) {
        FUN_004577b0(param_1,uVar1,param_2);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00450770 @ 0x00450770 ====

void FUN_00450770(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uStack_40;
  undefined4 *puStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  piVar3 = (int *)FUN_0044f820();
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x10))();
    uStack_38 = (undefined4 *)0x45079f;
    piVar4 = (int *)FUN_0044f820();
    puVar2 = param_3;
    if (piVar4 != (int *)0x0) {
      switch(*param_3) {
      case 0:
        uStack_38 = (undefined4 *)0x4507ca;
        piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
        if (*piVar4 != 0x10) {
          uStack_38 = (undefined4 *)0x4507da;
          piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
          if (*piVar4 != 0xf) {
            uStack_38 = (undefined4 *)0x4507ea;
            piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
            if (*piVar4 != 0x11) {
              uStack_38 = (undefined4 *)0x4507fa;
              piVar3 = (int *)(**(code **)(*piVar3 + 0xc))();
              uVar1 = param_2;
              uStack_38 = (undefined4 *)param_2;
              puStack_3c = (undefined4 *)0x450806;
              (**(code **)(*piVar3 + 0x50))();
              puStack_3c = (undefined4 *)uVar1;
              FUN_00457620(puVar2[1]);
              return;
            }
          }
        }
        break;
      case 1:
        uStack_38 = (undefined4 *)0x450829;
        piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
        if (*piVar4 != 0x10) {
          uStack_38 = (undefined4 *)0x450839;
          piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
          if (*piVar4 != 0xf) {
            uStack_38 = (undefined4 *)0x450849;
            piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
            if (*piVar4 != 0x11) {
              uStack_38 = (undefined4 *)0x450859;
              piVar3 = (int *)(**(code **)(*piVar3 + 0xc))();
              uVar1 = param_2;
              uStack_38 = (undefined4 *)param_2;
              puStack_3c = (undefined4 *)0x450865;
              (**(code **)(*piVar3 + 0x50))();
              puStack_3c = (undefined4 *)uVar1;
              FUN_00457670(puVar2[1]);
              return;
            }
          }
        }
        break;
      case 2:
        uStack_38 = (undefined4 *)0x450888;
        piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
        if (*piVar4 != 0x10) {
          uStack_38 = (undefined4 *)0x450898;
          piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
          if (*piVar4 != 0xf) {
            uStack_38 = (undefined4 *)0x4508a8;
            piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
            if (*piVar4 != 0x11) {
              uStack_38 = (undefined4 *)0x4508b8;
              piVar3 = (int *)(**(code **)(*piVar3 + 0xc))();
              uVar1 = param_2;
              uStack_38 = (undefined4 *)param_2;
              puStack_3c = (undefined4 *)0x4508c4;
              (**(code **)(*piVar3 + 0x50))();
              puStack_3c = (undefined4 *)uVar1;
              FUN_004576c0(puVar2[1]);
              return;
            }
          }
        }
        break;
      case 3:
        uStack_38 = (undefined4 *)0x4508e7;
        piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
        if (*piVar4 != 0x10) {
          uStack_38 = (undefined4 *)0x4508f7;
          piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
          if (*piVar4 != 0xf) {
            uStack_38 = (undefined4 *)0x450907;
            piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
            if (*piVar4 != 0x11) {
              uStack_38 = (undefined4 *)0x450917;
              piVar3 = (int *)(**(code **)(*piVar3 + 0xc))();
              uVar1 = param_2;
              uStack_38 = (undefined4 *)param_2;
              puStack_3c = (undefined4 *)0x450923;
              (**(code **)(*piVar3 + 0x50))();
              puStack_3c = (undefined4 *)uVar1;
              FUN_00457710(puVar2[1]);
              return;
            }
          }
        }
        break;
      case 4:
        uStack_38 = (undefined4 *)0x450946;
        piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
        if (*piVar4 != 0x10) {
          uStack_38 = (undefined4 *)0x450956;
          piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
          if (*piVar4 != 0xf) {
            uStack_38 = (undefined4 *)0x450966;
            piVar4 = (int *)(**(code **)(*piVar3 + 0x30))();
            if (*piVar4 != 0x11) {
              uStack_38 = (undefined4 *)0x450976;
              piVar3 = (int *)(**(code **)(*piVar3 + 0xc))();
              uVar1 = param_2;
              uStack_38 = (undefined4 *)param_2;
              puStack_3c = (undefined4 *)0x450982;
              (**(code **)(*piVar3 + 0x50))();
              puStack_3c = (undefined4 *)uVar1;
              FUN_00457760(puVar2[1]);
              return;
            }
          }
        }
        break;
      case 7:
        uStack_1c = param_3[1];
        uStack_38 = &uStack_20;
        uStack_20 = 0xe;
        puStack_3c = (undefined4 *)0x4509b9;
        (**(code **)(*piVar3 + 0x2c))();
        puStack_3c = &param_2;
        param_2 = 0;
        uStack_40 = 0x4509cb;
        (**(code **)(*piVar3 + 0x3c))();
        uStack_40 = 0x4509d2;
        piVar5 = (int *)(**(code **)(*piVar3 + 0xc))();
        uStack_40 = 0;
        (**(code **)(*piVar5 + 0x58))();
        piVar5 = (int *)(**(code **)(*piVar3 + 0xc))();
        (**(code **)(*piVar5 + 0x50))(0);
        piVar5 = (int *)(**(code **)(*piVar3 + 0xc))();
        (**(code **)(*piVar5 + 0x48))(0);
        (**(code **)(*piVar3 + 0x34))(1);
        (**(code **)(*piVar4 + 0x2c))((int)register0x00000010 + -0x30);
        uStack_40 = 0;
        (**(code **)(*piVar4 + 0x3c))(&uStack_40);
        piVar3 = (int *)(**(code **)(*piVar4 + 0xc))();
        (**(code **)(*piVar3 + 0x58))(0);
        piVar3 = (int *)(**(code **)(*piVar4 + 0xc))();
        (**(code **)(*piVar3 + 0x50))(0);
        piVar3 = (int *)(**(code **)(*piVar4 + 0xc))();
        (**(code **)(*piVar3 + 0x48))(0);
        (**(code **)(*piVar4 + 0x34))(1);
        return;
      case 9:
        uStack_c = param_3[1];
        uStack_38 = &uStack_10;
        uStack_10 = 0xd;
        puStack_3c = (undefined4 *)0x450a88;
        (**(code **)(*piVar3 + 0x2c))();
        uStack_8 = puVar2[1];
        puStack_3c = &uStack_c;
        uStack_c = 0xd;
        uStack_40 = 0x450a9f;
        (**(code **)(*piVar4 + 0x2c))();
      }
    }
  }
  return;
}


// ==== FUN_00450ae0 @ 0x00450ae0 ====

void FUN_00450ae0(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined1 uStack00000000;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = (int *)FUN_0044f820(param_1);
  if (piVar1 != (int *)0x0) {
    if (*param_2 == 7) {
      local_8 = 0xe;
      local_4 = 0;
      (**(code **)(*piVar1 + 0x2c))(&local_8);
      (**(code **)(*piVar1 + 0x3c))(&uStack00000000);
      piVar2 = (int *)(**(code **)(*piVar1 + 0xc))();
      (**(code **)(*piVar2 + 0x50))(0);
      piVar2 = (int *)(**(code **)(*piVar1 + 0xc))();
      (**(code **)(*piVar2 + 0x58))(0);
      piVar2 = (int *)(**(code **)(*piVar1 + 0xc))();
      (**(code **)(*piVar2 + 0x48))(0);
      (**(code **)(*piVar1 + 0x34))(1);
      return;
    }
    if (*param_2 == 9) {
      local_8 = 0xd;
      local_4 = 0;
      (**(code **)(*piVar1 + 0x2c))(&local_8);
    }
  }
  return;
}


// ==== FUN_00450ba0 @ 0x00450ba0 ====

undefined4 FUN_00450ba0(uint param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  cVar1 = (**(code **)(*param_2 + 0x38))();
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*param_2 + 0x30))();
    if (param_1 - *(int *)(iVar2 + 4) < 5000) {
      return 0;
    }
    (**(code **)(*param_2 + 0x34))(1);
  }
  else {
    iVar2 = (**(code **)(*param_2 + 0x30))();
    if (param_1 < *(uint *)(iVar2 + 4)) {
      (**(code **)(*param_2 + 0x34))(1);
      return 0;
    }
  }
  return 1;
}


// ==== FUN_00450c00 @ 0x00450c00 ====

bool FUN_00450c00(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_2 != (int *)0x0) {
    iVar2 = (**(code **)(*param_2 + 0x48))();
    if (*(int *)(iVar2 + 0x8c) != 0) {
      iVar2 = (**(code **)(*param_2 + 0x48))();
      uVar1 = *(uint *)(iVar2 + 0x8c);
      if (uVar1 == 0) {
        return false;
      }
      piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
      uVar4 = (**(code **)(*piVar3 + 0x74))();
      iVar2 = (**(code **)(*param_2 + 0x48))();
      if (uVar4 <= (uint)(*(int *)(iVar2 + 0x90) + param_1)) {
        iVar2 = (**(code **)(*param_2 + 0x48))();
        uVar4 = *(uint *)(iVar2 + 0x98);
        uVar5 = FUN_0044fdf0(param_2);
        if (uVar4 <= uVar5) {
          uVar4 = FUN_0044fd20(param_2);
          return uVar4 < uVar1;
        }
      }
      return false;
    }
  }
  return false;
}


// ==== FUN_00450ca0 @ 0x00450ca0 ====

void FUN_00450ca0(int param_1,int *param_2)

{
  undefined4 uVar1;
  char cVar2;
  char cVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iStack_8;
  undefined4 uStack_4;
  
  if (param_2 != (int *)0x0) {
    puVar4 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
    uVar1 = *puVar4;
    piVar5 = (int *)(**(code **)(*param_2 + 0xc))();
    uVar6 = (**(code **)(*piVar5 + 0x54))();
    piVar5 = (int *)FUN_0044f820(uVar6);
    uStack_4 = uVar1;
    if ((piVar5 == (int *)0x0) || (piVar7 = (int *)(**(code **)(*piVar5 + 0x30))(), *piVar7 == 0xe))
    {
      iStack_8 = param_1;
      (**(code **)(*DAT_00b5a808 + 0x20))(&iStack_8);
      return;
    }
    cVar2 = (**(code **)(*DAT_00b5a804 + 0x14))();
    if (((cVar2 != '\x01') && (cVar2 = (**(code **)(*DAT_00b5a804 + 0x1c))(), cVar2 != '\x01')) ||
       ((iVar8 = (**(code **)(*param_2 + 0x14))(), *(int *)(iVar8 + 4) == 2 &&
        (iVar8 = (**(code **)(*piVar5 + 0x14))(), *(int *)(iVar8 + 4) == 0)))) {
      piVar7 = (int *)(**(code **)(*param_2 + 0x18))();
      iVar8 = *piVar7;
      cVar2 = FUN_0044f750(param_2,piVar5,iVar8);
      if ((cVar2 == '\x01') && (iVar8 != 0)) {
        FUN_00457350(param_1,uVar1,uVar6);
        return;
      }
      iVar8 = (**(code **)(*param_2 + 0x14))();
      iVar9 = (**(code **)(*piVar5 + 0x14))();
      iVar10 = (**(code **)(*param_2 + 0x18))();
      iStack_8 = *(int *)(iVar10 + 0x18);
      cVar2 = FUN_0044fbf0(iVar8 + 0x18,iVar9 + 0x18);
      iVar8 = iStack_8;
      cVar3 = FUN_0044f750(param_2,piVar5,iStack_8);
      if (((cVar2 != '\0') && (cVar3 == '\x01')) && (iVar8 != 0)) {
        FUN_004573f0(param_1,uVar1,uVar6);
        return;
      }
      piVar7 = (int *)(**(code **)(*param_2 + 0xc))();
      uVar11 = (**(code **)(*piVar7 + 100))();
      iVar8 = FUN_0044f860(param_2,uVar11,param_1);
      cVar2 = FUN_0044f750(param_2,piVar5,iVar8);
      if (((cVar2 == '\x01') && (iVar8 != 0)) ||
         ((piVar5 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar5 == 0x10 ||
          ((piVar5 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar5 == 0xf ||
           (piVar5 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar5 == 0x11)))))) {
        FUN_00457490(param_1,uVar1,uVar6);
      }
      else {
        piVar5 = (int *)(**(code **)(*param_2 + 0xc))();
        cVar2 = (**(code **)(*piVar5 + 0x8c))();
        if (cVar2 != '\x01') {
          iStack_8 = param_1;
          (**(code **)(*DAT_00b5a808 + 0x20))(&iStack_8);
          piVar5 = (int *)(**(code **)(*param_2 + 0xc))();
          (**(code **)(*piVar5 + 0x88))(1);
          return;
        }
      }
    }
  }
  return;
}


// ==== FUN_00450ed0 @ 0x00450ed0 ====

void FUN_00450ed0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = (**(code **)(*param_1 + 0x14))();
  if (*(int *)(iVar1 + 4) == 0) {
    iVar1 = (**(code **)(*param_1 + 0x10))();
    iVar1 = *(int *)(iVar1 + 4);
    iVar2 = FUN_0044f820(iVar1);
    if (((iVar2 != 0) && (iVar1 != 0)) &&
       (piVar3 = (int *)FUN_0044f820(iVar1), piVar3 != (int *)0x0)) {
      piVar4 = (int *)(**(code **)(*param_1 + 0xc))();
      iVar1 = *piVar4;
      iVar2 = (**(code **)(*piVar3 + 0x14))();
      (**(code **)(iVar1 + 0x80))(*(undefined4 *)(iVar2 + 0x38));
    }
  }
  return;
}


// ==== FUN_00450f40 @ 0x00450f40 ====

void FUN_00450f40(byte param_1)

{
  void *in_ECX;
  
  FUN_0044f1e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00450f60 @ 0x00450f60 ====

void FUN_00450f60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff60;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00450f80 @ 0x00450f80 ====

void FUN_00450f80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff60;
  return;
}


// ==== FUN_00450f90 @ 0x00450f90 ====

void FUN_00450f90(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  *(undefined4 *)(in_ECX + 0x14) = param_1[4];
  *(undefined4 *)(in_ECX + 0x18) = param_1[5];
  *(undefined4 *)(in_ECX + 0x1c) = param_1[6];
  *(undefined4 *)(in_ECX + 0x20) = param_1[7];
  *(undefined4 *)(in_ECX + 0x24) = param_1[8];
  *(undefined4 *)(in_ECX + 0x28) = param_1[9];
  *(undefined4 *)(in_ECX + 0x2c) = param_1[10];
  *(undefined4 *)(in_ECX + 0x30) = param_1[0xb];
  *(undefined4 *)(in_ECX + 0x34) = param_1[0xc];
  *(undefined4 *)(in_ECX + 0x38) = param_1[0xd];
  *(undefined1 *)(in_ECX + 0x3c) = *(undefined1 *)(param_1 + 0xe);
  *(undefined4 *)(in_ECX + 0x40) = param_1[0xf];
  *(undefined4 *)(in_ECX + 0x44) = param_1[0x10];
  *(undefined4 *)(in_ECX + 0x48) = param_1[0x11];
  *(undefined4 *)(in_ECX + 0x4c) = param_1[0x12];
  *(undefined4 *)(in_ECX + 0x50) = param_1[0x13];
  *(undefined4 *)(in_ECX + 0x54) = param_1[0x14];
  *(undefined4 *)(in_ECX + 0x58) = param_1[0x15];
  *(undefined4 *)(in_ECX + 0x5c) = param_1[0x16];
  *(undefined4 *)(in_ECX + 0x60) = param_1[0x17];
  *(undefined4 *)(in_ECX + 100) = param_1[0x18];
  *(undefined4 *)(in_ECX + 0x68) = param_1[0x19];
  *(undefined4 *)(in_ECX + 0x6c) = param_1[0x1a];
  *(undefined4 *)(in_ECX + 0x70) = param_1[0x1b];
  *(undefined4 *)(in_ECX + 0x74) = param_1[0x1c];
  *(undefined4 *)(in_ECX + 0x78) = param_1[0x1d];
  *(undefined4 *)(in_ECX + 0x7c) = param_1[0x1e];
  *(undefined4 *)(in_ECX + 0x80) = param_1[0x1f];
  *(undefined4 *)(in_ECX + 0x84) = param_1[0x20];
  *(undefined4 *)(in_ECX + 0x88) = param_1[0x21];
  *(undefined4 *)(in_ECX + 0x8c) = param_1[0x22];
  *(undefined4 *)(in_ECX + 0x90) = param_1[0x23];
  *(undefined4 *)(in_ECX + 0x94) = param_1[0x24];
  *(undefined4 *)(in_ECX + 0x98) = param_1[0x25];
  *(undefined4 *)(in_ECX + 0x9c) = param_1[0x26];
  return;
}


// ==== FUN_004510b0 @ 0x004510b0 ====

int FUN_004510b0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_004510c0 @ 0x004510c0 ====

void FUN_004510c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff70;
  return;
}


// ==== FUN_004510d0 @ 0x004510d0 ====

void FUN_004510d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00450f80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004510f0 @ 0x004510f0 ====

void FUN_004510f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff80;
  return;
}


// ==== FUN_00451100 @ 0x00451100 ====

void FUN_00451100(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff80;
  return;
}


// ==== FUN_00451110 @ 0x00451110 ====

void FUN_00451110(void)

{
  return;
}


// ==== FUN_00451120 @ 0x00451120 ====

void FUN_00451120(void)

{
  return;
}


// ==== FUN_00451130 @ 0x00451130 ====

void FUN_00451130(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff80;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00451150 @ 0x00451150 ====

void FUN_00451150(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff88;
  return;
}


// ==== FUN_00451160 @ 0x00451160 ====

void FUN_00451160(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff88;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004511a0 @ 0x004511a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004511a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff98;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5a80c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5a80c = in_ECX;
  return;
}


// ==== FUN_004511d0 @ 0x004511d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004511d0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5a80c = 0;
  *in_ECX = &PTR_FUN_0099ff88;
  return;
}


// ==== FUN_004511f0 @ 0x004511f0 ====

void FUN_004511f0(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  
  if (((param_2 != (int *)0x0) && (piVar2 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar2 != 0xe)
      ) && (cVar1 = FUN_00451260(param_1,param_2), cVar1 != '\0')) {
    FUN_00451320(param_1,param_2);
  }
  return;
}


// ==== FUN_00451230 @ 0x00451230 ====

void FUN_00451230(undefined4 param_1,int param_2)

{
  char cVar1;
  
  if ((param_2 != 0) && (cVar1 = FUN_00451260(param_1,param_2), cVar1 != '\0')) {
    FUN_00451320(param_1,param_2);
  }
  return;
}


// ==== FUN_00451260 @ 0x00451260 ====

bool FUN_00451260(uint param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 != (int *)0x0) {
    iVar2 = (**(code **)(*param_2 + 0x48))();
    if (*(int *)(iVar2 + 0x8c) != 0) {
      iVar2 = (**(code **)(*param_2 + 0x48))();
      uVar1 = *(uint *)(iVar2 + 0x8c);
      if (uVar1 == 0) {
        return false;
      }
      piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
      iVar2 = (**(code **)(*piVar3 + 0x74))();
      iVar4 = (**(code **)(*param_2 + 0x48))();
      if ((uint)(*(int *)(iVar4 + 0x90) + iVar2) <= param_1) {
        iVar2 = (**(code **)(*param_2 + 0x48))();
        uVar6 = *(uint *)(iVar2 + 0x98);
        uVar5 = FUN_0044fdf0(param_2);
        if (uVar6 <= uVar5) {
          uVar6 = FUN_0044fd20(param_2);
          return uVar6 < uVar1;
        }
      }
      return false;
    }
  }
  return false;
}


// ==== FUN_00451300 @ 0x00451300 ====

void FUN_00451300(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ffa8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00451320 @ 0x00451320 ====

void FUN_00451320(undefined4 param_1,int *param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 *local_28;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  int iStack_1c;
  float fStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  float fStack_8;
  float fStack_4;
  
  local_28 = operator_new(0x808);
  if (local_28 == (undefined4 *)0x0) {
    local_28 = (undefined4 *)0x0;
  }
  else {
    *local_28 = &PTR_FUN_0099ffa8;
    local_28[0x201] = 0;
  }
  iVar4 = (**(code **)(*param_2 + 0x48))();
  iVar4 = *(int *)(iVar4 + 0x94);
  iStack_1c = 0;
  uVar1 = iVar4 * 2 + 1;
  while( true ) {
    iVar5 = (**(code **)(*param_2 + 0x14))();
    fVar2 = *(float *)(iVar5 + 0x18);
    iVar5 = (**(code **)(*param_2 + 0x14))();
    fVar3 = *(float *)(iVar5 + 0x1c);
    if (uVar1 == 0) {
      uVar9 = 0;
    }
    else {
      iVar5 = FUN_00797ac0(0x1000);
      uVar9 = FUN_00797ac0(0x1000);
      uVar6 = FUN_00797ac0(0x100);
      uVar9 = (uVar6 & 0xff | iVar5 << 0x14 | (uVar9 & 0xfff) << 8) % uVar1;
    }
    fStack_18 = (float)(uVar9 - iVar4);
    if (uVar1 == 0) {
      uVar9 = 0;
    }
    else {
      iVar5 = FUN_00797ac0(0x1000);
      uVar9 = FUN_00797ac0(0x1000);
      uVar6 = FUN_00797ac0(0x100);
      uVar9 = (uVar6 & 0xff | iVar5 << 0x14 | (uVar9 & 0xfff) << 8) % uVar1;
    }
    iVar10 = (int)fVar2 + (int)fStack_18;
    iVar11 = (int)fVar3 + (uVar9 - iVar4);
    uStack_20 = (undefined2)iVar10;
    uStack_1e = (undefined2)iVar11;
    iVar5 = (**(code **)(*DAT_00b5a718 + 0x10))(&uStack_20);
    if (*(char *)(iVar5 + 4) == '\x01') break;
    iStack_1c = iStack_1c + 1;
    if (4 < iStack_1c) {
LAB_004514cc:
      if (local_28 != (undefined4 *)0x0) {
        (**(code **)*local_28)(1);
      }
      return;
    }
  }
  puVar7 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
  uStack_c = *puVar7;
  fStack_18 = (float)iVar10;
  fStack_14 = (float)iVar11;
  local_28[0x201] = 0;
  uStack_10 = param_1;
  fStack_8 = fStack_18;
  fStack_4 = fStack_14;
  (**(code **)(*DAT_00b5a808 + 0x1c))(&uStack_10);
  piVar8 = (int *)(**(code **)(*param_2 + 0xc))();
  (**(code **)(*piVar8 + 0x70))(param_1);
  goto LAB_004514cc;
}


// ==== FUN_004514f0 @ 0x004514f0 ====

void FUN_004514f0(byte param_1)

{
  void *in_ECX;
  
  FUN_004511d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00451530 @ 0x00451530 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00451530(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bdf8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099ffb0;
  puVar1 = operator_new(0x808);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_0099ffa8;
    puVar1[0x201] = 0;
  }
  in_ECX[1] = puVar1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    _DAT_00b5a810 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  _DAT_00b5a810 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004515c0 @ 0x004515c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004515c0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097be0a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099ffb0;
  _DAT_00b5a810 = 0;
  piVar1 = (int *)(in_ECX[1] + 0x804);
  *piVar1 = *piVar1 - *(int *)(in_ECX[1] + 0x804);
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099ff88;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00451630 @ 0x00451630 ====

void FUN_00451630(undefined4 param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 unaff_retaddr;
  
  if (param_2 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar2 + 0x50))(param_3);
    cVar1 = FUN_004516a0(unaff_retaddr,param_2);
    if (cVar1 != '\0') {
      FUN_00451770(unaff_retaddr,param_2);
    }
  }
  return;
}


// ==== FUN_00451670 @ 0x00451670 ====

void FUN_00451670(undefined4 param_1,int param_2)

{
  char cVar1;
  
  if ((param_2 != 0) && (cVar1 = FUN_004516a0(param_1,param_2), cVar1 != '\0')) {
    FUN_00451770(param_1,param_2);
  }
  return;
}


// ==== FUN_004516a0 @ 0x004516a0 ====

bool FUN_004516a0(uint param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0x30))();
    if (*(uint *)(iVar1 + 4) <= param_1) {
      iVar1 = (**(code **)(*param_2 + 0x28))();
      if (iVar1 != 0) {
        piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
        if (*piVar2 != 0xe) {
          iVar1 = (**(code **)(*DAT_00b5a6fc + 4))();
          return iVar1 != 0;
        }
      }
    }
  }
  return false;
}


// ==== FUN_004516f0 @ 0x004516f0 ====

void FUN_004516f0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0x48))();
    iStack_14 = *(int *)(iVar1 + 0x18) + param_1;
    uStack_18 = 0;
    (**(code **)(*param_2 + 0x2c))(&uStack_18);
    puVar2 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
    uStack_10 = *puVar2;
    iStack_14 = param_1;
    iVar1 = (**(code **)(*param_2 + 0x14))();
    uStack_c = *(undefined4 *)(iVar1 + 0x18);
    uStack_8 = *(undefined4 *)(iVar1 + 0x1c);
    (**(code **)(*DAT_00b5a808 + 0x14))(&iStack_14);
  }
  return;
}


// ==== __break @ 0x00451764 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00451770 @ 0x00451770 ====

void FUN_00451770(undefined4 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined1 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_8;
  
  if (param_2 != (int *)0x0) {
    iVar2 = (**(code **)(*param_2 + 0x14))();
    iStack_24 = *(int *)(iVar2 + 0x18);
    uStack_20 = *(undefined4 *)(iVar2 + 0x1c);
    iVar2 = (**(code **)(*param_2 + 0x14))();
    uStack_2c = *(undefined4 *)(iVar2 + 0x20);
    uStack_28 = *(undefined4 *)(iVar2 + 0x24);
    cVar1 = (**(code **)(*DAT_00b5a800 + 4))(&iStack_24,&uStack_2c,*(undefined4 *)(in_ECX + 4));
    if (cVar1 == '\x01') {
      uStack_28 = 1;
      iVar2 = (**(code **)(*param_2 + 0x48))();
      iStack_24 = *(int *)(iVar2 + 0x1c) + iStack_8;
      (**(code **)(*param_2 + 0x2c))(&uStack_28);
      puVar3 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
      uStack_20 = *puVar3;
      iVar2 = *(int *)(in_ECX + 4);
      iStack_24 = iStack_8;
      uStack_18 = *(undefined4 *)(iVar2 + 0xc);
      uStack_14 = *(undefined4 *)(iVar2 + 0x10);
      uStack_1c = 1;
      *(int *)(iVar2 + 0x804) = *(int *)(iVar2 + 0x804) - *(int *)(iVar2 + 0x804);
      (**(code **)(*DAT_00b5a808 + 0xc))(&iStack_24);
      return;
    }
    FUN_004516f0(iStack_8,param_2);
  }
  return;
}


// ==== FUN_00451860 @ 0x00451860 ====

void FUN_00451860(byte param_1)

{
  void *in_ECX;
  
  FUN_004515c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00451890 @ 0x00451890 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00451890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ffc0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5a814 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5a814 = in_ECX;
  return;
}


// ==== FUN_004518c0 @ 0x004518c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004518c0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5a814 = 0;
  *in_ECX = &PTR_FUN_0099ff88;
  return;
}


// ==== FUN_004518e0 @ 0x004518e0 ====

void FUN_004518e0(undefined4 param_1,int *param_2)

{
  int *piVar1;
  undefined4 unaff_ESI;
  
  if (param_2 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar1 != 0xe) {
      piVar1 = (int *)(**(code **)(*param_2 + 0xc))();
      (**(code **)(*piVar1 + 0x48))(1);
      piVar1 = (int *)(**(code **)(*param_2 + 0xc))();
      (**(code **)(*piVar1 + 0x50))(param_2);
      FUN_00451950(unaff_ESI,param_2);
    }
  }
  return;
}


// ==== FUN_00451930 @ 0x00451930 ====

void FUN_00451930(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    return;
  }
  FUN_00451950();
  return;
}


// ==== FUN_00451950 @ 0x00451950 ====

void FUN_00451950(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined4 uStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  if (param_2 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*param_2 + 0xc))();
    uVar3 = (**(code **)(*piVar2 + 0x54))();
    iVar4 = FUN_0044f820(uVar3);
    if (iVar4 != 0) {
      uVar5 = FUN_0044fc60(uVar3);
      iVar4 = (**(code **)(*param_2 + 0x48))();
      if ((uVar5 < *(uint *)(iVar4 + 0x30)) &&
         (piVar2 = (int *)(**(code **)(*DAT_00b5a6fc + 8))(), piVar2 != (int *)0x0)) {
        piVar6 = (int *)(**(code **)(*piVar2 + 8))();
        while (piVar6 != (int *)0x0) {
          piVar10 = *(int **)(*piVar6 + 4);
          if (piVar10 == (int *)0x0) {
            piVar6 = (int *)(**(code **)(*piVar2 + 0x48))(piVar6);
          }
          else {
            piVar7 = (int *)(**(code **)(*piVar10 + 0x10))();
            iVar4 = *piVar7;
            piVar7 = (int *)(**(code **)(*param_2 + 0x10))();
            if (iVar4 == *piVar7) {
              piVar6 = (int *)(**(code **)(*piVar2 + 0x48))(piVar6);
            }
            else {
              iVar8 = (**(code **)(*piVar10 + 0x48))();
              if (uVar5 < *(uint *)(iVar8 + 0x3c)) {
                iVar8 = (**(code **)(*piVar10 + 0x14))();
                iVar8 = *(int *)(iVar8 + 4);
                iVar9 = (**(code **)(*param_2 + 0x14))();
                if (iVar8 == *(int *)(iVar9 + 4)) {
                  (**(code **)(*param_2 + 0x14))();
                  (**(code **)(*piVar10 + 0x14))();
                  iVar8 = (**(code **)(*param_2 + 0x48))();
                  cVar1 = FUN_0044f750(param_2,piVar10,*(undefined4 *)(iVar8 + 0x34));
                  if (cVar1 == '\0') {
                    piVar6 = (int *)(**(code **)(*piVar2 + 0x48))(piVar6);
                  }
                  else {
                    piVar7 = (int *)(**(code **)(*piVar10 + 0x30))();
                    if (((((*piVar7 != 7) ||
                          (piVar7 = (int *)(**(code **)(*piVar10 + 0x30))(), *piVar7 != 5)) ||
                         (piVar7 = (int *)(**(code **)(*piVar10 + 0x30))(), *piVar7 != 0xc)) ||
                        ((piVar7 = (int *)(**(code **)(*piVar10 + 0x30))(), *piVar7 != 0xe ||
                         (piVar7 = (int *)(**(code **)(*piVar10 + 0x30))(), *piVar7 != 0xf)))) ||
                       ((piVar7 = (int *)(**(code **)(*piVar10 + 0x30))(), *piVar7 != 0x10 ||
                        ((piVar7 = (int *)(**(code **)(*piVar10 + 0x30))(), *piVar7 != 0x12 ||
                         (piVar10 = (int *)(**(code **)(*piVar10 + 0x30))(), *piVar10 != 0x11))))))
                    {
                      uStack_c = param_1;
                      iStack_8 = iVar4;
                      uStack_4 = uVar3;
                      (**(code **)(*DAT_00b5a808 + 0x18))(&uStack_c);
                    }
                    piVar6 = (int *)(**(code **)(*piVar2 + 0x48))(piVar6);
                  }
                }
                else {
                  piVar6 = (int *)(**(code **)(*piVar2 + 0x48))(piVar6);
                }
              }
              else {
                piVar6 = (int *)(**(code **)(*piVar2 + 0x48))(piVar6);
              }
            }
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_00451b40 @ 0x00451b40 ====

void FUN_00451b40(byte param_1)

{
  void *in_ECX;
  
  FUN_004518c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00451b80 @ 0x00451b80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00451b80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ffd0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5a818 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5a818 = in_ECX;
  return;
}


// ==== FUN_00451bb0 @ 0x00451bb0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00451bb0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5a818 = 0;
  *in_ECX = &PTR_FUN_0099ff88;
  return;
}


// ==== FUN_00451bd0 @ 0x00451bd0 ====

void FUN_00451bd0(undefined4 param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_ESI;
  
  if (param_2 != (int *)0x0) {
    piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar3 + 0x50))(param_3);
    piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar3 + 0x48))(1);
    cVar1 = FUN_00451d50(unaff_ESI,param_2);
    if (cVar1 != '\0') {
      FUN_00452270(param_2,unaff_ESI);
      uVar2 = FUN_00452a00(param_2);
      iVar4 = FUN_00451e90(param_2);
      if (iVar4 == 1) {
        FUN_004520b0(unaff_ESI,param_2,uVar2);
        return;
      }
      if (iVar4 == 2) {
        FUN_00452180(unaff_ESI,param_2,uVar2);
        return;
      }
      FUN_00451fe0(unaff_ESI,param_2,uVar2);
    }
  }
  return;
}


// ==== FUN_00451c80 @ 0x00451c80 ====

void FUN_00451c80(undefined4 param_1,int *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 unaff_ESI;
  
  if (param_2 != (int *)0x0) {
    piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
    piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
    iVar6 = *piVar4;
    uVar5 = (**(code **)(*piVar3 + 0x54))();
    (**(code **)(iVar6 + 0x50))(uVar5);
    piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar3 + 0x48))(1);
    cVar1 = FUN_00451d50(unaff_ESI,param_2);
    if (cVar1 != '\0') {
      FUN_00452270(param_2,unaff_ESI);
      uVar2 = FUN_00452a00(param_2);
      iVar6 = FUN_00451e90(param_2);
      if (iVar6 == 1) {
        FUN_004520b0(unaff_ESI,param_2,uVar2);
        return;
      }
      if (iVar6 == 2) {
        FUN_00452180(unaff_ESI,param_2,uVar2);
        return;
      }
      FUN_00451fe0(unaff_ESI,param_2,uVar2);
    }
  }
  return;
}


// ==== FUN_00451d50 @ 0x00451d50 ====

bool FUN_00451d50(uint param_1,int *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  
  if ((param_2 == (int *)0x0) || (iVar3 = (**(code **)(*param_2 + 0x28))(), iVar3 == 0)) {
    return false;
  }
  iVar3 = (**(code **)(*param_2 + 0x30))();
  if ((param_1 <= *(uint *)(iVar3 + 4)) ||
     (((cVar1 = (**(code **)(*param_2 + 0x38))(), cVar1 == '\0' ||
       (piVar4 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar4 == 0x12)) ||
      (iVar3 = (**(code **)(*DAT_00b5a6fc + 4))(), iVar3 == 0)))) {
    return false;
  }
  piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
  uVar5 = (**(code **)(*piVar4 + 0x54))();
  piVar4 = (int *)FUN_0044f820(uVar5);
  if (piVar4 == (int *)0x0) {
    iVar3 = *param_2;
    uVar5 = (**(code **)(*DAT_00b5a708 + 4))(1,param_1,uVar5);
    (**(code **)(iVar3 + 0x1c))(uVar5);
  }
  else {
    piVar6 = (int *)(**(code **)(*piVar4 + 0x30))();
    if (*piVar6 != 0xe) {
      cVar1 = (**(code **)(*DAT_00b5a804 + 0x1c))();
      if (((cVar1 == '\0') && (iVar3 = (**(code **)(*param_2 + 0x14))(), *(int *)(iVar3 + 4) == 0))
         && (iVar3 = (**(code **)(*piVar4 + 0x14))(), *(int *)(iVar3 + 4) == 0)) {
        iVar3 = (**(code **)(*param_2 + 0x14))();
        iVar7 = (**(code **)(*piVar4 + 0x14))();
        if (*(int *)(iVar3 + 0x38) == *(int *)(iVar7 + 0x38)) {
          return false;
        }
      }
      iVar3 = (**(code **)(*param_2 + 0x18))();
      uVar5 = *(undefined4 *)(iVar3 + 0x18);
      iVar3 = (**(code **)(*param_2 + 0x14))();
      if ((*(int *)(iVar3 + 4) == 0) &&
         (iVar3 = (**(code **)(*piVar4 + 0x14))(), *(int *)(iVar3 + 4) == 3)) {
        uVar2 = FUN_0044ee60(param_2,piVar4,uVar5);
        return (bool)uVar2;
      }
      cVar1 = FUN_0044f750(param_2,piVar4,uVar5);
      return cVar1 != '\0';
    }
  }
  return false;
}


// ==== FUN_00451e90 @ 0x00451e90 ====

undefined4 FUN_00451e90(int *param_1)

{
  uint uVar1;
  byte bVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  piVar3 = (int *)(**(code **)(*param_1 + 0xc))();
  uVar4 = (**(code **)(*piVar3 + 0x54))();
  iVar5 = FUN_0044f820(uVar4);
  if (iVar5 == 0) {
    return 3;
  }
  iVar6 = (**(code **)(*param_1 + 0x14))();
  iVar6 = (**(code **)(*param_1 + 0x14))((int)ROUND((float10)*(int *)(iVar6 + 0xc)));
  bVar2 = FUN_0044f040((int)ROUND((float10)*(int *)(iVar6 + 8)));
  iVar6 = (**(code **)(*param_1 + 0x48))();
  uVar1 = *(uint *)(iVar6 + 0x80);
  uVar9 = *(uint *)(iVar6 + 0x74);
  iVar7 = (**(code **)(*param_1 + 0x18))();
  FUN_0044f750(param_1,iVar5,*(undefined4 *)(iVar7 + 0x20));
  if ((uVar9 != 0) && (bVar2 <= uVar9)) {
    uVar9 = *(uint *)(iVar6 + 0x7c);
    if (uVar9 == 0) {
      return 0;
    }
    uVar8 = FUN_0044ee00(0,0x65);
    if (uVar8 < uVar9) {
      return 1;
    }
  }
  iVar7 = (**(code **)(*param_1 + 0x18))();
  FUN_0044f750(param_1,iVar5,*(undefined4 *)(iVar7 + 0x28));
  if ((((uVar1 == 0) || (uVar1 < bVar2)) || (uVar1 = *(uint *)(iVar6 + 0x88), uVar1 == 0)) ||
     (uVar9 = FUN_0044ee00(0,0x65), uVar1 <= uVar9)) {
    return 0;
  }
  return 2;
}


// ==== FUN_00451fe0 @ 0x00451fe0 ====

void FUN_00451fe0(int param_1,int *param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  char cStack_c;
  
  (**(code **)(*param_2 + 0x48))();
  iVar1 = (**(code **)(*param_2 + 0x18))();
  iVar1 = *(int *)(iVar1 + 0x1c);
  iStack_1c = 0x13;
  iStack_18 = 0;
  piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
  if (*piVar2 != 0x10) {
    piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar2 != 0xf) {
      piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
      if ((*piVar2 != 0x11) && (iStack_1c = 5, param_3 != '\x01')) goto LAB_00452043;
    }
  }
  iStack_1c = 0xf;
LAB_00452043:
  iStack_18 = param_1 + iVar1;
  (**(code **)(*param_2 + 0x2c))(&iStack_1c);
  (**(code **)(*param_2 + 0x34))(0);
  iStack_1c = param_1;
  puVar3 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
  iStack_18 = *puVar3;
  uStack_10 = 3;
  piVar2 = (int *)(**(code **)(*param_2 + 0xc))();
  uStack_14 = (**(code **)(*piVar2 + 0x54))();
  cStack_c = param_3;
  (**(code **)(*DAT_00b5a808 + 8))(&iStack_1c);
  return;
}


// ==== FUN_004520b0 @ 0x004520b0 ====

void FUN_004520b0(int param_1,int *param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  char cStack_c;
  
  iVar1 = (**(code **)(*param_2 + 0x18))();
  iVar1 = *(int *)(iVar1 + 0x24);
  iStack_1c = 0x13;
  iStack_18 = 0;
  piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
  if (*piVar2 != 0xf) {
    piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar2 != 0x10) {
      piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
      if ((*piVar2 != 0x11) && (iStack_1c = 5, param_3 != '\x01')) goto LAB_0045210c;
    }
  }
  iStack_1c = 0xf;
LAB_0045210c:
  iStack_18 = param_1 + iVar1;
  (**(code **)(*param_2 + 0x2c))(&iStack_1c);
  (**(code **)(*param_2 + 0x34))(0);
  iStack_1c = param_1;
  puVar3 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
  iStack_18 = *puVar3;
  uStack_10 = 5;
  piVar2 = (int *)(**(code **)(*param_2 + 0xc))();
  uStack_14 = (**(code **)(*piVar2 + 0x54))();
  cStack_c = param_3;
  (**(code **)(*DAT_00b5a808 + 8))(&iStack_1c);
  return;
}


// ==== FUN_00452180 @ 0x00452180 ====

void FUN_00452180(int param_1,int *param_2,char param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 uStack_c;
  
  iVar2 = (**(code **)(*param_2 + 0x18))();
  iVar2 = *(int *)(iVar2 + 0x2c);
  iStack_1c = 0x13;
  iStack_18 = 0;
  piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
  if (*piVar3 == 0xf) {
LAB_004521d4:
    iStack_1c = 0xf;
  }
  else {
    piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar3 == 0x10) goto LAB_004521d4;
    piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
    if ((*piVar3 == 0x11) || (iStack_1c = 5, param_3 == '\x01')) goto LAB_004521d4;
  }
  iStack_18 = param_1 + iVar2;
  (**(code **)(*param_2 + 0x2c))(&iStack_1c);
  (**(code **)(*param_2 + 0x34))(0);
  iStack_1c = param_1;
  puVar4 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
  iStack_18 = *puVar4;
  uStack_10 = 4;
  piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
  uStack_14 = (**(code **)(*piVar3 + 0x54))();
  cVar1 = (**(code **)(*DAT_00b5a804 + 0x14))();
  if (cVar1 != '\x01') {
    cVar1 = (**(code **)(*DAT_00b5a804 + 0x1c))();
    if (cVar1 != '\x01') {
      uStack_c = 0;
      goto LAB_00452258;
    }
  }
  uStack_c = (undefined1)param_1;
LAB_00452258:
  (**(code **)(*DAT_00b5a808 + 8))(&iStack_1c);
  return;
}


// ==== FUN_00452270 @ 0x00452270 ====

void FUN_00452270(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 != (int *)0x0) {
    iVar2 = (**(code **)(*param_1 + 0x48))();
    uVar1 = *(undefined4 *)(iVar2 + 4);
    piVar3 = (int *)(**(code **)(*param_1 + 0xc))();
    (**(code **)(*piVar3 + 0x60))(uVar1);
    piVar3 = (int *)(**(code **)(*param_1 + 0xc))();
    (**(code **)(*piVar3 + 0x68))(param_1);
  }
  return;
}


// ==== FUN_004522b0 @ 0x004522b0 ====

void FUN_004522b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00451bb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004522f0 @ 0x004522f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004522f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ffe0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5a81c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5a81c = in_ECX;
  return;
}


// ==== FUN_00452320 @ 0x00452320 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00452320(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5a81c = 0;
  *in_ECX = &PTR_FUN_0099ff88;
  return;
}


// ==== FUN_00452340 @ 0x00452340 ====

void FUN_00452340(undefined4 param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_ESI;
  
  if (param_2 != (int *)0x0) {
    piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar3 + 0x50))(param_3);
    piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar3 + 0x48))(1);
    cVar1 = FUN_004524c0(unaff_ESI,param_2);
    if (cVar1 != '\0') {
      FUN_00452270(param_2,unaff_ESI);
      uVar2 = FUN_00452a00(param_2);
      iVar4 = FUN_004525f0(param_2);
      if (iVar4 == 1) {
        FUN_00452820(unaff_ESI,param_2,uVar2);
        return;
      }
      if (iVar4 == 2) {
        FUN_00452900(unaff_ESI,param_2,uVar2);
        return;
      }
      FUN_00452740(unaff_ESI,param_2,uVar2);
    }
  }
  return;
}


// ==== FUN_004523f0 @ 0x004523f0 ====

void FUN_004523f0(undefined4 param_1,int *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 unaff_ESI;
  
  if (param_2 != (int *)0x0) {
    piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
    piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
    iVar6 = *piVar4;
    uVar5 = (**(code **)(*piVar3 + 0x54))();
    (**(code **)(iVar6 + 0x50))(uVar5);
    piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar3 + 0x48))(1);
    cVar1 = FUN_004524c0(unaff_ESI,param_2);
    if (cVar1 != '\0') {
      FUN_00452270(param_2,unaff_ESI);
      uVar2 = FUN_00452a00(param_2);
      iVar6 = FUN_004525f0(param_2);
      if (iVar6 == 1) {
        FUN_00452820(unaff_ESI,param_2,uVar2);
        return;
      }
      if (iVar6 == 2) {
        FUN_00452900(unaff_ESI,param_2,uVar2);
        return;
      }
      FUN_00452740(unaff_ESI,param_2,uVar2);
    }
  }
  return;
}


// ==== FUN_004524c0 @ 0x004524c0 ====

bool FUN_004524c0(uint param_1,int *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  
  if ((param_2 == (int *)0x0) || (iVar3 = (**(code **)(*param_2 + 0x28))(), iVar3 == 0)) {
    return false;
  }
  iVar3 = (**(code **)(*param_2 + 0x30))();
  if ((param_1 <= *(uint *)(iVar3 + 4)) ||
     ((cVar1 = (**(code **)(*param_2 + 0x38))(), cVar1 == '\0' ||
      (piVar4 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar4 == 0x12)))) {
    return false;
  }
  piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
  uVar5 = (**(code **)(*piVar4 + 0x54))();
  piVar4 = (int *)FUN_0044f820(uVar5);
  if (piVar4 == (int *)0x0) {
    iVar3 = *param_2;
    uVar5 = (**(code **)(*DAT_00b5a708 + 4))(1,param_1,uVar5);
    (**(code **)(iVar3 + 0x1c))(uVar5);
  }
  else {
    piVar6 = (int *)(**(code **)(*piVar4 + 0x30))();
    if (*piVar6 != 0xe) {
      cVar1 = (**(code **)(*DAT_00b5a804 + 0x1c))();
      if (((cVar1 == '\0') && (iVar3 = (**(code **)(*param_2 + 0x14))(), *(int *)(iVar3 + 4) == 0))
         && (iVar3 = (**(code **)(*piVar4 + 0x14))(), *(int *)(iVar3 + 4) == 0)) {
        iVar3 = (**(code **)(*param_2 + 0x14))();
        iVar7 = (**(code **)(*piVar4 + 0x14))();
        if (*(int *)(iVar3 + 0x38) == *(int *)(iVar7 + 0x38)) {
          return false;
        }
      }
      puVar8 = (undefined4 *)(**(code **)(*param_2 + 0x18))();
      uVar5 = *puVar8;
      iVar3 = (**(code **)(*param_2 + 0x14))();
      if ((*(int *)(iVar3 + 4) == 0) &&
         (iVar3 = (**(code **)(*piVar4 + 0x14))(), *(int *)(iVar3 + 4) == 3)) {
        uVar2 = FUN_0044ee60(param_2,piVar4,uVar5);
        return (bool)uVar2;
      }
      cVar1 = FUN_0044f750(param_2,piVar4,uVar5);
      return cVar1 != '\0';
    }
  }
  return false;
}


// ==== FUN_004525f0 @ 0x004525f0 ====

undefined4 FUN_004525f0(int *param_1)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  piVar4 = (int *)(**(code **)(*param_1 + 0xc))();
  uVar5 = (**(code **)(*piVar4 + 0x54))();
  iVar6 = FUN_0044f820(uVar5);
  if (iVar6 == 0) {
    return 3;
  }
  iVar7 = (**(code **)(*param_1 + 0x14))();
  iVar7 = (**(code **)(*param_1 + 0x14))((int)ROUND((float10)*(int *)(iVar7 + 0xc)));
  bVar2 = FUN_0044f040((int)ROUND((float10)*(int *)(iVar7 + 8)));
  iVar7 = (**(code **)(*param_1 + 0x48))();
  uVar1 = *(uint *)(iVar7 + 0x80);
  uVar10 = *(uint *)(iVar7 + 0x74);
  iVar8 = (**(code **)(*param_1 + 0x18))();
  cVar3 = FUN_0044f750(param_1,iVar6,*(undefined4 *)(iVar8 + 8));
  if (((uVar10 != 0) && (bVar2 <= uVar10)) && (cVar3 != '\0')) {
    uVar10 = *(uint *)(iVar7 + 0x78);
    if (uVar10 == 0) {
      return 0;
    }
    uVar9 = FUN_0044ee00(0,0x65);
    if (uVar9 < uVar10) {
      return 1;
    }
  }
  iVar8 = (**(code **)(*param_1 + 0x18))();
  cVar3 = FUN_0044f750(param_1,iVar6,*(undefined4 *)(iVar8 + 0x10));
  if (((uVar1 == 0) || (uVar1 < bVar2)) ||
     ((cVar3 == '\0' ||
      ((uVar1 = *(uint *)(iVar7 + 0x84), uVar1 == 0 ||
       (uVar10 = FUN_0044ee00(0,0x65), uVar1 <= uVar10)))))) {
    return 0;
  }
  return 2;
}


// ==== FUN_00452740 @ 0x00452740 ====

void FUN_00452740(int param_1,int *param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  char cStack_c;
  
  iVar1 = (**(code **)(*param_2 + 0x18))();
  iVar1 = *(int *)(iVar1 + 4);
  piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
  if (*piVar2 != 0x10) {
    piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar2 != 0xf) {
      piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
      if ((*piVar2 != 0x11) && (param_3 != '\x01')) {
        iStack_18 = iVar1 + param_1;
        iStack_1c = 7;
        (**(code **)(*param_2 + 0x2c))(&iStack_1c);
        goto LAB_004527c0;
      }
    }
  }
  iStack_18 = iVar1 + param_1;
  iStack_1c = 0x10;
  (**(code **)(*param_2 + 0x2c))(&iStack_1c);
LAB_004527c0:
  (**(code **)(*param_2 + 0x34))(0);
  iStack_1c = param_1;
  puVar3 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
  iStack_18 = *puVar3;
  uStack_10 = 0;
  piVar2 = (int *)(**(code **)(*param_2 + 0xc))();
  uStack_14 = (**(code **)(*piVar2 + 0x54))();
  cStack_c = param_3;
  (**(code **)(*DAT_00b5a808 + 8))(&iStack_1c);
  return;
}


// ==== FUN_00452820 @ 0x00452820 ====

void FUN_00452820(int param_1,int *param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  char cStack_c;
  
  iVar1 = (**(code **)(*param_2 + 0x18))();
  iVar1 = *(int *)(iVar1 + 0xc);
  piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
  if (*piVar2 != 0x10) {
    piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar2 != 0xf) {
      piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
      if ((*piVar2 != 0x11) && (param_3 != '\x01')) {
        iStack_18 = iVar1 + param_1;
        iStack_1c = 7;
        (**(code **)(*param_2 + 0x2c))(&iStack_1c);
        goto LAB_004528a0;
      }
    }
  }
  iStack_18 = iVar1 + param_1;
  iStack_1c = 0x10;
  (**(code **)(*param_2 + 0x2c))(&iStack_1c);
LAB_004528a0:
  (**(code **)(*param_2 + 0x34))(0);
  iStack_1c = param_1;
  puVar3 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
  iStack_18 = *puVar3;
  uStack_10 = 2;
  piVar2 = (int *)(**(code **)(*param_2 + 0xc))();
  uStack_14 = (**(code **)(*piVar2 + 0x54))();
  cStack_c = param_3;
  (**(code **)(*DAT_00b5a808 + 8))(&iStack_1c);
  return;
}


// ==== FUN_00452900 @ 0x00452900 ====

void FUN_00452900(int param_1,int *param_2,char param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  char cStack_c;
  
  iVar2 = (**(code **)(*param_2 + 0x18))();
  iVar2 = *(int *)(iVar2 + 0x14);
  piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
  if (*piVar3 == 0x10) {
LAB_00452962:
    iStack_18 = iVar2 + param_1;
    iStack_1c = 0x10;
    (**(code **)(*param_2 + 0x2c))(&iStack_1c);
  }
  else {
    piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar3 == 0xf) goto LAB_00452962;
    piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
    if ((*piVar3 == 0x11) || (param_3 == '\x01')) goto LAB_00452962;
    iStack_18 = iVar2 + param_1;
    iStack_1c = 7;
    (**(code **)(*param_2 + 0x2c))(&iStack_1c);
  }
  (**(code **)(*param_2 + 0x34))(0);
  iStack_1c = param_1;
  puVar4 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
  iStack_18 = *puVar4;
  uStack_10 = 1;
  piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
  uStack_14 = (**(code **)(*piVar3 + 0x54))();
  cVar1 = (**(code **)(*DAT_00b5a804 + 0x14))();
  if (cVar1 != '\x01') {
    cVar1 = (**(code **)(*DAT_00b5a804 + 0x1c))();
    cStack_c = '\0';
    if (cVar1 != '\x01') goto LAB_004529db;
  }
  cStack_c = param_3;
LAB_004529db:
  (**(code **)(*DAT_00b5a808 + 8))(&iStack_1c);
  return;
}


// ==== FUN_00452a00 @ 0x00452a00 ====

bool FUN_00452a00(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x14))();
    if (*(int *)(iVar1 + 4) == 0) {
      piVar2 = (int *)(**(code **)(*param_1 + 0xc))();
      uVar3 = (**(code **)(*piVar2 + 0x54))();
      piVar2 = (int *)FUN_0044f820(uVar3);
      if (piVar2 != (int *)0x0) {
        iVar1 = (**(code **)(*param_1 + 0x10))();
        iVar1 = *(int *)(iVar1 + 4);
        iVar4 = FUN_0044f820(iVar1);
        if (iVar4 != 0) {
          piVar5 = (int *)(**(code **)(*piVar2 + 0x10))();
          if (*piVar5 != iVar1) {
            iVar1 = (**(code **)(*piVar2 + 0x14))();
            return *(int *)(iVar1 + 4) == 0;
          }
        }
      }
      return false;
    }
  }
  return false;
}


// ==== FUN_00452a80 @ 0x00452a80 ====

void FUN_00452a80(byte param_1)

{
  void *in_ECX;
  
  FUN_00452320();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00452ad0 @ 0x00452ad0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00452ad0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097be28;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099fff0;
  puVar1 = operator_new(0x808);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_0099ffa8;
    puVar1[0x201] = 0;
  }
  in_ECX[1] = puVar1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    _DAT_00b5a820 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  _DAT_00b5a820 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00452b60 @ 0x00452b60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00452b60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097be3a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099fff0;
  _DAT_00b5a820 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099ff88;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00452bc0 @ 0x00452bc0 ====

void FUN_00452bc0(undefined4 param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 unaff_ESI;
  
  if (param_2 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar2 + 0x50))(param_3);
    piVar2 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar2 + 0x48))(1);
    cVar1 = FUN_00452e60(unaff_ESI,param_2);
    if (cVar1 != '\0') {
      FUN_00453270(unaff_ESI,param_2);
    }
  }
  return;
}


// ==== FUN_00452c10 @ 0x00452c10 ====

void FUN_00452c10(undefined4 param_1,int param_2)

{
  char cVar1;
  
  if ((param_2 != 0) && (cVar1 = FUN_00452e60(param_1,param_2), cVar1 != '\0')) {
    FUN_00453270(param_1,param_2);
  }
  return;
}


// ==== FUN_00452c40 @ 0x00452c40 ====

int FUN_00452c40(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    return 0;
  }
  iVar3 = (**(code **)(*param_1 + 0x14))();
  fVar1 = *(float *)(iVar3 + 0x18);
  iVar3 = (**(code **)(*param_1 + 0x14))();
  fVar2 = *(float *)(iVar3 + 0x1c);
  iVar3 = (**(code **)(*param_2 + 0x14))();
  iVar4 = (int)ROUND(fVar1) - (int)ROUND(*(float *)(iVar3 + 0x18));
  iVar3 = (**(code **)(*param_2 + 0x14))();
  iVar3 = (int)ROUND(fVar2) - (int)*(float *)(iVar3 + 0x1c);
  return iVar3 * iVar3 + iVar4 * iVar4;
}


// ==== FUN_00452d00 @ 0x00452d00 ====

undefined4 FUN_00452d00(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 uStack_8;
  
  piVar1 = (int *)FUN_0044f820(param_2);
  uVar9 = 0;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  piVar2 = (int *)(**(code **)(*piVar1 + 0xc))();
  (**(code **)(*piVar2 + 8))();
  piVar2 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  uStack_8 = 0;
  piVar3 = (int *)(**(code **)(*piVar2 + 8))();
joined_r0x00452d5a:
  do {
    if (piVar3 == (int *)0x0) {
      return uStack_8;
    }
    piVar7 = *(int **)(*piVar3 + 4);
    if (piVar7 != (int *)0x0) {
      piVar4 = (int *)(**(code **)(*piVar7 + 0xc))();
      piVar4 = (int *)(**(code **)(*piVar4 + 4))();
      if (param_1 != *piVar4) {
        piVar4 = (int *)(**(code **)(*piVar7 + 0xc))();
        iVar5 = (**(code **)(*piVar4 + 0x54))();
        if (param_2 != iVar5) {
          piVar3 = (int *)(**(code **)(*piVar2 + 0x48))(piVar3);
          goto joined_r0x00452d5a;
        }
        piVar4 = (int *)(**(code **)(*piVar7 + 0xc))();
        (**(code **)(*piVar4 + 8))();
        uVar6 = FUN_00452c40(piVar7,piVar1);
        if (uVar9 < uVar6) {
          piVar7 = (int *)(**(code **)(*piVar7 + 0xc))();
          puVar8 = (undefined4 *)(**(code **)(*piVar7 + 4))();
          uStack_8 = *puVar8;
          uVar9 = uVar6;
        }
      }
    }
    piVar3 = (int *)(**(code **)(*piVar2 + 0x48))(piVar3);
  } while( true );
}


// ==== FUN_00452e00 @ 0x00452e00 ====

void FUN_00452e00(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 unaff_retaddr;
  undefined1 auStack_2 [2];
  
  piVar2 = (int *)FUN_0044f820(param_1);
  if (piVar2 != (int *)0x0) {
    piVar3 = (int *)(**(code **)(*piVar2 + 0xc))();
    (**(code **)(*piVar3 + 0x48))(0);
    (**(code **)(*piVar2 + 0x3c))(auStack_2 + -6);
    iVar1 = *piVar2;
    uVar4 = (**(code **)(*DAT_00b5a708 + 4))(1,unaff_retaddr,0);
    (**(code **)(iVar1 + 0x1c))(uVar4);
  }
  return;
}


// ==== FUN_00452e60 @ 0x00452e60 ====

undefined4 FUN_00452e60(uint param_1,int *param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**(code **)(*param_2 + 0x30))();
  if ((((param_1 < *(uint *)(iVar3 + 4)) ||
       (cVar2 = (**(code **)(*param_2 + 0x38))(), cVar2 == '\0')) ||
      (iVar3 = (**(code **)(*param_2 + 0x28))(), iVar3 == 0)) ||
     (piVar4 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar4 == 0x12)) {
    return 0;
  }
  piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
  uVar5 = (**(code **)(*piVar4 + 0x54))();
  piVar4 = (int *)FUN_0044f820(uVar5);
  if (piVar4 == (int *)0x0) {
    iVar3 = *param_2;
    uVar5 = (**(code **)(*DAT_00b5a708 + 4))(1,param_1,uVar5);
    (**(code **)(iVar3 + 0x1c))(uVar5);
  }
  else {
    piVar6 = (int *)(**(code **)(*piVar4 + 0x30))();
    if (*piVar6 != 0xe) {
      cVar2 = (**(code **)(*DAT_00b5a804 + 0x1c))();
      if (((cVar2 == '\0') && (iVar3 = (**(code **)(*param_2 + 0x14))(), *(int *)(iVar3 + 4) == 0))
         && (iVar3 = (**(code **)(*piVar4 + 0x14))(), *(int *)(iVar3 + 4) == 0)) {
        iVar3 = (**(code **)(*param_2 + 0x14))();
        iVar7 = (**(code **)(*piVar4 + 0x14))();
        if (*(int *)(iVar3 + 0x38) == *(int *)(iVar7 + 0x38)) {
          return 0;
        }
      }
      piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
      uVar5 = (**(code **)(*piVar4 + 0x54))();
      uVar8 = FUN_0044fc60(uVar5);
      iVar3 = (**(code **)(*param_2 + 0x48))();
      if (*(uint *)(iVar3 + 0x3c) < uVar8) {
        puVar9 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
        uVar1 = *puVar9;
        iVar3 = (**(code **)(*param_2 + 0x48))();
        iVar3 = uVar8 - *(int *)(iVar3 + 0x3c);
        if (0 < iVar3) {
          do {
            iVar7 = FUN_00452d00(uVar1,uVar5);
            if (iVar7 != 0) {
              FUN_00452e00(iVar7,param_1);
            }
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00452fa0 @ 0x00452fa0 ====

void FUN_00452fa0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int local_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_18 = 0;
  iVar1 = (**(code **)(*param_2 + 0x48))();
  iStack_14 = *(int *)(iVar1 + 0x18) + param_1;
  (**(code **)(*param_2 + 0x2c))(&local_18);
  (**(code **)(*param_2 + 0x34))(0);
  puVar2 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
  iStack_14 = *puVar2;
  local_18 = param_1;
  iVar1 = (**(code **)(*param_2 + 0x14))();
  uStack_10 = *(undefined4 *)(iVar1 + 0x18);
  uStack_c = *(undefined4 *)(iVar1 + 0x1c);
  (**(code **)(*DAT_00b5a808 + 0x14))(&local_18);
  return;
}


// ==== FUN_00453020 @ 0x00453020 ====

void FUN_00453020(int param_1,int *param_2,int *param_3)

{
  float10 fVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int in_ECX;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float fVar9;
  float fStack_40;
  float fStack_34;
  int iStack_30;
  float fStack_2c;
  float fStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined1 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar3 = (**(code **)(*param_2 + 0x14))();
  iStack_24 = *(int *)(iVar3 + 0x18);
  uStack_20 = *(undefined4 *)(iVar3 + 0x1c);
  iVar3 = (**(code **)(*param_3 + 0x14))();
  fStack_2c = *(float *)(iVar3 + 0x18);
  fStack_28 = *(float *)(iVar3 + 0x1c);
  piVar4 = (int *)(**(code **)(*param_3 + 0xc))();
  fVar6 = (float10)(**(code **)(*piVar4 + 0x9c))();
  fStack_40 = (float)((float10)fStack_2c - fVar6);
  piVar4 = (int *)(**(code **)(*param_3 + 0xc))();
  fVar6 = (float10)(**(code **)(*piVar4 + 0x98))();
  fStack_34 = (float)((float10)fStack_28 - fVar6);
  piVar4 = (int *)(**(code **)(*param_3 + 0xc))();
  fVar7 = (float10)(**(code **)(*piVar4 + 0x9c))();
  fVar6 = (float10)fStack_2c;
  piVar4 = (int *)(**(code **)(*param_3 + 0xc))();
  fVar8 = (float10)(**(code **)(*piVar4 + 0x98))();
  fVar1 = (float10)fStack_28;
  if (fStack_40 <= (float)(fVar7 + fVar6)) {
    do {
      for (fVar9 = fStack_34; fVar9 <= (float)(fVar8 + fVar1); fVar9 = fVar9 + DAT_0099d080) {
        fStack_2c = fStack_40;
        piVar4 = (int *)(*(int *)(in_ECX + 4) + 0x804);
        *piVar4 = *piVar4 - *(int *)(*(int *)(in_ECX + 4) + 0x804);
        fStack_28 = fVar9;
        cVar2 = (**(code **)(*DAT_00b5a800 + 4))(&iStack_24,&fStack_2c,*(undefined4 *)(in_ECX + 4));
        if (cVar2 == '\x01') {
          iVar3 = (**(code **)(*param_2 + 0x48))();
          iVar3 = *(int *)(iVar3 + 0x1c);
          fStack_34 = 2.66247e-44;
          iStack_30 = 0;
          piVar4 = (int *)(**(code **)(*param_2 + 0x30))();
          if (((*piVar4 == 0x10) ||
              (piVar4 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar4 == 0xf)) ||
             (piVar4 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar4 == 0x11)) {
            fStack_34 = 2.38221e-44;
          }
          else {
            fStack_34 = 1.68156e-44;
          }
          iStack_30 = iVar3 + param_1;
          (**(code **)(*param_2 + 0x2c))(&fStack_34);
          (**(code **)(*param_2 + 0x34))(0);
          puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
          uStack_20 = *puVar5;
          iVar3 = *(int *)(in_ECX + 4);
          iStack_24 = param_1;
          uStack_18 = *(undefined4 *)(iVar3 + 0xc);
          uStack_14 = *(undefined4 *)(iVar3 + 0x10);
          uStack_1c = 1;
          *(int *)(iVar3 + 0x804) = *(int *)(iVar3 + 0x804) - *(int *)(iVar3 + 0x804);
          (**(code **)(*DAT_00b5a808 + 0xc))(&iStack_24);
          return;
        }
      }
      fStack_40 = fStack_40 + DAT_0099d080;
    } while (fStack_40 <= (float)(fVar7 + fVar6));
  }
  FUN_00452fa0(param_1,param_2);
  return;
}


// ==== FUN_00453270 @ 0x00453270 ====

void FUN_00453270(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puStack_50;
  int *piStack_4c;
  int *piStack_48;
  undefined4 uStack_44;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined4 uStack_c;
  
  if (param_2 == (int *)0x0) {
    return;
  }
  uStack_44 = (undefined4 *)0x45328f;
  piVar2 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar2 == (int *)0x0) {
    return;
  }
  uStack_44 = (undefined4 *)0x4532a0;
  piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
  uStack_44 = (undefined4 *)0x4532a7;
  uStack_34 = (**(code **)(*piVar3 + 0x54))();
  uStack_44 = &uStack_34;
  piStack_48 = (int *)0x4532b7;
  piVar2 = (int *)(**(code **)(*piVar2 + 0x30))();
  if (piVar2 == (int *)0x0) {
    return;
  }
  piVar2 = *(int **)(*piVar2 + 4);
  piStack_48 = (int *)0x4532cb;
  iVar4 = (**(code **)(*param_2 + 0x14))();
  if (*(int *)(iVar4 + 4) == 0) {
    piStack_48 = (int *)0x4532d8;
    iVar4 = (**(code **)(*piVar2 + 0x14))();
    if (*(int *)(iVar4 + 4) == 3) {
      piStack_4c = param_2;
      piStack_48 = piVar2;
      FUN_00453020();
      return;
    }
  }
  piStack_48 = (int *)0x4532fc;
  iVar4 = (**(code **)(*param_2 + 0x14))();
  uStack_28 = *(undefined4 *)(iVar4 + 0x18);
  uStack_24 = *(undefined4 *)(iVar4 + 0x1c);
  piStack_48 = (int *)0x453311;
  iVar4 = (**(code **)(*piVar2 + 0x14))();
  uStack_30 = *(undefined4 *)(iVar4 + 0x18);
  uStack_2c = *(undefined4 *)(iVar4 + 0x1c);
  piVar2 = (int *)(*(int *)(in_ECX + 4) + 0x804);
  *piVar2 = *piVar2 - *(int *)(*(int *)(in_ECX + 4) + 0x804);
  piStack_48 = *(int **)(in_ECX + 4);
  piStack_4c = &uStack_30;
  puStack_50 = &uStack_28;
  cVar1 = (**(code **)(*DAT_00b5a800 + 4))();
  if (cVar1 != '\x01') {
    cVar1 = (**(code **)(*DAT_00b5a800 + 0x10))
                      (&uStack_34,(int)register0x00000010 + -0x3c,&uStack_2c);
    if (cVar1 != '\0') {
      FUN_00452fa0(iStack_18,param_2);
      return;
    }
    iVar4 = (**(code **)(*param_2 + 0x48))();
    iVar4 = *(int *)(iVar4 + 0x1c);
    puStack_50 = (undefined4 *)0x13;
    piStack_4c = (int *)0x0;
    piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
    if ((*piVar2 != 0x10) && (piVar2 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar2 != 0xf)) {
      piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
      puStack_50 = (undefined4 *)0xc;
      if (*piVar2 != 0x11) goto LAB_00453475;
    }
    puStack_50 = (undefined4 *)0x11;
LAB_00453475:
    piStack_4c = (int *)(iVar4 + iStack_18);
    (**(code **)(*param_2 + 0x2c))(&puStack_50);
    (**(code **)(*param_2 + 0x34))(0);
    puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
    uStack_34 = *puVar5;
    uStack_30 = CONCAT31(uStack_30._1_3_,1);
    (**(code **)(*DAT_00b5a808 + 0xc))((int)register0x00000010 + -0x38);
    return;
  }
  (**(code **)(*param_2 + 0x48))();
  uStack_44 = (undefined4 *)0x13;
  piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
  if ((*piVar2 != 0x10) && (piVar2 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar2 != 0xf)) {
    piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
    uStack_44 = (undefined4 *)0xc;
    if (*piVar2 != 0x11) goto LAB_00453398;
  }
  uStack_44 = (undefined4 *)0x11;
LAB_00453398:
  (**(code **)(*param_2 + 0x2c))(&uStack_44);
  (**(code **)(*param_2 + 0x34))(0);
  puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
  uStack_28 = *puVar5;
  iVar4 = *(int *)(in_ECX + 4);
  uStack_2c = uStack_c;
  uStack_20 = *(undefined4 *)(iVar4 + 0xc);
  uStack_1c = *(undefined4 *)(iVar4 + 0x10);
  uStack_24 = CONCAT31(uStack_24._1_3_,1);
  *(int *)(iVar4 + 0x804) = *(int *)(iVar4 + 0x804) - *(int *)(iVar4 + 0x804);
  (**(code **)(*DAT_00b5a808 + 0xc))(&uStack_2c);
  return;
}


// ==== FUN_004534f0 @ 0x004534f0 ====

void FUN_004534f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00452b60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00453540 @ 0x00453540 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00453540(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0000;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5a824 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5a824 = in_ECX;
  return;
}


// ==== FUN_00453570 @ 0x00453570 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00453570(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5a824 = 0;
  *in_ECX = &PTR_FUN_0099ff88;
  return;
}


// ==== FUN_00453590 @ 0x00453590 ====

void FUN_00453590(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_retaddr;
  
  if (param_2 != (int *)0x0) {
    iVar3 = (**(code **)(*param_2 + 0x48))();
    uVar1 = *(undefined4 *)(iVar3 + 4);
    piVar4 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar4 + 0x60))(uVar1);
    cVar2 = FUN_00453680(unaff_retaddr,param_2);
    if (cVar2 != '\0') {
      iVar3 = FUN_004536f0(param_2);
      if (iVar3 != 0) {
        FUN_00453a40(unaff_retaddr,param_2,iVar3);
        return;
      }
      piVar4 = (int *)(**(code **)(*param_2 + 0x30))();
      if (*piVar4 != 0) {
        FUN_00453750(unaff_retaddr,param_2);
        return;
      }
      FUN_00453cc0(unaff_retaddr,param_2);
    }
  }
  return;
}


// ==== FUN_00453610 @ 0x00453610 ====

void FUN_00453610(undefined4 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_2 != (int *)0x0) && (cVar1 = FUN_00453680(param_1,param_2), cVar1 != '\0')) {
    iVar2 = FUN_004536f0(param_2);
    if (iVar2 != 0) {
      FUN_00453a40(param_1,param_2,iVar2);
      return;
    }
    piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar3 == 0) {
      FUN_00453cc0(param_1,param_2);
    }
    else {
      piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
      if (*piVar3 != 0x12) {
        FUN_00453750(param_1,param_2);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00453680 @ 0x00453680 ====

undefined4 FUN_00453680(uint param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2 != (int *)0x0) {
    iVar2 = (**(code **)(*param_2 + 0x28))();
    if (iVar2 != 0) {
      cVar1 = (**(code **)(*param_2 + 0x38))();
      if (cVar1 != '\0') {
        piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
        if (*piVar3 != 0xe) {
          iVar2 = (**(code **)(*param_2 + 0x30))();
          if (*(uint *)(iVar2 + 4) < param_1) {
            piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
            if (*piVar3 != 0x10) {
              piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
              if (*piVar3 != 0xf) {
                piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
                if (*piVar3 != 0x11) {
                  return 1;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_004536f0 @ 0x004536f0 ====

uint FUN_004536f0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x14))();
    if (*(int *)(iVar1 + 4) != 2) {
      iVar1 = (**(code **)(*param_1 + 0x10))();
      piVar2 = (int *)FUN_0044f820(*(undefined4 *)(iVar1 + 4));
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      piVar3 = (int *)(**(code **)(*param_1 + 0x10))();
      iVar1 = *piVar3;
      iVar4 = (**(code **)(*piVar2 + 0x10))();
      return (iVar1 != *(int *)(iVar4 + 8)) - 1 & (uint)piVar2;
    }
  }
  return 0;
}


// ==== FUN_00453750 @ 0x00453750 ====

void FUN_00453750(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (param_2 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar1 != 0) {
      iVar2 = (**(code **)(*param_2 + 0x48))();
      iVar2 = *(int *)(iVar2 + 0x10);
      iVar3 = (**(code **)(*param_2 + 0x10))();
      iVar3 = FUN_0044f820(*(undefined4 *)(iVar3 + 4));
      if (iVar3 != 0) {
        iVar2 = (**(code **)(*param_2 + 0x48))();
        iVar2 = *(int *)(iVar2 + 0x18);
      }
      piVar1 = (int *)(**(code **)(*param_2 + 0x30))();
      if (*piVar1 == 0x12) {
        iStack_14 = iVar2 + param_1;
        iStack_18 = 0x12;
        (**(code **)(*param_2 + 0x2c))(&iStack_18);
        return;
      }
      iStack_14 = iVar2 + param_1;
      iStack_18 = 0;
      (**(code **)(*param_2 + 0x2c))(&iStack_18);
      (**(code **)(*param_2 + 0x34))(0);
      puVar4 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
      iStack_14 = *puVar4;
      iStack_18 = param_1;
      iVar2 = (**(code **)(*param_2 + 0x14))();
      uStack_10 = *(undefined4 *)(iVar2 + 0x18);
      uStack_c = *(undefined4 *)(iVar2 + 0x1c);
      (**(code **)(*DAT_00b5a808 + 0x14))(&iStack_18);
    }
  }
  return;
}


// ==== FUN_00453830 @ 0x00453830 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00453830(int param_1,int *param_2,int param_3,int param_4)

{
  float fVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iStack_c0;
  int iStack_bc;
  float fStack_b8;
  float fStack_b4;
  undefined4 auStack_a8 [5];
  int iStack_94;
  
  if (param_2 != (int *)0x0) {
    puVar2 = (undefined4 *)(**(code **)(*param_2 + 0x48))();
    puVar5 = auStack_a8;
    for (iVar4 = 0x27; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar5 = puVar5 + 1;
    }
    fVar1 = (float)iStack_94;
    if (iStack_94 < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    iVar4 = FUN_0044ee00((int)ROUND(DAT_0099d0b4 * fVar1),(int)ROUND(DAT_009a000c * fVar1));
    piVar3 = (int *)(**(code **)(*param_2 + 0x30))();
    iStack_bc = iVar4 + param_1;
    if (*piVar3 == 0x12) {
      iStack_c0 = 0x12;
      (**(code **)(*param_2 + 0x2c))(&iStack_c0);
    }
    else {
      iStack_c0 = 4;
      (**(code **)(*param_2 + 0x2c))(&iStack_c0);
    }
    (**(code **)(*param_2 + 0x34))(0);
    puVar2 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
    fStack_b8 = (float)param_3;
    iStack_bc = *puVar2;
    iStack_c0 = param_1;
    if (param_3 < 0) {
      fStack_b8 = fStack_b8 + _DAT_0099d104;
    }
    fStack_b4 = (float)param_4;
    if (param_4 < 0) {
      fStack_b4 = fStack_b4 + _DAT_0099d104;
    }
    (**(code **)(*DAT_00b5a808 + 0x10))(&iStack_c0);
  }
  return;
}


// ==== FUN_00453980 @ 0x00453980 ====

void FUN_00453980(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iStack_1c;
  int iStack_18;
  undefined1 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0x48))();
    piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar2 == 0x12) {
      iStack_18 = *(int *)(iVar1 + 0x1c);
      iStack_1c = 0x12;
    }
    else {
      iStack_18 = *(int *)(iVar1 + 0x1c);
      iStack_1c = 1;
    }
    iStack_18 = iStack_18 + param_1;
    (**(code **)(*param_2 + 0x2c))(&iStack_1c);
    (**(code **)(*param_2 + 0x34))(0);
    puVar3 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
    iStack_18 = *puVar3;
    uStack_10 = *(undefined4 *)(param_1 + 0xc);
    uStack_c = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x804) = 0;
    iStack_1c = param_1;
    uStack_14 = 1;
    (**(code **)(*DAT_00b5a808 + 0xc))(&iStack_1c);
  }
  return;
}


// ==== FUN_00453a40 @ 0x00453a40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00453a40(undefined4 param_1,int *param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((param_2 == (int *)0x0) || (param_3 == (int *)0x0)) {
    return;
  }
  iVar5 = (**(code **)(*param_2 + 0x14))();
  fVar1 = *(float *)(iVar5 + 0x18);
  iVar5 = (**(code **)(*param_2 + 0x14))();
  fVar2 = *(float *)(iVar5 + 0x1c);
  iVar5 = (**(code **)(*param_3 + 0x14))();
  iVar5 = (int)ROUND(*(float *)(iVar5 + 0x18));
  iVar6 = (**(code **)(*param_3 + 0x14))();
  iVar6 = (int)ROUND(*(float *)(iVar6 + 0x1c));
  iVar7 = (**(code **)(*param_2 + 0x48))();
  cVar3 = FUN_0044f750(param_2,param_3,*(undefined4 *)(iVar7 + 0x24));
  FUN_0044f750(param_2,param_3,*(int *)(iVar7 + 0x24) + 2);
  cVar4 = FUN_0044f750(param_2,param_3,*(undefined4 *)(iVar7 + 0x28));
  fStack_8 = (float)(int)ROUND(fVar1);
  if ((int)ROUND(fVar1) < 0) {
    fStack_8 = fStack_8 + _DAT_0099d104;
  }
  fStack_4 = (float)(int)ROUND(fVar2);
  if ((int)ROUND(fVar2) < 0) {
    fStack_4 = fStack_4 + _DAT_0099d104;
  }
  fStack_10 = (float)iVar5;
  if (iVar5 < 0) {
    fStack_10 = fStack_10 + _DAT_0099d104;
  }
  fStack_c = (float)iVar6;
  if (iVar6 < 0) {
    fStack_c = fStack_c + _DAT_0099d104;
  }
  if (cVar3 != '\x01') {
    if (cVar4 == '\0') {
      FUN_00453830(param_1,param_2,iVar5,iVar6);
      return;
    }
    piVar8 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar8 != 0x12) {
      puVar9 = operator_new(0x808);
      puVar10 = (undefined4 *)0x0;
      if (puVar9 != (undefined4 *)0x0) {
        puVar9[0x201] = 0;
        *puVar9 = &PTR_FUN_0099ffa8;
        puVar10 = puVar9;
      }
      cVar3 = (**(code **)(*DAT_00b5a800 + 4))(&fStack_8,&fStack_10,puVar10);
      if (cVar3 == '\0') {
        puVar10[0x201] = 0;
        (**(code **)*puVar10)(1);
        FUN_00453830(fStack_c,param_2,iVar5,fStack_4);
        return;
      }
      if ((uint)puVar10[0x201] < *(uint *)(iVar7 + 0x28)) {
        FUN_00453980(fStack_8,param_2,puVar10);
        (**(code **)*puVar10)(1);
        return;
      }
      puVar10[0x201] = 0;
      (**(code **)*puVar10)(1);
      FUN_00453830(fStack_c,param_2,iVar5,fStack_4);
      return;
    }
  }
  FUN_00453750(param_1,param_2);
  return;
}


// ==== FUN_00453cc0 @ 0x00453cc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00453cc0(undefined4 param_1,int *param_2)

{
  float fVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  ushort *puVar7;
  undefined4 *puVar8;
  float *pfVar9;
  int iVar10;
  float unaff_ESI;
  uint uVar11;
  undefined4 local_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  float fStack_10;
  
  if (param_2 != (int *)0x0) {
    piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar3 + 0x50))(0);
    piVar3 = (int *)(**(code **)(*param_2 + 0x48))();
    iVar4 = (**(code **)(*param_2 + 0x14))();
    local_30 = *(float *)(iVar4 + 0x18);
    fStack_2c = *(float *)(iVar4 + 0x1c);
    piVar5 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar5 + 0x44))(&local_30);
    iVar6 = *piVar3;
    iVar10 = (int)local_30;
    iVar4 = FUN_0044ee00(0,iVar6 * 2 + 1);
    iVar4 = (int)unaff_ESI + (iVar4 - iVar6);
    iVar6 = FUN_0044ee00(0,iVar6 * 2 + 1);
    iVar10 = iVar10 + (iVar6 - *piVar3);
    puVar7 = (ushort *)(**(code **)(*DAT_00b5a718 + 8))();
    uVar11 = (uint)*puVar7;
    iVar6 = (**(code **)(*DAT_00b5a718 + 8))();
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    else if (iVar4 < (int)uVar11) {
      if (iVar10 < 0) {
        iVar10 = 0;
      }
      else if ((int)uVar11 <= iVar10) {
        iVar10 = *(ushort *)(iVar6 + 2) - 1;
      }
    }
    else {
      iVar4 = uVar11 - 1;
    }
    fStack_2c = (float)iVar4;
    fStack_28 = (float)iVar10;
    puVar8 = operator_new(0x808);
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      *puVar8 = &PTR_FUN_0099ffa8;
      puVar8[0x201] = 0;
    }
    cVar2 = (**(code **)(*DAT_00b5a800 + 4))((int)register0x00000010 + -0x34,&fStack_2c,puVar8);
    if (cVar2 == '\x01') {
      fVar1 = (float)piVar3[5];
      local_30 = 1.4013e-45;
      if (piVar3[5] < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      iVar4 = FUN_0044ee00((int)ROUND(DAT_0099d0b4 * fVar1),(int)ROUND(DAT_009a000c * fVar1));
      fStack_2c = (float)(iVar4 + (int)fStack_10);
      (**(code **)(*param_2 + 0x2c))(&local_30);
      (**(code **)(*param_2 + 0x34))(0);
      pfVar9 = (float *)(**(code **)(*param_2 + 0x10))();
      fStack_2c = *pfVar9;
      uStack_20 = puVar8[4];
      uStack_24 = puVar8[3];
      local_30 = fStack_10;
      fStack_28 = (float)((uint)fStack_28 & 0xffffff00);
      (**(code **)(*DAT_00b5a808 + 0xc))(&local_30);
    }
    else {
      FUN_00453750(fStack_10,param_2);
    }
    puVar8[0x201] = 0;
    (**(code **)*puVar8)(1);
  }
  return;
}


// ==== FUN_00453ef0 @ 0x00453ef0 ====

void FUN_00453ef0(byte param_1)

{
  void *in_ECX;
  
  FUN_00453570();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00453f30 @ 0x00453f30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00453f30(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097be58;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0014;
  puVar1 = operator_new(0x808);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_0099ffa8;
    puVar1[0x201] = 0;
  }
  in_ECX[1] = puVar1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    _DAT_00b5a828 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  _DAT_00b5a828 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00453fc0 @ 0x00453fc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00453fc0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097be6a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0014;
  _DAT_00b5a828 = 0;
  piVar1 = (int *)(in_ECX[1] + 0x804);
  *piVar1 = *piVar1 - *(int *)(in_ECX[1] + 0x804);
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099ff88;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00454030 @ 0x00454030 ====

void FUN_00454030(undefined4 param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 unaff_ESI;
  
  if (param_2 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar2 + 0x50))(param_3);
    piVar2 = (int *)(**(code **)(*param_2 + 0xc))();
    (**(code **)(*piVar2 + 0x48))(1);
    cVar1 = FUN_004540f0(unaff_ESI,param_2);
    if ((cVar1 != '\0') && (cVar1 = FUN_004541e0(unaff_ESI,param_2), cVar1 == '\0')) {
      FUN_00454440(unaff_ESI,param_2);
    }
  }
  return;
}


// ==== FUN_00454090 @ 0x00454090 ====

void FUN_00454090(undefined4 param_1,int param_2)

{
  char cVar1;
  
  if (((param_2 != 0) && (cVar1 = FUN_004540f0(param_1,param_2), cVar1 != '\0')) &&
     (cVar1 = FUN_004541e0(param_1,param_2), cVar1 == '\0')) {
    FUN_00454440(param_1,param_2);
  }
  return;
}


// ==== FUN_004540d0 @ 0x004540d0 ====

bool FUN_004540d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  cVar1 = FUN_0044f750(param_1,param_2,param_3);
  return cVar1 == '\0';
}


// ==== FUN_004540f0 @ 0x004540f0 ====

undefined4 FUN_004540f0(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  
  if (param_2 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*param_2 + 0x30))();
    if (*piVar2 != 0xe) {
      iVar3 = (**(code **)(*param_2 + 0x28))();
      if (iVar3 != 0) {
        piVar2 = (int *)(**(code **)(*param_2 + 0xc))();
        uVar4 = (**(code **)(*piVar2 + 0x54))();
        piVar2 = (int *)FUN_0044f820(uVar4);
        if (piVar2 == (int *)0x0) {
          iVar3 = *param_2;
          uVar4 = (**(code **)(*DAT_00b5a708 + 4))(1,param_1,uVar4);
          (**(code **)(iVar3 + 0x1c))(uVar4);
        }
        else {
          piVar5 = (int *)(**(code **)(*piVar2 + 0x30))();
          if (*piVar5 != 0xe) {
            cVar1 = FUN_004540d0(param_2,piVar2,0xc);
            if (cVar1 != '\x01') {
              piVar5 = (int *)(**(code **)(*param_2 + 0x30))();
              if (*piVar5 != 2) {
                piVar5 = (int *)(**(code **)(*param_2 + 0x30))();
                if (*piVar5 != 3) {
                  iVar3 = (**(code **)(*param_2 + 0x14))();
                  iVar3 = *(int *)(iVar3 + 4);
                  iVar6 = (**(code **)(*piVar2 + 0x14))();
                  if (iVar3 == *(int *)(iVar6 + 4)) {
                    iVar3 = *param_2;
                    uVar4 = (**(code **)(*DAT_00b5a708 + 4))(1,param_1,uVar4);
                    (**(code **)(iVar3 + 0x1c))(uVar4);
                    return 0;
                  }
                  return 1;
                }
              }
            }
          }
        }
        return 0;
      }
    }
  }
  return 0;
}


// ==== FUN_004541e0 @ 0x004541e0 ====

undefined4 FUN_004541e0(float param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int in_ECX;
  int iVar12;
  uint uVar13;
  uint uVar14;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined1 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  piVar1 = param_2;
  piVar3 = (int *)(**(code **)(*param_2 + 0xc))();
  uVar4 = (**(code **)(*piVar3 + 0x54))();
  piVar3 = (int *)FUN_0044f820(uVar4);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  iVar5 = (**(code **)(*param_2 + 0x48))();
  iVar6 = (**(code **)(*piVar3 + 0x14))();
  fStack_24 = *(float *)(iVar6 + 0x18);
  fStack_20 = *(float *)(iVar6 + 0x1c);
  iVar6 = (**(code **)(*param_2 + 0x14))();
  fStack_2c = *(float *)(iVar6 + 0x18);
  fStack_28 = *(float *)(iVar6 + 0x1c);
  param_2 = (int *)0x0;
  do {
    iVar6 = (int)fStack_2c;
    iVar12 = (int)fStack_28;
    uVar13 = *(int *)(iVar5 + 0xc) * 2 + 0x15;
    if (uVar13 == 0) {
      uVar13 = 0;
    }
    else {
      iVar7 = FUN_00797ac0(0x1000);
      uVar14 = FUN_00797ac0(0x1000);
      uVar9 = FUN_00797ac0(0x100);
      uVar13 = (uVar9 & 0xff | iVar7 << 0x14 | (uVar14 & 0xfff) << 8) % uVar13;
    }
    iVar7 = *(int *)(iVar5 + 0xc);
    uVar14 = iVar7 * 2 + 0x15;
    if (uVar14 == 0) {
      uVar14 = 0;
    }
    else {
      iVar8 = FUN_00797ac0(0x1000);
      uVar9 = FUN_00797ac0(0x1000);
      uVar10 = FUN_00797ac0(0x100);
      uVar14 = (uVar10 & 0xff | iVar8 << 0x14 | (uVar9 & 0xfff) << 8) % uVar14;
    }
    fStack_1c = (float)(int)((uVar13 - iVar7) + -10 + iVar6);
    fStack_18 = (float)(int)((uVar14 - *(int *)(iVar5 + 0xc)) + -10 + iVar12);
    if ((fStack_20 - fStack_28) * (fStack_18 - fStack_28) +
        (fStack_24 - fStack_2c) * (fStack_1c - fStack_2c) < 0.0) {
      cVar2 = (**(code **)(*DAT_00b5a800 + 4))(&fStack_2c,&fStack_1c,*(undefined4 *)(in_ECX + 4));
      if (cVar2 == '\x01') {
        fStack_20 = (float)(*(int *)(iVar5 + 0x1c) + 1000 + (int)param_1);
        fStack_24 = 2.8026e-45;
        (**(code **)(*piVar1 + 0x2c))(&fStack_24);
        puVar11 = (undefined4 *)(**(code **)(*piVar1 + 0x10))();
        uStack_14 = *puVar11;
        iVar5 = *(int *)(in_ECX + 4);
        fStack_18 = param_1;
        uStack_c = *(undefined4 *)(iVar5 + 0xc);
        uStack_8 = *(undefined4 *)(iVar5 + 0x10);
        uStack_10 = 1;
        *(int *)(iVar5 + 0x804) = *(int *)(iVar5 + 0x804) - *(int *)(iVar5 + 0x804);
        (**(code **)(*DAT_00b5a808 + 0xc))(&fStack_18);
        return 1;
      }
    }
    param_2 = (int *)((int)param_2 + 1);
  } while (param_2 < 5);
  return 0;
}


// ==== FUN_00454440 @ 0x00454440 ====

void FUN_00454440(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = (**(code **)(*param_2 + 0x48))();
  iStack_14 = *(int *)(iVar1 + 0x18) + param_1;
  uStack_18 = 3;
  (**(code **)(*param_2 + 0x2c))(&uStack_18);
  puVar2 = (undefined4 *)(**(code **)(*param_2 + 0x10))();
  uStack_10 = *puVar2;
  iStack_14 = param_1;
  iVar1 = (**(code **)(*param_2 + 0x14))();
  uStack_c = *(undefined4 *)(iVar1 + 0x18);
  uStack_8 = *(undefined4 *)(iVar1 + 0x1c);
  (**(code **)(*DAT_00b5a808 + 0x14))(&iStack_14);
  return;
}


// ==== FUN_004544b0 @ 0x004544b0 ====

void FUN_004544b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00453fc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004544d0 @ 0x004544d0 ====

void FUN_004544d0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004544d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 8))();
  return;
}


// ==== FUN_004544e0 @ 0x004544e0 ====

void FUN_004544e0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004544e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  return;
}


// ==== FUN_004544f0 @ 0x004544f0 ====

void FUN_004544f0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004544f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 8))();
  return;
}


// ==== FUN_00454500 @ 0x00454500 ====

void FUN_00454500(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00454505. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  return;
}


// ==== FUN_00454510 @ 0x00454510 ====

void FUN_00454510(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00454515. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x18))();
  return;
}


// ==== FUN_00454520 @ 0x00454520 ====

void FUN_00454520(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00454525. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_00454530 @ 0x00454530 ====

void FUN_00454530(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00454535. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
  return;
}


// ==== FUN_00454540 @ 0x00454540 ====

void FUN_00454540(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00454545. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_00454550 @ 0x00454550 ====

void FUN_00454550(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00454555. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
  return;
}


// ==== FUN_00454560 @ 0x00454560 ====

void FUN_00454560(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00454565. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x38))();
  return;
}


// ==== FUN_00454570 @ 0x00454570 ====

void FUN_00454570(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00454575. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
  return;
}


// ==== FUN_00454580 @ 0x00454580 ====

void FUN_00454580(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00454585. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x38))();
  return;
}


// ==== FUN_00454590 @ 0x00454590 ====

void FUN_00454590(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00454595. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x3c))();
  return;
}


// ==== FUN_004545a0 @ 0x004545a0 ====

void FUN_004545a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004545a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x40))();
  return;
}


// ==== FUN_004545b0 @ 0x004545b0 ====

void FUN_004545b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004545b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x48))();
  return;
}


// ==== FUN_004545c0 @ 0x004545c0 ====

void FUN_004545c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004545c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x50))();
  return;
}


// ==== FUN_004545d0 @ 0x004545d0 ====

void FUN_004545d0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004545d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x44))();
  return;
}


// ==== FUN_004545e0 @ 0x004545e0 ====

void FUN_004545e0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004545e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x4c))();
  return;
}


// ==== FUN_004545f0 @ 0x004545f0 ====

void FUN_004545f0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097be88;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a00ac;
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
  *in_ECX = &PTR_FUN_009a0024;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00454660 @ 0x00454660 ====

void FUN_00454660(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = *param_1;
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  (**(code **)(**(int **)(in_ECX + 8) + 0x3c))(uVar1);
  return;
}


// ==== FUN_00454690 @ 0x00454690 ====

void FUN_00454690(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int in_ECX;
  undefined4 *unaff_EBX;
  int *unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar1 = *unaff_EBX;
  puVar1[1] = unaff_retaddr;
  piVar2 = (int *)(**(code **)(*unaff_retaddr + 0xc))();
  (**(code **)(*piVar2 + 0x1c))(*unaff_EBX);
  (**(code **)(**(int **)(in_ECX + 8) + 0x24))(puVar1);
  return;
}


// ==== FUN_004546d0 @ 0x004546d0 ====

void FUN_004546d0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int in_ECX;
  undefined4 *unaff_EBX;
  int *unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar1 = *unaff_EBX;
  puVar1[1] = unaff_retaddr;
  piVar2 = (int *)(**(code **)(*unaff_retaddr + 0xc))();
  (**(code **)(*piVar2 + 0x1c))(*unaff_EBX);
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
  return;
}


// ==== FUN_00454710 @ 0x00454710 ====

void FUN_00454710(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097beb0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a00ac;
  pvVar1 = operator_new(0x7e8);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004548c0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0xca8);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00454e70(in_ECX[1]);
  in_ECX[2] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004547c0 @ 0x004547c0 ====

void FUN_004547c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0024;
  return;
}


// ==== FUN_004547d0 @ 0x004547d0 ====

void FUN_004547d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a007c;
  return;
}


// ==== FUN_004547e0 @ 0x004547e0 ====

void FUN_004547e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0094;
  return;
}


// ==== FUN_004547f0 @ 0x004547f0 ====

void FUN_004547f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a007c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00454810 @ 0x00454810 ====

void FUN_00454810(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0094;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00454830 @ 0x00454830 ====

undefined4 FUN_00454830(void)

{
  return 0;
}


// ==== FUN_00454840 @ 0x00454840 ====

void FUN_00454840(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0024;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00454860 @ 0x00454860 ====

void FUN_00454860(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a010c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,100,FUN_006ef6d0);
  return;
}


// ==== FUN_00454880 @ 0x00454880 ====

void FUN_00454880(byte param_1)

{
  void *in_ECX;
  
  FUN_00454860();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004548a0 @ 0x004548a0 ====

void FUN_004548a0(byte param_1)

{
  void *in_ECX;
  
  FUN_004545f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004548c0 @ 0x004548c0 ====

void FUN_004548c0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bec8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0114;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a010c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,100,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x1f6] = 0;
  in_ECX[0x1f6] = in_ECX[0x1f6] + 100;
  in_ECX[0x1f9] = in_ECX + 2;
  in_ECX[0x1f7] = 0;
  in_ECX[0x1f8] = 0;
  iVar2 = 99;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[499] = 0;
  in_ECX[500] = 0;
  in_ECX[0x1f5] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00454970 @ 0x00454970 ====

undefined4 FUN_00454970(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x7dc);
}


// ==== FUN_00454980 @ 0x00454980 ====

void FUN_00454980(byte param_1)

{
  void *in_ECX;
  
  FUN_004549a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004549a0 @ 0x004549a0 ====

void FUN_004549a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bef3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0114;
  local_4 = 1;
  if ((void *)in_ECX[0x1f8] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009a010c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009a007c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1f8]);
  return;
}


// ==== FUN_00454a20 @ 0x00454a20 ====

void * FUN_00454a20(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097bf0b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x7e4);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x7dc) = *(int *)(in_ECX + 0x7dc) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x7e0);
      *(void **)(in_ECX + 0x7e0) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x7e4) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_s_009a0128,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00454b00 @ 0x00454b00 ====

undefined4 FUN_00454b00(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_009a0128,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x7e4);
    *(int *)(in_ECX + 0x7dc) = *(int *)(in_ECX + 0x7dc) + -1;
    *(int *)(in_ECX + 0x7e4) = param_2;
  }
  return 0;
}


// ==== FUN_00454b80 @ 0x00454b80 ====

void FUN_00454b80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0188;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,100,FUN_006ef6d0);
  return;
}


// ==== FUN_00454ba0 @ 0x00454ba0 ====

void FUN_00454ba0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bf33;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0190;
  local_4 = 1;
  if ((void *)in_ECX[0x324] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009a0188;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009a0094;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x324]);
  return;
}


// ==== FUN_00454c20 @ 0x00454c20 ====

undefined4 FUN_00454c20(void)

{
  return 100;
}


// ==== FUN_00454c30 @ 0x00454c30 ====

undefined4 FUN_00454c30(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc8c);
}


// ==== FUN_00454c40 @ 0x00454c40 ====

undefined4 FUN_00454c40(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_009a0128,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0xc94);
    *(int *)(in_ECX + 0xc8c) = *(int *)(in_ECX + 0xc8c) + -1;
    *(int *)(in_ECX + 0xc94) = param_2;
  }
  return 0;
}


// ==== FUN_00454cc0 @ 0x00454cc0 ====

undefined4 * FUN_00454cc0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_009a0128,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xc94);
  *(int *)(in_ECX + 0xc8c) = *(int *)(in_ECX + 0xc8c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0xc90);
    *(undefined4 **)(in_ECX + 0xc90) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0xc94) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_00454d80 @ 0x00454d80 ====

void FUN_00454d80(byte param_1)

{
  void *in_ECX;
  
  FUN_00454b80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00454da0 @ 0x00454da0 ====

void FUN_00454da0(byte param_1)

{
  void *in_ECX;
  
  FUN_00454ba0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00454dc0 @ 0x00454dc0 ====

void FUN_00454dc0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bf48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0190;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a0188;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,100,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x322] = 0;
  in_ECX[0x322] = in_ECX[0x322] + 100;
  in_ECX[0x325] = in_ECX + 2;
  in_ECX[0x323] = 0;
  in_ECX[0x324] = 0;
  iVar2 = 99;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[799] = 0;
  in_ECX[800] = 0;
  in_ECX[0x321] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00454e70 @ 0x00454e70 ====

void FUN_00454e70(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bf68;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a01ac;
  FUN_00454dc0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00454ed0 @ 0x00454ed0 ====

void FUN_00454ed0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00454ef0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00454ef0 @ 0x00454ef0 ====

void FUN_00454ef0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00454ef0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00454ef0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00454f30 @ 0x00454f30 ====

void FUN_00454f30(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00454f50(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00454f50 @ 0x00454f50 ====

void FUN_00454f50(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00454f50(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00454f50(param_1[3]);
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


// ==== FUN_00454fc0 @ 0x00454fc0 ====

void FUN_00454fc0(byte param_1)

{
  void *in_ECX;
  
  FUN_00454fe0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00454fe0 @ 0x00454fe0 ====

void FUN_00454fe0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097bf93;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a01ac;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00454f50(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00454ba0();
  *in_ECX = &PTR_FUN_009a0024;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00455050 @ 0x00455050 ====

void FUN_00455050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0204;
  return;
}


// ==== __break @ 0x00455059 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00455060 @ 0x00455060 ====

void FUN_00455060(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0204;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00455080 @ 0x00455080 ====

void FUN_00455080(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00455090 @ 0x00455090 ====

undefined4 FUN_00455090(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_004550a0 @ 0x004550a0 ====

void FUN_004550a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004550a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_004550b0 @ 0x004550b0 ====

void FUN_004550b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004550b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_004550c0 @ 0x004550c0 ====

void FUN_004550c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004550c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_004550d0 @ 0x004550d0 ====

void FUN_004550d0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = *param_1;
  return;
}


// ==== FUN_004550e0 @ 0x004550e0 ====

int FUN_004550e0(void)

{
  int in_ECX;
  
  return in_ECX + 0x18;
}


// ==== FUN_004550f0 @ 0x004550f0 ====

void FUN_004550f0(int *param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(int **)(in_ECX + 0xc) = param_1;
  (**(code **)(*param_1 + 4))(param_2);
  return;
}


// ==== FUN_00455110 @ 0x00455110 ====

undefined4 FUN_00455110(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00455120 @ 0x00455120 ====

undefined4 FUN_00455120(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00455130 @ 0x00455130 ====

void FUN_00455130(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00455135. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x10) + 8))();
  return;
}


// ==== FUN_00455140 @ 0x00455140 ====

void FUN_00455140(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00455145. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x10) + 4))();
  return;
}


// ==== FUN_00455150 @ 0x00455150 ====

void FUN_00455150(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00455155. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x10) + 0xc))();
  return;
}


// ==== FUN_00455160 @ 0x00455160 ====

void FUN_00455160(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00455165. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x10) + 0x10))();
  return;
}


// ==== FUN_00455170 @ 0x00455170 ====

void FUN_00455170(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00455175. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x14) + 4))();
  return;
}


// ==== FUN_00455180 @ 0x00455180 ====

void FUN_00455180(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00455185. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x14) + 8))();
  return;
}


// ==== FUN_004551c0 @ 0x004551c0 ====

void FUN_004551c0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097bfc9;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0254;
  pvVar1 = operator_new(0xa8);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00457c90();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00457920();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0xa0);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004510c0();
  }
  in_ECX[5] = uVar2;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[6] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00455290 @ 0x00455290 ====

void FUN_00455290(void)

{
  undefined4 *in_ECX;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bfdb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a0254;
  local_4 = 0;
  (**(code **)(*DAT_00b5a704 + 0x10))(1,in_ECX[2]);
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009a0204;
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_00455320 @ 0x00455320 ====

void FUN_00455320(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5a704 + 0x10))(1,*(undefined4 *)(in_ECX + 8));
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00455340 @ 0x00455340 ====

void FUN_00455340(void)

{
  int in_ECX;
  undefined4 unaff_ESI;
  
  (**(code **)(*DAT_00b5a704 + 0x10))(1,*(undefined4 *)(in_ECX + 8));
  *(undefined4 *)(in_ECX + 8) = unaff_ESI;
  return;
}


// ==== FUN_00455360 @ 0x00455360 ====

void FUN_00455360(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *in_ECX;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 *puStack_74;
  undefined4 *puStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  
  uStack_5c = 0;
  uStack_60 = 0x455374;
  (**(code **)(*(int *)in_ECX[1] + 0x2c))();
  uStack_60 = 0;
  uStack_64 = 0x45537d;
  (**(code **)(*(int *)in_ECX[1] + 0x30))();
  uStack_64 = 0;
  uStack_68 = 0x455386;
  (**(code **)(*(int *)in_ECX[1] + 0x34))();
  uStack_68 = 0;
  uStack_6c = 0x45538f;
  (**(code **)(*(int *)in_ECX[1] + 0x38))();
  uStack_6c = 0;
  puStack_70 = (undefined4 *)0x455398;
  (**(code **)(*(int *)in_ECX[1] + 0x3c))();
  puStack_70 = &uStack_5c;
  uStack_5c = 0;
  puStack_74 = (undefined4 *)0x4553b4;
  (**(code **)(*(int *)in_ECX[1] + 0x40))();
  puStack_74 = &uStack_60;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_78 = 0x4553d0;
  (**(code **)(*(int *)in_ECX[1] + 0x44))();
  uStack_78 = 0;
  uStack_7c = 0x4553d9;
  (**(code **)(*(int *)in_ECX[1] + 0x48))();
  uStack_7c = 0;
  uStack_80 = 0x4553e2;
  (**(code **)(*(int *)in_ECX[1] + 0x4c))();
  uStack_80 = 0;
  uStack_84 = 0x4553eb;
  (**(code **)(*(int *)in_ECX[1] + 0x50))();
  uStack_84 = 0;
  uStack_88 = 0x4553f4;
  (**(code **)(*(int *)in_ECX[1] + 0x58))();
  uStack_88 = 0;
  uStack_8c = 0x4553fd;
  (**(code **)(*(int *)in_ECX[1] + 0x5c))();
  uStack_8c = 0;
  uStack_90 = 0x455406;
  (**(code **)(*(int *)in_ECX[1] + 0x70))();
  uStack_90 = 0;
  uStack_94 = 0x45540f;
  (**(code **)(*(int *)in_ECX[1] + 0x78))();
  uStack_94 = 0;
  (**(code **)(*(int *)in_ECX[1] + 0x80))();
  (**(code **)(*(int *)in_ECX[1] + 0x88))(0);
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  puStack_74 = (undefined4 *)0x0;
  puStack_70 = (undefined4 *)0x0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  (**(code **)(*(int *)in_ECX[1] + 0x18))(&uStack_80);
  uStack_8c = 0;
  uStack_88 = 0;
  (**(code **)(*(int *)in_ECX[4] + 8))(&uStack_8c);
  (**(code **)(*(int *)in_ECX[4] + 0xc))(1);
  uStack_94 = 0;
  (**(code **)(*in_ECX + 0x3c))(&uStack_94);
  iVar1 = *in_ECX;
  uVar2 = (**(code **)(*DAT_00b5a708 + 4))(1,0,0);
  (**(code **)(iVar1 + 0x1c))(uVar2);
  piVar3 = (int *)(**(code **)(*DAT_00b5a704 + 0xc))(1,0);
  iVar1 = *piVar3;
  uVar2 = (**(code **)(*DAT_00b5a6f4 + 8))(0);
  (**(code **)(iVar1 + 4))(uVar2);
  (**(code **)(*in_ECX + 0x24))(piVar3);
  return;
}


// ==== FUN_004554f0 @ 0x004554f0 ====

void FUN_004554f0(int *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int *in_ECX;
  undefined1 auStack_e [6];
  undefined4 uStack_8;
  int iStack_4;
  
  iVar3 = (**(code **)(*in_ECX + 0x14))();
  if (((*(int *)(iVar3 + 4) != 3) &&
      (iVar3 = (**(code **)(*in_ECX + 0x14))(), *(int *)(iVar3 + 4) != 4)) &&
     ((piVar4 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar4 != 0xe || (*param_1 == 9)))) {
    iVar3 = *param_1;
    puVar5 = (undefined4 *)(**(code **)(*in_ECX + 0x40))();
    uStack_8 = *puVar5;
    iStack_4 = iVar3;
    piVar4 = (int *)(**(code **)(*in_ECX + 0x28))();
    piVar4 = (int *)(**(code **)(*piVar4 + 0xc))(&uStack_8);
    if ((((piVar4 != (int *)0x0) && (piVar4[1] != 8)) && (*piVar4 != 6)) &&
       (cVar2 = FUN_00456320(param_1), cVar2 != '\0')) {
      piVar6 = (int *)(**(code **)(*in_ECX + 0xc))();
      uVar7 = (**(code **)(*piVar6 + 0x54))();
      uVar8 = FUN_0044fc60(uVar7);
      iVar3 = (**(code **)(*in_ECX + 0x48))();
      if (*(uint *)(iVar3 + 0x3c) < uVar8) {
        piVar6 = (int *)(**(code **)(*in_ECX + 0xc))();
        puVar5 = (undefined4 *)(**(code **)(*piVar6 + 4))();
        uVar1 = *puVar5;
        iVar3 = (**(code **)(*in_ECX + 0x48))();
        iVar3 = uVar8 - *(int *)(iVar3 + 0x3c);
        if (0 < iVar3) {
          do {
            iVar9 = FUN_00452d00(uVar1,uVar7);
            if (iVar9 != 0) {
              FUN_00452e00(iVar9,param_1[1]);
            }
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
      iVar3 = (**(code **)(*DAT_00b5a708 + 4))(piVar4[1]);
      if (iVar3 != 0) {
        iVar9 = *param_1;
        if (iVar9 == 0) {
          FUN_00455f80(param_1[1]);
          FUN_004557f0(param_1,iVar3,piVar4);
          return;
        }
        if (iVar9 == 1) {
          FUN_00455f80(param_1[1]);
          FUN_00455fb0(param_1,iVar3,piVar4);
          return;
        }
        if (iVar9 == 2) {
          FUN_00455f80(param_1[1]);
          FUN_004560f0(param_1,iVar3,piVar4);
          return;
        }
        if (iVar9 == 3) {
          FUN_00455f80(param_1[1]);
          FUN_004558e0(param_1,iVar3,piVar4);
          return;
        }
        if (iVar9 == 4) {
          FUN_00455f80(param_1[1]);
          FUN_004559f0(param_1,iVar3,piVar4);
          return;
        }
        if ((iVar9 == 7) || (iVar9 == 9)) {
          (**(code **)(*in_ECX + 0x2c))(auStack_e + -10);
          return;
        }
        if ((iVar9 == 0xe) || (iVar9 == 0x10)) {
          FUN_00455af0(param_1,iVar3,piVar4);
          return;
        }
        if (iVar9 == 0xc) {
          FUN_00455b90(param_1,iVar3,piVar4);
          return;
        }
        if ((((iVar9 != 0x12) && (iVar9 != 0x13)) && (iVar9 != 0x14)) &&
           ((iVar9 != 0x15 && (iVar9 != 0x16)))) {
          if (iVar9 == 0x19) {
            FUN_00455d60(param_1,iVar3,piVar4);
            return;
          }
          if (iVar9 == 0x1a) {
            FUN_00456230(param_1,iVar3,piVar4);
            return;
          }
          if (iVar9 == 0x17) {
            FUN_00455e40(param_1,iVar3,piVar4);
            return;
          }
          if (iVar9 == 0x18) {
            FUN_00455f10(param_1,iVar3,piVar4);
            return;
          }
          (**(code **)(*in_ECX + 0x3c))(piVar4);
          (**(code **)(*in_ECX + 0x1c))(iVar3,param_1[1],param_1[2]);
          return;
        }
        FUN_00455c40(param_1,iVar3,piVar4);
      }
    }
  }
  return;
}


// ==== FUN_004557f0 @ 0x004557f0 ====

void FUN_004557f0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined4 local_8;
  int local_4;
  
  local_8 = 0x13;
  if (param_1 == 0) {
    return;
  }
  local_4 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 4);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (((*piVar1 == 0x12) || (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0x10)) ||
     (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0xf)) {
    puVar2 = (undefined4 *)(**(code **)(*in_ECX + 0x30))();
    local_8 = *puVar2;
  }
  else {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
    if (*piVar1 == 0x11) {
      piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
      piVar1 = (int *)(**(code **)(*piVar1 + 0xc))();
      if (*piVar1 == 0) {
        if (piVar1[6] != 0) {
          local_8 = 0xf;
        }
      }
      else {
        local_8 = 0x10;
      }
    }
    else {
      local_8 = 7;
    }
  }
  (**(code **)(*in_ECX + 0x2c))(&local_8);
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  (**(code **)(*piVar1 + 0x48))(1);
  (**(code **)(*in_ECX + 0x3c))(param_1);
  (**(code **)(*in_ECX + 0x1c))(local_4,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}


// ==== FUN_004558e0 @ 0x004558e0 ====

void FUN_004558e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *in_ECX;
  int local_8;
  undefined4 local_4;
  
  if (param_1 == 0) {
    return;
  }
  local_8 = 0x13;
  local_4 = 0;
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  piVar2 = (int *)(**(code **)(*in_ECX + 0xc))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0xc))();
  if (*(char *)(iVar1 + 0x38) == '\0') {
    local_4 = 0;
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 0x30))();
    local_4 = *(undefined4 *)(iVar1 + 4);
  }
  piVar3 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (*piVar3 == 0x12) {
    local_8 = 0x12;
  }
  piVar3 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (((*piVar3 == 0x10) || (piVar3 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar3 == 0xf)) ||
     (piVar3 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar3 == 0x11)) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x30))();
    local_8 = *piVar2;
  }
  else if (*piVar2 == 0) {
    local_8 = (uint)(piVar2[6] == 0) * 2 + 5;
  }
  else {
    local_8 = 7;
  }
  (**(code **)(*in_ECX + 0x2c))(&local_8);
  piVar2 = (int *)(**(code **)(*in_ECX + 0xc))();
  (**(code **)(*piVar2 + 0x48))(1);
  (**(code **)(*in_ECX + 0x3c))(param_1);
  (**(code **)(*in_ECX + 0x1c))(local_4,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}


// ==== FUN_004559f0 @ 0x004559f0 ====

void FUN_004559f0(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  int iStack_8;
  undefined4 uStack_4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0xc))();
  iStack_8 = 0x13;
  uStack_4 = 0;
  piVar2 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (*piVar2 != 0x12) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x30))();
    if (*piVar2 != 0x10) {
      piVar2 = (int *)(**(code **)(*in_ECX + 0x30))();
      if (*piVar2 != 0xf) {
        piVar2 = (int *)(**(code **)(*in_ECX + 0x30))();
        if (*piVar2 == 0x11) {
          if (*piVar1 == 0) {
            if (piVar1[6] != 0) {
              iStack_8 = 0xf;
            }
          }
          else {
            iStack_8 = 0x10;
          }
        }
        else if (*piVar1 == 0) {
          if (piVar1[6] != 0) {
            iStack_8 = 5;
          }
        }
        else {
          iStack_8 = 7;
        }
        goto LAB_00455a90;
      }
    }
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  iStack_8 = *piVar1;
LAB_00455a90:
  iVar3 = (**(code **)(*in_ECX + 0x30))();
  uStack_4 = *(undefined4 *)(iVar3 + 4);
  (**(code **)(*in_ECX + 0x2c))(&iStack_8);
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  (**(code **)(*piVar1 + 0x48))(1);
  (**(code **)(*in_ECX + 0x3c))(param_1);
  (**(code **)(*in_ECX + 0x1c))
            (uStack_4,*(undefined4 *)(iStack_8 + 4),*(undefined4 *)(iStack_8 + 8));
  return;
}


// ==== FUN_00455af0 @ 0x00455af0 ====

void FUN_00455af0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  undefined4 unaff_retaddr;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  iVar3 = *(int *)(param_1 + 8);
  iVar2 = (**(code **)(*piVar1 + 0x54))();
  if (iVar3 != iVar2) {
    return;
  }
  uStack_8 = 0x13;
  uStack_4 = 0;
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if ((*piVar1 == 0xc) || (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0x11)) {
    uStack_4 = 0;
  }
  else {
    iVar3 = (**(code **)(*in_ECX + 0x30))();
    uStack_4 = *(undefined4 *)(iVar3 + 4);
  }
  puVar4 = (undefined4 *)(**(code **)(*in_ECX + 0x30))();
  uStack_8 = *puVar4;
  (**(code **)(*in_ECX + 0x2c))(&uStack_8);
  (**(code **)(*in_ECX + 0x3c))(param_2);
  (**(code **)(*in_ECX + 0x1c))
            (unaff_retaddr,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}


// ==== FUN_00455b90 @ 0x00455b90 ====

void FUN_00455b90(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  undefined4 unaff_retaddr;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  iVar3 = *(int *)(param_1 + 8);
  iVar2 = (**(code **)(*piVar1 + 0x54))();
  if (iVar3 != iVar2) {
    return;
  }
  uStack_8 = 0x13;
  uStack_4 = 0;
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (((*piVar1 == 0xf) || (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0x10)) ||
     (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0x11)) {
    uStack_4 = *(undefined4 *)(param_1 + 4);
  }
  else {
    iVar3 = (**(code **)(*in_ECX + 0x30))();
    uStack_4 = *(undefined4 *)(iVar3 + 4);
  }
  puVar4 = (undefined4 *)(**(code **)(*in_ECX + 0x30))();
  uStack_8 = *puVar4;
  (**(code **)(*in_ECX + 0x2c))(&uStack_8);
  (**(code **)(*in_ECX + 0x3c))(param_2);
  (**(code **)(*in_ECX + 0x1c))
            (unaff_retaddr,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}


// ==== FUN_00455c40 @ 0x00455c40 ====

void FUN_00455c40(int param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  undefined4 unaff_retaddr;
  undefined4 uStack_8;
  int iStack_4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (*piVar1 == 0x10) {
    return;
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (*piVar1 == 0xf) {
    return;
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (*piVar1 == 0x11) {
    return;
  }
  uStack_8 = 0x13;
  iStack_4 = 0;
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (((*piVar1 == 7) || (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 5)) ||
     (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0xc)) {
    iVar2 = (**(code **)(*in_ECX + 0x30))();
    iStack_4 = *(int *)(iVar2 + 4);
  }
  else {
    iStack_4 = *(int *)(param_1 + 4) + -1;
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if (*(int *)(iVar2 + 0x18) == 0) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
    piVar1 = (int *)(**(code **)(*piVar1 + 0xc))();
    if (*piVar1 != 0) {
      uStack_8 = 7;
    }
  }
  else {
    uStack_8 = 5;
  }
  (**(code **)(*in_ECX + 0x2c))(&uStack_8);
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  (**(code **)(*piVar1 + 0x48))(1);
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  (**(code **)(*piVar1 + 0x50))(*(undefined4 *)(param_1 + 8));
  (**(code **)(*in_ECX + 0x3c))(unaff_retaddr);
  (**(code **)(*in_ECX + 0x1c))(uStack_8,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}


// ==== FUN_00455d60 @ 0x00455d60 ====

void FUN_00455d60(int param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  undefined4 unaff_retaddr;
  undefined4 local_8;
  int local_4;
  
  local_4 = *(undefined4 *)(param_1 + 4);
  local_8 = 0x13;
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (*piVar1 != 0x11) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
    if (*piVar1 != 0xc) {
      iVar2 = (**(code **)(*in_ECX + 0x30))();
      local_4 = *(int *)(iVar2 + 4);
      goto LAB_00455daa;
    }
  }
  local_4 = *(int *)(param_1 + 4) + -1;
LAB_00455daa:
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if (*(int *)(iVar2 + 0x18) == 0) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
    piVar1 = (int *)(**(code **)(*piVar1 + 0xc))();
    if (*piVar1 != 0) {
      local_8 = 0x10;
    }
  }
  else {
    local_8 = 0xf;
  }
  (**(code **)(*in_ECX + 0x10))();
  (**(code **)(*in_ECX + 0x2c))(&local_8);
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  (**(code **)(*piVar1 + 0x48))(1);
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  (**(code **)(*piVar1 + 0x50))(*(undefined4 *)(param_1 + 8));
  (**(code **)(*in_ECX + 0x3c))(unaff_retaddr);
  (**(code **)(*in_ECX + 0x1c))(local_8,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}


// ==== FUN_00455e40 @ 0x00455e40 ====

void FUN_00455e40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int unaff_retaddr;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (*piVar1 == 0x10) {
    return;
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (*piVar1 == 0xf) {
    return;
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (*piVar1 == 0x11) {
    return;
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (((*piVar1 == 1) || (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0)) ||
     (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 4)) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
    if (*piVar1 != 0x12) goto LAB_00455eda;
    iVar2 = (**(code **)(*in_ECX + 0x30))();
    uStack_4 = *(undefined4 *)(iVar2 + 4);
    uStack_8 = 0x12;
  }
  else {
    iVar2 = (**(code **)(*in_ECX + 0x30))();
    uStack_4 = *(undefined4 *)(iVar2 + 4);
    uStack_8 = 4;
  }
  (**(code **)(*in_ECX + 0x2c))(&uStack_8);
LAB_00455eda:
  (**(code **)(*in_ECX + 0x3c))(param_3);
  (**(code **)(*in_ECX + 0x1c))
            (param_1,*(undefined4 *)(unaff_retaddr + 4),*(undefined4 *)(unaff_retaddr + 8));
  return;
}


// ==== FUN_00455f10 @ 0x00455f10 ====

void FUN_00455f10(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *in_ECX;
  undefined4 unaff_retaddr;
  uint local_8;
  int local_4;
  
  local_8 = 0x13;
  local_4 = 0;
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  local_8 = (*piVar1 != 0x12) - 1 & 0x12;
  (**(code **)(*in_ECX + 0x2c))(&local_8);
  (**(code **)(*in_ECX + 0x3c))(param_2);
  (**(code **)(*in_ECX + 0x1c))
            (unaff_retaddr,*(undefined4 *)(local_4 + 4),*(undefined4 *)(local_4 + 8));
  return;
}


// ==== FUN_00455f80 @ 0x00455f80 ====

void FUN_00455f80(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x48))();
  uVar1 = *(undefined4 *)(iVar2 + 4);
  piVar3 = (int *)(**(code **)(*in_ECX + 0xc))();
  (**(code **)(*piVar3 + 0x60))(uVar1);
  piVar3 = (int *)(**(code **)(*in_ECX + 0xc))();
                    /* WARNING: Could not recover jumptable at 0x00455fa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar3 + 0x68))();
  return;
}


// ==== FUN_00455fb0 @ 0x00455fb0 ====

void FUN_00455fb0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  uint uVar4;
  undefined4 local_8;
  uint local_4;
  
  if (param_1 != 0) {
    local_8 = 0x13;
    local_4 = 0;
    piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
    if ((((*piVar1 == 7) || (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 5)) ||
        (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0x10)) ||
       (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0xf)) {
      uVar4 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 4);
      iVar2 = (**(code **)(*in_ECX + 0x30))();
      local_4 = uVar4;
      if (uVar4 <= *(uint *)(iVar2 + 4)) {
        local_4 = *(uint *)(iVar2 + 4);
      }
    }
    else {
      local_4 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 4);
    }
    piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
    if (((*piVar1 == 0x12) || (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0x10)) ||
       (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0xf)) {
      puVar3 = (undefined4 *)(**(code **)(*in_ECX + 0x30))();
      local_8 = *puVar3;
    }
    else {
      piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
      if (*piVar1 == 0x11) {
        piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
        piVar1 = (int *)(**(code **)(*piVar1 + 0xc))();
        if (*piVar1 == 0) {
          if (piVar1[6] != 0) {
            local_8 = 0xf;
          }
        }
        else {
          local_8 = 0x10;
        }
      }
      else {
        local_8 = 7;
      }
    }
    (**(code **)(*in_ECX + 0x2c))(&local_8);
    piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
    (**(code **)(*piVar1 + 0x48))(1);
    (**(code **)(*in_ECX + 0x3c))(param_1);
    (**(code **)(*in_ECX + 0x1c))(local_4,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8))
    ;
  }
  return;
}


// ==== FUN_004560f0 @ 0x004560f0 ====

void FUN_004560f0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  uint uVar4;
  undefined4 local_8;
  uint local_4;
  
  if (param_1 != 0) {
    local_8 = 0x13;
    local_4 = 0;
    piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
    if ((((*piVar1 == 7) || (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 5)) ||
        (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0x10)) ||
       (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0xf)) {
      uVar4 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 4);
      iVar2 = (**(code **)(*in_ECX + 0x30))();
      local_4 = *(uint *)(iVar2 + 4);
      if (uVar4 <= *(uint *)(iVar2 + 4)) {
        local_4 = uVar4;
      }
    }
    else {
      local_4 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 4);
    }
    piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
    if (((*piVar1 == 0x12) || (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0x10)) ||
       (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0xf)) {
      puVar3 = (undefined4 *)(**(code **)(*in_ECX + 0x30))();
      local_8 = *puVar3;
    }
    else {
      piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
      if (*piVar1 == 0x11) {
        piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
        piVar1 = (int *)(**(code **)(*piVar1 + 0xc))();
        if (*piVar1 == 0) {
          if (piVar1[6] != 0) {
            local_8 = 0xf;
          }
        }
        else {
          local_8 = 0x10;
        }
      }
      else {
        local_8 = 7;
      }
    }
    (**(code **)(*in_ECX + 0x2c))(&local_8);
    piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
    (**(code **)(*piVar1 + 0x48))(1);
    (**(code **)(*in_ECX + 0x3c))(param_1);
    (**(code **)(*in_ECX + 0x1c))(local_4,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8))
    ;
  }
  return;
}


// ==== FUN_00456230 @ 0x00456230 ====

void FUN_00456230(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  undefined4 uStack_10;
  int iStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
  if (*piVar1 != 0x12) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 4))();
    uStack_10 = *(undefined4 *)(param_1 + 4);
    iStack_c = *puVar2;
    piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
    iVar3 = (**(code **)(*piVar1 + 8))();
    uStack_8 = *(undefined4 *)(iVar3 + 0x18);
    uStack_4 = *(undefined4 *)(iVar3 + 0x1c);
    (**(code **)(*in_ECX + 0x34))(0);
    (**(code **)(*DAT_00b5a808 + 0x14))((int)register0x00000010 + -0x14);
  }
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = (**(code **)(*in_ECX + 0x48))();
  iVar4 = *(int *)(iVar4 + 0x10);
  iVar5 = (**(code **)(*in_ECX + 0x30))();
  if (*(uint *)(iVar5 + 4) < (uint)(iVar4 + iVar3)) {
    iVar3 = *(int *)(param_1 + 4);
    iVar4 = (**(code **)(*in_ECX + 0x48))();
    iStack_c = *(int *)(iVar4 + 0x10) + iVar3;
    uStack_10 = 0x12;
    (**(code **)(*in_ECX + 0x2c))(&uStack_10);
    return;
  }
  iVar3 = (**(code **)(*in_ECX + 0x30))();
  iStack_c = *(undefined4 *)(iVar3 + 4);
  uStack_10 = 0x12;
  (**(code **)(*in_ECX + 0x2c))(&uStack_10);
  return;
}


// ==== FUN_00456320 @ 0x00456320 ====

undefined4 FUN_00456320(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar3 = *param_1;
  if (((((((iVar3 == 0) || (iVar3 == 1)) || (iVar3 == 3)) || ((iVar3 == 2 || (iVar3 == 4)))) ||
       (iVar3 == 0xe)) ||
      (((iVar3 == 0x10 || (iVar3 == 0xc)) ||
       ((iVar3 == 10 || (((iVar3 == 0x12 || (iVar3 == 0x13)) || (iVar3 == 0x14)))))))) ||
     ((iVar3 == 0x16 || (iVar3 == 0x15)))) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
    uVar2 = (**(code **)(*piVar1 + 0x54))();
    iVar3 = FUN_0044f820(uVar2);
    piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
    if ((*piVar1 == 0x10) ||
       ((piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0xf ||
        (piVar1 = (int *)(**(code **)(*in_ECX + 0x30))(), *piVar1 == 0x11)))) {
      if (iVar3 == 0) goto LAB_004563bc;
      piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
      iVar3 = param_1[2];
      iVar4 = (**(code **)(*piVar1 + 0x54))();
      if (iVar3 != iVar4) {
        return 0;
      }
    }
    else if (iVar3 == 0) {
LAB_004563bc:
      piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
      (**(code **)(*piVar1 + 0x50))(param_1[2]);
      return 1;
    }
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
  iVar3 = (**(code **)(*piVar1 + 8))();
  if (*(int *)(iVar3 + 4) == 0) {
    piVar1 = (int *)FUN_0044f820(param_1[2]);
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    piVar1 = (int *)(**(code **)(*piVar1 + 0xc))();
    iVar3 = (**(code **)(*piVar1 + 8))();
    if ((*(int *)(iVar3 + 4) == 0) &&
       (((((iVar3 = *param_1, iVar3 == 0 || (iVar3 == 1)) || (iVar3 == 3)) ||
         (((iVar3 == 2 || (iVar3 == 4)) || ((iVar3 == 0xe || ((iVar3 == 0x10 || (iVar3 == 0xc)))))))
         ) || (iVar3 == 10)))) {
      piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
      uVar2 = (**(code **)(*piVar1 + 0x54))();
      iVar3 = FUN_0044f820(uVar2);
      if (iVar3 == 0) {
        piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
        (**(code **)(*piVar1 + 0x50))(param_1[2]);
        return 1;
      }
      piVar1 = (int *)(**(code **)(*in_ECX + 0xc))();
      iVar3 = param_1[2];
      iVar4 = (**(code **)(*piVar1 + 0x54))();
      if (iVar3 != iVar4) {
        return 0;
      }
    }
  }
  return 1;
}


// ==== FUN_004564b0 @ 0x004564b0 ====

void FUN_004564b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00455290();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004564d0 @ 0x004564d0 ====

void FUN_004564d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a02c0;
  return;
}


// ==== FUN_004564e0 @ 0x004564e0 ====

void FUN_004564e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a02c0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00456500 @ 0x00456500 ====

void FUN_00456500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a02d0;
  return;
}


// ==== FUN_00456510 @ 0x00456510 ====

void FUN_00456510(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a02ec;
  return;
}


// ==== FUN_00456520 @ 0x00456520 ====

void FUN_00456520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0344;
  return;
}


// ==== FUN_00456530 @ 0x00456530 ====

void FUN_00456530(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a02d0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00456550 @ 0x00456550 ====

void FUN_00456550(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a02ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00456570 @ 0x00456570 ====

void FUN_00456570(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0344;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00456590 @ 0x00456590 ====

void FUN_00456590(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bff8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a035c;
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
  *in_ECX = &PTR_FUN_009a02c0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00456600 @ 0x00456600 ====

int FUN_00456600(undefined4 *param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = *param_1;
  local_c = param_1[1];
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(&local_10);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *piVar1 + 8;
}


// ==== FUN_00456640 @ 0x00456640 ====

void FUN_00456640(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined1 auStack_fe [250];
  undefined4 *puStack_4;
  
  iVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)(**(code **)(*(int *)in_ECX[1] + 0xc))(1,0);
    *puVar2 = *param_1;
    puVar2[1] = param_1[1];
    puVar2[2] = *puStack_4;
    puVar2[3] = puStack_4[1];
    (**(code **)(*(int *)in_ECX[2] + 0x24))(puVar2);
    return;
  }
  FUN_0044a580(auStack_fe + -6,&DAT_009a02b8,&DAT_009a02a4);
  FUN_00797b80(auStack_fe + -6);
  return;
}


// ==== FUN_004566d0 @ 0x004566d0 ====

void FUN_004566d0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097c020;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a035c;
  pvVar1 = operator_new(0x41b8);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004567e0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x548c);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00456d60(in_ECX[1]);
  in_ECX[2] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00456780 @ 0x00456780 ====

void FUN_00456780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a036c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,600,FUN_006ef6d0);
  return;
}


// ==== FUN_004567a0 @ 0x004567a0 ====

void FUN_004567a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00456780();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004567c0 @ 0x004567c0 ====

void FUN_004567c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00456590();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004567e0 @ 0x004567e0 ====

void FUN_004567e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c038;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0374;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a036c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x1c,600,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x106a] = 0;
  in_ECX[0x106a] = in_ECX[0x106a] + 600;
  in_ECX[0x106d] = in_ECX + 2;
  in_ECX[0x106b] = 0;
  in_ECX[0x106c] = 0;
  iVar2 = 599;
  puVar1 = in_ECX;
  do {
    puVar1[6] = puVar1 + 9;
    puVar1[7] = 0;
    puVar1[8] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 7;
  } while (iVar2 != 0);
  in_ECX[0x1067] = 0;
  in_ECX[0x1068] = 0;
  in_ECX[0x1069] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00456890 @ 0x00456890 ====

undefined4 FUN_00456890(void)

{
  return 600;
}


// ==== FUN_004568a0 @ 0x004568a0 ====

undefined4 FUN_004568a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x41ac);
}


// ==== FUN_004568b0 @ 0x004568b0 ====

void FUN_004568b0(byte param_1)

{
  void *in_ECX;
  
  FUN_004568d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004568d0 @ 0x004568d0 ====

void FUN_004568d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c063;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0374;
  local_4 = 1;
  if ((void *)in_ECX[0x106c] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009a036c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,600,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009a02d0;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x106c]);
  return;
}


// ==== FUN_00456950 @ 0x00456950 ====

void * FUN_00456950(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x18) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099fbc0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x18) = *(int *)((int)param_2 + 0x18) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x41b4);
  *(int *)(in_ECX + 0x41ac) = *(int *)(in_ECX + 0x41ac) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x1c);
    *(undefined4 *)((int)pvVar2 + 0x14) = *(undefined4 *)(in_ECX + 0x41b0);
    *(void **)(in_ECX + 0x41b0) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x41b4) = *(undefined4 *)((int)pvVar2 + 0x10);
  }
  *(undefined4 *)((int)pvVar2 + 0x10) = 0;
  *(int *)((int)pvVar2 + 0x18) = param_1;
  return pvVar2;
}


// ==== FUN_00456a00 @ 0x00456a00 ====

undefined4 FUN_00456a00(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099fbc0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x18);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x18);
    }
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x41b4);
    *(int *)(in_ECX + 0x41ac) = *(int *)(in_ECX + 0x41ac) + -1;
    *(int *)(in_ECX + 0x41b4) = param_2;
  }
  return 0;
}


// ==== FUN_00456a80 @ 0x00456a80 ====

void FUN_00456a80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a038c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x24,600,FUN_006ef6d0);
  return;
}


// ==== FUN_00456aa0 @ 0x00456aa0 ====

void FUN_00456aa0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c083;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0394;
  local_4 = 1;
  if ((void *)in_ECX[0x151c] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009a038c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x24,600,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009a0344;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x151c]);
  return;
}


// ==== FUN_00456b20 @ 0x00456b20 ====

undefined4 FUN_00456b20(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x546c);
}


// ==== FUN_00456b30 @ 0x00456b30 ====

undefined4 FUN_00456b30(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x20) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099fbc0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x20);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x20);
    }
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(in_ECX + 0x5474);
    *(int *)(in_ECX + 0x546c) = *(int *)(in_ECX + 0x546c) + -1;
    *(int *)(in_ECX + 0x5474) = param_2;
  }
  return 0;
}


// ==== FUN_00456bb0 @ 0x00456bb0 ====

undefined4 * FUN_00456bb0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[8] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099fbc0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[8] = param_2[8] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x5474);
  *(int *)(in_ECX + 0x546c) = *(int *)(in_ECX + 0x546c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x24);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[7] = *(undefined4 *)(in_ECX + 0x5470);
    *(undefined4 **)(in_ECX + 0x5470) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x5474) = puVar2[6];
  }
  puVar2[6] = 0;
  puVar2[8] = param_1;
  return puVar2;
}


// ==== FUN_00456c70 @ 0x00456c70 ====

void FUN_00456c70(byte param_1)

{
  void *in_ECX;
  
  FUN_00456a80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00456c90 @ 0x00456c90 ====

void FUN_00456c90(byte param_1)

{
  void *in_ECX;
  
  FUN_00456aa0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00456cb0 @ 0x00456cb0 ====

void FUN_00456cb0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c098;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0394;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a038c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x24,600,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x151a] = 0;
  in_ECX[0x151a] = in_ECX[0x151a] + 600;
  in_ECX[0x151d] = in_ECX + 2;
  in_ECX[0x151b] = 0;
  in_ECX[0x151c] = 0;
  iVar2 = 599;
  puVar1 = in_ECX;
  do {
    puVar1[8] = puVar1 + 0xb;
    puVar1[9] = 0;
    puVar1[10] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 9;
  } while (iVar2 != 0);
  in_ECX[0x1517] = 0;
  in_ECX[0x1518] = 0;
  in_ECX[0x1519] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00456d60 @ 0x00456d60 ====

void FUN_00456d60(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c0c3;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a03ac;
  FUN_00456cb0();
  in_ECX[3] = param_1;
  local_4 = CONCAT31(local_4._1_3_,1);
  puVar1 = (undefined4 *)(**(code **)(in_ECX[5] + 0xc))(1,0);
  in_ECX[1] = puVar1;
  *puVar1 = 0;
  *(undefined4 *)(in_ECX[1] + 8) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0xc) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0x10) = in_ECX[1];
  *(undefined1 *)(in_ECX[1] + 0x14) = 1;
  in_ECX[2] = in_ECX[1];
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_00456df0 @ 0x00456df0 ====

int FUN_00456df0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*(int *)(in_ECX + 0x14) + 8))();
  return iVar1 + -1;
}


// ==== FUN_00456e00 @ 0x00456e00 ====

void FUN_00456e00(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00456e05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(in_ECX + 0x14) + 4))();
  return;
}


// ==== FUN_00456e10 @ 0x00456e10 ====

void FUN_00456e10(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00456e12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x24))();
  return;
}


// ==== FUN_00456e20 @ 0x00456e20 ====

void FUN_00456e20(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00456e22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x2c))();
  return;
}


// ==== FUN_00456e30 @ 0x00456e30 ====

void FUN_00456e30(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00456e32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x30))();
  return;
}


// ==== FUN_00456e40 @ 0x00456e40 ====

void FUN_00456e40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_00456e60(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_00456e60 @ 0x00456e60 ====

void FUN_00456e60(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != *(int *)(in_ECX + 4)) {
    FUN_00456e60(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != *(int *)(in_ECX + 4)) {
    FUN_00456e60(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00456ea0 @ 0x00456ea0 ====

void FUN_00456ea0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_00456ec0(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_00456ec0 @ 0x00456ec0 ====

void FUN_00456ec0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != *(int *)(in_ECX + 4)) {
    FUN_00456ec0(param_1[2]);
  }
  if (param_1[3] != *(int *)(in_ECX + 4)) {
    FUN_00456ec0(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00456f30 @ 0x00456f30 ====

undefined4 * FUN_00456f30(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int *unaff_ESI;
  
  iVar1 = in_ECX + 0x14;
  piVar3 = (int *)(**(code **)(*(int *)(in_ECX + 0x14) + 0xc))(1,0);
  *piVar3 = iVar1;
  piVar3[2] = *(int *)(in_ECX + 4);
  piVar3[3] = *(int *)(in_ECX + 4);
  piVar3[4] = *(int *)(in_ECX + 4);
  *(undefined1 *)(piVar3 + 5) = 0;
  puVar2 = *(undefined4 **)(in_ECX + 8);
  if (puVar2 == *(undefined4 **)(in_ECX + 4)) {
    *(int **)(in_ECX + 8) = piVar3;
    FUN_0044b660(piVar3);
    return (undefined4 *)0x0;
  }
  iVar4 = FUN_0061e420(iVar1,*puVar2);
  do {
    if (iVar4 == 0) {
      (**(code **)(*unaff_ESI + 0x10))(1,piVar3);
      return puVar2;
    }
    if (iVar4 < 1) {
      puVar5 = (undefined4 *)puVar2[2];
      if (puVar5 == *(undefined4 **)(in_ECX + 4)) {
        piVar3[4] = (int)puVar2;
        puVar2[2] = piVar3;
        FUN_0044b660(piVar3);
        return (undefined4 *)0x0;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == *(undefined4 **)(in_ECX + 4)) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
        FUN_0044b660(piVar3);
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_0061e420(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_00457010 @ 0x00457010 ====

void FUN_00457010(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    iVar2 = *(int *)(iVar1 + 8);
    *(int *)(param_1 + 0xc) = iVar2;
    if (iVar2 != *(int *)(in_ECX + 4)) {
      *(int *)(iVar2 + 0x10) = param_1;
    }
    iVar2 = *(int *)(param_1 + 0x10);
    *(int *)(iVar1 + 0x10) = iVar2;
    if (iVar2 == *(int *)(in_ECX + 4)) {
      *(int *)(in_ECX + 8) = iVar1;
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


// ==== FUN_00457070 @ 0x00457070 ====

void FUN_00457070(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    iVar2 = *(int *)(iVar1 + 0xc);
    *(int *)(param_1 + 8) = iVar2;
    if (iVar2 != *(int *)(in_ECX + 4)) {
      *(int *)(iVar2 + 0x10) = param_1;
    }
    iVar2 = *(int *)(param_1 + 0x10);
    *(int *)(iVar1 + 0x10) = iVar2;
    if (iVar2 == *(int *)(in_ECX + 4)) {
      *(int *)(in_ECX + 8) = iVar1;
      *(int *)(iVar1 + 0xc) = param_1;
      *(int *)(param_1 + 0x10) = iVar1;
      return;
    }
    if (param_1 == *(int *)(iVar2 + 8)) {
      *(int *)(iVar2 + 8) = iVar1;
      *(int *)(iVar1 + 0xc) = param_1;
      *(int *)(param_1 + 0x10) = iVar1;
      return;
    }
    *(int *)(iVar2 + 0xc) = iVar1;
    *(int *)(iVar1 + 0xc) = param_1;
    *(int *)(param_1 + 0x10) = iVar1;
  }
  return;
}


// ==== FUN_004570d0 @ 0x004570d0 ====

void FUN_004570d0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  piVar4 = *(int **)(in_ECX + 8);
  if (piVar4 != *(int **)(in_ECX + 4)) {
    iVar1 = *param_1;
    do {
      iVar2 = *(int *)*piVar4;
      if (iVar1 < iVar2) {
LAB_00457110:
        piVar4 = (int *)piVar4[2];
      }
      else {
        if (iVar1 <= iVar2) {
          iVar3 = ((int *)*piVar4)[1];
          if (param_1[1] < iVar3) goto LAB_00457110;
          if (iVar1 <= iVar2) {
            if (iVar1 < iVar2) {
              return;
            }
            if (param_1[1] <= iVar3) {
              return;
            }
          }
        }
        piVar4 = (int *)piVar4[3];
      }
    } while (piVar4 != *(int **)(in_ECX + 4));
  }
  return;
}


// ==== FUN_00457120 @ 0x00457120 ====

uint FUN_00457120(undefined4 param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_004570d0(param_1);
  return -(uint)(uVar1 != *(uint *)(in_ECX + 4)) & uVar1;
}


// ==== FUN_00457140 @ 0x00457140 ====

int FUN_00457140(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(iVar1 + 8);
  if (*(char *)(iVar2 + 0x14) == '\0') {
    *(undefined1 *)(iVar2 + 0x14) = 1;
    *(undefined1 *)(iVar1 + 0x14) = 0;
    FUN_00457070(iVar1);
    iVar2 = *(int *)(iVar1 + 8);
  }
  if (*(char *)(*(int *)(iVar2 + 8) + 0x14) == '\x01') {
    *(undefined1 *)(iVar2 + 0x14) = 0;
    if (*(char *)(*(int *)(iVar2 + 0xc) + 0x14) == '\x01') {
      return iVar1;
    }
    *(undefined1 *)(*(int *)(iVar2 + 0xc) + 0x14) = 1;
    FUN_00457010(iVar2);
    iVar2 = *(int *)(iVar1 + 8);
  }
  *(undefined1 *)(iVar2 + 0x14) = *(undefined1 *)(iVar1 + 0x14);
  *(undefined1 *)(iVar1 + 0x14) = 1;
  *(undefined1 *)(*(int *)(iVar2 + 8) + 0x14) = 1;
  FUN_00457070(iVar1);
  return *(int *)(in_ECX + 8);
}


// ==== FUN_004571c0 @ 0x004571c0 ====

void FUN_004571c0(byte param_1)

{
  void *in_ECX;
  
  FUN_004571e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004571e0 @ 0x004571e0 ====

void FUN_004571e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097c0c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a03ac;
  local_4 = 1;
  if (in_ECX[2] != in_ECX[1]) {
    FUN_00456ec0(in_ECX[2]);
    in_ECX[2] = in_ECX[1];
  }
  FUN_0054e140();
  local_4 = local_4 & 0xffffff00;
  FUN_00456aa0();
  *in_ECX = &PTR_FUN_009a02ec;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00457250 @ 0x00457250 ====

void FUN_00457250(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0404;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00457270 @ 0x00457270 ====

void FUN_00457270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0404;
  return;
}


// ==== FUN_00457280 @ 0x00457280 ====

void FUN_00457280(void)

{
  return;
}


// ==== FUN_00457290 @ 0x00457290 ====

void FUN_00457290(void)

{
  return;
}


// ==== FUN_004572a0 @ 0x004572a0 ====

void FUN_004572a0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_004572b0 @ 0x004572b0 ====

undefined4 FUN_004572b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_004572c0 @ 0x004572c0 ====

void FUN_004572c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0418;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_004572d0 @ 0x004572d0 ====

undefined4 FUN_004572d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x004572e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return uVar1;
}


// ==== FUN_004572f0 @ 0x004572f0 ====

void FUN_004572f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00457270();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00457310 @ 0x00457310 ====

void FUN_00457310(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a042c;
  return;
}


// ==== FUN_00457350 @ 0x00457350 ====

void FUN_00457350(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 0xe;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_004573f0 @ 0x004573f0 ====

void FUN_004573f0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 0x10;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_00457490 @ 0x00457490 ====

void FUN_00457490(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 0xc;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_004574e0 @ 0x004574e0 ====

void FUN_004574e0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 0xd;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_00457530 @ 0x00457530 ====

void FUN_00457530(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 10;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_00457620 @ 0x00457620 ====

void FUN_00457620(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 0x12;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_00457670 @ 0x00457670 ====

void FUN_00457670(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 0x13;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_004576c0 @ 0x004576c0 ====

void FUN_004576c0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 0x15;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_00457710 @ 0x00457710 ====

void FUN_00457710(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 0x14;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_00457760 @ 0x00457760 ====

void FUN_00457760(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 0x16;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_004577b0 @ 0x004577b0 ====

void FUN_004577b0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 0x17;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_00457800 @ 0x00457800 ====

void FUN_00457800(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  puVar1[2] = param_1;
  *puVar1 = 0x18;
  puVar1[1] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_retaddr,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return;
}


// ==== FUN_00457850 @ 0x00457850 ====

void FUN_00457850(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a042c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00457870 @ 0x00457870 ====

void FUN_00457870(void)

{
  undefined4 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1);
  *puVar1 = 0x17;
  puVar1[1] = 0;
  puVar1[2] = unaff_retaddr;
  return;
}


// ==== FUN_004578a0 @ 0x004578a0 ====

void FUN_004578a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0434;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004578c0 @ 0x004578c0 ====

void FUN_004578c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0434;
  return;
}


// ==== FUN_004578d0 @ 0x004578d0 ====

int FUN_004578d0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_004578e0 @ 0x004578e0 ====

void FUN_004578e0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  return;
}


// ==== FUN_00457900 @ 0x00457900 ====

void FUN_00457900(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00457910 @ 0x00457910 ====

undefined1 FUN_00457910(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xc);
}


// ==== FUN_00457920 @ 0x00457920 ====

void FUN_00457920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a044c;
  in_ECX[1] = 0x13;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_00457940 @ 0x00457940 ====

void FUN_00457940(byte param_1)

{
  void *in_ECX;
  
  FUN_004578c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00457960 @ 0x00457960 ====

void FUN_00457960(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0464;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00457980 @ 0x00457980 ====

void FUN_00457980(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0464;
  return;
}


// ==== FUN_00457990 @ 0x00457990 ====

int FUN_00457990(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_004579a0 @ 0x004579a0 ====

int FUN_004579a0(void)

{
  int in_ECX;
  
  return in_ECX + 0x10;
}


// ==== FUN_004579b0 @ 0x004579b0 ====

int FUN_004579b0(void)

{
  int in_ECX;
  
  return in_ECX + 0x50;
}


// ==== FUN_004579c0 @ 0x004579c0 ====

void FUN_004579c0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  return;
}


// ==== FUN_004579e0 @ 0x004579e0 ====

void FUN_004579e0(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x10) = *param_1;
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 2);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 6);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 10);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0xe);
  *(undefined1 *)(in_ECX + 0x38) = *(undefined1 *)(param_1 + 0x14);
  *(undefined1 *)(in_ECX + 0x39) = *(undefined1 *)((int)param_1 + 0x29);
  *(undefined1 *)(in_ECX + 0x44) = *(undefined1 *)(param_1 + 0x1a);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined1 *)(in_ECX + 0x4c) = *(undefined1 *)(param_1 + 0x1e);
  return;
}


// ==== FUN_00457a40 @ 0x00457a40 ====

void FUN_00457a40(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50) = *param_1;
  *(undefined4 *)(in_ECX + 0x54) = param_1[1];
  *(undefined4 *)(in_ECX + 0x58) = param_1[2];
  *(undefined4 *)(in_ECX + 0x5c) = param_1[3];
  *(undefined4 *)(in_ECX + 0x68) = param_1[6];
  *(undefined4 *)(in_ECX + 0x6c) = param_1[7];
  *(undefined4 *)(in_ECX + 0x70) = param_1[8];
  *(undefined4 *)(in_ECX + 0x74) = param_1[9];
  *(undefined4 *)(in_ECX + 0x80) = param_1[0xc];
  *(undefined4 *)(in_ECX + 0x84) = param_1[0xd];
  *(undefined4 *)(in_ECX + 0x88) = param_1[0xe];
  *(undefined4 *)(in_ECX + 0x8c) = param_1[0xf];
  *(undefined4 *)(in_ECX + 0x60) = param_1[4];
  *(undefined4 *)(in_ECX + 100) = param_1[5];
  *(undefined4 *)(in_ECX + 0x78) = param_1[10];
  *(undefined4 *)(in_ECX + 0x7c) = param_1[0xb];
  return;
}


// ==== FUN_00457ac0 @ 0x00457ac0 ====

void FUN_00457ac0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00457ad0 @ 0x00457ad0 ====

void FUN_00457ad0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00457ae0 @ 0x00457ae0 ====

void FUN_00457ae0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00457af0 @ 0x00457af0 ====

void FUN_00457af0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = param_1;
  return;
}


// ==== FUN_00457b00 @ 0x00457b00 ====

void FUN_00457b00(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = param_1;
  return;
}


// ==== FUN_00457b10 @ 0x00457b10 ====

void FUN_00457b10(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== FUN_00457b20 @ 0x00457b20 ====

void FUN_00457b20(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = param_1;
  return;
}


// ==== FUN_00457b30 @ 0x00457b30 ====

void FUN_00457b30(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  return;
}


// ==== FUN_00457b40 @ 0x00457b40 ====

void FUN_00457b40(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00457b50 @ 0x00457b50 ====

void FUN_00457b50(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = *param_1;
  *(undefined4 *)(in_ECX + 0x2c) = param_1[1];
  return;
}


// ==== FUN_00457b70 @ 0x00457b70 ====

void FUN_00457b70(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = *param_1;
  *(undefined4 *)(in_ECX + 0x34) = param_1[1];
  return;
}


// ==== FUN_00457b90 @ 0x00457b90 ====

void FUN_00457b90(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x38) = param_1;
  return;
}


// ==== FUN_00457ba0 @ 0x00457ba0 ====

void FUN_00457ba0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x39) = param_1;
  return;
}


// ==== FUN_00457bb0 @ 0x00457bb0 ====

void FUN_00457bb0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_00457bc0 @ 0x00457bc0 ====

void FUN_00457bc0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x40) = param_1;
  return;
}


// ==== FUN_00457bd0 @ 0x00457bd0 ====

void FUN_00457bd0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x44) = param_1;
  return;
}


// ==== FUN_00457be0 @ 0x00457be0 ====

undefined1 FUN_00457be0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x44);
}


// ==== FUN_00457bf0 @ 0x00457bf0 ====

void FUN_00457bf0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x48) = param_1;
  return;
}


// ==== FUN_00457c00 @ 0x00457c00 ====

undefined4 FUN_00457c00(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x48);
}


// ==== FUN_00457c10 @ 0x00457c10 ====

void FUN_00457c10(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x4c) = param_1;
  return;
}


// ==== FUN_00457c20 @ 0x00457c20 ====

undefined1 FUN_00457c20(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x4c);
}


// ==== FUN_00457c30 @ 0x00457c30 ====

void FUN_00457c30(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0) = param_1;
  return;
}


// ==== FUN_00457c50 @ 0x00457c50 ====

void FUN_00457c50(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa4) = param_1;
  return;
}


// ==== FUN_00457c70 @ 0x00457c70 ====

float10 FUN_00457c70(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0xa0);
}


// ==== FUN_00457c80 @ 0x00457c80 ====

float10 FUN_00457c80(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0xa4);
}


// ==== FUN_00457c90 @ 0x00457c90 ====

void FUN_00457c90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a050c;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  return;
}


// ==== FUN_00457cb0 @ 0x00457cb0 ====

void FUN_00457cb0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x90) = param_1;
  return;
}


// ==== FUN_00457cc0 @ 0x00457cc0 ====

undefined4 FUN_00457cc0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x90);
}


// ==== FUN_00457cd0 @ 0x00457cd0 ====

void FUN_00457cd0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x94) = param_1;
  return;
}


// ==== FUN_00457ce0 @ 0x00457ce0 ====

undefined4 FUN_00457ce0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x94);
}


// ==== FUN_00457cf0 @ 0x00457cf0 ====

void FUN_00457cf0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x98) = param_1;
  return;
}


// ==== FUN_00457d00 @ 0x00457d00 ====

void FUN_00457d00(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x9c) = param_1;
  return;
}


// ==== FUN_00457d10 @ 0x00457d10 ====

undefined4 FUN_00457d10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x9c);
}


// ==== FUN_00457d20 @ 0x00457d20 ====

void FUN_00457d20(byte param_1)

{
  void *in_ECX;
  
  FUN_00457980();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00457d40 @ 0x00457d40 ====

void FUN_00457d40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a06e8;
  return;
}


// ==== FUN_00457d50 @ 0x00457d50 ====

void FUN_00457d50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a06e8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00457d70 @ 0x00457d70 ====

void FUN_00457d70(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x18) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x18))(1);
  }
  *(undefined4 *)(in_ECX + 0x18) = 0;
  if (*(undefined4 **)(in_ECX + 0x14) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x14))(1);
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  if (*(undefined4 **)(in_ECX + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xc))(1);
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (*(undefined4 **)(in_ECX + 0x10) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x10))(1);
  }
  *(undefined4 *)(in_ECX + 0x10) = 0;
  FUN_0049d730();
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  FUN_00498bd0();
  return;
}


// ==== FUN_00457df0 @ 0x00457df0 ====

uint FUN_00457df0(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a688 + 0x28))();
  if ((char)uVar1 == '\x01') {
    *(undefined1 *)(in_ECX + 4) = 1;
    return uVar1;
  }
  (**(code **)(*DAT_00b5a83c + 0x10))();
  uVar1 = (**(code **)(*DAT_00b5a740 + 0x20))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_00457e30 @ 0x00457e30 ====

void FUN_00457e30(void)

{
  int in_ECX;
  
  FUN_00458850(*(undefined4 *)(*(int *)(in_ECX + 4) + 4));
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_00457e60 @ 0x00457e60 ====

void FUN_00457e60(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  void *pvStack_64;
  undefined1 uStack_60;
  uint uStack_50;
  undefined4 uStack_4c;
  void *pvStack_48;
  undefined4 uStack_38;
  uint uStack_34;
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c101;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x28);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00460140();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 8) = uVar2;
  uVar2 = FUN_0054a330();
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  FUN_00498b30();
  piVar3 = (int *)FUN_004d5e90();
  *(int **)(in_ECX + 0x14) = piVar3;
  (**(code **)(*piVar3 + 4))();
  pvVar1 = operator_new(0x11c);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0045c980();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar3 + 4))();
  *(int **)(in_ECX + 0x10) = piVar3;
  pvVar1 = operator_new(0xa0);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004599d0();
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar2;
  local_4 = 0xffffffff;
  uStack_4c = 0xf;
  uStack_50 = 0;
  uStack_60 = 0;
  FUN_00401740(s_changemaxmessage_009a05ec,0x10);
  local_4 = 3;
  uVar2 = FUN_0040bf70(&pvStack_64,1);
  local_4 = CONCAT31(local_4._1_3_,4);
  (**(code **)(*DAT_00b5a7d8 + 4))(uVar2);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  if (uStack_50 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(pvStack_64);
  return;
}


// ==== FUN_00457ff0 @ 0x00457ff0 ====

undefined4 FUN_00457ff0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c113;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_changemaxmessage_009a061c,0x10);
  if (iVar1 != 0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_00459160(local_28,0);
  local_4 = 0;
  uVar2 = FUN_00796fb0(uVar2);
  *(undefined4 *)(in_ECX + 0x1c) = uVar2;
  if (uStack_10 < 0x10) {
    ExceptionList = local_c;
    return 1;
  }
  _free(pvStack_24);
  return extraout_EAX;
}


// ==== FUN_00458090 @ 0x00458090 ====

void FUN_00458090(int param_1)

{
  int in_ECX;
  int local_10 [2];
  undefined1 local_8 [8];
  
  FUN_0079bba0(local_10,&param_1);
  if (local_10[0] == *(int *)(in_ECX + 4)) {
    local_10[0] = param_1;
    local_10[1] = 1;
    FUN_00458d90(local_8,local_10);
    return;
  }
  *(int *)(local_10[0] + 0x10) = *(int *)(local_10[0] + 0x10) + 1;
  return;
}


// ==== FUN_004580f0 @ 0x004580f0 ====

void FUN_004580f0(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  
  cVar1 = FUN_004596e0(param_1);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 4))(param_1);
    if (cVar1 == '\0') {
      cVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0xc))(param_1);
      if (cVar1 == '\0') {
        cVar1 = (**(code **)(**(int **)(in_ECX + 0x14) + 0xc))(param_1);
        if (cVar1 == '\0') {
          cVar1 = (**(code **)(**(int **)(in_ECX + 0x10) + 8))(param_1);
          if (cVar1 == '\0') {
            cVar1 = (**(code **)(*DAT_00b5a7c8 + 4))(param_1);
            if (cVar1 == '\0') {
              cVar1 = (**(code **)(*DAT_00b5a82c + 4))(param_1);
              if (cVar1 == '\0') {
                iVar2 = (**(code **)(*param_1 + 4))();
                if (iVar2 == 0x70004) {
                  FUN_00457ff0(param_1);
                }
                else if (iVar2 == 0xc0001) {
                  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0x10))();
                  (**(code **)(*piVar3 + 0x14))();
                  return;
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_004581a0 @ 0x004581a0 ====

void FUN_004581a0(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int in_ECX;
  uint uVar7;
  uint local_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097c125;
  pvStack_c = ExceptionList;
  uVar7 = 0;
  local_2c = 0;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5a688 + 0x28))();
  if (cVar1 == '\x01') {
    *(undefined1 *)(in_ECX + 4) = 1;
    ExceptionList = pvStack_c;
    return;
  }
  (**(code **)(*DAT_00b5a83c + 0x10))();
  (**(code **)(*DAT_00b5a740 + 0x20))();
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  iVar2 = (**(code **)(*DAT_00b5a6ac + 0x24))();
  puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  if (puVar3 != (undefined4 *)0x0) {
    do {
      iVar4 = (**(code **)(*DAT_00b5a6ac + 0x24))();
      if (100 < (uint)(iVar4 - iVar2)) {
        cVar1 = (**(code **)(*DAT_00b5a688 + 0x28))();
        if (cVar1 == '\x01') {
          *(undefined1 *)(in_ECX + 4) = 1;
        }
        else {
          (**(code **)(*DAT_00b5a83c + 0x10))();
          (**(code **)(*DAT_00b5a740 + 0x20))();
        }
        iVar2 = iVar4;
      }
      FUN_004580f0();
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)();
      }
      uVar7 = local_2c + 1;
      puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      local_2c = uVar7;
    } while (puVar3 != (undefined4 *)0x0);
  }
  (**(code **)(**(int **)(in_ECX + 0xc) + 8))();
  piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  (**(code **)(*piVar5 + 0x10))();
  if (*(uint *)(in_ECX + 0x1c) < uVar7) {
    FUN_00401740(s_Exceed_Max_Message__u__u__009a0600,0x19);
    uVar6 = FUN_00797530(auStack_28);
    uStack_4 = 0;
    FUN_00796d90(uVar6);
    uStack_4 = 0xffffffff;
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  }
  FUN_00458850();
  *(int *)(*(int *)(in_ECX + 0x24) + 4) = *(int *)(in_ECX + 0x24);
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x24);
  *(int *)(*(int *)(in_ECX + 0x24) + 8) = *(int *)(in_ECX + 0x24);
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00458350 @ 0x00458350 ====

void FUN_00458350(void)

{
  undefined4 *in_ECX;
  undefined1 auStack_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097c142;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a06f8;
  local_4 = 1;
  FUN_00457d70();
  local_4 = local_4 & 0xffffff00;
  FUN_00458e50(auStack_10,*(undefined4 *)in_ECX[9],(undefined4 *)in_ECX[9]);
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_004583d0 @ 0x004583d0 ====

void FUN_004583d0(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = *(char *)(in_ECX + 4);
  while (cVar1 == '\0') {
    FUN_004581a0();
    cVar1 = *(char *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_004583f0 @ 0x004583f0 ====

void FUN_004583f0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined4 *puVar7;
  undefined4 *_Memory;
  int iVar8;
  undefined1 auStack_90 [4];
  undefined1 local_8c;
  undefined4 uStack_84;
  undefined4 *puStack_80;
  undefined4 *local_7c;
  int local_78;
  undefined1 **ppuStack_74;
  char *pcStack_70;
  int local_54;
  undefined1 *local_50;
  undefined4 local_4c;
  undefined1 local_48 [4];
  undefined4 *local_44;
  undefined4 *local_40;
  int local_3c;
  undefined1 local_34 [4];
  void *local_30;
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  puStack_10 = &LAB_0097c16c;
  _Memory = (undefined4 *)0x0;
  puVar7 = (undefined4 *)0x0;
  local_44 = (undefined4 *)0x0;
  local_40 = (undefined4 *)0x0;
  local_3c = 0;
  puVar2 = *(undefined4 **)(in_ECX + 4);
  puVar3 = (undefined4 *)*puVar2;
  local_c = 0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  while (puVar3 != puVar2) {
    local_4c = puVar3[4];
    local_50 = (undefined1 *)puVar3[3];
    if ((_Memory == (undefined4 *)0x0) ||
       ((uint)(local_3c - (int)_Memory >> 3) <= (uint)((int)puVar7 - (int)_Memory >> 3))) {
      pcStack_70 = (char *)0x1;
      local_78 = 0x45849a;
      ppuStack_74 = (undefined1 **)puVar7;
      FUN_00458f10();
      _Memory = local_44;
    }
    else {
      pcStack_70 = local_48;
      ppuStack_74 = &local_50;
      local_78 = 1;
      puStack_80 = (undefined4 *)0x45847d;
      local_7c = puVar7;
      FUN_00429bc0();
      local_40 = puVar7 + 2;
    }
    puVar7 = local_40;
    if (_Memory != local_40) {
      puVar5 = (undefined4 *)((int)(local_40 + -2) - (int)_Memory >> 3);
      if (0 < (int)puVar5) {
        pcStack_70 = (char *)local_40[-1];
        ppuStack_74 = (undefined1 **)local_40[-2];
        local_78 = 0;
        uStack_84 = 0x4584c8;
        puStack_80 = _Memory;
        local_7c = puVar5;
        FUN_00458770();
      }
    }
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
        puVar4 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar4, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar4 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  pcStack_70 = s__________________________________009a0630;
  local_1c = 0xf;
  local_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  ppuStack_74 = (undefined1 **)0x45852f;
  FUN_00401740();
  local_c._0_1_ = 1;
  pcStack_70 = (char *)0x45853e;
  FUN_00796d50();
  local_c = (uint)local_c._1_3_ << 8;
  if (0xf < local_1c) {
    pcStack_70 = (char *)0x458556;
    _free(local_30);
    return;
  }
  local_54 = 1;
  do {
    if ((_Memory == (undefined4 *)0x0) || (iVar8 = (int)puVar7 - (int)_Memory >> 3, iVar8 == 0))
    break;
    pcStack_70 = (char *)*_Memory;
    ppuStack_74 = (undefined1 **)local_54;
    local_50 = auStack_90;
    local_78 = 0xf;
    local_7c = (undefined4 *)0x0;
    local_8c = 0;
    FUN_00401740(s___2d____code__8x__count___u_009a0678,0x1b);
    uVar6 = FUN_00404230(local_34);
    local_c._0_1_ = 2;
    FUN_00796d50(uVar6);
    local_c = (uint)local_c._1_3_ << 8;
    if (0xf < local_1c) {
      pcStack_70 = (char *)0x4585d4;
      _free(local_30);
      return;
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffffff00);
    if (1 < iVar8) {
      ppuStack_74 = (undefined1 **)puVar7[-2];
      pcStack_70 = (char *)puVar7[-1];
      puVar7[-2] = *_Memory;
      puVar7[-1] = _Memory[1];
      local_78 = (int)(puVar7 + -2) - (int)_Memory >> 3;
      local_7c = (undefined4 *)0x0;
      uStack_84 = 0x458612;
      puStack_80 = _Memory;
      FUN_004587d0();
      puVar7 = local_40;
    }
    if (iVar8 != 0) {
      puVar7 = puVar7 + -2;
      local_40 = puVar7;
    }
    local_54 = local_54 + 1;
  } while (local_54 < 0xb);
  pcStack_70 = s__________________________________009a0698;
  local_1c = 0xf;
  local_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  ppuStack_74 = (undefined1 **)0x458658;
  FUN_00401740();
  local_c = CONCAT31(local_c._1_3_,3);
  pcStack_70 = (char *)0x458667;
  FUN_00796d50();
  if (0xf < local_1c) {
    pcStack_70 = (char *)0x45867b;
    _free(local_30);
    return;
  }
  if (_Memory == (undefined4 *)0x0) {
    ExceptionList = local_14;
    return;
  }
  pcStack_70 = (char *)0x458688;
  _free(_Memory);
  return;
}


// ==== FUN_004586a0 @ 0x004586a0 ====

void FUN_004586a0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c17e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a06f8;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 500;
  iVar1 = FUN_0058d7c0();
  in_ECX[9] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[9] + 4) = in_ECX[9];
  *(undefined4 *)in_ECX[9] = in_ECX[9];
  *(undefined4 *)(in_ECX[9] + 8) = in_ECX[9];
  in_ECX[10] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00458720 @ 0x00458720 ====

void FUN_00458720(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x15) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x15) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x15);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x15);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x15);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x15);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_00458770 @ 0x00458770 ====

void FUN_00458770(int param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  
  while ((param_3 < param_2 &&
         (iVar1 = (param_2 + -1) / 2, *(uint *)(param_1 + 4 + iVar1 * 8) < param_5))) {
    *(undefined4 *)(param_1 + param_2 * 8) = *(undefined4 *)(param_1 + iVar1 * 8);
    *(undefined4 *)(param_1 + 4 + param_2 * 8) = *(undefined4 *)(param_1 + 4 + iVar1 * 8);
    param_2 = iVar1;
  }
  *(uint *)(param_1 + 4 + param_2 * 8) = param_5;
  *(undefined4 *)(param_1 + param_2 * 8) = param_4;
  return;
}


// ==== FUN_004587d0 @ 0x004587d0 ====

void FUN_004587d0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2 * 2 + 2;
  iVar3 = param_2;
  iVar2 = param_2;
  if (iVar1 < param_3) {
    do {
      iVar2 = iVar1;
      if (*(uint *)(param_1 + 4 + iVar1 * 8) < *(uint *)(param_1 + -4 + iVar1 * 8)) {
        iVar2 = iVar1 + -1;
      }
      *(undefined4 *)(param_1 + iVar3 * 8) = *(undefined4 *)(param_1 + iVar2 * 8);
      *(undefined4 *)(param_1 + 4 + iVar3 * 8) = *(undefined4 *)(param_1 + 4 + iVar2 * 8);
      iVar1 = iVar2 * 2 + 2;
      iVar3 = iVar2;
    } while (iVar1 < param_3);
  }
  if (iVar1 == param_3) {
    *(undefined4 *)(param_1 + iVar2 * 8) = *(undefined4 *)(param_1 + -8 + param_3 * 8);
    *(undefined4 *)(param_1 + 4 + iVar2 * 8) = *(undefined4 *)(param_1 + -4 + param_3 * 8);
    iVar2 = param_3 + -1;
  }
  FUN_00458770(param_1,iVar2,param_2,param_4,param_5,param_6);
  return;
}


// ==== FUN_00458850 @ 0x00458850 ====

void FUN_00458850(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00458850(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00458890 @ 0x00458890 ====

void FUN_00458890(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097c198;
  local_c = ExceptionList;
  if (0x1ffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00448a90(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[5] == '\0') {
LAB_00458989:
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
      if ((char)piVar6[5] == '\0') goto LAB_00458989;
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


// ==== FUN_00458a70 @ 0x00458a70 ====

/* WARNING: Removing unreachable block (ram,0x00458b83) */
/* WARNING: Removing unreachable block (ram,0x00458b93) */
/* WARNING: Removing unreachable block (ram,0x00458b9c) */
/* WARNING: Removing unreachable block (ram,0x00458b9f) */
/* WARNING: Removing unreachable block (ram,0x00458b8f) */
/* WARNING: Removing unreachable block (ram,0x00458bad) */
/* WARNING: Removing unreachable block (ram,0x00458bba) */
/* WARNING: Removing unreachable block (ram,0x00458bc5) */
/* WARNING: Removing unreachable block (ram,0x00458bc1) */
/* WARNING: Removing unreachable block (ram,0x00458bb5) */
/* WARNING: Removing unreachable block (ram,0x00458bc8) */

void FUN_00458a70(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097c198;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x15) != '\0') {
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
  FUN_00458720();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
    if (*(char *)(param_2[2] + 0x15) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      piVar3 = (int *)FUN_004cf3b0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      uVar4 = FUN_004489e0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[5] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[5] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[5] == '\0') {
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(piVar3 + 5) = 0;
            FUN_00448a00(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            if ((*(char *)(*piVar5 + 0x14) == '\x01') && (*(char *)(piVar5[2] + 0x14) == '\x01'))
            goto LAB_00458c95;
            if (*(char *)(piVar5[2] + 0x14) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x14) = 1;
              *(undefined1 *)(piVar5 + 5) = 0;
              FUN_00519c40(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 5) = (char)piVar3[5];
            *(undefined1 *)(piVar3 + 5) = 1;
            *(undefined1 *)(piVar5[2] + 0x14) = 1;
            FUN_00448a00(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[5] == '\0') {
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(piVar3 + 5) = 0;
            FUN_00519c40(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            if ((*(char *)(piVar5[2] + 0x14) != '\x01') || (*(char *)(*piVar5 + 0x14) != '\x01')) {
              if (*(char *)(*piVar5 + 0x14) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x14) = 1;
                *(undefined1 *)(piVar5 + 5) = 0;
                FUN_00448a00(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 5) = (char)piVar3[5];
              *(undefined1 *)(piVar3 + 5) = 1;
              *(undefined1 *)(*piVar5 + 0x14) = 1;
              FUN_00519c40(piVar3);
              break;
            }
LAB_00458c95:
            *(undefined1 *)(piVar5 + 5) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 5) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_00458d20 @ 0x00458d20 ====

void FUN_00458d20(void)

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
  puStack_8 = &LAB_0097c198;
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


// ==== FUN_00458d90 @ 0x00458d90 ====

void FUN_00458d90(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00458890(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00458890(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00458e50 @ 0x00458e50 ====

void FUN_00458e50(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00458850(piVar6[1]);
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
    FUN_00458a70(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00458f10 @ 0x00458f10 ====

void FUN_00458f10(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int extraout_ECX;
  int iVar6;
  int iVar7;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097c1b0;
  local_10 = ExceptionList;
  local_1c = param_3[1];
  local_20 = *param_3;
  iVar3 = *(int *)(in_ECX + 4);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x2c);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0xc) - iVar3 >> 3;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x2c);
    if (0x1fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar2 = FUN_00458d20();
      iVar3 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    if (uVar2 < iVar6 + param_2) {
      if (0x1fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
      }
      if (uVar2 < iVar6 + param_2) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - iVar3 >> 3;
        }
        uVar2 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar2 * 8);
      local_8 = 0;
      local_18 = pvVar4;
      iVar3 = FUN_00751a10(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_00429bc0(iVar3,param_2,&local_20);
      FUN_00751a10(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 8);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 8 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 8);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar6 = *(int *)(in_ECX + 8);
    iVar3 = param_2 * 8;
    if ((uint)(iVar6 - param_1 >> 3) < param_2) {
      FUN_00751a10(param_1,iVar6,iVar3 + param_1);
      local_8 = 2;
      FUN_004b9150(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 3),&local_20);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar3;
      FUN_00686630(param_1,*(int *)(in_ECX + 8) + param_2 * -8,&local_20);
      ExceptionList = local_10;
      return;
    }
    iVar7 = iVar6 + param_2 * -8;
    uVar5 = FUN_00751a10(iVar7,iVar6,iVar6);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00576790(param_1,iVar7,iVar6);
    FUN_00686630(param_1,iVar3 + param_1,&local_20);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00459081 @ 0x00459081 ====

void Catch_00459081(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00459160 @ 0x00459160 ====

int FUN_00459160(int param_1,uint param_2)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) != 0) {
    if (param_2 < (uint)((*(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28)) / 0x1c)) {
      iVar1 = *(int *)(in_ECX + 0x28);
      if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0x2c) - iVar1) / 0x1c) <= param_2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401660(iVar1 + param_2 * 0x1c,0,0xffffffff);
      return param_1;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(&DAT_0099cf70,0);
  return param_1;
}


// ==== FUN_00459220 @ 0x00459220 ====

void FUN_00459220(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00458e50(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00459250 @ 0x00459250 ====

void FUN_00459250(byte param_1)

{
  void *in_ECX;
  
  FUN_00458350();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00459270 @ 0x00459270 ====

void FUN_00459270(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0708;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00459290 @ 0x00459290 ====

void FUN_00459290(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0718;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a71c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a71c = in_ECX;
  return;
}


// ==== FUN_004592d0 @ 0x004592d0 ====

void FUN_004592d0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a71c = 0;
  *in_ECX = &PTR_FUN_009a0708;
  return;
}


// ==== FUN_004592f0 @ 0x004592f0 ====

void FUN_004592f0(void)

{
                    /* WARNING: Could not recover jumptable at 0x004592f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a68c + 4))();
  return;
}


// ==== FUN_00459300 @ 0x00459300 ====

undefined4 FUN_00459300(undefined4 param_1)

{
  (**(code **)(*DAT_00b5a68c + 0xc))(param_1);
  return param_1;
}


// ==== FUN_00459320 @ 0x00459320 ====

void FUN_00459320(byte param_1)

{
  void *in_ECX;
  
  FUN_004592d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00459340 @ 0x00459340 ====

void FUN_00459340(undefined4 param_1)

{
  (**(code **)(*DAT_00b5a688 + 4))(param_1);
  return;
}


// ==== FUN_00459360 @ 0x00459360 ====

void FUN_00459360(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x28);
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
  return;
}


// ==== FUN_004593a0 @ 0x004593a0 ====

void FUN_004593a0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_004593a0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004593e0 @ 0x004593e0 ====

void FUN_004593e0(int param_1)

{
  int iVar1;
  __time32_t _Var2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  for (iVar3 = *(int *)(param_1 + 4); iVar3 != iVar1; iVar3 = iVar3 + 0x48) {
    _Var2 = FID_conflict___time32((__time32_t *)0x0);
    *(__time32_t *)(iVar3 + 0x18) = _Var2;
  }
  return;
}


// ==== FUN_00459410 @ 0x00459410 ====

void FUN_00459410(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_ECX;
  void *unaff_EBP;
  undefined1 auStack_7c [4];
  undefined1 uStack_78;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  uint uStack_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0097c1d0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x84) + 0x10))();
  if ((piVar1 == (int *)0x0) || (param_1 == 0 && param_2 == 0)) {
    if ((*(int *)(in_ECX + 0x98) == 2) || (*(int *)(in_ECX + 0x98) == 3)) {
      iStack_60 = (**(code **)(**(int **)(in_ECX + 0x84) + 0x14))();
      uStack_64 = 0x4594e5;
      puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 0x84) + 0x10))();
      if (puVar2 != (undefined4 *)0x0) {
        iStack_60 = *puVar2;
        puStack_4 = auStack_7c;
        uStack_64 = 0xf;
        uStack_68 = 0;
        uStack_78 = 0;
        FUN_00401740(s_rc_pplinfo__d__s_009a07b0,0x10);
        FUN_00404230(auStack_30);
        pvStack_c = (void *)0x0;
        iStack_60 = 0x459546;
        (**(code **)(*DAT_00b5a688 + 4))();
        if (0xf < uStack_18) {
          unaff_EBP = pvStack_2c;
          goto LAB_00459550;
        }
      }
    }
  }
  else if ((*(char *)(in_ECX + 0x9c) == '\0') || (*piVar1 != 0)) {
    iStack_60 = *piVar1;
    puStack_4 = auStack_7c;
    FUN_00401830(s_rc_pplinfo__d__s_009a07c4);
    FUN_00404230(auStack_30 + -0x1c);
    pvStack_c = (void *)0x1;
    iStack_60 = 0x4594a6;
    (**(code **)(*DAT_00b5a688 + 4))();
    if (0xf < uStack_34) {
LAB_00459550:
      iStack_60 = 0x459556;
      _free(unaff_EBP);
      return;
    }
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00459570 @ 0x00459570 ====

void FUN_00459570(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097c1fb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a07dc;
  local_4 = 1;
  if (*(char *)(in_ECX + 2) != '\0') {
    (**(code **)(*(int *)in_ECX[0x21] + 8))();
  }
  if ((undefined4 *)in_ECX[0x21] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x21])(1);
  }
  in_ECX[0x21] = 0;
  local_4 = local_4 & 0xffffff00;
  _eh_vector_destructor_iterator_(in_ECX + 0xd,0x10,5,FUN_0045a3d0);
  if ((uint)in_ECX[10] < 0x10) {
    in_ECX[9] = 0;
    in_ECX[10] = 0xf;
    *(undefined1 *)(in_ECX + 5) = 0;
    ExceptionList = pvStack_c;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_00459610 @ 0x00459610 ====

void FUN_00459610(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined8 uVar2;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c20d;
  local_c = ExceptionList;
  if ((*(char *)(in_ECX + 8) != '\0') &&
     (ExceptionList = &local_c,
     *(int *)(in_ECX + 0x88) = *(int *)(in_ECX + 0x88) + *(int *)(param_1 + 4),
     4999 < *(uint *)(in_ECX + 0x88))) {
    *(undefined4 *)(in_ECX + 0x88) = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    iVar1 = *(int *)(in_ECX + 0x98) * 0x10 + in_ECX;
    local_4 = 0;
    FUN_0045a770(0,*(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x3c),param_1);
    if (*(char *)(in_ECX + 0x9c) != '\0') {
      FUN_0045a3e0(&param_1,local_18);
    }
    uVar2 = (**(code **)(**(int **)(in_ECX + 0x84) + 0xc))(local_1c);
    FUN_00459410(uVar2);
    FUN_0045a360();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004596e0 @ 0x004596e0 ====

/* WARNING: Removing unreachable block (ram,0x004597b9) */

undefined4 FUN_004596e0(int *param_1)

{
  int iVar1;
  int in_ECX;
  longlong lVar2;
  
  if (*(int *)(in_ECX + 0x84) == 0) {
    return 0;
  }
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    FUN_00459610(param_1);
  }
  else {
    if (iVar1 == 0x70940002) {
      if (*(char *)(in_ECX + 8) == '\0') {
        iVar1 = param_1[1];
        *(int *)(in_ECX + 0x98) = iVar1;
        FUN_004593e0(iVar1 * 0x10 + 0x34 + in_ECX);
        (**(code **)(**(int **)(in_ECX + 0x84) + 4))
                  (in_ECX + 0xc,*(int *)(in_ECX + 0x98) * 0x10 + 0x34 + in_ECX);
        (**(code **)(*DAT_00b5a834 + 0xc))();
        *(undefined1 *)(in_ECX + 0x9c) = 0;
        *(undefined1 *)(in_ECX + 8) = 1;
        *(undefined4 *)(in_ECX + 0x88) = 5000;
        if (((*(int *)(in_ECX + 0x98) == 1) || (*(int *)(in_ECX + 0x98) == 0)) &&
           (lVar2 = (**(code **)(**(int **)(in_ECX + 0x84) + 0x14))(), 0 < lVar2)) {
          *(undefined1 *)(in_ECX + 0x9c) = 1;
          (**(code **)(*DAT_00b5a838 + 8))(*(undefined4 *)(in_ECX + 0x98));
          FUN_00459410(lVar2);
        }
      }
      return 1;
    }
    if (iVar1 == 0x70940003) {
      if (*(char *)(in_ECX + 8) != '\0') {
        (**(code **)(**(int **)(in_ECX + 0x84) + 8))();
        *(undefined1 *)(in_ECX + 8) = 0;
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00459800 @ 0x00459800 ====

void FUN_00459800(void)

{
  undefined4 local_54;
  undefined *local_50;
  undefined4 local_4c;
  undefined4 local_44;
  undefined4 local_40;
  __time32_t local_3c;
  void *local_28;
  undefined4 local_18;
  uint local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c21f;
  local_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4 = 0;
  local_54 = 0;
  local_50 = (undefined *)0x0;
  local_4c = 0;
  local_44 = 0;
  local_40 = 0;
  ExceptionList = &local_c;
  local_3c = FID_conflict___time32((__time32_t *)0x0);
  local_54 = 0x10;
  local_50 = (undefined *)0x1fbd64;
  local_4c = 0x1f;
  FUN_00401740(s_2PoisonousSwamp_009a073c,0xf);
  FUN_0045ab80(&local_54);
  local_54 = 0x10;
  local_50 = &DAT_00b7e238;
  local_4c = 0x1f;
  FUN_00401740(s_2PoisonousSwamp_Video_009a074c,0x15);
  FUN_0045ab80(&local_54);
  local_54 = 1;
  local_50 = (undefined *)0x1fbd64;
  local_4c = 0x1f;
  FUN_00401740(s_2Twin_Towers_009a0764,0xc);
  FUN_0045ab80(&local_54);
  local_54 = 1;
  local_50 = &DAT_00b7e238;
  local_4c = 0x1f;
  FUN_00401740(s_12Twin_Towers_Video_009a0774,0x13);
  FUN_0045ab80(&local_54);
  local_54 = 0x10;
  local_50 = &DAT_00b7e238;
  local_4c = 0x1f;
  FUN_00401740(s_12Death_Velley_009a0788,0xe);
  FUN_0045ab80(&local_54);
  local_54 = 0x10;
  local_50 = &DAT_00b7e238;
  local_4c = 0x1f;
  FUN_00401740(s_12Log_out_009a0798,9);
  FUN_0045ab80(&local_54);
  local_54 = 1;
  local_50 = (undefined *)0x1fbd64;
  local_4c = 0x1f;
  FUN_00401740(s_2Main_Page_009a07a4,10);
  FUN_0045ab80(&local_54);
  if (local_14 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_28);
  return;
}


// ==== FUN_004599d0 @ 0x004599d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004599d0(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c255;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a07dc;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  local_4 = 0;
  _eh_vector_constructor_iterator_(in_ECX + 0xd,0x10,5,FUN_0045a320,FUN_0045a3d0);
  in_ECX[0x21] = 0;
  in_ECX[0x26] = 0;
  local_4._0_1_ = 1;
  iVar1 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar1 == 3) {
    pvVar2 = operator_new(0xc);
    local_4._0_1_ = 2;
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004621a0();
    }
    local_4._0_1_ = 1;
    in_ECX[0x21] = uVar3;
  }
  in_ECX[3] = 0x6a;
  FUN_00401740(&DAT_009a0728,3);
  puVar4 = operator_new(8);
  in_ECX[0xc] = puVar4;
  *puVar4 = 0x1fbd64;
  *(undefined **)(in_ECX[0xc] + 4) = &DAT_00b7e238;
  in_ECX[0xb] = 150000;
  _DAT_00b5a850 = DAT_009a072c;
  DAT_00b5a85c = DAT_009a0738;
  _DAT_00b5a854 = DAT_009a0730;
  _DAT_00b5a858 = DAT_009a0734;
  DAT_00b5a848 = 0x4443;
  FUN_00459800();
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x22] = 5000;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00459b20 @ 0x00459b20 ====

void FUN_00459b20(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x40) < 0x10) {
    *(undefined4 *)(in_ECX + 0x40) = 0xf;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    *(undefined1 *)(in_ECX + 0x2c) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x2c));
  return;
}


// ==== FUN_00459b50 @ 0x00459b50 ====

void FUN_00459b50(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  in_ECX[8] = param_1[8];
  in_ECX[9] = param_1[9];
  in_ECX[0x10] = 0xf;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  FUN_00401660(param_1 + 10,0,0xffffffff);
  return;
}


// ==== FUN_00459bb0 @ 0x00459bb0 ====

void FUN_00459bb0(void)

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
  puStack_8 = &LAB_0097c268;
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


// ==== FUN_00459c20 @ 0x00459c20 ====

/* WARNING: Removing unreachable block (ram,0x00459d33) */
/* WARNING: Removing unreachable block (ram,0x00459d43) */
/* WARNING: Removing unreachable block (ram,0x00459d4c) */
/* WARNING: Removing unreachable block (ram,0x00459d4f) */
/* WARNING: Removing unreachable block (ram,0x00459d3f) */
/* WARNING: Removing unreachable block (ram,0x00459d5d) */
/* WARNING: Removing unreachable block (ram,0x00459d6a) */
/* WARNING: Removing unreachable block (ram,0x00459d75) */
/* WARNING: Removing unreachable block (ram,0x00459d71) */
/* WARNING: Removing unreachable block (ram,0x00459d65) */
/* WARNING: Removing unreachable block (ram,0x00459d78) */

void FUN_00459c20(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097c268;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x21) != '\0') {
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
  FUN_004dde50();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x21) == '\0') {
    if (*(char *)(param_2[2] + 0x21) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x21) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x21) == '\0') {
      piVar3 = (int *)FUN_004128f0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x21) == '\0') {
      uVar4 = FUN_0057dff0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[8] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[8] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_004bdf70(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(*piVar5 + 0x20) == '\x01') && (*(char *)(piVar5[2] + 0x20) == '\x01'))
            goto LAB_00459e45;
            if (*(char *)(piVar5[2] + 0x20) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x20) = 1;
              *(undefined1 *)(piVar5 + 8) = 0;
              FUN_004bdfc0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 8) = (char)piVar3[8];
            *(undefined1 *)(piVar3 + 8) = 1;
            *(undefined1 *)(piVar5[2] + 0x20) = 1;
            FUN_004bdf70(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_004bdfc0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(piVar5[2] + 0x20) != '\x01') || (*(char *)(*piVar5 + 0x20) != '\x01')) {
              if (*(char *)(*piVar5 + 0x20) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x20) = 1;
                *(undefined1 *)(piVar5 + 8) = 0;
                FUN_004bdf70(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 8) = (char)piVar3[8];
              *(undefined1 *)(piVar3 + 8) = 1;
              *(undefined1 *)(*piVar5 + 0x20) = 1;
              FUN_004bdfc0(piVar3);
              break;
            }
LAB_00459e45:
            *(undefined1 *)(piVar5 + 8) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 8) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_00459ed0 @ 0x00459ed0 ====

undefined4 * FUN_00459ed0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3[4] = param_1[4];
    param_3[5] = param_1[5];
    param_3[6] = param_1[6];
    param_3[7] = param_1[7];
    param_3[8] = param_1[8];
    param_3[9] = param_1[9];
    FUN_00401660(param_1 + 10,0,0xffffffff);
    param_1 = param_1 + 0x12;
    param_3 = param_3 + 0x12;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_00459f40 @ 0x00459f40 ====

undefined4 * FUN_00459f40(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x48;
    puVar2 = param_3 + -0x12;
    *puVar2 = *(undefined4 *)(param_2 + -0x48);
    param_3[-0x11] = *(undefined4 *)(param_2 + -0x44);
    param_3[-0x10] = *(undefined4 *)(param_2 + -0x40);
    param_3[-0xe] = *(undefined4 *)(param_2 + -0x38);
    param_3[-0xd] = *(undefined4 *)(param_2 + -0x34);
    param_3[-0xc] = *(undefined4 *)(param_2 + -0x30);
    param_3[-0xb] = *(undefined4 *)(param_2 + -0x2c);
    param_3[-10] = *(undefined4 *)(param_2 + -0x28);
    param_3[-9] = *(undefined4 *)(param_2 + -0x24);
    FUN_00401660(param_2 + -0x20,0,0xffffffff);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_00459fb0 @ 0x00459fb0 ====

undefined4 * FUN_00459fb0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097c291;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x12) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
      param_3[4] = param_1[4];
      param_3[5] = param_1[5];
      param_3[6] = param_1[6];
      param_3[7] = param_1[7];
      param_3[8] = param_1[8];
      param_3[9] = param_1[9];
      param_3[0x10] = 0xf;
      param_3[0xf] = 0;
      *(undefined1 *)(param_3 + 0xb) = 0;
      FUN_00401660(param_1 + 10,0,0xffffffff);
    }
    param_3 = param_3 + 0x12;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0045a052 @ 0x0045a052 ====

void Catch_0045a052(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (uint *)(iVar2 + 0x40);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x48;
      puVar1 = puVar1 + 0x12;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0045a0b0 @ 0x0045a0b0 ====

undefined4 FUN_0045a0b0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x38e38e3 < param_1) {
    param_1 = FUN_00459bb0();
  }
  pvVar1 = operator_new(param_1 * 0x48);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x48 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_0045a100 @ 0x0045a100 ====

void FUN_0045a100(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004593a0(piVar6[1]);
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
    FUN_00459c20(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0045a1c0 @ 0x0045a1c0 ====

void FUN_0045a1c0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      param_1[2] = param_3[2];
      param_1[4] = param_3[4];
      param_1[5] = param_3[5];
      param_1[6] = param_3[6];
      param_1[7] = param_3[7];
      param_1[8] = param_3[8];
      param_1[9] = param_3[9];
      FUN_00401660(param_3 + 10,0,0xffffffff);
      param_1 = param_1 + 0x12;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0045a230 @ 0x0045a230 ====

void FUN_0045a230(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097c2b1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      param_1[2] = param_3[2];
      param_1[4] = param_3[4];
      param_1[5] = param_3[5];
      param_1[6] = param_3[6];
      param_1[7] = param_3[7];
      param_1[8] = param_3[8];
      param_1[9] = param_3[9];
      param_1[0x10] = 0xf;
      param_1[0xf] = 0;
      *(undefined1 *)(param_1 + 0xb) = 0;
      FUN_00401660(param_3 + 10,0,0xffffffff);
    }
    param_1 = param_1 + 0x12;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0045a2d3 @ 0x0045a2d3 ====

void Catch_0045a2d3(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 8)) {
    puVar1 = (uint *)(iVar2 + 0x40);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x48;
      puVar1 = puVar1 + 0x12;
    } while (iVar2 != *(int *)(unaff_EBP + 8));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0045a320 @ 0x0045a320 ====

void FUN_0045a320(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_0045a330 @ 0x0045a330 ====

void FUN_0045a330(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x48) {
    FUN_00459b20();
  }
  return;
}


// ==== FUN_0045a360 @ 0x0045a360 ====

void FUN_0045a360(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x48) {
    FUN_00459b20();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0045a3b0 @ 0x0045a3b0 ====

void FUN_0045a3b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00459fb0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0045a3d0 @ 0x0045a3d0 ====

void FUN_0045a3d0(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x48) {
    FUN_00459b20();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0045a3e0 @ 0x0045a3e0 ====

void FUN_0045a3e0(int *param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  FUN_00459ed0(param_2 + 0x48,*(undefined4 *)(in_ECX + 8),param_2,param_2);
  iVar1 = *(int *)(in_ECX + 8);
  for (iVar2 = iVar1 + -0x48; iVar2 != iVar1; iVar2 = iVar2 + 0x48) {
    FUN_00459b20();
  }
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x48;
  *param_1 = param_2;
  return;
}


// ==== FUN_0045a430 @ 0x0045a430 ====

int FUN_0045a430(int param_1,int param_2,undefined4 param_3)

{
  FUN_0045a230(param_1,param_2,param_3);
  return param_1 + param_2 * 0x48;
}


// ==== FUN_0045a460 @ 0x0045a460 ====

void FUN_0045a460(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  undefined1 local_64 [2];
  undefined1 auStack_62 [42];
  void *local_38;
  uint local_24;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097c2c8;
  local_10 = ExceptionList;
  local_14 = local_64 + -0xc;
  ExceptionList = &local_10;
  FUN_00459b50(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x48;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x48;
    }
    if (0x38e38e3U - iVar1 < param_2) {
      FUN_00459bb0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x48;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x38e38e3 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x48;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_00868440();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x48);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_00459fb0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0045a230(iVar2,param_2,local_64);
      FUN_00459fb0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x48);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x48;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_0045a330(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x48 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x48);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      if ((uint)((iVar2 - param_1) / 0x48) < param_2) {
        FUN_00459fb0(param_1,iVar2,param_2 * 0x48 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0045a430(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x48,local_64
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x48;
        local_8 = 0;
        FUN_0045a1c0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x48,local_64);
      }
      else {
        iVar1 = iVar2 + param_2 * -0x48;
        uVar4 = FUN_00459fb0(iVar1,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_00459f40(param_1,iVar1,iVar2,iVar1);
        FUN_0045a1c0(param_1,param_2 * 0x48 + param_1,local_64);
      }
    }
  }
  if (local_24 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_38);
  return;
}


// ==== Catch@0045a61e @ 0x0045a61e ====

void Catch_0045a61e(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_0045a330(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0045a6d1 @ 0x0045a6d1 ====

void Catch_0045a6d1(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x48;
  FUN_0045a330(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0045a770 @ 0x0045a770 ====

void FUN_0045a770(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint extraout_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097c2e0;
  local_10 = ExceptionList;
  iVar3 = *(int *)(in_ECX + 4);
  uVar1 = (param_3 - param_2) / 0x48;
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x48;
  }
  if (uVar1 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x48;
    }
    ExceptionList = &local_10;
    if (0x38e38e3U - iVar2 < uVar1) {
      ExceptionList = &local_10;
      FUN_00459bb0();
      uVar6 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x48;
    }
    if (uVar6 < iVar2 + uVar1) {
      if (0x38e38e3 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x48;
      }
      if (uVar6 < iVar3 + uVar1) {
        iVar3 = FUN_00868440();
        uVar6 = iVar3 + uVar1;
      }
      pvVar4 = operator_new(uVar6 * 0x48);
      local_8 = 0;
      uVar5 = FUN_00459fb0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00459fb0(param_2,param_3,uVar5);
      FUN_00459fb0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x48;
      }
      if (*(int *)(in_ECX + 4) == 0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x48 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0x48);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      FUN_0045a330(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x48) < uVar1) {
      FUN_00459fb0(param_1,iVar3,uVar1 * 0x48 + param_1);
      iVar3 = param_2 + ((*(int *)(in_ECX + 8) - param_1) / 0x48) * 0x48;
      local_8 = 2;
      FUN_00459fb0(iVar3,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0x48;
      local_8 = 0xffffffff;
      FUN_00459ed0(param_2,iVar3,param_1,param_2);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0x48;
    uVar5 = FUN_00459fb0(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00459f40(param_1,iVar2,iVar3,param_2);
    FUN_00459ed0(param_2,param_3,param_1,param_2);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0045a93e @ 0x0045a93e ====

void Catch_0045a93e(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_0045a330(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@0045aa0f @ 0x0045aa0f ====

void Catch_0045aa0f(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x14) * 0x48;
  FUN_0045a330(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0045aa90 @ 0x0045aa90 ====

void FUN_0045aa90(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0045a100(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0045aac0 @ 0x0045aac0 ====

void FUN_0045aac0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00459360();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_0045aaf0 @ 0x0045aaf0 ====

void FUN_0045aaf0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x48 != 0) {
      iVar1 = (param_2 - iVar1) / 0x48;
      goto LAB_0045ab35;
    }
  }
  iVar1 = 0;
LAB_0045ab35:
  FUN_0045a460(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x48;
  return;
}


// ==== FUN_0045ab60 @ 0x0045ab60 ====

void FUN_0045ab60(byte param_1)

{
  void *in_ECX;
  
  FUN_00459570();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0045ab80 @ 0x0045ab80 ====

void FUN_0045ab80(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x48) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x48))) {
    FUN_0045aaf0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0045a230(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x48;
  return;
}


// ==== FUN_0045ac10 @ 0x0045ac10 ====

void FUN_0045ac10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0978;
  return;
}


// ==== FUN_0045ac20 @ 0x0045ac20 ====

void FUN_0045ac20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0978;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0045ad20 @ 0x0045ad20 ====

void FUN_0045ad20(undefined4 param_1)

{
  int in_ECX;
  
  switch(param_1) {
  case 0:
    *(undefined4 *)(in_ECX + 0x98) = 0;
    break;
  case 1:
    *(undefined4 *)(in_ECX + 0x98) = 3;
    break;
  case 2:
    *(undefined4 *)(in_ECX + 0x98) = 2;
    break;
  case 3:
    *(undefined4 *)(in_ECX + 0x98) = 1;
  }
  if (*(int *)(in_ECX + 0x14) != 0) {
    _AIL_set_3D_speaker_type_8(*(int *)(in_ECX + 0x14),*(undefined4 *)(in_ECX + 0x98));
  }
  return;
}


// ==== FUN_0045ada0 @ 0x0045ada0 ====

uint FUN_0045ada0(uint param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  uint uVar3;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    return 0;
  }
  uVar3 = 0;
  if (param_1 != 0) {
    piVar2 = (int *)(in_ECX + 0x18);
    do {
      iVar1 = _AIL_allocate_sample_handle_4(*(undefined4 *)(in_ECX + 0xc));
      *piVar2 = iVar1;
      if (iVar1 == 0) {
        return uVar3;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (uVar3 < param_1);
  }
  return param_1;
}


// ==== FUN_0045ae20 @ 0x0045ae20 ====

void FUN_0045ae20(int param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  int *piVar1;
  bool bVar2;
  
  if (param_1 == 2) {
    piVar1 = *(int **)(in_ECX + 0xd4);
    *(undefined4 *)(in_ECX + 0xb0) = param_2;
    if (piVar1 == (int *)0x0) {
      return;
    }
    bVar2 = *(int *)(in_ECX + 0xac) == 2;
  }
  else {
    if (param_1 != 3) {
      return;
    }
    piVar1 = *(int **)(in_ECX + 0xd4);
    *(undefined4 *)(in_ECX + 0xb4) = param_2;
    if (piVar1 == (int *)0x0) {
      return;
    }
    bVar2 = *(int *)(in_ECX + 0xac) == 3;
  }
  if (bVar2) {
    (**(code **)(*piVar1 + 0x2c))(param_2,param_3);
  }
  return;
}


// ==== FUN_0045ae90 @ 0x0045ae90 ====

void FUN_0045ae90(int param_1,int param_2)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0xa0) = param_2;
  *(float *)(in_ECX + 0xa4) = (float)param_1;
  if (param_2 != 0) {
    *(undefined4 *)(in_ECX + 0xa4) = 0;
  }
  return;
}


// ==== FUN_0045aec0 @ 0x0045aec0 ====

void FUN_0045aec0(void)

{
  return;
}


// ==== FUN_0045aed0 @ 0x0045aed0 ====

void FUN_0045aed0(int param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x20))(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 4),0);
  return;
}


// ==== FUN_0045af20 @ 0x0045af20 ====

void FUN_0045af20(void)

{
  int in_ECX;
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(in_ECX + 0x10) != 0) {
    puVar1 = (undefined4 *)(in_ECX + 0x18);
    do {
      _AIL_end_sample_4(*puVar1);
      uVar3 = uVar3 + 1;
      puVar1 = puVar1 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0x10));
  }
  FUN_00462e80();
  waveOutSetVolume((HWAVEOUT)0x0,*(DWORD *)(in_ECX + 0x9c));
  iVar2 = *(int *)(in_ECX + 0x10);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(in_ECX + 0x18);
    do {
      _AIL_release_sample_handle_4(*puVar1);
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_00462e80();
  if (*(undefined4 **)(in_ECX + 0xd4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xd4))(1);
  }
  if (*(int *)(in_ECX + 0xc) != 0) {
    _AIL_close_digital_driver_4(*(int *)(in_ECX + 0xc));
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0045afb7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _AIL_shutdown_0();
  return;
}


// ==== FUN_0045afc0 @ 0x0045afc0 ====

void FUN_0045afc0(undefined4 param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  float10 fVar4;
  
  if (*(int *)(in_ECX + 0xd4) != 0) {
    if (*(int *)(*(int *)(in_ECX + 0xd4) + 0xb8) != 0) {
      FUN_00463d20(param_1);
    }
    if ((*(char *)(*(int *)(in_ECX + 0xd4) + 0xb4) == '\x01') && (*(int *)(in_ECX + 0xac) == 3)) {
      fVar4 = (float10)FUN_00462f00();
      fVar1 = (float)fVar4;
      if (DAT_0099cdc8 < fVar1) {
        if (DAT_0099de78 <= fVar1) {
          FUN_00462e80();
        }
        puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puVar3 != (undefined4 *)0x0) {
          uVar2 = *(undefined4 *)(in_ECX + 0xac);
          *puVar3 = &PTR_FUN_009a09a8;
          puVar3[1] = uVar2;
          puVar3[2] = fVar1;
          FUN_00797a20(puVar3);
          return;
        }
        FUN_00797a20(0);
      }
    }
  }
  return;
}


// ==== FUN_0045b080 @ 0x0045b080 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045b080(int param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int in_ECX;
  float10 fVar5;
  float fVar6;
  float local_40;
  float local_3c;
  float fStack_38;
  float fStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  undefined4 uStack_18;
  float fStack_14;
  undefined4 uStack_10;
  float fStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  fVar6 = DAT_0099d0b4;
  local_3c = DAT_0099d0b4;
  local_40 = 0.0;
  if (((*(float *)(param_1 + 0x20) == 0.0) && (*(float *)(param_1 + 0x24) == 0.0)) &&
     (*(float *)(param_1 + 0x28) == 0.0)) {
    local_40 = *(float *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else {
    iVar2 = (**(code **)(*DAT_00b5a988 + 0x14))();
    fStack_c = *(float *)(iVar2 + 0x28);
    uStack_8 = *(undefined4 *)(iVar2 + 0x2c);
    fStack_4 = *(float *)(iVar2 + 0x30);
    if (DAT_00b5a97c == (int *)0x0) {
      iVar2 = (**(code **)(*DAT_00b5a988 + 0x14))();
      *(undefined4 *)(in_ECX + 0x110) = *(undefined4 *)(iVar2 + 0x34);
      *(undefined4 *)(in_ECX + 0x114) = *(undefined4 *)(iVar2 + 0x38);
      *(undefined4 *)(in_ECX + 0x118) = *(undefined4 *)(iVar2 + 0x3c);
    }
    else {
      piVar3 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x28))();
      uStack_30 = *puVar4;
      uStack_2c = puVar4[1];
      piVar3 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      uStack_18 = uStack_30;
      fVar5 = (float10)(**(code **)(*piVar3 + 0x30))();
      fStack_14 = (float)fVar5;
      *(undefined4 *)(in_ECX + 0x110) = uStack_18;
      uStack_10 = uStack_2c;
      *(float *)(in_ECX + 0x114) = fStack_14;
      *(undefined4 *)(in_ECX + 0x118) = uStack_2c;
    }
    fStack_28 = *(float *)(in_ECX + 0x110) - fStack_c;
    fStack_24 = *(float *)(in_ECX + 0x118) - fStack_4;
    fVar5 = (float10)FUN_0040d5f0(&fStack_28);
    FUN_0040d600(&fStack_20,(float)(fVar5 + (float10)_DAT_00ae0288));
    fStack_34 = *(float *)(in_ECX + 0x118) - *(float *)(param_1 + 0x28);
    fStack_38 = *(float *)(in_ECX + 0x110) - *(float *)(param_1 + 0x20);
    fVar1 = SQRT(fStack_38 * fStack_38 + fStack_34 * fStack_34);
    *(float *)(param_1 + 0x18) = fVar1;
    if (fVar1 < *(float *)(param_1 + 0x14)) {
      if (fVar1 < DAT_009a09bc) {
        thunk_FUN_0079de77(&fStack_38,&fStack_38);
        fVar6 = fStack_1c * fStack_34 + fStack_20 * fStack_38;
      }
      local_40 = ((*(float *)(param_1 + 0x14) - *(float *)(param_1 + 0x18)) /
                 *(float *)(param_1 + 0x14)) * *(float *)(param_1 + 0x10);
      if (local_40 < 0.0) {
        local_40 = 0.0;
      }
    }
    local_3c = (fVar6 + DAT_0099d080) * DAT_0099d0b4;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    if (*(int *)(param_1 + 8) != 0) {
      fVar6 = (float)*(int *)(param_1 + 4);
      if (*(int *)(param_1 + 4) < 0) {
        fVar6 = fVar6 + _DAT_0099d104;
      }
      local_40 = fVar6 * DAT_0099d0ec * local_40;
      if (local_40 == DAT_0099cdc8) {
        *(undefined4 *)(param_1 + 4) = 0;
      }
    }
    FUN_00464140(*(float *)(in_ECX + 0xa4) * DAT_009a09b8,local_40,local_3c);
  }
  return;
}


// ==== FUN_0045b340 @ 0x0045b340 ====

undefined4 FUN_0045b340(int param_1,uint param_2,uint param_3,byte param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x48) + 0x88) + 0x40) != 0) {
    cVar1 = FUN_00464110();
    if (cVar1 == '\0') {
      if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_1 + 0xc) != 0)) {
        return 1;
      }
    }
    else {
      if ((*(int *)(param_1 + 8) != 0) && (*(uint *)(param_1 + 4) <= param_3)) {
        return 1;
      }
      if ((2 < param_2) &&
         ((fVar4 = (float10)(**(code **)(**(int **)(param_1 + 0x48) + 0x18))(),
          (float10)DAT_0099cdc8 == fVar4 || (2 < param_4)))) {
        FUN_00464070();
        return 0;
      }
      uVar2 = (**(code **)(*in_ECX + 0xc))();
      iVar3 = _AIL_active_sample_count_4(uVar2);
      if (((iVar3 == 0x20) && (*(char *)((*(int **)(param_1 + 0x48))[0x22] + 0x4c) != '\0')) &&
         (fVar4 = (float10)(**(code **)(**(int **)(param_1 + 0x48) + 0x18))(),
         (float10)DAT_0099cdc8 == fVar4)) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_0045b460 @ 0x0045b460 ====

void FUN_0045b460(void)

{
  int in_ECX;
  
  if (*(float *)(in_ECX + 0xb0) != DAT_0099cdc8) {
    FUN_00401660(in_ECX + 0xb8,0,0xffffffff);
    FUN_00463810();
  }
  return;
}


// ==== FUN_0045b4c0 @ 0x0045b4c0 ====

undefined1 FUN_0045b4c0(int param_1,undefined4 param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c2fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(0xb0);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00464260();
  }
  *(undefined4 *)(param_1 + 0x48) = uVar3;
  local_4 = 0xffffffff;
  FUN_00401660(param_2,0,0xffffffff);
  cVar1 = FUN_004642f0();
  if (cVar1 == '\0') {
    ExceptionList = local_c;
    return 0;
  }
  FUN_0045b080();
  (**(code **)(**(int **)(param_1 + 0x48) + 0x1c))();
  ExceptionList = pvVar2;
  return 1;
}


// ==== FUN_0045b590 @ 0x0045b590 ====

void FUN_0045b590(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c30d;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) == *(int *)(in_ECX + 0xac)) {
    ExceptionList = &local_c;
    uVar1 = FUN_0045d200(local_28);
    local_4 = 0;
    FUN_00401660(uVar1,0,0xffffffff);
    local_4 = 0xffffffff;
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    if (*(int *)(in_ECX + 0xd4) != 0) {
      FUN_00462ea0();
    }
    *(undefined4 *)(in_ECX + 0xac) = 2;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0045b640 @ 0x0045b640 ====

void FUN_0045b640(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_74 [16];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 local_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 local_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c336;
  pvStack_c = ExceptionList;
  uStack_60 = 0x45b66e;
  ExceptionList = &pvStack_c;
  FUN_0045d1d0();
  local_4 = 0;
  uStack_60 = 0x45b680;
  FUN_0045d200();
  uVar1 = *(undefined4 *)(param_1 + 4);
  local_4._0_1_ = 1;
  FUN_00405bd0(auStack_74,local_44);
  FUN_00463240();
  iVar2 = (**(code **)(*DAT_00b5a6a8 + 4))();
  local_4._0_1_ = 2;
  if (iVar2 != 0) {
    uStack_60 = 0xf;
    uStack_64 = 0;
    auStack_74[0] = 0;
    FUN_00401660(local_28,0,0xffffffff);
    FUN_0045d230(uVar1);
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  uStack_60 = 0x45b707;
  FUN_00797a20();
  if (0xf < uStack_2c) {
    uStack_60 = 0x45b71f;
    _free(pvStack_40);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (uStack_10 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  uStack_60 = 0x45b742;
  _free(pvStack_24);
  return;
}


// ==== FUN_0045b760 @ 0x0045b760 ====

void FUN_0045b760(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c348;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 0xc) != 0) {
    ExceptionList = &local_c;
    uVar1 = FUN_0045d200(local_28);
    local_4 = 0;
    FUN_00401660(uVar1,0,0xffffffff);
    local_4 = 0xffffffff;
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    if (*(undefined4 **)(in_ECX + 0xd4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0xd4))(1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0045b800 @ 0x0045b800 ====

void FUN_0045b800(undefined1 param_1,void *param_2)

{
  int iVar1;
  uint in_stack_0000001c;
  undefined4 *in_stack_00000020;
  undefined4 uStack_40;
  uint local_3c;
  undefined1 uStack_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097c371;
  pvStack_c = ExceptionList;
  uStack_24 = in_stack_00000020;
  in_stack_00000020 = &uStack_40;
  local_28 = 0xf;
  local_2c = 0;
  local_4 = 0;
  local_3c = local_3c & 0xffffff00;
  ExceptionList = &pvStack_c;
  FUN_00401660();
  local_4._0_1_ = 1;
  FUN_00401660(&param_1,0,0xffffffff);
  local_4 = (uint)local_4._1_3_ << 8;
  iVar1 = FUN_00463a30();
  if (iVar1 == 0) {
    in_stack_00000020 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    local_4._0_1_ = 2;
    if (in_stack_00000020 != (undefined4 *)0x0) {
      local_3c = 0xffffffff;
      uStack_40 = 0;
      uStack_24 = 0;
      uStack_34 = 0;
      FUN_00401660();
      local_3c = 0x45b8cd;
      FUN_0045d330();
    }
    local_4 = (uint)local_4._1_3_ << 8;
    uStack_24 = 0x45b8db;
    FUN_00797a20();
  }
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  uStack_24 = 0x45b8ef;
  _free(param_2);
  return;
}


// ==== FUN_0045b910 @ 0x0045b910 ====

void FUN_0045b910(int param_1)

{
  int *piVar1;
  void **ppvVar2;
  int iVar3;
  HWND pHVar4;
  int iVar5;
  undefined4 uVar6;
  int *in_ECX;
  void *unaff_EBX;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  UINT UVar10;
  void *pvStack_98;
  uint uStack_8c;
  uint uStack_84;
  void *pvStack_78;
  void *pvStack_68;
  uint uStack_64;
  uint uStack_54;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097c3b1;
  local_c = ExceptionList;
  if ((in_ECX[3] != 0) && (*(int *)(*(int *)(*(int *)(param_1 + 0x48) + 0x88) + 0x40) != 0)) {
    uVar7 = 0;
    ExceptionList = &local_c;
    ppvVar2 = &local_c;
    if (in_ECX[4] != 0) {
      do {
        ExceptionList = ppvVar2;
        iVar3 = _AIL_sample_status_4();
        if (iVar3 == 2) {
          _AIL_init_sample_4();
          FUN_0045d080();
          puStack_8 = (undefined1 *)0x0;
          iVar3 = FUN_00403620();
          puStack_8 = (undefined1 *)0xffffffff;
          if (0xf < uStack_84) {
            _free(pvStack_98);
            return;
          }
          if (iVar3 == 0) {
            (**(code **)(**(int **)(param_1 + 0x48) + 8))();
            local_c = (void *)0x1;
            (**(code **)(**(int **)(param_1 + 0x48) + 0xc))();
            uStack_10._0_1_ = 2;
            FUN_00405bd0();
            if (0xf < uStack_54) {
              _free(pvStack_68);
              return;
            }
            uStack_10 = CONCAT31(uStack_10._1_3_,4);
            if (0xf < uStack_8c) {
              _free(unaff_EBX);
              return;
            }
            (**(code **)(**(int **)(*(int *)(param_1 + 0x48) + 0x88) + 4))();
            iVar3 = _AIL_set_named_sample_file_20();
            if (iVar3 == 0) {
              UVar10 = 0x30;
              pcVar9 = s_Fatal_Error_009a082c;
              pcVar8 = s_Sorry__no_ASI_provider_available_009a0838;
              pHVar4 = GetForegroundWindow();
              MessageBoxA(pHVar4,pcVar8,pcVar9,UVar10);
              if (uStack_64 < 0x10) {
                ExceptionList = local_c;
                return;
              }
              pvStack_24 = pvStack_78;
              goto LAB_0045bcbf;
            }
            uStack_4 = 0xffffffff;
            if (0xf < uStack_64) {
              _free(pvStack_78);
              return;
            }
          }
          else {
            iVar3 = _AIL_set_sample_file_12();
            if (iVar3 == 0) {
              UVar10 = 0x30;
              pcVar9 = s_Fatal_Error_009a0870;
              pcVar8 = s_Sorry__no_ASI_provider_available_009a087c;
              pHVar4 = GetForegroundWindow();
              MessageBoxA(pHVar4,pcVar8,pcVar9,UVar10);
              ExceptionList = local_c;
              return;
            }
          }
          piVar1 = *(int **)(param_1 + 0x48);
          (**(code **)(*in_ECX + 0x18))();
          (**(code **)(*piVar1 + 0x18))();
          _AIL_set_sample_volume_pan_12();
          _AIL_sample_playback_rate_4();
          _AIL_set_sample_user_data_12();
          iVar3 = (**(code **)(*in_ECX + 0x10))();
          iVar5 = _AIL_sample_user_data_8(in_ECX[uVar7 + 6]);
          iVar5 = iVar5 * (iVar3 + 1);
          _AIL_set_sample_playback_rate_8
                    (in_ECX[uVar7 + 6],(int)(iVar5 + (iVar5 >> 0x1f & 0x3fU)) >> 6);
          uVar6 = (**(code **)(**(int **)(param_1 + 0x48) + 4))();
          _AIL_set_sample_loop_count_8(in_ECX[uVar7 + 6],uVar6);
          _AIL_start_sample_4(in_ECX[uVar7 + 6]);
          iVar3 = *(int *)(param_1 + 0x48);
          *(int *)(iVar3 + 0x80) = in_ECX[uVar7 + 6];
          *(uint *)(iVar3 + 0xa8) = uVar7;
          break;
        }
        uVar7 = uVar7 + 1;
        ppvVar2 = ExceptionList;
      } while (uVar7 < (uint)in_ECX[4]);
    }
    if ((uint)in_ECX[4] < uVar7) {
      (**(code **)(**(int **)(param_1 + 0x48) + 8))();
      uStack_4 = 6;
      FUN_00401740(s_Sound_Max___No_play__s_009a08b4,0x17);
      uVar6 = FUN_00404230(auStack_44);
      uStack_4 = CONCAT31(uStack_4._1_3_,7);
      FUN_00796d50(uVar6);
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return;
      }
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      if (0xf < uStack_10) {
LAB_0045bcbf:
        _free(pvStack_24);
        return;
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0045bcf0 @ 0x0045bcf0 ====

void FUN_0045bcf0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  undefined1 local_44 [4];
  void *local_40;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c3cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar2 = FUN_0045d200(local_28);
  local_4 = 0;
  FUN_00404650(local_44,uVar2);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_0041ec50(&param_1,local_44);
  if (param_1 != *(int *)(in_ECX + 0xf0)) {
    piVar3 = *(int **)(param_1 + 0x28);
    if (piVar3 != *(int **)(param_1 + 0x2c)) {
      do {
        if (*piVar3 == *(int *)(iVar1 + 4)) {
          piVar3[8] = *(int *)(iVar1 + 0x24);
          piVar3[9] = *(int *)(iVar1 + 0x28);
          piVar3[10] = *(int *)(iVar1 + 0x2c);
          break;
        }
        piVar3 = piVar3 + 0x13;
      } while (piVar3 != *(int **)(param_1 + 0x2c));
    }
  }
  if (local_2c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_40);
  return;
}


// ==== FUN_0045bdf0 @ 0x0045bdf0 ====

void FUN_0045bdf0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  uint *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int *in_ECX;
  uint uVar11;
  int iVar12;
  float10 fVar13;
  uint *puStack_d4;
  undefined1 auStack_d0 [4];
  undefined1 uStack_cc;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 uStack_b8;
  undefined1 **ppuStack_b0;
  undefined1 *apuStack_8c [2];
  void *local_84;
  undefined4 local_74;
  uint local_70;
  undefined1 auStack_6c [4];
  void *pvStack_68;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined4 uStack_3c;
  uint auStack_38 [2];
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0097c405;
  pvStack_14 = ExceptionList;
  _ppuStack_b0 = 4.98753884161199e-317;
  local_70 = 0xf;
  local_74 = 0;
  local_84 = (void *)((uint)local_84 & 0xffffff00);
  uStack_b8 = (double)CONCAT44(0x45be3d,(undefined4)uStack_b8);
  ExceptionList = &pvStack_14;
  FUN_00401740();
  puVar1 = (undefined4 *)in_ECX[0x3c];
  puVar2 = (undefined4 *)*puVar1;
  local_c = 0;
  for (; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar3 = puVar2[0xb];
    iVar12 = puVar2[10];
    _ppuStack_b0 = (double)CONCAT44(0x45be75,ppuStack_b0);
    piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    _ppuStack_b0 = (double)CONCAT44(0x45be7c,ppuStack_b0);
    puVar6 = (uint *)(**(code **)(*piVar5 + 0x1c))();
    if (1 < *puVar6) {
      if (puVar2[10] == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = (int)(puVar2[0xb] - puVar2[10]) / 0x4c;
      }
      if ((uint)puVar2[8] < 0x10) {
        puVar8 = puVar2 + 3;
      }
      else {
        puVar8 = (undefined4 *)puVar2[3];
      }
      _ppuStack_b0 = (double)CONCAT44(iVar7,puVar8);
      apuStack_8c[0] = auStack_d0;
      puStack_d4 = (uint *)0x10;
      uStack_b8 = (double)CONCAT44(*(undefined4 *)(*(int *)(iVar12 + 0x48) + 0xa8),0xf);
      uStack_bc = 0;
      uStack_cc = 0;
      FUN_00401740(s___d_____s____d___009a092c);
      puStack_d4 = (uint *)auStack_6c;
      uVar9 = FUN_00404230();
      _ppuStack_b0 = -NAN;
      local_c._0_1_ = 1;
      uStack_b8 = (double)CONCAT44(uVar9,0x45bf07);
      FUN_00401ff0();
      local_c = (uint)local_c._1_3_ << 8;
      if (0xf < uStack_54) {
        _ppuStack_b0 = (double)CONCAT44(pvStack_68,0x45bf1e);
        _free(pvStack_68);
        return;
      }
      uStack_54 = 0xf;
      uStack_58 = 0;
      pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
    }
    for (uVar11 = 0; (iVar12 != iVar3 && (uVar11 < 3)); uVar11 = uVar11 + 1) {
      _ppuStack_b0 = (double)CONCAT44(0x45bf54,ppuStack_b0);
      piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
      _ppuStack_b0 = (double)CONCAT44(0x45bf5b,ppuStack_b0);
      puVar6 = (uint *)(**(code **)(*piVar5 + 0x1c))();
      if (1 < *puVar6) {
        _ppuStack_b0 = (double)CONCAT44(0x45bf6c,ppuStack_b0);
        fVar13 = (float10)(**(code **)(**(int **)(iVar12 + 0x48) + 0x18))();
        apuStack_8c[0] = (undefined1 *)&puStack_d4;
        _ppuStack_b0 = (double)fVar13;
        uStack_b8 = (double)*(float *)(iVar12 + 0x18);
        uStack_bc = 0xf;
        uStack_c0 = 0;
        auStack_d0[0] = 0;
        FUN_00401740(s_volume___2f___2f___009a0940,0x12);
        uVar9 = FUN_00404230(auStack_50);
        _ppuStack_b0 = -NAN;
        local_c._0_1_ = 2;
        uStack_b8 = (double)CONCAT44(uVar9,0x45bfbe);
        FUN_00401ff0();
        local_c = (uint)local_c._1_3_ << 8;
        if (0xf < auStack_38[0]) {
          _ppuStack_b0 = (double)CONCAT44(pvStack_4c,0x45bfd6);
          _free(pvStack_4c);
          return;
        }
        auStack_38[0] = 0xf;
        uStack_3c = 0;
        pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
      }
      _ppuStack_b0 = (double)CONCAT44(0x45bff1,ppuStack_b0);
      cVar4 = FUN_00464110();
      if (cVar4 == '\0') {
        _ppuStack_b0 = (double)CONCAT44(0x45bffd,ppuStack_b0);
        fVar13 = (float10)(**(code **)(**(int **)(iVar12 + 0x48) + 0x18))();
        if ((float10)DAT_0099cdc8 != fVar13) {
          if ((*(int *)(iVar12 + 0x1c) == 0) || (*(int *)(iVar12 + 0xc) == 0)) {
            _ppuStack_b0 = (double)CONCAT44(iVar12,0x45c02d);
            FUN_0045b910();
            _ppuStack_b0 = (double)CONCAT44(0x45c035,ppuStack_b0);
            cVar4 = FUN_00464110();
            if (cVar4 != '\0') {
              *(undefined4 *)(iVar12 + 0xc) = 1;
            }
          }
          else {
            *(undefined4 *)(iVar12 + 4) = 0;
            *(undefined4 *)(iVar12 + 8) = 1;
          }
        }
      }
      iVar12 = iVar12 + 0x4c;
    }
  }
  _ppuStack_b0 = (double)CONCAT44(0x45c070,ppuStack_b0);
  piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  _ppuStack_b0 = (double)CONCAT44(0x45c077,ppuStack_b0);
  puVar6 = (uint *)(**(code **)(*piVar5 + 0x1c))();
  if (1 < *puVar6) {
    _ppuStack_b0 = (double)CONCAT44(0x45c087,ppuStack_b0);
    uVar10 = (**(code **)(*in_ECX + 0xc))();
    ppuStack_b0 = (undefined1 **)0x45c08e;
    uVar9 = _AIL_active_sample_count_4();
    ppuStack_b0 = (undefined1 **)0x9;
    uStack_58 = 0xf;
    uStack_5c = 0;
    auStack_6c[0] = 0;
    uStack_b8 = 9.269366528548375e-306;
    FUN_00401740();
    ppuStack_b0 = apuStack_8c;
    puStack_d4 = (uint *)0xd;
    uStack_b8 = (double)CONCAT44(uVar9,0xf);
    uStack_bc = 0;
    puStack_10._0_1_ = 3;
    uStack_cc = 0;
    FUN_00401740(s_Total_____d___009a0954);
    puStack_d4 = auStack_38;
    uVar9 = FUN_00404230();
    uStack_b8 = (double)CONCAT44(uVar9,&uStack_54);
    puStack_10._0_1_ = 4;
    uStack_bc = 0x45c0fb;
    uVar9 = FUN_00405bd0();
    _ppuStack_b0 = (double)CONCAT44(uVar10,uVar9);
    puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,5);
    uStack_b8 = (double)CONCAT44(&local_70,0x45c117);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < auStack_38[0]) {
      _ppuStack_b0 = (double)CONCAT44(pvStack_4c,0x45c12c);
      _free(pvStack_4c);
      return;
    }
    auStack_38[0] = 0xf;
    uStack_3c = 0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    if (0xf < uStack_1c) {
      _ppuStack_b0 = (double)CONCAT44(pvStack_30,0x45c14e);
      _free(pvStack_30);
      return;
    }
    uStack_1c = 0xf;
    uStack_20 = 0;
    pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
    if (0xf < uStack_54) {
      _ppuStack_b0 = (double)CONCAT44(pvStack_68,0x45c173);
      _free(pvStack_68);
      return;
    }
  }
  if (local_70 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  _ppuStack_b0 = (double)CONCAT44(local_84,0x45c18d);
  _free(local_84);
  return;
}


// ==== FUN_0045c1b0 @ 0x0045c1b0 ====

void FUN_0045c1b0(int param_1)

{
  int in_ECX;
  undefined1 auStack_54 [20];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c417;
  local_c = ExceptionList;
  uStack_38 = 0x45c1dc;
  ExceptionList = &local_c;
  uStack_3c = FUN_0045d170();
  uStack_38 = 0;
  local_4 = 0;
  uStack_40 = 0x45c1f4;
  FUN_00401660();
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    uStack_38 = 0x45c20d;
    _free(local_24);
    return;
  }
  if (*(int *)(param_1 + 4) == 2) {
    if (*(int *)(in_ECX + 0xac) != 3) {
      *(undefined4 *)(in_ECX + 0xac) = 2;
      uStack_38 = *(undefined4 *)(param_1 + 8);
      uStack_3c = 0x45c293;
      FUN_0045b460();
    }
  }
  else if (*(int *)(param_1 + 4) == 3) {
    *(undefined4 *)(in_ECX + 0xac) = 3;
    uStack_38 = *(undefined4 *)(param_1 + 8);
    FUN_0045d1a0(auStack_54);
    FUN_0045b800();
    ExceptionList = local_c;
    return;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0045c2b0 @ 0x0045c2b0 ====

void FUN_0045c2b0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  int *piVar4;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097c42c;
  local_c = ExceptionList;
  uVar3 = 0;
  if (*(int *)(in_ECX + 4) == 0) {
    ExceptionList = &local_c;
    iVar1 = (**(code **)(*DAT_00b5a6e4 + 8))();
    *(undefined4 *)(in_ECX + 0xa0) = 0;
    *(undefined4 *)(in_ECX + 0xa4) = *(undefined4 *)(iVar1 + 0x18);
    *(undefined4 *)(in_ECX + 0xac) = 2;
    *(float *)(in_ECX + 0xb0) = *(float *)(iVar1 + 0x14) * DAT_009a09b8;
    waveOutGetVolume((HWAVEOUT)0x0,(LPDWORD)(in_ECX + 0x9c));
    _AIL_set_redist_directory_4(s___redist_009a081c);
    _AIL_startup_0();
    iVar1 = _AIL_open_digital_driver_16(0xac44,0x10,2,0);
    *(int *)(in_ECX + 0xc) = iVar1;
    if (iVar1 != 0) {
      piVar4 = (int *)(in_ECX + 0x18);
      do {
        iVar1 = _AIL_allocate_sample_handle_4(*(undefined4 *)(in_ECX + 0xc));
        *piVar4 = iVar1;
        if (iVar1 == 0) goto LAB_0045c36d;
        uVar3 = uVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar3 < 0x20);
      uVar3 = 0x20;
    }
LAB_0045c36d:
    *(uint *)(in_ECX + 0x10) = uVar3;
    FUN_0045ad20(*(undefined4 *)(in_ECX + 0x98));
    *(undefined4 *)(in_ECX + 4) = 1;
    FUN_0045efd0();
    pvStack_10 = *(void **)(in_ECX + 0xf0);
    FUN_0045e2e0(9,&pvStack_10);
    *(undefined4 *)(in_ECX + 0x108) = 1;
    *(undefined4 *)(in_ECX + 0x10c) = 1;
    pvStack_10 = operator_new(0xec);
    uStack_4 = 0;
    if (pvStack_10 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00463190(in_ECX);
    }
    *(undefined4 *)(in_ECX + 0xd4) = uVar2;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0045c400 @ 0x0045c400 ====

/* WARNING: Removing unreachable block (ram,0x0045c4e2) */

void FUN_0045c400(void)

{
  int iVar1;
  undefined4 *puVar2;
  void *_Memory;
  int in_ECX;
  int iVar3;
  int *piVar4;
  int *local_4;
  
  local_4 = *(int **)(in_ECX + 0xf0);
  piVar4 = (int *)*local_4;
  if (piVar4 != local_4) {
    do {
      iVar1 = piVar4[0xb];
      for (iVar3 = piVar4[10]; iVar3 != iVar1; iVar3 = iVar3 + 0x4c) {
        if (*(undefined4 **)(iVar3 + 0x48) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(iVar3 + 0x48))(1);
        }
        *(undefined4 *)(iVar3 + 0x48) = 0;
      }
      iVar3 = piVar4[10];
      if (iVar3 != 0) {
        iVar1 = piVar4[0xb];
        for (; iVar3 != iVar1; iVar3 = iVar3 + 0x4c) {
          FUN_0045d050();
        }
        _free((void *)piVar4[10]);
        return;
      }
      piVar4[10] = 0;
      piVar4[0xb] = 0;
      piVar4[0xc] = 0;
      piVar4 = (int *)*piVar4;
    } while (piVar4 != local_4);
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xf0);
  _Memory = (void *)*puVar2;
  *puVar2 = puVar2;
  *(int *)(*(int *)(in_ECX + 0xf0) + 4) = *(int *)(in_ECX + 0xf0);
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  if (_Memory != *(void **)(in_ECX + 0xf0)) {
    FUN_0045ecd0();
    _free(_Memory);
    return;
  }
  local_4 = *(int **)(in_ECX + 0xf0);
  if (*(int *)(in_ECX + 0xfc) != *(int *)(in_ECX + 0x100)) {
    *(int *)(in_ECX + 0x100) = *(int *)(in_ECX + 0xfc);
  }
  FUN_0045db70(*(undefined4 *)(in_ECX + 0xfc),9,&local_4);
  *(undefined4 *)(in_ECX + 0x108) = 1;
  *(undefined4 *)(in_ECX + 0x10c) = 1;
  return;
}


// ==== FUN_0045c520 @ 0x0045c520 ====

void FUN_0045c520(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piVar4;
  float10 fVar5;
  int local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c446;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar3 = FUN_0045d200(local_44);
  local_4 = 0;
  FUN_00404650(local_28,uVar3);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_0041ec50(&param_1,local_28);
  iVar2 = param_1;
  if (param_1 != *(int *)(in_ECX + 0xf0)) {
    piVar4 = *(int **)(param_1 + 0x28);
    if (piVar4 != *(int **)(param_1 + 0x2c)) {
      do {
        if (*piVar4 == *(int *)(iVar1 + 4)) {
          fVar5 = (float10)(**(code **)(*(int *)piVar4[0x12] + 0x18))();
          if ((float10)DAT_0099cdc8 == fVar5) {
            if ((undefined4 *)piVar4[0x12] != (undefined4 *)0x0) {
              (*(code *)**(undefined4 **)piVar4[0x12])(1);
            }
            piVar4[0x12] = 0;
            FUN_0045e4b0(&local_48,piVar4);
          }
          else {
            piVar4[1] = 1000;
            piVar4[2] = 1;
          }
          break;
        }
        piVar4 = piVar4 + 0x13;
      } while (piVar4 != *(int **)(param_1 + 0x2c));
    }
    iVar1 = *(int *)(iVar2 + 0x28);
    if ((iVar1 == 0) || (local_48 = (*(int *)(iVar2 + 0x2c) - iVar1) / 0x4c, local_48 == 0)) {
      FUN_0045f010(&param_1,param_1);
    }
  }
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_0045c690 @ 0x0045c690 ====

void FUN_0045c690(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint local_10;
  undefined1 local_4 [4];
  
  if (*(int *)(in_ECX + 0xf4) != 0) {
    piVar6 = (int *)**(int **)(in_ECX + 0xf0);
    if (piVar6 != *(int **)(in_ECX + 0xf0)) {
      do {
        iVar5 = piVar6[10];
        if ((iVar5 != 0) && (iVar4 = piVar6[0xb], 2 < (uint)((iVar4 - iVar5) / 0x4c))) {
          FUN_0045ee80(iVar5,iVar4,(iVar4 - iVar5) / 0x4c,&LAB_0045ac40);
        }
        iVar5 = piVar6[10];
        local_10 = local_10 & 0xffffff00;
        if (iVar5 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = (piVar6[0xb] - iVar5) / 0x4c;
        }
        if (iVar5 != piVar6[0xb]) {
          do {
            FUN_0045b080(iVar5);
            if ((*(int *)(iVar5 + 8) != 0) && (param_1 < *(uint *)(iVar5 + 4))) {
              *(uint *)(iVar5 + 4) = *(uint *)(iVar5 + 4) - param_1;
            }
            iVar2 = FUN_0045b340(iVar5,iVar4,param_1,local_10);
            if (iVar2 == 0) {
              local_10 = CONCAT31(local_10._1_3_,(char)local_10 + '\x01');
              iVar5 = iVar5 + 0x4c;
            }
            else {
              if (piVar6[10] == 0) {
                iVar4 = 0;
              }
              else {
                iVar4 = (piVar6[0xb] - piVar6[10]) / 0x4c;
              }
              if (*(undefined4 **)(iVar5 + 0x48) != (undefined4 *)0x0) {
                (**(code **)**(undefined4 **)(iVar5 + 0x48))(1);
              }
              *(undefined4 *)(iVar5 + 0x48) = 0;
              FUN_0045d5b0(iVar5 + 0x4c,piVar6[0xb],iVar5,param_1);
              iVar1 = piVar6[0xb];
              for (iVar2 = iVar1 + -0x4c; iVar2 != iVar1; iVar2 = iVar2 + 0x4c) {
                FUN_0045d050();
              }
              piVar6[0xb] = piVar6[0xb] + -0x4c;
            }
          } while (iVar5 != piVar6[0xb]);
        }
        if ((piVar6[10] == 0) || ((piVar6[0xb] - piVar6[10]) / 0x4c == 0)) {
          puVar3 = (undefined4 *)FUN_0045f010(local_4,piVar6);
          piVar6 = (int *)*puVar3;
        }
        else {
          piVar6 = (int *)*piVar6;
        }
      } while (piVar6 != *(undefined4 **)(in_ECX + 0xf0));
    }
    FUN_0045bdf0(param_1);
  }
  return;
}


// ==== FUN_0045c850 @ 0x0045c850 ====

void FUN_0045c850(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c482;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a09ec;
  local_4 = 3;
  FUN_0045c400();
  FUN_0045af20();
  if ((void *)in_ECX[0x3f] == (void *)0x0) {
    in_ECX[0x3f] = 0;
    in_ECX[0x40] = 0;
    in_ECX[0x41] = 0;
    FUN_0045efd0();
    _free((void *)in_ECX[0x3c]);
    return;
  }
  _free((void *)in_ECX[0x3f]);
  return;
}


// ==== FUN_0045c950 @ 0x0045c950 ====

void FUN_0045c950(int param_1)

{
  FUN_0045c690(*(undefined4 *)(param_1 + 4));
  FUN_0045afc0(*(undefined4 *)(param_1 + 4));
  return;
}


// ==== FUN_0045c980 @ 0x0045c980 ====

void FUN_0045c980(void)

{
  undefined4 *in_ECX;
  undefined1 local_11 [5];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c4be;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a09ec;
  in_ECX[0x34] = 0xf;
  in_ECX[0x33] = 0;
  *(undefined1 *)(in_ECX + 0x2f) = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  local_4 = 2;
  FUN_0045f0c0(local_11,local_11);
  local_4 = CONCAT31(local_4._1_3_,3);
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[5] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[2] = 0x40;
  in_ECX[0x26] = 0;
  FUN_00403ea0(in_ECX + 0x28,0,8);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0045ca40 @ 0x0045ca40 ====

void FUN_0045ca40(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  int *piVar5;
  undefined1 auStack_11c [16];
  undefined4 uStack_10c;
  undefined1 *puStack_108;
  undefined1 **ppuStack_104;
  int local_ec;
  undefined1 local_e8 [4];
  void *local_e4;
  undefined4 local_d4;
  uint local_d0;
  int local_cc;
  undefined1 local_c8 [4];
  void *local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b4;
  uint local_b0;
  undefined1 *local_ac [2];
  undefined1 local_a4 [4];
  void *local_a0;
  int local_90;
  uint local_8c;
  int *local_88;
  undefined1 *local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  void *local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  void *local_34;
  uint local_20;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c51d;
  local_c = ExceptionList;
  ppuStack_104 = (undefined1 **)0x45ca74;
  ExceptionList = &local_c;
  FUN_0045d0c0();
  ppuStack_104 = (undefined1 **)local_e8;
  local_4 = 0;
  puStack_108 = (undefined1 *)0x45ca8c;
  FUN_00404650();
  local_cc = *(int *)(param_1 + 8);
  local_4._0_1_ = 1;
  if (local_90 == 0) {
    ppuStack_104 = (undefined1 **)s_Sound_File_Empty_009a08cc;
    local_b0 = 0xf;
    local_b4 = 0;
    local_c4 = (void *)((uint)local_c4 & 0xffffff00);
    puStack_108 = (undefined1 *)0x45cac9;
    FUN_00401740();
    local_4._0_1_ = 2;
    ppuStack_104 = (undefined1 **)0x45cadb;
    FUN_00796d50();
    if (0xf < local_b0) {
      ppuStack_104 = (undefined1 **)0x45caf3;
      _free(local_c4);
      return;
    }
    if (0xf < local_d0) {
      ppuStack_104 = (undefined1 **)0x45cb06;
      _free(local_e4);
      return;
    }
    if (local_8c < 0x10) {
      ExceptionList = local_c;
      return;
    }
  }
  else {
    ppuStack_104 = (undefined1 **)&local_ec;
    local_ac[0] = (undefined1 *)(in_ECX + 0xe8);
    puStack_108 = (undefined1 *)0x45cb42;
    FUN_0041ec50();
    if ((local_ec != *(int *)(in_ECX + 0xf0)) &&
       (local_88 = *(int **)(local_ec + 0x28), local_88 != (int *)0x0)) {
      iVar4 = *(int *)(local_ec + 0x2c) - (int)local_88;
      iVar1 = iVar4 >> 0x1f;
      iVar4 = iVar4 / 0x4c + iVar1;
      if (iVar4 != iVar1) {
        if ((*(char *)(*(int *)(local_88[0x12] + 0x88) + 0x4c) == '\0') &&
           (2 < (uint)(iVar4 - iVar1))) {
          local_ac[0] = auStack_11c;
          FUN_00401830(s_Same_Sound_File_Max__>__s_009a08e4);
          uVar3 = FUN_00404230(local_c8);
          local_4 = CONCAT31(local_4._1_3_,3);
          FUN_00796d50(uVar3);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        if (local_88 != *(int **)(local_ec + 0x2c)) {
          piVar5 = local_88;
          do {
            if (*piVar5 == *(int *)(param_1 + 4)) {
              piVar5[8] = *(int *)(param_1 + 0x14);
              piVar5[9] = *(int *)(param_1 + 0x18);
              piVar5[10] = *(int *)(param_1 + 0x1c);
              piVar5[7] = local_cc;
              ppuStack_104 = (undefined1 **)0x45cd2f;
              (**(code **)(*(int *)piVar5[0x12] + 0x1c))();
              ppuStack_104 = (undefined1 **)0x45cd37;
              FUN_0045b080();
              local_ac[0] = auStack_11c;
              FUN_00401830(s_Same_ID_Already_Exist__>_Refresh_009a0900);
              uVar3 = FUN_00404230(local_c8);
              local_4._0_1_ = 4;
              FUN_00796d50(uVar3);
              if (0xf < local_b0) {
                ppuStack_104 = (undefined1 **)0x45cd89;
                _free(local_c4);
                return;
              }
              if (0xf < local_d0) {
                ppuStack_104 = (undefined1 **)0x45cd9c;
                _free(local_e4);
                return;
              }
              goto LAB_0045ce88;
            }
            piVar5 = piVar5 + 0x13;
          } while (piVar5 != *(int **)(local_ec + 0x2c));
        }
      }
    }
    local_40 = 0xf;
    local_44 = 0;
    local_54 = (void *)((uint)local_54 & 0xffffff00);
    local_3c = 0;
    local_80 = 0;
    local_7c = 0;
    local_78 = 0;
    local_6c = 0;
    local_84 = *(undefined1 **)(param_1 + 4);
    local_74 = *(undefined4 *)(param_1 + 0xc);
    local_64 = *(undefined4 *)(param_1 + 0x14);
    local_60 = *(undefined4 *)(param_1 + 0x18);
    local_5c = *(undefined4 *)(param_1 + 0x1c);
    ppuStack_104 = (undefined1 **)0x0;
    puStack_108 = local_a4;
    local_70 = *(undefined4 *)(param_1 + 0x10);
    local_4._0_1_ = 5;
    local_68 = local_cc;
    uStack_10c = 0x45ccbf;
    FUN_00401660();
    ppuStack_104 = (undefined1 **)0x45cccb;
    FUN_0045b080();
    if (local_ec == *(int *)(in_ECX + 0xf0)) {
      local_c4 = (void *)0x0;
      local_c0 = 0;
      local_bc = 0;
      ppuStack_104 = &local_84;
      local_4._0_1_ = 6;
      puStack_108 = (undefined1 *)0x45cdd1;
      cVar2 = FUN_0045b4c0();
      if (cVar2 != '\0') {
        ppuStack_104 = (undefined1 **)0x45cde3;
        FUN_0045ed60();
        ppuStack_104 = (undefined1 **)local_e8;
        puStack_108 = (undefined1 *)0x45cdf9;
        FUN_0045ebf0();
        ppuStack_104 = local_ac;
        local_4._0_1_ = 7;
        puStack_108 = (undefined1 *)0x45ce10;
        FUN_0045f1c0();
        FUN_0045e220();
        if (0xf < local_20) {
          ppuStack_104 = (undefined1 **)0x45ce32;
          _free(local_34);
          return;
        }
      }
      FUN_0045e220();
    }
    else {
      ppuStack_104 = &local_84;
      puStack_108 = (undefined1 *)0x45ccef;
      cVar2 = FUN_0045b4c0();
      if (cVar2 != '\0') {
        ppuStack_104 = (undefined1 **)0x45cd04;
        FUN_0045ed60();
      }
    }
    if (0xf < local_40) {
      ppuStack_104 = (undefined1 **)0x45ce54;
      _free(local_54);
      return;
    }
    local_40 = 0xf;
    local_44 = 0;
    local_54 = (void *)((uint)local_54 & 0xffffff00);
    if (0xf < local_d0) {
      ppuStack_104 = (undefined1 **)0x45ce81;
      _free(local_e4);
      return;
    }
LAB_0045ce88:
    if (local_8c < 0x10) {
      ExceptionList = local_c;
      return;
    }
  }
  local_d0 = 0xf;
  local_d4 = 0;
  local_e4 = (void *)((uint)local_e4 & 0xffffff00);
  ppuStack_104 = (undefined1 **)0x45cea0;
  _free(local_a0);
  return;
}


// ==== FUN_0045cec0 @ 0x0045cec0 ====

undefined4 FUN_0045cec0(int *param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0xb0011) {
    if (uVar1 == 0xb0010) {
      FUN_0045b640(param_1);
      return 1;
    }
    if (uVar1 < 0xb0004) {
      if (uVar1 == 0xb0003) {
        FUN_0045c1b0(param_1);
        return 1;
      }
      if (uVar1 == 0x40001) {
        FUN_0045c950(param_1);
        return 0;
      }
      if (uVar1 == 0xb0002) {
        FUN_0045b760(param_1);
        return 1;
      }
    }
    else {
      if (uVar1 == 0xb0005) {
        FUN_0045b590(param_1);
        return 1;
      }
      if (uVar1 == 0xb0006) {
        if (in_ECX[0x35] == 0) {
          return 1;
        }
        FUN_00462e40();
        return 1;
      }
    }
  }
  else if (uVar1 < 0x60050002) {
    if (uVar1 == 0x60050001) {
      FUN_0045ca40(param_1);
      return 1;
    }
    if (uVar1 == 0x30030109) {
      FUN_0045aed0(param_1);
      return 1;
    }
    if (uVar1 == 0x30030110) {
      (**(code **)(*in_ECX + 0x24))(param_1[1],0);
      return 1;
    }
  }
  else {
    if (uVar1 == 0x60050002) {
      FUN_0045c520(param_1);
      return 1;
    }
    if (uVar1 == 0x60050003) {
      FUN_0045bcf0(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0045cff0 @ 0x0045cff0 ====

int FUN_0045cff0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x4c;
}


// ==== FUN_0045d010 @ 0x0045d010 ====

undefined4 FUN_0045d010(void)

{
  return 0xb0012;
}


// ==== FUN_0045d020 @ 0x0045d020 ====

void FUN_0045d020(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = *param_3;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_0045d050 @ 0x0045d050 ====

void FUN_0045d050(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x44) < 0x10) {
    *(undefined4 *)(in_ECX + 0x44) = 0xf;
    *(undefined4 *)(in_ECX + 0x40) = 0;
    *(undefined1 *)(in_ECX + 0x30) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x30));
  return;
}


// ==== FUN_0045d080 @ 0x0045d080 ====

int FUN_0045d080(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0x8c,0,0xffffffff);
  return param_1;
}


// ==== FUN_0045d0c0 @ 0x0045d0c0 ====

int FUN_0045d0c0(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0x20,0,0xffffffff);
  return param_1;
}


// ==== FUN_0045d0f0 @ 0x0045d0f0 ====

void FUN_0045d0f0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  in_ECX[8] = param_1[8];
  in_ECX[9] = param_1[9];
  in_ECX[10] = param_1[10];
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0xf;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  FUN_00401660(param_1 + 0xb,0,0xffffffff);
  in_ECX[0x12] = param_1[0x12];
  return;
}


// ==== FUN_0045d170 @ 0x0045d170 ====

int FUN_0045d170(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0xc,0,0xffffffff);
  return param_1;
}


// ==== FUN_0045d1a0 @ 0x0045d1a0 ====

int FUN_0045d1a0(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0x28,0,0xffffffff);
  return param_1;
}


// ==== FUN_0045d1d0 @ 0x0045d1d0 ====

int FUN_0045d1d0(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0x24,0,0xffffffff);
  return param_1;
}


// ==== FUN_0045d200 @ 0x0045d200 ====

int FUN_0045d200(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 8,0,0xffffffff);
  return param_1;
}


// ==== FUN_0045d230 @ 0x0045d230 ====

void FUN_0045d230(undefined4 param_1,undefined1 param_2,void *param_3)

{
  undefined4 *in_ECX;
  uint in_stack_00000020;
  undefined4 in_stack_00000024;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c540;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[1] = param_1;
  in_ECX[2] = in_stack_00000024;
  *in_ECX = &PTR_FUN_009a09c4;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  local_4 = 1;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(&param_2,0,0xffffffff);
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_3);
  return;
}


// ==== FUN_0045d2b0 @ 0x0045d2b0 ====

undefined4 FUN_0045d2b0(void)

{
  return 0xb0011;
}


// ==== FUN_0045d2c0 @ 0x0045d2c0 ====

void FUN_0045d2c0(byte param_1)

{
  FUN_0045d2f0();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_0045d2f0 @ 0x0045d2f0 ====

void FUN_0045d2f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a09c4;
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[9] = 0xf;
    in_ECX[8] = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_0045d330 @ 0x0045d330 ====

void FUN_0045d330(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c560;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a09d8;
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


// ==== FUN_0045d3b0 @ 0x0045d3b0 ====

undefined4 FUN_0045d3b0(void)

{
  return 0xb0013;
}


// ==== FUN_0045d3c0 @ 0x0045d3c0 ====

void FUN_0045d3c0(byte param_1)

{
  FUN_0045d3f0();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_0045d3f0 @ 0x0045d3f0 ====

void FUN_0045d3f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a09d8;
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


// ==== FUN_0045d430 @ 0x0045d430 ====

void FUN_0045d430(uint param_1)

{
  int in_ECX;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c578;
  local_c = ExceptionList;
  if (0x5d1745dU - *(int *)(in_ECX + 8) < param_1) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_00401740(s_list<T>_too_long_0099d1d0,0x10);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c48c);
  }
  *(uint *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return;
}


// ==== FUN_0045d4d0 @ 0x0045d4d0 ====

void FUN_0045d4d0(void)

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
  puStack_8 = &LAB_0097c578;
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


// ==== FUN_0045d540 @ 0x0045d540 ====

void FUN_0045d540(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  in_ECX[8] = param_1[8];
  in_ECX[9] = param_1[9];
  in_ECX[10] = param_1[10];
  FUN_00401660(param_1 + 0xb,0,0xffffffff);
  in_ECX[0x12] = param_1[0x12];
  return;
}


// ==== FUN_0045d5b0 @ 0x0045d5b0 ====

undefined4 * FUN_0045d5b0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3[3] = param_1[3];
    param_3[4] = param_1[4];
    param_3[5] = param_1[5];
    param_3[6] = param_1[6];
    param_3[7] = param_1[7];
    param_3[8] = param_1[8];
    param_3[9] = param_1[9];
    param_3[10] = param_1[10];
    FUN_00401660(param_1 + 0xb,0,0xffffffff);
    param_3[0x12] = param_1[0x12];
    param_1 = param_1 + 0x13;
    param_3 = param_3 + 0x13;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_0045d640 @ 0x0045d640 ====

int FUN_0045d640(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    *(undefined4 *)(param_3 + -0x4c) = *(undefined4 *)(param_2 + -0x4c);
    iVar1 = param_2 + -0x4c;
    iVar2 = param_3 + -0x4c;
    *(undefined4 *)(param_3 + -0x48) = *(undefined4 *)(param_2 + -0x48);
    *(undefined4 *)(param_3 + -0x44) = *(undefined4 *)(param_2 + -0x44);
    *(undefined4 *)(param_3 + -0x40) = *(undefined4 *)(param_2 + -0x40);
    *(undefined4 *)(param_3 + -0x3c) = *(undefined4 *)(param_2 + -0x3c);
    *(undefined4 *)(param_3 + -0x38) = *(undefined4 *)(param_2 + -0x38);
    *(undefined4 *)(param_3 + -0x34) = *(undefined4 *)(param_2 + -0x34);
    *(undefined4 *)(param_3 + -0x30) = *(undefined4 *)(param_2 + -0x30);
    *(undefined4 *)(param_3 + -0x2c) = *(undefined4 *)(param_2 + -0x2c);
    *(undefined4 *)(param_3 + -0x28) = *(undefined4 *)(param_2 + -0x28);
    *(undefined4 *)(param_3 + -0x24) = *(undefined4 *)(param_2 + -0x24);
    FUN_00401660(param_2 + -0x20,0,0xffffffff);
    *(undefined4 *)(param_3 + -4) = *(undefined4 *)(param_2 + -4);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_0045d6d0 @ 0x0045d6d0 ====

int FUN_0045d6d0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097c5a1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x4c) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_0045d0f0(param_1);
    }
    param_3 = param_3 + 0x4c;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0045d726 @ 0x0045d726 ====

void Catch_0045d726(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (uint *)(iVar2 + 0x44);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x4c;
      puVar1 = puVar1 + 0x13;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0045d780 @ 0x0045d780 ====

void FUN_0045d780(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_58 [48];
  void *local_28;
  uint local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c5b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0045d0f0(param_1);
  local_4 = 0;
  FUN_0045d540(param_2);
  FUN_0045d540(local_58);
  if (local_14 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_28);
  return;
}


// ==== FUN_0045d7f0 @ 0x0045d7f0 ====

void FUN_0045d7f0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
                 undefined4 param_14,undefined1 param_15,void *param_16)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint in_stack_00000054;
  undefined4 in_stack_00000058;
  code *in_stack_0000005c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c5d8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  if (param_3 < param_2) {
    ExceptionList = &pvStack_c;
    do {
      iVar4 = (param_2 + -1) / 2;
      iVar1 = param_1 + iVar4 * 0x4c;
      iVar3 = (*in_stack_0000005c)(iVar1,&param_4);
      if (iVar3 == 0) break;
      FUN_0045d540(iVar1);
      param_2 = iVar4;
    } while (param_3 < iVar4);
  }
  puVar2 = (undefined4 *)(param_1 + param_2 * 0x4c);
  *puVar2 = param_4;
  puVar2[1] = param_5;
  puVar2[2] = param_6;
  puVar2[3] = param_7;
  puVar2[7] = param_11;
  puVar2[8] = param_12;
  puVar2[4] = param_8;
  puVar2[9] = param_13;
  puVar2[5] = param_9;
  puVar2[10] = param_14;
  puVar2[6] = param_10;
  FUN_00401660(&param_15,0,0xffffffff);
  puVar2[0x12] = in_stack_00000058;
  if (in_stack_00000054 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(param_16);
  return;
}


// ==== FUN_0045d920 @ 0x0045d920 ====

void FUN_0045d920(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  undefined1 local_58 [48];
  void *local_28;
  undefined4 local_18;
  uint local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c5b8;
  local_c = ExceptionList;
  iVar2 = (param_3 - param_1) / 0x4c;
  iVar1 = (param_2 - param_1) / 0x4c;
  iVar6 = iVar1;
  local_68 = iVar2;
  while (iVar3 = iVar6, iVar3 != 0) {
    iVar6 = local_68 % iVar3;
    local_68 = iVar3;
  }
  if ((local_68 < iVar2) && (0 < local_68)) {
    param_2 = iVar1 * 0x4c;
    puVar9 = (undefined4 *)(param_1 + local_68 * 0x4c);
    ExceptionList = &local_c;
    do {
      iVar2 = param_2;
      local_4 = 0xffffffff;
      FUN_0045d0f0(puVar9);
      local_4 = 0;
      if ((int)puVar9 + iVar2 == param_3) {
        piVar8 = &param_1;
      }
      else {
        local_64 = (int)puVar9 + iVar2;
        piVar8 = &local_64;
      }
      puVar7 = (undefined4 *)*piVar8;
      puVar5 = puVar9;
      while (puVar4 = puVar7, puVar4 != puVar9) {
        *puVar5 = *puVar4;
        puVar5[1] = puVar4[1];
        puVar5[2] = puVar4[2];
        puVar5[3] = puVar4[3];
        puVar5[4] = puVar4[4];
        puVar5[5] = puVar4[5];
        puVar5[6] = puVar4[6];
        puVar5[7] = puVar4[7];
        puVar5[8] = puVar4[8];
        puVar5[9] = puVar4[9];
        puVar5[10] = puVar4[10];
        FUN_00401660(puVar4 + 0xb,0,0xffffffff);
        puVar5[0x12] = puVar4[0x12];
        iVar2 = (param_3 - (int)puVar4) / 0x4c;
        if (iVar1 < iVar2) {
          local_60 = param_2 + (int)puVar4;
          piVar8 = &local_60;
        }
        else {
          local_5c = param_1 + (iVar1 - iVar2) * 0x4c;
          piVar8 = &local_5c;
        }
        puVar5 = puVar4;
        puVar7 = (undefined4 *)*piVar8;
      }
      FUN_0045d540(local_58);
      local_4 = 0xffffffff;
      if (0xf < local_14) {
        _free(local_28);
        return;
      }
      puVar9 = puVar9 + -0x13;
      local_68 = local_68 + -1;
      local_14 = 0xf;
      local_18 = 0;
      local_28 = (void *)((uint)local_28 & 0xffffff00);
    } while (local_68 != 0);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0045db10 @ 0x0045db10 ====

undefined4 FUN_0045db10(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x35e50d7 < param_1) {
    param_1 = FUN_0045d4d0();
  }
  pvVar1 = operator_new(param_1 * 0x4c);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x4c + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_0045db70 @ 0x0045db70 ====

void FUN_0045db70(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097c5f0;
  local_10 = ExceptionList;
  iVar5 = *(int *)(in_ECX + 4);
  param_3 = (undefined4 *)*param_3;
  if (iVar5 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar5 >> 2;
  }
  uVar7 = CONCAT44(iVar5,iVar1);
  if (param_2 != 0) {
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    ExceptionList = &local_10;
    if (0x3fffffffU - iVar5 < param_2) {
      ExceptionList = &local_10;
      uVar7 = FUN_0045d4d0();
    }
    iVar5 = (int)((ulonglong)uVar7 >> 0x20);
    uVar2 = (uint)uVar7;
    if (iVar5 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    if (uVar2 < iVar1 + param_2) {
      if (0x3fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar5 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
      }
      if (uVar2 < iVar1 + param_2) {
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
        }
        uVar2 = iVar5 + param_2;
      }
      pvVar3 = operator_new(uVar2 * 4);
      local_8 = 0;
      iVar5 = FUN_0042ea40(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0045d020(iVar5,param_2,&param_3);
      FUN_0042ea40(param_1,*(undefined4 *)(in_ECX + 8),iVar5 + param_2 * 4);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)pvVar3);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar5) * 4);
        *(void **)(in_ECX + 4) = pvVar3;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar1 = *(int *)(in_ECX + 8);
    iVar5 = param_2 * 4;
    if ((uint)(iVar1 - param_1 >> 2) < param_2) {
      FUN_0042ea40(param_1,iVar1,iVar5 + param_1);
      local_8 = 2;
      FUN_0041ea60(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&param_3);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar5;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + param_2 * -4,&param_3);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar1 + param_2 * -4;
    uVar4 = FUN_0042ea40(iVar6,iVar1,iVar1);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_0056bf90(param_1,iVar6,iVar1);
    FUN_008335f0(param_1,iVar5 + param_1,&param_3);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0045dcd9 @ 0x0045dcd9 ====

void Catch_0045dcd9(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0045ddb0 @ 0x0045ddb0 ====

void FUN_0045ddb0(uint param_1,undefined4 param_2)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097c600;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    uVar1 = param_1;
    if (0x3fffffff < param_1) {
      uVar1 = FUN_0045d4d0();
    }
    uVar1 = uVar1 * 4;
    pvVar2 = operator_new(uVar1);
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 + (int)pvVar2);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    local_8 = 0;
    FUN_0045d020(pvVar2,param_1,param_2);
    *(void **)(in_ECX + 8) = (void *)(uVar1 + (int)pvVar2);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0045de46 @ 0x0045de46 ====

void Catch_0045de46(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0045de60 @ 0x0045de60 ====

void FUN_0045de60(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      param_1[2] = param_3[2];
      param_1[3] = param_3[3];
      param_1[4] = param_3[4];
      param_1[5] = param_3[5];
      param_1[6] = param_3[6];
      param_1[7] = param_3[7];
      param_1[8] = param_3[8];
      param_1[9] = param_3[9];
      param_1[10] = param_3[10];
      FUN_00401660(param_3 + 0xb,0,0xffffffff);
      param_1[0x12] = param_3[0x12];
      param_1 = param_1 + 0x13;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0045dee0 @ 0x0045dee0 ====

void FUN_0045dee0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097c621;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_0045d0f0(param_3);
    }
    param_1 = param_1 + 0x4c;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0045df38 @ 0x0045df38 ====

void Catch_0045df38(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 8)) {
    puVar1 = (uint *)(iVar2 + 0x44);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x4c;
      puVar1 = puVar1 + 0x13;
    } while (iVar2 != *(int *)(unaff_EBP + 8));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0045df90 @ 0x0045df90 ====

void FUN_0045df90(undefined4 param_1,undefined4 param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  
  iVar1 = (*param_4)(param_2,param_1);
  if (iVar1 != 0) {
    FUN_0045d780(param_2,param_1);
  }
  iVar1 = (*param_4)(param_3,param_2);
  if (iVar1 != 0) {
    FUN_0045d780(param_3,param_2);
  }
  iVar1 = (*param_4)(param_2,param_1);
  if (iVar1 != 0) {
    FUN_0045d780(param_2,param_1);
  }
  return;
}


// ==== FUN_0045dff0 @ 0x0045dff0 ====

void FUN_0045dff0(int param_1,int param_2,int param_3,undefined1 param_4)

{
  undefined4 *puVar1;
  void **ppvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *in_stack_00000040;
  uint in_stack_00000054;
  code *in_stack_0000005c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c5d8;
  pvStack_c = ExceptionList;
  iVar4 = param_2 * 2 + 2;
  local_4 = 0;
  iVar6 = param_2;
  iVar5 = param_2;
  ExceptionList = &pvStack_c;
  ppvVar2 = &pvStack_c;
  if (iVar4 < param_3) {
    do {
      iVar3 = (*in_stack_0000005c)();
      iVar5 = iVar4;
      if (iVar3 != 0) {
        iVar5 = iVar4 + -1;
      }
      iVar4 = param_1 + iVar5 * 0x4c;
      puVar1 = (undefined4 *)(param_1 + iVar6 * 0x4c);
      *puVar1 = *(undefined4 *)(param_1 + iVar5 * 0x4c);
      puVar1[1] = *(undefined4 *)(iVar4 + 4);
      puVar1[2] = *(undefined4 *)(iVar4 + 8);
      puVar1[3] = *(undefined4 *)(iVar4 + 0xc);
      puVar1[4] = *(undefined4 *)(iVar4 + 0x10);
      puVar1[5] = *(undefined4 *)(iVar4 + 0x14);
      puVar1[6] = *(undefined4 *)(iVar4 + 0x18);
      puVar1[7] = *(undefined4 *)(iVar4 + 0x1c);
      puVar1[8] = *(undefined4 *)(iVar4 + 0x20);
      puVar1[9] = *(undefined4 *)(iVar4 + 0x24);
      puVar1[10] = *(undefined4 *)(iVar4 + 0x28);
      FUN_00401660();
      puVar1[0x12] = *(undefined4 *)(iVar4 + 0x48);
      iVar4 = iVar5 * 2 + 2;
      iVar6 = iVar5;
    } while (iVar4 < param_3);
    ppvVar2 = ExceptionList;
  }
  ExceptionList = ppvVar2;
  if (iVar4 == param_3) {
    FUN_0045d540();
    iVar5 = param_3 + -1;
  }
  FUN_0045d0f0(&param_4);
  FUN_0045d7f0(param_1,iVar5,param_2);
  if (in_stack_00000054 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(in_stack_00000040);
  return;
}


// ==== FUN_0045e160 @ 0x0045e160 ====

void FUN_0045e160(int param_1,int param_2,undefined4 param_3,undefined1 param_4)

{
  void *in_stack_00000040;
  uint in_stack_00000054;
  undefined4 in_stack_0000005c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c5d8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_0045d540();
  FUN_0045d0f0(&param_4);
  FUN_0045dff0(param_1,0,(param_2 - param_1) / 0x4c);
  if (in_stack_00000054 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000040);
  return;
}


// ==== FUN_0045e1f0 @ 0x0045e1f0 ====

void FUN_0045e1f0(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x4c) {
    FUN_0045d050();
  }
  return;
}


// ==== FUN_0045e220 @ 0x0045e220 ====

void FUN_0045e220(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x4c) {
    FUN_0045d050();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0045e270 @ 0x0045e270 ====

void FUN_0045e270(uint param_1,undefined1 param_2)

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
    FUN_0045db70(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_0045e2e0 @ 0x0045e2e0 ====

/* WARNING: Removing unreachable block (ram,0x0045e2fb) */
/* WARNING: Removing unreachable block (ram,0x0045e300) */
/* WARNING: Removing unreachable block (ram,0x0045e30e) */

void FUN_0045e2e0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_0045db70(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_0045e330 @ 0x0045e330 ====

void FUN_0045e330(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (param_3 - param_1) / 0x4c;
  if (iVar1 < 0x29) {
    FUN_0045df90(param_1,param_2,param_3,param_4);
    return;
  }
  iVar1 = iVar1 + 1;
  iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
  iVar1 = iVar2 * 0x4c + param_1;
  FUN_0045df90(param_1,iVar1,iVar2 * 0x98 + param_1,param_4);
  FUN_0045df90(param_2 + iVar2 * -0x4c,param_2,iVar2 * 0x4c + param_2,param_4);
  iVar3 = param_3 + iVar2 * -0x4c;
  FUN_0045df90(param_3 + iVar2 * -0x98,iVar3,param_3,param_4);
  FUN_0045df90(iVar1,param_2,iVar3,param_4);
  return;
}


// ==== FUN_0045e400 @ 0x0045e400 ====

void FUN_0045e400(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (param_2 - param_1) / 0x4c;
  iVar3 = iVar1 / 2;
  if (0 < iVar3) {
    iVar2 = param_1 + iVar3 * 0x4c;
    do {
      iVar2 = iVar2 + -0x4c;
      iVar3 = iVar3 + -1;
      FUN_0045d0f0(iVar2);
      FUN_0045dff0(param_1,iVar3,iVar1);
    } while (0 < iVar3);
  }
  return;
}


// ==== FUN_0045e470 @ 0x0045e470 ====

void FUN_0045e470(undefined4 param_1,int param_2)

{
  param_2 = param_2 + -0x4c;
  FUN_0045d0f0(param_2);
  FUN_0045e160(param_1,param_2,param_2);
  return;
}


// ==== FUN_0045e4a0 @ 0x0045e4a0 ====

void FUN_0045e4a0(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x4c) {
    FUN_0045d050();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0045e4b0 @ 0x0045e4b0 ====

void FUN_0045e4b0(int *param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  FUN_0045d5b0(param_2 + 0x4c,*(undefined4 *)(in_ECX + 8),param_2,param_2);
  iVar1 = *(int *)(in_ECX + 8);
  for (iVar2 = iVar1 + -0x4c; iVar2 != iVar1; iVar2 = iVar2 + 0x4c) {
    FUN_0045d050();
  }
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x4c;
  *param_1 = param_2;
  return;
}


// ==== FUN_0045e500 @ 0x0045e500 ====

void FUN_0045e500(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097c630;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x4c;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_0045db10(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_0045d6d0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0045e58a @ 0x0045e58a ====

void Catch_0045e58a(void)

{
  FUN_0045e220();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0045e5a0 @ 0x0045e5a0 ====

int FUN_0045e5a0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0045dee0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x4c;
}


// ==== FUN_0045e5d0 @ 0x0045e5d0 ====

void FUN_0045e5d0(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined1 local_64 [2];
  undefined1 auStack_62 [46];
  void *local_34;
  uint local_20;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097c648;
  local_10 = ExceptionList;
  local_14 = local_64 + -0xc;
  ExceptionList = &local_10;
  FUN_0045d0f0(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x4c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x4c;
    }
    if (0x35e50d7U - iVar1 < param_2) {
      FUN_0045d4d0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x4c;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x35e50d7 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x4c;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_0045cff0();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x4c);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_0045d6d0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0045dee0(iVar2,param_2,local_64);
      FUN_0045d6d0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x4c);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x4c;
      }
      if (iVar2 != 0) {
        FUN_0045e1f0(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x4c + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar1) * 0x4c);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x4c;
      if ((uint)((iVar2 - param_1) / 0x4c) < param_2) {
        FUN_0045d6d0(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0045e5a0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x4c,local_64
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_0045de60(param_1,*(int *)(in_ECX + 8) + param_2 * -0x4c,local_64);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x4c;
        uVar4 = FUN_0045d6d0(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0045d640(param_1,iVar6,iVar2,param_1);
        FUN_0045de60(param_1,iVar1 + param_1,local_64);
      }
    }
  }
  if (local_20 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_34);
  return;
}


// ==== Catch@0045e79a @ 0x0045e79a ====

void Catch_0045e79a(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_0045e1f0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0045e854 @ 0x0045e854 ====

void Catch_0045e854(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x4c;
  FUN_0045e1f0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0045e8e0 @ 0x0045e8e0 ====

void FUN_0045e8e0(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c668;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_0045e500(param_1 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0045e950 @ 0x0045e950 ====

void FUN_0045e950(uint *param_1,uint param_2,uint param_3,code *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uStack_4;
  
  uVar4 = param_2 + ((int)(param_3 - param_2) / 0x98) * 0x4c;
  FUN_0045e330(param_2,uVar4,param_3 - 0x4c,param_4);
  uVar1 = uVar4;
  while (uStack_4 = uVar1, param_2 < uStack_4) {
    uVar1 = uStack_4 - 0x4c;
    iVar2 = (*param_4)(uVar1,uStack_4);
    if ((iVar2 != 0) || (iVar2 = (*param_4)(uStack_4,uVar1), iVar2 != 0)) break;
  }
  do {
    uVar4 = uVar4 + 0x4c;
    uVar1 = uVar4;
    uVar5 = uStack_4;
    if (param_3 <= uVar4) break;
    iVar2 = (*param_4)(uVar4,uStack_4);
    if ((iVar2 != 0) || (iVar2 = (*param_4)(uStack_4,uVar4), iVar2 != 0)) break;
  } while( true );
joined_r0x0045e9f9:
  if (param_3 <= uVar1) {
LAB_0045ea32:
    if (param_2 < uStack_4) {
      uVar3 = uStack_4;
      do {
        uVar3 = uVar3 - 0x4c;
        iVar2 = (*param_4)(uVar3,uVar5);
        if (iVar2 == 0) {
          iVar2 = (*param_4)(uVar5,uVar3);
          if (iVar2 != 0) break;
          uVar5 = uVar5 - 0x4c;
          FUN_0045d780(uVar5,uVar3);
        }
        uStack_4 = uStack_4 - 0x4c;
      } while (param_2 < uStack_4);
    }
    if (uStack_4 == param_2) {
      if (uVar1 == param_3) {
        *param_1 = uVar5;
        param_1[1] = uVar4;
        return;
      }
      if (uVar4 != uVar1) {
        FUN_0045d780(uVar5,uVar4);
      }
      uVar4 = uVar4 + 0x4c;
      FUN_0045d780(uVar5,uVar1);
      uVar1 = uVar1 + 0x4c;
      uVar5 = uVar5 + 0x4c;
    }
    else {
      uStack_4 = uStack_4 - 0x4c;
      if (uVar1 == param_3) {
        uVar5 = uVar5 - 0x4c;
        if (uStack_4 != uVar5) {
          FUN_0045d780(uStack_4,uVar5);
        }
        uVar4 = uVar4 - 0x4c;
        FUN_0045d780(uVar5,uVar4);
      }
      else {
        FUN_0045d780(uVar1,uStack_4);
        uVar1 = uVar1 + 0x4c;
      }
    }
    goto joined_r0x0045e9f9;
  }
  iVar2 = (*param_4)(uVar5,uVar1);
  uVar3 = uVar4;
  if (iVar2 == 0) {
    iVar2 = (*param_4)(uVar1,uVar5);
    if (iVar2 != 0) goto LAB_0045ea32;
    uVar3 = uVar4 + 0x4c;
    FUN_0045d780(uVar4,uVar1);
  }
  uVar4 = uVar3;
  uVar1 = uVar1 + 0x4c;
  goto joined_r0x0045e9f9;
}


// ==== FUN_0045eb20 @ 0x0045eb20 ====

void FUN_0045eb20(int param_1,int param_2,code *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = param_1;
  if (param_1 != param_2) {
    while (iVar2 = iVar1, iVar1 = iVar2 + 0x4c, iVar1 != param_2) {
      iVar3 = (*param_3)(iVar1,param_1);
      if (iVar3 == 0) {
        iVar4 = (*param_3)(iVar1,iVar2);
        iVar3 = iVar2;
        if (iVar4 != 0) {
          do {
            iVar5 = iVar3;
            iVar4 = (*param_3)(iVar1,iVar5 + -0x4c);
            iVar3 = iVar5 + -0x4c;
          } while (iVar4 != 0);
          if ((iVar5 != iVar1) && (iVar1 != iVar2 + 0x98)) {
            FUN_0045d920(iVar5,iVar1,iVar2 + 0x98,0,0);
          }
        }
      }
      else if ((param_1 != iVar1) && (iVar1 != iVar2 + 0x98)) {
        FUN_0045d920(param_1,iVar1,iVar2 + 0x98,0,0);
      }
    }
  }
  return;
}


// ==== FUN_0045ebc0 @ 0x0045ebc0 ====

void FUN_0045ebc0(void)

{
  int in_ECX;
  
  FUN_0045e220();
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0045ebf0 @ 0x0045ebf0 ====

void FUN_0045ebf0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c668;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_0045e500(param_2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0045ec60 @ 0x0045ec60 ====

void FUN_0045ec60(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x4c != 0) {
      iVar1 = (param_2 - iVar1) / 0x4c;
      goto LAB_0045eca5;
    }
  }
  iVar1 = 0;
LAB_0045eca5:
  FUN_0045e5d0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x4c;
  return;
}


// ==== FUN_0045ecd0 @ 0x0045ecd0 ====

void FUN_0045ecd0(void)

{
  int in_ECX;
  
  FUN_0045e220();
  if (*(uint *)(in_ECX + 0x20) < 0x10) {
    *(undefined4 *)(in_ECX + 0x20) = 0xf;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined1 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_0045ed00 @ 0x0045ed00 ====

void FUN_0045ed00(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = param_2 - param_1;
  while (1 < iVar1 / 0x4c) {
    FUN_0045e470(param_1,param_2,param_3,0);
    param_2 = param_2 + -0x4c;
    iVar1 = param_2 - param_1;
  }
  return;
}


// ==== FUN_0045ed60 @ 0x0045ed60 ====

void FUN_0045ed60(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x4c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x4c))) {
    FUN_0045ec60(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0045dee0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x4c;
  return;
}


// ==== FUN_0045edf0 @ 0x0045edf0 ====

undefined4 * FUN_0045edf0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097c691;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x34);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_2;
    *puVar1 = param_1;
    FUN_0045e8e0(param_3);
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0045ee5e @ 0x0045ee5e ====

void Catch_0045ee5e(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0045ee80 @ 0x0045ee80 ====

void FUN_0045ee80(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_8;
  int local_4;
  
  iVar1 = (param_2 - param_1) / 0x4c;
  if (0x20 < iVar1) {
    do {
      if (param_3 < 1) {
        if (0x20 < iVar1) {
          if (1 < (param_2 - param_1) / 0x4c) {
            FUN_0045e400(param_1,param_2,param_4,0,0);
          }
          FUN_0045ed00(param_1,param_2,param_4);
          return;
        }
        break;
      }
      FUN_0045e950(&local_8,param_1,param_2,param_4);
      iVar1 = local_4;
      param_3 = param_3 / 2 + (param_3 / 2) / 2;
      if ((local_8 - param_1) / 0x4c < (param_2 - local_4) / 0x4c) {
        FUN_0045ee80(param_1,local_8,param_3,param_4);
        param_1 = iVar1;
      }
      else {
        FUN_0045ee80(local_4,param_2,param_3,param_4);
        param_2 = local_8;
      }
      iVar1 = (param_2 - param_1) / 0x4c;
    } while (0x20 < iVar1);
  }
  if (1 < iVar1) {
    FUN_0045eb20(param_1,param_2,param_4);
  }
  return;
}


// ==== FUN_0045efd0 @ 0x0045efd0 ====

void FUN_0045efd0(void)

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
  FUN_0045ecd0();
  _free(_Memory);
  return;
}


// ==== FUN_0045f010 @ 0x0045f010 ====

void FUN_0045f010(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  
  uVar3 = *(uint *)(in_ECX + 0x20);
  uVar5 = FUN_0041e6e0(param_2 + 2);
  uVar5 = uVar5 & uVar3;
  if (*(uint *)(in_ECX + 0x24) <= uVar5) {
    uVar5 = uVar5 + (-1 - (uVar3 >> 1));
  }
  iVar4 = *(int *)(in_ECX + 0x14);
  iVar1 = uVar5 * 4;
  piVar2 = *(int **)(iVar1 + iVar4);
  while ((param_2 == piVar2 &&
         (*(undefined4 *)(iVar1 + iVar4) = **(undefined4 **)(iVar1 + iVar4), uVar5 != 0))) {
    iVar4 = *(int *)(in_ECX + 0x14);
    uVar5 = uVar5 - 1;
    iVar1 = uVar5 * 4;
    piVar2 = *(int **)(iVar1 + iVar4);
  }
  if (param_2 == *(int **)(in_ECX + 8)) {
    *param_1 = *param_2;
    return;
  }
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  FUN_0045ecd0();
  _free(param_2);
  return;
}


// ==== FUN_0045f0a0 @ 0x0045f0a0 ====

void FUN_0045f0a0(void)

{
  int in_ECX;
  
  FUN_0045efd0();
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0045f0c0 @ 0x0045f0c0 ====

void FUN_0045f0c0(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c6ab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = *param_1;
  uVar1 = FUN_004c4d20();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  param_1 = *(undefined1 **)(in_ECX + 8);
  local_4 = 0;
  FUN_0045ddb0(9,&param_1);
  *(undefined4 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0045f140 @ 0x0045f140 ====

void FUN_0045f140(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x14) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    FUN_0045efd0();
    _free(*(void **)(in_ECX + 8));
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_0045f180 @ 0x0045f180 ====

undefined4 FUN_0045f180(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0045f190 @ 0x0045f190 ====

undefined4 FUN_0045f190(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_0045f1a0 @ 0x0045f1a0 ====

int FUN_0045f1a0(void)

{
  int in_ECX;
  
  return (int)*(float *)(in_ECX + 0xa4);
}


// ==== FUN_0045f1b0 @ 0x0045f1b0 ====

undefined4 FUN_0045f1b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0);
}


// ==== FUN_0045f1c0 @ 0x0045f1c0 ====

/* WARNING: Removing unreachable block (ram,0x0045f2db) */
/* WARNING: Removing unreachable block (ram,0x0045f4cf) */

void FUN_0045f1c0(int *param_1,int param_2)

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
      FUN_0045e270(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
LAB_0045f424:
        if ((uint)piVar11[7] <= uVar9) {
          bVar15 = false;
          goto LAB_0045f434;
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
        if (iVar6 == 0) goto LAB_0045f424;
LAB_0045f434:
        if (!bVar15) {
          if (*(uint *)(param_2 + 0x18) < 0x10) {
            pbVar14 = (byte *)(param_2 + 4);
          }
          else {
            pbVar14 = *(byte **)(param_2 + 4);
          }
          uVar9 = piVar11[7];
          if (uVar9 == 0) goto LAB_0045f4fc;
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
          goto code_r0x0045f4ef;
        }
      }
    } while (piVar11 != *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  goto LAB_0045f445;
  while( true ) {
    uVar7 = uVar7 - 1;
    bVar15 = *pbVar13 < *pbVar14;
    bVar16 = *pbVar13 == *pbVar14;
    pbVar13 = pbVar13 + 1;
    pbVar14 = pbVar14 + 1;
    if (!bVar16) break;
code_r0x0045f4ef:
    if (uVar7 == 0) break;
  }
  if (!bVar16) {
    iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
  }
  bVar15 = iVar6 < 0;
  if (iVar6 == 0) {
LAB_0045f4fc:
    if (uVar5 <= uVar9) {
      bVar15 = false;
      goto LAB_0045f50d;
    }
  }
  else {
LAB_0045f50d:
    if (!bVar15) {
      *param_1 = (int)piVar11;
      *(undefined1 *)(param_1 + 1) = 0;
      return;
    }
  }
  piVar11 = (int *)*piVar11;
LAB_0045f445:
  iVar6 = FUN_0045edf0(piVar11,piVar11[1],param_2);
  FUN_0045d430(1);
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


// ==== FUN_0045f530 @ 0x0045f530 ====

void FUN_0045f530(byte param_1)

{
  void *in_ECX;
  
  FUN_0045c850();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0045f550 @ 0x0045f550 ====

void FUN_0045f550(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0b84;
  return;
}


// ==== FUN_0045f560 @ 0x0045f560 ====

void FUN_0045f560(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0b84;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0045f580 @ 0x0045f580 ====

void FUN_0045f580(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x10) != 0) &&
     (iVar1 = *(int *)(in_ECX + 0x10) + -1, *(int *)(in_ECX + 0x10) = iVar1, iVar1 == 0)) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  return;
}


// ==== FUN_0045f5a0 @ 0x0045f5a0 ====

void FUN_0045f5a0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  (**(code **)(*DAT_00b5a994 + 4))();
  (**(code **)(*DAT_00b5a83c + 4))();
  puVar1 = *(undefined4 **)(in_ECX + 0x20);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x1c); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 4))();
  }
  return;
}


// ==== FUN_0045f5e0 @ 0x0045f5e0 ====

int FUN_0045f5e0(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    iVar3 = (**(code **)(*DAT_00b5a994 + 8))();
    if ((iVar3 == 0) && (iVar3 = (**(code **)(*DAT_00b5a83c + 8))(), iVar3 == 0)) {
      puVar1 = *(undefined4 **)(in_ECX + 0x20);
      for (puVar5 = *(undefined4 **)(in_ECX + 0x1c); puVar5 != puVar1; puVar5 = puVar5 + 1) {
        iVar3 = (**(code **)(*(int *)*puVar5 + 8))();
        if (iVar3 != 0) {
          return iVar3;
        }
      }
      iVar3 = 0;
    }
  }
  else {
    uVar2 = *(uint *)(in_ECX + 0x10) >> 2;
    iVar3 = uVar2 * -4;
    if (*(uint *)(in_ECX + 0xc) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(in_ECX + 0xc);
    }
    iVar3 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + uVar2 * 4) +
                    (*(uint *)(in_ECX + 0x10) + iVar3) * 4);
    if (*(int *)(in_ECX + 0x14) != 0) {
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
      if ((uint)(*(int *)(in_ECX + 0xc) * 4) <= *(uint *)(in_ECX + 0x10)) {
        *(undefined4 *)(in_ECX + 0x10) = 0;
      }
      iVar4 = *(int *)(in_ECX + 0x14) + -1;
      *(int *)(in_ECX + 0x14) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 *)(in_ECX + 0x10) = 0;
        return iVar3;
      }
    }
  }
  return iVar3;
}


// ==== FUN_0045f680 @ 0x0045f680 ====

void FUN_0045f680(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined4 local_28;
  uint local_24;
  void *pvStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c708;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_debug_network_009a0a98,0xd);
  local_4 = 0;
  (**(code **)(*DAT_00b5a7d8 + 8))(&local_28);
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_networkanalysis_009a0aa8,0xf);
  puStack_8 = (undefined1 *)0x1;
  (**(code **)(*DAT_00b5a7d8 + 8))((int)register0x00000010 + -0x2c);
  pvStack_c = (void *)0xffffffff;
  if (0xf < uStack_18) {
    _free(unaff_EBX);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  FUN_00401740(s_networkanalysis_save_009a0ab8,0x14);
  pvStack_c = (void *)0x2;
  (**(code **)(*DAT_00b5a7d8 + 8))((int)register0x00000010 + -0x30);
  local_10 = 0xffffffff;
  if (0xf < uStack_1c) {
    _free(unaff_EBP);
    return;
  }
  uStack_1c = 0xf;
  pvStack_20 = (void *)0x0;
  FUN_00401740(s_delayanalysis_save_009a0ad0,0x12);
  local_10 = 3;
  (**(code **)(*DAT_00b5a7d8 + 8))((int)register0x00000010 + -0x34);
  local_14 = 0xffffffff;
  if (0xf < pvStack_20) {
    _free(unaff_ESI);
    return;
  }
  pvStack_20 = (void *)0xf;
  local_24 = 0;
  FUN_00401740(s_delayanalysis_clear_009a0ae4,0x13);
  local_14 = 4;
  (**(code **)(*DAT_00b5a7d8 + 8))((int)register0x00000010 + -0x38);
  uStack_18 = 0xffffffff;
  if (0xf < local_24) {
    _free(unaff_EDI);
    return;
  }
  FUN_004eb890(in_ECX + 0x18);
  if (DAT_00b5a994 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a994)(1);
  }
  if (DAT_00b5a83c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a83c)(1);
  }
  iVar3 = *(int *)(in_ECX + 0x14);
  while (iVar3 != 0) {
    uVar2 = *(uint *)(in_ECX + 0x10) >> 2;
    iVar3 = uVar2 * -4;
    if (*(uint *)(in_ECX + 0xc) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(in_ECX + 0xc);
    }
    puVar1 = *(undefined4 **)
              (*(int *)(*(int *)(in_ECX + 8) + uVar2 * 4) + (*(uint *)(in_ECX + 0x10) + iVar3) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    if (*(int *)(in_ECX + 0x14) != 0) {
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
      if ((uint)(*(int *)(in_ECX + 0xc) * 4) <= *(uint *)(in_ECX + 0x10)) {
        *(undefined4 *)(in_ECX + 0x10) = 0;
      }
      iVar3 = *(int *)(in_ECX + 0x14) + -1;
      *(int *)(in_ECX + 0x14) = iVar3;
      if (iVar3 == 0) {
        *(undefined4 *)(in_ECX + 0x10) = 0;
      }
    }
    iVar3 = *(int *)(in_ECX + 0x14);
  }
  ExceptionList = pvStack_20;
  return;
}


// ==== FUN_0045f8e0 @ 0x0045f8e0 ====

void FUN_0045f8e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c730;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0ba4;
  local_4 = 2;
  DAT_00b5a840 = 0;
  FUN_0045f680();
  if ((void *)in_ECX[7] == (void *)0x0) {
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    FUN_0046cfc0();
    *in_ECX = &PTR_FUN_009a0b84;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[7]);
  return;
}


// ==== FUN_0045f960 @ 0x0045f960 ====

undefined4 FUN_0045f960(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX_00;
  void *pvStack_44;
  undefined1 uStack_40;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined1 local_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c755;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_debug_network_009a0af8,0xd);
  if (iVar2 != 0) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_networkanalysis_009a0b30,0xf);
    if (iVar2 == 0) {
      uVar4 = FUN_00459160(local_28,0);
      local_4 = 2;
      uVar4 = thunk_FUN_00796fb0(uVar4);
      local_4 = 0xffffffff;
      if (pvStack_10 < (void *)0x10) {
        pvStack_10 = (void *)0xf;
        uStack_14 = 0;
        pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
        (**(code **)(*DAT_00b5a990 + 4))(uVar4);
        ExceptionList = pvStack_10;
        return 1;
      }
      _free(pvStack_24);
      return extraout_EAX_00;
    }
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_networkanalysis_save_009a0b40,0x14);
    if (iVar2 == 0) {
      (**(code **)(*DAT_00b5a990 + 8))();
      ExceptionList = local_c;
      return 1;
    }
    cVar1 = FUN_004036a0(param_1 + 8,s_delayanalysis_save_009a0b58);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5a98c + 0x18))();
      ExceptionList = local_c;
      return 1;
    }
    cVar1 = FUN_004036a0(param_1 + 8,s_delayanalysis_clear_009a0b6c);
    if (cVar1 == '\0') {
      ExceptionList = local_c;
      return 0;
    }
    (**(code **)(*DAT_00b5a98c + 0x14))();
    ExceptionList = local_c;
    return 1;
  }
  cVar1 = (**(code **)(*DAT_00b5a83c + 0x14))();
  if (cVar1 != '\0') {
    if (DAT_00b5a83c != (int *)0x0) {
      (**(code **)*DAT_00b5a83c)(1);
    }
    pvVar3 = operator_new(0x2c);
    local_4 = 1;
    if (pvVar3 != (void *)0x0) {
      FUN_00464b50();
    }
    ExceptionList = local_c;
    return 1;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  uStack_40 = 0;
  FUN_00401740(s_Cannot_Change_NetworkMode_to_Deb_009a0b08,0x26);
  local_4 = 0;
  (**(code **)(*DAT_00b5a72c + 8))(&pvStack_44);
  if (uStack_30 < 0x10) {
    ExceptionList = pvStack_10;
    return 1;
  }
  _free(pvStack_44);
  return extraout_EAX;
}


// ==== FUN_0045fb90 @ 0x0045fb90 ====

undefined4 FUN_0045fb90(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  iVar3 = (**(code **)(*param_1 + 4))();
  if ((((iVar3 == 0x70004) && (cVar2 = FUN_0045f960(param_1), cVar2 != '\0')) ||
      (cVar2 = (**(code **)(*DAT_00b5a994 + 0xc))(param_1), cVar2 == '\x01')) ||
     (cVar2 = (**(code **)(*DAT_00b5a83c + 0xc))(param_1), cVar2 == '\x01')) {
    return 1;
  }
  puVar4 = *(undefined4 **)(in_ECX + 0x1c);
  puVar1 = *(undefined4 **)(in_ECX + 0x20);
  while( true ) {
    if (puVar4 == puVar1) {
      return 0;
    }
    cVar2 = (**(code **)(*(int *)*puVar4 + 0xc))(param_1);
    if (cVar2 != '\0') break;
    puVar4 = puVar4 + 1;
  }
  return 1;
}


// ==== FUN_0045fc10 @ 0x0045fc10 ====

void FUN_0045fc10(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined4 local_fc;
  uint uStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  undefined4 uStack_e8;
  undefined1 auStack_e0 [4];
  void *local_dc;
  undefined1 local_d8;
  void *pvStack_cc;
  void *local_c8;
  undefined4 local_c4;
  void *local_c0;
  undefined4 uStack_bc;
  uint uStack_b8;
  uint uStack_b4;
  undefined4 uStack_b0;
  void *pvStack_ac;
  void *pvStack_a8;
  void *pvStack_a0;
  undefined4 uStack_9c;
  uint uStack_98;
  void *pvStack_94;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined4 uStack_84;
  uint uStack_80;
  void *pvStack_74;
  undefined4 uStack_64;
  uint uStack_60;
  void *pvStack_58;
  undefined1 auStack_4c [8];
  uint uStack_44;
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  void *pvStack_20;
  undefined1 uStack_14;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c802;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_fc = operator_new(0x48);
  local_4 = 0;
  if (local_fc != (void *)0x0) {
    FUN_004668f0();
  }
  local_4 = 0xffffffff;
  local_fc = operator_new(0x2c);
  local_4 = 1;
  if (local_fc != (void *)0x0) {
    FUN_00464b50();
  }
  local_4 = 0xffffffff;
  local_fc = operator_new(0xc);
  local_4 = 2;
  if (local_fc == (void *)0x0) {
    local_fc = (void *)0x0;
  }
  else {
    local_fc = (void *)FUN_00466460();
  }
  iVar1 = *(int *)(in_ECX + 0x1c);
  local_4 = 0xffffffff;
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x24) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x20) - iVar1 >> 2)))
  {
    FUN_00460330(*(undefined4 *)(in_ECX + 0x20),1,&local_fc);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x20);
    *puVar2 = local_fc;
    *(undefined4 **)(in_ECX + 0x20) = puVar2 + 1;
  }
  FUN_004664e0();
  local_fc = operator_new(0x1c);
  local_4 = 3;
  if (local_fc == (void *)0x0) {
    local_fc = (void *)0x0;
  }
  else {
    local_fc = (void *)FUN_00465ff0();
  }
  iVar1 = *(int *)(in_ECX + 0x1c);
  local_4 = 0xffffffff;
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x24) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x20) - iVar1 >> 2)))
  {
    FUN_00460330(*(undefined4 *)(in_ECX + 0x20),1,&local_fc);
  }
  else {
    puVar3 = *(uint **)(in_ECX + 0x20);
    *puVar3 = (uint)local_fc;
    *(uint **)(in_ECX + 0x20) = puVar3 + 1;
  }
  FUN_00466060();
  local_c4 = 0xf;
  local_c8 = (void *)0x0;
  local_d8 = 0;
  FUN_00401740(s_debug_network_009a0a1c,0xd);
  local_4 = 4;
  uVar4 = FUN_004601d0(&local_dc);
  local_4 = CONCAT31(local_4._1_3_,5);
  (**(code **)(*DAT_00b5a7d8 + 4))(uVar4);
  if (0xf < uStack_8c) {
    _free(pvStack_a0);
    return;
  }
  uStack_8c = 0xf;
  uStack_90 = 0;
  pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
  if (0xf < pvStack_ac) {
    _free(local_c0);
    return;
  }
  puStack_8 = (undefined1 *)0xffffffff;
  pvStack_ac = (void *)0xf;
  uStack_b0 = 0;
  local_c0 = (void *)((uint)local_c0 & 0xffffff00);
  if (0xf < local_c8) {
    _free(local_dc);
    return;
  }
  local_c8 = (void *)0xf;
  pvStack_cc = (void *)0x0;
  local_dc = (void *)((uint)local_dc & 0xffffff00);
  FUN_00401740(s_networkanalysis_009a0a2c,0xf);
  puStack_8 = (undefined1 *)0x6;
  FUN_0040bf70(auStack_e0,1);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,8);
  if (0xf < local_c8) {
    _free(local_dc);
    return;
  }
  local_c8 = (void *)0xf;
  pvStack_cc = (void *)0x0;
  local_dc = (void *)((uint)local_dc & 0xffffff00);
  FUN_00401740(s_networkanalysis__interval__009a0a3c,0x1a);
  (**(code **)(*DAT_00b5a7d8 + 4))(auStack_4c);
  uStack_e8 = 0xf;
  uStack_ec = 0;
  local_fc = (void *)((uint)local_fc & 0xffffff00);
  FUN_00401740(s_networkanalysis_save_009a0a58,0x14);
  pvStack_c._0_1_ = 9;
  uVar4 = FUN_004601d0(auStack_e0 + -0x20);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,10);
  (**(code **)(*DAT_00b5a7d8 + 4))(uVar4);
  if (0xf < pvStack_94) {
    _free(pvStack_a8);
    return;
  }
  pvStack_94 = (void *)0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < uStack_b4) {
    _free(local_c8);
    return;
  }
  uStack_b4 = 0xf;
  uStack_b8 = 0;
  local_c8 = (void *)((uint)local_c8 & 0xffffff00);
  uStack_10 = 8;
  if (0xf < uStack_ec) {
    _free(unaff_EBX);
    return;
  }
  uStack_ec = 0xf;
  uStack_f0 = 0;
  FUN_00401740(s_delayanalysis_save_009a0a70,0x12);
  uStack_10 = 0xb;
  uVar4 = FUN_004601d0(auStack_e0 + -0x24);
  uStack_10 = 0xc;
  (**(code **)(*DAT_00b5a7d8 + 4))(uVar4);
  if (0xf < uStack_98) {
    _free(pvStack_ac);
    return;
  }
  uStack_98 = 0xf;
  uStack_9c = 0;
  pvStack_ac = (void *)((uint)pvStack_ac & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(pvStack_cc);
    return;
  }
  uStack_b8 = 0xf;
  uStack_bc = 0;
  pvStack_cc = (void *)((uint)pvStack_cc & 0xffffff00);
  uStack_14 = 8;
  if (0xf < uStack_f0) {
    _free(unaff_ESI);
    return;
  }
  uStack_f0 = 0xf;
  uStack_f4 = 0;
  FUN_00401740(s_delayanalysis_clear_009a0a84,0x13);
  uStack_14 = 0xd;
  uVar4 = FUN_004601d0(auStack_e0 + -0x28);
  uStack_14 = 0xe;
  (**(code **)(*DAT_00b5a7d8 + 4))(uVar4);
  if (0xf < uStack_60) {
    _free(pvStack_74);
    return;
  }
  uStack_60 = 0xf;
  uStack_64 = 0;
  pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return;
  }
  uStack_80 = 0xf;
  uStack_84 = 0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  if (0xf < uStack_f4) {
    _free(unaff_EDI);
    return;
  }
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  if (uStack_44 < 0x10) {
    ExceptionList = pvStack_20;
    return;
  }
  _free(pvStack_58);
  return;
}


