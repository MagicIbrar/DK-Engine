// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x590000-0x59ffff

// ==== FUN_005904f0 @ 0x005904f0 ====

/* WARNING: Removing unreachable block (ram,0x00590735) */
/* WARNING: Removing unreachable block (ram,0x005906f7) */
/* WARNING: Removing unreachable block (ram,0x00590774) */
/* WARNING: Removing unreachable block (ram,0x005906b8) */

void FUN_005904f0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined1 auStackY_130 [128];
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *_Memory;
  uint uVar10;
  undefined4 uStack_30;
  void *local_1c;
  uint local_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  uStack_30 = (void **)0x6;
  *in_ECX = &PTR_FUN_009bf3fc;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740();
  uStack_30 = &local_1c;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_10) {
    _free(unaff_EBP);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_14) {
    _free(unaff_ESI);
    return;
  }
  uStack_14 = 0xf;
  local_18 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < local_18) {
    _free(unaff_EDI);
    return;
  }
  local_18 = 0xf;
  local_1c = (void *)0x0;
  FUN_00401740();
  _Memory = &uStack_30;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if ((void *)0xf < local_1c) {
    _free(uStack_30);
    return;
  }
  local_1c = (void *)0xf;
  uStack_30 = (void **)((uint)uStack_30 & 0xffffff00);
  FUN_00401740();
  puVar3 = auStackY_130 + 0xfc;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740();
  puVar2 = auStackY_130 + 0xf8;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740();
  puVar1 = auStackY_130 + 0xf4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740();
  puVar6 = auStackY_130 + 0xf0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  uStack_30 = (void **)0x0;
  FUN_00401740();
  puVar5 = auStackY_130 + 0xec;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_30) {
    _free(_Memory);
    return;
  }
  uStack_30 = (void **)0xf;
  uVar10 = 0;
  FUN_00401740();
  puVar4 = auStackY_130 + 0xe8;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar3);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar3 = auStackY_130 + 0xe4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar2);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar2 = auStackY_130 + 0xe0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar1);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar1 = auStackY_130 + 0xdc;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar6);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar6 = auStackY_130 + 0xd8;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar5);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar5 = auStackY_130 + 0xd4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar4);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar4 = auStackY_130 + 0xd0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar3);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar3 = auStackY_130 + 0xcc;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar2);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar2 = auStackY_130 + 200;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar1);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar1 = auStackY_130 + 0xc4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar6);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar6 = auStackY_130 + 0xc0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar5);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar5 = auStackY_130 + 0xbc;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar4);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar4 = auStackY_130 + 0xb8;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar3);
    return;
  }
  uVar10 = 0;
  FUN_00401740();
  puVar3 = auStackY_130 + 0xb4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar2);
    return;
  }
  uVar9 = 0;
  uVar10 = (uint)puVar2 & 0xffffff00;
  FUN_00401740();
  puVar2 = auStackY_130 + 0xb0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar9) {
    _free(puVar1);
    return;
  }
  uVar8 = 0;
  uVar9 = (uint)puVar1 & 0xffffff00;
  FUN_00401740(s_show_effectname_009bf14c);
  puVar1 = auStackY_130 + 0xac;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar8) {
    _free(puVar6);
    return;
  }
  uVar7 = 0;
  uVar8 = (uint)puVar6 & 0xffffff00;
  FUN_00401740(s_reload_split_009bf15c,0xc);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_130 + 0xa8);
  if (0xf < uVar7) {
    _free(puVar5);
    return;
  }
  uVar7 = 0;
  FUN_00401740(s_refresh_damage_009bf16c,0xe);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_130 + 0xa4);
  if (0xf < uVar7) {
    _free(puVar4);
    return;
  }
  FUN_00401830(s_sp_delaytime_009bf17c);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_130 + 0xa0);
  if (0xf < uVar10) {
    _free(puVar3);
    return;
  }
  FUN_00401830(s_previewcamera_009bf18c);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_130 + 0x9c);
  if (0xf < uVar9) {
    _free(puVar2);
    return;
  }
  FUN_00401830(s_ds_showdamage_009bf19c);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_130 + 0x98);
  if (uVar8 < 0x10) {
    DAT_00b5af48 = 0;
    *in_ECX = &PTR_FUN_009bf3bc;
    return;
  }
  _free(puVar1);
  return;
}


// ==== FUN_00590ce0 @ 0x00590ce0 ====

void FUN_00590ce0(void)

{
  void *pvVar1;
  
  if (DAT_00b5af48 == 0) {
    pvVar1 = operator_new(0x20);
    if (pvVar1 != (void *)0x0) {
      FUN_0058f9e0();
      return;
    }
  }
  return;
}


// ==== FUN_00590d00 @ 0x00590d00 ====

undefined4 FUN_00590d00(int param_1)

{
  char cVar1;
  undefined4 ****ppppuVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  int iVar5;
  undefined4 extraout_EAX_00;
  int *piVar6;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 *puVar7;
  float *pfVar8;
  int in_ECX;
  float *pfVar9;
  float10 fVar10;
  void *pvStack_44;
  float local_40;
  undefined4 ****local_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  undefined4 local_2c;
  float local_28;
  undefined1 local_1c [28];
  
  local_28 = 2.10195e-44;
  local_2c = 0;
  local_3c = (undefined4 ****)((uint)local_3c & 0xffffff00);
  FUN_00401740(s_ds_lod_009bf1ac,6);
  iVar5 = param_1 + 8;
  ppppuVar2 = local_3c;
  if ((uint)local_28 < 0x10) {
    ppppuVar2 = &local_3c;
  }
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),ppppuVar2,local_2c);
  if (0xf < (uint)local_28) {
    _free(local_3c);
    return extraout_EAX;
  }
  if (iVar3 == 0) {
    uVar4 = FUN_00459160(&local_40,0);
    iVar5 = thunk_FUN_00796e60(uVar4);
    *(bool *)(in_ECX + 5) = iVar5 != 0;
    if (0xf < (uint)local_28) {
      _free(local_3c);
      return extraout_EAX_00;
    }
  }
  else {
    iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_setmovement_009bf1b4,0xb);
    if (iVar3 != 0) {
      iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_settracealone_009bf1c0,0xd);
      if (iVar3 == 0) {
        uVar4 = FUN_00459160(&local_40,0);
        iVar5 = thunk_FUN_00796e60(uVar4);
        *(bool *)(in_ECX + 4) = iVar5 != 0;
        if ((uint)local_28 < 0x10) {
          return 0;
        }
        _free(local_3c);
        return extraout_EAX_02;
      }
      cVar1 = FUN_004036a0(iVar5,s_show_effectname_009bf1d0);
      if (cVar1 != '\0') {
        piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
        puVar7 = (undefined4 *)(**(code **)(*piVar6 + 0x1c))();
        uVar4 = FUN_00459160(&local_40,0);
        uVar4 = thunk_FUN_00796fb0(uVar4);
        *puVar7 = uVar4;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar1 = FUN_004036a0(iVar5,s_reload_split_009bf1e0);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5afb8 + 0x18))();
        return 1;
      }
      cVar1 = FUN_004036a0(iVar5,s_refresh_damage_009bf1f0);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5afb8 + 0x20))();
        return 1;
      }
      cVar1 = FUN_004036a0(iVar5,s_sp_delaytime_009bf200);
      if (cVar1 != '\0') {
        uVar4 = FUN_00459160(&local_40,0);
        fVar10 = (float10)thunk_FUN_00796ec0(uVar4);
        *(float *)(in_ECX + 8) = (float)fVar10;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar1 = FUN_004036a0(iVar5,s_ds_fov_009bf210);
      if (cVar1 == '\0') {
        cVar1 = FUN_004036a0(iVar5,s_ds_znear_009bf218);
        if (cVar1 == '\0') {
          cVar1 = FUN_004036a0(iVar5,s_ds_clipfar_009bf224);
          if (cVar1 != '\0') {
            uVar4 = FUN_00459160(local_1c,0);
            thunk_FUN_00796ec0(uVar4);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          cVar1 = FUN_004036a0(iVar5,s_ds_zfar_009bf230);
          if (cVar1 != '\0') {
            uVar4 = FUN_00459160(local_1c,0);
            thunk_FUN_00796ec0(uVar4);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          cVar1 = FUN_004036a0(iVar5,s_ds_frustum_009bf238);
          if (cVar1 != '\0') {
            uVar4 = FUN_00459160(local_1c,0);
            thunk_FUN_00796e60(uVar4);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          cVar1 = FUN_004036a0(iVar5,s_3dcamera_culldistance_009bf244);
          if (cVar1 == '\0') {
            cVar1 = FUN_004036a0(iVar5,s_3dcamera_distance_009bf25c);
            if (cVar1 != '\0') {
              pfVar8 = (float *)(**(code **)(*DAT_00b5ae24 + 8))();
              local_40 = *pfVar8;
              local_3c = (undefined4 ****)pfVar8[1];
              fStack_38 = pfVar8[2];
              fStack_34 = pfVar8[3];
              fStack_30 = pfVar8[4];
              uVar4 = FUN_00459160(local_1c,0);
              fVar10 = (float10)thunk_FUN_00796ec0(uVar4);
              local_40 = (float)fVar10;
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0(iVar5,s_3dcamera_zangle_009bf270);
            if (cVar1 != '\0') {
              pfVar8 = (float *)(**(code **)(*DAT_00b5a988 + 0xc))();
              local_40 = *pfVar8;
              local_3c = (undefined4 ****)pfVar8[1];
              fStack_38 = pfVar8[2];
              fStack_34 = pfVar8[3];
              fStack_30 = pfVar8[4];
              uVar4 = FUN_00459160(local_1c,0);
              fVar10 = (float10)thunk_FUN_00796ec0(uVar4);
              fStack_34 = (float)fVar10;
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0(iVar5,s_camera_export_009bf280);
            if (cVar1 != '\0') {
              iVar5 = *DAT_00b5aea4;
              uVar4 = FUN_00459160(local_1c,0);
              (**(code **)(iVar5 + 0x24))(uVar4);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0(iVar5,s_camera_import_009bf290);
            if (cVar1 != '\0') {
              iVar5 = *DAT_00b5aea4;
              uVar4 = FUN_00459160(local_1c,0);
              (**(code **)(iVar5 + 0x28))(uVar4);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0(iVar5,s_camera_strg_distance_009bf2a0);
            if (cVar1 != '\0') {
              pfVar8 = (float *)(**(code **)(*DAT_00b5add8 + 0x14))();
              pfVar9 = &local_40;
              for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
                *pfVar9 = *pfVar8;
                pfVar8 = pfVar8 + 1;
                pfVar9 = pfVar9 + 1;
              }
              uVar4 = FUN_00459160(local_1c,0);
              fVar10 = (float10)FUN_00796ec0(uVar4);
              local_40 = (float)fVar10;
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0(iVar5,s_camera_strg_direction_009bf2b8);
            if (cVar1 != '\0') {
              pfVar8 = (float *)(**(code **)(*DAT_00b5add8 + 0x14))();
              pfVar9 = &local_40;
              for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
                *pfVar9 = *pfVar8;
                pfVar8 = pfVar8 + 1;
                pfVar9 = pfVar9 + 1;
              }
              uVar4 = FUN_00459160(local_1c,0);
              fVar10 = (float10)FUN_00796ec0(uVar4);
              fStack_34 = (float)fVar10;
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0(iVar5,s_camera_strg_target_009bf2d0);
            if (cVar1 != '\0') {
              pfVar8 = (float *)(**(code **)(*DAT_00b5add8 + 0x14))();
              pfVar9 = &local_40;
              for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
                *pfVar9 = *pfVar8;
                pfVar8 = pfVar8 + 1;
                pfVar9 = pfVar9 + 1;
              }
              uVar4 = FUN_00459160(local_1c,0);
              fVar10 = (float10)FUN_00796ec0(uVar4);
              local_28 = (float)fVar10;
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0(iVar5,s_camera_sensitivity_009bf2e4);
            if (cVar1 == '\0') {
              uVar4 = FUN_00401830(s_ds_showgeometry_009bf2f8);
              FUN_00423420(iVar5,uVar4);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            uVar4 = FUN_00459160(local_1c,0);
            FUN_00796ec0(uVar4);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          pfVar8 = (float *)(**(code **)(*DAT_00b5afd0 + 8))();
          local_40 = *pfVar8;
          local_3c = (undefined4 ****)pfVar8[1];
          fStack_38 = pfVar8[2];
          fStack_34 = pfVar8[3];
          uVar4 = FUN_00459160(local_1c,0);
          fVar10 = (float10)thunk_FUN_00796ec0(uVar4);
          fStack_34 = (float)fVar10;
        }
        else {
          pfVar8 = (float *)(**(code **)(*DAT_00b5afd0 + 8))();
          local_40 = *pfVar8;
          local_3c = (undefined4 ****)pfVar8[1];
          fStack_38 = pfVar8[2];
          fStack_34 = pfVar8[3];
          uVar4 = FUN_00459160(local_1c,0);
          fVar10 = (float10)thunk_FUN_00796ec0(uVar4);
          local_3c = (undefined4 ****)(float)fVar10;
        }
      }
      else {
        pfVar8 = (float *)(**(code **)(*DAT_00b5afd0 + 8))();
        local_40 = *pfVar8;
        local_3c = (undefined4 ****)pfVar8[1];
        fStack_38 = pfVar8[2];
        fStack_34 = pfVar8[3];
        uVar4 = FUN_00459160(local_1c,0);
        fVar10 = (float10)thunk_FUN_00796ec0(uVar4);
        local_40 = (float)fVar10;
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar3 = *piVar6;
    uVar4 = FUN_00459160(&local_40,0);
    (**(code **)(iVar3 + 0x10))(iVar5,uVar4);
    if (0xf < (uint)fStack_30) {
      _free(pvStack_44);
      return extraout_EAX_01;
    }
  }
  return 1;
}


// ==== FUN_00591fa0 @ 0x00591fa0 ====

undefined4 FUN_00591fa0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_00590d00(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00591fd0 @ 0x00591fd0 ====

void FUN_00591fd0(void)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = DAT_0099d080;
  uVar1 = DAT_009b0300;
  *(undefined4 *)(in_ECX + 8) = DAT_009bab34;
  *(undefined4 *)(in_ECX + 0xc) = uVar1;
  uVar1 = DAT_009bf3cc;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = uVar1;
  in_ECX[1] = 0;
  *in_ECX = 1;
  in_ECX[2] = 1;
  in_ECX[0x18] = 0;
  return;
}


// ==== FUN_00592050 @ 0x00592050 ====

undefined4 FUN_00592050(void)

{
  return 0x60010010;
}


// ==== FUN_005920a0 @ 0x005920a0 ====

undefined4 FUN_005920a0(void)

{
  return 0x60010002;
}


// ==== FUN_005920b0 @ 0x005920b0 ====

void FUN_005920b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005904f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005920d0 @ 0x005920d0 ====

void FUN_005920d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf410;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005920f0 @ 0x005920f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005920f0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf418;
  FUN_00595bd0();
  FUN_00595aa0();
  FUN_00595850();
  FUN_005957e0();
  FUN_00595770();
  FUN_005956a0();
  FUN_00595660();
  FUN_005955f0();
  FUN_0082b030();
  FUN_0082af60();
  FUN_0082ae90();
  FUN_0082adf0();
  FUN_0082ad20();
  FUN_0082ace0();
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  if (*(int *)(iVar2 + 4) == 0) {
    FUN_0082ac10();
    FUN_0082ab40();
  }
  FUN_005954b0();
  FUN_00595460();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5afd8 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5afd8 = in_ECX;
  return;
}


// ==== FUN_00592190 @ 0x00592190 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00592190(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf418;
  _DAT_00b5afd8 = 0;
  FUN_00595490();
  FUN_00595570();
  FUN_0082ad00();
  FUN_00595720();
  FUN_0082ada0();
  FUN_0082ae50();
  FUN_0082af10();
  FUN_0082afe0();
  FUN_0082b110();
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  if (*(int *)(iVar2 + 4) == 0) {
    FUN_0082ac90();
    FUN_0082abc0();
  }
  FUN_00595630();
  FUN_00595680();
  FUN_005957b0();
  FUN_00595800();
  FUN_00595820();
  FUN_00595b60();
  FUN_00595c00();
  *in_ECX = &PTR_FUN_009bf410;
  return;
}


// ==== FUN_00592220 @ 0x00592220 ====

void FUN_00592220(byte param_1)

{
  void *in_ECX;
  
  FUN_00592190();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00592240 @ 0x00592240 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00592240(float *param_1)

{
  float fVar1;
  int in_ECX;
  
  if ((0.0 < *param_1 || *param_1 == 0.0) && (0.0 < param_1[1] || param_1[1] == 0.0)) {
    fVar1 = (float)*(int *)(in_ECX + 0x40);
    if (*(int *)(in_ECX + 0x40) < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    if (*param_1 < fVar1) {
      fVar1 = (float)*(int *)(in_ECX + 0x44);
      if (*(int *)(in_ECX + 0x44) < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      if (param_1[1] < fVar1) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_005922a0 @ 0x005922a0 ====

void FUN_005922a0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== FUN_005922b0 @ 0x005922b0 ====

void FUN_005922b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf52c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005922d0 @ 0x005922d0 ====

void FUN_005922d0(void)

{
  FUN_0081d670();
  return;
}


// ==== FUN_005922e0 @ 0x005922e0 ====

int FUN_005922e0(void)

{
  int in_ECX;
  
  return in_ECX + 100;
}


// ==== FUN_00592340 @ 0x00592340 ====

uint FUN_00592340(int param_1,undefined4 *param_2,char param_3)

{
  uint in_EAX;
  int iVar1;
  uint uVar2;
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(int *)(in_ECX + 0x14) == 0) ||
     ((*(char *)(in_ECX + 5) == '\0' && (*(char *)(in_ECX + 4) == '\0')))) {
LAB_005923a9:
    return in_EAX & 0xffffff00;
  }
  if (param_3 == '\0') {
    in_EAX = FUN_004a87a0(param_1 + 0xc,&local_c);
    if ((char)in_EAX == '\0') goto LAB_005923a9;
  }
  else {
    iVar1 = (**(code **)(*DAT_00b5a988 + 0x14))();
    uVar2 = FUN_004a8d60(param_1 + 0xc,&local_c,in_ECX + 0x54,iVar1 + 0x34);
    if ((char)uVar2 == '\0') {
      return uVar2;
    }
  }
  param_2[1] = *(undefined4 *)(in_ECX + 0xc);
  *param_2 = 2;
  param_2[2] = local_c;
  param_2[3] = local_8;
  param_2[4] = local_4;
  return CONCAT31((int3)((uint)(param_2 + 2) >> 8),1);
}


// ==== FUN_005923f0 @ 0x005923f0 ====

undefined1 FUN_005923f0(int param_1,float *param_2)

{
  char cVar1;
  int in_ECX;
  float10 extraout_ST0;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    return 0;
  }
  cVar1 = FUN_00592240(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  FUN_004d3e50(param_1,param_1 + 4);
  *param_2 = (float)extraout_ST0;
  return 1;
}


// ==== FUN_00592440 @ 0x00592440 ====

undefined1 FUN_00592440(float *param_1,undefined4 *param_2)

{
  float *pfVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  float10 fVar5;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    return 0;
  }
  cVar2 = FUN_00592240(param_1);
  if (cVar2 == '\0') {
    return 0;
  }
  pfVar1 = param_1 + 1;
  fVar4 = (float10)FUN_004a9180((int)ROUND(*param_1),(int)ROUND(*pfVar1));
  if ((float)fVar4 == DAT_009af6c0) {
    uVar3 = FUN_004d4020(param_1,pfVar1);
    *param_2 = uVar3;
    return 1;
  }
  fVar5 = (float10)FUN_004d3e50(param_1,pfVar1);
  if (fVar5 < (float10)(float)fVar4) {
    *param_2 = 3;
    return 1;
  }
  uVar3 = FUN_004d4020(param_1,pfVar1);
  *param_2 = uVar3;
  return 1;
}


// ==== FUN_00592550 @ 0x00592550 ====

void FUN_00592550(undefined2 *param_1)

{
  FUN_006eb3f0(*param_1,param_1[2]);
  return;
}


// ==== FUN_00592570 @ 0x00592570 ====

void FUN_00592570(undefined2 *param_1)

{
  FUN_006ebe50(*param_1,param_1[2]);
  return;
}


// ==== FUN_00592590 @ 0x00592590 ====

void FUN_00592590(undefined2 *param_1)

{
  FUN_006ebfe0(*param_1,param_1[2]);
  return;
}


// ==== FUN_005925b0 @ 0x005925b0 ====

void FUN_005925b0(undefined2 *param_1)

{
  FUN_006ebcc0(*param_1,param_1[2]);
  return;
}


// ==== FUN_005925d0 @ 0x005925d0 ====

void FUN_005925d0(undefined2 *param_1)

{
  FUN_006ec2b0(*param_1,param_1[2]);
  return;
}


// ==== FUN_00592620 @ 0x00592620 ====

void FUN_00592620(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  
  iVar5 = *(int *)(in_ECX + 0x38);
  if (iVar5 != 0) {
    uVar1 = *(uint *)(iVar5 + 0x3c);
    uVar2 = *(uint *)(iVar5 + 0x40);
    uVar6 = 0;
    if (uVar1 != 0) {
      do {
        uVar7 = 0;
        if (uVar2 != 0) {
          do {
            uVar3 = FUN_004af350(uVar6,uVar7);
            if ((short)uVar3 != 0) {
              FUN_004cd1f0(uVar6 + 1,uVar7 + 1);
              piVar4 = (int *)(**(code **)(*DAT_00b5ab10 + 8))(uVar3);
              if (piVar4 == (int *)0x0) {
                uVar3 = 0xff000000;
              }
              else {
                iVar5 = (**(code **)(*piVar4 + 4))();
                uVar3 = *(undefined4 *)(iVar5 + 4);
              }
              FUN_004cec50(uVar3,uVar6,uVar7);
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar2);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar1);
    }
  }
  return;
}


// ==== FUN_005926d0 @ 0x005926d0 ====

void FUN_005926d0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = 2;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  *(undefined1 *)(in_ECX + 0x25) = 0;
  *(undefined1 *)(in_ECX + 0x26) = 0;
  *(undefined1 *)(in_ECX + 0x27) = 0;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  *(undefined1 *)(in_ECX + 0x29) = 0;
  if (*(void **)(in_ECX + 0x98) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x98) = 0;
    *(undefined4 *)(in_ECX + 0x9c) = 0;
    *(undefined4 *)(in_ECX + 0xa0) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x98));
  return;
}


// ==== FUN_00592720 @ 0x00592720 ====

void FUN_00592720(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 0x34));
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined1 *)(in_ECX + 0x24) = 0;
    (**(code **)(*DAT_00b5afac + 0x10))(*(undefined4 *)(in_ECX + 0x2c));
  }
  uVar1 = FUN_0051edd0(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x34) = uVar1;
  *(undefined1 *)(in_ECX + 0x24) = *(undefined1 *)(param_1 + 4);
  *(undefined1 *)(in_ECX + 0x25) = 1;
  *(undefined1 *)(in_ECX + 0x29) = 0;
  (**(code **)(*DAT_00b5a720 + 0x20))();
  (**(code **)(*DAT_00b5afac + 0xc))(*(undefined4 *)(in_ECX + 0x2c));
  piVar2 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(*(undefined2 *)(param_1 + 6));
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x10))();
    *(undefined4 *)(in_ECX + 0xd0) = *(undefined4 *)(iVar3 + 0x628);
    *(undefined1 *)(in_ECX + 0xd8) = *(undefined1 *)(iVar3 + 0x960);
    *(undefined4 *)(in_ECX + 0xd4) = *(undefined4 *)(iVar3 + 0x830);
  }
  return;
}


// ==== FUN_005927e0 @ 0x005927e0 ====

void FUN_005927e0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 0x38));
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  uVar1 = FUN_00594740(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x38) = uVar1;
  return;
}


// ==== FUN_005929d0 @ 0x005929d0 ====

void FUN_005929d0(int *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (((*(int *)(in_ECX + 0x34) != 0) && (*(int *)(in_ECX + 0x68) != 0)) &&
     (*(int *)(in_ECX + 0x6c) - *(int *)(in_ECX + 0x68) >> 2 != 0)) {
    puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x6c))();
    *puVar1 = *(undefined4 *)(in_ECX + 0x34);
    *(bool *)(puVar1 + 2) = *(char *)(in_ECX + 0x24) == '\x01';
    puVar1[1] = *(undefined4 *)(in_ECX + 0x30);
    *(bool *)((int)puVar1 + 9) = *(char *)(in_ECX + 0x25) == '\x01';
    *(bool *)((int)puVar1 + 10) = *(char *)(in_ECX + 0x26) == '\x01';
    *(bool *)((int)puVar1 + 0xb) = *(char *)(in_ECX + 0x27) == '\x01';
    *(undefined1 *)(puVar1 + 3) = *(undefined1 *)(in_ECX + 0x28);
    puVar1[0x10] = *(undefined4 *)(in_ECX + 0x3c);
    puVar1[0x11] = *(undefined4 *)(in_ECX + 0x40);
    puVar1[0x12] = *(undefined4 *)(in_ECX + 0x44);
    puVar1[0x13] = *(undefined4 *)(in_ECX + 0x48);
    puVar1[0x14] = *(undefined4 *)(in_ECX + 0x4c);
    puVar1[0x15] = *(undefined4 *)(in_ECX + 0x50);
    if ((void *)puVar1[9] != (void *)0x0) {
      _free((void *)puVar1[9]);
      return;
    }
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    FUN_00430ad0(in_ECX + 100);
    if ((void *)puVar1[5] != (void *)0x0) {
      _free((void *)puVar1[5]);
      return;
    }
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    FUN_005947f0(*(undefined4 *)(in_ECX + 0x98),*(undefined4 *)(in_ECX + 0x9c));
    uStack_10 = *(undefined4 *)(in_ECX + 0x54);
    uStack_c = *(undefined4 *)(in_ECX + 0x58);
    uStack_8 = *(undefined4 *)(in_ECX + 0x5c);
    uStack_4 = *(undefined4 *)(in_ECX + 0x60);
    (**(code **)(*param_1 + 0x10))(&uStack_10);
  }
  return;
}


// ==== FUN_00592b00 @ 0x00592b00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00592b00(float *param_1,int param_2)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  uint uVar4;
  float fVar5;
  int in_ECX;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  float fVar9;
  float local_40;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float *local_14;
  float *local_10;
  undefined4 local_c;
  
  iVar6 = 0;
  local_14 = (float *)0x0;
  local_10 = (float *)0x0;
  local_c = 0;
  pfVar7 = (float *)(param_2 + 4);
  do {
    if (_DAT_009b632c <= pfVar7[3]) {
      if (local_14 != (float *)0x0) {
        _free(local_14);
        return;
      }
      pfVar8 = (float *)0x0;
      pfVar7 = (float *)0x0;
      goto LAB_00592c84;
    }
    if (param_1[4] < *pfVar7) {
      local_30 = pfVar7[-1] - (DAT_0099d080 / pfVar7[3]) * pfVar7[2] * (*pfVar7 - param_1[4]);
      pfVar8 = &local_30;
      local_2c = pfVar7[1] - pfVar7[4] * (*pfVar7 - param_1[4]) * (DAT_0099d080 / pfVar7[3]);
    }
    else {
      local_38 = pfVar7[-1];
      local_34 = pfVar7[1];
      pfVar8 = &local_38;
    }
    FUN_0058ac00(pfVar8);
    if (param_1[1] < *pfVar7) {
      local_20 = pfVar7[-1] - (DAT_0099d080 / pfVar7[3]) * pfVar7[2] * (*pfVar7 - param_1[1]);
      pfVar8 = &local_20;
      local_1c = pfVar7[1] - pfVar7[4] * (*pfVar7 - param_1[1]) * (DAT_0099d080 / pfVar7[3]);
    }
    else {
      local_28 = pfVar7[-1];
      local_24 = pfVar7[1];
      pfVar8 = &local_28;
    }
    FUN_0058ac00(pfVar8);
    iVar6 = iVar6 + 1;
    pfVar7 = pfVar7 + 6;
  } while (iVar6 < 4);
  pfVar7 = local_10;
  pfVar8 = local_14;
LAB_00592c84:
  local_40 = *param_1;
  if (local_40 <= 0.0) {
    local_40 = 0.0;
  }
  *(int *)(in_ECX + 0x54) = (int)ROUND(local_40);
  local_40 = param_1[2];
  if (local_40 <= 0.0) {
    local_40 = 0.0;
  }
  *(int *)(in_ECX + 0x58) = (int)ROUND(local_40);
  *(int *)(in_ECX + 0x5c) = (int)ROUND(param_1[3]);
  *(int *)(in_ECX + 0x60) = (int)ROUND(param_1[5]);
  if (pfVar8 == (float *)0x0) {
    return;
  }
  local_38 = (float)((int)pfVar7 - (int)pfVar8 >> 3);
  if (local_38 != 0.0) {
    local_40 = *pfVar8;
    local_34 = pfVar8[1];
    fVar5 = *pfVar8;
    fVar1 = pfVar8[1];
    fVar9 = local_34;
    pfVar3 = pfVar8;
    while( true ) {
      pfVar2 = pfVar3;
      pfVar3 = pfVar2 + 2;
      if (pfVar3 == pfVar7) break;
      if (*pfVar3 <= local_40) {
        local_40 = *pfVar3;
      }
      if (pfVar2[3] <= fVar9) {
        fVar9 = pfVar2[3];
      }
      if (fVar5 < *pfVar3 || fVar5 == *pfVar3) {
        fVar5 = *pfVar3;
      }
      if (fVar1 < pfVar2[3] || fVar1 == pfVar2[3]) {
        fVar1 = pfVar2[3];
      }
    }
    if (local_40 <= 0.0) {
      local_40 = 0.0;
    }
    uVar4 = (int)ROUND(local_40);
    if ((uint)(int)ROUND(local_40) < *(uint *)(in_ECX + 0x54)) {
      uVar4 = *(uint *)(in_ECX + 0x54);
    }
    *(uint *)(in_ECX + 0x54) = uVar4;
    local_40 = fVar9;
    if (fVar9 <= 0.0) {
      local_40 = 0.0;
    }
    uVar4 = (int)ROUND(local_40);
    if ((uint)(int)ROUND(local_40) < *(uint *)(in_ECX + 0x58)) {
      uVar4 = *(uint *)(in_ECX + 0x58);
    }
    *(uint *)(in_ECX + 0x58) = uVar4;
    local_40 = fVar5;
    if (fVar5 <= 0.0) {
      local_40 = 0.0;
    }
    uVar4 = (int)ROUND(local_40);
    if (*(uint *)(in_ECX + 0x5c) <= (uint)(int)ROUND(local_40)) {
      uVar4 = *(uint *)(in_ECX + 0x5c);
    }
    *(uint *)(in_ECX + 0x5c) = uVar4;
    local_40 = fVar1;
    if (fVar1 <= 0.0) {
      local_40 = 0.0;
    }
    local_38 = (float)(int)ROUND(local_40);
    fVar5 = local_38;
    if ((uint)*(float *)(in_ECX + 0x60) <= (uint)local_38) {
      fVar5 = *(float *)(in_ECX + 0x60);
    }
    *(float *)(in_ECX + 0x60) = fVar5;
  }
  _free(pfVar8);
  return;
}


