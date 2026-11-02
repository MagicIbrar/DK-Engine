// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x8d0000-0x8dffff

// ==== FUN_008d083b @ 0x008d083b ====

int FUN_008d083b(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 local_5c [16];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_30;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_18 = 0;
  iVar1 = FUN_008c9d22();
  local_1c = iVar1;
  FUN_008f3cb2();
  if (iVar1 == 0) {
    return 0;
  }
  if (param_1 == 0) {
    return 0;
  }
  local_14 = *(int *)(iVar1 + 0x18);
  local_8 = param_1 + 0x10;
  if ((*(byte *)(iVar1 + 0x10) & 0x40) != 0) {
    FUN_008c98fa();
  }
  if ((*(byte *)(iVar1 + 0x10) & 1) != 0) {
    FUN_008c98fa();
  }
  iVar1 = FUN_008c9ee7(local_14);
  if (iVar1 == 0) {
    FUN_008c98fa();
  }
  local_10 = 0;
  for (iVar1 = param_2; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    if ((*(int *)(iVar1 + 8) != 0) && (*(int *)(*(int *)(iVar1 + 8) + 4) == 6)) {
      iVar2 = *(int *)(iVar1 + 0xc);
      if ((iVar2 == 0) || (*(int *)(*(int *)(iVar2 + 8) + 4) != 0xc)) {
        if (local_10 != 0) {
          FUN_008c98fa();
        }
      }
      else {
        local_10 = 1;
        iVar1 = iVar2;
      }
    }
  }
  iVar1 = FUN_008bf738(0x14);
  if (iVar1 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_008f3584(0,0,s_Stmts_00a1fda0);
  }
  if (local_10 == 0) {
    return 0;
  }
  iVar1 = FUN_008bf738(0x30);
  if (iVar1 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_008f3958(2,0,0,0);
  }
  iVar1 = local_c;
  if (local_c == 0) {
    return 0;
  }
  *(int *)(local_10 + 8) = local_c;
  iVar2 = FUN_008f352c(param_1);
  *(int *)(iVar1 + 0x14) = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = FUN_008bf738(0x40);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_008f3bba();
  }
  if (iVar2 == 0) {
    return 0;
  }
  *(int *)(iVar1 + 0x18) = iVar2;
  *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(local_1c + 0x10);
  if (*(int *)(local_1c + 0x14) != 0) {
    iVar1 = FUN_008f352c(*(int *)(local_1c + 0x14));
    *(int *)(iVar2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  if (local_14 != 0) {
    iVar1 = FUN_008f352c(local_14);
    *(int *)(iVar2 + 0x20) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  FUN_008c9d2e(*(undefined4 *)(iVar2 + 0x20),1);
  if (param_3 != 0) {
    if (*(int *)(iVar2 + 0x20) == 0) {
      FUN_008c98fa();
      param_3 = 0;
    }
    if (param_3 != 0) {
      iVar1 = FUN_008f352c(param_3);
      *(int *)(iVar2 + 0x34) = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
      do {
        iVar1 = *(int *)(param_3 + 8);
        if ((iVar1 != 0) && (*(int *)(iVar1 + 4) == 3)) {
          iVar1 = FUN_008f352c(iVar1);
          *(int *)(iVar2 + 0x30) = iVar1;
          if (iVar1 == 0) {
            return 0;
          }
        }
        param_3 = *(int *)(param_3 + 0xc);
      } while (param_3 != 0);
    }
  }
  if ((param_2 != 0) && (*(int *)(param_2 + 8) != 0)) {
    iVar1 = FUN_008f352c(param_2);
    *(int *)(iVar2 + 0x24) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar3 = FUN_008ce5ff(2,local_8,*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x24),
                       *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x20),10,&param_2,&local_18);
  iVar1 = param_2;
  if (iVar3 < 0) {
LAB_008d0ac8:
    FUN_008c98fa();
    return 0;
  }
  if (iVar3 == 0) {
    iVar3 = FUN_008c9fec(*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(param_2 + 0x20));
    if (iVar3 == 0) goto LAB_008d0ac8;
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(local_c + 0x24) = *(undefined4 *)(*(int *)(local_18 + 8) + 0x18);
  }
  else {
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(in_ECX + 0x58);
    iVar3 = FUN_008c9f5e(*(undefined4 *)(iVar2 + 0x20));
    *(int *)(iVar2 + 0x14) = iVar3;
    *(int *)(in_ECX + 0x58) = *(int *)(in_ECX + 0x58) + iVar3;
  }
  local_4c = *(undefined4 *)(iVar2 + 0x10);
  local_48 = *(undefined4 *)(iVar2 + 0x14);
  local_40 = 0;
  local_44 = 3;
  local_3c = FUN_008f352c(*(undefined4 *)(iVar2 + 0x20));
  local_30 = FUN_008f352c(param_3);
  FUN_008c9d2e(local_3c,0);
  uVar4 = FUN_008cecbc(param_1,local_5c);
  *(undefined4 *)(iVar2 + 0x2c) = uVar4;
  if (iVar1 == 0) {
    iVar1 = *(int *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(iVar1 + 0x20);
    iVar3 = FUN_008cafd3(local_c,0);
    *(int *)(in_ECX + 0x10) = iVar1;
    if (iVar3 < 0) {
      return 0;
    }
    *(int *)(in_ECX + 0x54) = *(int *)(in_ECX + 0x54) + 1;
  }
  *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x14) = *(undefined4 *)(local_8 + 8);
  *(int *)(in_ECX + 0x18) = iVar2;
  return local_10;
}


// ==== FUN_008d0bbc @ 0x008d0bbc ====

undefined4 FUN_008d0bbc(void *param_1)

{
  int iVar1;
  uint uVar2;
  void *_Memory;
  int iVar3;
  int iVar4;
  undefined4 extraout_EAX;
  int *piVar5;
  uint local_8;
  
  iVar1 = (int)param_1;
  if ((param_1 == (void *)0x0) || (*(int *)((int)param_1 + 4) != 0xd)) {
    return 0;
  }
  uVar2 = *(int *)((int)param_1 + 0x18) * *(int *)((int)param_1 + 0x14);
  _Memory = operator_new(uVar2 * 0x10);
  if ((_Memory != (void *)0x0) && (iVar3 = FUN_008cf35c(param_1,_Memory), -1 < iVar3)) {
    iVar3 = FUN_008bf738(0x50);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_008f3e67(0,0,0,0,1,(int)param_1 + 0x30);
    }
    if (iVar3 != 0) {
      if (*(int *)((int)param_1 + 0x10) != 0) {
        iVar4 = (**(code **)(**(int **)((int)param_1 + 0x10) + 4))();
        *(int *)(iVar3 + 0x10) = iVar4;
        if (iVar4 == 0) goto LAB_008d0cd1;
      }
      local_8 = 0;
      piVar5 = (int *)(iVar3 + 0x20);
      if (uVar2 != 0) {
        param_1 = _Memory;
        do {
          iVar4 = FUN_008bf738(0x14);
          if (iVar4 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_008f3584(0,0,s_Value_00a20198);
          }
          *piVar5 = iVar4;
          if (iVar4 == 0) goto LAB_008d0cd1;
          iVar4 = FUN_008bf738(0x40);
          if (iVar4 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_008f3f68(param_1,iVar1 + 0x30);
          }
          *(int *)(*piVar5 + 8) = iVar4;
          if (iVar4 == 0) goto LAB_008d0cd1;
          param_1 = (void *)((int)param_1 + 0x10);
          piVar5 = (int *)(*piVar5 + 0xc);
          local_8 = local_8 + 1;
        } while (local_8 < uVar2);
      }
      FUN_008ca999(iVar3);
    }
  }
LAB_008d0cd1:
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_008d0ce7 @ 0x008d0ce7 ====

int FUN_008d0ce7(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_008d0bbc(param_1);
  if (((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0x10), iVar1 != 0)) && (*(int *)(iVar1 + 4) == 9))
  {
    uVar2 = FUN_008c9ec3(iVar1);
    iVar1 = (int)((ulonglong)uVar2 >> 0x20);
    if ((int)uVar2 != 0) {
      iVar1 = FUN_008ccef6(param_2,*(int *)(*(int *)(iVar1 + 0x20) + 8) + 0x10,iVar1 + 0x30);
      if (iVar1 < 0) {
        return iVar1;
      }
      return 0;
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008d0d40 @ 0x008d0d40 ====

undefined4 FUN_008d0d40(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 in_ECX;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  int local_14;
  int local_10;
  uint local_c;
  undefined4 local_8;
  
  local_14 = 0;
  piVar3 = &local_14;
  local_8 = in_ECX;
  if (param_2 != 0) {
    while (*(int *)(param_2 + 8) != 0) {
      iVar2 = FUN_008bf738(0x14);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_008f3584(0,0,s_Stmts_00a1fda0);
      }
      *piVar3 = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
      iVar2 = FUN_008bf738(0x30);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_008f3958(0,0,0,0);
      }
      if (iVar2 == 0) {
        return 0;
      }
      *(int *)(*piVar3 + 8) = iVar2;
      piVar3 = (int *)(*piVar3 + 0xc);
      local_c = 1;
      local_10 = 0;
      if (param_1 != 0) {
        iVar4 = FUN_008f352c(param_1);
        *(int *)(iVar2 + 0x18) = iVar4;
        if (iVar4 == 0) {
          return 0;
        }
      }
      for (iVar4 = *(int *)(param_2 + 8); *(int *)(iVar4 + 4) != 3; iVar4 = *(int *)(iVar4 + 8)) {
        iVar5 = FUN_008bf738(0x18);
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_008f3aa3();
        }
        if (iVar5 == 0) {
          return 0;
        }
        *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x18) = iVar5;
        piVar1 = (int *)(iVar5 + 0x14);
        if (*(int *)(iVar4 + 0xc) == 0) {
          local_10 = 0xc00;
LAB_008d0e41:
          *piVar1 = 1;
        }
        else {
          iVar5 = FUN_008d0ce7(*(int *)(iVar4 + 0xc),piVar1);
          if (iVar5 < 0) {
            local_10 = 0xbf2;
            goto LAB_008d0e41;
          }
        }
        local_c = *piVar1 * local_c;
      }
      iVar5 = FUN_008f352c(iVar4);
      *(int *)(iVar2 + 0x14) = iVar5;
      if (iVar5 == 0) {
        return 0;
      }
      if (local_10 == 0xbf2) {
        uVar8 = *(undefined4 *)(iVar4 + 0x18);
        pcVar7 = s___s___array_dimensions_must_be_l_00a2082c;
        uVar6 = 0xbf2;
LAB_008d0ee0:
        FUN_008c98fa(local_8,iVar4 + 0x10,uVar6,pcVar7,uVar8);
        return 0;
      }
      if (local_10 == 0xc00) {
        uVar8 = *(undefined4 *)(iVar4 + 0x18);
        pcVar7 = s___s___array_dimensions_of_type_m_00a20868;
        uVar6 = 0xc00;
        goto LAB_008d0ee0;
      }
      if ((local_c == 0) || (0x10000 < local_c)) {
        uVar8 = *(undefined4 *)(iVar4 + 0x18);
        pcVar7 = s___s___array_dimension_must_be_be_00a20898;
        uVar6 = 0xbf3;
        goto LAB_008d0ee0;
      }
      iVar2 = FUN_008cafd3(iVar2,1);
      if (iVar2 < 0) {
        return 0;
      }
      param_2 = *(int *)(param_2 + 0xc);
      if (param_2 == 0) {
        return local_14;
      }
    }
  }
  return 0;
}


// ==== FUN_008d0ef0 @ 0x008d0ef0 ====

undefined4 FUN_008d0ef0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_008bf738(0x14);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3584(param_2,0,&DAT_00a208cc);
  }
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_008d0d40(param_1,iVar1);
    *(undefined4 *)(iVar1 + 8) = 0;
  }
  return uVar2;
}


// ==== FUN_008d0f38 @ 0x008d0f38 ====

undefined4 FUN_008d0f38(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = param_1;
  if (param_1 != 0) {
    iVar2 = FUN_008d0ce7(param_2,&param_1);
    if (iVar2 < 0) {
      FUN_008c98fa();
    }
    else if ((param_1 == 0) || (4 < param_1)) {
      FUN_008c98fa();
    }
    else {
      iVar2 = FUN_008bf738(0x24);
      if (iVar2 != 0) {
        uVar3 = FUN_008f3b3d(1,*(undefined4 *)(uVar1 + 0x14),1,param_1,0);
        return uVar3;
      }
    }
  }
  return 0;
}


// ==== FUN_008d0fbe @ 0x008d0fbe ====

undefined4 FUN_008d0fbe(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = param_1;
  if (param_1 != 0) {
    iVar2 = FUN_008d0ce7(param_2,&param_2);
    if ((iVar2 < 0) || (iVar2 = FUN_008d0ce7(param_3,&param_1), iVar2 < 0)) {
      FUN_008c98fa();
    }
    else if ((param_2 == 0) || (((4 < param_2 || (param_1 == 0)) || (4 < param_1)))) {
      FUN_008c98fa();
    }
    else {
      iVar2 = FUN_008bf738(0x24);
      if (iVar2 != 0) {
        uVar3 = FUN_008f3b3d(2,*(undefined4 *)(uVar1 + 0x14),param_2,param_1,0);
        return uVar3;
      }
    }
  }
  return 0;
}


// ==== FUN_008d1067 @ 0x008d1067 ====

int FUN_008d1067(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = FUN_008d0ce7(param_2,&param_2);
  if (iVar3 < 0) {
    FUN_008c98fa();
  }
  else {
    iVar3 = FUN_008bf738(0x18);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_008f3abd(0,param_2);
    }
    if (iVar3 != 0) {
      piVar1 = &param_1;
      iVar2 = param_1;
      while ((iVar2 != 0 && (*(int *)(*piVar1 + 4) == 8))) {
        piVar1 = (int *)(*piVar1 + 0x10);
        iVar2 = *piVar1;
      }
      *(int *)(iVar3 + 0x10) = *piVar1;
      *piVar1 = iVar3;
      return param_1;
    }
  }
  return 0;
}


// ==== FUN_008d10e0 @ 0x008d10e0 ====

int FUN_008d10e0(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 in_ECX;
  uint uVar5;
  undefined4 uVar6;
  char *pcVar7;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_1[1] != 0xd) {
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  if (*(int *)(param_2 + 4) != 0xd) {
    return 0;
  }
  iVar4 = param_2 + 0x30;
  iVar1 = FUN_008bf738(0x50);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3e67(0,0x16,0,0,1,iVar4);
  }
  if (iVar1 == 0) {
    return 0;
  }
  iVar3 = param_1[4];
  uVar6 = *(undefined4 *)(param_2 + 0x10);
  if (iVar3 == 0) {
LAB_008d12e9:
    pcVar7 = s_array_expected_00a209cc;
    uVar6 = 0xbcd;
  }
  else {
    if (*(int *)(iVar3 + 4) == 8) {
      if (*(int *)(iVar3 + 0x10) != 0) {
        iVar2 = (**(code **)(**(int **)(iVar3 + 0x10) + 4))();
        *(int *)(iVar1 + 0x10) = iVar2;
        if (iVar2 == 0) {
          return 0;
        }
      }
      uVar5 = *(uint *)(iVar3 + 0x14);
    }
    else {
      if (*(int *)(iVar3 + 4) != 9) goto LAB_008d12e9;
      if (*(int *)(iVar3 + 0x10) == 1) {
        iVar2 = FUN_008bf738(0x24);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_008f3b3d(0,*(undefined4 *)(iVar3 + 0x14),1,1,*(uint *)(iVar3 + 0x20) & 0x200);
        }
        *(int *)(iVar1 + 0x10) = iVar2;
        if (iVar2 == 0) {
          return 0;
        }
        uVar5 = *(uint *)(iVar3 + 0x1c);
      }
      else {
        if (*(int *)(iVar3 + 0x10) != 2) goto LAB_008d12e9;
        iVar2 = FUN_008bf738(0x24);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_008f3b3d(1,*(undefined4 *)(iVar3 + 0x14),1,*(undefined4 *)(iVar3 + 0x1c),
                               *(uint *)(iVar3 + 0x20) & 0x200);
        }
        *(int *)(iVar1 + 0x10) = iVar2;
        if (iVar2 == 0) {
          return 0;
        }
        uVar5 = *(uint *)(iVar3 + 0x18);
      }
    }
    iVar3 = FUN_008c9ec3(uVar6);
    if (iVar3 != 0) {
      iVar3 = (**(code **)(*param_1 + 4))();
      *(int *)(iVar1 + 0x20) = iVar3;
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = FUN_008ca87b(param_2);
      if (iVar3 == 0) {
        iVar4 = FUN_008f352c(param_2);
        *(int *)(iVar1 + 0x24) = iVar4;
        if (iVar4 == 0) {
          return 0;
        }
      }
      else {
        iVar3 = FUN_008d0ce7(param_2,&param_2);
        if (iVar3 < 0) {
          return 0;
        }
        if (uVar5 <= param_2) {
          FUN_008c98fa(in_ECX,iVar4,0xbd6,s_array_index_out_of_bounds_00a204dc);
          param_2 = 0;
        }
        iVar3 = FUN_008c9f5e(*(undefined4 *)(iVar1 + 0x10));
        iVar2 = FUN_008bf738(0x40);
        if (iVar2 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_008f3fb4(2,iVar3 * param_2,iVar4);
        }
        *(int *)(iVar1 + 0x24) = iVar4;
        if (iVar4 == 0) {
          return 0;
        }
        *(undefined4 *)(iVar1 + 0x1c) = 0x17;
      }
      FUN_008ca999(iVar1);
      return iVar1;
    }
    pcVar7 = s_scalar_expected_00a209dc;
    uVar6 = 0xbeb;
  }
  FUN_008c98fa(in_ECX,iVar4,uVar6,pcVar7);
  return 0;
}


// ==== FUN_008d130a @ 0x008d130a ====

int FUN_008d130a(int param_1,int *param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined8 uVar4;
  undefined4 uVar5;
  int *piVar6;
  char *pcVar7;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  piVar1 = param_2;
  local_14 = (int *)0x0;
  local_18 = (int *)0x0;
  local_c = (int *)0x0;
  local_10 = (int *)0x0;
  if ((param_2 != (int *)0x0) && (param_2[1] != 0xd)) {
    return 0;
  }
  if (param_3 == (int *)0x0) {
    if (param_2 != (int *)0x0) goto LAB_008d1349;
    param_2 = (int *)(in_ECX + 0x20);
  }
  else {
    param_2 = param_3;
    if (param_3[1] != 0xd) {
      return 0;
    }
LAB_008d1349:
    param_2 = param_2 + 0xc;
  }
  local_8 = in_ECX;
  iVar2 = FUN_008bf738(0x50);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_008f3e67(0,param_1,0,0,param_4,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 4))();
    *(int *)(iVar2 + 0x20) = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
  }
  iVar3 = 0x15;
  if ((((((param_1 == 0x1c) || (param_1 == 0x1d)) || (param_1 == 0x1e)) ||
       ((param_1 == 0x1f || (param_1 == 0x20)))) || (param_1 == 0x21)) || (param_1 == 0x22)) {
    if (param_1 == 0x1c) {
      piVar6 = (int *)0x7;
LAB_008d1421:
      param_1 = iVar3;
    }
    else {
      if (param_1 == 0x1d) {
        piVar6 = (int *)0x8;
        goto LAB_008d1421;
      }
      if (param_1 == 0x1e) {
        piVar6 = (int *)0x9;
        goto LAB_008d1421;
      }
      if (param_1 == 0x1f) {
        piVar6 = (int *)0xa;
        goto LAB_008d1421;
      }
      if (param_1 == 0x20) {
        piVar6 = (int *)0xb;
        goto LAB_008d1421;
      }
      if (param_1 == 0x21) {
        iVar3 = 1;
        piVar6 = (int *)0x2;
        goto LAB_008d1421;
      }
      if (param_1 == 0x22) {
        iVar3 = 1;
        piVar6 = (int *)0x3;
        goto LAB_008d1421;
      }
      piVar6 = param_3;
    }
    iVar3 = FUN_008d130a(piVar6,piVar1,param_3,0);
    *(int *)(iVar2 + 0x24) = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
    *(int *)(iVar2 + 0x1c) = param_1;
  }
  else if (param_3 != (int *)0x0) {
    iVar3 = (**(code **)(*param_3 + 4))();
    *(int *)(iVar2 + 0x24) = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
  }
  if (*(int *)(iVar2 + 0x20) != 0) {
    local_18 = *(int **)(*(int *)(iVar2 + 0x20) + 0x10);
    local_14 = local_18;
  }
  if ((((param_1 != 0) && (param_1 != 1)) &&
      ((param_1 != 0x14 && (((param_1 != 0x15 && (param_1 != 0x10)) && (param_1 != 0x11)))))) &&
     (((local_14 == (int *)0x0 || (local_14[1] != 9)) ||
      (iVar3 = FUN_008c9ee7(local_14), iVar3 == 0)))) {
    pcVar7 = s_scalar__vector__or_matrix_expect_00a20a50;
    uVar5 = 0xbce;
    goto LAB_008d170a;
  }
  piVar1 = local_14;
  if (((param_1 == 2) || (param_1 == 3)) || ((param_1 == 0x14 || (param_1 == 0x15)))) {
    iVar3 = FUN_008c9e50(local_14);
    if (iVar3 == 0) {
      uVar4 = FUN_008ca7ff(*(undefined4 *)(iVar2 + 0x20));
      if ((int)uVar4 == 0) {
        iVar3 = *(int *)(*(int *)((int)((ulonglong)uVar4 >> 0x20) + 0x10) + 0x10);
        if (((iVar3 == 3) || (iVar3 == 4)) && (iVar3 = FUN_008c9ee7(piVar1), iVar3 == 0)) {
          pcVar7 = s_object_assignments_are_not_allow_00a20a1c;
          uVar5 = 0xbf9;
          goto LAB_008d170a;
        }
        goto LAB_008d150b;
      }
    }
    pcVar7 = s_l_value_specifies_const_object_00a209ec;
    uVar5 = 0xbd1;
LAB_008d170a:
    FUN_008c98fa(local_8,param_2,uVar5,pcVar7);
    return 0;
  }
LAB_008d150b:
  if (*(int *)(iVar2 + 0x24) != 0) {
    local_10 = *(int **)(*(int *)(iVar2 + 0x24) + 0x10);
    local_c = local_10;
  }
  if ((param_1 == 0x14) || (param_1 == 0x15)) {
    iVar3 = FUN_008cbaba(piVar1,local_c,0);
    if (iVar3 == 0) {
      FUN_008cbdf2(param_2,0,piVar1,local_c,0);
      return 0;
    }
    if (piVar1 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar1 + 4))();
      *(int *)(iVar2 + 0x10) = iVar3;
      if (iVar3 == 0) {
        return 0;
      }
    }
    local_10 = piVar1;
  }
  else if (param_1 == 0) {
    if (piVar1 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar1 + 4))();
      *(int *)(iVar2 + 0x10) = iVar3;
      if (iVar3 == 0) {
        return 0;
      }
    }
  }
  else {
    if (((param_1 != 4) && (param_1 != 5)) &&
       ((param_1 != 6 && (((param_1 != 2 && (param_1 != 3)) && (param_1 != 1)))))) {
      if (((param_1 == 0xc) || (param_1 == 0xd)) ||
         ((param_1 == 0xe ||
          (((param_1 == 0xf || (param_1 == 0x10)) ||
           ((param_1 == 0x11 || ((param_1 == 0x12 || (param_1 == 0x13)))))))))) {
        iVar3 = FUN_008cc1d3(piVar1,local_c,&local_18,&local_10,(int *)(iVar2 + 0x10));
        if (-1 < iVar3) {
          *(undefined4 *)(*(int *)(iVar2 + 0x10) + 0x14) = 0;
          goto LAB_008d1666;
        }
      }
      else {
        iVar3 = FUN_008cc1d3(piVar1,local_c,&local_18,&local_10,iVar2 + 0x10);
        if (-1 < iVar3) goto LAB_008d1666;
      }
      pcVar7 = s_type_mismatch_00a20a0c;
      uVar5 = 0xbcc;
      goto LAB_008d170a;
    }
    if (piVar1 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar1 + 4))();
      *(int *)(iVar2 + 0x10) = iVar3;
      if (iVar3 == 0) {
        return 0;
      }
    }
    FUN_008c9d2e(*(undefined4 *)(iVar2 + 0x10),1);
  }
LAB_008d1666:
  if ((*(int *)(iVar2 + 0x20) != 0) && (piVar1 != local_18)) {
    uVar4 = FUN_008c9fec(piVar1,local_18);
    if ((int)uVar4 == 0) {
      iVar3 = FUN_008cedc3(local_18,(int)((ulonglong)uVar4 >> 0x20),0,0);
      if (iVar3 == 0) {
        return 0;
      }
      *(int *)(iVar2 + 0x20) = iVar3;
    }
  }
  if ((*(int *)(iVar2 + 0x24) != 0) && (local_c != local_10)) {
    uVar4 = FUN_008c9fec(local_c,local_10);
    if ((int)uVar4 == 0) {
      iVar3 = FUN_008cedc3(local_10,(int)((ulonglong)uVar4 >> 0x20),0,0);
      if (iVar3 == 0) {
        return 0;
      }
      *(int *)(iVar2 + 0x24) = iVar3;
    }
  }
  if (*(int *)(iVar2 + 0x10) == 0) {
    *(undefined4 *)(iVar2 + 0x10) = 0;
  }
  FUN_008ca999(iVar2);
  iVar3 = FUN_008ca87b(iVar2);
  if (iVar3 == 0) {
    return iVar2;
  }
  iVar3 = FUN_008d0bbc(iVar2);
  if (iVar3 == 0) {
    return iVar2;
  }
  return iVar3;
}


// ==== FUN_008d1723 @ 0x008d1723 ====

undefined4 FUN_008d1723(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x18) == 0) {
    return 0;
  }
  iVar1 = FUN_008bf738(0x24);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3da4();
  }
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0x10) = 1;
  iVar2 = *(int *)(in_ECX + 0x18);
  if (param_1 == 0) {
    if (*(int *)(iVar2 + 0x20) == 0) goto LAB_008d17b3;
  }
  else if (*(int *)(iVar2 + 0x20) != 0) {
    uVar3 = FUN_008d130a(0x15,*(undefined4 *)(iVar2 + 0x2c),param_1,1);
    *(undefined4 *)(iVar1 + 0x14) = uVar3;
    goto LAB_008d17b3;
  }
  FUN_008c98fa();
LAB_008d17b3:
  iVar2 = FUN_008bf738(0x14);
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = FUN_008f3584(iVar1,0,s_Stmts_00a1fda0);
  return uVar3;
}


// ==== FUN_008d17d7 @ 0x008d17d7 ====

int FUN_008d17d7(int param_1,uint *param_2,uint param_3,int param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int extraout_ECX;
  char *pcVar10;
  undefined8 uVar11;
  char *pcVar12;
  char *local_4c [4];
  char *local_3c;
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  char *local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_34 = s_global_variables_00a20ef0;
  local_30 = s_structure_members_00a20edc;
  local_2c = s_function_parameters_00a20ec8;
  local_28 = s_local_variables_009fe934;
  local_24 = s_loop_control_variables_00a20eb0;
  local_20 = s_annotation_members_00a20e9c;
  local_4c[0] = s_initial_value_00a20f04;
  local_4c[1] = s_initializer_00a20e90;
  local_4c[2] = s_default_value_00a20e80;
  local_4c[3] = s_initial_value_00a20f04;
  local_3c = s_initial_value_00a20f04;
  local_38 = s_value_00a20e78;
  local_1c = FUN_008c9d22();
  if (local_1c == 0) {
    return 0;
  }
  if (*(int *)(extraout_ECX + 0x10) == 0) {
    return 0;
  }
  if (param_1 == 0) {
    return 0;
  }
  local_18 = *(uint *)(local_1c + 0x18);
  iVar2 = FUN_008bf738(0x14);
  if (iVar2 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_008f3584(0,0,s_Stmts_00a1fda0);
  }
  if (local_10 == 0) {
    return 0;
  }
  iVar2 = FUN_008bf738(0x30);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_008f3958(1,0,0,0);
  }
  if (iVar2 == 0) {
    return 0;
  }
  *(int *)(local_10 + 8) = iVar2;
  local_c = iVar2;
  iVar3 = FUN_008bf738(0x40);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_008f3cb2();
  }
  if (iVar3 == 0) {
    return 0;
  }
  *(int *)(iVar2 + 0x18) = iVar3;
  if (param_3 != 0) {
    iVar4 = FUN_008f352c(param_3);
    *(int *)(iVar2 + 0x1c) = iVar4;
    if (iVar4 == 0) {
      return 0;
    }
  }
  if (param_2 != (uint *)0x0) {
    iVar4 = FUN_008f352c(param_2);
    *(int *)(iVar3 + 0x30) = iVar4;
    if (iVar4 == 0) {
      return 0;
    }
    do {
      iVar4 = *(int *)((int)param_2 + 8);
      if ((iVar4 != 0) && (*(int *)(iVar4 + 4) == 3)) {
        iVar4 = FUN_008f352c(iVar4);
        *(int *)(iVar3 + 0x2c) = iVar4;
        if (iVar4 == 0) {
          return 0;
        }
      }
      param_2 = *(uint **)((int)param_2 + 0xc);
    } while (param_2 != (uint *)0x0);
  }
  if ((param_4 != 0) && (*(int *)(param_4 + 4) != 0xd)) {
    uVar5 = FUN_008cc553();
    *(undefined4 *)(iVar3 + 0x24) = uVar5;
  }
  param_3 = 1;
  param_2 = (uint *)0x0;
  local_14 = 0;
  if (local_18 != 0) {
    iVar4 = FUN_008f352c(local_18);
    *(int *)(iVar3 + 0x20) = iVar4;
    if (iVar4 == 0) {
      return 0;
    }
  }
  if (*(int *)(param_1 + 4) != 3) {
    do {
      iVar2 = FUN_008bf738(0x18);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_008f3aa3();
      }
      if (iVar2 == 0) {
        return 0;
      }
      if (param_2 != (uint *)0x0) {
        local_14 = 0xc01;
      }
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0x20);
      puVar1 = (uint *)(iVar2 + 0x14);
      if (*(int *)(param_1 + 0xc) == 0) {
        param_2 = puVar1;
LAB_008d19d2:
        *puVar1 = 1;
      }
      else {
        iVar4 = FUN_008d0ce7();
        if (iVar4 < 0) {
          local_14 = 0xbf2;
          goto LAB_008d19d2;
        }
      }
      param_3 = *puVar1 * param_3;
      *(int *)(iVar3 + 0x20) = iVar2;
      param_1 = *(int *)(param_1 + 8);
    } while (*(int *)(param_1 + 4) != 3);
    iVar2 = local_c;
  }
  iVar4 = FUN_008f352c(param_1);
  *(int *)(iVar2 + 0x14) = iVar4;
  if (iVar4 == 0) {
    return 0;
  }
  iVar2 = *(int *)(*(int *)(local_8 + 0x10) + 0x10);
  iVar4 = param_1 + 0x10;
  if (local_14 == 0xbf2) {
    uVar5 = *(undefined4 *)(param_1 + 0x18);
    uVar11 = 0xa2082c00000bf2;
LAB_008d20e7:
    FUN_008c98fa(local_8,iVar4,uVar11,uVar5);
    return 0;
  }
  if (local_14 == 0xc01) {
    uVar5 = *(undefined4 *)(param_1 + 0x18);
    uVar11 = 0xa20ac400000c01;
    goto LAB_008d20e7;
  }
  if (param_2 != (uint *)0x0) {
    if ((((iVar2 != 0) && (iVar2 != 3)) && (iVar2 != 4)) && (iVar2 != 5)) {
      pcVar10 = local_4c[iVar2 + 6];
      uVar11 = CONCAT44(*(undefined4 *)(param_1 + 0x18),s___s___array_dimensions_of__s_mus_00a20e48)
      ;
      uVar5 = 0xc00;
      goto LAB_008d1a5d;
    }
    iVar6 = FUN_008c9f5e(local_18);
    local_18 = iVar6 * param_3;
    if (iVar6 * param_3 == 0) {
      *param_2 = 0;
      param_3 = 0;
    }
    else {
      iVar6 = *(int *)(iVar3 + 0x24);
      if ((iVar6 == 0) || (*(int *)(iVar6 + 4) != 0xd)) {
        pcVar10 = local_4c[iVar2];
        uVar11 = CONCAT44(*(undefined4 *)(param_1 + 0x18),s___s___implicit_array_missing__s_00a20dfc
                         );
        uVar5 = 0xc02;
LAB_008d1a5d:
        FUN_008c98fa(local_8,iVar4,uVar5,uVar11,pcVar10);
        return 0;
      }
      uVar7 = FUN_008c9f5e(*(undefined4 *)(iVar6 + 0x10));
      if (uVar7 % local_18 != 0) {
        pcVar10 = local_4c[iVar2];
        uVar11 = CONCAT44(*(undefined4 *)(param_1 + 0x18),
                          s___s___implicit_array_type_does_n_00a20e1c);
        uVar5 = 0xc03;
        goto LAB_008d1a5d;
      }
      *param_2 = uVar7 / local_18;
      param_3 = (uVar7 / local_18) * param_3;
    }
  }
  if ((param_3 == 0) || (0x10000 < param_3)) {
    uVar5 = *(undefined4 *)(param_1 + 0x18);
    uVar11 = 0xa2089800000bf3;
    goto LAB_008d20e7;
  }
  iVar6 = FUN_008c9f5e(*(undefined4 *)(iVar3 + 0x20));
  *(int *)(iVar3 + 0x14) = iVar6;
  *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(*(int *)(local_8 + 0x10) + 0x10);
  if (*(int *)(*(int *)(local_8 + 0x10) + 0x10) == 1) {
    *(undefined4 *)(iVar3 + 0x10) = 0xffffffff;
  }
  else {
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(local_8 + 0x58);
    *(int *)(local_8 + 0x58) = *(int *)(local_8 + 0x58) + iVar6;
  }
  param_3 = *(uint *)(local_1c + 0x10);
  if (*(int *)(local_1c + 0x14) != 0) {
    FUN_008c98fa(local_8,iVar4,0xbdf,s___s____s_cannot_be_target_specif_00a20dd8,
                 *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6]);
  }
  if ((param_3 & 0x100) != 0) {
    FUN_008c98fa(local_8,iVar4,0xbef,s___s____s_cannot_be_declared__inl_00a20db0,
                 *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6]);
  }
  if (iVar2 == 1) {
    iVar6 = FUN_008c9e50(*(undefined4 *)(iVar3 + 0x20));
    if (iVar6 != 0) {
      FUN_008c98fa(local_8,iVar4,0xbdb,s___s____s_cannot_be_declared__con_00a20d8c,
                   *(undefined4 *)(param_1 + 0x18),s_structure_members_00a20edc);
      goto LAB_008d1bb4;
    }
LAB_008d1c98:
    if ((((param_3 & 2) != 0) && (iVar2 != 3)) && (iVar2 != 4)) {
      FUN_008c98fa(local_8,iVar4,0xbbf,s___s____s_cannot_be_declared__sta_00a20cb8,
                   *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6]);
      param_3 = param_3 & 0xfffffffd;
    }
    if ((param_3 & 0x40) != 0) {
      if (iVar2 != 2) {
        FUN_008c98fa(local_8,iVar4,0xbe7,s___s____s_cannot_be_declared__uni_00a20c90,
                     *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6]);
        param_3 = param_3 & 0xffffffbf;
      }
      if (((param_3 & 0x40) != 0) && ((param_3 & 0x20) != 0)) {
        FUN_008c98fa(local_8,iVar4,0xbf6,s___s____s_cannot_be_declared__uni_00a20c64,
                     *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6]);
        param_3 = param_3 & 0xffffffbf;
      }
    }
    if ((param_3 & 1) != 0) {
      FUN_008c98fa(local_8,iVar4,0xbbe,s___s____s_cannot_be_declared__ext_00a20c3c,
                   *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6]);
      param_3 = param_3 & 0xfffffffe;
    }
    if ((param_3 & 8) != 0) {
      FUN_008c98fa(local_8,iVar4,0xbee,s___s____s_cannot_be_declared__sha_00a20c14,
                   *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6]);
      param_3 = param_3 & 0xfffffff7;
    }
  }
  else {
LAB_008d1bb4:
    if (iVar2 == 2) {
      if (((param_3 & 0x10) != 0) ||
         (iVar6 = FUN_008c9e50(*(undefined4 *)(iVar3 + 0x20)), iVar6 == 0)) goto LAB_008d1c98;
      FUN_008c98fa(local_8,iVar4,0xbe6,s___s___output_paramaters_cannot_b_00a20d58,
                   *(undefined4 *)(param_1 + 0x18));
    }
    if (((iVar2 == 3) || (iVar2 == 4)) &&
       (iVar6 = FUN_008c9ee7(*(undefined4 *)(iVar3 + 0x20)), iVar6 == 0)) {
      FUN_008c98fa(local_8,iVar4,0xbde,s___s____s_must_be_numeric_00a20d3c,
                   *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6]);
    }
    if (iVar2 != 0) goto LAB_008d1c98;
    if ((param_3 & 2) == 0) {
LAB_008d1c8f:
      param_3 = param_3 | 0x41;
    }
    else {
      if ((param_3 & 1) != 0) {
        FUN_008c98fa(local_8,iVar4,0xbbf,s___s___extern__s_cannot_be_declar_00a20d10,
                     *(undefined4 *)(param_1 + 0x18),s_global_variables_00a20ef0);
        param_3 = param_3 & 0xfffffffd;
      }
      if ((param_3 & 2) == 0) goto LAB_008d1c8f;
      if ((param_3 & 0x40) != 0) {
        FUN_008c98fa(local_8,iVar4,0xbbf,s___s___uniform__s_cannot_be_decla_00a20ce0,
                     *(undefined4 *)(param_1 + 0x18),s_global_variables_00a20ef0);
        param_3 = param_3 & 0xfffffffd;
      }
      if ((param_3 & 2) == 0) goto LAB_008d1c8f;
    }
  }
  if (((((param_3 & 4) != 0) && (iVar2 != 3)) && (iVar2 != 4)) && (iVar2 != 2)) {
    FUN_008c98fa(local_8,iVar4,0xbc0,s___s____s_cannot_be_declared__vol_00a20bec,
                 *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6]);
    param_3 = param_3 & 0xfffffffb;
  }
  if (iVar2 == 5) {
    FUN_008c9d2e();
    param_3 = param_3 | 0x40;
  }
  local_18 = 0;
  *(uint *)(iVar3 + 0x1c) = param_3;
  if (param_4 == 0) {
    if ((((iVar2 == 0) || (iVar2 == 3)) || (iVar2 == 4)) && ((param_3 & 2) != 0)) {
      uVar5 = FUN_008cc2d1(5,0,0,iVar4);
      goto LAB_008d1e53;
    }
  }
  else {
    if (*(int *)(param_4 + 4) == 0xd) {
      uVar5 = 0;
      iVar6 = param_4;
    }
    else {
      iVar6 = *(int *)(iVar3 + 0x24);
      if (iVar6 == 0) {
        param_4 = 0;
      }
      else {
        param_4 = *(undefined4 *)(iVar6 + 0x10);
      }
      iVar8 = FUN_008c9f5e(param_4);
      uVar5 = 1;
      if (*(int *)(iVar3 + 0x14) != iVar8) {
        FUN_008cbdf2(iVar4,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(iVar3 + 0x20),param_4,1);
        *(undefined4 *)(iVar3 + 0x24) = 0;
        goto LAB_008d1e56;
      }
    }
    uVar5 = FUN_008cedc3(*(undefined4 *)(iVar3 + 0x20),iVar6,uVar5);
LAB_008d1e53:
    *(undefined4 *)(iVar3 + 0x24) = uVar5;
  }
LAB_008d1e56:
  if (*(int *)(iVar3 + 0x24) == 0) {
    if (iVar2 == 0) {
      iVar6 = FUN_008c9e50(*(undefined4 *)(iVar3 + 0x20));
      if (iVar6 == 0) goto LAB_008d2055;
      if ((param_3 & 2) == 0) goto LAB_008d1fe5;
    }
    else {
LAB_008d1fe5:
      if ((((iVar2 != 3) && (iVar2 != 4)) ||
          (iVar6 = FUN_008c9e50(*(undefined4 *)(iVar3 + 0x20)), iVar6 == 0)) && (iVar2 != 5))
      goto LAB_008d2020;
    }
    FUN_008c98fa(local_8,iVar4,0xbc4,s___s___missing__s_00a20b3c,*(undefined4 *)(param_1 + 0x18),
                 local_4c[iVar2]);
LAB_008d2020:
    if ((((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) || (*(int *)(iVar3 + 0x2c) == 0))
    goto LAB_008d2055;
    FUN_008c98fa(local_8,iVar4,0xbe3,s___s____s_cannot_have_semantics_00a20b1c,
                 *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6]);
  }
  else {
    if (iVar2 == 1) {
      pcVar12 = s_initializer_00a20e90;
      uVar11 = CONCAT44(s_structure_members_00a20edc,*(undefined4 *)(param_1 + 0x18));
      pcVar10 = s___s____s_cannot_have__ss_00a20bd0;
    }
    else {
      if ((iVar2 != 2) || (iVar6 = FUN_008c9ee7(*(undefined4 *)(iVar3 + 0x20)), iVar6 != 0)) {
        if (((param_3 & 0x10) == 0) && ((param_3 & 0x20) != 0)) {
          FUN_008c98fa(local_8,iVar4,0xbe5,s___s___output_only__s_cannot_have_00a20b78,
                       *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6],local_4c[iVar2]);
        }
        else if (((param_3 & 0x50) == 0) ||
                (iVar6 = FUN_008ca87b(*(undefined4 *)(iVar3 + 0x24)), iVar6 != 0)) {
          iVar6 = FUN_008cbaba(*(undefined4 *)(iVar3 + 0x20),
                               *(undefined4 *)(*(int *)(iVar3 + 0x24) + 0x10),0);
          if (iVar6 != 0) {
            if ((param_3 & 0x40) != 0) {
              uVar5 = FUN_008d0bbc(*(undefined4 *)(iVar3 + 0x24));
              *(undefined4 *)(iVar3 + 0x28) = uVar5;
            }
            if (((param_3 & 0x50) == 0) &&
               (iVar6 = FUN_008c9e50(*(undefined4 *)(iVar3 + 0x20)), iVar6 != 0)) {
              uVar5 = FUN_008d0bbc(*(undefined4 *)(iVar3 + 0x24));
            }
            else {
              uVar5 = 0;
              if (((param_3 & 0x10) != 0) || ((param_3 & 0x40) == 0)) {
                uVar5 = *(undefined4 *)(iVar3 + 0x24);
                *(undefined4 *)(iVar3 + 0x24) = 0;
                uVar9 = FUN_008cecbc();
                local_18 = FUN_008d130a(0x14,uVar9,uVar5,1);
                goto LAB_008d2020;
              }
            }
            *(undefined4 *)(iVar3 + 0x24) = uVar5;
            goto LAB_008d2020;
          }
          FUN_008cbdf2(iVar4,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(iVar3 + 0x20),
                       *(undefined4 *)(*(int *)(iVar3 + 0x24) + 0x10),0);
        }
        else {
          FUN_008c98fa(local_8,iVar4,0xbc3,s___s____s_must_be_a_literal_expre_00a20b50,
                       *(undefined4 *)(param_1 + 0x18),local_4c[iVar2]);
        }
        *(undefined4 *)(iVar3 + 0x24) = 0;
        goto LAB_008d2020;
      }
      pcVar12 = s_default_value_00a20e80;
      uVar11 = CONCAT44(s_function_parameters_00a20ec8,*(undefined4 *)(param_1 + 0x18));
      pcVar10 = s___s___non_numeric_uniform__s_can_00a20ba0;
    }
    FUN_008c98fa(local_8,iVar4,0xbc1,pcVar10,uVar11,pcVar12);
  }
  *(undefined4 *)(iVar3 + 0x24) = 0;
LAB_008d2055:
  if (((*(int *)(local_c + 0x1c) != 0) && (iVar2 != 0)) && (iVar2 != 2)) {
    FUN_008c98fa(local_8,iVar4,0xbe0,s___s____s_cannot_have_annotations_00a20af8,
                 *(undefined4 *)(param_1 + 0x18),local_4c[iVar2 + 6]);
    *(undefined4 *)(local_c + 0x1c) = 0;
  }
  iVar2 = FUN_008cafd3();
  if (iVar2 < 0) {
    return 0;
  }
  if (local_18 != 0) {
    iVar2 = FUN_008ca9e1(local_18);
    *(int *)(local_10 + 0xc) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  return local_10;
}


// ==== FUN_008d20fc @ 0x008d20fc ====

int FUN_008d20fc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  int in_ECX;
  bool bVar8;
  char *pcVar9;
  int local_30;
  int local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 0;
  local_1c = 0;
  local_18 = 0;
  local_2c = 0;
  local_30 = 0;
  if ((param_1 == 0) || (*(int *)(param_1 + 4) != 3)) {
    return 0;
  }
  iVar6 = param_1 + 0x10;
  if (*(int *)(in_ECX + 0x18) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x1c);
  }
  uVar5 = 6;
  if (param_3 != 0) {
    uVar5 = 0x16;
  }
  local_c = iVar6;
  local_8 = in_ECX;
  iVar4 = FUN_008ce5ff(2,iVar6,uVar3,param_2,*(undefined4 *)(in_ECX + 0x10),uVar5,&local_14,
                       &local_18);
  bVar8 = iVar4 == 0;
  if (iVar4 < 0) {
    return 0;
  }
  if (param_3 == 0) {
    if (bVar8) goto LAB_008d2224;
    iVar4 = FUN_008cb11d(iVar6,param_2,&local_1c,&local_18);
    if (iVar4 < 0) {
      return 0;
    }
    if (iVar4 == 0) {
      bVar8 = true;
      goto LAB_008d21a5;
    }
LAB_008d21a9:
    iVar4 = FUN_008ce5ff(2,iVar6,0,0,*(undefined4 *)(local_8 + 0x10),2,&local_14,&local_18);
    if (iVar4 < 0) {
      return 0;
    }
    if (iVar4 == 0) {
      bVar8 = true;
    }
  }
  else {
LAB_008d21a5:
    if (!bVar8) goto LAB_008d21a9;
  }
  if (param_3 == 0) {
    if (!bVar8) {
      iVar4 = FUN_008cb11d(iVar6,0,&local_1c,&local_18);
      if (iVar4 < 0) {
        return 0;
      }
      if (iVar4 != 0) goto LAB_008d21fc;
      bVar8 = true;
      goto LAB_008d21f8;
    }
  }
  else {
LAB_008d21f8:
    if (!bVar8) {
LAB_008d21fc:
      FUN_008c98fa(local_8,iVar6,0xbbc,s_undeclared_identifier___s__00a20298,
                   *(undefined4 *)(param_1 + 0x18));
      return 0;
    }
  }
  if (local_1c != 0) {
    local_14 = local_1c;
  }
LAB_008d2224:
  local_20 = &local_2c;
  local_24 = &local_30;
  iVar4 = param_2;
  for (local_10 = *(int *)(local_14 + 0x24); local_10 != 0; local_10 = *(int *)(local_10 + 0xc)) {
    iVar1 = *(int *)(local_10 + 8);
    iVar2 = *(int *)(local_10 + 0xc);
    bVar8 = false;
    if ((iVar2 != 0) && (iVar6 = local_c, *(int *)(*(int *)(iVar2 + 8) + 4) == 0xc)) {
      bVar8 = true;
      local_10 = iVar2;
    }
    if ((param_3 == 0) || ((*(byte *)(*(int *)(iVar1 + 0x18) + 0x1c) & 0x40) != 0)) {
      if (iVar4 == 0) {
        if (!bVar8) goto LAB_008d23d8;
      }
      else {
        local_28 = *(int *)(iVar1 + 0x18);
        uVar3 = *(undefined4 *)(local_28 + 0x20);
        if (*(int *)(iVar4 + 8) == 0) {
          param_1 = 0;
        }
        else {
          param_1 = *(undefined4 *)(*(int *)(iVar4 + 8) + 0x10);
        }
        iVar6 = FUN_008bf738(0x14);
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_008f3584(0,0,s_Inputs_00a20f8c);
        }
        *local_20 = iVar6;
        if (iVar6 == 0) {
          return 0;
        }
        iVar6 = FUN_008bf738(0x14);
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_008f3584(0,0,s_Outputs_00a20f84);
        }
        *local_24 = iVar6;
        if (iVar6 == 0) {
          return 0;
        }
        if ((*(byte *)(local_28 + 0x1c) & 0x10) != 0) {
          iVar6 = FUN_008cbaba(uVar3,param_1,0);
          if (iVar6 == 0) {
            uVar5 = uVar3;
            goto LAB_008d240d;
          }
          uVar5 = FUN_008cedc3(uVar3,*(undefined4 *)(iVar4 + 8),0,0);
          *(undefined4 *)(*local_20 + 8) = uVar5;
        }
        if ((*(byte *)(local_28 + 0x1c) & 0x20) != 0) {
          iVar6 = FUN_008c9e50(param_1);
          if ((iVar6 != 0) || (iVar6 = FUN_008cbaba(param_1,uVar3,0), iVar6 == 0)) {
            uVar5 = param_1;
            param_1 = uVar3;
LAB_008d240d:
            FUN_008cbdf2(local_c,*(undefined4 *)(local_c + 8),uVar5,param_1,0);
            return 0;
          }
          iVar6 = FUN_008cecbc(*(undefined4 *)(iVar1 + 0x14),local_28);
          if (iVar6 == 0) {
            return 0;
          }
          iVar6 = FUN_008cedc3(param_1,iVar6,0,0);
          if (iVar6 == 0) {
            return 0;
          }
          iVar6 = FUN_008d130a(0x15,*(undefined4 *)(iVar4 + 8),iVar6,1);
          if (iVar6 == 0) {
            return 0;
          }
          *(int *)(*local_24 + 8) = iVar6;
        }
        iVar4 = *(int *)(iVar4 + 0xc);
        local_20 = (int *)(*local_20 + 0xc);
        local_24 = (int *)(*local_24 + 0xc);
        iVar6 = local_c;
      }
    }
  }
  if (iVar4 == 0) {
LAB_008d23d8:
    if (local_10 == 0) {
      iVar4 = FUN_008bf738(0x50);
      if (iVar4 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_008f3e67(0,(local_1c != 0) + '\x19',0,0,1,iVar6);
      }
      if (iVar6 == 0) {
        return 0;
      }
      if (*(int *)(local_14 + 0x20) != 0) {
        iVar4 = (**(code **)(**(int **)(local_14 + 0x20) + 4))();
        *(int *)(iVar6 + 0x10) = iVar4;
        if (iVar4 == 0) {
          return 0;
        }
      }
      *(undefined4 *)(iVar6 + 0x20) = local_18;
      iVar4 = FUN_008bf738(0x14);
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_008f3584(0,0,s_Parameters_00a20f78);
      }
      *(int *)(iVar6 + 0x24) = iVar4;
      if (iVar4 == 0) {
        return 0;
      }
      *(int *)(iVar4 + 8) = local_2c;
      *(int *)(*(int *)(iVar6 + 0x24) + 0xc) = local_30;
      FUN_008ca999(iVar6);
      iVar4 = FUN_008ca87b(iVar6);
      if (iVar4 == 0) {
        return iVar6;
      }
      iVar4 = FUN_008d0bbc(iVar6);
      if (iVar4 == 0) {
        return iVar6;
      }
      return iVar4;
    }
  }
  iVar4 = 0;
  for (; param_2 != 0; param_2 = *(int *)(param_2 + 0xc)) {
    iVar4 = iVar4 + 1;
  }
  puVar7 = &DAT_00a1fc84;
  if (local_1c == 0) {
    if (iVar4 == 1) {
      puVar7 = &DAT_0099cf70;
    }
    uVar3 = *(undefined4 *)(iVar6 + 8);
    pcVar9 = s___s___function_does_not_take__u_p_00a20f4c;
  }
  else {
    if (iVar4 == 1) {
      puVar7 = &DAT_0099cf70;
    }
    uVar3 = *(undefined4 *)(iVar6 + 8);
    pcVar9 = s___s___intrinsic_function_does_no_00a20f14;
  }
  FUN_008c98fa(local_8,iVar6,0xbc5,pcVar9,uVar3,iVar4,puVar7);
  return 0;
}


// ==== FUN_008d2514 @ 0x008d2514 ====

int FUN_008d2514(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined1 local_1c [4];
  uint local_18;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  iVar2 = param_1 + 0x10;
  local_10 = iVar2;
  iVar1 = FUN_008f31ff(*(undefined4 *)(param_1 + 0x18),2,local_1c);
  if (iVar1 < 0) {
    FUN_008c98fa(local_c,iVar2,0xbe1,s_unsupported_compiler_target___s__00a20f94,
                 *(undefined4 *)(param_1 + 0x18));
    return 0;
  }
  if ((local_18 & 0xffff0000) == 0xfffe0000) {
    param_4 = (uint)(param_4 != 0) * 2 + 0x1a;
  }
  else if ((local_18 & 0xffff0000) == 0xffff0000) {
    param_4 = (uint)(param_4 != 0) * 2 + 0x19;
  }
  iVar1 = FUN_008bf738(0x50);
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_008f3e67(0,0x1b,0,0,1,iVar2);
  }
  iVar2 = local_8;
  if (local_8 != 0) {
    iVar1 = FUN_008bf738(0x24);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_008f3b3d(3,param_4,1,1,0x200);
    }
    *(int *)(iVar2 + 0x10) = iVar1;
    if (iVar1 != 0) {
      iVar1 = FUN_008f352c(param_1);
      *(int *)(iVar2 + 0x20) = iVar1;
      if (iVar1 != 0) {
        iVar1 = FUN_008d20fc(param_2,param_3,1);
        *(int *)(iVar2 + 0x24) = iVar1;
        if (iVar1 != 0) {
          iVar2 = FUN_008bf738(0x50);
          if (iVar2 == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = FUN_008f3e67(0,0,0,0,1,local_10);
          }
          if (iVar2 != 0) {
            iVar1 = FUN_008bf738(0x24);
            if (iVar1 == 0) {
              iVar1 = 0;
            }
            else {
              iVar1 = FUN_008f3b3d(3,param_4,1,1,0x200);
            }
            *(int *)(iVar2 + 0x10) = iVar1;
            if (iVar1 != 0) {
              iVar1 = FUN_008bf738(0x14);
              if (iVar1 == 0) {
                iVar1 = 0;
              }
              else {
                iVar1 = FUN_008f3584(0,0,s_Value_00a20198);
              }
              *(int *)(iVar2 + 0x20) = iVar1;
              if (iVar1 != 0) {
                iVar1 = FUN_008bf738(0x40);
                if (iVar1 == 0) {
                  iVar1 = 0;
                }
                else {
                  iVar1 = FUN_008f3fb4(4,local_8,local_10);
                }
                *(int *)(*(int *)(iVar2 + 0x20) + 8) = iVar1;
                if (iVar1 != 0) {
                  FUN_008ca999(iVar2);
                  return iVar2;
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


// ==== FUN_008d26dc @ 0x008d26dc ====

void FUN_008d26dc(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int in_ECX;
  undefined1 *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 *local_64 [4];
  undefined4 local_54;
  undefined1 local_24 [28];
  undefined1 *local_8;
  
  puVar6 = (undefined1 *)0x0;
  local_8 = (undefined1 *)0x0;
  if (*(int *)(in_ECX + 0x44) != 0) {
    return;
  }
  while (param_2 != 0) {
    iVar5 = *(int *)(in_ECX + 8);
    param_2 = param_2 + -1;
    if (iVar5 == 0) goto LAB_008d3591;
    local_64[param_2] = *(undefined1 **)(iVar5 + 8);
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(iVar5 + 0xc);
    *(undefined4 *)(iVar5 + 8) = 0;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(in_ECX + 0xc);
    *(int *)(in_ECX + 0xc) = iVar5;
  }
  switch(param_1) {
  case 0:
    iVar5 = FUN_008bf738(0x20);
    if (iVar5 == 0) break;
    local_64[0] = (undefined1 *)0x0;
    uVar8 = 0;
    uVar12 = 0;
LAB_008d2751:
    puVar6 = (undefined1 *)FUN_008f37fb(uVar12,uVar8,local_64[0]);
    goto LAB_008d275f;
  case 1:
    iVar5 = FUN_008bf738(0x20);
    if (iVar5 != 0) {
      uVar8 = *(undefined8 *)(in_ECX + 0x54);
      uVar12 = *(undefined4 *)(in_ECX + 0x50);
      goto LAB_008d2751;
    }
    break;
  case 2:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0x12:
  case 0x14:
  case 0x21:
  case 0x24:
  case 0x25:
  case 0x28:
  case 0x2a:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x4e:
  case 0x51:
  case 0x56:
  case 0x59:
  case 0x5f:
  case 0x61:
  case 100:
  case 0x65:
  case 0x66:
  case 0x68:
  case 0x6b:
  case 0x6e:
  case 0x79:
  case 0x80:
  case 0x86:
  case 0x8c:
  case 0x93:
  case 0x97:
  case 0x9e:
  case 0xa7:
  case 0xa8:
  case 0xa9:
  case 0xaa:
  case 0xad:
  case 0xb5:
  case 0xb7:
  case 0xb9:
  case 0xbc:
  case 0xbd:
  case 0xbe:
  case 0xbf:
  case 0xc0:
  case 199:
  case 0xd4:
  case 0xd5:
  case 0xd6:
  case 0xdb:
  case 0xe1:
  case 0xe3:
  case 0xe7:
  case 0xea:
  case 0xef:
  case 0xf2:
  case 0xf4:
  case 0xf6:
  case 0xfd:
  case 0x102:
  case 0x104:
  case 0x105:
  case 0x106:
  case 0x108:
  case 0x109:
  case 0x10b:
  case 0x10d:
  case 0x10f:
  case 0x111:
  case 0x118:
  case 0x119:
  case 0x121:
    puVar6 = local_64[0];
    goto LAB_008d29a2;
  case 3:
  case 0x52:
  case 0x62:
  case 0x6c:
  case 0x7a:
  case 0x8d:
  case 0x94:
  case 0x9f:
  case 0x107:
    goto LAB_008d2793;
  case 4:
  case 0x2c:
  case 0x4a:
  case 0x58:
  case 0x5c:
  case 0x5e:
  case 0x67:
  case 0x74:
  case 0x75:
  case 0x78:
  case 0x88:
  case 0x8f:
  case 0x96:
  case 0x9a:
  case 0xa0:
  case 0xb3:
  case 0xb6:
  case 0xb8:
  case 0xcc:
  case 0x101:
  case 0x117:
    goto switchD_008d2731_caseD_4;
  case 0xb:
  case 0x15:
  case 0x81:
    FUN_008c9dc3();
    puVar6 = local_64[0];
    goto LAB_008d29a2;
  case 0xc:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 == 0) break;
    lVar7 = 2;
LAB_008d27c1:
    puVar6 = (undefined1 *)FUN_008f3a2e(lVar7,0);
    goto LAB_008d275f;
  case 0xd:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 0x40;
      goto LAB_008d27c1;
    }
    break;
  case 0xe:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 1;
      goto LAB_008d27c1;
    }
    break;
  case 0xf:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 4;
      goto LAB_008d27c1;
    }
    break;
  case 0x10:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 0x100;
      goto LAB_008d27c1;
    }
    break;
  case 0x11:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 8;
      goto LAB_008d27c1;
    }
    break;
  case 0x13:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = ZEXT48(local_64[0]) << 0x20;
      goto LAB_008d27c1;
    }
    break;
  case 0x16:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 0x200;
      goto LAB_008d27c1;
    }
    break;
  case 0x17:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 0x400;
      goto LAB_008d27c1;
    }
    break;
  case 0x18:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 0x800;
      goto LAB_008d27c1;
    }
    break;
  case 0x19:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 == 0) goto LAB_008d28b4;
    uVar8 = 0;
LAB_008d2ef8:
    local_64[0] = (undefined1 *)FUN_008f3a2e(uVar8,local_64[0]);
    goto LAB_008d28b6;
  case 0x1a:
    *(undefined1 **)(local_64[0] + 0x18) = local_64[1];
    goto LAB_008d28be;
  default:
    FUN_008c99bd();
    goto LAB_008d29a2;
  case 0x1d:
    FUN_008f3a2e(0,0,*(undefined4 *)(*(int *)(local_64[0] + 8) + 0x18));
    puVar4 = local_24;
    puVar6 = local_64[0];
    goto LAB_008d28bf;
  case 0x1e:
    *(undefined4 *)(local_64[0] + 0x18) = *(undefined4 *)(*(int *)(local_64[1] + 8) + 0x18);
    FUN_008cd197(local_64[0]);
    *(undefined4 *)(local_64[0] + 0x18) = 0;
    goto switchD_008d2731_caseD_4b;
  case 0x1f:
    puVar6 = (undefined1 *)FUN_008d0d40();
    goto LAB_008d275f;
  case 0x20:
    uVar12 = FUN_008d0d40();
    FUN_008c9a25(uVar12);
    goto LAB_008d2793;
  case 0x22:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 == 0) break;
    pcVar10 = s_TypeDefs_00a21094;
LAB_008d295b:
    local_64[1] = (undefined1 *)0x0;
LAB_008d295c:
    puVar6 = (undefined1 *)FUN_008f3584(local_64[0],local_64[1],pcVar10);
    goto LAB_008d275f;
  case 0x23:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 != 0) {
      pcVar10 = s_TypeDefs_00a21094;
      goto LAB_008d295c;
    }
    break;
  case 0x26:
    FUN_008ce5ff(0,local_64[0] + 0x10,0,0,*(undefined4 *)(in_ECX + 0x10),1,&local_8,0);
    goto LAB_008d299f;
  case 0x27:
    iVar5 = FUN_008ce5ff(0,local_64[0] + 0x10,0,0,*(undefined4 *)(in_ECX + 0x10),1,&local_8,0);
    puVar6 = local_8;
    if (iVar5 == 0) {
      if ((local_8 != (undefined1 *)0x0) && (*(int *)(local_8 + 4) != 1)) {
        FUN_008c98fa();
      }
      goto LAB_008d29a2;
    }
LAB_008d299f:
    puVar6 = local_8;
    goto LAB_008d29a2;
  case 0x29:
    FUN_008cba07();
    puVar6 = local_64[1];
    goto LAB_008d29a2;
  case 0x2b:
    puVar6 = (undefined1 *)FUN_008d1067();
    goto LAB_008d275f;
  case 0x30:
    FUN_008caf04();
    puVar6 = local_64[0];
    goto LAB_008d29a2;
  case 0x31:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 == 0) break;
    uVar12 = 0;
LAB_008d2a61:
    uVar8 = 0x100000001;
    uVar11 = 0;
LAB_008d2a62:
    puVar6 = (undefined1 *)FUN_008f3b3d(uVar11,uVar12,uVar8,0);
    goto LAB_008d275f;
  case 0x32:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 4;
      goto LAB_008d2a61;
    }
    break;
  case 0x33:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 10;
      goto LAB_008d2a61;
    }
    break;
  case 0x34:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0xb;
      goto LAB_008d2a61;
    }
    break;
  case 0x35:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0xc;
      goto LAB_008d2a61;
    }
    break;
  case 0x36:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar8 = 0x400000001;
      uVar12 = 0xb;
      uVar11 = 1;
      goto LAB_008d2a62;
    }
    break;
  case 0x37:
    puVar6 = (undefined1 *)FUN_008d0f38();
    goto LAB_008d275f;
  case 0x38:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar8 = 0x400000004;
      uVar12 = 0xb;
      uVar11 = 2;
      goto LAB_008d2a62;
    }
    break;
  case 0x39:
    puVar6 = (undefined1 *)FUN_008d0fbe(local_64[0],local_64[1],local_64[2]);
    goto LAB_008d275f;
  case 0x3a:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0xe;
LAB_008d2ccb:
      uVar8 = 0x100000001;
      uVar11 = 3;
      goto LAB_008d2a62;
    }
    break;
  case 0x3b:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0xf;
      goto LAB_008d2ccb;
    }
    break;
  case 0x3c:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x10;
      goto LAB_008d2ccb;
    }
    break;
  case 0x3d:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x11;
      goto LAB_008d2ccb;
    }
    break;
  case 0x3e:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x12;
      goto LAB_008d2ccb;
    }
    break;
  case 0x3f:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x13;
      goto LAB_008d2ccb;
    }
    break;
  case 0x40:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x14;
      goto LAB_008d2ccb;
    }
    break;
  case 0x41:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x15;
      goto LAB_008d2ccb;
    }
    break;
  case 0x42:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x16;
      goto LAB_008d2ccb;
    }
    break;
  case 0x43:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x17;
      goto LAB_008d2ccb;
    }
    break;
  case 0x44:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x18;
      goto LAB_008d2ccb;
    }
    break;
  case 0x45:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x19;
      goto LAB_008d2ccb;
    }
    break;
  case 0x46:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x1a;
      goto LAB_008d2ccb;
    }
    break;
  case 0x47:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x1b;
      goto LAB_008d2ccb;
    }
    break;
  case 0x48:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x1c;
      goto LAB_008d2ccb;
    }
    break;
  case 0x49:
    iVar5 = FUN_008bf738(0x24);
    if (iVar5 != 0) {
      uVar12 = 0x1d;
      goto LAB_008d2ccb;
    }
    break;
  case 0x4b:
  case 0x5d:
  case 0x76:
  case 0x89:
  case 0x90:
  case 0x9b:
    goto switchD_008d2731_caseD_4b;
  case 0x4c:
    goto LAB_008d2cd6;
  case 0x4d:
LAB_008d2cd6:
    puVar6 = (undefined1 *)FUN_008d0ef0();
    goto LAB_008d275f;
  case 0x4f:
    FUN_008cba07();
    goto switchD_008d2731_caseD_4b;
  case 0x50:
    goto LAB_008d2d03;
  case 0x53:
  case 99:
  case 0x8b:
  case 0x9d:
    goto switchD_008d2731_caseD_53;
  case 0x54:
  case 0x55:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 != 0) {
      pcVar10 = s_Semantics_00a21074;
      goto LAB_008d295b;
    }
    break;
  case 0x57:
    puVar6 = (undefined1 *)FUN_008f3545();
    goto LAB_008d275f;
  case 0x5a:
    iVar5 = FUN_008bf738(0x18);
    if (iVar5 == 0) break;
LAB_008d2d5b:
    puVar6 = (undefined1 *)FUN_008f41ee();
    goto LAB_008d275f;
  case 0x5b:
    iVar5 = FUN_008bf738(0x18);
    if (iVar5 != 0) goto LAB_008d2d5b;
    break;
  case 0x60:
    goto LAB_008d2d03;
  case 0x69:
  case 0x7b:
    puVar6 = local_64[1];
    goto LAB_008d2d86;
  case 0x6a:
    puVar6 = (undefined1 *)FUN_008f3545();
    goto LAB_008d2d86;
  case 0x6d:
    puVar6 = (undefined1 *)FUN_008d17d7(local_64[0],local_64[1],local_64[2],local_64[3]);
    goto LAB_008d275f;
  case 0x6f:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 != 0) {
      pcVar10 = s_VariableDim_00a21068;
      goto LAB_008d295b;
    }
    break;
  case 0x70:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 != 0) {
      pcVar10 = s_VariableDim_00a21068;
      goto LAB_008d295c;
    }
    break;
  case 0x71:
    FUN_008caf3c();
    *(undefined4 *)(in_ECX + 0x18) = 0;
    puVar6 = local_64[0];
    goto LAB_008d29a2;
  case 0x72:
    if ((local_64[0] != (undefined1 *)0x0) && (iVar5 = *(int *)(local_64[0] + 8), iVar5 != 0)) {
      iVar3 = *(int *)(iVar5 + 0x18);
      *(undefined1 **)(iVar5 + 0x1c) = local_64[1];
      *(undefined1 **)(iVar3 + 0x28) = local_64[2];
      *(undefined4 *)(iVar3 + 0x3c) = 1;
      for (iVar3 = *(int *)(in_ECX + 0x10); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x20)) {
        for (iVar2 = FUN_008c9bf1(); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
          iVar1 = *(int *)(iVar2 + 8);
          if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 6)) &&
             (*(int *)(iVar1 + 0x24) == *(int *)(iVar5 + 0x24))) {
            if (*(int *)(*(int *)(*(int *)(iVar2 + 8) + 0x18) + 0x3c) != 0) {
              FUN_008c98fa();
            }
            *(undefined4 *)(*(int *)(*(int *)(iVar2 + 8) + 0x18) + 0x3c) = 1;
            goto LAB_008d2ea7;
          }
        }
      }
    }
LAB_008d2ea7:
    FUN_008caf3c();
    *(undefined4 *)(in_ECX + 0x18) = 0;
    puVar6 = local_64[0];
    goto LAB_008d29a2;
  case 0x73:
    puVar6 = (undefined1 *)FUN_008d083b(local_64[1],local_64[2],local_64[3]);
    FUN_008c9a25(puVar6);
LAB_008d2d86:
    FUN_008c9d0e();
    goto LAB_008d29a2;
  case 0x77:
    goto LAB_008d2d03;
  case 0x7c:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      uVar8 = 0x10;
      goto LAB_008d2ef8;
    }
LAB_008d28b4:
    local_64[0] = (undefined1 *)0x0;
LAB_008d28b6:
    FUN_008c9a25(local_64[0]);
    goto LAB_008d28be;
  case 0x7d:
    *(undefined1 **)(local_64[0] + 0x18) = local_64[1];
    if ((local_64[0][0x10] & 0x70) == 0) {
      *(uint *)(local_64[0] + 0x10) = *(uint *)(local_64[0] + 0x10) | 0x10;
    }
LAB_008d28be:
    puVar6 = local_64[0];
    puVar4 = local_64[0];
LAB_008d28bf:
    FUN_008cd197(puVar4);
    goto LAB_008d29a2;
  case 0x82:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 0x10;
      goto LAB_008d27c1;
    }
    break;
  case 0x83:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 0x20;
      goto LAB_008d27c1;
    }
    break;
  case 0x84:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 0x30;
      goto LAB_008d27c1;
    }
    break;
  case 0x85:
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 != 0) {
      lVar7 = 0x50;
      goto LAB_008d27c1;
    }
    break;
  case 0x87:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 == 0) {
      puVar6 = (undefined1 *)0x0;
    }
    else {
      puVar6 = (undefined1 *)FUN_008f3584(0,0,s_Stmts_00a1fda0);
    }
    iVar5 = FUN_008c9a25(puVar6);
    if (iVar5 != 0) {
      iVar5 = FUN_008bf738(0x30);
      if (iVar5 == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = FUN_008f3958(3,local_64[0],local_64[2],local_64[1]);
      }
      *(undefined4 *)(puVar6 + 8) = uVar12;
      FUN_008c9a25(uVar12);
    }
    *(int *)(in_ECX + 0x50) = *(int *)(in_ECX + 0x50) + 1;
    goto LAB_008d29a2;
  case 0x8a:
    FUN_008c9a5a();
    goto switchD_008d2731_caseD_4;
  case 0x8e:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 == 0) {
      puVar6 = (undefined1 *)0x0;
    }
    else {
      puVar6 = (undefined1 *)FUN_008f3584(0,0,s_Passes_00a21048);
    }
    iVar5 = FUN_008c9a25(puVar6);
    if (iVar5 == 0) goto LAB_008d29a2;
    iVar5 = FUN_008bf738(0x30);
    if (iVar5 == 0) {
LAB_008d30a7:
      puVar4 = (undefined1 *)0x0;
    }
    else {
      puVar4 = (undefined1 *)FUN_008f3958(4,local_64[0],local_64[2],local_64[1]);
    }
    goto LAB_008d30a9;
  case 0x91:
    FUN_008c9a5a();
    *(undefined4 *)(in_ECX + 0x48) = 0;
switchD_008d2731_caseD_4:
    puVar6 = (undefined1 *)0x0;
    goto LAB_008d29a2;
  case 0x92:
    *(undefined4 *)(in_ECX + 0x48) = 1;
switchD_008d2731_caseD_53:
    puVar6 = (undefined1 *)0x0;
LAB_008d2d13:
    FUN_008caf3c();
    goto LAB_008d29a2;
  case 0x95:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 == 0) {
      puVar6 = (undefined1 *)0x0;
    }
    else {
      puVar6 = (undefined1 *)FUN_008f3584(0,0,s_States_00a21040);
    }
    iVar5 = FUN_008c9a25(puVar6);
    if (iVar5 == 0) goto LAB_008d29a2;
    iVar5 = FUN_008bf738(0x1c);
    if (iVar5 == 0) goto LAB_008d30a7;
    puVar4 = (undefined1 *)FUN_008f40c7(local_64[0],local_64[1],local_64[3]);
LAB_008d30a9:
    *(undefined1 **)(puVar6 + 8) = puVar4;
    goto LAB_008d2760;
  case 0x98:
    *(undefined4 *)(in_ECX + 0x48) = 1;
    goto LAB_008d29a2;
  case 0x99:
    *(undefined4 *)(in_ECX + 0x48) = 0;
    goto LAB_008d29a2;
  case 0x9c:
    goto LAB_008d2d03;
  case 0xa1:
  case 0xb4:
    puVar6 = (undefined1 *)FUN_008ca9e1(local_64[0]);
    goto LAB_008d2798;
  case 0xa2:
    local_64[0] = (undefined1 *)0x0;
    goto LAB_008d30d4;
  case 0xa3:
LAB_008d30d4:
    puVar6 = (undefined1 *)FUN_008d1723(local_64[0]);
    goto LAB_008d2798;
  case 0xa4:
    puVar6 = local_64[0];
    puVar4 = local_64[0];
    local_64[0] = local_64[1];
    goto LAB_008d3119;
  case 0xa5:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 != 0) {
      pcVar10 = s_Stmts_00a1fda0;
      goto LAB_008d295b;
    }
    break;
  case 0xa6:
    puVar6 = (undefined1 *)FUN_008caa43();
    goto LAB_008d2798;
  case 0xab:
  case 0xae:
    puVar6 = (undefined1 *)0x0;
    puVar4 = local_64[1];
LAB_008d3119:
    puVar6 = (undefined1 *)FUN_008caac6(puVar6,local_64[0],puVar4);
    goto LAB_008d2798;
  case 0xac:
  case 0xaf:
    puVar6 = (undefined1 *)FUN_008caac6(local_64[1],local_64[2],local_64[3],local_54);
    goto LAB_008d2d13;
  case 0xb0:
    local_64[2] = (undefined1 *)0x0;
    goto LAB_008d3145;
  case 0xb1:
LAB_008d3145:
    puVar6 = (undefined1 *)FUN_008cfbb9(local_64[0],local_64[1],local_64[2]);
    goto LAB_008d2798;
  case 0xb2:
LAB_008d2d03:
    FUN_008c9a5a();
    puVar6 = (undefined1 *)0x0;
    goto LAB_008d29a2;
  case 0xba:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 != 0) {
      pcVar10 = s_DwordExpr_00a21034;
      goto LAB_008d295b;
    }
    break;
  case 0xbb:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 != 0) {
      pcVar10 = s_DwordExpr_00a21034;
      goto LAB_008d295c;
    }
    break;
  case 0xc1:
    uVar8 = 0x3ff0000000000000;
    uVar12 = 1;
    goto LAB_008d31b0;
  case 0xc2:
    uVar8 = 0;
    uVar12 = 0;
LAB_008d31b0:
    puVar6 = (undefined1 *)FUN_008cc2d1(0,uVar12,uVar8,in_ECX + 0x20);
    goto LAB_008d275f;
  case 0xc3:
  case 0xc4:
    puVar6 = (undefined1 *)FUN_008cc3e9(local_64[0]);
    goto LAB_008d275f;
  case 0xc5:
    puVar6 = (undefined1 *)FUN_008cc46d(local_64[0]);
    goto LAB_008d275f;
  case 0xc6:
    puVar6 = (undefined1 *)FUN_008cecbc();
    goto LAB_008d275f;
  case 200:
  case 0xc9:
    uVar12 = 1;
    goto LAB_008d31fd;
  case 0xca:
    puVar6 = (undefined1 *)FUN_008d20fc(local_64[0],local_64[1],0);
    goto LAB_008d275f;
  case 0xcb:
    puVar6 = (undefined1 *)FUN_008ca617(local_64[0]);
    goto LAB_008d2798;
  case 0xcd:
    local_64[0] = local_64[1];
    goto LAB_008d3239;
  case 0xce:
  case 0xcf:
LAB_008d3239:
    puVar6 = (undefined1 *)FUN_008ccacc(local_64[0]);
    goto LAB_008d2798;
  case 0xd0:
    uVar12 = 0;
    goto LAB_008d3259;
  case 0xd1:
    puVar6 = (undefined1 *)FUN_008ccc06(local_64[0]);
    goto LAB_008d275f;
  case 0xd2:
    uVar12 = 1;
LAB_008d3259:
    puVar6 = (undefined1 *)FUN_008d2514(local_64[0],local_64[1],local_64[2],uVar12);
    goto LAB_008d2798;
  case 0xd3:
    puVar6 = (undefined1 *)FUN_008ccce0(local_64[0]);
    goto LAB_008d275f;
  case 0xd7:
    puVar6 = (undefined1 *)FUN_008d10e0();
    goto LAB_008d275f;
  case 0xd8:
    puVar6 = (undefined1 *)FUN_008cc63b();
    goto LAB_008d275f;
  case 0xd9:
    uVar11 = 1;
    uVar9 = ZEXT48(local_64[0]);
    uVar12 = 0x21;
    goto LAB_008d32a9;
  case 0xda:
    uVar11 = 1;
    uVar9 = ZEXT48(local_64[0]);
    uVar12 = 0x22;
    goto LAB_008d32a9;
  case 0xdc:
    uVar11 = 1;
    uVar9 = ZEXT48(local_64[0]);
    uVar12 = 2;
    goto LAB_008d32a9;
  case 0xdd:
    uVar11 = 1;
    uVar9 = ZEXT48(local_64[0]);
    uVar12 = 3;
    goto LAB_008d32a9;
  case 0xde:
    uVar11 = 1;
    uVar9 = ZEXT48(local_64[0]);
    uVar12 = 4;
    goto LAB_008d32a9;
  case 0xdf:
    uVar11 = 1;
    uVar9 = ZEXT48(local_64[0]);
    uVar12 = 5;
    goto LAB_008d32a9;
  case 0xe0:
    uVar11 = 1;
    uVar9 = ZEXT48(local_64[0]);
    uVar12 = 6;
    goto LAB_008d32a9;
  case 0xe2:
    uVar12 = 0;
LAB_008d31fd:
    puVar6 = (undefined1 *)FUN_008cedc3(local_64[0],local_64[1],uVar12,1);
    goto LAB_008d275f;
  case 0xe4:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 7;
    goto LAB_008d32a9;
  case 0xe5:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 8;
    goto LAB_008d32a9;
  case 0xe6:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 9;
    goto LAB_008d32a9;
  case 0xe8:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 10;
    goto LAB_008d32a9;
  case 0xe9:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0xb;
    goto LAB_008d32a9;
  case 0xeb:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0xc;
    goto LAB_008d32a9;
  case 0xec:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0xd;
    goto LAB_008d32a9;
  case 0xed:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0xe;
    goto LAB_008d32a9;
  case 0xee:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0xf;
    goto LAB_008d32a9;
  case 0xf0:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0x10;
    goto LAB_008d32a9;
  case 0xf1:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0x11;
    goto LAB_008d32a9;
  case 0xf3:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0x12;
    goto LAB_008d32a9;
  case 0xf5:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0x13;
    goto LAB_008d32a9;
  case 0xf7:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0x15;
    goto LAB_008d32a9;
  case 0xf8:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0x1c;
    goto LAB_008d32a9;
  case 0xf9:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0x1d;
    goto LAB_008d32a9;
  case 0xfa:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0x1e;
    goto LAB_008d32a9;
  case 0xfb:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0x1f;
    goto LAB_008d32a9;
  case 0xfc:
    uVar11 = 1;
    uVar9 = CONCAT44(local_64[1],local_64[0]);
    uVar12 = 0x20;
    goto LAB_008d32a9;
  case 0xfe:
    puVar6 = (undefined1 *)FUN_008cefec(local_64[0],local_64[1],local_64[2]);
    goto LAB_008d275f;
  case 0xff:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 != 0) {
      pcVar10 = s_Arguments_00a21028;
      goto LAB_008d295b;
    }
    break;
  case 0x100:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 == 0) {
      puVar6 = (undefined1 *)0x0;
    }
    else {
      puVar6 = (undefined1 *)FUN_008f3584(local_64[1],0,s_Arguments_00a21028);
    }
    iVar5 = FUN_008c9a25(puVar6);
    if (iVar5 == 0) goto LAB_008d29a2;
LAB_008d2793:
    puVar6 = (undefined1 *)FUN_008f3545();
    goto LAB_008d2798;
  case 0x103:
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 != 0) {
      pcVar10 = s_Value_00a20198;
      goto LAB_008d295b;
    }
    break;
  case 0x10a:
    if ((*(int *)(in_ECX + 0x10) != 0) && (*(int *)(*(int *)(in_ECX + 0x10) + 0x10) == 7)) {
      FUN_008c9960();
    }
    uVar11 = 0;
    uVar9 = CONCAT44(local_64[0],local_64[1]);
    uVar12 = 1;
LAB_008d32a9:
    puVar6 = (undefined1 *)FUN_008d130a(uVar12,uVar9,uVar11);
    goto LAB_008d275f;
  case 0x10c:
    *(int *)(local_64[0] + 0x18) = -*(int *)(local_64[0] + 0x18);
    puVar6 = local_64[0];
    goto LAB_008d29a2;
  case 0x10e:
    *(double *)(local_64[0] + 0x18) = -*(double *)(local_64[0] + 0x18);
    puVar6 = local_64[0];
    goto LAB_008d29a2;
  case 0x110:
    puVar6 = (undefined1 *)FUN_008cad35();
    goto LAB_008d2798;
  case 0x112:
  case 0x113:
  case 0x114:
  case 0x11a:
  case 0x11b:
  case 0x11c:
  case 0x11d:
  case 0x11e:
  case 0x11f:
  case 0x120:
  case 0x123:
  case 0x124:
  case 0x125:
    iVar5 = FUN_008bf738(0x30);
    if (iVar5 == 0) break;
    puVar6 = (undefined1 *)FUN_008f378b(in_ECX + 0x20);
    goto LAB_008d275f;
  case 0x115:
  case 0x116:
    *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(local_64[0] + 0x18);
    puVar6 = local_64[0];
    goto LAB_008d29a2;
  case 0x122:
    puVar6 = (undefined1 *)FUN_008cae34();
    goto LAB_008d2798;
  case 0x126:
    puVar6 = (undefined1 *)FUN_008cabe1();
    goto LAB_008d2798;
  case 0x127:
    uVar12 = 0;
    goto LAB_008d3544;
  case 0x128:
    uVar12 = 1;
LAB_008d3544:
    puVar6 = (undefined1 *)FUN_008cabfc(uVar12);
LAB_008d2798:
    goto LAB_008d29a2;
  }
  puVar6 = (undefined1 *)0x0;
LAB_008d275f:
  puVar4 = puVar6;
LAB_008d2760:
  FUN_008c9a25(puVar4);
LAB_008d29a2:
  if (*(int *)(in_ECX + 0x44) == 0) {
    iVar5 = *(int *)(in_ECX + 0xc);
    if (iVar5 == 0) {
      iVar5 = FUN_008bf738(0x14);
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_008f3584(puVar6,*(undefined4 *)(in_ECX + 8),s_Stack_00a17c20);
      }
      if (iVar5 == 0) {
LAB_008d3591:
        FUN_008c99bd();
        return;
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar5 + 0xc);
      *(undefined1 **)(iVar5 + 8) = puVar6;
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(in_ECX + 8);
    }
    *(int *)(in_ECX + 8) = iVar5;
  }
  return;
switchD_008d2731_caseD_4b:
  puVar6 = local_64[1];
  goto LAB_008d29a2;
}


// ==== FUN_008d3a45 @ 0x008d3a45 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008d3a45(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar4 = 0;
  _DAT_00b5f6c0 = 0;
  DAT_00b5f6bc = 0;
  DAT_00b5f6b4 = (short *)&DAT_00b5f2c0;
  DAT_00b5f6b0 = (undefined4 *)&DAT_00b5eaf0;
  _DAT_00b5f2c0 = 0;
LAB_008d3a80:
  DAT_00b5f6b8 = -1;
LAB_008d3a85:
  iVar2 = (int)(short)(&DAT_00b54d30)[iVar4];
  if (iVar2 == 0) {
    if ((DAT_00b5f6b8 < 0) && (DAT_00b5f6b8 = FUN_008cfce0(), DAT_00b5f6b8 < 0)) {
      DAT_00b5f6b8 = 0;
    }
    if (((((short)(&DAT_00b551e0)[iVar4] != 0) &&
         (iVar2 = (short)(&DAT_00b551e0)[iVar4] + DAT_00b5f6b8, -1 < iVar2)) && (iVar2 < 0xd89)) &&
       (*(short *)(&DAT_00b57570 + iVar2 * 2) == DAT_00b5f6b8)) {
      if (&DAT_00b5f6a6 <= DAT_00b5f6b4) goto LAB_008d4897;
      iVar4 = (int)*(short *)(&DAT_00b55a58 + iVar2 * 2);
      DAT_00b5f6b4 = DAT_00b5f6b4 + 1;
      *DAT_00b5f6b4 = *(short *)(&DAT_00b55a58 + iVar2 * 2);
      DAT_00b5f6b0 = DAT_00b5f6b0 + 1;
      *DAT_00b5f6b0 = DAT_00b5f6a8;
      DAT_00b5f6b8 = -1;
      if (0 < DAT_00b5f6bc) {
        DAT_00b5f6bc = DAT_00b5f6bc + -1;
      }
      goto LAB_008d3a85;
    }
    if ((((short)(&DAT_00b555a8)[iVar4] != 0) &&
        (iVar2 = (short)(&DAT_00b555a8)[iVar4] + DAT_00b5f6b8, -1 < iVar2)) &&
       ((iVar2 < 0xd89 && (*(short *)(&DAT_00b57570 + iVar2 * 2) == DAT_00b5f6b8)))) {
      iVar2 = (int)*(short *)(&DAT_00b55a58 + iVar2 * 2);
      goto LAB_008d3b69;
    }
    if (DAT_00b5f6bc == 0) {
      FUN_008c97ba(DAT_00b5f6c8,s_syntax_error_009fea30);
      _DAT_00b5f6c0 = _DAT_00b5f6c0 + 1;
    }
    if (2 < DAT_00b5f6bc) goto LAB_008d488b;
    DAT_00b5f6bc = 3;
    while ((((short)(&DAT_00b551e0)[*DAT_00b5f6b4] == 0 ||
            (iVar4 = (short)(&DAT_00b551e0)[*DAT_00b5f6b4] + 0x100, iVar4 < 0)) ||
           ((0xd88 < iVar4 || (*(short *)(&DAT_00b57570 + iVar4 * 2) != 0x100))))) {
      if (DAT_00b5f6b4 < (short *)0xb5f2c1) {
        DAT_00b5f6bc = 3;
        return 1;
      }
      DAT_00b5f6b4 = DAT_00b5f6b4 + -1;
      DAT_00b5f6b0 = DAT_00b5f6b0 + -1;
    }
    if ((short *)0xb5f6a5 < DAT_00b5f6b4) goto LAB_008d4897;
    sVar1 = *(short *)(&DAT_00b55a58 + iVar4 * 2);
    DAT_00b5f6b4 = DAT_00b5f6b4 + 1;
    *DAT_00b5f6b4 = sVar1;
    uVar6 = DAT_00b5f6a8;
  }
  else {
LAB_008d3b69:
    iVar4 = (int)*(short *)(&DAT_00b54ae0 + iVar2 * 2);
    DAT_00b5f6ac = DAT_00b5f6b0[1 - iVar4];
    switch(iVar2) {
    case 1:
      uVar7 = 0;
      uVar6 = 0;
      break;
    case 2:
      uVar7 = 1;
      uVar6 = 1;
      break;
    case 3:
      uVar7 = 1;
      uVar6 = 2;
      break;
    case 4:
      uVar7 = 2;
      uVar6 = 3;
      break;
    case 5:
      uVar7 = 0;
      uVar6 = 4;
      break;
    case 6:
      uVar7 = 1;
      uVar6 = 5;
      break;
    case 7:
      uVar7 = 1;
      uVar6 = 6;
      break;
    case 8:
      uVar7 = 1;
      uVar6 = 7;
      break;
    case 9:
      uVar7 = 1;
      uVar6 = 8;
      break;
    case 10:
      uVar7 = 1;
      uVar6 = 9;
      break;
    case 0xb:
      uVar7 = 1;
      uVar6 = 10;
      break;
    case 0xc:
      uVar7 = 2;
      uVar6 = 0xb;
      break;
    case 0xd:
      uVar7 = 0;
      uVar6 = 0xc;
      break;
    case 0xe:
      uVar7 = 0;
      uVar6 = 0xd;
      break;
    case 0xf:
      uVar7 = 0;
      uVar6 = 0xe;
      break;
    case 0x10:
      uVar7 = 0;
      uVar6 = 0xf;
      break;
    case 0x11:
      uVar7 = 0;
      uVar6 = 0x10;
      break;
    case 0x12:
      uVar7 = 0;
      uVar6 = 0x11;
      break;
    case 0x13:
      uVar7 = 1;
      uVar6 = 0x12;
      break;
    case 0x14:
      uVar7 = 1;
      uVar6 = 0x13;
      break;
    case 0x15:
      uVar7 = 1;
      uVar6 = 0x14;
      break;
    case 0x16:
      uVar7 = 2;
      uVar6 = 0x15;
      break;
    case 0x17:
      uVar7 = 0;
      uVar6 = 0x16;
      break;
    case 0x18:
      uVar7 = 0;
      uVar6 = 0x17;
      break;
    case 0x19:
      uVar7 = 0;
      uVar6 = 0x18;
      break;
    case 0x1a:
      uVar7 = 1;
      uVar6 = 0x19;
      break;
    case 0x1b:
      uVar7 = 2;
      uVar6 = 0x1a;
      break;
    case 0x1c:
      uVar7 = 1;
      uVar6 = 0x1d;
      break;
    case 0x1d:
      uVar7 = 2;
      uVar6 = 0x1e;
      break;
    case 0x1e:
      uVar7 = 2;
      uVar6 = 0x1f;
      break;
    case 0x1f:
      uVar7 = 2;
      uVar6 = 0x20;
      break;
    case 0x20:
      uVar7 = 1;
      uVar6 = 0x21;
      break;
    case 0x21:
      uVar7 = 1;
      uVar6 = 0x22;
      break;
    case 0x22:
      uVar7 = 2;
      uVar6 = 0x23;
      break;
    case 0x23:
      uVar7 = 1;
      uVar6 = 0x24;
      break;
    case 0x24:
      uVar7 = 1;
      uVar6 = 0x25;
      break;
    case 0x25:
      uVar7 = 1;
      uVar6 = 0x26;
      break;
    case 0x26:
      uVar7 = 1;
      uVar6 = 0x27;
      break;
    case 0x27:
      uVar7 = 1;
      uVar6 = 0x28;
      break;
    case 0x28:
      uVar7 = 2;
      uVar6 = 0x29;
      break;
    case 0x29:
      uVar7 = 1;
      uVar6 = 0x2a;
      break;
    case 0x2a:
      uVar7 = 2;
      uVar6 = 0x2b;
      break;
    case 0x2b:
      uVar7 = 0;
      uVar6 = 0x2c;
      break;
    case 0x2c:
      uVar7 = 1;
      uVar6 = 0x2d;
      break;
    case 0x2d:
      uVar7 = 1;
      uVar6 = 0x2e;
      break;
    case 0x2e:
      uVar7 = 1;
      uVar6 = 0x2f;
      break;
    case 0x2f:
      uVar7 = 1;
      uVar6 = 0x30;
      break;
    case 0x30:
      uVar7 = 0;
      uVar6 = 0x31;
      break;
    case 0x31:
      uVar7 = 0;
      uVar6 = 0x32;
      break;
    case 0x32:
      uVar7 = 0;
      uVar6 = 0x33;
      break;
    case 0x33:
      uVar7 = 0;
      uVar6 = 0x34;
      break;
    case 0x34:
      uVar7 = 0;
      uVar6 = 0x35;
      break;
    case 0x35:
      uVar7 = 0;
      uVar6 = 0x36;
      break;
    case 0x36:
      uVar7 = 2;
      uVar6 = 0x37;
      break;
    case 0x37:
      uVar7 = 0;
      uVar6 = 0x38;
      break;
    case 0x38:
      uVar7 = 3;
      uVar6 = 0x39;
      break;
    case 0x39:
      uVar7 = 0;
      uVar6 = 0x3a;
      break;
    case 0x3a:
      uVar7 = 0;
      uVar6 = 0x3b;
      break;
    case 0x3b:
      uVar7 = 0;
      uVar6 = 0x3c;
      break;
    case 0x3c:
      uVar7 = 0;
      uVar6 = 0x3d;
      break;
    case 0x3d:
      uVar7 = 0;
      uVar6 = 0x3e;
      break;
    case 0x3e:
      uVar7 = 0;
      uVar6 = 0x3f;
      break;
    case 0x3f:
      uVar7 = 0;
      uVar6 = 0x40;
      break;
    case 0x40:
      uVar7 = 0;
      uVar6 = 0x41;
      break;
    case 0x41:
      uVar7 = 0;
      uVar6 = 0x42;
      break;
    case 0x42:
      uVar7 = 0;
      uVar6 = 0x43;
      break;
    case 0x43:
      uVar7 = 0;
      uVar6 = 0x44;
      break;
    case 0x44:
      uVar7 = 0;
      uVar6 = 0x45;
      break;
    case 0x45:
      uVar7 = 0;
      uVar6 = 0x46;
      break;
    case 0x46:
      uVar7 = 0;
      uVar6 = 0x47;
      break;
    case 0x47:
      uVar7 = 0;
      uVar6 = 0x48;
      break;
    case 0x48:
      uVar7 = 0;
      uVar6 = 0x49;
      break;
    case 0x49:
      uVar7 = 2;
      uVar6 = 0x4a;
      break;
    case 0x4a:
      uVar7 = 3;
      uVar6 = 0x4b;
      break;
    case 0x4b:
      uVar7 = 3;
      uVar6 = 0x4c;
      break;
    case 0x4c:
      uVar7 = 4;
      uVar6 = 0x4d;
      break;
    case 0x4d:
      uVar7 = 1;
      uVar6 = 0x4e;
      break;
    case 0x4e:
      uVar7 = 2;
      uVar6 = 0x4f;
      break;
    case 0x4f:
      uVar7 = 0;
      uVar6 = 0x50;
      break;
    case 0x50:
      uVar7 = 1;
      uVar6 = 0x51;
      break;
    case 0x51:
      uVar7 = 2;
      uVar6 = 0x52;
      break;
    case 0x52:
      uVar7 = 0;
      uVar6 = 0x53;
      break;
    case 0x53:
      uVar7 = 1;
      uVar6 = 0x54;
      break;
    case 0x54:
      uVar7 = 1;
      uVar6 = 0x55;
      break;
    case 0x55:
      uVar7 = 1;
      uVar6 = 0x56;
      break;
    case 0x56:
      uVar7 = 2;
      uVar6 = 0x57;
      break;
    case 0x57:
      uVar7 = 0;
      uVar6 = 0x58;
      break;
    case 0x58:
      uVar7 = 1;
      uVar6 = 0x59;
      break;
    case 0x59:
      uVar7 = 1;
      uVar6 = 0x5a;
      break;
    case 0x5a:
      uVar7 = 2;
      uVar6 = 0x5b;
      break;
    case 0x5b:
      uVar7 = 2;
      uVar6 = 0x5c;
      break;
    case 0x5c:
      uVar7 = 3;
      uVar6 = 0x5d;
      break;
    case 0x5d:
      uVar7 = 0;
      uVar6 = 0x5e;
      break;
    case 0x5e:
      uVar7 = 1;
      uVar6 = 0x5f;
      break;
    case 0x5f:
      uVar7 = 0;
      uVar6 = 0x60;
      break;
    case 0x60:
      uVar7 = 1;
      uVar6 = 0x61;
      break;
    case 0x61:
      uVar7 = 2;
      uVar6 = 0x62;
      break;
    case 0x62:
      uVar7 = 0;
      uVar6 = 99;
      break;
    case 99:
      uVar7 = 1;
      uVar6 = 100;
      break;
    case 100:
      uVar7 = 1;
      uVar6 = 0x65;
      break;
    case 0x65:
      uVar7 = 1;
      uVar6 = 0x66;
      break;
    case 0x66:
      uVar7 = 0;
      uVar6 = 0x67;
      break;
    case 0x67:
      uVar7 = 1;
      uVar6 = 0x68;
      break;
    case 0x68:
      uVar7 = 2;
      uVar6 = 0x69;
      break;
    case 0x69:
      uVar7 = 2;
      uVar6 = 0x6a;
      break;
    case 0x6a:
      uVar7 = 1;
      uVar6 = 0x6b;
      break;
    case 0x6b:
      uVar7 = 2;
      uVar6 = 0x6c;
      break;
    case 0x6c:
      uVar7 = 4;
      uVar6 = 0x6d;
      break;
    case 0x6d:
      uVar7 = 1;
      uVar6 = 0x6e;
      break;
    case 0x6e:
      uVar7 = 1;
      uVar6 = 0x6f;
      break;
    case 0x6f:
      uVar7 = 2;
      uVar6 = 0x70;
      break;
    case 0x70:
      uVar7 = 1;
      uVar6 = 0x71;
      break;
    case 0x71:
      uVar7 = 3;
      uVar6 = 0x72;
      break;
    case 0x72:
      uVar7 = 4;
      uVar6 = 0x73;
      break;
    case 0x73:
      uVar7 = 2;
      uVar6 = 0x74;
      break;
    case 0x74:
      uVar7 = 2;
      uVar6 = 0x75;
      break;
    case 0x75:
      uVar7 = 3;
      uVar6 = 0x76;
      break;
    case 0x76:
      uVar7 = 0;
      uVar6 = 0x77;
      break;
    case 0x77:
      uVar7 = 0;
      uVar6 = 0x78;
      break;
    case 0x78:
      uVar7 = 1;
      uVar6 = 0x79;
      break;
    case 0x79:
      uVar7 = 2;
      uVar6 = 0x7a;
      break;
    case 0x7a:
      uVar7 = 2;
      uVar6 = 0x7b;
      break;
    case 0x7b:
      uVar7 = 1;
      uVar6 = 0x7c;
      break;
    case 0x7c:
      uVar7 = 2;
      uVar6 = 0x7d;
      break;
    case 0x7d:
      uVar7 = 1;
      uVar6 = 0x80;
      break;
    case 0x7e:
      uVar7 = 2;
      uVar6 = 0x81;
      break;
    case 0x7f:
      uVar7 = 0;
      uVar6 = 0x82;
      break;
    case 0x80:
      uVar7 = 0;
      uVar6 = 0x83;
      break;
    case 0x81:
      uVar7 = 0;
      uVar6 = 0x84;
      break;
    case 0x82:
      uVar7 = 0;
      uVar6 = 0x85;
      break;
    case 0x83:
      uVar7 = 1;
      uVar6 = 0x86;
      break;
    case 0x84:
      uVar7 = 3;
      uVar6 = 0x87;
      break;
    case 0x85:
      uVar7 = 2;
      uVar6 = 0x88;
      break;
    case 0x86:
      uVar7 = 3;
      uVar6 = 0x89;
      break;
    case 0x87:
      uVar7 = 0;
      uVar6 = 0x8a;
      break;
    case 0x88:
      uVar7 = 0;
      uVar6 = 0x8b;
      break;
    case 0x89:
      uVar7 = 1;
      uVar6 = 0x8c;
      break;
    case 0x8a:
      uVar7 = 2;
      uVar6 = 0x8d;
      break;
    case 0x8b:
      uVar7 = 3;
      uVar6 = 0x8e;
      break;
    case 0x8c:
      uVar7 = 2;
      uVar6 = 0x8f;
      break;
    case 0x8d:
      uVar7 = 3;
      uVar6 = 0x90;
      break;
    case 0x8e:
      uVar7 = 0;
      uVar6 = 0x91;
      break;
    case 0x8f:
      uVar7 = 0;
      uVar6 = 0x92;
      break;
    case 0x90:
      uVar7 = 1;
      uVar6 = 0x93;
      break;
    case 0x91:
      uVar7 = 2;
      uVar6 = 0x94;
      break;
    case 0x92:
      uVar7 = 5;
      uVar6 = 0x95;
      break;
    case 0x93:
      uVar7 = 0;
      uVar6 = 0x96;
      break;
    case 0x94:
      uVar7 = 1;
      uVar6 = 0x97;
      break;
    case 0x95:
      uVar7 = 0;
      uVar6 = 0x98;
      break;
    case 0x96:
      uVar7 = 0;
      uVar6 = 0x99;
      break;
    case 0x97:
      uVar7 = 2;
      uVar6 = 0x9a;
      break;
    case 0x98:
      uVar7 = 3;
      uVar6 = 0x9b;
      break;
    case 0x99:
      uVar7 = 0;
      uVar6 = 0x9c;
      break;
    case 0x9a:
      uVar7 = 0;
      uVar6 = 0x9d;
      break;
    case 0x9b:
      uVar7 = 1;
      uVar6 = 0x9e;
      break;
    case 0x9c:
      uVar7 = 2;
      uVar6 = 0x9f;
      break;
    case 0x9d:
      uVar7 = 0;
      uVar6 = 0xa0;
      break;
    case 0x9e:
      uVar7 = 1;
      uVar6 = 0xa1;
      break;
    case 0x9f:
      uVar7 = 0;
      uVar6 = 0xa2;
      break;
    case 0xa0:
      uVar7 = 1;
      uVar6 = 0xa3;
      break;
    case 0xa1:
      uVar7 = 2;
      uVar6 = 0xa4;
      break;
    case 0xa2:
      uVar7 = 1;
      uVar6 = 0xa5;
      break;
    case 0xa3:
      uVar7 = 0;
      uVar6 = 0xa6;
      break;
    case 0xa4:
      uVar7 = 1;
      uVar6 = 0xa7;
      break;
    case 0xa5:
      uVar7 = 1;
      uVar6 = 0xa8;
      break;
    case 0xa6:
      uVar7 = 1;
      uVar6 = 0xa9;
      break;
    case 0xa7:
      uVar7 = 1;
      uVar6 = 0xaa;
      break;
    case 0xa8:
      uVar7 = 2;
      uVar6 = 0xab;
      break;
    case 0xa9:
      uVar7 = 5;
      uVar6 = 0xac;
      break;
    case 0xaa:
      uVar7 = 1;
      uVar6 = 0xad;
      break;
    case 0xab:
      uVar7 = 2;
      uVar6 = 0xae;
      break;
    case 0xac:
      uVar7 = 5;
      uVar6 = 0xaf;
      break;
    case 0xad:
      uVar7 = 2;
      uVar6 = 0xb0;
      break;
    case 0xae:
      uVar7 = 3;
      uVar6 = 0xb1;
      break;
    case 0xaf:
      uVar7 = 0;
      uVar6 = 0xb2;
      break;
    case 0xb0:
      uVar7 = 0;
      uVar6 = 0xb3;
      break;
    case 0xb1:
      uVar7 = 1;
      uVar6 = 0xb4;
      break;
    case 0xb2:
      uVar7 = 1;
      uVar6 = 0xb5;
      break;
    case 0xb3:
      uVar7 = 0;
      uVar6 = 0xb6;
      break;
    case 0xb4:
      uVar7 = 1;
      uVar6 = 0xb7;
      break;
    case 0xb5:
      uVar7 = 0;
      uVar6 = 0xb8;
      break;
    case 0xb6:
      uVar7 = 1;
      uVar6 = 0xb9;
      break;
    case 0xb7:
      uVar7 = 1;
      uVar6 = 0xba;
      break;
    case 0xb8:
      uVar7 = 2;
      uVar6 = 0xbb;
      break;
    case 0xb9:
      uVar7 = 1;
      uVar6 = 0xbc;
      break;
    case 0xba:
      uVar7 = 1;
      uVar6 = 0xbd;
      break;
    case 0xbb:
      uVar7 = 1;
      uVar6 = 0xbe;
      break;
    case 0xbc:
      uVar7 = 1;
      uVar6 = 0xbf;
      break;
    case 0xbd:
      uVar7 = 1;
      uVar6 = 0xc0;
      break;
    case 0xbe:
      uVar7 = 0;
      uVar6 = 0xc1;
      break;
    case 0xbf:
      uVar7 = 0;
      uVar6 = 0xc2;
      break;
    case 0xc0:
      uVar7 = 1;
      uVar6 = 0xc3;
      break;
    case 0xc1:
      uVar7 = 1;
      uVar6 = 0xc4;
      break;
    case 0xc2:
      uVar7 = 1;
      uVar6 = 0xc5;
      break;
    case 0xc3:
      uVar7 = 1;
      uVar6 = 0xc6;
      break;
    case 0xc4:
      uVar7 = 1;
      uVar6 = 199;
      break;
    case 0xc5:
      uVar7 = 2;
      uVar6 = 200;
      break;
    case 0xc6:
      uVar7 = 2;
      uVar6 = 0xc9;
      break;
    case 199:
      uVar7 = 2;
      uVar6 = 0xca;
      break;
    case 200:
      uVar7 = 1;
      uVar6 = 0xcb;
      break;
    case 0xc9:
      uVar7 = 1;
      uVar6 = 0xcc;
      break;
    case 0xca:
      uVar7 = 2;
      uVar6 = 0xcd;
      break;
    case 0xcb:
      uVar7 = 1;
      uVar6 = 0xce;
      break;
    case 0xcc:
      uVar7 = 1;
      uVar6 = 0xcf;
      break;
    case 0xcd:
      uVar7 = 3;
      uVar6 = 0xd0;
      break;
    case 0xce:
      uVar7 = 1;
      uVar6 = 0xd1;
      break;
    case 0xcf:
      uVar7 = 3;
      uVar6 = 0xd2;
      break;
    case 0xd0:
      uVar7 = 1;
      uVar6 = 0xd3;
      break;
    case 0xd1:
      uVar7 = 1;
      uVar6 = 0xd4;
      break;
    case 0xd2:
      uVar7 = 1;
      uVar6 = 0xd5;
      break;
    case 0xd3:
      uVar7 = 1;
      uVar6 = 0xd6;
      break;
    case 0xd4:
      uVar7 = 2;
      uVar6 = 0xd7;
      break;
    case 0xd5:
      uVar7 = 2;
      uVar6 = 0xd8;
      break;
    case 0xd6:
      uVar7 = 1;
      uVar6 = 0xd9;
      break;
    case 0xd7:
      uVar7 = 1;
      uVar6 = 0xda;
      break;
    case 0xd8:
      uVar7 = 1;
      uVar6 = 0xdb;
      break;
    case 0xd9:
      uVar7 = 1;
      uVar6 = 0xdc;
      break;
    case 0xda:
      uVar7 = 1;
      uVar6 = 0xdd;
      break;
    case 0xdb:
      uVar7 = 1;
      uVar6 = 0xde;
      break;
    case 0xdc:
      uVar7 = 1;
      uVar6 = 0xdf;
      break;
    case 0xdd:
      uVar7 = 1;
      uVar6 = 0xe0;
      break;
    case 0xde:
      uVar7 = 1;
      uVar6 = 0xe1;
      break;
    case 0xdf:
      uVar7 = 2;
      uVar6 = 0xe2;
      break;
    case 0xe0:
      uVar7 = 1;
      uVar6 = 0xe3;
      break;
    case 0xe1:
      uVar7 = 2;
      uVar6 = 0xe4;
      break;
    case 0xe2:
      uVar7 = 2;
      uVar6 = 0xe5;
      break;
    case 0xe3:
      uVar7 = 2;
      uVar6 = 0xe6;
      break;
    case 0xe4:
      uVar7 = 1;
      uVar6 = 0xe7;
      break;
    case 0xe5:
      uVar7 = 2;
      uVar6 = 0xe8;
      break;
    case 0xe6:
      uVar7 = 2;
      uVar6 = 0xe9;
      break;
    case 0xe7:
      uVar7 = 1;
      uVar6 = 0xea;
      break;
    case 0xe8:
      uVar7 = 2;
      uVar6 = 0xeb;
      break;
    case 0xe9:
      uVar7 = 2;
      uVar6 = 0xec;
      break;
    case 0xea:
      uVar7 = 2;
      uVar6 = 0xed;
      break;
    case 0xeb:
      uVar7 = 2;
      uVar6 = 0xee;
      break;
    case 0xec:
      uVar7 = 1;
      uVar6 = 0xef;
      break;
    case 0xed:
      uVar7 = 2;
      uVar6 = 0xf0;
      break;
    case 0xee:
      uVar7 = 2;
      uVar6 = 0xf1;
      break;
    case 0xef:
      uVar7 = 1;
      uVar6 = 0xf2;
      break;
    case 0xf0:
      uVar7 = 2;
      uVar6 = 0xf3;
      break;
    case 0xf1:
      uVar7 = 1;
      uVar6 = 0xf4;
      break;
    case 0xf2:
      uVar7 = 2;
      uVar6 = 0xf5;
      break;
    case 0xf3:
      uVar7 = 1;
      uVar6 = 0xfd;
      break;
    case 0xf4:
      uVar7 = 3;
      uVar6 = 0xfe;
      break;
    case 0xf5:
      uVar7 = 1;
      uVar6 = 0xf6;
      break;
    case 0xf6:
      uVar7 = 2;
      uVar6 = 0xf7;
      break;
    case 0xf7:
      uVar7 = 2;
      uVar6 = 0xf8;
      break;
    case 0xf8:
      uVar7 = 2;
      uVar6 = 0xf9;
      break;
    case 0xf9:
      uVar7 = 2;
      uVar6 = 0xfa;
      break;
    case 0xfa:
      uVar7 = 2;
      uVar6 = 0xfb;
      break;
    case 0xfb:
      uVar7 = 2;
      uVar6 = 0xfc;
      break;
    case 0xfc:
      uVar7 = 1;
      uVar6 = 0xff;
      break;
    case 0xfd:
      uVar7 = 2;
      uVar6 = 0x100;
      break;
    case 0xfe:
      uVar7 = 0;
      uVar6 = 0x101;
      break;
    case 0xff:
      uVar7 = 1;
      uVar6 = 0x102;
      break;
    case 0x100:
      uVar7 = 1;
      uVar6 = 0x103;
      break;
    case 0x101:
      uVar7 = 1;
      uVar6 = 0x104;
      break;
    case 0x102:
      uVar7 = 1;
      uVar6 = 0x105;
      break;
    case 0x103:
      uVar7 = 1;
      uVar6 = 0x106;
      break;
    case 0x104:
      uVar7 = 2;
      uVar6 = 0x107;
      break;
    case 0x105:
      uVar7 = 1;
      uVar6 = 0x108;
      break;
    case 0x106:
      uVar7 = 1;
      uVar6 = 0x109;
      break;
    case 0x107:
      uVar7 = 2;
      uVar6 = 0x10a;
      break;
    case 0x108:
      uVar7 = 1;
      uVar6 = 0x10b;
      break;
    case 0x109:
      uVar7 = 1;
      uVar6 = 0x10c;
      break;
    case 0x10a:
      uVar7 = 1;
      uVar6 = 0x10d;
      break;
    case 0x10b:
      uVar7 = 1;
      uVar6 = 0x10e;
      break;
    case 0x10c:
      uVar7 = 1;
      uVar6 = 0x10f;
      break;
    case 0x10d:
      uVar7 = 2;
      uVar6 = 0x110;
      break;
    case 0x10e:
      uVar7 = 1;
      uVar6 = 0x111;
      break;
    case 0x10f:
      uVar7 = 0;
      uVar6 = 0x112;
      break;
    case 0x110:
      uVar7 = 0;
      uVar6 = 0x113;
      break;
    case 0x111:
      uVar7 = 0;
      uVar6 = 0x114;
      break;
    case 0x112:
      uVar7 = 1;
      uVar6 = 0x115;
      break;
    case 0x113:
      uVar7 = 1;
      uVar6 = 0x116;
      break;
    case 0x114:
      uVar7 = 0;
      uVar6 = 0x117;
      break;
    case 0x115:
      uVar7 = 1;
      uVar6 = 0x118;
      break;
    case 0x116:
      uVar7 = 1;
      uVar6 = 0x119;
      break;
    case 0x117:
      uVar7 = 0;
      uVar6 = 0x11a;
      break;
    case 0x118:
      uVar7 = 0;
      uVar6 = 0x11b;
      break;
    case 0x119:
      uVar7 = 0;
      uVar6 = 0x11c;
      break;
    case 0x11a:
      uVar7 = 0;
      uVar6 = 0x11d;
      break;
    case 0x11b:
      uVar7 = 0;
      uVar6 = 0x11e;
      break;
    case 0x11c:
      uVar7 = 0;
      uVar6 = 0x11f;
      break;
    case 0x11d:
      uVar7 = 0;
      uVar6 = 0x120;
      break;
    case 0x11e:
      uVar7 = 1;
      uVar6 = 0x121;
      break;
    case 0x11f:
      uVar7 = 2;
      uVar6 = 0x122;
      break;
    case 0x120:
      uVar7 = 0;
      uVar6 = 0x123;
      break;
    case 0x121:
      uVar7 = 0;
      uVar6 = 0x124;
      break;
    case 0x122:
      uVar7 = 0;
      uVar6 = 0x125;
      break;
    case 0x123:
      uVar7 = 0;
      uVar6 = 0x126;
      break;
    case 0x124:
      uVar7 = 0;
      uVar6 = 0x127;
      break;
    case 0x125:
      uVar7 = 0;
      uVar6 = 0x128;
      break;
    default:
      goto switchD_008d3b9c_default;
    }
    FUN_008d26dc(uVar6,uVar7);
switchD_008d3b9c_default:
    DAT_00b5f6b4 = DAT_00b5f6b4 + -iVar4;
    iVar3 = (int)*DAT_00b5f6b4;
    DAT_00b5f6b0 = DAT_00b5f6b0 + -iVar4;
    iVar4 = (int)*(short *)(iVar2 * 2 + 0xb54890);
    if ((iVar3 == 0) && (iVar4 == 0)) {
      DAT_00b5f6b4 = DAT_00b5f6b4 + 1;
      iVar4 = 0x28;
      *DAT_00b5f6b4 = 0x28;
      DAT_00b5f6b0 = DAT_00b5f6b0 + 1;
      *DAT_00b5f6b0 = DAT_00b5f6ac;
      bVar5 = DAT_00b5f6b8 == 0;
      if (DAT_00b5f6b8 < 0) {
        DAT_00b5f6b8 = FUN_008cfce0();
        bVar5 = DAT_00b5f6b8 == 0;
        if (DAT_00b5f6b8 < 0) {
          DAT_00b5f6b8 = 0;
          bVar5 = true;
        }
      }
      if (bVar5) {
        return 0;
      }
      goto LAB_008d3a85;
    }
    iVar4 = iVar4 * 2;
    if ((((*(short *)(&DAT_00b55970 + iVar4) == 0) ||
         (iVar2 = *(short *)(&DAT_00b55970 + iVar4) + iVar3, iVar2 < 0)) || (0xd88 < iVar2)) ||
       (*(short *)(&DAT_00b57570 + iVar2 * 2) != iVar3)) {
      sVar1 = *(short *)(&DAT_00b550f8 + iVar4);
    }
    else {
      sVar1 = *(short *)(&DAT_00b55a58 + iVar2 * 2);
    }
    if ((short *)0xb5f6a5 < DAT_00b5f6b4) {
LAB_008d4897:
      FUN_008c97ba(DAT_00b5f6c8,s_yacc_stack_overflow_00a17c74);
      return 1;
    }
    DAT_00b5f6b4 = DAT_00b5f6b4 + 1;
    *DAT_00b5f6b4 = sVar1;
    uVar6 = DAT_00b5f6ac;
  }
  iVar4 = (int)sVar1;
  DAT_00b5f6b0 = DAT_00b5f6b0 + 1;
  *DAT_00b5f6b0 = uVar6;
  goto LAB_008d3a85;
LAB_008d488b:
  if (DAT_00b5f6b8 == 0) {
    return 1;
  }
  goto LAB_008d3a80;
}


// ==== FUN_008d4d44 @ 0x008d4d44 ====

uint FUN_008d4d44(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x8876086c;
  }
  else {
    *param_3 = 0;
    *in_ECX = param_2;
    in_ECX[1] = param_1;
    in_ECX[2] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 1;
    in_ECX[0x13] = 0;
    in_ECX[0x14] = 0;
    in_ECX[0x15] = 0;
    in_ECX[0x16] = 0;
    DAT_00b5f6c8 = in_ECX;
    uVar1 = FUN_008be4a1(1);
    if (-1 < (int)uVar1) {
      FUN_008c9a5a(0,0);
      iVar2 = FUN_008d3a45();
      if (iVar2 != 0) {
        in_ECX[0x10] = 1;
      }
      uVar1 = FUN_008c19ba();
      if (-1 < (int)uVar1) {
        if (in_ECX[0x10] == 0) {
          *param_3 = *(undefined4 *)(in_ECX[2] + 8);
          *(undefined4 *)(in_ECX[2] + 8) = 0;
        }
        uVar1 = -(uint)(in_ECX[0x10] != 0) & 0x80004005;
      }
    }
  }
  return uVar1;
}


// ==== FUN_008d4df2 @ 0x008d4df2 ====

int FUN_008d4df2(int *param_1,int param_2,int *param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  piVar1 = param_1;
  uVar4 = 0;
  if (param_4 != 0) {
    piVar3 = param_3;
    do {
      param_1 = (int *)0x0;
      if (*piVar3 != 0) {
        param_1 = (int *)0xffffffff;
      }
      iVar2 = (**(code **)(*piVar1 + 0x188))(piVar1,param_2 + uVar4,&param_1,1);
      if (iVar2 < 0) {
        return iVar2;
      }
      piVar3 = piVar3 + 1;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_4);
  }
  return 0;
}


// ==== FUN_008d4e3f @ 0x008d4e3f ====

undefined4 FUN_008d4e3f(void)

{
  undefined4 *puVar1;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = *(int *)(in_ECX + 0x110);
  *(int *)(in_ECX + 0x110) = iVar3 << 1;
  puVar1 = operator_new(iVar3 << 3);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  puVar4 = *(undefined4 **)(in_ECX + 0x108);
  for (uVar2 = *(uint *)(in_ECX + 0x10c) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = puVar1 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  _free(*(void **)(in_ECX + 0x108));
  return extraout_EAX;
}


// ==== FUN_008d4ea9 @ 0x008d4ea9 ====

int FUN_008d4ea9(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (*(int *)(in_ECX + 0xb4) == 0) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_1 + 0x14) * 4);
    if (*(int *)(iVar1 + 0x34) != 0) {
      puVar4 = *(undefined4 **)(*(int *)(iVar1 + 0x34) + 0x18);
      if ((*(byte *)(in_ECX + 0x119) & 1) == 0) {
        piVar3 = puVar4 + 7;
        do {
          puVar4 = (undefined4 *)*piVar3;
          *puVar4 = 1;
          *(undefined4 *)
           ((uint)*(ushort *)((int)puVar4 + 0x16) * 100 +
           *(int *)((uint)*(ushort *)(puVar4 + 5) * 100 + 4 + *(int *)(in_ECX + 0x2c))) = 1;
          piVar3 = puVar4 + 7;
        } while (*piVar3 != *(int *)(iVar1 + 0x34));
      }
      else {
        do {
          puVar4 = (undefined4 *)puVar4[7];
          *puVar4 = 1;
          puVar5 = (undefined4 *)
                   ((uint)*(ushort *)((int)puVar4 + 0x16) * 100 +
                   *(int *)((uint)*(ushort *)(puVar4 + 5) * 100 + 4 + *(int *)(in_ECX + 0x2c)));
          *puVar5 = 1;
          if ((*(byte *)(puVar5 + 0xc) & 2) == 0) {
            if ((*(uint *)(in_ECX + 0x110) <= *(uint *)(in_ECX + 0x10c)) &&
               (iVar2 = FUN_008d4e3f(), iVar2 < 0)) {
              return iVar2;
            }
            *(undefined2 *)(*(int *)(in_ECX + 0x108) + *(int *)(in_ECX + 0x10c) * 4) =
                 *(undefined2 *)(puVar4 + 5);
            *(undefined2 *)(*(int *)(in_ECX + 0x108) + 2 + *(int *)(in_ECX + 0x10c) * 4) =
                 *(undefined2 *)((int)puVar4 + 0x16);
            puVar5[0xc] = puVar5[0xc] | 2;
            *(int *)(in_ECX + 0x10c) = *(int *)(in_ECX + 0x10c) + 1;
          }
        } while (puVar4[7] != *(int *)(iVar1 + 0x34));
      }
    }
  }
  else if (*(uint *)(param_1 + 0x14) < *(uint *)(in_ECX + 0xac)) {
    *(undefined1 *)(*(uint *)(param_1 + 0x14) + *(int *)(in_ECX + 0xbc)) = 1;
    piVar3 = *(int **)(*(int *)(in_ECX + 0xb8) + *(int *)(param_1 + 0x14) * 4);
    if (piVar3 != (int *)0x0) {
      if ((*(byte *)(in_ECX + 0x119) & 1) == 0) {
        for (; (undefined4 *)*piVar3 != (undefined4 *)0x0; piVar3 = piVar3 + 1) {
          *(undefined4 *)*piVar3 = 1;
          **(undefined4 **)(*piVar3 + 8) = 1;
        }
      }
      else {
        for (; puVar4 = (undefined4 *)*piVar3, puVar4 != (undefined4 *)0x0; piVar3 = piVar3 + 1) {
          puVar5 = (undefined4 *)puVar4[2];
          *puVar4 = 1;
          *puVar5 = 1;
          if ((*(byte *)(puVar5 + 0xc) & 2) == 0) {
            if ((*(uint *)(in_ECX + 0x110) <= *(uint *)(in_ECX + 0x10c)) &&
               (iVar1 = FUN_008d4e3f(), iVar1 < 0)) {
              return iVar1;
            }
            *(undefined2 *)(*(int *)(in_ECX + 0x108) + *(int *)(in_ECX + 0x10c) * 4) =
                 *(undefined2 *)(puVar4 + 5);
            *(undefined2 *)(*(int *)(in_ECX + 0x108) + 2 + *(int *)(in_ECX + 0x10c) * 4) =
                 *(undefined2 *)((int)puVar4 + 0x16);
            puVar5[0xc] = puVar5[0xc] | 2;
            *(int *)(in_ECX + 0x10c) = *(int *)(in_ECX + 0x10c) + 1;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_008d507a @ 0x008d507a ====

int FUN_008d507a(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0x3c) == 4) {
    if (*(int *)(param_1 + 0x38) != 0) {
      piVar1 = (int *)(*(int *)(param_1 + 0x38) + 8);
      *piVar1 = *piVar1 + -1;
      *(undefined4 *)(*(int *)(param_1 + 0x38) + 0xc) = 0;
    }
    iVar3 = (uint)*(ushort *)(param_1 + 0x42) * 0xb4 + *(int *)(param_1 + 0xa4);
    *(undefined4 *)(param_1 + 0x3c) = 0;
    if ((*(byte *)(param_1 + 0x118) & 8) != 0) {
      if (*(int *)(iVar3 + 0x88) == 0) {
        iVar2 = 0;
      }
      else {
        piVar1 = *(int **)(iVar3 + 0x88);
        iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
      }
      if (-1 < iVar2) {
        if ((*(byte *)(param_1 + 0x118) & 0x20) != 0) {
          if (*(int *)(iVar3 + 0x90) == 0) {
            iVar2 = 0;
          }
          else {
            piVar1 = *(int **)(iVar3 + 0x90);
            iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
          }
          if (iVar2 < 0) {
            return iVar2;
          }
          if (*(int *)(iVar3 + 0x8c) == 0) {
            iVar2 = 0;
          }
          else {
            piVar1 = *(int **)(iVar3 + 0x8c);
            iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
          }
          if (iVar2 < 0) {
            return iVar2;
          }
        }
        if ((*(byte *)(param_1 + 0x118) & 0x10) != 0) {
          if (*(int *)(iVar3 + 0x98) == 0) {
            iVar2 = 0;
          }
          else {
            piVar1 = *(int **)(iVar3 + 0x98);
            iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
          }
          if (-1 < iVar2) {
            if (*(int *)(iVar3 + 0x94) == 0) {
              iVar2 = 0;
            }
            else {
              piVar1 = *(int **)(iVar3 + 0x94);
              iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
            }
          }
        }
      }
    }
  }
  else {
    iVar2 = -0x7fffbffb;
  }
  return iVar2;
}


// ==== FUN_008d5160 @ 0x008d5160 ====

undefined4 FUN_008d5160(int param_1)

{
  uint *puVar1;
  ushort *puVar2;
  uint uVar3;
  
  *(byte *)(param_1 + 0x119) = *(byte *)(param_1 + 0x119) & 0xfe;
  if (*(int *)(param_1 + 0x10c) != 0) {
    uVar3 = 0;
    if (*(int *)(param_1 + 0x10c) != 0) {
      do {
        puVar2 = (ushort *)(*(int *)(param_1 + 0x108) + uVar3 * 4);
        puVar1 = (uint *)((uint)puVar2[1] * 100 +
                          *(int *)((uint)*puVar2 * 100 + 4 + *(int *)(param_1 + 0x2c)) + 0x30);
        *puVar1 = *puVar1 & 0xfffffffd;
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(param_1 + 0x10c));
    }
    *(undefined4 *)(param_1 + 0x10c) = 0;
  }
  return 0;
}


// ==== FUN_008d51ba @ 0x008d51ba ====

undefined4 FUN_008d51ba(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  int in_ECX;
  uint uVar7;
  int *piVar8;
  ushort *puVar9;
  uint local_8;
  
  piVar8 = (int *)(param_1 * 100 + *(int *)(in_ECX + 0x2c));
  sVar5 = (short)param_2;
  if (-1 < (int)((uint)*(ushort *)(piVar8 + 0xf) + (int)sVar5)) {
    *(ushort *)(piVar8 + 0xf) = *(ushort *)(piVar8 + 0xf) + sVar5;
  }
  sVar6 = (short)param_3;
  if (-1 < (int)((uint)*(ushort *)((int)piVar8 + 0x3a) + (int)sVar6)) {
    *(ushort *)((int)piVar8 + 0x3a) = *(ushort *)((int)piVar8 + 0x3a) + sVar6;
  }
  iVar1 = piVar8[5];
  iVar2 = *piVar8;
  param_1 = 0;
  if ((short)piVar8[0xd] != 0) {
    do {
      iVar4 = (uint)*(ushort *)(iVar1 + iVar2 + param_1 * 2) * 100 + piVar8[1];
      puVar9 = (ushort *)(*(int *)(iVar4 + 0x48) + *piVar8);
      if (*puVar9 != 0) {
        uVar3 = *(uint *)(*(int *)(iVar4 + 0xc) + 0x10);
        local_8 = 0;
        while( true ) {
          uVar7 = uVar3;
          if (uVar3 == 0) {
            uVar7 = 1;
          }
          if (uVar7 <= (local_8 & 0xffff)) break;
          if (sVar6 != 0) {
            FUN_008d51ba((*puVar9 - 1) + (local_8 & 0xffff),0,param_3);
          }
          local_8 = local_8 + 1;
        }
        if (sVar5 != 0) {
          FUN_008d51ba((puVar9[1] - 1) + (uint)*puVar9,param_2,0);
        }
      }
      param_1 = param_1 + 1;
    } while (param_1 < *(ushort *)(piVar8 + 0xd));
  }
  return 0;
}


// ==== FUN_008d52a6 @ 0x008d52a6 ====

int FUN_008d52a6(uint param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  undefined1 local_418 [4];
  undefined1 auStack_414 [516];
  undefined4 local_210;
  undefined4 local_20c;
  int *local_8;
  
  local_8 = (int *)0x0;
  if (param_1 == 0) {
    piVar1 = (int *)(in_ECX + 0x100);
    if (*piVar1 != 0) {
      (**(code **)(*(int *)*piVar1 + 4))((int *)*piVar1);
    }
    local_8 = (int *)*piVar1;
  }
  else {
    iVar2 = FUN_008f2df6(param_1,local_418,&param_1);
    if (iVar2 < 0) goto LAB_008d5398;
    if (0x40 < param_1) {
      iVar2 = -0x7fffbffb;
      goto LAB_008d5398;
    }
    uVar3 = 0;
    if (param_1 != 0) {
      do {
        iVar2 = uVar3 * 8;
        *(undefined2 *)(auStack_414 + iVar2 + 0x204) = 0;
        *(short *)(auStack_414 + iVar2 + 0x206) = (short)uVar3 * 0xc;
        auStack_414[iVar2 + 0x208] = 2;
        auStack_414[iVar2 + 0x209] = 0;
        auStack_414[iVar2 + 0x20a] = local_418[iVar2];
        uVar3 = uVar3 + 1;
        auStack_414[iVar2 + 0x20b] = auStack_414[iVar2];
      } while (uVar3 < param_1);
    }
    *(undefined4 *)(auStack_414 + uVar3 * 8 + 0x204) = DAT_00a210a0;
    *(undefined4 *)(auStack_414 + uVar3 * 8 + 0x208) = DAT_00a210a4;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x158))
                      (*(int **)(in_ECX + 0xc),&local_210,&local_8);
    if (iVar2 < 0) goto LAB_008d5398;
  }
  iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x15c))(*(int **)(in_ECX + 0xc),local_8);
LAB_008d5398:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar2;
}


// ==== FUN_008d53ae @ 0x008d53ae ====

int FUN_008d53ae(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar3 = param_1;
  iVar4 = *param_1;
  iVar5 = *(int *)(iVar4 + 0x10);
  iVar1 = *(int *)(iVar4 + 4);
  if (iVar5 == 0) {
    iVar5 = 1;
  }
  if (-1 < iVar1) {
    if (iVar1 < 4) {
      uVar2 = *(uint *)(iVar4 + 0x14);
      iVar1 = *(int *)(iVar4 + 0x18);
      *param_1 = iVar4 + 0x1c;
      return ((uint)(uVar2 % param_2 != 0) + uVar2 / param_2) * iVar1 * iVar5;
    }
    if ((iVar1 != 4) && (iVar1 == 5)) {
      iVar1 = *(int *)(iVar4 + 0x14);
      iVar6 = 0;
      *param_1 = iVar4 + 0x18;
      if (iVar1 != 0) {
        param_1 = (int *)iVar1;
        do {
          iVar4 = FUN_008d53ae(piVar3,param_2);
          iVar6 = iVar6 + iVar4;
          param_1 = (int *)((int)param_1 + -1);
        } while (param_1 != (int *)0x0);
      }
      return iVar6 * iVar5;
    }
  }
  return 0;
}


// ==== FUN_008d542d @ 0x008d542d ====

undefined4 FUN_008d542d(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar3 = *param_1;
  iVar1 = *(int *)(iVar3 + 4);
  if (iVar1 < 0) {
LAB_008d547e:
    uVar4 = 0;
  }
  else {
    if (iVar1 < 2) {
      *param_1 = iVar3 + 0x1c;
    }
    else {
      if (((iVar1 < 4) || (iVar1 == 4)) || (iVar1 != 5)) goto LAB_008d547e;
      uVar2 = *(uint *)(iVar3 + 0x14);
      uVar5 = 0;
      *param_1 = iVar3 + 0x18;
      if (uVar2 != 0) {
        do {
          iVar3 = FUN_008d542d(param_1);
          if (iVar3 == 0) goto LAB_008d547e;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar2);
      }
    }
    uVar4 = 1;
  }
  return uVar4;
}


// ==== FUN_008d5487 @ 0x008d5487 ====

int FUN_008d5487(int *param_1,int *param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint local_28;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar6 = param_4;
  piVar5 = param_3;
  piVar1 = (int *)*param_1;
  iVar9 = piVar1[1];
  local_c = piVar1[4];
  local_14 = 0;
  if (local_c == 0) {
    local_c = 1;
  }
  if (-1 < iVar9) {
    if (iVar9 < 4) {
      uVar2 = piVar1[5];
      uVar3 = piVar1[6];
      iVar9 = *piVar1;
      uVar11 = (uVar2 >> 2) + (uint)((uVar2 & 3) != 0);
      local_10 = uVar11;
      local_8 = uVar2;
      if (iVar9 == 1) {
        local_18 = 0;
        uVar12 = uVar11;
        if (local_c != 0) {
          do {
            uVar7 = 0;
            if (*param_4 == 0) break;
            if (uVar3 != 0) {
              do {
                uVar4 = *param_4;
                if (uVar4 == 0) break;
                if (uVar4 < uVar11) {
                  local_8 = uVar4 << 2;
                  local_10 = uVar4;
                }
                if (local_8 != 0) {
                  local_1c = uVar7 << 2;
                  local_28 = local_8;
                  do {
                    uVar8 = __ftol();
                    *(undefined4 *)(local_1c + *param_2) = uVar8;
                    local_1c = local_1c + uVar3 * 4;
                    local_28 = local_28 - 1;
                  } while (local_28 != 0);
                }
                *param_4 = *param_4 - local_10;
                uVar7 = uVar7 + 1;
                uVar12 = local_10;
              } while (uVar7 < uVar3);
            }
            *param_3 = *param_3 + uVar7 * uVar12 * 8;
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_18 = local_18 + 1;
          } while (local_18 < local_c);
        }
      }
      else if (iVar9 == 2) {
        local_1c = 0;
        uVar12 = uVar11;
        if (local_c != 0) {
          do {
            uVar7 = 0;
            if (*param_4 == 0) break;
            if (uVar3 != 0) {
              do {
                uVar4 = *param_4;
                if (uVar4 == 0) break;
                if (uVar4 < uVar11) {
                  local_8 = uVar4 << 2;
                  local_10 = uVar4;
                }
                if (local_8 != 0) {
                  local_18 = uVar7 << 2;
                  local_28 = local_8;
                  do {
                    uVar8 = __ftol();
                    *(undefined4 *)(local_18 + *param_2) = uVar8;
                    local_18 = local_18 + uVar3 * 4;
                    local_28 = local_28 - 1;
                  } while (local_28 != 0);
                }
                *param_4 = *param_4 - local_10;
                uVar7 = uVar7 + 1;
                uVar12 = local_10;
              } while (uVar7 < uVar3);
            }
            *param_3 = *param_3 + uVar7 * uVar12 * 8;
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_1c = local_1c + 1;
          } while (local_1c < local_c);
        }
      }
      else {
        if (iVar9 != 3) {
          return -0x7fffbffb;
        }
        local_18 = 0;
        if (local_c != 0) {
          uVar12 = uVar11;
          do {
            uVar7 = 0;
            if (*param_4 == 0) break;
            if (uVar3 != 0) {
              do {
                uVar4 = *param_4;
                if (uVar4 == 0) break;
                if (uVar4 < uVar11) {
                  local_8 = uVar4 << 2;
                  local_10 = uVar4;
                }
                if (local_8 != 0) {
                  iVar10 = uVar7 << 2;
                  iVar9 = uVar7 << 3;
                  param_3 = (int *)local_8;
                  do {
                    *(float *)(iVar10 + *param_2) = (float)*(double *)(iVar9 + *piVar5);
                    iVar9 = iVar9 + uVar3 * 8;
                    iVar10 = iVar10 + uVar3 * 4;
                    param_3 = (int *)((int)param_3 - 1);
                  } while (param_3 != (int *)0x0);
                }
                *param_4 = *param_4 - local_10;
                uVar7 = uVar7 + 1;
                uVar12 = local_10;
              } while (uVar7 < uVar3);
            }
            *piVar5 = *piVar5 + uVar7 * uVar12 * 8;
            *param_2 = *param_2 + uVar3 * uVar2 * 4;
            local_18 = local_18 + 1;
          } while (local_18 < local_c);
        }
      }
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar9 == 5) {
      local_10 = 0;
      uVar2 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      if (local_c == 0) {
        return 0;
      }
      do {
        if (*puVar6 == 0) {
          return local_14;
        }
        param_4 = (uint *)0x0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar2 != 0) {
          do {
            if (*puVar6 == 0) break;
            local_14 = FUN_008d5487(param_1,param_2,param_3,puVar6);
            if (local_14 < 0) {
              return local_14;
            }
            param_4 = (uint *)((int)param_4 + 1);
          } while (param_4 < uVar2);
        }
        local_10 = local_10 + 1;
        if (local_c <= local_10) {
          return local_14;
        }
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008d578c @ 0x008d578c ====

undefined4 FUN_008d578c(uint param_1,int *param_2,short *param_3,ushort *param_4,ushort *param_5)

{
  short sVar1;
  short *psVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  uint *puVar6;
  ushort uVar7;
  uint uVar8;
  undefined4 local_8;
  
  puVar4 = param_5;
  puVar3 = param_4;
  psVar2 = param_3;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  *param_4 = 0xffff;
  param_4[1] = 0xffff;
  param_4[2] = 0xffff;
  param_4[3] = 0xffff;
  *param_5 = 0;
  param_5[1] = 0;
  param_5[2] = 0;
  param_5[3] = 0;
  local_8 = 0;
  *param_2 = 0;
  if (param_1 != 0) {
    param_4 = (ushort *)0x0;
    iVar5 = FUN_008f2d0f(param_1,0x42415443,&param_4,&param_1);
    if (iVar5 < 0) {
      return 0;
    }
    if (param_4 != (ushort *)0x0) {
      if ((param_1 < 0x1c) || (param_1 < *(int *)((int)param_4 + 0xc) * 4 + 0x1cU)) {
LAB_008d581a:
        local_8 = 0x80004005;
      }
      else {
        param_5 = (ushort *)0x0;
        puVar6 = (uint *)(*(int *)((int)param_4 + 0x10) + (int)param_4);
        if (*(int *)((int)param_4 + 0xc) != 0) {
          do {
            param_3 = (short *)0x0;
            for (uVar8 = *puVar6; (uVar8 < param_1 && (*(char *)(uVar8 + (int)param_4) != '\0'));
                uVar8 = uVar8 + 1) {
              param_3 = (short *)((int)param_3 + 1);
            }
            if (param_1 <= *puVar6 + (int)param_3) goto LAB_008d581a;
            sVar1 = (short)puVar6[1];
            if (sVar1 == 0) {
              psVar2[1] = psVar2[1] + (short)puVar6[2];
              uVar7 = puVar4[1];
              param_3 = (short *)0x4;
              if ((uint)uVar7 <= (uint)(ushort)puVar6[2] + (uint)*(ushort *)((int)puVar6 + 6)) {
                uVar7 = (short)puVar6[2] + *(short *)((int)puVar6 + 6);
              }
              puVar4[1] = uVar7;
              uVar7 = puVar3[1];
              if (*(ushort *)((int)puVar6 + 6) <= puVar3[1]) {
                uVar7 = *(ushort *)((int)puVar6 + 6);
              }
              puVar3[1] = uVar7;
            }
            else if (sVar1 == 1) {
              psVar2[2] = psVar2[2] + (short)puVar6[2];
              uVar7 = puVar4[2];
              param_3 = (short *)0x10;
              if ((uint)uVar7 <= (uint)(ushort)puVar6[2] + (uint)*(ushort *)((int)puVar6 + 6)) {
                uVar7 = (short)puVar6[2] + *(short *)((int)puVar6 + 6);
              }
              puVar4[2] = uVar7;
              uVar7 = puVar3[2];
              if (*(ushort *)((int)puVar6 + 6) <= puVar3[2]) {
                uVar7 = *(ushort *)((int)puVar6 + 6);
              }
              puVar3[2] = uVar7;
            }
            else if (sVar1 == 2) {
              *psVar2 = *psVar2 + (short)puVar6[2];
              uVar7 = *puVar4;
              param_3 = (short *)0x10;
              if ((uint)uVar7 <= (uint)(ushort)puVar6[2] + (uint)*(ushort *)((int)puVar6 + 6)) {
                uVar7 = (short)puVar6[2] + *(short *)((int)puVar6 + 6);
              }
              *puVar4 = uVar7;
              uVar7 = *puVar3;
              if (*(ushort *)((int)puVar6 + 6) <= *puVar3) {
                uVar7 = *(ushort *)((int)puVar6 + 6);
              }
              *puVar3 = uVar7;
            }
            else {
              if (sVar1 != 3) goto LAB_008d581a;
              psVar2[3] = psVar2[3] + (short)puVar6[2];
              param_3 = (short *)0x0;
              uVar7 = puVar4[3];
              if ((uint)uVar7 <= (uint)(ushort)puVar6[2] + (uint)*(ushort *)((int)puVar6 + 6)) {
                uVar7 = (short)puVar6[2] + *(short *)((int)puVar6 + 6);
              }
              puVar4[3] = uVar7;
              uVar7 = puVar3[3];
              if (*(ushort *)((int)puVar6 + 6) <= puVar3[3]) {
                uVar7 = *(ushort *)((int)puVar6 + 6);
              }
              puVar3[3] = uVar7;
            }
            iVar5 = (uint)(ushort)puVar6[2] * (int)param_3;
            if ((iVar5 != 0) && (param_1 <= puVar6[4] + iVar5)) goto LAB_008d581a;
            param_5 = (ushort *)((int)param_5 + 1);
            puVar6 = puVar6 + 5;
          } while (param_5 < *(uint *)((int)param_4 + 0xc));
        }
        *param_2 = (int)param_4;
      }
    }
  }
  return local_8;
}


// ==== FUN_008d59e0 @ 0x008d59e0 ====

int FUN_008d59e0(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(&DAT_00a210f8 + (uint)*(ushort *)(*param_1 + 4) * 4) -
          *(int *)(&DAT_00a210f8 + (uint)*(ushort *)(*param_2 + 4) * 4);
  if (iVar1 == 0) {
    iVar1 = (uint)*(ushort *)(*param_1 + 6) - (uint)*(ushort *)(*param_2 + 6);
  }
  return iVar1;
}


// ==== FUN_008d5a3d @ 0x008d5a3d ====

void FUN_008d5a3d(byte param_1)

{
  void *in_ECX;
  
  FUN_008de297();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008d5a5e @ 0x008d5a5e ====

void FUN_008d5a5e(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_8;
  
  in_ECX[2] = in_ECX[2] & 0xffffffe0;
  *(undefined2 *)((int)in_ECX + 0x3e) = 0xffff;
  *in_ECX = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[1] = 0;
  *(undefined2 *)(in_ECX + 0xd) = 0;
  *(undefined2 *)((int)in_ECX + 0x36) = 0;
  *(undefined2 *)(in_ECX + 0xe) = 0;
  *(undefined2 *)(in_ECX + 0xf) = 0;
  *(undefined2 *)((int)in_ECX + 0x3a) = 0;
  puVar3 = in_ECX + 0xb;
  puVar4 = in_ECX + 7;
  puVar1 = in_ECX + 6;
  local_8 = 2;
  do {
    *(undefined2 *)puVar1 = 0xffff;
    uVar2 = 0;
    do {
      *(undefined1 *)((int)puVar3 + uVar2) = 0;
      *(undefined2 *)puVar4 = 0;
      uVar2 = uVar2 + 1;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    } while (uVar2 < 4);
    puVar1 = (undefined4 *)((int)puVar1 + 2);
    puVar3 = puVar3 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}


// ==== FUN_008d5ac8 @ 0x008d5ac8 ====

undefined4 FUN_008d5ac8(void)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 extraout_EAX;
  undefined4 *in_ECX;
  undefined4 uVar4;
  
  iVar1 = (in_ECX[3] & 1) + (in_ECX[3] & 0xfffffffe);
  in_ECX[5] = iVar1;
  uVar2 = iVar1 + (uint)*(ushort *)(in_ECX + 0xd) * 2;
  uVar4 = 0;
  in_ECX[3] = uVar2;
  if ((uint)in_ECX[4] < uVar2) {
    pvVar3 = operator_new(uVar2);
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0x8007000e;
    }
    else {
      if ((void *)*in_ECX != (void *)0x0) {
        _free((void *)*in_ECX);
        return extraout_EAX;
      }
      *in_ECX = pvVar3;
      in_ECX[4] = in_ECX[3];
    }
  }
  return uVar4;
}


// ==== FUN_008d5b42 @ 0x008d5b42 ====

void FUN_008d5b42(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  piVar1 = (int *)in_ECX[1];
  if ((piVar1 != (int *)0x0) &&
     ((iVar2 = *in_ECX, iVar2 == 4 ||
      ((4 < iVar2 && (((iVar2 < 10 || (iVar2 == 0xf)) || (iVar2 == 0x10)))))))) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[1] = 0;
  }
  piVar1 = (int *)in_ECX[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[2] = 0;
  }
  return;
}


// ==== FUN_008d5b85 @ 0x008d5b85 ====

void FUN_008d5b85(void)

{
  int in_ECX;
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(in_ECX + 0xb4) == 0) {
    if (*(int *)(in_ECX + 0xc0) == 0) {
      return;
    }
    if (*(int *)(in_ECX + 0xa0) != 0) {
      do {
        *(uint *)(in_ECX + 0xb8) = *(int *)(in_ECX + 0xc0) + *(int *)(in_ECX + 0xac) * uVar1 * 4;
        if (*(int *)(in_ECX + 0xac) != 0) {
          _free((void *)**(undefined4 **)(in_ECX + 0xb8));
          return;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(in_ECX + 0xa0));
    }
    _free(*(void **)(in_ECX + 0xc0));
    return;
  }
  if (*(int *)(in_ECX + 0xa0) != 0) {
    do {
      *(uint *)(in_ECX + 0xb8) = *(int *)(in_ECX + 0xb4) + *(int *)(in_ECX + 0xac) * uVar1 * 4;
      if (*(int *)(in_ECX + 0xac) != 0) {
        _free((void *)**(undefined4 **)(in_ECX + 0xb8));
        return;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(in_ECX + 0xa0));
  }
  _free(*(void **)(in_ECX + 0xb4));
  return;
}


// ==== FUN_008d5c5b @ 0x008d5c5b ====

undefined4 FUN_008d5c5b(int param_1)

{
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  return *(undefined4 *)(param_1 + 0x24);
}


// ==== FUN_008d5c6d @ 0x008d5c6d ====

undefined4 FUN_008d5c6d(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  
  uVar2 = 0;
  if (param_3 == (undefined4 *)0x0) {
    uVar2 = 0x80004005;
  }
  else {
    iVar1 = 4;
    bVar5 = true;
    piVar3 = param_2;
    piVar4 = &DAT_00a24f7c;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *piVar3 == *piVar4;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar1 = 4;
      bVar5 = true;
      piVar3 = &DAT_00a52010;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *param_2 == *piVar3;
        param_2 = param_2 + 1;
        piVar3 = piVar3 + 1;
      } while (bVar5);
      if (!bVar5) {
        return 0x80004002;
      }
    }
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
  }
  return uVar2;
}


// ==== FUN_008d5cc2 @ 0x008d5cc2 ====

void FUN_008d5cc2(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 0x108));
  return;
}


// ==== FUN_008d5d05 @ 0x008d5d05 ====

void FUN_008d5d05(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  FUN_007a41ff(1);
  if ((*(byte *)(in_ECX + 0x119) & 2) == 0) {
    iVar2 = **(int **)(in_ECX + 0xc);
    uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0xc))(*(int **)(param_1 + 8),param_1 + 4);
    iVar2 = (**(code **)(iVar2 + 0x16c))(*(undefined4 *)(in_ECX + 0xc),uVar1);
    if (iVar2 < 0) {
      FUN_007a41ff(0);
      *(undefined4 *)(param_1 + 4) = 0;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffc;
    }
    else {
      FUN_007a41ff(0);
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 3;
    }
  }
  return;
}


// ==== FUN_008d5d63 @ 0x008d5d63 ====

void FUN_008d5d63(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  FUN_007a41ff(1);
  if ((*(byte *)(in_ECX + 0x119) & 2) == 0) {
    iVar2 = **(int **)(in_ECX + 0xc);
    uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0xc))(*(int **)(param_1 + 8),param_1 + 4);
    iVar2 = (**(code **)(iVar2 + 0x1a8))(*(undefined4 *)(in_ECX + 0xc),uVar1);
    if (iVar2 < 0) {
      FUN_007a41ff(0);
      *(undefined4 *)(param_1 + 4) = 0;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffc;
    }
    else {
      FUN_007a41ff(0);
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 3;
    }
  }
  return;
}


// ==== FUN_008d5dc1 @ 0x008d5dc1 ====

int FUN_008d5dc1(int *param_1,uint *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *_Memory;
  int iVar7;
  undefined4 *puVar8;
  int extraout_EAX;
  int in_ECX;
  undefined4 *puVar9;
  uint local_10;
  
  puVar4 = param_2;
  if ((param_1 != (int *)0x0) &&
     (uVar5 = (**(code **)(*param_1 + 0x10))(param_1), *param_2 + 1 <= uVar5)) {
    iVar6 = (**(code **)(*param_1 + 0xc))(param_1);
    local_10 = *(uint *)(iVar6 + *param_2 * 4);
  }
  *param_2 = *param_2 + 1;
  if ((param_1 != (int *)0x0) &&
     (uVar5 = (**(code **)(*param_1 + 0x10))(param_1), *param_2 + 1 <= uVar5)) {
    iVar6 = (**(code **)(*param_1 + 0xc))(param_1);
    param_2 = *(uint **)(iVar6 + *param_2 * 4);
  }
  *puVar4 = *puVar4 + 1;
  if (((param_1 == (int *)0x0) || (uVar5 = (**(code **)(*param_1 + 0x10))(param_1), uVar5 < *puVar4)
      ) || (*(uint *)(in_ECX + 0x14) <= local_10)) {
    return -0x7fffbffb;
  }
  _Memory = operator_new((uint)param_2);
  if (_Memory == (undefined4 *)0x0) {
    param_1 = (int *)0x8007000e;
    goto LAB_008d5fda;
  }
  if (param_2 != (uint *)0x0) {
    iVar6 = (uint)(((uint)param_2 & 3) != 0) + ((uint)param_2 >> 2);
    uVar5 = (**(code **)(*param_1 + 0x10))(param_1);
    if (*puVar4 + iVar6 <= uVar5) {
      iVar7 = (**(code **)(*param_1 + 0xc))(param_1);
      puVar9 = (undefined4 *)(iVar7 + *puVar4 * 4);
      puVar8 = _Memory;
      for (uVar5 = (uint)param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar8 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar5 = (uint)param_2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
    }
    *puVar4 = *puVar4 + iVar6;
  }
  uVar5 = (**(code **)(*param_1 + 0x10))(param_1);
  if (*puVar4 <= uVar5) {
    param_1 = (int *)0x0;
    piVar3 = (int *)(*(int *)(in_ECX + 0x18) + local_10 * 0x18);
    piVar1 = piVar3 + 1;
    if ((*piVar1 == 0) && (piVar2 = piVar3 + 2, *piVar2 == 0)) {
      if (param_2 == (uint *)0x0) goto LAB_008d5fda;
      iVar6 = *piVar3;
      if (iVar6 == 4) {
        if (*(char *)((int)param_2 + -1 + (int)_Memory) == '\0') {
          param_1 = (int *)FUN_008eb3df(param_2,piVar1);
          if (-1 < (int)param_1) {
            puVar8 = (undefined4 *)(**(code **)(*(int *)*piVar1 + 0xc))((int *)*piVar1);
            puVar9 = _Memory;
            for (uVar5 = (uint)param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *puVar8 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar8 = puVar8 + 1;
            }
            for (uVar5 = (uint)param_2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined1 *)puVar8 = *(undefined1 *)puVar9;
              puVar9 = (undefined4 *)((int)puVar9 + 1);
              puVar8 = (undefined4 *)((int)puVar8 + 1);
            }
          }
          goto LAB_008d5fda;
        }
      }
      else if ((0xe < iVar6) && (iVar6 < 0x11)) {
        param_1 = (int *)FUN_008eb3df(param_2,piVar2);
        if (-1 < (int)param_1) {
          puVar8 = (undefined4 *)(**(code **)(*(int *)*piVar2 + 0xc))((int *)*piVar2);
          puVar9 = _Memory;
          for (uVar5 = (uint)param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar8 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar8 = puVar8 + 1;
          }
          for (uVar5 = (uint)param_2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar8 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
          if (*piVar3 == 0x10) {
            FUN_008d5d05(piVar3);
            *(undefined2 *)((uint)*(ushort *)(piVar3 + 4) * 100 + 0x18 + *(int *)(in_ECX + 0x2c)) =
                 0;
          }
          else if (*piVar3 == 0xf) {
            FUN_008d5d63(piVar3);
            *(undefined2 *)((uint)*(ushort *)(piVar3 + 4) * 100 + 0x1a + *(int *)(in_ECX + 0x2c)) =
                 0;
          }
          **(undefined4 **)((uint)*(ushort *)(piVar3 + 4) * 100 + 4 + *(int *)(in_ECX + 0x2c)) = 1;
        }
        goto LAB_008d5fda;
      }
    }
  }
  param_1 = (int *)0x80004005;
LAB_008d5fda:
  if (_Memory == (undefined4 *)0x0) {
    return (int)param_1;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_008d5ff3 @ 0x008d5ff3 ====

uint FUN_008d5ff3(int param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = -(uint)((uint)(*(int *)(in_ECX + 0x1c) + *(int *)(in_ECX + 0x20)) <
                 (uint)(*(int *)(in_ECX + 0x20) + 4 + param_1)) & 0x80004005;
  if (-1 < (int)uVar2) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x20) + param_1);
    if (iVar1 != 0) {
      uVar2 = -(uint)((uint)(*(int *)(in_ECX + 0x20) + *(int *)(in_ECX + 0x1c)) <
                     (uint)(*(int *)(in_ECX + 0x20) + iVar1 + param_1 + 4)) & 0x80004005;
      if ((-1 < (int)uVar2) &&
         (*(char *)(*(int *)(in_ECX + 0x20) + iVar1 + -1 + param_1 + 4) != '\0')) {
        uVar2 = 0x80004005;
      }
    }
  }
  return uVar2;
}


// ==== FUN_008d604f @ 0x008d604f ====

uint FUN_008d604f(int param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  uint *puVar3;
  
  uVar2 = -(uint)((uint)(*(int *)(in_ECX + 0x1c) + *(int *)(in_ECX + 0x20)) <
                 (uint)(*(int *)(in_ECX + 0x20) + 4 + param_1)) & 0x80004005;
  if (-1 < (int)uVar2) {
    puVar3 = (uint *)(param_1 + *(int *)(in_ECX + 0x20));
    if (*puVar3 < 2) {
LAB_008d60ab:
      uVar2 = 0x80004005;
    }
    else {
      uVar2 = FUN_008d5ff3(param_1);
      if (-1 < (int)uVar2) {
        for (puVar3 = puVar3 + 1; cVar1 = (char)*puVar3, cVar1 != '\0';
            puVar3 = (uint *)((int)puVar3 + 1)) {
          if ((((cVar1 == '.') || (cVar1 == '@')) || (cVar1 == '[')) || (cVar1 == ']'))
          goto LAB_008d60ab;
        }
      }
    }
  }
  return uVar2;
}


// ==== FUN_008d60b3 @ 0x008d60b3 ====

undefined4 FUN_008d60b3(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  
  iVar3 = param_2 * 100 + *(int *)(param_1 * 100 + 4 + *(int *)(in_ECX + 0x2c));
  puVar2 = (undefined4 *)(param_3 * 0x20 + *(int *)(iVar3 + 0x34));
  puVar2[4] = param_5;
  puVar2[2] = iVar3;
  *puVar2 = 1;
  puVar2[3] = param_4;
  *(short *)(puVar2 + 5) = (short)param_1;
  *(short *)((int)puVar2 + 0x16) = (short)param_2;
  iVar1 = *(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_4 + 0x14) * 4);
  if (*(int *)(iVar1 + 0x34) == 0) {
    *(undefined4 **)(iVar1 + 0x34) = puVar2;
  }
  else {
    puVar2[6] = *(undefined4 *)
                 (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_4 + 0x14) * 4) + 0x34)
                 + 0x18);
    puVar2[7] = *(undefined4 *)
                 (*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_4 + 0x14) * 4) + 0x34);
    *(undefined4 **)
     (*(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_4 + 0x14) * 4) + 0x34) +
              0x18) + 0x1c) = puVar2;
    *(undefined4 **)
     (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_4 + 0x14) * 4) + 0x34) + 0x18) =
         puVar2;
  }
  if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_4 + 0x14) * 4) + 0x28) & 1) != 0)
  {
    puVar2[1] = 1;
    if ((*(int *)(iVar3 + 0x58) != 0xa000000) && (*(int *)(iVar3 + 0x58) != 0xb000000)) {
      *(undefined4 *)(iVar3 + 4) = 1;
    }
  }
  if (((*(byte *)(in_ECX + 0x119) & 8) == 0) && (*(int *)(in_ECX + 0xb4) != 0)) {
    FUN_008d5b85();
  }
  return 0;
}


// ==== FUN_008d61a2 @ 0x008d61a2 ====

uint FUN_008d61a2(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  int in_ECX;
  int *piVar5;
  byte *pbVar6;
  uint uVar7;
  bool bVar8;
  uint local_8;
  
  if ((byte *)((uint)param_1 & 0xffff) != param_1) {
    if ((int)param_1 < 1) {
      uVar7 = ~(uint)param_1;
      if ((((*(int *)(uVar7 + 0x10) == 3) && (*(uint *)(uVar7 + 0x14) < *(uint *)(in_ECX + 0xa8)))
          && (*(int *)(uVar7 + 0x18) == 0)) &&
         ((*(int *)(uVar7 + 0x1c) == 0 && (*(int *)(uVar7 + 8) == -1)))) {
        uVar7 = *(uint *)(*(int *)(in_ECX + 0xb0) + *(uint *)(uVar7 + 0x14) * 4);
        return ~-(uint)((*(byte *)(uVar7 + 0x28) & 4) != 0) & uVar7;
      }
    }
    else {
      local_8 = 0;
      if (*(int *)(in_ECX + 0x98) != 0) {
        piVar5 = (int *)(*(int *)(in_ECX + 0x9c) + 0x2c);
        do {
          if (piVar5[5] == 0) {
            iVar2 = *(int *)(in_ECX + 0x20);
          }
          else {
            iVar2 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
          }
          piVar3 = (int *)(iVar2 + *(int *)(iVar2 + 8 + *piVar5));
          pbVar6 = param_1;
          if ((*piVar3 == 0) || (pbVar4 = (byte *)(piVar3 + 1), pbVar4 == (byte *)0x0)) {
joined_r0x008d623b:
            if (pbVar6 == (byte *)0x0) break;
          }
          else if (param_1 != (byte *)0x0) {
            do {
              bVar1 = *pbVar4;
              bVar8 = bVar1 < *pbVar6;
              if (bVar1 != *pbVar6) {
LAB_008d6229:
                pbVar6 = (byte *)((1 - (uint)bVar8) - (uint)(bVar8 != 0));
                goto joined_r0x008d623b;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar4[1];
              bVar8 = bVar1 < pbVar6[1];
              if (bVar1 != pbVar6[1]) goto LAB_008d6229;
              pbVar4 = pbVar4 + 2;
              pbVar6 = pbVar6 + 2;
            } while (bVar1 != 0);
            pbVar6 = (byte *)0x0;
            goto joined_r0x008d623b;
          }
          local_8 = local_8 + 1;
          piVar5 = piVar5 + 0x14;
        } while (local_8 < *(uint *)(in_ECX + 0x98));
      }
      if (local_8 != *(uint *)(in_ECX + 0x98)) {
        return local_8 * 0x50 + *(int *)(in_ECX + 0x9c);
      }
    }
  }
  return 0;
}


// ==== FUN_008d62ad @ 0x008d62ad ====

int FUN_008d62ad(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar3 = param_3;
  piVar2 = param_2;
  iVar1 = *param_2;
  piVar4 = (int *)(param_1 + iVar1);
  iVar7 = piVar4[4];
  iVar5 = piVar4[1];
  if (iVar7 == 0) {
    iVar7 = 1;
  }
  if (-1 < iVar5) {
    if (iVar5 < 2) {
      iVar5 = *piVar4;
      if (((iVar5 == 1) || (iVar5 == 2)) || (iVar5 == 3)) {
        iVar5 = 4;
        iVar6 = 4;
      }
      else {
        iVar5 = 0;
        iVar6 = 0;
      }
      *param_2 = iVar1 + 0x1c;
      *param_3 = *param_3 + iVar6 * iVar7 * 4;
      return iVar5 * iVar7 * 4;
    }
    if (iVar5 < 4) {
      iVar5 = *piVar4;
      if (((iVar5 == 1) || (iVar5 == 2)) || (iVar5 == 3)) {
        iVar5 = 4;
        iVar6 = 4;
      }
      else {
        iVar5 = 0;
        iVar6 = 0;
      }
      *param_2 = iVar1 + 0x1c;
      *param_3 = *param_3 + iVar6 * iVar7 * 0x10;
      return iVar5 * iVar7 * 0x10;
    }
    if (iVar5 == 4) {
      if ((*piVar4 < 10) || (0xe < *piVar4)) {
        iVar5 = 4;
      }
      else {
        iVar5 = 0;
      }
      *param_2 = iVar1 + 0x14;
      *param_3 = *param_3 + iVar7 * 4;
      return iVar5 * iVar7;
    }
    if (iVar5 == 5) {
      iVar5 = piVar4[5];
      param_3 = (int *)0x0;
      *param_2 = iVar1 + 0x18;
      iVar1 = *piVar3;
      if (iVar5 != 0) {
        param_2 = (int *)iVar5;
        do {
          iVar5 = FUN_008d62ad(param_1,piVar2,piVar3);
          param_3 = (int *)((int)param_3 + iVar5);
          param_2 = (int *)((int)param_2 + -1);
        } while (param_2 != (int *)0x0);
      }
      *piVar3 = (*piVar3 - iVar1) * (iVar7 + -1) + *piVar3;
      return (int)param_3 * iVar7;
    }
  }
  return 0;
}


// ==== FUN_008d63c8 @ 0x008d63c8 ====

int FUN_008d63c8(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  piVar5 = param_3;
  piVar4 = param_2;
  iVar2 = *param_2;
  piVar1 = (int *)(iVar2 + param_1);
  iVar9 = piVar1[4];
  iVar6 = piVar1[1];
  if (iVar9 == 0) {
    iVar9 = 1;
  }
  if (iVar6 < 0) {
LAB_008d64af:
    iVar7 = 0;
  }
  else {
    if (iVar6 < 4) {
      iVar6 = piVar1[5];
      iVar3 = piVar1[6];
      iVar7 = *piVar1;
      if (((iVar7 == 1) || (iVar7 == 2)) || (iVar7 == 3)) {
        iVar7 = 4;
        iVar8 = 4;
      }
      else {
        iVar7 = 0;
        iVar8 = 0;
      }
      *param_2 = iVar2 + 0x1c;
      *param_3 = *param_3 + iVar8 * iVar3 * iVar6 * iVar9;
      iVar7 = iVar3 * iVar6 * iVar7;
    }
    else if (iVar6 == 4) {
      if ((*piVar1 < 10) || (0xe < *piVar1)) {
        iVar7 = 4;
      }
      else {
        iVar7 = 0;
      }
      *param_2 = iVar2 + 0x14;
      *param_3 = *param_3 + iVar9 * 4;
    }
    else {
      if (iVar6 != 5) goto LAB_008d64af;
      iVar6 = piVar1[5];
      param_3 = (int *)0x0;
      *param_2 = iVar2 + 0x18;
      iVar2 = *piVar5;
      if (iVar6 != 0) {
        param_2 = (int *)iVar6;
        do {
          iVar6 = FUN_008d63c8(param_1,piVar4,piVar5);
          param_3 = (int *)((int)param_3 + iVar6);
          param_2 = (int *)((int)param_2 + -1);
        } while (param_2 != (int *)0x0);
      }
      *piVar5 = (*piVar5 - iVar2) * (iVar9 + -1) + *piVar5;
      iVar7 = (int)param_3;
    }
    iVar7 = iVar7 * iVar9;
  }
  return iVar7;
}


// ==== FUN_008d64b8 @ 0x008d64b8 ====

uint FUN_008d64b8(uint param_1,uint param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  if (param_1 != 0) {
    if ((int)param_1 < 0) {
      uVar6 = ~param_1;
    }
    else {
      uVar6 = FUN_008e606c(param_1,param_3,0);
      if (uVar6 == 0) {
        return 0;
      }
    }
    param_3 = *(uint *)(*(int *)(uVar6 + 4) + 0x10);
    if (*(int *)(uVar6 + 8) != -1) {
      return 0;
    }
    if (param_3 == 0) {
      return 0;
    }
    if (param_3 <= param_2) {
      return 0;
    }
    local_8 = (int *)0x0;
    piVar1 = *(int **)(uVar6 + 0x24);
    if (*(int **)(uVar6 + 0x24) != (int *)0x0) {
      do {
        piVar5 = piVar1;
        piVar1 = piVar5;
        if (param_2 <= (uint)piVar5[2]) break;
        piVar1 = (int *)piVar5[9];
        local_8 = piVar5;
      } while (piVar1 != (int *)0x0);
      if ((piVar1 != (int *)0x0) && ((uint)piVar1[2] <= param_2)) goto LAB_008d667a;
    }
    piVar1 = operator_new(0x28);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1[2] = -1;
      piVar1[9] = 0;
      piVar1[8] = 0;
      *piVar1 = 0;
      piVar1[1] = 0;
    }
    if (piVar1 != (int *)0x0) {
      piVar5 = (int *)(*(int *)(in_ECX + 0xb0) + *(int *)(uVar6 + 0x14) * 4);
      local_14 = *(int *)(*piVar5 + 0x2c) + *(int *)(uVar6 + 0x18);
      param_1 = *(int *)(*piVar5 + 0x30) + *(int *)(uVar6 + 0x1c);
      if (*(int *)(*piVar5 + 0x40) == 0) {
        uVar3 = *(undefined4 *)(in_ECX + 0x20);
      }
      else {
        uVar3 = *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x10);
      }
      local_10 = local_14;
      local_c = param_1;
      uVar2 = FUN_008d63c8(uVar3,&local_10,&local_c);
      if (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(uVar6 + 0x14) * 4) + 0x40) == 0) {
        uVar3 = *(undefined4 *)(in_ECX + 0x20);
      }
      else {
        uVar3 = *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x10);
      }
      FUN_008d62ad(uVar3,&local_14,&param_1);
      piVar1[4] = 3;
      piVar1[5] = *(int *)(uVar6 + 0x14);
      piVar1[6] = *(int *)(uVar6 + 0x18);
      piVar1[7] = (((param_1 -
                    *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(uVar6 + 0x14) * 4) + 0x30))
                   - *(int *)(uVar6 + 0x1c)) / param_3) * param_2 + *(int *)(uVar6 + 0x1c);
      piVar1[3] = uVar2 / param_3;
      piVar1[2] = param_2;
      piVar1[1] = *(int *)(uVar6 + 4);
      if (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar1[5] * 4) + 0x40) == 0) {
        iVar4 = *(int *)(in_ECX + 0x20);
      }
      else {
        iVar4 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
      }
      *piVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar1[5] * 4) + 0x30) + iVar4 +
                piVar1[7];
      if (local_8 == (int *)0x0) {
        piVar1[9] = *(int *)(uVar6 + 0x24);
        *(int **)(uVar6 + 0x24) = piVar1;
      }
      else {
        piVar1[9] = local_8[9];
        local_8[9] = (int)piVar1;
      }
LAB_008d667a:
      return ~(uint)piVar1;
    }
  }
  return 0;
}


// ==== FUN_008d6689 @ 0x008d6689 ====

uint FUN_008d6689(int param_1)

{
  return ~((uint)*(ushort *)(param_1 + 0x42) * 0xb4 + *(int *)(param_1 + 0xa4));
}


// ==== FUN_008d66a7 @ 0x008d66a7 ====

undefined4 FUN_008d66a7(char *param_1,int *param_2,int *param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined1 *_Memory;
  undefined4 uVar9;
  char *pcVar10;
  int *piVar11;
  char *pcVar12;
  undefined4 *puVar13;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  uint local_c;
  undefined4 *local_8;
  
  piVar4 = *(int **)((int)param_2 + 4);
  param_2 = (int *)(*(int *)(*(int *)(in_ECX + 0x11c) +
                            (*(int *)((int)param_2 + 0x14) - *(int *)(in_ECX + 0xac)) * 4) +
                   piVar4[2]);
  _Memory = (undefined1 *)0x0;
  local_8 = (undefined4 *)0x0;
  if (*param_2 == 0) {
    param_2 = (int *)0x0;
  }
  else {
    param_2 = param_2 + 1;
  }
  local_10 = *piVar4;
  local_14 = piVar4[1];
  local_c = piVar4[4];
  if ((param_1 == (char *)0x0) || (param_2 == (int *)0x0)) goto LAB_008d694a;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  piVar4 = param_2;
  do {
    iVar7 = *piVar4;
    piVar4 = (int *)((int)piVar4 + 1);
  } while ((char)iVar7 != '\0');
  _Memory = operator_new((uint)(pcVar3 + (int)((int)piVar4 +
                                              ((2 - (int)((int)param_2 + 1)) - (int)(param_1 + 1))))
                        );
  uVar2 = local_c;
  if (_Memory == (undefined1 *)0x0) {
    uVar9 = 0x8007000e;
    goto LAB_008d695f;
  }
  *_Memory = 0;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar12 = _Memory + -1;
  do {
    pcVar10 = pcVar12 + 1;
    pcVar12 = pcVar12 + 1;
  } while (*pcVar10 != '\0');
  pcVar10 = param_1;
  for (uVar5 = (uint)((int)pcVar3 - (int)param_1) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar12 = pcVar12 + 4;
  }
  puVar8 = (undefined2 *)(_Memory + -1);
  for (uVar5 = (int)pcVar3 - (int)param_1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar12 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar12 = pcVar12 + 1;
  }
  do {
    pcVar3 = (char *)((int)puVar8 + 1);
    puVar8 = (undefined2 *)((int)puVar8 + 1);
  } while (*pcVar3 != '\0');
  *puVar8 = DAT_00a22eac;
  piVar4 = param_2;
  do {
    iVar7 = *piVar4;
    piVar4 = (int *)((int)piVar4 + 1);
  } while ((char)iVar7 != '\0');
  piVar6 = (int *)(_Memory + -1);
  do {
    pcVar3 = (char *)((int)piVar6 + 1);
    piVar6 = (int *)((int)piVar6 + 1);
  } while (*pcVar3 != '\0');
  piVar11 = param_2;
  for (uVar5 = (uint)((int)piVar4 - (int)param_2) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *piVar6 = *piVar11;
    piVar11 = piVar11 + 1;
    piVar6 = piVar6 + 1;
  }
  for (uVar5 = (int)piVar4 - (int)param_2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)piVar6 = (char)*piVar11;
    piVar11 = (int *)((int)piVar11 + 1);
    piVar6 = (int *)((int)piVar6 + 1);
  }
  if (local_c == 0) {
LAB_008d67ec:
    if (local_10 == 1) {
      if (local_c == 0) {
        uVar9 = (**(code **)(*param_3 + 0x58))(param_3,_Memory,0);
      }
      else {
        uVar9 = (**(code **)(*param_3 + 0x60))(param_3,_Memory,local_8,local_c);
      }
    }
    else if (local_10 == 2) {
      if (local_c == 0) {
        uVar9 = (**(code **)(*param_3 + 0x68))(param_3,_Memory,0);
      }
      else {
        uVar9 = (**(code **)(*param_3 + 0x70))(param_3,_Memory,local_8,local_c);
      }
    }
    else if (local_10 == 3) {
      if (local_14 == 0) {
        if (local_c == 0) {
          uVar9 = (**(code **)(*param_3 + 0x78))(param_3,_Memory,0);
        }
        else {
          uVar9 = (**(code **)(*param_3 + 0x80))(param_3,_Memory,local_8,local_c);
        }
      }
      else if (local_14 == 1) {
        if (local_c == 0) {
          local_24 = 0;
          local_20 = 0;
          local_1c = 0;
          local_18 = 0;
          uVar9 = (**(code **)(*param_3 + 0x88))(param_3,_Memory,&local_24);
        }
        else {
          uVar9 = (**(code **)(*param_3 + 0x90))(param_3,_Memory,local_8,local_c);
        }
      }
      else {
        if (local_14 != 2) goto LAB_008d694a;
        if (local_c == 0) {
          local_64 = 0;
          local_60 = 0;
          local_5c = 0;
          local_58 = 0;
          local_54 = 0;
          local_50 = 0;
          local_4c = 0;
          local_48 = 0;
          local_44 = 0;
          local_40 = 0;
          local_3c = 0;
          local_38 = 0;
          local_34 = 0;
          local_30 = 0;
          local_2c = 0;
          local_28 = 0;
          uVar9 = (**(code **)(*param_3 + 0x98))(param_3,_Memory,&local_64);
        }
        else {
          uVar9 = (**(code **)(*param_3 + 0xa0))(param_3,_Memory,local_8,local_c);
        }
      }
    }
    else if ((local_10 == 4) && (local_c == 0)) {
      uVar9 = (**(code **)(*param_3 + 200))(param_3,_Memory,0);
    }
    else {
LAB_008d694a:
      uVar9 = 0x80004005;
    }
  }
  else {
    local_8 = operator_new(local_c << 6);
    if (local_8 != (undefined4 *)0x0) {
      puVar13 = local_8;
      for (iVar7 = (uVar2 & 0x3ffffff) << 4; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)puVar13 = 0;
        puVar13 = (undefined4 *)((int)puVar13 + 1);
      }
      goto LAB_008d67ec;
    }
    uVar9 = 0x8007000e;
  }
  if (local_8 != (undefined4 *)0x0) {
    _free(local_8);
    return extraout_EAX;
  }
LAB_008d695f:
  if (_Memory == (undefined1 *)0x0) {
    return uVar9;
  }
  _free(_Memory);
  return extraout_EAX_00;
}


// ==== FUN_008d6973 @ 0x008d6973 ====

int FUN_008d6973(uint param_1)

{
  int in_ECX;
  int iVar1;
  
  param_1 = ~param_1;
  if ((*(int *)(param_1 + 0x10) == 1) &&
     ((uint)*(ushort *)(param_1 + 0x14) < *(uint *)(in_ECX + 0xa0))) {
    iVar1 = *(int *)(in_ECX + 0xa4) + (uint)*(ushort *)(param_1 + 0x14) * 0xb4;
    if ((uint)*(ushort *)(param_1 + 0x18) < *(uint *)(iVar1 + 0x34)) {
      return (uint)*(ushort *)(param_1 + 0x18) * 0x38 + *(int *)(iVar1 + 0x38);
    }
  }
  return 0;
}


// ==== FUN_008d69b4 @ 0x008d69b4 ====

int FUN_008d69b4(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  byte *pbVar4;
  byte *pbVar5;
  int *piVar6;
  bool bVar7;
  uint local_8;
  
  if ((byte *)((uint)param_1 & 0xffff) == param_1) {
LAB_008d6a7d:
    iVar2 = 0;
  }
  else {
    if ((int)param_1 < 1) {
      if ((*(int *)(~(uint)param_1 + 0x10) != 0) ||
         (local_8 = (uint)*(ushort *)(~(uint)param_1 + 0x14), *(uint *)(in_ECX + 0xa0) <= local_8))
      goto LAB_008d6a7d;
    }
    else {
      local_8 = 0;
      if (*(int *)(in_ECX + 0xa0) != 0) {
        piVar6 = (int *)(*(int *)(in_ECX + 0xa4) + 0x28);
        do {
          piVar3 = (int *)(*(int *)(in_ECX + 0x20) + *piVar6);
          pbVar5 = param_1;
          if ((*piVar3 == 0) || (pbVar4 = (byte *)(piVar3 + 1), pbVar4 == (byte *)0x0)) {
joined_r0x008d6a37:
            if (pbVar5 == (byte *)0x0) break;
          }
          else if (param_1 != (byte *)0x0) {
            do {
              bVar1 = *pbVar4;
              bVar7 = bVar1 < *pbVar5;
              if (bVar1 != *pbVar5) {
LAB_008d6a27:
                pbVar5 = (byte *)((1 - (uint)bVar7) - (uint)(bVar7 != 0));
                goto joined_r0x008d6a37;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar4[1];
              bVar7 = bVar1 < pbVar5[1];
              if (bVar1 != pbVar5[1]) goto LAB_008d6a27;
              pbVar4 = pbVar4 + 2;
              pbVar5 = pbVar5 + 2;
            } while (bVar1 != 0);
            pbVar5 = (byte *)0x0;
            goto joined_r0x008d6a37;
          }
          local_8 = local_8 + 1;
          piVar6 = piVar6 + 0x2d;
        } while (local_8 < *(uint *)(in_ECX + 0xa0));
      }
      if (*(uint *)(in_ECX + 0xa0) == local_8) goto LAB_008d6a7d;
    }
    iVar2 = local_8 * 0xb4 + *(int *)(in_ECX + 0xa4);
  }
  return iVar2;
}


// ==== FUN_008d6a83 @ 0x008d6a83 ====

uint FUN_008d6a83(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < *(uint *)(param_1 + 0xa0)) {
    uVar1 = ~(param_2 * 0xb4 + *(int *)(param_1 + 0xa4));
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_008d6aac @ 0x008d6aac ====

uint FUN_008d6aac(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  byte *pbVar4;
  byte *pbVar5;
  int *piVar6;
  bool bVar7;
  uint local_8;
  
  local_8 = 0;
  if (*(int *)(param_1 + 0xa0) != 0) {
    piVar6 = (int *)(*(int *)(param_1 + 0xa4) + 0x28);
    do {
      piVar3 = (int *)(*piVar6 + *(int *)(param_1 + 0x20));
      if ((*piVar3 == 0) || (pbVar4 = (byte *)(piVar3 + 1), pbVar4 == (byte *)0x0)) {
        pbVar4 = param_2;
LAB_008d6b15:
        if (pbVar4 == (byte *)0x0) break;
      }
      else {
        pbVar5 = param_2;
        if (param_2 != (byte *)0x0) {
          do {
            bVar1 = *pbVar4;
            bVar7 = bVar1 < *pbVar5;
            if (bVar1 != *pbVar5) {
LAB_008d6b08:
              pbVar4 = (byte *)((1 - (uint)bVar7) - (uint)(bVar7 != 0));
              goto LAB_008d6b15;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar4[1];
            bVar7 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_008d6b08;
            pbVar4 = pbVar4 + 2;
            pbVar5 = pbVar5 + 2;
          } while (bVar1 != 0);
          pbVar4 = (byte *)0x0;
          goto LAB_008d6b15;
        }
      }
      local_8 = local_8 + 1;
      piVar6 = piVar6 + 0x2d;
    } while (local_8 < *(uint *)(param_1 + 0xa0));
  }
  if (*(uint *)(param_1 + 0xa0) == local_8) {
    uVar2 = 0;
  }
  else {
    uVar2 = ~(local_8 * 0xb4 + *(int *)(param_1 + 0xa4));
  }
  return uVar2;
}


// ==== FUN_008d6b4f @ 0x008d6b4f ====

uint FUN_008d6b4f(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_008d69b4(param_2,1);
  if ((iVar1 == 0) || (*(uint *)(iVar1 + 0x34) <= param_3)) {
    uVar2 = 0;
  }
  else {
    uVar2 = ~(*(int *)(iVar1 + 0x38) + param_3 * 0x38);
  }
  return uVar2;
}


// ==== FUN_008d6b7f @ 0x008d6b7f ====

uint FUN_008d6b7f(undefined4 param_1,uint param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  int extraout_ECX;
  int *piVar3;
  byte *pbVar4;
  byte *pbVar5;
  int *piVar6;
  bool bVar7;
  
  iVar2 = FUN_008d69b4(param_2,1);
  if (iVar2 != 0) {
    param_2 = 0;
    if (*(int *)(iVar2 + 0x34) != 0) {
      piVar6 = (int *)(*(int *)(iVar2 + 0x38) + 0x28);
      do {
        piVar3 = (int *)(*(int *)(extraout_ECX + 0x20) + *piVar6);
        if ((*piVar3 == 0) || (pbVar4 = (byte *)(piVar3 + 1), pbVar4 == (byte *)0x0)) {
          pbVar4 = param_3;
LAB_008d6bf7:
          if (pbVar4 == (byte *)0x0) break;
        }
        else {
          pbVar5 = param_3;
          if (param_3 != (byte *)0x0) {
            do {
              bVar1 = *pbVar4;
              bVar7 = bVar1 < *pbVar5;
              if (bVar1 != *pbVar5) {
LAB_008d6bea:
                pbVar4 = (byte *)((1 - (uint)bVar7) - (uint)(bVar7 != 0));
                goto LAB_008d6bf7;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar4[1];
              bVar7 = bVar1 < pbVar5[1];
              if (bVar1 != pbVar5[1]) goto LAB_008d6bea;
              pbVar4 = pbVar4 + 2;
              pbVar5 = pbVar5 + 2;
            } while (bVar1 != 0);
            pbVar4 = (byte *)0x0;
            goto LAB_008d6bf7;
          }
        }
        param_2 = param_2 + 1;
        piVar6 = piVar6 + 0xe;
      } while (param_2 < *(uint *)(iVar2 + 0x34));
    }
    if (*(uint *)(iVar2 + 0x34) != param_2) {
      return ~(param_2 * 0x38 + *(int *)(iVar2 + 0x38));
    }
  }
  return 0;
}


// ==== FUN_008d6c22 @ 0x008d6c22 ====

undefined4 FUN_008d6c22(void)

{
  return 0;
}


// ==== FUN_008d6c27 @ 0x008d6c27 ====

undefined4 FUN_008d6c27(uint param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 local_2c [12];
  int local_20;
  int local_c;
  uint local_8;
  
  iVar4 = param_1;
  piVar2 = *(int **)(param_1 + 0x104);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(int *)(param_1 + 0x104) = 0;
  }
  piVar2 = (int *)(param_1 + 0xa0);
  param_1 = 0;
  if (*piVar2 != 0) {
    local_8 = 0;
    while( true ) {
      uVar1 = local_8;
      piVar2 = (int *)(*(int *)(iVar4 + 0xa4) + 0x88 + local_8);
      if (*piVar2 != 0) {
        piVar2 = (int *)*piVar2;
        (**(code **)(*piVar2 + 8))(piVar2);
        *(undefined4 *)(*(int *)(iVar4 + 0xa4) + 0x88 + uVar1) = 0;
      }
      iVar5 = uVar1 + 0x8c;
      local_c = 2;
      do {
        piVar2 = (int *)(iVar5 + 8 + *(int *)(iVar4 + 0xa4));
        if (*piVar2 != 0) {
          piVar2 = (int *)*piVar2;
          (**(code **)(*piVar2 + 8))(piVar2);
          *(undefined4 *)(iVar5 + 8 + *(int *)(iVar4 + 0xa4)) = 0;
        }
        piVar2 = (int *)(*(int *)(iVar4 + 0xa4) + iVar5);
        if (*piVar2 != 0) {
          piVar2 = (int *)*piVar2;
          (**(code **)(*piVar2 + 8))(piVar2);
          *(undefined4 *)(iVar5 + *(int *)(iVar4 + 0xa4)) = 0;
        }
        iVar5 = iVar5 + 4;
        local_c = local_c + -1;
      } while (local_c != 0);
      param_1 = param_1 + 1;
      local_8 = local_8 + 0xb4;
      local_c = 0;
      if (*(uint *)(iVar4 + 0xa0) <= param_1) break;
      local_c = 0;
    }
  }
  param_1 = 0;
  if (*(int *)(iVar4 + 0x14) != 0) {
    iVar5 = 0;
    do {
      piVar2 = (int *)(*(int *)(iVar4 + 0x18) + iVar5);
      iVar6 = *piVar2;
      if ((((((iVar6 == 5) || (iVar6 == 6)) || (iVar6 == 7)) || ((iVar6 == 8 || (iVar6 == 9)))) &&
          (piVar2[1] != 0)) &&
         (((**(code **)(*(int *)piVar2[1] + 0x44))((int *)piVar2[1],0,local_2c), local_20 == 0 &&
          (piVar2 = (int *)(*(int *)(iVar4 + 0x18) + 4 + iVar5), *piVar2 != 0)))) {
        piVar2 = (int *)*piVar2;
        (**(code **)(*piVar2 + 8))(piVar2);
        *(undefined4 *)(*(int *)(iVar4 + 0x18) + 4 + iVar5) = 0;
      }
      param_1 = param_1 + 1;
      iVar5 = iVar5 + 0x18;
    } while (param_1 < *(uint *)(iVar4 + 0x14));
  }
  param_1 = 0;
  if (*(int *)(iVar4 + 0xd0) != 0) {
    do {
      for (iVar5 = *(int *)(*(int *)(iVar4 + 0xd8) + param_1 * 4); iVar5 != 0;
          iVar5 = *(int *)(iVar5 + 0x18)) {
        local_8 = 0;
        if (*(int *)(iVar5 + 0x10) != 0) {
          do {
            iVar3 = local_8 * 8;
            piVar2 = (int *)(*(int *)(iVar5 + 0x14) + iVar3);
            iVar6 = *piVar2;
            if (((((iVar6 == 5) || (iVar6 == 6)) || (iVar6 == 7)) || ((iVar6 == 8 || (iVar6 == 9))))
               && ((piVar2[1] != 0 &&
                   ((piVar2 = *(int **)(iVar3 + 4 + *(int *)(iVar5 + 0x14)),
                    (**(code **)(*piVar2 + 0x44))(piVar2,0,local_2c), local_20 == 0 &&
                    (*(int *)(iVar3 + 4 + *(int *)(iVar5 + 0x14)) != 0)))))) {
              piVar2 = *(int **)(iVar3 + 4 + *(int *)(iVar5 + 0x14));
              (**(code **)(*piVar2 + 8))(piVar2);
              *(undefined4 *)(iVar3 + 4 + *(int *)(iVar5 + 0x14)) = 0;
            }
            local_8 = local_8 + 1;
          } while (local_8 < *(uint *)(iVar5 + 0x10));
        }
      }
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(iVar4 + 0xd0));
  }
  for (iVar4 = *(int *)(iVar4 + 0xf8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x18)) {
    param_1 = 0;
    if (*(int *)(iVar4 + 0x10) != 0) {
      do {
        iVar6 = param_1 * 8;
        piVar2 = (int *)(*(int *)(iVar4 + 0x14) + iVar6);
        iVar5 = *piVar2;
        if (((((iVar5 == 5) || (iVar5 == 6)) || (iVar5 == 7)) || ((iVar5 == 8 || (iVar5 == 9)))) &&
           ((piVar2[1] != 0 &&
            ((piVar2 = *(int **)(iVar6 + 4 + *(int *)(iVar4 + 0x14)),
             (**(code **)(*piVar2 + 0x44))(piVar2,0,local_2c), local_20 == 0 &&
             (*(int *)(iVar6 + 4 + *(int *)(iVar4 + 0x14)) != 0)))))) {
          piVar2 = *(int **)(iVar6 + 4 + *(int *)(iVar4 + 0x14));
          (**(code **)(*piVar2 + 8))(piVar2);
          *(undefined4 *)(iVar6 + 4 + *(int *)(iVar4 + 0x14)) = 0;
        }
        param_1 = param_1 + 1;
      } while (param_1 < *(uint *)(iVar4 + 0x10));
    }
  }
  return 0;
}


// ==== FUN_008d6e92 @ 0x008d6e92 ====

undefined4 FUN_008d6e92(void)

{
  return 0;
}


// ==== FUN_008d6e97 @ 0x008d6e97 ====

undefined4 FUN_008d6e97(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 == (int *)0x0) {
    uVar2 = 0x8876086c;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x38);
    *param_2 = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return uVar2;
}


// ==== FUN_008d6ec6 @ 0x008d6ec6 ====

undefined4 FUN_008d6ec6(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 == (int *)0x0) {
    uVar2 = 0x8876086c;
  }
  else {
    piVar1 = *(int **)(param_1 + 0xc);
    *param_2 = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return uVar2;
}


// ==== FUN_008d6ef5 @ 0x008d6ef5 ====

undefined4 FUN_008d6ef5(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x8876086c;
  }
  else {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    *param_2 = PTR_s_D3DX_Effect_Compiler_00b59084;
    param_2[1] = *(undefined4 *)(param_1 + 0x98);
    param_2[2] = *(undefined4 *)(param_1 + 0xa0);
    param_2[3] = 0;
  }
  return uVar1;
}


// ==== FUN_008d6f3b @ 0x008d6f3b ====

undefined4 FUN_008d6f3b(int param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  int extraout_ECX;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_3 == (undefined4 *)0x0) {
LAB_008d6f4b:
    uVar3 = 0x8876086c;
  }
  else {
    if (param_2 == 0) {
      iVar2 = (uint)*(ushort *)(param_1 + 0x42) * 0xb4 + *(int *)(param_1 + 0xa4);
    }
    else {
      iVar2 = FUN_008d69b4(param_2,1);
      param_1 = extraout_ECX;
      if (iVar2 == 0) goto LAB_008d6f4b;
    }
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    piVar1 = (int *)(*(int *)(iVar2 + 0x28) + *(int *)(param_1 + 0x20));
    if (*piVar1 == 0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = piVar1 + 1;
    }
    *param_3 = piVar1;
    param_3[1] = *(undefined4 *)(iVar2 + 0x34);
    param_3[2] = *(undefined4 *)(iVar2 + 0x2c);
  }
  return uVar3;
}


// ==== FUN_008d6faf @ 0x008d6faf ====

undefined4 FUN_008d6faf(void)

{
  return 0x80004005;
}


// ==== FUN_008d6fb7 @ 0x008d6fb7 ====

undefined4 FUN_008d6fb7(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  
  if (param_3 == (int *)0x0) {
    iVar5 = param_2;
  }
  else {
    iVar5 = *(int *)(param_3[2] + param_2 * 4);
  }
  iVar5 = *(int *)(in_ECX + 0x18) + iVar5 * 0x18;
  if (param_1 != *(int **)(iVar5 + 4)) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    piVar2 = *(int **)(iVar5 + 4);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(iVar5 + 4) = 0;
    }
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 1;
    *(int **)(iVar5 + 4) = param_1;
    *(uint *)(in_ECX + 0x118) = *(uint *)(in_ECX + 0x118) | 0x40;
    if (param_3 != (int *)0x0) {
      for (piVar2 = (int *)param_3[4]; piVar2 != param_3; piVar2 = (int *)piVar2[4]) {
        if (*piVar2 != 0) {
          iVar1 = *(int *)(*piVar2 + 0x18) + *(int *)(piVar2[2] + param_2 * 4) * 0x18;
          piVar3 = *(int **)(iVar5 + 4);
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 4))(piVar3);
          }
          piVar3 = *(int **)(iVar1 + 4);
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 8))(piVar3);
            *(undefined4 *)(iVar1 + 4) = 0;
          }
          uVar4 = *(undefined4 *)(iVar5 + 4);
          *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 1;
          *(undefined4 *)(iVar1 + 4) = uVar4;
        }
      }
    }
  }
  return 0;
}


// ==== FUN_008d706f @ 0x008d706f ====

undefined4 FUN_008d706f(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  
  if (param_3 == (int *)0x0) {
    iVar3 = param_2;
  }
  else {
    iVar3 = *(int *)(param_3[2] + param_2 * 4);
  }
  iVar3 = *(int *)(in_ECX + 0x18) + iVar3 * 0x18;
  if (param_1 != *(int **)(iVar3 + 4)) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    piVar4 = *(int **)(iVar3 + 4);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))(piVar4);
      *(undefined4 *)(iVar3 + 4) = 0;
    }
    *(int **)(iVar3 + 4) = param_1;
    if (param_3 != (int *)0x0) {
      for (piVar4 = (int *)param_3[4]; piVar4 != param_3; piVar4 = (int *)piVar4[4]) {
        if (*piVar4 != 0) {
          iVar1 = *(int *)(*piVar4 + 0x18) + *(int *)(piVar4[2] + param_2 * 4) * 0x18;
          piVar2 = *(int **)(iVar3 + 4);
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 4))(piVar2);
          }
          piVar2 = *(int **)(iVar1 + 4);
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))(piVar2);
            *(undefined4 *)(iVar1 + 4) = 0;
          }
          *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar3 + 4);
        }
      }
    }
  }
  return 0;
}


// ==== FUN_008d7113 @ 0x008d7113 ====

int FUN_008d7113(char *param_1,int param_2,int *param_3)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int in_ECX;
  uint uVar8;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = (int *)0x0;
  if (param_3 == (int *)0x0) {
    iVar5 = param_2;
  }
  else {
    iVar5 = *(int *)(param_3[2] + param_2 * 4);
  }
  iVar5 = *(int *)(in_ECX + 0x18) + iVar5 * 0x18;
  if (param_1 != (char *)0x0) {
    pcVar6 = param_1;
    do {
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    pcVar6 = pcVar6 + (1 - (int)(param_1 + 1));
    piVar3 = *(int **)(iVar5 + 4);
    if ((piVar3 == (int *)0x0) ||
       (pcVar7 = (char *)(**(code **)(*piVar3 + 0x10))(piVar3), pcVar7 < pcVar6)) {
      local_c = FUN_008eb3df(pcVar6,&local_8);
      if (local_c < 0) goto LAB_008d722b;
    }
    else {
      local_8 = *(int **)(iVar5 + 4);
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 4))(local_8);
      }
    }
    pcVar7 = (char *)(**(code **)(*local_8 + 0xc))(local_8);
    for (uVar8 = (uint)pcVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)param_1;
      param_1 = param_1 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar8 = (uint)pcVar6 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *pcVar7 = *param_1;
      param_1 = param_1 + 1;
      pcVar7 = pcVar7 + 1;
    }
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 4))(local_8);
    }
  }
  piVar3 = *(int **)(iVar5 + 4);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(iVar5 + 4) = 0;
  }
  *(int **)(iVar5 + 4) = local_8;
  if (param_3 != (int *)0x0) {
    for (piVar3 = (int *)param_3[4]; piVar3 != param_3; piVar3 = (int *)piVar3[4]) {
      if (*piVar3 != 0) {
        iVar1 = *(int *)(*piVar3 + 0x18) + *(int *)(piVar3[2] + param_2 * 4) * 0x18;
        piVar4 = *(int **)(iVar5 + 4);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 4))(piVar4);
        }
        piVar4 = *(int **)(iVar1 + 4);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 8))(piVar4);
          *(undefined4 *)(iVar1 + 4) = 0;
        }
        *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar5 + 4);
      }
    }
  }
LAB_008d722b:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return local_c;
}


// ==== FUN_008d7242 @ 0x008d7242 ====

undefined4 FUN_008d7242(int *param_1,float *param_2,float *param_3,uint param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  if (iVar2 == 1) {
    iVar2 = param_4 << 4;
    if (iVar2 != 0) {
      iVar3 = (int)param_2 - (int)param_3;
      do {
        *(uint *)(iVar3 + (int)param_3) = (uint)(DAT_0099cdc8 != *param_3);
        param_3 = param_3 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  else if (iVar2 == 2) {
    iVar2 = param_4 << 4;
    if (iVar2 != 0) {
      do {
        fVar1 = (float)__ftol();
        *param_2 = fVar1;
        param_2 = param_2 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  else {
    if (iVar2 != 3) {
      return 0x8876086c;
    }
    for (iVar2 = (param_4 & 0x3ffffff) << 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *param_3;
      param_3 = param_3 + 1;
      param_2 = param_2 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)param_2 = *(undefined1 *)param_3;
      param_3 = (float *)((int)param_3 + 1);
      param_2 = (float *)((int)param_2 + 1);
    }
  }
  return 0;
}


// ==== FUN_008d72db @ 0x008d72db ====

undefined4 FUN_008d72db(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  
  pfVar4 = param_2;
  iVar3 = *param_1;
  if (iVar3 == 1) {
    param_2 = (float *)0x4;
    do {
      pfVar2 = pfVar4;
      iVar3 = 4;
      do {
        *pfVar2 = (float)(uint)(DAT_0099cdc8 != *param_3);
        param_3 = param_3 + 1;
        pfVar2 = pfVar2 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      pfVar4 = pfVar4 + 1;
      param_2 = (float *)((int)param_2 + -1);
    } while (param_2 != (float *)0x0);
  }
  else if (iVar3 == 2) {
    param_1 = (int *)0x4;
    do {
      param_2 = (float *)0x4;
      pfVar2 = pfVar4;
      do {
        fVar1 = (float)__ftol();
        *pfVar2 = fVar1;
        pfVar2 = pfVar2 + 4;
        param_2 = (float *)((int)param_2 + -1);
      } while (param_2 != (float *)0x0);
      pfVar4 = pfVar4 + 1;
      param_1 = (int *)((int)param_1 + -1);
    } while (param_1 != (int *)0x0);
  }
  else {
    if (iVar3 != 3) {
      return 0x80004005;
    }
    iVar3 = 4;
    param_3 = param_3 + 8;
    do {
      *param_2 = param_3[-8];
      param_2[1] = param_3[-4];
      param_2[2] = *param_3;
      param_2[3] = param_3[4];
      param_2 = param_2 + 4;
      param_3 = param_3 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 0;
}


// ==== FUN_008d739d @ 0x008d739d ====

undefined4 FUN_008d739d(int *param_1,float *param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  int local_c;
  int local_8;
  
  iVar5 = *param_1;
  if (iVar5 == 1) {
    if (param_4 != (float *)0x0) {
      param_1 = (int *)param_4;
      do {
        param_4 = (float *)0x4;
        pfVar4 = param_2;
        pfVar1 = param_3;
        do {
          pfVar3 = pfVar4;
          iVar5 = 4;
          do {
            *pfVar3 = (float)(uint)(DAT_0099cdc8 != *pfVar1);
            pfVar1 = pfVar1 + 1;
            pfVar3 = pfVar3 + 4;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          pfVar4 = pfVar4 + 1;
          param_4 = (float *)((int)param_4 + -1);
        } while (param_4 != (float *)0x0);
        param_3 = param_3 + 0x10;
        param_2 = param_2 + 0x10;
        param_1 = (int *)((int)param_1 + -1);
      } while (param_1 != (int *)0x0);
    }
  }
  else if (iVar5 == 2) {
    if (param_4 != (float *)0x0) {
      local_c = (int)param_4;
      do {
        param_4 = param_2;
        local_8 = 4;
        do {
          param_1 = (int *)0x4;
          pfVar4 = param_4;
          do {
            fVar2 = (float)__ftol();
            *pfVar4 = fVar2;
            pfVar4 = pfVar4 + 4;
            param_1 = (int *)((int)param_1 + -1);
          } while (param_1 != (int *)0x0);
          param_4 = param_4 + 1;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
        param_2 = param_2 + 0x10;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  else if ((iVar5 == 3) && (param_4 != (float *)0x0)) {
    pfVar4 = param_3 + 8;
    param_3 = param_4;
    do {
      pfVar1 = param_2;
      pfVar3 = pfVar4;
      iVar5 = 4;
      do {
        *pfVar1 = pfVar3[-8];
        pfVar1[1] = pfVar3[-4];
        pfVar1[2] = *pfVar3;
        pfVar1[3] = pfVar3[4];
        pfVar1 = pfVar1 + 4;
        pfVar3 = pfVar3 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      param_2 = param_2 + 0x10;
      pfVar4 = pfVar4 + 0x10;
      param_3 = (float *)((int)param_3 + -1);
    } while (param_3 != (float *)0x0);
  }
  return 0;
}


// ==== FUN_008d74b2 @ 0x008d74b2 ====

undefined4 FUN_008d74b2(int *param_1,int param_2,float *param_3,uint param_4)

{
  uint *puVar1;
  uint *puVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  uint uVar6;
  float *pfVar7;
  uint uVar8;
  undefined4 local_c;
  uint local_8;
  
  pfVar7 = param_3;
  iVar5 = *param_1;
  puVar1 = (uint *)(param_1 + 5);
  puVar2 = (uint *)(param_1 + 6);
  local_c = 0;
  param_1 = (int *)0x4;
  if (*puVar2 < 5) {
    param_1 = (int *)*puVar2;
  }
  local_8 = 4;
  if (*puVar1 < 5) {
    local_8 = *puVar1;
  }
  if (iVar5 == 1) {
    for (iVar5 = (param_4 & 0x3ffffff) << 4; iVar5 != 0; iVar5 = iVar5 + -1) {
      *param_3 = 0.0;
      param_3 = param_3 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)param_3 = 0;
      param_3 = (float *)((int)param_3 + 1);
    }
    if (param_4 != 0) {
      param_3 = (float *)param_4;
      do {
        if (param_1 != (int *)0x0) {
          param_4 = (uint)param_1;
          pfVar3 = pfVar7;
          do {
            if (local_8 != 0) {
              pfVar4 = pfVar3;
              uVar8 = local_8;
              do {
                *pfVar4 = (float)(*(int *)((int)pfVar4 + (param_2 - (int)pfVar7)) != 0);
                pfVar4 = pfVar4 + 1;
                uVar8 = uVar8 - 1;
              } while (uVar8 != 0);
            }
            pfVar3 = pfVar3 + 4;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
        }
        param_2 = param_2 + 0x40;
        pfVar7 = pfVar7 + 0x10;
        param_3 = (float *)((int)param_3 - 1);
      } while (param_3 != (float *)0x0);
    }
  }
  else if (iVar5 == 2) {
    for (iVar5 = (param_4 & 0x3ffffff) << 4; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pfVar7 = 0.0;
      pfVar7 = pfVar7 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)pfVar7 = 0;
      pfVar7 = (float *)((int)pfVar7 + 1);
    }
    if (param_4 != 0) {
      do {
        if (param_1 != (int *)0x0) {
          pfVar7 = param_3;
          uVar8 = (uint)param_1;
          do {
            if (local_8 != 0) {
              pfVar3 = pfVar7;
              uVar6 = local_8;
              do {
                *pfVar3 = (float)*(int *)((int)pfVar3 + (param_2 - (int)param_3));
                pfVar3 = pfVar3 + 1;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            pfVar7 = pfVar7 + 4;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
        }
        param_2 = param_2 + 0x40;
        param_3 = param_3 + 0x10;
        param_4 = param_4 - 1;
      } while (param_4 != 0);
    }
  }
  else if (iVar5 == 3) {
    for (iVar5 = (param_4 & 0x3ffffff) << 4; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pfVar7 = 0.0;
      pfVar7 = pfVar7 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)pfVar7 = 0;
      pfVar7 = (float *)((int)pfVar7 + 1);
    }
    if (param_4 != 0) {
      do {
        if (param_1 != (int *)0x0) {
          pfVar7 = param_3;
          uVar8 = (uint)param_1;
          do {
            if (local_8 != 0) {
              pfVar3 = pfVar7;
              uVar6 = local_8;
              do {
                *pfVar3 = *(float *)((param_2 - (int)param_3) + (int)pfVar3);
                pfVar3 = pfVar3 + 1;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            pfVar7 = pfVar7 + 4;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
        }
        param_2 = param_2 + 0x40;
        param_3 = param_3 + 0x10;
        param_4 = param_4 - 1;
      } while (param_4 != 0);
    }
  }
  else {
    local_c = 0x8876086c;
  }
  return local_c;
}


// ==== FUN_008d7631 @ 0x008d7631 ====

undefined4 FUN_008d7631(int *param_1,float *param_2,float *param_3,uint param_4)

{
  uint *puVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  uint uVar6;
  uint uVar7;
  float *pfVar8;
  float *pfVar9;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  iVar4 = *param_1;
  puVar1 = (uint *)(param_1 + 6);
  local_8 = 4;
  if ((uint)param_1[5] < 5) {
    local_8 = param_1[5];
  }
  param_1 = (int *)0x4;
  if (*puVar1 < 5) {
    param_1 = (int *)*puVar1;
  }
  if (iVar4 == 1) {
    pfVar8 = param_3;
    for (iVar4 = (param_4 & 0x3ffffff) << 4; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar8 = 0.0;
      pfVar8 = pfVar8 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)pfVar8 = 0;
      pfVar8 = (float *)((int)pfVar8 + 1);
    }
    if (param_4 != 0) {
      local_c = param_4;
      do {
        if (param_1 != (int *)0x0) {
          param_4 = (uint)param_1;
          pfVar8 = param_3;
          pfVar9 = param_2;
          do {
            if (local_8 != 0) {
              pfVar3 = pfVar8;
              pfVar5 = pfVar9;
              uVar6 = local_8;
              do {
                fVar2 = *pfVar5;
                pfVar5 = pfVar5 + 1;
                *pfVar3 = (float)(fVar2 != 0.0);
                pfVar3 = pfVar3 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            pfVar9 = pfVar9 + 4;
            pfVar8 = pfVar8 + 1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
        }
        param_2 = param_2 + 0x10;
        param_3 = param_3 + 0x10;
        local_c = local_c - 1;
      } while (local_c != 0);
    }
  }
  else if (iVar4 == 2) {
    pfVar8 = param_3;
    for (iVar4 = (param_4 & 0x3ffffff) << 4; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar8 = 0.0;
      pfVar8 = pfVar8 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)pfVar8 = 0;
      pfVar8 = (float *)((int)pfVar8 + 1);
    }
    if (param_4 != 0) {
      do {
        if (param_1 != (int *)0x0) {
          uVar6 = (uint)param_1;
          pfVar8 = param_2;
          pfVar9 = param_3;
          do {
            if (local_8 != 0) {
              pfVar3 = pfVar9;
              pfVar5 = pfVar8;
              uVar7 = local_8;
              do {
                fVar2 = *pfVar5;
                pfVar5 = pfVar5 + 1;
                *pfVar3 = (float)(int)fVar2;
                pfVar3 = pfVar3 + 4;
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
            }
            pfVar8 = pfVar8 + 4;
            pfVar9 = pfVar9 + 1;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
        param_2 = param_2 + 0x10;
        param_3 = param_3 + 0x10;
        param_4 = param_4 - 1;
      } while (param_4 != 0);
    }
  }
  else if (iVar4 == 3) {
    pfVar8 = param_3;
    for (iVar4 = (param_4 & 0x3ffffff) << 4; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar8 = 0.0;
      pfVar8 = pfVar8 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)pfVar8 = 0;
      pfVar8 = (float *)((int)pfVar8 + 1);
    }
    if (param_4 != 0) {
      local_c = param_4;
      do {
        if (param_1 != (int *)0x0) {
          param_4 = (uint)param_1;
          pfVar8 = param_2;
          pfVar9 = param_3;
          do {
            if (local_8 != 0) {
              pfVar3 = pfVar9;
              pfVar5 = pfVar8;
              uVar6 = local_8;
              do {
                *pfVar3 = *pfVar5;
                pfVar3 = pfVar3 + 4;
                pfVar5 = pfVar5 + 1;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            pfVar8 = pfVar8 + 4;
            pfVar9 = pfVar9 + 1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
        }
        param_2 = param_2 + 0x10;
        param_3 = param_3 + 0x10;
        local_c = local_c - 1;
      } while (local_c != 0);
    }
  }
  else {
    local_10 = 0x8876086c;
  }
  return local_10;
}


// ==== FUN_008d77c4 @ 0x008d77c4 ====

undefined4 FUN_008d77c4(int *param_1,int param_2,int *param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_8;
  
  iVar3 = *param_1;
  local_8 = 0;
  if (iVar3 == 1) {
    if (param_4 != 0) {
      do {
        uVar1 = 0;
        if (*param_3 != 0) {
          do {
            iVar3 = 4;
            do {
              *(uint *)(uVar1 + param_2) = (uint)(DAT_0099cdc8 != *(float *)(uVar1 + *param_3));
              uVar1 = uVar1 + 4;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          } while (uVar1 < 0x40);
        }
        param_2 = param_2 + 0x40;
        param_3 = param_3 + 1;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  else if (iVar3 == 2) {
    if (param_4 != 0) {
      param_1 = (int *)param_4;
      do {
        uVar1 = 0;
        if (*param_3 != 0) {
          do {
            param_4 = 4;
            do {
              uVar2 = __ftol();
              *(undefined4 *)(uVar1 + param_2) = uVar2;
              uVar1 = uVar1 + 4;
              param_4 = param_4 + -1;
            } while (param_4 != 0);
          } while (uVar1 < 0x40);
        }
        param_2 = param_2 + 0x40;
        param_3 = param_3 + 1;
        param_1 = (int *)((int)param_1 + -1);
      } while (param_1 != (int *)0x0);
    }
  }
  else if (iVar3 == 3) {
    if (param_4 != 0) {
      do {
        uVar1 = 0;
        if (*param_3 != 0) {
          do {
            iVar3 = 4;
            do {
              *(undefined4 *)(uVar1 + param_2) = *(undefined4 *)(uVar1 + *param_3);
              uVar1 = uVar1 + 4;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          } while (uVar1 < 0x40);
        }
        param_2 = param_2 + 0x40;
        param_3 = param_3 + 1;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  else {
    local_8 = 0x8876086c;
  }
  return local_8;
}


// ==== FUN_008d78c4 @ 0x008d78c4 ====

undefined4 FUN_008d78c4(int *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  int *piVar5;
  int iVar6;
  undefined4 local_c;
  int local_8;
  
  iVar6 = *param_1;
  local_c = 0;
  if (iVar6 == 1) {
    if (param_4 != (uint *)0x0) {
      do {
        uVar1 = 0;
        if (*param_3 != 0) {
          puVar3 = param_2;
          do {
            puVar4 = puVar3;
            iVar6 = 4;
            do {
              *puVar4 = (uint)(DAT_0099cdc8 != *(float *)(uVar1 + *param_3));
              puVar4 = puVar4 + 4;
              uVar1 = uVar1 + 4;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            puVar3 = puVar3 + 1;
          } while (uVar1 < 0x40);
        }
        param_2 = param_2 + 0x10;
        param_3 = param_3 + 1;
        param_4 = (uint *)((int)param_4 + -1);
      } while (param_4 != (uint *)0x0);
    }
  }
  else if (iVar6 == 2) {
    if (param_4 != (uint *)0x0) {
      local_8 = (int)param_4;
      do {
        uVar1 = 0;
        if (*param_3 != 0) {
          param_4 = param_2;
          do {
            param_1 = (int *)0x4;
            puVar3 = param_4;
            do {
              uVar2 = __ftol();
              *puVar3 = uVar2;
              puVar3 = puVar3 + 4;
              uVar1 = uVar1 + 4;
              param_1 = (int *)((int)param_1 + -1);
            } while (param_1 != (int *)0x0);
            param_4 = param_4 + 1;
          } while (uVar1 < 0x40);
        }
        param_2 = param_2 + 0x10;
        param_3 = param_3 + 1;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
  }
  else if (iVar6 == 3) {
    if (param_4 != (uint *)0x0) {
      piVar5 = (int *)param_3;
      do {
        uVar1 = 0;
        if (*piVar5 != 0) {
          param_3 = param_2;
          do {
            puVar3 = param_3;
            iVar6 = 4;
            do {
              puVar4 = (uint *)(uVar1 + *piVar5);
              uVar1 = uVar1 + 4;
              *puVar3 = *puVar4;
              puVar3 = puVar3 + 4;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            param_3 = param_3 + 1;
          } while (uVar1 < 0x40);
        }
        param_2 = param_2 + 0x10;
        piVar5 = piVar5 + 1;
        param_4 = (uint *)((int)param_4 + -1);
      } while (param_4 != (uint *)0x0);
    }
  }
  else {
    local_c = 0x8876086c;
  }
  return local_c;
}


// ==== FUN_008d79f3 @ 0x008d79f3 ====

undefined4 FUN_008d79f3(int *param_1,int param_2,int *param_3,int param_4)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 local_c;
  uint local_8;
  
  iVar3 = *param_1;
  puVar1 = (uint *)(param_1 + 5);
  puVar2 = (uint *)(param_1 + 6);
  local_c = 0;
  param_1 = (int *)0x4;
  if (*puVar2 < 5) {
    param_1 = (int *)*puVar2;
  }
  local_8 = 4;
  if (*puVar1 < 5) {
    local_8 = *puVar1;
  }
  if (iVar3 == 1) {
    if (param_4 != 0) {
      do {
        if ((undefined4 *)*param_3 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)*param_3;
          for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          uVar6 = 0;
          if (param_1 != (int *)0x0) {
            do {
              if (local_8 != 0) {
                iVar3 = uVar6 << 4;
                uVar4 = local_8;
                do {
                  *(float *)(iVar3 + *param_3) = (float)(*(int *)(iVar3 + param_2) != 0);
                  iVar3 = iVar3 + 4;
                  uVar4 = uVar4 - 1;
                } while (uVar4 != 0);
              }
              uVar6 = uVar6 + 1;
            } while (uVar6 < param_1);
          }
        }
        param_2 = param_2 + 0x40;
        param_3 = param_3 + 1;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  else if (iVar3 == 2) {
    if (param_4 != 0) {
      do {
        if ((undefined4 *)*param_3 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)*param_3;
          for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          uVar6 = 0;
          if (param_1 != (int *)0x0) {
            do {
              if (local_8 != 0) {
                iVar3 = uVar6 << 4;
                uVar4 = local_8;
                do {
                  *(float *)(iVar3 + *param_3) = (float)*(int *)(iVar3 + param_2);
                  iVar3 = iVar3 + 4;
                  uVar4 = uVar4 - 1;
                } while (uVar4 != 0);
              }
              uVar6 = uVar6 + 1;
            } while (uVar6 < param_1);
          }
        }
        param_2 = param_2 + 0x40;
        param_3 = param_3 + 1;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  else if (iVar3 == 3) {
    if (param_4 != 0) {
      do {
        if ((undefined4 *)*param_3 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)*param_3;
          for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          uVar6 = 0;
          if (param_1 != (int *)0x0) {
            do {
              if (local_8 != 0) {
                iVar3 = uVar6 << 4;
                uVar4 = local_8;
                do {
                  *(undefined4 *)(iVar3 + *param_3) = *(undefined4 *)(iVar3 + param_2);
                  iVar3 = iVar3 + 4;
                  uVar4 = uVar4 - 1;
                } while (uVar4 != 0);
              }
              uVar6 = uVar6 + 1;
            } while (uVar6 < param_1);
          }
        }
        param_2 = param_2 + 0x40;
        param_3 = param_3 + 1;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  else {
    local_c = 0x8876086c;
  }
  return local_c;
}


// ==== FUN_008d7b51 @ 0x008d7b51 ====

undefined4 FUN_008d7b51(int *param_1,int *param_2,int *param_3,int *param_4)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_10 = 0;
  iVar2 = *param_1;
  puVar1 = (uint *)(param_1 + 6);
  local_8 = 4;
  if ((uint)param_1[5] < 5) {
    local_8 = param_1[5];
  }
  param_1 = (int *)0x4;
  if (*puVar1 < 5) {
    param_1 = (int *)*puVar1;
  }
  if (iVar2 == 1) {
    if (param_4 != (int *)0x0) {
      local_c = (int)param_4;
      do {
        if ((undefined4 *)*param_3 != (undefined4 *)0x0) {
          uVar4 = 0;
          puVar5 = (undefined4 *)*param_3;
          for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          if (param_1 != (int *)0x0) {
            param_4 = param_2;
            do {
              if (local_8 != 0) {
                iVar2 = uVar4 << 2;
                piVar3 = param_4;
                uVar6 = local_8;
                do {
                  *(float *)(iVar2 + *param_3) = (float)(*piVar3 != 0);
                  iVar2 = iVar2 + 0x10;
                  piVar3 = piVar3 + 1;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_4 = param_4 + 4;
              uVar4 = uVar4 + 1;
            } while (uVar4 < param_1);
          }
        }
        param_2 = param_2 + 0x10;
        param_3 = param_3 + 1;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  else if (iVar2 == 2) {
    if (param_4 != (int *)0x0) {
      local_c = (int)param_4;
      do {
        if ((undefined4 *)*param_3 != (undefined4 *)0x0) {
          uVar4 = 0;
          puVar5 = (undefined4 *)*param_3;
          for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          if (param_1 != (int *)0x0) {
            param_4 = param_2;
            do {
              if (local_8 != 0) {
                iVar2 = uVar4 << 2;
                piVar3 = param_4;
                uVar6 = local_8;
                do {
                  *(float *)(iVar2 + *param_3) = (float)*piVar3;
                  iVar2 = iVar2 + 0x10;
                  piVar3 = piVar3 + 1;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_4 = param_4 + 4;
              uVar4 = uVar4 + 1;
            } while (uVar4 < param_1);
          }
        }
        param_2 = param_2 + 0x10;
        param_3 = param_3 + 1;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  else if (iVar2 == 3) {
    if (param_4 != (int *)0x0) {
      local_c = (int)param_4;
      do {
        if ((undefined4 *)*param_3 != (undefined4 *)0x0) {
          uVar4 = 0;
          puVar5 = (undefined4 *)*param_3;
          for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          if (param_1 != (int *)0x0) {
            param_4 = param_2;
            do {
              if (local_8 != 0) {
                iVar2 = uVar4 << 2;
                piVar3 = param_4;
                uVar6 = local_8;
                do {
                  *(int *)(iVar2 + *param_3) = *piVar3;
                  iVar2 = iVar2 + 0x10;
                  piVar3 = piVar3 + 1;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_4 = param_4 + 4;
              uVar4 = uVar4 + 1;
            } while (uVar4 < param_1);
          }
        }
        param_2 = param_2 + 0x10;
        param_3 = param_3 + 1;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  else {
    local_10 = 0x8876086c;
  }
  return local_10;
}


// ==== FUN_008d7cd6 @ 0x008d7cd6 ====

int FUN_008d7cd6(int *param_1,int *param_2,int *param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  bool bVar9;
  int local_c;
  int local_8;
  
  piVar1 = (int *)*param_1;
  local_c = 0;
  iVar2 = *piVar1;
  local_8 = piVar1[4];
  iVar4 = piVar1[1];
  if (local_8 == 0) {
    local_8 = 1;
  }
  if (-1 < iVar4) {
    if (iVar4 < 4) {
      uVar3 = piVar1[6] * piVar1[5] * local_8;
      if (((iVar2 != 1) && (iVar2 != 2)) && (iVar2 != 3)) {
        return -0x7fffbffb;
      }
      iVar2 = uVar3 * 4;
      puVar6 = (undefined4 *)*param_3;
      puVar7 = (undefined4 *)*param_2;
      for (uVar3 = uVar3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      *param_2 = *param_2 + iVar2;
      *param_3 = *param_3 + iVar2;
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar4 != 4) {
      if (iVar4 != 5) {
        return -0x7fffbffb;
      }
      uVar3 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      do {
        if (local_8 == 0) {
          return local_c;
        }
        uVar5 = 0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar3 != 0) {
          do {
            local_c = FUN_008d7cd6(param_1,param_2,param_3,param_4,param_5,param_6);
            if (local_c < 0) {
              return local_c;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar3);
        }
        local_8 = local_8 + -1;
      } while( true );
    }
    if (iVar2 < 0x10) {
      if (iVar2 == 0xf) {
        for (; local_8 != 0; local_8 = local_8 + -1) {
          if (param_5 == 0) {
            iVar2 = *(int *)*param_3;
          }
          else {
            iVar2 = *(int *)(*(int *)(param_5 + 8) + *(int *)*param_3 * 4);
          }
          iVar2 = *(int *)(param_6 + 0x18) + iVar2 * 0x18;
          if (param_4 == 0) {
            iVar4 = *(int *)*param_2;
          }
          else {
            iVar4 = *(int *)(*(int *)(param_4 + 8) + *(int *)*param_2 * 4);
          }
          iVar4 = *(int *)(in_ECX + 0x18) + iVar4 * 0x18;
          if (*(int *)(iVar2 + 8) != 0) {
            (**(code **)(**(int **)(iVar2 + 8) + 4))(*(int **)(iVar2 + 8));
          }
          piVar1 = *(int **)(iVar4 + 8);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)(iVar4 + 8) = 0;
          }
          *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar2 + 8);
          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
          if ((*(int *)(in_ECX + 0xc) == *(int *)(param_6 + 0xc)) || (*(int *)(iVar2 + 8) == 0)) {
            if (*(int *)(iVar2 + 4) != 0) {
              (**(code **)(**(int **)(iVar2 + 4) + 4))(*(int **)(iVar2 + 4));
            }
            piVar1 = *(int **)(iVar4 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar4 + 4) = 0;
            }
            *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar2 + 4);
            *(uint *)(iVar4 + 0x14) =
                 *(uint *)(iVar4 + 0x14) ^
                 ((*(int *)(iVar2 + 0x14) << 0x1e) >> 0x1e ^ *(uint *)(iVar4 + 0x14)) & 2;
          }
          else {
            piVar1 = *(int **)(iVar4 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar4 + 4) = 0;
            }
            if (param_4 != 0) {
              return -0x7fffbffb;
            }
            FUN_008d5d63(iVar4);
          }
          *param_2 = *param_2 + 4;
          *param_3 = *param_3 + 4;
        }
        goto LAB_008d811c;
      }
      if (iVar2 == 4) {
        if (local_8 != 0) {
          do {
            if (param_5 == 0) {
              iVar2 = *(int *)*param_3;
            }
            else {
              iVar2 = *(int *)(*(int *)(param_5 + 8) + *(int *)*param_3 * 4);
            }
            iVar2 = *(int *)(param_6 + 0x18) + iVar2 * 0x18;
            if (param_4 == 0) {
              iVar4 = *(int *)*param_2;
            }
            else {
              iVar4 = *(int *)(*(int *)(param_4 + 8) + *(int *)*param_2 * 4);
            }
            iVar4 = *(int *)(in_ECX + 0x18) + iVar4 * 0x18;
            if (*(int *)(iVar2 + 4) != 0) {
              (**(code **)(**(int **)(iVar2 + 4) + 4))(*(int **)(iVar2 + 4));
            }
            piVar1 = *(int **)(iVar4 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar4 + 4) = 0;
            }
            *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar2 + 4);
            *param_2 = *param_2 + 4;
            *param_3 = *param_3 + 4;
            local_8 = local_8 + -1;
          } while (local_8 != 0);
        }
        goto LAB_008d811c;
      }
      if (iVar2 < 5) {
        return -0x7fffbffb;
      }
      if (iVar2 < 10) {
        if (local_8 != 0) {
          do {
            if (param_5 == 0) {
              iVar2 = *(int *)*param_3;
            }
            else {
              iVar2 = *(int *)(*(int *)(param_5 + 8) + *(int *)*param_3 * 4);
            }
            iVar2 = *(int *)(param_6 + 0x18) + iVar2 * 0x18;
            if (param_4 == 0) {
              iVar4 = *(int *)*param_2;
            }
            else {
              iVar4 = *(int *)(*(int *)(param_4 + 8) + *(int *)*param_2 * 4);
            }
            iVar4 = *(int *)(in_ECX + 0x18) + iVar4 * 0x18;
            if (*(int *)(in_ECX + 0xc) == *(int *)(param_6 + 0xc)) {
              if (*(int *)(iVar2 + 4) != 0) {
                (**(code **)(**(int **)(iVar2 + 4) + 4))(*(int **)(iVar2 + 4));
              }
              piVar1 = *(int **)(iVar4 + 4);
              if (piVar1 != (int *)0x0) {
                (**(code **)(*piVar1 + 8))(piVar1);
                *(undefined4 *)(iVar4 + 4) = 0;
              }
              *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar2 + 4);
            }
            else {
              piVar1 = *(int **)(iVar4 + 4);
              if (piVar1 != (int *)0x0) {
                (**(code **)(*piVar1 + 8))(piVar1);
                *(undefined4 *)(iVar4 + 4) = 0;
              }
              if (param_4 != 0) {
                return -0x7fffbffb;
              }
            }
            *param_2 = *param_2 + 4;
            *param_3 = *param_3 + 4;
            local_8 = local_8 + -1;
          } while (local_8 != 0);
        }
        goto LAB_008d811c;
      }
      bVar9 = SBORROW4(iVar2,0xe);
      iVar4 = iVar2 + -0xe;
      bVar8 = iVar2 == 0xe;
    }
    else {
      if (iVar2 == 0x10) {
        for (; local_8 != 0; local_8 = local_8 + -1) {
          if (param_5 == 0) {
            iVar2 = *(int *)*param_3;
          }
          else {
            iVar2 = *(int *)(*(int *)(param_5 + 8) + *(int *)*param_3 * 4);
          }
          iVar2 = *(int *)(param_6 + 0x18) + iVar2 * 0x18;
          if (param_4 == 0) {
            iVar4 = *(int *)*param_2;
          }
          else {
            iVar4 = *(int *)(*(int *)(param_4 + 8) + *(int *)*param_2 * 4);
          }
          iVar4 = *(int *)(in_ECX + 0x18) + iVar4 * 0x18;
          if (*(int *)(iVar2 + 8) != 0) {
            (**(code **)(**(int **)(iVar2 + 8) + 4))(*(int **)(iVar2 + 8));
          }
          piVar1 = *(int **)(iVar4 + 8);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)(iVar4 + 8) = 0;
          }
          *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar2 + 8);
          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
          if ((*(int *)(in_ECX + 0xc) == *(int *)(param_6 + 0xc)) || (*(int *)(iVar2 + 8) == 0)) {
            if (*(int *)(iVar2 + 4) != 0) {
              (**(code **)(**(int **)(iVar2 + 4) + 4))(*(int **)(iVar2 + 4));
            }
            piVar1 = *(int **)(iVar4 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar4 + 4) = 0;
            }
            *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar2 + 4);
            *(uint *)(iVar4 + 0x14) =
                 *(uint *)(iVar4 + 0x14) ^
                 ((*(int *)(iVar2 + 0x14) << 0x1e) >> 0x1e ^ *(uint *)(iVar4 + 0x14)) & 2;
          }
          else {
            piVar1 = *(int **)(iVar4 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar4 + 4) = 0;
            }
            if (param_4 != 0) {
              return -0x7fffbffb;
            }
            FUN_008d5d05(iVar4);
          }
          *param_2 = *param_2 + 4;
          *param_3 = *param_3 + 4;
        }
        goto LAB_008d811c;
      }
      if (iVar2 < 0x11) {
        return -0x7fffbffb;
      }
      bVar9 = SBORROW4(iVar2,0x12);
      iVar4 = iVar2 + -0x12;
      bVar8 = iVar2 == 0x12;
    }
    if (bVar8 || bVar9 != iVar4 < 0) {
LAB_008d811c:
      *param_1 = *param_1 + 0x14;
      return 0;
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008d816f @ 0x008d816f ====

int FUN_008d816f(int *param_1,int *param_2,int *param_3,uint param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int local_c;
  int local_8;
  
  piVar4 = param_1;
  piVar1 = (int *)*param_1;
  iVar5 = *piVar1;
  iVar2 = piVar1[1];
  if (iVar2 < 0) {
    return -0x7fffbffb;
  }
  if (iVar2 < 2) {
    puVar7 = (undefined4 *)*param_2;
    puVar9 = (undefined4 *)*param_3;
    iVar5 = piVar1[5];
    puVar6 = puVar7 + param_4 * 4;
    for (; puVar7 < puVar6; puVar7 = puVar7 + (4 - iVar5)) {
      if (iVar5 != 0) {
        param_4 = iVar5;
        do {
          *puVar7 = *puVar9;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
          param_4 = param_4 + -1;
        } while (param_4 != 0);
      }
    }
    *param_2 = (int)puVar7;
    *param_3 = (int)puVar9;
  }
  else {
    if (3 < iVar2) {
      if (iVar2 == 4) {
        if (iVar5 == 4) {
          for (; param_4 != 0; param_4 = param_4 + -1) {
            iVar5 = FUN_008d7113(*(undefined4 *)*param_3,*(undefined4 *)*param_2,
                                 *(undefined4 *)
                                  (*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_5 + 0x14) * 4)
                                  + 0x40));
            if (iVar5 < 0) {
              return iVar5;
            }
            *param_2 = *param_2 + 4;
            *param_3 = *param_3 + 4;
          }
        }
        else if (4 < iVar5) {
          if (iVar5 < 10) {
            for (; param_4 != 0; param_4 = param_4 + -1) {
              iVar5 = FUN_008d706f(*(undefined4 *)*param_3,*(undefined4 *)*param_2,
                                   *(undefined4 *)
                                    (*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_5 + 0x14) * 4
                                             ) + 0x40));
              if (iVar5 < 0) {
                return iVar5;
              }
              *param_2 = *param_2 + 4;
              *param_3 = *param_3 + 4;
            }
          }
          else if (iVar5 == 0xf) {
            for (; param_4 != 0; param_4 = param_4 + -1) {
              iVar5 = FUN_008d6fb7(*(undefined4 *)*param_3,*(undefined4 *)*param_2,
                                   *(undefined4 *)
                                    (*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_5 + 0x14) * 4
                                             ) + 0x40));
              if (iVar5 < 0) {
                return iVar5;
              }
              *param_2 = *param_2 + 4;
              *param_3 = *param_3 + 4;
            }
          }
          else if (iVar5 == 0x10) {
            for (; param_4 != 0; param_4 = param_4 + -1) {
              iVar5 = FUN_008d6fb7(*(undefined4 *)*param_3,*(undefined4 *)*param_2,
                                   *(undefined4 *)
                                    (*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_5 + 0x14) * 4
                                             ) + 0x40));
              if (iVar5 < 0) {
                return iVar5;
              }
              *param_2 = *param_2 + 4;
              *param_3 = *param_3 + 4;
            }
          }
        }
        *param_1 = *param_1 + 0x14;
        return 0;
      }
      if (iVar2 != 5) {
        return -0x7fffbffb;
      }
      uVar3 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      do {
        if (param_4 == 0) {
          return 0;
        }
        param_1 = (int *)0x0;
        *piVar4 = (int)(piVar1 + 6);
        if (uVar3 != 0) {
          do {
            iVar5 = *(int *)(*piVar4 + 0x10);
            if (iVar5 == 0) {
              iVar5 = 1;
            }
            iVar5 = FUN_008d816f(piVar4,param_2,param_3,iVar5,param_5);
            if (iVar5 < 0) {
              return iVar5;
            }
            param_1 = (int *)((int)param_1 + 1);
          } while (param_1 < uVar3);
        }
        param_4 = param_4 + -1;
      } while( true );
    }
    iVar2 = piVar1[5];
    uVar3 = piVar1[6];
    if (iVar5 == 1) {
      if (param_4 != 0) {
        local_8 = param_4;
        do {
          param_4 = 0;
          if (uVar3 != 0) {
            do {
              if (iVar2 != 0) {
                iVar5 = param_4 << 4;
                iVar8 = param_4 << 2;
                local_c = iVar2;
                do {
                  *(uint *)(iVar5 + *param_2) = (uint)(*(int *)(iVar8 + *param_3) != 0);
                  iVar5 = iVar5 + 4;
                  iVar8 = iVar8 + uVar3 * 4;
                  local_c = local_c + -1;
                } while (local_c != 0);
              }
              param_4 = param_4 + 1;
            } while (param_4 < uVar3);
          }
          *param_2 = *param_2 + 0x40;
          *param_3 = *param_3 + uVar3 * iVar2 * 4;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
    }
    else if (iVar5 == 2) {
      if (param_4 != 0) {
        local_8 = param_4;
        do {
          param_4 = 0;
          if (uVar3 != 0) {
            do {
              if (iVar2 != 0) {
                iVar5 = param_4 << 4;
                iVar8 = param_4 << 2;
                local_c = iVar2;
                do {
                  *(undefined4 *)(iVar5 + *param_2) = *(undefined4 *)(iVar8 + *param_3);
                  iVar5 = iVar5 + 4;
                  iVar8 = iVar8 + uVar3 * 4;
                  local_c = local_c + -1;
                } while (local_c != 0);
              }
              param_4 = param_4 + 1;
            } while (param_4 < uVar3);
          }
          *param_2 = *param_2 + 0x40;
          *param_3 = *param_3 + uVar3 * iVar2 * 4;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
    }
    else if ((iVar5 == 3) && (param_4 != 0)) {
      local_c = param_4;
      do {
        param_4 = 0;
        if (uVar3 != 0) {
          do {
            if (iVar2 != 0) {
              iVar5 = param_4 << 4;
              iVar8 = param_4 << 2;
              local_8 = iVar2;
              do {
                *(undefined4 *)(iVar5 + *param_2) = *(undefined4 *)(iVar8 + *param_3);
                iVar5 = iVar5 + 4;
                iVar8 = iVar8 + uVar3 * 4;
                local_8 = local_8 + -1;
              } while (local_8 != 0);
            }
            param_4 = param_4 + 1;
          } while (param_4 < uVar3);
        }
        *param_2 = *param_2 + 0x40;
        *param_3 = *param_3 + uVar3 * iVar2 * 4;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  *param_1 = *param_1 + 0x1c;
  return 0;
}


// ==== FUN_008d850f @ 0x008d850f ====

int FUN_008d850f(int *param_1,int *param_2,int *param_3,uint param_4,uint param_5)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  int iVar7;
  bool bVar8;
  int local_14;
  int local_10;
  int local_c;
  
  piVar1 = (int *)*param_1;
  local_c = 0;
  bVar8 = param_5 != 0;
  iVar7 = *piVar1;
  param_5 = piVar1[4];
  iVar5 = piVar1[1];
  if ((bVar8) || (param_5 == 0)) {
    param_5 = 1;
  }
  if (-1 < iVar5) {
    if (iVar5 < 4) {
      iVar3 = piVar1[5];
      uVar2 = piVar1[6];
      iVar5 = ((iVar5 != 2) - 1 & 0x30) + 0x10;
      local_10 = param_5;
      if (iVar7 == 1) {
        if (param_5 != 0) {
          do {
            param_4 = 0;
            if (uVar2 != 0) {
              do {
                if (iVar3 != 0) {
                  iVar7 = param_4 << 4;
                  iVar6 = param_4 << 2;
                  local_14 = iVar3;
                  do {
                    piVar1 = (int *)(iVar7 + *param_2);
                    iVar7 = iVar7 + 4;
                    *(uint *)(iVar6 + *param_3) = (uint)(*piVar1 != 0);
                    iVar6 = iVar6 + uVar2 * 4;
                    local_14 = local_14 + -1;
                  } while (local_14 != 0);
                }
                param_4 = param_4 + 1;
              } while (param_4 < uVar2);
            }
            *param_2 = *param_2 + iVar5;
            *param_3 = *param_3 + uVar2 * iVar3 * 4;
            local_10 = local_10 + -1;
          } while (local_10 != 0);
        }
      }
      else if (iVar7 == 2) {
        if (param_5 != 0) {
          do {
            param_4 = 0;
            if (uVar2 != 0) {
              do {
                if (iVar3 != 0) {
                  iVar6 = param_4 << 4;
                  iVar7 = param_4 << 2;
                  local_14 = iVar3;
                  do {
                    *(undefined4 *)(iVar7 + *param_3) = *(undefined4 *)(iVar6 + *param_2);
                    iVar6 = iVar6 + 4;
                    iVar7 = iVar7 + uVar2 * 4;
                    local_14 = local_14 + -1;
                  } while (local_14 != 0);
                }
                param_4 = param_4 + 1;
              } while (param_4 < uVar2);
            }
            *param_2 = *param_2 + iVar5;
            *param_3 = *param_3 + uVar2 * iVar3 * 4;
            local_10 = local_10 + -1;
          } while (local_10 != 0);
        }
      }
      else {
        if (iVar7 != 3) {
          return -0x7fffbffb;
        }
        if (param_5 != 0) {
          local_14 = param_5;
          do {
            param_4 = 0;
            if (uVar2 != 0) {
              do {
                if (iVar3 != 0) {
                  iVar6 = param_4 << 4;
                  iVar7 = param_4 << 2;
                  local_10 = iVar3;
                  do {
                    *(undefined4 *)(iVar7 + *param_3) = *(undefined4 *)(iVar6 + *param_2);
                    iVar6 = iVar6 + 4;
                    iVar7 = iVar7 + uVar2 * 4;
                    local_10 = local_10 + -1;
                  } while (local_10 != 0);
                }
                param_4 = param_4 + 1;
              } while (param_4 < uVar2);
            }
            *param_2 = *param_2 + iVar5;
            *param_3 = *param_3 + uVar2 * iVar3 * 4;
            local_14 = local_14 + -1;
          } while (local_14 != 0);
        }
      }
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar5 == 4) {
      if (iVar7 == 4) {
        if (param_5 != 0) {
          do {
            iVar7 = *(int *)*param_2;
            if (param_4 != 0) {
              iVar7 = *(int *)(*(int *)(param_4 + 8) + iVar7 * 4);
            }
            iVar7 = *(int *)(in_ECX + 0x18) + iVar7 * 0x18;
            if (*(int *)(iVar7 + 4) == 0) {
              uVar4 = 0;
            }
            else {
              piVar1 = *(int **)(iVar7 + 4);
              uVar4 = (**(code **)(*piVar1 + 0xc))(piVar1);
            }
            *(undefined4 *)*param_3 = uVar4;
            *param_2 = *param_2 + 4;
            *param_3 = *param_3 + 4;
            param_5 = param_5 + -1;
          } while (param_5 != 0);
        }
      }
      else {
        if (iVar7 < 5) {
          return -0x7fffbffb;
        }
        if (iVar7 < 10) {
          if (param_5 != 0) {
            do {
              iVar7 = *(int *)*param_2;
              if (param_4 != 0) {
                iVar7 = *(int *)(*(int *)(param_4 + 8) + iVar7 * 4);
              }
              *(undefined4 *)*param_3 = *(undefined4 *)(*(int *)(in_ECX + 0x18) + 4 + iVar7 * 0x18);
              if (*(int *)*param_3 != 0) {
                piVar1 = *(int **)*param_3;
                (**(code **)(*piVar1 + 4))(piVar1);
              }
              *param_2 = *param_2 + 4;
              *param_3 = *param_3 + 4;
              param_5 = param_5 + -1;
            } while (param_5 != 0);
          }
        }
        else if (iVar7 == 0xf) {
          if (param_5 != 0) {
            do {
              iVar7 = *(int *)*param_2;
              if (param_4 != 0) {
                iVar7 = *(int *)(*(int *)(param_4 + 8) + iVar7 * 4);
              }
              *(undefined4 *)*param_3 = *(undefined4 *)(*(int *)(in_ECX + 0x18) + 4 + iVar7 * 0x18);
              if (*(int *)*param_3 != 0) {
                piVar1 = *(int **)*param_3;
                (**(code **)(*piVar1 + 4))(piVar1);
              }
              *param_2 = *param_2 + 4;
              *param_3 = *param_3 + 4;
              param_5 = param_5 + -1;
            } while (param_5 != 0);
          }
        }
        else {
          if (iVar7 != 0x10) {
            return -0x7fffbffb;
          }
          if (param_5 != 0) {
            do {
              iVar7 = *(int *)*param_2;
              if (param_4 != 0) {
                iVar7 = *(int *)(*(int *)(param_4 + 8) + iVar7 * 4);
              }
              *(undefined4 *)*param_3 = *(undefined4 *)(*(int *)(in_ECX + 0x18) + 4 + iVar7 * 0x18);
              if (*(int *)*param_3 != 0) {
                piVar1 = *(int **)*param_3;
                (**(code **)(*piVar1 + 4))(piVar1);
              }
              *param_2 = *param_2 + 4;
              *param_3 = *param_3 + 4;
              param_5 = param_5 + -1;
            } while (param_5 != 0);
          }
        }
      }
      *param_1 = *param_1 + 0x14;
      return 0;
    }
    if (iVar5 == 5) {
      uVar2 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      iVar7 = param_5;
      do {
        if (iVar7 == 0) {
          return local_c;
        }
        param_5 = 0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar2 != 0) {
          do {
            local_c = FUN_008d850f(param_1,param_2,param_3,param_4,0);
            if (local_c < 0) {
              return local_c;
            }
            param_5 = param_5 + 1;
          } while (param_5 < uVar2);
        }
        iVar7 = iVar7 + -1;
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008d88d5 @ 0x008d88d5 ====

undefined4 FUN_008d88d5(void)

{
  return 0x80004005;
}


// ==== FUN_008d88dd @ 0x008d88dd ====

undefined4 FUN_008d88dd(void)

{
  return 0x80004005;
}


// ==== FUN_008d88e5 @ 0x008d88e5 ====

void FUN_008d88e5(void)

{
  return;
}


// ==== FUN_008d88e8 @ 0x008d88e8 ====

undefined4 FUN_008d88e8(void)

{
  return 0x80004005;
}


// ==== FUN_008d88f0 @ 0x008d88f0 ====

undefined4 FUN_008d88f0(void)

{
  return 0x80004005;
}


// ==== FUN_008d88f8 @ 0x008d88f8 ====

undefined4 FUN_008d88f8(void)

{
  return 0x80004005;
}


// ==== FUN_008d8900 @ 0x008d8900 ====

undefined4 FUN_008d8900(void)

{
  return 0x80004005;
}


// ==== FUN_008d8908 @ 0x008d8908 ====

float10 FUN_008d8908(void)

{
  return (float10)DAT_0099cdc8;
}


// ==== FUN_008d8911 @ 0x008d8911 ====

undefined4 FUN_008d8911(void)

{
  return 0x80004005;
}


// ==== FUN_008d8919 @ 0x008d8919 ====

undefined4 FUN_008d8919(void)

{
  return 0x80004005;
}


// ==== FUN_008d8921 @ 0x008d8921 ====

undefined4 FUN_008d8921(int *param_1)

{
  int *piVar1;
  int in_ECX;
  
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  piVar1 = *(int **)(in_ECX + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  *(int **)(in_ECX + 8) = param_1;
  *(int **)(in_ECX + 4) = param_1;
  return 0;
}


// ==== FUN_008d8956 @ 0x008d8956 ====

undefined4 FUN_008d8956(int *param_1)

{
  int *piVar1;
  int in_ECX;
  
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  piVar1 = *(int **)(in_ECX + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  *(int **)(in_ECX + 0xc) = param_1;
  if (param_1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 8);
  }
  else {
    *(int *)(in_ECX + 4) = in_ECX;
  }
  return 0;
}


// ==== FUN_008d8997 @ 0x008d8997 ====

undefined4 FUN_008d8997(undefined4 *param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 4))(*(int **)(in_ECX + 0xc));
  }
  *param_1 = *(undefined4 *)(in_ECX + 0xc);
  return 0;
}


// ==== FUN_008d89bd @ 0x008d89bd ====

void FUN_008d89bd(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0xc))(*(int **)(param_1 + 0xc),param_2,param_3);
  return;
}


// ==== FUN_008d89d8 @ 0x008d89d8 ====

void FUN_008d89d8(int param_1,undefined4 param_2)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x10))(*(int **)(param_1 + 0xc),param_2);
  return;
}


// ==== FUN_008d89f0 @ 0x008d89f0 ====

void FUN_008d89f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x14))(*(int **)(param_1 + 0xc),param_2,param_3);
  return;
}


// ==== FUN_008d8a0b @ 0x008d8a0b ====

void FUN_008d8a0b(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x18))(*(int **)(param_1 + 0xc),param_2,param_3);
  return;
}


// ==== FUN_008d8a26 @ 0x008d8a26 ====

void FUN_008d8a26(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))(*(int **)(param_1 + 0xc),param_2,param_3);
  return;
}


// ==== FUN_008d8a41 @ 0x008d8a41 ====

void FUN_008d8a41(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x20))(*(int **)(param_1 + 0xc),param_2,param_3);
  return;
}


// ==== FUN_008d8a5c @ 0x008d8a5c ====

void FUN_008d8a5c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x24))(*(int **)(param_1 + 0xc),param_2,param_3,param_4);
  return;
}


// ==== FUN_008d8a7a @ 0x008d8a7a ====

void FUN_008d8a7a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x28))(*(int **)(param_1 + 0xc),param_2,param_3,param_4);
  return;
}


// ==== FUN_008d8a98 @ 0x008d8a98 ====

void FUN_008d8a98(int param_1,undefined4 param_2)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x2c))(*(int **)(param_1 + 0xc),param_2);
  return;
}


// ==== FUN_008d8ab4 @ 0x008d8ab4 ====

void FUN_008d8ab4(int param_1,undefined4 param_2)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x30))(*(int **)(param_1 + 0xc),param_2);
  return;
}


// ==== FUN_008d8acc @ 0x008d8acc ====

void FUN_008d8acc(int param_1,undefined4 param_2)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x34))(*(int **)(param_1 + 0xc),param_2);
  return;
}


// ==== FUN_008d8ae4 @ 0x008d8ae4 ====

void FUN_008d8ae4(int param_1,undefined4 param_2)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x44))(*(int **)(param_1 + 0xc),param_2);
  return;
}


// ==== FUN_008d8afc @ 0x008d8afc ====

void FUN_008d8afc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x38))(*(int **)(param_1 + 0xc),param_2,param_3,param_4);
  return;
}


// ==== FUN_008d8b1a @ 0x008d8b1a ====

void FUN_008d8b1a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x3c))(*(int **)(param_1 + 0xc),param_2,param_3,param_4);
  return;
}


// ==== FUN_008d8b38 @ 0x008d8b38 ====

int FUN_008d8b38(int param_1,int param_2,int *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = 0;
  if (param_4 != 0) {
    piVar3 = param_3;
    do {
      param_3 = (int *)0x0;
      if (*piVar3 != 0) {
        param_3 = (int *)0xffffffff;
      }
      iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x40))
                        (*(int **)(param_1 + 0xc),param_2 + uVar2,&param_3,1);
      if (iVar1 < 0) {
        return iVar1;
      }
      piVar3 = piVar3 + 1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_4);
  }
  return 0;
}


// ==== FUN_008d8b83 @ 0x008d8b83 ====

void FUN_008d8b83(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x48))(*(int **)(param_1 + 0xc),param_2,param_3,param_4);
  return;
}


// ==== FUN_008d8ba1 @ 0x008d8ba1 ====

void FUN_008d8ba1(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x4c))(*(int **)(param_1 + 0xc),param_2,param_3,param_4);
  return;
}


// ==== FUN_008d8bbf @ 0x008d8bbf ====

void FUN_008d8bbf(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x50))(*(int **)(param_1 + 0xc),param_2,param_3,param_4);
  return;
}


// ==== FUN_008d8bdd @ 0x008d8bdd ====

uint FUN_008d8bdd(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint extraout_EAX;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint local_8;
  
  local_8 = 0;
  if ((*(int *)(param_1 + 0x3c) != 4) && (*(int *)(param_1 + 0x3c) == 3)) {
    if (*(int *)(param_1 + 0xd0) == *(int *)(param_1 + 0xd4)) {
      uVar1 = *(int *)(param_1 + 0xd0) * 2 + 1;
      puVar2 = operator_new(uVar1 * 4);
      if (puVar2 == (undefined4 *)0x0) {
        return 0;
      }
      puVar5 = puVar2;
      for (uVar3 = uVar1 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar5 = 0;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      puVar5 = *(undefined4 **)(param_1 + 0xd8);
      puVar6 = puVar2;
      for (uVar3 = *(uint *)(param_1 + 0xd0) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      if (*(void **)(param_1 + 0xd8) != (void *)0x0) {
        _free(*(void **)(param_1 + 0xd8));
        return extraout_EAX;
      }
      *(undefined4 **)(param_1 + 0xd8) = puVar2;
      *(uint *)(param_1 + 0xd4) = uVar1;
    }
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0xd8) + *(int *)(param_1 + 0xd0) * 4) =
         *(undefined4 *)(param_1 + 0xf8);
    *(undefined4 *)(param_1 + 0xf8) = 0;
    puVar2 = operator_new(0x28);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2[2] = 0xffffffff;
      puVar2[9] = 0;
      puVar2[8] = 0;
      *puVar2 = 0;
      puVar2[1] = 0;
    }
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[4] = 4;
      puVar2[5] = *(undefined4 *)(param_1 + 0xd0);
      puVar2[9] = *(undefined4 *)(param_1 + 0xdc);
      *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + 1;
      *(undefined4 *)(param_1 + 0xdc) = puVar2;
      local_8 = ~(uint)puVar2;
    }
  }
  return local_8;
}


// ==== FUN_008d8d00 @ 0x008d8d00 ====

undefined4 FUN_008d8d00(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (((((int)param_1 < 1) && ((param_1 & 0xffff) != param_1)) && (*(int *)(~param_1 + 0x10) == 4))
     && (uVar1 = *(uint *)(~param_1 + 0x14), uVar1 < *(uint *)(in_ECX + 0xd0))) {
    uVar2 = *(undefined4 *)(*(int *)(in_ECX + 0xd8) + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008d8d3c @ 0x008d8d3c ====

int FUN_008d8d3c(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)FUN_008d8d00(param_2,0);
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = -0x7789f794;
  }
  else {
    do {
      switch(*puVar1) {
      case 0:
        iVar2 = (**(code **)(*param_1 + 0x50))(param_1,puVar1[1],puVar1[3],puVar1[2]);
        break;
      case 1:
        iVar2 = (**(code **)(*param_1 + 0x58))(param_1,puVar1[1],puVar1[3]);
        break;
      case 2:
        iVar2 = (**(code **)(*param_1 + 0x60))(param_1,puVar1[1],puVar1[3],puVar1[2]);
        break;
      case 3:
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1,puVar1[1],puVar1[3]);
        break;
      case 4:
        iVar2 = (**(code **)(*param_1 + 0x70))(param_1,puVar1[1],puVar1[3],puVar1[2]);
        break;
      case 5:
        iVar2 = (**(code **)(*param_1 + 0x78))(param_1,puVar1[1],puVar1[3]);
        break;
      case 6:
        iVar2 = (**(code **)(*param_1 + 0x80))(param_1,puVar1[1],puVar1[3],puVar1[2]);
        break;
      case 7:
        iVar2 = (**(code **)(*param_1 + 0x88))(param_1,puVar1[1],puVar1[3]);
        break;
      case 8:
        iVar2 = (**(code **)(*param_1 + 0x90))(param_1,puVar1[1],puVar1[3],puVar1[2]);
        break;
      case 9:
        iVar2 = (**(code **)(*param_1 + 0x98))(param_1,puVar1[1],puVar1[3]);
        break;
      case 10:
        iVar2 = (**(code **)(*param_1 + 0xa0))(param_1,puVar1[1],puVar1[3],puVar1[2]);
        break;
      case 0xb:
        if (*(int *)(puVar1[5] + 4) == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = (**(code **)(**(int **)(puVar1[5] + 4) + 0xc))(*(int **)(puVar1[5] + 4));
        }
        iVar2 = (**(code **)(*param_1 + 200))(param_1,puVar1[1],uVar3);
        break;
      case 0xc:
        iVar2 = (**(code **)(*param_1 + 0xd0))(param_1,puVar1[1],*(undefined4 *)(puVar1[5] + 4));
        break;
      case 0xd:
        iVar2 = (**(code **)(*param_1 + 0xd8))(param_1,puVar1[1],*(undefined4 *)(puVar1[5] + 4));
        break;
      case 0xe:
        iVar2 = (**(code **)(*param_1 + 0xe0))(param_1,puVar1[1],*(undefined4 *)(puVar1[5] + 4));
        break;
      default:
        iVar2 = -0x7fffbffb;
      }
    } while ((-1 < iVar2) && (puVar1 = (undefined4 *)puVar1[6], puVar1 != (undefined4 *)0x0));
  }
  return iVar2;
}


// ==== FUN_008d8f08 @ 0x008d8f08 ====

void FUN_008d8f08(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 3;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[3] = 0;
  in_ECX[6] = 0;
  return;
}


// ==== FUN_008d8f1f @ 0x008d8f1f ====

int FUN_008d8f1f(int *param_1,int *param_2,int *param_3,int *param_4,int param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  int *local_10;
  int local_c;
  int local_8;
  
  piVar5 = param_1;
  piVar2 = (int *)*param_1;
  local_10 = (int *)0x0;
  local_8 = piVar2[4];
  iVar3 = piVar2[1];
  iVar4 = *piVar2;
  local_c = 0;
  if ((param_5 != 0) || (local_8 == 0)) {
    local_8 = 1;
  }
  if (-1 < iVar3) {
    if (iVar3 < 4) {
      if (((iVar4 != 1) && (iVar4 != 2)) && (iVar4 != 3)) {
        return -0x7fffbffb;
      }
      *param_2 = *param_2 + piVar2[6] * piVar2[5] * local_8 * 4;
      *param_1 = *param_1 + 0x1c;
      goto LAB_008d918c;
    }
    if (iVar3 == 4) {
      if (iVar4 == 4) {
        for (; local_10 = (int *)0x0, local_8 != 0; local_8 = local_8 + -1) {
          local_10 = (int *)0x0;
          if (*param_3 != 0) {
            pcVar9 = *(char **)*param_2;
            if (pcVar9 != (char *)0x0) {
              pcVar6 = pcVar9;
              do {
                cVar1 = *pcVar6;
                pcVar6 = pcVar6 + 1;
              } while (cVar1 != '\0');
              pcVar6 = pcVar6 + (1 - (int)(pcVar9 + 1));
              local_c = FUN_008eb3df(pcVar6,&local_10);
              if (local_c < 0) {
                return local_c;
              }
              pcVar7 = (char *)(**(code **)(*local_10 + 0xc))(local_10);
              for (uVar8 = (uint)pcVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined4 *)pcVar7 = *(undefined4 *)pcVar9;
                pcVar9 = pcVar9 + 4;
                pcVar7 = pcVar7 + 4;
              }
              for (uVar8 = (uint)pcVar6 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *pcVar7 = *pcVar9;
                pcVar9 = pcVar9 + 1;
                pcVar7 = pcVar7 + 1;
              }
            }
            *(undefined4 *)*param_3 = 4;
            *(int **)(*param_3 + 4) = local_10;
            *param_3 = *param_3 + 8;
          }
          if (param_4 != (int *)0x0) {
            *param_4 = *param_4 + 1;
          }
          *param_2 = *param_2 + 4;
        }
      }
      else {
        if (iVar4 < 5) {
          return -0x7fffbffb;
        }
        param_5 = local_8;
        if (iVar4 < 10) {
          if (local_8 != 0) {
            do {
              if (*param_3 != 0) {
                piVar2 = *(int **)*param_2;
                if (piVar2 != (int *)0x0) {
                  (**(code **)(*piVar2 + 4))(piVar2);
                }
                *(undefined4 *)*param_3 = 5;
                *(int **)(*param_3 + 4) = piVar2;
                *param_3 = *param_3 + 8;
              }
              if (param_4 != (int *)0x0) {
                *param_4 = *param_4 + 1;
              }
              *param_2 = *param_2 + 4;
              param_5 = param_5 + -1;
            } while (param_5 != 0);
          }
        }
        else if (iVar4 == 0xf) {
          if (local_8 != 0) {
            do {
              if (*param_3 != 0) {
                piVar2 = *(int **)*param_2;
                if (piVar2 != (int *)0x0) {
                  (**(code **)(*piVar2 + 4))(piVar2);
                }
                *(undefined4 *)*param_3 = 0xf;
                *(int **)(*param_3 + 4) = piVar2;
                *param_3 = *param_3 + 8;
              }
              if (param_4 != (int *)0x0) {
                *param_4 = *param_4 + 1;
              }
              *param_2 = *param_2 + 4;
              param_5 = param_5 + -1;
            } while (param_5 != 0);
          }
        }
        else {
          if (iVar4 != 0x10) {
            return -0x7fffbffb;
          }
          if (local_8 != 0) {
            do {
              if (*param_3 != 0) {
                piVar2 = *(int **)*param_2;
                if (piVar2 != (int *)0x0) {
                  (**(code **)(*piVar2 + 4))(piVar2);
                }
                *(undefined4 *)*param_3 = 0x10;
                *(int **)(*param_3 + 4) = piVar2;
                *param_3 = *param_3 + 8;
              }
              if (param_4 != (int *)0x0) {
                *param_4 = *param_4 + 1;
              }
              *param_2 = *param_2 + 4;
              param_5 = param_5 + -1;
            } while (param_5 != 0);
          }
        }
      }
      *param_1 = *param_1 + 0x14;
      goto LAB_008d918c;
    }
    if (iVar3 == 5) {
      uVar8 = piVar2[5];
      *param_1 = (int)(piVar2 + 6);
      if (local_8 == 0) {
        return 0;
      }
      do {
        param_1 = (int *)0x0;
        *piVar5 = (int)(piVar2 + 6);
        if (uVar8 != 0) {
          do {
            local_c = FUN_008d8f1f(piVar5,param_2,param_3,param_4,0);
            if (local_c < 0) goto LAB_008d918c;
            param_1 = (int *)((int)param_1 + 1);
          } while (param_1 < uVar8);
        }
        local_8 = local_8 + -1;
      } while (local_8 != 0);
      goto LAB_008d918c;
    }
  }
  local_c = -0x7fffbffb;
LAB_008d918c:
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  return local_c;
}


// ==== FUN_008d91a3 @ 0x008d91a3 ====

void FUN_008d91a3(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_008d8f1f(&param_1,&param_2,&param_3,param_4,param_5);
  return;
}


// ==== FUN_008d91d0 @ 0x008d91d0 ====

void FUN_008d91d0(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  if (((iVar1 == 4) || ((4 < iVar1 && (((iVar1 < 10 || (iVar1 == 0xf)) || (iVar1 == 0x10)))))) &&
     (piVar2 = (int *)in_ECX[1], piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 8))(piVar2);
    in_ECX[1] = 0;
  }
  return;
}


// ==== FUN_008d9200 @ 0x008d9200 ====

void FUN_008d9200(int *param_1,int *param_2,int *param_3,int param_4,uint param_5,ushort *param_6,
                 uint param_7)

{
  float *pfVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  float *pfVar9;
  uint uVar10;
  float *pfVar11;
  float *pfVar12;
  uint uVar13;
  int iVar14;
  undefined4 *puVar15;
  int iVar16;
  undefined4 *puVar17;
  int local_10;
  uint local_c;
  uint local_8;
  
  piVar2 = param_3;
  piVar5 = param_2;
  if (param_4 == 0) {
    uVar10 = *(uint *)(*param_1 + 4);
    puVar7 = param_6;
  }
  else {
    uVar10 = (uint)*(ushort *)(param_5 + param_4);
    puVar7 = (ushort *)(param_5 + param_4);
  }
  if (param_7 == 0xffffffff) {
    param_5 = *(uint *)(*param_1 + 0x10);
    if (param_5 == 0) {
      param_5 = 1;
    }
  }
  else {
    param_5 = param_7;
  }
  if ((int)uVar10 < 0) {
    return;
  }
  if ((int)uVar10 < 2) {
LAB_008d9497:
    piVar5 = (int *)*param_1;
    iVar8 = piVar5[5];
    iVar14 = *piVar5;
    uVar6 = piVar5[6];
    param_7 = 0;
    if (uVar10 == 3) {
      param_7 = (4 - uVar6) * 4;
    }
    if (iVar14 == 1) {
      pfVar12 = (float *)*param_3;
      iVar14 = *(int *)param_6;
      pfVar9 = (float *)*param_2;
      local_8 = 0;
      if (param_5 != 0) {
        do {
          if (iVar14 == 0) break;
          local_c = 0;
          if (uVar6 != 0) {
            do {
              if (iVar14 == 0) break;
              if (iVar8 != 0) {
                iVar16 = iVar8;
                pfVar11 = pfVar12;
                do {
                  *pfVar11 = (float)*(int *)(((int)pfVar9 - (int)pfVar12) + (int)pfVar11);
                  pfVar11 = pfVar11 + 1;
                  iVar16 = iVar16 + -1;
                } while (iVar16 != 0);
              }
              pfVar12 = pfVar12 + 4;
              pfVar9 = pfVar9 + 4;
              iVar14 = iVar14 + -1;
              local_c = local_c + 1;
            } while (local_c < uVar6);
          }
          local_8 = local_8 + 1;
          pfVar9 = pfVar9 + param_7;
        } while (local_8 < param_5);
      }
    }
    else if (iVar14 == 2) {
      pfVar12 = (float *)*param_3;
      iVar14 = *(int *)param_6;
      pfVar9 = (float *)*param_2;
      local_8 = 0;
      if (param_5 != 0) {
        do {
          if (iVar14 == 0) break;
          local_c = 0;
          if (uVar6 != 0) {
            do {
              if (iVar14 == 0) break;
              if (iVar8 != 0) {
                iVar16 = iVar8;
                pfVar11 = pfVar12;
                do {
                  *pfVar11 = (float)*(int *)(((int)pfVar9 - (int)pfVar12) + (int)pfVar11);
                  pfVar11 = pfVar11 + 1;
                  iVar16 = iVar16 + -1;
                } while (iVar16 != 0);
              }
              pfVar12 = pfVar12 + 4;
              pfVar9 = pfVar9 + 4;
              iVar14 = iVar14 + -1;
              local_c = local_c + 1;
            } while (local_c < uVar6);
          }
          local_8 = local_8 + 1;
          pfVar9 = pfVar9 + param_7;
        } while (local_8 < param_5);
      }
    }
    else {
      if (iVar14 != 3) {
        return;
      }
      iVar14 = *(int *)param_6;
      pfVar12 = (float *)*param_3;
      pfVar9 = (float *)*param_2;
      param_3 = (int *)0x0;
      if (param_5 != 0) {
        do {
          if (iVar14 == 0) break;
          uVar10 = 0;
          pfVar11 = pfVar12;
          if (uVar6 != 0) {
            do {
              pfVar12 = pfVar11;
              if (iVar14 == 0) break;
              *pfVar11 = *pfVar9;
              pfVar11[1] = pfVar9[1];
              pfVar11[2] = pfVar9[2];
              pfVar1 = pfVar9 + 3;
              pfVar12 = pfVar11 + 4;
              pfVar9 = pfVar9 + 4;
              pfVar11[3] = *pfVar1;
              iVar14 = iVar14 + -1;
              uVar10 = uVar10 + 1;
              pfVar11 = pfVar12;
            } while (uVar10 < uVar6);
          }
          param_3 = (int *)((int)param_3 + 1);
          pfVar9 = pfVar9 + param_7;
        } while (param_3 < param_5);
      }
    }
    *piVar2 = (int)pfVar12;
    *(int *)param_6 = iVar14;
    *param_2 = (int)pfVar9;
    *param_1 = *param_1 + 0x1c;
    return;
  }
  if (uVar10 != 2) {
    if (uVar10 != 3) {
      if (uVar10 != 5) {
        return;
      }
      local_c = 0;
      if (param_4 != 0) {
        local_10 = *(int *)(puVar7 + 6) + param_4;
      }
      local_8 = 0;
      uVar10 = *(uint *)(*param_1 + 0x14);
      iVar8 = *param_1 + 0x18;
      *param_1 = iVar8;
      if (param_5 == 0) {
        return;
      }
      do {
        if (*(int *)param_6 == 0) {
          return;
        }
        param_7 = 0;
        *param_1 = iVar8;
        if (uVar10 != 0) {
          puVar15 = (undefined4 *)(local_10 + 4);
          do {
            if (*(int *)param_6 == 0) break;
            if (param_4 != 0) {
              local_c = *puVar15;
            }
            FUN_008d9200(param_1,param_2,param_3,param_4,local_c,param_6,0xffffffff);
            param_7 = param_7 + 1;
            puVar15 = puVar15 + 2;
          } while (param_7 < uVar10);
        }
        local_8 = local_8 + 1;
        if (param_5 <= local_8) {
          return;
        }
      } while( true );
    }
    goto LAB_008d9497;
  }
  piVar4 = (int *)*param_1;
  uVar10 = piVar4[5];
  uVar6 = piVar4[6];
  iVar8 = *piVar4;
  if (iVar8 == 1) {
    iVar8 = *(int *)param_6;
    param_2 = (int *)*param_2;
    local_c = 0;
    iVar14 = *param_3;
    if (param_5 != 0) {
      do {
        if (iVar8 == 0) break;
        local_8 = 0;
        if (uVar10 != 0) {
          do {
            uVar13 = 0;
            if (iVar8 == 0) break;
            if (uVar6 != 0) {
              iVar16 = local_8 << 2;
              do {
                piVar2 = (int *)(iVar16 + *piVar5);
                iVar16 = iVar16 + 0x10;
                *(float *)(iVar14 + uVar13 * 4) = (float)*piVar2;
                uVar13 = uVar13 + 1;
              } while (uVar13 < uVar6);
            }
            iVar14 = iVar14 + 0x10;
            iVar8 = iVar8 + -1;
            local_8 = local_8 + 1;
          } while (local_8 < uVar10);
        }
        param_2 = (int *)((int)param_2 + 0x40);
        local_c = local_c + 1;
      } while (local_c < param_5);
    }
  }
  else {
    if (iVar8 != 2) {
      if (iVar8 != 3) {
        return;
      }
      local_c = 0;
      iVar8 = *param_3;
      iVar14 = *(int *)param_6;
      puVar15 = (undefined4 *)*param_2;
      if (param_5 != 0) {
        do {
          if (iVar14 == 0) break;
          local_8 = 0;
          if (uVar10 != 0) {
            param_3 = puVar15;
            do {
              if (iVar14 == 0) break;
              uVar13 = 0;
              if (uVar6 != 0) {
                puVar17 = param_3;
                do {
                  uVar3 = *puVar17;
                  puVar17 = puVar17 + 4;
                  *(undefined4 *)(iVar8 + uVar13 * 4) = uVar3;
                  uVar13 = uVar13 + 1;
                } while (uVar13 < uVar6);
              }
              param_3 = param_3 + 1;
              iVar8 = iVar8 + 0x10;
              iVar14 = iVar14 + -1;
              local_8 = local_8 + 1;
            } while (local_8 < uVar10);
          }
          puVar15 = puVar15 + 0x10;
          local_c = local_c + 1;
        } while (local_c < param_5);
      }
      *piVar2 = iVar8;
      *(int *)param_6 = iVar14;
      *param_2 = (int)puVar15;
      goto LAB_008d948f;
    }
    iVar8 = *(int *)param_6;
    param_2 = (int *)*param_2;
    local_c = 0;
    iVar14 = *param_3;
    if (param_5 != 0) {
      do {
        if (iVar8 == 0) break;
        local_8 = 0;
        if (uVar10 != 0) {
          do {
            uVar13 = 0;
            if (iVar8 == 0) break;
            if (uVar6 != 0) {
              iVar16 = local_8 << 2;
              do {
                piVar2 = (int *)(iVar16 + *piVar5);
                iVar16 = iVar16 + 0x10;
                *(float *)(iVar14 + uVar13 * 4) = (float)*piVar2;
                uVar13 = uVar13 + 1;
              } while (uVar13 < uVar6);
            }
            iVar14 = iVar14 + 0x10;
            iVar8 = iVar8 + -1;
            local_8 = local_8 + 1;
          } while (local_8 < uVar10);
        }
        param_2 = (int *)((int)param_2 + 0x40);
        local_c = local_c + 1;
      } while (local_c < param_5);
    }
  }
  *param_3 = iVar14;
  *(int *)param_6 = iVar8;
  *piVar5 = (int)param_2;
LAB_008d948f:
  *param_1 = *param_1 + 0x1c;
  return;
}


// ==== FUN_008d9627 @ 0x008d9627 ====

void FUN_008d9627(int *param_1,int *param_2,int *param_3,int param_4,uint param_5,ushort *param_6,
                 uint param_7)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  ushort *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_8;
  
  piVar2 = param_2;
  if (param_4 == 0) {
    uVar6 = *(uint *)(*param_1 + 4);
    puVar4 = param_6;
  }
  else {
    uVar6 = (uint)*(ushort *)(param_5 + param_4);
    puVar4 = (ushort *)(param_5 + param_4);
  }
  if (param_7 == 0xffffffff) {
    param_5 = *(uint *)(*param_1 + 0x10);
    if (param_5 == 0) {
      param_5 = 1;
    }
  }
  else {
    param_5 = param_7;
  }
  if ((int)uVar6 < 0) {
    return;
  }
  if (1 < (int)uVar6) {
    if (uVar6 == 2) {
      piVar1 = (int *)*param_1;
      uVar6 = piVar1[5];
      uVar3 = piVar1[6];
      iVar11 = *piVar1;
      if (iVar11 == 1) {
        iVar11 = *(int *)param_6;
        param_4 = *param_2;
        local_18 = 0;
        iVar10 = *param_3;
        if (param_5 != 0) {
          do {
            if (iVar11 == 0) break;
            param_2 = (int *)0x0;
            if (uVar6 != 0) {
              do {
                if (iVar11 == 0) break;
                uVar9 = 0;
                if (uVar3 != 0) {
                  iVar7 = (int)param_2 << 2;
                  do {
                    *(undefined4 *)(iVar10 + uVar9 * 4) = *(undefined4 *)(iVar7 + *piVar2);
                    uVar9 = uVar9 + 1;
                    iVar7 = iVar7 + 0x10;
                  } while (uVar9 < uVar3);
                }
                iVar10 = iVar10 + 0x10;
                iVar11 = iVar11 + -1;
                param_2 = (int *)((int)param_2 + 1);
              } while (param_2 < uVar6);
            }
            param_4 = param_4 + 0x40;
            local_18 = local_18 + 1;
          } while (local_18 < param_5);
        }
      }
      else {
        if (iVar11 != 2) {
          if (iVar11 != 3) {
            return;
          }
          iVar11 = *param_3;
          iVar10 = *(int *)param_6;
          param_4 = *param_2;
          local_18 = 0;
          if (param_5 != 0) {
            do {
              if (iVar10 == 0) break;
              local_14 = 0;
              if (uVar6 != 0) {
                do {
                  if (iVar10 == 0) break;
                  uVar9 = 0;
                  if (uVar3 != 0) {
                    do {
                      uVar5 = __ftol();
                      *(undefined4 *)(iVar11 + uVar9 * 4) = uVar5;
                      uVar9 = uVar9 + 1;
                    } while (uVar9 < uVar3);
                  }
                  iVar11 = iVar11 + 0x10;
                  iVar10 = iVar10 + -1;
                  local_14 = local_14 + 1;
                } while (local_14 < uVar6);
              }
              param_4 = param_4 + 0x40;
              local_18 = local_18 + 1;
            } while (local_18 < param_5);
          }
          *param_3 = iVar11;
          *(int *)param_6 = iVar10;
          goto LAB_008d98ca;
        }
        iVar11 = *(int *)param_6;
        param_4 = *param_2;
        local_18 = 0;
        iVar10 = *param_3;
        if (param_5 != 0) {
          do {
            if (iVar11 == 0) break;
            param_2 = (int *)0x0;
            if (uVar6 != 0) {
              do {
                if (iVar11 == 0) break;
                uVar9 = 0;
                if (uVar3 != 0) {
                  iVar7 = (int)param_2 << 2;
                  do {
                    *(undefined4 *)(iVar10 + uVar9 * 4) = *(undefined4 *)(iVar7 + *piVar2);
                    uVar9 = uVar9 + 1;
                    iVar7 = iVar7 + 0x10;
                  } while (uVar9 < uVar3);
                }
                iVar10 = iVar10 + 0x10;
                iVar11 = iVar11 + -1;
                param_2 = (int *)((int)param_2 + 1);
              } while (param_2 < uVar6);
            }
            param_4 = param_4 + 0x40;
            local_18 = local_18 + 1;
          } while (local_18 < param_5);
        }
      }
      *param_3 = iVar10;
      *(int *)param_6 = iVar11;
LAB_008d98ca:
      *piVar2 = param_4;
      *param_1 = *param_1 + 0x1c;
      return;
    }
    if (uVar6 != 3) {
      if (uVar6 != 5) {
        return;
      }
      local_18 = 0;
      if (param_4 != 0) {
        local_14 = *(int *)(puVar4 + 6) + param_4;
      }
      local_8 = 0;
      uVar6 = *(uint *)(*param_1 + 0x14);
      iVar11 = *param_1 + 0x18;
      *param_1 = iVar11;
      if (param_5 == 0) {
        return;
      }
      do {
        if (*(int *)param_6 == 0) {
          return;
        }
        param_7 = 0;
        *param_1 = iVar11;
        if (uVar6 != 0) {
          puVar8 = (undefined4 *)(local_14 + 4);
          do {
            if (*(int *)param_6 == 0) break;
            if (param_4 != 0) {
              local_18 = *puVar8;
            }
            FUN_008d9627(param_1,param_2,param_3,param_4,local_18,param_6,0xffffffff);
            param_7 = param_7 + 1;
            puVar8 = puVar8 + 2;
          } while (param_7 < uVar6);
        }
        local_8 = local_8 + 1;
        if (param_5 <= local_8) {
          return;
        }
      } while( true );
    }
  }
  piVar2 = (int *)*param_1;
  iVar11 = piVar2[5];
  iVar10 = *piVar2;
  uVar3 = piVar2[6];
  param_7 = 0;
  if (uVar6 == 3) {
    param_7 = (4 - uVar3) * 4;
  }
  if (iVar10 == 1) {
    puVar8 = (undefined4 *)*param_3;
    iVar7 = *(int *)param_6;
    local_14 = 0;
    iVar10 = *param_2;
    if (param_5 != 0) {
      do {
        if (iVar7 == 0) break;
        local_18 = 0;
        if (uVar3 != 0) {
          do {
            if (iVar7 == 0) break;
            if (iVar11 != 0) {
              puVar12 = puVar8;
              local_10 = iVar11;
              do {
                *puVar12 = *(undefined4 *)((iVar10 - (int)puVar8) + (int)puVar12);
                puVar12 = puVar12 + 1;
                local_10 = local_10 + -1;
              } while (local_10 != 0);
            }
            puVar8 = puVar8 + 4;
            iVar10 = iVar10 + 0x10;
            iVar7 = iVar7 + -1;
            local_18 = local_18 + 1;
          } while (local_18 < uVar3);
        }
        local_14 = local_14 + 1;
        iVar10 = iVar10 + param_7 * 4;
      } while (local_14 < param_5);
    }
  }
  else {
    if (iVar10 != 2) {
      if (iVar10 != 3) {
        return;
      }
      puVar8 = (undefined4 *)*param_3;
      iVar10 = *(int *)param_6;
      local_14 = 0;
      iVar11 = *param_2;
      if (param_5 != 0) {
        do {
          if (iVar10 == 0) break;
          local_18 = 0;
          if (uVar3 != 0) {
            do {
              if (iVar10 == 0) break;
              uVar5 = __ftol();
              *puVar8 = uVar5;
              uVar5 = __ftol();
              puVar8[1] = uVar5;
              uVar5 = __ftol();
              puVar8[2] = uVar5;
              uVar5 = __ftol();
              puVar8[3] = uVar5;
              puVar8 = puVar8 + 4;
              iVar11 = iVar11 + 0x10;
              iVar10 = iVar10 + -1;
              local_18 = local_18 + 1;
            } while (local_18 < uVar3);
          }
          local_14 = local_14 + 1;
          iVar11 = iVar11 + param_7 * 4;
        } while (local_14 < param_5);
      }
      *param_3 = (int)puVar8;
      *(int *)param_6 = iVar10;
      *param_2 = iVar11;
      goto LAB_008d9a8c;
    }
    puVar8 = (undefined4 *)*param_3;
    iVar7 = *(int *)param_6;
    local_14 = 0;
    iVar10 = *param_2;
    if (param_5 != 0) {
      do {
        if (iVar7 == 0) break;
        local_18 = 0;
        if (uVar3 != 0) {
          do {
            if (iVar7 == 0) break;
            if (iVar11 != 0) {
              puVar12 = puVar8;
              local_10 = iVar11;
              do {
                *puVar12 = *(undefined4 *)((iVar10 - (int)puVar8) + (int)puVar12);
                puVar12 = puVar12 + 1;
                local_10 = local_10 + -1;
              } while (local_10 != 0);
            }
            puVar8 = puVar8 + 4;
            iVar10 = iVar10 + 0x10;
            iVar7 = iVar7 + -1;
            local_18 = local_18 + 1;
          } while (local_18 < uVar3);
        }
        local_14 = local_14 + 1;
        iVar10 = iVar10 + param_7 * 4;
      } while (local_14 < param_5);
    }
  }
  *param_3 = (int)puVar8;
  *(int *)param_6 = iVar7;
  *param_2 = iVar10;
LAB_008d9a8c:
  *param_1 = *param_1 + 0x1c;
  return;
}


// ==== FUN_008d9a99 @ 0x008d9a99 ====

void FUN_008d9a99(int *param_1,int *param_2,int *param_3,int param_4,uint param_5,ushort *param_6,
                 uint param_7)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  ushort *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint local_10;
  uint local_c;
  uint local_8;
  
  piVar2 = param_3;
  piVar1 = param_2;
  if (param_4 == 0) {
    uVar4 = *(uint *)(*param_1 + 4);
    puVar6 = param_6;
  }
  else {
    uVar4 = (uint)*(ushort *)(param_4 + param_5);
    puVar6 = (ushort *)(param_4 + param_5);
  }
  if (param_7 == 0xffffffff) {
    param_5 = *(uint *)(*param_1 + 0x10);
    if (param_5 == 0) {
      param_5 = 1;
    }
  }
  else {
    param_5 = param_7;
  }
  if ((int)uVar4 < 0) {
    return;
  }
  if (1 < (int)uVar4) {
    if (uVar4 == 2) {
      uVar4 = ((int *)*param_1)[5];
      iVar9 = *(int *)*param_1;
      if (iVar9 == 1) {
        iVar9 = *(int *)param_6;
        param_2 = (int *)0x0;
        puVar7 = (undefined4 *)*param_3;
        iVar8 = *piVar1;
        if (param_5 != 0) {
          do {
            if (iVar9 == 0) break;
            uVar10 = 0;
            if (uVar4 != 0) {
              do {
                if (iVar9 == 0) break;
                *puVar7 = *(undefined4 *)(*piVar1 + uVar10 * 4);
                puVar7 = puVar7 + 1;
                iVar9 = iVar9 + -1;
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar4);
            }
            iVar8 = iVar8 + 0x40;
            param_2 = (int *)((int)param_2 + 1);
          } while (param_2 < param_5);
        }
      }
      else {
        if (iVar9 != 2) {
          if (iVar9 != 3) {
            return;
          }
          puVar7 = (undefined4 *)*param_3;
          iVar9 = *(int *)param_6;
          local_8 = 0;
          iVar8 = *param_2;
          if (param_5 != 0) {
            do {
              if (iVar9 == 0) break;
              param_7 = 0;
              if (uVar4 != 0) {
                do {
                  if (iVar9 == 0) break;
                  uVar3 = __ftol();
                  *puVar7 = uVar3;
                  puVar7 = puVar7 + 1;
                  iVar9 = iVar9 + -1;
                  param_7 = param_7 + 1;
                } while (param_7 < uVar4);
              }
              iVar8 = iVar8 + 0x40;
              local_8 = local_8 + 1;
            } while (local_8 < param_5);
          }
          *param_3 = (int)puVar7;
          *(int *)param_6 = iVar9;
          *param_2 = iVar8;
          goto LAB_008d9cbe;
        }
        iVar9 = *(int *)param_6;
        param_2 = (int *)0x0;
        puVar7 = (undefined4 *)*param_3;
        iVar8 = *piVar1;
        if (param_5 != 0) {
          do {
            if (iVar9 == 0) break;
            uVar10 = 0;
            if (uVar4 != 0) {
              do {
                if (iVar9 == 0) break;
                *puVar7 = *(undefined4 *)(*piVar1 + uVar10 * 4);
                puVar7 = puVar7 + 1;
                iVar9 = iVar9 + -1;
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar4);
            }
            iVar8 = iVar8 + 0x40;
            param_2 = (int *)((int)param_2 + 1);
          } while (param_2 < param_5);
        }
      }
      *param_3 = (int)puVar7;
      *(int *)param_6 = iVar9;
      *piVar1 = iVar8;
LAB_008d9cbe:
      *param_1 = *param_1 + 0x1c;
      return;
    }
    if (uVar4 != 3) {
      if (uVar4 != 5) {
        return;
      }
      local_10 = 0;
      if (param_4 != 0) {
        local_c = *(int *)(puVar6 + 6) + param_4;
      }
      local_8 = 0;
      uVar4 = *(uint *)(*param_1 + 0x14);
      iVar9 = *param_1 + 0x18;
      *param_1 = iVar9;
      if (param_5 == 0) {
        return;
      }
      do {
        if (*(int *)param_6 == 0) {
          return;
        }
        param_7 = 0;
        *param_1 = iVar9;
        if (uVar4 != 0) {
          puVar7 = (undefined4 *)(local_c + 4);
          do {
            if (*(int *)param_6 == 0) break;
            if (param_4 != 0) {
              local_10 = *puVar7;
            }
            FUN_008d9a99(param_1,param_2,param_3,param_4,local_10,param_6,0xffffffff);
            param_7 = param_7 + 1;
            puVar7 = puVar7 + 2;
          } while (param_7 < uVar4);
        }
        local_8 = local_8 + 1;
        if (param_5 <= local_8) {
          return;
        }
      } while( true );
    }
  }
  uVar10 = ((int *)*param_1)[6];
  iVar9 = *(int *)*param_1;
  local_8 = 0;
  if (uVar4 == 3) {
    local_8 = (4 - uVar10) * 4;
  }
  if (iVar9 == 1) {
    iVar9 = *(int *)param_6;
    puVar5 = (undefined4 *)*param_3;
    puVar7 = (undefined4 *)*param_2;
    param_3 = (int *)0x0;
    if (param_5 != 0) {
      do {
        if (iVar9 == 0) break;
        uVar4 = 0;
        if (uVar10 != 0) {
          do {
            if (iVar9 == 0) break;
            uVar3 = *puVar7;
            puVar7 = puVar7 + 4;
            *puVar5 = uVar3;
            puVar5 = puVar5 + 1;
            iVar9 = iVar9 + -1;
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar10);
        }
        param_3 = (int *)((int)param_3 + 1);
        puVar7 = puVar7 + local_8;
      } while (param_3 < param_5);
    }
  }
  else {
    if (iVar9 != 2) {
      if (iVar9 != 3) {
        return;
      }
      puVar7 = (undefined4 *)*param_3;
      param_7 = *(uint *)param_6;
      iVar9 = *param_2;
      local_10 = 0;
      if (param_5 != 0) {
        do {
          if (param_7 == 0) break;
          local_c = 0;
          puVar5 = puVar7;
          if (uVar10 != 0) {
            do {
              puVar7 = puVar5;
              if (param_7 == 0) break;
              uVar3 = __ftol();
              *puVar5 = uVar3;
              puVar7 = puVar5 + 1;
              uVar3 = __ftol();
              *puVar7 = uVar3;
              uVar3 = __ftol();
              puVar5[2] = uVar3;
              uVar3 = __ftol();
              iVar9 = iVar9 + 0x10;
              param_7 = param_7 + -1;
              local_c = local_c + 1;
              puVar5[3] = uVar3;
              puVar5 = puVar7;
            } while (local_c < uVar10);
          }
          local_10 = local_10 + 1;
          iVar9 = iVar9 + local_8 * 4;
        } while (local_10 < param_5);
      }
      *param_3 = (int)puVar7;
      *(uint *)param_6 = param_7;
      *param_2 = iVar9;
      goto LAB_008d9e3b;
    }
    iVar9 = *(int *)param_6;
    puVar5 = (undefined4 *)*param_3;
    puVar7 = (undefined4 *)*param_2;
    param_3 = (int *)0x0;
    if (param_5 != 0) {
      do {
        if (iVar9 == 0) break;
        uVar4 = 0;
        if (uVar10 != 0) {
          do {
            if (iVar9 == 0) break;
            uVar3 = *puVar7;
            puVar7 = puVar7 + 4;
            *puVar5 = uVar3;
            puVar5 = puVar5 + 1;
            iVar9 = iVar9 + -1;
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar10);
        }
        param_3 = (int *)((int)param_3 + 1);
        puVar7 = puVar7 + local_8;
      } while (param_3 < param_5);
    }
  }
  *piVar2 = (int)puVar5;
  *(int *)param_6 = iVar9;
  *param_2 = (int)puVar7;
LAB_008d9e3b:
  *param_1 = *param_1 + 0x1c;
  return;
}


// ==== FUN_008d9e45 @ 0x008d9e45 ====

void FUN_008d9e45(int *param_1,int *param_2,float *param_3,int param_4,uint param_5,ushort *param_6,
                 uint param_7)

{
  int *piVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  ushort *puVar6;
  float *pfVar7;
  float *pfVar8;
  uint uVar9;
  double *pdVar10;
  double *pdVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  undefined4 *puVar15;
  uint uVar16;
  int iVar17;
  int local_10;
  uint local_c;
  uint local_8;
  
  piVar1 = (int *)param_3;
  piVar4 = param_2;
  if (param_4 == 0) {
    uVar9 = *(uint *)(*param_1 + 4);
    puVar6 = param_6;
  }
  else {
    uVar9 = (uint)*(ushort *)(param_5 + param_4);
    puVar6 = (ushort *)(param_5 + param_4);
  }
  if (param_7 == 0xffffffff) {
    param_5 = *(uint *)(*param_1 + 0x10);
    if (param_5 == 0) {
      param_5 = 1;
    }
  }
  else {
    param_5 = param_7;
  }
  if ((int)uVar9 < 0) {
    return;
  }
  if (1 < (int)uVar9) {
    if (uVar9 == 2) {
      piVar3 = (int *)*param_1;
      uVar9 = piVar3[5];
      uVar5 = piVar3[6];
      iVar14 = *piVar3;
      if (iVar14 == 1) {
        iVar14 = *(int *)param_6;
        param_2 = (int *)*param_2;
        local_c = 0;
        iVar12 = (int)*param_3;
        if (param_5 != 0) {
          do {
            if (iVar14 == 0) break;
            local_8 = 0;
            if (uVar9 != 0) {
              do {
                uVar13 = 0;
                if (iVar14 == 0) break;
                if (uVar5 != 0) {
                  iVar17 = local_8 << 2;
                  do {
                    piVar1 = (int *)(iVar17 + *piVar4);
                    iVar17 = iVar17 + 0x10;
                    *(double *)(iVar12 + uVar13 * 8) = (double)*piVar1;
                    uVar13 = uVar13 + 1;
                  } while (uVar13 < uVar5);
                }
                iVar12 = iVar12 + 0x20;
                iVar14 = iVar14 + -1;
                local_8 = local_8 + 1;
              } while (local_8 < uVar9);
            }
            param_2 = (int *)((int)param_2 + 0x40);
            local_c = local_c + 1;
          } while (local_c < param_5);
        }
      }
      else {
        if (iVar14 != 2) {
          if (iVar14 != 3) {
            return;
          }
          local_c = 0;
          iVar14 = (int)*param_3;
          iVar12 = *(int *)param_6;
          pfVar8 = (float *)*param_2;
          if (param_5 != 0) {
            do {
              if (iVar12 == 0) break;
              local_8 = 0;
              if (uVar9 != 0) {
                param_3 = pfVar8;
                do {
                  if (iVar12 == 0) break;
                  uVar13 = 0;
                  if (uVar5 != 0) {
                    pfVar7 = param_3;
                    do {
                      fVar2 = *pfVar7;
                      pfVar7 = pfVar7 + 4;
                      *(double *)(iVar14 + uVar13 * 8) = (double)fVar2;
                      uVar13 = uVar13 + 1;
                    } while (uVar13 < uVar5);
                  }
                  param_3 = param_3 + 1;
                  iVar14 = iVar14 + 0x20;
                  iVar12 = iVar12 + -1;
                  local_8 = local_8 + 1;
                } while (local_8 < uVar9);
              }
              pfVar8 = pfVar8 + 0x10;
              local_c = local_c + 1;
            } while (local_c < param_5);
          }
          *piVar1 = iVar14;
          *(int *)param_6 = iVar12;
          *param_2 = (int)pfVar8;
          goto LAB_008da0d4;
        }
        iVar14 = *(int *)param_6;
        param_2 = (int *)*param_2;
        local_c = 0;
        iVar12 = (int)*param_3;
        if (param_5 != 0) {
          do {
            if (iVar14 == 0) break;
            local_8 = 0;
            if (uVar9 != 0) {
              do {
                uVar13 = 0;
                if (iVar14 == 0) break;
                if (uVar5 != 0) {
                  iVar17 = local_8 << 2;
                  do {
                    piVar1 = (int *)(iVar17 + *piVar4);
                    iVar17 = iVar17 + 0x10;
                    *(double *)(iVar12 + uVar13 * 8) = (double)*piVar1;
                    uVar13 = uVar13 + 1;
                  } while (uVar13 < uVar5);
                }
                iVar12 = iVar12 + 0x20;
                iVar14 = iVar14 + -1;
                local_8 = local_8 + 1;
              } while (local_8 < uVar9);
            }
            param_2 = (int *)((int)param_2 + 0x40);
            local_c = local_c + 1;
          } while (local_c < param_5);
        }
      }
      *param_3 = (float)iVar12;
      *(int *)param_6 = iVar14;
      *piVar4 = (int)param_2;
LAB_008da0d4:
      *param_1 = *param_1 + 0x1c;
      return;
    }
    if (uVar9 != 3) {
      if (uVar9 != 5) {
        return;
      }
      local_c = 0;
      if (param_4 != 0) {
        local_10 = *(int *)(puVar6 + 6) + param_4;
      }
      local_8 = 0;
      uVar9 = *(uint *)(*param_1 + 0x14);
      iVar14 = *param_1 + 0x18;
      *param_1 = iVar14;
      if (param_5 == 0) {
        return;
      }
      do {
        if (*(int *)param_6 == 0) {
          return;
        }
        param_7 = 0;
        *param_1 = iVar14;
        if (uVar9 != 0) {
          puVar15 = (undefined4 *)(local_10 + 4);
          do {
            if (*(int *)param_6 == 0) break;
            if (param_4 != 0) {
              local_c = *puVar15;
            }
            FUN_008d9e45(param_1,param_2,param_3,param_4,local_c,param_6,0xffffffff);
            param_7 = param_7 + 1;
            puVar15 = puVar15 + 2;
          } while (param_7 < uVar9);
        }
        local_8 = local_8 + 1;
        if (param_5 <= local_8) {
          return;
        }
      } while( true );
    }
  }
  piVar4 = (int *)*param_1;
  uVar5 = piVar4[5];
  iVar14 = *piVar4;
  uVar13 = piVar4[6];
  local_8 = 0;
  if (uVar9 == 3) {
    local_8 = (4 - uVar13) * 4;
  }
  if (iVar14 == 1) {
    iVar14 = *(int *)param_6;
    iVar12 = (int)*param_3;
    pfVar8 = (float *)*param_2;
    local_c = 0;
    if (param_5 != 0) {
      do {
        if (iVar14 == 0) break;
        param_3 = (float *)0x0;
        if (uVar13 != 0) {
          do {
            if (iVar14 == 0) break;
            uVar9 = 0;
            if (uVar5 != 0) {
              do {
                *(double *)(iVar12 + uVar9 * 8) = (double)(int)pfVar8[uVar9];
                uVar9 = uVar9 + 1;
              } while (uVar9 < uVar5);
            }
            iVar12 = iVar12 + 0x20;
            pfVar8 = pfVar8 + 4;
            iVar14 = iVar14 + -1;
            param_3 = (float *)((int)param_3 + 1);
          } while (param_3 < uVar13);
        }
        local_c = local_c + 1;
        pfVar8 = pfVar8 + local_8;
      } while (local_c < param_5);
    }
  }
  else {
    if (iVar14 != 2) {
      if (iVar14 != 3) {
        return;
      }
      iVar14 = *(int *)param_6;
      pdVar11 = (double *)*param_3;
      pfVar8 = (float *)*param_2;
      param_3 = (float *)0x0;
      if (param_5 != 0) {
        do {
          if (iVar14 == 0) break;
          uVar9 = 0;
          pfVar7 = pfVar8;
          pdVar10 = pdVar11;
          if (uVar13 != 0) {
            do {
              pfVar7 = pfVar8;
              pdVar11 = pdVar10;
              if (iVar14 == 0) break;
              pfVar7 = pfVar8 + 4;
              *pdVar10 = (double)*pfVar8;
              pdVar11 = pdVar10 + 4;
              iVar14 = iVar14 + -1;
              pdVar10[1] = (double)pfVar8[1];
              uVar9 = uVar9 + 1;
              pdVar10[2] = (double)pfVar8[2];
              pdVar10[3] = (double)pfVar8[3];
              pfVar8 = pfVar7;
              pdVar10 = pdVar11;
            } while (uVar9 < uVar13);
          }
          param_3 = (float *)((int)param_3 + 1);
          pfVar8 = pfVar7 + local_8;
        } while (param_3 < param_5);
      }
      *piVar1 = (int)pdVar11;
      goto LAB_008da238;
    }
    iVar14 = *(int *)param_6;
    iVar12 = (int)*param_3;
    pfVar8 = (float *)*param_2;
    param_3 = (float *)0x0;
    if (param_5 != 0) {
      do {
        if (iVar14 == 0) break;
        uVar9 = 0;
        if (uVar13 != 0) {
          do {
            if (iVar14 == 0) break;
            uVar16 = 0;
            if (uVar5 != 0) {
              do {
                *(double *)(iVar12 + uVar16 * 8) = (double)(int)pfVar8[uVar16];
                uVar16 = uVar16 + 1;
              } while (uVar16 < uVar5);
            }
            iVar12 = iVar12 + 0x20;
            pfVar8 = pfVar8 + 4;
            iVar14 = iVar14 + -1;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar13);
        }
        param_3 = (float *)((int)param_3 + 1);
        pfVar8 = pfVar8 + local_8;
      } while (param_3 < param_5);
    }
  }
  *piVar1 = iVar12;
LAB_008da238:
  *(int *)param_6 = iVar14;
  *param_2 = (int)pfVar8;
  *param_1 = *param_1 + 0x1c;
  return;
}


// ==== FUN_008da24f @ 0x008da24f ====

void FUN_008da24f(int *param_1,int *param_2,int *param_3,int param_4,uint param_5,ushort *param_6,
                 undefined4 *param_7)

{
  float fVar1;
  int *piVar2;
  int *piVar3;
  double *pdVar4;
  float *pfVar5;
  float *pfVar6;
  uint uVar7;
  double *pdVar8;
  ushort *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar3 = param_3;
  piVar2 = param_2;
  if (param_4 == 0) {
    uVar7 = *(uint *)(*param_1 + 4);
    puVar9 = param_6;
  }
  else {
    uVar7 = (uint)*(ushort *)(param_4 + param_5);
    puVar9 = (ushort *)(param_4 + param_5);
  }
  if (param_7 == (undefined4 *)0xffffffff) {
    param_5 = *(uint *)(*param_1 + 0x10);
    if (param_5 == 0) {
      param_5 = 1;
    }
  }
  else {
    param_5 = (uint)param_7;
  }
  if ((int)uVar7 < 0) {
    return;
  }
  if ((int)uVar7 < 2) {
LAB_008da453:
    uVar10 = ((int *)*param_1)[6];
    iVar13 = *(int *)*param_1;
    param_7 = (undefined4 *)0x0;
    if (uVar7 == 3) {
      param_7 = (undefined4 *)((4 - uVar10) * 4);
    }
    if (iVar13 == 1) {
      iVar13 = *(int *)param_6;
      pdVar4 = (double *)*param_3;
      pfVar5 = (float *)*param_2;
      param_3 = (int *)0x0;
      if (param_5 != 0) {
        do {
          if (iVar13 == 0) break;
          uVar7 = 0;
          if (uVar10 != 0) {
            do {
              if (iVar13 == 0) break;
              fVar1 = *pfVar5;
              pfVar5 = pfVar5 + 4;
              *pdVar4 = (double)(int)fVar1;
              pdVar4 = pdVar4 + 1;
              iVar13 = iVar13 + -1;
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar10);
          }
          param_3 = (int *)((int)param_3 + 1);
          pfVar5 = pfVar5 + (int)param_7;
        } while (param_3 < param_5);
      }
LAB_008da57c:
      *piVar3 = (int)pdVar4;
      goto LAB_008da57e;
    }
    if (iVar13 == 2) {
      iVar13 = *(int *)param_6;
      pdVar4 = (double *)*param_3;
      pfVar5 = (float *)*param_2;
      param_3 = (int *)0x0;
      if (param_5 != 0) {
        do {
          if (iVar13 == 0) break;
          uVar7 = 0;
          if (uVar10 != 0) {
            do {
              if (iVar13 == 0) break;
              fVar1 = *pfVar5;
              pfVar5 = pfVar5 + 4;
              *pdVar4 = (double)(int)fVar1;
              pdVar4 = pdVar4 + 1;
              iVar13 = iVar13 + -1;
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar10);
          }
          param_3 = (int *)((int)param_3 + 1);
          pfVar5 = pfVar5 + (int)param_7;
        } while (param_3 < param_5);
      }
      goto LAB_008da57c;
    }
    if (iVar13 != 3) {
      return;
    }
    iVar13 = *(int *)param_6;
    pdVar4 = (double *)*param_3;
    pfVar5 = (float *)*param_2;
    param_3 = (int *)0x0;
    if (param_5 != 0) {
      do {
        if (iVar13 == 0) break;
        uVar7 = 0;
        pfVar6 = pfVar5;
        pdVar8 = pdVar4;
        if (uVar10 != 0) {
          do {
            pfVar6 = pfVar5;
            pdVar4 = pdVar8;
            if (iVar13 == 0) break;
            pdVar4 = pdVar8 + 1;
            *pdVar8 = (double)*pfVar5;
            pfVar6 = pfVar5 + 4;
            iVar13 = iVar13 + -1;
            *pdVar4 = (double)pfVar5[1];
            uVar7 = uVar7 + 1;
            pdVar8[2] = (double)pfVar5[2];
            pdVar8[3] = (double)pfVar5[3];
            pfVar5 = pfVar6;
            pdVar8 = pdVar4;
          } while (uVar7 < uVar10);
        }
        param_3 = (int *)((int)param_3 + 1);
        pfVar5 = pfVar6 + (int)param_7;
      } while (param_3 < param_5);
    }
    *piVar3 = (int)pdVar4;
    *(int *)param_6 = iVar13;
  }
  else {
    if (uVar7 != 2) {
      if (uVar7 != 3) {
        if (uVar7 != 5) {
          return;
        }
        local_c = 0;
        if (param_4 != 0) {
          local_10 = *(int *)(puVar9 + 6) + param_4;
        }
        local_8 = 0;
        uVar7 = *(uint *)(*param_1 + 0x14);
        iVar13 = *param_1 + 0x18;
        *param_1 = iVar13;
        if (param_5 == 0) {
          return;
        }
        do {
          uVar10 = 0;
          if (*(int *)param_6 == 0) {
            return;
          }
          *param_1 = iVar13;
          if (uVar7 != 0) {
            param_7 = (undefined4 *)(local_10 + 4);
            do {
              if (*(int *)param_6 == 0) break;
              if (param_4 != 0) {
                local_c = *param_7;
              }
              FUN_008da24f(param_1,param_2,param_3,param_4,local_c,param_6,0xffffffff);
              param_7 = param_7 + 2;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar7);
          }
          local_8 = local_8 + 1;
          if (param_5 <= local_8) {
            return;
          }
        } while( true );
      }
      goto LAB_008da453;
    }
    uVar7 = ((int *)*param_1)[5];
    iVar13 = *(int *)*param_1;
    if (iVar13 == 1) {
      iVar13 = *(int *)param_6;
      param_2 = (int *)0x0;
      pdVar4 = (double *)*param_3;
      iVar12 = *piVar2;
      if (param_5 != 0) {
        do {
          if (iVar13 == 0) break;
          uVar10 = 0;
          if (uVar7 != 0) {
            do {
              if (iVar13 == 0) break;
              *pdVar4 = (double)*(int *)(*piVar2 + uVar10 * 4);
              pdVar4 = pdVar4 + 1;
              iVar13 = iVar13 + -1;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar7);
          }
          iVar12 = iVar12 + 0x40;
          param_2 = (int *)((int)param_2 + 1);
        } while (param_2 < param_5);
      }
LAB_008da442:
      *param_3 = (int)pdVar4;
      *(int *)param_6 = iVar13;
      *piVar2 = iVar12;
      goto LAB_008da588;
    }
    if (iVar13 == 2) {
      iVar13 = *(int *)param_6;
      param_2 = (int *)0x0;
      pdVar4 = (double *)*param_3;
      iVar12 = *piVar2;
      if (param_5 != 0) {
        do {
          if (iVar13 == 0) break;
          uVar10 = 0;
          if (uVar7 != 0) {
            do {
              if (iVar13 == 0) break;
              *pdVar4 = (double)*(int *)(*piVar2 + uVar10 * 4);
              pdVar4 = pdVar4 + 1;
              iVar13 = iVar13 + -1;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar7);
          }
          iVar12 = iVar12 + 0x40;
          param_2 = (int *)((int)param_2 + 1);
        } while (param_2 < param_5);
      }
      goto LAB_008da442;
    }
    if (iVar13 != 3) {
      return;
    }
    iVar13 = *(int *)param_6;
    pdVar4 = (double *)*param_3;
    pfVar5 = (float *)*param_2;
    uVar10 = 0;
    if (param_5 != 0) {
      do {
        if (iVar13 == 0) break;
        uVar11 = 0;
        if (uVar7 != 0) {
          do {
            if (iVar13 == 0) break;
            *pdVar4 = (double)pfVar5[uVar11];
            pdVar4 = pdVar4 + 1;
            iVar13 = iVar13 + -1;
            uVar11 = uVar11 + 1;
          } while (uVar11 < uVar7);
        }
        pfVar5 = pfVar5 + 0x10;
        uVar10 = uVar10 + 1;
      } while (uVar10 < param_5);
    }
    *param_3 = (int)pdVar4;
LAB_008da57e:
    *(int *)param_6 = iVar13;
  }
  *param_2 = (int)pfVar5;
LAB_008da588:
  *param_1 = *param_1 + 0x1c;
  return;
}


// ==== FUN_008da595 @ 0x008da595 ====

int FUN_008da595(int param_1,ushort *param_2)

{
  void *_Memory;
  undefined4 *puVar1;
  int extraout_EAX;
  int in_ECX;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int local_8;
  
  local_8 = 0;
  uVar4 = (uint)*param_2 * 0x10;
  if ((uint)*param_2 * 0x10 <= (uint)param_2[1] * 4) {
    uVar4 = (uint)param_2[1] * 4;
  }
  if (uVar4 <= (uint)param_2[2] * 0x10) {
    uVar4 = (uint)param_2[2] * 0x10;
  }
  if (*(uint *)(in_ECX + 200) < uVar4) {
    puVar1 = operator_new(uVar4);
    if (puVar1 == (undefined4 *)0x0) {
      return -0x7ff8fff2;
    }
    puVar5 = puVar1;
    for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = 0;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    _Memory = *(void **)(in_ECX + 0xcc);
    if (_Memory != (void *)0x0) {
      _free(_Memory);
      return extraout_EAX;
    }
    *(undefined4 **)(in_ECX + 0xcc) = puVar1;
    *(uint *)(in_ECX + 200) = uVar4;
  }
  if ((param_1 != 0) &&
     (local_8 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x170))(*(int **)(in_ECX + 0xc),0),
     local_8 < 0)) {
    return local_8;
  }
  if ((*param_2 != 0) &&
     (local_8 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x178))
                          (*(int **)(in_ECX + 0xc),0,*(undefined4 *)(in_ECX + 0xcc),*param_2),
     local_8 < 0)) {
    return local_8;
  }
  if ((param_2[1] != 0) &&
     (local_8 = FUN_008d4df2(*(undefined4 *)(in_ECX + 0xc),0,*(undefined4 *)(in_ECX + 0xcc),
                             param_2[1]), local_8 < 0)) {
    return local_8;
  }
  if (param_2[2] != 0) {
    local_8 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x180))
                        (*(int **)(in_ECX + 0xc),0,*(undefined4 *)(in_ECX + 0xcc),param_2[2]);
  }
  return local_8;
}


// ==== FUN_008da6b6 @ 0x008da6b6 ====

void FUN_008da6b6(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  undefined4 local_c;
  uint local_8;
  
  local_8 = 0;
  if (*(short *)(param_2 + 6) != 0) {
    iVar2 = 0x101;
    while (iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x104))(*(int **)(in_ECX + 0xc),iVar2,0),
          -1 < iVar1) {
      uVar3 = 0x1c;
      do {
        if (*(int *)(uVar3 + 0xa22d08) == 0) {
          local_c = 0;
        }
        else {
          local_c = *(undefined4 *)(*(int *)(uVar3 + 0xa22d08) + 4);
        }
        iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x114))
                          (*(int **)(in_ECX + 0xc),iVar2,*(uint *)(uVar3 + 0xa22d04) & 0xffffff,
                           local_c);
        if (iVar1 < 0) {
          return;
        }
        uVar3 = uVar3 + 0x1c;
      } while (uVar3 < 0x188);
      local_8 = local_8 + 1;
      iVar2 = iVar2 + 1;
      if (*(ushort *)(param_2 + 6) <= local_8) {
        return;
      }
    }
  }
  return;
}


// ==== FUN_008da744 @ 0x008da744 ====

int FUN_008da744(int param_1,ushort *param_2)

{
  void *_Memory;
  undefined4 *puVar1;
  int extraout_EAX;
  int in_ECX;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int local_8;
  
  local_8 = 0;
  uVar4 = (uint)*param_2 * 0x10;
  if ((uint)*param_2 * 0x10 <= (uint)param_2[1] * 4) {
    uVar4 = (uint)param_2[1] * 4;
  }
  if (uVar4 <= (uint)param_2[2] * 0x10) {
    uVar4 = (uint)param_2[2] * 0x10;
  }
  if (*(uint *)(in_ECX + 200) < uVar4) {
    puVar1 = operator_new(uVar4);
    if (puVar1 == (undefined4 *)0x0) {
      return -0x7ff8fff2;
    }
    puVar5 = puVar1;
    for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = 0;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    _Memory = *(void **)(in_ECX + 0xcc);
    if (_Memory != (void *)0x0) {
      _free(_Memory);
      return extraout_EAX;
    }
    *(undefined4 **)(in_ECX + 0xcc) = puVar1;
    *(uint *)(in_ECX + 200) = uVar4;
  }
  if ((param_1 != 0) &&
     (local_8 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x1ac))(*(int **)(in_ECX + 0xc),0),
     local_8 < 0)) {
    return local_8;
  }
  if ((*param_2 != 0) &&
     (local_8 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x1b4))
                          (*(int **)(in_ECX + 0xc),0,*(undefined4 *)(in_ECX + 0xcc),*param_2),
     local_8 < 0)) {
    return local_8;
  }
  if ((param_2[1] != 0) &&
     (local_8 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x1c4))
                          (*(int **)(in_ECX + 0xc),0,*(undefined4 *)(in_ECX + 0xcc),param_2[1]),
     local_8 < 0)) {
    return local_8;
  }
  if (param_2[2] != 0) {
    local_8 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x1bc))
                        (*(int **)(in_ECX + 0xc),0,*(undefined4 *)(in_ECX + 0xcc),param_2[2]);
  }
  return local_8;
}


// ==== FUN_008da869 @ 0x008da869 ====

int FUN_008da869(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  undefined4 local_8;
  
  uVar2 = 0;
  iVar1 = 0;
  if (*(short *)(param_2 + 6) != 0) {
    while (iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x104))(*(int **)(in_ECX + 0xc),uVar2,0),
          -1 < iVar1) {
      uVar3 = 0x1c;
      do {
        if (*(int *)(uVar3 + 0xa22d08) == 0) {
          local_8 = 0;
        }
        else {
          local_8 = *(undefined4 *)(*(int *)(uVar3 + 0xa22d08) + 4);
        }
        iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x114))
                          (*(int **)(in_ECX + 0xc),uVar2,*(uint *)(uVar3 + 0xa22d04) & 0xffffff,
                           local_8);
        if (iVar1 < 0) {
          return iVar1;
        }
        uVar3 = uVar3 + 0x1c;
      } while (uVar3 < 0x16c);
      uVar2 = uVar2 + 1;
      if (*(ushort *)(param_2 + 6) <= uVar2) {
        return iVar1;
      }
    }
  }
  return iVar1;
}


// ==== FUN_008da8ec @ 0x008da8ec ====

int FUN_008da8ec(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(param_1 + 0x14) * 4) + 0x40);
  if (piVar1 == (int *)0x0) {
LAB_008da979:
    iVar3 = FUN_008d4ea9(param_1);
  }
  else {
    uVar2 = *(uint *)(*(int *)(in_ECX + 0x38) + 8);
    if (uVar2 < 2) {
      if (uVar2 != 0) {
        iVar3 = *(int *)(*(int *)(in_ECX + 0x38) + 0xc);
        if (iVar3 == in_ECX) goto LAB_008da979;
        if (iVar3 != 0) {
          for (piVar4 = (int *)piVar1[4]; piVar4 != piVar1; piVar4 = (int *)piVar4[4]) {
            if (iVar3 == *piVar4) {
              param_1 = piVar4[1];
              goto LAB_008da979;
            }
          }
        }
        goto LAB_008da93a;
      }
    }
    else {
LAB_008da93a:
      for (piVar4 = (int *)piVar1[4]; piVar4 != piVar1; piVar4 = (int *)piVar4[4]) {
        if (((*piVar4 != 0) && ((*(byte *)(*piVar4 + 0x119) & 1) != 0)) &&
           (iVar3 = FUN_008d4ea9(piVar4[1]), iVar3 < 0)) {
          return iVar3;
        }
      }
      if ((*(byte *)(in_ECX + 0x119) & 1) != 0) goto LAB_008da979;
    }
    iVar3 = 0;
  }
  return iVar3;
}


// ==== FUN_008da985 @ 0x008da985 ====

int FUN_008da985(int *param_1,int param_2,uint *param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(ushort *)((int)param_1 + 0x42);
  iVar4 = 0;
  if ((param_1[0xf] == 0) && (param_3 != (uint *)0x0)) {
    if (*(ushort *)(param_1 + 0x11) != 0xffff) {
      iVar4 = FUN_008d51ba(*(undefined2 *)
                            (*(int *)((uint)*(ushort *)((int)param_1 + 0x42) * 0xb4 + 0x38 +
                                     param_1[0x29]) + 0x34 +
                            (uint)*(ushort *)(param_1 + 0x11) * 0x38),0xffffffff,
                           (*(ushort *)(param_1 + 0x10) != *(ushort *)((int)param_1 + 0x42)) - 1);
      if (iVar4 < 0) goto LAB_008daa8c;
    }
    *(undefined2 *)(param_1 + 0x11) = 0xffff;
    if (param_2 == 0) {
      iVar3 = param_1[0x2d];
      *(undefined2 *)((int)param_1 + 0x42) = 0;
    }
    else {
      iVar3 = FUN_008d69b4(param_2,1);
      if (iVar3 == 0) goto LAB_008da9a1;
      uVar2 = *(short *)(iVar3 + 0x14) + 1;
      *(ushort *)((int)param_1 + 0x42) = uVar2;
      iVar3 = param_1[0x2d] + (uint)uVar2 * param_1[0x2b] * 4;
    }
    param_1[0x2e] = iVar3;
    while ((uint)*(ushort *)((int)param_1 + 0x42) < (uint)param_1[0x28]) {
      param_1[0x2e] = param_1[0x2d] + (uint)*(ushort *)((int)param_1 + 0x42) * param_1[0x2b] * 4;
      iVar3 = (**(code **)(*param_1 + 0xf8))(param_1,0);
      if (-1 < iVar3) {
        *param_3 = ~((uint)*(ushort *)((int)param_1 + 0x42) * 0xb4 + param_1[0x29]);
        goto LAB_008daa8c;
      }
      *(short *)((int)param_1 + 0x42) = *(short *)((int)param_1 + 0x42) + 1;
    }
    *param_3 = 0;
    iVar4 = 1;
  }
  else {
LAB_008da9a1:
    iVar4 = -0x7789f794;
  }
LAB_008daa8c:
  *(ushort *)((int)param_1 + 0x42) = uVar1;
  param_1[0x2e] = param_1[0x2d] + (uint)uVar1 * param_1[0x2b] * 4;
  return iVar4;
}


// ==== FUN_008daace @ 0x008daace ====

int FUN_008daace(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 local_10 [4];
  int local_c;
  undefined4 local_8;
  
  piVar3 = param_1;
  if ((*(ushort *)(param_1 + 0x11) != 0xffff) &&
     (iVar4 = FUN_008d51ba(*(undefined2 *)
                            (*(int *)((uint)*(ushort *)((int)param_1 + 0x42) * 0xb4 + 0x38 +
                                     param_1[0x29]) + 0x34 +
                            (uint)*(ushort *)(param_1 + 0x11) * 0x38),0xffffffff,
                           (*(ushort *)(param_1 + 0x10) != *(ushort *)((int)param_1 + 0x42)) - 1),
     iVar4 < 0)) goto LAB_008dada0;
  *(undefined2 *)(param_1 + 0x11) = 0xffff;
  iVar4 = param_1[0xf];
  piVar1 = (int *)param_1[3];
  param_1 = (int *)(uint)*(ushort *)((int)param_1 + 0x42);
  local_c = piVar3[2];
  local_8 = 0xffff;
  piVar3[2] = (int)piVar1;
  if (iVar4 != 0) {
LAB_008dab4e:
    iVar4 = -0x7789f794;
    goto LAB_008dada0;
  }
  if (param_2 != 0) {
    iVar4 = FUN_008d69b4(param_2,1);
    if (iVar4 == 0) goto LAB_008dab4e;
    if (*(short *)((int)piVar3 + 0x42) != *(short *)(iVar4 + 0x14)) {
      *(undefined2 *)(piVar3 + 0x11) = 0xffff;
      *(undefined2 *)((int)piVar3 + 0x42) = *(undefined2 *)(iVar4 + 0x14);
    }
    piVar3[0x2e] = piVar3[0x2d] + (uint)*(ushort *)((int)piVar3 + 0x42) * piVar3[0x2b] * 4;
  }
  piVar2 = piVar3 + 0x40;
  if ((*piVar2 == 0) &&
     (iVar4 = (**(code **)(*piVar1 + 0x158))(piVar1,&DAT_00a210a8,piVar2), iVar4 < 0))
  goto LAB_008dada0;
  if ((piVar3[0x41] == 0) && ((*(byte *)((int)piVar3 + 0x119) & 2) == 0)) {
    iVar4 = (**(code **)(*(int *)piVar3[3] + 0xf0))((int *)piVar3[3]);
    if (iVar4 < 0) goto LAB_008dada0;
    iVar4 = (**(code **)(*(int *)piVar3[3] + 0x15c))((int *)piVar3[3],*piVar2);
    if (((iVar4 < 0) ||
        (iVar4 = (**(code **)(*(int *)piVar3[3] + 0x170))((int *)piVar3[3],0), iVar4 < 0)) ||
       (iVar4 = (**(code **)(*(int *)piVar3[3] + 0x1ac))((int *)piVar3[3],0), iVar4 < 0)) {
      piVar1 = piVar3 + 0x41;
      (**(code **)(*(int *)piVar3[3] + 0xf4))((int *)piVar3[3],piVar1);
      piVar2 = (int *)*piVar1;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
        *piVar1 = 0;
      }
      goto LAB_008dada0;
    }
    iVar4 = (**(code **)(*(int *)piVar3[3] + 0xf4))((int *)piVar3[3],piVar3 + 0x41);
    if (iVar4 < 0) goto LAB_008dada0;
  }
  iVar4 = (**(code **)(*(int *)piVar3[0x41] + 0x10))((int *)piVar3[0x41]);
  if (iVar4 < 0) goto LAB_008dada0;
  param_2 = 0;
  iVar4 = (**(code **)(*(int *)piVar3[3] + 0x15c))((int *)piVar3[3],*piVar2);
  if (((iVar4 < 0) ||
      (iVar4 = (**(code **)(*(int *)piVar3[3] + 0x170))((int *)piVar3[3],0), iVar4 < 0)) ||
     ((iVar4 = (**(code **)(*(int *)piVar3[3] + 0x1ac))((int *)piVar3[3],0), iVar4 < 0 ||
      (iVar4 = (**(code **)(*piVar3 + 0x104))(piVar3,0,0), iVar4 < 0)))) {
LAB_008dad78:
    param_2 = iVar4;
  }
  else {
    piVar3[0xf] = 2;
    FUN_007a41ff(1);
    uVar6 = 0;
    if (*(int *)((uint)*(ushort *)((int)piVar3 + 0x42) * 0xb4 + 0x34 + piVar3[0x29]) != 0) {
      do {
        iVar4 = (**(code **)(*piVar3 + 0x108))(piVar3,uVar6);
        if (((iVar4 < 0) ||
            (iVar4 = (**(code **)(*(int *)piVar3[3] + 0x118))((int *)piVar3[3],local_10), iVar4 < 0)
            ) || (iVar4 = (**(code **)(*piVar3 + 0x110))(piVar3), iVar4 < 0)) {
          param_2 = iVar4;
          break;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)((uint)*(ushort *)((int)piVar3 + 0x42) * 0xb4 + 0x34 + piVar3[0x29])
              );
    }
    FUN_007a41ff(0);
    piVar3[0xf] = 4;
    iVar4 = (**(code **)(*piVar3 + 0x114))(piVar3);
    if ((iVar4 < 0) && (-1 < param_2)) goto LAB_008dad78;
  }
  iVar4 = (**(code **)(*(int *)piVar3[0x41] + 0x14))((int *)piVar3[0x41]);
  if (iVar4 < 0) {
    if (-1 < param_2) {
      param_2 = iVar4;
      goto LAB_008dad96;
    }
  }
  else {
LAB_008dad96:
    if (-1 < param_2) goto LAB_008dada0;
  }
  iVar4 = param_2;
LAB_008dada0:
  if (((*(ushort *)(piVar3 + 0x11) != 0xffff) &&
      (iVar5 = FUN_008d51ba(*(undefined2 *)
                             (*(int *)((uint)*(ushort *)((int)piVar3 + 0x42) * 0xb4 + 0x38 +
                                      piVar3[0x29]) + 0x34 + (uint)*(ushort *)(piVar3 + 0x11) * 0x38
                             ),0xffffffff,
                            (*(ushort *)(piVar3 + 0x10) != *(ushort *)((int)piVar3 + 0x42)) - 1),
      iVar5 < 0)) && (-1 < iVar4)) {
    iVar4 = -0x7fffbffb;
  }
  *(short *)((int)piVar3 + 0x42) = (short)param_1;
  *(undefined2 *)(piVar3 + 0x11) = (undefined2)local_8;
  piVar3[2] = local_c;
  piVar3[0x2e] = piVar3[0x2d] + ((uint)param_1 & 0xffff) * piVar3[0x2b] * 4;
  return iVar4;
}


// ==== FUN_008dae25 @ 0x008dae25 ====

int FUN_008dae25(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint local_30;
  int *local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  piVar7 = (int *)(param_1 * 100 + *(int *)(in_ECX + 0x2c));
  iVar6 = param_2 * 100 + piVar7[1];
  puVar2 = (uint *)(**(code **)(**(int **)(iVar6 + 0x38) + 0xc))(*(int **)(iVar6 + 0x38));
  param_1 = puVar2[3] + *piVar7;
  local_1c = 0;
  uVar5 = *puVar2;
  local_2c = *(int **)(iVar6 + 0xc);
  param_2 = *(int *)(iVar6 + 8);
  local_10 = local_2c[4];
  iVar6 = local_2c[1];
  if (local_10 == 0) {
    local_10 = 1;
  }
  if (-1 < iVar6) {
    local_8 = uVar5;
    if (iVar6 < 4) {
      local_18 = local_2c[5];
      uVar1 = local_2c[6];
      iVar6 = *local_2c;
      local_28 = (uint)((local_18 & 3) != 0) + (local_18 >> 2);
      local_14 = local_18;
      local_c = local_28;
      if (iVar6 == 1) {
        local_20 = 0;
        if (local_10 == 0) {
          return 0;
        }
        do {
          if (uVar5 == 0) {
            return local_1c;
          }
          uVar3 = 0;
          iVar6 = param_1;
          if (uVar1 != 0) {
            do {
              if (uVar5 == 0) break;
              if (uVar5 < local_28) {
                local_14 = uVar5 << 2;
                local_c = uVar5;
              }
              if (local_14 != 0) {
                local_24 = uVar3 << 2;
                local_30 = local_14;
                do {
                  uVar4 = __ftol();
                  *(undefined4 *)(local_24 + param_2) = uVar4;
                  local_24 = local_24 + uVar1 * 4;
                  local_30 = local_30 - 1;
                } while (local_30 != 0);
                iVar6 = param_1;
                uVar5 = local_8;
              }
              uVar5 = uVar5 - local_c;
              uVar3 = uVar3 + 1;
              local_8 = uVar5;
            } while (uVar3 < uVar1);
          }
          local_20 = local_20 + 1;
          param_2 = param_2 + uVar1 * local_18 * 4;
          param_1 = iVar6 + uVar3 * local_c * 8;
          if (local_10 <= local_20) {
            return local_1c;
          }
        } while( true );
      }
      if (iVar6 == 2) {
        local_24 = 0;
        if (local_10 == 0) {
          return 0;
        }
        do {
          if (uVar5 == 0) {
            return local_1c;
          }
          uVar3 = 0;
          iVar6 = param_1;
          if (uVar1 != 0) {
            do {
              if (uVar5 == 0) break;
              if (uVar5 < local_28) {
                local_14 = uVar5 << 2;
                local_c = uVar5;
              }
              if (local_14 != 0) {
                local_20 = uVar3 << 2;
                local_30 = local_14;
                do {
                  uVar4 = __ftol();
                  *(undefined4 *)(local_20 + param_2) = uVar4;
                  local_20 = local_20 + uVar1 * 4;
                  local_30 = local_30 - 1;
                } while (local_30 != 0);
                iVar6 = param_1;
                uVar5 = local_8;
              }
              uVar5 = uVar5 - local_c;
              uVar3 = uVar3 + 1;
              local_8 = uVar5;
            } while (uVar3 < uVar1);
          }
          local_24 = local_24 + 1;
          param_2 = param_2 + uVar1 * local_18 * 4;
          param_1 = iVar6 + uVar3 * local_c * 8;
          if (local_10 <= local_24) {
            return local_1c;
          }
        } while( true );
      }
      if (iVar6 == 3) {
        local_20 = 0;
        if (local_10 == 0) {
          return 0;
        }
        do {
          if (uVar5 == 0) {
            return 0;
          }
          uVar3 = 0;
          if (uVar1 != 0) {
            do {
              if (uVar5 == 0) break;
              if (uVar5 < local_28) {
                local_14 = uVar5 << 2;
                local_c = uVar5;
              }
              if (local_14 != 0) {
                iVar8 = uVar3 << 2;
                iVar6 = uVar3 << 3;
                uVar5 = local_14;
                do {
                  *(float *)(iVar8 + param_2) = (float)*(double *)(iVar6 + param_1);
                  iVar6 = iVar6 + uVar1 * 8;
                  iVar8 = iVar8 + uVar1 * 4;
                  uVar5 = uVar5 - 1;
                } while (uVar5 != 0);
                uVar5 = local_8;
              }
              uVar5 = uVar5 - local_c;
              uVar3 = uVar3 + 1;
              local_8 = uVar5;
            } while (uVar3 < uVar1);
          }
          param_1 = param_1 + uVar3 * local_c * 8;
          local_20 = local_20 + 1;
          param_2 = param_2 + uVar1 * local_18 * 4;
          if (local_10 <= local_20) {
            return 0;
          }
        } while( true );
      }
    }
    else if (iVar6 == 5) {
      local_14 = 0;
      uVar1 = local_2c[5];
      piVar7 = local_2c + 6;
      if (local_10 == 0) {
        return 0;
      }
      do {
        if (uVar5 == 0) {
          return local_1c;
        }
        local_18 = 0;
        local_2c = piVar7;
        if (uVar1 != 0) {
          do {
            if (uVar5 == 0) break;
            local_1c = FUN_008d5487(&local_2c,&param_2,&param_1,&local_8);
            if (local_1c < 0) {
              return local_1c;
            }
            local_18 = local_18 + 1;
            uVar5 = local_8;
          } while (local_18 < uVar1);
        }
        local_14 = local_14 + 1;
        if (local_10 <= local_14) {
          return local_1c;
        }
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008db131 @ 0x008db131 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008db131(int param_1,int param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int in_ECX;
  undefined4 *puVar8;
  int iVar9;
  int local_24;
  ushort local_20;
  ushort local_1e;
  ushort local_1c;
  undefined1 local_18 [4];
  int *local_14;
  undefined1 local_10 [4];
  int *local_c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  iVar9 = param_1 * 100 + *(int *)(in_ECX + 0x2c);
  puVar8 = (undefined4 *)(param_2 * 100 + *(int *)(iVar9 + 4));
  if ((*(short *)(puVar8 + 0x14) == 0) && (puVar8[0xd] == 0)) {
    puVar8[0xc] = puVar8[0xc] & 0xfffffffd;
    *(undefined2 *)((int)puVar8 + 0x4e) = 0;
    *(undefined2 *)(puVar8 + 0x14) = 0;
    *puVar8 = 1;
    local_24 = FUN_008d578c(param_3 + 0x20,puVar8 + 0xf,local_18,local_10,&local_20);
    if ((-1 < local_24) && (puVar8[0xf] != 0)) {
      local_c = *(int **)(puVar8[0xf] + 0xc);
      piVar4 = operator_new((int)local_c * 0x20 + 4);
      piVar3 = local_c;
      if (piVar4 == (int *)0x0) {
        local_c = (int *)0x0;
      }
      else {
        *piVar4 = (int)local_c;
        local_c = piVar4 + 1;
        FUN_0040d030(local_c,0x20,piVar3,&LAB_008d5a15);
      }
      puVar8[0xd] = local_c;
      if (local_c == (int *)0x0) {
        local_24 = -0x7ff8fff2;
      }
      else {
        iVar5 = puVar8[0xf];
        local_c = (int *)0x0;
        *(undefined2 *)(puVar8 + 0x14) = *(undefined2 *)(iVar5 + 0xc);
        local_14 = (int *)(*(int *)(iVar5 + 0x10) + iVar5);
        if (*(int *)(iVar5 + 0xc) != 0) {
          do {
            iVar5 = FUN_008d61a2(*local_14 + puVar8[0xf],10);
            if (iVar5 == 0) goto LAB_008db331;
            sVar1 = *(short *)((int)puVar8 + 0x4e);
            *(short *)((int)puVar8 + 0x4e) = sVar1 + 1;
            local_24 = FUN_008d60b3(param_1,param_2,sVar1,iVar5,local_14);
            if (local_24 < 0) {
              return local_24;
            }
            local_c = (int *)((int)local_c + 1);
            local_14 = local_14 + 5;
          } while (local_c < *(uint *)(puVar8[0xf] + 0xc));
        }
        iVar5 = (uint)local_1e + ((uint)local_20 + (uint)local_1c) * 4;
        *(int *)(param_3 + 8) = iVar5;
        if (iVar5 != 0) {
          *(int *)(param_3 + 8) = iVar5 + -1;
        }
        uVar6 = *(uint *)(param_3 + 8) >> 1 | *(uint *)(param_3 + 8);
        uVar6 = uVar6 >> 2 | uVar6;
        uVar6 = uVar6 >> 4 | uVar6;
        uVar6 = uVar6 >> 8 | uVar6;
        uVar6 = uVar6 >> 0x10 | uVar6;
        *(uint *)(param_3 + 8) = uVar6;
        uVar2 = *(uint *)(iVar9 + 0xc) >> 3;
        uVar7 = *(uint *)(iVar9 + 0xc) & 7;
        uVar6 = uVar7 + 8 + (uVar2 + uVar6) * 8;
        iVar5 = uVar7 + uVar2 * 8;
        *(int *)(iVar9 + 0xc) = iVar5;
        *(int *)(param_3 + 0x10) = iVar5;
        uVar7 = *(int *)(iVar9 + 0xc) + (uint)local_20 * 0x20;
        iVar5 = (uVar7 & 7) + (uVar7 & 0xfffffff8);
        *(int *)(iVar9 + 0xc) = iVar5;
        *(int *)(param_3 + 0x14) = iVar5;
        uVar7 = *(int *)(iVar9 + 0xc) + (uint)local_1e * 8;
        iVar5 = (uVar7 & 7) + (uVar7 & 0xfffffff8);
        *(int *)(iVar9 + 0xc) = iVar5;
        *(int *)(param_3 + 0x18) = iVar5;
        *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + (uint)local_1c * 0x20;
        uVar7 = *(uint *)(iVar9 + 0xc);
        if (*(uint *)(iVar9 + 0xc) <= uVar6) {
          uVar7 = uVar6;
        }
        *(uint *)(iVar9 + 0xc) = uVar7;
      }
    }
  }
  else {
LAB_008db331:
    local_24 = -0x7fffbffb;
  }
  return local_24;
}


// ==== FUN_008db34a @ 0x008db34a ====

void FUN_008db34a(byte param_1)

{
  void *in_ECX;
  
  if ((param_1 & 2) == 0) {
    if ((param_1 & 1) != 0) {
      _free(in_ECX);
      return;
    }
  }
  else {
    FUN_0049b480(in_ECX,0x20,*(undefined4 *)((int)in_ECX + -4),FUN_0095cf1d);
    if ((param_1 & 1) != 0) {
      _free((undefined4 *)((int)in_ECX + -4));
      return;
    }
  }
  return;
}


// ==== FUN_008db391 @ 0x008db391 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008db391(int param_1,int param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int in_ECX;
  undefined4 *puVar8;
  int iVar9;
  int *local_24;
  ushort local_20;
  ushort local_1e;
  ushort local_1c;
  undefined1 local_18 [4];
  int local_14;
  undefined1 local_10 [4];
  int *local_c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  iVar9 = param_1 * 100 + *(int *)(in_ECX + 0x2c);
  puVar8 = (undefined4 *)(param_2 * 100 + *(int *)(iVar9 + 4));
  if ((*(short *)(puVar8 + 0x14) == 0) && (puVar8[0xd] == 0)) {
    puVar8[0xc] = puVar8[0xc] & 0xfffffffd;
    *(undefined2 *)((int)puVar8 + 0x4e) = 0;
    *(undefined2 *)(puVar8 + 0x14) = 0;
    *puVar8 = 1;
    local_14 = FUN_008d578c(param_3 + 0x68,puVar8 + 0xf,local_18,local_10,&local_20);
    if ((-1 < local_14) && (puVar8[0xf] != 0)) {
      local_c = *(int **)(puVar8[0xf] + 0xc);
      piVar4 = operator_new((int)local_c * 0x20 + 4);
      piVar3 = local_c;
      if (piVar4 == (int *)0x0) {
        local_c = (int *)0x0;
      }
      else {
        *piVar4 = (int)local_c;
        local_c = piVar4 + 1;
        FUN_0040d030(local_c,0x20,piVar3,&LAB_008d5a15);
      }
      puVar8[0xd] = local_c;
      if (local_c == (int *)0x0) {
        local_14 = -0x7ff8fff2;
      }
      else {
        iVar5 = puVar8[0xf];
        local_c = (int *)0x0;
        *(short *)(puVar8 + 0x14) = *(short *)(iVar5 + 0xc) << 1;
        local_24 = (int *)(*(int *)(iVar5 + 0x10) + iVar5);
        if (*(int *)(iVar5 + 0xc) != 0) {
          do {
            iVar5 = FUN_008d61a2(*local_24 + puVar8[0xf],10);
            if (iVar5 != 0) {
              sVar1 = *(short *)((int)puVar8 + 0x4e);
              *(short *)((int)puVar8 + 0x4e) = sVar1 + 1;
              local_14 = FUN_008d60b3(param_1,param_2,sVar1,iVar5,local_24);
              if (local_14 < 0) {
                return local_14;
              }
            }
            local_c = (int *)((int)local_c + 1);
            local_24 = local_24 + 5;
          } while (local_c < *(uint *)(puVar8[0xf] + 0xc));
        }
        iVar5 = (uint)local_1e + ((uint)local_20 + (uint)local_1c) * 4;
        *(int *)(param_3 + 0x18) = iVar5;
        if (iVar5 != 0) {
          *(int *)(param_3 + 0x18) = iVar5 + -1;
        }
        uVar6 = *(uint *)(param_3 + 0x18) >> 1 | *(uint *)(param_3 + 0x18);
        uVar6 = uVar6 >> 2 | uVar6;
        uVar6 = uVar6 >> 4 | uVar6;
        uVar6 = uVar6 >> 8 | uVar6;
        uVar6 = uVar6 >> 0x10 | uVar6;
        *(uint *)(param_3 + 0x18) = uVar6;
        uVar2 = *(uint *)(iVar9 + 0xc) >> 3;
        uVar7 = *(uint *)(iVar9 + 0xc) & 7;
        uVar6 = uVar7 + 8 + (uVar2 + uVar6) * 8;
        iVar5 = uVar7 + uVar2 * 8;
        *(int *)(iVar9 + 0xc) = iVar5;
        *(int *)(param_3 + 0x34) = iVar5;
        uVar7 = *(int *)(iVar9 + 0xc) + (uint)local_20 * 0x20;
        iVar5 = (uVar7 & 7) + (uVar7 & 0xfffffff8);
        *(int *)(iVar9 + 0xc) = iVar5;
        *(int *)(param_3 + 0x38) = iVar5;
        uVar7 = *(int *)(iVar9 + 0xc) + (uint)local_1e * 8;
        iVar5 = (uVar7 & 7) + (uVar7 & 0xfffffff8);
        *(int *)(iVar9 + 0xc) = iVar5;
        *(int *)(param_3 + 0x3c) = iVar5;
        *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + (uint)local_1c * 0x20;
        uVar7 = *(uint *)(iVar9 + 0xc);
        if (*(uint *)(iVar9 + 0xc) <= uVar6) {
          uVar7 = uVar6;
        }
        *(uint *)(iVar9 + 0xc) = uVar7;
      }
    }
  }
  else {
    local_14 = -0x7fffbffb;
  }
  return local_14;
}


// ==== FUN_008db5a9 @ 0x008db5a9 ====

undefined4 FUN_008db5a9(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = param_3 * 0x20 +
          *(int *)(*(int *)(param_1 * 100 + 4 + *(int *)(in_ECX + 0x2c)) + 0x34 + param_2 * 100);
  *(undefined4 *)(*(int *)(uVar2 + 0x18) + 0x1c) = *(undefined4 *)(uVar2 + 0x1c);
  *(undefined4 *)(*(int *)(uVar2 + 0x1c) + 0x18) = *(undefined4 *)(uVar2 + 0x18);
  iVar1 = *(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(*(int *)(uVar2 + 0xc) + 0x14) * 4);
  if (uVar2 == *(uint *)(iVar1 + 0x34)) {
    *(uint *)(iVar1 + 0x34) = -(uint)(*(uint *)(uVar2 + 0x1c) != uVar2) & *(uint *)(uVar2 + 0x1c);
  }
  *(uint *)(uVar2 + 0x18) = uVar2;
  *(uint *)(uVar2 + 0x1c) = uVar2;
  if (((*(byte *)(in_ECX + 0x119) & 8) == 0) && (*(int *)(in_ECX + 0xb4) != 0)) {
    FUN_008d5b85();
  }
  return 0;
}


// ==== FUN_008db628 @ 0x008db628 ====

int FUN_008db628(uint param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  int *local_c;
  int *local_8;
  
  uVar2 = param_1;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  iVar3 = (**(code **)(**(int **)(param_1 + 4) + 0x10))(*(int **)(param_1 + 4),0,&param_1);
  if (iVar3 < 0) goto LAB_008db6f4;
  iVar3 = (**(code **)(**(int **)(uVar2 + 4) + 0xc))(*(int **)(uVar2 + 4),&local_c);
  if (iVar3 < 0) goto LAB_008db6f4;
  piVar1 = *(int **)(uVar2 + 8);
  if (piVar1 == (int *)0x0) {
LAB_008db686:
    iVar3 = FUN_008eb3df(param_1,&local_8);
    if (iVar3 < 0) goto LAB_008db6f4;
    piVar1 = *(int **)(uVar2 + 8);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(uVar2 + 8) = 0;
    }
    *(int **)(uVar2 + 8) = local_8;
    local_8 = (int *)0x0;
  }
  else {
    uVar4 = (**(code **)(*piVar1 + 0x10))(piVar1);
    if (uVar4 < param_1) goto LAB_008db686;
  }
  iVar3 = **(int **)(uVar2 + 4);
  uVar5 = (**(code **)(**(int **)(uVar2 + 8) + 0xc))(*(int **)(uVar2 + 8),&param_1);
  iVar3 = (**(code **)(iVar3 + 0x10))(*(undefined4 *)(uVar2 + 4),uVar5);
  if ((-1 < iVar3) && (local_c != *(int **)(in_ECX + 0xc))) {
    piVar1 = *(int **)(uVar2 + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(uVar2 + 4) = 0;
    }
    FUN_008d5d05(uVar2);
  }
LAB_008db6f4:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
    local_8 = (int *)0x0;
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  return iVar3;
}


// ==== FUN_008db71a @ 0x008db71a ====

int FUN_008db71a(uint param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  int *local_c;
  int *local_8;
  
  uVar2 = param_1;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  iVar3 = (**(code **)(**(int **)(param_1 + 4) + 0x10))(*(int **)(param_1 + 4),0,&param_1);
  if (iVar3 < 0) goto LAB_008db7e6;
  iVar3 = (**(code **)(**(int **)(uVar2 + 4) + 0xc))(*(int **)(uVar2 + 4),&local_c);
  if (iVar3 < 0) goto LAB_008db7e6;
  piVar1 = *(int **)(uVar2 + 8);
  if (piVar1 == (int *)0x0) {
LAB_008db778:
    iVar3 = FUN_008eb3df(param_1,&local_8);
    if (iVar3 < 0) goto LAB_008db7e6;
    piVar1 = *(int **)(uVar2 + 8);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(uVar2 + 8) = 0;
    }
    *(int **)(uVar2 + 8) = local_8;
    local_8 = (int *)0x0;
  }
  else {
    uVar4 = (**(code **)(*piVar1 + 0x10))(piVar1);
    if (uVar4 < param_1) goto LAB_008db778;
  }
  iVar3 = **(int **)(uVar2 + 4);
  uVar5 = (**(code **)(**(int **)(uVar2 + 8) + 0xc))(*(int **)(uVar2 + 8),&param_1);
  iVar3 = (**(code **)(iVar3 + 0x10))(*(undefined4 *)(uVar2 + 4),uVar5);
  if ((-1 < iVar3) && (local_c != *(int **)(in_ECX + 0xc))) {
    piVar1 = *(int **)(uVar2 + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(uVar2 + 4) = 0;
    }
    FUN_008d5d63(uVar2);
  }
LAB_008db7e6:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
    local_8 = (int *)0x0;
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  return iVar3;
}


// ==== FUN_008db80c @ 0x008db80c ====

void FUN_008db80c(byte param_1)

{
  void *in_ECX;
  
  if ((param_1 & 2) == 0) {
    FUN_008de297();
    if ((param_1 & 1) != 0) {
      _free(in_ECX);
      return;
    }
  }
  else {
    FUN_0049b480(in_ECX,0x28,*(undefined4 *)((int)in_ECX + -4),FUN_008de297);
    if ((param_1 & 1) != 0) {
      _free((undefined4 *)((int)in_ECX + -4));
      return;
    }
  }
  return;
}


// ==== FUN_008db85a @ 0x008db85a ====

void FUN_008db85a(byte param_1)

{
  void *in_ECX;
  
  if ((param_1 & 2) == 0) {
    FUN_008d5b42();
    if ((param_1 & 1) != 0) {
      _free(in_ECX);
      return;
    }
  }
  else {
    FUN_0049b480(in_ECX,0x18,*(undefined4 *)((int)in_ECX + -4),FUN_008d5b42);
    if ((param_1 & 1) != 0) {
      _free((undefined4 *)((int)in_ECX + -4));
      return;
    }
  }
  return;
}


// ==== FUN_008db8a8 @ 0x008db8a8 ====

int FUN_008db8a8(int *param_1,int *param_2,int *param_3,int *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *in_ECX;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  uint local_14;
  uint local_8;
  
  piVar4 = param_1;
  iVar6 = *(int *)(in_ECX[0x2c] + param_1[5] * 4);
  if (*(int *)(iVar6 + 0x40) == 0) {
    iVar5 = in_ECX[8];
  }
  else {
    iVar5 = *(int *)(in_ECX[0xe] + 0x10);
  }
  iVar5 = *(int *)(iVar6 + 0x2c) + param_1[6] + iVar5;
  local_8 = *(uint *)(iVar5 + 0x10);
  uVar7 = *(uint *)(iVar5 + 4);
  if (local_8 < 2) {
    local_8 = 1;
  }
  uVar2 = *(uint *)(iVar5 + 0x14);
  uVar3 = *(uint *)(iVar5 + 0x18);
  if (uVar7 < 2) {
    piVar11 = param_1 + 0xc;
    param_1 = (int *)(*param_2 + in_ECX[8]);
    puVar8 = (undefined4 *)(*piVar11 + in_ECX[8]);
    if (local_8 != 0) {
      param_4 = (int *)local_8;
      do {
        puVar10 = puVar8;
        puVar9 = param_1;
        for (uVar7 = uVar2 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar9 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar9 = puVar9 + 1;
        }
        puVar8 = puVar8 + uVar2;
        param_1 = param_1 + 4;
        param_4 = (int *)((int)param_4 - 1);
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
      } while (param_4 != (int *)0x0);
    }
    piVar4[0xc] = *param_2;
    *param_2 = *param_2 + local_8 * 0x10;
  }
  else if (uVar7 < 4) {
    puVar8 = (undefined4 *)(param_1[0xc] + in_ECX[8]);
    param_1 = (int *)(*param_3 + in_ECX[8]);
    piVar11 = param_3;
    if (local_8 != 0) {
      param_2 = puVar8;
      local_14 = local_8;
      do {
        puVar10 = param_1;
        if (uVar2 != 0) {
          puVar9 = puVar8;
          param_4 = (int *)uVar2;
          do {
            puVar8 = param_2 + uVar3;
            puVar1 = param_1 + 4;
            for (uVar7 = uVar3 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
              *param_1 = *puVar9;
              puVar9 = puVar9 + 1;
              param_1 = param_1 + 1;
            }
            param_4 = (int *)((int)param_4 - 1);
            for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
              *(undefined1 *)param_1 = *(undefined1 *)puVar9;
              puVar9 = (undefined4 *)((int)puVar9 + 1);
              param_1 = (undefined4 *)((int)param_1 + 1);
            }
            puVar9 = puVar8;
            param_1 = puVar1;
            param_2 = puVar8;
          } while (param_4 != (int *)0x0);
          param_4 = (int *)0x0;
          piVar11 = param_3;
        }
        param_1 = param_1 + (4 - uVar2) * 4;
        thunk_FUN_0079f0cc(puVar10,puVar10);
        local_14 = local_14 - 1;
      } while (local_14 != 0);
    }
    piVar4[0xc] = *piVar11;
    *piVar11 = *piVar11 + local_8 * 0x40;
  }
  else if (uVar7 == 5) {
    param_3 = (int *)param_1[0xc];
    param_2 = (int *)param_1[0xb];
    iVar6 = FUN_008d62ad(in_ECX[8],&param_2,&param_3);
    param_1[0xc] = *param_4;
    *param_4 = *param_4 + iVar6;
    *param_1 = param_1[0xc] + in_ECX[8];
    param_1[1] = in_ECX[8] + param_1[0xb];
    iVar6 = (**(code **)(*in_ECX + 0x50))();
    if (iVar6 < 0) {
      return iVar6;
    }
  }
  return 0;
}


// ==== FUN_008dba54 @ 0x008dba54 ====

undefined4 FUN_008dba54(uint param_1,uint param_2,int *param_3,uint *param_4)

{
  uint *puVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  
  puVar1 = param_4;
  iVar8 = (param_1 & 0xffff) * 100 + *(int *)(in_ECX + 0x2c);
  puVar7 = (undefined4 *)((param_2 & 0xffff) * 100 + *(int *)(iVar8 + 4));
  *puVar7 = 0;
  puVar7[7] = 0;
  if ((param_3 != (int *)0x0) &&
     (uVar4 = (**(code **)(*param_3 + 0x10))(param_3), *puVar1 + 1 <= uVar4)) {
    iVar5 = (**(code **)(*param_3 + 0xc))(param_3);
    *(undefined4 *)((int)puVar7 + 0x52) = *(undefined4 *)(iVar5 + *puVar1 * 4);
  }
  *puVar1 = *puVar1 + 1;
  if ((param_3 != (int *)0x0) &&
     (uVar4 = (**(code **)(*param_3 + 0x10))(param_3), *puVar1 + 1 <= uVar4)) {
    iVar5 = (**(code **)(*param_3 + 0xc))(param_3);
    puVar7[0x15] = *(undefined4 *)(iVar5 + *puVar1 * 4);
  }
  *puVar1 = *puVar1 + 1;
  if ((param_3 != (int *)0x0) &&
     (uVar4 = (**(code **)(*param_3 + 0x10))(param_3), *puVar1 + 1 <= uVar4)) {
    iVar5 = (**(code **)(*param_3 + 0xc))(param_3);
    puVar7[8] = *(undefined4 *)(iVar5 + *puVar1 * 4);
  }
  *puVar1 = *puVar1 + 1;
  if ((param_3 != (int *)0x0) &&
     (uVar4 = (**(code **)(*param_3 + 0x10))(param_3), *puVar1 + 1 <= uVar4)) {
    iVar5 = (**(code **)(*param_3 + 0xc))(param_3);
    puVar7[9] = *(undefined4 *)(iVar5 + *puVar1 * 4);
  }
  *puVar1 = *puVar1 + 1;
  if (((param_3 == (int *)0x0) || (uVar4 = (**(code **)(*param_3 + 0x10))(param_3), uVar4 < *puVar1)
      ) || (0xb5 < *(ushort *)((int)puVar7 + 0x52))) {
    return 0x80004005;
  }
  iVar5 = (uint)*(ushort *)((int)puVar7 + 0x52) * 0x1c;
  uVar4 = *(uint *)(&DAT_00a218e8 + iVar5);
  if ((uVar4 != 0) && (uVar4 <= *(ushort *)(puVar7 + 0x15))) {
    return 0x80004005;
  }
  if (uVar4 == 0x105) {
    uVar2 = *(ushort *)(puVar7 + 0x15);
    if (((uVar2 < 0x10) || (uVar2 == 0x101)) ||
       ((uVar2 == 0x102 || ((uVar2 == 0x103 || (uVar2 == 0x104)))))) {
      if (*(int *)(&DAT_00a218ec + iVar5) == 0x300000d) {
        return 0x80004005;
      }
    }
    else if (uVar2 != 0x100) {
      return 0x80004005;
    }
  }
  *(undefined2 *)((int)puVar7 + 0x56) = 0;
  uVar4 = *(uint *)(&DAT_00a218ec + iVar5);
  puVar7[0x16] = uVar4;
  if (uVar4 < 0xc020001) {
    if (uVar4 == 0xc020000) {
LAB_008dbe1b:
      param_2 = puVar7[8] + *(int *)(in_ECX + 0x20);
      uVar2 = FUN_008d53ae(&param_2,4);
      *(ushort *)((int)puVar7 + 0x56) = uVar2;
    }
    else {
      if (uVar4 < 0xc000002) {
        if (uVar4 != 0xc000001) {
          if (uVar4 == 0x9000000) {
            *(undefined4 *)
             (*(int *)(in_ECX + 0x18) + *(int *)(puVar7[9] + *(int *)(in_ECX + 0x20)) * 0x18) =
                 *(undefined4 *)(&DAT_00a218dc + iVar5);
          }
          else {
            if (uVar4 == 0xa000000) {
              *(undefined2 *)(iVar8 + 0x18) = (undefined2)param_2;
            }
            else {
              if (uVar4 != 0xb000000) {
                if (uVar4 == 0xc000000) goto LAB_008dbd68;
                goto LAB_008dbdc7;
              }
              *(undefined2 *)(iVar8 + 0x1a) = (undefined2)param_2;
            }
            *(undefined4 *)
             (*(int *)(in_ECX + 0x18) + *(int *)(puVar7[9] + *(int *)(in_ECX + 0x20)) * 0x18) =
                 *(undefined4 *)(&DAT_00a218dc + (uint)*(ushort *)((int)puVar7 + 0x52) * 0x1c);
          }
          *puVar7 = 0;
          puVar7[0xc] = puVar7[0xc] & 0xfffffffd;
          *(undefined2 *)((int)puVar7 + 0x56) = 1;
          goto LAB_008dbc54;
        }
      }
      else {
        if (uVar4 != 0xc000002) {
          if (uVar4 != 0xc000003) {
            if (uVar4 != 0xc000004) {
              if (uVar4 == 0xc010000) goto LAB_008dbc86;
              goto LAB_008dbdc7;
            }
            goto LAB_008dbd18;
          }
          goto LAB_008dbd1e;
        }
LAB_008dbd22:
        *(short *)((int)puVar7 + 0x56) = *(short *)((int)puVar7 + 0x56) + 1;
      }
LAB_008dbd26:
      *(short *)((int)puVar7 + 0x56) = *(short *)((int)puVar7 + 0x56) + 1;
      iVar5 = *(int *)(&DAT_00a218ec + iVar5);
      if (((iVar5 == 0xd000001) || (iVar5 == 0xd000002)) ||
         ((iVar5 == 0xd000003 || (iVar5 == 0xd000004)))) {
        *(undefined2 *)((int)puVar7 + 0x52) = 0x9c;
        puVar7[0x16] = 0xd000000;
      }
      else {
        *(undefined2 *)((int)puVar7 + 0x52) = 0x94;
        puVar7[0x16] = 0xc000000;
      }
LAB_008dbd68:
      if ((*(int *)(&DAT_00a218ec + (uint)*(ushort *)((int)puVar7 + 0x52) * 0x1c) == 0xd000000) ||
         (*(int *)(&DAT_00a218ec + (uint)*(ushort *)((int)puVar7 + 0x52) * 0x1c) == 0xc000000)) {
        param_2 = puVar7[8] + *(int *)(in_ECX + 0x20);
        uVar3 = FUN_008d53ae(&param_2,4);
        *(undefined2 *)((int)puVar7 + 0x56) = uVar3;
      }
      uVar2 = *(ushort *)((int)puVar7 + 0x56);
    }
    iVar6 = (uint)uVar2 << 4;
    *puVar7 = 1;
  }
  else {
    if (uVar4 < 0xd000005) {
      if (uVar4 == 0xd000004) {
LAB_008dbd18:
        *(undefined2 *)((int)puVar7 + 0x56) = 1;
LAB_008dbd1e:
        *(short *)((int)puVar7 + 0x56) = *(short *)((int)puVar7 + 0x56) + 1;
        goto LAB_008dbd22;
      }
      if (uVar4 == 0xd000000) goto LAB_008dbd68;
      if (uVar4 == 0xd000001) goto LAB_008dbd26;
      if (uVar4 == 0xd000002) goto LAB_008dbd22;
      if (uVar4 == 0xd000003) goto LAB_008dbd1e;
    }
    else {
      if (uVar4 == 0xd010000) {
LAB_008dbc86:
        param_2 = puVar7[8] + *(int *)(in_ECX + 0x20);
        uVar2 = FUN_008d53ae(&param_2,1);
        *(ushort *)((int)puVar7 + 0x56) = uVar2;
        iVar6 = (uint)uVar2 << 2;
        *puVar7 = 1;
        goto LAB_008dbcab;
      }
      if (uVar4 == 0xd020000) goto LAB_008dbe1b;
      if ((uVar4 == 0xe000000) || (uVar4 == 0xf000000)) {
        *(undefined2 *)((int)puVar7 + 0x56) = 1;
        *(short *)(iVar8 + 0x34) = *(short *)(iVar8 + 0x34) + 1;
        *puVar7 = 0;
        puVar7[0xc] = puVar7[0xc] & 0xfffffffd;
        iVar6 = 4;
        goto LAB_008dbcb3;
      }
    }
LAB_008dbdc7:
    iVar6 = *(int *)(&DAT_00a218dc + iVar5);
    if ((((iVar6 == 1) || (iVar6 == 2)) || (iVar6 == 3)) || (iVar6 == 0xf20000)) {
      iVar6 = 4;
    }
    else {
      iVar6 = 0;
    }
    iVar6 = *(int *)(&DAT_00a218e4 + iVar5) * *(int *)(&DAT_00a218e0 + iVar5) * iVar6;
    *(undefined2 *)((int)puVar7 + 0x56) = 1;
    *puVar7 = 1;
  }
LAB_008dbcab:
  puVar7[0xc] = puVar7[0xc] & 0xfffffffd;
  if (iVar6 != 0) {
LAB_008dbcb3:
    uVar4 = (*(uint *)(iVar8 + 0xc) & 3) + (*(uint *)(iVar8 + 0xc) & 0xfffffffc);
    uVar4 = (uVar4 & 1) + (uVar4 & 0xfffffffe);
    uVar4 = (uVar4 & 3) + (uVar4 & 0xfffffffc);
    uVar4 = (uVar4 & 3) + (uVar4 & 0xfffffffc);
    iVar5 = (uVar4 & 3) + (uVar4 & 0xfffffffc);
    *(int *)(iVar8 + 0xc) = iVar5;
    puVar7[0x12] = iVar5;
    *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + iVar6;
    return 0;
  }
LAB_008dbc54:
  puVar7[0x12] = 0;
  return 0;
}


// ==== FUN_008dbe47 @ 0x008dbe47 ====

int FUN_008dbe47(int param_1,int param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint *puVar8;
  int *piVar9;
  uint local_c;
  
  iVar5 = param_1 * 100 + *(int *)(in_ECX + 0x2c);
  puVar6 = (undefined4 *)(param_2 * 100 + *(int *)(iVar5 + 4));
  if (param_3 == (int *)0x0) {
    puVar8 = param_4;
  }
  else {
    uVar1 = (**(code **)(*param_3 + 0x10))(param_3);
    puVar8 = param_4;
    if (*param_4 + 1 <= uVar1) {
      iVar2 = (**(code **)(*param_3 + 0xc))(param_3);
      local_c = *(uint *)(iVar2 + *puVar8 * 4);
    }
  }
  *puVar8 = *puVar8 + 1;
  if ((param_3 != (int *)0x0) && (uVar1 = (**(code **)(*param_3 + 0x10))(param_3), *puVar8 <= uVar1)
     ) {
    iVar2 = FUN_008eb3df(local_c + 0x20,puVar6 + 0xe);
    if (iVar2 < 0) {
      return iVar2;
    }
    piVar3 = (int *)puVar6[0xe];
    piVar3 = (int *)(**(code **)(*piVar3 + 0xc))(piVar3);
    piVar3[2] = 0;
    if (local_c == 0) {
      return iVar2;
    }
    iVar2 = (uint)((local_c & 3) != 0) + (local_c >> 2);
    uVar1 = (**(code **)(*param_3 + 0x10))(param_3);
    if (*param_4 + iVar2 <= uVar1) {
      iVar4 = (**(code **)(*param_3 + 0xc))(param_3);
      piVar7 = (int *)(iVar4 + *param_4 * 4);
      piVar9 = piVar3 + 8;
      for (uVar1 = local_c >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      for (uVar1 = local_c & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
        *(char *)piVar9 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
    }
    *param_4 = *param_4 + iVar2;
    iVar2 = FUN_008b5afa(piVar3 + 8,puVar6 + 0x10,puVar6 + 0x11);
    if (iVar2 < 0) {
      return iVar2;
    }
    uVar1 = (**(code **)(*param_3 + 0x10))(param_3);
    if (*param_4 <= uVar1) {
      iVar2 = FUN_008b5afa(piVar3 + 8,puVar6 + 0x10,puVar6 + 0x11);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = FUN_008db131(param_1,param_2,piVar3);
      if (iVar2 < 0) {
        return iVar2;
      }
      param_3 = (int *)(puVar6[8] + *(int *)(in_ECX + 0x20));
      iVar4 = FUN_008d53ae(&param_3,4);
      *piVar3 = iVar4;
      iVar4 = iVar4 * 4;
      piVar3[1] = iVar4;
      if (iVar4 != 0) {
        piVar3[1] = iVar4 + -1;
      }
      uVar1 = (uint)piVar3[1] >> 1 | piVar3[1];
      uVar1 = uVar1 >> 2 | uVar1;
      uVar1 = uVar1 >> 4 | uVar1;
      uVar1 = uVar1 >> 8 | uVar1;
      uVar1 = uVar1 >> 0x10 | uVar1;
      piVar3[1] = uVar1;
      iVar4 = (*(uint *)(iVar5 + 0xc) & 7) + (*(uint *)(iVar5 + 0xc) & 0xfffffff8);
      *(int *)(iVar5 + 0xc) = iVar4;
      piVar3[3] = iVar4;
      *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + uVar1 * 8 + 8;
      *puVar6 = 1;
      return iVar2;
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008dc02c @ 0x008dc02c ====

void FUN_008dc02c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008d64b8(param_2,param_3,0);
  return;
}


// ==== FUN_008dc045 @ 0x008dc045 ====

undefined4 FUN_008dc045(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  int iVar7;
  int local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  iVar3 = param_1;
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_008db80c(3);
    *(undefined4 *)(iVar3 + 0x20) = 0;
  }
  iVar7 = param_2;
  local_c = operator_new(param_2 * 0x28 + 4);
  if (local_c == (int *)0x0) {
    local_c = (int *)0x0;
  }
  else {
    *local_c = iVar7;
    local_c = local_c + 1;
    FUN_0040d030(local_c,0x28,iVar7,&LAB_008d5a29);
  }
  *(int **)(iVar3 + 0x20) = local_c;
  if (local_c == (int *)0x0) {
    uVar4 = 0x8007000e;
  }
  else {
    piVar1 = (int *)(*(int *)(in_ECX + 0xb0) + *(int *)(iVar3 + 0x14) * 4);
    param_1 = *(int *)(*piVar1 + 0x2c) + 0x18 + *(int *)(iVar3 + 0x18);
    local_10 = *(int *)(*piVar1 + 0x30) + *(int *)(iVar3 + 0x1c);
    if (iVar7 != 0) {
      iVar7 = 0;
      local_c = (int *)param_2;
      local_14 = param_1;
      local_8 = local_10;
      do {
        *(undefined4 *)(iVar7 + 0x10 + *(int *)(iVar3 + 0x20)) = 3;
        *(undefined4 *)(iVar7 + 0x14 + *(int *)(iVar3 + 0x20)) = *(undefined4 *)(iVar3 + 0x14);
        *(int *)(iVar7 + 0x18 + *(int *)(iVar3 + 0x20)) =
             param_1 - *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(iVar3 + 0x14) * 4) +
                               0x2c);
        *(int *)(iVar7 + 0x1c + *(int *)(iVar3 + 0x20)) =
             local_8 - *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(iVar3 + 0x14) * 4) +
                               0x30);
        if (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(iVar3 + 0x14) * 4) + 0x40) == 0) {
          uVar4 = *(undefined4 *)(in_ECX + 0x20);
        }
        else {
          uVar4 = *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x10);
        }
        uVar4 = FUN_008d63c8(uVar4,&param_1,&local_10);
        *(undefined4 *)(iVar7 + 0xc + *(int *)(iVar3 + 0x20)) = uVar4;
        if (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(iVar3 + 0x14) * 4) + 0x40) == 0) {
          uVar4 = *(undefined4 *)(in_ECX + 0x20);
        }
        else {
          uVar4 = *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x10);
        }
        FUN_008d62ad(uVar4,&local_14,&local_8);
        iVar2 = iVar7 + *(int *)(iVar3 + 0x20);
        iVar5 = *(int *)(iVar2 + 0x14) * 4;
        if (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + iVar5) + 0x40) == 0) {
          iVar6 = *(int *)(in_ECX + 0x20);
        }
        else {
          iVar6 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
        }
        *(int *)(iVar2 + 4) =
             *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + iVar5) + 0x2c) + *(int *)(iVar2 + 0x18) +
             iVar6;
        piVar1 = (int *)(iVar7 + *(int *)(iVar3 + 0x20));
        if (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar1[5] * 4) + 0x40) == 0) {
          param_2 = *(int *)(in_ECX + 0x20);
        }
        else {
          param_2 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
        }
        iVar7 = iVar7 + 0x28;
        local_c = (int *)((int)local_c + -1);
        *piVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar1[5] * 4) + 0x30) + piVar1[7] +
                  param_2;
      } while (local_c != (int *)0x0);
    }
    uVar4 = 0;
  }
  return uVar4;
}


// ==== FUN_008dc21f @ 0x008dc21f ====

uint FUN_008dc21f(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 != 0) {
    iVar1 = FUN_008d61a2(param_2,10);
    if (iVar1 == 0) {
      iVar1 = FUN_008d69b4(param_2,10);
      if ((iVar1 == 0) && (iVar1 = FUN_008d6973(param_2,10), iVar1 == 0)) {
        return 0;
      }
      uVar3 = *(uint *)(iVar1 + 0x2c);
      uVar2 = *(uint *)(iVar1 + 0x30);
    }
    else {
      uVar3 = *(uint *)(iVar1 + 0x38);
      uVar2 = *(uint *)(iVar1 + 0x3c);
    }
    if (param_3 < uVar3) {
      if (param_3 != 0) {
        do {
          param_3 = param_3 - 1;
          uVar2 = *(uint *)(uVar2 + 0x3c);
        } while (param_3 != 0);
      }
      return ~uVar2;
    }
  }
  return 0;
}


// ==== FUN_008dc283 @ 0x008dc283 ====

int FUN_008dc283(int param_1,undefined4 param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int local_8;
  
  local_8 = 0;
  if (*(int *)(param_1 + 0x3c) == 4) {
    local_8 = -0x7789f794;
  }
  else {
    iVar3 = FUN_008d69b4(param_2,1);
    if (iVar3 == 0) {
      local_8 = -0x7789f794;
    }
    else {
      if (*(ushort *)(param_1 + 0x44) != 0xffff) {
        local_8 = FUN_008d51ba(*(undefined2 *)
                                (*(int *)((uint)*(ushort *)(param_1 + 0x42) * 0xb4 + 0x38 +
                                         *(int *)(param_1 + 0xa4)) + 0x34 +
                                (uint)*(ushort *)(param_1 + 0x44) * 0x38),0xffffffff,
                               (*(ushort *)(param_1 + 0x40) != *(ushort *)(param_1 + 0x42)) - 1);
        if (local_8 < 0) {
          return local_8;
        }
        *(undefined2 *)(param_1 + 0x44) = 0xffff;
      }
      uVar1 = *(ushort *)(iVar3 + 0x14);
      sVar2 = *(short *)(param_1 + 0x42);
      *(ushort *)(param_1 + 0x42) = uVar1;
      *(uint *)(param_1 + 0xb8) =
           *(int *)(param_1 + 0xb4) + (uint)uVar1 * *(int *)(param_1 + 0xac) * 4;
      if (((*(int *)(param_1 + 0xb4) != 0) && (sVar2 != *(short *)(param_1 + 0x42))) &&
         (uVar5 = 0, *(int *)(param_1 + 0xac) != 0)) {
        do {
          if ((*(char *)(uVar5 + *(int *)(param_1 + 0xbc)) != '\0') &&
             (piVar4 = *(int **)(*(int *)(param_1 + 0xb8) + uVar5 * 4), piVar4 != (int *)0x0)) {
            for (; (undefined4 *)*piVar4 != (undefined4 *)0x0; piVar4 = piVar4 + 1) {
              *(undefined4 *)*piVar4 = 1;
              *(undefined4 *)
               ((uint)*(ushort *)(*piVar4 + 0x16) * 100 +
               *(int *)((uint)*(ushort *)(*piVar4 + 0x14) * 100 + 4 + *(int *)(param_1 + 0x2c))) = 1
              ;
            }
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_1 + 0xac));
      }
    }
  }
  return local_8;
}


// ==== FUN_008dc3aa @ 0x008dc3aa ====

void FUN_008dc3aa(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_008d7cd6(&param_1,&param_2,&param_3,param_4,param_5,param_6);
  return;
}


// ==== FUN_008dc3cd @ 0x008dc3cd ====

int FUN_008dc3cd(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_18;
  int local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  piVar2 = param_1;
  puVar8 = (undefined4 *)*param_1;
  local_c = (int *)param_1[1];
  if ((param_1[2] != -1) || (local_18 = local_c[4], local_18 == 0)) {
    local_18 = 1;
  }
  iVar4 = local_c[1];
  iVar6 = *local_c;
  if (iVar4 < 0) {
LAB_008dc72c:
    iVar4 = -0x7fffbffb;
  }
  else {
    if (iVar4 < 2) {
      iVar4 = local_c[5];
      puVar5 = puVar8 + local_18 * 4;
      for (; puVar8 < puVar5; puVar8 = puVar8 + (4 - iVar4)) {
        if (iVar4 != 0) {
          local_18 = iVar4;
          do {
            *puVar8 = *param_2;
            puVar8 = puVar8 + 1;
            param_2 = param_2 + 1;
            local_18 = local_18 + -1;
          } while (local_18 != 0);
        }
      }
    }
    else {
      param_1 = puVar8;
      if (iVar4 < 4) {
        iVar4 = local_c[5];
        uVar1 = local_c[6];
        local_14 = local_18;
        if (iVar6 == 1) {
          if (local_18 != 0) {
            do {
              local_8 = 0;
              if (uVar1 != 0) {
                do {
                  if (iVar4 != 0) {
                    iVar6 = local_8 << 4;
                    iVar7 = local_8 << 2;
                    local_18 = iVar4;
                    do {
                      *(uint *)(iVar6 + (int)param_1) = (uint)(*(int *)(iVar7 + (int)param_2) != 0);
                      iVar6 = iVar6 + 4;
                      iVar7 = iVar7 + uVar1 * 4;
                      local_18 = local_18 + -1;
                    } while (local_18 != 0);
                  }
                  local_8 = local_8 + 1;
                } while (local_8 < uVar1);
              }
              param_1 = param_1 + 0x10;
              param_2 = param_2 + uVar1 * iVar4;
              local_14 = local_14 + -1;
            } while (local_14 != 0);
          }
        }
        else if (iVar6 == 2) {
          if (local_18 != 0) {
            do {
              local_8 = 0;
              if (uVar1 != 0) {
                do {
                  if (iVar4 != 0) {
                    iVar6 = local_8 << 4;
                    iVar7 = local_8 << 2;
                    local_18 = iVar4;
                    do {
                      *(undefined4 *)(iVar6 + (int)param_1) = *(undefined4 *)(iVar7 + (int)param_2);
                      iVar6 = iVar6 + 4;
                      iVar7 = iVar7 + uVar1 * 4;
                      local_18 = local_18 + -1;
                    } while (local_18 != 0);
                  }
                  local_8 = local_8 + 1;
                } while (local_8 < uVar1);
              }
              param_1 = param_1 + 0x10;
              param_2 = param_2 + uVar1 * iVar4;
              local_14 = local_14 + -1;
            } while (local_14 != 0);
          }
        }
        else if ((iVar6 == 3) && (local_18 != 0)) {
          do {
            local_8 = 0;
            if (uVar1 != 0) {
              do {
                if (iVar4 != 0) {
                  iVar6 = local_8 << 4;
                  iVar7 = local_8 << 2;
                  local_14 = iVar4;
                  do {
                    *(undefined4 *)(iVar6 + (int)param_1) = *(undefined4 *)(iVar7 + (int)param_2);
                    iVar6 = iVar6 + 4;
                    iVar7 = iVar7 + uVar1 * 4;
                    local_14 = local_14 + -1;
                  } while (local_14 != 0);
                }
                local_8 = local_8 + 1;
              } while (local_8 < uVar1);
            }
            param_1 = param_1 + 0x10;
            param_2 = param_2 + uVar1 * iVar4;
            local_18 = local_18 + -1;
          } while (local_18 != 0);
        }
      }
      else {
        local_8 = local_18;
        if (iVar4 == 4) {
          if (iVar6 == 4) {
            for (; local_8 != 0; local_8 = local_8 + -1) {
              iVar4 = FUN_008d7113(*param_2,*param_1,
                                   *(undefined4 *)
                                    (*(int *)(*(int *)(in_ECX + 0xb0) + piVar2[5] * 4) + 0x40));
              if (iVar4 < 0) {
                return iVar4;
              }
              param_2 = param_2 + 1;
              param_1 = param_1 + 1;
            }
          }
          else if (4 < iVar6) {
            if (iVar6 < 10) {
              for (; local_8 != 0; local_8 = local_8 + -1) {
                iVar4 = FUN_008d706f(*param_2,*param_1,
                                     *(undefined4 *)
                                      (*(int *)(*(int *)(in_ECX + 0xb0) + piVar2[5] * 4) + 0x40));
                if (iVar4 < 0) {
                  return iVar4;
                }
                param_2 = param_2 + 1;
                param_1 = param_1 + 1;
              }
            }
            else if (iVar6 == 0xf) {
              for (; local_8 != 0; local_8 = local_8 + -1) {
                iVar4 = FUN_008d6fb7(*param_2,*param_1,
                                     *(undefined4 *)
                                      (*(int *)(*(int *)(in_ECX + 0xb0) + piVar2[5] * 4) + 0x40));
                if (iVar4 < 0) {
                  return iVar4;
                }
                param_2 = param_2 + 1;
                param_1 = param_1 + 1;
              }
            }
            else if (iVar6 == 0x10) {
              for (; local_8 != 0; local_8 = local_8 + -1) {
                iVar4 = FUN_008d6fb7(*param_2,*param_1,
                                     *(undefined4 *)
                                      (*(int *)(*(int *)(in_ECX + 0xb0) + piVar2[5] * 4) + 0x40));
                if (iVar4 < 0) {
                  return iVar4;
                }
                param_2 = param_2 + 1;
                param_1 = param_1 + 1;
              }
            }
          }
        }
        else {
          if (iVar4 != 5) goto LAB_008dc72c;
          uVar1 = local_c[5];
          piVar3 = local_c + 6;
          for (; local_8 != 0; local_8 = local_8 + -1) {
            local_10 = 0;
            local_c = piVar3;
            if (uVar1 != 0) {
              do {
                iVar4 = local_c[4];
                if (iVar4 == 0) {
                  iVar4 = 1;
                }
                iVar4 = FUN_008d816f(&local_c,&param_1,&param_2,iVar4,piVar2);
                if (iVar4 < 0) {
                  return iVar4;
                }
                local_10 = local_10 + 1;
              } while (local_10 < uVar1);
            }
          }
        }
      }
    }
    iVar4 = 0;
  }
  return iVar4;
}


// ==== FUN_008dc738 @ 0x008dc738 ====

void FUN_008dc738(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_008d850f(&param_1,&param_2,&param_3,param_4,param_5);
  return;
}


// ==== FUN_008dc758 @ 0x008dc758 ====

void FUN_008dc758(undefined4 param_1,undefined4 param_2)

{
  FUN_008d8956(param_2);
  return;
}


// ==== FUN_008dc76f @ 0x008dc76f ====

undefined4 FUN_008dc76f(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x8876086c;
  }
  else {
    uVar1 = FUN_008d8997(param_2);
  }
  return uVar1;
}


// ==== FUN_008dc793 @ 0x008dc793 ====

void FUN_008dc793(byte param_1)

{
  void *in_ECX;
  
  if ((param_1 & 2) == 0) {
    FUN_008d91d0();
    if ((param_1 & 1) != 0) {
      _free(in_ECX);
      return;
    }
  }
  else {
    FUN_0049b480(in_ECX,8,*(undefined4 *)((int)in_ECX + -4),FUN_008d91d0);
    if ((param_1 & 1) != 0) {
      _free((undefined4 *)((int)in_ECX + -4));
      return;
    }
  }
  return;
}


// ==== FUN_008dc7e1 @ 0x008dc7e1 ====

void FUN_008dc7e1(undefined4 *param_1,float *param_2,ushort *param_3,int param_4,uint param_5,
                 uint *param_6,float *param_7)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  float *pfVar4;
  uint uVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  ushort *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  int *local_14;
  uint local_10;
  uint local_c;
  float *local_8;
  
  pfVar4 = param_2;
  piVar2 = (int *)param_1[1];
  local_8 = (float *)*param_1;
  if (param_4 == 0) {
    uVar6 = piVar2[1];
    puVar11 = param_3;
  }
  else {
    puVar11 = (ushort *)(*(int *)(param_5 + 0xc) + param_4);
    uVar6 = (uint)*puVar11;
  }
  if (param_7 == (float *)0xffffffff) {
    param_1 = (undefined4 *)piVar2[4];
    if (param_1 == (undefined4 *)0x0) {
      param_1 = (undefined4 *)0x1;
    }
  }
  else {
    param_1 = param_7;
  }
  pfVar9 = param_2;
  if ((int)uVar6 < 0) goto LAB_008dcb8a;
  if (1 < (int)uVar6) {
    if (uVar6 == 2) {
      uVar6 = piVar2[5];
      uVar3 = piVar2[6];
      iVar8 = *piVar2;
      if (iVar8 == 1) {
        param_7 = (float *)0x0;
        if (param_1 != (undefined4 *)0x0) {
          do {
            uVar13 = 0;
            pfVar9 = param_2;
            if (param_3 == (ushort *)0x0) break;
            if (uVar6 != 0) {
              do {
                uVar5 = 0;
                if (param_3 == (ushort *)0x0) break;
                if (uVar3 != 0) {
                  iVar8 = uVar13 << 2;
                  do {
                    piVar2 = (int *)(iVar8 + (int)local_8);
                    iVar8 = iVar8 + 0x10;
                    param_2[uVar5] = (float)*piVar2;
                    uVar5 = uVar5 + 1;
                  } while (uVar5 < uVar3);
                }
                param_2 = param_2 + 4;
                param_3 = (ushort *)((int)param_3 + -1);
                uVar13 = uVar13 + 1;
              } while (uVar13 < uVar6);
            }
            param_7 = (float *)((int)param_7 + 1);
            pfVar9 = param_2;
          } while (param_7 < param_1);
        }
      }
      else if (iVar8 == 2) {
        param_7 = (float *)0x0;
        if (param_1 != (undefined4 *)0x0) {
          do {
            uVar13 = 0;
            pfVar9 = param_2;
            if (param_3 == (ushort *)0x0) break;
            if (uVar6 != 0) {
              do {
                uVar5 = 0;
                if (param_3 == (ushort *)0x0) break;
                if (uVar3 != 0) {
                  iVar8 = uVar13 << 2;
                  do {
                    piVar2 = (int *)(iVar8 + (int)local_8);
                    iVar8 = iVar8 + 0x10;
                    param_2[uVar5] = (float)*piVar2;
                    uVar5 = uVar5 + 1;
                  } while (uVar5 < uVar3);
                }
                param_2 = param_2 + 4;
                param_3 = (ushort *)((int)param_3 + -1);
                uVar13 = uVar13 + 1;
              } while (uVar13 < uVar6);
            }
            param_7 = (float *)((int)param_7 + 1);
            pfVar9 = param_2;
          } while (param_7 < param_1);
        }
      }
      else if (iVar8 == 3) {
        local_c = 0;
        param_7 = local_8;
        if (param_1 != (undefined4 *)0x0) {
          do {
            uVar13 = 0;
            if (param_3 == (ushort *)0x0) break;
            if (uVar6 != 0) {
              pfVar9 = param_7;
              do {
                if (param_3 == (ushort *)0x0) break;
                uVar5 = 0;
                if (uVar3 != 0) {
                  pfVar7 = pfVar9;
                  do {
                    fVar1 = *pfVar7;
                    pfVar7 = pfVar7 + 4;
                    param_2[uVar5] = fVar1;
                    uVar5 = uVar5 + 1;
                  } while (uVar5 < uVar3);
                }
                param_2 = param_2 + 4;
                param_3 = (ushort *)((int)param_3 + -1);
                uVar13 = uVar13 + 1;
                pfVar9 = pfVar9 + 1;
              } while (uVar13 < uVar6);
            }
            param_7 = param_7 + 0x10;
            local_c = local_c + 1;
          } while (local_c < param_1);
        }
        pfVar9 = param_2;
      }
      goto LAB_008dcb8a;
    }
    if (uVar6 != 3) {
      if (uVar6 == 5) {
        local_10 = 0;
        if (param_4 != 0) {
          local_c = *(int *)(puVar11 + 6) + param_4;
        }
        param_7 = (float *)0x0;
        uVar6 = piVar2[5];
        if (param_1 != (undefined4 *)0x0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            param_5 = 0;
            if (uVar6 != 0) {
              puVar12 = (undefined4 *)(local_c + 4);
              local_14 = piVar2 + 6;
              do {
                if (param_3 == (ushort *)0x0) break;
                if (param_4 != 0) {
                  local_10 = *puVar12;
                }
                FUN_008d9200(&local_14,&local_8,&param_2,param_4,local_10,&param_3,0xffffffff);
                param_5 = param_5 + 1;
                puVar12 = puVar12 + 2;
                pfVar9 = param_2;
              } while (param_5 < uVar6);
            }
            param_7 = (float *)((int)param_7 + 1);
          } while (param_7 < param_1);
        }
      }
      goto LAB_008dcb8a;
    }
  }
  iVar8 = piVar2[5];
  iVar10 = *piVar2;
  uVar3 = piVar2[6];
  param_7 = (float *)0x0;
  if (uVar6 == 3) {
    param_7 = (float *)((4 - uVar3) * 4);
  }
  if (iVar10 == 1) {
    local_c = 0;
    if (param_1 != (undefined4 *)0x0) {
      do {
        if (param_3 == (ushort *)0x0) break;
        local_10 = 0;
        if (uVar3 != 0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            if (iVar8 != 0) {
              pfVar9 = param_2;
              iVar10 = iVar8;
              do {
                *pfVar9 = (float)*(int *)(((int)local_8 - (int)param_2) + (int)pfVar9);
                pfVar9 = pfVar9 + 1;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
            }
            param_2 = param_2 + 4;
            local_8 = local_8 + 4;
            param_3 = (ushort *)((int)param_3 + -1);
            local_10 = local_10 + 1;
          } while (local_10 < uVar3);
        }
        local_c = local_c + 1;
        local_8 = local_8 + (int)param_7;
      } while (local_c < param_1);
    }
  }
  else {
    if (iVar10 != 2) {
      if ((iVar10 == 3) && (uVar6 = 0, param_1 != (undefined4 *)0x0)) {
        do {
          pfVar9 = param_2;
          if (param_3 == (ushort *)0x0) break;
          uVar13 = 0;
          if (uVar3 != 0) {
            do {
              param_2 = pfVar9;
              if (param_3 == (ushort *)0x0) break;
              *pfVar9 = *local_8;
              pfVar9[1] = local_8[1];
              pfVar9[2] = local_8[2];
              pfVar7 = local_8 + 3;
              param_2 = pfVar9 + 4;
              local_8 = local_8 + 4;
              pfVar9[3] = *pfVar7;
              param_3 = (ushort *)((int)param_3 + -1);
              uVar13 = uVar13 + 1;
              pfVar9 = param_2;
            } while (uVar13 < uVar3);
          }
          uVar6 = uVar6 + 1;
          local_8 = local_8 + (int)param_7;
          pfVar9 = param_2;
        } while (uVar6 < param_1);
      }
      goto LAB_008dcb8a;
    }
    local_10 = 0;
    if (param_1 != (undefined4 *)0x0) {
      do {
        if (param_3 == (ushort *)0x0) break;
        local_c = 0;
        if (uVar3 != 0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            if (iVar8 != 0) {
              pfVar9 = param_2;
              iVar10 = iVar8;
              do {
                *pfVar9 = (float)*(int *)(((int)local_8 - (int)param_2) + (int)pfVar9);
                pfVar9 = pfVar9 + 1;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
            }
            param_2 = param_2 + 4;
            local_8 = local_8 + 4;
            param_3 = (ushort *)((int)param_3 + -1);
            local_c = local_c + 1;
          } while (local_c < uVar3);
        }
        local_10 = local_10 + 1;
        local_8 = local_8 + (int)param_7;
      } while (local_10 < param_1);
    }
  }
  pfVar9 = param_2;
LAB_008dcb8a:
  *param_6 = (uint)((int)pfVar9 - (int)pfVar4) >> 4;
  return;
}


// ==== FUN_008dcb9c @ 0x008dcb9c ====

void FUN_008dcb9c(int *param_1,ushort *param_2,int param_3,uint param_4,uint param_5,uint *param_6,
                 ushort *param_7)

{
  int *piVar1;
  ushort *puVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  ushort *puVar9;
  int *local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  puVar2 = param_2;
  local_1c = (int *)param_1[1];
  local_8 = *param_1;
  if (param_4 == 0) {
    uVar6 = local_1c[1];
    puVar5 = param_2;
  }
  else {
    puVar5 = (ushort *)(*(int *)(param_5 + 0xc) + param_4);
    uVar6 = (uint)*puVar5;
  }
  if (param_7 == (ushort *)0xffffffff) {
    param_1 = (int *)local_1c[4];
    if (param_1 == (int *)0x0) {
      param_1 = (int *)0x1;
    }
  }
  else {
    param_1 = (int *)param_7;
  }
  puVar9 = param_2;
  if ((int)uVar6 < 0) goto LAB_008dcf8e;
  if (1 < (int)uVar6) {
    if (uVar6 == 2) {
      param_5 = local_1c[5];
      param_4 = local_1c[6];
      iVar7 = *local_1c;
      if (iVar7 == 1) {
        param_7 = (ushort *)0x0;
        if (param_1 != (int *)0x0) {
          do {
            uVar6 = 0;
            puVar9 = param_2;
            if (param_3 == 0) break;
            if (param_5 != 0) {
              do {
                if (param_3 == 0) break;
                uVar3 = 0;
                if (param_4 != 0) {
                  iVar7 = uVar6 << 2;
                  do {
                    *(undefined4 *)(param_2 + uVar3 * 2) = *(undefined4 *)(iVar7 + local_8);
                    uVar3 = uVar3 + 1;
                    iVar7 = iVar7 + 0x10;
                  } while (uVar3 < param_4);
                }
                param_2 = param_2 + 8;
                param_3 = param_3 + -1;
                uVar6 = uVar6 + 1;
              } while (uVar6 < param_5);
            }
            param_7 = (ushort *)((int)param_7 + 1);
            puVar9 = param_2;
          } while (param_7 < param_1);
        }
      }
      else if (iVar7 == 2) {
        param_7 = (ushort *)0x0;
        if (param_1 != (int *)0x0) {
          do {
            uVar6 = 0;
            puVar9 = param_2;
            if (param_3 == 0) break;
            if (param_5 != 0) {
              do {
                if (param_3 == 0) break;
                uVar3 = 0;
                if (param_4 != 0) {
                  iVar7 = uVar6 << 2;
                  do {
                    *(undefined4 *)(param_2 + uVar3 * 2) = *(undefined4 *)(iVar7 + local_8);
                    uVar3 = uVar3 + 1;
                    iVar7 = iVar7 + 0x10;
                  } while (uVar3 < param_4);
                }
                param_2 = param_2 + 8;
                param_3 = param_3 + -1;
                uVar6 = uVar6 + 1;
              } while (uVar6 < param_5);
            }
            param_7 = (ushort *)((int)param_7 + 1);
            puVar9 = param_2;
          } while (param_7 < param_1);
        }
      }
      else if (iVar7 == 3) {
        local_18 = 0;
        param_7 = param_2;
        iVar7 = param_3;
        local_14 = local_8;
        if (param_1 != (int *)0x0) {
          do {
            if (iVar7 == 0) break;
            local_10 = 0;
            if (param_5 != 0) {
              local_c = local_14;
              do {
                uVar6 = 0;
                if (iVar7 == 0) break;
                if (param_4 != 0) {
                  do {
                    uVar4 = __ftol();
                    *(undefined4 *)(param_7 + uVar6 * 2) = uVar4;
                    uVar6 = uVar6 + 1;
                  } while (uVar6 < param_4);
                }
                param_7 = param_7 + 8;
                local_c = local_c + 4;
                iVar7 = iVar7 + -1;
                local_10 = local_10 + 1;
              } while (local_10 < param_5);
            }
            local_14 = local_14 + 0x40;
            local_18 = local_18 + 1;
          } while (local_18 < param_1);
        }
        param_2 = param_7;
        puVar9 = param_2;
      }
      goto LAB_008dcf8e;
    }
    if (uVar6 != 3) {
      if (uVar6 == 5) {
        local_18 = 0;
        if (param_4 != 0) {
          local_14 = *(int *)(puVar5 + 6) + param_4;
        }
        uVar6 = local_1c[5];
        piVar1 = local_1c + 6;
        param_7 = (ushort *)0x0;
        if (param_1 != (int *)0x0) {
          do {
            puVar9 = param_2;
            if (param_3 == 0) break;
            param_5 = 0;
            if (uVar6 != 0) {
              puVar8 = (undefined4 *)(local_14 + 4);
              local_1c = piVar1;
              do {
                if (param_3 == 0) break;
                if (param_4 != 0) {
                  local_18 = *puVar8;
                }
                FUN_008d9627(&local_1c,&local_8,&param_2,param_4,local_18,&param_3,0xffffffff);
                param_5 = param_5 + 1;
                puVar8 = puVar8 + 2;
              } while (param_5 < uVar6);
            }
            param_7 = (ushort *)((int)param_7 + 1);
            puVar9 = param_2;
          } while (param_7 < param_1);
        }
      }
      goto LAB_008dcf8e;
    }
  }
  local_10 = local_1c[5];
  param_4 = local_1c[6];
  iVar7 = *local_1c;
  param_5 = 0;
  if (uVar6 == 3) {
    param_5 = (4 - param_4) * 4;
  }
  if (iVar7 == 1) {
    local_18 = 0;
    if (param_1 != (int *)0x0) {
      do {
        puVar9 = param_2;
        if (param_3 == 0) break;
        param_7 = (ushort *)0x0;
        if (param_4 != 0) {
          do {
            if (param_3 == 0) break;
            if (local_10 != 0) {
              puVar5 = param_2;
              local_14 = local_10;
              do {
                *(undefined4 *)puVar5 = *(undefined4 *)((local_8 - (int)param_2) + (int)puVar5);
                puVar5 = puVar5 + 2;
                local_14 = local_14 + -1;
              } while (local_14 != 0);
            }
            param_2 = param_2 + 8;
            local_8 = local_8 + 0x10;
            param_3 = param_3 + -1;
            param_7 = (ushort *)((int)param_7 + 1);
          } while (param_7 < param_4);
        }
        local_18 = local_18 + 1;
        local_8 = local_8 + param_5 * 4;
        puVar9 = param_2;
      } while (local_18 < param_1);
    }
  }
  else if (iVar7 == 2) {
    local_18 = 0;
    if (param_1 != (int *)0x0) {
      do {
        puVar9 = param_2;
        if (param_3 == 0) break;
        param_7 = (ushort *)0x0;
        if (param_4 != 0) {
          do {
            if (param_3 == 0) break;
            if (local_10 != 0) {
              puVar5 = param_2;
              local_14 = local_10;
              do {
                *(undefined4 *)puVar5 = *(undefined4 *)((local_8 - (int)param_2) + (int)puVar5);
                puVar5 = puVar5 + 2;
                local_14 = local_14 + -1;
              } while (local_14 != 0);
            }
            param_2 = param_2 + 8;
            local_8 = local_8 + 0x10;
            param_3 = param_3 + -1;
            param_7 = (ushort *)((int)param_7 + 1);
          } while (param_7 < param_4);
        }
        local_18 = local_18 + 1;
        local_8 = local_8 + param_5 * 4;
        puVar9 = param_2;
      } while (local_18 < param_1);
    }
  }
  else if ((iVar7 == 3) && (local_18 = 0, iVar7 = param_3, param_1 != (int *)0x0)) {
    do {
      if (iVar7 == 0) break;
      param_7 = (ushort *)0x0;
      if (param_4 != 0) {
        do {
          if (iVar7 == 0) break;
          uVar4 = __ftol();
          *(undefined4 *)puVar9 = uVar4;
          uVar4 = __ftol();
          *(undefined4 *)(puVar9 + 2) = uVar4;
          uVar4 = __ftol();
          *(undefined4 *)(puVar9 + 4) = uVar4;
          uVar4 = __ftol();
          *(undefined4 *)(puVar9 + 6) = uVar4;
          puVar9 = puVar9 + 8;
          iVar7 = iVar7 + -1;
          param_7 = (ushort *)((int)param_7 + 1);
        } while (param_7 < param_4);
      }
      local_18 = local_18 + 1;
    } while (local_18 < param_1);
  }
LAB_008dcf8e:
  param_2 = puVar9;
  *param_6 = (uint)((int)param_2 - (int)puVar2) >> 4;
  return;
}


// ==== FUN_008dcfa2 @ 0x008dcfa2 ====

void FUN_008dcfa2(int *param_1,undefined4 *param_2,ushort *param_3,uint param_4,ushort *param_5,
                 uint *param_6,uint param_7)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  ushort *puVar9;
  int *local_14;
  uint local_10;
  int local_c;
  undefined4 *local_8;
  
  puVar3 = param_2;
  local_14 = (int *)param_1[1];
  local_8 = (undefined4 *)*param_1;
  if (param_4 == 0) {
    uVar6 = local_14[1];
    puVar9 = param_3;
  }
  else {
    puVar9 = (ushort *)(*(int *)((int)param_5 + 0xc) + param_4);
    uVar6 = (uint)*puVar9;
  }
  if (param_7 == 0xffffffff) {
    param_1 = (int *)local_14[4];
    if (param_1 == (int *)0x0) {
      param_1 = (int *)0x1;
    }
  }
  else {
    param_1 = (int *)param_7;
  }
  puVar7 = param_2;
  if ((int)uVar6 < 0) goto LAB_008dd2c1;
  if (1 < (int)uVar6) {
    if (uVar6 == 2) {
      param_4 = local_14[5];
      iVar2 = *local_14;
      if (iVar2 == 1) {
        uVar6 = 0;
        if (param_1 != (int *)0x0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            uVar4 = 0;
            if (param_4 != 0) {
              do {
                if (param_3 == (ushort *)0x0) break;
                *param_2 = local_8[uVar4];
                param_2 = param_2 + 1;
                param_3 = (ushort *)((int)param_3 + -1);
                uVar4 = uVar4 + 1;
              } while (uVar4 < param_4);
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < param_1);
        }
      }
      else {
        if (iVar2 != 2) {
          if (iVar2 == 3) {
            param_7 = 0;
            puVar9 = param_3;
            param_5 = (ushort *)local_8;
            if (param_1 != (int *)0x0) {
              do {
                uVar6 = 0;
                if (puVar9 == (ushort *)0x0) break;
                if (param_4 != 0) {
                  do {
                    if (puVar9 == (ushort *)0x0) break;
                    uVar5 = __ftol();
                    *puVar7 = uVar5;
                    puVar7 = puVar7 + 1;
                    puVar9 = (ushort *)((int)puVar9 + -1);
                    uVar6 = uVar6 + 1;
                  } while (uVar6 < param_4);
                }
                param_5 = (ushort *)((int)param_5 + 0x40);
                param_7 = param_7 + 1;
              } while (param_7 < param_1);
            }
          }
          goto LAB_008dd2c1;
        }
        uVar6 = 0;
        if (param_1 != (int *)0x0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            uVar4 = 0;
            if (param_4 != 0) {
              do {
                if (param_3 == (ushort *)0x0) break;
                *param_2 = local_8[uVar4];
                param_2 = param_2 + 1;
                param_3 = (ushort *)((int)param_3 + -1);
                uVar4 = uVar4 + 1;
              } while (uVar4 < param_4);
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < param_1);
        }
      }
      puVar7 = param_2;
      goto LAB_008dd2c1;
    }
    if (uVar6 != 3) {
      if (uVar6 == 5) {
        local_10 = 0;
        if (param_4 != 0) {
          local_c = *(int *)(puVar9 + 6) + param_4;
        }
        uVar6 = local_14[5];
        piVar1 = local_14 + 6;
        param_7 = 0;
        if (param_1 != (int *)0x0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            param_5 = (ushort *)0x0;
            if (uVar6 != 0) {
              puVar8 = (undefined4 *)(local_c + 4);
              local_14 = piVar1;
              do {
                if (param_3 == (ushort *)0x0) break;
                if (param_4 != 0) {
                  local_10 = *puVar8;
                }
                FUN_008d9a99(&local_14,&local_8,&param_2,param_4,local_10,&param_3,0xffffffff);
                param_5 = (ushort *)((int)param_5 + 1);
                puVar8 = puVar8 + 2;
                puVar7 = param_2;
              } while (param_5 < uVar6);
            }
            param_7 = param_7 + 1;
          } while (param_7 < param_1);
        }
      }
      goto LAB_008dd2c1;
    }
  }
  iVar2 = *local_14;
  param_4 = local_14[6];
  local_c = 0;
  if (uVar6 == 3) {
    local_c = (4 - param_4) * 4;
  }
  if (iVar2 == 1) {
    param_5 = (ushort *)0x0;
    if (param_1 != (int *)0x0) {
      do {
        puVar7 = param_2;
        if (param_3 == (ushort *)0x0) break;
        uVar6 = 0;
        if (param_4 != 0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            uVar5 = *local_8;
            local_8 = local_8 + 4;
            *param_2 = uVar5;
            param_2 = param_2 + 1;
            param_3 = (ushort *)((int)param_3 + -1);
            uVar6 = uVar6 + 1;
          } while (uVar6 < param_4);
        }
        param_5 = (ushort *)((int)param_5 + 1);
        local_8 = local_8 + local_c;
        puVar7 = param_2;
      } while (param_5 < param_1);
    }
  }
  else if (iVar2 == 2) {
    param_5 = (ushort *)0x0;
    if (param_1 != (int *)0x0) {
      do {
        if (param_3 == (ushort *)0x0) break;
        uVar6 = 0;
        if (param_4 != 0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            uVar5 = *local_8;
            local_8 = local_8 + 4;
            *puVar7 = uVar5;
            puVar7 = puVar7 + 1;
            param_3 = (ushort *)((int)param_3 + -1);
            uVar6 = uVar6 + 1;
          } while (uVar6 < param_4);
        }
        param_5 = (ushort *)((int)param_5 + 1);
        local_8 = local_8 + local_c;
      } while (param_5 < param_1);
    }
  }
  else if (iVar2 == 3) {
    param_5 = param_3;
    local_10 = 0;
    if (param_1 != (int *)0x0) {
      do {
        if (param_5 == (ushort *)0x0) break;
        param_7 = 0;
        puVar8 = puVar7;
        if (param_4 != 0) {
          do {
            puVar7 = puVar8;
            if (param_5 == (ushort *)0x0) break;
            uVar5 = __ftol();
            *puVar8 = uVar5;
            puVar7 = puVar8 + 1;
            uVar5 = __ftol();
            *puVar7 = uVar5;
            uVar5 = __ftol();
            puVar8[2] = uVar5;
            uVar5 = __ftol();
            param_5 = (ushort *)((int)param_5 + -1);
            param_7 = param_7 + 1;
            puVar8[3] = uVar5;
            puVar8 = puVar7;
          } while (param_7 < param_4);
        }
        local_10 = local_10 + 1;
      } while (local_10 < param_1);
    }
  }
LAB_008dd2c1:
  *param_6 = (uint)((int)puVar7 - (int)puVar3) >> 2;
  return;
}


// ==== FUN_008dd2d3 @ 0x008dd2d3 ====

void FUN_008dd2d3(undefined4 *param_1,double *param_2,ushort *param_3,int param_4,uint param_5,
                 uint *param_6,float *param_7)

{
  float fVar1;
  int *piVar2;
  double *pdVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  double *pdVar8;
  uint uVar9;
  ushort *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int local_14;
  int *local_10;
  uint local_c;
  float *local_8;
  
  pdVar3 = param_2;
  piVar2 = (int *)param_1[1];
  local_8 = (float *)*param_1;
  if (param_4 == 0) {
    uVar4 = piVar2[1];
    puVar10 = param_3;
  }
  else {
    puVar10 = (ushort *)(*(int *)(param_5 + 0xc) + param_4);
    uVar4 = (uint)*puVar10;
  }
  if (param_7 == (float *)0xffffffff) {
    param_1 = (undefined4 *)piVar2[4];
    if (param_1 == (undefined4 *)0x0) {
      param_1 = (undefined4 *)0x1;
    }
  }
  else {
    param_1 = param_7;
  }
  pdVar8 = param_2;
  if ((int)uVar4 < 0) goto LAB_008dd65a;
  if (1 < (int)uVar4) {
    if (uVar4 == 2) {
      uVar4 = piVar2[5];
      uVar13 = piVar2[6];
      iVar6 = *piVar2;
      if (iVar6 == 1) {
        param_7 = (float *)0x0;
        if (param_1 != (undefined4 *)0x0) {
          do {
            uVar12 = 0;
            pdVar8 = param_2;
            if (param_3 == (ushort *)0x0) break;
            if (uVar4 != 0) {
              do {
                uVar9 = 0;
                if (param_3 == (ushort *)0x0) break;
                if (uVar13 != 0) {
                  iVar6 = uVar12 << 2;
                  do {
                    piVar2 = (int *)(iVar6 + (int)local_8);
                    iVar6 = iVar6 + 0x10;
                    param_2[uVar9] = (double)*piVar2;
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < uVar13);
                }
                param_2 = param_2 + 4;
                param_3 = (ushort *)((int)param_3 + -1);
                uVar12 = uVar12 + 1;
              } while (uVar12 < uVar4);
            }
            param_7 = (float *)((int)param_7 + 1);
            pdVar8 = param_2;
          } while (param_7 < param_1);
        }
      }
      else if (iVar6 == 2) {
        param_7 = (float *)0x0;
        if (param_1 != (undefined4 *)0x0) {
          do {
            uVar12 = 0;
            pdVar8 = param_2;
            if (param_3 == (ushort *)0x0) break;
            if (uVar4 != 0) {
              do {
                uVar9 = 0;
                if (param_3 == (ushort *)0x0) break;
                if (uVar13 != 0) {
                  iVar6 = uVar12 << 2;
                  do {
                    piVar2 = (int *)(iVar6 + (int)local_8);
                    iVar6 = iVar6 + 0x10;
                    param_2[uVar9] = (double)*piVar2;
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < uVar13);
                }
                param_2 = param_2 + 4;
                param_3 = (ushort *)((int)param_3 + -1);
                uVar12 = uVar12 + 1;
              } while (uVar12 < uVar4);
            }
            param_7 = (float *)((int)param_7 + 1);
            pdVar8 = param_2;
          } while (param_7 < param_1);
        }
      }
      else if (iVar6 == 3) {
        local_c = 0;
        param_7 = local_8;
        if (param_1 != (undefined4 *)0x0) {
          do {
            uVar12 = 0;
            if (param_3 == (ushort *)0x0) break;
            if (uVar4 != 0) {
              pfVar7 = param_7;
              do {
                if (param_3 == (ushort *)0x0) break;
                uVar9 = 0;
                if (uVar13 != 0) {
                  pfVar5 = pfVar7;
                  do {
                    fVar1 = *pfVar5;
                    pfVar5 = pfVar5 + 4;
                    param_2[uVar9] = (double)fVar1;
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < uVar13);
                }
                param_2 = param_2 + 4;
                param_3 = (ushort *)((int)param_3 + -1);
                uVar12 = uVar12 + 1;
                pfVar7 = pfVar7 + 1;
              } while (uVar12 < uVar4);
            }
            param_7 = param_7 + 0x10;
            local_c = local_c + 1;
          } while (local_c < param_1);
        }
        pdVar8 = param_2;
      }
      goto LAB_008dd65a;
    }
    if (uVar4 != 3) {
      if (uVar4 == 5) {
        local_c = 0;
        if (param_4 != 0) {
          local_14 = *(int *)(puVar10 + 6) + param_4;
        }
        param_7 = (float *)0x0;
        uVar4 = piVar2[5];
        if (param_1 != (undefined4 *)0x0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            param_5 = 0;
            if (uVar4 != 0) {
              puVar11 = (undefined4 *)(local_14 + 4);
              local_10 = piVar2 + 6;
              do {
                if (param_3 == (ushort *)0x0) break;
                if (param_4 != 0) {
                  local_c = *puVar11;
                }
                FUN_008d9e45(&local_10,&local_8,&param_2,param_4,local_c,&param_3,0xffffffff);
                param_5 = param_5 + 1;
                puVar11 = puVar11 + 2;
                pdVar8 = param_2;
              } while (param_5 < uVar4);
            }
            param_7 = (float *)((int)param_7 + 1);
          } while (param_7 < param_1);
        }
      }
      goto LAB_008dd65a;
    }
  }
  uVar13 = piVar2[5];
  uVar12 = piVar2[6];
  iVar6 = *piVar2;
  param_5 = 0;
  if (uVar4 == 3) {
    param_5 = (4 - uVar12) * 4;
  }
  if (iVar6 == 1) {
    param_7 = (float *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      do {
        if (param_3 == (ushort *)0x0) break;
        uVar4 = 0;
        if (uVar12 != 0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            uVar9 = 0;
            if (uVar13 != 0) {
              do {
                param_2[uVar9] = (double)(int)local_8[uVar9];
                uVar9 = uVar9 + 1;
              } while (uVar9 < uVar13);
            }
            param_2 = param_2 + 4;
            local_8 = local_8 + 4;
            param_3 = (ushort *)((int)param_3 + -1);
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar12);
        }
        param_7 = (float *)((int)param_7 + 1);
        local_8 = local_8 + param_5;
      } while (param_7 < param_1);
    }
  }
  else {
    if (iVar6 != 2) {
      if ((iVar6 == 3) && (uVar4 = 0, param_1 != (undefined4 *)0x0)) {
        do {
          pdVar8 = param_2;
          if (param_3 == (ushort *)0x0) break;
          uVar13 = 0;
          pfVar7 = local_8;
          if (uVar12 != 0) {
            do {
              pfVar7 = local_8;
              param_2 = pdVar8;
              if (param_3 == (ushort *)0x0) break;
              pfVar7 = local_8 + 4;
              *pdVar8 = (double)*local_8;
              param_2 = pdVar8 + 4;
              param_3 = (ushort *)((int)param_3 + -1);
              pdVar8[1] = (double)local_8[1];
              uVar13 = uVar13 + 1;
              pdVar8[2] = (double)local_8[2];
              pdVar8[3] = (double)local_8[3];
              local_8 = pfVar7;
              pdVar8 = param_2;
            } while (uVar13 < uVar12);
          }
          uVar4 = uVar4 + 1;
          local_8 = pfVar7 + param_5;
          pdVar8 = param_2;
        } while (uVar4 < param_1);
      }
      goto LAB_008dd65a;
    }
    param_7 = (float *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      do {
        if (param_3 == (ushort *)0x0) break;
        uVar4 = 0;
        if (uVar12 != 0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            uVar9 = 0;
            if (uVar13 != 0) {
              do {
                param_2[uVar9] = (double)(int)local_8[uVar9];
                uVar9 = uVar9 + 1;
              } while (uVar9 < uVar13);
            }
            param_2 = param_2 + 4;
            local_8 = local_8 + 4;
            param_3 = (ushort *)((int)param_3 + -1);
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar12);
        }
        param_7 = (float *)((int)param_7 + 1);
        local_8 = local_8 + param_5;
      } while (param_7 < param_1);
    }
  }
  pdVar8 = param_2;
LAB_008dd65a:
  *param_6 = (uint)((int)pdVar8 - (int)pdVar3) >> 5;
  return;
}


// ==== FUN_008dd66c @ 0x008dd66c ====

void FUN_008dd66c(undefined4 *param_1,double *param_2,ushort *param_3,int param_4,uint param_5,
                 uint *param_6,uint param_7)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  double *pdVar4;
  float *pfVar5;
  double *pdVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  int local_14;
  int *local_c;
  float *local_8;
  
  pdVar4 = param_2;
  piVar2 = (int *)param_1[1];
  local_8 = (float *)*param_1;
  if (param_4 == 0) {
    uVar7 = piVar2[1];
    puVar9 = param_3;
  }
  else {
    puVar9 = (ushort *)(*(int *)(param_5 + 0xc) + param_4);
    uVar7 = (uint)*puVar9;
  }
  if (param_7 == 0xffffffff) {
    param_1 = (undefined4 *)piVar2[4];
    if (param_1 == (undefined4 *)0x0) {
      param_1 = (undefined4 *)0x1;
    }
  }
  else {
    param_1 = (undefined4 *)param_7;
  }
  pdVar6 = param_2;
  if ((int)uVar7 < 0) goto LAB_008dd963;
  if ((int)uVar7 < 2) {
LAB_008dd852:
    uVar8 = piVar2[6];
    iVar3 = *piVar2;
    param_4 = 0;
    if (uVar7 == 3) {
      param_4 = (4 - uVar8) * 4;
    }
    if (iVar3 == 1) {
      param_5 = 0;
      if (param_1 != (undefined4 *)0x0) {
        do {
          if (param_3 == (ushort *)0x0) break;
          uVar7 = 0;
          if (uVar8 != 0) {
            do {
              if (param_3 == (ushort *)0x0) break;
              fVar1 = *local_8;
              local_8 = local_8 + 4;
              *param_2 = (double)(int)fVar1;
              param_2 = param_2 + 1;
              param_3 = (ushort *)((int)param_3 + -1);
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar8);
          }
          param_5 = param_5 + 1;
          local_8 = local_8 + param_4;
        } while (param_5 < param_1);
      }
    }
    else {
      if (iVar3 != 2) {
        if ((iVar3 == 3) && (uVar7 = 0, param_1 != (undefined4 *)0x0)) {
          do {
            pdVar6 = param_2;
            if (param_3 == (ushort *)0x0) break;
            uVar11 = 0;
            pfVar5 = local_8;
            if (uVar8 != 0) {
              do {
                pfVar5 = local_8;
                param_2 = pdVar6;
                if (param_3 == (ushort *)0x0) break;
                param_2 = pdVar6 + 1;
                *pdVar6 = (double)*local_8;
                pfVar5 = local_8 + 4;
                param_3 = (ushort *)((int)param_3 + -1);
                *param_2 = (double)local_8[1];
                uVar11 = uVar11 + 1;
                pdVar6[2] = (double)local_8[2];
                pdVar6[3] = (double)local_8[3];
                local_8 = pfVar5;
                pdVar6 = param_2;
              } while (uVar11 < uVar8);
            }
            uVar7 = uVar7 + 1;
            local_8 = pfVar5 + param_4;
            pdVar6 = param_2;
          } while (uVar7 < param_1);
        }
        goto LAB_008dd963;
      }
      param_5 = 0;
      if (param_1 != (undefined4 *)0x0) {
        do {
          if (param_3 == (ushort *)0x0) break;
          uVar7 = 0;
          if (uVar8 != 0) {
            do {
              if (param_3 == (ushort *)0x0) break;
              fVar1 = *local_8;
              local_8 = local_8 + 4;
              *param_2 = (double)(int)fVar1;
              param_2 = param_2 + 1;
              param_3 = (ushort *)((int)param_3 + -1);
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar8);
          }
          param_5 = param_5 + 1;
          local_8 = local_8 + param_4;
        } while (param_5 < param_1);
      }
    }
  }
  else {
    if (uVar7 != 2) {
      if (uVar7 != 3) {
        if (uVar7 == 5) {
          param_7 = 0;
          if (param_4 != 0) {
            local_14 = *(int *)(puVar9 + 6) + param_4;
          }
          uVar7 = piVar2[5];
          param_5 = 0;
          if (param_1 != (undefined4 *)0x0) {
            do {
              if (param_3 == (ushort *)0x0) break;
              uVar8 = 0;
              if (uVar7 != 0) {
                puVar10 = (undefined4 *)(local_14 + 4);
                local_c = piVar2 + 6;
                do {
                  if (param_3 == (ushort *)0x0) break;
                  if (param_4 != 0) {
                    param_7 = *puVar10;
                  }
                  FUN_008da24f(&local_c,&local_8,&param_2,param_4,param_7,&param_3,0xffffffff);
                  uVar8 = uVar8 + 1;
                  puVar10 = puVar10 + 2;
                  pdVar6 = param_2;
                } while (uVar8 < uVar7);
              }
              param_5 = param_5 + 1;
            } while (param_5 < param_1);
          }
        }
        goto LAB_008dd963;
      }
      goto LAB_008dd852;
    }
    uVar7 = piVar2[5];
    iVar3 = *piVar2;
    if (iVar3 == 1) {
      uVar8 = 0;
      if (param_1 != (undefined4 *)0x0) {
        do {
          if (param_3 == (ushort *)0x0) break;
          uVar11 = 0;
          if (uVar7 != 0) {
            do {
              if (param_3 == (ushort *)0x0) break;
              *pdVar6 = (double)(int)local_8[uVar11];
              pdVar6 = pdVar6 + 1;
              param_3 = (ushort *)((int)param_3 + -1);
              uVar11 = uVar11 + 1;
            } while (uVar11 < uVar7);
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < param_1);
      }
      goto LAB_008dd963;
    }
    if (iVar3 == 2) {
      uVar8 = 0;
      if (param_1 != (undefined4 *)0x0) {
        do {
          if (param_3 == (ushort *)0x0) break;
          uVar11 = 0;
          if (uVar7 != 0) {
            do {
              if (param_3 == (ushort *)0x0) break;
              *pdVar6 = (double)(int)local_8[uVar11];
              pdVar6 = pdVar6 + 1;
              param_3 = (ushort *)((int)param_3 + -1);
              uVar11 = uVar11 + 1;
            } while (uVar11 < uVar7);
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < param_1);
      }
      goto LAB_008dd963;
    }
    if (iVar3 != 3) goto LAB_008dd963;
    uVar8 = 0;
    if (param_1 != (undefined4 *)0x0) {
      do {
        if (param_3 == (ushort *)0x0) break;
        uVar11 = 0;
        if (uVar7 != 0) {
          do {
            if (param_3 == (ushort *)0x0) break;
            *param_2 = (double)local_8[uVar11];
            param_2 = param_2 + 1;
            param_3 = (ushort *)((int)param_3 + -1);
            uVar11 = uVar11 + 1;
          } while (uVar11 < uVar7);
        }
        local_8 = local_8 + 0x10;
        uVar8 = uVar8 + 1;
      } while (uVar8 < param_1);
    }
  }
  pdVar6 = param_2;
LAB_008dd963:
  *param_6 = (uint)((int)pdVar6 - (int)pdVar4) >> 3;
  return;
}


// ==== FUN_008dd975 @ 0x008dd975 ====

int FUN_008dd975(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *local_18 [3];
  int **local_c;
  uint local_8;
  
  local_18[2] = (int *)((uint)*(ushort *)(in_ECX + 0x42) * 0xb4 + 0x94 + *(int *)(in_ECX + 0xa4));
  local_18[0] = (int *)0x0;
  local_18[1] = (int *)0x0;
  if ((*(byte *)(in_ECX + 0x119) & 2) == 0) {
    local_c = local_18;
    local_8 = 0;
    do {
      iVar3 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xf0))(*(int **)(in_ECX + 0xc));
      if (iVar3 < 0) goto LAB_008dda80;
      FUN_007a41ff(1);
      iVar3 = FUN_008da595(param_1,param_2);
      FUN_007a41ff(0);
      if (iVar3 < 0) {
        (**(code **)(**(int **)(in_ECX + 0xc) + 0xf4))(*(int **)(in_ECX + 0xc),local_18 + local_8);
        goto LAB_008dda80;
      }
      iVar3 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xf4))(*(int **)(in_ECX + 0xc),local_c);
      if (iVar3 < 0) goto LAB_008dda80;
      local_8 = local_8 + 1;
      local_c = local_c + 1;
    } while (local_8 < 2);
  }
  iVar3 = (**(code **)(*local_18[0] + 0x10))(local_18[0]);
  piVar2 = local_18[2];
  if (-1 < iVar3) {
    piVar1 = (int *)*local_18[2];
    if (piVar1 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0x14))(piVar1);
    }
    if (-1 < iVar3) {
      iVar3 = (**(code **)(*local_18[1] + 0x10))(local_18[1]);
      if (-1 < iVar3) {
        iVar3 = (**(code **)(*local_18[0] + 0x14))(local_18[0]);
        if (-1 < iVar3) {
          piVar1 = (int *)*piVar2;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *piVar2 = 0;
          }
          *piVar2 = (int)local_18[1];
          local_18[1] = (int *)0x0;
        }
      }
    }
  }
LAB_008dda80:
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
    local_18[0] = (int *)0x0;
  }
  if (local_18[1] != (int *)0x0) {
    (**(code **)(*local_18[1] + 8))(local_18[1]);
  }
  return iVar3;
}


// ==== FUN_008ddaa6 @ 0x008ddaa6 ====

int FUN_008ddaa6(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *local_18 [3];
  int **local_c;
  uint local_8;
  
  local_18[2] = (int *)((uint)*(ushort *)(in_ECX + 0x42) * 0xb4 + 0x8c + *(int *)(in_ECX + 0xa4));
  local_18[0] = (int *)0x0;
  local_18[1] = (int *)0x0;
  if ((*(byte *)(in_ECX + 0x119) & 2) == 0) {
    local_c = local_18;
    local_8 = 0;
    do {
      iVar3 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xf0))(*(int **)(in_ECX + 0xc));
      if (iVar3 < 0) goto LAB_008ddbb1;
      FUN_007a41ff(1);
      iVar3 = FUN_008da6b6(param_1,param_2);
      FUN_007a41ff(0);
      if (iVar3 < 0) {
        (**(code **)(**(int **)(in_ECX + 0xc) + 0xf4))(*(int **)(in_ECX + 0xc),local_18 + local_8);
        goto LAB_008ddbb1;
      }
      iVar3 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xf4))(*(int **)(in_ECX + 0xc),local_c);
      if (iVar3 < 0) goto LAB_008ddbb1;
      local_8 = local_8 + 1;
      local_c = local_c + 1;
    } while (local_8 < 2);
  }
  iVar3 = (**(code **)(*local_18[0] + 0x10))(local_18[0]);
  piVar2 = local_18[2];
  if (-1 < iVar3) {
    piVar1 = (int *)*local_18[2];
    if (piVar1 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0x14))(piVar1);
    }
    if (-1 < iVar3) {
      iVar3 = (**(code **)(*local_18[1] + 0x10))(local_18[1]);
      if (-1 < iVar3) {
        iVar3 = (**(code **)(*local_18[0] + 0x14))(local_18[0]);
        if (-1 < iVar3) {
          piVar1 = (int *)*piVar2;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *piVar2 = 0;
          }
          *piVar2 = (int)local_18[1];
          local_18[1] = (int *)0x0;
        }
      }
    }
  }
LAB_008ddbb1:
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
    local_18[0] = (int *)0x0;
  }
  if (local_18[1] != (int *)0x0) {
    (**(code **)(*local_18[1] + 8))(local_18[1]);
  }
  return iVar3;
}


// ==== FUN_008ddbd7 @ 0x008ddbd7 ====

int FUN_008ddbd7(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *local_18 [3];
  int **local_c;
  uint local_8;
  
  local_18[2] = (int *)((uint)*(ushort *)(in_ECX + 0x42) * 0xb4 + 0x98 + *(int *)(in_ECX + 0xa4));
  local_18[0] = (int *)0x0;
  local_18[1] = (int *)0x0;
  if ((*(byte *)(in_ECX + 0x119) & 2) == 0) {
    local_c = local_18;
    local_8 = 0;
    do {
      iVar3 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xf0))(*(int **)(in_ECX + 0xc));
      if (iVar3 < 0) goto LAB_008ddce2;
      FUN_007a41ff(1);
      iVar3 = FUN_008da744(param_1,param_2);
      FUN_007a41ff(0);
      if (iVar3 < 0) {
        (**(code **)(**(int **)(in_ECX + 0xc) + 0xf4))(*(int **)(in_ECX + 0xc),local_18 + local_8);
        goto LAB_008ddce2;
      }
      iVar3 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xf4))(*(int **)(in_ECX + 0xc),local_c);
      if (iVar3 < 0) goto LAB_008ddce2;
      local_8 = local_8 + 1;
      local_c = local_c + 1;
    } while (local_8 < 2);
  }
  iVar3 = (**(code **)(*local_18[0] + 0x10))(local_18[0]);
  piVar2 = local_18[2];
  if (-1 < iVar3) {
    piVar1 = (int *)*local_18[2];
    if (piVar1 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0x14))(piVar1);
    }
    if (-1 < iVar3) {
      iVar3 = (**(code **)(*local_18[1] + 0x10))(local_18[1]);
      if (-1 < iVar3) {
        iVar3 = (**(code **)(*local_18[0] + 0x14))(local_18[0]);
        if (-1 < iVar3) {
          piVar1 = (int *)*piVar2;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *piVar2 = 0;
          }
          *piVar2 = (int)local_18[1];
          local_18[1] = (int *)0x0;
        }
      }
    }
  }
LAB_008ddce2:
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
    local_18[0] = (int *)0x0;
  }
  if (local_18[1] != (int *)0x0) {
    (**(code **)(*local_18[1] + 8))(local_18[1]);
  }
  return iVar3;
}


// ==== FUN_008ddd08 @ 0x008ddd08 ====

int FUN_008ddd08(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *local_18 [3];
  int **local_c;
  uint local_8;
  
  local_18[2] = (int *)((uint)*(ushort *)(in_ECX + 0x42) * 0xb4 + 0x90 + *(int *)(in_ECX + 0xa4));
  local_18[0] = (int *)0x0;
  local_18[1] = (int *)0x0;
  if ((*(byte *)(in_ECX + 0x119) & 2) == 0) {
    local_c = local_18;
    local_8 = 0;
    do {
      iVar3 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xf0))(*(int **)(in_ECX + 0xc));
      if (iVar3 < 0) goto LAB_008dde13;
      FUN_007a41ff(1);
      iVar3 = FUN_008da869(param_1,param_2);
      FUN_007a41ff(0);
      if (iVar3 < 0) {
        (**(code **)(**(int **)(in_ECX + 0xc) + 0xf4))(*(int **)(in_ECX + 0xc),local_18 + local_8);
        goto LAB_008dde13;
      }
      iVar3 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xf4))(*(int **)(in_ECX + 0xc),local_c);
      if (iVar3 < 0) goto LAB_008dde13;
      local_8 = local_8 + 1;
      local_c = local_c + 1;
    } while (local_8 < 2);
  }
  iVar3 = (**(code **)(*local_18[0] + 0x10))(local_18[0]);
  piVar2 = local_18[2];
  if (-1 < iVar3) {
    piVar1 = (int *)*local_18[2];
    if (piVar1 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0x14))(piVar1);
    }
    if (-1 < iVar3) {
      iVar3 = (**(code **)(*local_18[1] + 0x10))(local_18[1]);
      if (-1 < iVar3) {
        iVar3 = (**(code **)(*local_18[0] + 0x14))(local_18[0]);
        if (-1 < iVar3) {
          piVar1 = (int *)*piVar2;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *piVar2 = 0;
          }
          *piVar2 = (int)local_18[1];
          local_18[1] = (int *)0x0;
        }
      }
    }
  }
LAB_008dde13:
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
    local_18[0] = (int *)0x0;
  }
  if (local_18[1] != (int *)0x0) {
    (**(code **)(*local_18[1] + 8))(local_18[1]);
  }
  return iVar3;
}


// ==== FUN_008dde39 @ 0x008dde39 ====

void FUN_008dde39(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int in_ECX;
  int *piVar13;
  int iVar14;
  int *piVar15;
  int local_10;
  int local_c;
  int local_8;
  
  piVar15 = (int *)(param_1 * 100 + *(int *)(in_ECX + 0x2c));
  iVar14 = param_2 * 100 + piVar15[1];
  local_8 = in_ECX;
  iVar10 = (**(code **)(**(int **)(iVar14 + 0x38) + 0xc))(*(int **)(iVar14 + 0x38));
  local_c = *(int *)(iVar10 + 0xc) + *piVar15;
  uVar4 = *(undefined4 *)(iVar10 + 4);
  local_10 = 0;
  param_1 = 0;
  if ((*(byte *)(local_8 + 0x118) & 1) == 0) {
    uVar11 = __controlfp(0,0);
    *(uint *)(local_8 + 0x114) = uVar11;
    __controlfp(0,0x30000);
    *(uint *)(local_8 + 0x118) = *(uint *)(local_8 + 0x118) | 1;
  }
  if (*(int *)(iVar14 + 0x3c) != 0) {
    iVar5 = *piVar15;
    iVar6 = *(int *)(iVar10 + 0x10);
    iVar7 = *(int *)(iVar10 + 0x14);
    iVar8 = *(int *)(iVar10 + 0x18);
    uVar1 = 0;
    if (*(short *)(iVar14 + 0x4e) != 0) {
      do {
        piVar13 = (int *)((uint)uVar1 * 0x20 + *(int *)(iVar14 + 0x34));
        if (*piVar13 != 0) {
          *piVar13 = piVar13[1];
          iVar9 = piVar13[4];
          sVar2 = *(short *)(iVar9 + 4);
          if (sVar2 == 0) {
            FUN_008dd66c(piVar13[3],iVar7 + iVar5 + (uint)*(ushort *)(iVar9 + 6) * 8,
                         *(undefined2 *)(iVar9 + 8),*(undefined4 *)(iVar14 + 0x3c),iVar9,&local_10,
                         0xffffffff);
          }
          else {
            if (sVar2 == 1) {
              uVar3 = *(undefined2 *)(iVar9 + 8);
              iVar12 = (uint)*(ushort *)(iVar9 + 6) * 0x20 + iVar8 + iVar5;
            }
            else {
              if (sVar2 != 2) goto LAB_008ddf69;
              uVar3 = *(undefined2 *)(iVar9 + 8);
              iVar12 = (uint)*(ushort *)(iVar9 + 6) * 0x20 + iVar6 + iVar5;
            }
            FUN_008dd2d3(piVar13[3],iVar12,uVar3,*(undefined4 *)(iVar14 + 0x3c),iVar9,&local_10,
                         0xffffffff);
          }
        }
LAB_008ddf69:
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(ushort *)(iVar14 + 0x4e));
    }
    local_10 = *piVar15 + *(int *)(iVar10 + 0x10);
    param_1 = *(undefined4 *)(iVar10 + 8);
  }
  FUN_008b5baa(*(undefined4 *)(iVar14 + 0x40),*(undefined4 *)(iVar14 + 0x44),0,local_10,0,local_c,
               local_c,local_c,0,param_1,0,uVar4,uVar4,uVar4);
  return;
}


// ==== FUN_008ddfb8 @ 0x008ddfb8 ====

int FUN_008ddfb8(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  ushort uVar2;
  short sVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  float *pfVar18;
  undefined4 *puVar19;
  undefined4 uVar20;
  int in_ECX;
  int iVar21;
  int *piVar22;
  double *pdVar23;
  int *piVar24;
  int iVar25;
  float *pfVar26;
  int local_c;
  
  piVar24 = (int *)(param_1 * 100 + *(int *)(in_ECX + 0x2c));
  iVar25 = (int)param_2 * 100 + piVar24[1];
  iVar14 = (**(code **)(**(int **)(iVar25 + 0x38) + 0xc))(*(int **)(iVar25 + 0x38));
  iVar17 = *piVar24;
  iVar21 = *(int *)(iVar14 + 0x1c) + iVar17;
  iVar5 = *(int *)(iVar14 + 0x20);
  iVar6 = *(int *)(iVar14 + 0x24);
  uVar20 = *(undefined4 *)(iVar14 + 0xc);
  uVar7 = *(undefined4 *)(iVar14 + 0x10);
  uVar8 = *(undefined4 *)(iVar14 + 0x14);
  param_2 = (undefined4 *)0x0;
  param_1 = 0;
  if ((*(byte *)(in_ECX + 0x118) & 1) == 0) {
    uVar15 = __controlfp(0,0);
    *(uint *)(in_ECX + 0x114) = uVar15;
    __controlfp(0,0x30000);
    *(uint *)(in_ECX + 0x118) = *(uint *)(in_ECX + 0x118) | 1;
  }
  if (*(int *)(iVar25 + 0x3c) != 0) {
    iVar9 = *piVar24;
    iVar10 = *(int *)(iVar14 + 0x34);
    iVar11 = *(int *)(iVar14 + 0x38);
    iVar12 = *(int *)(iVar14 + 0x3c);
    uVar2 = 0;
    if (*(short *)(iVar25 + 0x4e) != 0) {
      do {
        piVar22 = (int *)((uint)uVar2 * 0x20 + *(int *)(iVar25 + 0x34));
        if (*piVar22 != 0) {
          *piVar22 = piVar22[1];
          iVar13 = piVar22[4];
          sVar3 = *(short *)(iVar13 + 4);
          if (sVar3 == 0) {
            FUN_008dd66c(piVar22[3],iVar11 + iVar9 + (uint)*(ushort *)(iVar13 + 6) * 8,
                         *(undefined2 *)(iVar13 + 8),*(undefined4 *)(iVar25 + 0x3c),iVar13,&param_2,
                         0xffffffff);
          }
          else {
            if (sVar3 == 1) {
              uVar4 = *(undefined2 *)(iVar13 + 8);
              iVar16 = (uint)*(ushort *)(iVar13 + 6) * 0x20 + iVar12 + iVar9;
            }
            else {
              if (sVar3 != 2) goto LAB_008de106;
              uVar4 = *(undefined2 *)(iVar13 + 8);
              iVar16 = (uint)*(ushort *)(iVar13 + 6) * 0x20 + iVar10 + iVar9;
            }
            FUN_008dd2d3(piVar22[3],iVar16,uVar4,*(undefined4 *)(iVar25 + 0x3c),iVar13,&param_2,
                         0xffffffff);
          }
        }
LAB_008de106:
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(ushort *)(iVar25 + 0x4e));
    }
    param_2 = (undefined4 *)(*piVar24 + *(int *)(iVar14 + 0x34));
    param_1 = *(undefined4 *)(iVar14 + 0x18);
  }
  iVar17 = FUN_008b5baa(*(undefined4 *)(iVar25 + 0x40),*(undefined4 *)(iVar25 + 0x44),0,param_2,0,
                        iVar21,iVar6 + iVar17,iVar5 + iVar17,0,param_1,0,uVar20,uVar8,uVar7);
  if (-1 < iVar17) {
    if (*(int *)(iVar14 + 0x4c) != 0) {
      iVar5 = *(int *)(iVar14 + 0x28);
      iVar6 = *piVar24;
      piVar22 = (int *)(*(int *)(iVar14 + 0x5c) + iVar14);
      param_1 = *piVar22;
      piVar22 = piVar22 + 1;
      if (param_1 != 0) {
        do {
          pfVar18 = (float *)(*piVar22 * 0x10 + iVar5 + iVar6);
          pdVar23 = (double *)(*piVar22 * 0x20 + iVar21);
          pfVar26 = pfVar18 + piVar22[1] * 4;
          for (; pfVar18 < pfVar26; pfVar18 = pfVar18 + 4) {
            *pfVar18 = (float)*pdVar23;
            pfVar18[1] = (float)pdVar23[1];
            pfVar18[2] = (float)pdVar23[2];
            pfVar18[3] = (float)pdVar23[3];
            pdVar23 = pdVar23 + 4;
          }
          piVar22 = piVar22 + 2;
          param_1 = param_1 + -1;
        } while (param_1 != 0);
      }
    }
    if (*(int *)(iVar14 + 0x54) != 0) {
      iVar5 = *(int *)(iVar14 + 0x30);
      iVar6 = *piVar24;
      piVar22 = (int *)(*(int *)(iVar14 + 100) + iVar14);
      local_c = *piVar22;
      piVar22 = piVar22 + 1;
      if (local_c != 0) {
        do {
          param_2 = (undefined4 *)(*piVar22 * 0x10 + iVar5 + iVar6);
          puVar19 = param_2 + piVar22[1] * 4;
          for (; param_2 < puVar19; param_2 = param_2 + 1) {
            uVar20 = __ftol();
            *param_2 = uVar20;
          }
          piVar22 = piVar22 + 2;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
    }
    if (*(int *)(iVar14 + 0x50) != 0) {
      iVar5 = *(int *)(iVar14 + 0x2c);
      iVar6 = *piVar24;
      piVar24 = (int *)(*(int *)(iVar14 + 0x60) + iVar14);
      param_2 = (undefined4 *)*piVar24;
      piVar24 = piVar24 + 1;
      if (param_2 != (undefined4 *)0x0) {
        do {
          puVar19 = (undefined4 *)(iVar5 + iVar6 + *piVar24 * 4);
          puVar1 = puVar19 + piVar24[1];
          for (; puVar19 < puVar1; puVar19 = puVar19 + 1) {
            uVar20 = __ftol();
            *puVar19 = uVar20;
          }
          piVar24 = piVar24 + 2;
          param_2 = (undefined4 *)((int)param_2 + -1);
        } while (param_2 != (undefined4 *)0x0);
      }
    }
  }
  return iVar17;
}


// ==== FUN_008de297 @ 0x008de297 ====

void FUN_008de297(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    FUN_008db80c(3);
    *(undefined4 *)(in_ECX + 0x20) = 0;
  }
  while (*(int *)(in_ECX + 0x24) != 0) {
    iVar1 = *(int *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(iVar1 + 0x24);
    *(undefined4 *)(iVar1 + 0x24) = 0;
    FUN_008d5a3d(1);
  }
  return;
}


// ==== FUN_008de31c @ 0x008de31c ====

void FUN_008de31c(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x38);
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  if (*(int *)(in_ECX + 0x34) != 0) {
    FUN_008db34a(3);
    *(undefined4 *)(in_ECX + 0x34) = 0;
  }
  FUN_008de297();
  return;
}


// ==== FUN_008de373 @ 0x008de373 ====

void FUN_008de373(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int local_8;
  
  in_ECX[2] = 0xffffffff;
  in_ECX[9] = 0;
  in_ECX[8] = 0;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[4] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x22] = 0;
  puVar1 = in_ECX + 0x25;
  puVar2 = in_ECX + 0x29;
  local_8 = 2;
  do {
    puVar1[2] = 0xffff;
    *puVar2 = 0;
    puVar2[1] = 0;
    *puVar1 = 0;
    puVar1[-2] = 0;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 2;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}


// ==== FUN_008de3d6 @ 0x008de3d6 ====

void FUN_008de3d6(void)

{
  int iVar1;
  void *_Memory;
  int *in_ECX;
  
  if (in_ECX[5] != 0) {
    FUN_008dc793(3);
    in_ECX[5] = 0;
  }
  iVar1 = *in_ECX;
  if (((((iVar1 == 0) || (iVar1 == 2)) || (iVar1 == 4)) || ((5 < iVar1 && (iVar1 < 0xb)))) &&
     ((void *)in_ECX[3] != (void *)0x0)) {
    _free((void *)in_ECX[3]);
    return;
  }
  if (in_ECX[6] == 0) {
    return;
  }
  _Memory = (void *)in_ECX[6];
  in_ECX[6] = *(int *)((int)_Memory + 0x18);
  *(undefined4 *)((int)_Memory + 0x18) = 0;
  FUN_008de3d6();
  _free(_Memory);
  return;
}


// ==== FUN_008de443 @ 0x008de443 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008de443(int param_1,ushort *param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  ushort uVar3;
  undefined4 local_14;
  ushort local_10;
  ushort local_e;
  ushort local_c;
  ushort local_a;
  undefined4 local_8;
  
  iVar2 = (uint)*(ushort *)(in_ECX + 0x42) * 0xb4 + *(int *)(in_ECX + 0xa4);
  local_8 = DAT_00b49670;
  iVar1 = 0;
  if ((*(uint *)(in_ECX + 0x118) & 8) == 0) {
    return 0;
  }
  if ((*(uint *)(in_ECX + 0x118) & 0x10) == 0) goto LAB_008de562;
  if (*(int *)(iVar2 + 0x94) == 0) {
LAB_008de4c6:
    if (*(int *)(iVar2 + 0x9c) == 0) goto LAB_008de4ce;
LAB_008de4d6:
    local_14 = 1;
  }
  else {
    if ((param_1 == 0) || (*(int *)(iVar2 + 0x9c) != 0)) {
      if ((*param_2 <= *(ushort *)(iVar2 + 0xa4)) &&
         ((param_2[1] <= *(ushort *)(iVar2 + 0xa6) && (param_2[2] <= *(ushort *)(iVar2 + 0xa8)))))
      goto LAB_008de562;
      goto LAB_008de4c6;
    }
LAB_008de4ce:
    local_14 = 0;
    if (param_1 != 0) goto LAB_008de4d6;
  }
  local_10 = *(ushort *)(iVar2 + 0xa4);
  if (*(ushort *)(iVar2 + 0xa4) <= *param_2) {
    local_10 = *param_2;
  }
  local_e = *(ushort *)(iVar2 + 0xa6);
  if (*(ushort *)(iVar2 + 0xa6) <= param_2[1]) {
    local_e = param_2[1];
  }
  local_c = *(ushort *)(iVar2 + 0xa8);
  if (*(ushort *)(iVar2 + 0xa8) <= param_2[2]) {
    local_c = param_2[2];
  }
  iVar1 = FUN_008dd975(local_14,&local_10);
  if (iVar1 < 0) {
    return iVar1;
  }
  *(undefined4 *)(iVar2 + 0x9c) = local_14;
  *(ushort *)(iVar2 + 0xa4) = local_10;
  *(ushort *)(iVar2 + 0xa6) = local_e;
  *(ushort *)(iVar2 + 0xa8) = local_c;
LAB_008de562:
  if ((*(int *)(iVar2 + 0x8c) == 0) || (*(ushort *)(iVar2 + 0xaa) < param_2[3])) {
    uVar3 = param_2[3];
    if (param_2[3] < *(ushort *)(iVar2 + 0xaa)) {
      uVar3 = *(ushort *)(iVar2 + 0xaa);
    }
    local_a = uVar3;
    iVar1 = FUN_008ddaa6(0,&local_10);
    if (-1 < iVar1) {
      *(ushort *)(iVar2 + 0xaa) = uVar3;
    }
  }
  return iVar1;
}


// ==== FUN_008de5b4 @ 0x008de5b4 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008de5b4(int param_1,ushort *param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  ushort uVar3;
  undefined4 local_14;
  ushort local_10;
  ushort local_e;
  ushort local_c;
  ushort local_a;
  undefined4 local_8;
  
  iVar2 = (uint)*(ushort *)(in_ECX + 0x42) * 0xb4 + *(int *)(in_ECX + 0xa4);
  local_8 = DAT_00b49670;
  iVar1 = 0;
  if ((*(uint *)(in_ECX + 0x118) & 8) == 0) {
    return 0;
  }
  if ((*(uint *)(in_ECX + 0x118) & 0x10) == 0) goto LAB_008de6d3;
  if (*(int *)(iVar2 + 0x98) == 0) {
LAB_008de637:
    if (*(int *)(iVar2 + 0xa0) == 0) goto LAB_008de63f;
LAB_008de647:
    local_14 = 1;
  }
  else {
    if ((param_1 == 0) || (*(int *)(iVar2 + 0xa0) != 0)) {
      if ((*param_2 <= *(ushort *)(iVar2 + 0xac)) &&
         ((param_2[1] <= *(ushort *)(iVar2 + 0xae) && (param_2[2] <= *(ushort *)(iVar2 + 0xb0)))))
      goto LAB_008de6d3;
      goto LAB_008de637;
    }
LAB_008de63f:
    local_14 = 0;
    if (param_1 != 0) goto LAB_008de647;
  }
  local_10 = *(ushort *)(iVar2 + 0xac);
  if (*(ushort *)(iVar2 + 0xac) <= *param_2) {
    local_10 = *param_2;
  }
  local_e = *(ushort *)(iVar2 + 0xae);
  if (*(ushort *)(iVar2 + 0xae) <= param_2[1]) {
    local_e = param_2[1];
  }
  local_c = *(ushort *)(iVar2 + 0xb0);
  if (*(ushort *)(iVar2 + 0xb0) <= param_2[2]) {
    local_c = param_2[2];
  }
  iVar1 = FUN_008ddbd7(local_14,&local_10);
  if (iVar1 < 0) {
    return iVar1;
  }
  *(undefined4 *)(iVar2 + 0xa0) = local_14;
  *(ushort *)(iVar2 + 0xac) = local_10;
  *(ushort *)(iVar2 + 0xae) = local_e;
  *(ushort *)(iVar2 + 0xb0) = local_c;
LAB_008de6d3:
  if ((*(int *)(iVar2 + 0x90) == 0) || (*(ushort *)(iVar2 + 0xb2) < param_2[3])) {
    uVar3 = param_2[3];
    if (param_2[3] < *(ushort *)(iVar2 + 0xb2)) {
      uVar3 = *(ushort *)(iVar2 + 0xb2);
    }
    local_a = uVar3;
    iVar1 = FUN_008ddd08(0,&local_10);
    if (-1 < iVar1) {
      *(ushort *)(iVar2 + 0xb2) = uVar3;
    }
  }
  return iVar1;
}


// ==== FUN_008de725 @ 0x008de725 ====

int FUN_008de725(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  ushort *puVar7;
  int local_8;
  
  *param_4 = 0;
  piVar5 = (int *)(param_1 * 100 + *(int *)(in_ECX + 0x2c));
  local_8 = 0;
  if (*(ushort *)(piVar5 + 6) != 0xffff) {
    piVar6 = (int *)((uint)*(ushort *)(piVar5 + 6) * 100 + piVar5[1]);
    iVar3 = piVar6[0x16];
    if ((iVar3 == 0xa000000) || (iVar3 == 0xb000000)) {
      iVar3 = *(int *)(piVar6[7] * 4 + *(int *)(in_ECX + 0xb0));
      if (*(int *)(iVar3 + 0x40) == 0) {
        iVar3 = *(int *)(*(int *)(iVar3 + 0x30) + piVar6[9] + *(int *)(in_ECX + 0x20));
      }
      else {
        iVar3 = *(int *)(piVar6[7] * 4 + *(int *)(in_ECX + 0xb0));
        iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 0x40) + 8) +
                        *(int *)(*(int *)(iVar3 + 0x30) + piVar6[9] +
                                *(int *)(*(int *)(in_ECX + 0x38) + 0x10)) * 4);
      }
      iVar3 = *(int *)(in_ECX + 0x18) + iVar3 * 0x18;
      if ((*(uint *)(iVar3 + 0x14) & 1) != 0) {
        if (*(int *)(iVar3 + 4) == 0) {
          *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 2;
          *(undefined4 *)(iVar3 + 0xc) = 0;
        }
        else {
          local_8 = FUN_008db628(iVar3);
          if (local_8 < 0) {
            return local_8;
          }
        }
        *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffe;
      }
      if ((*(int *)(iVar3 + 4) != 0) || ((*(byte *)(iVar3 + 0x14) & 2) == 0)) {
        uVar4 = (**(code **)(**(int **)(iVar3 + 8) + 0xc))(*(int **)(iVar3 + 8));
        *param_4 = uVar4;
      }
    }
    else if (iVar3 == 0xe000000) {
      if (*piVar6 != 0) {
        *piVar6 = piVar6[1];
        local_8 = FUN_008dde39(param_1,(short)piVar5[6]);
        if (local_8 < 0) {
          return local_8;
        }
        iVar3 = *piVar5;
        (**(code **)(*(int *)piVar6[0xe] + 0xc))((int *)piVar6[0xe]);
        uVar2 = __ftol();
        puVar7 = (ushort *)(piVar6[0x12] + iVar3);
        if (puVar7[1] != uVar2) {
          if (*(uint *)(piVar6[3] + 0x10) <= (uint)uVar2) {
            return -0x7fffbffb;
          }
          uVar1 = 0;
          if (*(short *)((int)piVar6 + 0x56) != 0) {
            do {
              local_8 = FUN_008d51ba((puVar7[1] - 1) + (uint)*puVar7,-(uint)(param_2 != 0),
                                     -(uint)(param_3 != 0));
              if (local_8 < 0) {
                return local_8;
              }
              uVar1 = uVar1 + 1;
            } while (uVar1 < *(ushort *)((int)piVar6 + 0x56));
          }
          uVar1 = 0;
          puVar7[1] = uVar2;
          if (*(short *)((int)piVar6 + 0x56) != 0) {
            do {
              local_8 = FUN_008d51ba((puVar7[1] - 1) + (uint)*puVar7,param_2 != 0,param_3 != 0);
              if (local_8 < 0) {
                return local_8;
              }
              uVar1 = uVar1 + 1;
            } while (uVar1 < *(ushort *)((int)piVar6 + 0x56));
          }
        }
      }
      uVar2 = *(ushort *)(piVar6[0x12] + *piVar5);
      if (uVar2 != 0) {
        local_8 = FUN_008de725((((ushort *)(piVar6[0x12] + *piVar5))[1] - 1) + (uint)uVar2,param_2,
                               param_3,param_4);
      }
    }
  }
  return local_8;
}


// ==== FUN_008de96d @ 0x008de96d ====

int FUN_008de96d(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  ushort *puVar7;
  int local_8;
  
  *param_4 = 0;
  piVar5 = (int *)(param_1 * 100 + *(int *)(in_ECX + 0x2c));
  local_8 = 0;
  if (*(ushort *)((int)piVar5 + 0x1a) != 0xffff) {
    piVar6 = (int *)((uint)*(ushort *)((int)piVar5 + 0x1a) * 100 + piVar5[1]);
    iVar3 = piVar6[0x16];
    if ((iVar3 == 0xa000000) || (iVar3 == 0xb000000)) {
      iVar3 = *(int *)(piVar6[7] * 4 + *(int *)(in_ECX + 0xb0));
      if (*(int *)(iVar3 + 0x40) == 0) {
        iVar3 = *(int *)(*(int *)(iVar3 + 0x30) + piVar6[9] + *(int *)(in_ECX + 0x20));
      }
      else {
        iVar3 = *(int *)(piVar6[7] * 4 + *(int *)(in_ECX + 0xb0));
        iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 0x40) + 8) +
                        *(int *)(*(int *)(iVar3 + 0x30) + piVar6[9] +
                                *(int *)(*(int *)(in_ECX + 0x38) + 0x10)) * 4);
      }
      iVar3 = *(int *)(in_ECX + 0x18) + iVar3 * 0x18;
      if ((*(uint *)(iVar3 + 0x14) & 1) != 0) {
        if (*(int *)(iVar3 + 4) == 0) {
          *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 2;
          *(undefined4 *)(iVar3 + 0xc) = 0;
        }
        else {
          local_8 = FUN_008db71a(iVar3);
          if (local_8 < 0) {
            return local_8;
          }
        }
        *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffe;
      }
      if ((*(int *)(iVar3 + 4) != 0) || ((*(byte *)(iVar3 + 0x14) & 2) == 0)) {
        uVar4 = (**(code **)(**(int **)(iVar3 + 8) + 0xc))(*(int **)(iVar3 + 8));
        *param_4 = uVar4;
      }
    }
    else if (iVar3 == 0xe000000) {
      if (*piVar6 != 0) {
        *piVar6 = piVar6[1];
        local_8 = FUN_008dde39(param_1,*(undefined2 *)((int)piVar5 + 0x1a));
        if (local_8 < 0) {
          return local_8;
        }
        iVar3 = *piVar5;
        (**(code **)(*(int *)piVar6[0xe] + 0xc))((int *)piVar6[0xe]);
        uVar2 = __ftol();
        puVar7 = (ushort *)(piVar6[0x12] + iVar3);
        if (puVar7[1] != uVar2) {
          if (*(uint *)(piVar6[3] + 0x10) <= (uint)uVar2) {
            return -0x7fffbffb;
          }
          uVar1 = 0;
          if (*(short *)((int)piVar6 + 0x56) != 0) {
            do {
              local_8 = FUN_008d51ba((puVar7[1] - 1) + (uint)*puVar7,-(uint)(param_2 != 0),
                                     -(uint)(param_3 != 0));
              if (local_8 < 0) {
                return local_8;
              }
              uVar1 = uVar1 + 1;
            } while (uVar1 < *(ushort *)((int)piVar6 + 0x56));
          }
          uVar1 = 0;
          puVar7[1] = uVar2;
          if (*(short *)((int)piVar6 + 0x56) != 0) {
            do {
              local_8 = FUN_008d51ba((puVar7[1] - 1) + (uint)*puVar7,param_2 != 0,param_3 != 0);
              if (local_8 < 0) {
                return local_8;
              }
              uVar1 = uVar1 + 1;
            } while (uVar1 < *(ushort *)((int)piVar6 + 0x56));
          }
        }
      }
      uVar2 = *(ushort *)(piVar6[0x12] + *piVar5);
      if (uVar2 != 0) {
        local_8 = FUN_008de96d((((ushort *)(piVar6[0x12] + *piVar5))[1] - 1) + (uint)uVar2,param_2,
                               param_3,param_4);
      }
    }
  }
  return local_8;
}


// ==== FUN_008debb5 @ 0x008debb5 ====

int FUN_008debb5(int *param_1,undefined4 *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_8;
  
  local_8 = 0;
  iVar2 = param_1[2];
  param_1[2] = param_1[3];
  if (param_1[0xf] == 4) {
    local_8 = -0x7789f794;
  }
  else if ((param_3 & 7) == param_3) {
    iVar6 = (uint)*(ushort *)((int)param_1 + 0x42) * 0xb4 + param_1[0x29];
    uVar4 = ~(param_3 << 3) & 8;
    param_1[0x46] =
         ((uint)((param_3 & 5) == 0) << 1 | (uint)((param_3 & 3) == 0)) << 4 | uVar4 |
         param_1[0x46] & 0xffffffc7U;
    if (uVar4 != 0) {
      local_8 = FUN_008de443(*(undefined4 *)(iVar6 + 0x9c),iVar6 + 0xa4);
      if ((((local_8 < 0) ||
           (local_8 = FUN_008de5b4(*(undefined4 *)(iVar6 + 0xa0),iVar6 + 0xac), local_8 < 0)) ||
          (((*(byte *)(param_1 + 0x46) & 0x10) != 0 &&
           ((local_8 = (**(code **)(**(int **)(iVar6 + 0x94) + 0x10))(*(int **)(iVar6 + 0x94)),
            local_8 < 0 ||
            (local_8 = (**(code **)(**(int **)(iVar6 + 0x98) + 0x10))(*(int **)(iVar6 + 0x98)),
            local_8 < 0)))))) ||
         (((*(byte *)(param_1 + 0x46) & 0x20) != 0 &&
          ((local_8 = (**(code **)(**(int **)(iVar6 + 0x8c) + 0x10))(*(int **)(iVar6 + 0x8c)),
           local_8 < 0 ||
           (local_8 = (**(code **)(**(int **)(iVar6 + 0x90) + 0x10))(*(int **)(iVar6 + 0x90)),
           local_8 < 0)))))) goto LAB_008dee44;
      if (*(int *)(iVar6 + 0x88) == 0) {
        puVar7 = (undefined4 *)(iVar6 + 0x44);
        for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        puVar7 = *(undefined4 **)(iVar6 + 0x40);
        for (uVar4 = (uint)*(ushort *)(iVar6 + 0x3c) * 0x68 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined1 *)puVar7 = 0;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        local_8 = (**(code **)(*(int *)param_1[3] + 0xf0))((int *)param_1[3]);
        if (local_8 < 0) goto LAB_008dee44;
        param_1[0xf] = 1;
        FUN_007a41ff(1);
        uVar4 = 0;
        if (*(int *)(iVar6 + 0x34) != 0) {
          do {
            (**(code **)(*param_1 + 0x108))(param_1,uVar4);
            (**(code **)(*param_1 + 0x110))(param_1);
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(iVar6 + 0x34));
        }
        FUN_007a41ff(0);
        piVar1 = (int *)(iVar6 + 0x88);
        local_8 = (**(code **)(*(int *)param_1[3] + 0xf4))((int *)param_1[3],piVar1);
        if (local_8 < 0) {
          piVar3 = (int *)*piVar1;
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 8))(piVar3);
            *piVar1 = 0;
          }
          goto LAB_008dee44;
        }
        param_1[0xf] = 0;
        if ((*(ushort *)(param_1 + 0x11) != 0xffff) &&
           (local_8 = FUN_008d51ba(*(undefined2 *)
                                    ((uint)*(ushort *)(param_1 + 0x11) * 0x38 + 0x34 +
                                    *(int *)(iVar6 + 0x38)),0xffffffff,
                                   ((short)param_1[0x10] != *(short *)((int)param_1 + 0x42)) - 1),
           local_8 < 0)) goto LAB_008dee44;
        *(undefined2 *)(param_1 + 0x11) = 0xffff;
      }
      local_8 = (**(code **)(**(int **)(iVar6 + 0x88) + 0x10))(*(int **)(iVar6 + 0x88));
      if (local_8 < 0) goto LAB_008dee44;
    }
    puVar7 = (undefined4 *)(iVar6 + 0x44);
    for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    puVar7 = *(undefined4 **)(iVar6 + 0x40);
    for (uVar4 = (uint)*(ushort *)(iVar6 + 0x3c) * 0x68 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar7 = 0;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(iVar6 + 0x34);
    }
    if (param_1[0xe] != 0) {
      piVar1 = (int *)(param_1[0xe] + 8);
      *piVar1 = *piVar1 + 1;
      *(int **)(param_1[0xe] + 0xc) = param_1;
    }
    param_1[0xf] = 4;
  }
  else {
    local_8 = -0x7789f794;
  }
LAB_008dee44:
  param_1[2] = iVar2;
  return local_8;
}


// ==== FUN_008dee52 @ 0x008dee52 ====

int FUN_008dee52(uint param_1,uint param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float *pfVar7;
  int in_ECX;
  uint uVar8;
  uint uVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  float *pfVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar17;
  float10 fVar18;
  float10 extraout_ST0_01;
  float10 fVar19;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float local_1c [4];
  int *local_c;
  int local_8;
  
  local_8 = 0;
  local_c = (int *)(param_1 * 100 + *(int *)(in_ECX + 0x2c));
  iVar12 = param_2 * 100 + local_c[1];
  if ((*(byte *)(iVar12 + 0x30) & 4) == 0) {
    if (*(int *)(iVar12 + 0x38) != 0) {
      local_8 = FUN_008dde39(param_1,param_2);
      if (local_8 < 0) {
        return local_8;
      }
      local_8 = FUN_008dae25(param_1,param_2);
      if (local_8 < 0) {
        return local_8;
      }
    }
  }
  else {
    uVar9 = *(uint *)(iVar12 + 0x60);
    puVar14 = *(undefined4 **)(iVar12 + 0x5c);
    puVar15 = *(undefined4 **)(iVar12 + 8);
    for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar15 = *puVar14;
      puVar14 = puVar14 + 1;
      puVar15 = puVar15 + 1;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined1 *)puVar15 = *(undefined1 *)puVar14;
      puVar14 = (undefined4 *)((int)puVar14 + 1);
      puVar15 = (undefined4 *)((int)puVar15 + 1);
    }
  }
  pfVar10 = (float *)(*(int *)(iVar12 + 0x48) + *local_c);
  pfVar13 = *(float **)(iVar12 + 8);
  iVar5 = (uint)*(ushort *)(iVar12 + 0x52) * 0x1c;
  piVar1 = *(int **)(iVar12 + 0xc);
  iVar12 = *piVar1;
  if (*(int *)(&DAT_00a218dc + iVar5) == 3) {
    if (iVar12 == 1) {
      param_2 = piVar1[5];
      uVar9 = piVar1[6];
      if (uVar9 == 1) {
        uVar9 = 0x10;
        if (param_2 < 0x11) {
          uVar9 = param_2;
        }
        if (uVar9 == 0) {
          return local_8;
        }
        iVar12 = (int)pfVar13 - (int)pfVar10;
        do {
          *pfVar10 = (float)*(int *)((int)pfVar10 + iVar12);
          pfVar10 = pfVar10 + 1;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
        return local_8;
      }
      if (4 < param_2) {
        param_2 = 4;
      }
      param_1 = 4;
      if (uVar9 < 5) {
        param_1 = uVar9;
      }
      if (param_2 == 0) {
        return local_8;
      }
      do {
        if (param_1 != 0) {
          pfVar7 = pfVar13;
          pfVar11 = pfVar10;
          uVar8 = param_1;
          do {
            fVar6 = *pfVar7;
            pfVar7 = pfVar7 + 1;
            *pfVar11 = (float)(int)fVar6;
            pfVar11 = pfVar11 + 1;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
        }
        pfVar10 = pfVar10 + 4;
        pfVar13 = pfVar13 + uVar9;
        param_2 = param_2 - 1;
      } while (param_2 != 0);
      return local_8;
    }
    if (iVar12 != 2) {
      if (iVar12 != 3) {
        return -0x7fffbffb;
      }
      local_c = (int *)piVar1[5];
      uVar9 = piVar1[6];
      if (uVar9 == 1) {
        uVar9 = 0x10;
        if (local_c < 0x11) {
          uVar9 = (uint)local_c;
        }
        if (uVar9 == 0) {
          return local_8;
        }
        iVar12 = (int)pfVar13 - (int)pfVar10;
        do {
          *pfVar10 = *(float *)(iVar12 + (int)pfVar10);
          pfVar10 = pfVar10 + 1;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
        return local_8;
      }
      if (4 < local_c) {
        local_c = (int *)4;
      }
      param_1 = 4;
      if (uVar9 < 5) {
        param_1 = uVar9;
      }
      if (local_c == (int *)0x0) {
        return local_8;
      }
      do {
        if (param_1 != 0) {
          param_2 = param_1;
          pfVar7 = pfVar13;
          pfVar11 = pfVar10;
          do {
            *pfVar11 = *pfVar7;
            pfVar7 = pfVar7 + 1;
            pfVar11 = pfVar11 + 1;
            param_2 = param_2 - 1;
          } while (param_2 != 0);
        }
        pfVar10 = pfVar10 + 4;
        pfVar13 = pfVar13 + uVar9;
        local_c = (int *)((int)local_c - 1);
      } while (local_c != (int *)0x0);
      return local_8;
    }
    uVar9 = piVar1[5];
    uVar8 = piVar1[6];
    if (uVar8 == 1) {
      if (uVar9 == 1) {
        if ((*(int *)(&DAT_00a218e0 + iVar5) == 1) && (*(int *)(&DAT_00a218e4 + iVar5) == 4)) {
          fVar6 = *pfVar13;
          fVar2 = (float)((uint)fVar6 >> 8 & 0xff) * DAT_0099d0b0;
          fVar3 = (float)((uint)fVar6 & 0xff) * DAT_0099d0b0;
          fVar4 = (float)((uint)fVar6 >> 0x18) * DAT_0099d0b0;
          *pfVar10 = (float)((uint)fVar6 >> 0x10 & 0xff) * DAT_0099d0b0;
          pfVar10[1] = fVar2;
          pfVar10[2] = fVar3;
          pfVar10[3] = fVar4;
          return local_8;
        }
      }
      else if (0x10 < uVar9) {
        uVar9 = 0x10;
      }
      if (uVar9 == 0) {
        return local_8;
      }
      iVar12 = (int)pfVar13 - (int)pfVar10;
      do {
        *pfVar10 = (float)*(int *)((int)pfVar10 + iVar12);
        pfVar10 = pfVar10 + 1;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
      return local_8;
    }
    param_2 = 4;
    if (uVar9 < 5) {
      param_2 = uVar9;
    }
    param_1 = 4;
    if (uVar8 < 5) {
      param_1 = uVar8;
    }
    if (param_2 == 0) {
      return local_8;
    }
    do {
      if (param_1 != 0) {
        pfVar7 = pfVar13;
        pfVar11 = pfVar10;
        uVar9 = param_1;
        do {
          fVar6 = *pfVar7;
          pfVar7 = pfVar7 + 1;
          *pfVar11 = (float)(int)fVar6;
          pfVar11 = pfVar11 + 1;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
      pfVar10 = pfVar10 + 4;
      pfVar13 = pfVar13 + uVar8;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
    return local_8;
  }
  if (*(int *)(&DAT_00a218dc + iVar5) != 0xf20000) {
    return -0x7fffbffb;
  }
  local_1c[0] = 0.0;
  local_1c[1] = 0.0;
  local_1c[2] = 0.0;
  local_1c[3] = 0.0;
  if (iVar12 == 1) {
    uVar9 = piVar1[5];
    if (uVar9 == 1) {
LAB_008df00d:
      fVar6 = *pfVar13;
      goto LAB_008df00f;
    }
    uVar8 = 4;
    if (uVar9 < 5) {
      uVar8 = uVar9;
    }
    uVar9 = 0;
    if (uVar8 != 0) {
      do {
        uVar16 = uVar9 + 1;
        local_1c[uVar9] = (float)(int)pfVar13[uVar9];
        uVar9 = uVar16;
      } while (uVar16 < uVar8);
    }
  }
  else if (iVar12 == 2) {
    uVar9 = piVar1[5];
    if (uVar9 == 1) goto LAB_008df00d;
    uVar8 = 4;
    if (uVar9 < 5) {
      uVar8 = uVar9;
    }
    uVar9 = 0;
    if (uVar8 != 0) {
      do {
        uVar16 = uVar9 + 1;
        local_1c[uVar9] = (float)(int)pfVar13[uVar9];
        uVar9 = uVar16;
      } while (uVar16 < uVar8);
    }
  }
  else {
    if (iVar12 != 3) {
      return -0x7fffbffb;
    }
    uVar9 = piVar1[5];
    if (uVar9 == 1) {
      fVar6 = (float)__ftol();
      goto LAB_008df00f;
    }
    if (4 < uVar9) {
      uVar9 = 4;
    }
    if (uVar9 != 0) {
      pfVar7 = local_1c;
      for (; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pfVar7 = *pfVar13;
        pfVar13 = pfVar13 + 1;
        pfVar7 = pfVar7 + 1;
      }
    }
  }
  fVar17 = (float10)DAT_0099d080;
  uVar9 = 0xff;
  fVar18 = (float10)DAT_0099cdc8;
  if ((float10)local_1c[0] < fVar17) {
    fVar19 = (float10)local_1c[0];
    if ((NAN(fVar19) || NAN(fVar18)) || fVar19 < fVar18 == (fVar19 == fVar18)) {
      param_1 = __ftol();
      fVar18 = extraout_ST0;
      fVar17 = extraout_ST1;
    }
    else {
      param_1 = 0;
    }
  }
  else {
    param_1 = 0xff;
  }
  if ((float10)local_1c[1] < fVar17) {
    fVar19 = (float10)local_1c[1];
    if ((NAN(fVar19) || NAN(fVar18)) || fVar19 < fVar18 == (fVar19 == fVar18)) {
      uVar8 = __ftol();
      fVar18 = extraout_ST0_01;
      fVar17 = extraout_ST1_00;
    }
    else {
      uVar8 = 0;
    }
  }
  else {
    uVar8 = uVar9;
  }
  if ((float10)local_1c[2] < fVar17) {
    fVar19 = (float10)local_1c[2];
    if ((NAN(fVar19) || NAN(fVar18)) || fVar19 < fVar18 == (fVar19 == fVar18)) {
      uVar16 = __ftol();
      fVar17 = extraout_ST0_00;
    }
    else {
      uVar16 = 0;
    }
  }
  else {
    uVar16 = 0xff;
  }
  if ((float10)local_1c[3] < fVar17) {
    if ((NAN(local_1c[3]) || NAN(DAT_0099cdc8)) ||
        local_1c[3] < DAT_0099cdc8 == (local_1c[3] == DAT_0099cdc8)) {
      uVar9 = __ftol();
    }
    else {
      uVar9 = 0;
    }
  }
  fVar6 = (float)(((uVar9 << 8 | param_1) << 8 | uVar8) << 8 | uVar16);
LAB_008df00f:
  *pfVar10 = fVar6;
  return local_8;
}


// ==== FUN_008df302 @ 0x008df302 ====

void FUN_008df302(void)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = 0xffffffff;
  in_ECX[9] = 0;
  in_ECX[8] = 0;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[4] = 3;
  in_ECX[0xf] = 0;
  in_ECX[0xd] = 0;
  in_ECX[10] = 0;
  *(undefined2 *)((int)in_ECX + 0x46) = 0;
  in_ECX[0x10] = 0;
  return;
}


// ==== FUN_008df32d @ 0x008df32d ====

void FUN_008df32d(void)

{
  void *_Memory;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x3c) != 0) {
    _Memory = *(void **)(in_ECX + 0x3c);
    *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)((int)_Memory + 0x3c);
    *(undefined4 *)((int)_Memory + 0x3c) = 0;
    FUN_008df32d();
    _free(_Memory);
    return;
  }
  if (*(int *)(in_ECX + 0x40) != 0) {
    FUN_008bc860(1);
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  FUN_008de297();
  return;
}


// ==== FUN_008df375 @ 0x008df375 ====

void FUN_008df375(byte param_1)

{
  void *in_ECX;
  
  FUN_008df32d();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008df396 @ 0x008df396 ====

void FUN_008df396(byte param_1)

{
  void *in_ECX;
  
  if ((param_1 & 2) == 0) {
    FUN_008de31c();
    if ((param_1 & 1) != 0) {
      _free(in_ECX);
      return;
    }
  }
  else {
    FUN_0049b480(in_ECX,100,*(undefined4 *)((int)in_ECX + -4),FUN_008de31c);
    if ((param_1 & 1) != 0) {
      _free((undefined4 *)((int)in_ECX + -4));
      return;
    }
  }
  return;
}


// ==== FUN_008df3e4 @ 0x008df3e4 ====

undefined4 FUN_008df3e4(ushort param_1)

{
  uint *puVar1;
  int in_ECX;
  uint uVar2;
  uint *puVar3;
  
  if (*(ushort *)(in_ECX + 0x38) < param_1) {
    uVar2 = (uint)param_1;
    puVar1 = operator_new(uVar2 * 100 + 4);
    if (puVar1 == (uint *)0x0) {
      puVar3 = (uint *)0x0;
    }
    else {
      puVar3 = puVar1 + 1;
      *puVar1 = uVar2;
      FUN_0040d030(puVar3,100,uVar2,&LAB_008de2cc);
    }
    if (puVar3 == (uint *)0x0) {
      return 0x8007000e;
    }
    if (*(int *)(in_ECX + 4) != 0) {
      FUN_008df396(3);
      *(undefined4 *)(in_ECX + 4) = 0;
    }
    *(uint **)(in_ECX + 4) = puVar3;
    *(ushort *)(in_ECX + 0x38) = param_1;
  }
  *(ushort *)(in_ECX + 0x36) = param_1;
  return 0;
}


// ==== FUN_008df464 @ 0x008df464 ====

void FUN_008df464(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x30) != 0) {
    FUN_008df375(1);
    *(undefined4 *)(in_ECX + 0x30) = 0;
  }
  FUN_008de297();
  return;
}


// ==== FUN_008df483 @ 0x008df483 ====

void FUN_008df483(byte param_1)

{
  void *in_ECX;
  
  if ((param_1 & 2) == 0) {
    FUN_008df464();
    if ((param_1 & 1) != 0) {
      _free(in_ECX);
      return;
    }
  }
  else {
    FUN_0049b480(in_ECX,0x38,*(undefined4 *)((int)in_ECX + -4),FUN_008df464);
    if ((param_1 & 1) != 0) {
      _free((undefined4 *)((int)in_ECX + -4));
      return;
    }
  }
  return;
}


// ==== FUN_008df4d1 @ 0x008df4d1 ====

int FUN_008df4d1(void)

{
  undefined4 *in_ECX;
  int extraout_EDX;
  
  *in_ECX = &PTR_FUN_00a23090;
  in_ECX[1] = &PTR_FUN_00a22eb0;
  in_ECX[4] = 0;
  in_ECX[3] = 0;
  in_ECX[2] = 0;
  FUN_008df302();
  FUN_008d8f08();
  *(ushort *)(extraout_EDX + 0x118) = *(ushort *)(extraout_EDX + 0x118) & 0xe478;
  *(undefined4 *)(extraout_EDX + 0x38) = 0;
  *(undefined4 *)(extraout_EDX + 0x9c) = 0;
  *(undefined4 *)(extraout_EDX + 0xa4) = 0;
  *(undefined4 *)(extraout_EDX + 0x18) = 0;
  *(undefined4 *)(extraout_EDX + 0x20) = 0;
  *(undefined4 *)(extraout_EDX + 0xb0) = 0;
  *(undefined4 *)(extraout_EDX + 0x28) = 0;
  *(undefined4 *)(extraout_EDX + 0xc4) = 0;
  *(undefined4 *)(extraout_EDX + 0x100) = 0;
  *(undefined4 *)(extraout_EDX + 0x104) = 0;
  *(undefined4 *)(extraout_EDX + 0xb4) = 0;
  *(undefined4 *)(extraout_EDX + 0xc0) = 0;
  *(undefined4 *)(extraout_EDX + 0xb8) = 0;
  *(undefined4 *)(extraout_EDX + 0xbc) = 0;
  *(undefined4 *)(extraout_EDX + 200) = 0;
  *(undefined4 *)(extraout_EDX + 0xcc) = 0;
  *(undefined2 *)(extraout_EDX + 0x30) = 0;
  *(undefined4 *)(extraout_EDX + 0x34) = 0;
  *(undefined4 *)(extraout_EDX + 0x2c) = 0;
  *(undefined4 *)(extraout_EDX + 0xd0) = 0;
  *(undefined4 *)(extraout_EDX + 0xd4) = 0;
  *(undefined4 *)(extraout_EDX + 0xd8) = 0;
  *(undefined4 *)(extraout_EDX + 0xdc) = 0;
  *(undefined4 *)(extraout_EDX + 0x114) = 0;
  *(undefined4 *)(extraout_EDX + 0x74) = 0;
  *(undefined4 *)(extraout_EDX + 0x78) = 0;
  *(undefined4 *)(extraout_EDX + 0x60) = 0;
  *(undefined4 *)(extraout_EDX + 100) = 0;
  *(undefined4 *)(extraout_EDX + 0x5c) = 0;
  *(undefined4 *)(extraout_EDX + 0x108) = 0;
  *(undefined4 *)(extraout_EDX + 0x10c) = 0;
  *(undefined4 *)(extraout_EDX + 0x110) = 0;
  *(undefined4 *)(extraout_EDX + 0x128) = 0;
  *(undefined4 *)(extraout_EDX + 0x124) = 0;
  *(undefined4 *)(extraout_EDX + 300) = 0;
  *(undefined4 *)(extraout_EDX + 0x120) = 0;
  *(undefined4 *)(extraout_EDX + 0x11c) = 0;
  *(undefined4 *)(extraout_EDX + 0x3c) = 0;
  *(undefined4 *)(extraout_EDX + 0x24) = 1;
  return extraout_EDX;
}


// ==== FUN_008df5d1 @ 0x008df5d1 ====

void FUN_008df5d1(byte param_1)

{
  void *in_ECX;
  
  FUN_008de3d6();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008df5f2 @ 0x008df5f2 ====

void FUN_008df5f2(byte param_1)

{
  void *in_ECX;
  
  if ((param_1 & 2) == 0) {
    FUN_008df32d();
    if ((param_1 & 1) != 0) {
      _free(in_ECX);
      return;
    }
  }
  else {
    FUN_0049b480(in_ECX,0x50,*(undefined4 *)((int)in_ECX + -4),FUN_008df32d);
    if ((param_1 & 1) != 0) {
      _free((undefined4 *)((int)in_ECX + -4));
      return;
    }
  }
  return;
}


// ==== FUN_008df640 @ 0x008df640 ====

int FUN_008df640(uint param_1,int param_2,int *param_3,uint *param_4)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int in_ECX;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  iVar4 = param_1 * 100 + *(int *)(in_ECX + 0x2c);
  puVar10 = (undefined4 *)(param_2 * 100 + *(int *)(iVar4 + 4));
  if ((*(int *)(&DAT_00a218dc + (uint)*(ushort *)((int)puVar10 + 0x52) * 0x1c) != 0x10) &&
     (*(int *)(&DAT_00a218dc + (uint)*(ushort *)((int)puVar10 + 0x52) * 0x1c) != 0xf)) {
    return 0;
  }
  if ((param_3 != (int *)0x0) &&
     (uVar5 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar5)) {
    iVar6 = (**(code **)(*param_3 + 0xc))(param_3);
    param_1 = *(uint *)(iVar6 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if ((param_3 != (int *)0x0) &&
     (uVar5 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 <= uVar5)) {
    piVar2 = (int *)(*(int *)(in_ECX + 0xb0) + puVar10[7] * 4);
    iVar6 = *piVar2;
    if (*(int *)(iVar6 + 0x40) == 0) {
      iVar6 = *(int *)(*(int *)(iVar6 + 0x30) + puVar10[9] + *(int *)(in_ECX + 0x20));
    }
    else {
      iVar6 = *piVar2;
      iVar6 = *(int *)(*(int *)(*(int *)(iVar6 + 0x40) + 8) +
                      *(int *)(*(int *)(iVar6 + 0x30) + puVar10[9] +
                              *(int *)(*(int *)(in_ECX + 0x38) + 0x10)) * 4);
    }
    piVar2 = (int *)(*(int *)(in_ECX + 0x18) + iVar6 * 0x18);
    if ((uint)*(ushort *)(in_ECX + 0x30) < *(uint *)(in_ECX + 0x34)) {
      *(ushort *)(piVar2 + 4) = *(ushort *)(in_ECX + 0x30);
      *(short *)(in_ECX + 0x30) = *(short *)(in_ECX + 0x30) + 1;
      iVar6 = FUN_008df3e4(1);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar9 = *(int *)(&DAT_00a218dc + (uint)*(ushort *)((int)puVar10 + 0x52) * 0x1c);
      *piVar2 = iVar9;
      iVar7 = (uint)*(ushort *)(piVar2 + 4) * 100 + *(int *)(in_ECX + 0x2c);
      if (iVar9 == 0x10) {
        *(undefined2 *)(iVar7 + 0x18) = 0;
        *(undefined2 *)(*(int *)(iVar7 + 4) + 0x52) = 0x92;
        *(undefined4 *)(*(int *)(iVar7 + 4) + 0x58) = 0xa000000;
      }
      else {
        *(undefined2 *)(iVar7 + 0x1a) = 0;
        *(undefined2 *)(*(int *)(iVar7 + 4) + 0x52) = 0x93;
        *(undefined4 *)(*(int *)(iVar7 + 4) + 0x58) = 0xb000000;
      }
      *(undefined2 *)(*(int *)(iVar7 + 4) + 0x54) = 0xffff;
      *(undefined2 *)(*(int *)(iVar7 + 4) + 0x56) = 1;
      puVar1 = (uint *)(*(int *)(iVar7 + 4) + 0x30);
      *puVar1 = *puVar1 | 1;
      **(undefined4 **)(iVar7 + 4) = 1;
      puVar8 = puVar10 + 2;
      puVar11 = (undefined4 *)(*(int *)(iVar7 + 4) + 8);
      for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
      *(undefined4 *)(*(int *)(iVar7 + 4) + 0x28) = 0;
      *(undefined4 *)(*(int *)(iVar7 + 4) + 0x2c) = 0;
      if (param_1 == 0) {
        return iVar6;
      }
      iVar6 = FUN_008eb3df(param_1,piVar2 + 2);
      if (iVar6 < 0) {
        return iVar6;
      }
      piVar3 = (int *)piVar2[2];
      puVar8 = (undefined4 *)(**(code **)(*piVar3 + 0xc))(piVar3);
      iVar6 = (uint)((param_1 & 3) != 0) + (param_1 >> 2);
      uVar5 = (**(code **)(*param_3 + 0x10))(param_3);
      if (*param_4 + iVar6 <= uVar5) {
        iVar9 = (**(code **)(*param_3 + 0xc))(param_3);
        puVar11 = (undefined4 *)(iVar9 + *param_4 * 4);
        for (uVar5 = param_1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar8 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar8 = puVar8 + 1;
        }
        for (param_1 = param_1 & 3; param_1 != 0; param_1 = param_1 - 1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar11;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
      }
      *param_4 = *param_4 + iVar6;
      uVar5 = (**(code **)(*param_3 + 0x10))(param_3);
      if (*param_4 <= uVar5) {
        if (*piVar2 == 0x10) {
          FUN_008d5d05(piVar2);
        }
        else {
          FUN_008d5d63(piVar2);
        }
        *(undefined2 *)(puVar10 + 0x15) = 0xffff;
        *puVar10 = 0;
        *(undefined2 *)((int)puVar10 + 0x52) = 0xb3;
        puVar10[0x16] = 0xe000000;
        *(undefined2 *)((int)puVar10 + 0x56) = 1;
        *(short *)(iVar4 + 0x34) = *(short *)(iVar4 + 0x34) + 1;
        iVar6 = (*(uint *)(iVar4 + 0xc) & 3) + (*(uint *)(iVar4 + 0xc) & 0xfffffffc);
        *(int *)(iVar4 + 0xc) = iVar6;
        puVar10[0x12] = iVar6;
        *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 4;
        return 0;
      }
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008df8be @ 0x008df8be ====

uint FUN_008df8be(int *param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int in_ECX;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  int *piVar14;
  int iVar15;
  undefined4 *puVar16;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar13 = param_2;
  puVar5 = (uint *)(*(int *)(in_ECX + 0x1c) + *(int *)(in_ECX + 0x20));
  piVar14 = (int *)*param_1;
  puVar1 = (uint *)(piVar14 + 5);
  if (puVar5 < puVar1) {
    return 0x80004005;
  }
  iVar12 = *piVar14;
  local_10 = piVar14[4];
  uVar6 = FUN_008d604f(piVar14[2]);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  uVar6 = FUN_008d5ff3(piVar14[3]);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  if (local_10 == 0) {
    local_10 = 1;
  }
  uVar6 = local_10;
  iVar10 = piVar14[1];
  if (iVar10 < 0) {
    return 0x80004005;
  }
  if (iVar10 < 4) {
    if (iVar12 < 1) {
      return 0x80004005;
    }
    if ((2 < iVar12) && (iVar12 != 3)) {
      return 0x80004005;
    }
    uVar6 = -(uint)(puVar5 < piVar14 + 7) & 0x80004005;
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    iVar12 = piVar14[6] * *puVar1 * local_10;
    uVar6 = -(uint)(puVar5 < piVar14 + iVar12) & 0x80004005;
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    *param_2 = *param_2 + iVar12 * 4;
    *param_1 = *param_1 + 0x1c;
    return uVar6;
  }
  if (iVar10 != 4) {
    if (iVar10 != 5) {
      return 0x80004005;
    }
    if (iVar12 != 0) {
      return 0x80004005;
    }
    puVar13 = (uint *)(piVar14 + 6);
    uVar7 = -(uint)(puVar5 < puVar13) & 0x80004005;
    if ((int)uVar7 < 0) {
      return uVar7;
    }
    uVar3 = *puVar1;
    *param_1 = (int)puVar13;
    local_8 = 0;
    if (local_10 == 0) {
      return uVar7;
    }
    do {
      *param_1 = (int)puVar13;
      local_10 = 0;
      if (uVar3 != 0) {
        do {
          uVar7 = FUN_008df8be(param_1,param_2,param_3);
          if ((int)uVar7 < 0) {
            return uVar7;
          }
          local_10 = local_10 + 1;
        } while (local_10 < uVar3);
      }
      local_8 = local_8 + 1;
    } while (local_8 < uVar6);
    return uVar7;
  }
  uVar6 = 0;
  if (iVar12 < 4) {
    return 0x80004005;
  }
  if (9 < iVar12) {
    if (iVar12 < 0xf) {
      iVar12 = *(int *)(*(int *)(in_ECX + 0xb0) + param_3 * 4);
      if (*(short *)(iVar12 + 0x46) != 0) {
        return 0x80004005;
      }
      local_8 = 0;
      *(short *)(iVar12 + 0x46) = (short)local_10;
      *(short *)(in_ECX + 0x30) = *(short *)(in_ECX + 0x30) + (short)local_10;
      if (local_10 != 0) {
        do {
          iVar10 = (*(ushort *)(iVar12 + 0x44) + local_8) * 100 + *(int *)(in_ECX + 0x2c);
          *(undefined2 *)(iVar10 + 0x3e) = (undefined2)param_3;
          piVar14 = (int *)*puVar13 + 1;
          uVar6 = -(uint)((int *)(*(int *)(in_ECX + 0x1c) + *(int *)(in_ECX + 0x20)) < piVar14) &
                  0x80004005;
          if ((int)uVar6 < 0) {
            return uVar6;
          }
          iVar15 = *(int *)*puVar13;
          *puVar13 = (uint)piVar14;
          iVar11 = FUN_008df3e4(iVar15);
          if (iVar11 < 0) {
            return 0x8007000e;
          }
          uVar6 = -(uint)((uint)(*(int *)(in_ECX + 0x1c) + *(int *)(in_ECX + 0x20)) <
                         iVar15 * 0x10 + *puVar13) & 0x80004005;
          if ((int)uVar6 < 0) {
            return uVar6;
          }
          local_c = 0;
          if (*(short *)(iVar10 + 0x36) != 0) {
            param_2 = (uint *)0x0;
            do {
              puVar9 = (undefined4 *)(*(int *)(iVar10 + 4) + (int)param_2);
              puVar9[0xc] = puVar9[0xc] & 0xfffffffd;
              *puVar9 = 1;
              *(undefined2 *)((int)puVar9 + 0x52) = *(undefined2 *)*puVar13;
              *puVar13 = *puVar13 + 4;
              puVar9[0x16] = *(undefined4 *)
                              (&DAT_00a218ec + (uint)*(ushort *)((int)puVar9 + 0x52) * 0x1c);
              *(undefined2 *)(puVar9 + 0x15) = *(undefined2 *)*puVar13;
              *puVar13 = *puVar13 + 4;
              *(undefined2 *)(puVar9 + 0x15) = 0xffff;
              puVar9[8] = *(undefined4 *)*puVar13;
              *puVar13 = *puVar13 + 4;
              puVar9[9] = *(undefined4 *)*puVar13;
              *puVar13 = *puVar13 + 4;
              puVar9[7] = 0;
              puVar9[3] = puVar9[8] + *(int *)(in_ECX + 0x20);
              puVar9[2] = *(int *)(in_ECX + 0x20) + puVar9[9];
              uVar2 = *(ushort *)((int)puVar9 + 0x52);
              if (0xb5 < uVar2) {
                return 0x80004005;
              }
              if (puVar9[0x16] == 0x9000000) {
                *(undefined4 *)
                 (*(int *)(in_ECX + 0x18) + *(int *)(puVar9[9] + *(int *)(in_ECX + 0x20)) * 0x18) =
                     *(undefined4 *)(&DAT_00a218dc + (uint)uVar2 * 0x1c);
              }
              else {
                if ((puVar9[0x16] & 0xff000000) != 0x3000000) {
                  return 0x80004005;
                }
                iVar11 = (uint)uVar2 * 0x1c;
                iVar15 = *(int *)(&DAT_00a218dc + iVar11);
                if ((((iVar15 != 1) && (iVar15 != 2)) && (iVar15 != 3)) && (iVar15 != 0xf20000)) {
                  return 0x80004005;
                }
                iVar4 = *(int *)(&DAT_00a218e4 + iVar11);
                iVar11 = *(int *)(&DAT_00a218e0 + iVar11);
                uVar7 = (*(uint *)(iVar10 + 0xc) & 3) + (*(uint *)(iVar10 + 0xc) & 0xfffffffc);
                uVar7 = (uVar7 & 1) + (uVar7 & 0xfffffffe);
                uVar7 = (uVar7 & 3) + (uVar7 & 0xfffffffc);
                uVar7 = (uVar7 & 3) + (uVar7 & 0xfffffffc);
                iVar15 = (uVar7 & 3) + (uVar7 & 0xfffffffc);
                *(int *)(iVar10 + 0xc) = iVar15;
                puVar9[0x12] = iVar15;
                *(int *)(iVar10 + 0xc) = *(int *)(iVar10 + 0xc) + iVar4 * iVar11 * 4;
                puVar9[0xc] = puVar9[0xc] & 0xfffffffd;
                *puVar9 = 1;
              }
              local_c = local_c + 1;
              param_2 = (uint *)((int)param_2 + 100);
            } while (local_c < *(ushort *)(iVar10 + 0x36));
          }
          local_8 = local_8 + 1;
        } while (local_8 < local_10);
      }
      goto LAB_008dfde1;
    }
    if (0x10 < iVar12) {
      return 0x80004005;
    }
  }
  uVar6 = -(uint)(puVar5 < (uint *)(*param_2 + local_10 * 4)) & 0x80004005;
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  local_8 = 0;
  if (local_10 != 0) {
    do {
      uVar7 = *(uint *)*param_2;
      if (*(uint *)(in_ECX + 0x14) <= uVar7) {
        return 0x80004005;
      }
      if (uVar7 == 0) {
        return 0x80004005;
      }
      iVar10 = uVar7 * 0x18;
      piVar14 = (int *)(*(int *)(in_ECX + 0x18) + iVar10);
      if (*piVar14 != 0x7fffffff) {
        return 0x80004005;
      }
      *piVar14 = iVar12;
      puVar1 = (uint *)(iVar10 + 0x14 + *(int *)(in_ECX + 0x18));
      *puVar1 = *puVar1 | 1;
      if ((iVar12 == 0x10) || (iVar12 == 0xf)) {
        puVar9 = *(undefined4 **)(*(int *)(in_ECX + 0xb0) + param_3 * 4);
        if (*(uint *)(in_ECX + 0x34) <= (uint)*(ushort *)(in_ECX + 0x30)) {
          return 0x80004005;
        }
        *(ushort *)(iVar10 + 0x10 + *(int *)(in_ECX + 0x18)) = *(ushort *)(in_ECX + 0x30);
        *(short *)((int)puVar9 + 0x46) = *(short *)((int)puVar9 + 0x46) + 1;
        *(short *)(in_ECX + 0x30) = *(short *)(in_ECX + 0x30) + 1;
        iVar10 = (*(ushort *)(puVar9 + 0x11) - 1) + (uint)*(ushort *)((int)puVar9 + 0x46);
        iVar15 = iVar10 * 100 + *(int *)(in_ECX + 0x2c);
        *(undefined2 *)(iVar15 + 0x3e) = (undefined2)param_3;
        if (*(short *)(iVar15 + 0x38) != 0) {
          return 0x80004005;
        }
        uVar6 = FUN_008df3e4(1);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        if (iVar12 == 0x10) {
          *(undefined2 *)(iVar15 + 0x18) = 0;
          *(undefined2 *)(*(int *)(iVar15 + 4) + 0x52) = 0x92;
          *(undefined4 *)(*(int *)(iVar15 + 4) + 0x58) = 0xa000000;
        }
        else {
          *(undefined2 *)(iVar15 + 0x1a) = 0;
          *(undefined2 *)(*(int *)(iVar15 + 4) + 0x52) = 0x93;
          *(undefined4 *)(*(int *)(iVar15 + 4) + 0x58) = 0xb000000;
        }
        *(undefined2 *)(*(int *)(iVar15 + 4) + 0x54) = 0xffff;
        *(undefined2 *)(*(int *)(iVar15 + 4) + 0x56) = 1;
        **(undefined4 **)(iVar15 + 4) = 1;
        puVar1 = (uint *)(*(int *)(iVar15 + 4) + 0x30);
        *puVar1 = *puVar1 | 1;
        *(undefined4 *)(*(int *)(iVar15 + 4) + 0x3c) = 0;
        puVar8 = puVar9;
        puVar16 = (undefined4 *)(*(int *)(iVar15 + 4) + 8);
        for (iVar11 = 10; iVar11 != 0; iVar11 = iVar11 + -1) {
          *puVar16 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar16 = puVar16 + 1;
        }
        *(undefined4 *)(*(int *)(iVar15 + 4) + 0x28) = 0;
        *(undefined4 *)(*(int *)(iVar15 + 4) + 0x2c) = 0;
        *(uint *)(*(int *)(iVar15 + 4) + 0x24) = local_8 << 2;
        uVar6 = local_8;
        if (*(int *)(*param_1 + 0x10) == 0) {
          uVar6 = 0xffffffff;
        }
        *(uint *)(*(int *)(iVar15 + 4) + 0x10) = uVar6;
        *(undefined4 *)(*(int *)(iVar15 + 4) + 0x14) = 4;
        puVar8 = operator_new(0x24);
        if (puVar8 == (undefined4 *)0x0) {
          puVar16 = (undefined4 *)0x0;
        }
        else {
          puVar16 = puVar8 + 1;
          *puVar8 = 1;
          FUN_0040d030(puVar16,0x20,1,&LAB_008d5a15);
        }
        *(undefined4 **)(*(int *)(iVar15 + 4) + 0x34) = puVar16;
        if (puVar16 == (undefined4 *)0x0) {
          return 0x8007000e;
        }
        *(undefined2 *)(*(int *)(iVar15 + 4) + 0x50) = 1;
        *(undefined2 *)(*(int *)(iVar15 + 4) + 0x4e) = *(undefined2 *)(*(int *)(iVar15 + 4) + 0x50);
        uVar6 = FUN_008d60b3(iVar10,0,0,puVar9,0);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
      }
      local_8 = local_8 + 1;
      *param_2 = *param_2 + 4;
    } while (local_8 < local_10);
  }
LAB_008dfde1:
  *param_1 = *param_1 + 0x14;
  return uVar6;
}


// ==== FUN_008dfe48 @ 0x008dfe48 ====

/* WARNING: Removing unreachable block (ram,0x008e03e6) */
/* WARNING: Removing unreachable block (ram,0x008e03f2) */

uint FUN_008dfe48(uint param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  int in_ECX;
  int *piVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *local_10;
  void *local_8;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    iVar2 = FUN_008d61a2(param_1,10);
    if (iVar2 == 0) {
      iVar2 = FUN_008d69b4(param_1,10);
      if ((iVar2 == 0) && (iVar2 = FUN_008d6973(param_1,10), iVar2 == 0)) {
        return 0;
      }
      puVar3 = (uint *)(iVar2 + 0x30);
    }
    else {
      puVar3 = (uint *)(iVar2 + 0x3c);
    }
    param_1 = *puVar3;
    if (param_1 != 0) {
      do {
        uVar9 = *(uint *)(param_1 + 0x14);
        iVar2 = *(int *)(param_1 + 4);
        if (uVar9 < *(uint *)(in_ECX + 0xac)) {
          if (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + uVar9 * 4) + 0x40) == 0) {
            iVar4 = *(int *)(in_ECX + 0x20);
          }
          else {
            iVar4 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
          }
        }
        else {
          iVar4 = *(int *)(*(int *)(in_ECX + 0x11c) + (uVar9 - *(uint *)(in_ECX + 0xac)) * 4);
        }
        piVar5 = (int *)(iVar4 + *(int *)(iVar2 + 8));
        piVar7 = (int *)0x0;
        if (*piVar5 != 0) {
          piVar7 = piVar5 + 1;
        }
        for (pcVar8 = param_2; (*pcVar8 == (char)*piVar7 && (*pcVar8 != '\0')); pcVar8 = pcVar8 + 1)
        {
          piVar7 = (int *)((int)piVar7 + 1);
        }
        cVar1 = *pcVar8;
        if (cVar1 == (char)*piVar7) {
          return ~param_1;
        }
        if ((char)*piVar7 == '\0') {
          if (cVar1 == '.') {
            pcVar8 = pcVar8 + 1;
            param_1 = ~param_1;
            goto LAB_008e0082;
          }
          if (cVar1 == '[') {
            pcVar8 = pcVar8 + 1;
            if (*pcVar8 < '0') {
              return 0;
            }
            if ('9' < *pcVar8) {
              return 0;
            }
            uVar9 = _atol(pcVar8);
            if (*(uint *)(iVar2 + 0x10) <= uVar9) {
              return 0;
            }
            for (; ('/' < *pcVar8 && (*pcVar8 < ':')); pcVar8 = pcVar8 + 1) {
            }
            if (*pcVar8 != ']') {
              return 0;
            }
            param_1 = FUN_008d64b8(~param_1,uVar9,param_3);
            if (param_1 == 0) {
              return 0;
            }
            if (pcVar8[1] == '\0') {
              return param_1;
            }
            if (pcVar8[1] != '.') {
              return 0;
            }
            pcVar8 = pcVar8 + 2;
LAB_008e0082:
            uVar9 = FUN_008e4cba(param_1,pcVar8,param_3);
            return uVar9;
          }
        }
        param_1 = *(uint *)(param_1 + 0x3c);
      } while (param_1 != 0);
      param_1 = 0;
    }
    if ((*(byte *)(in_ECX + 0x118) & 2) != 0) {
      cVar1 = *param_2;
      local_8 = (void *)0x0;
      local_10 = (undefined4 *)0x0;
      pcVar8 = param_2;
      do {
        if ((((cVar1 == '.') || (cVar1 == '@')) || (cVar1 == '[')) || (cVar1 == ']'))
        goto LAB_008e03b3;
        pcVar8 = pcVar8 + 1;
        cVar1 = *pcVar8;
      } while (cVar1 != '\0');
      do {
        cVar1 = *param_2;
        param_2 = param_2 + 1;
      } while (cVar1 != '\0');
      local_8 = operator_new(*(int *)(in_ECX + 0xa8) * 4 + 4);
      if ((local_8 == (void *)0x0) ||
         (local_10 = operator_new(*(int *)(in_ECX + 0x120) * 4 + 4), local_10 == (undefined4 *)0x0))
      {
LAB_008e03b3:
        if (param_1 != 0) {
          FUN_008df375(1);
        }
      }
      else {
        pvVar6 = operator_new(0x50);
        if (pvVar6 == (void *)0x0) {
          param_1 = 0;
        }
        else {
          param_1 = FUN_008df302();
        }
        if (param_1 != 0) {
          puVar10 = *(undefined4 **)(in_ECX + 0x11c);
          puVar11 = local_10;
          for (uVar9 = *(uint *)(in_ECX + 0x120) & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          local_10[*(int *)(in_ECX + 0x120)] = 0;
          _free(*(void **)(in_ECX + 0x11c));
          return extraout_EAX;
        }
      }
      if (local_8 != (void *)0x0) {
        _free(local_8);
        return extraout_EAX_00;
      }
      if (local_10 == (undefined4 *)0x0) {
        return 0;
      }
      _free(local_10);
      return extraout_EAX_01;
    }
  }
  return 0;
}