// ==== FUN_00592ef0 @ 0x00592ef0 ====

void FUN_00592ef0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined1 auStack_48 [8];
  int aiStack_40 [2];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar2 = param_2;
  FUN_0058b9b0(&param_2,param_2);
  if (param_2 != *(int *)(param_1 + 0x40)) {
    puVar1 = *(undefined4 **)(param_2 + 0x1c);
    for (puVar4 = *(undefined4 **)(param_2 + 0x18); puVar4 != puVar1; puVar4 = puVar4 + 0xf) {
      piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
      param_2 = (**(code **)(*piVar3 + 4))(2,s____Environment_Element_QMap_cpp_009bf423 + 1,0x155);
      if (puVar4[0xd] != 0) {
        uStack_24 = 0xf;
        uStack_28 = 0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
        aiStack_40[0] = param_2;
        FUN_00401660(puVar4 + 8,0,0xffffffff);
        uStack_20 = *puVar4;
        uStack_1c = puVar4[1];
        uStack_8 = puVar4[6];
        uStack_18 = puVar4[2];
        uStack_14 = puVar4[3];
        uStack_10 = puVar4[4];
        uStack_c = puVar4[5];
        uStack_4 = puVar4[7];
        (**(code **)(*DAT_00b5afe4 + 4))(aiStack_40);
        puVar6 = &param_2;
        puVar5 = auStack_48;
        FUN_00595210(iVar2);
        FUN_004677a0(puVar5,puVar6);
        if (0xf < uStack_24) {
          _free(pvStack_38);
          return;
        }
        uStack_24 = 0xf;
        uStack_28 = 0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      }
    }
  }
  return;
}


// ==== FUN_00593030 @ 0x00593030 ====

void FUN_00593030(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_7c;
  undefined4 uStack_78;
  int local_74;
  int local_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 *local_64;
  undefined1 local_60 [8];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 *local_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  FUN_0058b9b0(&local_7c,param_2);
  iVar3 = local_7c;
  if (local_7c != *(int *)(param_1 + 0x40)) {
    FUN_00558e00(&local_7c,param_2);
    if (local_7c == *(int *)(in_ECX + 0xc0)) {
      local_70 = FUN_00751a80();
      *(undefined1 *)(local_70 + 0x11) = 1;
      *(int *)(local_70 + 4) = local_70;
      *(int *)local_70 = local_70;
      *(int *)(local_70 + 8) = local_70;
      local_58 = *param_2;
      local_6c = 0;
      FUN_00594840(&local_74);
      FUN_00594ca0(local_60,&local_58);
      FUN_00467860(&local_64,*local_50,local_50);
      _free(local_50);
      return;
    }
    local_7c = FUN_00595210(param_2);
    puVar4 = *(undefined4 **)(iVar3 + 0x18);
    local_64 = *(undefined4 **)(iVar3 + 0x1c);
    if (puVar4 != local_64) {
      local_58 = 0;
      local_54 = 0;
      local_50 = (undefined4 *)0x0;
      do {
        piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
        uVar2 = (**(code **)(*piVar1 + 4))(2,s___Environment_Element_QMap_cpp_009bf464,0x1bb);
        uStack_68 = uVar2;
        FUN_0081d760();
        uStack_c = local_54;
        uStack_40 = puVar4[1];
        uStack_8 = local_50;
        uStack_10 = local_58;
        uStack_44 = *puVar4;
        uStack_28 = DAT_0099d080;
        uStack_3c = puVar4[6];
        uStack_24 = 0;
        uStack_20 = 0;
        uStack_1c = 0;
        uStack_18 = 0;
        uStack_14 = 0;
        uStack_4 = 0xffffffff;
        uStack_48 = uVar2;
        FUN_0081d680(puVar4 + 2);
        uStack_24 = puVar4[8];
        uStack_20 = puVar4[9];
        uStack_1c = puVar4[10];
        if (*(int *)(local_7c + 8) == 0) {
LAB_00593288:
          (**(code **)(*DAT_00b5afe0 + 4))(&uStack_48);
          puVar5 = &uStack_68;
          piVar1 = &local_74;
          FUN_00595210(param_2);
          FUN_004677a0(piVar1,puVar5);
          FUN_0081d670();
        }
        else {
          iVar3 = FUN_00595210(param_2);
          local_74 = *(int *)(iVar3 + 4);
          iVar3 = FUN_00595210(param_2);
          uStack_78 = *(undefined4 *)(iVar3 + 4);
          iVar3 = FUN_00595210(param_2);
          piVar1 = (int *)FUN_00594530(local_60,**(undefined4 **)(iVar3 + 4),uStack_78,puVar4 + 8);
          if (*piVar1 == local_74) goto LAB_00593288;
          FUN_0081d670();
        }
        puVar4 = puVar4 + 0xf;
      } while (puVar4 != local_64);
    }
  }
  return;
}


// ==== FUN_005932e0 @ 0x005932e0 ====

void FUN_005932e0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0xc0);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    puVar4 = (undefined4 *)puVar3[5];
    puVar5 = (undefined4 *)*puVar4;
    while (puVar5 != puVar4) {
      (**(code **)(*DAT_00b5afe0 + 8))(puVar5[3]);
      piVar8 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
      (**(code **)(*piVar8 + 8))(s___Environment_Element_QMap_cpp_009bf4a4,0x35c,2,puVar5[3]);
      if (*(char *)((int)puVar5 + 0x11) == '\0') {
        puVar6 = (undefined4 *)puVar5[2];
        if (*(char *)((int)puVar6 + 0x11) == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x11);
          puVar5 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar6 + 0x11);
            puVar5 = puVar6;
            puVar6 = (undefined4 *)*puVar6;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar5[1] + 0x11);
          puVar7 = (undefined4 *)puVar5[1];
          puVar6 = puVar5;
          while ((puVar5 = puVar7, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar5[2]))) {
            cVar1 = *(char *)((int)puVar5[1] + 0x11);
            puVar7 = (undefined4 *)puVar5[1];
            puVar6 = puVar5;
          }
        }
      }
    }
    if (*(char *)((int)puVar3 + 0x1d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x1d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x1d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x1d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x1d);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x1d);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  FUN_00594ed0(*(undefined4 *)(*(int *)(in_ECX + 0xc0) + 4));
  *(int *)(*(int *)(in_ECX + 0xc0) + 4) = *(int *)(in_ECX + 0xc0);
  *(undefined4 *)(in_ECX + 0xc4) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(in_ECX + 0xc0);
  *(int *)(*(int *)(in_ECX + 0xc0) + 8) = *(int *)(in_ECX + 0xc0);
  FUN_00594ed0(*(undefined4 *)(*(int *)(in_ECX + 0xa8) + 4));
  *(int *)(*(int *)(in_ECX + 0xa8) + 4) = *(int *)(in_ECX + 0xa8);
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0xa8) = *(undefined4 *)(in_ECX + 0xa8);
  *(int *)(*(int *)(in_ECX + 0xa8) + 8) = *(int *)(in_ECX + 0xa8);
  return;
}


// ==== FUN_00593450 @ 0x00593450 ====

void FUN_00593450(int param_1)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 4);
  if (((piVar2 != (int *)0x0) &&
      (piVar1 = *(int **)(param_1 + 8), (int)piVar1 - (int)piVar2 >> 2 != 0)) &&
     (*(int *)(in_ECX + 200) != 0)) {
    for (; piVar2 != piVar1; piVar2 = piVar2 + 1) {
      param_1 = *(undefined4 *)(*(int *)(*piVar2 + 0xc4) + 8);
      FUN_00592ef0(*(undefined4 *)(in_ECX + 200),&param_1);
    }
  }
  return;
}


// ==== FUN_005934b0 @ 0x005934b0 ====

void FUN_005934b0(int param_1)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 4);
  if (((piVar2 != (int *)0x0) &&
      (piVar1 = *(int **)(param_1 + 8), (int)piVar1 - (int)piVar2 >> 2 != 0)) &&
     (*(int *)(in_ECX + 0xcc) != 0)) {
    for (; piVar2 != piVar1; piVar2 = piVar2 + 1) {
      param_1 = *(undefined4 *)(*(int *)(*piVar2 + 0xc4) + 8);
      FUN_00593030(*(undefined4 *)(in_ECX + 0xcc),&param_1);
    }
  }
  return;
}


// ==== FUN_00593510 @ 0x00593510 ====

void FUN_00593510(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *_Memory;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int in_ECX;
  int local_8;
  undefined4 uStack_4;
  
  FUN_00558e00(&local_8,param_1);
  iVar5 = local_8;
  if (local_8 != *(int *)(in_ECX + 0xb4)) {
    puVar2 = *(undefined4 **)(local_8 + 0x14);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      (**(code **)(*DAT_00b5afe4 + 8))(puVar3[3]);
      piVar7 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
      (**(code **)(*piVar7 + 8))(s___Environment_Element_QMap_cpp_009bf444,0x183,2,puVar3[3]);
      if (*(char *)((int)puVar3 + 0x11) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x11) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x11);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x11);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x11);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x11);
            puVar6 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    _Memory = *(void **)(*(int *)(iVar5 + 0x14) + 4);
    if (*(char *)((int)_Memory + 0x11) == '\0') {
      FUN_00467210(*(undefined4 *)((int)_Memory + 8));
      _free(_Memory);
      return;
    }
    *(int *)(*(int *)(iVar5 + 0x14) + 4) = *(int *)(iVar5 + 0x14);
    *(undefined4 *)(iVar5 + 0x18) = 0;
    *(undefined4 *)*(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar5 + 0x14);
    *(int *)(*(int *)(iVar5 + 0x14) + 8) = *(int *)(iVar5 + 0x14);
    FUN_005945a0(&local_8,param_1);
    FUN_00595310(&param_1,local_8,uStack_4);
  }
  return;
}


// ==== FUN_00593650 @ 0x00593650 ====

void FUN_00593650(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int in_ECX;
  undefined4 *puVar8;
  undefined1 *puVar9;
  undefined4 local_4c;
  undefined4 uStack_48;
  int local_44;
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [4];
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 auStack_14 [2];
  undefined4 *puStack_c;
  
  puVar2 = param_1;
  iVar4 = FUN_00595210(param_1);
  iVar4 = **(int **)(iVar4 + 4);
  iVar5 = FUN_00595210(param_1);
  local_44 = *(int *)(iVar5 + 4);
  param_1 = (undefined4 *)iVar4;
  if (iVar4 != local_44) {
    do {
      uVar1 = *(undefined4 *)((int)param_1 + 0xc);
      piVar6 = (int *)(**(code **)(*DAT_00b5afdc + 0x10))(uVar1);
      if (piVar6 == (int *)0x0) {
LAB_005937ff:
        (**(code **)(*DAT_00b5afe0 + 8))(uVar1);
        piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
        (**(code **)(*piVar6 + 8))(s___Environment_Element_QMap_cpp_009bf484,0x1fb,2,uVar1);
        puVar8 = &uStack_48;
        FUN_00595210(puVar2);
        piVar6 = (int *)FUN_004674f0(puVar8,param_1);
        param_1 = (undefined4 *)*piVar6;
      }
      else {
        piVar7 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
        iVar4 = (**(code **)(*piVar7 + 0x1c))();
        if ((*(int *)(iVar4 + 4) != 1) || (cVar3 = (**(code **)(*piVar6 + 0x10))(), cVar3 == '\0'))
        goto LAB_005937ff;
        piVar7 = (int *)FUN_00558e00(&local_44,puVar2);
        if (*piVar7 == *(int *)(in_ECX + 0x164)) {
          iStack_1c = FUN_00751a80();
          *(undefined1 *)(iStack_1c + 0x11) = 1;
          *(int *)(iStack_1c + 4) = iStack_1c;
          *(int *)iStack_1c = iStack_1c;
          *(int *)(iStack_1c + 8) = iStack_1c;
          uStack_18 = 0;
          local_4c = (**(code **)(*piVar6 + 0x14))();
          FUN_004677a0(auStack_30,&local_4c);
          auStack_14[0] = *puVar2;
          FUN_00594840(auStack_20);
          FUN_00594ca0(auStack_28,auStack_14);
          FUN_00467860(auStack_40,*puStack_c,puStack_c);
          _free(puStack_c);
          return;
        }
        uStack_48 = (**(code **)(*piVar6 + 0x14))();
        puVar8 = &uStack_48;
        puVar9 = auStack_38;
        FUN_00595210(puVar2);
        FUN_004677a0(puVar9,puVar8);
        FUN_007519c0();
      }
    } while (param_1 != (undefined4 *)local_44);
  }
  iVar4 = FUN_00595210(puVar2);
  if (*(int *)(iVar4 + 8) == 0) {
    FUN_005953d0(puVar2);
  }
  return;
}


// ==== FUN_00593880 @ 0x00593880 ====

/* WARNING: Removing unreachable block (ram,0x00593903) */

void FUN_00593880(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xcc) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 0xcc));
    *(undefined4 *)(in_ECX + 0xcc) = 0;
  }
  FUN_00401660(param_1 + 4,0,0xffffffff);
  uVar1 = FUN_005946e0(param_1 + 4);
  *(undefined4 *)(in_ECX + 0xcc) = uVar1;
  FUN_005932e0();
  FUN_005934b0(in_ECX + 0x74);
  return;
}


// ==== FUN_00593920 @ 0x00593920 ====

void FUN_00593920(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xcc) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 0xcc));
    *(undefined4 *)(in_ECX + 0xcc) = 0;
  }
  FUN_005932e0();
  return;
}


// ==== FUN_00593950 @ 0x00593950 ====

void FUN_00593950(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xb8);
  while (iVar1 != 0) {
    FUN_00593510(**(int **)(in_ECX + 0xb4) + 0xc);
    iVar1 = *(int *)(in_ECX + 0xb8);
  }
  return;
}


// ==== FUN_00593980 @ 0x00593980 ====

void FUN_00593980(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[8] = &PTR_FUN_009bf52c;
  *in_ECX = &PTR_FUN_009bf574;
  in_ECX[8] = &PTR_FUN_009bf550;
  *(undefined1 *)(in_ECX + 9) = 0;
  *(undefined1 *)((int)in_ECX + 0x25) = 1;
  *(undefined1 *)((int)in_ECX + 0x26) = 0;
  *(undefined1 *)((int)in_ECX + 0x27) = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *(undefined1 *)((int)in_ECX + 0x29) = 0;
  in_ECX[0xb] = 0xffffffff;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  iVar1 = FUN_00594490();
  in_ECX[0x2a] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x2a] + 4) = in_ECX[0x2a];
  *(undefined4 *)in_ECX[0x2a] = in_ECX[0x2a];
  *(undefined4 *)(in_ECX[0x2a] + 8) = in_ECX[0x2a];
  in_ECX[0x2b] = 0;
  iVar1 = FUN_00594490();
  in_ECX[0x2d] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x2d] + 4) = in_ECX[0x2d];
  *(undefined4 *)in_ECX[0x2d] = in_ECX[0x2d];
  *(undefined4 *)(in_ECX[0x2d] + 8) = in_ECX[0x2d];
  in_ECX[0x2e] = 0;
  iVar1 = FUN_00594490();
  in_ECX[0x30] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x30] + 4) = in_ECX[0x30];
  *(undefined4 *)in_ECX[0x30] = in_ECX[0x30];
  *(undefined4 *)(in_ECX[0x30] + 8) = in_ECX[0x30];
  in_ECX[0x31] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x34] = 0;
  *(undefined1 *)(in_ECX + 0x36) = 0;
  in_ECX[0x35] = 0;
  if (in_ECX == (undefined4 *)0xffffffdc) {
    DAT_00b5af50 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5af50 = in_ECX + 8;
  return;
}


// ==== FUN_00593b20 @ 0x00593b20 ====

void FUN_00593b20(void)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined1 auStack_4 [4];
  
  *in_ECX = &PTR_FUN_009bf574;
  in_ECX[8] = &PTR_FUN_009bf550;
  if (in_ECX[0xd] != 0) {
    (**(code **)(*DAT_00b5afac + 0x10))(in_ECX[0xb]);
    if (in_ECX[0xd] != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x1c))(in_ECX[0xd]);
      in_ECX[0xd] = 0;
    }
  }
  if (in_ECX[0xe] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(in_ECX[0xe]);
    in_ECX[0xe] = 0;
  }
  if (in_ECX[0x32] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(in_ECX[0x32]);
    in_ECX[0x32] = 0;
  }
  if (in_ECX[0x33] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(in_ECX[0x33]);
    in_ECX[0x33] = 0;
  }
  FUN_005932e0();
  iVar1 = in_ECX[0x2e];
  while (iVar1 != 0) {
    FUN_00593510(*(int *)in_ECX[0x2d] + 0xc);
    iVar1 = in_ECX[0x2e];
  }
  DAT_00b5af50 = 0;
  FUN_00595310(auStack_4,*(undefined4 *)in_ECX[0x30],(undefined4 *)in_ECX[0x30]);
  _free((void *)in_ECX[0x30]);
  return;
}


// ==== FUN_00593d00 @ 0x00593d00 ====

void FUN_00593d00(int param_1)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 4);
  if (((piVar2 != (int *)0x0) &&
      (piVar1 = *(int **)(param_1 + 8), (int)piVar1 - (int)piVar2 >> 2 != 0)) &&
     (*(int *)(in_ECX + 200) != 0)) {
    for (; piVar2 != piVar1; piVar2 = piVar2 + 1) {
      param_1 = *(undefined4 *)(*(int *)(*piVar2 + 0xc4) + 8);
      FUN_00593510(&param_1);
    }
  }
  return;
}


// ==== FUN_00593d60 @ 0x00593d60 ====

void FUN_00593d60(int param_1)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 4);
  if (((piVar2 != (int *)0x0) &&
      (piVar1 = *(int **)(param_1 + 8), (int)piVar1 - (int)piVar2 >> 2 != 0)) &&
     (*(int *)(in_ECX + 0xcc) != 0)) {
    for (; piVar2 != piVar1; piVar2 = piVar2 + 1) {
      param_1 = *(undefined4 *)(*(int *)(*piVar2 + 0xc4) + 8);
      FUN_00593650(&param_1);
    }
  }
  return;
}


// ==== FUN_00593dc0 @ 0x00593dc0 ====

void FUN_00593dc0(void)

{
  int in_ECX;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (*(int *)(in_ECX + 0x34) != 0) {
    *(undefined1 *)(in_ECX + 0x24) = 0;
    *(undefined1 *)(in_ECX + 0x25) = 0;
    *(undefined1 *)(in_ECX + 0x26) = 0;
    *(undefined1 *)(in_ECX + 0x27) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 0x34));
    *(undefined4 *)(in_ECX + 0x34) = 0;
    if (*(int *)(in_ECX + 0x38) != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 0x38));
      *(undefined4 *)(in_ECX + 0x38) = 0;
    }
    if (*(void **)(in_ECX + 0x68) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x68));
      return;
    }
    *(undefined4 *)(in_ECX + 0x68) = 0;
    *(undefined4 *)(in_ECX + 0x6c) = 0;
    *(undefined4 *)(in_ECX + 0x70) = 0;
    if (*(void **)(in_ECX + 0x78) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x78));
      return;
    }
    *(undefined4 *)(in_ECX + 0x78) = 0;
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    *(undefined4 *)(in_ECX + 0x80) = 0;
    if (*(void **)(in_ECX + 0x88) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x88));
      return;
    }
    *(undefined4 *)(in_ECX + 0x88) = 0;
    *(undefined4 *)(in_ECX + 0x8c) = 0;
    *(undefined4 *)(in_ECX + 0x90) = 0;
    if (*(int *)(in_ECX + 200) != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 200));
      *(undefined4 *)(in_ECX + 200) = 0;
    }
    if (*(int *)(in_ECX + 0xcc) != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 0xcc));
      *(undefined4 *)(in_ECX + 0xcc) = 0;
    }
    FUN_00593950();
    FUN_005932e0();
    (**(code **)(*DAT_00b5afac + 0x10))(*(undefined4 *)(in_ECX + 0x2c));
    uVar6 = 0x3f800000;
    uVar5 = 0x43ff0000;
    uVar4 = 0x43fc8000;
    uVar1 = 0;
    uVar2 = 0;
    *(undefined4 *)(in_ECX + 0xd0) = 0;
    *(undefined1 *)(in_ECX + 0xd8) = 0;
    *(undefined4 *)(in_ECX + 0xd4) = 0;
    uVar3 = 0;
    (**(code **)(*DAT_00b5afb4 + 0x14))(0,0,0,0x43fc8000,0x43ff0000,0x3f800000);
    FUN_005964f0(uVar1,uVar2,uVar3,uVar4,uVar5,uVar6);
  }
  return;
}


// ==== FUN_00593f30 @ 0x00593f30 ====

void FUN_00593f30(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 200) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 200));
    *(undefined4 *)(in_ECX + 200) = 0;
  }
  uVar2 = FUN_004d5470(param_1 + 4);
  iVar1 = *(int *)(in_ECX + 0xb8);
  *(undefined4 *)(in_ECX + 200) = uVar2;
  while (iVar1 != 0) {
    FUN_00593510(**(int **)(in_ECX + 0xb4) + 0xc);
    iVar1 = *(int *)(in_ECX + 0xb8);
  }
  FUN_00593450(in_ECX + 0x74);
  return;
}


// ==== FUN_00593fa0 @ 0x00593fa0 ====

void FUN_00593fa0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 200) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 200));
    *(undefined4 *)(in_ECX + 200) = 0;
  }
  iVar1 = *(int *)(in_ECX + 0xb8);
  while (iVar1 != 0) {
    FUN_00593510(**(int **)(in_ECX + 0xb4) + 0xc);
    iVar1 = *(int *)(in_ECX + 0xb8);
  }
  return;
}


// ==== FUN_00593ff0 @ 0x00593ff0 ====

undefined4 FUN_00593ff0(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x10040101) {
    if (uVar1 == 0x10040100) {
      if (*(int *)(in_ECX + 0x38) != 0) {
        (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 0x38));
        *(undefined4 *)(in_ECX + 0x38) = 0;
      }
      uVar2 = FUN_00594740(param_1 + 1);
      *(undefined4 *)(in_ECX + 0x38) = uVar2;
      return 1;
    }
    switch(uVar1 + 0xeffbfff0) {
    case 0:
      FUN_00592720(param_1);
      return 1;
    case 1:
      *(char *)(in_ECX + 0x24) = (char)param_1[1];
      *(int *)(in_ECX + 0x30) = param_1[2];
      return 1;
    case 2:
      FUN_00412dc0();
      FUN_004d0e30(*(undefined4 *)(in_ECX + 0x98),param_1[2],param_1[3]);
      return 1;
    case 3:
      *(char *)(in_ECX + 0x28) = (char)param_1[1];
      return 1;
    case 4:
      *(char *)(in_ECX + 0x26) = (char)param_1[1];
      return 1;
    case 5:
      *(char *)(in_ECX + 0x27) = (char)param_1[1];
      return 1;
    case 6:
      *(char *)(in_ECX + 0x25) = (char)param_1[1];
      return 1;
    case 8:
      FUN_00593dc0(param_1);
      return 1;
    }
  }
  else {
    switch(uVar1) {
    case 0x10040200:
      FUN_00593f30(param_1);
      return 1;
    case 0x10040201:
      FUN_00593fa0();
      return 1;
    case 0x10040210:
      FUN_00593880(param_1);
      return 1;
    case 0x10040211:
      FUN_00593920(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00594190 @ 0x00594190 ====

void FUN_00594190(void)

{
  int in_ECX;
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  void *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(int *)(in_ECX + 200) != 0) || (*(int *)(in_ECX + 0xcc) != 0)) {
    local_c = (void *)0x0;
    local_8 = 0;
    local_4 = 0;
    FUN_00594a20(local_24,*(undefined4 *)(in_ECX + 0x78),*(undefined4 *)(in_ECX + 0x7c),
                 *(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x8c),local_10);
    local_1c = (void *)0x0;
    local_18 = 0;
    local_14 = 0;
    FUN_00594a20(local_24,*(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x8c),
                 *(undefined4 *)(in_ECX + 0x78),*(undefined4 *)(in_ECX + 0x7c),local_20);
    FUN_00593d00(local_20);
    FUN_00593d60(local_20);
    FUN_00593450(local_10);
    FUN_005934b0(local_10);
    if (local_1c != (void *)0x0) {
      _free(local_1c);
      return;
    }
    local_1c = (void *)0x0;
    local_18 = 0;
    local_14 = 0;
    if (local_c != (void *)0x0) {
      _free(local_c);
      return;
    }
  }
  return;
}


// ==== FUN_00594280 @ 0x00594280 ====

undefined4 FUN_00594280(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar2;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar1 = *(undefined4 *)(in_ECX + 0x88);
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(in_ECX + 0x78);
  *(undefined4 *)(in_ECX + 0x78) = uVar1;
  uVar1 = *(undefined4 *)(in_ECX + 0x8c);
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(in_ECX + 0x7c);
  *(undefined4 *)(in_ECX + 0x7c) = uVar1;
  uVar1 = *(undefined4 *)(in_ECX + 0x90);
  *(undefined4 *)(in_ECX + 0x90) = *(undefined4 *)(in_ECX + 0x80);
  *(undefined4 *)(in_ECX + 0x80) = uVar1;
  if (*(void **)(in_ECX + 0x78) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x78));
    return extraout_EAX;
  }
  *(undefined4 *)(in_ECX + 0x78) = 0;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  if (*(void **)(in_ECX + 0x68) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x68));
    return extraout_EAX_00;
  }
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  if (*(int *)(in_ECX + 0x34) == 0) {
    return 0;
  }
  iVar2 = (**(code **)(*DAT_00b5a988 + 0x14))();
  uStack_8 = *(undefined4 *)(iVar2 + 0x34);
  iVar2 = (**(code **)(*DAT_00b5a988 + 0x14))();
  uStack_4 = *(undefined4 *)(iVar2 + 0x3c);
  iVar2 = (**(code **)(*DAT_00b5afb4 + 0x14))();
  FUN_004a8720(param_1,in_ECX + 0x3c,in_ECX + 100,&uStack_8,*(undefined4 *)(iVar2 + 0xe0));
  FUN_004a9110(in_ECX + 0x74);
  FUN_00594190(*(undefined4 *)(in_ECX + 0x34));
  FUN_00592b00(in_ECX + 0x3c,unaff_EBX);
  return 1;
}


// ==== FUN_00594390 @ 0x00594390 ====

void FUN_00594390(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = *(undefined4 *)(in_ECX + 4);
  local_4 = *(undefined4 *)(in_ECX + 0xc);
  local_10 = *(undefined4 *)(in_ECX + 0x10);
  local_c = *(undefined4 *)(in_ECX + 0x18);
  FUN_004a8890(&local_8,&local_10,param_2);
  return;
}


// ==== FUN_005943e0 @ 0x005943e0 ====

undefined4 * FUN_005943e0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982440;
  local_10 = ExceptionList;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x11) == '\0') {
    ExceptionList = &local_10;
    puVar1 = (undefined4 *)
             FUN_004671c0(local_18,param_2,local_18,param_1 + 3,*(undefined1 *)(param_1 + 4));
    if (*(char *)((int)local_18 + 0x11) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_005943e0(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_005943e0(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}


// ==== Catch@00594478 @ 0x00594478 ====

void Catch_00594478(void)

{
  int unaff_EBP;
  
  FUN_00467210(*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00594490 @ 0x00594490 ====

void FUN_00594490(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982450;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 7) = 1;
  *(undefined1 *)((int)puVar1 + 0x1d) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0059451a @ 0x0059451a ====

void Catch_0059451a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00594530 @ 0x00594530 ====

void FUN_00594530(undefined4 *param_1,int *param_2,int *param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_2 == param_3) {
    *param_1 = param_2;
    return;
  }
  do {
    if (param_2[3] == *param_4) break;
    if (*(char *)((int)param_2 + 0x11) == '\0') {
      piVar2 = (int *)param_2[2];
      if (*(char *)((int)piVar2 + 0x11) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x11);
        param_2 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x11);
          param_2 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_2[1] + 0x11);
        piVar3 = (int *)param_2[1];
        piVar2 = param_2;
        while ((param_2 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_2[2]))) {
          cVar1 = *(char *)(param_2[1] + 0x11);
          piVar3 = (int *)param_2[1];
          piVar2 = param_2;
        }
      }
    }
  } while (param_2 != param_3);
  *param_1 = param_2;
  return;
}


// ==== FUN_005945a0 @ 0x005945a0 ====

void FUN_005945a0(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x1d) == '\0') {
    puVar1 = (undefined4 *)puVar4[1];
    do {
      if (*param_2 < (uint)puVar1[3]) {
        puVar2 = (undefined4 *)*puVar1;
        puVar4 = puVar1;
      }
      else {
        puVar2 = (undefined4 *)puVar1[2];
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x1d) == '\0');
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar1[1] + 0x1d) == '\0') {
    puVar2 = (undefined4 *)puVar1[1];
    do {
      if ((uint)puVar2[3] < *param_2) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        puVar1 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x1d) == '\0');
  }
  *param_1 = (int)puVar1;
  param_1[1] = (int)puVar4;
  return;
}


// ==== FUN_00594600 @ 0x00594600 ====

void FUN_00594600(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  uVar7 = FUN_005943e0(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 *)(iVar2 + 4) = uVar7;
  piVar3 = *(int **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x11) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x11);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x11);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x11);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x11);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)(in_ECX + 4) + 8) = iVar2;
  return;
}


// ==== FUN_00594680 @ 0x00594680 ====

void FUN_00594680(int *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  while (param_1 != param_2) {
    *param_3 = *param_3 + 1;
    if (*(char *)((int)param_1 + 0x1d) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x1d) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x1d);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x1d);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x1d);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x1d);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  return;
}


// ==== FUN_005946e0 @ 0x005946e0 ====

undefined4 FUN_005946e0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *local_20;
  undefined1 local_1c;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = DAT_00b5a7cc;
  local_c = 0;
  local_1c = 0;
  local_8 = 0xf;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 4;
  uVar2 = (**(code **)(*piVar1 + 8))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_00594740 @ 0x00594740 ====

undefined4 FUN_00594740(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *local_20;
  undefined1 local_1c;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = DAT_00b5a7cc;
  local_c = 0;
  local_1c = 0;
  local_8 = 0xf;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 3;
  uVar2 = (**(code **)(*piVar1 + 8))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_005947a0 @ 0x005947a0 ====

undefined4 FUN_005947a0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x1fffffff < param_1) {
    param_1 = FUN_0058a8f0();
  }
  pvVar1 = operator_new(param_1 * 8);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 8 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_005947f0 @ 0x005947f0 ====

void FUN_005947f0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  int in_ECX;
  
  if (*(void **)(in_ECX + 4) != *(void **)(in_ECX + 8)) {
    pvVar1 = _memmove(*(void **)(in_ECX + 4),*(void **)(in_ECX + 8),0);
    *(void **)(in_ECX + 8) = pvVar1;
  }
  FUN_004d00f0(*(undefined4 *)(in_ECX + 4),param_1,param_2,param_2);
  return;
}


// ==== FUN_00594840 @ 0x00594840 ====

void FUN_00594840(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982460;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00751a80();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x11) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  local_8 = 0;
  FUN_00594600(param_1);
  ExceptionList = local_10;
  return;
}


// ==== Catch@005948b8 @ 0x005948b8 ====

void Catch_005948b8(void)

{
  FUN_00467920();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005948d0 @ 0x005948d0 ====

void FUN_005948d0(int *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 == param_3) {
    *param_1 = param_4;
    return;
  }
  do {
    iVar1 = *(int *)(param_4 + 4);
    if ((iVar1 == 0) ||
       ((uint)(*(int *)(param_4 + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(param_4 + 8) - iVar1 >> 2)))
    {
      FUN_004d04f0(*(undefined4 *)(param_4 + 8),1,param_2);
    }
    else {
      puVar2 = *(undefined4 **)(param_4 + 8);
      *puVar2 = *param_2;
      *(undefined4 **)(param_4 + 8) = puVar2 + 1;
    }
    param_2 = param_2 + 1;
  } while (param_2 != param_3);
  *param_1 = param_4;
  return;
}


// ==== FUN_00594950 @ 0x00594950 ====

void FUN_00594950(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  FUN_00594840(param_4 + 1);
  *(undefined1 *)(in_ECX + 7) = param_5;
  *(undefined1 *)((int)in_ECX + 0x1d) = 0;
  return;
}


// ==== FUN_00594990 @ 0x00594990 ====

void * FUN_00594990(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982470;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x20);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00594950(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00594a05 @ 0x00594a05 ====

void Catch_00594a05(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00594a20 @ 0x00594a20 ====

undefined4
FUN_00594a20(undefined4 param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  if (param_2 != param_3) {
    do {
      if (param_4 == param_5) break;
      uVar1 = *param_2;
      if (uVar1 < *param_4) {
        iVar2 = *(int *)(param_6 + 4);
        if ((iVar2 == 0) ||
           ((uint)(*(int *)(param_6 + 0xc) - iVar2 >> 2) <=
            (uint)(*(int *)(param_6 + 8) - iVar2 >> 2))) {
          FUN_004d04f0(*(undefined4 *)(param_6 + 8),1,param_2);
          param_2 = param_2 + 1;
        }
        else {
          puVar3 = *(uint **)(param_6 + 8);
          *puVar3 = uVar1;
          *(uint **)(param_6 + 8) = puVar3 + 1;
          param_2 = param_2 + 1;
        }
      }
      else {
        if (uVar1 <= *param_4) {
          param_2 = param_2 + 1;
        }
        param_4 = param_4 + 1;
      }
    } while (param_2 != param_3);
  }
  FUN_005948d0(param_1,param_2,param_3,param_6,param_3);
  return param_1;
}


// ==== FUN_00594ac0 @ 0x00594ac0 ====

void FUN_00594ac0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0xffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00594990(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x1c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x1c) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[7] == '\0') {
LAB_00594bc5:
        *(undefined1 *)(*piVar5 + 0x1c) = 1;
        *(undefined1 *)(piVar6 + 7) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x1c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0046a370(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x1c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
        FUN_004e1270(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[7] == '\0') goto LAB_00594bc5;
      if (piVar7 == (int *)*piVar2) {
        FUN_004e1270(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x1c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x1d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x1c);
  } while( true );
}


// ==== FUN_00594ca0 @ 0x00594ca0 ====

void FUN_00594ca0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x1d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x1d) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00594ac0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0046a3c0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00594ac0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00594d60 @ 0x00594d60 ====

undefined4 * FUN_00594d60(undefined4 *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00594ac0(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*param_3 < (uint)param_2[3]) {
      FUN_00594ac0(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *param_3) {
      FUN_00594ac0(param_1,0,piVar1[2],param_3);
      return param_1;
    }
  }
  else {
    uVar2 = *param_3;
    uVar3 = param_2[3];
    if (uVar2 < uVar3) {
      FUN_0046a3c0();
      if ((uint)param_2[3] < uVar2) {
        if (*(char *)(param_2[2] + 0x1d) == '\0') {
          FUN_00594ac0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00594ac0(param_1,0,param_2,param_3);
        return param_1;
      }
      uVar3 = param_2[3];
    }
    if (uVar3 < uVar2) {
      FUN_005038e0();
      if ((param_2 == *(int **)(in_ECX + 4)) || (uVar2 < (uint)param_2[3])) {
        if (*(char *)(param_2[2] + 0x1d) == '\0') {
          FUN_00594ac0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00594ac0(param_1,0,param_2,param_3);
        return param_1;
      }
    }
  }
  puVar4 = (undefined4 *)FUN_00594ca0(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== FUN_00594ed0 @ 0x00594ed0 ====

void FUN_00594ed0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_1;
  if (*(char *)(param_1 + 0x1d) == '\0') {
    FUN_00594ed0(*(undefined4 *)(param_1 + 8));
    puVar1 = *(undefined4 **)(iVar2 + 0x14);
    FUN_00467860(&param_1,*puVar1,puVar1);
    _free(*(void **)(iVar2 + 0x14));
    return;
  }
  return;
}


// ==== FUN_00594f30 @ 0x00594f30 ====

/* WARNING: Removing unreachable block (ram,0x00595049) */
/* WARNING: Removing unreachable block (ram,0x0059505a) */
/* WARNING: Removing unreachable block (ram,0x00595063) */
/* WARNING: Removing unreachable block (ram,0x00595066) */
/* WARNING: Removing unreachable block (ram,0x00595056) */
/* WARNING: Removing unreachable block (ram,0x00595074) */
/* WARNING: Removing unreachable block (ram,0x00595081) */
/* WARNING: Removing unreachable block (ram,0x0059508c) */
/* WARNING: Removing unreachable block (ram,0x00595088) */
/* WARNING: Removing unreachable block (ram,0x0059507c) */
/* WARNING: Removing unreachable block (ram,0x0059508f) */

void FUN_00594f30(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)((int)param_2 + 0x1d) != '\0') {
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
  FUN_005038e0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x1d) == '\0') {
    if (*(char *)(param_2[2] + 0x1d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x1d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x1d) == '\0') {
      piVar3 = (int *)FUN_004af910(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x1d) == '\0') {
      uVar4 = FUN_0088f320(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[7] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[7] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[7] == '\0') {
            *(undefined1 *)(piVar5 + 7) = 1;
            *(undefined1 *)(piVar3 + 7) = 0;
            FUN_0046a370(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x1d) == '\0') {
            if ((*(char *)(*piVar5 + 0x1c) == '\x01') && (*(char *)(piVar5[2] + 0x1c) == '\x01'))
            goto LAB_00595164;
            if (*(char *)(piVar5[2] + 0x1c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x1c) = 1;
              *(undefined1 *)(piVar5 + 7) = 0;
              FUN_004e1270(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 7) = (char)piVar3[7];
            *(undefined1 *)(piVar3 + 7) = 1;
            *(undefined1 *)(piVar5[2] + 0x1c) = 1;
            FUN_0046a370(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[7] == '\0') {
            *(undefined1 *)(piVar5 + 7) = 1;
            *(undefined1 *)(piVar3 + 7) = 0;
            FUN_004e1270(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x1d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x1c) != '\x01') || (*(char *)(*piVar5 + 0x1c) != '\x01')) {
              if (*(char *)(*piVar5 + 0x1c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x1c) = 1;
                *(undefined1 *)(piVar5 + 7) = 0;
                FUN_0046a370(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 7) = (char)piVar3[7];
              *(undefined1 *)(piVar3 + 7) = 1;
              *(undefined1 *)(*piVar5 + 0x1c) = 1;
              FUN_004e1270(piVar3);
              break;
            }
LAB_00595164:
            *(undefined1 *)(piVar5 + 7) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 7) = 1;
  }
  FUN_00467860(local_48,*(undefined4 *)param_2[5],(undefined4 *)param_2[5]);
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_00595210 @ 0x00595210 ====

undefined4 * FUN_00595210(uint *param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *extraout_EAX;
  int in_ECX;
  undefined4 *puVar4;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  uint local_10 [2];
  undefined4 *local_8;
  
  puVar1 = param_1;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x1d) == '\0') {
    puVar2 = (undefined4 *)puVar4[1];
    do {
      if ((uint)puVar2[3] < *param_1) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        puVar4 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x1d) == '\0');
  }
  if ((puVar4 == *(undefined4 **)(in_ECX + 4)) || (*param_1 < (uint)puVar4[3])) {
    local_18 = FUN_00751a80();
    *(undefined1 *)(local_18 + 0x11) = 1;
    *(int *)(local_18 + 4) = local_18;
    *(int *)local_18 = local_18;
    *(int *)(local_18 + 8) = local_18;
    local_10[0] = *puVar1;
    local_14 = 0;
    FUN_00594840(local_1c);
    FUN_00594d60(&param_1,puVar4,local_10);
    FUN_00467860(local_20,*local_8,local_8);
    _free(local_8);
    return extraout_EAX;
  }
  return puVar4 + 4;
}


// ==== FUN_00595310 @ 0x00595310 ====

void FUN_00595310(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00594ed0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x1d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x1d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x1d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x1d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x1d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x1d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00594f30(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_005953d0 @ 0x005953d0 ====

undefined4 FUN_005953d0(undefined4 param_1)

{
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_005945a0(&local_8,param_1);
  param_1 = 0;
  FUN_00594680(local_8,local_4,&param_1,0);
  FUN_00595310(&local_8,local_8,local_4);
  return param_1;
}


// ==== FUN_00595430 @ 0x00595430 ====

void FUN_00595430(void)

{
  FUN_00595440();
  return;
}


// ==== FUN_00595440 @ 0x00595440 ====

void FUN_00595440(byte param_1)

{
  void *in_ECX;
  
  FUN_00593b20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00595460 @ 0x00595460 ====

void FUN_00595460(void)

{
  void *pvVar1;
  int *piVar2;
  
  if (DAT_00b5afb4 != 0) {
    return;
  }
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00597b80();
  }
                    /* WARNING: Could not recover jumptable at 0x00595486. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 4))();
  return;
}


// ==== FUN_00595490 @ 0x00595490 ====

void FUN_00595490(void)

{
  if (DAT_00b5afb4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afb4)(1);
  }
  return;
}


// ==== FUN_005954b0 @ 0x005954b0 ====

void FUN_005954b0(void)

{
  void *pvVar1;
  
  if (DAT_00b5aff0 == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_0059a500();
    }
  }
  if (DAT_00b5afb8 == 0) {
    pvVar1 = operator_new(0x14);
    if (pvVar1 != (void *)0x0) {
      FUN_0059a090();
    }
  }
  if (DAT_00b5afc0 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_005999f0();
    }
  }
  if (DAT_00b5afbc == 0) {
    pvVar1 = operator_new(0x4c);
    if (pvVar1 != (void *)0x0) {
      FUN_00598a30();
    }
  }
  if (DAT_00b5afec == 0) {
    pvVar1 = operator_new(0x14);
    if (pvVar1 != (void *)0x0) {
      FUN_00598570();
    }
  }
  if (DAT_00b5afe8 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_00598030();
      return;
    }
  }
  return;
}


// ==== FUN_00595570 @ 0x00595570 ====

void FUN_00595570(void)

{
  if (DAT_00b5afec != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afec)(1);
  }
  if (DAT_00b5afbc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afbc)(1);
  }
  if (DAT_00b5afc0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afc0)(1);
  }
  if (DAT_00b5afb8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afb8)(1);
  }
  if (DAT_00b5aff0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5aff0)(1);
  }
  if (DAT_00b5afe8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afe8)(1);
  }
  return;
}


// ==== FUN_005955f0 @ 0x005955f0 ====

void FUN_005955f0(void)

{
  void *pvVar1;
  
  if (DAT_00b5a7c0 == 0) {
    pvVar1 = operator_new(0x30);
    if (pvVar1 != (void *)0x0) {
      FUN_0059bf50();
    }
  }
  if (DAT_00b5a7c4 == 0) {
    pvVar1 = operator_new(0x20);
    if (pvVar1 != (void *)0x0) {
      FUN_0059b3b0();
      return;
    }
  }
  return;
}


// ==== FUN_00595630 @ 0x00595630 ====

void FUN_00595630(void)

{
  if (DAT_00b5a7c4 != (int *)0x0) {
    (**(code **)(*DAT_00b5a7c4 + 0x10))(1);
  }
  if (DAT_00b5a7c0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a7c0)(1);
  }
  return;
}


// ==== FUN_00595660 @ 0x00595660 ====

void FUN_00595660(void)

{
  void *pvVar1;
  
  if (DAT_00b5afb0 == 0) {
    pvVar1 = operator_new(0x34);
    if (pvVar1 != (void *)0x0) {
      FUN_0059c940();
      return;
    }
  }
  return;
}


// ==== FUN_00595680 @ 0x00595680 ====

void FUN_00595680(void)

{
  if (DAT_00b5afb0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afb0)(1);
  }
  return;
}


// ==== FUN_005956a0 @ 0x005956a0 ====

void FUN_005956a0(void)

{
  void *pvVar1;
  
  if (DAT_00b5afc4 == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_005a27e0();
    }
  }
  if (DAT_00b5afcc == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_005a21c0();
    }
  }
  if (DAT_00b5afc8 == 0) {
    pvVar1 = operator_new(0x54);
    if (pvVar1 != (void *)0x0) {
      FUN_005a0ae0();
    }
  }
  if (DAT_00b5aff8 == 0) {
    pvVar1 = operator_new(0x2c);
    if (pvVar1 != (void *)0x0) {
      FUN_0059e650();
      return;
    }
  }
  return;
}


// ==== FUN_00595720 @ 0x00595720 ====

void FUN_00595720(void)

{
  if (DAT_00b5afc8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afc8)(1);
  }
  if (DAT_00b5aff8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5aff8)(1);
  }
  if (DAT_00b5afc4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afc4)(1);
  }
  if (DAT_00b5afcc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afcc)(1);
  }
  return;
}


// ==== FUN_00595770 @ 0x00595770 ====

void FUN_00595770(void)

{
  void *pvVar1;
  
  if (DAT_00b5affc == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_005a33e0();
    }
  }
  if (DAT_00b5b000 == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_005a2df0();
      return;
    }
  }
  return;
}


// ==== FUN_005957b0 @ 0x005957b0 ====

void FUN_005957b0(void)

{
  if (DAT_00b5b000 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b000)(1);
  }
  if (DAT_00b5affc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5affc)(1);
  }
  return;
}


// ==== FUN_005957e0 @ 0x005957e0 ====

void FUN_005957e0(void)

{
  void *pvVar1;
  
  if (DAT_00b5ae50 == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_005a4020();
      return;
    }
  }
  return;
}


// ==== FUN_00595800 @ 0x00595800 ====

void FUN_00595800(void)

{
  if (DAT_00b5ae50 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae50)(1);
  }
  return;
}


// ==== FUN_00595820 @ 0x00595820 ====

void FUN_00595820(void)

{
  if (DAT_00b5aff4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5aff4)(1);
  }
  if (DAT_00b5a9d4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a9d4)(1);
  }
  return;
}


// ==== __break @ 0x0059584f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00595850 @ 0x00595850 ====

void FUN_00595850(void)

{
  void *pvVar1;
  
  if (DAT_00b5a9d4 == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_005959a0();
    }
  }
  if (DAT_00b5aff4 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_005a48b0();
      return;
    }
  }
  return;
}


// ==== FUN_00595890 @ 0x00595890 ====

void FUN_00595890(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982480;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0xc);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005958ff @ 0x005958ff ====

void Catch_005958ff(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00595920 @ 0x00595920 ====

void FUN_00595920(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982490;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = *param_3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00595989 @ 0x00595989 ====

void Catch_00595989(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005959a0 @ 0x005959a0 ====

undefined4 * FUN_005959a0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *in_ECX;
  int iVar4;
  void *local_8;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009bf594;
  local_4 = in_ECX;
  uVar2 = FUN_00595890();
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  DAT_00b5a9d4 = (undefined4 *)0x0;
  if (in_ECX != (undefined4 *)0xfffffffc) {
    DAT_00b5a9d4 = in_ECX;
  }
  iVar4 = 0x80;
  do {
    local_8 = operator_new(0x120);
    iVar1 = in_ECX[2];
    iVar3 = FUN_00595920(iVar1,*(undefined4 *)(iVar1 + 4),&local_8);
    FUN_00517200(1);
    iVar4 = iVar4 + -1;
    *(int *)(iVar1 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
  } while (iVar4 != 0);
  return local_4;
}


// ==== FUN_00595a20 @ 0x00595a20 ====

void FUN_00595a20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf594;
  DAT_00b5a9d4 = 0;
  FUN_00595a60(in_ECX + 1);
  FUN_008984a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00595a60 @ 0x00595a60 ====

void FUN_00595a60(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    return;
  }
  piVar1 = (int *)**(int **)(param_1 + 4);
  if (piVar1 == *(int **)(param_1 + 4)) {
    FUN_00510b80();
    return;
  }
  _free((void *)piVar1[2]);
  return;
}


// ==== FUN_00595aa0 @ 0x00595aa0 ====

void FUN_00595aa0(void)

{
  void *pvVar1;
  
  if (DAT_00b5a988 == 0) {
    pvVar1 = operator_new(0xe8);
    if (pvVar1 != (void *)0x0) {
      FUN_005a68f0();
    }
  }
  if (DAT_00b5ad14 == 0) {
    pvVar1 = operator_new(0x14);
    if (pvVar1 != (void *)0x0) {
      FUN_005a5f60();
    }
  }
  if (DAT_00b5afd0 == 0) {
    pvVar1 = operator_new(0xd8);
    if (pvVar1 != (void *)0x0) {
      FUN_005a5e50();
    }
  }
  if (DAT_00b5ae24 == 0) {
    pvVar1 = operator_new(0x18);
    if (pvVar1 != (void *)0x0) {
      FUN_005a5b60();
    }
  }
  if (DAT_00b5aea4 == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_005a5160();
    }
  }
  if (DAT_00b5add8 == 0) {
    pvVar1 = operator_new(0x38);
    if (pvVar1 != (void *)0x0) {
      FUN_005a4a90();
      return;
    }
  }
  return;
}


// ==== FUN_00595b60 @ 0x00595b60 ====

void FUN_00595b60(void)

{
  if (DAT_00b5a988 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a988)(1);
  }
  if (DAT_00b5ad14 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ad14)(1);
  }
  if (DAT_00b5afd0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afd0)(1);
  }
  if (DAT_00b5ae24 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae24)(1);
  }
  if (DAT_00b5aea4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5aea4)(1);
  }
  if (DAT_00b5add8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5add8)(1);
  }
  return;
}


// ==== FUN_00595bd0 @ 0x00595bd0 ====

void FUN_00595bd0(void)

{
  void *pvVar1;
  
  if (DAT_00b5afac == 0) {
    pvVar1 = operator_new(0x1a8);
    if (pvVar1 != (void *)0x0) {
      FUN_005a7840();
      return;
    }
  }
  return;
}


// ==== FUN_00595c00 @ 0x00595c00 ====

void FUN_00595c00(void)

{
  if (DAT_00b5afac != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afac)(1);
  }
  return;
}


// ==== FUN_00595c20 @ 0x00595c20 ====

void FUN_00595c20(int param_1)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  float fVar3;
  
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x10);
  fVar3 = *(float *)(in_ECX + 0x60);
  *(undefined4 *)(in_ECX + 0xbc) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc4) = *(undefined4 *)(param_1 + 0xc);
  if ((*(char *)(in_ECX + 8) == '\0') || (*(char *)(in_ECX + 0xc) != '\x01')) {
    *(undefined4 *)(in_ECX + 0xac) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_ECX + 0xb0) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(in_ECX + 0xb4) = *(undefined4 *)(param_1 + 0xc);
  }
  else {
    fVar2 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 0x60),*(undefined4 *)(in_ECX + 0x10),
                                  *(undefined4 *)(in_ECX + 200));
    fVar3 = (float)fVar2;
  }
  *(float *)(*(int *)(in_ECX + 4) + 0x5c) = fVar3;
  iVar1 = *(int *)(in_ECX + 4);
  *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(in_ECX + 0xac);
  *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(in_ECX + 0xb0);
  *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(in_ECX + 0xb4);
  return;
}


// ==== FUN_00595ce0 @ 0x00595ce0 ====

void FUN_00595ce0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_8;
  
  iVar2 = *(int *)(in_ECX + 4);
  uVar1 = *(undefined1 *)(param_1 + 8);
  local_8 = CONCAT22(*(undefined2 *)(param_1 + 5),
                     CONCAT11(*(undefined1 *)(param_1 + 7),*(undefined1 *)(param_1 + 4)));
  *(undefined4 *)(iVar2 + 0x91) = local_8;
  *(undefined1 *)(iVar2 + 0x95) = uVar1;
  return;
}


// ==== FUN_00595d20 @ 0x00595d20 ====

void FUN_00595d20(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  
  *(undefined1 *)(in_ECX + 0xa0) = *(undefined1 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0xa4) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xa8) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0xf0) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0xf4) = *(undefined4 *)(param_1 + 0x14);
  puVar1 = (undefined4 *)(in_ECX + 0xe4);
  *(undefined1 *)puVar1 = *(undefined1 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0xe8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xec) = *(undefined4 *)(param_1 + 0xc);
  if ((*(char *)(in_ECX + 8) != '\0') && (*(char *)(in_ECX + 0x50) != '\0')) {
    if (*(float *)(in_ECX + 0x54) == DAT_0099cdc8) {
      *(undefined1 *)puVar1 = 1;
    }
    else {
      *(undefined1 *)puVar1 = 0;
    }
    fVar3 = (float10)FUN_0040d140(*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 0x54),
                                  *(undefined4 *)(in_ECX + 200));
    *(float *)(in_ECX + 0xe8) = (float)fVar3;
    fVar3 = (float10)FUN_0040d140(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(in_ECX + 0x58),
                                  *(undefined4 *)(in_ECX + 200));
    *(float *)(in_ECX + 0xec) = (float)fVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  *(undefined4 *)(iVar2 + 0x7c) = *puVar1;
  *(undefined4 *)(iVar2 + 0x80) = *(undefined4 *)(in_ECX + 0xe8);
  *(undefined4 *)(iVar2 + 0x84) = *(undefined4 *)(in_ECX + 0xec);
  *(undefined4 *)(iVar2 + 0x88) = *(undefined4 *)(in_ECX + 0xf0);
  *(undefined4 *)(iVar2 + 0x8c) = *(undefined4 *)(in_ECX + 0xf4);
  return;
}


// ==== FUN_00595e20 @ 0x00595e20 ====

void FUN_00595e20(void)

{
  float *pfVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  fVar5 = *(float *)(in_ECX + 0x8c);
  fVar9 = *(float *)(in_ECX + 0x88);
  fVar10 = *(float *)(in_ECX + 0x90);
  pfVar1 = (float *)(in_ECX + 0x94);
  fVar6 = *pfVar1;
  fVar7 = *(float *)(in_ECX + 0x98);
  fVar8 = *(float *)(in_ECX + 0x9c);
  if ((*(char *)(in_ECX + 8) != '\0') && (*(char *)(in_ECX + 0x34) == '\x01')) {
    fVar4 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x38),
                                  *(undefined4 *)(in_ECX + 200));
    fVar9 = (float)fVar4;
    fVar4 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 0x8c),*(undefined4 *)(in_ECX + 0x3c),
                                  *(undefined4 *)(in_ECX + 200));
    fVar5 = (float)fVar4;
    fVar4 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 0x90),*(undefined4 *)(in_ECX + 0x40),
                                  *(undefined4 *)(in_ECX + 200));
    fVar10 = (float)fVar4;
    fVar8 = *(float *)(in_ECX + 200);
    fVar6 = (*(float *)(in_ECX + 0x44) - *pfVar1) * fVar8 + *pfVar1;
    fVar7 = (*(float *)(in_ECX + 0x48) - *(float *)(in_ECX + 0x98)) * fVar8 +
            *(float *)(in_ECX + 0x98);
    fVar8 = (*(float *)(in_ECX + 0x4c) - *(float *)(in_ECX + 0x9c)) * fVar8 +
            *(float *)(in_ECX + 0x9c);
  }
  uVar2 = *(undefined4 *)(in_ECX + 0xb8);
  *(float *)(in_ECX + 0xe0) = fVar5;
  iVar3 = *(int *)(in_ECX + 4);
  *(float *)(iVar3 + 0x60) = fVar9;
  *(float *)(iVar3 + 100) = fVar5;
  *(float *)(iVar3 + 0x68) = fVar10;
  *(undefined4 *)(iVar3 + 0x6c) = uVar2;
  *(float *)(iVar3 + 0x70) = fVar6;
  *(float *)(iVar3 + 0x74) = fVar7;
  *(float *)(iVar3 + 0x78) = fVar8;
  return;
}


// ==== FUN_00595f60 @ 0x00595f60 ====

void FUN_00595f60(int param_1)

{
  float *pfVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  pfVar1 = (float *)(in_ECX + 0x68);
  *pfVar1 = *(float *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(param_1 + 0xc);
  fVar4 = *(float *)(param_1 + 0x10);
  fVar5 = *pfVar1;
  fVar6 = *(float *)(in_ECX + 0x6c);
  fVar7 = *(float *)(in_ECX + 0x70);
  *(float *)(in_ECX + 100) = fVar4;
  if ((*(char *)(in_ECX + 8) != '\0') && (*(char *)(in_ECX + 0xc) == '\x01')) {
    fVar7 = *(float *)(in_ECX + 200);
    fVar5 = (*(float *)(in_ECX + 0x18) - *pfVar1) * fVar7 + *pfVar1;
    fVar6 = (*(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x6c)) * fVar7 +
            *(float *)(in_ECX + 0x6c);
    fVar7 = (*(float *)(in_ECX + 0x20) - *(float *)(in_ECX + 0x70)) * fVar7 +
            *(float *)(in_ECX + 0x70);
    fVar3 = (float10)FUN_0040d140(fVar4,*(undefined4 *)(in_ECX + 0x14),*(undefined4 *)(in_ECX + 200)
                                 );
    fVar4 = (float)fVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  *(float *)(iVar2 + 0x40) = fVar5;
  *(float *)(iVar2 + 0x44) = fVar6;
  *(float *)(iVar2 + 0x48) = fVar7;
  *(float *)(*(int *)(in_ECX + 4) + 0x4c) = fVar4;
  return;
}


// ==== FUN_00596050 @ 0x00596050 ====

void FUN_00596050(int param_1)

{
  float *pfVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  pfVar1 = (float *)(in_ECX + 0x78);
  *pfVar1 = *(float *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(param_1 + 0x18);
  fVar4 = *(float *)(param_1 + 0x1c);
  fVar5 = *pfVar1;
  fVar6 = *(float *)(in_ECX + 0x7c);
  fVar7 = *(float *)(in_ECX + 0x80);
  *(float *)(in_ECX + 0x74) = fVar4;
  if ((*(char *)(in_ECX + 8) != '\0') && (*(char *)(in_ECX + 0xc) == '\x01')) {
    fVar7 = *(float *)(in_ECX + 200);
    fVar5 = (*(float *)(in_ECX + 0x28) - *pfVar1) * fVar7 + *pfVar1;
    fVar6 = (*(float *)(in_ECX + 0x2c) - *(float *)(in_ECX + 0x7c)) * fVar7 +
            *(float *)(in_ECX + 0x7c);
    fVar7 = (*(float *)(in_ECX + 0x30) - *(float *)(in_ECX + 0x80)) * fVar7 +
            *(float *)(in_ECX + 0x80);
    fVar3 = (float10)FUN_0040d140(fVar4,*(undefined4 *)(in_ECX + 0x24),*(undefined4 *)(in_ECX + 200)
                                 );
    fVar4 = (float)fVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  *(float *)(iVar2 + 0x24) = fVar5;
  *(float *)(iVar2 + 0x28) = fVar6;
  *(float *)(iVar2 + 0x2c) = fVar7;
  *(float *)(*(int *)(in_ECX + 4) + 0x3c) = fVar4;
  iVar2 = *(int *)(in_ECX + 4);
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(param_1 + 0xc);
  return;
}


// ==== FUN_00596160 @ 0x00596160 ====

void FUN_00596160(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  int iVar12;
  int in_ECX;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  
  if ((*(float *)(in_ECX + 0xcc) == *(float *)(in_ECX + 200)) &&
     (*(float *)(in_ECX + 200) == DAT_0099cdc8)) {
    *(undefined1 *)(in_ECX + 8) = 0;
    return;
  }
  if (*(char *)(in_ECX + 0xc) != '\0') {
    fVar13 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 0x60),*(undefined4 *)(in_ECX + 0x10),
                                   *(undefined4 *)(in_ECX + 200));
    *(float *)(*(int *)(in_ECX + 4) + 0x5c) = (float)fVar13;
    fVar13 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 100),*(undefined4 *)(in_ECX + 0x14),
                                   *(undefined4 *)(in_ECX + 200));
    fVar1 = *(float *)(in_ECX + 200);
    iVar12 = *(int *)(in_ECX + 4);
    fVar2 = *(float *)(in_ECX + 0x1c);
    fVar3 = *(float *)(in_ECX + 0x6c);
    fVar4 = *(float *)(in_ECX + 0x6c);
    fVar5 = *(float *)(in_ECX + 0x20);
    fVar6 = *(float *)(in_ECX + 0x70);
    fVar7 = *(float *)(in_ECX + 0x70);
    *(float *)(iVar12 + 0x40) =
         (*(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0x68)) * fVar1 + *(float *)(in_ECX + 0x68)
    ;
    *(float *)(iVar12 + 0x44) = (fVar2 - fVar3) * fVar1 + fVar4;
    *(float *)(iVar12 + 0x48) = (fVar5 - fVar6) * fVar1 + fVar7;
    *(float *)(*(int *)(in_ECX + 4) + 0x4c) = (float)fVar13;
    iVar12 = *(int *)(in_ECX + 4);
    *(undefined4 *)(iVar12 + 0x50) = *(undefined4 *)(in_ECX + 0xac);
    *(undefined4 *)(iVar12 + 0x54) = *(undefined4 *)(in_ECX + 0xb0);
    *(undefined4 *)(iVar12 + 0x58) = *(undefined4 *)(in_ECX + 0xb4);
    fVar13 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 0x74),*(undefined4 *)(in_ECX + 0x24),
                                   *(undefined4 *)(in_ECX + 200));
    fVar1 = *(float *)(in_ECX + 200);
    iVar12 = *(int *)(in_ECX + 4);
    fVar2 = *(float *)(in_ECX + 0x2c);
    fVar3 = *(float *)(in_ECX + 0x7c);
    fVar4 = *(float *)(in_ECX + 0x7c);
    fVar5 = *(float *)(in_ECX + 0x30);
    fVar6 = *(float *)(in_ECX + 0x80);
    fVar7 = *(float *)(in_ECX + 0x80);
    *(float *)(iVar12 + 0x24) =
         (*(float *)(in_ECX + 0x28) - *(float *)(in_ECX + 0x78)) * fVar1 + *(float *)(in_ECX + 0x78)
    ;
    *(float *)(iVar12 + 0x28) = (fVar2 - fVar3) * fVar1 + fVar4;
    *(float *)(iVar12 + 0x2c) = (fVar5 - fVar6) * fVar1 + fVar7;
    *(float *)(*(int *)(in_ECX + 4) + 0x3c) = (float)fVar13;
  }
  if (*(char *)(in_ECX + 0x34) != '\0') {
    fVar13 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x38),
                                   *(undefined4 *)(in_ECX + 200));
    fVar14 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 0x8c),*(undefined4 *)(in_ECX + 0x3c),
                                   *(undefined4 *)(in_ECX + 200));
    fVar15 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 0x90),*(undefined4 *)(in_ECX + 0x40),
                                   *(undefined4 *)(in_ECX + 200));
    fVar1 = *(float *)(in_ECX + 200);
    fVar2 = *(float *)(in_ECX + 0x44);
    fVar3 = *(float *)(in_ECX + 0x94);
    iVar12 = *(int *)(in_ECX + 4);
    fVar4 = *(float *)(in_ECX + 0x94);
    fVar5 = *(float *)(in_ECX + 0x48);
    fVar6 = *(float *)(in_ECX + 0x98);
    fVar7 = *(float *)(in_ECX + 0x98);
    fVar8 = *(float *)(in_ECX + 0x4c);
    fVar9 = *(float *)(in_ECX + 0x9c);
    fVar10 = *(float *)(in_ECX + 0x9c);
    uVar11 = *(undefined4 *)(in_ECX + 0xb8);
    *(float *)(iVar12 + 0x68) = (float)fVar15;
    *(float *)(iVar12 + 0x60) = (float)fVar13;
    *(float *)(iVar12 + 100) = (float)fVar14;
    *(undefined4 *)(iVar12 + 0x6c) = uVar11;
    *(float *)(iVar12 + 0x70) = (fVar2 - fVar3) * fVar1 + fVar4;
    *(float *)(iVar12 + 0x74) = (fVar5 - fVar6) * fVar1 + fVar7;
    *(float *)(iVar12 + 0x78) = (fVar8 - fVar9) * fVar1 + fVar10;
  }
  if (*(char *)(in_ECX + 0x50) != '\0') {
    if (*(float *)(in_ECX + 0x54) <= DAT_0099cdc8) {
      *(undefined1 *)(in_ECX + 0xe4) = 0;
    }
    else {
      *(undefined1 *)(in_ECX + 0xe4) = 1;
    }
    fVar13 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 0xa4),*(undefined4 *)(in_ECX + 0x54),
                                   *(undefined4 *)(in_ECX + 200));
    *(float *)(in_ECX + 0xe8) = (float)fVar13;
    fVar13 = (float10)FUN_0040d140(*(undefined4 *)(in_ECX + 0xa8),*(undefined4 *)(in_ECX + 0x58),
                                   *(undefined4 *)(in_ECX + 200));
    *(float *)(in_ECX + 0xec) = (float)fVar13;
    iVar12 = *(int *)(in_ECX + 4);
    *(undefined4 *)(iVar12 + 0x7c) = *(undefined4 *)(in_ECX + 0xe4);
    *(undefined4 *)(iVar12 + 0x80) = *(undefined4 *)(in_ECX + 0xe8);
    *(undefined4 *)(iVar12 + 0x84) = *(undefined4 *)(in_ECX + 0xec);
    *(undefined4 *)(iVar12 + 0x88) = *(undefined4 *)(in_ECX + 0xf0);
    *(undefined4 *)(iVar12 + 0x8c) = *(undefined4 *)(in_ECX + 0xf4);
  }
  *(undefined4 *)(in_ECX + 0xcc) = *(undefined4 *)(in_ECX + 200);
  *(undefined1 *)(in_ECX + 8) = 1;
  return;
}


// ==== FUN_005964a0 @ 0x005964a0 ====

void FUN_005964a0(int param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x84) = 1;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined4 *)(in_ECX + 0x94) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x9c) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xb8) = *(undefined4 *)(param_1 + 4);
  FUN_00595e20();
  return;
}


// ==== FUN_005964f0 @ 0x005964f0 ====

void FUN_005964f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x94) = param_1;
  *(undefined4 *)(in_ECX + 0x8c) = param_4;
  *(undefined4 *)(in_ECX + 0x98) = param_2;
  *(undefined4 *)(in_ECX + 0x88) = param_5;
  *(undefined4 *)(in_ECX + 0x9c) = param_3;
  *(undefined4 *)(in_ECX + 0xb8) = param_6;
  FUN_00595e20();
  return;
}


// ==== FUN_00596540 @ 0x00596540 ====

void FUN_00596540(float param_1)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0x8c) = param_1;
  param_1 = param_1 - DAT_0099d100;
  if (*(float *)(in_ECX + 0x88) <= param_1 && param_1 != *(float *)(in_ECX + 0x88)) {
    param_1 = *(float *)(in_ECX + 0x88);
  }
  *(float *)(in_ECX + 0x88) = param_1;
  FUN_00595e20();
  return;
}


// ==== FUN_00596580 @ 0x00596580 ====

void FUN_00596580(int param_1)

{
  undefined1 *puVar1;
  int in_ECX;
  
  puVar1 = *(undefined1 **)(in_ECX + 0xd4);
  if (puVar1 != *(undefined1 **)(in_ECX + 0xd8)) {
    while (*(int *)(puVar1 + 4) != *(int *)(param_1 + 4)) {
      puVar1 = puVar1 + 0x80;
      if (puVar1 == *(undefined1 **)(in_ECX + 0xd8)) {
        return;
      }
    }
    *puVar1 = 1;
  }
  return;
}


// ==== FUN_005965b0 @ 0x005965b0 ====

/* WARNING: Removing unreachable block (ram,0x005965e7) */

void FUN_005965b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf59c;
  if ((void *)in_ECX[0x35] == (void *)0x0) {
    in_ECX[0x35] = 0;
    in_ECX[0x36] = 0;
    in_ECX[0x37] = 0;
    in_ECX[0x35] = 0;
    in_ECX[0x36] = 0;
    in_ECX[0x37] = 0;
    return;
  }
  _free((void *)in_ECX[0x35]);
  return;
}


// ==== FUN_00596610 @ 0x00596610 ====

void FUN_00596610(uint param_1)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int in_ECX;
  int local_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((*(int *)(in_ECX + 0xd4) != 0) &&
     (local_10 = *(int *)(in_ECX + 0xd8) - *(int *)(in_ECX + 0xd4) >> 7, local_10 != 0)) {
    iVar2 = (**(code **)(*DAT_00b5a988 + 0x14))();
    fStack_c = *(float *)(iVar2 + 0x34);
    fStack_8 = *(float *)(iVar2 + 0x38);
    fStack_4 = *(float *)(iVar2 + 0x3c);
    pcVar4 = *(char **)(in_ECX + 0xd4);
    if (pcVar4 != *(char **)(in_ECX + 0xd8)) {
      do {
        fVar1 = SQRT((fStack_c - *(float *)(pcVar4 + 0x24)) * (fStack_c - *(float *)(pcVar4 + 0x24))
                     + (fStack_8 - *(float *)(pcVar4 + 0x28)) *
                       (fStack_8 - *(float *)(pcVar4 + 0x28)) +
                       (fStack_4 - *(float *)(pcVar4 + 0x2c)) *
                       (fStack_4 - *(float *)(pcVar4 + 0x2c)));
        *(float *)(pcVar4 + 0x18) = fVar1;
        if (*pcVar4 == '\0') {
          *(uint *)(pcVar4 + 0xc) = *(int *)(pcVar4 + 0xc) - param_1;
          if (*(uint *)(pcVar4 + 0xc) < *(uint *)(pcVar4 + 8)) {
            *pcVar4 = '\x01';
          }
LAB_005966e8:
          pcVar4 = pcVar4 + 0x80;
        }
        else {
          if ((param_1 <= *(uint *)(pcVar4 + 0x10)) && (fVar1 < *(float *)(pcVar4 + 0x1c))) {
            *(uint *)(pcVar4 + 0x10) = *(uint *)(pcVar4 + 0x10) - param_1;
            goto LAB_005966e8;
          }
          puVar3 = (undefined4 *)FUN_00597700(&local_10,pcVar4);
          pcVar4 = (char *)*puVar3;
        }
      } while (pcVar4 != *(char **)(in_ECX + 0xd8));
    }
    FUN_005977e0(*(int *)(in_ECX + 0xd4),*(int *)(in_ECX + 0xd8),
                 *(int *)(in_ECX + 0xd8) - *(int *)(in_ECX + 0xd4) >> 7,&LAB_0045ac40);
  }
  return;
}


// ==== FUN_00596730 @ 0x00596730 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00596730(undefined4 param_1)

{
  uint uVar1;
  char *pcVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  float fVar7;
  float fVar8;
  
  FUN_00596610(param_1);
  if ((*(int *)(in_ECX + 0xd4) == 0) ||
     (*(int *)(in_ECX + 0xd8) - *(int *)(in_ECX + 0xd4) >> 7 == 0)) {
    *(undefined4 *)(in_ECX + 200) = 0;
    *(undefined1 *)(in_ECX + 8) = 0;
    FUN_00596160();
    return;
  }
  pcVar2 = *(char **)(in_ECX + 0xd4);
  *(undefined4 *)(in_ECX + 200) = 0;
  if (pcVar2 == *(char **)(in_ECX + 0xd8)) {
LAB_005968ac:
    FUN_00596160();
    return;
  }
  do {
    if (*(float *)(pcVar2 + 0x18) < *(float *)(pcVar2 + 0x1c)) {
      uVar3 = *(int *)(pcVar2 + 0x14) - *(int *)(pcVar2 + 0xc);
      if (*pcVar2 == '\0') {
        uVar1 = *(uint *)(pcVar2 + 8);
        fVar8 = DAT_0099d080;
        if (uVar3 < uVar1) {
          fVar8 = (float)(int)uVar3;
          if ((int)uVar3 < 0) {
            fVar8 = fVar8 + _DAT_0099d104;
          }
          uVar3 = uVar1;
          goto LAB_005967fa;
        }
      }
      else {
        fVar8 = (float)*(int *)(pcVar2 + 0x10);
        if (*(int *)(pcVar2 + 0x10) < 0) {
          fVar8 = fVar8 + _DAT_0099d104;
        }
        uVar1 = *(uint *)(pcVar2 + 8);
        uVar3 = *(uint *)(pcVar2 + 8);
LAB_005967fa:
        fVar7 = (float)(int)uVar3;
        if ((int)uVar1 < 0) {
          fVar7 = fVar7 + _DAT_0099d104;
        }
        fVar8 = fVar8 / fVar7;
      }
      fVar7 = DAT_0099d080;
      if (*(float *)(pcVar2 + 0x1c) - *(float *)(pcVar2 + 0x20) < *(float *)(pcVar2 + 0x18)) {
        fVar7 = (*(float *)(pcVar2 + 0x1c) - *(float *)(pcVar2 + 0x18)) / *(float *)(pcVar2 + 0x20);
      }
      if (fVar8 < fVar7) {
        fVar7 = fVar8;
      }
      if (0.0 < fVar7) {
        *(undefined4 *)(in_ECX + 0xac) = *(undefined4 *)(pcVar2 + 0x24);
        *(undefined4 *)(in_ECX + 0xb0) = *(undefined4 *)(pcVar2 + 0x28);
        *(undefined4 *)(in_ECX + 0xb4) = *(undefined4 *)(pcVar2 + 0x2c);
        pcVar5 = pcVar2 + 0x30;
        puVar6 = (undefined4 *)(in_ECX + 0xc);
        for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          puVar6 = puVar6 + 1;
        }
        pcVar5 = pcVar2 + 0x58;
        puVar6 = (undefined4 *)(in_ECX + 0x34);
        for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          puVar6 = puVar6 + 1;
        }
        *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(pcVar2 + 0x74);
        *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(pcVar2 + 0x78);
        *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(pcVar2 + 0x7c);
        *(float *)(in_ECX + 200) = fVar7;
        goto LAB_005968ac;
      }
    }
    pcVar2 = pcVar2 + 0x80;
    if (pcVar2 == *(char **)(in_ECX + 0xd8)) {
      FUN_00596160();
      return;
    }
  } while( true );
}


// ==== FUN_005968c0 @ 0x005968c0 ====

void FUN_005968c0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar1 = DAT_009bf5a0;
  uVar2 = DAT_009b0e84;
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009bf59c;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x22] = uVar1;
  in_ECX[0x23] = DAT_009b012c;
  uVar1 = DAT_0099d080;
  in_ECX[0x25] = DAT_0099d080;
  in_ECX[0x26] = uVar1;
  in_ECX[0x27] = uVar1;
  in_ECX[0x1e] = uVar1;
  in_ECX[0x1f] = uVar1;
  in_ECX[0x20] = uVar1;
  *(undefined1 *)(in_ECX + 0x21) = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x1d] = uVar1;
  in_ECX[0x19] = uVar1;
  in_ECX[0x2e] = uVar1;
  in_ECX[0x38] = uVar2;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  *(undefined1 *)(in_ECX + 0x39) = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = uVar1;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  return;
}


// ==== FUN_005969e0 @ 0x005969e0 ====

void FUN_005969e0(int param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int in_ECX;
  undefined1 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined1 auStack_80 [4];
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  float fStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  float fStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 auStack_50 [10];
  undefined4 auStack_28 [7];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar6 = (**(code **)(*DAT_00b5a988 + 0x14))();
  pfVar1 = (float *)(param_1 + 0x18);
  fVar3 = *(float *)(iVar6 + 0x34) - *pfVar1;
  fVar5 = *(float *)(iVar6 + 0x38) - *(float *)(param_1 + 0x1c);
  fVar4 = *(float *)(iVar6 + 0x3c) - *(float *)(param_1 + 0x20);
  puVar7 = *(undefined1 **)(in_ECX + 0xd4);
  fStack_68 = SQRT(fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4);
  if (puVar7 != *(undefined1 **)(in_ECX + 0xd8)) {
    do {
      if (*(int *)(puVar7 + 4) == *(int *)(param_1 + 4)) {
        *(float *)(puVar7 + 0x24) = *pfVar1;
        *(undefined4 *)(puVar7 + 0x28) = *(undefined4 *)(param_1 + 0x1c);
        *(undefined4 *)(puVar7 + 0x2c) = *(undefined4 *)(param_1 + 0x20);
        uVar2 = *(undefined4 *)(param_1 + 8);
        *(undefined4 *)(puVar7 + 0x14) = uVar2;
        *(undefined4 *)(puVar7 + 0xc) = uVar2;
        *(undefined4 *)(puVar7 + 0x10) = *(undefined4 *)(param_1 + 0xc);
        *(float *)(puVar7 + 0x18) = fStack_68;
        *puVar7 = 0;
        return;
      }
      puVar7 = puVar7 + 0x80;
    } while (puVar7 != *(undefined1 **)(in_ECX + 0xd8));
  }
  uStack_7c = *(undefined4 *)(param_1 + 4);
  fStack_5c = *pfVar1;
  uStack_58 = *(undefined4 *)(param_1 + 0x1c);
  uStack_54 = *(undefined4 *)(param_1 + 0x20);
  uStack_74 = *(undefined4 *)(param_1 + 8);
  uStack_78 = *(undefined4 *)(param_1 + 0xc);
  uStack_64 = *(undefined4 *)(param_1 + 0x10);
  uStack_60 = *(undefined4 *)(param_1 + 0x14);
  puVar8 = (undefined4 *)(param_1 + 0x4c);
  puVar9 = auStack_50;
  for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  uStack_c = *(undefined4 *)(param_1 + 0x24);
  uStack_8 = *(undefined4 *)(param_1 + 0x28);
  uStack_4 = *(undefined4 *)(param_1 + 0x2c);
  puVar8 = (undefined4 *)(param_1 + 0x30);
  puVar9 = auStack_28;
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  iVar6 = *(int *)(in_ECX + 0xd4);
  auStack_80[0] = 0;
  uStack_70 = uStack_78;
  uStack_6c = uStack_74;
  if ((iVar6 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xdc) - iVar6 >> 7) <= (uint)(*(int *)(in_ECX + 0xd8) - iVar6 >> 7)))
  {
    FUN_00597900(*(undefined4 *)(in_ECX + 0xd8),1,auStack_80);
    return;
  }
  iVar6 = *(int *)(in_ECX + 0xd8);
  FUN_00597070(iVar6,1,auStack_80,in_ECX + 0xd0,fStack_68);
  *(int *)(in_ECX + 0xd8) = iVar6 + 0x80;
  return;
}


// ==== FUN_00596be0 @ 0x00596be0 ====

undefined4 FUN_00596be0(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x60040006) {
    if (uVar1 == 0x60040005) {
      FUN_00595d20(param_1);
      return 1;
    }
    if (uVar1 < 0x60040002) {
      if (uVar1 == 0x60040001) {
        FUN_00595f60(param_1);
        return 1;
      }
      if (uVar1 == 0x40001) {
        FUN_00596730(param_1[1]);
      }
      else if (uVar1 == 0x10040019) {
        FUN_005964a0(param_1);
        return 1;
      }
    }
    else {
      if (uVar1 == 0x60040002) {
        FUN_00596050(param_1);
        return 1;
      }
      if (uVar1 == 0x60040004) {
        FUN_00595c20(param_1);
        return 1;
      }
    }
  }
  else {
    switch(uVar1) {
    case 0x60040010:
      FUN_005969e0(param_1);
      return 1;
    case 0x60040011:
      FUN_00596580(param_1);
      return 1;
    case 0x60040020:
      *(char *)(*(int *)(in_ECX + 4) + 0x90) = (char)param_1[2];
      *(char *)(*(int *)(in_ECX + 4) + 0x21) = (char)param_1[1];
      return 1;
    case 0x60040021:
      FUN_00595ce0(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00596d10 @ 0x00596d10 ====

void FUN_00596d10(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 0x20;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 0x20; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_00596d40 @ 0x00596d40 ====

void FUN_00596d40(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0x20;
    param_3 = param_3 + -0x20;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_00596d80 @ 0x00596d80 ====

void FUN_00596d80(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_00596da0 @ 0x00596da0 ====

int FUN_00596da0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009824a0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x80) {
    FUN_00596d80(param_3,param_1);
    param_3 = param_3 + 0x80;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00596e0c @ 0x00596e0c ====

void Catch_00596e0c(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00596e20 @ 0x00596e20 ====

void FUN_00596e20(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,code *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_88 [33];
  
  cVar1 = (*param_4)(param_2,param_1);
  if (cVar1 != '\0') {
    puVar3 = param_2;
    puVar4 = auStack_88;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar3 = param_1;
    puVar4 = param_2;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar3 = auStack_88;
    puVar4 = param_1;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  cVar1 = (*param_4)(param_3,param_2);
  if (cVar1 != '\0') {
    puVar3 = param_3;
    puVar4 = auStack_88;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar3 = param_2;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_3 = *puVar3;
      puVar3 = puVar3 + 1;
      param_3 = param_3 + 1;
    }
    puVar3 = auStack_88;
    puVar4 = param_2;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  cVar1 = (*param_4)(param_2,param_1);
  if (cVar1 != '\0') {
    puVar3 = param_2;
    puVar4 = auStack_88;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar3 = param_1;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
    puVar3 = auStack_88;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = *puVar3;
      puVar3 = puVar3 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_00596ee0 @ 0x00596ee0 ====

void FUN_00596ee0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  code *in_stack_00000090;
  
  if (param_3 < param_2) {
    do {
      iVar3 = (param_2 + -1) / 2;
      puVar4 = (undefined4 *)(iVar3 * 0x80 + param_1);
      cVar1 = (*in_stack_00000090)(puVar4,&param_4);
      if (cVar1 == '\0') break;
      puVar5 = (undefined4 *)(param_2 * 0x80 + param_1);
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      param_2 = iVar3;
    } while (param_3 < iVar3);
  }
  puVar4 = &param_4;
  puVar5 = (undefined4 *)(param_2 * 0x80 + param_1);
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  return;
}


// ==== FUN_00596f50 @ 0x00596f50 ====

void FUN_00596f50(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 **ppuVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_9c;
  undefined4 *local_98;
  undefined4 *local_94;
  undefined4 *local_90;
  int local_8c;
  undefined4 local_88 [33];
  
  local_8c = param_2 - (int)param_1 >> 7;
  iVar5 = (int)param_3 - (int)param_1 >> 7;
  local_9c = iVar5;
  if (local_8c != 0) {
    iVar3 = iVar5;
    iVar4 = local_8c;
    do {
      local_9c = iVar4;
      iVar4 = iVar3 % local_9c;
      iVar3 = local_9c;
    } while (iVar4 != 0);
  }
  if ((local_9c < iVar5) && (0 < local_9c)) {
    puVar6 = param_1 + local_9c * 0x20;
    do {
      puVar7 = puVar6;
      puVar8 = local_88;
      for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      if (puVar6 + local_8c * 0x20 == param_3) {
        ppuVar2 = &param_1;
      }
      else {
        local_98 = puVar6 + local_8c * 0x20;
        ppuVar2 = &local_98;
      }
      puVar8 = *ppuVar2;
      puVar7 = puVar6;
      while (puVar1 = puVar8, puVar1 != puVar6) {
        puVar8 = puVar1;
        for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar7 = puVar7 + 1;
        }
        iVar5 = (int)param_3 - (int)puVar1 >> 7;
        if (local_8c < iVar5) {
          local_94 = puVar1 + local_8c * 0x20;
          ppuVar2 = &local_94;
        }
        else {
          ppuVar2 = &local_90;
          local_90 = param_1 + (iVar5 * 0x1ffffff + local_8c) * 0x20;
        }
        puVar7 = puVar1;
        puVar8 = *ppuVar2;
      }
      puVar6 = puVar6 + -0x20;
      local_9c = local_9c + -1;
      puVar8 = local_88;
      for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar7 = puVar7 + 1;
      }
    } while (local_9c != 0);
  }
  return;
}


// ==== FUN_00597070 @ 0x00597070 ====

void FUN_00597070(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009824b0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00596d80(param_1,param_3);
    param_1 = param_1 + 0x80;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005970d9 @ 0x005970d9 ====

void Catch_005970d9(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005970f0 @ 0x005970f0 ====

void FUN_005970f0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_3 - param_1 >> 7;
  if (iVar1 < 0x29) {
    FUN_00596e20();
    return;
  }
  iVar1 = iVar1 + 1;
  iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
  iVar1 = iVar2 * 0x80 + param_1;
  FUN_00596e20(param_1,iVar1,iVar2 * 0x100 + param_1,param_4);
  FUN_00596e20(param_2 + iVar2 * -0x80,param_2,iVar2 * 0x80 + param_2,param_4);
  iVar3 = param_3 + iVar2 * -0x80;
  FUN_00596e20(param_3 + iVar2 * -0x100,iVar3,param_3,param_4);
  FUN_00596e20(iVar1,param_2,iVar3,param_4);
  return;
}


// ==== FUN_00597190 @ 0x00597190 ====

void FUN_00597190(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  code *in_stack_00000090;
  undefined4 auStack_98 [30];
  undefined4 uStack_20;
  int iStack_1c;
  code *pcStack_18;
  
  iVar1 = param_2;
  while( true ) {
    iVar3 = param_2 * 2;
    iVar4 = iVar3 + 2;
    if (param_3 <= iVar4) break;
    pcStack_18 = (code *)((iVar3 + 0x2000001) * 0x80 + param_1);
    iStack_1c = iVar4 * 0x80 + param_1;
    uStack_20 = 0x5971cb;
    cVar2 = (*in_stack_00000090)();
    if (cVar2 != '\0') {
      iVar4 = iVar3 + 1;
    }
    puVar5 = (undefined4 *)(iVar4 * 0x80 + param_1);
    puVar6 = (undefined4 *)(param_2 * 0x80 + param_1);
    for (iVar3 = 0x20; param_2 = iVar4, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  if (iVar4 == param_3) {
    iVar3 = param_2 * 0x80;
    param_2 = param_3 + -1;
    puVar5 = (undefined4 *)((param_3 + 0x1ffffff) * 0x80 + param_1);
    puVar6 = (undefined4 *)(iVar3 + param_1);
    for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  puVar5 = &param_4;
  puVar6 = auStack_98;
  pcStack_18 = in_stack_00000090;
  for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  FUN_00596ee0(param_1,param_2,iVar1);
  return;
}


// ==== FUN_00597260 @ 0x00597260 ====

void FUN_00597260(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00596da0(param_1,param_2,param_3);
  return;
}


// ==== FUN_00597280 @ 0x00597280 ====

void FUN_00597280(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,code *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *local_398;
  undefined4 *puStack_390;
  undefined4 *local_38c;
  undefined4 auStack_388 [32];
  undefined4 auStack_308 [32];
  undefined4 auStack_288 [32];
  undefined4 auStack_208 [32];
  undefined4 auStack_188 [32];
  undefined4 auStack_108 [32];
  undefined4 auStack_88 [33];
  
  puVar4 = param_2 + (((int)param_3 - (int)param_2 >> 7) - ((int)param_3 - (int)param_2 >> 0x1f) >>
                     1) * 0x20;
  FUN_005970f0(param_2,puVar4,param_3 + -0x20,param_4);
  puVar8 = puVar4;
  do {
    puStack_390 = puVar8;
    if (puStack_390 <= param_2) break;
    puVar8 = puStack_390 + -0x20;
    cVar1 = (*param_4)(puVar8,puStack_390);
    if (cVar1 != '\0') break;
    cVar1 = (*param_4)(puStack_390,puVar8);
  } while (cVar1 == '\0');
  do {
    puVar4 = puVar4 + 0x20;
    if ((param_3 <= puVar4) || (cVar1 = (*param_4)(puVar4,puStack_390), cVar1 != '\0')) break;
    cVar1 = (*param_4)(puStack_390,puVar4);
  } while (cVar1 == '\0');
  puVar8 = puVar4;
  puVar3 = puStack_390;
  do {
    while (param_3 <= puVar8) {
LAB_005973ad:
      if (param_2 < puStack_390) {
        local_38c = puStack_390;
        do {
          local_38c = local_38c + -0x20;
          cVar1 = (*param_4)(local_38c,puVar3);
          if (cVar1 == '\0') {
            cVar1 = (*param_4)(puVar3,local_38c);
            if (cVar1 != '\0') break;
            puVar3 = puVar3 + -0x20;
            puVar5 = puVar3;
            puVar7 = auStack_388;
            for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar7 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar5 = local_38c;
            puVar7 = puVar3;
            for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar7 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar5 = auStack_388;
            puVar7 = local_38c;
            for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar7 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar7 = puVar7 + 1;
            }
          }
          puStack_390 = puStack_390 + -0x20;
        } while (param_2 < puStack_390);
      }
      if (puStack_390 == param_2) {
        if (puVar8 == param_3) {
          *param_1 = puVar3;
          param_1[1] = puVar4;
          return;
        }
        if (puVar4 != puVar8) {
          puVar5 = puVar3;
          puVar7 = auStack_208;
          for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar5 = puVar4;
          puVar7 = puVar3;
          for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar5 = auStack_208;
          puVar7 = puVar4;
          for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
        }
        puVar4 = puVar4 + 0x20;
        puVar5 = puVar3;
        puVar7 = auStack_308;
        for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
        puVar5 = puVar8;
        puVar7 = puVar3;
        for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
        puVar5 = auStack_308;
        puVar7 = puVar8;
        for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
        puVar3 = puVar3 + 0x20;
        puVar8 = puVar8 + 0x20;
      }
      else {
        puStack_390 = puStack_390 + -0x20;
        if (puVar8 == param_3) {
          puVar3 = puVar3 + -0x20;
          if (puStack_390 != puVar3) {
            puVar5 = puStack_390;
            puVar7 = auStack_288;
            for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar7 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar5 = puVar3;
            puVar7 = puStack_390;
            for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar7 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar5 = auStack_288;
            puVar7 = puVar3;
            for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar7 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar7 = puVar7 + 1;
            }
          }
          puVar4 = puVar4 + -0x20;
          puVar5 = puVar3;
          puVar7 = auStack_188;
          for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar5 = puVar4;
          puVar7 = puVar3;
          for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar5 = auStack_188;
          puVar7 = puVar4;
          for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
        }
        else {
          puVar6 = puVar8 + 0x20;
          puVar5 = puVar8;
          puVar7 = auStack_88;
          for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar5 = puStack_390;
          for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar8 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar8 = puVar8 + 1;
          }
          puVar5 = auStack_88;
          puVar7 = puStack_390;
          for (iVar2 = 0x20; puVar8 = puVar6, iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
        }
      }
    }
    cVar1 = (*param_4)(puVar3,puVar8);
    local_398 = puVar4;
    if (cVar1 == '\0') {
      cVar1 = (*param_4)(puVar8,puVar3);
      if (cVar1 != '\0') goto LAB_005973ad;
      local_398 = puVar4 + 0x20;
      puVar5 = puVar4;
      puVar7 = auStack_108;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar5 = puVar8;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar4 = auStack_108;
      puVar5 = puVar8;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    puVar4 = local_398;
    puVar8 = puVar8 + 0x20;
  } while( true );
}


// ==== FUN_005975b0 @ 0x005975b0 ====

void FUN_005975b0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 auStack_94 [32];
  undefined4 uStack_14;
  
  iVar1 = param_2 - param_1 >> 7;
  iVar3 = iVar1 - (param_2 - param_1 >> 0x1f) >> 1;
  if (0 < iVar3) {
    puVar4 = (undefined4 *)(iVar3 * 0x80 + param_1);
    do {
      uStack_14 = param_3;
      puVar4 = puVar4 + -0x20;
      puVar5 = puVar4;
      puVar6 = auStack_94;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      iVar3 = iVar3 + -1;
      FUN_00597190(param_1,iVar3,iVar1);
    } while (0 < iVar3);
  }
  return;
}


// ==== FUN_00597620 @ 0x00597620 ====

int FUN_00597620(int param_1,int param_2,undefined4 param_3)

{
  FUN_00597070(param_1,param_2,param_3);
  return param_2 * 0x80 + param_1;
}


// ==== FUN_00597650 @ 0x00597650 ====

void FUN_00597650(int param_1,int param_2,code *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  
  iVar1 = param_1;
  if (param_1 != param_2) {
    while (iVar2 = iVar1, iVar1 = iVar2 + 0x80, iVar1 != param_2) {
      cVar4 = (*param_3)(iVar1,param_1);
      if (cVar4 == '\0') {
        cVar4 = (*param_3)(iVar1,iVar2);
        if (cVar4 != '\0') {
          iVar3 = iVar2;
          do {
            iVar5 = iVar3;
            cVar4 = (*param_3)(iVar1,iVar5 + -0x80);
            iVar3 = iVar5 + -0x80;
          } while (cVar4 != '\0');
          if ((iVar5 != iVar1) && (iVar1 != iVar2 + 0x100)) {
            FUN_00596f50(iVar5,iVar1,iVar2 + 0x100,0,0);
          }
        }
      }
      else if ((param_1 != iVar1) && (iVar1 != iVar2 + 0x100)) {
        FUN_00596f50(param_1,iVar1,iVar2 + 0x100,0,0);
      }
    }
  }
  return;
}


// ==== FUN_00597700 @ 0x00597700 ====

void FUN_00597700(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  if (param_2 + 0x20 != puVar1) {
    puVar2 = param_2 + 0x20;
    puVar5 = param_2;
    do {
      puVar3 = puVar2 + 0x20;
      puVar6 = puVar5;
      for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar2 = puVar3;
      puVar5 = puVar5 + 0x20;
    } while (puVar3 != puVar1);
  }
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x80;
  *param_1 = param_2;
  return;
}


// ==== FUN_00597750 @ 0x00597750 ====

void FUN_00597750(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_11c [32];
  undefined4 uStack_9c;
  undefined4 local_88 [33];
  
  for (param_2 = param_2 - (int)param_1; 1 < param_2 >> 7; param_2 = param_2 + -0x80) {
    puVar3 = (undefined4 *)((int)param_1 + param_2 + -0x80);
    puVar2 = puVar3;
    puVar4 = local_88;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    uStack_9c = param_3;
    puVar2 = param_1;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar3 = local_88;
    puVar2 = auStack_11c;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar2 = puVar2 + 1;
    }
    FUN_00597190(param_1,0,param_2 + -0x80 >> 7);
  }
  return;
}


// ==== FUN_005977e0 @ 0x005977e0 ====

void FUN_005977e0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_8;
  int local_4;
  
  iVar1 = param_2 - param_1 >> 7;
  if (0x20 < iVar1) {
    do {
      if (param_3 < 1) {
        if (0x20 < iVar1) {
          if (0x80 < (int)(param_2 - param_1 & 0xffffff80U)) {
            FUN_005975b0(param_1,param_2,param_4,0,0);
          }
          FUN_00597750(param_1,param_2,param_4);
          return;
        }
        break;
      }
      FUN_00597280(&local_8,param_1,param_2,param_4);
      iVar1 = local_4;
      param_3 = param_3 / 2 + (param_3 / 2) / 2;
      if ((int)(local_8 - param_1 & 0xffffff80U) < (int)(param_2 - local_4 & 0xffffff80U)) {
        FUN_005977e0(param_1,local_8,param_3,param_4);
        param_1 = iVar1;
      }
      else {
        FUN_005977e0(local_4,param_2,param_3,param_4);
        param_2 = local_8;
      }
      iVar1 = param_2 - param_1 >> 7;
    } while (0x20 < iVar1);
  }
  if (1 < iVar1) {
    FUN_00597650(param_1,param_2,param_4);
  }
  return;
}


// ==== FUN_005978e0 @ 0x005978e0 ====

void FUN_005978e0(byte param_1)

{
  void *in_ECX;
  
  FUN_005965b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00597900 @ 0x00597900 ====

void FUN_00597900(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 local_b0;
  uint local_28;
  undefined4 local_24;
  int local_20;
  void *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009824c0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0xbc);
  puVar5 = &local_b0;
  for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_3;
    param_3 = param_3 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar4 >> 7;
  }
  uVar6 = CONCAT44(iVar4,iVar1);
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 7;
    }
    ExceptionList = &local_10;
    if (0x1ffffffU - iVar4 < param_2) {
      ExceptionList = &local_10;
      uVar6 = FUN_0085b3b0();
    }
    iVar4 = (int)((ulonglong)uVar6 >> 0x20);
    local_28 = (uint)uVar6;
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar4 >> 7;
    }
    if (local_28 < iVar1 + param_2) {
      if (0x1ffffff - (local_28 >> 1) < local_28) {
        local_28 = 0;
      }
      else {
        local_28 = local_28 + (local_28 >> 1);
      }
      if (iVar4 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar4 >> 7;
      }
      if (local_28 < iVar1 + param_2) {
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 7;
        }
        local_28 = iVar4 + param_2;
      }
      local_28 = local_28 << 7;
      pvVar2 = operator_new(local_28);
      local_8 = 0;
      local_1c = pvVar2;
      local_24 = FUN_00597260(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      local_24 = FUN_00597620(local_24,param_2,&local_b0);
      FUN_00597260(param_1,*(undefined4 *)(in_ECX + 8),local_24);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - (int)_Memory >> 7;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_28 + (int)pvVar2;
        *(void **)(in_ECX + 8) = (void *)((param_2 + iVar4) * 0x80 + (int)pvVar2);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_20 = *(int *)(in_ECX + 8);
    if ((uint)(local_20 - param_1 >> 7) < param_2) {
      local_18 = param_2 * 0x80;
      FUN_00596da0(param_1,local_20,local_18 + param_1);
      local_8 = 2;
      FUN_00597620(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 7),&local_b0);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_00596d10(param_1,*(int *)(in_ECX + 8) - local_18,&local_b0);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x80;
    iVar4 = local_20 + param_2 * -0x80;
    uVar3 = FUN_00596da0(iVar4,local_20,local_20);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_00596d40(param_1,iVar4,local_20);
    FUN_00596d10(param_1,local_18 + param_1,&local_b0);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00597a6d @ 0x00597a6d ====

void Catch_00597a6d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00597b60 @ 0x00597b60 ====

void FUN_00597b60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf5fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00597b80 @ 0x00597b80 ====

void FUN_00597b80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf618;
  in_ECX[1] = 0xffffffff;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5afb4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afb4 = in_ECX;
  return;
}


// ==== FUN_00597bc0 @ 0x00597bc0 ====

undefined4 FUN_00597bc0(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) != 0) && (cVar1 = FUN_00593ff0(param_1), cVar1 != '\0')) {
    return 1;
  }
  if ((*(int *)(in_ECX + 0xc) != 0) && (cVar1 = FUN_00596be0(param_1), cVar1 != '\0')) {
    return 1;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x60090001) {
    (**(code **)(*DAT_00b5a988 + 0x30))(CONCAT31(0x600900,(char)param_1[2]));
    return 1;
  }
  return 0;
}


// ==== FUN_00597c20 @ 0x00597c20 ====

void FUN_00597c20(void)

{
  int *piVar1;
  undefined4 uVar2;
  void *pvVar3;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 4))(2,s___Environment_Provider_cpp_009bf5a8,0x25);
  *(undefined4 *)(in_ECX + 4) = uVar2;
  pvVar3 = operator_new(0x98);
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005a8cb0();
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  (**(code **)(*DAT_00b5afac + 4))(*(undefined4 *)(in_ECX + 4),uVar2,1);
  pvVar3 = operator_new(0xdc);
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00593980();
  }
  *(undefined4 *)(in_ECX + 8) = uVar2;
  FUN_005926d0();
  pvVar3 = operator_new(0xf8);
  if (pvVar3 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  uVar2 = FUN_005968c0(*(undefined4 *)(in_ECX + 0x10));
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  return;
}


// ==== FUN_00597cc0 @ 0x00597cc0 ====

void FUN_00597cc0(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    (**(code **)(*DAT_00b5afac + 8))(*(undefined4 *)(in_ECX + 4),1);
    if (*(undefined4 **)(in_ECX + 0x10) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x10))(1);
    }
    *(undefined4 *)(in_ECX + 0x10) = 0;
  }
  if (*(int *)(in_ECX + 4) != -1) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    (**(code **)(*piVar1 + 8))
              (s___Environment_Provider_cpp_009bf5dc,0xa8,2,*(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  }
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  if (*(undefined4 **)(in_ECX + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xc))(1);
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_00597d40 @ 0x00597d40 ====

void FUN_00597d40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf618;
  FUN_00597cc0();
  DAT_00b5afb4 = 0;
  *in_ECX = &PTR_FUN_009bf5fc;
  return;
}


// ==== FUN_00597d60 @ 0x00597d60 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

float10 FUN_00597d60(undefined4 *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  float10 extraout_ST0;
  undefined1 auStack_1018 [4];
  void *pvStack_1014;
  uint uStack_1000;
  undefined4 auStack_ffc [590];
  float fStack_6c4;
  float fStack_6c0;
  float fStack_6bc;
  float fStack_6b8;
  float fStack_6b4;
  float fStack_6b0;
  undefined4 uStack_c;
  
  uStack_c = 0x597d70;
  if (DAT_00b5ac1c != (int *)0x0) {
    uVar1 = (**(code **)(*DAT_00b5ac1c + 0x38))();
    piVar2 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(uVar1);
    if (piVar2 == (int *)0x0) {
      FUN_00401740(s__s__u_009bf5d4,5);
      uVar1 = FUN_00404230(auStack_1018);
      FUN_00796d50(uVar1);
      if (0xf < uStack_1000) {
        _free(pvStack_1014);
        return extraout_ST0;
      }
    }
    else {
      puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
      puVar5 = auStack_ffc;
      for (iVar4 = 0x3fb; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      switch(*param_1) {
      case 3:
        return (float10)fStack_6b4;
      case 4:
        return (float10)fStack_6b8;
      case 6:
      case 8:
        return (float10)fStack_6bc;
      case 7:
        return (float10)fStack_6c4;
      case 9:
        return (float10)fStack_6c0;
      case 0xff:
        return (float10)fStack_6b0;
      }
    }
  }
  return (float10)DAT_0099cdc8;
}


// ==== FUN_00597fd0 @ 0x00597fd0 ====

void FUN_00597fd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf618;
  FUN_00597cc0();
  DAT_00b5afb4 = 0;
  *in_ECX = &PTR_FUN_009bf5fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00598010 @ 0x00598010 ====

void FUN_00598010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf6a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00598030 @ 0x00598030 ====

void FUN_00598030(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf6b4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5afe8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afe8 = in_ECX;
  return;
}


// ==== FUN_00598080 @ 0x00598080 ====

void FUN_00598080(undefined4 *param_1)

{
  code *pcVar1;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(1);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pUnit____NULL_009bf634,0xd);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005980e0 @ 0x005980e0 ====

int FUN_005980e0(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0xf4);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_005a9680(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pUnit____NULL_009bf660,0xd);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_00598160 @ 0x00598160 ====

int FUN_00598160(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x1cc);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_005abb00(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pUnit____NULL_009bf670,0xd);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_005981e0 @ 0x005981e0 ====

int FUN_005981e0(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0xbc);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_005ad0b0(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pUnit____NULL_009bf680,0xd);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_00598260 @ 0x00598260 ====

int FUN_00598260(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x98);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_005ad6b0(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pUnit____NULL_009bf690,0xd);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_005982e0 @ 0x005982e0 ====

int * FUN_005982e0(undefined4 *param_1,int param_2)

{
  code *pcVar1;
  int *extraout_EAX;
  int *piVar2;
  int *extraout_EAX_00;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  switch(*param_1) {
  case 1:
    piVar2 = (int *)FUN_005980e0();
    break;
  default:
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(s_false_009bf644,5);
    FUN_00406880(local_38);
    if (local_20 < 0x10) {
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      piVar2 = (int *)(*pcVar1)();
      return piVar2;
    }
    _free(local_34);
    return extraout_EAX;
  case 6:
    piVar2 = (int *)FUN_00598260();
    break;
  case 7:
    piVar2 = (int *)FUN_00598160();
    break;
  case 0xb:
    piVar2 = (int *)FUN_005981e0();
  }
  if (param_2 != 0) {
    (**(code **)(*piVar2 + 0xc))(*param_1);
    (**(code **)(*piVar2 + 0x24))(param_1,param_2);
    return piVar2;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_i_pParent____NULL_009bf64c,0x11);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    piVar2 = (int *)(*pcVar1)();
    return piVar2;
  }
  _free(local_18);
  return extraout_EAX_00;
}


// ==== FUN_00598410 @ 0x00598410 ====

void FUN_00598410(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5afe8 = 0;
  *in_ECX = &PTR_FUN_009bf6a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00598440 @ 0x00598440 ====

void FUN_00598440(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf6c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00598460 @ 0x00598460 ====

void FUN_00598460(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf6d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00598480 @ 0x00598480 ====

int FUN_00598480(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(in_ECX + 8);
  if (puVar2 != *(undefined4 **)(in_ECX + 0xc)) {
    do {
      iVar1 = (**(code **)(*(int *)*puVar2 + 4))(param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != *(undefined4 **)(in_ECX + 0xc));
  }
  return 0;
}


// ==== FUN_005984b0 @ 0x005984b0 ====

void FUN_005984b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf6f8;
  FUN_004eb890(in_ECX + 1);
  DAT_00b5afec = 0;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009bf6c4;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00598500 @ 0x00598500 ====

void FUN_00598500(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *local_4;
  
  local_4 = operator_new(4);
  if (local_4 == (undefined4 *)0x0) {
    local_4 = (undefined4 *)0x0;
  }
  else {
    *local_4 = &PTR_FUN_009bf6e0;
  }
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2)))
  {
    FUN_00598610(*(undefined4 *)(in_ECX + 0xc),1,&local_4);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xc);
  *puVar2 = local_4;
  *(undefined4 **)(in_ECX + 0xc) = puVar2 + 1;
  return;
}


// ==== FUN_00598570 @ 0x00598570 ====

void FUN_00598570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf6f8;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5afec = (undefined4 *)0x0;
    FUN_00598500();
    return;
  }
  DAT_00b5afec = in_ECX;
  FUN_00598500();
  return;
}


// ==== FUN_005985b0 @ 0x005985b0 ====

void FUN_005985b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf6f8;
  FUN_004eb890(in_ECX + 1);
  DAT_00b5afec = 0;
  if ((void *)in_ECX[2] != (void *)0x0) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_009bf6c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00598610 @ 0x00598610 ====

void FUN_00598610(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_009824d0;
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


// ==== Catch@00598771 @ 0x00598771 ====

void Catch_00598771(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00598860 @ 0x00598860 ====

void FUN_00598860(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf71c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005988f0 @ 0x005988f0 ====

undefined4 FUN_005988f0(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5afb8 + 8))(param_1);
  if (piVar2 != (int *)0x0) {
    iVar1 = *in_ECX;
    uVar3 = (**(code **)(*piVar2 + 4))(piVar2);
    (**(code **)(iVar1 + 4))(uVar3);
  }
  return 1;
}


// ==== FUN_00598920 @ 0x00598920 ====

undefined4 FUN_00598920(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  if ((puVar3 == (undefined4 *)0x0) ||
     (puVar1 = *(undefined4 **)(param_1 + 8), (int)puVar1 - (int)puVar3 >> 2 == 0)) {
    return 0;
  }
  while( true ) {
    if (puVar3 == puVar1) {
      return 0;
    }
    cVar2 = (**(code **)(*(int *)*puVar3 + 0x10))(param_2);
    if (cVar2 != '\0') break;
    puVar3 = puVar3 + 1;
  }
  return 1;
}


// ==== FUN_00598980 @ 0x00598980 ====

undefined4 FUN_00598980(int *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  int *in_ECX;
  
  cVar2 = (**(code **)(*param_1 + 8))();
  if (cVar2 == '\0') {
    uVar5 = (**(code **)(*param_1 + 4))();
    if (((uVar5 == 0x40001) || ((uVar5 & 0xffff0000) == 0x60060000)) || (uVar5 == 0x70004)) {
      cVar2 = FUN_00598920(in_ECX + 5,param_1);
      if (cVar2 != '\0') {
        return 1;
      }
    }
  }
  else {
    iVar1 = *in_ECX;
    uVar3 = (**(code **)(*param_1 + 0x10))();
    piVar4 = (int *)(**(code **)(iVar1 + 0xc))(uVar3);
    if (piVar4 != (int *)0x0) {
      uVar3 = (**(code **)(*piVar4 + 0x10))(param_1);
      return uVar3;
    }
  }
  return 0;
}


// ==== FUN_00598a00 @ 0x00598a00 ====

undefined4 FUN_00598a00(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x2c)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0xc);
}


// ==== FUN_00598a30 @ 0x00598a30 ====

void FUN_00598a30(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009bf738;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 9) = local_5;
  uVar1 = FUN_00598d70();
  in_ECX[0xb] = uVar1;
  in_ECX[0xc] = 0;
  local_4 = in_ECX[0xb];
  FUN_005994b0(9,&local_4);
  in_ECX[0x11] = 1;
  in_ECX[0x12] = 1;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5afbc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afbc = in_ECX;
  return;
}


// ==== FUN_00598ac0 @ 0x00598ac0 ====

void FUN_00598ac0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  int *piVar3;
  undefined1 auStack_4 [4];
  
  *in_ECX = &PTR_FUN_009bf738;
  DAT_00b5afbc = 0;
  piVar1 = (int *)in_ECX[0xb];
  piVar3 = (int *)*piVar1;
  if (piVar3 != piVar1) {
    do {
      if ((undefined4 *)piVar3[3] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar3[3])(1);
      }
      puVar2 = (undefined4 *)FUN_00598f60(auStack_4,piVar3);
      piVar3 = (int *)*puVar2;
    } while (piVar3 != piVar1);
  }
  FUN_005998a0();
  if ((void *)in_ECX[6] != (void *)0x0) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if ((void *)in_ECX[0xe] != (void *)0x0) {
    _free((void *)in_ECX[0xe]);
    return;
  }
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  FUN_008984a0();
  if ((void *)in_ECX[6] != (void *)0x0) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009bf71c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00598b90 @ 0x00598b90 ====

undefined4 FUN_00598b90(int *param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  int *in_ECX;
  undefined1 auStack_2a [2];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar3 = (**(code **)(*in_ECX + 0xc))(param_1);
  piVar2 = param_1;
  if (iVar3 != 0) {
    return 0;
  }
  FUN_00599670(auStack_28,auStack_2a + -6);
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 == 0) {
    FUN_00599620(&param_1);
    return 1;
  }
  FUN_00401830(s_GFALSE_009bf708);
  FUN_00406880(auStack_20);
  if (uStack_8 < 0x10) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    pcVar1 = (code *)swi(3);
    uVar4 = (*pcVar1)();
    return uVar4;
  }
  _free(pvStack_1c);
  return extraout_EAX;
}


// ==== FUN_00598c40 @ 0x00598c40 ====

int * FUN_00598c40(undefined4 param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  int *extraout_EAX;
  undefined4 *puVar5;
  int *in_ECX;
  undefined1 auStack_20 [2];
  undefined1 auStack_1e [2];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  undefined1 auStack_4 [4];
  
  piVar3 = (int *)(**(code **)(*in_ECX + 0xc))(param_1);
  if (piVar3 == (int *)0x0) {
    return (int *)0x0;
  }
  iVar4 = (**(code **)(*piVar3 + 0x30))();
  if (iVar4 != 0) {
    FUN_00401830(s_GFALSE_009bf710);
    FUN_00406880(auStack_20);
    if (uStack_8 < 0x10) {
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      pcVar2 = (code *)swi(3);
      piVar3 = (int *)(*pcVar2)();
      return piVar3;
    }
    _free(pvStack_1c);
    return extraout_EAX;
  }
  puVar1 = (undefined4 *)in_ECX[7];
  puVar5 = (undefined4 *)in_ECX[6];
  if (puVar5 != puVar1) {
    do {
      if ((int *)*puVar5 == piVar3) break;
      puVar5 = puVar5 + 1;
    } while (puVar5 != puVar1);
    if (puVar5 != puVar1) {
      FUN_00598f00(auStack_20 + -4,puVar5);
    }
  }
  (**(code **)(*DAT_00b5afb8 + 0xc))(piVar3);
  FUN_00599960(auStack_4);
  return piVar3;
}


// ==== FUN_00598d00 @ 0x00598d00 ====

int FUN_00598d00(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009824e0;
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


// ==== Catch@00598d66 @ 0x00598d66 ====

void Catch_00598d66(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00598d70 @ 0x00598d70 ====

void FUN_00598d70(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009824f0;
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


// ==== Catch@00598ddf @ 0x00598ddf ====

void Catch_00598ddf(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00598e00 @ 0x00598e00 ====

void * FUN_00598e00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982500;
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


// ==== Catch@00598e6d @ 0x00598e6d ====

void Catch_00598e6d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00598e90 @ 0x00598e90 ====

void FUN_00598e90(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982510;
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


// ==== Catch@00598ef6 @ 0x00598ef6 ====

void Catch_00598ef6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00598f00 @ 0x00598f00 ====

void FUN_00598f00(undefined4 *param_1,void *param_2)

{
  int in_ECX;
  
  _memmove(param_2,(void *)((int)param_2 + 4),(*(int *)(in_ECX + 8) - ((int)param_2 + 4) >> 2) * 4);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -4;
  *param_1 = param_2;
  return;
}


// ==== FUN_00598f40 @ 0x00598f40 ====

void FUN_00598f40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00598d00(param_1,param_2,param_3);
  return;
}


// ==== FUN_00598f60 @ 0x00598f60 ====

void FUN_00598f60(int *param_1,int *param_2)

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
  _free(param_2);
  return;
}


// ==== FUN_00598fe0 @ 0x00598fe0 ====

int FUN_00598fe0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00598e90(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_00599010 @ 0x00599010 ====

void FUN_00599010(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982520;
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
      uVar5 = FUN_00598f40(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00598fe0(uVar5,param_2,&local_18);
      FUN_00598f40(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_00598d00(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00598fe0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_00598d00(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00599171 @ 0x00599171 ====

void Catch_00599171(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00599260 @ 0x00599260 ====

void FUN_00599260(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982530;
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


// ==== Catch@005993c1 @ 0x005993c1 ====

void Catch_005993c1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005994b0 @ 0x005994b0 ====

void FUN_005994b0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982540;
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
    uVar2 = FUN_00598fe0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00599544 @ 0x00599544 ====

void Catch_00599544(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00599560 @ 0x00599560 ====

void FUN_00599560(uint param_1,undefined1 param_2)

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
    FUN_00599010(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_005995d0 @ 0x005995d0 ====

/* WARNING: Removing unreachable block (ram,0x005995eb) */
/* WARNING: Removing unreachable block (ram,0x005995f0) */
/* WARNING: Removing unreachable block (ram,0x005995fe) */

void FUN_005995d0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_00599010(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_00599620 @ 0x00599620 ====

void FUN_00599620(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_00599260(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_00599670 @ 0x00599670 ====

/* WARNING: Removing unreachable block (ram,0x00599758) */

void FUN_00599670(int *param_1,uint *param_2)

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
      FUN_00599560(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_00598e00(puVar7,puVar7[1],param_2);
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


// ==== FUN_005998a0 @ 0x005998a0 ====

void FUN_005998a0(void)

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
    FUN_005995d0(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00599900 @ 0x00599900 ====

void FUN_00599900(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  
  piVar3 = param_3;
  piVar2 = param_2;
  if ((param_2 == (int *)**(int **)(in_ECX + 8)) && (param_3 == *(int **)(in_ECX + 8))) {
    FUN_005998a0();
    *param_1 = **(undefined4 **)(in_ECX + 8);
    return;
  }
  while (piVar2 != piVar3) {
    piVar1 = (int *)*piVar2;
    FUN_00598f60(&param_2,piVar2);
    piVar2 = piVar1;
  }
  *param_1 = piVar2;
  return;
}


// ==== FUN_00599960 @ 0x00599960 ====

int FUN_00599960(undefined4 param_1)

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
  FUN_00599900(&param_1,local_8,local_4);
  return iVar2;
}


// ==== FUN_005999b0 @ 0x005999b0 ====

void FUN_005999b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00598ac0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005999d0 @ 0x005999d0 ====

void FUN_005999d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf790;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005999f0 @ 0x005999f0 ====

void FUN_005999f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf7a0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5afc0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afc0 = in_ECX;
  return;
}


// ==== FUN_00599a20 @ 0x00599a20 ====

bool FUN_00599a20(int *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)(**(code **)(*DAT_00b5af48 + 8))();
  if (((*pcVar2 == '\0') && (iVar3 = (**(code **)(*param_1 + 4))(), iVar3 == 0x60060031)) &&
     (*(char *)((int)param_1 + 0xf) == '\x01')) {
    return true;
  }
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == 0x2001ffff) {
    (**(code **)(*DAT_00b5afbc + 8))(param_1[1]);
    return true;
  }
  if (iVar3 == 0x60020001) {
    (**(code **)(*DAT_00b5afbc + 0x10))(param_1);
    return true;
  }
  cVar1 = (**(code **)(*DAT_00b5afbc + 0x14))();
  return cVar1 != '\0';
}


// ==== FUN_00599ab0 @ 0x00599ab0 ====

void FUN_00599ab0(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined4 uStack_1c;
  uint uStack_8;
  
  cVar1 = (**(code **)(*in_ECX + 4))(param_1);
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 4))();
    FUN_00401740(s_>>>>>>>>>>>>>>>>>>>>>>>>_Unhandl_009bf754,0x35);
    uVar2 = FUN_00404230((int)register0x00000010 + -0x20);
    FUN_00796d50(uVar2);
    if (0xf < uStack_8) {
      _free(uStack_1c);
      return;
    }
  }
  if (param_1 != (int *)0x0) {
    (**(code **)*param_1)(1);
  }
  return;
}


// ==== FUN_00599b30 @ 0x00599b30 ====

void FUN_00599b30(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5afc0 = 0;
  *in_ECX = &PTR_FUN_009bf790;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00599b60 @ 0x00599b60 ====

void FUN_00599b60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf7f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00599b80 @ 0x00599b80 ====

undefined4 FUN_00599b80(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4 + param_1 * 4);
}


// ==== FUN_00599ba0 @ 0x00599ba0 ====

undefined4 FUN_00599ba0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00599bb0 @ 0x00599bb0 ====

void FUN_00599bb0(void)

{
  FUN_004bdca0();
  return;
}


// ==== FUN_00599bc0 @ 0x00599bc0 ====

undefined4 FUN_00599bc0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00599bf0 @ 0x00599bf0 ====

int * FUN_00599bf0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  uVar2 = (**(code **)(*param_1 + 0x10))();
  piVar3 = (int *)(**(code **)(iVar1 + 0x10))(uVar2);
  piVar3 = (int *)(**(code **)(*piVar3 + 8))(param_1);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))();
  }
  return piVar3;
}


// ==== FUN_00599c30 @ 0x00599c30 ====

void FUN_00599c30(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x30))();
  piVar2 = (int *)(**(code **)(*in_ECX + 0x10))((iVar1 != 0) + '\x01');
  (**(code **)(*param_1 + 0xc))();
  (**(code **)(*piVar2 + 0xc))(param_1);
  return;
}


// ==== FUN_00599c70 @ 0x00599c70 ====

void FUN_00599c70(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  void *_Memory;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  undefined4 uStack_18;
  float fStack_14;
  undefined1 local_10 [4];
  void *local_c;
  int local_8;
  int local_4;
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 4) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
  }
  iVar3 = (int)(iVar3 - param_2) / 2;
  local_c = (void *)0x0;
  local_8 = 0;
  local_4 = 0;
  param_1 = 0;
  if (0 < iVar3) {
    iVar6 = param_2 * 0x1c;
    do {
      iVar1 = *(int *)(iVar2 + 4);
      if ((iVar1 == 0) || ((uint)((*(int *)(iVar2 + 8) - iVar1) / 0x1c) <= param_2)) {
LAB_00599e04:
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar4 = thunk_FUN_00796e60(iVar6 + iVar1);
      iVar1 = *(int *)(iVar2 + 4);
      iVar5 = iVar6 + 0x1c;
      if ((iVar1 == 0) || ((uint)((*(int *)(iVar2 + 8) - iVar1) / 0x1c) <= param_2 + 1))
      goto LAB_00599e04;
      param_2 = param_2 + 2;
      iVar6 = iVar6 + 0x38;
      uStack_18 = uVar4;
      fVar7 = (float10)thunk_FUN_00796ec0(iVar5 + iVar1);
      iVar1 = local_8;
      fStack_14 = (float)fVar7;
      if ((local_c == (void *)0x0) ||
         ((uint)(local_4 - (int)local_c >> 3) <= (uint)(local_8 - (int)local_c >> 3))) {
        FUN_004b9740(local_8,1,&uStack_18);
      }
      else {
        FUN_00429bc0(local_8,1,&uStack_18,local_10,param_1);
        local_8 = iVar1 + 8;
      }
      param_1 = param_1 + 1;
    } while (param_1 < iVar3);
  }
  _Memory = local_c;
  FUN_004b9a80(0,1000,local_10);
  if (_Memory == (void *)0x0) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00599e10 @ 0x00599e10 ====

void FUN_00599e10(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  float10 fVar6;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_Effect_damageeffect_csv_009bf7d8,0x17);
  iVar3 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  iVar1 = *(int *)(iVar3 + 0x44);
  iVar2 = *(int *)(iVar3 + 0x40);
  iVar5 = 1;
  while( true ) {
    iVar2 = iVar2 + 0x1c;
    if (iVar2 == iVar1) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar3);
      return;
    }
    local_18 = (void *)0x0;
    local_14 = 0;
    local_10 = 0;
    FUN_00404fb0(iVar2,0x2c,local_1c);
    if (iVar5 == 1) {
      FUN_00599c70(local_1c,1,*(int *)(in_ECX + 0x10) + 0xc);
    }
    else if (iVar5 == 2) {
      FUN_00599c70(local_1c,1,*(int *)(in_ECX + 0x10) + 0x54);
    }
    else if (iVar5 == 3) {
      FUN_00599c70(local_1c,1,*(int *)(in_ECX + 0x10) + 0x24);
    }
    else if (iVar5 == 4) {
      FUN_00599c70(local_1c,1,*(int *)(in_ECX + 0x10) + 0x3c);
    }
    else if (iVar5 == 5) {
      uVar4 = FUN_00405d30(1);
      uVar4 = thunk_FUN_00796fb0(uVar4);
      **(undefined4 **)(in_ECX + 0x10) = uVar4;
    }
    else if (iVar5 == 6) {
      uVar4 = FUN_00405d30(1);
      uVar4 = thunk_FUN_00796fb0(uVar4);
      *(undefined4 *)(*(int *)(in_ECX + 0x10) + 4) = uVar4;
    }
    else if (iVar5 == 7) {
      uVar4 = FUN_00405d30(1);
      fVar6 = (float10)thunk_FUN_00796ec0(uVar4);
      *(float *)(*(int *)(in_ECX + 0x10) + 8) = (float)fVar6;
    }
    if (local_18 != (void *)0x0) break;
    iVar5 = iVar5 + 1;
    local_18 = (void *)0x0;
    local_14 = 0;
    local_10 = 0;
  }
  FUN_00405de0(local_18,local_14,local_1c,iVar3);
  _free(local_18);
  return;
}


// ==== FUN_00599fe0 @ 0x00599fe0 ====

void FUN_00599fe0(void)

{
  int *piVar1;
  void *local_3c;
  undefined1 local_38;
  uint local_28;
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c;
  undefined4 uStack_10;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_24 = 0xf;
  local_28 = 0;
  local_38 = 0;
  FUN_00401740(s_Effect_damageeffect_csv_009bf7c0,0x17);
  piVar1 = DAT_00b5a7cc;
  local_8 = 0xf;
  local_c = 0;
  local_1c = 0;
  FUN_00401660(&local_3c,0,0xffffffff);
  local_4 = 0x12;
  (**(code **)(*piVar1 + 0x28))(&local_20);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  uStack_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  if (local_28 < 0x10) {
    FUN_00599e10();
    return;
  }
  _free(local_3c);
  return;
}


// ==== FUN_0059a090 @ 0x0059a090 ====

void FUN_0059a090(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009bf81c;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_split_mesh_lua_009bf7b0,0xe);
  uVar1 = FUN_0059a1e0(local_1c);
  in_ECX[3] = uVar1;
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_005adc20();
  }
  if (in_ECX[2] == 0) {
    in_ECX[2] = uVar1;
  }
  pvVar2 = operator_new(0x6c);
  if (pvVar2 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0059a2f0();
  }
  in_ECX[4] = uVar1;
  FUN_00599e10();
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5afb8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afb8 = in_ECX;
  return;
}


// ==== FUN_0059a160 @ 0x0059a160 ====

void FUN_0059a160(void)

{
  void *_Memory;
  int *in_ECX;
  int iVar1;
  int *piVar2;
  
  *in_ECX = (int)&PTR_FUN_009bf81c;
  DAT_00b5afb8 = 0;
  iVar1 = 2;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    *piVar2 = 0;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  _Memory = (void *)in_ECX[4];
  if (_Memory != (void *)0x0) {
    FUN_0059a240();
    _free(_Memory);
    return;
  }
  in_ECX[4] = 0;
  if (in_ECX[3] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[3]);
    in_ECX[3] = 0;
  }
  *in_ECX = (int)&PTR_FUN_009bf7f4;
  return;
}


// ==== FUN_0059a1e0 @ 0x0059a1e0 ====

undefined4 FUN_0059a1e0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *local_20;
  undefined1 local_1c;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = DAT_00b5a7cc;
  local_c = 0;
  local_1c = 0;
  local_8 = 0xf;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0x13;
  uVar2 = (**(code **)(*piVar1 + 8))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_0059a240 @ 0x0059a240 ====

void FUN_0059a240(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004b9680(local_4,**(undefined4 **)(in_ECX + 0x58),*(undefined4 **)(in_ECX + 0x58));
  _free(*(void **)(in_ECX + 0x58));
  return;
}


// ==== FUN_0059a2f0 @ 0x0059a2f0 ====

void FUN_0059a2f0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0058b910();
  *(int *)(in_ECX + 0x10) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(in_ECX + 0x10) + 4) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x10);
  *(int *)(*(int *)(in_ECX + 0x10) + 8) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  iVar1 = FUN_0058b910();
  *(int *)(in_ECX + 0x28) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(in_ECX + 0x28) + 4) = *(int *)(in_ECX + 0x28);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(in_ECX + 0x28);
  *(int *)(*(int *)(in_ECX + 0x28) + 8) = *(int *)(in_ECX + 0x28);
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  iVar1 = FUN_0058b910();
  *(int *)(in_ECX + 0x40) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(in_ECX + 0x40) + 4) = *(int *)(in_ECX + 0x40);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(in_ECX + 0x40);
  *(int *)(*(int *)(in_ECX + 0x40) + 8) = *(int *)(in_ECX + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = 0;
  iVar1 = FUN_0058b910();
  *(int *)(in_ECX + 0x58) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(in_ECX + 0x58) + 4) = *(int *)(in_ECX + 0x58);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(in_ECX + 0x58);
  *(int *)(*(int *)(in_ECX + 0x58) + 8) = *(int *)(in_ECX + 0x58);
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  return;
}


// ==== FUN_0059a3a0 @ 0x0059a3a0 ====

void FUN_0059a3a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0059a160();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059a3c0 @ 0x0059a3c0 ====

void FUN_0059a3c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf844;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059a3e0 @ 0x0059a3e0 ====

void FUN_0059a3e0(void)

{
  return;
}


// ==== FUN_0059a3f0 @ 0x0059a3f0 ====

undefined4 FUN_0059a3f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_14 [8];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar1 = param_1;
  FUN_0059a7a0(&param_1,param_1);
  if (param_1 != *(undefined4 **)(in_ECX + 8)) {
    return param_1[5];
  }
  pvVar2 = operator_new(0x78);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005ae020(puVar1);
  }
  local_c = *puVar1;
  local_8 = puVar1[1];
  local_4 = uVar3;
  FUN_0059a9e0(local_14,&local_c);
  return uVar3;
}


// ==== FUN_0059a470 @ 0x0059a470 ====

void FUN_0059a470(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009bf854;
  local_4 = in_ECX;
  if (in_ECX[3] != 0) {
    local_4 = (undefined4 *)((uint)in_ECX & 0xffffff00);
    FUN_0059a730(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2],local_4);
    FUN_0059a6f0(*(undefined4 *)(in_ECX[2] + 4));
    *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
    in_ECX[3] = 0;
    *(undefined4 *)in_ECX[2] = in_ECX[2];
    *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  }
  DAT_00b5aff0 = 0;
  FUN_0059aab0(&local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0059a500 @ 0x0059a500 ====

void FUN_0059a500(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf854;
  iVar1 = FUN_0059a650();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aff0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aff0 = in_ECX;
  return;
}


// ==== FUN_0059a550 @ 0x0059a550 ====

int FUN_0059a550(int *param_1)

{
  int iVar1;
  uint3 uVar2;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if ((iVar1 < *param_1) ||
     ((iVar1 <= *param_1 && (*(ushort *)(in_ECX + 1) < *(ushort *)(param_1 + 1))))) {
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}


// ==== FUN_0059a580 @ 0x0059a580 ====

undefined4 * FUN_0059a580(int *param_1)

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
         (((int)puVar2[3] <= *param_1 && (*(ushort *)(puVar2 + 4) < *(ushort *)(param_1 + 1))))) {
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


// ==== FUN_0059a5c0 @ 0x0059a5c0 ====

void * FUN_0059a5c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982550;
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


// ==== Catch@0059a635 @ 0x0059a635 ====

void Catch_0059a635(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0059a650 @ 0x0059a650 ====

void FUN_0059a650(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982560;
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


// ==== Catch@0059a6da @ 0x0059a6da ====

void Catch_0059a6da(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0059a6f0 @ 0x0059a6f0 ====

void FUN_0059a6f0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    FUN_0059a6f0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0059a730 @ 0x0059a730 ====

undefined1 FUN_0059a730(int *param_1,int *param_2,undefined1 param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  while (param_1 != param_2) {
    if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[5])(1);
    }
    if (*(char *)((int)param_1 + 0x19) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x19) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x19);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x19);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x19);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  return param_3;
}


// ==== FUN_0059a7a0 @ 0x0059a7a0 ====

void FUN_0059a7a0(int *param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0059a580(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if ((*(int *)(iVar1 + 0xc) <= *param_2) &&
       ((*(int *)(iVar1 + 0xc) < *param_2 || (*(ushort *)(iVar1 + 0x10) <= *(ushort *)(param_2 + 1))
        ))) {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_0059a800 @ 0x0059a800 ====

void FUN_0059a800(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_0059a5c0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_0059a905:
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
      if ((char)piVar6[6] == '\0') goto LAB_0059a905;
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


// ==== FUN_0059a9e0 @ 0x0059a9e0 ====

void FUN_0059a9e0(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int in_ECX;
  
  piVar1 = param_2;
  puVar3 = *(undefined4 **)(in_ECX + 4);
  cVar4 = '\x01';
  if (*(char *)((int)puVar3[1] + 0x19) == '\0') {
    puVar2 = (undefined4 *)puVar3[1];
    do {
      puVar3 = puVar2;
      if (*param_2 < (int)puVar3[3]) {
        cVar4 = '\x01';
      }
      else if (((int)puVar3[3] < *param_2) || (*(ushort *)(puVar3 + 4) <= *(ushort *)(param_2 + 1)))
      {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      if (cVar4 == '\0') {
        puVar2 = (undefined4 *)puVar3[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar3;
      }
    } while (*(char *)((int)puVar2 + 0x19) == '\0');
  }
  param_2 = puVar3;
  if (cVar4 != '\0') {
    if (puVar3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      cVar4 = '\x01';
      goto LAB_0059aa51;
    }
    FUN_004b83a0();
  }
  if ((*piVar1 <= param_2[3]) &&
     ((*piVar1 < param_2[3] || (*(ushort *)(piVar1 + 1) <= *(ushort *)(param_2 + 4))))) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_0059aa51:
  puVar3 = (undefined4 *)FUN_0059a800(&param_2,cVar4,puVar3,piVar1);
  *param_1 = *puVar3;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_0059aab0 @ 0x0059aab0 ====

void FUN_0059aab0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0059a6f0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x19) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x19) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x19);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x19);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x19);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00850bf0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0059ab70 @ 0x0059ab70 ====

void FUN_0059ab70(byte param_1)

{
  void *in_ECX;
  
  FUN_0059a470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059ab90 @ 0x0059ab90 ====

void FUN_0059ab90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf894;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059abb0 @ 0x0059abb0 ====

void FUN_0059abb0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x5d);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x5d);
  }
  return;
}


// ==== FUN_0059abd0 @ 0x0059abd0 ====

void FUN_0059abd0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x5d) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x5d) == '\0');
  }
  return;
}


// ==== FUN_0059abf0 @ 0x0059abf0 ====

undefined4 * FUN_0059abf0(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x5d) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if (((uint)puVar2[3] < *param_1) ||
         (((uint)puVar2[3] <= *param_1 && ((uint)puVar2[4] < param_1[1])))) {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x5d) == '\0');
  }
  return puVar2;
}


// ==== FUN_0059ac30 @ 0x0059ac30 ====

void FUN_0059ac30(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x5d) == '\0') {
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


// ==== FUN_0059ac80 @ 0x0059ac80 ====

void FUN_0059ac80(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x5d) == '\0') {
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


// ==== FUN_0059ace0 @ 0x0059ace0 ====

void FUN_0059ace0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x5d) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x5d) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x5d);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x5d);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x5d);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x5d);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_0059ad30 @ 0x0059ad30 ====

void FUN_0059ad30(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x5d) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x5d) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x5d);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x5d);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x5d) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x5d) == '\0');
    if (*(char *)((int)piVar4 + 0x5d) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0059ad90 @ 0x0059ad90 ====

void FUN_0059ad90(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982570;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x60);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x17) = 1;
  *(undefined1 *)((int)puVar1 + 0x5d) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0059ae1a @ 0x0059ae1a ====

void Catch_0059ae1a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0059ae30 @ 0x0059ae30 ====

void FUN_0059ae30(int *param_1,uint *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0059abf0(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if ((*(uint *)(iVar1 + 0xc) <= *param_2) &&
       ((*(uint *)(iVar1 + 0xc) < *param_2 || (*(uint *)(iVar1 + 0x10) <= param_2[1])))) {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_0059ae90 @ 0x0059ae90 ====

void FUN_0059ae90(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0059ae30(&param_1,param_1);
  iVar1 = param_1;
  if ((((param_1 != *(int *)(in_ECX + 0x18)) && (*(int *)(param_1 + 0x34) != 0)) &&
      (*(int *)(param_1 + 0x14) != 0)) &&
     (iVar2 = *(int *)(param_1 + 0x14) + -1, *(int *)(param_1 + 0x14) = iVar2, iVar2 == 0)) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(param_1 + 0x34));
    *(undefined4 *)(iVar1 + 0x34) = 0;
  }
  return;
}


// ==== FUN_0059aee0 @ 0x0059aee0 ====

void FUN_0059aee0(undefined4 *param_1,int param_2)

{
  int in_ECX;
  
  FUN_0059ae30(&param_2,param_2);
  if (param_2 == *(int *)(in_ECX + 0x18)) {
    *param_1 = *(undefined4 *)(in_ECX + 4);
    param_1[1] = *(undefined4 *)(in_ECX + 8);
    param_1[2] = *(undefined4 *)(in_ECX + 0xc);
    param_1[3] = *(undefined4 *)(in_ECX + 0x10);
    return;
  }
  *param_1 = *(undefined4 *)(param_2 + 0x38);
  param_1[1] = *(undefined4 *)(param_2 + 0x3c);
  param_1[2] = *(undefined4 *)(param_2 + 0x40);
  param_1[3] = *(undefined4 *)(param_2 + 0x44);
  return;
}


// ==== FUN_0059af50 @ 0x0059af50 ====

int FUN_0059af50(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_0059ae30(&param_1,param_1);
  iVar1 = param_1;
  if (param_1 == *(int *)(in_ECX + 0x18)) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x14) == 0) && (*(int *)(param_1 + 0x34) == 0)) {
    uVar2 = FUN_004b4e70(param_1 + 0x18);
    *(undefined4 *)(iVar1 + 0x34) = uVar2;
  }
  *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
  return iVar1 + 0x34;
}


// ==== FUN_0059afa0 @ 0x0059afa0 ====

void FUN_0059afa0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  undefined1 auStack_2cc [4];
  void *local_2c8;
  undefined4 uStack_2b8;
  uint uStack_2b4;
  int aiStack_2b0 [4];
  int iStack_2a0;
  undefined1 uStack_29c;
  int iStack_298;
  int iStack_294;
  int iStack_290;
  int iStack_28c;
  void *pvStack_288;
  undefined1 uStack_284;
  undefined4 uStack_278;
  uint uStack_274;
  undefined4 uStack_270;
  undefined4 auStack_26c [4];
  void *pvStack_25c;
  undefined4 uStack_24c;
  uint uStack_248;
  int aiStack_244 [10];
  undefined1 auStack_21c [20];
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  local_208[0] = '\0';
  FUN_0044a580(local_100,&DAT_009bf88c,s_Image_009bf884);
  uVar2 = 0;
  do {
    local_208[uVar2] = local_100[uVar2];
    if (local_100[uVar2] == '\0') goto LAB_0059aff4;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_208[0] = '\0';
LAB_0059aff4:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  uVar2 = 0;
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (iVar4 == 0) {
LAB_0059b2e8:
    (**(code **)(*DAT_00b5aa34 + 0xc))(piVar3);
    return;
  }
  do {
    pcVar5 = (char *)(**(code **)(*piVar3 + 0x10))(uVar2,0);
    FUN_0044a580(local_208 + 0xfc,&DAT_009bf88c,&DAT_009bf88a);
    uVar9 = 0;
    pcVar6 = pcVar5;
    while (*pcVar6 == pcVar6[(int)(local_208 + (0xfc - (int)pcVar5))]) {
      if (*pcVar6 == '\0') goto LAB_0059b2d3;
      uVar9 = uVar9 + 1;
      pcVar6 = pcVar6 + 1;
      if (0xff < uVar9) goto LAB_0059b2d3;
    }
    uStack_2b4 = 0xf;
    uStack_270 = 0xf;
    uStack_2b8 = 0;
    local_2c8 = (void *)((uint)local_2c8 & 0xffffff00);
    uStack_274 = 0;
    uStack_284 = 0;
    pcVar6 = pcVar5;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(pcVar5,(int)pcVar6 - (int)(pcVar5 + 1));
    (**(code **)(*DAT_00b5a7c0 + 4))(&pvStack_288);
    if (0xf < uStack_274) {
      _free(pvStack_288);
      return;
    }
    uStack_274 = 0xf;
    uStack_278 = 0;
    pvStack_288 = (void *)((uint)pvStack_288 & 0xffffff00);
    uVar7 = FUN_004756e0(uVar2,1);
    pcVar5 = (char *)(**(code **)(*piVar3 + 0x10))(uVar2,2);
    pcVar6 = pcVar5;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(pcVar5,(int)pcVar6 - (int)(pcVar5 + 1));
    aiStack_2b0[1] = FUN_00477a70(uVar2,3);
    aiStack_2b0[2] = FUN_00477a70(uVar2,4);
    aiStack_2b0[3] = FUN_00477a70(uVar2,5);
    iStack_2a0 = FUN_00477a70(uVar2,6);
    iStack_2a0 = iStack_2a0 + aiStack_2b0[2];
    aiStack_2b0[3] = aiStack_2b0[3] + aiStack_2b0[1];
    iStack_298 = FUN_00477a70(uVar2,7);
    iStack_294 = FUN_00477a70(uVar2,8);
    iStack_290 = FUN_00477a70(uVar2,9);
    iStack_28c = FUN_00477a70(uVar2,10);
    aiStack_2b0[0] = 0;
    if ((((iStack_298 != 0) || (iStack_294 != 0)) || (iStack_290 != 0)) ||
       (uStack_29c = 0, iStack_28c != 0)) {
      uStack_29c = 1;
    }
    uStack_24c = 0;
    uStack_248 = 0xf;
    pvStack_25c = (void *)((uint)pvStack_25c & 0xffffff00);
    auStack_26c[0] = uVar7;
    FUN_00401660(auStack_2cc,0,0xffffffff);
    piVar8 = aiStack_2b0;
    piVar10 = aiStack_244;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar10 = *piVar8;
      piVar8 = piVar8 + 1;
      piVar10 = piVar10 + 1;
    }
    FUN_0059bab0(auStack_21c,auStack_26c);
    if (0xf < uStack_248) {
      _free(pvStack_25c);
      return;
    }
    uStack_248 = 0xf;
    uStack_24c = 0;
    pvStack_25c = (void *)((uint)pvStack_25c & 0xffffff00);
    if (0xf < uStack_2b4) {
      _free(local_2c8);
      return;
    }
    uStack_2b4 = 0xf;
    uStack_2b8 = 0;
    local_2c8 = (void *)((uint)local_2c8 & 0xffffff00);
LAB_0059b2d3:
    uVar2 = uVar2 + 1;
    uVar9 = (**(code **)(*piVar3 + 8))();
    if (uVar9 <= uVar2) goto LAB_0059b2e8;
  } while( true );
}


// ==== FUN_0059b300 @ 0x0059b300 ====

void FUN_0059b300(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009bf8ac;
  DAT_00b5a7c4 = 0;
  puVar2 = (undefined4 *)in_ECX[6];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (puVar3[0xd] != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(puVar3[0xd]);
      puVar3[0xd] = 0;
    }
    if (*(char *)((int)puVar3 + 0x5d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x5d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x5d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x5d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x5d);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x5d);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  FUN_0059bb80(local_4,*(undefined4 *)in_ECX[6],(undefined4 *)in_ECX[6]);
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_0059b3b0 @ 0x0059b3b0 ====

void FUN_0059b3b0(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009bf8ac;
  iVar1 = FUN_0059ad90();
  in_ECX[6] = iVar1;
  *(undefined1 *)(iVar1 + 0x5d) = 1;
  *(undefined4 *)(in_ECX[6] + 4) = in_ECX[6];
  *(undefined4 *)in_ECX[6] = in_ECX[6];
  *(undefined4 *)(in_ECX[6] + 8) = in_ECX[6];
  in_ECX[7] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a7c4 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a7c4 = in_ECX;
  }
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_Script_UI_Com_ImageTable_txt_009bf864,0x1c);
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0081db30(local_1c);
  }
  FUN_0059afa0(puVar3);
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0059b480 @ 0x0059b480 ====

void FUN_0059b480(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  in_ECX[4] = param_4[1];
  in_ECX[5] = param_4[2];
  in_ECX[0xc] = 0xf;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  FUN_00401660(param_4 + 3,0,0xffffffff);
  puVar2 = param_4 + 10;
  puVar3 = in_ECX + 0xd;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)(in_ECX + 0x17) = param_5;
  *(undefined1 *)((int)in_ECX + 0x5d) = 0;
  return;
}


// ==== FUN_0059b500 @ 0x0059b500 ====

void * FUN_0059b500(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982580;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x60);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0059b480(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0059b575 @ 0x0059b575 ====

void Catch_0059b575(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0059b590 @ 0x0059b590 ====

/* WARNING: Removing unreachable block (ram,0x0059b6a9) */
/* WARNING: Removing unreachable block (ram,0x0059b6ba) */
/* WARNING: Removing unreachable block (ram,0x0059b6c3) */
/* WARNING: Removing unreachable block (ram,0x0059b6c6) */
/* WARNING: Removing unreachable block (ram,0x0059b6b6) */
/* WARNING: Removing unreachable block (ram,0x0059b6d4) */
/* WARNING: Removing unreachable block (ram,0x0059b6e1) */
/* WARNING: Removing unreachable block (ram,0x0059b6ec) */
/* WARNING: Removing unreachable block (ram,0x0059b6e8) */
/* WARNING: Removing unreachable block (ram,0x0059b6dc) */
/* WARNING: Removing unreachable block (ram,0x0059b6ef) */

void FUN_0059b590(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x5d) != '\0') {
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
  FUN_0059ace0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x5d) == '\0') {
    if (*(char *)(param_2[2] + 0x5d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x5d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x5d) == '\0') {
      piVar3 = (int *)FUN_0059abb0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x5d) == '\0') {
      uVar4 = FUN_0059abd0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x17] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x17] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x17] == '\0') {
            *(undefined1 *)(piVar5 + 0x17) = 1;
            *(undefined1 *)(piVar3 + 0x17) = 0;
            FUN_0059ac30(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x5d) == '\0') {
            if ((*(char *)(*piVar5 + 0x5c) == '\x01') && (*(char *)(piVar5[2] + 0x5c) == '\x01'))
            goto LAB_0059b7c4;
            if (*(char *)(piVar5[2] + 0x5c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x5c) = 1;
              *(undefined1 *)(piVar5 + 0x17) = 0;
              FUN_0059ac80(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x17) = (char)piVar3[0x17];
            *(undefined1 *)(piVar3 + 0x17) = 1;
            *(undefined1 *)(piVar5[2] + 0x5c) = 1;
            FUN_0059ac30(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x17] == '\0') {
            *(undefined1 *)(piVar5 + 0x17) = 1;
            *(undefined1 *)(piVar3 + 0x17) = 0;
            FUN_0059ac80(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x5d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x5c) != '\x01') || (*(char *)(*piVar5 + 0x5c) != '\x01')) {
              if (*(char *)(*piVar5 + 0x5c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x5c) = 1;
                *(undefined1 *)(piVar5 + 0x17) = 0;
                FUN_0059ac30(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x17) = (char)piVar3[0x17];
              *(undefined1 *)(piVar3 + 0x17) = 1;
              *(undefined1 *)(*piVar5 + 0x5c) = 1;
              FUN_0059ac80(piVar3);
              break;
            }
LAB_0059b7c4:
            *(undefined1 *)(piVar5 + 0x17) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x17) = 1;
  }
  if ((uint)param_2[0xc] < 0x10) {
    param_2[0xc] = 0xf;
    param_2[0xb] = 0;
    *(undefined1 *)(param_2 + 7) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[7]);
  return;
}


// ==== FUN_0059b870 @ 0x0059b870 ====

void FUN_0059b870(void *param_1)

{
  if (*(char *)((int)param_1 + 0x5d) != '\0') {
    return;
  }
  FUN_0059b870(*(undefined4 *)((int)param_1 + 8));
  if (*(uint *)((int)param_1 + 0x30) < 0x10) {
    *(undefined4 *)((int)param_1 + 0x30) = 0xf;
    *(undefined4 *)((int)param_1 + 0x2c) = 0;
    *(undefined1 *)((int)param_1 + 0x1c) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x1c));
  return;
}


// ==== FUN_0059b8d0 @ 0x0059b8d0 ====

void FUN_0059b8d0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x3333331 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0059b500(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x5c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x5c) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x17] == '\0') {
LAB_0059b9d5:
        *(undefined1 *)(*piVar5 + 0x5c) = 1;
        *(undefined1 *)(piVar6 + 0x17) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x5c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0059ac30(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x5c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x5c) = 0;
        FUN_0059ac80(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x17] == '\0') goto LAB_0059b9d5;
      if (piVar7 == (int *)*piVar2) {
        FUN_0059ac80(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x5c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x5c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x5d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x5c);
  } while( true );
}


// ==== FUN_0059bab0 @ 0x0059bab0 ====

void FUN_0059bab0(undefined4 *param_1,uint *param_2)

{
  bool bVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_4;
  
  puVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar1 = true;
  local_4 = 1;
  if (*(char *)((int)puVar4[1] + 0x5d) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if ((*param_2 < (uint)puVar4[3]) ||
         ((*param_2 <= (uint)puVar4[3] && (param_2[1] < (uint)puVar4[4])))) {
        puVar3 = (undefined4 *)*puVar4;
        bVar1 = true;
        local_4 = 1;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
        bVar1 = false;
        local_4 = 0;
      }
    } while (*(char *)((int)puVar3 + 0x5d) == '\0');
  }
  param_2 = puVar4;
  if (bVar1) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      local_4 = 1;
      goto LAB_0059bb05;
    }
    FUN_0059ad30();
  }
  if ((*puVar2 <= param_2[3]) && ((*puVar2 < param_2[3] || (puVar2[1] <= param_2[4])))) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_0059bb05:
  puVar4 = (undefined4 *)FUN_0059b8d0(&param_2,local_4,puVar4,puVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_0059bb80 @ 0x0059bb80 ====

void FUN_0059bb80(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0059b870(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x5d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x5d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x5d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x5d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x5d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x5d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0059b590(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0059bc40 @ 0x0059bc40 ====

void FUN_0059bc40(byte param_1)

{
  void *in_ECX;
  
  FUN_0059b300();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059bc60 @ 0x0059bc60 ====

void FUN_0059bc60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf8c8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059bc80 @ 0x0059bc80 ====

int FUN_0059bc80(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982590;
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


// ==== Catch@0059bce6 @ 0x0059bce6 ====

void Catch_0059bce6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0059bcf0 @ 0x0059bcf0 ====

void FUN_0059bcf0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009825a0;
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


// ==== Catch@0059bd5f @ 0x0059bd5f ====

void Catch_0059bd5f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0059bd80 @ 0x0059bd80 ====

void FUN_0059bd80(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009825b0;
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


// ==== Catch@0059bde6 @ 0x0059bde6 ====

void Catch_0059bde6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0059bdf0 @ 0x0059bdf0 ====

void FUN_0059bdf0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0059bc80(param_1,param_2,param_3);
  return;
}


// ==== FUN_0059be10 @ 0x0059be10 ====

int FUN_0059be10(int param_1,int param_2,undefined4 param_3)

{
  FUN_0059bd80(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_0059be40 @ 0x0059be40 ====

undefined4 FUN_0059be40(int param_1)

{
  int in_ECX;
  
  FUN_0041ec50(&param_1,param_1);
  if (param_1 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x24);
}


// ==== FUN_0059be70 @ 0x0059be70 ====

void FUN_0059be70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf8d8;
  DAT_00b5a7c0 = 0;
  if ((void *)in_ECX[6] == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    FUN_0059c2f0();
    _free((void *)in_ECX[3]);
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_0059bec0 @ 0x0059bec0 ====

int FUN_0059bec0(int param_1)

{
  int iVar1;
  int extraout_EAX;
  int in_ECX;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  FUN_0041ec50(&param_1,param_1);
  if (param_1 != *(int *)(in_ECX + 0xc)) {
    return *(int *)(param_1 + 0x24);
  }
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  local_4 = *(undefined4 *)(in_ECX + 0x2c);
  FUN_0059c500(local_28,local_20);
  if (local_8 < 0x10) {
    iVar1 = *(int *)(in_ECX + 0x2c);
    *(int *)(in_ECX + 0x2c) = iVar1 + 1;
    return iVar1;
  }
  _free(local_1c);
  return extraout_EAX;
}


// ==== FUN_0059bf50 @ 0x0059bf50 ====

void FUN_0059bf50(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_21;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009bf8d8;
  *(undefined1 *)(in_ECX + 1) = local_21;
  uVar1 = FUN_0059bcf0();
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  local_20 = in_ECX[3];
  FUN_0059c3e0(9,&local_20);
  in_ECX[9] = 1;
  in_ECX[10] = 1;
  in_ECX[0xb] = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_009bf8c2,0);
  FUN_0059bec0(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a7c0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a7c0 = in_ECX;
  return;
}


// ==== FUN_0059c010 @ 0x0059c010 ====

void FUN_0059c010(uint param_1)

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
  
  if (0x7ffffffU - *(int *)(in_ECX + 8) < param_1) {
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


// ==== FUN_0059c0a0 @ 0x0059c0a0 ====

void FUN_0059c0a0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_009825c0;
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
      uVar5 = FUN_0059bdf0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_0059be10(uVar5,param_2,&local_18);
      FUN_0059bdf0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_0059bc80(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_0059be10(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_0059bc80(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0059c201 @ 0x0059c201 ====

void Catch_0059c201(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0059c2f0 @ 0x0059c2f0 ====

void FUN_0059c2f0(void)

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
  if (*(uint *)((int)_Memory + 0x20) < 0x10) {
    *(undefined4 *)((int)_Memory + 0x20) = 0xf;
    *(undefined4 *)((int)_Memory + 0x1c) = 0;
    *(undefined1 *)((int)_Memory + 0xc) = 0;
    _free(_Memory);
    return;
  }
  _free(*(void **)((int)_Memory + 0xc));
  return;
}


// ==== FUN_0059c350 @ 0x0059c350 ====

void * FUN_0059c350(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009825d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x28);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0056c180(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0059c3bd @ 0x0059c3bd ====

void Catch_0059c3bd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0059c3e0 @ 0x0059c3e0 ====

void FUN_0059c3e0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009825e0;
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
    uVar2 = FUN_0059be10(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0059c474 @ 0x0059c474 ====

void Catch_0059c474(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0059c490 @ 0x0059c490 ====

void FUN_0059c490(uint param_1,undefined1 param_2)

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
    FUN_0059c0a0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_0059c500 @ 0x0059c500 ====

/* WARNING: Removing unreachable block (ram,0x0059c61b) */
/* WARNING: Removing unreachable block (ram,0x0059c80f) */

void FUN_0059c500(int *param_1,int param_2)

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
      FUN_0059c490(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
LAB_0059c764:
        if ((uint)piVar11[7] <= uVar9) {
          bVar15 = false;
          goto LAB_0059c774;
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
        if (iVar6 == 0) goto LAB_0059c764;
LAB_0059c774:
        if (!bVar15) {
          if (*(uint *)(param_2 + 0x18) < 0x10) {
            pbVar14 = (byte *)(param_2 + 4);
          }
          else {
            pbVar14 = *(byte **)(param_2 + 4);
          }
          uVar9 = piVar11[7];
          if (uVar9 == 0) goto LAB_0059c83c;
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
          goto code_r0x0059c82f;
        }
      }
    } while (piVar11 != *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  goto LAB_0059c785;
  while( true ) {
    uVar7 = uVar7 - 1;
    bVar15 = *pbVar13 < *pbVar14;
    bVar16 = *pbVar13 == *pbVar14;
    pbVar13 = pbVar13 + 1;
    pbVar14 = pbVar14 + 1;
    if (!bVar16) break;
code_r0x0059c82f:
    if (uVar7 == 0) break;
  }
  if (!bVar16) {
    iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
  }
  bVar15 = iVar6 < 0;
  if (iVar6 == 0) {
LAB_0059c83c:
    if (uVar5 <= uVar9) {
      bVar15 = false;
      goto LAB_0059c84d;
    }
  }
  else {
LAB_0059c84d:
    if (!bVar15) {
      *param_1 = (int)piVar11;
      *(undefined1 *)(param_1 + 1) = 0;
      return;
    }
  }
  piVar11 = (int *)*piVar11;
LAB_0059c785:
  iVar6 = FUN_0059c350(piVar11,piVar11[1],param_2);
  FUN_0059c010(1);
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


// ==== FUN_0059c870 @ 0x0059c870 ====

void FUN_0059c870(byte param_1)

{
  void *in_ECX;
  
  FUN_0059be70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059c890 @ 0x0059c890 ====

void FUN_0059c890(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf9ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059c8d0 @ 0x0059c8d0 ====

int FUN_0059c8d0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0059c940 @ 0x0059c940 ====

void FUN_0059c940(void)

{
  int *piVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bfa68;
  in_ECX[1] = 0xffffffff;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5afb0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5afb0 = in_ECX;
  }
  in_ECX[5] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0xffffffff;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 4))(2,s___Mouse_MouseImpl_cpp_009bf8e8,0x94);
  in_ECX[0xb] = uVar2;
  pvVar3 = operator_new(0x48);
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005ae890();
  }
  in_ECX[0xc] = uVar2;
  (**(code **)(*DAT_00b5afac + 4))(in_ECX[0xb],uVar2,1);
  return;
}


// ==== FUN_0059c9e0 @ 0x0059c9e0 ====

void FUN_0059c9e0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bfa68;
  if (in_ECX[0xc] != 0) {
    (**(code **)(*DAT_00b5afac + 8))(in_ECX[0xb],1);
    if ((undefined4 *)in_ECX[0xc] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0xc])(1);
    }
    in_ECX[0xc] = 0;
  }
  if (in_ECX[0xb] != -1) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    (**(code **)(*piVar1 + 8))(s___Mouse_MouseImpl_cpp_009bf900,0xa3,2,in_ECX[0xb]);
    in_ECX[0xb] = 0xffffffff;
  }
  DAT_00b5afb0 = 0;
  *in_ECX = &PTR_FUN_009bf9ec;
  return;
}


// ==== FUN_0059caa0 @ 0x0059caa0 ====

undefined4 FUN_0059caa0(uint param_1)

{
  char cVar1;
  int iVar2;
  
  if (DAT_00b5ac1c != (int *)0x0) {
    cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
    if ((cVar1 != '\0') && (DAT_00b5ad04 != (int *)0x0)) {
      cVar1 = (**(code **)(*DAT_00b5ad04 + 4))();
      if (cVar1 != '\x01') {
        cVar1 = (**(code **)(*DAT_00b5ad04 + 0x10))(param_1);
        if (cVar1 != '\0') {
          if ((param_1 & 1) != 0) {
            return 1;
          }
          iVar2 = (**(code **)(*DAT_00b5ad04 + 0x18))(param_1);
          if (iVar2 != 0) {
            if ((*(char *)(iVar2 + 0xc) == '\x01') || (*(short *)(iVar2 + 0x14) != 0)) {
              return 1;
            }
            return 0;
          }
        }
        return 0;
      }
    }
  }
  return 0;
}


// ==== FUN_0059cb20 @ 0x0059cb20 ====

void FUN_0059cb20(int *param_1)

{
  char cVar1;
  char cVar2;
  undefined1 uStack00000000;
  int iVar3;
  undefined4 local_8;
  int local_4;
  
  if (*param_1 == 2) {
    local_8 = (int)(float)param_1[6];
    local_4 = (int)(float)param_1[8];
    cVar1 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_8);
    if ((DAT_00b5aeec != (int *)0x0) &&
       (cVar2 = (**(code **)(*DAT_00b5aeec + 0x38))(), cVar2 == '\x01')) {
      iVar3 = (int)register0x00000010 + -0xc;
      (**(code **)(*DAT_00b5afb4 + 0x10))(iVar3);
      cVar1 = FUN_005925b0(iVar3);
      if (cVar1 == '\x01') {
        FUN_005ae920(&uStack00000000);
        return;
      }
      FUN_005ae920(&uStack00000000);
      return;
    }
    if ((DAT_00b5af10 == (int *)0x0) || (cVar2 = (**(code **)(*DAT_00b5af10 + 8))(), cVar2 == '\0'))
    {
      FUN_005ae920(&uStack00000000);
      return;
    }
    if ((-(cVar1 != '\x01') & 3U) == 0) {
      FUN_005ae920(&uStack00000000);
      return;
    }
    FUN_005ae920(&uStack00000000);
  }
  return;
}


// ==== FUN_0059cc40 @ 0x0059cc40 ====

void FUN_0059cc40(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_1c [7];
  
  if (*(int *)(in_ECX + 0x14) != 0) {
    puVar1 = auStack_1c + -1;
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009bf9f8;
    }
    puVar4 = (undefined4 *)(in_ECX + 0x10);
    puVar5 = puVar2;
    for (iVar3 = 7; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
    }
    FUN_00797a20(puVar2);
    puVar2 = (undefined4 *)(in_ECX + 0x10);
    for (iVar3 = 7; puVar1 = puVar1 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar1;
      puVar2 = puVar2 + 1;
    }
    return;
  }
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009bfa24;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0059cce0 @ 0x0059cce0 ====

void FUN_0059cce0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_1c [7];
  
  if (*(int *)(in_ECX + 0x14) != 0) {
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009bf9f8;
    }
    puVar3 = (undefined4 *)(in_ECX + 0x10);
    puVar4 = puVar1;
    for (iVar2 = 7; puVar4 = puVar4 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
    }
    FUN_00797a20(puVar1);
    auStack_1c[1] = 0;
    auStack_1c[3] = 0;
    auStack_1c[2] = 0;
    auStack_1c[4] = 0xffffffff;
    auStack_1c[0]._0_1_ = 0;
    puVar1 = auStack_1c;
    puVar4 = (undefined4 *)(in_ECX + 0x10);
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_0059cd50 @ 0x0059cd50 ====

bool FUN_0059cd50(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  if (DAT_00b5ad9c != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*DAT_00b5ad98 + 8))();
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0xc))();
      if (iVar3 == 5) {
        cVar1 = (**(code **)(*DAT_00b5ad9c + 0x10))(param_1);
        if (cVar1 == '\x01') {
          return true;
        }
      }
    }
  }
  cVar1 = FUN_0059caa0(param_1,param_2);
  return cVar1 == '\x01';
}


// ==== FUN_0059cdb0 @ 0x0059cdb0 ====

void FUN_0059cdb0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int *piVar6;
  int in_ECX;
  int iVar7;
  undefined4 *puVar8;
  int unaff_retaddr;
  undefined1 auStackY_9c [128];
  
  puVar4 = param_2;
  FUN_0059cb20(param_2);
  if (*(int *)(in_ECX + 4) == param_1) {
    cVar2 = FUN_0059cd50(param_1,puVar4[9]);
    if (cVar2 == '\x01') {
      param_1 = 10;
      FUN_005ae920(&param_1);
      return;
    }
  }
  else {
    if (*(int *)(in_ECX + 4) != -1) {
      iVar3 = (**(code **)(*DAT_00b5a6a8 + 4))();
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_0059de30(*(undefined4 *)(in_ECX + 4),8);
      }
      puVar8 = (undefined4 *)(iVar3 + 0xc);
      for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar8 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar8 = puVar8 + 1;
      }
      FUN_00797a20(iVar3);
      puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        uVar1 = *(undefined4 *)(in_ECX + 4);
        *puVar4 = &PTR_FUN_009b663c;
        puVar4[1] = uVar1;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = 0;
      }
      pvVar5 = operator_new(8);
      if (pvVar5 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_005aeae0();
      }
      *(undefined1 *)(iVar3 + 4) = 0;
      FUN_00512750(iVar3);
      FUN_00797a20(puVar4);
      puVar4 = param_2;
    }
    iVar3 = param_1;
    if (param_1 != -1) {
      iVar7 = (**(code **)(*DAT_00b5a6a8 + 4))();
      if (iVar7 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_0059de30(iVar3,7);
      }
      puVar8 = (undefined4 *)(iVar3 + 0xc);
      for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar8 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar8 = puVar8 + 1;
      }
      FUN_00797a20(iVar3);
      puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      iVar3 = param_1;
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = &PTR_FUN_009b663c;
        puVar4[1] = param_1;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = 0;
      }
      pvVar5 = operator_new(8);
      if (pvVar5 == (void *)0x0) {
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_005aeae0();
      }
      *(undefined1 *)(iVar7 + 4) = 1;
      FUN_00512750(iVar7);
      FUN_00797a20(puVar4);
      piVar6 = (int *)(**(code **)(*DAT_00b5afbc + 0xc))(iVar3);
      if (piVar6 == (int *)0x0) {
        (**(code **)(*DAT_00b5afa4 + 8))(iVar3);
        FUN_005ae920(auStackY_9c + 0x98);
        *(int *)(in_ECX + 4) = iVar3;
        return;
      }
      cVar2 = FUN_0059cd50(iVar3,*(undefined4 *)(param_1 + 0x24));
      puVar4 = &param_1;
      if (cVar2 == '\x01') {
        param_1 = 10;
      }
      else {
        puVar4 = (undefined4 *)(**(code **)(*piVar6 + 0x18))(puVar4);
      }
      FUN_005ae920(puVar4);
      param_1 = unaff_retaddr;
    }
    *(int *)(in_ECX + 4) = param_1;
  }
  return;
}


// ==== FUN_0059cfb0 @ 0x0059cfb0 ====

void FUN_0059cfb0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 unaff_retaddr;
  undefined1 local_60 [20];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_4;
  
  *(undefined4 *)(in_ECX + 8) = param_1[4];
  *(undefined4 *)(in_ECX + 0xc) = param_1[5];
  FUN_005ae6f0((undefined4 *)(in_ECX + 8));
  local_48 = param_1[4];
  local_44 = param_1[5];
  local_40 = *param_3;
  local_3c = param_3[1];
  local_38 = param_3[2];
  local_34 = param_3[3];
  local_30 = param_3[4];
  local_4c = 3;
  cVar1 = (**(code **)(*DAT_00b5a6b4 + 8))(&local_4c,local_60);
  if (cVar1 == '\0') {
LAB_0059d13d:
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009bfa10;
      puVar2[2] = 0;
      puVar2[3] = 0xffffffff;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      puVar2[0xb] = 0;
    }
    puVar4 = param_1;
    puVar5 = puVar2 + 2;
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    *(undefined2 *)(puVar2 + 1) = unaff_retaddr;
    FUN_00797a20(puVar2);
    FUN_0059cdb0(0xffffffff,param_1);
    return;
  }
  if (unaff_EBP == 1) {
    uStack_4 = 1;
  }
  else if (unaff_EBP == 2) {
    uStack_4 = 2;
  }
  else {
    if (unaff_EBP != 3) goto LAB_0059d13d;
    uStack_4 = 3;
  }
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009bfa10;
    puVar2[2] = 0;
    puVar2[3] = 0xffffffff;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
  }
  puVar4 = param_1;
  puVar5 = &local_30;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  local_30 = uStack_4;
  uStack_28 = param_1[2];
  uStack_24 = param_1[3];
  puVar4 = &local_30;
  puVar5 = puVar2 + 2;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)(puVar2 + 1) = unaff_retaddr;
  FUN_00797a20(puVar2);
  FUN_0059cdb0(unaff_EBX,&local_30);
  return;
}


// ==== FUN_0059d1c0 @ 0x0059d1c0 ====

void FUN_0059d1c0(int param_1,int *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  void *unaff_ESI;
  int *piVar5;
  uint *puVar6;
  int *piVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uVar10;
  double dVar11;
  double dVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  void *pvStack_ac;
  uint auStack_a8 [4];
  uint uStack_98;
  int iStack_94;
  void *pvStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  uint uStack_7c;
  int iStack_70;
  uint uStack_6c;
  float local_68;
  float fStack_64;
  float fStack_60;
  int aiStack_5c [4];
  int iStack_4c;
  int iStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  int iStack_38;
  undefined4 local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_28 = param_2[4];
  local_24 = param_2[5];
  local_20 = *param_3;
  local_1c = param_3[1];
  local_18 = param_3[2];
  local_14 = param_3[3];
  local_10 = param_3[4];
  local_c = param_3[5];
  local_2c = 3;
  cVar1 = (**(code **)(*DAT_00b5a6b4 + 8))(&local_2c,&local_68);
  if (cVar1 == '\0') {
LAB_0059d541:
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009bfa38;
      puVar2[2] = param_1;
      puVar2[1] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xffffffff;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      puVar2[0xb] = 0;
      puVar2[0xc] = 0;
    }
    piVar5 = puVar2 + 3;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar5 = *param_2;
      param_2 = param_2 + 1;
      piVar5 = piVar5 + 1;
    }
    FUN_00797a20(puVar2);
    FUN_00401740();
    FUN_00401740(s__x__f__f__f__x_009bf990,0xe);
    FUN_00404230(&uStack_8c);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_7c) {
      _free(pvStack_90);
      return;
    }
    uStack_7c = 0xf;
    uStack_80 = 0;
    pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
    if (0xf < auStack_a8[2]) {
      _free(unaff_ESI);
      return;
    }
    if (param_1 == 3) {
      puVar6 = auStack_a8 + -4;
      puVar8 = (uint *)0x1f;
      for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
    }
    FUN_0059cdb0();
  }
  else {
    if (iStack_70 == 1) {
      iStack_94 = 1;
    }
    else if (iStack_70 == 2) {
      iStack_94 = 2;
    }
    else {
      if (iStack_70 != 3) goto LAB_0059d541;
      iStack_94 = 3;
    }
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2[1] = uStack_6c;
      *puVar2 = &PTR_FUN_009bfa38;
      puVar2[2] = param_1;
      puVar2[3] = 0;
      puVar2[4] = 0xffffffff;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      puVar2[0xb] = 0;
      puVar2[0xc] = 0;
    }
    piVar5 = param_2;
    piVar7 = aiStack_5c;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar7 = *piVar5;
      piVar5 = piVar5 + 1;
      piVar7 = piVar7 + 1;
    }
    aiStack_5c[1] = uStack_6c;
    aiStack_5c[0] = iStack_94;
    aiStack_5c[3] = param_2[3];
    aiStack_5c[2] = param_2[2];
    iStack_48 = param_2[5];
    iStack_4c = param_2[4];
    fStack_40 = fStack_64;
    fStack_44 = local_68;
    iStack_38 = param_2[9];
    fStack_3c = fStack_60;
    piVar5 = aiStack_5c;
    piVar7 = puVar2 + 3;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar7 = *piVar5;
      piVar5 = piVar5 + 1;
      piVar7 = piVar7 + 1;
    }
    FUN_00797a20(puVar2);
    dVar12 = (double)fStack_40;
    dVar11 = (double)fStack_44;
    uVar9 = 0xf;
    uVar10 = aiStack_5c[1];
    FUN_00401740(s__x__f__f__f__x_009bf968,0xe);
    FUN_00404230(&uStack_8c);
    if ((iStack_94 == 1) || (iStack_94 == 2)) {
      uVar3 = (int)(fStack_3c * DAT_009af898) & ((int)(fStack_3c * DAT_009af898) < 0) - 1;
      uVar14 = CONCAT44(((int)(fStack_44 * DAT_009af898) < 0) - 1 & (int)(fStack_44 * DAT_009af898),
                        0xf);
      uVar13 = (ulonglong)dVar12 & 0xffffffff;
      uVar10 = uVar10 & 0xffffff00;
      FUN_00401740(s_zone__d__d__009bf978,0xc);
      uVar9 = FUN_00404230(auStack_a8 + -2,uVar9,uVar10,dVar11,uVar13,uVar14,uVar3);
      FUN_00401ff0(uVar9,0,0xffffffff);
      if (0xf < uStack_98) {
        _free(pvStack_ac);
        return;
      }
    }
    FUN_00401740();
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < auStack_a8[2]) {
      _free(unaff_ESI);
      return;
    }
    FUN_0059cdb0();
    if (((param_1 == 1) || (param_1 == 3)) || (param_1 == 5)) {
      puVar6 = auStack_a8 + -4;
      puVar8 = (uint *)0x1f;
      for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
    }
    if (0xf < uStack_7c) {
      _free(pvStack_90);
      return;
    }
  }
  if (((param_1 == 2) || (param_1 == 6)) || (param_1 == 4)) {
    pvStack_90 = (void *)0x0;
    local_88 = 0;
    uStack_8c = 0;
    uStack_84 = 0xffffffff;
    piVar5 = &iStack_94;
    piVar7 = (int *)0x1f;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar7 = *piVar5;
      piVar5 = piVar5 + 1;
      piVar7 = piVar7 + 1;
    }
  }
  return;
}


// ==== FUN_0059d6f0 @ 0x0059d6f0 ====

void FUN_0059d6f0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  void *in_ECX;
  int iVar4;
  undefined4 *unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 *unaff_ESI;
  uint *puVar5;
  void **ppvVar6;
  int unaff_EDI;
  uint *puVar7;
  undefined4 *puVar8;
  float fVar9;
  float fVar10;
  uint uVar11;
  double dVar12;
  double dVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  undefined1 *local_a0;
  void *local_9c;
  uint uStack_90;
  void *apvStack_8c [6];
  uint uStack_74;
  uint auStack_68 [4];
  undefined4 uStack_58;
  undefined4 uStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  undefined4 uStack_44;
  int iStack_40;
  uint uStack_3c;
  float local_38;
  float fStack_34;
  float fStack_30;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_9c = in_ECX;
  if (param_1 != 0) {
    iVar4 = *(int *)((int)in_ECX + 0x1c);
    if ((iVar4 == 1) && (param_1 != 2)) {
      uVar16 = 2;
    }
    else if ((iVar4 == 2) && (param_1 != 4)) {
      uVar16 = 4;
    }
    else {
      if ((iVar4 != 3) || (param_1 == 6)) goto LAB_0059d75a;
      uVar16 = 6;
    }
    FUN_0059d6f0(uVar16,param_2,param_3);
  }
LAB_0059d75a:
  local_a0 = (undefined1 *)((int)in_ECX + 0x10);
  if (*(char *)((int)in_ECX + 0x10) == '\0') {
    fVar10 = (float)(param_2[4] - *(int *)((int)in_ECX + 0x24));
    fVar9 = (float)(param_2[5] - *(int *)((int)in_ECX + 0x28));
    if (SQRT(fVar10 * fVar10 + fVar9 * fVar9) <= DAT_009bfa74) {
      FUN_0059d1c0(param_1,param_2,param_3);
      return;
    }
    *local_a0 = 1;
  }
  local_1c = param_2[5];
  local_20 = param_2[4];
  local_10 = param_3[2];
  local_4 = param_3[5];
  local_14 = param_3[1];
  local_18 = *param_3;
  local_c = param_3[3];
  local_8 = param_3[4];
  local_24 = 3;
  cVar1 = (**(code **)(*DAT_00b5a6b4 + 8))(&local_24,&local_38);
  if (cVar1 == '\0') {
LAB_0059da97:
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      uVar16 = *(undefined4 *)((int)in_ECX + 0x20);
      *puVar2 = &PTR_FUN_009bfa50;
      puVar2[1] = uVar16;
      puVar2[2] = unaff_EBP;
      puVar2[10] = 0;
      puVar2[0xb] = 0xffffffff;
      puVar2[0xc] = 0;
      puVar2[0xd] = 0;
      puVar2[0xe] = 0;
      puVar2[0xf] = 0;
      puVar2[0x10] = 0;
      puVar2[0x11] = 0;
      puVar2[0x12] = 0;
      puVar2[0x13] = 0;
    }
    puVar8 = puVar2 + 3;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = *unaff_EBX;
      unaff_EBX = unaff_EBX + 1;
      puVar8 = puVar8 + 1;
    }
    puVar8 = puVar2 + 10;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = *param_2;
      param_2 = param_2 + 1;
      puVar8 = puVar8 + 1;
    }
    FUN_00797a20(puVar2);
    apvStack_8c[1] = (void *)0xf;
    apvStack_8c[0] = (void *)0x0;
    local_9c = (void *)((uint)local_9c & 0xffffff00);
    FUN_00401740();
    FUN_00401740(s__x__f__f__f__x_009bf9d0,0xe);
    FUN_00404230(apvStack_8c + 2);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_74) {
      _free(apvStack_8c[1]);
      return;
    }
    uStack_74 = 0xf;
    apvStack_8c[5] = (void *)0x0;
    apvStack_8c[1] = (void *)((uint)apvStack_8c[1] & 0xffffff00);
    if (0xf < uStack_90) {
      _free((void *)(uint)(param_1 != 0));
      return;
    }
    FUN_0059cdb0();
  }
  else {
    if (iStack_40 == 1) {
      auStack_68[0] = 1;
    }
    else if (iStack_40 == 2) {
      auStack_68[0] = 2;
    }
    else {
      if (iStack_40 != 3) goto LAB_0059da97;
      auStack_68[0] = 3;
    }
    auStack_68[2] = param_2[2];
    auStack_68[1] = uStack_3c;
    uStack_58 = param_2[4];
    auStack_68[3] = param_2[3];
    uStack_54 = param_2[5];
    uStack_44 = param_2[9];
    fStack_4c = fStack_34;
    fStack_50 = local_38;
    fStack_48 = fStack_30;
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      uVar16 = *(undefined4 *)((int)in_ECX + 0x20);
      *puVar2 = &PTR_FUN_009bfa50;
      puVar2[1] = uVar16;
      puVar2[2] = unaff_EBP;
      puVar2[10] = 0;
      puVar2[0xb] = 0xffffffff;
      puVar2[0xc] = 0;
      puVar2[0xd] = 0;
      puVar2[0xe] = 0;
      puVar2[0xf] = 0;
      puVar2[0x10] = 0;
      puVar2[0x11] = 0;
      puVar2[0x12] = 0;
      puVar2[0x13] = 0;
    }
    puVar8 = puVar2 + 3;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = *unaff_EBX;
      unaff_EBX = unaff_EBX + 1;
      puVar8 = puVar8 + 1;
    }
    puVar5 = auStack_68;
    puVar7 = puVar2 + 10;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    FUN_00797a20(puVar2);
    dVar13 = (double)fStack_4c;
    dVar12 = (double)fStack_50;
    uVar16 = 0xf;
    uVar11 = auStack_68[1];
    FUN_00401740(s__x__f__f__f__x_009bf9a8,0xe);
    FUN_00404230(apvStack_8c + 2);
    uVar3 = (int)(fStack_48 * DAT_009af898) & ((int)(fStack_48 * DAT_009af898) < 0) - 1;
    uVar15 = CONCAT44(((int)(fStack_50 * DAT_009af898) < 0) - 1 & (int)(fStack_50 * DAT_009af898),
                      0xf);
    uVar14 = (ulonglong)dVar13 & 0xffffffff;
    uVar11 = uVar11 & 0xffffff00;
    FUN_00401740(s_zone__d__d__009bf9b8,0xc);
    uVar16 = FUN_00404230(&local_a0,uVar16,uVar11,dVar12,uVar14,uVar15,uVar3);
    FUN_00401ff0(uVar16,0,0xffffffff);
    if (0xf < apvStack_8c[1]) {
      _free(local_9c);
      return;
    }
    apvStack_8c[1] = (void *)0xf;
    apvStack_8c[0] = (void *)0x0;
    local_9c = (void *)((uint)local_9c & 0xffffff00);
    FUN_00401740();
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_90) {
      _free((void *)(uint)(param_1 != 0));
      return;
    }
    FUN_0059cdb0();
    if (0xf < uStack_74) {
      _free(apvStack_8c[1]);
      return;
    }
  }
  if (unaff_EDI == 1) {
    apvStack_8c[1] = (void *)0x0;
    apvStack_8c[3] = (void *)0x0;
    apvStack_8c[2] = (void *)0x0;
    apvStack_8c[4] = (void *)0xffffffff;
    ppvVar6 = apvStack_8c;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
      *unaff_ESI = *ppvVar6;
      ppvVar6 = ppvVar6 + 1;
      unaff_ESI = unaff_ESI + 1;
    }
  }
  return;
}


// ==== FUN_0059dc00 @ 0x0059dc00 ====

void FUN_0059dc00(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  void *unaff_EBX;
  char *pcVar2;
  undefined4 uVar3;
  undefined1 local_38 [4];
  undefined1 local_34;
  uint uStack_28;
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_2 + 0x14);
  FUN_005ae6f0((undefined4 *)(in_ECX + 8));
  if (*(int *)(in_ECX + 0x14) == 0) {
    FUN_0059d1c0(param_1,param_2,param_3);
  }
  else if (*(int *)(in_ECX + 0x14) == 3) {
    FUN_0059d6f0(param_1,param_2,param_3);
  }
  iVar1 = *(int *)(in_ECX + 0x14);
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = 0;
  if (iVar1 != 0) {
    if (*(int *)(in_ECX + 0x1c) == 1) {
      uVar3 = 0xd;
      pcVar2 = s_L_Button_Down_009bf918;
      goto LAB_0059dcb8;
    }
    if (iVar1 != 0) {
      if (*(int *)(in_ECX + 0x1c) == 2) {
        uVar3 = 0xd;
        pcVar2 = s_R_Button_Down_009bf928;
        goto LAB_0059dcb8;
      }
      if (iVar1 != 0) {
        if (*(int *)(in_ECX + 0x1c) == 3) {
          uVar3 = 0xd;
          pcVar2 = s_M_Button_Down_009bf938;
          goto LAB_0059dcb8;
        }
        if (iVar1 != 0) {
          uVar3 = 5;
          pcVar2 = s_error_009bf950;
          goto LAB_0059dcb8;
        }
      }
    }
  }
  uVar3 = 5;
  pcVar2 = s_Blank_009bf948;
LAB_0059dcb8:
  FUN_00401740(pcVar2,uVar3);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_cursor_state_009bf958,0xc);
  (**(code **)(*DAT_00b5a688 + 8))(local_1c,local_38);
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  if (uStack_28 < 0x10) {
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_0059dd30 @ 0x0059dd30 ====

undefined4 FUN_0059dd30(int *param_1)

{
  uint uVar1;
  undefined2 extraout_var;
  undefined1 auStack_18 [2];
  undefined1 auStack_16 [22];
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x10050004) {
    if (uVar1 == 0x10050003) {
      FUN_0059cc40();
      return 1;
    }
    if (uVar1 == 0x10050001) {
      (**(code **)(*DAT_00b5a988 + 0x20))(auStack_18,param_1 + 2);
      FUN_0059dc00(param_1[1],param_1 + 2,auStack_18 + -8);
      return 1;
    }
    if (uVar1 == 0x10050002) {
      (**(code **)(*DAT_00b5a988 + 0x20))(auStack_18,param_1 + 2);
      FUN_0059cfb0(param_1 + 2,CONCAT22(extraout_var,(short)param_1[1]),auStack_18 + -8);
      return 1;
    }
  }
  else if (uVar1 == 0x10050100) {
    FUN_0059cce0();
    return 1;
  }
  return 0;
}


// ==== FUN_0059de00 @ 0x0059de00 ====

undefined4 FUN_0059de00(void)

{
  return 0x10004;
}


// ==== FUN_0059de10 @ 0x0059de10 ====

undefined4 FUN_0059de10(void)

{
  return 0x10010;
}


// ==== FUN_0059de20 @ 0x0059de20 ====

undefined4 FUN_0059de20(void)

{
  return 0x20004;
}


// ==== FUN_0059de30 @ 0x0059de30 ====

void FUN_0059de30(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009bfa38;
  in_ECX[2] = param_2;
  in_ECX[3] = 0;
  in_ECX[4] = 0xffffffff;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_0059de80 @ 0x0059de80 ====

undefined4 FUN_0059de80(void)

{
  return 0x10001;
}


// ==== FUN_0059de90 @ 0x0059de90 ====

undefined4 FUN_0059de90(void)

{
  return 0x10003;
}


// ==== FUN_0059dea0 @ 0x0059dea0 ====

void FUN_0059dea0(byte param_1)

{
  void *in_ECX;
  
  FUN_0059c9e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059dec0 @ 0x0059dec0 ====

void FUN_0059dec0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0a48;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059dee0 @ 0x0059dee0 ====

void FUN_0059dee0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0a58;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059df00 @ 0x0059df00 ====

void FUN_0059df00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0a70;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059df20 @ 0x0059df20 ====

void FUN_0059df20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0a88;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059df40 @ 0x0059df40 ====

void FUN_0059df40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0aa0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059df60 @ 0x0059df60 ====

void FUN_0059df60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0ab8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059df80 @ 0x0059df80 ====

void FUN_0059df80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0ad0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059dfa0 @ 0x0059dfa0 ====

void FUN_0059dfa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0ae8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059dfc0 @ 0x0059dfc0 ====

void FUN_0059dfc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b00;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059dfe0 @ 0x0059dfe0 ====

void FUN_0059dfe0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e000 @ 0x0059e000 ====

void FUN_0059e000(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b30;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e020 @ 0x0059e020 ====

void FUN_0059e020(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b48;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e040 @ 0x0059e040 ====

void FUN_0059e040(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b50;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e060 @ 0x0059e060 ====

void FUN_0059e060(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b58;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e080 @ 0x0059e080 ====

void FUN_0059e080(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b60;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e0a0 @ 0x0059e0a0 ====

void FUN_0059e0a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b68;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e0c0 @ 0x0059e0c0 ====

void FUN_0059e0c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b70;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e0e0 @ 0x0059e0e0 ====

void FUN_0059e0e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b78;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e100 @ 0x0059e100 ====

void FUN_0059e100(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b80;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e120 @ 0x0059e120 ====

void FUN_0059e120(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b88;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e140 @ 0x0059e140 ====

void FUN_0059e140(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0b90;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059e160 @ 0x0059e160 ====

void FUN_0059e160(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c0b98;
  in_ECX[1] = &PTR_FUN_009c0b48;
  in_ECX[0x9a02] = 0;
  in_ECX[0x9a02] = in_ECX[0x9a02] + 0x200;
  in_ECX[0x9a05] = in_ECX + 2;
  in_ECX[0x9a03] = 0;
  in_ECX[0x9a04] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x4c] = puVar1 + 0x4f;
    puVar1[0x4d] = 0;
    puVar1[0x4e] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x4d;
  } while (iVar2 != 0);
  in_ECX[0x99ff] = 0;
  in_ECX[0x9a00] = 0;
  in_ECX[0x9a01] = 0;
  return;
}


// ==== FUN_0059e1d0 @ 0x0059e1d0 ====

undefined4 FUN_0059e1d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2680c);
}


// ==== FUN_0059e1e0 @ 0x0059e1e0 ====

void FUN_0059e1e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c0bb0;
  in_ECX[1] = &PTR_FUN_009c0b50;
  in_ECX[0x2802] = 0;
  in_ECX[0x2802] = in_ECX[0x2802] + 0x100;
  in_ECX[0x2805] = in_ECX + 2;
  in_ECX[0x2803] = 0;
  in_ECX[0x2804] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[0x27] = puVar1 + 0x2a;
    puVar1[0x28] = 0;
    puVar1[0x29] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x28;
  } while (iVar2 != 0);
  in_ECX[0x27ff] = 0;
  in_ECX[0x2800] = 0;
  in_ECX[0x2801] = 0;
  return;
}


// ==== FUN_0059e250 @ 0x0059e250 ====

undefined4 FUN_0059e250(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa00c);
}


// ==== FUN_0059e260 @ 0x0059e260 ====

void FUN_0059e260(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c0bc8;
  in_ECX[1] = &PTR_FUN_009c0b58;
  in_ECX[0x10002] = 0;
  in_ECX[0x10002] = in_ECX[0x10002] + 0x200;
  in_ECX[0x10005] = in_ECX + 2;
  in_ECX[0x10003] = 0;
  in_ECX[0x10004] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x7f] = puVar1 + 0x82;
    puVar1[0x80] = 0;
    puVar1[0x81] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x80;
  } while (iVar2 != 0);
  in_ECX[0xffff] = 0;
  in_ECX[0x10000] = 0;
  in_ECX[0x10001] = 0;
  return;
}


// ==== FUN_0059e2d0 @ 0x0059e2d0 ====

undefined4 FUN_0059e2d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x4000c);
}


// ==== FUN_0059e2e0 @ 0x0059e2e0 ====

void FUN_0059e2e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c0be0;
  in_ECX[1] = &PTR_FUN_009c0b60;
  in_ECX[0xba02] = 0;
  in_ECX[0xba02] = in_ECX[0xba02] + 0x200;
  in_ECX[0xba05] = in_ECX + 2;
  in_ECX[0xba03] = 0;
  in_ECX[0xba04] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x5c] = puVar1 + 0x5f;
    puVar1[0x5d] = 0;
    puVar1[0x5e] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x5d;
  } while (iVar2 != 0);
  in_ECX[0xb9ff] = 0;
  in_ECX[0xba00] = 0;
  in_ECX[0xba01] = 0;
  return;
}


// ==== FUN_0059e350 @ 0x0059e350 ====

undefined4 FUN_0059e350(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2e80c);
}


// ==== FUN_0059e360 @ 0x0059e360 ====

void FUN_0059e360(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c0bf8;
  in_ECX[1] = &PTR_FUN_009c0b68;
  in_ECX[0x6602] = 0;
  in_ECX[0x6602] = in_ECX[0x6602] + 0x200;
  in_ECX[0x6605] = in_ECX + 2;
  in_ECX[0x6603] = 0;
  in_ECX[0x6604] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x32] = puVar1 + 0x35;
    puVar1[0x33] = 0;
    puVar1[0x34] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x33;
  } while (iVar2 != 0);
  in_ECX[0x65ff] = 0;
  in_ECX[0x6600] = 0;
  in_ECX[0x6601] = 0;
  return;
}


// ==== FUN_0059e3d0 @ 0x0059e3d0 ====

undefined4 FUN_0059e3d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1980c);
}


// ==== FUN_0059e3e0 @ 0x0059e3e0 ====

void FUN_0059e3e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c0c10;
  in_ECX[1] = &PTR_FUN_009c0b70;
  in_ECX[0x11402] = 0;
  in_ECX[0x11402] = in_ECX[0x11402] + 0x200;
  in_ECX[0x11405] = in_ECX + 2;
  in_ECX[0x11403] = 0;
  in_ECX[0x11404] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x89] = puVar1 + 0x8c;
    puVar1[0x8a] = 0;
    puVar1[0x8b] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x8a;
  } while (iVar2 != 0);
  in_ECX[0x113ff] = 0;
  in_ECX[0x11400] = 0;
  in_ECX[0x11401] = 0;
  return;
}


// ==== FUN_0059e450 @ 0x0059e450 ====

undefined4 FUN_0059e450(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x4500c);
}


// ==== FUN_0059e460 @ 0x0059e460 ====

void FUN_0059e460(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c0c28;
  in_ECX[1] = &PTR_FUN_009c0b78;
  in_ECX[0x1402] = 0;
  in_ECX[0x1402] = in_ECX[0x1402] + 0x80;
  in_ECX[0x1405] = in_ECX + 2;
  in_ECX[0x1403] = 0;
  in_ECX[0x1404] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[0x27] = puVar1 + 0x2a;
    puVar1[0x28] = 0;
    puVar1[0x29] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x28;
  } while (iVar2 != 0);
  in_ECX[0x13ff] = 0;
  in_ECX[0x1400] = 0;
  in_ECX[0x1401] = 0;
  return;
}


// ==== FUN_0059e4d0 @ 0x0059e4d0 ====

void FUN_0059e4d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c0c40;
  in_ECX[1] = &PTR_FUN_009c0b80;
  in_ECX[0x1502] = 0;
  in_ECX[0x1502] = in_ECX[0x1502] + 0x80;
  in_ECX[0x1505] = in_ECX + 2;
  in_ECX[0x1503] = 0;
  in_ECX[0x1504] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[0x29] = puVar1 + 0x2c;
    puVar1[0x2a] = 0;
    puVar1[0x2b] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x2a;
  } while (iVar2 != 0);
  in_ECX[0x14ff] = 0;
  in_ECX[0x1500] = 0;
  in_ECX[0x1501] = 0;
  return;
}


// ==== FUN_0059e540 @ 0x0059e540 ====

undefined4 FUN_0059e540(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x540c);
}


// ==== FUN_0059e550 @ 0x0059e550 ====

void FUN_0059e550(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c0c58;
  in_ECX[1] = &PTR_FUN_009c0b88;
  in_ECX[0x6d2] = 0;
  in_ECX[0x6d2] = in_ECX[0x6d2] + 0x10;
  in_ECX[0x6d5] = in_ECX + 2;
  in_ECX[0x6d3] = 0;
  in_ECX[0x6d4] = 0;
  iVar2 = 0xf;
  puVar1 = in_ECX;
  do {
    puVar1[0x6c] = puVar1 + 0x6f;
    puVar1[0x6d] = 0;
    puVar1[0x6e] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x6d;
  } while (iVar2 != 0);
  in_ECX[0x6cf] = 0;
  in_ECX[0x6d0] = 0;
  in_ECX[0x6d1] = 0;
  return;
}


// ==== FUN_0059e5c0 @ 0x0059e5c0 ====

undefined4 FUN_0059e5c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1b4c);
}


// ==== FUN_0059e5d0 @ 0x0059e5d0 ====

void FUN_0059e5d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c0c70;
  in_ECX[1] = &PTR_FUN_009c0b90;
  in_ECX[0x1602] = 0;
  in_ECX[0x1602] = in_ECX[0x1602] + 0x80;
  in_ECX[0x1605] = in_ECX + 2;
  in_ECX[0x1603] = 0;
  in_ECX[0x1604] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[0x2b] = puVar1 + 0x2e;
    puVar1[0x2c] = 0;
    puVar1[0x2d] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x2c;
  } while (iVar2 != 0);
  in_ECX[0x15ff] = 0;
  in_ECX[0x1600] = 0;
  in_ECX[0x1601] = 0;
  return;
}


// ==== FUN_0059e640 @ 0x0059e640 ====

undefined4 FUN_0059e640(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x580c);
}


// ==== FUN_0059e650 @ 0x0059e650 ====

void FUN_0059e650(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0c88;
  pvVar1 = operator_new(0x26818);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0059e160();
  }
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0xa018);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0059e1e0();
  }
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x40018);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0059e260();
  }
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0x2e818);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0059e2e0();
  }
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0x19818);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0059e360();
  }
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(0x45018);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0059e3e0();
  }
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(0x5018);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0059e460();
  }
  in_ECX[7] = uVar2;
  pvVar1 = operator_new(0x5418);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0059e4d0();
  }
  in_ECX[8] = uVar2;
  pvVar1 = operator_new(7000);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0059e550();
  }
  in_ECX[9] = uVar2;
  pvVar1 = operator_new(0x5818);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0059e5d0();
  }
  in_ECX[10] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aff8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aff8 = in_ECX;
  return;
}


// ==== FUN_0059e7c0 @ 0x0059e7c0 ====

void FUN_0059e7c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0c88;
  DAT_00b5aff8 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[9])(1);
  }
  in_ECX[9] = 0;
  if ((undefined4 *)in_ECX[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[10])(1);
  }
  in_ECX[10] = 0;
  *in_ECX = &PTR_FUN_009c0a48;
  return;
}


// ==== FUN_0059e880 @ 0x0059e880 ====

void FUN_0059e880(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  int *local_8;
  uint local_4;
  
  if (param_1 != (int *)0x0) {
    uVar2 = (**(code **)(*param_1 + 0x14))();
    switch(uVar2) {
    case 1:
      uVar2 = FUN_00803725(param_1,0,&Framework::DollStage::Effect::IUnit::RTTI_Type_Descriptor,
                           &Framework::DollStage::Effect::Unit::Sprite::RTTI_Type_Descriptor,0);
      (**(code **)(**(int **)(in_ECX + 0x10) + 0x10))(1,uVar2);
      return;
    case 2:
      uVar2 = FUN_00803725(param_1,0,&Framework::DollStage::Effect::IUnit::RTTI_Type_Descriptor,
                           &Framework::DollStage::Effect::Unit::Decal::RTTI_Type_Descriptor,0);
      (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,uVar2);
      return;
    case 3:
      uVar2 = FUN_00803725(param_1,0,&Framework::DollStage::Effect::IUnit::RTTI_Type_Descriptor,
                           &Framework::DollStage::Effect::Unit::Mesh::RTTI_Type_Descriptor,0);
      (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,uVar2);
      return;
    case 4:
      uVar2 = FUN_00803725(param_1,0,&Framework::DollStage::Effect::IUnit::RTTI_Type_Descriptor,
                           &Framework::DollStage::Effect::Unit::Light::RTTI_Type_Descriptor,0);
      (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,uVar2);
      return;
    case 5:
      uVar2 = FUN_00803725(param_1,0,&Framework::DollStage::Effect::IUnit::RTTI_Type_Descriptor,
                           &Framework::DollStage::Effect::Unit::Quake::RTTI_Type_Descriptor,0);
      (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10))(1,uVar2);
      return;
    case 6:
      uVar2 = FUN_00803725(param_1,0,&Framework::DollStage::Effect::IUnit::RTTI_Type_Descriptor,
                           &Framework::DollStage::Effect::Unit::Sound::RTTI_Type_Descriptor,0);
      (**(code **)(**(int **)(in_ECX + 0x20) + 0x10))(1,uVar2);
      return;
    case 7:
      uVar2 = FUN_00803725(param_1,0,&Framework::DollStage::Effect::IUnit::RTTI_Type_Descriptor,
                           &Framework::DollStage::Effect::Unit::Particle::RTTI_Type_Descriptor,0);
      (**(code **)(**(int **)(in_ECX + 0x18) + 0x10))(1,uVar2);
      return;
    case 8:
      uVar2 = FUN_00803725(param_1,0,&Framework::DollStage::Effect::IUnit::RTTI_Type_Descriptor,
                           &Framework::DollStage::Effect::Unit::Weather::RTTI_Type_Descriptor,0);
      (**(code **)(**(int **)(in_ECX + 0x24) + 0x10))(1,uVar2);
      return;
    case 9:
      uVar2 = FUN_00803725(param_1,0,&Framework::DollStage::Effect::IUnit::RTTI_Type_Descriptor,
                           &Framework::DollStage::Effect::Unit::Shockwave::RTTI_Type_Descriptor,0);
      (**(code **)(**(int **)(in_ECX + 0x14) + 0x10))(1,uVar2);
      return;
    case 0xb:
      uVar2 = FUN_00803725(param_1,0,&Framework::DollStage::Effect::IUnit::RTTI_Type_Descriptor,
                           &Framework::DollStage::Effect::Unit::MeshStatus::RTTI_Type_Descriptor,0);
      (**(code **)(**(int **)(in_ECX + 0x28) + 0x10))(1,uVar2);
    }
    return;
  }
  local_4 = 0xf;
  local_8 = param_1;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pUnit____NULL_009bfa7c,0xd);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0059eac0 @ 0x0059eac0 ====

/* WARNING: Removing unreachable block (ram,0x0059eb0a) */

int FUN_0059eac0(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1);
  if (iVar2 == 0) {
    FUN_00401740(s_pUnit____NULL_009bfaa8,0xd);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return iVar2;
}


// ==== FUN_0059eb20 @ 0x0059eb20 ====

/* WARNING: Removing unreachable block (ram,0x0059eb6a) */

int FUN_0059eb20(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0xc))(1);
  if (iVar2 == 0) {
    FUN_00401740(s_pUnit____NULL_009bfab8,0xd);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return iVar2;
}


// ==== FUN_0059eb80 @ 0x0059eb80 ====

/* WARNING: Removing unreachable block (ram,0x0059ebca) */

int FUN_0059eb80(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))(1);
  if (iVar2 == 0) {
    FUN_00401740(s_pUnit____NULL_009bfac8,0xd);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return iVar2;
}


// ==== FUN_0059ebe0 @ 0x0059ebe0 ====

/* WARNING: Removing unreachable block (ram,0x0059ec2a) */

int FUN_0059ebe0(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x10) + 0xc))(1);
  if (iVar2 == 0) {
    FUN_00401740(s_pUnit____NULL_009bfad8,0xd);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return iVar2;
}


// ==== FUN_0059ec40 @ 0x0059ec40 ====

/* WARNING: Removing unreachable block (ram,0x0059ec8a) */

int FUN_0059ec40(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x14) + 0xc))(1);
  if (iVar2 == 0) {
    FUN_00401740(s_pUnit____NULL_009bfae8,0xd);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return iVar2;
}


// ==== FUN_0059eca0 @ 0x0059eca0 ====

/* WARNING: Removing unreachable block (ram,0x0059ecea) */

int FUN_0059eca0(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x18) + 0xc))(1);
  if (iVar2 == 0) {
    FUN_00401740(s_pUnit____NULL_009bfaf8,0xd);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return iVar2;
}


// ==== FUN_0059ed00 @ 0x0059ed00 ====

/* WARNING: Removing unreachable block (ram,0x0059ed4a) */

int FUN_0059ed00(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x1c) + 0xc))(1);
  if (iVar2 == 0) {
    FUN_00401740(s_pUnit____NULL_009bfb08,0xd);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return iVar2;
}


// ==== FUN_0059ed60 @ 0x0059ed60 ====

/* WARNING: Removing unreachable block (ram,0x0059edaa) */

int FUN_0059ed60(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x20) + 0xc))(1);
  if (iVar2 == 0) {
    FUN_00401740(s_pUnit____NULL_009bfb18,0xd);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return iVar2;
}


// ==== FUN_0059edc0 @ 0x0059edc0 ====

/* WARNING: Removing unreachable block (ram,0x0059ee0a) */

int FUN_0059edc0(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x24) + 0xc))(1);
  if (iVar2 == 0) {
    FUN_00401740(s_pUnit____NULL_009bfb28,0xd);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return iVar2;
}


// ==== FUN_0059ee20 @ 0x0059ee20 ====

/* WARNING: Removing unreachable block (ram,0x0059ee6a) */

int FUN_0059ee20(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x28) + 0xc))(1);
  if (iVar2 == 0) {
    FUN_00401740(s_pUnit____NULL_009bfb38,0xd);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return iVar2;
}


// ==== FUN_0059ee80 @ 0x0059ee80 ====

int * FUN_0059ee80(undefined4 *param_1,int param_2)

{
  code *pcVar1;
  int *extraout_EAX;
  int *piVar2;
  int *extraout_EAX_00;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  switch(*param_1) {
  case 1:
    piVar2 = (int *)FUN_0059ebe0();
    break;
  case 2:
    piVar2 = (int *)FUN_0059eac0();
    break;
  case 3:
    piVar2 = (int *)FUN_0059eb80();
    break;
  case 4:
    piVar2 = (int *)FUN_0059eb20();
    break;
  case 5:
    piVar2 = (int *)FUN_0059ed00();
    break;
  case 6:
    piVar2 = (int *)FUN_0059ed60();
    break;
  case 7:
    piVar2 = (int *)FUN_0059eca0();
    break;
  case 8:
    piVar2 = (int *)FUN_0059edc0();
    break;
  case 9:
    piVar2 = (int *)FUN_0059ec40();
    break;
  default:
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(s_false_009bfa8c,5);
    FUN_00406880(local_38);
    if (local_20 < 0x10) {
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      piVar2 = (int *)(*pcVar1)();
      return piVar2;
    }
    _free(local_34);
    return extraout_EAX;
  case 0xb:
    piVar2 = (int *)FUN_0059ee20();
  }
  if (param_2 != 0) {
    (**(code **)(*piVar2 + 0xc))(*param_1);
    (**(code **)(*piVar2 + 0x28))(param_1,param_2);
    return piVar2;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_i_pParent____NULL_009bfa94,0x11);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    piVar2 = (int *)(*pcVar1)();
    return piVar2;
  }
  _free(local_18);
  return extraout_EAX_00;
}


// ==== FUN_0059eff0 @ 0x0059eff0 ====

int FUN_0059eff0(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x130) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x130) = *(int *)(param_2 + 0x130) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x26814);
  *(int *)(in_ECX + 0x2680c) = *(int *)(in_ECX + 0x2680c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x134);
    *(undefined4 *)((int)pvVar2 + 300) = *(undefined4 *)(in_ECX + 0x26810);
    *(void **)(in_ECX + 0x26810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x26814) = *(undefined4 *)((int)pvVar2 + 0x128);
  }
  *(undefined4 *)((int)pvVar2 + 0x128) = 0;
  *(int *)((int)pvVar2 + 0x130) = param_1;
  iVar3 = FUN_005aece0();
  return iVar3;
}


// ==== FUN_0059f0c0 @ 0x0059f0c0 ====

undefined4 FUN_0059f0c0(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[0x4c] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 0x4c;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[0x4c];
    }
    (**(code **)*param_2)(0);
    param_2[0x4a] = *(undefined4 *)(in_ECX + 0x26814);
    *(int *)(in_ECX + 0x2680c) = *(int *)(in_ECX + 0x2680c) + -1;
    *(undefined4 **)(in_ECX + 0x26814) = param_2;
  }
  return 0;
}


// ==== FUN_0059f150 @ 0x0059f150 ====

int FUN_0059f150(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x9c) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x9c) = *(int *)(param_2 + 0x9c) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0xa014);
  *(int *)(in_ECX + 0xa00c) = *(int *)(in_ECX + 0xa00c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0xa0);
    *(undefined4 *)((int)pvVar2 + 0x98) = *(undefined4 *)(in_ECX + 0xa010);
    *(void **)(in_ECX + 0xa010) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0xa014) = *(undefined4 *)((int)pvVar2 + 0x94);
  }
  *(undefined4 *)((int)pvVar2 + 0x94) = 0;
  *(int *)((int)pvVar2 + 0x9c) = param_1;
  iVar3 = FUN_005af910();
  return iVar3;
}


// ==== FUN_0059f220 @ 0x0059f220 ====

undefined4 FUN_0059f220(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[0x27] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 0x27;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[0x27];
    }
    (**(code **)*param_2)(0);
    param_2[0x25] = *(undefined4 *)(in_ECX + 0xa014);
    *(int *)(in_ECX + 0xa00c) = *(int *)(in_ECX + 0xa00c) + -1;
    *(undefined4 **)(in_ECX + 0xa014) = param_2;
  }
  return 0;
}


// ==== FUN_0059f2b0 @ 0x0059f2b0 ====

int FUN_0059f2b0(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x1fc) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x1fc) = *(int *)(param_2 + 0x1fc) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x40014);
  *(int *)(in_ECX + 0x4000c) = *(int *)(in_ECX + 0x4000c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x200);
    *(undefined4 *)((int)pvVar2 + 0x1f8) = *(undefined4 *)(in_ECX + 0x40010);
    *(void **)(in_ECX + 0x40010) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x40014) = *(undefined4 *)((int)pvVar2 + 500);
  }
  *(undefined4 *)((int)pvVar2 + 500) = 0;
  *(int *)((int)pvVar2 + 0x1fc) = param_1;
  iVar3 = FUN_005b0e80();
  return iVar3;
}


// ==== FUN_0059f380 @ 0x0059f380 ====

undefined4 FUN_0059f380(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[0x7f] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 0x7f;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[0x7f];
    }
    (**(code **)*param_2)(0);
    param_2[0x7d] = *(undefined4 *)(in_ECX + 0x40014);
    *(int *)(in_ECX + 0x4000c) = *(int *)(in_ECX + 0x4000c) + -1;
    *(undefined4 **)(in_ECX + 0x40014) = param_2;
  }
  return 0;
}


// ==== FUN_0059f410 @ 0x0059f410 ====

int FUN_0059f410(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x170) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x170) = *(int *)(param_2 + 0x170) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x2e814);
  *(int *)(in_ECX + 0x2e80c) = *(int *)(in_ECX + 0x2e80c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x174);
    *(undefined4 *)((int)pvVar2 + 0x16c) = *(undefined4 *)(in_ECX + 0x2e810);
    *(void **)(in_ECX + 0x2e810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x2e814) = *(undefined4 *)((int)pvVar2 + 0x168);
  }
  *(undefined4 *)((int)pvVar2 + 0x168) = 0;
  *(int *)((int)pvVar2 + 0x170) = param_1;
  iVar3 = FUN_005b3310();
  return iVar3;
}


// ==== FUN_0059f4e0 @ 0x0059f4e0 ====

undefined4 FUN_0059f4e0(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[0x5c] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 0x5c;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[0x5c];
    }
    (**(code **)*param_2)(0);
    param_2[0x5a] = *(undefined4 *)(in_ECX + 0x2e814);
    *(int *)(in_ECX + 0x2e80c) = *(int *)(in_ECX + 0x2e80c) + -1;
    *(undefined4 **)(in_ECX + 0x2e814) = param_2;
  }
  return 0;
}


// ==== FUN_0059f570 @ 0x0059f570 ====

int FUN_0059f570(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 200) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 200) = *(int *)(param_2 + 200) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x19814);
  *(int *)(in_ECX + 0x1980c) = *(int *)(in_ECX + 0x1980c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0xcc);
    *(undefined4 *)((int)pvVar2 + 0xc4) = *(undefined4 *)(in_ECX + 0x19810);
    *(void **)(in_ECX + 0x19810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x19814) = *(undefined4 *)((int)pvVar2 + 0xc0);
  }
  *(undefined4 *)((int)pvVar2 + 0xc0) = 0;
  *(int *)((int)pvVar2 + 200) = param_1;
  iVar3 = FUN_005b3e90();
  return iVar3;
}


// ==== FUN_0059f640 @ 0x0059f640 ====

undefined4 FUN_0059f640(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[0x32] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 0x32;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[0x32];
    }
    (**(code **)*param_2)(0);
    param_2[0x30] = *(undefined4 *)(in_ECX + 0x19814);
    *(int *)(in_ECX + 0x1980c) = *(int *)(in_ECX + 0x1980c) + -1;
    *(undefined4 **)(in_ECX + 0x19814) = param_2;
  }
  return 0;
}


// ==== FUN_0059f6d0 @ 0x0059f6d0 ====

int FUN_0059f6d0(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x224) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x224) = *(int *)(param_2 + 0x224) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x45014);
  *(int *)(in_ECX + 0x4500c) = *(int *)(in_ECX + 0x4500c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x228);
    *(undefined4 *)((int)pvVar2 + 0x220) = *(undefined4 *)(in_ECX + 0x45010);
    *(void **)(in_ECX + 0x45010) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x45014) = *(undefined4 *)((int)pvVar2 + 0x21c);
  }
  *(undefined4 *)((int)pvVar2 + 0x21c) = 0;
  *(int *)((int)pvVar2 + 0x224) = param_1;
  iVar3 = FUN_005b50e0();
  return iVar3;
}


// ==== FUN_0059f7a0 @ 0x0059f7a0 ====

undefined4 FUN_0059f7a0(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[0x89] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 0x89;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[0x89];
    }
    (**(code **)*param_2)(0);
    param_2[0x87] = *(undefined4 *)(in_ECX + 0x45014);
    *(int *)(in_ECX + 0x4500c) = *(int *)(in_ECX + 0x4500c) + -1;
    *(undefined4 **)(in_ECX + 0x45014) = param_2;
  }
  return 0;
}


// ==== FUN_0059f830 @ 0x0059f830 ====

int FUN_0059f830(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x9c) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x9c) = *(int *)(param_2 + 0x9c) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x5014);
  *(int *)(in_ECX + 0x500c) = *(int *)(in_ECX + 0x500c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0xa0);
    *(undefined4 *)((int)pvVar2 + 0x98) = *(undefined4 *)(in_ECX + 0x5010);
    *(void **)(in_ECX + 0x5010) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x5014) = *(undefined4 *)((int)pvVar2 + 0x94);
  }
  *(undefined4 *)((int)pvVar2 + 0x94) = 0;
  *(int *)((int)pvVar2 + 0x9c) = param_1;
  iVar3 = FUN_005b6710();
  return iVar3;
}


// ==== FUN_0059f900 @ 0x0059f900 ====

undefined4 FUN_0059f900(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[0x27] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 0x27;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[0x27];
    }
    (**(code **)*param_2)(0);
    param_2[0x25] = *(undefined4 *)(in_ECX + 0x5014);
    *(int *)(in_ECX + 0x500c) = *(int *)(in_ECX + 0x500c) + -1;
    *(undefined4 **)(in_ECX + 0x5014) = param_2;
  }
  return 0;
}


// ==== FUN_0059f990 @ 0x0059f990 ====

int FUN_0059f990(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0xa4) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0xa4) = *(int *)(param_2 + 0xa4) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x5414);
  *(int *)(in_ECX + 0x540c) = *(int *)(in_ECX + 0x540c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0xa8);
    *(undefined4 *)((int)pvVar2 + 0xa0) = *(undefined4 *)(in_ECX + 0x5410);
    *(void **)(in_ECX + 0x5410) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x5414) = *(undefined4 *)((int)pvVar2 + 0x9c);
  }
  *(undefined4 *)((int)pvVar2 + 0x9c) = 0;
  *(int *)((int)pvVar2 + 0xa4) = param_1;
  iVar3 = FUN_005b6c40();
  return iVar3;
}


// ==== FUN_0059fa60 @ 0x0059fa60 ====

undefined4 FUN_0059fa60(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[0x29] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 0x29;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[0x29];
    }
    (**(code **)*param_2)(0);
    param_2[0x27] = *(undefined4 *)(in_ECX + 0x5414);
    *(int *)(in_ECX + 0x540c) = *(int *)(in_ECX + 0x540c) + -1;
    *(undefined4 **)(in_ECX + 0x5414) = param_2;
  }
  return 0;
}


// ==== FUN_0059faf0 @ 0x0059faf0 ====

int FUN_0059faf0(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x1b0) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x1b0) = *(int *)(param_2 + 0x1b0) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x1b54);
  *(int *)(in_ECX + 0x1b4c) = *(int *)(in_ECX + 0x1b4c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x1b4);
    *(undefined4 *)((int)pvVar2 + 0x1ac) = *(undefined4 *)(in_ECX + 0x1b50);
    *(void **)(in_ECX + 0x1b50) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1b54) = *(undefined4 *)((int)pvVar2 + 0x1a8);
  }
  *(undefined4 *)((int)pvVar2 + 0x1a8) = 0;
  *(int *)((int)pvVar2 + 0x1b0) = param_1;
  iVar3 = FUN_005b81f0();
  return iVar3;
}


// ==== FUN_0059fbc0 @ 0x0059fbc0 ====

undefined4 FUN_0059fbc0(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[0x6c] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 0x6c;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[0x6c];
    }
    (**(code **)*param_2)(0);
    param_2[0x6a] = *(undefined4 *)(in_ECX + 0x1b54);
    *(int *)(in_ECX + 0x1b4c) = *(int *)(in_ECX + 0x1b4c) + -1;
    *(undefined4 **)(in_ECX + 0x1b54) = param_2;
  }
  return 0;
}


// ==== FUN_0059fc50 @ 0x0059fc50 ====

int FUN_0059fc50(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0xac) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0xac) = *(int *)(param_2 + 0xac) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x5814);
  *(int *)(in_ECX + 0x580c) = *(int *)(in_ECX + 0x580c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0xb0);
    *(undefined4 *)((int)pvVar2 + 0xa8) = *(undefined4 *)(in_ECX + 0x5810);
    *(void **)(in_ECX + 0x5810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x5814) = *(undefined4 *)((int)pvVar2 + 0xa4);
  }
  *(undefined4 *)((int)pvVar2 + 0xa4) = 0;
  *(int *)((int)pvVar2 + 0xac) = param_1;
  iVar3 = FUN_005b8cd0();
  return iVar3;
}


// ==== FUN_0059fd20 @ 0x0059fd20 ====

undefined4 FUN_0059fd20(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[0x2b] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0c98,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 0x2b;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[0x2b];
    }
    (**(code **)*param_2)(0);
    param_2[0x29] = *(undefined4 *)(in_ECX + 0x5814);
    *(int *)(in_ECX + 0x580c) = *(int *)(in_ECX + 0x580c) + -1;
    *(undefined4 **)(in_ECX + 0x5814) = param_2;
  }
  return 0;
}


// ==== FUN_0059fdb0 @ 0x0059fdb0 ====

void FUN_0059fdb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0059fdd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059fdd0 @ 0x0059fdd0 ====

void FUN_0059fdd0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c0b98;
  if (in_ECX[0x9a03] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009bfbb0,
                         s_d__usa_24_0_1_2__develop_module__009bfb48,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x4e;
  iVar3 = 0x200;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009bfc30,
                           s_d__usa_24_0_1_2__develop_module__009bfbc8,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x4d;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x9a04];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c0b48;
    *in_ECX = &PTR_FUN_009c0a58;
    return;
  }
  if (*(int *)((int)_Memory + 0x130) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009bfcb0,
                         s_d__usa_24_0_1_2__develop_module__009bfc48,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_0059fec0 @ 0x0059fec0 ====

void FUN_0059fec0(byte param_1)

{
  void *in_ECX;
  
  FUN_0059fee0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059fee0 @ 0x0059fee0 ====

void FUN_0059fee0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c0bb0;
  if (in_ECX[0x2803] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009bfd30,
                         s_d__usa_24_0_1_2__develop_module__009bfcc8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x29;
  iVar3 = 0x100;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009bfdb0,
                           s_d__usa_24_0_1_2__develop_module__009bfd48,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x28;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x2804];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c0b50;
    *in_ECX = &PTR_FUN_009c0a70;
    return;
  }
  if (*(int *)((int)_Memory + 0x9c) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009bfe30,
                         s_d__usa_24_0_1_2__develop_module__009bfdc8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_0059ffd0 @ 0x0059ffd0 ====

void FUN_0059ffd0(byte param_1)

{
  void *in_ECX;
  
  FUN_0059fff0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0059fff0 @ 0x0059fff0 ====

void FUN_0059fff0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c0bc8;
  if (in_ECX[0x10003] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009bfeb0,
                         s_d__usa_24_0_1_2__develop_module__009bfe48,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x81;
  iVar3 = 0x200;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009bff30,
                           s_d__usa_24_0_1_2__develop_module__009bfec8,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x80;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x10004];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c0b58;
    *in_ECX = &PTR_FUN_009c0a88;
    return;
  }
  if (*(int *)((int)_Memory + 0x1fc) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009bffb0,
                         s_d__usa_24_0_1_2__develop_module__009bff48,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


