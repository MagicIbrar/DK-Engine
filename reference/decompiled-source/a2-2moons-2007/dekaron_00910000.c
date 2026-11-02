// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x910000-0x91ffff

// ==== FUN_009100cd @ 0x009100cd ====

void FUN_009100cd(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  
  iVar2 = param_1;
  uVar1 = *(uint *)(param_1 + 0x58);
  if ((uVar1 & 1) == 0) {
    pcVar6 = s_Missing_IHDR_before_PLTE_00a29218;
LAB_009100fa:
    FUN_008ee0f5(param_1,pcVar6);
LAB_00910100:
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 2;
    if (param_3 % 3 != 0) {
      pcVar6 = s_Invalid_palette_chunk_00a291d0;
      if (*(char *)(param_1 + 0x116) != '\x03') goto LAB_00910120;
      FUN_008ee0f5(param_1,s_Invalid_palette_chunk_00a291d0);
    }
    iVar3 = (int)param_3 / 3;
    iVar4 = FUN_008ee1e3(param_1,iVar3,3);
    *(byte *)(param_1 + 0x5d) = *(byte *)(param_1 + 0x5d) | 0x10;
    if (0 < iVar3) {
      puVar5 = (undefined1 *)(iVar4 + 2);
      param_1 = iVar3;
      do {
        FUN_0090f568(iVar2,&param_3,3);
        puVar5[-2] = (undefined1)param_3;
        puVar5[-1] = param_3._1_1_;
        *puVar5 = param_3._2_1_;
        puVar5 = puVar5 + 3;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
    FUN_0090fe4c(iVar2,0);
    *(int *)(iVar2 + 0x104) = iVar4;
    *(short *)(iVar2 + 0x108) = (short)iVar3;
    FUN_008eeb51(iVar2,param_2,iVar4,iVar3);
    if ((((*(char *)(iVar2 + 0x116) == '\x03') && (param_2 != 0)) &&
        ((*(byte *)(param_2 + 8) & 0x10) != 0)) &&
       (*(ushort *)(iVar2 + 0x108) < *(ushort *)(iVar2 + 0x10a))) {
      FUN_008ee116(iVar2,s_Truncating_incorrect_tRNS_chunk_l_00a291a8);
      *(ushort *)(iVar2 + 0x10a) = *(ushort *)(iVar2 + 0x108);
    }
  }
  else {
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 2) != 0) {
        pcVar6 = s_Duplicate_PLTE_chunk_00a291e8;
        goto LAB_009100fa;
      }
      goto LAB_00910100;
    }
    pcVar6 = s_Invalid_PLTE_after_IDAT_00a29200;
LAB_00910120:
    FUN_008ee116(param_1,pcVar6);
    FUN_0090fe4c(param_1,param_3);
  }
  return;
}


// ==== FUN_009101e8 @ 0x009101e8 ====

void FUN_009101e8(int param_1,int param_2,int param_3)

{
  if ((((*(uint *)(param_1 + 0x58) & 1) == 0) || ((*(uint *)(param_1 + 0x58) & 4) == 0)) &&
     (FUN_008ee0f5(param_1,s_No_image_in_file_00a29250), param_2 == 0)) {
    return;
  }
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x18;
  if (param_3 != 0) {
    FUN_008ee116(param_1,s_Incorrect_IEND_chunk_length_00a29234);
  }
  FUN_0090fe4c(param_1,param_3);
  return;
}


// ==== FUN_00910230 @ 0x00910230 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00910230(int param_1,int param_2,int param_3)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  iVar4 = param_2;
  iVar3 = param_1;
  uVar1 = *(uint *)(param_1 + 0x58);
  if ((uVar1 & 1) == 0) {
    FUN_008ee0f5(param_1,s_Missing_IHDR_before_gAMA_00a29314);
  }
  else {
    if ((uVar1 & 4) != 0) {
      pcVar6 = s_Invalid_gAMA_after_IDAT_00a292e0;
      goto LAB_00910260;
    }
    if ((uVar1 & 2) == 0) {
      if (((param_2 != 0) && ((*(uint *)(param_2 + 8) & 1) != 0)) &&
         ((*(uint *)(param_2 + 8) & 0x800) == 0)) {
        pcVar6 = s__Duplicate_gAMA_chunk_00a292af + 1;
        goto LAB_00910260;
      }
    }
    else {
      FUN_008ee116(param_1,s_Out_of_place_gAMA_chunk_00a292c8);
    }
  }
  if (param_3 == 4) {
    FUN_0090f568(iVar3,&param_1,4);
    iVar5 = FUN_0090fe4c(iVar3,0);
    if (iVar5 != 0) {
      return;
    }
    param_3 = FUN_0090f524();
    if (param_3 == 0) {
      return;
    }
    if ((*(uint *)(iVar4 + 8) & 0x800) != 0) {
      fVar2 = (float)param_3;
      if (param_3 < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      if ((float)_DAT_00a292a0 < ABS(fVar2 - (float)_DAT_00a292a8)) {
        FUN_008ee116(iVar3,s_Ignoring_incorrect_gAMA_value_wh_00a29264);
        return;
      }
    }
    fVar2 = (float)param_3;
    if (param_3 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar2 = fVar2 * _DAT_00a1694c;
    *(float *)(iVar3 + 0x130) = fVar2;
    FUN_008eea8e(iVar3,iVar4,(double)fVar2);
    return;
  }
  pcVar6 = s_Incorrect_gAMA_chunk_length_00a292f8;
LAB_00910260:
  FUN_008ee116(iVar3,pcVar6);
  FUN_0090fe4c(iVar3,param_3);
  return;
}


// ==== FUN_00910333 @ 0x00910333 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00910333(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  uVar2 = param_1;
  uVar1 = *(uint *)(param_1 + 0x58);
  if ((uVar1 & 1) == 0) {
    FUN_008ee0f5(param_1,s_Missing_IHDR_before_sRGB_00a293a8);
  }
  else {
    if ((uVar1 & 4) != 0) {
      pcVar4 = s_Invalid_sRGB_after_IDAT_00a29374;
      goto LAB_00910359;
    }
    if ((uVar1 & 2) == 0) {
      if ((param_2 != 0) && ((*(byte *)(param_2 + 9) & 8) != 0)) {
        pcVar4 = s_Duplicate_sRGB_chunk_00a29344;
        goto LAB_00910359;
      }
    }
    else {
      FUN_008ee116(param_1,s_Out_of_place_sRGB_chunk_00a2935c);
    }
  }
  if (param_3 == 1) {
    FUN_0090f568(uVar2,(int)&param_1 + 3,1);
    iVar3 = FUN_0090fe4c(uVar2,0);
    if (iVar3 != 0) {
      return;
    }
    uVar1 = param_1 >> 0x18;
    if (3 < uVar1) {
      FUN_008ee116(uVar2,s_Unknown_sRGB_intent_00a29330);
      return;
    }
    if (((*(byte *)(param_2 + 8) & 1) != 0) &&
       ((float)_DAT_00a292a0 <
        ABS((*(float *)(uVar2 + 0x130) * DAT_009b0e8c + (float)_DAT_00a011c0) - (float)_DAT_00a292a8
           ))) {
      FUN_008ee116(uVar2,s_Ignoring_incorrect_gAMA_value_wh_00a29264);
    }
    FUN_008eeb99(uVar2,param_2,uVar1);
    return;
  }
  pcVar4 = s_Incorrect_sRGB_chunk_length_00a2938c;
LAB_00910359:
  FUN_008ee116(uVar2,pcVar4);
  FUN_0090fe4c(uVar2,param_3);
  return;
}


// ==== FUN_00910417 @ 0x00910417 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00910417(int param_1,int param_2,uint param_3)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined1 local_10 [2];
  undefined1 local_e [2];
  undefined1 local_c [4];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  if ((*(uint *)(param_1 + 0x58) & 1) == 0) {
    FUN_008ee0f5(param_1,s_Missing_IHDR_before_tRNS_00a29470);
  }
  else {
    if ((*(uint *)(param_1 + 0x58) & 4) != 0) {
      pcVar5 = s_Invalid_tRNS_after_IDAT_00a29424;
LAB_00910493:
      FUN_008ee116(param_1,pcVar5);
      FUN_0090fe4c(param_1,param_3);
      return;
    }
    if ((param_2 != 0) && ((*(byte *)(param_2 + 8) & 0x10) != 0)) {
      pcVar5 = s_Duplicate_tRNS_chunk_00a2940c;
      goto LAB_00910493;
    }
  }
  cVar1 = *(char *)(param_1 + 0x116);
  if (cVar1 == '\x03') {
    if ((*(byte *)(param_1 + 0x58) & 2) == 0) {
      FUN_008ee116(param_1,s_Missing_PLTE_before_tRNS_00a29454);
LAB_00910464:
      if (param_3 != 0) {
        uVar3 = FUN_0090c9a9(param_1,param_3);
        *(byte *)(param_1 + 0x5d) = *(byte *)(param_1 + 0x5d) | 0x20;
        *(undefined4 *)(param_1 + 0x15c) = uVar3;
        FUN_0090f568(param_1,uVar3,param_3);
        *(short *)(param_1 + 0x10a) = (short)param_3;
        goto LAB_0091056f;
      }
      FUN_008ee116(param_1,s_Zero_length_tRNS_chunk_00a2943c);
    }
    else {
      if (param_3 <= *(ushort *)(param_1 + 0x108)) goto LAB_00910464;
      FUN_008ee116(param_1,s_Incorrect_tRNS_chunk_length_00a293f0);
    }
LAB_009105a7:
    FUN_0090fe4c(param_1,param_3);
  }
  else {
    if (cVar1 == '\x02') {
      if (param_3 != 6) {
LAB_00910543:
        pcVar5 = s_Incorrect_tRNS_chunk_length_00a293f0;
LAB_0091059e:
        FUN_008ee116(param_1,pcVar5);
        goto LAB_009105a7;
      }
      FUN_0090f568(param_1,local_10,6);
      *(undefined2 *)(param_1 + 0x10a) = 1;
      uVar2 = FUN_0090f54e(local_10);
      *(undefined2 *)(param_1 + 0x162) = uVar2;
      uVar2 = FUN_0090f54e(local_e);
      *(undefined2 *)(param_1 + 0x164) = uVar2;
      uVar2 = FUN_0090f54e(local_c);
      *(undefined2 *)(param_1 + 0x166) = uVar2;
    }
    else {
      if (cVar1 != '\0') {
        pcVar5 = s_tRNS_chunk_not_allowed_with_alph_00a293c4;
        goto LAB_0091059e;
      }
      if (param_3 != 2) goto LAB_00910543;
      FUN_0090f568(param_1,local_10,2);
      *(undefined2 *)(param_1 + 0x10a) = 1;
      uVar2 = FUN_0090f54e(local_10);
      *(undefined2 *)(param_1 + 0x168) = uVar2;
    }
LAB_0091056f:
    iVar4 = FUN_0090fe4c(param_1,0);
    if (iVar4 == 0) {
      FUN_008eebd2(param_1,param_2,*(undefined4 *)(param_1 + 0x15c),*(undefined2 *)(param_1 + 0x10a)
                   ,param_1 + 0x160);
    }
  }
  return;
}


// ==== FUN_009105bc @ 0x009105bc ====

void FUN_009105bc(int param_1,int param_2,undefined4 param_3)

{
  FUN_0090f5df(param_1,(byte *)(param_1 + 0x10c));
  if (((*(byte *)(param_1 + 0x10c) & 0x20) == 0) &&
     (FUN_008ee131(param_1,s_unknown_critical_chunk_00a2948c), param_2 == 0)) {
    return;
  }
  if ((*(uint *)(param_1 + 0x58) & 4) != 0) {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 8;
  }
  FUN_0090fe4c(param_1,param_3);
  return;
}


// ==== FUN_00910605 @ 0x00910605 ====

void FUN_00910605(int param_1)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  undefined1 local_8 [4];
  
  iVar3 = param_1;
  puVar1 = (uint *)(param_1 + 0xd4);
  *puVar1 = *puVar1 + 1;
  if (*(uint *)(param_1 + 0xc0) <= *puVar1) {
    if (*(char *)(param_1 + 0x113) != '\0') {
      *puVar1 = 0;
      FUN_0090ca28(param_1,*(undefined4 *)(param_1 + 0xd8),0,*(int *)(param_1 + 200) + 1);
      do {
        *(char *)(iVar3 + 0x114) = *(char *)(iVar3 + 0x114) + '\x01';
        bVar2 = *(byte *)(iVar3 + 0x114);
        if (6 < bVar2) goto LAB_009106d9;
        iVar7 = (uint)bVar2 * 4;
        uVar4 = ((*(int *)(iVar3 + 0xb8) - *(int *)(&DAT_00a28fd4 + iVar7)) + -1 +
                *(uint *)(&DAT_00a28ff0 + iVar7)) / *(uint *)(&DAT_00a28ff0 + iVar7);
        *(uint *)(iVar3 + 0xd0) = uVar4;
        *(uint *)(iVar3 + 0xcc) = (*(byte *)(iVar3 + 0x119) * uVar4 + 7 >> 3) + 1;
      } while (((*(byte *)(iVar3 + 0x60) & 2) == 0) &&
              (*(uint *)(iVar3 + 0xc0) =
                    ((*(int *)(iVar3 + 0xbc) - *(int *)(&DAT_00a2900c + iVar7)) + -1 +
                    *(uint *)(&DAT_00a29028 + iVar7)) / *(uint *)(&DAT_00a29028 + iVar7),
              *(int *)(iVar3 + 0xd0) == 0));
      if (bVar2 < 7) {
        return;
      }
    }
LAB_009106d9:
    if ((*(byte *)(iVar3 + 0x5c) & 0x20) == 0) {
      *(int *)(iVar3 + 0x70) = (int)&param_1 + 3;
      *(undefined4 *)(iVar3 + 0x74) = 1;
      while( true ) {
        if (*(int *)(iVar3 + 0x68) == 0) {
          if (*(int *)(iVar3 + 0xfc) == 0) {
            do {
              FUN_0090fe4c(iVar3,0);
              FUN_008f0db9(iVar3,local_8,4);
              uVar5 = FUN_0090f524(local_8);
              *(undefined4 *)(iVar3 + 0xfc) = uVar5;
              FUN_008ee244(iVar3);
              FUN_0090f568(iVar3,(int *)(iVar3 + 0x10c),4);
              if (*(int *)(iVar3 + 0x10c) != DAT_00a29044) {
                FUN_008ee0f5(iVar3,s_Not_enough_image_data_00a24e0c);
              }
            } while (*(int *)(iVar3 + 0xfc) == 0);
          }
          *(uint *)(iVar3 + 0x68) = *(uint *)(iVar3 + 0xa0);
          *(undefined4 *)(iVar3 + 100) = *(undefined4 *)(iVar3 + 0x9c);
          if (*(uint *)(iVar3 + 0xfc) < *(uint *)(iVar3 + 0xa0)) {
            *(uint *)(iVar3 + 0x68) = *(uint *)(iVar3 + 0xfc);
          }
          FUN_0090f568(iVar3,*(undefined4 *)(iVar3 + 0x9c),*(undefined4 *)(iVar3 + 0x68));
          *(int *)(iVar3 + 0xfc) = *(int *)(iVar3 + 0xfc) - *(int *)(iVar3 + 0x68);
        }
        iVar7 = FUN_0090f1b1((undefined4 *)(iVar3 + 100),1);
        if (iVar7 == 1) break;
        if (iVar7 != 0) {
          pcVar6 = *(char **)(iVar3 + 0x7c);
          if (pcVar6 == (char *)0x0) {
            pcVar6 = s_Decompression_Error_00a294bc;
          }
          FUN_008ee0f5(iVar3,pcVar6);
        }
        if (*(int *)(iVar3 + 0x74) == 0) {
          FUN_008ee0f5(iVar3,s_Extra_compressed_data_00a24de0);
        }
      }
      if (((*(int *)(iVar3 + 0x74) == 0) || (*(int *)(iVar3 + 0x68) != 0)) ||
         (*(int *)(iVar3 + 0xfc) != 0)) {
        FUN_008ee0f5(iVar3,s_Extra_compressed_data_00a24de0);
      }
      *(uint *)(iVar3 + 0x58) = *(uint *)(iVar3 + 0x58) | 8;
      *(uint *)(iVar3 + 0x5c) = *(uint *)(iVar3 + 0x5c) | 0x20;
      *(undefined4 *)(iVar3 + 0x74) = 0;
    }
    if ((*(int *)(iVar3 + 0xfc) != 0) || (*(int *)(iVar3 + 0x68) != 0)) {
      FUN_008ee0f5(iVar3,s_Extra_compression_data_00a294a4);
    }
    FUN_0090f032(iVar3 + 100);
    *(uint *)(iVar3 + 0x58) = *(uint *)(iVar3 + 0x58) | 8;
  }
  return;
}


// ==== FUN_0091081f @ 0x0091081f ====

void FUN_0091081f(int param_1,int param_2,short *param_3,int param_4,int *param_5,int *param_6)

{
  short *psVar1;
  ushort uVar2;
  ushort uVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  
  psVar4 = param_3;
  psVar1 = param_3 + 5;
  if (*psVar1 == 0) {
    if (*(short *)(param_2 + 4) == 0) {
      uVar6 = (uint)(ushort)param_3[3];
      uVar2 = param_3[2];
    }
    else {
      if (*param_3 == 3) {
        uVar3 = param_3[2];
        uVar2 = param_3[3];
      }
      else {
        uVar3 = param_3[3];
        uVar2 = param_3[2];
      }
      uVar6 = (int)(uVar3 + 3) >> 2;
    }
    *param_5 = *param_5 + uVar6 * uVar2 * param_4;
    *param_6 = *param_6 + (uint)(ushort)param_3[3] * (uint)(ushort)param_3[2] * param_4;
  }
  else {
    piVar7 = (int *)(param_3 + 6);
    param_3 = (short *)0x0;
    if (*psVar1 != 0) {
      piVar7 = (int *)(*piVar7 + *(int *)(param_1 + 8) + 4);
      do {
        if (*piVar7 != 0) {
          iVar5 = *(int *)(param_1 + 8) + *piVar7;
          FUN_0091081f(param_1,param_2,iVar5,(uint)*(ushort *)(iVar5 + 8) * param_4,param_5,param_6)
          ;
        }
        param_3 = (short *)((int)param_3 + 1);
        piVar7 = piVar7 + 2;
      } while (param_3 < (uint)(ushort)psVar4[5]);
    }
  }
  return;
}


// ==== FUN_009108da @ 0x009108da ====

undefined4 FUN_009108da(uint param_1)

{
  char *in_EAX;
  undefined4 uVar1;
  int unaff_EBX;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = 0;
  bVar4 = param_1 == 0;
  if (param_1 != 0) {
    iVar2 = unaff_EBX - (int)in_EAX;
    do {
      if (in_EAX[iVar2] < *in_EAX) {
        return 0xffffffff;
      }
      if (*in_EAX < in_EAX[iVar2]) goto LAB_00910909;
      uVar3 = uVar3 + 1;
      in_EAX = in_EAX + 1;
    } while (uVar3 < param_1);
    bVar4 = uVar3 == param_1;
  }
  if ((bVar4) && (*(char *)(uVar3 + unaff_EBX) != '\0')) {
LAB_00910909:
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0091091b @ 0x0091091b ====

int FUN_0091091b(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_ECX;
  int iVar3;
  int extraout_EDX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *in_ECX = param_1;
  puVar4 = param_2;
  puVar5 = in_ECX;
  for (iVar3 = 5; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
  }
  piVar1 = in_ECX + 0xd;
  piVar2 = in_ECX + 0xb;
  in_ECX[7] = param_4;
  in_ECX[8] = param_5;
  in_ECX[6] = param_3;
  in_ECX[9] = 0;
  *piVar2 = 0;
  *piVar1 = 0;
  FUN_0091081f(param_1,param_2,param_3,1,piVar2,piVar1);
  *(uint *)(extraout_EDX + 0x28) = (uint)*(ushort *)(param_3 + 8) * *piVar2;
  *(uint *)(extraout_EDX + 0x30) = (uint)*(ushort *)(param_3 + 8) * *piVar1;
  *(undefined4 *)(extraout_EDX + 0x38) = 0;
  *(undefined4 *)(extraout_EDX + 0x3c) = 0;
  *(undefined4 *)(extraout_EDX + 0x40) = 0;
  return extraout_EDX;
}


// ==== FUN_0091098c @ 0x0091098c ====

void FUN_0091098c(void)

{
  void *pvVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(in_ECX + 0x38) == 0) {
    uVar2 = 0;
    if (*(int *)(in_ECX + 0x3c) == 0) {
      _free(*(void **)(in_ECX + 0x40));
      return;
    }
    if (*(short *)(*(int *)(in_ECX + 0x18) + 8) != 0) {
      do {
        pvVar1 = *(void **)(*(int *)(in_ECX + 0x3c) + uVar2 * 4);
        if (pvVar1 != (void *)0x0) {
          FUN_0091098c();
          _free(pvVar1);
          return;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(ushort *)(*(int *)(in_ECX + 0x18) + 8));
    }
    _free(*(void **)(in_ECX + 0x3c));
    return;
  }
  if (*(short *)(*(int *)(in_ECX + 0x18) + 10) != 0) {
    do {
      pvVar1 = *(void **)(*(int *)(in_ECX + 0x38) + uVar2 * 4);
      if (pvVar1 != (void *)0x0) {
        FUN_0091098c();
        _free(pvVar1);
        return;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(ushort *)(*(int *)(in_ECX + 0x18) + 10));
  }
  _free(*(void **)(in_ECX + 0x38));
  return;
}


// ==== FUN_00910a1a @ 0x00910a1a ====

undefined4 FUN_00910a1a(uint param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = param_1;
  param_1 = 0;
  *(int *)(in_ECX + 0x20) = iVar2;
  if (*(short *)(*(int *)(in_ECX + 0x18) + 10) != 0) {
    do {
      FUN_00910a1a(iVar2);
      iVar1 = *(int *)(*(int *)(in_ECX + 0x38) + param_1 * 4);
      param_1 = param_1 + 1;
      iVar2 = iVar2 + ((-(uint)(*(short *)(iVar1 + 8) != 0) & 3) + 1) *
                      (uint)*(ushort *)(*(int *)(iVar1 + 0x18) + 8) * *(int *)(iVar1 + 0x2c) * 4;
    } while (param_1 < *(ushort *)(*(int *)(in_ECX + 0x18) + 10));
  }
  return 0;
}


// ==== FUN_00910a86 @ 0x00910a86 ====

undefined4 FUN_00910a86(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (in_ECX[1] == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*in_ECX + 8) + in_ECX[1];
  }
  *param_1 = iVar1;
  param_1[1] = (uint)*(ushort *)(in_ECX + 2);
  param_1[2] = (uint)*(ushort *)((int)in_ECX + 10);
  param_1[3] = (uint)*(ushort *)(in_ECX + 3);
  param_1[4] = (uint)*(ushort *)in_ECX[6];
  param_1[5] = (uint)*(ushort *)(in_ECX[6] + 2);
  param_1[6] = (uint)*(ushort *)(in_ECX[6] + 4);
  param_1[7] = (uint)*(ushort *)(in_ECX[6] + 6);
  param_1[8] = (uint)*(ushort *)(in_ECX[6] + 8);
  param_1[9] = (uint)*(ushort *)(in_ECX[6] + 10);
  param_1[10] = param_1[8] * param_1[6] * param_1[7] * 4;
  if (in_ECX[5] == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*in_ECX + 8) + in_ECX[5];
  }
  param_1[0xb] = iVar1;
  return 0;
}


// ==== FUN_00910b29 @ 0x00910b29 ====

undefined4 FUN_00910b29(uint param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 < *(ushort *)(*(int *)(in_ECX + 0x18) + 10)) {
    uVar1 = *(undefined4 *)(*(int *)(in_ECX + 0x38) + param_1 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00910b4a @ 0x00910b4a ====

int FUN_00910b4a(undefined4 param_1,int param_2)

{
  int iVar1;
  int *in_ECX;
  
  if ((in_ECX[5] == 0) ||
     (iVar1 = (*(code *)in_ECX[7])
                        (param_1,(uint)*(ushort *)((int)in_ECX + 10) + param_2,
                         *(int *)(*in_ECX + 8) + in_ECX[5] +
                         ((-(uint)((short)in_ECX[2] != 0) & 3) + 1) * param_2 * 4,in_ECX[8],
                         (short)in_ECX[3]), -1 < iVar1)) {
    return 0;
  }
  return iVar1;
}


// ==== FUN_00910b96 @ 0x00910b96 ====

undefined4 FUN_00910b96(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  
  *param_3 = 0;
  iVar1 = 4;
  bVar4 = true;
  piVar2 = param_2;
  piVar3 = &DAT_00a52010;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *piVar2 == *piVar3;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    iVar1 = 4;
    bVar4 = true;
    piVar2 = &DAT_00a24f8c;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *param_2 == *piVar2;
      param_2 = param_2 + 1;
      piVar2 = piVar2 + 1;
    } while (bVar4);
    if (!bVar4) {
      return 0x80004002;
    }
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


// ==== FUN_00910bdf @ 0x00910bdf ====

undefined4 FUN_00910bdf(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}


// ==== FUN_00910bf1 @ 0x00910bf1 ====

undefined4 FUN_00910bf1(int param_1,int *param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == (int *)0x0) {
    uVar2 = 0x8876086c;
  }
  else if (((*(uint *)(param_1 + 0xc) < 0x1c) || (puVar1 = *(uint **)(param_1 + 8), *puVar1 < 0x1c))
          || (*(uint *)(param_1 + 0xc) <= puVar1[1])) {
    uVar2 = 0x88760b59;
  }
  else {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    if (puVar1[1] == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(param_1 + 8) + puVar1[1];
    }
    *param_2 = iVar3;
    param_2[1] = puVar1[2];
    param_2[2] = puVar1[3];
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_00910c52 @ 0x00910c52 ====

int FUN_00910c52(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x18) != 0) {
    do {
      iVar1 = FUN_00910b4a(param_2,0);
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0x18));
  }
  return 0;
}


// ==== FUN_00910c85 @ 0x00910c85 ====

void FUN_00910c85(int *param_1,undefined4 param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_5 << 2;
  if (iVar2 != 0) {
    iVar1 = param_3 - (int)param_4;
    do {
      *param_4 = (uint)(*(int *)(iVar1 + (int)param_4) != 0);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00910cc9 @ 0x00910cc9 ====

void FUN_00910cc9(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00910ce7 @ 0x00910ce7 ====

void FUN_00910ce7(int *param_1,undefined4 param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_5 << 2;
  if (iVar2 != 0) {
    iVar1 = param_3 - (int)param_4;
    do {
      *param_4 = (int)ROUND(*(float *)(iVar1 + (int)param_4));
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00910d4d @ 0x00910d4d ====

void FUN_00910d4d(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00910d6b @ 0x00910d6b ====

void FUN_00910d6b(int *param_1,undefined4 param_2,int param_3,float *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_5 << 2;
  if (iVar2 != 0) {
    iVar1 = param_3 - (int)param_4;
    do {
      *param_4 = (float)(*(int *)(iVar1 + (int)param_4) != 0);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00910db5 @ 0x00910db5 ====

void FUN_00910db5(int *param_1,undefined4 param_2,int param_3,float *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_5 << 2;
  if (iVar2 != 0) {
    iVar1 = param_3 - (int)param_4;
    do {
      *param_4 = (float)*(int *)(iVar1 + (int)param_4);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00910df0 @ 0x00910df0 ====

undefined4 FUN_00910df0(int *param_1,int param_2,undefined4 *param_3,float *param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = param_5 << 2;
  if (iVar2 != 0) {
    iVar1 = (int)param_3 - (int)param_4;
    do {
      *param_4 = (float)(*(int *)(iVar1 + (int)param_4) != 0);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = (**(code **)(*param_1 + 0xc))(param_1);
  puVar3 = (undefined4 *)(iVar2 + param_2 * 0x10);
  for (iVar1 = (param_5 & 0xfffffff) << 2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_3;
    param_3 = (undefined4 *)((int)param_3 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  return 0;
}


// ==== FUN_00910e54 @ 0x00910e54 ====

undefined4 FUN_00910e54(int *param_1,int param_2,undefined4 *param_3,float *param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = param_5 << 2;
  if (iVar2 != 0) {
    iVar1 = (int)param_3 - (int)param_4;
    do {
      *param_4 = (float)*(int *)(iVar1 + (int)param_4);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = (**(code **)(*param_1 + 0xc))(param_1);
  puVar3 = (undefined4 *)(iVar2 + param_2 * 0x10);
  for (iVar1 = (param_5 & 0xfffffff) << 2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_3;
    param_3 = (undefined4 *)((int)param_3 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  return 0;
}


// ==== FUN_00910eaa @ 0x00910eaa ====

undefined4
FUN_00910eaa(int *param_1,int param_2,undefined4 *param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = (**(code **)(*param_1 + 0xc))(param_1);
  puVar3 = (undefined4 *)(iVar1 + param_2 * 0x10);
  for (iVar2 = (param_5 & 0xfffffff) << 2; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_3;
    param_3 = (undefined4 *)((int)param_3 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  return 0;
}


// ==== FUN_00910ee7 @ 0x00910ee7 ====

void FUN_00910ee7(byte param_1)

{
  void *in_ECX;
  
  FUN_0091098c();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00910f08 @ 0x00910f08 ====

void FUN_00910f08(void)

{
  undefined4 *in_ECX;
  uint uVar1;
  
  *in_ECX = &PTR_FUN_00a294d0;
  if (in_ECX[5] == 0) {
    _free((void *)in_ECX[2]);
    return;
  }
  uVar1 = 0;
  if (in_ECX[6] != 0) {
    do {
      if (*(int *)(in_ECX[5] + uVar1 * 4) != 0) {
        FUN_00910ee7(1);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)in_ECX[6]);
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_00910f56 @ 0x00910f56 ====

void FUN_00910f56(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(*param_1 + 0x188))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00910f74 @ 0x00910f74 ====

void FUN_00910f74(int *param_1,undefined4 param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_5 != 0) {
    iVar1 = param_3 - (int)param_4;
    iVar2 = param_5;
    do {
      *param_4 = (uint)(*(int *)(iVar1 + (int)param_4) != 0);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x188))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00910fb5 @ 0x00910fb5 ====

void FUN_00910fb5(int *param_1,undefined4 param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_5 != 0) {
    iVar1 = param_3 - (int)param_4;
    iVar2 = param_5;
    do {
      *param_4 = (uint)(*(float *)(iVar1 + (int)param_4) != DAT_0099cdc8);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x188))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00911007 @ 0x00911007 ====

void FUN_00911007(int *param_1,undefined4 param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_5 << 2;
  if (iVar2 != 0) {
    iVar1 = param_3 - (int)param_4;
    do {
      *param_4 = (uint)(*(int *)(iVar1 + (int)param_4) != 0);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x180))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_0091104b @ 0x0091104b ====

void FUN_0091104b(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(*param_1 + 0x180))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00911069 @ 0x00911069 ====

void FUN_00911069(int *param_1,undefined4 param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_5 << 2;
  if (iVar2 != 0) {
    iVar1 = param_3 - (int)param_4;
    do {
      *param_4 = (int)ROUND(*(float *)(iVar1 + (int)param_4));
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x180))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_009110cf @ 0x009110cf ====

void FUN_009110cf(int *param_1,undefined4 param_2,int param_3,float *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_5 << 2;
  if (iVar2 != 0) {
    iVar1 = param_3 - (int)param_4;
    do {
      *param_4 = (float)(*(int *)(iVar1 + (int)param_4) != 0);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x178))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00911119 @ 0x00911119 ====

void FUN_00911119(int *param_1,undefined4 param_2,int param_3,float *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_5 << 2;
  if (iVar2 != 0) {
    iVar1 = param_3 - (int)param_4;
    do {
      *param_4 = (float)*(int *)(iVar1 + (int)param_4);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x178))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00911154 @ 0x00911154 ====

void FUN_00911154(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(*param_1 + 0x178))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00911172 @ 0x00911172 ====

void FUN_00911172(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(*param_1 + 0x1c4))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00911190 @ 0x00911190 ====

void FUN_00911190(int *param_1,undefined4 param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_5 != 0) {
    iVar1 = param_3 - (int)param_4;
    iVar2 = param_5;
    do {
      *param_4 = (uint)(*(int *)(iVar1 + (int)param_4) != 0);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x1c4))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_009111d1 @ 0x009111d1 ====

void FUN_009111d1(int *param_1,undefined4 param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_5 != 0) {
    iVar1 = param_3 - (int)param_4;
    iVar2 = param_5;
    do {
      *param_4 = (uint)(*(float *)(iVar1 + (int)param_4) != DAT_0099cdc8);
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(*param_1 + 0x1c4))(param_1,param_2,param_3,param_5);
  return;
}


// ==== FUN_00911223 @ 0x00911223 ====

int FUN_00911223(uint param_1,undefined4 param_2,undefined4 *param_3,uint param_4,int param_5)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 *puVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  bool bVar14;
  bool bVar15;
  int local_18;
  undefined *local_14;
  undefined4 *local_10;
  undefined4 *local_8;
  
  iVar10 = param_1;
  puVar4 = *(undefined4 **)(param_1 + 0x20);
  psVar5 = *(short **)(param_1 + 0x18);
  local_8 = param_3;
  sVar1 = *psVar5;
  if (sVar1 == 0) {
    uVar11 = (uint)(ushort)psVar5[4];
    bVar14 = param_4 < uVar11;
    bVar15 = param_4 == uVar11;
  }
  else {
    if (sVar1 == 1) {
      uVar11 = (uint)(ushort)psVar5[3];
    }
    else {
      if (sVar1 != 2) {
        if (sVar1 != 3) {
          if (sVar1 != 5) {
            return -0x7fffbfff;
          }
          param_4 = param_4 / *(uint *)(param_1 + 0x34);
          if ((ushort)psVar5[4] < param_4) {
            param_4 = (uint)(ushort)psVar5[4];
          }
          param_1 = 0;
          if (param_4 == 0) {
            return 0;
          }
          do {
            param_3 = (undefined4 *)0x0;
            if (psVar5[5] != 0) {
              do {
                iVar6 = *(int *)(*(int *)(iVar10 + 0x38) + (int)param_3 * 4);
                iVar7 = FUN_00911223(iVar10,param_2,local_8,*(undefined4 *)(iVar6 + 0x30),param_5);
                if (iVar7 < 0) {
                  return iVar7;
                }
                local_8 = local_8 + *(int *)(iVar6 + 0x30);
                param_5 = param_5 + *(int *)(iVar6 + 0x28);
                param_3 = (undefined4 *)((int)param_3 + 1);
              } while (param_3 < (uint)(ushort)psVar5[5]);
            }
            param_1 = param_1 + 1;
          } while (param_1 < param_4);
          return 0;
        }
        uVar11 = (uint)(ushort)psVar5[2];
        param_4 = param_4 / (uVar11 * (ushort)psVar5[3]);
        if ((ushort)psVar5[4] < param_4) {
          param_4 = (uint)(ushort)psVar5[4];
        }
        local_10 = (undefined4 *)0x0;
        puVar9 = puVar4;
        if (param_4 != 0) {
          do {
            local_8 = (undefined4 *)0x0;
            if (psVar5[3] != 0) {
              do {
                uVar8 = 0;
                if (uVar11 != 0) {
                  do {
                    *puVar9 = param_3[(uVar11 * (int)local_10 + uVar8) * (uint)(ushort)psVar5[3] +
                                      (int)local_8];
                    uVar11 = (uint)(ushort)psVar5[2];
                    puVar9 = puVar9 + 1;
                    uVar8 = uVar8 + 1;
                  } while (uVar8 < uVar11);
                }
                local_8 = (undefined4 *)((int)local_8 + 1);
              } while (local_8 < (uint)(ushort)psVar5[3]);
            }
            local_10 = (undefined4 *)((int)local_10 + 1);
          } while (local_10 < param_4);
        }
        local_8 = puVar4;
        goto LAB_009113a9;
      }
      uVar11 = (uint)(ushort)psVar5[3] * (uint)(ushort)psVar5[2];
    }
    param_4 = param_4 / uVar11;
    uVar11 = (uint)(ushort)psVar5[4];
    bVar14 = param_4 < uVar11;
    bVar15 = param_4 == uVar11;
  }
  if (!bVar14 && !bVar15) {
    param_4 = uVar11;
  }
LAB_009113a9:
  if (*(short *)(param_1 + 8) != 0) {
    if (*psVar5 == 3) {
      uVar2 = psVar5[2];
      uVar3 = psVar5[3];
    }
    else {
      uVar2 = psVar5[3];
      uVar3 = psVar5[2];
    }
    uVar11 = (uint)uVar2;
    if ((uVar2 & 3) != 0) {
      local_14 = &DAT_00a2954c;
      if (*(short *)(param_1 + 8) != 1) {
        local_14 = &DAT_00a2953c;
      }
      local_18 = uVar3 * param_4;
      uVar8 = uVar11 + 3 & 0xfffffffc;
      if (local_18 != 0) {
        iVar10 = local_18 * 4 + 4;
        puVar12 = (undefined4 *)(iVar10 * uVar11 + (int)local_8);
        local_10 = (undefined4 *)(iVar10 * uVar8 + (int)puVar4);
        puVar9 = puVar4 + local_18 * uVar8 + uVar11;
        do {
          local_10 = local_10 + -uVar8;
          puVar9 = puVar9 + -uVar8;
          puVar12 = puVar12 + -uVar11;
          if (uVar11 < uVar8) {
            puVar13 = local_10;
            param_3 = (undefined4 *)uVar8;
            do {
              param_3 = (undefined4 *)((int)param_3 - 1);
              puVar13 = puVar13 + -1;
              *puVar13 = *(undefined4 *)(local_14 + ((uint)param_3 & 3) * 4);
            } while (uVar11 < param_3);
          }
          if (uVar11 != 0) {
            puVar13 = puVar9;
            param_3 = puVar12;
            local_8 = (undefined4 *)uVar11;
            do {
              param_3 = param_3 + -1;
              puVar13 = puVar13 + -1;
              local_8 = (undefined4 *)((int)local_8 - 1);
              *puVar13 = *param_3;
            } while (local_8 != (undefined4 *)0x0);
          }
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      local_8 = puVar4;
    }
  }
  param_4 = *(int *)(param_1 + 0x2c) * param_4;
  if (*(ushort *)(param_1 + 0xc) < param_4) {
    param_4 = (uint)*(ushort *)(param_1 + 0xc);
  }
  iVar10 = (**(code **)(param_1 + 0x1c))
                     (param_2,(uint)*(ushort *)(param_1 + 10) + param_5,local_8,puVar4,param_4);
  if (iVar10 < 0) {
    return iVar10;
  }
  return 0;
}


// ==== FUN_009114c2 @ 0x009114c2 ====

int FUN_009114c2(uint param_1,undefined4 param_2,uint *param_3,uint param_4,int param_5)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  uint *puVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  bool bVar14;
  bool bVar15;
  int local_18;
  undefined *local_14;
  uint *local_10;
  uint *local_8;
  
  iVar9 = param_1;
  puVar4 = *(uint **)(param_1 + 0x20);
  psVar5 = *(short **)(param_1 + 0x18);
  local_8 = param_3;
  sVar1 = *psVar5;
  if (sVar1 == 0) {
    uVar11 = (uint)(ushort)psVar5[4];
    bVar14 = param_4 < uVar11;
    bVar15 = param_4 == uVar11;
  }
  else {
    if (sVar1 == 1) {
      uVar11 = (uint)(ushort)psVar5[3];
    }
    else {
      if (sVar1 != 2) {
        if (sVar1 != 3) {
          if (sVar1 != 5) {
            return -0x7fffbfff;
          }
          param_4 = param_4 / *(uint *)(param_1 + 0x34);
          if ((ushort)psVar5[4] < param_4) {
            param_4 = (uint)(ushort)psVar5[4];
          }
          param_1 = 0;
          if (param_4 == 0) {
            return 0;
          }
          do {
            param_3 = (uint *)0x0;
            if (psVar5[5] != 0) {
              do {
                iVar6 = *(int *)(*(int *)(iVar9 + 0x38) + (int)param_3 * 4);
                iVar7 = FUN_009114c2(iVar9,param_2,local_8,*(undefined4 *)(iVar6 + 0x30),param_5);
                if (iVar7 < 0) {
                  return iVar7;
                }
                local_8 = local_8 + *(int *)(iVar6 + 0x30);
                param_5 = param_5 + *(int *)(iVar6 + 0x28);
                param_3 = (uint *)((int)param_3 + 1);
              } while (param_3 < (uint)(ushort)psVar5[5]);
            }
            param_1 = param_1 + 1;
          } while (param_1 < param_4);
          return 0;
        }
        uVar11 = (uint)(ushort)psVar5[2];
        param_4 = param_4 / (uVar11 * (ushort)psVar5[3]);
        if ((ushort)psVar5[4] < param_4) {
          param_4 = (uint)(ushort)psVar5[4];
        }
        local_10 = (uint *)0x0;
        puVar10 = puVar4;
        if (param_4 != 0) {
          do {
            local_8 = (uint *)0x0;
            if (psVar5[3] != 0) {
              do {
                uVar8 = 0;
                if (uVar11 != 0) {
                  do {
                    *puVar10 = param_3[(uVar11 * (int)local_10 + uVar8) * (uint)(ushort)psVar5[3] +
                                       (int)local_8];
                    uVar11 = (uint)(ushort)psVar5[2];
                    puVar10 = puVar10 + 1;
                    uVar8 = uVar8 + 1;
                  } while (uVar8 < uVar11);
                }
                local_8 = (uint *)((int)local_8 + 1);
              } while (local_8 < (uint)(ushort)psVar5[3]);
            }
            local_10 = (uint *)((int)local_10 + 1);
          } while (local_10 < param_4);
        }
        local_8 = puVar4;
        goto LAB_0091164a;
      }
      uVar11 = (uint)(ushort)psVar5[3] * (uint)(ushort)psVar5[2];
    }
    param_4 = param_4 / uVar11;
    uVar11 = (uint)(ushort)psVar5[4];
    bVar14 = param_4 < uVar11;
    bVar15 = param_4 == uVar11;
  }
  if (!bVar14 && !bVar15) {
    param_4 = uVar11;
  }
LAB_0091164a:
  sVar1 = psVar5[1];
  if (sVar1 != 1) {
    iVar9 = *(int *)(param_1 + 0x34) * param_4;
    if (sVar1 != 1) {
      if (sVar1 == 2) {
        if (iVar9 != 0) {
          puVar10 = puVar4;
          do {
            *puVar10 = (uint)(*(int *)((int)puVar10 + ((int)local_8 - (int)puVar4)) != 0);
            puVar10 = puVar10 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
      else if ((sVar1 == 3) && (iVar9 != 0)) {
        puVar10 = puVar4;
        do {
          if (*(int *)(((int)local_8 - (int)puVar4) + (int)puVar10) == 0) {
            uVar11 = 0;
          }
          else {
            uVar11 = 0x3f800000;
          }
          *puVar10 = uVar11;
          puVar10 = puVar10 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
    local_8 = puVar4;
  }
  if (*(short *)(param_1 + 8) != 0) {
    if (*psVar5 == 3) {
      uVar2 = psVar5[2];
      uVar3 = psVar5[3];
    }
    else {
      uVar2 = psVar5[3];
      uVar3 = psVar5[2];
    }
    uVar11 = (uint)uVar2;
    if ((uVar2 & 3) != 0) {
      local_14 = &DAT_00a2954c;
      if (*(short *)(param_1 + 8) != 1) {
        local_14 = &DAT_00a2953c;
      }
      local_18 = uVar3 * param_4;
      uVar8 = uVar11 + 3 & 0xfffffffc;
      if (local_18 != 0) {
        iVar9 = local_18 * 4 + 4;
        puVar12 = (uint *)(iVar9 * uVar11 + (int)local_8);
        local_10 = (uint *)(iVar9 * uVar8 + (int)puVar4);
        puVar10 = puVar4 + local_18 * uVar8 + uVar11;
        do {
          local_10 = local_10 + -uVar8;
          puVar10 = puVar10 + -uVar8;
          puVar12 = puVar12 + -uVar11;
          if (uVar11 < uVar8) {
            puVar13 = local_10;
            param_3 = (uint *)uVar8;
            do {
              param_3 = (uint *)((int)param_3 - 1);
              puVar13 = puVar13 + -1;
              *puVar13 = *(uint *)(local_14 + ((uint)param_3 & 3) * 4);
            } while (uVar11 < param_3);
          }
          if (uVar11 != 0) {
            puVar13 = puVar10;
            param_3 = puVar12;
            local_8 = (uint *)uVar11;
            do {
              param_3 = param_3 + -1;
              puVar13 = puVar13 + -1;
              local_8 = (uint *)((int)local_8 - 1);
              *puVar13 = *param_3;
            } while (local_8 != (uint *)0x0);
          }
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      local_8 = puVar4;
    }
  }
  param_4 = *(int *)(param_1 + 0x2c) * param_4;
  if (*(ushort *)(param_1 + 0xc) < param_4) {
    param_4 = (uint)*(ushort *)(param_1 + 0xc);
  }
  iVar9 = (**(code **)(param_1 + 0x1c))
                    (param_2,(uint)*(ushort *)(param_1 + 10) + param_5,local_8,puVar4,param_4);
  if (iVar9 < 0) {
    return iVar9;
  }
  return 0;
}


// ==== FUN_009117c4 @ 0x009117c4 ====

int FUN_009117c4(uint param_1,undefined4 param_2,float *param_3,uint param_4,int param_5)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  short *psVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  float *pfVar10;
  uint uVar11;
  float *pfVar12;
  float *pfVar13;
  bool bVar14;
  bool bVar15;
  int local_18;
  undefined *local_14;
  float *local_10;
  float *local_8;
  
  iVar9 = param_1;
  psVar4 = *(short **)(param_1 + 0x18);
  pfVar5 = *(float **)(param_1 + 0x20);
  local_8 = param_3;
  sVar1 = *psVar4;
  if (sVar1 == 0) {
    uVar11 = (uint)(ushort)psVar4[4];
    bVar14 = param_4 < uVar11;
    bVar15 = param_4 == uVar11;
  }
  else {
    if (sVar1 == 1) {
      uVar11 = (uint)(ushort)psVar4[3];
    }
    else {
      if (sVar1 != 2) {
        if (sVar1 != 3) {
          if (sVar1 != 5) {
            return -0x7fffbfff;
          }
          param_4 = param_4 / *(uint *)(param_1 + 0x34);
          if ((ushort)psVar4[4] < param_4) {
            param_4 = (uint)(ushort)psVar4[4];
          }
          param_1 = 0;
          if (param_4 == 0) {
            return 0;
          }
          do {
            param_3 = (float *)0x0;
            if (psVar4[5] != 0) {
              do {
                iVar6 = *(int *)(*(int *)(iVar9 + 0x38) + (int)param_3 * 4);
                iVar7 = FUN_009117c4(iVar9,param_2,local_8,*(undefined4 *)(iVar6 + 0x30),param_5);
                if (iVar7 < 0) {
                  return iVar7;
                }
                local_8 = local_8 + *(int *)(iVar6 + 0x30);
                param_5 = param_5 + *(int *)(iVar6 + 0x28);
                param_3 = (float *)((int)param_3 + 1);
              } while (param_3 < (uint)(ushort)psVar4[5]);
            }
            param_1 = param_1 + 1;
          } while (param_1 < param_4);
          return 0;
        }
        uVar11 = (uint)(ushort)psVar4[2];
        param_4 = param_4 / (uVar11 * (ushort)psVar4[3]);
        if ((ushort)psVar4[4] < param_4) {
          param_4 = (uint)(ushort)psVar4[4];
        }
        local_10 = (float *)0x0;
        pfVar10 = pfVar5;
        if (param_4 != 0) {
          do {
            local_8 = (float *)0x0;
            if (psVar4[3] != 0) {
              do {
                uVar8 = 0;
                if (uVar11 != 0) {
                  do {
                    *pfVar10 = param_3[(uVar11 * (int)local_10 + uVar8) * (uint)(ushort)psVar4[3] +
                                       (int)local_8];
                    uVar11 = (uint)(ushort)psVar4[2];
                    pfVar10 = pfVar10 + 1;
                    uVar8 = uVar8 + 1;
                  } while (uVar8 < uVar11);
                }
                local_8 = (float *)((int)local_8 + 1);
              } while (local_8 < (uint)(ushort)psVar4[3]);
            }
            local_10 = (float *)((int)local_10 + 1);
          } while (local_10 < param_4);
        }
        local_8 = pfVar5;
        goto LAB_0091194b;
      }
      uVar11 = (uint)(ushort)psVar4[3] * (uint)(ushort)psVar4[2];
    }
    param_4 = param_4 / uVar11;
    uVar11 = (uint)(ushort)psVar4[4];
    bVar14 = param_4 < uVar11;
    bVar15 = param_4 == uVar11;
  }
  if (!bVar14 && !bVar15) {
    param_4 = uVar11;
  }
LAB_0091194b:
  sVar1 = psVar4[1];
  if (sVar1 != 2) {
    iVar9 = *(int *)(param_1 + 0x34) * param_4;
    if (sVar1 == 1) {
      if (iVar9 != 0) {
        pfVar10 = pfVar5;
        do {
          *pfVar10 = (float)(uint)(*(int *)((int)pfVar10 + ((int)local_8 - (int)pfVar5)) != 0);
          pfVar10 = pfVar10 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
    else if (((sVar1 != 2) && (sVar1 == 3)) && (iVar9 != 0)) {
      pfVar10 = pfVar5;
      do {
        *pfVar10 = (float)*(int *)(((int)local_8 - (int)pfVar5) + (int)pfVar10);
        pfVar10 = pfVar10 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    local_8 = pfVar5;
  }
  if (*(short *)(param_1 + 8) != 0) {
    if (*psVar4 == 3) {
      uVar2 = psVar4[2];
      uVar3 = psVar4[3];
    }
    else {
      uVar2 = psVar4[3];
      uVar3 = psVar4[2];
    }
    uVar11 = (uint)uVar2;
    if ((uVar2 & 3) != 0) {
      local_14 = &DAT_00a2954c;
      if (*(short *)(param_1 + 8) != 1) {
        local_14 = &DAT_00a2953c;
      }
      local_18 = uVar3 * param_4;
      uVar8 = uVar11 + 3 & 0xfffffffc;
      if (local_18 != 0) {
        iVar9 = local_18 * 4 + 4;
        pfVar12 = (float *)(iVar9 * uVar11 + (int)local_8);
        local_10 = (float *)(iVar9 * uVar8 + (int)pfVar5);
        pfVar10 = pfVar5 + local_18 * uVar8 + uVar11;
        do {
          local_10 = local_10 + -uVar8;
          pfVar10 = pfVar10 + -uVar8;
          pfVar12 = pfVar12 + -uVar11;
          if (uVar11 < uVar8) {
            pfVar13 = local_10;
            param_3 = (float *)uVar8;
            do {
              param_3 = (float *)((int)param_3 - 1);
              pfVar13 = pfVar13 + -1;
              *pfVar13 = *(float *)(local_14 + ((uint)param_3 & 3) * 4);
            } while (uVar11 < param_3);
          }
          if (uVar11 != 0) {
            pfVar13 = pfVar10;
            param_3 = pfVar12;
            local_8 = (float *)uVar11;
            do {
              param_3 = param_3 + -1;
              pfVar13 = pfVar13 + -1;
              local_8 = (float *)((int)local_8 - 1);
              *pfVar13 = *param_3;
            } while (local_8 != (float *)0x0);
          }
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      local_8 = pfVar5;
    }
  }
  param_4 = *(int *)(param_1 + 0x2c) * param_4;
  if (*(ushort *)(param_1 + 0xc) < param_4) {
    param_4 = (uint)*(ushort *)(param_1 + 0xc);
  }
  iVar9 = (**(code **)(param_1 + 0x1c))
                    (param_2,(uint)*(ushort *)(param_1 + 10) + param_5,local_8,pfVar5,param_4);
  if (iVar9 < 0) {
    return iVar9;
  }
  return 0;
}


// ==== FUN_00911aba @ 0x00911aba ====

int FUN_00911aba(uint param_1,undefined4 param_2,uint *param_3,uint param_4,int param_5)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  uint *puVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  bool bVar14;
  bool bVar15;
  int local_18;
  undefined *local_14;
  uint *local_10;
  uint *local_8;
  
  iVar12 = param_1;
  puVar4 = *(uint **)(param_1 + 0x20);
  psVar5 = *(short **)(param_1 + 0x18);
  local_8 = param_3;
  sVar1 = *psVar5;
  if (sVar1 == 0) {
    uVar11 = (uint)(ushort)psVar5[4];
    bVar14 = param_4 < uVar11;
    bVar15 = param_4 == uVar11;
  }
  else {
    if (sVar1 == 1) {
      uVar11 = (uint)(ushort)psVar5[3];
    }
    else {
      if (sVar1 != 2) {
        if (sVar1 != 3) {
          if (sVar1 != 5) {
            return -0x7fffbfff;
          }
          param_4 = param_4 / *(uint *)(param_1 + 0x34);
          if ((ushort)psVar5[4] < param_4) {
            param_4 = (uint)(ushort)psVar5[4];
          }
          param_1 = 0;
          if (param_4 == 0) {
            return 0;
          }
          do {
            param_3 = (uint *)0x0;
            if (psVar5[5] != 0) {
              do {
                iVar6 = *(int *)(*(int *)(iVar12 + 0x38) + (int)param_3 * 4);
                iVar7 = FUN_00911aba(iVar12,param_2,local_8,*(undefined4 *)(iVar6 + 0x30),param_5);
                if (iVar7 < 0) {
                  return iVar7;
                }
                local_8 = local_8 + *(int *)(iVar6 + 0x30);
                param_5 = param_5 + *(int *)(iVar6 + 0x28);
                param_3 = (uint *)((int)param_3 + 1);
              } while (param_3 < (uint)(ushort)psVar5[5]);
            }
            param_1 = param_1 + 1;
          } while (param_1 < param_4);
          return 0;
        }
        uVar11 = (uint)(ushort)psVar5[2];
        param_4 = param_4 / (uVar11 * (ushort)psVar5[3]);
        if ((ushort)psVar5[4] < param_4) {
          param_4 = (uint)(ushort)psVar5[4];
        }
        local_10 = (uint *)0x0;
        puVar9 = puVar4;
        if (param_4 != 0) {
          do {
            local_8 = (uint *)0x0;
            if (psVar5[3] != 0) {
              do {
                uVar8 = 0;
                if (uVar11 != 0) {
                  do {
                    *puVar9 = param_3[(uVar11 * (int)local_10 + uVar8) * (uint)(ushort)psVar5[3] +
                                      (int)local_8];
                    uVar11 = (uint)(ushort)psVar5[2];
                    puVar9 = puVar9 + 1;
                    uVar8 = uVar8 + 1;
                  } while (uVar8 < uVar11);
                }
                local_8 = (uint *)((int)local_8 + 1);
              } while (local_8 < (uint)(ushort)psVar5[3]);
            }
            local_10 = (uint *)((int)local_10 + 1);
          } while (local_10 < param_4);
        }
        local_8 = puVar4;
        goto LAB_00911c42;
      }
      uVar11 = (uint)(ushort)psVar5[3] * (uint)(ushort)psVar5[2];
    }
    param_4 = param_4 / uVar11;
    uVar11 = (uint)(ushort)psVar5[4];
    bVar14 = param_4 < uVar11;
    bVar15 = param_4 == uVar11;
  }
  if (!bVar14 && !bVar15) {
    param_4 = uVar11;
  }
LAB_00911c42:
  sVar1 = psVar5[1];
  if (sVar1 != 3) {
    iVar12 = *(int *)(param_1 + 0x34) * param_4;
    if (sVar1 == 1) {
      if (iVar12 != 0) {
        puVar9 = puVar4;
        do {
          *puVar9 = (uint)(*(float *)((int)puVar9 + ((int)local_8 - (int)puVar4)) != DAT_0099cdc8);
          puVar9 = puVar9 + 1;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
    }
    else if ((sVar1 == 2) && (iVar12 != 0)) {
      puVar9 = puVar4;
      do {
        *puVar9 = (int)ROUND(*(float *)(((int)local_8 - (int)puVar4) + (int)puVar9));
        puVar9 = puVar9 + 1;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    local_8 = puVar4;
  }
  if (*(short *)(param_1 + 8) != 0) {
    if (*psVar5 == 3) {
      uVar2 = psVar5[2];
      uVar3 = psVar5[3];
    }
    else {
      uVar2 = psVar5[3];
      uVar3 = psVar5[2];
    }
    uVar11 = (uint)uVar2;
    if ((uVar2 & 3) != 0) {
      local_14 = &DAT_00a2954c;
      if (*(short *)(param_1 + 8) != 1) {
        local_14 = &DAT_00a2953c;
      }
      local_18 = uVar3 * param_4;
      uVar8 = uVar11 + 3 & 0xfffffffc;
      if (local_18 != 0) {
        iVar12 = local_18 * 4 + 4;
        puVar10 = (uint *)(iVar12 * uVar11 + (int)local_8);
        local_10 = (uint *)(iVar12 * uVar8 + (int)puVar4);
        puVar9 = puVar4 + local_18 * uVar8 + uVar11;
        do {
          local_10 = local_10 + -uVar8;
          puVar9 = puVar9 + -uVar8;
          puVar10 = puVar10 + -uVar11;
          if (uVar11 < uVar8) {
            puVar13 = local_10;
            param_3 = (uint *)uVar8;
            do {
              param_3 = (uint *)((int)param_3 - 1);
              puVar13 = puVar13 + -1;
              *puVar13 = *(uint *)(local_14 + ((uint)param_3 & 3) * 4);
            } while (uVar11 < param_3);
          }
          if (uVar11 != 0) {
            puVar13 = puVar9;
            param_3 = puVar10;
            local_8 = (uint *)uVar11;
            do {
              param_3 = param_3 + -1;
              puVar13 = puVar13 + -1;
              local_8 = (uint *)((int)local_8 - 1);
              *puVar13 = *param_3;
            } while (local_8 != (uint *)0x0);
          }
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      local_8 = puVar4;
    }
  }
  param_4 = *(int *)(param_1 + 0x2c) * param_4;
  if (*(ushort *)(param_1 + 0xc) < param_4) {
    param_4 = (uint)*(ushort *)(param_1 + 0xc);
  }
  iVar12 = (**(code **)(param_1 + 0x1c))
                     (param_2,(uint)*(ushort *)(param_1 + 10) + param_5,local_8,puVar4,param_4);
  if (iVar12 < 0) {
    return iVar12;
  }
  return 0;
}


// ==== FUN_00911deb @ 0x00911deb ====

int FUN_00911deb(int param_1,undefined4 param_2,uint *param_3,uint param_4,int param_5)

{
  short sVar1;
  ushort uVar2;
  uint *puVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  int local_18;
  undefined *local_14;
  uint *local_10;
  uint *local_8;
  
  puVar3 = *(uint **)(param_1 + 0x20);
  psVar4 = *(short **)(param_1 + 0x18);
  local_8 = param_3;
  sVar1 = *psVar4;
  if (sVar1 == 0) {
    param_4 = param_4 * 4;
    if ((ushort)psVar4[4] < param_4) {
      param_4 = (uint)(ushort)psVar4[4];
    }
  }
  else {
    if (sVar1 == 1) {
      if ((ushort)psVar4[4] < param_4) {
        param_4 = (uint)(ushort)psVar4[4];
      }
      if (psVar4[3] == 4) goto LAB_0091202e;
      uVar12 = 0;
      if (param_4 != 0) {
        uVar11 = (uint)(ushort)psVar4[3];
        puVar7 = puVar3;
        do {
          uVar6 = 0;
          if (uVar11 != 0) {
            do {
              if (uVar6 < 5) {
                uVar11 = param_3[uVar6 + uVar12 * 4];
              }
              else {
                uVar11 = 0;
              }
              *puVar7 = uVar11;
              uVar11 = (uint)(ushort)psVar4[3];
              puVar7 = puVar7 + 1;
              uVar6 = uVar6 + 1;
            } while (uVar6 < uVar11);
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 < param_4);
      }
    }
    else if (sVar1 == 2) {
      uVar12 = (uint)(ushort)psVar4[2];
      param_4 = param_4 / uVar12;
      if ((ushort)psVar4[4] < param_4) {
        param_4 = (uint)(ushort)psVar4[4];
      }
      uVar10 = psVar4[3];
      if (uVar10 == 4) goto LAB_0091202e;
      local_8 = (uint *)0x0;
      puVar7 = puVar3;
      if (param_4 != 0) {
        do {
          uVar11 = 0;
          if (uVar12 != 0) {
            uVar6 = (uint)uVar10;
            do {
              uVar12 = 0;
              if (uVar6 != 0) {
                do {
                  if (uVar12 < 5) {
                    uVar6 = param_3[uVar12 + ((uint)(ushort)psVar4[2] * (int)local_8 + uVar11) * 4];
                  }
                  else {
                    uVar6 = 0;
                  }
                  *puVar7 = uVar6;
                  uVar10 = psVar4[3];
                  puVar7 = puVar7 + 1;
                  uVar6 = (uint)uVar10;
                  uVar12 = uVar12 + 1;
                } while (uVar12 < uVar6);
              }
              uVar12 = (uint)(ushort)psVar4[2];
              uVar11 = uVar11 + 1;
            } while (uVar11 < uVar12);
          }
          local_8 = (uint *)((int)local_8 + 1);
        } while (local_8 < param_4);
      }
    }
    else {
      if (sVar1 != 3) {
        if (sVar1 != 5) {
          return -0x7fffbfff;
        }
        param_4 = (param_4 << 2) / *(uint *)(param_1 + 0x34);
        if ((ushort)psVar4[4] < param_4) {
          param_4 = (uint)(ushort)psVar4[4];
        }
        param_3 = (uint *)0x0;
        if (param_4 == 0) {
          return 0;
        }
        do {
          uVar12 = 0;
          if (psVar4[5] != 0) {
            do {
              iVar8 = *(int *)(*(int *)(param_1 + 0x38) + uVar12 * 4);
              iVar5 = FUN_00911aba(param_1,param_2,local_8,*(undefined4 *)(iVar8 + 0x30),param_5);
              if (iVar5 < 0) {
                return iVar5;
              }
              local_8 = local_8 + *(int *)(iVar8 + 0x30);
              param_5 = param_5 + *(int *)(iVar8 + 0x28);
              uVar12 = uVar12 + 1;
            } while (uVar12 < (ushort)psVar4[5]);
          }
          param_3 = (uint *)((int)param_3 + 1);
        } while (param_3 < param_4);
        return 0;
      }
      uVar12 = (uint)(ushort)psVar4[3];
      param_4 = param_4 / uVar12;
      if ((ushort)psVar4[4] < param_4) {
        param_4 = (uint)(ushort)psVar4[4];
      }
      local_8 = (uint *)0x0;
      puVar7 = puVar3;
      if (param_4 != 0) {
        do {
          uVar11 = 0;
          if (uVar12 != 0) {
            uVar6 = (uint)(ushort)psVar4[2];
            do {
              uVar12 = 0;
              if (uVar6 != 0) {
                do {
                  if (uVar11 < 5) {
                    uVar6 = param_3[uVar11 + (uVar6 * (int)local_8 + uVar12) * 4];
                  }
                  else {
                    uVar6 = 0;
                  }
                  *puVar7 = uVar6;
                  uVar6 = (uint)(ushort)psVar4[2];
                  puVar7 = puVar7 + 1;
                  uVar12 = uVar12 + 1;
                } while (uVar12 < uVar6);
              }
              uVar12 = (uint)(ushort)psVar4[3];
              uVar11 = uVar11 + 1;
            } while (uVar11 < uVar12);
          }
          local_8 = (uint *)((int)local_8 + 1);
        } while (local_8 < param_4);
      }
    }
    local_8 = puVar3;
  }
LAB_0091202e:
  sVar1 = psVar4[1];
  if (sVar1 != 3) {
    iVar8 = *(int *)(param_1 + 0x34) * param_4;
    if (sVar1 == 1) {
      if (iVar8 != 0) {
        puVar7 = puVar3;
        do {
          *puVar7 = (uint)(*(float *)((int)puVar7 + ((int)local_8 - (int)puVar3)) != DAT_0099cdc8);
          puVar7 = puVar7 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
    else if ((sVar1 == 2) && (iVar8 != 0)) {
      puVar7 = puVar3;
      do {
        *puVar7 = (int)ROUND(*(float *)(((int)local_8 - (int)puVar3) + (int)puVar7));
        puVar7 = puVar7 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    local_8 = puVar3;
  }
  if (*(short *)(param_1 + 8) != 0) {
    if (*psVar4 == 3) {
      uVar10 = psVar4[2];
      uVar2 = psVar4[3];
    }
    else {
      uVar10 = psVar4[3];
      uVar2 = psVar4[2];
    }
    uVar12 = (uint)uVar10;
    if ((uVar10 & 3) != 0) {
      local_14 = &DAT_00a2954c;
      if (*(short *)(param_1 + 8) != 1) {
        local_14 = &DAT_00a2953c;
      }
      local_18 = uVar2 * param_4;
      uVar11 = uVar12 + 3 & 0xfffffffc;
      if (local_18 != 0) {
        puVar7 = (uint *)(uVar12 * (local_18 * 4 + 4) + (int)local_8);
        local_10 = puVar3 + local_18 * uVar11 + uVar12;
        puVar9 = (uint *)(uVar11 * (local_18 * 4 + 4) + (int)puVar3);
        do {
          local_10 = local_10 + -uVar11;
          puVar9 = puVar9 + -uVar11;
          puVar7 = puVar7 + -uVar12;
          if (uVar12 < uVar11) {
            param_3 = (uint *)uVar11;
            local_8 = puVar9;
            do {
              param_3 = (uint *)((int)param_3 - 1);
              local_8 = local_8 + -1;
              *local_8 = *(uint *)(local_14 + ((uint)param_3 & 3) * 4);
            } while (uVar12 < param_3);
          }
          if (uVar12 != 0) {
            puVar13 = local_10;
            param_3 = puVar7;
            local_8 = (uint *)uVar12;
            do {
              param_3 = param_3 + -1;
              puVar13 = puVar13 + -1;
              local_8 = (uint *)((int)local_8 - 1);
              *puVar13 = *param_3;
            } while (local_8 != (uint *)0x0);
          }
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      local_8 = puVar3;
    }
  }
  param_4 = *(int *)(param_1 + 0x2c) * param_4;
  if (*(ushort *)(param_1 + 0xc) < param_4) {
    param_4 = (uint)*(ushort *)(param_1 + 0xc);
  }
  iVar8 = (**(code **)(param_1 + 0x1c))
                    (param_2,(uint)*(ushort *)(param_1 + 10) + param_5,local_8,puVar3,param_4);
  if (iVar8 < 0) {
    return iVar8;
  }
  return 0;
}


// ==== FUN_009121d8 @ 0x009121d8 ====

int FUN_009121d8(int param_1,undefined4 param_2,uint *param_3,uint param_4,int param_5)

{
  short sVar1;
  ushort uVar2;
  short *psVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  int local_18;
  uint local_14;
  undefined *local_10;
  uint *local_c;
  
  psVar3 = *(short **)(param_1 + 0x18);
  sVar1 = *psVar3;
  puVar4 = *(uint **)(param_1 + 0x20);
  local_c = param_3;
  if (sVar1 == 0) {
    param_4 = param_4 * 0x10;
    if ((ushort)psVar3[4] < param_4) {
      param_4 = (uint)(ushort)psVar3[4];
    }
  }
  else {
    if (sVar1 == 1) {
      param_4 = param_4 * 4;
      if ((ushort)psVar3[4] < param_4) {
        param_4 = (uint)(ushort)psVar3[4];
      }
      if (psVar3[3] == 4) goto LAB_009124bf;
      uVar12 = 0;
      if (param_4 != 0) {
        uVar13 = (uint)(ushort)psVar3[3];
        puVar6 = puVar4;
        do {
          uVar8 = 0;
          if (uVar13 != 0) {
            do {
              if (uVar8 < 5) {
                uVar13 = param_3[uVar8 + ((uVar12 & 3) + (uVar12 & 0xfffffffc)) * 4];
              }
              else {
                uVar13 = 0;
              }
              *puVar6 = uVar13;
              uVar13 = (uint)(ushort)psVar3[3];
              puVar6 = puVar6 + 1;
              uVar8 = uVar8 + 1;
            } while (uVar8 < uVar13);
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 < param_4);
      }
    }
    else if (sVar1 == 2) {
      if ((ushort)psVar3[4] < param_4) {
        param_4 = (uint)(ushort)psVar3[4];
      }
      uVar11 = psVar3[2];
      if ((uVar11 == 4) && (psVar3[3] == 4)) goto LAB_009124bf;
      local_c = (uint *)0x0;
      puVar6 = puVar4;
      if (param_4 != 0) {
        do {
          uVar12 = 0;
          if (uVar11 != 0) {
            uVar13 = (uint)(ushort)psVar3[3];
            do {
              uVar8 = 0;
              if (uVar13 != 0) {
                do {
                  if ((uVar12 < 5) && (uVar8 < 5)) {
                    uVar13 = param_3[uVar8 + (uVar12 + (int)local_c * 4) * 4];
                  }
                  else {
                    uVar13 = 0;
                  }
                  *puVar6 = uVar13;
                  uVar13 = (uint)(ushort)psVar3[3];
                  puVar6 = puVar6 + 1;
                  uVar8 = uVar8 + 1;
                } while (uVar8 < uVar13);
              }
              uVar11 = psVar3[2];
              uVar12 = uVar12 + 1;
            } while (uVar12 < uVar11);
          }
          local_c = (uint *)((int)local_c + 1);
        } while (local_c < param_4);
      }
    }
    else {
      if (sVar1 != 3) {
        if (sVar1 != 5) {
          return -0x7fffbfff;
        }
        param_4 = (param_4 << 4) / *(uint *)(param_1 + 0x34);
        if ((ushort)psVar3[4] < param_4) {
          param_4 = (uint)(ushort)psVar3[4];
        }
        param_3 = (uint *)0x0;
        if (param_4 == 0) {
          return 0;
        }
        do {
          uVar12 = 0;
          if (psVar3[5] != 0) {
            do {
              iVar9 = *(int *)(*(int *)(param_1 + 0x38) + uVar12 * 4);
              iVar5 = FUN_00911aba(param_1,param_2,local_c,*(undefined4 *)(iVar9 + 0x30),param_5);
              if (iVar5 < 0) {
                return iVar5;
              }
              local_c = local_c + *(int *)(iVar9 + 0x30);
              param_5 = param_5 + *(int *)(iVar9 + 0x28);
              uVar12 = uVar12 + 1;
            } while (uVar12 < (ushort)psVar3[5]);
          }
          param_3 = (uint *)((int)param_3 + 1);
        } while (param_3 < param_4);
        return 0;
      }
      if ((ushort)psVar3[4] < param_4) {
        param_4 = (uint)(ushort)psVar3[4];
      }
      uVar11 = psVar3[2];
      if ((uVar11 == 4) && (psVar3[3] == 4)) {
        if (param_4 != 0) {
          puVar6 = puVar4 + 2;
          puVar7 = param_3 + 8;
          uVar12 = param_4;
          do {
            puVar6[-2] = puVar7[-8];
            puVar6[-1] = puVar7[-4];
            *puVar6 = *puVar7;
            puVar6[1] = puVar7[4];
            puVar6[2] = puVar7[-7];
            puVar6[3] = puVar7[-3];
            puVar6[4] = puVar7[1];
            puVar6[5] = puVar7[5];
            *(uint *)((int)puVar7 + ((int)puVar4 - (int)param_3)) = puVar7[-6];
            puVar6[7] = puVar7[-2];
            puVar6[8] = puVar7[2];
            puVar6[9] = puVar7[6];
            puVar6[10] = puVar7[-5];
            puVar6[0xb] = puVar7[-1];
            puVar6[0xc] = puVar7[3];
            puVar6[0xd] = puVar7[7];
            puVar7 = puVar7 + 0x10;
            puVar6 = puVar6 + 0x10;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
      }
      else {
        uVar12 = 0;
        puVar6 = puVar4;
        if (param_4 != 0) {
          do {
            local_c = (uint *)0x0;
            if (psVar3[3] != 0) {
              uVar13 = (uint)uVar11;
              do {
                uVar8 = 0;
                if (uVar13 != 0) {
                  do {
                    if ((uVar8 < 5) && (local_c < 5)) {
                      uVar13 = param_3[(int)local_c + (uVar8 + uVar12 * 4) * 4];
                    }
                    else {
                      uVar13 = 0;
                    }
                    *puVar6 = uVar13;
                    uVar11 = psVar3[2];
                    puVar6 = puVar6 + 1;
                    uVar13 = (uint)uVar11;
                    uVar8 = uVar8 + 1;
                  } while (uVar8 < uVar13);
                }
                local_c = (uint *)((int)local_c + 1);
              } while (local_c < (uint)(ushort)psVar3[3]);
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < param_4);
        }
      }
    }
    local_c = puVar4;
  }
LAB_009124bf:
  sVar1 = psVar3[1];
  if (sVar1 != 3) {
    iVar9 = *(int *)(param_1 + 0x34) * param_4;
    if (sVar1 == 1) {
      if (iVar9 != 0) {
        puVar6 = puVar4;
        do {
          *puVar6 = (uint)(*(float *)((int)puVar6 + ((int)local_c - (int)puVar4)) != DAT_0099cdc8);
          puVar6 = puVar6 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
    else if ((sVar1 == 2) && (iVar9 != 0)) {
      puVar6 = puVar4;
      do {
        *puVar6 = (int)ROUND(*(float *)(((int)local_c - (int)puVar4) + (int)puVar6));
        puVar6 = puVar6 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    local_c = puVar4;
  }
  if (*(short *)(param_1 + 8) != 0) {
    if (*psVar3 == 3) {
      uVar11 = psVar3[2];
      uVar2 = psVar3[3];
    }
    else {
      uVar11 = psVar3[3];
      uVar2 = psVar3[2];
    }
    uVar12 = (uint)uVar11;
    if ((uVar11 & 3) != 0) {
      local_10 = &DAT_00a2954c;
      if (*(short *)(param_1 + 8) != 1) {
        local_10 = &DAT_00a2953c;
      }
      local_18 = uVar2 * param_4;
      uVar13 = uVar12 + 3 & 0xfffffffc;
      if (local_18 != 0) {
        iVar9 = local_18 * 4 + 4;
        puVar7 = (uint *)(iVar9 * uVar12 + (int)local_c);
        local_c = (uint *)(iVar9 * uVar13 + (int)puVar4);
        puVar6 = puVar4 + local_18 * uVar13 + uVar12;
        do {
          local_c = local_c + -uVar13;
          puVar6 = puVar6 + -uVar13;
          puVar7 = puVar7 + -uVar12;
          if (uVar12 < uVar13) {
            puVar10 = local_c;
            param_3 = (uint *)uVar13;
            do {
              param_3 = (uint *)((int)param_3 - 1);
              puVar10 = puVar10 + -1;
              *puVar10 = *(uint *)(local_10 + ((uint)param_3 & 3) * 4);
            } while (uVar12 < param_3);
          }
          if (uVar12 != 0) {
            puVar10 = puVar6;
            param_3 = puVar7;
            local_14 = uVar12;
            do {
              param_3 = param_3 + -1;
              puVar10 = puVar10 + -1;
              local_14 = local_14 - 1;
              *puVar10 = *param_3;
            } while (local_14 != 0);
          }
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      local_c = puVar4;
    }
  }
  param_4 = *(int *)(param_1 + 0x2c) * param_4;
  if (*(ushort *)(param_1 + 0xc) < param_4) {
    param_4 = (uint)*(ushort *)(param_1 + 0xc);
  }
  iVar9 = (**(code **)(param_1 + 0x1c))
                    (param_2,(uint)*(ushort *)(param_1 + 10) + param_5,local_c,puVar4,param_4);
  if (iVar9 < 0) {
    return iVar9;
  }
  return 0;
}


// ==== FUN_0091266d @ 0x0091266d ====

int FUN_0091266d(int param_1,undefined4 param_2,undefined4 *param_3,uint param_4,int param_5)

{
  float *pfVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 *puVar5;
  short *psVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int local_18;
  uint local_14;
  undefined *local_10;
  undefined4 *local_c;
  
  puVar5 = *(undefined4 **)(param_1 + 0x20);
  psVar6 = *(short **)(param_1 + 0x18);
  sVar2 = *psVar6;
  uVar14 = 0;
  if (sVar2 == 0) {
    param_4 = param_4 * 0x10;
    if ((ushort)psVar6[4] < param_4) {
      param_4 = (uint)(ushort)psVar6[4];
    }
    puVar12 = puVar5;
    if (param_4 != 0) {
      do {
        *puVar12 = *(undefined4 *)
                    (*(int *)((int)param_3 + (uVar14 >> 4) * 4) +
                    ((uVar14 & 3) + (uVar14 >> 2 & 3) * 4) * 4);
        puVar12 = puVar12 + 1;
        uVar14 = uVar14 + 1;
      } while (uVar14 < param_4);
    }
  }
  else if (sVar2 == 1) {
    param_4 = param_4 * 4;
    if ((ushort)psVar6[4] < param_4) {
      param_4 = (uint)(ushort)psVar6[4];
    }
    local_c = (undefined4 *)0x0;
    if (param_4 != 0) {
      uVar14 = (uint)(ushort)psVar6[3];
      puVar12 = puVar5;
      do {
        uVar16 = 0;
        if (uVar14 != 0) {
          do {
            if (uVar16 < 5) {
              uVar8 = *(undefined4 *)
                       (*(int *)((int)param_3 + ((uint)local_c & 0xfffffffc)) +
                       (uVar16 + ((uint)local_c & 3) * 4) * 4);
            }
            else {
              uVar8 = 0;
            }
            *puVar12 = uVar8;
            uVar14 = (uint)(ushort)psVar6[3];
            puVar12 = puVar12 + 1;
            uVar16 = uVar16 + 1;
          } while (uVar16 < uVar14);
        }
        local_c = (undefined4 *)((int)local_c + 1);
      } while (local_c < param_4);
    }
  }
  else if (sVar2 == 2) {
    if ((ushort)psVar6[4] < param_4) {
      param_4 = (uint)(ushort)psVar6[4];
    }
    uVar14 = 0;
    local_c = puVar5;
    if (param_4 != 0) {
      do {
        uVar16 = 0;
        if (psVar6[2] != 0) {
          uVar15 = (uint)(ushort)psVar6[3];
          do {
            uVar11 = 0;
            if (uVar15 != 0) {
              do {
                if ((uVar16 < 5) && (uVar11 < 5)) {
                  uVar8 = *(undefined4 *)
                           (*(int *)((int)param_3 + uVar14 * 4) + (uVar11 + uVar16 * 4) * 4);
                }
                else {
                  uVar8 = 0;
                }
                puVar12 = local_c + 1;
                *local_c = uVar8;
                uVar15 = (uint)(ushort)psVar6[3];
                uVar11 = uVar11 + 1;
                local_c = puVar12;
              } while (uVar11 < uVar15);
            }
            uVar16 = uVar16 + 1;
          } while (uVar16 < (ushort)psVar6[2]);
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < param_4);
    }
  }
  else {
    if (sVar2 != 3) {
      if (sVar2 != 5) {
        return -0x7fffbfff;
      }
      param_4 = (param_4 << 4) / *(uint *)(param_1 + 0x34);
      if ((ushort)psVar6[4] < param_4) {
        param_4 = (uint)(ushort)psVar6[4];
      }
      uVar14 = *(uint *)(param_1 + 0x34) * param_4;
      uVar16 = 0;
      puVar12 = puVar5;
      if (uVar14 != 0) {
        do {
          *puVar12 = *(undefined4 *)
                      (*(int *)((int)param_3 + (uVar16 >> 4) * 4) +
                      ((uVar16 & 3) + (uVar16 >> 2 & 3) * 4) * 4);
          puVar12 = puVar12 + 1;
          uVar16 = uVar16 + 1;
        } while (uVar16 < uVar14);
      }
      local_c = (undefined4 *)0x0;
      param_3 = puVar5;
      if (param_4 == 0) {
        return 0;
      }
      do {
        uVar14 = 0;
        if (psVar6[5] != 0) {
          do {
            iVar10 = *(int *)(*(int *)(param_1 + 0x38) + uVar14 * 4);
            iVar7 = FUN_00911aba(param_1,param_2,param_3,*(undefined4 *)(iVar10 + 0x30),param_5);
            if (iVar7 < 0) {
              return iVar7;
            }
            param_3 = param_3 + *(int *)(iVar10 + 0x30);
            param_5 = param_5 + *(int *)(iVar10 + 0x28);
            uVar14 = uVar14 + 1;
          } while (uVar14 < (ushort)psVar6[5]);
        }
        local_c = (undefined4 *)((int)local_c + 1);
      } while (local_c < param_4);
      return 0;
    }
    if ((ushort)psVar6[4] < param_4) {
      param_4 = (uint)(ushort)psVar6[4];
    }
    uVar14 = 0;
    puVar12 = puVar5;
    if (param_4 != 0) {
      do {
        local_c = (undefined4 *)0x0;
        if (psVar6[3] != 0) {
          uVar16 = (uint)(ushort)psVar6[2];
          do {
            uVar15 = 0;
            if (uVar16 != 0) {
              iVar10 = (int)local_c << 2;
              do {
                if ((uVar15 < 5) && (local_c < 5)) {
                  uVar8 = *(undefined4 *)(iVar10 + *(int *)((int)param_3 + uVar14 * 4));
                }
                else {
                  uVar8 = 0;
                }
                *puVar12 = uVar8;
                uVar16 = (uint)(ushort)psVar6[2];
                puVar12 = puVar12 + 1;
                uVar15 = uVar15 + 1;
                iVar10 = iVar10 + 0x10;
              } while (uVar15 < uVar16);
            }
            local_c = (undefined4 *)((int)local_c + 1);
          } while (local_c < (uint)(ushort)psVar6[3]);
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < param_4);
    }
  }
  sVar2 = psVar6[1];
  if (sVar2 != 3) {
    uVar14 = *(int *)(param_1 + 0x34) * param_4;
    if (sVar2 == 1) {
      uVar16 = 0;
      if (uVar14 != 0) {
        do {
          pfVar1 = (float *)(puVar5 + uVar16);
          uVar16 = uVar16 + 1;
          *pfVar1 = (float)(uint)(*pfVar1 != DAT_0099cdc8);
        } while (uVar16 < uVar14);
      }
    }
    else if ((sVar2 == 2) && (uVar16 = 0, uVar14 != 0)) {
      do {
        pfVar1 = (float *)(puVar5 + uVar16);
        uVar16 = uVar16 + 1;
        *pfVar1 = (float)(int)ROUND(*pfVar1);
      } while (uVar16 < uVar14);
    }
  }
  if (*(short *)(param_1 + 8) != 0) {
    if (*psVar6 == 3) {
      uVar3 = psVar6[2];
      uVar4 = psVar6[3];
    }
    else {
      uVar3 = psVar6[3];
      uVar4 = psVar6[2];
    }
    uVar14 = (uint)uVar3;
    if ((uVar3 & 3) != 0) {
      local_10 = &DAT_00a2954c;
      if (*(short *)(param_1 + 8) != 1) {
        local_10 = &DAT_00a2953c;
      }
      local_18 = uVar4 * param_4;
      uVar16 = uVar14 + 3 & 0xfffffffc;
      if (local_18 != 0) {
        iVar10 = local_18 * 4 + 4;
        puVar9 = (undefined4 *)(iVar10 * uVar14 + (int)puVar5);
        local_c = (undefined4 *)(iVar10 * uVar16 + (int)puVar5);
        puVar12 = puVar5 + local_18 * uVar16 + uVar14;
        do {
          local_c = local_c + -uVar16;
          puVar12 = puVar12 + -uVar16;
          puVar9 = puVar9 + -uVar14;
          if (uVar14 < uVar16) {
            puVar13 = local_c;
            param_3 = (undefined4 *)uVar16;
            do {
              param_3 = (undefined4 *)((int)param_3 - 1);
              puVar13 = puVar13 + -1;
              *puVar13 = *(undefined4 *)(local_10 + ((uint)param_3 & 3) * 4);
            } while (uVar14 < param_3);
          }
          if (uVar14 != 0) {
            puVar13 = puVar12;
            param_3 = puVar9;
            local_14 = uVar14;
            do {
              param_3 = param_3 + -1;
              puVar13 = puVar13 + -1;
              local_14 = local_14 - 1;
              *puVar13 = *param_3;
            } while (local_14 != 0);
          }
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
    }
  }
  param_4 = *(int *)(param_1 + 0x2c) * param_4;
  if (*(ushort *)(param_1 + 0xc) < param_4) {
    param_4 = (uint)*(ushort *)(param_1 + 0xc);
  }
  iVar10 = (**(code **)(param_1 + 0x1c))
                     (param_2,(uint)*(ushort *)(param_1 + 10) + param_5,puVar5,puVar5,param_4);
  if (iVar10 < 0) {
    return iVar10;
  }
  return 0;
}


// ==== FUN_00912aa7 @ 0x00912aa7 ====

int FUN_00912aa7(int param_1,undefined4 param_2,uint *param_3,uint param_4,int param_5)

{
  short sVar1;
  ushort uVar2;
  uint *puVar3;
  short *psVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  ushort uVar12;
  uint uVar13;
  int local_18;
  uint local_14;
  undefined *local_10;
  uint *local_c;
  
  puVar3 = *(uint **)(param_1 + 0x20);
  psVar4 = *(short **)(param_1 + 0x18);
  sVar1 = *psVar4;
  local_c = param_3;
  if (sVar1 == 0) {
    param_4 = param_4 * 0x10;
    if ((ushort)psVar4[4] < param_4) {
      param_4 = (uint)(ushort)psVar4[4];
    }
    uVar8 = 0;
    puVar6 = puVar3;
    if (param_4 != 0) {
      do {
        *puVar6 = param_3[(uVar8 >> 2 & 3) + ((uVar8 & 3) + (uVar8 >> 4) * 4) * 4];
        puVar6 = puVar6 + 1;
        uVar8 = uVar8 + 1;
      } while (uVar8 < param_4);
    }
  }
  else if (sVar1 == 1) {
    param_4 = param_4 * 4;
    if ((ushort)psVar4[4] < param_4) {
      param_4 = (uint)(ushort)psVar4[4];
    }
    uVar8 = 0;
    if (param_4 != 0) {
      uVar13 = (uint)(ushort)psVar4[3];
      puVar6 = puVar3;
      do {
        uVar9 = 0;
        if (uVar13 != 0) {
          do {
            if (uVar9 < 5) {
              uVar13 = param_3[(uVar8 & 3) + (uVar9 + (uVar8 & 0xfffffffc)) * 4];
            }
            else {
              uVar13 = 0;
            }
            *puVar6 = uVar13;
            uVar13 = (uint)(ushort)psVar4[3];
            puVar6 = puVar6 + 1;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar13);
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < param_4);
    }
  }
  else if (sVar1 == 2) {
    if ((ushort)psVar4[4] < param_4) {
      param_4 = (uint)(ushort)psVar4[4];
    }
    uVar12 = psVar4[2];
    if ((uVar12 == 4) && (psVar4[3] == 4)) {
      if (param_4 != 0) {
        puVar6 = puVar3 + 2;
        puVar7 = param_3 + 8;
        uVar8 = param_4;
        do {
          puVar6[-2] = puVar7[-8];
          puVar6[-1] = puVar7[-4];
          *puVar6 = *puVar7;
          puVar6[1] = puVar7[4];
          puVar6[2] = puVar7[-7];
          puVar6[3] = puVar7[-3];
          puVar6[4] = puVar7[1];
          puVar6[5] = puVar7[5];
          *(uint *)(((int)puVar3 - (int)param_3) + (int)puVar7) = puVar7[-6];
          puVar6[7] = puVar7[-2];
          puVar6[8] = puVar7[2];
          puVar6[9] = puVar7[6];
          puVar6[10] = puVar7[-5];
          puVar6[0xb] = puVar7[-1];
          puVar6[0xc] = puVar7[3];
          puVar6[0xd] = puVar7[7];
          puVar7 = puVar7 + 0x10;
          puVar6 = puVar6 + 0x10;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
    }
    else {
      local_c = (uint *)0x0;
      puVar6 = puVar3;
      if (param_4 != 0) {
        do {
          uVar8 = 0;
          if (uVar12 != 0) {
            uVar13 = (uint)(ushort)psVar4[3];
            do {
              uVar9 = 0;
              if (uVar13 != 0) {
                do {
                  if ((uVar8 < 5) && (uVar9 < 5)) {
                    uVar13 = param_3[uVar8 + (uVar9 + (int)local_c * 4) * 4];
                  }
                  else {
                    uVar13 = 0;
                  }
                  *puVar6 = uVar13;
                  uVar13 = (uint)(ushort)psVar4[3];
                  puVar6 = puVar6 + 1;
                  uVar9 = uVar9 + 1;
                } while (uVar9 < uVar13);
              }
              uVar12 = psVar4[2];
              uVar8 = uVar8 + 1;
            } while (uVar8 < uVar12);
          }
          local_c = (uint *)((int)local_c + 1);
        } while (local_c < param_4);
      }
    }
  }
  else {
    if (sVar1 != 3) {
      if (sVar1 != 5) {
        return -0x7fffbfff;
      }
      param_4 = (param_4 << 4) / *(uint *)(param_1 + 0x34);
      if ((ushort)psVar4[4] < param_4) {
        param_4 = (uint)(ushort)psVar4[4];
      }
      uVar8 = *(uint *)(param_1 + 0x34) * param_4;
      uVar13 = 0;
      puVar6 = puVar3;
      if (uVar8 != 0) {
        do {
          *puVar6 = param_3[(uVar13 >> 2 & 3) + ((uVar13 & 3) + (uVar13 >> 4) * 4) * 4];
          puVar6 = puVar6 + 1;
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar8);
      }
      param_3 = (uint *)0x0;
      local_c = puVar3;
      if (param_4 == 0) {
        return 0;
      }
      do {
        uVar8 = 0;
        if (psVar4[5] != 0) {
          do {
            iVar10 = *(int *)(*(int *)(param_1 + 0x38) + uVar8 * 4);
            iVar5 = FUN_00911aba(param_1,param_2,local_c,*(undefined4 *)(iVar10 + 0x30),param_5);
            if (iVar5 < 0) {
              return iVar5;
            }
            local_c = local_c + *(int *)(iVar10 + 0x30);
            param_5 = param_5 + *(int *)(iVar10 + 0x28);
            uVar8 = uVar8 + 1;
          } while (uVar8 < (ushort)psVar4[5]);
        }
        param_3 = (uint *)((int)param_3 + 1);
      } while (param_3 < param_4);
      return 0;
    }
    if ((ushort)psVar4[4] < param_4) {
      param_4 = (uint)(ushort)psVar4[4];
    }
    uVar12 = psVar4[2];
    if ((uVar12 == 4) && (psVar4[3] == 4)) goto LAB_00912e06;
    uVar8 = 0;
    puVar6 = puVar3;
    if (param_4 != 0) {
      do {
        local_c = (uint *)0x0;
        if (psVar4[3] != 0) {
          uVar13 = (uint)uVar12;
          do {
            uVar9 = 0;
            if (uVar13 != 0) {
              do {
                if ((uVar9 < 5) && (local_c < 5)) {
                  uVar13 = param_3[uVar9 + ((int)local_c + uVar8 * 4) * 4];
                }
                else {
                  uVar13 = 0;
                }
                *puVar6 = uVar13;
                uVar12 = psVar4[2];
                puVar6 = puVar6 + 1;
                uVar13 = (uint)uVar12;
                uVar9 = uVar9 + 1;
              } while (uVar9 < uVar13);
            }
            local_c = (uint *)((int)local_c + 1);
          } while (local_c < (uint)(ushort)psVar4[3]);
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < param_4);
    }
  }
  local_c = puVar3;
LAB_00912e06:
  sVar1 = psVar4[1];
  if (sVar1 != 3) {
    iVar10 = *(int *)(param_1 + 0x34) * param_4;
    if (sVar1 == 1) {
      if (iVar10 != 0) {
        puVar6 = puVar3;
        do {
          *puVar6 = (uint)(*(float *)((int)puVar6 + ((int)local_c - (int)puVar3)) != DAT_0099cdc8);
          puVar6 = puVar6 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
    }
    else if ((sVar1 == 2) && (iVar10 != 0)) {
      puVar6 = puVar3;
      do {
        *puVar6 = (int)ROUND(*(float *)(((int)local_c - (int)puVar3) + (int)puVar6));
        puVar6 = puVar6 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    local_c = puVar3;
  }
  if (*(short *)(param_1 + 8) != 0) {
    if (*psVar4 == 3) {
      uVar12 = psVar4[2];
      uVar2 = psVar4[3];
    }
    else {
      uVar12 = psVar4[3];
      uVar2 = psVar4[2];
    }
    uVar8 = (uint)uVar12;
    if ((uVar12 & 3) != 0) {
      local_10 = &DAT_00a2954c;
      if (*(short *)(param_1 + 8) != 1) {
        local_10 = &DAT_00a2953c;
      }
      local_18 = uVar2 * param_4;
      uVar13 = uVar8 + 3 & 0xfffffffc;
      if (local_18 != 0) {
        iVar10 = local_18 * 4 + 4;
        puVar7 = (uint *)(iVar10 * uVar8 + (int)local_c);
        local_c = (uint *)(iVar10 * uVar13 + (int)puVar3);
        puVar6 = puVar3 + local_18 * uVar13 + uVar8;
        do {
          local_c = local_c + -uVar13;
          puVar6 = puVar6 + -uVar13;
          puVar7 = puVar7 + -uVar8;
          if (uVar8 < uVar13) {
            puVar11 = local_c;
            param_3 = (uint *)uVar13;
            do {
              param_3 = (uint *)((int)param_3 - 1);
              puVar11 = puVar11 + -1;
              *puVar11 = *(uint *)(local_10 + ((uint)param_3 & 3) * 4);
            } while (uVar8 < param_3);
          }
          if (uVar8 != 0) {
            puVar11 = puVar6;
            param_3 = puVar7;
            local_14 = uVar8;
            do {
              param_3 = param_3 + -1;
              puVar11 = puVar11 + -1;
              local_14 = local_14 - 1;
              *puVar11 = *param_3;
            } while (local_14 != 0);
          }
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      local_c = puVar3;
    }
  }
  param_4 = *(int *)(param_1 + 0x2c) * param_4;
  if (*(ushort *)(param_1 + 0xc) < param_4) {
    param_4 = (uint)*(ushort *)(param_1 + 0xc);
  }
  iVar10 = (**(code **)(param_1 + 0x1c))
                     (param_2,(uint)*(ushort *)(param_1 + 10) + param_5,local_c,puVar3,param_4);
  if (iVar10 < 0) {
    return iVar10;
  }
  return 0;
}


// ==== FUN_00912faf @ 0x00912faf ====

int FUN_00912faf(int param_1,undefined4 param_2,undefined4 *param_3,uint param_4,int param_5)

{
  float *pfVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 *puVar5;
  short *psVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  int local_18;
  uint local_14;
  undefined *local_10;
  undefined4 *local_c;
  
  puVar5 = *(undefined4 **)(param_1 + 0x20);
  psVar6 = *(short **)(param_1 + 0x18);
  sVar2 = *psVar6;
  uVar15 = 0;
  if (sVar2 == 0) {
    param_4 = param_4 * 0x10;
    if ((ushort)psVar6[4] < param_4) {
      param_4 = (uint)(ushort)psVar6[4];
    }
    puVar13 = puVar5;
    if (param_4 != 0) {
      do {
        *puVar13 = *(undefined4 *)
                    (*(int *)((int)param_3 + (uVar15 >> 4) * 4) +
                    ((uVar15 >> 2 & 3) + (uVar15 & 3) * 4) * 4);
        puVar13 = puVar13 + 1;
        uVar15 = uVar15 + 1;
      } while (uVar15 < param_4);
    }
  }
  else if (sVar2 == 1) {
    param_4 = param_4 * 4;
    if ((ushort)psVar6[4] < param_4) {
      param_4 = (uint)(ushort)psVar6[4];
    }
    local_c = (undefined4 *)0x0;
    if (param_4 != 0) {
      uVar15 = (uint)(ushort)psVar6[3];
      puVar13 = puVar5;
      do {
        uVar16 = 0;
        if (uVar15 != 0) {
          do {
            if (uVar16 < 5) {
              uVar9 = *(undefined4 *)
                       (*(int *)((int)param_3 + ((uint)local_c & 0xfffffffc)) +
                       (((uint)local_c & 3) + uVar16 * 4) * 4);
            }
            else {
              uVar9 = 0;
            }
            *puVar13 = uVar9;
            uVar15 = (uint)(ushort)psVar6[3];
            puVar13 = puVar13 + 1;
            uVar16 = uVar16 + 1;
          } while (uVar16 < uVar15);
        }
        local_c = (undefined4 *)((int)local_c + 1);
      } while (local_c < param_4);
    }
  }
  else if (sVar2 == 2) {
    if ((ushort)psVar6[4] < param_4) {
      param_4 = (uint)(ushort)psVar6[4];
    }
    uVar15 = 0;
    puVar13 = puVar5;
    if (param_4 != 0) {
      do {
        local_c = (undefined4 *)0x0;
        if (psVar6[2] != 0) {
          uVar16 = (uint)(ushort)psVar6[3];
          do {
            uVar8 = 0;
            if (uVar16 != 0) {
              iVar11 = (int)local_c << 2;
              do {
                if ((local_c < 5) && (uVar8 < 5)) {
                  uVar9 = *(undefined4 *)(iVar11 + *(int *)((int)param_3 + uVar15 * 4));
                }
                else {
                  uVar9 = 0;
                }
                *puVar13 = uVar9;
                uVar16 = (uint)(ushort)psVar6[3];
                puVar13 = puVar13 + 1;
                uVar8 = uVar8 + 1;
                iVar11 = iVar11 + 0x10;
              } while (uVar8 < uVar16);
            }
            local_c = (undefined4 *)((int)local_c + 1);
          } while (local_c < (uint)(ushort)psVar6[2]);
        }
        uVar15 = uVar15 + 1;
      } while (uVar15 < param_4);
    }
  }
  else {
    if (sVar2 != 3) {
      if (sVar2 != 5) {
        return -0x7fffbfff;
      }
      param_4 = (param_4 << 4) / *(uint *)(param_1 + 0x34);
      if ((ushort)psVar6[4] < param_4) {
        param_4 = (uint)(ushort)psVar6[4];
      }
      uVar15 = *(uint *)(param_1 + 0x34) * param_4;
      uVar16 = 0;
      puVar13 = puVar5;
      if (uVar15 != 0) {
        do {
          *puVar13 = *(undefined4 *)
                      (*(int *)((int)param_3 + (uVar16 >> 4) * 4) +
                      ((uVar16 >> 2 & 3) + (uVar16 & 3) * 4) * 4);
          puVar13 = puVar13 + 1;
          uVar16 = uVar16 + 1;
        } while (uVar16 < uVar15);
      }
      local_c = (undefined4 *)0x0;
      param_3 = puVar5;
      if (param_4 == 0) {
        return 0;
      }
      do {
        uVar15 = 0;
        if (psVar6[5] != 0) {
          do {
            iVar11 = *(int *)(*(int *)(param_1 + 0x38) + uVar15 * 4);
            iVar7 = FUN_00911aba(param_1,param_2,param_3,*(undefined4 *)(iVar11 + 0x30),param_5);
            if (iVar7 < 0) {
              return iVar7;
            }
            param_3 = param_3 + *(int *)(iVar11 + 0x30);
            param_5 = param_5 + *(int *)(iVar11 + 0x28);
            uVar15 = uVar15 + 1;
          } while (uVar15 < (ushort)psVar6[5]);
        }
        local_c = (undefined4 *)((int)local_c + 1);
      } while (local_c < param_4);
      return 0;
    }
    if ((ushort)psVar6[4] < param_4) {
      param_4 = (uint)(ushort)psVar6[4];
    }
    uVar15 = 0;
    local_c = puVar5;
    if (param_4 != 0) {
      do {
        uVar16 = 0;
        if (psVar6[3] != 0) {
          uVar8 = (uint)(ushort)psVar6[2];
          do {
            uVar12 = 0;
            if (uVar8 != 0) {
              do {
                if ((uVar12 < 5) && (uVar16 < 5)) {
                  uVar9 = *(undefined4 *)
                           (*(int *)((int)param_3 + uVar15 * 4) + (uVar12 + uVar16 * 4) * 4);
                }
                else {
                  uVar9 = 0;
                }
                puVar13 = local_c + 1;
                *local_c = uVar9;
                uVar8 = (uint)(ushort)psVar6[2];
                uVar12 = uVar12 + 1;
                local_c = puVar13;
              } while (uVar12 < uVar8);
            }
            uVar16 = uVar16 + 1;
          } while (uVar16 < (ushort)psVar6[3]);
        }
        uVar15 = uVar15 + 1;
      } while (uVar15 < param_4);
    }
  }
  sVar2 = psVar6[1];
  if (sVar2 != 3) {
    uVar15 = *(int *)(param_1 + 0x34) * param_4;
    if (sVar2 == 1) {
      uVar16 = 0;
      if (uVar15 != 0) {
        do {
          pfVar1 = (float *)(puVar5 + uVar16);
          uVar16 = uVar16 + 1;
          *pfVar1 = (float)(uint)(*pfVar1 != DAT_0099cdc8);
        } while (uVar16 < uVar15);
      }
    }
    else if ((sVar2 == 2) && (uVar16 = 0, uVar15 != 0)) {
      do {
        pfVar1 = (float *)(puVar5 + uVar16);
        uVar16 = uVar16 + 1;
        *pfVar1 = (float)(int)ROUND(*pfVar1);
      } while (uVar16 < uVar15);
    }
  }
  if (*(short *)(param_1 + 8) != 0) {
    if (*psVar6 == 3) {
      uVar3 = psVar6[2];
      uVar4 = psVar6[3];
    }
    else {
      uVar3 = psVar6[3];
      uVar4 = psVar6[2];
    }
    uVar15 = (uint)uVar3;
    if ((uVar3 & 3) != 0) {
      local_10 = &DAT_00a2954c;
      if (*(short *)(param_1 + 8) != 1) {
        local_10 = &DAT_00a2953c;
      }
      local_18 = uVar4 * param_4;
      uVar16 = uVar15 + 3 & 0xfffffffc;
      if (local_18 != 0) {
        iVar11 = local_18 * 4 + 4;
        puVar10 = (undefined4 *)(iVar11 * uVar15 + (int)puVar5);
        local_c = (undefined4 *)(iVar11 * uVar16 + (int)puVar5);
        puVar13 = puVar5 + local_18 * uVar16 + uVar15;
        do {
          local_c = local_c + -uVar16;
          puVar13 = puVar13 + -uVar16;
          puVar10 = puVar10 + -uVar15;
          if (uVar15 < uVar16) {
            puVar14 = local_c;
            param_3 = (undefined4 *)uVar16;
            do {
              param_3 = (undefined4 *)((int)param_3 - 1);
              puVar14 = puVar14 + -1;
              *puVar14 = *(undefined4 *)(local_10 + ((uint)param_3 & 3) * 4);
            } while (uVar15 < param_3);
          }
          if (uVar15 != 0) {
            puVar14 = puVar13;
            param_3 = puVar10;
            local_14 = uVar15;
            do {
              param_3 = param_3 + -1;
              puVar14 = puVar14 + -1;
              local_14 = local_14 - 1;
              *puVar14 = *param_3;
            } while (local_14 != 0);
          }
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
    }
  }
  param_4 = *(int *)(param_1 + 0x2c) * param_4;
  if (*(ushort *)(param_1 + 0xc) < param_4) {
    param_4 = (uint)*(ushort *)(param_1 + 0xc);
  }
  iVar11 = (**(code **)(param_1 + 0x1c))
                     (param_2,(uint)*(ushort *)(param_1 + 10) + param_5,puVar5,puVar5,param_4);
  if (iVar11 < 0) {
    return iVar11;
  }
  return 0;
}


// ==== FUN_009133e9 @ 0x009133e9 ====

int FUN_009133e9(int param_1,int param_2,int param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  
  pcVar6 = (code *)0x0;
  uVar5 = *(uint *)(*(int *)(param_1 + 0x10) + 8) & 0xffff0000;
  if (*(short *)(param_3 + 10) == 0) {
    if (uVar5 == 0x54580000) {
      if (*(short *)(param_2 + 4) == 2) {
        sVar1 = *(short *)(param_3 + 2);
        if (sVar1 == 0) {
          pcVar6 = FUN_00910eaa;
        }
        else if (sVar1 == 1) {
          pcVar6 = FUN_00910df0;
        }
        else if (sVar1 == 2) {
          pcVar6 = FUN_00910e54;
        }
        else if (sVar1 == 3) {
          pcVar6 = FUN_00910eaa;
        }
      }
      goto LAB_00913638;
    }
    if (uVar5 == 0xfffe0000) {
      sVar1 = *(short *)(param_2 + 4);
      if (sVar1 == 0) {
        sVar1 = *(short *)(param_3 + 2);
        if (sVar1 == 0) {
          pcVar6 = FUN_00910f56;
          goto LAB_00913638;
        }
        if (sVar1 != 1) {
          if (sVar1 == 2) {
            pcVar6 = FUN_00910f74;
          }
          else if (sVar1 == 3) {
            pcVar6 = FUN_00910fb5;
          }
          goto LAB_00913638;
        }
        goto LAB_00913633;
      }
      if (sVar1 == 1) {
        sVar1 = *(short *)(param_3 + 2);
        if (sVar1 == 0) {
          pcVar6 = FUN_0091104b;
          goto LAB_00913638;
        }
        if (sVar1 == 1) {
          pcVar6 = FUN_00911007;
          goto LAB_00913638;
        }
        if (sVar1 != 2) {
          if (sVar1 == 3) {
            pcVar6 = FUN_00911069;
          }
          goto LAB_00913638;
        }
        goto LAB_00913560;
      }
      if (sVar1 != 2) goto LAB_00913638;
      uVar5 = (uint)*(ushort *)(param_3 + 2);
      if (uVar5 == 0) {
        pcVar6 = FUN_00911154;
        goto LAB_00913638;
      }
      if (uVar5 == 1) {
        pcVar6 = FUN_009110cf;
        goto LAB_00913638;
      }
      iVar2 = uVar5 - 2;
      if (iVar2 == 0) {
        pcVar6 = FUN_00911119;
        goto LAB_00913638;
      }
      goto LAB_00913512;
    }
    if (uVar5 != 0xffff0000) goto LAB_00913638;
    sVar1 = *(short *)(param_2 + 4);
    if (sVar1 == 0) {
      sVar1 = *(short *)(param_3 + 2);
      if (sVar1 == 0) {
        pcVar6 = FUN_00911172;
        goto LAB_00913638;
      }
      if (sVar1 != 1) {
        if (sVar1 == 2) {
          pcVar6 = FUN_00911190;
        }
        else if (sVar1 == 3) {
          pcVar6 = FUN_009111d1;
        }
        goto LAB_00913638;
      }
      goto LAB_009134d7;
    }
    if (sVar1 == 1) {
      sVar1 = *(short *)(param_3 + 2);
      if (sVar1 == 0) {
        pcVar6 = FUN_00910cc9;
        goto LAB_00913638;
      }
      if (sVar1 == 1) {
        pcVar6 = FUN_00910c85;
        goto LAB_00913638;
      }
      if (sVar1 != 2) {
        if (sVar1 == 3) {
          pcVar6 = FUN_00910ce7;
        }
        goto LAB_00913638;
      }
      goto LAB_00913615;
    }
    if (sVar1 != 2) goto LAB_00913638;
    uVar5 = (uint)*(ushort *)(param_3 + 2);
    if (uVar5 == 0) {
      pcVar6 = FUN_00910d4d;
      goto LAB_00913638;
    }
    if (uVar5 == 1) {
      pcVar6 = FUN_00910d6b;
      goto LAB_00913638;
    }
    iVar2 = uVar5 - 2;
    if (iVar2 == 0) {
      pcVar6 = FUN_00910db5;
      goto LAB_00913638;
    }
  }
  else {
    if (uVar5 == 0xfffe0000) {
      if (*(ushort *)(param_2 + 4) == 0) {
LAB_00913633:
        pcVar6 = FUN_00910f56;
        goto LAB_00913638;
      }
      iVar2 = *(ushort *)(param_2 + 4) - 1;
      if (iVar2 == 0) {
LAB_00913560:
        pcVar6 = FUN_0091104b;
        goto LAB_00913638;
      }
LAB_00913512:
      if (iVar2 == 1) {
        pcVar6 = FUN_00911154;
      }
      goto LAB_00913638;
    }
    if (uVar5 != 0xffff0000) goto LAB_00913638;
    if (*(ushort *)(param_2 + 4) == 0) {
LAB_009134d7:
      pcVar6 = FUN_00911172;
      goto LAB_00913638;
    }
    iVar2 = *(ushort *)(param_2 + 4) - 1;
    if (iVar2 == 0) {
LAB_00913615:
      pcVar6 = FUN_00910cc9;
      goto LAB_00913638;
    }
  }
  if (iVar2 == 1) {
    pcVar6 = FUN_00910d4d;
  }
LAB_00913638:
  pvVar3 = operator_new(0x44);
  if (pvVar3 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0091091b(param_1,param_2,param_3,pcVar6,param_4);
  }
  if (iVar2 != 0) {
    iVar4 = FUN_00913681();
    if (-1 < iVar4) {
      return iVar2;
    }
    FUN_00910ee7(1);
  }
  return 0;
}


// ==== FUN_00913681 @ 0x00913681 ====

undefined4 FUN_00913681(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *in_ECX;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_28;
  short local_24;
  ushort local_22;
  ushort local_20;
  int local_1c;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  if (*(short *)(in_ECX[6] + 10) != 0) {
    puVar1 = operator_new((uint)*(ushort *)(in_ECX[6] + 10) << 2);
    in_ECX[0xe] = (int)puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    for (uVar3 = (uint)*(ushort *)(in_ECX[6] + 10); uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar1 = 0;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
    }
    local_c = in_ECX[8];
    iVar4 = in_ECX[6];
    piVar6 = &local_28;
    piVar7 = in_ECX;
    for (iVar5 = 5; piVar7 = piVar7 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar6 = *piVar7;
      piVar6 = piVar6 + 1;
    }
    uVar3 = (uint)*(ushort *)(iVar4 + 10);
    iVar4 = *(int *)(iVar4 + 0xc);
    if (*(uint *)(*in_ECX + 0xc) < iVar4 + uVar3 * 8) {
      return 0x80004005;
    }
    local_8 = 0;
    piVar7 = (int *)(*(int *)(*in_ECX + 8) + iVar4);
    if (uVar3 != 0) {
      do {
        iVar4 = *in_ECX;
        if (*(uint *)(iVar4 + 0xc) < piVar7[1] + 0x10U) {
          return 0x80004005;
        }
        local_10 = 0;
        local_14 = 0;
        iVar5 = *(int *)(iVar4 + 8) + piVar7[1];
        FUN_0091081f(iVar4,&local_28,iVar5,1,&local_10,&local_14);
        local_28 = *piVar7;
        local_1c = piVar7[1];
        local_20 = *(short *)(iVar5 + 8) * (short)local_10;
        uVar3 = (uint)*(ushort *)(in_ECX + 3) + (uint)*(ushort *)((int)in_ECX + 10);
        if (uVar3 < (uint)local_20 + (uint)local_22) {
          iVar4 = uVar3 - local_22;
          if (iVar4 < 0) {
            local_20 = 0;
          }
          else {
            local_20 = (ushort)iVar4;
          }
        }
        uVar2 = FUN_009133e9(*in_ECX,&local_28,iVar5,local_c);
        *(undefined4 *)(in_ECX[0xe] + local_8 * 4) = uVar2;
        piVar6 = (int *)(in_ECX[0xe] + local_8 * 4);
        if (*piVar6 == 0) {
          return 0x8007000e;
        }
        local_22 = local_22 + local_20;
        local_c = local_c + ((-(uint)(local_24 != 0) & 3) + 1) * *(int *)(*piVar6 + 0x2c) *
                            (uint)*(ushort *)(iVar5 + 8) * 4;
        piVar7 = piVar7 + 2;
        local_8 = local_8 + 1;
      } while (local_8 < *(ushort *)(in_ECX[6] + 10));
    }
  }
  return 0;
}


// ==== FUN_009137f7 @ 0x009137f7 ====

void FUN_009137f7(uint param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  undefined4 *in_ECX;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 local_1c;
  ushort local_16;
  ushort local_14;
  int local_c;
  int local_8;
  
  uVar1 = *(ushort *)(in_ECX[6] + 8);
  if ((param_1 < uVar1) && (uVar1 != 1)) {
    if (in_ECX[0xf] == 0) {
      puVar4 = operator_new((uint)uVar1 << 2);
      in_ECX[0xf] = puVar4;
      if (puVar4 == (undefined4 *)0x0) {
        return;
      }
      for (uVar7 = (uint)*(ushort *)(in_ECX[6] + 8); uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
    }
    local_8 = param_1 * 4;
    if (*(int *)(local_8 + in_ECX[0xf]) == 0) {
      if (in_ECX[0x10] == 0) {
        puVar4 = operator_new(0x10);
        in_ECX[0x10] = puVar4;
        if (puVar4 == (undefined4 *)0x0) {
          return;
        }
        puVar9 = (undefined4 *)in_ECX[6];
        *puVar4 = *puVar9;
        puVar4[1] = puVar9[1];
        puVar4[2] = puVar9[2];
        puVar4[3] = puVar9[3];
        *(undefined2 *)(in_ECX[0x10] + 8) = 1;
      }
      sVar2 = *(short *)(in_ECX + 0xb);
      uVar1 = *(ushort *)(in_ECX + 0xb);
      puVar9 = &local_1c;
      puVar4 = in_ECX;
      for (iVar8 = 5; puVar4 = puVar4 + 1, iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar9 = *puVar4;
        puVar9 = puVar9 + 1;
      }
      local_16 = sVar2 * (short)param_1 + *(ushort *)((int)in_ECX + 10);
      iVar8 = (uint)*(ushort *)((int)in_ECX + 10) + ((uint)*(ushort *)(in_ECX + 3) - (uint)local_16)
      ;
      local_14 = uVar1;
      if (iVar8 < (int)(uint)uVar1) {
        if (iVar8 < 0) {
          local_14 = 0;
        }
        else {
          local_14 = (ushort)iVar8;
        }
      }
      iVar8 = (-(uint)(*(short *)(in_ECX + 2) != 0) & 3) + 1;
      if (in_ECX[5] != 0) {
        local_c = in_ECX[5] + in_ECX[0xb] * iVar8 * param_1 * 4;
      }
      iVar6 = in_ECX[0xb];
      iVar3 = in_ECX[8];
      pvVar5 = operator_new(0x44);
      if (pvVar5 == (void *)0x0) {
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_0091091b(*in_ECX,&local_1c,in_ECX[0x10],in_ECX[7],
                             iVar3 + iVar6 * iVar8 * param_1 * 4);
      }
      *(int *)(local_8 + in_ECX[0xf]) = iVar8;
      if ((iVar8 != 0) && (iVar6 = FUN_00913681(), iVar8 = local_8, iVar6 < 0)) {
        if (*(int *)(local_8 + in_ECX[0xf]) != 0) {
          FUN_00910ee7(1);
        }
        *(undefined4 *)(iVar8 + in_ECX[0xf]) = 0;
      }
    }
  }
  return;
}


// ==== FUN_00913995 @ 0x00913995 ====

void FUN_00913995(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a294d0;
  in_ECX[1] = 1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  return;
}


// ==== FUN_009139b6 @ 0x009139b6 ====

int FUN_009139b6(int param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  void *pvVar6;
  ushort *puVar7;
  int in_ECX;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 *local_c;
  int *local_8;
  
  if (param_1 == 0) {
    return -0x7789f794;
  }
  puVar1 = (uint *)(in_ECX + 0xc);
  iVar3 = FUN_008f2d0f(param_1,0x42415443,&local_c,puVar1);
  if (iVar3 < 0) {
    return iVar3;
  }
  if (iVar3 == 1) {
    return -0x7789f4a7;
  }
  puVar4 = operator_new(*puVar1);
  *(undefined4 **)(in_ECX + 8) = puVar4;
  if (puVar4 == (undefined4 *)0x0) {
    return -0x7ff8fff2;
  }
  uVar9 = *puVar1;
  for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar4 = *local_c;
    local_c = local_c + 1;
    puVar4 = puVar4 + 1;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined1 *)puVar4 = *(undefined1 *)local_c;
    local_c = (undefined4 *)((int)local_c + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  puVar1 = *(uint **)(in_ECX + 8);
  *(uint **)(in_ECX + 0x10) = puVar1;
  if (0x1b < *puVar1) {
    puVar4 = operator_new(puVar1[3] << 2);
    *(undefined4 **)(in_ECX + 0x14) = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      return -0x7ff8fff2;
    }
    for (uVar9 = *(uint *)(*(int *)(in_ECX + 0x10) + 0xc) & 0x3fffffff; uVar9 != 0;
        uVar9 = uVar9 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    iVar3 = *(int *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(iVar3 + 0xc);
    if ((uint)(*(int *)(iVar3 + 0x10) + *(int *)(iVar3 + 0xc) * 0x14) <= *(uint *)(in_ECX + 0xc)) {
      param_1 = 0;
      iVar3 = *(int *)(in_ECX + 8) + *(int *)(iVar3 + 0x10);
      uVar9 = 0;
      if (*(int *)(in_ECX + 0x18) != 0) {
        local_8 = (int *)(iVar3 + 0xc);
        do {
          if (*(uint *)(in_ECX + 0xc) < *local_8 + 0x10U) goto LAB_00913bb8;
          uVar5 = FUN_009133e9(in_ECX,local_8 + -3,*(int *)(in_ECX + 8) + *local_8,0);
          *(undefined4 *)(*(int *)(in_ECX + 0x14) + uVar9 * 4) = uVar5;
          piVar2 = (int *)(*(int *)(in_ECX + 0x14) + uVar9 * 4);
          if (*piVar2 == 0) {
            return -0x7ff8fff2;
          }
          iVar10 = *piVar2;
          local_8 = local_8 + 5;
          param_1 = param_1 + ((-(uint)(*(short *)(iVar10 + 8) != 0) & 3) + 1) *
                              (uint)*(ushort *)(*(int *)(iVar10 + 0x18) + 8) *
                              *(int *)(iVar10 + 0x2c);
          uVar9 = uVar9 + 1;
        } while (uVar9 < *(uint *)(in_ECX + 0x18));
      }
      pvVar6 = operator_new(param_1 << 2);
      uVar9 = 0;
      *(void **)(in_ECX + 0x1c) = pvVar6;
      if (pvVar6 == (void *)0x0) {
        return -0x7ff8fff2;
      }
      param_1 = 0;
      if (*(int *)(in_ECX + 0x18) != 0) {
        do {
          FUN_00910a1a(*(int *)(in_ECX + 0x1c) + param_1 * 4);
          iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + uVar9 * 4);
          param_1 = param_1 + ((-(uint)(*(short *)(iVar10 + 8) != 0) & 3) + 1) *
                              (uint)*(ushort *)(*(int *)(iVar10 + 0x18) + 8) *
                              *(int *)(iVar10 + 0x2c);
          uVar9 = uVar9 + 1;
        } while (uVar9 < *(uint *)(in_ECX + 0x18));
      }
      uVar9 = 0;
      if (param_2 != 0) {
        if (*(int *)(in_ECX + 0x18) != 0) {
          iVar10 = *(int *)(in_ECX + 0x18);
          puVar7 = (ushort *)(iVar3 + 8);
          do {
            if (puVar7[-2] == 2) {
              if (uVar9 < (uint)puVar7[-1] + (uint)*puVar7) {
                uVar9 = (uint)puVar7[-1] + (uint)*puVar7;
              }
            }
            puVar7 = puVar7 + 10;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
        iVar3 = FUN_008eb3df(uVar9 << 4,param_2);
        if (iVar3 < 0) {
          return iVar3;
        }
      }
      return 0;
    }
  }
LAB_00913bb8:
  return -0x7789f4a7;
}


// ==== FUN_00913bbd @ 0x00913bbd ====

int FUN_00913bbd(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = iVar2 + -1;
  *(int *)(param_1 + 4) = iVar1;
  if (iVar2 == 1) {
    FUN_008f31de(1);
  }
  return iVar1;
}


// ==== FUN_00913be1 @ 0x00913be1 ====

int FUN_00913be1(char *param_1,uint param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int local_8;
  
  local_8 = in_ECX;
  do {
    while (iVar3 = _isspace((int)*param_1), iVar3 != 0) {
      param_1 = param_1 + 1;
    }
    cVar1 = *param_1;
    if (cVar1 == '\0') {
      return local_8;
    }
    if (cVar1 == '[') {
      do {
        param_1 = param_1 + 1;
        iVar3 = _isspace((int)*param_1);
      } while (iVar3 != 0);
      iVar3 = _isdigit((int)*param_1);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = 0;
      while (iVar4 = _isdigit((int)*param_1), iVar4 != 0) {
        iVar3 = *param_1 + -0x30 + iVar3 * 10;
        param_1 = param_1 + 1;
      }
      while (iVar4 = _isspace((int)*param_1), iVar4 != 0) {
        param_1 = param_1 + 1;
      }
      if (*param_1 != ']') {
        return 0;
      }
      local_8 = FUN_009137f7(iVar3);
      if (local_8 == 0) {
        return 0;
      }
      param_1 = param_1 + 1;
    }
    else {
      if (cVar1 != '.') {
        if (param_2 == 0) {
          return 0;
        }
        if (cVar1 != '.') goto LAB_00913c95;
      }
      do {
        param_1 = param_1 + 1;
LAB_00913c95:
        iVar3 = _isspace((int)*param_1);
      } while (iVar3 != 0);
      for (iVar3 = 0; (iVar4 = _isalnum((int)param_1[iVar3]), iVar4 != 0 || (param_1[iVar3] == '_'))
          ; iVar3 = iVar3 + 1) {
      }
      if (iVar3 == 0) {
        return 0;
      }
      uVar2 = *(ushort *)(*(int *)(local_8 + 0x18) + 10);
      param_2 = 0;
      while( true ) {
        if (uVar2 <= param_2) {
          return 0;
        }
        if ((*(int *)(*(int *)(*(int *)(local_8 + 0x38) + param_2 * 4) + 4) != 0) &&
           (iVar4 = FUN_009108da(iVar3), iVar4 == 0)) break;
        param_2 = param_2 + 1;
      }
      local_8 = FUN_00910b29(param_2);
      if (local_8 == 0) {
        return 0;
      }
      param_1 = param_1 + iVar3;
    }
    param_2 = 0;
  } while( true );
}


// ==== FUN_00913d2f @ 0x00913d2f ====

undefined4 FUN_00913d2f(char *param_1,int *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int in_ECX;
  byte *pbVar6;
  uint uVar7;
  int *piVar8;
  byte *pbVar9;
  bool bVar10;
  int *local_18;
  char *local_14;
  byte *local_10;
  byte *local_c;
  int local_8;
  
  if ((int)param_1 < 0) {
    *param_2 = -(int)param_1;
    uVar2 = 0;
  }
  else {
    local_14 = param_1;
    iVar3 = _isspace((int)*param_1);
    if (iVar3 != 0) {
      do {
        param_1 = param_1 + 1;
        iVar3 = _isspace((int)*param_1);
      } while (iVar3 != 0);
      local_14 = param_1;
    }
    iVar3 = _isalnum((int)*local_14);
    if (((iVar3 == 0) && (*local_14 != '_')) && (*local_14 != '$')) {
      uVar2 = 0x8876086c;
    }
    else {
      local_8 = 1;
      while( true ) {
        iVar3 = _isalnum((int)local_14[local_8]);
        if ((iVar3 == 0) && (local_14[local_8] != '_')) break;
        local_8 = local_8 + 1;
      }
      param_1 = *(char **)(*(int *)(in_ECX + 0x10) + 0xc);
      uVar7 = 0;
      local_c = (byte *)0x0;
      iVar3 = *(int *)(*(int *)(in_ECX + 0x10) + 0x10) + *(int *)(in_ECX + 8);
      if (param_1 != (char *)0x0) {
        do {
          uVar7 = (uint)((int)param_1 + (int)local_c) >> 1;
          iVar4 = FUN_009108da(local_8);
          if (iVar4 == 0) break;
          if (iVar4 < 0) {
            local_c = (byte *)(uVar7 + 1);
          }
          else {
            param_1 = (char *)uVar7;
          }
        } while (local_c < param_1);
      }
      if (local_c != (byte *)param_1) {
        local_18 = (int *)(iVar3 + uVar7 * 0x14);
        pbVar6 = (byte *)(*local_18 + *(int *)(in_ECX + 8));
        for (; uVar7 != 0; uVar7 = uVar7 - 1) {
          local_18 = local_18 + -5;
          local_10 = (byte *)(*local_18 + *(int *)(in_ECX + 8));
          if (pbVar6 != local_10) {
            local_c = pbVar6;
            do {
              bVar1 = *local_c;
              bVar10 = bVar1 < *local_10;
              if (bVar1 != *local_10) {
LAB_00913e80:
                iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
                goto LAB_00913e85;
              }
              if (bVar1 == 0) break;
              bVar1 = local_c[1];
              bVar10 = bVar1 < local_10[1];
              if (bVar1 != local_10[1]) goto LAB_00913e80;
              local_c = local_c + 2;
              local_10 = local_10 + 2;
            } while (bVar1 != 0);
            iVar4 = 0;
LAB_00913e85:
            if (iVar4 != 0) break;
          }
        }
        iVar4 = FUN_00913be1(local_14 + local_8,0);
        if (iVar4 != 0) {
          piVar8 = (int *)(iVar3 + uVar7 * 0x14);
          do {
            *param_2 = iVar4;
            param_2 = (int *)(iVar4 + 0x24);
            uVar7 = uVar7 + 1;
            piVar8 = piVar8 + 5;
            if (*(uint *)(*(int *)(in_ECX + 0x10) + 0xc) <= uVar7) {
              return 0;
            }
            pbVar5 = (byte *)(*piVar8 + *(int *)(in_ECX + 8));
            pbVar9 = pbVar6;
            if (pbVar6 != pbVar5) {
              do {
                bVar1 = *pbVar9;
                bVar10 = bVar1 < *pbVar5;
                if (bVar1 != *pbVar5) {
LAB_00913f0b:
                  iVar3 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
                  goto LAB_00913f10;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar9[1];
                bVar10 = bVar1 < pbVar5[1];
                if (bVar1 != pbVar5[1]) goto LAB_00913f0b;
                pbVar9 = pbVar9 + 2;
                pbVar5 = pbVar5 + 2;
              } while (bVar1 != 0);
              iVar3 = 0;
LAB_00913f10:
              if (iVar3 != 0) {
                return 0;
              }
            }
            iVar4 = FUN_00913be1(local_14 + local_8,0);
          } while (iVar4 != 0);
        }
      }
      uVar2 = 0x8876086c;
    }
  }
  return uVar2;
}


// ==== FUN_00913f36 @ 0x00913f36 ====

int FUN_00913f36(undefined4 param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  uint uVar5;
  uint uVar6;
  
  puVar2 = param_4;
  iVar3 = param_3;
  if ((param_3 == 0) && (param_4 == (uint *)0x0)) {
    iVar3 = -0x7789f794;
  }
  else {
    if (param_2 < 0) {
      iVar4 = -param_2;
    }
    else {
      iVar4 = FUN_00913d2f(param_2,&param_3);
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar4 = param_3;
    }
    uVar5 = 0;
    uVar6 = 1;
    for (iVar1 = iVar4; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x24)) {
      uVar5 = uVar5 + 1;
    }
    if (puVar2 != (uint *)0x0) {
      if (*puVar2 != 0) {
        uVar6 = *puVar2;
      }
      if (uVar5 < uVar6) {
        uVar6 = uVar5;
      }
      *puVar2 = uVar5;
    }
    if (iVar3 != 0) {
      for (; (iVar4 != 0 && (uVar6 != 0)); uVar6 = uVar6 - 1) {
        iVar4 = FUN_00910a86(iVar3);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = *(int *)(extraout_ECX + 0x24);
        iVar3 = iVar3 + 0x30;
      }
    }
    iVar3 = 0;
  }
  return iVar3;
}


// ==== FUN_00913fc1 @ 0x00913fc1 ====

uint FUN_00913fc1(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = -param_2;
  }
  else {
    iVar1 = FUN_00913d2f(param_2,&param_2);
    if (iVar1 < 0) {
      return 0xffffffff;
    }
  }
  if (*(short *)(param_2 + 8) == 3) {
    return (uint)*(ushort *)(param_2 + 10);
  }
  return 0xffffffff;
}


// ==== FUN_00913ff9 @ 0x00913ff9 ====

int FUN_00913ff9(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    if (*(uint *)(param_1 + 0x18) <= param_3) {
      return 0;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x14) + param_3 * 4);
  }
  else {
    if (param_2 < 0) {
      param_1 = -param_2;
    }
    else {
      iVar1 = FUN_00913d2f(param_2,&param_1);
      if (iVar1 < 0) {
        return 0;
      }
    }
    iVar1 = FUN_00910b29(param_3);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return -iVar1;
}


// ==== FUN_00914049 @ 0x00914049 ====

int FUN_00914049(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    if (param_3 < 0) {
      param_1 = -param_3;
    }
    else {
      iVar1 = FUN_00913d2f(param_3,&param_1);
      if (iVar1 < 0) {
        return 0;
      }
    }
  }
  else {
    if (param_2 < 0) {
      param_1 = -param_2;
    }
    else {
      iVar1 = FUN_00913d2f(param_2,&param_1);
      if (iVar1 < 0) {
        return 0;
      }
    }
    param_1 = FUN_00913be1(param_3,1);
    if (param_1 == 0) {
      return 0;
    }
  }
  return -param_1;
}


// ==== FUN_009140a9 @ 0x009140a9 ====

int FUN_009140a9(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = -param_2;
  }
  else {
    iVar1 = FUN_00913d2f(param_2,&param_2);
    if (iVar1 < 0) {
      return 0;
    }
  }
  iVar1 = FUN_009137f7(param_3);
  if (iVar1 == 0) {
    return 0;
  }
  return -iVar1;
}


// ==== FUN_009140e6 @ 0x009140e6 ====

int FUN_009140e6(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_3 < 0) {
    iVar1 = -param_3;
  }
  else {
    iVar1 = FUN_00913d2f(param_3,&param_3);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = param_3;
  }
  uVar3 = param_5 >> 2;
  do {
    iVar2 = FUN_00911223(iVar1,param_2,param_4,uVar3,0);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar1 = *(int *)(iVar1 + 0x24);
  } while (iVar1 != 0);
  return 0;
}


// ==== FUN_00914138 @ 0x00914138 ====

int FUN_00914138(undefined4 param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_009114c2(iVar2,param_2,&param_4,1,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_00914184 @ 0x00914184 ====

int FUN_00914184(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_009114c2(iVar2,param_2,param_4,param_5,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_009141d0 @ 0x009141d0 ====

int FUN_009141d0(undefined4 param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_009117c4(iVar2,param_2,&param_4,1,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_0091421c @ 0x0091421c ====

int FUN_0091421c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_009117c4(iVar2,param_2,param_4,param_5,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_00914268 @ 0x00914268 ====

int FUN_00914268(undefined4 param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_00911aba(iVar2,param_2,&param_4,1,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_009142b4 @ 0x009142b4 ====

int FUN_009142b4(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_00911aba(iVar2,param_2,param_4,param_5,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_00914300 @ 0x00914300 ====

int FUN_00914300(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_00911deb(iVar2,param_2,param_4,1,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_0091434b @ 0x0091434b ====

int FUN_0091434b(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_00911deb(iVar2,param_2,param_4,param_5,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_00914397 @ 0x00914397 ====

int FUN_00914397(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_009121d8(iVar2,param_2,param_4,1,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_009143e2 @ 0x009143e2 ====

int FUN_009143e2(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_009121d8(iVar2,param_2,param_4,param_5,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_0091442e @ 0x0091442e ====

int FUN_0091442e(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_0091266d(iVar2,param_2,param_4,param_5,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_0091447a @ 0x0091447a ====

int FUN_0091447a(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_00912aa7(iVar2,param_2,param_4,1,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_009144c5 @ 0x009144c5 ====

int FUN_009144c5(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_00912aa7(iVar2,param_2,param_4,param_5,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_00914511 @ 0x00914511 ====

int FUN_00914511(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    iVar2 = -param_3;
  }
  else {
    iVar2 = FUN_00913d2f(param_3,&param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_3;
  }
  do {
    iVar3 = FUN_00912faf(iVar2,param_2,param_4,param_5,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *piVar1;
  } while (*piVar1 != 0);
  return 0;
}


// ==== FUN_0091455d @ 0x0091455d ====

void FUN_0091455d(void)

{
  undefined4 *in_ECX;
  
  in_ECX[0xc] = 0xffffffff;
  in_ECX[0xd] = 0xffffffff;
  *in_ECX = 0;
  in_ECX[1] = 0;
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
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  return;
}


// ==== FUN_00914593 @ 0x00914593 ====

undefined4 FUN_00914593(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 == 0) {
    uVar1 = 0x80004005;
  }
  else {
    *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_009145b2 @ 0x009145b2 ====

uint FUN_009145b2(int param_1,int *param_2)

{
  uint uVar1;
  uint *in_ECX;
  
  uVar1 = *in_ECX & 0xfffff;
  if (in_ECX[1] < uVar1 * param_1 + uVar1) {
    if (param_2 != (int *)0x0) {
      *param_2 = 0;
    }
    uVar1 = 0;
  }
  else if (param_2 != (int *)0x0) {
    *param_2 = in_ECX[2] + uVar1 * param_1 * 4;
  }
  return uVar1;
}


// ==== FUN_009145ef @ 0x009145ef ====

undefined4 FUN_009145ef(void)

{
  uint uVar1;
  uint *in_ECX;
  
  if (((((*in_ECX & 0xf0000000) == 0x60000000) ||
       (uVar1 = *in_ECX & 0xfff00000, uVar1 == 0x50100000)) || (uVar1 == 0x50200000)) ||
     (uVar1 == 0x50300000)) {
    return 1;
  }
  return 0;
}


// ==== FUN_00914622 @ 0x00914622 ====

undefined4 FUN_00914622(void)

{
  uint uVar1;
  uint *in_ECX;
  
  uVar1 = *in_ECX & 0xfff00000;
  if ((((uVar1 == 0x10300000) || (uVar1 == 0x10500000)) || (uVar1 == 0x10600000)) ||
     (uVar1 == 0x10700000)) {
    return 1;
  }
  return 0;
}


// ==== FUN_0091464c @ 0x0091464c ====

undefined4 FUN_0091464c(void)

{
  uint uVar1;
  uint *in_ECX;
  
  uVar1 = *in_ECX & 0xfff00000;
  if ((((uVar1 == 0x20000000) || (uVar1 == 0x20100000)) || (uVar1 == 0x20400000)) ||
     ((uVar1 == 0x20500000 || (uVar1 == 0x50000000)))) {
    return 1;
  }
  return 0;
}


// ==== FUN_0091467d @ 0x0091467d ====

undefined4 FUN_0091467d(void)

{
  uint uVar1;
  uint *in_ECX;
  
  uVar1 = *in_ECX & 0xfff00000;
  if ((((uVar1 == 0x10000000) || (uVar1 == 0x10100000)) || (uVar1 == 0x11200000)) ||
     (((uVar1 == 0x20700000 || (uVar1 == 0x20800000)) || (uVar1 == 0x20900000)))) {
    return 1;
  }
  return 0;
}


// ==== FUN_009146b5 @ 0x009146b5 ====

undefined4 FUN_009146b5(void)

{
  uint uVar1;
  uint *in_ECX;
  bool bVar2;
  
  uVar1 = *in_ECX & 0xfff00000;
  if (uVar1 < 0x70700001) {
    if (uVar1 == 0x70700000) {
      return 1;
    }
    if (uVar1 == 0x50300000) {
      return 1;
    }
    if (uVar1 == 0x70100000) {
      return 1;
    }
    if (uVar1 == 0x70200000) {
      return 1;
    }
    if (uVar1 == 0x70500000) {
      return 1;
    }
    bVar2 = uVar1 == 0x70600000;
  }
  else {
    if (uVar1 == 0x70b00000) {
      return 1;
    }
    if (uVar1 == 0x70c00000) {
      return 1;
    }
    if (uVar1 == 0x70d00000) {
      return 1;
    }
    bVar2 = uVar1 == 0x71000000;
  }
  if (bVar2) {
    return 1;
  }
  return 0;
}


// ==== FUN_0091470d @ 0x0091470d ====

undefined4 FUN_0091470d(void)

{
  uint uVar1;
  uint *in_ECX;
  bool bVar2;
  
  uVar1 = *in_ECX & 0xfff00000;
  if (uVar1 < 0x74200001) {
    if (uVar1 == 0x74200000) {
      return 1;
    }
    if (uVar1 < 0x11500001) {
      if (uVar1 == 0x11500000) {
        return 1;
      }
      if (uVar1 == 0x11100000) {
        return 1;
      }
      if (uVar1 == 0x11200000) {
        return 1;
      }
      if (uVar1 == 0x11300000) {
        return 1;
      }
      bVar2 = uVar1 == 0x11400000;
    }
    else {
      if (uVar1 == 0x20800000) {
        return 1;
      }
      if (uVar1 == 0x20900000) {
        return 1;
      }
      bVar2 = uVar1 == 0x74100000;
    }
  }
  else {
    if (uVar1 == 0x74300000) {
      return 1;
    }
    if (uVar1 == 0x74400000) {
      return 1;
    }
    if (uVar1 == 0x74500000) {
      return 1;
    }
    if (uVar1 == 0x74600000) {
      return 1;
    }
    if (uVar1 == 0x74700000) {
      return 1;
    }
    if (uVar1 == 0x74a00000) {
      return 1;
    }
    bVar2 = uVar1 == 0x74b00000;
  }
  if (bVar2) {
    return 1;
  }
  return 0;
}


// ==== FUN_00914793 @ 0x00914793 ====

undefined4 FUN_00914793(void)

{
  uint uVar1;
  uint *in_ECX;
  
  uVar1 = *in_ECX & 0xfff00000;
  if ((((uVar1 == 0x73100000) || (uVar1 == 0x73300000)) || (uVar1 == 0x73d00000)) ||
     (((uVar1 == 0x73e00000 || (uVar1 == 0x73f00000)) || (uVar1 == 0x74000000)))) {
    return 1;
  }
  return 0;
}


// ==== FUN_009147cb @ 0x009147cb ====

undefined4 FUN_009147cb(void)

{
  uint *in_ECX;
  
  if (((*in_ECX & 0xfff00000) == 0x20700000) || ((*in_ECX & 0xfff00000) == 0x73400000)) {
    return 1;
  }
  return 0;
}


// ==== FUN_009147e7 @ 0x009147e7 ====

undefined4 FUN_009147e7(void)

{
  uint uVar1;
  uint *in_ECX;
  bool bVar2;
  
  uVar1 = *in_ECX & 0xfff00000;
  if (uVar1 < 0x73800001) {
    if (uVar1 == 0x73800000) {
      return 1;
    }
    if (uVar1 < 0x20900001) {
      if (uVar1 == 0x20900000) {
        return 1;
      }
      if (uVar1 < 0x11400001) {
        if (uVar1 == 0x11400000) {
          return 1;
        }
        if (uVar1 == 0x10f00000) {
          return 1;
        }
        if (uVar1 == 0x11100000) {
          return 1;
        }
        if (uVar1 == 0x11200000) {
          return 1;
        }
        bVar2 = uVar1 == 0x11300000;
      }
      else {
        if (uVar1 == 0x11500000) {
          return 1;
        }
        if (uVar1 == 0x20700000) {
          return 1;
        }
        bVar2 = uVar1 == 0x20800000;
      }
    }
    else if (uVar1 < 0x73400001) {
      if (uVar1 == 0x73400000) {
        return 1;
      }
      if (uVar1 == 0x73000000) {
        return 1;
      }
      if (uVar1 == 0x73100000) {
        return 1;
      }
      if (uVar1 == 0x73200000) {
        return 1;
      }
      bVar2 = uVar1 == 0x73300000;
    }
    else {
      if (uVar1 == 0x73500000) {
        return 1;
      }
      if (uVar1 == 0x73600000) {
        return 1;
      }
      bVar2 = uVar1 == 0x73700000;
    }
  }
  else if (uVar1 < 0x74100001) {
    if (uVar1 == 0x74100000) {
      return 1;
    }
    if (uVar1 < 0x73d00001) {
      if (uVar1 == 0x73d00000) {
        return 1;
      }
      if (uVar1 == 0x73900000) {
        return 1;
      }
      if (uVar1 == 0x73a00000) {
        return 1;
      }
      if (uVar1 == 0x73b00000) {
        return 1;
      }
      bVar2 = uVar1 == 0x73c00000;
    }
    else {
      if (uVar1 == 0x73e00000) {
        return 1;
      }
      if (uVar1 == 0x73f00000) {
        return 1;
      }
      bVar2 = uVar1 == 0x74000000;
    }
  }
  else if (uVar1 < 0x74600001) {
    if (uVar1 == 0x74600000) {
      return 1;
    }
    if (uVar1 == 0x74200000) {
      return 1;
    }
    if (uVar1 == 0x74300000) {
      return 1;
    }
    if (uVar1 == 0x74400000) {
      return 1;
    }
    bVar2 = uVar1 == 0x74500000;
  }
  else {
    if (uVar1 == 0x74700000) {
      return 1;
    }
    if (uVar1 == 0x74a00000) {
      return 1;
    }
    bVar2 = uVar1 == 0x74b00000;
  }
  if (bVar2) {
    return 1;
  }
  return 0;
}


// ==== FUN_0091494e @ 0x0091494e ====

undefined4 FUN_0091494e(void)

{
  uint uVar1;
  uint *in_ECX;
  bool bVar2;
  
  uVar1 = *in_ECX & 0xfff00000;
  if (uVar1 < 0x60800001) {
    if (uVar1 == 0x60800000) {
      return 1;
    }
    if (uVar1 == 0x10d00000) {
      return 1;
    }
    if (uVar1 == 0x10e00000) {
      return 1;
    }
    if (uVar1 == 0x60000000) {
      return 1;
    }
    if (uVar1 == 0x60200000) {
      return 1;
    }
    if (uVar1 == 0x60300000) {
      return 1;
    }
    if (uVar1 == 0x60500000) {
      return 1;
    }
    bVar2 = uVar1 == 0x60700000;
  }
  else {
    if (uVar1 == 0x60a00000) {
      return 1;
    }
    if (uVar1 == 0x60c00000) {
      return 1;
    }
    if (uVar1 == 0x60d00000) {
      return 1;
    }
    if (uVar1 == 0x60f00000) {
      return 1;
    }
    if (uVar1 == 0x61100000) {
      return 1;
    }
    bVar2 = uVar1 == 0x61200000;
  }
  if (bVar2) {
    return 1;
  }
  return 0;
}


// ==== FUN_009149c2 @ 0x009149c2 ====

void FUN_009149c2(undefined4 param_1)

{
  DAT_00b602ac = 0;
  DAT_00b602b0 = param_1;
  return;
}


// ==== FUN_009149da @ 0x009149da ====

void FUN_009149da(int param_1)

{
  FUN_008f33e7(param_1 << 2,0x10);
  return;
}


// ==== FUN_009149f7 @ 0x009149f7 ====

void FUN_009149f7(undefined4 param_1)

{
  if (DAT_00b602ac == 0) {
    FUN_008f33e7(param_1,0x10);
  }
  else {
    DAT_00b602ac = *(int *)(DAT_00b602ac + 0x70);
  }
  return;
}


// ==== FUN_00914a24 @ 0x00914a24 ====

void FUN_00914a24(int param_1)

{
  if (param_1 != 0) {
    *(int *)(param_1 + 0x70) = DAT_00b602ac;
    DAT_00b602ac = param_1;
  }
  return;
}


// ==== FUN_00914a42 @ 0x00914a42 ====

undefined4 FUN_00914a42(uint param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint *in_ECX;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
  
  uVar1 = param_1 & 0xfffff;
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[3] = param_3;
  if (param_4 == 0) {
    uVar4 = param_1 & 0xf0000000;
    if (uVar4 == 0) {
      param_2 = 0;
      param_3 = 0;
      goto LAB_00914be4;
    }
    if (uVar4 == 0x10000000) goto LAB_00914bb8;
    if (uVar4 == 0x20000000) {
      param_2 = uVar1 * 2;
LAB_00914bba:
      param_3 = uVar1;
    }
    else {
      if (uVar4 == 0x30000000) {
        param_2 = uVar1 * 3;
        goto LAB_00914bba;
      }
      if (uVar4 == 0x40000000) {
        param_2 = uVar1 << 2;
        goto LAB_00914bba;
      }
      if (uVar4 == 0x50000000) {
        param_1 = param_1 & 0xfff00000;
        if (param_1 != 0x50000000) {
          if (param_1 != 0x50100000) {
            if (param_1 == 0x50200000) {
              param_2 = uVar1;
              goto LAB_00914bca;
            }
            if (param_1 != 0x50300000) goto LAB_00914be4;
          }
LAB_00914bb8:
          param_2 = uVar1;
          goto LAB_00914bba;
        }
        param_2 = uVar1 * 2;
        if (param_3 == 0xffffffff) {
LAB_00914bca:
          param_3 = 1;
        }
      }
      else if (uVar4 == 0x60000000) {
        param_1 = param_1 & 0xfff00000;
        if (param_1 < 0x60a00001) {
          if (param_1 != 0x60a00000) {
            if (param_1 < 0x60500001) {
              if ((param_1 == 0x60500000) || (param_1 == 0x60000000)) {
                param_2 = 4;
                param_3 = param_2;
                goto LAB_00914be4;
              }
              if (((param_1 != 0x60100000) && (param_1 != 0x60200000)) && (param_1 != 0x60300000)) {
                bVar6 = param_1 == 0x60400000;
                goto LAB_00914b04;
              }
            }
            else if (((param_1 != 0x60600000) && (param_1 != 0x60700000)) && (param_1 != 0x60800000)
                    ) {
              bVar6 = param_1 == 0x60900000;
LAB_00914b04:
              if (!bVar6) goto LAB_00914be4;
            }
            goto LAB_00914b0a;
          }
LAB_00914b38:
          param_2 = 6;
        }
        else {
          if (param_1 < 0x60f00001) {
            if (param_1 == 0x60f00000) goto LAB_00914b38;
            if (param_1 == 0x60b00000) goto LAB_00914b8a;
            if ((param_1 != 0x60c00000) && (param_1 != 0x60d00000)) {
              bVar6 = param_1 == 0x60e00000;
              goto LAB_00914b04;
            }
          }
          else {
            if (param_1 == 0x61000000) {
LAB_00914b8a:
              param_2 = 0xc;
              goto LAB_00914b8c;
            }
            if ((param_1 != 0x61100000) && (param_1 != 0x61200000)) {
              bVar6 = param_1 == 0x61300000;
              goto LAB_00914b04;
            }
          }
LAB_00914b0a:
          param_2 = 8;
        }
LAB_00914b8c:
        param_3 = 4;
      }
    }
LAB_00914be4:
    if (in_ECX[1] == 0xffffffff) {
      in_ECX[1] = param_2;
    }
    if (in_ECX[3] == 0xffffffff) {
      in_ECX[3] = param_3;
    }
    if ((((in_ECX[1] != param_2) || (in_ECX[3] != param_3)) || (in_ECX[1] == 0xffffffff)) ||
       (in_ECX[3] == 0xffffffff)) {
      return 0x80004005;
    }
  }
  if (in_ECX[1] < 9) {
    in_ECX[2] = (uint)(in_ECX + 0x10);
LAB_00914c33:
    if (in_ECX[3] < 5) {
      in_ECX[4] = (uint)(in_ECX + 0x18);
    }
    else {
      uVar1 = FUN_009149da(in_ECX[3]);
      in_ECX[4] = uVar1;
      if (uVar1 == 0) goto LAB_00914c9a;
    }
    puVar5 = (undefined4 *)in_ECX[2];
    for (uVar1 = in_ECX[1] & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar5 = 0xffffffff;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = 0xff;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    puVar5 = (undefined4 *)in_ECX[4];
    for (uVar1 = in_ECX[3] & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar5 = 0xffffffff;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = 0xff;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    uVar2 = 0;
  }
  else {
    uVar1 = FUN_009149da(in_ECX[1]);
    in_ECX[2] = uVar1;
    if (uVar1 != 0) goto LAB_00914c33;
LAB_00914c9a:
    uVar2 = 0x8007000e;
  }
  return uVar2;
}


// ==== FUN_00914ca1 @ 0x00914ca1 ====

undefined4 FUN_00914ca1(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0x80004005;
  }
  else {
    *in_ECX = *param_1;
    uVar1 = param_1[1];
    if ((uint)in_ECX[1] < uVar1) {
      if (uVar1 < 9) {
        in_ECX[2] = in_ECX + 0x10;
      }
      else {
        iVar3 = FUN_009149da(uVar1);
        in_ECX[2] = iVar3;
        if (iVar3 == 0) {
          return 0x8007000e;
        }
      }
    }
    iVar3 = param_1[1];
    in_ECX[1] = iVar3;
    puVar4 = (undefined4 *)param_1[2];
    puVar5 = (undefined4 *)in_ECX[2];
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    uVar1 = param_1[3];
    if ((uint)in_ECX[3] < uVar1) {
      if (uVar1 < 5) {
        in_ECX[4] = in_ECX + 0x18;
      }
      else {
        iVar3 = FUN_009149da(uVar1);
        in_ECX[4] = iVar3;
        if (iVar3 == 0) {
          return 0x8007000e;
        }
      }
    }
    iVar3 = param_1[3];
    in_ECX[3] = iVar3;
    puVar4 = (undefined4 *)param_1[4];
    puVar5 = (undefined4 *)in_ECX[4];
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    in_ECX[9] = param_1[9];
    in_ECX[10] = param_1[10];
    in_ECX[0xc] = param_1[0xc];
    in_ECX[0xf] = param_1[0xf];
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_00914d55 @ 0x00914d55 ====

uint FUN_00914d55(int param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint *in_ECX;
  
  uVar2 = *in_ECX;
  uVar1 = uVar2 & 0xfff00000;
  if (uVar1 == 0) {
    uVar2 = 0;
    goto LAB_00914da3;
  }
  if (uVar1 != 0x50000000) {
    if (uVar1 == 0x50200000) {
      uVar2 = 1;
      goto LAB_00914da3;
    }
    if (uVar1 != 0x70800000) {
      if ((uVar2 & 0xf0000000) == 0x60000000) {
        uVar2 = 4;
      }
      else {
        uVar2 = uVar2 & 0xfffff;
      }
      goto LAB_00914da3;
    }
  }
  uVar2 = in_ECX[3];
LAB_00914da3:
  if (in_ECX[3] < uVar2 * param_1 + uVar2) {
    if (param_2 != (int *)0x0) {
      *param_2 = 0;
    }
    uVar2 = 0;
  }
  else if (param_2 != (int *)0x0) {
    *param_2 = in_ECX[4] + uVar2 * param_1 * 4;
  }
  return uVar2;
}


// ==== FUN_00914dd4 @ 0x00914dd4 ====

undefined4 FUN_00914dd4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 *in_ECX;
  
  *(undefined8 *)(in_ECX + 8) = param_4;
  in_ECX[3] = param_2;
  *(undefined8 *)(in_ECX + 10) = param_4;
  in_ECX[1] = param_1;
  in_ECX[4] = param_3;
  in_ECX[2] = 0xffffffff;
  in_ECX[5] = 0xffffffff;
  in_ECX[0xc] = 0xffffffff;
  in_ECX[0xd] = 0xffffffff;
  in_ECX[0xe] = 0xffffffff;
  in_ECX[0x10] = 0xffffffff;
  in_ECX[0x11] = 0xffffffff;
  in_ECX[0x12] = 0xffffffff;
  in_ECX[0x13] = 0xffffffff;
  in_ECX[0x14] = 0xffffffff;
  in_ECX[0x15] = 0xffffffff;
  in_ECX[0x16] = 0xffffffff;
  in_ECX[0x1b] = 0xffffffff;
  in_ECX[0x1d] = 0xffffffff;
  in_ECX[6] = 1;
  *in_ECX = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1c] = 0;
  return 0;
}


// ==== FUN_00914e44 @ 0x00914e44 ====

undefined4 FUN_00914e44(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    in_ECX[1] = param_1[1];
    in_ECX[2] = param_1[2];
    in_ECX[3] = param_1[3];
    in_ECX[4] = param_1[4];
    in_ECX[5] = param_1[5];
    in_ECX[6] = param_1[6];
    *(undefined8 *)(in_ECX + 8) = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)(in_ECX + 10) = *(undefined8 *)(param_1 + 10);
    *in_ECX = *param_1;
    in_ECX[0xc] = param_1[0xc];
    in_ECX[0xd] = param_1[0xd];
    in_ECX[0xe] = param_1[0xe];
    in_ECX[0x10] = param_1[0x10];
    in_ECX[0xf] = param_1[0xf];
    in_ECX[0x11] = param_1[0x11];
    in_ECX[0x12] = param_1[0x12];
    in_ECX[0x13] = param_1[0x13];
    in_ECX[0x14] = param_1[0x14];
    in_ECX[0x15] = param_1[0x15];
    in_ECX[0x16] = param_1[0x16];
    in_ECX[0x17] = param_1[0x17];
    in_ECX[0x18] = param_1[0x18];
    in_ECX[0x19] = param_1[0x19];
    in_ECX[0x1a] = param_1[0x1a];
    in_ECX[0x1b] = param_1[0x1b];
    in_ECX[0x1c] = param_1[0x1c];
    in_ECX[0x1d] = param_1[0x1d];
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00914f00 @ 0x00914f00 ====

undefined4 FUN_00914f00(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 == 0) {
    uVar1 = 0x80004005;
  }
  else {
    *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 100);
    *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
    *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(param_1 + 0x70);
    *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(param_1 + 0x74);
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00914f3d @ 0x00914f3d ====

void FUN_00914f3d(undefined4 param_1)

{
  DAT_00b602b4 = 0;
  DAT_00b602b8 = param_1;
  return;
}


// ==== FUN_00914f55 @ 0x00914f55 ====

void FUN_00914f55(undefined4 param_1)

{
  if (DAT_00b602b4 == 0) {
    FUN_008f33e7(param_1,0x10);
  }
  else {
    DAT_00b602b4 = *(int *)(DAT_00b602b4 + 0x78);
  }
  return;
}


// ==== FUN_00914f82 @ 0x00914f82 ====

void FUN_00914f82(int param_1)

{
  if (param_1 != 0) {
    *(int *)(param_1 + 0x78) = DAT_00b602b4;
    DAT_00b602b4 = param_1;
  }
  return;
}


// ==== FUN_00914fa0 @ 0x00914fa0 ====

void FUN_00914fa0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a2955c;
  in_ECX[1] = 0;
  in_ECX[7] = 0;
  in_ECX[4] = 0;
  in_ECX[2] = 0;
  in_ECX[8] = 0;
  in_ECX[5] = 0;
  in_ECX[3] = 0;
  in_ECX[9] = 0;
  in_ECX[6] = 0;
  return;
}


// ==== FUN_00914fc6 @ 0x00914fc6 ====

void FUN_00914fc6(byte param_1)

{
  void *in_ECX;
  
  FUN_0095cf1d();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00914fe7 @ 0x00914fe7 ====

int FUN_00914fe7(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int extraout_EAX;
  int in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x1c);
  if (*(int *)(in_ECX + 4) == local_8) {
    if (local_8 == 0) {
      local_8 = 0x10;
    }
    else {
      local_8 = local_8 * 2;
    }
    puVar1 = operator_new(local_8 << 2);
    if (puVar1 != (undefined4 *)0x0) {
      puVar4 = *(undefined4 **)(in_ECX + 0x10);
      puVar5 = puVar1;
      for (uVar3 = *(uint *)(in_ECX + 4) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      puVar1 = puVar1 + *(int *)(in_ECX + 4);
      for (uVar3 = local_8 - *(int *)(in_ECX + 4) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar1 = 0;
        puVar1 = (undefined4 *)((int)puVar1 + 1);
      }
      _free(*(void **)(in_ECX + 0x10));
      return extraout_EAX;
    }
    if (param_1 != 0) {
      FUN_00914fc6(1);
    }
    iVar2 = -1;
  }
  else {
    *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 4) * 4) = param_1;
    iVar2 = *(int *)(in_ECX + 4);
    *(int *)(in_ECX + 4) = iVar2 + 1;
  }
  return iVar2;
}


// ==== FUN_009150a1 @ 0x009150a1 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_009150a1(uint *param_1)

{
  float10 fVar1;
  double dVar2;
  undefined4 *puVar3;
  int iVar4;
  int extraout_EAX;
  int in_ECX;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float10 extraout_ST0;
  int local_8;
  
  dVar2 = _DAT_0099d098;
  local_8 = *(int *)(in_ECX + 0x20);
  if (*(int *)(in_ECX + 8) == local_8) {
    if (local_8 == 0) {
      local_8 = 0x400;
    }
    else {
      local_8 = local_8 * 2;
    }
    puVar3 = operator_new(local_8 << 2);
    if (puVar3 != (undefined4 *)0x0) {
      puVar6 = *(undefined4 **)(in_ECX + 0x14);
      puVar7 = puVar3;
      for (uVar5 = *(uint *)(in_ECX + 8) & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      puVar3 = puVar3 + *(int *)(in_ECX + 8);
      for (uVar5 = local_8 - *(int *)(in_ECX + 8) & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
      _free(*(void **)(in_ECX + 0x14));
      return extraout_EAX;
    }
    if (param_1 != (uint *)0x0) {
      FUN_008f61e7(1);
    }
    iVar4 = -1;
  }
  else {
    if (((param_1 != (uint *)0x0) &&
        ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + param_1[1] * 4) + 5) & 1) != 0)) &&
       (param_1[2] == 0xffffffff)) {
      *(byte *)param_1 = (byte)*param_1 | 0x80;
      if ((dVar2 == *(double *)(param_1 + 8)) || (_DAT_0099d0a0 == *(double *)(param_1 + 8))) {
        *param_1 = *param_1 | 1;
      }
      iVar4 = __ftol();
      if (ABS(*(double *)(param_1 + 8) - (double)iVar4) < _DAT_00a168b8) {
        *param_1 = *param_1 | 2;
      }
      fVar1 = (float10)*(double *)(param_1 + 8);
      if ((!NAN(extraout_ST0) && !NAN(fVar1)) && extraout_ST0 < fVar1 != (extraout_ST0 == fVar1)) {
        *param_1 = *param_1 | 4;
      }
      if ((float10)*(double *)(param_1 + 8) <= extraout_ST0) {
        *param_1 = *param_1 | 8;
      }
      dVar2 = ABS(*(double *)(param_1 + 8));
      if ((!NAN(dVar2) && !NAN(_DAT_0099d0a0)) && dVar2 < _DAT_0099d0a0 != (dVar2 == _DAT_0099d0a0))
      {
        *param_1 = *param_1 | 0x10;
      }
    }
    *(uint **)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8) * 4) = param_1;
    iVar4 = *(int *)(in_ECX + 8);
    *(int *)(in_ECX + 8) = iVar4 + 1;
  }
  return iVar4;
}


// ==== FUN_00915205 @ 0x00915205 ====

int FUN_00915205(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int extraout_EAX;
  int in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x24);
  if (*(int *)(in_ECX + 0xc) == local_8) {
    if (local_8 == 0) {
      local_8 = 0x100;
    }
    else {
      local_8 = local_8 * 2;
    }
    puVar1 = operator_new(local_8 << 2);
    if (puVar1 != (undefined4 *)0x0) {
      puVar4 = *(undefined4 **)(in_ECX + 0x18);
      puVar5 = puVar1;
      for (uVar3 = *(uint *)(in_ECX + 0xc) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      puVar1 = puVar1 + *(int *)(in_ECX + 0xc);
      for (uVar3 = local_8 - *(int *)(in_ECX + 0xc) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar1 = 0;
        puVar1 = (undefined4 *)((int)puVar1 + 1);
      }
      _free(*(void **)(in_ECX + 0x18));
      return extraout_EAX;
    }
    if (param_1 != 0) {
      FUN_008f4adb(1);
    }
    iVar2 = -1;
  }
  else {
    *(int *)(*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0xc) * 4) = param_1;
    iVar2 = *(int *)(in_ECX + 0xc);
    *(int *)(in_ECX + 0xc) = iVar2 + 1;
  }
  return iVar2;
}


// ==== FUN_009152bf @ 0x009152bf ====

undefined4 FUN_009152bf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  pvVar1 = operator_new(0x34);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0079e14e();
  }
  if (iVar2 != 0) {
    iVar3 = FUN_0095cf1e(param_1,param_2,param_3,param_4);
    if (-1 < iVar3) {
      uVar4 = FUN_00914fe7(iVar2);
      return uVar4;
    }
    FUN_00914fc6(1);
  }
  return 0xffffffff;
}


// ==== FUN_00915318 @ 0x00915318 ====

undefined4 FUN_00915318(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00914f55();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0079e14e();
  }
  if (iVar1 != 0) {
    iVar1 = FUN_00914dd4(param_1,param_2,param_3,param_4);
    if (-1 < iVar1) {
      uVar2 = FUN_009150a1();
      return uVar2;
    }
    FUN_008f61e7();
  }
  return 0xffffffff;
}


// ==== FUN_00915378 @ 0x00915378 ====

undefined4 FUN_00915378(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_009149f7(0x74);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0091455d();
  }
  if (iVar1 != 0) {
    iVar2 = FUN_00914a42(param_1,param_2,param_3,0);
    if (-1 < iVar2) {
      uVar3 = FUN_00915205(iVar1);
      return uVar3;
    }
    FUN_008f4adb(1);
  }
  return 0xffffffff;
}


// ==== FUN_009153cf @ 0x009153cf ====

undefined4 FUN_009153cf(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  pvVar1 = operator_new(0x34);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0079e14e();
  }
  if (iVar2 != 0) {
    iVar3 = FUN_0095cf66(param_1);
    if (-1 < iVar3) {
      uVar4 = FUN_00914fe7(iVar2);
      return uVar4;
    }
    FUN_00914fc6(1);
  }
  return 0xffffffff;
}


// ==== FUN_0091541f @ 0x0091541f ====

undefined4 FUN_0091541f(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00914f55(0x80);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0079e14e();
  }
  if (iVar1 != 0) {
    iVar2 = FUN_00914e44(param_1);
    if (-1 < iVar2) {
      uVar3 = FUN_009150a1(iVar1);
      return uVar3;
    }
    FUN_008f61e7(1);
  }
  return 0xffffffff;
}


// ==== FUN_00915471 @ 0x00915471 ====

undefined4 FUN_00915471(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_009149f7(0x74);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0091455d();
  }
  if (iVar1 != 0) {
    iVar2 = FUN_00914ca1(param_1);
    if (-1 < iVar2) {
      uVar3 = FUN_00915205(iVar1);
      return uVar3;
    }
    FUN_008f4adb(1);
  }
  return 0xffffffff;
}


// ==== FUN_009154c0 @ 0x009154c0 ====

char * FUN_009154c0(int param_1)

{
  char *pcVar1;
  int in_ECX;
  
  pcVar1 = s_input_009fd774;
  if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(param_1 + 4) * 4) + 4) & 0x20) != 0) {
    pcVar1 = s_output_009fd76c;
  }
  return pcVar1;
}


// ==== FUN_009154e5 @ 0x009154e5 ====

void FUN_009154e5(void)

{
  undefined4 *in_ECX;
  uint uVar1;
  
  *in_ECX = &PTR_FUN_00a2955c;
  if (in_ECX[4] != 0) {
    uVar1 = 0;
    if (in_ECX[1] != 0) {
      do {
        if (*(int *)(in_ECX[4] + uVar1 * 4) != 0) {
          FUN_00914fc6(1);
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < (uint)in_ECX[1]);
    }
    _free((void *)in_ECX[4]);
    return;
  }
  if (in_ECX[5] != 0) {
    uVar1 = 0;
    if (in_ECX[2] != 0) {
      do {
        if (*(int *)(in_ECX[5] + uVar1 * 4) != 0) {
          FUN_008f61e7(1);
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < (uint)in_ECX[2]);
    }
    _free((void *)in_ECX[5]);
    return;
  }
  if (in_ECX[6] == 0) {
    return;
  }
  uVar1 = 0;
  if (in_ECX[3] != 0) {
    do {
      if (*(int *)(in_ECX[6] + uVar1 * 4) != 0) {
        FUN_008f4adb(1);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)in_ECX[3]);
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_0091557c @ 0x0091557c ====

undefined4 FUN_0091557c(int param_1)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  uVar3 = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  iVar2 = *(int *)(param_1 + 4);
  *(int *)(in_ECX + 0x1c) = iVar2;
  pvVar1 = operator_new(iVar2 << 2);
  *(void **)(in_ECX + 0x10) = pvVar1;
  if (pvVar1 != (void *)0x0) {
    if (*(int *)(param_1 + 4) != 0) {
      do {
        iVar2 = FUN_009153cf(*(undefined4 *)(*(int *)(param_1 + 0x10) + uVar3 * 4));
        if (iVar2 == -1) {
          return 0x8007000e;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(param_1 + 4));
    }
    *(undefined4 *)(in_ECX + 8) = 0;
    iVar2 = *(int *)(param_1 + 8);
    *(int *)(in_ECX + 0x20) = iVar2;
    pvVar1 = operator_new(iVar2 << 2);
    uVar3 = 0;
    *(void **)(in_ECX + 0x14) = pvVar1;
    if (pvVar1 != (void *)0x0) {
      if (*(int *)(param_1 + 8) != 0) {
        do {
          iVar2 = FUN_0091541f(*(undefined4 *)(*(int *)(param_1 + 0x14) + uVar3 * 4));
          if (iVar2 == -1) {
            return 0x8007000e;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(param_1 + 8));
      }
      *(undefined4 *)(in_ECX + 0xc) = 0;
      iVar2 = *(int *)(param_1 + 0xc);
      *(int *)(in_ECX + 0x24) = iVar2;
      pvVar1 = operator_new(iVar2 << 2);
      uVar3 = 0;
      *(void **)(in_ECX + 0x18) = pvVar1;
      if (pvVar1 != (void *)0x0) {
        if (*(int *)(param_1 + 0xc) != 0) {
          do {
            iVar2 = FUN_00915471(*(undefined4 *)(*(int *)(param_1 + 0x18) + uVar3 * 4));
            if (iVar2 == -1) {
              return 0x8007000e;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *(uint *)(param_1 + 0xc));
        }
        return 0;
      }
    }
  }
  return 0x8007000e;
}


// ==== FUN_0091564e @ 0x0091564e ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0091564e(int param_1,char *param_2,size_t param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  char local_48 [63];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  _strncpy(local_48,*(char **)(*(int *)(param_1 + 0x68) + 0x18),0x3f);
  pcVar2 = local_48;
  local_9 = 0;
  uVar1 = FUN_009154c0(param_1);
  __snprintf(param_2,param_3,s__s_semantic___s__00a29560,uVar1,pcVar2);
  param_2[param_3 - 1] = '\0';
  return 0;
}


// ==== FUN_009156b6 @ 0x009156b6 ====

void FUN_009156b6(byte param_1)

{
  void *in_ECX;
  
  FUN_009154e5();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_009156d7 @ 0x009156d7 ====

undefined4 FUN_009156d7(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*(int *)(param_3 + 0x14) + param_2 * 4);
  iVar2 = *(int *)(*(int *)(param_3 + 0x14) + param_1 * 4);
  if (*(uint *)(iVar2 + 4) < *(uint *)(iVar1 + 4)) {
LAB_00915708:
    uVar3 = 0xffffffff;
  }
  else {
    if (*(uint *)(iVar2 + 4) <= *(uint *)(iVar1 + 4)) {
      if (*(double *)(iVar2 + 0x20) < *(double *)(iVar1 + 0x20)) goto LAB_00915708;
      if (*(double *)(iVar2 + 0x20) <= *(double *)(iVar1 + 0x20)) {
        return 0;
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}


// ==== FUN_00915726 @ 0x00915726 ====

uint FUN_00915726(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_3 + 0x14) + param_1 * 4);
  iVar2 = *(int *)(*(int *)(param_3 + 0x14) + param_2 * 4);
  if (*(uint *)(iVar2 + 0x38) <= *(uint *)(iVar1 + 0x38)) {
    if (*(uint *)(iVar2 + 0x38) < *(uint *)(iVar1 + 0x38)) {
      return 1;
    }
    if (*(uint *)(iVar2 + 0x3c) <= *(uint *)(iVar1 + 0x3c)) {
      if (*(uint *)(iVar2 + 0x3c) < *(uint *)(iVar1 + 0x3c)) {
        return 1;
      }
      if (*(uint *)(iVar2 + 4) <= *(uint *)(iVar1 + 4)) {
        if (*(uint *)(iVar2 + 4) < *(uint *)(iVar1 + 4)) {
          return 1;
        }
        if (*(uint *)(iVar2 + 0xc) <= *(uint *)(iVar1 + 0xc)) {
          if (*(uint *)(iVar2 + 0xc) < *(uint *)(iVar1 + 0xc)) {
            return 1;
          }
          if (*(uint *)(iVar2 + 8) <= *(uint *)(iVar1 + 8)) {
            if (*(uint *)(iVar2 + 8) < *(uint *)(iVar1 + 8)) {
              return 1;
            }
            if (*(uint *)(iVar2 + 0x10) <= *(uint *)(iVar1 + 0x10)) {
              if (*(uint *)(iVar2 + 0x10) < *(uint *)(iVar1 + 0x10)) {
                return 1;
              }
              if (*(uint *)(iVar2 + 0x14) <= *(uint *)(iVar1 + 0x14)) {
                if (*(uint *)(iVar2 + 0x14) < *(uint *)(iVar1 + 0x14)) {
                  return 1;
                }
                if (*(int *)(iVar2 + 0x18) <= *(int *)(iVar1 + 0x18)) {
                  return (uint)(*(int *)(iVar2 + 0x18) < *(int *)(iVar1 + 0x18));
                }
              }
            }
          }
        }
      }
    }
  }
  return 0xffffffff;
}


// ==== FUN_009157b4 @ 0x009157b4 ====

uint FUN_009157b4(uint param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 < param_2) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)(param_2 < param_1);
  }
  return uVar1;
}


// ==== FUN_009157ce @ 0x009157ce ====

uint FUN_009157ce(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_3 + 0x18) + param_1 * 4) + 0x30);
  iVar2 = *(int *)(*(int *)(*(int *)(param_3 + 0x18) + param_2 * 4) + 0x30);
  if (iVar2 <= iVar1) {
    if (iVar2 < iVar1) {
      return 1;
    }
    if (param_2 <= param_1) {
      return (uint)(param_2 < param_1);
    }
  }
  return 0xffffffff;
}


// ==== FUN_00915809 @ 0x00915809 ====

uint FUN_00915809(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar2 = param_3;
  iVar5 = *(int *)(*(int *)(param_3 + 0x18) + param_1 * 4);
  iVar8 = *(int *)(*(int *)(param_3 + 0x18) + param_2 * 4);
  iVar6 = *(int *)(iVar8 + 0x34);
  iVar7 = *(int *)(iVar5 + 0x34);
  local_c = 0;
  param_3 = 0;
  iVar4 = iVar6;
  uVar1 = param_3;
  if (iVar7 != -1) {
    iVar3 = iVar7;
    do {
      iVar3 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + iVar3 * 4) + 0x14);
      local_c = local_c + 1;
    } while (iVar3 != -1);
  }
  for (; iVar4 != -1; iVar4 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + iVar4 * 4) + 0x14)) {
    uVar1 = uVar1 + 1;
  }
  uVar9 = local_c;
  if (uVar1 < local_c) {
    iVar4 = local_c - uVar1;
    do {
      iVar7 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + iVar7 * 4) + 0x14);
      uVar9 = uVar9 - 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  param_3 = uVar1;
  if (uVar9 < uVar1) {
    iVar4 = uVar1 - uVar9;
    do {
      param_3 = param_3 - 1;
      iVar4 = iVar4 + -1;
      iVar6 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + iVar6 * 4) + 0x14);
    } while (iVar4 != 0);
  }
  if (iVar7 != iVar6) {
    do {
      iVar7 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + iVar7 * 4) + 0x14);
      iVar6 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + iVar6 * 4) + 0x14);
      uVar9 = uVar9 - 1;
      param_3 = param_3 - 1;
    } while (iVar7 != iVar6);
  }
  iVar7 = *(int *)(iVar5 + 0x34);
  iVar6 = *(int *)(iVar8 + 0x34);
  local_8 = param_1;
  local_10 = param_1;
  if (uVar9 < local_c) {
    local_c = local_c - uVar9;
    do {
      iVar7 = *(int *)(*(int *)(iVar2 + 0x14) + iVar7 * 4);
      if (*(uint *)(iVar7 + 0x48) < local_8) {
        local_8 = *(uint *)(iVar7 + 0x48);
      }
      if (local_10 < *(uint *)(iVar7 + 0x58)) {
        local_10 = *(uint *)(iVar7 + 0x58);
      }
      local_c = local_c + -1;
      iVar7 = *(int *)(iVar7 + 0x14);
    } while (local_c != 0);
  }
  local_c = param_2;
  uVar9 = param_2;
  if (param_3 < uVar1) {
    param_3 = uVar1 - param_3;
    do {
      iVar7 = *(int *)(*(int *)(iVar2 + 0x14) + iVar6 * 4);
      if (*(uint *)(iVar7 + 0x48) < uVar9) {
        uVar9 = *(uint *)(iVar7 + 0x48);
      }
      if (local_c < *(uint *)(iVar7 + 0x58)) {
        local_c = *(uint *)(iVar7 + 0x58);
      }
      param_3 = param_3 + -1;
      iVar6 = *(int *)(iVar7 + 0x14);
    } while (param_3 != 0);
  }
  if (((uVar9 <= param_1) && (param_1 <= local_c)) ||
     ((local_8 <= param_2 && (param_2 <= local_10)))) {
    if (local_8 < uVar9) {
      return 1;
    }
    if (uVar9 < local_8) {
      return 0xffffffff;
    }
  }
  iVar5 = *(int *)(*(int *)(iVar2 + 0x14) + **(int **)(iVar5 + 0x10) * 4);
  iVar8 = *(int *)(*(int *)(iVar2 + 0x14) + **(int **)(iVar8 + 0x10) * 4);
  iVar6 = *(int *)(iVar8 + 0x18);
  iVar7 = *(int *)(iVar5 + 0x18);
  iVar4 = *(int *)(iVar5 + 0x14);
  local_10 = 0;
  param_3 = 0;
  iVar8 = *(int *)(iVar8 + 0x14);
  for (iVar5 = iVar4; iVar3 = iVar8, iVar5 != -1;
      iVar5 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + iVar5 * 4) + 0x14)) {
    local_10 = local_10 + 1;
  }
  for (; iVar3 != -1; iVar3 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + iVar3 * 4) + 0x14)) {
    param_3 = param_3 + 1;
  }
  if (param_3 < local_10) {
    iVar5 = local_10 - param_3;
    do {
      iVar4 = *(int *)(*(int *)(iVar2 + 0x14) + iVar4 * 4);
      iVar7 = *(int *)(iVar4 + 0x18);
      iVar4 = *(int *)(iVar4 + 0x14);
      local_10 = local_10 - 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (local_10 < param_3) {
    iVar5 = param_3 - local_10;
    do {
      iVar5 = iVar5 + -1;
      iVar8 = *(int *)(*(int *)(iVar2 + 0x14) + iVar8 * 4);
      iVar6 = *(int *)(iVar8 + 0x18);
      iVar8 = *(int *)(iVar8 + 0x14);
    } while (iVar5 != 0);
  }
  if (iVar4 != iVar8) {
    do {
      iVar5 = *(int *)(*(int *)(iVar2 + 0x14) + iVar4 * 4);
      iVar8 = *(int *)(*(int *)(iVar2 + 0x14) + iVar8 * 4);
      iVar7 = *(int *)(iVar5 + 0x18);
      iVar6 = *(int *)(iVar8 + 0x18);
      iVar4 = *(int *)(iVar5 + 0x14);
      iVar8 = *(int *)(iVar8 + 0x14);
    } while (iVar4 != iVar8);
  }
  if (iVar7 == 0) {
    if (iVar6 != 0) {
      return 1;
    }
  }
  else if (iVar6 == 0) {
    return 0xffffffff;
  }
  if (param_1 < param_2) {
    return 0xffffffff;
  }
  return (uint)(param_2 < param_1);
}


// ==== FUN_00915a46 @ 0x00915a46 ====

uint FUN_00915a46(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_EAX;
  int in_ECX;
  int in_EDX;
  
  iVar2 = *(int *)(*(int *)(in_EAX + 0xbc) + 0x58);
  iVar1 = iVar2 + in_ECX * 0xc;
  iVar2 = iVar2 + in_EDX * 0xc;
  uVar3 = *(uint *)(iVar1 + 4);
  uVar4 = *(uint *)(iVar2 + 4);
  if (uVar4 <= uVar3) {
    if (uVar4 < uVar3) {
      return 1;
    }
    iVar1 = *(int *)(iVar1 + 8);
    iVar2 = *(int *)(iVar2 + 8);
    if (iVar2 <= iVar1) {
      return (uint)(iVar2 < iVar1);
    }
  }
  return 0xffffffff;
}


// ==== FUN_00915a87 @ 0x00915a87 ====

uint FUN_00915a87(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(*(int *)(param_3 + 0xbc) + 0x58);
  uVar3 = *(uint *)(iVar1 + param_1 * 0xc);
  uVar2 = *(uint *)(iVar1 + param_2 * 0xc);
  if (uVar2 < uVar3) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = (uint)(uVar3 < uVar2);
  }
  return uVar3;
}


// ==== FUN_00915abf @ 0x00915abf ====

void FUN_00915abf(void)

{
  int iVar1;
  
  iVar1 = FUN_00915a46();
  if (iVar1 == 0) {
    FUN_00915a87();
    return;
  }
  return;
}


// ==== FUN_00915ae0 @ 0x00915ae0 ====

uint FUN_00915ae0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(*(int *)(param_3 + 0x14) + param_1 * 4) + 0x40);
  uVar1 = *(uint *)(*(int *)(*(int *)(param_3 + 0x14) + param_2 * 4) + 0x40);
  if (uVar2 < uVar1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (uint)(uVar1 < uVar2);
  }
  return uVar2;
}


// ==== FUN_00915b0e @ 0x00915b0e ====

void FUN_00915b0e(code *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_c;
  uint local_8;
  
  puVar3 = param_2;
  if (1 < param_3) {
    uVar5 = param_3 >> 1;
    if (uVar5 != 0) {
      local_8 = uVar5 * 2 + 1;
      do {
        uVar5 = uVar5 - 1;
        uVar1 = puVar3[uVar5];
        local_8 = local_8 - 2;
        uVar8 = local_8;
        param_2 = (undefined4 *)uVar5;
        while (uVar8 < param_3) {
          local_c = puVar3[uVar8];
          uVar7 = uVar8;
          if (uVar8 + 1 < param_3) {
            uVar6 = puVar3[uVar8 + 1];
            iVar4 = (*param_1)(uVar6,local_c,param_4);
            if (0 < iVar4) {
              uVar7 = uVar8 + 1;
              local_c = uVar6;
            }
          }
          iVar4 = (*param_1)(local_c,uVar1,param_4);
          if (iVar4 < 1) break;
          puVar3[(int)param_2] = puVar3[uVar7];
          param_2 = (undefined4 *)uVar7;
          uVar8 = uVar7 * 2 + 1;
        }
        puVar3[(int)param_2] = uVar1;
      } while (uVar5 != 0);
    }
    while (param_3 = param_3 - 1, param_3 != 0) {
      param_2 = (undefined4 *)0x0;
      uVar1 = puVar3[param_3];
      uVar5 = 1;
      puVar3[param_3] = *puVar3;
      if (1 < param_3) {
        do {
          uVar6 = puVar3[uVar5];
          uVar8 = uVar5;
          if (uVar5 + 1 < param_3) {
            uVar2 = puVar3[uVar5 + 1];
            iVar4 = (*param_1)(uVar2,uVar6,param_4);
            if (0 < iVar4) {
              uVar6 = uVar2;
              uVar8 = uVar5 + 1;
            }
          }
          iVar4 = (*param_1)(uVar6,uVar1,param_4);
          if (iVar4 < 1) break;
          uVar5 = uVar8 * 2 + 1;
          puVar3[(int)param_2] = puVar3[uVar8];
          param_2 = (undefined4 *)uVar8;
        } while (uVar5 < param_3);
      }
      puVar3[(int)param_2] = uVar1;
    }
  }
  return;
}


// ==== FUN_00915c25 @ 0x00915c25 ====

void FUN_00915c25(void)

{
  undefined4 *in_ECX;
  
  FUN_00914fa0();
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x1d] = 0xffffffff;
  in_ECX[0x1e] = 0xffffffff;
  in_ECX[0x1f] = 0xffffffff;
  in_ECX[0x20] = 0xffffffff;
  in_ECX[0x21] = 0xffffffff;
  in_ECX[0x22] = 0xffffffff;
  in_ECX[0x23] = 0xffffffff;
  in_ECX[0x24] = 0xffffffff;
  in_ECX[0x25] = 0xffffffff;
  in_ECX[0x26] = 0xffffffff;
  in_ECX[0x27] = 0xffffffff;
  in_ECX[0x28] = 0xffffffff;
  in_ECX[0x2a] = 0xffffffff;
  in_ECX[0x2b] = 0xffffffff;
  in_ECX[0x2c] = 0xffffffff;
  in_ECX[0x2d] = 0xffffffff;
  in_ECX[0x2e] = 0xffffffff;
  *in_ECX = &PTR_FUN_00a29574;
  return;
}


// ==== FUN_00915ccb @ 0x00915ccb ====

void FUN_00915ccb(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a29574;
  _free((void *)in_ECX[0x34]);
  return;
}


// ==== FUN_00915cfa @ 0x00915cfa ====

undefined4 FUN_00915cfa(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar4;
  
  if (param_1 != (char *)0x0) {
    pcVar2 = param_1;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = pcVar2 + (1 - (int)(param_1 + 1));
    pcVar3 = operator_new((uint)pcVar2);
    if (pcVar3 == (char *)0x0) {
      return 0x8007000e;
    }
    for (uVar4 = (uint)pcVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)param_1;
      param_1 = param_1 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar4 = (uint)pcVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar3 = *param_1;
      param_1 = param_1 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  _free(*(void **)(in_ECX + 0xd0));
  return extraout_EAX;
}


// ==== FUN_00915d64 @ 0x00915d64 ====

undefined4 FUN_00915d64(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(uint *)(in_ECX + 0x6c) = *(uint *)(in_ECX + 0x6c) & 0xfffffffc;
  *(byte *)(in_ECX + 0x71) = *(byte *)(in_ECX + 0x71) | 2;
  *(undefined4 *)(in_ECX + 0x28) = 0x40;
  *(undefined4 *)(in_ECX + 0x2c) = 0x40;
  *(undefined4 *)(in_ECX + 0x38) = 0x2000;
  return 0;
}


// ==== FUN_00915d83 @ 0x00915d83 ====

void FUN_00915d83(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  if (param_4 == 0) {
    uVar2 = *(uint *)(*(int *)(param_1 + 8) + (*(int *)(param_1 + 0xc) * param_2 + param_3) * 4);
  }
  else {
    uVar1 = *(uint *)(*(int *)(param_1 + 8) + param_3 * 4);
    uVar2 = *(uint *)(*(int *)(param_1 + 8) + (*(int *)(param_1 + 0xc) + param_3) * 4);
    if (param_2 == 0) {
      if (uVar2 < uVar1) goto LAB_00915dcc;
    }
    else if (uVar1 <= uVar2) goto LAB_00915dcc;
    uVar2 = uVar1;
  }
LAB_00915dcc:
  while (uVar1 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar2 * 4) + 0x30), uVar2 != uVar1) {
    uVar2 = uVar1;
  }
  return;
}


// ==== FUN_00915de2 @ 0x00915de2 ====

undefined4 FUN_00915de2(void)

{
  return 0x80004001;
}


// ==== FUN_00915de8 @ 0x00915de8 ====

void FUN_00915de8(int param_1,uint *param_2)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4) + 0x14);
  uVar2 = 0;
  if (iVar1 != -1) {
    do {
      iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar1 * 4) + 0x14);
      uVar2 = uVar2 + 1;
    } while (iVar1 != -1);
    if (*param_2 < uVar2) {
      *param_2 = uVar2;
    }
  }
  return;
}


// ==== FUN_00915e19 @ 0x00915e19 ====

undefined4 FUN_00915e19(void)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar4 = 0;
  iVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + uVar4 * 4);
      if ((*(ushort *)(iVar2 + 2) & 0xfff0) == 0) {
        FUN_008f4adb(1);
      }
      else {
        *(int *)(*(int *)(in_ECX + 0x18) + iVar3 * 4) = iVar2;
        iVar3 = iVar3 + 1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 0xc));
  }
  if (iVar3 == *(int *)(in_ECX + 0xc)) {
    uVar1 = 1;
  }
  else {
    puVar5 = (undefined4 *)(*(int *)(in_ECX + 0x18) + iVar3 * 4);
    for (uVar4 = *(int *)(in_ECX + 0xc) - iVar3 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)puVar5 = 0;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    *(int *)(in_ECX + 0xc) = iVar3;
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00915e78 @ 0x00915e78 ====

undefined4 FUN_00915e78(int param_1)

{
  byte *pbVar1;
  int in_ECX;
  
  if (param_1 != -1) {
    do {
      pbVar1 = *(byte **)(*(int *)(in_ECX + 0x14) + param_1 * 4);
      if (((*pbVar1 & 0x20) != 0) ||
         ((*(int *)(pbVar1 + 0x38) != -1 &&
          ((**(byte **)(*(int *)(in_ECX + 0x14) + *(int *)(pbVar1 + 0x38) * 4) & 0x20) != 0)))) {
        return 1;
      }
      param_1 = *(int *)(pbVar1 + 8);
    } while (param_1 != -1);
  }
  return 0;
}


// ==== FUN_00915eb3 @ 0x00915eb3 ====

undefined4 FUN_00915eb3(void)

{
  uint *puVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  uVar6 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
      iVar5 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4);
      uVar4 = *(uint *)(iVar5 + 4);
      if (((uVar4 & 0x30) != 0) && ((uVar4 & 0x200) == 0)) {
        *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(in_ECX + 0x74);
      }
      if ((*(byte *)(iVar5 + 4) & 4) != 0) {
        *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(in_ECX + 0x88);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(in_ECX + 8));
  }
  local_14 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_14 * 4);
      uVar6 = *puVar1;
      if ((uVar6 & 0xfff00000) != 0) {
        local_c = 0;
        if (puVar1[3] != 0) {
          local_18 = puVar1[3];
          piVar2 = (int *)puVar1[4];
          do {
            if ((**(byte **)(*(int *)(in_ECX + 0x14) + *piVar2 * 4) & 0x20) != 0) {
              local_c = local_c + 1;
            }
            piVar2 = piVar2 + 1;
            local_18 = local_18 - 1;
          } while (local_18 != 0);
        }
        uVar4 = puVar1[3];
        if (local_c == uVar4) {
          *puVar1 = 0;
        }
        else {
          if (((local_c < uVar4) && (0xfffffff < (uVar6 & 0xf0000000))) &&
             ((uVar6 & 0xf0000000) < 0x40000001)) {
            uVar6 = puVar1[1] / (uVar6 & 0xfffff);
            uVar7 = 0;
            local_8 = 0;
            if (uVar4 != 0) {
              do {
                iVar3 = *(int *)(puVar1[4] + local_8 * 4);
                if ((**(byte **)(*(int *)(in_ECX + 0x14) + iVar3 * 4) & 0x20) == 0) {
                  local_10 = 0;
                  *(int *)(puVar1[4] + uVar7 * 4) = iVar3;
                  if (uVar6 != 0) {
                    do {
                      iVar3 = puVar1[3] * local_10;
                      local_10 = local_10 + 1;
                      *(undefined4 *)(puVar1[2] + (iVar3 + uVar7) * 4) =
                           *(undefined4 *)(puVar1[2] + (local_8 + iVar3) * 4);
                    } while (local_10 < uVar6);
                  }
                  uVar7 = uVar7 + 1;
                }
                local_8 = local_8 + 1;
              } while (local_8 < puVar1[3]);
            }
            local_8 = 1;
            if (1 < uVar6) {
              local_18 = uVar7 << 2;
              do {
                local_10 = 0;
                if (uVar7 != 0) {
                  uVar4 = local_18;
                  do {
                    iVar3 = puVar1[3] * local_8 + local_10;
                    local_10 = local_10 + 1;
                    *(undefined4 *)(uVar4 + puVar1[2]) = *(undefined4 *)(puVar1[2] + iVar3 * 4);
                    uVar4 = uVar4 + 4;
                  } while (local_10 < uVar7);
                }
                local_8 = local_8 + 1;
                local_18 = local_18 + uVar7 * 4;
              } while (local_8 < uVar6);
            }
            *puVar1 = *puVar1 ^ (*puVar1 ^ uVar7) & 0xfffff;
            puVar1[1] = uVar7 * uVar6;
            puVar1[3] = uVar7;
          }
          local_10 = 0;
          if (puVar1[3] != 0) {
            do {
              iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + local_10 * 4) * 4);
              local_18 = *(undefined4 *)(iVar3 + 0x18);
              iVar5 = *(int *)(iVar3 + 0x14);
              while ((iVar5 != -1 &&
                     ((**(byte **)(iVar5 * 4 + *(int *)(in_ECX + 0x14)) & 0x20) != 0))) {
                iVar5 = *(int *)(iVar5 * 4 + *(int *)(in_ECX + 0x14));
                local_18 = *(undefined4 *)(iVar5 + 0x18);
                iVar5 = *(int *)(iVar5 + 0x14);
              }
              local_10 = local_10 + 1;
              *(uint *)(iVar3 + 0x18) = local_18;
              *(int *)(iVar3 + 0x14) = iVar5;
            } while (local_10 < puVar1[3]);
          }
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < *(uint *)(in_ECX + 0xc));
  }
  return 0;
}


// ==== FUN_009160c4 @ 0x009160c4 ====

bool FUN_009160c4(void)

{
  uint *puVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  bVar2 = false;
  local_14 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_14 * 4);
      uVar4 = *puVar1;
      if ((((uVar4 & 0xfff00000) != 0) && ((uVar4 & 0xfff00000) != 0x10100000)) &&
         (local_8 = 0, puVar1[3] != 0)) {
        local_18 = puVar1[3];
        piVar3 = (int *)puVar1[4];
        do {
          if ((**(byte **)(*(int *)(in_ECX + 0x14) + *piVar3 * 4) & 0x20) == 0) {
            local_8 = local_8 + 1;
          }
          piVar3 = piVar3 + 1;
          local_18 = local_18 - 1;
        } while (local_18 != 0);
        if (local_8 != 0) {
          bVar2 = true;
          if (local_8 == puVar1[3]) {
            *puVar1 = 0;
          }
          else if (((local_8 < puVar1[3]) && (0xfffffff < (uVar4 & 0xf0000000))) &&
                  ((uVar4 & 0xf0000000) < 0x40000001)) {
            uVar4 = puVar1[1] / (uVar4 & 0xfffff);
            uVar7 = 0;
            uVar5 = 0;
            do {
              iVar6 = *(int *)(puVar1[4] + uVar5 * 4);
              if ((**(byte **)(*(int *)(in_ECX + 0x14) + iVar6 * 4) & 0x20) != 0) {
                local_c = 0;
                *(int *)(puVar1[4] + uVar7 * 4) = iVar6;
                if (uVar4 != 0) {
                  do {
                    iVar6 = puVar1[3] * local_c;
                    local_c = local_c + 1;
                    *(undefined4 *)(puVar1[2] + (iVar6 + uVar7) * 4) =
                         *(undefined4 *)(puVar1[2] + (iVar6 + uVar5) * 4);
                  } while (local_c < uVar4);
                }
                uVar7 = uVar7 + 1;
              }
              uVar5 = uVar5 + 1;
            } while (uVar5 < puVar1[3]);
            local_10 = 1;
            if (1 < uVar4) {
              local_18 = uVar7 << 2;
              do {
                local_c = 0;
                if (uVar7 != 0) {
                  uVar5 = local_18;
                  do {
                    iVar6 = puVar1[3] * local_10 + local_c;
                    local_c = local_c + 1;
                    *(undefined4 *)(uVar5 + puVar1[2]) = *(undefined4 *)(puVar1[2] + iVar6 * 4);
                    uVar5 = uVar5 + 4;
                  } while (local_c < uVar7);
                }
                local_10 = local_10 + 1;
                local_18 = local_18 + uVar7 * 4;
              } while (local_10 < uVar4);
            }
            *puVar1 = *puVar1 ^ (*puVar1 ^ uVar7) & 0xfffff;
            puVar1[1] = uVar7 * uVar4;
            puVar1[3] = uVar7;
          }
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < *(uint *)(in_ECX + 0xc));
  }
  return !bVar2;
}


// ==== FUN_0091625c @ 0x0091625c ====

undefined4 FUN_0091625c(int *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint local_8;
  
  iVar2 = *param_1;
  if ((iVar2 == -1) && (*param_2 == 0)) {
    *param_2 = param_4;
    iVar2 = param_3;
LAB_00916345:
    *param_1 = iVar2;
  }
  else if ((param_3 != -1) || (param_4 != 0)) {
    uVar3 = 0;
    local_8 = 0;
    if (iVar2 != -1) {
      iVar4 = iVar2;
      do {
        iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) + 0x14);
        uVar3 = uVar3 + 1;
      } while (iVar4 != -1);
    }
    if (param_3 != -1) {
      iVar4 = param_3;
      do {
        iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) + 0x14);
        local_8 = local_8 + 1;
      } while (iVar4 != -1);
    }
    iVar4 = *param_2;
    if (local_8 < uVar3) {
      iVar5 = uVar3 - local_8;
      do {
        iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4);
        iVar4 = *(int *)(iVar2 + 0x18);
        iVar2 = *(int *)(iVar2 + 0x14);
        uVar3 = uVar3 - 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    if (uVar3 < local_8) {
      iVar5 = local_8 - uVar3;
      do {
        iVar5 = iVar5 + -1;
        iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + param_3 * 4);
        param_4 = *(int *)(iVar1 + 0x18);
        param_3 = *(int *)(iVar1 + 0x14);
      } while (iVar5 != 0);
    }
    while( true ) {
      if ((iVar4 == param_4) && (iVar2 == param_3)) {
        *param_2 = iVar4;
        goto LAB_00916345;
      }
      if ((iVar2 == -1) || (param_3 == -1)) break;
      iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4);
      iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + param_3 * 4);
      iVar4 = *(int *)(iVar2 + 0x18);
      param_4 = *(int *)(iVar5 + 0x18);
      iVar2 = *(int *)(iVar2 + 0x14);
      param_3 = *(int *)(iVar5 + 0x14);
    }
    *param_2 = 0;
    *param_1 = -1;
  }
  return 0;
}


// ==== FUN_0091635e @ 0x0091635e ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0091635e(uint *param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  bool bVar3;
  double dVar4;
  uint *puVar5;
  uint uVar6;
  int in_ECX;
  int *piVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  uint *puVar14;
  undefined4 *puVar15;
  bool bVar16;
  double local_3c;
  int *local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  int *local_1c;
  uint local_18;
  int *local_14;
  int local_10;
  uint local_c;
  
  puVar5 = param_1;
  dVar4 = _DAT_0099d098;
  if ((*param_1 & 0xfff00000) != 0x50000000) {
    return true;
  }
  puVar1 = *(uint **)(*(int *)(in_ECX + 0x14) + *(int *)param_1[4] * 4);
  uVar12 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar1[1] * 4) + 4);
  if ((uVar12 & 1) == 0) {
    return true;
  }
  if ((uVar12 & 0x1000) != 0) {
    return true;
  }
  uVar12 = *param_1 & 0xfffff;
  local_18 = 0xe;
  if (uVar12 != 0) {
    piVar7 = (int *)param_1[2];
    local_14 = piVar7 + uVar12;
    local_24 = uVar12;
    do {
      iVar10 = *(int *)(in_ECX + 0x14);
      if (param_2 == 0) {
        puVar14 = *(uint **)(iVar10 + *piVar7 * 4);
        iVar11 = *local_14;
      }
      else {
        puVar14 = *(uint **)(iVar10 + *(int *)(*(int *)(iVar10 + *piVar7 * 4) + 0x30) * 4);
        iVar11 = *(int *)(*(int *)(iVar10 + *local_14 * 4) + 0x30);
      }
      puVar2 = *(uint **)(iVar10 + iVar11 * 4);
      uVar9 = *puVar14;
      local_c = 0;
      if (((((uVar9 & 4) != 0) && ((*puVar2 & 4) != 0)) ||
          (((uVar9 & 8) != 0 && ((*puVar2 & 8) != 0)))) || (puVar14 == puVar2)) {
        local_c = 4;
      }
      if ((((uVar9 & 4) != 0) && ((*puVar2 & 8) != 0)) ||
         (((uVar9 & 8) != 0 && ((*puVar2 & 4) != 0)))) {
        local_c = local_c | 8;
      }
      if (((uVar9 & 2) != 0) && ((*puVar2 & 2) != 0)) {
        local_c = local_c | 2;
      }
      local_18 = local_18 & local_c;
      local_14 = local_14 + 1;
      piVar7 = piVar7 + 1;
      local_24 = local_24 - 1;
    } while (local_24 != 0);
  }
  *puVar1 = *puVar1 | local_18;
  if (param_2 != 0) {
    local_24 = 0xffffffff;
    local_3c = 0.0;
    local_c = 0;
    local_10 = 0;
    local_20 = 0;
    if (uVar12 != 0) {
      local_1c = (int *)param_1[2];
      iVar10 = *(int *)(in_ECX + 0x14);
      local_2c = local_1c + uVar12;
      do {
        uVar9 = *(uint *)(*(int *)(iVar10 + *local_2c * 4) + 0x30);
        uVar6 = *(uint *)(*(int *)(iVar10 + *local_1c * 4) + 0x30);
        iVar11 = *(int *)(iVar10 + uVar9 * 4);
        iVar8 = *(int *)(iVar10 + uVar6 * 4);
        if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar8 + 4) * 4) + 5) & 1) == 0)
           || (*(int *)(iVar8 + 8) != -1)) {
          bVar16 = false;
        }
        else {
          bVar16 = true;
        }
        if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar11 + 4) * 4) + 5) & 1) == 0)
           || (*(int *)(iVar11 + 8) != -1)) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
        if (((bVar16) && (dVar4 == *(double *)(iVar8 + 0x20))) ||
           ((bVar3 && (dVar4 == *(double *)(iVar11 + 0x20))))) {
LAB_0091655e:
          local_c = local_c + 1;
        }
        else {
          if (bVar16) {
            if (bVar3) {
              local_3c = *(double *)(iVar11 + 0x20) * *(double *)(iVar8 + 0x20) + local_3c;
              goto LAB_0091655e;
            }
            if (_DAT_0099d0a0 != *(double *)(iVar8 + 0x20)) break;
            uVar6 = uVar9;
          }
          else if ((!bVar3) || (_DAT_0099d0a0 != *(double *)(iVar11 + 0x20))) break;
          local_10 = local_10 + 1;
          local_24 = uVar6;
        }
        local_20 = local_20 + 1;
        local_1c = local_1c + 1;
        local_2c = local_2c + 1;
      } while (local_20 < uVar12);
      if (((local_10 == 1) && (uVar12 - 1 == local_c)) && (dVar4 == local_3c)) {
        *param_1 = 0;
        puVar1[0xc] = local_24;
        return false;
      }
    }
    if (uVar12 == local_c) {
      *param_1 = 0;
      uVar12 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,local_3c);
      puVar1[0xc] = uVar12;
      *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar12 * 4) + 0x30) = uVar12;
      return false;
    }
  }
  local_28 = 0;
  local_c = 0;
  local_10 = 0;
  bVar16 = false;
  if (uVar12 != 0) {
    local_14 = (int *)param_1[2];
    piVar7 = local_14 + uVar12;
    local_2c = (int *)uVar12;
    do {
      iVar10 = *(int *)(in_ECX + 0x14);
      iVar11 = *piVar7;
      iVar8 = *(int *)(iVar10 + *local_14 * 4);
      if (param_2 != 0) {
        iVar8 = *(int *)(iVar10 + *(int *)(iVar8 + 0x30) * 4);
        iVar11 = *(int *)(*(int *)(iVar10 + iVar11 * 4) + 0x30);
      }
      iVar10 = *(int *)(iVar10 + iVar11 * 4);
      if (((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar8 + 4) * 4) + 5) & 1) == 0)
           || (*(int *)(iVar8 + 8) != -1)) || (dVar4 != *(double *)(iVar8 + 0x20))) &&
         ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar10 + 4) * 4) + 5) & 1) == 0
           || (*(int *)(iVar10 + 8) != -1)) || (dVar4 != *(double *)(iVar10 + 0x20))))) {
        local_c = local_c + 1;
        local_10 = 0;
      }
      else {
        local_28 = local_28 + 1;
        local_10 = local_10 + 1;
      }
      local_14 = local_14 + 1;
      piVar7 = piVar7 + 1;
      local_2c = (int *)((int)local_2c - 1);
    } while (local_2c != (int *)0x0);
    if (((local_28 != 0) && ((local_c != 2 || ((*(byte *)(in_ECX + 0x6c) & 0x20) != 0)))) &&
       ((local_c == 1 || ((local_28 == local_10 || ((*(byte *)(in_ECX + 0x6c) & 6) == 0)))))) {
      if (local_c == 0) {
        *param_1 = 0;
        return false;
      }
      local_c = 0;
      local_28 = uVar12 << 2;
      local_2c = (int *)0x0;
      local_14 = (int *)local_28;
      do {
        uVar9 = param_1[2];
        iVar10 = *(int *)(uVar9 + (int)local_2c * 4);
        iVar11 = *(int *)(in_ECX + 0x14);
        local_10 = *(int *)(iVar11 + iVar10 * 4);
        if (param_2 == 0) {
          iVar8 = *(int *)((int)local_14 + uVar9);
        }
        else {
          local_10 = *(int *)(iVar11 + *(int *)(local_10 + 0x30) * 4);
          iVar8 = *(int *)(*(int *)(iVar11 + *(int *)((int)local_14 + uVar9) * 4) + 0x30);
        }
        iVar11 = *(int *)(iVar11 + iVar8 * 4);
        if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(local_10 + 4) * 4) + 5) & 1) ==
             0) || (*(int *)(local_10 + 8) != -1)) {
LAB_0091677e:
          if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar11 + 4) * 4) + 5) & 1) !=
               0) && (*(int *)(iVar11 + 8) == -1)) {
            if (dVar4 == *(double *)(iVar11 + 0x20)) goto LAB_009167c0;
          }
          *(int *)(uVar9 + local_c * 4) = iVar10;
          *(undefined4 *)(local_28 + param_1[2]) = *(undefined4 *)((int)local_14 + param_1[2]);
          local_28 = local_28 + 4;
          local_c = local_c + 1;
        }
        else if (dVar4 != *(double *)(local_10 + 0x20)) goto LAB_0091677e;
LAB_009167c0:
        local_14 = (int *)((int)local_14 + 4);
        local_2c = (int *)((int)local_2c + 1);
      } while (local_2c < uVar12);
      puVar13 = (undefined4 *)(uVar12 * 4 + param_1[2]);
      puVar15 = (undefined4 *)(param_1[2] + local_c * 4);
      for (uVar9 = local_c & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar15 = *puVar13;
        puVar13 = puVar13 + 1;
        puVar15 = puVar15 + 1;
      }
      for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined1 *)puVar15 = *(undefined1 *)puVar13;
        puVar13 = (undefined4 *)((int)puVar13 + 1);
        puVar15 = (undefined4 *)((int)puVar15 + 1);
      }
      if (local_c == 1) {
        uVar9 = 0x20500001;
      }
      else {
        uVar9 = local_c & 0xfffff | 0x50000000;
      }
      *param_1 = uVar9;
      param_1[1] = local_c * 2;
      bVar16 = uVar12 != local_c;
      param_1[3] = 1;
      param_1 = (uint *)local_c;
      uVar12 = (uint)param_1;
    }
  }
  param_1 = (uint *)uVar12;
  if ((param_1 < 2) || ((param_1 == (uint *)0x2 && ((*(byte *)(in_ECX + 0x6c) & 0x20) == 0)))) {
    local_c = 0;
    if (param_1 != (uint *)0x0) {
      local_2c = (int *)((int)param_1 << 2);
      do {
        if (param_2 == 0) {
          iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar5[2] + local_c * 4) * 4);
          iVar11 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)((int)local_2c + puVar5[2]) * 4);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x14);
          iVar10 = *(int *)(iVar11 + *(int *)(*(int *)(iVar11 + *(int *)(puVar5[2] + local_c * 4) *
                                                                4) + 0x30) * 4);
          iVar11 = *(int *)(iVar11 + *(int *)(*(int *)(iVar11 + *(int *)((int)local_2c + puVar5[2])
                                                                * 4) + 0x30) * 4);
        }
        if (((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar10 + 4) * 4) + 5) & 1) ==
               0) || (*(int *)(iVar10 + 8) != -1)) || (_DAT_0099d0a0 != *(double *)(iVar10 + 0x20)))
           && ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar11 + 4) * 4) + 5) & 1)
                 == 0 || (*(int *)(iVar11 + 8) != -1)) ||
               (_DAT_0099d0a0 != *(double *)(iVar11 + 0x20))))) break;
        local_c = local_c + 1;
        local_2c = (int *)((int)local_2c + 4);
      } while (local_c < param_1);
    }
    if ((uint *)local_c == param_1) {
      local_c = 0;
      if (param_1 != (uint *)0x0) {
        local_28 = (int)param_1 << 2;
        do {
          piVar7 = (int *)(puVar5[2] + local_c * 4);
          if (param_2 == 0) {
            iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar7 * 4);
          }
          else {
            iVar10 = *(int *)(*(int *)(in_ECX + 0x14) +
                             *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar7 * 4) + 0x30) * 4);
          }
          if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar10 + 4) * 4) + 5) & 1) !=
                0) && (*(int *)(iVar10 + 8) == -1)) && (_DAT_0099d0a0 == *(double *)(iVar10 + 0x20))
             ) {
            *piVar7 = *(int *)(puVar5[2] + local_28);
          }
          local_28 = local_28 + 4;
          local_c = local_c + 1;
        } while (local_c < param_1);
      }
      if (param_1 == (uint *)0x2) {
        *puVar5 = 0x20400001;
        puVar5[1] = 2;
      }
      else {
        *puVar5 = 0x10000001;
        puVar5[1] = 1;
      }
      bVar16 = true;
    }
  }
  return !bVar16;
}


// ==== FUN_009169c8 @ 0x009169c8 ====

undefined4 FUN_009169c8(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  
  if (param_1 == param_2) {
    return 1;
  }
  iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + param_2 * 4);
  if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4) + 4) & 2) == 0) {
    return 0;
  }
  puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar3 + 0x48) * 4);
  if ((*puVar1 & 0xfff00000) == 0x10000000) {
    uVar2 = 0;
    if (puVar1[3] != 0) {
      piVar5 = (int *)puVar1[4];
      do {
        if (*piVar5 == param_2) break;
        uVar2 = uVar2 + 1;
        piVar5 = piVar5 + 1;
      } while (uVar2 < puVar1[3]);
    }
    iVar3 = FUN_009169c8(param_1,*(undefined4 *)(puVar1[2] + uVar2 * 4));
    if (iVar3 == 0) goto LAB_00916a49;
LAB_00916a41:
    uVar4 = 1;
  }
  else {
LAB_00916a49:
    if ((*puVar1 & 0xfff00000) == 0x20500000) {
      uVar2 = 0;
      if (puVar1[3] != 0) {
        piVar5 = (int *)puVar1[4];
        do {
          if (*piVar5 == param_2) break;
          uVar2 = uVar2 + 1;
          piVar5 = piVar5 + 1;
        } while (uVar2 < puVar1[3]);
      }
      iVar3 = FUN_009169c8(param_1,*(undefined4 *)(puVar1[2] + uVar2 * 4));
      if ((iVar3 != 0) ||
         (iVar3 = FUN_009169c8(param_1,*(undefined4 *)(puVar1[2] + (puVar1[3] + uVar2) * 4)),
         iVar3 != 0)) goto LAB_00916a41;
    }
    uVar4 = 0;
  }
  return uVar4;
}


// ==== FUN_00916aa5 @ 0x00916aa5 ====

undefined4 FUN_00916aa5(int param_1,int *param_2,double *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int in_ECX;
  int *piVar8;
  uint uVar9;
  double local_24;
  int local_1c;
  undefined4 local_18;
  int iStack_14;
  undefined4 local_10;
  int iStack_c;
  int local_8;
  
  local_1c = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
  if (param_1 == *param_2) {
LAB_00916ac4:
    local_8 = param_1;
    local_24 = 1.0;
    goto LAB_00916cf5;
  }
  local_8 = *(int *)(local_1c + 0x40);
  if (local_8 != -1) {
    local_24 = *(double *)(local_1c + 0x28);
    goto LAB_00916cf5;
  }
  if ((*(int *)(local_1c + 8) != -1) ||
     ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(local_1c + 4) * 4) + 4) & 2) == 0))
  goto LAB_00916ac4;
  puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(local_1c + 0x48) * 4);
  uVar2 = puVar1[3];
  uVar3 = 0;
  if (uVar2 != 0) {
    piVar8 = (int *)puVar1[4];
    do {
      if (*piVar8 == param_1) break;
      uVar3 = uVar3 + 1;
      piVar8 = piVar8 + 1;
    } while (uVar3 < uVar2);
  }
  if (uVar3 != uVar2) {
    uVar9 = *puVar1 & 0xfff00000;
    if (uVar9 == 0x10000000) {
      local_8 = -1;
      iVar4 = FUN_00916aa5(*(undefined4 *)(puVar1[2] + uVar3 * 4),&local_8,&local_24);
      if (-1 < iVar4) goto LAB_00916cf5;
    }
    else if (uVar9 == 0x10100000) {
      local_8 = -1;
      iVar4 = FUN_00916aa5(*(undefined4 *)(puVar1[2] + uVar3 * 4),&local_8,&local_24);
      if (-1 < iVar4) {
        local_24 = -local_24;
        goto LAB_00916cf5;
      }
    }
    else if (uVar9 == 0x20400000) {
      iVar4 = *(int *)(puVar1[2] + uVar3 * 4);
      iVar6 = *(int *)(puVar1[2] + (uVar2 + uVar3) * 4);
      local_8 = -1;
      if (iVar4 != iVar6) {
        iVar5 = FUN_00916aa5(iVar4,&local_8,&local_10);
        if ((iVar5 < 0) || (iVar5 = FUN_00916aa5(iVar6,&local_8,&local_18), iVar5 < 0)) {
          local_8 = -1;
          iVar6 = FUN_00916aa5(iVar6,&local_8,&local_18);
          if ((iVar6 < 0) || (iVar4 = FUN_00916aa5(iVar4,&local_8,&local_10), iVar4 < 0))
          goto LAB_00916cec;
        }
        local_24 = (double)CONCAT44(iStack_14,local_18) + (double)CONCAT44(iStack_c,local_10);
        goto LAB_00916cf5;
      }
      iVar4 = FUN_00916aa5(iVar4,&local_8,&local_24);
      if (-1 < iVar4) {
        local_24 = local_24 + local_24;
        goto LAB_00916cf5;
      }
    }
    else if (uVar9 == 0x20500000) {
      iStack_c = *(int *)(puVar1[2] + uVar3 * 4);
      iStack_14 = *(int *)(puVar1[2] + (uVar2 + uVar3) * 4);
      if (iStack_c != iStack_14) {
        iVar6 = iStack_14 * 4;
        iVar4 = *(int *)(iVar6 + *(int *)(in_ECX + 0x14));
        if (((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4) & 0x100) !=
             0) && (*(int *)(iVar4 + 8) == -1)) {
          local_8 = -1;
          iVar4 = FUN_00916aa5(iStack_c,&local_8,&local_24);
          if (iVar4 < 0) goto LAB_00916c9d;
          iVar4 = *(int *)(iVar6 + *(int *)(in_ECX + 0x14));
LAB_00916ce1:
          local_24 = local_24 * *(double *)(iVar4 + 0x20);
          goto LAB_00916cf5;
        }
LAB_00916c9d:
        iVar4 = *(int *)(iStack_c * 4 + *(int *)(in_ECX + 0x14));
        if (((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4) & 0x100) !=
             0) && (*(int *)(iVar4 + 8) == -1)) {
          local_8 = -1;
          iVar4 = iStack_14;
          iStack_14 = iStack_c * 4;
          iVar4 = FUN_00916aa5(iVar4,&local_8,&local_24);
          if (-1 < iVar4) {
            iVar4 = *(int *)(iStack_14 + *(int *)(in_ECX + 0x14));
            goto LAB_00916ce1;
          }
        }
      }
    }
  }
LAB_00916cec:
  local_24 = 1.0;
  local_8 = param_1;
LAB_00916cf5:
  if ((*param_2 == -1) || (local_8 == *param_2)) {
    *(int *)(local_1c + 0x40) = local_8;
    *param_2 = local_8;
    *(double *)(local_1c + 0x28) = local_24;
    *param_3 = local_24;
    uVar7 = 0;
  }
  else {
    uVar7 = 0x80004005;
  }
  return uVar7;
}


// ==== FUN_00916d2f @ 0x00916d2f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00916d2f(uint param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6)

{
  byte *pbVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int in_ECX;
  uint uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int *local_10;
  uint local_8;
  
  pbVar1 = *(byte **)(*(int *)(in_ECX + 0x14) + param_1 * 4);
  if (((*(int *)(pbVar1 + 8) != -1) || ((*pbVar1 & 1) == 0)) ||
     ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(pbVar1 + 4) * 4) + 4) & 2) == 0)) {
    return -0x7fffbffb;
  }
  puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(pbVar1 + 0x48) * 4);
  uVar7 = puVar2[3];
  uVar9 = 0;
  if (uVar7 != 0) {
    piVar10 = (int *)puVar2[4];
    do {
      if (*piVar10 == param_1) break;
      uVar9 = uVar9 + 1;
      piVar10 = piVar10 + 1;
    } while (uVar9 < uVar7);
  }
  if (uVar9 == uVar7) {
    return -0x7fffbffb;
  }
  uVar12 = *puVar2 & 0xfff00000;
  if (uVar12 == 0x10000000) {
    iVar6 = *(int *)(puVar2[2] + uVar9 * 4);
LAB_00916e06:
    iVar6 = FUN_00916d2f(iVar6,param_2,param_3,param_4,CONCAT44(param_6,param_5));
    if (iVar6 < 0) {
      return iVar6;
    }
    return 0;
  }
  if (uVar12 == 0x20500000) {
    iVar11 = *(int *)(puVar2[2] + uVar9 * 4);
    iVar6 = *(int *)(puVar2[2] + (uVar7 + uVar9) * 4);
    iVar5 = FUN_00916d2f(iVar11,param_2,param_3,param_4,param_5,param_6);
    if (iVar5 < 0) {
      return iVar5;
    }
    if (iVar11 == iVar6) {
      return 0;
    }
    goto LAB_00916e06;
  }
  if (uVar12 == 0x20200000) {
    iVar6 = *(int *)(puVar2[2] + uVar9 * 4);
    iVar11 = *(int *)(puVar2[2] + (uVar7 + uVar9) * 4);
    if (((*param_2 != -1) && (iVar11 != *param_2)) ||
       ((iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar6 * 4),
        (*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar5 + 4) * 4) + 4) & 0x100) == 0 ||
        (*(int *)(iVar5 + 8) != -1)))) {
      if ((*param_2 != -1) && (iVar6 != *param_2)) {
        return -0x7fffbffb;
      }
      iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4);
      if ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar5 + 4) * 4) + 4) & 0x100) == 0)
      {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar5 + 8) != -1) {
        return -0x7fffbffb;
      }
      if ((*param_6 != -1) &&
         (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_6 * 4) + 0x20) <=
          *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4) + 0x20))) {
        return 0;
      }
LAB_00916ee7:
      *param_2 = iVar6;
      *param_6 = iVar11;
      return 0;
    }
    if ((*param_3 != -1) &&
       (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar6 * 4) + 0x20) <=
        *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_3 * 4) + 0x20))) {
      return 0;
    }
LAB_00916f5f:
    *param_2 = iVar11;
    *param_3 = iVar6;
    return 0;
  }
  if (uVar12 == 0x20300000) {
    iVar6 = *(int *)(puVar2[2] + uVar9 * 4);
    iVar11 = *(int *)(puVar2[2] + (uVar7 + uVar9) * 4);
    if ((((*param_2 != -1) && (iVar11 != *param_2)) ||
        (iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar6 * 4),
        (*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar5 + 4) * 4) + 4) & 0x100) == 0))
       || (*(int *)(iVar5 + 8) != -1)) {
      if ((*param_2 != -1) && (iVar6 != *param_2)) {
        return -0x7fffbffb;
      }
      iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4);
      if ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar5 + 4) * 4) + 4) & 0x100) == 0)
      {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar5 + 8) != -1) {
        return -0x7fffbffb;
      }
      param_6 = param_4;
      if ((*param_4 != -1) &&
         (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4) + 0x20) <=
          *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_4 * 4) + 0x20))) {
        return 0;
      }
      goto LAB_00916ee7;
    }
    param_3 = param_5;
    if ((*param_5 != -1) &&
       (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_5 * 4) + 0x20) <=
        *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar6 * 4) + 0x20))) {
      return 0;
    }
    goto LAB_00916f5f;
  }
  if (uVar12 != 0x30000000) {
    return -0x7fffbffb;
  }
  iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar2[2] + (uVar9 + puVar2[3]) * 4) * 4);
  iVar11 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar2[2] + (uVar9 + puVar2[3] * 2) * 4) * 4)
  ;
  iVar5 = *(int *)(in_ECX + 0x10);
  if ((*(uint *)(*(int *)(iVar5 + *(int *)(iVar6 + 4) * 4) + 4) & 0x100) == 0) {
    return -0x7fffbffb;
  }
  if (*(int *)(iVar6 + 8) != -1) {
    return -0x7fffbffb;
  }
  if ((*(uint *)(*(int *)(iVar5 + *(int *)(iVar11 + 4) * 4) + 4) & 0x100) == 0) {
    return -0x7fffbffb;
  }
  if (*(int *)(iVar11 + 8) != -1) {
    return -0x7fffbffb;
  }
  if ((_DAT_0099d098 != *(double *)(iVar6 + 0x20)) || (_DAT_0099d0a0 != *(double *)(iVar11 + 0x20)))
  {
    if (_DAT_0099d0a0 != *(double *)(iVar6 + 0x20)) {
      return -0x7fffbffb;
    }
    if (_DAT_0099d098 != *(double *)(iVar11 + 0x20)) {
      return -0x7fffbffb;
    }
  }
  iVar11 = *(int *)(puVar2[2] + uVar9 * 4);
  iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4);
  if ((*(byte *)(*(int *)(iVar5 + *(int *)(iVar3 + 4) * 4) + 4) & 2) == 0) {
    return -0x7fffbffb;
  }
  puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar3 + 0x48) * 4);
  uVar7 = *puVar2 & 0xfff00000;
  if ((uVar7 != 0x20400000) && (uVar7 != 0x10100000)) {
    return -0x7fffbffb;
  }
  uVar9 = puVar2[3];
  param_1 = 0;
  if (uVar9 != 0) {
    local_10 = (int *)puVar2[4];
    do {
      if (*local_10 == iVar11) break;
      param_1 = param_1 + 1;
      local_10 = local_10 + 1;
    } while (param_1 < uVar9);
  }
  if (uVar7 == 0x10100000) {
    piVar8 = (int *)FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,0);
    piVar10 = *(int **)(puVar2[2] + param_1 * 4);
    if (piVar8 == (int *)0xffffffff) {
      return -0x7ff8fff2;
    }
    goto LAB_009171f5;
  }
  local_8 = 0;
  local_10 = (int *)(puVar2[2] + (param_1 + uVar9) * 4);
  do {
    iVar11 = *local_10;
    iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4);
    if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar5 + 4) * 4) + 4) & 2) != 0) &&
       (puVar4 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar5 + 0x48) * 4),
       (*puVar4 & 0xfff00000) == 0x10100000)) {
      local_10 = (int *)0x0;
      if (puVar4[3] == 0) goto LAB_009171d5;
      piVar10 = (int *)puVar4[4];
      goto LAB_009171bd;
    }
    local_8 = local_8 + 1;
    local_10 = local_10 + -uVar9;
  } while (local_8 < 2);
  piVar10 = param_2;
  piVar8 = param_2;
  goto LAB_009171eb;
  while( true ) {
    local_10 = (int *)((int)local_10 + 1);
    piVar10 = piVar10 + 1;
    if (puVar4[3] <= local_10) break;
LAB_009171bd:
    if (iVar11 == *piVar10) break;
  }
LAB_009171d5:
  piVar8 = *(int **)(puVar2[2] + (uVar9 * local_8 + param_1) * 4);
  piVar10 = *(int **)(puVar4[2] + (int)local_10 * 4);
LAB_009171eb:
  if (local_8 == 2) {
    return -0x7fffbffb;
  }
LAB_009171f5:
  if (((((int *)*param_2 == (int *)0xffffffff) || (piVar8 == (int *)*param_2)) &&
      (iVar11 = *(int *)(*(int *)(in_ECX + 0x14) + (int)piVar10 * 4),
      (*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar11 + 4) * 4) + 4) & 0x100) != 0))
     && (*(int *)(iVar11 + 8) == -1)) {
    if (_DAT_0099d0a0 == *(double *)(iVar6 + 0x20)) {
      if ((*param_4 != -1) &&
         (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)piVar10 * 4) + 0x20) <=
          *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_4 * 4) + 0x20))) {
        return 0;
      }
    }
    else {
      param_4 = param_6;
      if ((*param_6 != -1) &&
         (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_6 * 4) + 0x20) <=
          *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)piVar10 * 4) + 0x20))) {
        return 0;
      }
    }
    *param_2 = (int)piVar8;
    *param_4 = (int)piVar10;
    return 0;
  }
  if (((((int *)*param_2 != (int *)0xffffffff) && (piVar10 != (int *)*param_2)) ||
      (iVar11 = *(int *)(*(int *)(in_ECX + 0x14) + (int)piVar8 * 4),
      (*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar11 + 4) * 4) + 4) & 0x100) == 0))
     || (*(int *)(iVar11 + 8) != -1)) {
    return -0x7fffbffb;
  }
  if (_DAT_0099d0a0 == *(double *)(iVar6 + 0x20)) {
    if ((*param_5 != -1) &&
       (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_5 * 4) + 0x20) <=
        *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)piVar8 * 4) + 0x20))) {
      return 0;
    }
  }
  else {
    param_5 = param_3;
    if ((*param_3 != -1) &&
       (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)piVar8 * 4) + 0x20) <=
        *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_3 * 4) + 0x20))) {
      return 0;
    }
  }
  *param_2 = (int)piVar10;
  *param_5 = (int)piVar8;
  return 0;
}


// ==== FUN_0091733b @ 0x0091733b ====

undefined4 FUN_0091733b(int param_1,int param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  param_2 = param_2 * 4;
  param_1 = param_1 * 4;
  if ((((*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1) + 4) ==
         *(int *)(*(int *)(param_2 + *(int *)(in_ECX + 0x14)) + 4)) &&
       (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1) + 8) ==
        *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2) + 8))) &&
      (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1) + 0xc) ==
       *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2) + 0xc))) &&
     ((*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1) + 0x14) ==
       *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2) + 0x14) &&
      (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1) + 0x18) ==
       *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2) + 0x18))))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_009173b0 @ 0x009173b0 ====

undefined4 FUN_009173b0(int param_1,int param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((param_1 == param_2) ||
     ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2 * 4) + 0x40) &
      *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4) + 0x40)) != 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_009173dd @ 0x009173dd ====

undefined4 FUN_009173dd(uint *param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  int *piVar6;
  uint local_8;
  
  uVar2 = param_1[1];
  uVar5 = *param_1 & 0xfffff;
  local_8 = 0;
  if (uVar2 / uVar5 != 0) {
    puVar1 = param_1 + 2;
    iVar3 = *(int *)(in_ECX + 0x14);
    param_1 = (uint *)(*puVar1 + param_3 * 4);
    piVar6 = (int *)(*puVar1 + param_2 * 4);
    do {
      if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                               *(int *)(*(int *)(iVar3 + *piVar6 * 4) + 4) * 4) + 4) & 0x40) != 0)
          && ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                 *(int *)(*(int *)(iVar3 + *param_1 * 4) + 4) * 4) + 4) & 0x40) != 0
             )) && (iVar4 = FUN_0091733b(*piVar6,*param_1), iVar4 == 0)) {
        return 1;
      }
      local_8 = local_8 + 1;
      param_1 = param_1 + uVar5;
      piVar6 = piVar6 + uVar5;
    } while (local_8 < uVar2 / uVar5);
  }
  return 0;
}


// ==== FUN_00917482 @ 0x00917482 ====

undefined4 FUN_00917482(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  int *piVar10;
  int iVar11;
  uint local_30;
  int local_2c;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_10;
  uint local_8;
  
  uVar1 = param_1[3];
  uVar5 = param_1[1] / uVar1;
  iVar6 = FUN_00914622();
  if (iVar6 == 0) {
    local_1c = 0;
    local_10 = uVar1;
    if (uVar1 != 0) {
      do {
        uVar7 = param_1[4];
        iVar6 = *(int *)(uVar7 + local_1c * 4);
        if ((iVar6 != -1) &&
           ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                               *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar6 * 4) + 4) * 4) + 4)
            & 0x40) != 0)) {
          local_8 = 0;
          for (uVar8 = local_1c; uVar8 < uVar1; uVar8 = uVar8 + 1) {
            if ((*(int *)(uVar8 * 4 + uVar7) != -1) &&
               (iVar6 = FUN_0091733b(*(undefined4 *)(param_1[4] + local_1c * 4),
                                     *(undefined4 *)(param_1[4] + uVar8 * 4)), iVar6 != 0)) {
              local_8 = local_8 + 1;
            }
          }
          iVar6 = FUN_00915378((*param_1 ^ local_8) & 0xfffff ^ *param_1,0xffffffff,0xffffffff);
          if (iVar6 == -1) {
            return 0x8007000e;
          }
          iVar6 = *(int *)(*(int *)(in_ECX + 0x18) + iVar6 * 4);
          FUN_00914593(param_1);
          local_30 = *(uint *)(param_1[4] + local_1c * 4);
          local_8 = 0;
          for (uVar7 = local_1c; uVar7 < uVar1; uVar7 = uVar7 + 1) {
            iVar9 = *(int *)(param_1[4] + uVar7 * 4);
            if ((iVar9 != -1) && (iVar9 = FUN_0091733b(local_30,iVar9), iVar9 != 0)) {
              local_18 = 0;
              if (uVar5 != 0) {
                do {
                  iVar9 = param_1[3] * local_18;
                  iVar11 = *(int *)(iVar6 + 0xc) * local_18;
                  local_18 = local_18 + 1;
                  *(undefined4 *)(*(int *)(iVar6 + 8) + (iVar11 + local_8) * 4) =
                       *(undefined4 *)(param_1[2] + (iVar9 + uVar7) * 4);
                } while (local_18 < uVar5);
              }
              *(undefined4 *)(*(int *)(iVar6 + 0x10) + local_8 * 4) =
                   *(undefined4 *)(param_1[4] + uVar7 * 4);
              *(undefined4 *)(param_1[4] + uVar7 * 4) = 0xffffffff;
              local_10 = local_10 - 1;
              local_8 = local_8 + 1;
            }
          }
        }
        local_1c = local_1c + 1;
      } while (local_1c < uVar1);
    }
    local_2c = FUN_009147e7();
    bVar3 = true;
    bVar4 = true;
    if ((local_2c == 0) && (local_20 = 0, uVar1 != 0)) {
      piVar10 = (int *)param_1[4];
      do {
        if ((*piVar10 != -1) &&
           ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                               *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar10 * 4) + 4) * 4) +
                      5) & 0x10) != 0)) {
          local_2c = 1;
          break;
        }
        local_20 = local_20 + 1;
        piVar10 = piVar10 + 1;
      } while (local_20 < uVar1);
    }
joined_r0x009176c8:
    if (local_10 != 0) {
      if ((local_10 < 5) && (local_2c == 0)) {
        bVar3 = false;
        bVar4 = false;
      }
      local_8 = 0;
      local_18 = 0;
      if (uVar1 == 0) {
        return 0;
      }
      do {
        if (*(int *)(param_1[4] + local_18 * 4) != -1) {
          uVar7 = 0;
          local_1c = 0;
          do {
            if (3 < local_1c) break;
            uVar8 = param_1[4];
            if (((*(int *)(uVar8 + uVar7 * 4) != -1) &&
                ((!bVar3 ||
                 (iVar6 = FUN_009173b0(*(undefined4 *)(uVar8 + local_18 * 4),
                                       *(undefined4 *)(uVar8 + uVar7 * 4)), iVar6 != 0)))) &&
               ((!bVar4 || (iVar6 = FUN_009173dd(param_1,local_18,uVar7), iVar6 == 0)))) {
              local_1c = local_1c + 1;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar1);
          if (local_8 < local_1c) {
            local_8 = local_1c;
            local_30 = local_18;
          }
        }
        local_18 = local_18 + 1;
      } while (local_18 < uVar1);
      if (local_8 == 0) {
        return 0;
      }
      iVar6 = FUN_00915378((*param_1 ^ local_8) & 0xfffff ^ *param_1,0xffffffff,0xffffffff);
      if (iVar6 == -1) {
        return 0x8007000e;
      }
      iVar6 = *(int *)(*(int *)(in_ECX + 0x18) + iVar6 * 4);
      FUN_00914593(param_1);
      uVar2 = *(undefined4 *)(param_1[4] + local_30 * 4);
      local_18 = 0;
      local_20 = 0;
      do {
        if (3 < local_18) break;
        iVar9 = *(int *)(param_1[4] + local_20 * 4);
        if (((iVar9 != -1) && ((!bVar3 || (iVar9 = FUN_009173b0(uVar2,iVar9), iVar9 != 0)))) &&
           ((!bVar4 || (iVar9 = FUN_009173dd(param_1,local_30,local_20), iVar9 == 0)))) {
          local_1c = 0;
          if (uVar5 != 0) {
            do {
              iVar9 = param_1[3] * local_1c;
              iVar11 = *(int *)(iVar6 + 0xc) * local_1c;
              local_1c = local_1c + 1;
              *(undefined4 *)(*(int *)(iVar6 + 8) + (iVar11 + local_18) * 4) =
                   *(undefined4 *)(param_1[2] + (iVar9 + local_20) * 4);
            } while (local_1c < uVar5);
          }
          *(undefined4 *)(*(int *)(iVar6 + 0x10) + local_18 * 4) =
               *(undefined4 *)(param_1[4] + local_20 * 4);
          *(undefined4 *)(param_1[4] + local_20 * 4) = 0xffffffff;
          local_10 = local_10 - 1;
          local_18 = local_18 + 1;
        }
        local_20 = local_20 + 1;
      } while (local_20 < uVar1);
      goto joined_r0x009176c8;
    }
  }
  else {
    local_1c = 0;
    if (uVar1 != 0) {
      do {
        iVar6 = FUN_00915378(*param_1 & 0xfff00001 | 1,0xffffffff,0xffffffff);
        if (iVar6 == -1) {
          return 0x8007000e;
        }
        iVar6 = *(int *)(*(int *)(in_ECX + 0x18) + iVar6 * 4);
        FUN_00914593(param_1);
        uVar7 = 0;
        if (uVar5 != 0) {
          do {
            *(undefined4 *)(*(int *)(iVar6 + 8) + uVar7 * 4) =
                 *(undefined4 *)(param_1[2] + (param_1[3] * uVar7 + local_1c) * 4);
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar5);
        }
        iVar9 = local_1c * 4;
        local_1c = local_1c + 1;
        **(undefined4 **)(iVar6 + 0x10) = *(undefined4 *)(param_1[4] + iVar9);
      } while (local_1c < uVar1);
    }
  }
  return 0;
}


// ==== FUN_00917870 @ 0x00917870 ====

undefined4 FUN_00917870(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int in_ECX;
  bool bVar9;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  puVar4 = param_1;
  uVar5 = *param_1 & 0xfffff;
  param_1 = (uint *)0x0;
  local_14 = uVar5;
  if (uVar5 == 0) {
    return 0;
  }
  do {
    local_8 = 0;
    if (local_14 < 5) {
      local_8 = local_14;
    }
    else if (uVar5 != 0) {
      local_20 = 0;
      local_24 = uVar5 << 2;
      local_28 = 1;
      do {
        uVar1 = puVar4[2];
        if (*(int *)(uVar1 + local_20) != -1) {
          iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(uVar1 + local_20) * 4);
          iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(uVar1 + local_24) * 4);
          local_1c = 1;
          local_18 = local_28;
          if (local_28 < uVar5) {
            local_10 = local_24;
            do {
              local_10 = local_10 + 4;
              if (*(int *)(puVar4[2] + local_10) != -1) {
                iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar4[2] + local_18 * 4) * 4);
                iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar4[2] + local_10) * 4);
                if ((((((*(int *)(iVar6 + 4) == *(int *)(iVar2 + 4)) &&
                       (*(int *)(iVar6 + 8) == *(int *)(iVar2 + 8))) &&
                      (*(int *)(iVar6 + 0xc) == *(int *)(iVar2 + 0xc))) &&
                     ((*(int *)(iVar6 + 0x48) == *(int *)(iVar2 + 0x48) &&
                      (*(int *)(iVar8 + 4) == *(int *)(iVar3 + 4))))) &&
                    ((*(int *)(iVar8 + 8) == *(int *)(iVar3 + 8) &&
                     ((*(int *)(iVar8 + 0xc) == *(int *)(iVar3 + 0xc) &&
                      (*(int *)(iVar8 + 0x48) == *(int *)(iVar3 + 0x48))))))) &&
                   (local_1c = local_1c + 1, local_1c == 4)) break;
              }
              local_18 = local_18 + 1;
            } while (local_18 < uVar5);
          }
          if (local_8 < local_1c) {
            local_8 = local_1c;
            local_34 = *(int *)(iVar6 + 4);
            local_44 = *(int *)(iVar8 + 4);
            local_38 = *(int *)(iVar6 + 8);
            local_48 = *(int *)(iVar8 + 8);
            local_3c = *(int *)(iVar6 + 0xc);
            local_40 = *(int *)(iVar6 + 0x48);
            local_4c = *(int *)(iVar8 + 0xc);
            local_50 = *(int *)(iVar8 + 0x48);
          }
          if (local_8 == 4) break;
        }
        local_20 = local_20 + 4;
        local_24 = local_24 + 4;
        bVar9 = local_28 < uVar5;
        local_28 = local_28 + 1;
      } while (bVar9);
    }
    iVar6 = FUN_00915378(local_8 & 0xfffff | 0x50000000,0xffffffff,0xffffffff);
    if (iVar6 == -1) {
      return 0x8007000e;
    }
    iVar6 = *(int *)(*(int *)(in_ECX + 0x18) + iVar6 * 4);
    FUN_00914593();
    local_28 = 0;
    local_20 = 0;
    if (uVar5 != 0) {
      local_10 = uVar5 << 2;
      local_24 = local_8 << 2;
      do {
        if (local_8 <= local_28) break;
        if (*(int *)(puVar4[2] + local_20 * 4) != -1) {
          iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar4[2] + local_20 * 4) * 4);
          iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar4[2] + local_10) * 4);
          if ((local_14 < 5) ||
             ((((local_34 == *(int *)(iVar8 + 4) && (local_38 == *(int *)(iVar8 + 8))) &&
               (local_3c == *(int *)(iVar8 + 0xc))) &&
              (((local_40 == *(int *)(iVar8 + 0x48) && (local_44 == *(int *)(iVar2 + 4))) &&
               ((local_48 == *(int *)(iVar2 + 8) &&
                ((local_4c == *(int *)(iVar2 + 0xc) && (local_50 == *(int *)(iVar2 + 0x48)))))))))))
          {
            *(undefined4 *)(*(int *)(iVar6 + 8) + local_28 * 4) =
                 *(undefined4 *)(puVar4[2] + local_20 * 4);
            *(undefined4 *)(local_24 + *(int *)(iVar6 + 8)) = *(undefined4 *)(local_10 + puVar4[2]);
            *(undefined4 *)(puVar4[2] + local_20 * 4) = 0xffffffff;
            *(undefined4 *)(local_10 + puVar4[2]) = 0xffffffff;
            local_28 = local_28 + 1;
            local_24 = local_24 + 4;
          }
        }
        local_10 = local_10 + 4;
        local_20 = local_20 + 1;
      } while (local_20 < uVar5);
    }
    if (uVar5 < 5) {
      **(undefined4 **)(iVar6 + 0x10) = *(undefined4 *)puVar4[4];
    }
    else {
      uVar7 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0xffffffff,0xffffffff,0);
      **(undefined4 **)(iVar6 + 0x10) = uVar7;
      if (**(int **)(iVar6 + 0x10) == -1) {
        return 0x8007000e;
      }
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar6 + 0x10) * 4) + 0x14) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar4[4] * 4) + 0x14);
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar6 + 0x10) * 4) + 0x18) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar4[4] * 4) + 0x18);
    }
    local_14 = local_14 - local_8;
    param_1 = (uint *)((int)param_1 + 1);
    if (local_14 == 0) {
      if (param_1 < 2) {
        return 0;
      }
      iVar6 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0xffffffff,0,0x3ff0000000000000);
      if (iVar6 == -1) {
        return 0x8007000e;
      }
      do {
        local_1c = *(int *)(in_ECX + 0xc) - (int)param_1;
        local_18 = 0;
        if (param_1 != (uint *)0x0) {
          local_28 = 0;
          do {
            local_c = (int)param_1 - local_28;
            if (4 < local_c) {
              local_c = 4;
            }
            if (local_c == 1) {
              uVar5 = 0x10000001;
            }
            else if (local_c == 2) {
              uVar5 = 0x20400001;
            }
            else {
              uVar5 = local_c & 0xfffff | 0x50000000;
            }
            iVar8 = FUN_00915378(uVar5,0xffffffff,0xffffffff);
            if (iVar8 == -1) {
              return 0x8007000e;
            }
            iVar8 = *(int *)(*(int *)(in_ECX + 0x18) + iVar8 * 4);
            FUN_00914593();
            local_14 = 0;
            if (local_c != 0) {
              local_20 = local_c << 2;
              local_24 = local_1c << 2;
              do {
                *(undefined4 *)(*(int *)(iVar8 + 8) + local_14 * 4) =
                     **(undefined4 **)(*(int *)(local_24 + *(int *)(in_ECX + 0x18)) + 0x10);
                if (2 < local_c) {
                  *(int *)(local_20 + *(int *)(iVar8 + 8)) = iVar6;
                }
                local_24 = local_24 + 4;
                local_20 = local_20 + 4;
                local_14 = local_14 + 1;
              } while (local_14 < local_c);
            }
            if (param_1 < 5) {
              **(undefined4 **)(iVar8 + 0x10) = *(undefined4 *)puVar4[4];
            }
            else {
              uVar7 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0xffffffff,0xffffffff,0);
              **(undefined4 **)(iVar8 + 0x10) = uVar7;
              if (**(int **)(iVar8 + 0x10) == -1) {
                return 0x8007000e;
              }
              *(undefined4 *)
               (*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar8 + 0x10) * 4) + 0x14) =
                   *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar4[4] * 4) + 0x14)
              ;
              *(undefined4 *)
               (*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar8 + 0x10) * 4) + 0x18) =
                   *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar4[4] * 4) + 0x18)
              ;
            }
            local_1c = local_1c + local_c;
            local_28 = local_28 + 4;
            local_18 = local_18 + 1;
          } while (local_28 < param_1);
        }
        param_1 = (uint *)local_18;
        if (local_18 < 2) {
          return 0;
        }
      } while( true );
    }
  } while( true );
}


// ==== FUN_00917d35 @ 0x00917d35 ====

int FUN_00917d35(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 *local_c;
  uint local_8;
  
  iVar3 = FUN_00915471(param_1);
  if (iVar3 == -1) {
    return -0x7ff8fff2;
  }
  iVar3 = *(int *)(*(int *)(in_ECX + 0x18) + iVar3 * 4);
  FUN_00914593();
  uVar1 = *(uint *)(param_1 + 0xc);
  local_8 = 0;
  if (uVar1 != 0) {
    local_c = *(undefined4 **)(param_1 + 0x10);
    uVar5 = *local_c;
    do {
      iVar4 = FUN_0091733b(uVar5,*local_c);
      if (iVar4 == 0) break;
      local_8 = local_8 + 1;
      local_c = local_c + 1;
    } while (local_8 < uVar1);
  }
  if (local_8 != uVar1) {
    iVar4 = FUN_00915378(uVar1 & 0xfffff | 0x10000000,0xffffffff,0xffffffff);
    if (iVar4 == -1) {
      return -0x7ff8fff2;
    }
    puVar2 = *(undefined4 **)(*(int *)(in_ECX + 0x18) + iVar4 * 4);
    FUN_00914593();
    local_8 = 0;
    if (*(int *)(iVar3 + 0xc) != 0) {
      do {
        iVar4 = local_8 * 4;
        *(undefined4 *)(iVar4 + puVar2[4]) = *(undefined4 *)(iVar4 + *(int *)(iVar3 + 0x10));
        uVar5 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0xffffffff,0xffffffff,0);
        *(undefined4 *)(iVar4 + puVar2[2]) = uVar5;
        *(undefined4 *)(iVar4 + *(int *)(iVar3 + 0x10)) = *(undefined4 *)(iVar4 + puVar2[2]);
        if (*(int *)(iVar4 + *(int *)(iVar3 + 0x10)) == -1) {
          return -0x7ff8fff2;
        }
        FUN_00914f00();
        *(undefined4 *)
         (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar4 + *(int *)(iVar3 + 0x10)) * 4) + 0x14) =
             *(undefined4 *)
              (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar4 + *(int *)(param_1 + 0x10)) * 4) +
              0x14);
        local_8 = local_8 + 1;
        *(undefined4 *)
         (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar4 + *(int *)(iVar3 + 0x10)) * 4) + 0x18) =
             *(undefined4 *)
              (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar4 + *(int *)(param_1 + 0x10)) * 4) +
              0x18);
        **(undefined4 **)(*(int *)(in_ECX + 0x14) + *(int *)(iVar4 + *(int *)(iVar3 + 0x10)) * 4) =
             **(undefined4 **)
               (*(int *)(in_ECX + 0x14) + *(int *)(iVar4 + *(int *)(param_1 + 0x10)) * 4);
      } while (local_8 < *(uint *)(iVar3 + 0xc));
    }
    iVar3 = FUN_00917482();
    if (iVar3 < 0) {
      return iVar3;
    }
    *puVar2 = 0;
  }
  return 0;
}


// ==== FUN_00917edb @ 0x00917edb ====

undefined4 FUN_00917edb(uint *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_14;
  uint local_c;
  int local_8;
  
  if ((*param_1 & 0xfff00000) != 0) {
    uVar3 = *param_1 & 0xfffff;
    local_14 = param_1[1] / uVar3;
    if (local_14 != 0) {
      local_8 = 0;
      do {
        if (uVar3 != 0) {
          iVar4 = local_8;
          local_c = uVar3;
          do {
            iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar4 + param_1[2]) * 4);
            if ((*(int *)(iVar1 + 0x48) != -1) && (*(int *)(iVar1 + 8) == -1)) {
              iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + *(int *)(iVar1 + 0x48) * 4);
              *(uint *)(iVar1 + 0x40) =
                   *(uint *)(iVar1 + 0x40) | 1 << ((byte)*(undefined4 *)(iVar2 + 0x24) & 0x1f);
              *(undefined4 *)(iVar2 + 0x28) = 1;
            }
            iVar4 = iVar4 + 4;
            local_c = local_c - 1;
          } while (local_c != 0);
          iVar4 = local_8;
          uVar5 = uVar3;
          do {
            iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar4 + param_1[2]) * 4);
            iVar2 = *(int *)(iVar1 + 0x48);
            if (((iVar2 != -1) && (*(int *)(iVar1 + 8) == -1)) &&
               (iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + iVar2 * 4), *(int *)(iVar1 + 0x28) != 0))
            {
              *(undefined4 *)(iVar1 + 0x28) = 0;
              *(uint *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + 1U & 0x1f;
            }
            iVar4 = iVar4 + 4;
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
        local_8 = local_8 + uVar3 * 4;
        local_14 = local_14 - 1;
      } while (local_14 != 0);
    }
  }
  return 0;
}


// ==== FUN_00917fc0 @ 0x00917fc0 ====

undefined4 FUN_00917fc0(uint param_1,int *param_2,uint param_3,int *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  int local_40 [4];
  int local_30 [4];
  int *local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int *local_c;
  uint local_8;
  
  local_14 = 0xffffffff;
  iVar2 = *(int *)(*(int *)(in_ECX + 0x14) +
                  **(int **)(*(int *)(*(int *)(in_ECX + 0x18) + param_1 * 4) + 0x10) * 4);
  local_1c = *(int *)(iVar2 + 0x14);
  iVar6 = *param_2;
  local_18 = *(int *)(iVar2 + 0x18);
  do {
    iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + iVar6 * 4);
    local_10 = iVar2;
    if ((*(int *)(iVar2 + 0x10) == 0) &&
       ((*(uint *)(iVar2 + 0x48) == 0xffffffff || (*(uint *)(iVar2 + 0x48) < param_1)))) {
      iVar4 = local_1c;
      iVar7 = local_18;
      if (local_1c != -1) {
        do {
          if (iVar4 == *(int *)(iVar2 + 0x14)) break;
          iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
          iVar7 = *(int *)(iVar4 + 0x18);
          iVar4 = *(int *)(iVar4 + 0x14);
        } while (iVar4 != -1);
      }
      if ((iVar4 == *(int *)(iVar2 + 0x14)) && (iVar7 == *(int *)(iVar2 + 0x18))) {
        local_30[0] = iVar6;
        local_8 = 1;
        if (1 < param_3) {
          piVar8 = param_2 + 1;
          local_c = piVar8;
          local_20 = (int *)((int)local_30 - (int)param_2);
LAB_00918072:
          iVar6 = *piVar8;
          do {
            iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + iVar6 * 4);
            if ((*(uint *)(iVar7 + 0x10) == local_8) &&
               ((((*(uint *)(iVar7 + 0x48) == 0xffffffff || (*(uint *)(iVar7 + 0x48) < param_1)) &&
                 (*(int *)(iVar7 + 4) == *(int *)(iVar2 + 4))) &&
                ((*(int *)(iVar7 + 0xc) == *(int *)(iVar2 + 0xc) &&
                 (*(int *)(iVar7 + 8) == *(int *)(iVar2 + 8))))))) {
              iVar4 = local_18;
              iVar9 = local_1c;
              if (local_1c != -1) {
                do {
                  if (iVar9 == *(int *)(iVar7 + 0x14)) break;
                  iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + iVar9 * 4);
                  iVar4 = *(int *)(iVar9 + 0x18);
                  iVar9 = *(int *)(iVar9 + 0x14);
                } while (iVar9 != -1);
              }
              if ((iVar9 == *(int *)(iVar7 + 0x14)) && (iVar4 == *(int *)(iVar7 + 0x18)))
              goto LAB_009180e3;
            }
            iVar6 = *(int *)(iVar7 + 0x34);
            local_c = piVar8;
            if (iVar6 == *piVar8) break;
          } while( true );
        }
LAB_00918104:
        if (local_8 == param_3) {
          uVar10 = 0;
          uVar5 = 0;
          if (param_3 != 0) {
            do {
              if (*(int *)(*(int *)(local_30[uVar5] * 4 + *(int *)(in_ECX + 0x14)) + 0x48) != 0) {
                iVar6 = param_1 - *(int *)(*(int *)(local_30[uVar5] * 4 + *(int *)(in_ECX + 0x14)) +
                                          0x48);
                uVar10 = uVar10 + iVar6 * iVar6;
              }
              uVar5 = uVar5 + 1;
            } while (uVar5 < param_3);
          }
          if (uVar10 < local_14) {
            local_14 = uVar10;
            piVar8 = local_30;
            piVar11 = local_40;
            for (uVar5 = param_3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *piVar11 = *piVar8;
              piVar8 = piVar8 + 1;
              piVar11 = piVar11 + 1;
            }
          }
        }
      }
    }
    iVar6 = *(int *)(iVar2 + 0x34);
    if (iVar6 == *param_2) {
      if (local_14 == 0xffffffff) {
        uVar5 = FUN_00915378(param_3 & 0xfffff | 0x10000000,0xffffffff,0xffffffff);
        if (uVar5 == 0xffffffff) {
          return 0x8007000e;
        }
        iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
        local_14 = uVar5;
        FUN_00914593();
        local_8 = 0;
        if (param_3 != 0) {
          do {
            iVar6 = local_8 * 4;
            local_20 = param_2 + local_8;
            *(int *)(iVar6 + *(int *)(iVar2 + 8)) = *local_20;
            uVar3 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),*param_4,local_8,0);
            *(undefined4 *)(iVar6 + *(int *)(iVar2 + 0x10)) = uVar3;
            if (*(int *)(iVar6 + *(int *)(iVar2 + 0x10)) == -1) {
              return 0x8007000e;
            }
            *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar6 + *(int *)(iVar2 + 0x10)) * 4
                             ) + 0x18) = local_18;
            *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar6 + *(int *)(iVar2 + 0x10)) * 4
                             ) + 0x14) = local_1c;
            **(undefined4 **)
              (*(int *)(in_ECX + 0x14) + *(int *)(iVar6 + *(int *)(iVar2 + 0x10)) * 4) =
                 **(undefined4 **)
                   (*(int *)(in_ECX + 0x14) + *(int *)(iVar6 + *(int *)(iVar2 + 8)) * 4);
            local_8 = local_8 + 1;
            *(undefined4 *)
             (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar6 + *(int *)(iVar2 + 0x10)) * 4) +
             0x34) = *(undefined4 *)
                      (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar6 + *(int *)(iVar2 + 8)) * 4)
                      + 0x34);
            *(undefined4 *)
             (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar6 + *(int *)(iVar2 + 8)) * 4) + 0x34)
                 = *(undefined4 *)(iVar6 + *(int *)(iVar2 + 0x10));
            *local_20 = *(int *)(iVar6 + *(int *)(iVar2 + 0x10));
          } while (local_8 < param_3);
          uVar5 = local_14;
        }
        for (; param_1 < uVar5; uVar5 = uVar5 - 1) {
          puVar1 = (undefined4 *)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
          *puVar1 = puVar1[-1];
        }
        *(int *)(*(int *)(in_ECX + 0x18) + uVar5 * 4) = iVar2;
        *param_4 = *param_4 + 1;
      }
      else {
        piVar8 = local_40;
        for (; param_3 != 0; param_3 = param_3 - 1) {
          *param_2 = *piVar8;
          piVar8 = piVar8 + 1;
          param_2 = param_2 + 1;
        }
      }
      return 0;
    }
  } while( true );
LAB_009180e3:
  uVar5 = local_8 + 1;
  local_8 = uVar5;
  *(int *)(((int)local_30 - (int)param_2) + (int)piVar8) = iVar6;
  piVar8 = piVar8 + 1;
  local_c = piVar8;
  if (param_3 <= uVar5) goto LAB_00918104;
  goto LAB_00918072;
}


// ==== FUN_009182b3 @ 0x009182b3 ====

uint FUN_009182b3(void)

{
  int *piVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  uint local_c;
  uint local_8;
  
  uVar3 = 0;
  local_8 = 0;
  if ((*(uint *)(in_ECX + 0x6c) & 0x4000000) == 0) {
    if (((*(uint *)(in_ECX + 0x6c) & 0x8000000) != 0) &&
       (uVar2 = *(uint *)(in_ECX + 0xc), uVar2 != 0)) {
      local_c = 1;
      do {
        if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x18) + uVar3 * 4) + 0x2c) & 1) != 0) &&
            (local_8 = local_8 + 1, local_c < uVar2)) &&
           (piVar1 = (int *)(*(int *)(in_ECX + 0x18) + uVar3 * 4),
           *(int *)(*piVar1 + 0x2c) == *(int *)(piVar1[1] + 0x2c))) {
          uVar3 = uVar3 + 1;
          local_c = local_c + 1;
        }
        uVar3 = uVar3 + 1;
        local_c = local_c + 1;
      } while (uVar3 < uVar2);
    }
  }
  else {
    if (*(uint *)(in_ECX + 0xc) == 0) {
      return 0;
    }
    local_8 = (uint)((*(byte *)(**(int **)(in_ECX + 0x18) + 0x2c) & 1) == 0);
    uVar3 = 1;
    if (1 < *(uint *)(in_ECX + 0xc)) {
      do {
        if (((*(byte *)((*(int **)(in_ECX + 0x18))[uVar3] + 0x2c) & 1) != 0) &&
           (piVar1 = (int *)(*(int *)(in_ECX + 0x18) + uVar3 * 4),
           *(int *)(*piVar1 + 0x2c) != *(int *)(piVar1[-1] + 0x2c))) {
          local_8 = local_8 + 1;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(in_ECX + 0xc));
    }
  }
  return local_8;
}


// ==== FUN_00918365 @ 0x00918365 ====

undefined4 FUN_00918365(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_14;
  uint local_10;
  int *local_8;
  
  iVar5 = param_1 * 4;
  local_8 = (int *)(*(int *)(in_ECX + 0x18) + iVar5);
  iVar7 = *local_8;
  uVar1 = *(uint *)(iVar7 + 0x2c);
  iVar2 = param_1;
  if ((uVar1 & 1) == 0) {
    return 0;
  }
  while ((iVar2 != 0 && (local_8 = local_8 + -1, uVar1 < *(uint *)(*local_8 + 0x2c)))) {
    iVar2 = iVar2 + -1;
  }
  local_10 = param_1 - iVar2 >> 1;
  if (local_10 != 0) {
    local_8 = (int *)(iVar2 << 2);
    iVar6 = iVar5;
    do {
      puVar4 = (undefined4 *)((int)local_8 + *(int *)(in_ECX + 0x18));
      uVar3 = *puVar4;
      *puVar4 = *(undefined4 *)(iVar6 + -4 + *(int *)(in_ECX + 0x18));
      *(undefined4 *)(iVar6 + -4 + *(int *)(in_ECX + 0x18)) = uVar3;
      local_8 = (int *)((int)local_8 + 4);
      iVar6 = iVar6 + -4;
      local_10 = local_10 - 1;
    } while (local_10 != 0);
  }
  local_14 = iVar2;
  if (iVar2 != 0) {
    uVar1 = *(uint *)(iVar7 + 0x2c);
    local_8 = (int *)(*(int *)(in_ECX + 0x18) + -4 + iVar2 * 4);
    if (*(uint *)(*local_8 + 0x2c) < uVar1) {
      local_14 = iVar2 + -1;
      goto LAB_00918474;
    }
    do {
      if (uVar1 != *(uint *)(*local_8 + 0x2c)) break;
      local_8 = local_8 + -1;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  local_8 = (int *)((uint)(iVar2 - local_14) >> 1);
  if (local_8 != (int *)0x0) {
    local_10 = local_14 << 2;
    iVar7 = iVar2 << 2;
    do {
      puVar4 = (undefined4 *)(local_10 + *(int *)(in_ECX + 0x18));
      uVar3 = *puVar4;
      *puVar4 = *(undefined4 *)(iVar7 + -4 + *(int *)(in_ECX + 0x18));
      *(undefined4 *)(iVar7 + -4 + *(int *)(in_ECX + 0x18)) = uVar3;
      local_10 = local_10 + 4;
      iVar7 = iVar7 + -4;
      local_8 = (int *)((int)local_8 - 1);
    } while (local_8 != (int *)0x0);
  }
LAB_00918474:
  if (local_14 == iVar2) {
    uVar3 = 0;
  }
  else {
    param_1 = param_1 - local_14 >> 1;
    if (param_1 != 0) {
      local_14 = local_14 << 2;
      iVar7 = iVar5;
      do {
        puVar4 = (undefined4 *)(local_14 + *(int *)(in_ECX + 0x18));
        uVar3 = *puVar4;
        *puVar4 = *(undefined4 *)(iVar7 + -4 + *(int *)(in_ECX + 0x18));
        *(undefined4 *)(iVar7 + -4 + *(int *)(in_ECX + 0x18)) = uVar3;
        local_14 = local_14 + 4;
        iVar7 = iVar7 + -4;
        param_1 = param_1 - 1;
      } while (param_1 != 0);
    }
    puVar4 = (undefined4 *)(*(int *)(in_ECX + 0x18) + iVar5);
    uVar3 = puVar4[-1];
    puVar4[-1] = *puVar4;
    *(undefined4 *)(iVar5 + *(int *)(in_ECX + 0x18)) = uVar3;
    uVar3 = 1;
  }
  return uVar3;
}


// ==== FUN_009184cd @ 0x009184cd ====

bool FUN_009184cd(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  uint uVar7;
  int in_ECX;
  int local_18;
  uint local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  uVar7 = 0;
  bVar6 = false;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4) + 0x30) = 0xffffffff;
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(in_ECX + 8));
  }
  local_14 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + local_14 * 4);
      if ((*puVar2 & 0xfff00000) != 0) {
        local_18 = 0;
        while (local_8 = FUN_009145b2(local_18,&local_10), local_8 != 0) {
          if (*(int *)(*(int *)(*local_10 * 4 + *(int *)(in_ECX + 0x14)) + 0x30) != -1) {
            local_c = 1;
            if (1 < local_8) {
              do {
                if ((*(int *)(*(int *)(local_10[local_c] * 4 + *(int *)(in_ECX + 0x14)) + 0x30) ==
                     -1) || (iVar3 = *(int *)(in_ECX + 0x14),
                            *(int *)(*(int *)(iVar3 + *(int *)(*(int *)(iVar3 + *local_10 * 4) +
                                                              0x30) * 4) + 0xc) !=
                            *(int *)(*(int *)(iVar3 + *(int *)(*(int *)(iVar3 + local_10[local_c] *
                                                                                4) + 0x30) * 4) +
                                    0xc))) break;
                local_c = local_c + 1;
              } while (local_c < local_8);
              if (local_c < local_8) goto LAB_009185b4;
            }
            uVar7 = 0;
            if (local_8 != 0) {
              do {
                piVar1 = local_10 + uVar7;
                uVar7 = uVar7 + 1;
                *piVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4) + 0x30);
              } while (uVar7 < local_8);
            }
            bVar6 = true;
          }
LAB_009185b4:
          local_18 = local_18 + 1;
        }
        if (((*puVar2 & 0xfff00000) == 0x10000000) && (local_c = 0, puVar2[3] != 0)) {
          do {
            iVar3 = *(int *)(local_c * 4 + puVar2[4]);
            iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
            iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(local_c * 4 + puVar2[2]) * 4);
            if (((*(int *)(iVar4 + 4) == *(int *)(iVar5 + 4)) &&
                ((((*(int *)(iVar4 + 8) == *(int *)(iVar5 + 8) &&
                   (*(int *)(iVar4 + 0x10) == *(int *)(iVar5 + 0x10))) &&
                  (*(int *)(iVar4 + 0x14) == *(int *)(iVar5 + 0x14))) &&
                 ((*(int *)(iVar4 + 0x18) == *(int *)(iVar5 + 0x18) &&
                  (*(int *)(iVar5 + 0x38) == -1)))))) && (*(int *)(iVar4 + 0x3c) == 0)) {
              *(int *)(iVar5 + 0x30) = iVar3;
            }
            local_c = local_c + 1;
          } while (local_c < puVar2[3]);
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < *(uint *)(in_ECX + 0xc));
  }
  return !bVar6;
}


// ==== FUN_00918667 @ 0x00918667 ====

void FUN_00918667(int param_1,int *param_2,int param_3)

{
  int in_ECX;
  uint uVar1;
  
  if (*(int *)(param_1 + 0x38) != param_3) {
    *(int *)(param_1 + 0x38) = param_3;
    *param_2 = *param_2 + 1;
    uVar1 = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      do {
        FUN_00918667(*(undefined4 *)
                      (*(int *)(in_ECX + 0x18) + *(int *)(*(int *)(param_1 + 0x18) + uVar1 * 4) * 4)
                     ,param_2,param_3);
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_1 + 0x14));
    }
  }
  return;
}


// ==== FUN_009186b5 @ 0x009186b5 ====

void FUN_009186b5(undefined4 param_1,undefined4 param_2,int *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  iVar3 = param_4;
  FUN_00918667(param_1,param_2,param_4);
  param_4 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + param_4 * 4);
      uVar4 = 0;
      if ((*(int *)(iVar1 + 0x24) == 0) && (*(int *)(iVar1 + 0x14) != 0)) {
        do {
          iVar2 = *(int *)(*(int *)(in_ECX + 0x18) +
                          *(int *)(*(int *)(iVar1 + 0x18) + uVar4 * 4) * 4);
          if (iVar3 == *(int *)(iVar1 + 0x38)) {
            if (*(int *)(iVar2 + 0x24) != 0) {
              *param_3 = *param_3 + -0x10000;
            }
          }
          else if (iVar3 == *(int *)(iVar2 + 0x38)) {
            *param_3 = *param_3 + 0x10000;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(iVar1 + 0x14));
      }
      param_4 = param_4 + 1;
    } while (param_4 < *(uint *)(in_ECX + 0xc));
  }
  return;
}


// ==== FUN_00918735 @ 0x00918735 ====

int FUN_00918735(uint param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint in_ECX;
  uint uVar5;
  uint uVar6;
  int *local_10;
  int *local_c;
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + param_1 * 4);
  uVar5 = 0;
  if (*(int *)(iVar2 + 0x24) == 0) {
    local_8 = in_ECX;
    if (*(int *)(iVar2 + 0x14) != 0) {
      do {
        local_10 = (int *)0x0;
        piVar1 = (int *)(*(int *)(iVar2 + 0x18) + uVar5 * 4);
        iVar4 = *(int *)(*(int *)(local_8 + 0x18) + *piVar1 * 4);
        local_c = (int *)0x0;
        FUN_009186b5(iVar4,&local_c,&local_10,*piVar1);
        uVar5 = uVar5 + 1;
        *(int *)(iVar4 + 0x30) = (int)local_10 / ((int)local_c + 1);
        in_ECX = local_8;
      } while (uVar5 < *(uint *)(iVar2 + 0x14));
    }
    FUN_00915b0e(FUN_009157ce,*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x14),in_ECX);
    uVar5 = 0;
    if (*(int *)(iVar2 + 0x14) != 0) {
      do {
        iVar4 = FUN_00918735(*(undefined4 *)(*(int *)(iVar2 + 0x18) + uVar5 * 4),param_2,param_3);
        if (iVar4 < 0) {
          return iVar4;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(iVar2 + 0x14));
    }
    if (*(int *)(iVar2 + 0x24) == 0) {
      local_8 = 0;
      *(undefined4 *)(iVar2 + 0x24) = 1;
      *(uint *)(param_2 + *param_3 * 4) = param_1;
      *param_3 = *param_3 + 1;
      if (*(int *)(iVar2 + 0x14) != 0) {
        do {
          iVar4 = *(int *)(in_ECX + 0x18);
          iVar3 = *(int *)(iVar4 + *(int *)(*(int *)(iVar2 + 0x18) + local_8 * 4) * 4);
          uVar5 = *(uint *)(iVar3 + 0x1c);
          param_1 = 0;
          uVar6 = 0xffffffff;
          if (uVar5 != 0) {
            local_10 = *(int **)(iVar3 + 0x20);
            local_c = local_10;
            do {
              if (*(int *)(*(int *)(iVar4 + *local_c * 4) + 0x24) == 0) {
                if (uVar6 != 0xffffffff) goto LAB_00918858;
                uVar6 = param_1;
              }
              param_1 = param_1 + 1;
              local_c = local_c + 1;
            } while (param_1 < uVar5);
            if (uVar6 != 0xffffffff) {
LAB_00918858:
              if (param_1 == uVar5) {
                iVar3 = *(int *)(iVar4 + local_10[uVar6] * 4);
                uVar5 = *(uint *)(iVar3 + 0x14);
                param_1 = 0;
                if (uVar5 != 0) {
                  local_c = *(int **)(iVar3 + 0x18);
                  do {
                    if (*(int *)(*(int *)(iVar4 + *local_c * 4) + 0x24) == 0) break;
                    param_1 = param_1 + 1;
                    local_c = local_c + 1;
                  } while (param_1 < uVar5);
                }
                if ((uVar5 <= param_1) &&
                   (iVar4 = FUN_00918735(local_10[uVar6],param_2,param_3), iVar4 < 0)) {
                  return iVar4;
                }
              }
            }
          }
          local_8 = local_8 + 1;
        } while (local_8 < *(uint *)(iVar2 + 0x14));
      }
    }
  }
  return 0;
}


// ==== FUN_009188c0 @ 0x009188c0 ====

int FUN_009188c0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  piVar1 = (int *)(param_1 + (param_3 + param_2 * 4) * 4);
  if (*piVar1 == -1) {
    iVar3 = param_4 * 4;
    iVar2 = *(int *)(iVar3 + *(int *)(in_ECX + 0x14));
    if (*(int *)(iVar2 + 0xc) == -1) {
      *(int *)(*(int *)(iVar3 + *(int *)(in_ECX + 0x14)) + 0xc) = param_2;
      *(int *)(*(int *)(iVar3 + *(int *)(in_ECX + 0x14)) + 0x10) = param_3;
    }
    else {
      param_4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),param_2,param_3,
                             *(undefined8 *)(iVar2 + 0x20));
    }
    *piVar1 = param_4;
  }
  return *piVar1;
}


// ==== FUN_00918922 @ 0x00918922 ====

undefined4 FUN_00918922(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  
  piVar2 = param_2;
  uVar4 = 1;
  if (1 < param_3) {
    do {
      if (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2[uVar4] * 4) + 0x20) !=
          *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_2 * 4) + 0x20)) {
        uVar4 = 0;
        if (param_3 == 0) {
          return 0;
        }
        do {
          param_2 = (int *)0x0;
          do {
            uVar3 = (int)param_2 + uVar4 & 3;
            iVar1 = *(int *)(param_1 + uVar3 * 4);
            if ((iVar1 != -1) &&
               (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + piVar2[uVar4] * 4) + 0x20) ==
                *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar1 * 4) + 0x20))) {
              piVar2[uVar4] = *(int *)(param_1 + uVar3 * 4);
              break;
            }
            param_2 = (int *)((int)param_2 + 1);
          } while (param_2 < 4);
          uVar4 = uVar4 + 1;
          if (param_3 <= uVar4) {
            return 0;
          }
        } while( true );
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_3);
  }
  param_2 = (int *)0x0;
  while( true ) {
    uVar4 = (int)param_2 - 1U & 3;
    iVar1 = *(int *)(param_1 + uVar4 * 4);
    if ((iVar1 != -1) &&
       (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar2 * 4) + 0x20) ==
        *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar1 * 4) + 0x20))) break;
    param_2 = (int *)((int)param_2 + 1);
    if (3 < param_2) {
      return 0;
    }
  }
  uVar3 = 0;
  if (param_3 == 0) {
    return 0;
  }
  do {
    piVar2[uVar3] = *(int *)(param_1 + uVar4 * 4);
    uVar3 = uVar3 + 1;
  } while (uVar3 < param_3);
  return 0;
}


// ==== FUN_00918a13 @ 0x00918a13 ====

undefined4 FUN_00918a13(int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_2c [4];
  int local_1c;
  uint local_18;
  int *local_14;
  uint local_c;
  uint local_8;
  
  uVar4 = 0;
  local_8 = 0;
  uVar2 = 0;
  do {
    if (param_2[uVar2] == -1) break;
    local_8 = local_8 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  if (local_8 == 0) {
    return 0;
  }
  if ((*(uint *)(in_ECX + 0x6c) & 6) == 0) {
    if (local_8 != 0) {
      puVar8 = param_3;
      for (uVar2 = local_8; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
    }
  }
  else {
    uVar2 = 1;
    if (1 < local_8) {
      do {
        if (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_2 * 4) + 0x20) !=
            *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2[uVar2] * 4) + 0x20)) break;
        uVar2 = uVar2 + 1;
      } while (uVar2 < local_8);
    }
    if (uVar2 == local_8) {
      *param_3 = 0;
      local_8 = 1;
    }
    uVar2 = 0;
    if (local_8 != 0) {
      do {
        uVar4 = uVar4 + (param_3[uVar2] == 0);
        uVar2 = uVar2 + 1;
      } while (uVar2 < local_8);
    }
    if (((*(byte *)(in_ECX + 0x6c) & 4) != 0) && (uVar4 != 0)) {
      if (1 < uVar4) {
        return 0x80004005;
      }
      uVar2 = 0;
      if (local_8 != 0) {
        do {
          if ((param_3[uVar2] & 8) != 0) {
            return 0x80004005;
          }
          if (param_3[uVar2] == 0) {
            param_3[uVar2] = 8;
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < local_8);
      }
      uVar4 = 0;
    }
    uVar2 = 0;
    uVar6 = 0;
    if (local_8 != 0) {
      do {
        if ((uVar6 & param_3[uVar2]) != 0) {
          return 0x80004005;
        }
        uVar6 = uVar6 | param_3[uVar2];
        uVar2 = uVar2 + 1;
      } while (uVar2 < local_8);
    }
    iVar3 = 0;
    uVar2 = 0;
    do {
      if ((uVar6 & 1 << ((byte)uVar2 & 0x1f)) != 0) {
        iVar3 = iVar3 + 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 4);
    if (4 < iVar3 + uVar4) {
      return 0x80004005;
    }
  }
  local_1c = 0;
  local_14 = param_1;
  do {
    piVar1 = local_14;
    local_c = 0;
    local_2c[0] = *local_14;
    local_2c[1] = local_14[1];
    local_2c[2] = local_14[2];
    local_2c[3] = local_14[3];
    if (local_8 == 0) {
LAB_00918bcc:
      local_18 = 0;
      if (local_8 == 0) {
LAB_00918c69:
        uVar2 = 0;
        do {
          iVar7 = uVar2 * 4;
          iVar3 = local_2c[uVar2];
          if (iVar3 != *(int *)((int)piVar1 + (int)local_2c + (iVar7 - (int)local_2c))) {
            iVar3 = FUN_009188c0(param_1,local_1c,uVar2,iVar3);
          }
          uVar2 = uVar2 + 1;
          *(int *)((int)param_2 + (int)local_2c + (iVar7 - (int)local_2c)) = iVar3;
        } while (uVar2 < 4);
        return 0;
      }
      local_c = (int)param_3 - (int)param_2;
      piVar5 = param_2;
      do {
        uVar2 = 0;
        if (*(int *)(((int)param_3 - (int)param_2) + (int)piVar5) == 0) {
          do {
            if ((local_2c[uVar2] != -1) &&
               (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + local_2c[uVar2] * 4) + 0x20) ==
                *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2[local_18] * 4) + 0x20)))
            break;
            uVar2 = uVar2 + 1;
          } while (uVar2 < 4);
          if (3 < uVar2) {
            uVar2 = 0;
            do {
              if (local_2c[uVar2] == -1) {
                local_2c[uVar2] = *piVar5;
                break;
              }
              uVar2 = uVar2 + 1;
            } while (uVar2 < 4);
            if (uVar2 == 4) break;
          }
        }
        local_18 = local_18 + 1;
        piVar5 = piVar5 + 1;
      } while (local_18 < local_8);
      if (local_8 <= local_18) goto LAB_00918c69;
    }
    else {
      do {
        uVar4 = 0;
        uVar2 = param_3[local_c];
        do {
          if ((uVar2 & 1 << ((byte)uVar4 & 0x1f)) != 0) {
            iVar3 = local_2c[uVar4];
            if (iVar3 == -1) {
              local_2c[uVar4] = param_2[local_c];
            }
            else if (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4) + 0x20) !=
                     *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2[local_c] * 4) + 0x20))
            break;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < 4);
      } while ((3 < uVar4) && (local_c = local_c + 1, local_c < local_8));
      if (local_8 <= local_c) goto LAB_00918bcc;
    }
    local_1c = local_1c + 1;
    local_14 = local_14 + 4;
  } while( true );
}


// ==== FUN_00918cb6 @ 0x00918cb6 ====

undefined4 FUN_00918cb6(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
  uVar2 = *(uint *)(iVar1 + 0x48);
  if (uVar2 == 0xffffffff) {
LAB_00918d14:
    uVar4 = 1;
  }
  else {
    if ((param_3 <= uVar2) && (uVar2 < param_4)) {
      iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + **(int **)(param_2 + 0x10) * 4);
      iVar5 = *(int *)(iVar3 + 0x18);
      iVar3 = *(int *)(iVar3 + 0x14);
      if (iVar3 != -1) {
        do {
          if (iVar3 == *(int *)(iVar1 + 0x14)) break;
          iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
          iVar5 = *(int *)(iVar3 + 0x18);
          iVar3 = *(int *)(iVar3 + 0x14);
        } while (iVar3 != -1);
      }
      if ((iVar3 == *(int *)(iVar1 + 0x14)) && (iVar5 == *(int *)(iVar1 + 0x18))) goto LAB_00918d14;
    }
    uVar4 = 0;
  }
  return uVar4;
}


// ==== FUN_00918d20 @ 0x00918d20 ====

undefined4 FUN_00918d20(int param_1,int param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  param_2 = param_2 * 4;
  param_1 = param_1 * 4;
  if (((*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1) + 4) ==
        *(int *)(*(int *)(param_2 + *(int *)(in_ECX + 0x14)) + 4)) &&
      (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1) + 8) ==
       *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2) + 8))) &&
     (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1) + 0xc) ==
      *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2) + 0xc))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00918d73 @ 0x00918d73 ====

undefined4 FUN_00918d73(uint param_1,double *param_2,double *param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  double dVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  int in_ECX;
  uint uVar9;
  uint uVar10;
  int *local_8;
  
  iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
  iVar1 = *(int *)(iVar7 + 0x48);
  uVar5 = 0xffffffff;
  if ((iVar1 != -1) && (*(int *)(iVar7 + 8) == -1)) {
    puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar1 * 4);
    uVar9 = *puVar2 & 0xfff00000;
    if (uVar9 == 0x10100000) {
      uVar9 = 0;
      if (puVar2[3] != 0) {
        piVar6 = (int *)puVar2[4];
        do {
          if (*piVar6 == param_1) break;
          uVar9 = uVar9 + 1;
          piVar6 = piVar6 + 1;
        } while (uVar9 < puVar2[3]);
      }
      if (param_2 != (double *)0x0) {
        *param_2 = -*param_2;
      }
      uVar5 = *(undefined4 *)(puVar2[2] + uVar9 * 4);
    }
    else if ((uVar9 == 0x20500000) || (uVar9 == 0x20400000)) {
      uVar10 = 0;
      if (puVar2[3] != 0) {
        piVar6 = (int *)puVar2[4];
        do {
          if (*piVar6 == param_1) break;
          uVar10 = uVar10 + 1;
          piVar6 = piVar6 + 1;
        } while (uVar10 < puVar2[3]);
      }
      uVar3 = puVar2[3];
      param_1 = 0;
      iVar7 = uVar10 * 4;
      puVar8 = (undefined4 *)(iVar7 + puVar2[2]);
      local_8 = (int *)(puVar2[2] + (uVar3 + uVar10) * 4);
      do {
        uVar5 = *puVar8;
        iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *local_8 * 4);
        if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 5) & 1) != 0)
           && (*(int *)(iVar1 + 8) == -1)) {
          if (param_2 != (double *)0x0) {
            dVar4 = *(double *)(iVar1 + 0x20) * *param_2;
            if (uVar9 != 0x20500000) {
              dVar4 = dVar4 + *param_3;
              param_2 = param_3;
            }
            *param_2 = dVar4;
          }
          return uVar5;
        }
        param_1 = param_1 + 1;
        puVar8 = puVar8 + uVar3;
        local_8 = local_8 + -uVar3;
      } while (param_1 < 2);
      if ((uVar9 == 0x20400000) &&
         (*(int *)(puVar2[2] + iVar7) == *(int *)(puVar2[2] + (puVar2[3] + uVar10) * 4))) {
        if (param_2 != (double *)0x0) {
          *param_2 = *param_2 + *param_2;
        }
        uVar5 = *(undefined4 *)(iVar7 + puVar2[2]);
      }
      else {
        uVar5 = 0xffffffff;
      }
    }
  }
  return uVar5;
}


// ==== FUN_00918ee0 @ 0x00918ee0 ====

undefined4 FUN_00918ee0(int param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint local_8;
  
  uVar5 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    do {
      iVar7 = *(int *)(*(int *)(in_ECX + 0x10) + uVar5 * 4);
      uVar6 = *(uint *)(iVar7 + 4);
      if (((uVar6 & param_2) == param_2) && ((param_3 & uVar6) == 0)) {
        *(undefined4 *)(iVar7 + 8) = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 4));
  }
  uVar5 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + uVar5 * 4);
      iVar2 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4);
      if ((((*(uint *)(iVar2 + 4) & param_2) == param_2) && ((param_3 & *(uint *)(iVar2 + 4)) == 0))
         && (uVar6 = *(int *)(iVar7 + 0xc) + 1, *(uint *)(iVar2 + 8) <= uVar6)) {
        *(uint *)(iVar2 + 8) = uVar6;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 8));
  }
  uVar5 = 0;
  iVar7 = 0;
  bVar4 = false;
  if (*(int *)(in_ECX + 4) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x10) + uVar5 * 4);
      uVar6 = *(uint *)(iVar2 + 4);
      if (((uVar6 & param_2) == param_2) && ((param_3 & uVar6) == 0)) {
        *(int *)(iVar2 + 0x10) = iVar7;
        *(int *)(iVar2 + 0x18) = param_1;
        if ((uVar6 & 0x400) != 0) {
          bVar4 = true;
        }
        iVar7 = iVar7 + *(int *)(iVar2 + 8);
        *(undefined4 *)(iVar2 + 8) = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 4));
  }
  local_8 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + local_8 * 4);
      iVar3 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + 4) * 4);
      if (((*(uint *)(iVar3 + 4) & param_2) == param_2) && ((param_3 & *(uint *)(iVar3 + 4)) == 0))
      {
        *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar3 + 0x18);
        *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + *(int *)(iVar3 + 0x10);
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 8));
  }
  *(int *)(*(int *)(param_1 * 4 + *(int *)(in_ECX + 0x10)) + 8) = iVar7;
  if (bVar4) {
    pbVar1 = (byte *)(*(int *)(param_1 * 4 + *(int *)(in_ECX + 0x10)) + 5);
    *pbVar1 = *pbVar1 | 4;
  }
  return 0;
}


// ==== FUN_00919005 @ 0x00919005 ====

bool FUN_00919005(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  bool bVar4;
  uint local_8;
  
  uVar3 = 0;
  local_8 = 0;
  if (param_1 != -1) {
    iVar2 = param_1;
    do {
      iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4) + 0x14);
      local_8 = local_8 + 1;
    } while (iVar2 != -1);
  }
  if (param_3 != -1) {
    iVar2 = param_3;
    do {
      iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4) + 0x14);
      uVar3 = uVar3 + 1;
    } while (iVar2 != -1);
  }
  bVar4 = false;
  if (uVar3 < local_8) {
    iVar2 = local_8 - uVar3;
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
      param_2 = *(int *)(iVar1 + 0x18);
      local_8 = local_8 - 1;
      iVar2 = iVar2 + -1;
      param_1 = *(int *)(iVar1 + 0x14);
    } while (iVar2 != 0);
    bVar4 = uVar3 < local_8;
  }
  if (!(bVar4 || uVar3 == local_8)) {
    iVar2 = uVar3 - local_8;
    do {
      iVar2 = iVar2 + -1;
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + param_3 * 4);
      param_4 = *(int *)(iVar1 + 0x18);
      param_3 = *(int *)(iVar1 + 0x14);
    } while (iVar2 != 0);
  }
  if (param_1 != param_3) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + param_3 * 4);
      param_2 = *(int *)(iVar2 + 0x18);
      param_4 = *(int *)(iVar1 + 0x18);
      param_1 = *(int *)(iVar2 + 0x14);
      param_3 = *(int *)(iVar1 + 0x14);
    } while (param_1 != param_3);
  }
  return param_2 != param_4;
}


// ==== FUN_009190ba @ 0x009190ba ====

int FUN_009190ba(int param_1,uint param_2,int param_3,int param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  
  iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + param_2 * 4);
  param_3 = *(int *)(*(int *)(param_1 + 0x1c) + (param_4 + param_3 * 4) * 4);
  if (param_3 == -1) {
    return -1;
  }
  do {
    iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + param_3 * 4);
    if (*(uint *)(iVar3 + 0x48) < *(uint *)(iVar2 + 0x58)) {
      if (*(uint *)(iVar3 + 0x58) <= *(uint *)(iVar2 + 0x48)) {
        return -1;
      }
      if ((*(int *)(iVar2 + 0x14) == *(int *)(iVar3 + 0x14)) &&
         (*(int *)(iVar2 + 0x18) == *(int *)(iVar3 + 0x14))) {
        return param_3;
      }
      if (*(uint *)(iVar2 + 0x48) < *(uint *)(iVar3 + 0x48)) {
        iVar6 = iVar2;
        param_4 = iVar3;
      }
      else {
        iVar6 = iVar3;
        param_4 = iVar2;
      }
      iVar4 = *(int *)(param_1 + 0x54);
      param_2 = 0;
      iVar7 = *(int *)(iVar6 + 0x74) * 4;
      iVar6 = *(int *)(iVar7 + *(int *)(param_1 + 0x50));
      uVar5 = *(uint *)(iVar7 + *(int *)(param_1 + 0x4c));
      if (uVar5 != 0) {
        do {
          puVar1 = (uint *)(*(int *)(param_1 + 0x58) +
                           *(int *)(iVar4 + iVar6 * 4 + param_2 * 4) * 0xc);
          if (*puVar1 <= *(uint *)(param_4 + 0x48)) break;
          iVar7 = FUN_00919005(*(undefined4 *)(param_4 + 0x14),*(undefined4 *)(param_4 + 0x18),
                               puVar1[1],puVar1[2]);
          if (iVar7 == 0) {
            return param_3;
          }
          param_2 = param_2 + 1;
        } while (param_2 < uVar5);
      }
    }
    param_3 = *(int *)(iVar3 + 0x30);
    if (param_3 == -1) {
      return -1;
    }
  } while( true );
}


// ==== FUN_009191b8 @ 0x009191b8 ====

uint FUN_009191b8(int param_1,uint param_2,uint param_3,uint param_4,uint *param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  uint local_4c [9];
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  uint *local_10;
  uint local_c;
  int local_8;
  
  iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + param_2 * 4);
  local_24 = *(uint *)(*(int *)(param_1 + 8) + *(int *)(iVar5 + 0xc) * 4);
  local_20 = iVar5;
  local_c = 4;
  local_18 = in_ECX;
  if ((*(byte *)(iVar5 + 3) & 0x80) == 0) {
    bVar7 = local_24 == 0;
    bVar8 = false;
    if (local_24 == 1) {
      if ((*(byte *)(in_ECX + 0x6c) & 4) != 0) goto LAB_00919215;
      bVar7 = false;
      bVar8 = true;
    }
    if (((!bVar7 && !bVar8) && ((*(byte *)(in_ECX + 0x6c) & 2) != 0)) ||
       (iVar2 = FUN_009145ef(), iVar2 != 0)) goto LAB_00919215;
  }
  else {
LAB_00919215:
    local_c = 1;
  }
  local_4c[4] = 0xffffffff;
  local_4c[5] = 0xffffffff;
  local_4c[6] = 0xffffffff;
  local_4c[7] = 0xffffffff;
  local_4c[0] = 0xffffffff;
  local_4c[1] = 0xffffffff;
  local_4c[2] = 0xffffffff;
  local_4c[3] = 0xffffffff;
  local_8 = 4;
  param_2 = 0;
  iVar5 = *(int *)(iVar5 + 0xc) << 4;
  do {
    local_28 = *(int *)(iVar5 + *(int *)(param_1 + 0x18));
    local_1c = 0;
    if (local_28 == -1) {
LAB_009192f3:
      local_8 = local_8 + -1;
    }
    else {
      local_4c[8] = *(uint *)(iVar5 + *(int *)(param_1 + 0x30));
      local_14 = 0;
      if (local_4c[8] == 0) goto LAB_009192f3;
      local_10 = (uint *)(*(int *)(param_1 + 0x38) + *(int *)(iVar5 + *(int *)(param_1 + 0x34)) * 4)
      ;
      do {
        uVar6 = *(uint *)(*(int *)(param_1 + 0x10) + (*local_10 & 0xfffffffc));
        if (uVar6 != 0xffffffff) {
          local_1c = 1;
        }
        if ((((param_3 == uVar6) &&
             (uVar6 = *(uint *)(*(int *)(param_1 + 0x14) + *local_10 * 4), uVar6 != 0xffffffff)) &&
            ((local_4c[uVar6 + 4] == 0xffffffff && ((local_c != 1 || (param_2 == uVar6)))))) &&
           (iVar2 = FUN_009190ba(param_1,local_28,param_3,uVar6), iVar2 == -1)) {
          local_8 = local_8 + -1;
          local_4c[uVar6 + 4] = param_2;
          local_4c[param_2] = uVar6;
          break;
        }
        local_14 = local_14 + 1;
        local_10 = local_10 + 1;
      } while (local_14 < local_4c[8]);
      if (local_1c == 0) goto LAB_009192f3;
    }
    uVar6 = 0;
    param_2 = param_2 + 1;
    iVar5 = iVar5 + 4;
  } while (param_2 < 4);
  uVar3 = local_8 << 0x1d;
  if (param_6 <= uVar3) {
    return uVar3;
  }
  iVar5 = 0;
  if ((int)param_4 < 0) {
    if ((param_3 & 1) == 0) goto LAB_0091932f;
  }
  else if (((int)param_4 < 1) || ((param_3 & 1) != 0)) goto LAB_0091932f;
  iVar5 = 1;
LAB_0091932f:
  uVar3 = uVar3 | iVar5 << 0x1c;
  param_4 = uVar3;
  if (uVar3 < param_6) {
    do {
      if ((local_4c[uVar6] == 0xffffffff) &&
         (iVar5 = *(int *)(*(int *)(param_1 + 0x18) + (uVar6 + *(int *)(local_20 + 0xc) * 4) * 4),
         iVar5 != -1)) {
        uVar4 = 0;
        if (local_c != 0) {
          do {
            uVar3 = uVar4 + uVar6 & 3;
            if ((local_24 == 1) &&
               ((((*(byte *)(local_18 + 0x70) & 2) == 0 ||
                 (uVar1 = **(uint **)(*(int *)(local_18 + 0x18) + *(int *)(local_20 + 0x48) * 4),
                 (uVar1 & 0xfff00000) != 0x50000000)) || (3 < (uVar1 & 0xfffff))))) {
              uVar3 = 3 - uVar3;
            }
            if ((local_4c[uVar3 + 4] == 0xffffffff) &&
               (iVar2 = FUN_009190ba(param_1,iVar5,param_3,uVar3), iVar2 == -1)) {
              local_4c[uVar3 + 4] = uVar6;
              local_4c[uVar6] = uVar3;
              break;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < local_c);
        }
        if (local_c == uVar4) {
          return 0xffffffff;
        }
        if ((((*(byte *)(param_1 + 0x60) & 1) == 0) || (uVar3 = param_4, 1 < local_24)) &&
           (param_4 = param_4 + uVar4 * 0x1000000, uVar3 = param_4, param_6 <= param_4)) {
          return param_4;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 4);
    if (param_5 != (uint *)0x0) {
      *param_5 = local_4c[0];
      param_5[1] = local_4c[1];
      param_5[2] = local_4c[2];
      param_5[3] = local_4c[3];
    }
  }
  return uVar3;
}


// ==== FUN_0091942e @ 0x0091942e ====

void FUN_0091942e(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  do {
    iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2 * 4) + 0x38);
    if (iVar2 != -1) {
      param_2 = iVar2;
    }
    iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + param_2 * 4);
    if (*(int *)(iVar2 + 4) == *param_1) {
      iVar3 = *(int *)(iVar2 + 0x74);
      if (param_1[0x16] != 0) {
        iVar5 = iVar3 * 4;
        iVar5 = *(int *)(param_1[0x14] + iVar5) + *(int *)(param_1[0x13] + iVar5);
        *(int *)(param_1[0x15] + iVar5 * 4) = iVar5;
        iVar5 = iVar5 * 0xc;
        *(int *)(iVar5 + param_1[0x16]) = param_3;
        uVar6 = **(uint **)(*(int *)(in_ECX + 0x18) + param_3 * 4) & 0xfff00000;
        if (((uVar6 == 0x20700000) || (uVar6 == 0x20800000)) || (uVar6 == 0x11500000)) {
          *(undefined4 *)(iVar5 + 4 + param_1[0x16]) = *(undefined4 *)(iVar2 + 0x14);
          *(undefined4 *)(iVar5 + 8 + param_1[0x16]) = *(undefined4 *)(iVar2 + 0x18);
        }
        else {
          *(undefined4 *)(iVar5 + 4 + param_1[0x16]) =
               *(undefined4 *)
                (*(int *)(*(int *)(in_ECX + 0x14) +
                         **(int **)(*(int *)(*(int *)(in_ECX + 0x18) + param_3 * 4) + 0x10) * 4) +
                0x14);
          *(undefined4 *)(iVar5 + 8 + param_1[0x16]) =
               *(undefined4 *)
                (*(int *)(*(int *)(in_ECX + 0x14) +
                         **(int **)(*(int *)(*(int *)(in_ECX + 0x18) + param_3 * 4) + 0x10) * 4) +
                0x18);
        }
        iVar8 = *(int *)(iVar5 + param_1[0x16] + 4);
        uVar4 = *(undefined4 *)(iVar5 + param_1[0x16] + 8);
        while( true ) {
          if (iVar8 == *(int *)(iVar2 + 0x14)) break;
          iVar7 = iVar8 * 4;
          if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                 *(int *)(*(int *)(iVar7 + *(int *)(in_ECX + 0x14)) + 4) * 4) + 5) &
              0x80) != 0) {
            *(int *)(iVar5 + 4 + param_1[0x16]) = iVar8;
            *(undefined4 *)(iVar5 + 8 + param_1[0x16]) = uVar4;
            *(undefined4 *)(iVar5 + param_1[0x16]) =
                 *(undefined4 *)(*(int *)(iVar7 + *(int *)(in_ECX + 0x14)) + 0x58);
            if (*(uint *)(iVar2 + 0x58) <
                *(uint *)(*(int *)(iVar7 + *(int *)(in_ECX + 0x14)) + 0x58)) {
              *(undefined4 *)(iVar2 + 0x58) =
                   *(undefined4 *)(*(int *)(iVar7 + *(int *)(in_ECX + 0x14)) + 0x58);
            }
          }
          iVar8 = *(int *)(iVar7 + *(int *)(in_ECX + 0x14));
          uVar4 = *(undefined4 *)(iVar8 + 0x18);
          iVar8 = *(int *)(iVar8 + 0x14);
        }
      }
      piVar1 = (int *)(param_1[0x13] + iVar3 * 4);
      *piVar1 = *piVar1 + 1;
    }
    param_2 = *(int *)(iVar2 + 8);
  } while (param_2 != -1);
  return;
}


// ==== FUN_009195b1 @ 0x009195b1 ====

void FUN_009195b1(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2 * 4) + 0x14);
  if (iVar1 != -1) {
    FUN_0091942e(param_1,iVar1,param_3);
  }
  return;
}


// ==== FUN_009195d7 @ 0x009195d7 ====

void FUN_009195d7(int param_1)

{
  _free(*(void **)(param_1 + 8));
  return;
}


// ==== FUN_00919678 @ 0x00919678 ====

undefined4 FUN_00919678(undefined4 *param_1,uint param_2,uint param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined4 local_24 [4];
  uint local_14;
  uint local_10;
  uint local_8;
  
  iVar4 = param_2;
  if (param_4 != 0) {
    uVar5 = 0;
    if (param_3 != 0) {
      do {
        *(uint *)(param_2 + uVar5 * 4) = uVar5;
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_3);
    }
    local_14 = 0;
    if (param_3 != 0) {
      do {
        piVar1 = (int *)(iVar4 + local_14 * 4);
        iVar3 = *piVar1;
        param_2 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1[iVar3] * 4) + 0x10);
        local_8 = local_14;
        local_14 = local_14 + 1;
        for (uVar5 = local_14; uVar5 < param_3; uVar5 = uVar5 + 1) {
          local_10 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                       param_1[*(int *)(iVar4 + uVar5 * 4)] * 4) + 0x10);
          if ((local_10 < param_2) || ((local_10 == param_2 && (uVar5 < local_8)))) {
            local_8 = uVar5;
            param_2 = local_10;
          }
        }
        piVar2 = (int *)(iVar4 + local_8 * 4);
        *piVar1 = *piVar2;
        *piVar2 = iVar3;
      } while (local_14 < param_3);
    }
  }
  uVar5 = 0;
  if (param_3 != 0) {
    do {
      local_24[uVar5] = param_1[*(int *)(iVar4 + uVar5 * 4)];
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_3);
    if (param_3 != 0) {
      puVar6 = local_24;
      for (; param_3 != 0; param_3 = param_3 - 1) {
        *param_1 = *puVar6;
        puVar6 = puVar6 + 1;
        param_1 = param_1 + 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00919759 @ 0x00919759 ====

void FUN_00919759(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  while( true ) {
    iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
    if (*(int *)(iVar2 + 0x38) != -1) {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar2 + 0x38) * 4);
    }
    iVar1 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + 4) * 4);
    if (param_2 < *(uint *)(iVar2 + 0x54)) {
      *(uint *)(iVar2 + 0x54) = param_2;
    }
    if (*(uint *)(iVar2 + 0x58) < param_2) {
      *(uint *)(iVar2 + 0x58) = param_2;
    }
    *(int *)(iVar2 + 0x5c) = *(int *)(iVar2 + 0x5c) + 1;
    if (*(int *)(iVar2 + 8) == -1) break;
    if (param_2 < *(uint *)(iVar1 + 0x28)) {
      *(uint *)(iVar1 + 0x28) = param_2;
    }
    if (*(uint *)(iVar1 + 0x2c) < param_2) {
      *(uint *)(iVar1 + 0x2c) = param_2;
    }
    *(int *)(iVar1 + 0x30) = *(int *)(iVar1 + 0x30) + 1;
    param_1 = *(int *)(iVar2 + 8);
  }
  return;
}


// ==== FUN_009197b7 @ 0x009197b7 ====

void FUN_009197b7(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
  iVar3 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + 4) * 4);
  *(undefined4 *)(iVar2 + 0x48) = param_2;
  iVar3 = *(int *)(iVar3 + 0x20);
  if (iVar3 != 0) {
    piVar1 = (int *)(iVar3 + (*(int *)(iVar2 + 0x10) + *(int *)(iVar2 + 0xc) * 4) * 4);
    if (*piVar1 != -1) {
      *(int *)(iVar2 + 0x4c) = *piVar1;
      *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4) + 0x50) = param_1;
    }
    *piVar1 = param_1;
  }
  if (*(int *)(iVar2 + 0x14) != -1) {
    FUN_00919759(*(int *)(iVar2 + 0x14),param_2);
  }
  return;
}


// ==== FUN_00919819 @ 0x00919819 ====

undefined4 FUN_00919819(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  bVar3 = false;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4);
      if (*(int *)(iVar1 + 0x38) != -1) {
        iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar1 + 0x38) * 4);
        *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar2 + 4);
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 8);
        *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
        *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
        *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(iVar2 + 0x48);
        *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)(iVar2 + 0x4c);
        *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar2 + 0x50);
        uVar5 = *(uint *)(iVar2 + 0x54);
        if (uVar5 == 0xffffffff) {
          *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(iVar1 + 0x54);
          *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(iVar1 + 0x58);
          *(undefined4 *)(iVar2 + 0x5c) = *(undefined4 *)(iVar1 + 0x5c);
        }
        else {
          if (*(uint *)(iVar1 + 0x54) <= uVar5) {
            uVar5 = *(uint *)(iVar1 + 0x54);
          }
          *(uint *)(iVar1 + 0x54) = uVar5;
          *(uint *)(iVar2 + 0x54) = uVar5;
          uVar5 = *(uint *)(iVar2 + 0x58);
          if (*(uint *)(iVar2 + 0x58) <= *(uint *)(iVar1 + 0x58)) {
            uVar5 = *(uint *)(iVar1 + 0x58);
          }
          *(uint *)(iVar1 + 0x58) = uVar5;
          *(uint *)(iVar2 + 0x58) = uVar5;
          *(int *)(iVar2 + 0x5c) = *(int *)(iVar2 + 0x5c) + *(int *)(iVar1 + 0x5c);
        }
        bVar3 = true;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 8));
    if ((bVar3) && (uVar4 = 0, *(int *)(in_ECX + 8) != 0)) {
      do {
        iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4);
        iVar2 = *(int *)(iVar1 + 0x38);
        if (iVar2 != -1) {
          *(undefined4 *)(iVar1 + 0x54) =
               *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4) + 0x54);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 8));
    }
  }
  return 0;
}


// ==== FUN_009198e4 @ 0x009198e4 ====

undefined4 FUN_009198e4(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *local_10;
  uint local_c;
  uint local_8;
  
  uVar5 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    do {
      iVar8 = *(int *)(*(int *)(in_ECX + 0x10) + uVar5 * 4);
      *(undefined4 *)(iVar8 + 0x28) = 0xffffffff;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(iVar8 + 0x2c) = 0;
      *(undefined4 *)(iVar8 + 0x30) = 0;
      *(undefined4 *)(iVar8 + 0x20) = 0;
    } while (uVar5 < *(uint *)(in_ECX + 4));
  }
  uVar5 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + uVar5 * 4);
      *(uint *)(iVar8 + 0x34) = uVar5;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(iVar8 + 0x54) = 0xffffffff;
      *(undefined4 *)(iVar8 + 0x58) = 0;
      *(undefined4 *)(iVar8 + 0x5c) = 0;
      *(undefined4 *)(iVar8 + 0x48) = 0xffffffff;
      *(undefined4 *)(iVar8 + 0x4c) = 0xffffffff;
      *(undefined4 *)(iVar8 + 0x50) = 0xffffffff;
    } while (uVar5 < *(uint *)(in_ECX + 8));
  }
  local_10 = (undefined4 *)0x0;
  if (*(int *)(in_ECX + 0xdc) != 0) {
    uVar5 = 0;
    if (*(int *)(in_ECX + 4) != 0) {
      do {
        iVar8 = uVar5 * 4;
        uVar5 = uVar5 + 1;
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10) + iVar8) + 0x10) = 0;
      } while (uVar5 < *(uint *)(in_ECX + 4));
    }
    uVar5 = 0;
    if (*(int *)(in_ECX + 8) != 0) {
      do {
        iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + uVar5 * 4);
        iVar4 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar8 + 4) * 4);
        if ((((*(uint *)(iVar4 + 4) & 0x40) == 0) && ((*(uint *)(iVar4 + 4) & 2) != 0)) &&
           (uVar6 = *(int *)(iVar8 + 0xc) + 1, *(uint *)(iVar4 + 0x10) < uVar6)) {
          *(uint *)(iVar4 + 0x10) = uVar6;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(in_ECX + 8));
    }
    iVar8 = *(int *)(in_ECX + 4);
    uVar5 = 0;
    if (iVar8 != 0) {
      piVar7 = *(int **)(in_ECX + 0x10);
      do {
        uVar5 = uVar5 + *(int *)(*piVar7 + 0x10);
        piVar7 = piVar7 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    local_10 = operator_new(uVar5 << 4);
    if (local_10 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    puVar9 = local_10;
    for (iVar8 = (uVar5 & 0xfffffff) << 2; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = 0xffffffff;
      puVar9 = puVar9 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined1 *)puVar9 = 0xff;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    iVar8 = 0;
    uVar5 = 0;
    if (*(int *)(in_ECX + 4) != 0) {
      iVar4 = *(int *)(in_ECX + 0x10);
      do {
        *(uint *)(*(int *)(iVar4 + uVar5 * 4) + 0x20) =
             -(uint)(*(int *)(*(int *)(*(int *)(in_ECX + 0x10) + uVar5 * 4) + 0x10) != 0) &
             (uint)(local_10 + iVar8 * 4);
        iVar4 = *(int *)(in_ECX + 0x10);
        iVar8 = iVar8 + *(int *)(*(int *)(iVar4 + uVar5 * 4) + 0x10);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(in_ECX + 4));
    }
  }
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      uVar5 = 0;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
      if ((puVar1 != (uint *)0x0) && ((*puVar1 & 0xfff00000) != 0)) {
        if (puVar1[1] != 0) {
          do {
            FUN_00919759(*(undefined4 *)(puVar1[2] + uVar5 * 4),local_8);
            uVar5 = uVar5 + 1;
          } while (uVar5 < puVar1[1]);
        }
        uVar5 = 0;
        if (puVar1[3] != 0) {
          do {
            FUN_009197b7(*(undefined4 *)(puVar1[4] + uVar5 * 4),local_8);
            uVar5 = uVar5 + 1;
          } while (uVar5 < puVar1[3]);
        }
        if ((((*puVar1 & 0xfff00000) == 0x10000000) && ((*(byte *)(in_ECX + 0xcc) & 4) == 0)) &&
           (local_c = 0, puVar1[3] != 0)) {
          do {
            iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(local_c * 4 + puVar1[4]) * 4);
            iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(local_c * 4 + puVar1[2]) * 4);
            uVar5 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar8 + 4) * 4) + 4);
            if ((((uVar5 & 0x1020) == 0) && ((uVar5 & 1) != 0)) && (*(int *)(iVar4 + 0x3c) == 0)) {
              uVar2 = *(undefined4 *)(iVar8 + 0x34);
              *(undefined4 *)(iVar8 + 0x34) = *(undefined4 *)(iVar4 + 0x34);
              *(undefined4 *)(iVar4 + 0x34) = uVar2;
            }
            local_c = local_c + 1;
          } while (local_c < puVar1[3]);
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0xc));
  }
  uVar5 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + uVar5 * 4);
      iVar4 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar8 + 4) * 4);
      uVar6 = *(uint *)(iVar4 + 0x28);
      if (uVar6 < *(uint *)(iVar8 + 0x54)) {
        *(uint *)(iVar8 + 0x54) = uVar6;
      }
      uVar6 = *(uint *)(iVar4 + 0x2c);
      if (*(uint *)(iVar8 + 0x58) < uVar6) {
        *(uint *)(iVar8 + 0x58) = uVar6;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 8));
  }
  if ((*(int *)(in_ECX + 0xdc) != 0) && (uVar5 = 0, *(int *)(in_ECX + 8) != 0)) {
    do {
      iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + uVar5 * 4);
      if (*(int *)(iVar8 + 0x4c) == -1) {
        *(undefined4 *)(iVar8 + 0x4c) = 0;
      }
      else {
        iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar8 + 0x4c) * 4);
        uVar6 = *(uint *)(iVar4 + 0x58);
        *(uint *)(iVar8 + 0x4c) = uVar6;
        uVar3 = *(uint *)(iVar4 + 0x48);
        if (uVar6 <= uVar3) {
          *(uint *)(iVar8 + 0x4c) = uVar3 + 1;
        }
      }
      if (*(int *)(iVar8 + 0x50) == -1) {
        *(undefined4 *)(iVar8 + 0x50) = 0xffffffff;
      }
      else {
        iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar8 + 0x50) * 4);
        uVar6 = *(uint *)(iVar4 + 0x54);
        *(uint *)(iVar8 + 0x50) = uVar6;
        uVar3 = *(uint *)(iVar4 + 0x48);
        if (uVar3 < uVar6) {
          *(uint *)(iVar8 + 0x50) = uVar3;
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 8));
  }
  if (*(int *)(in_ECX + 0xd8) != 0) {
    FUN_00919819();
  }
  _free(local_10);
  return extraout_EAX;
}


// ==== FUN_00919bb1 @ 0x00919bb1 ====

void FUN_00919bb1(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  while( true ) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + param_2 * 4);
    iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
    if ((param_3 != 0) &&
       ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + 4) * 4) + 4) & 2) != 0)) {
      if (*(int *)(iVar1 + 0x18) != 0) {
        *(undefined4 *)(*(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x14) * 4) =
             *(undefined4 *)(iVar2 + 0x48);
      }
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
      iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + *(int *)(iVar2 + 0x48) * 4);
      if (*(int *)(iVar1 + 0x20) != 0) {
        *(int *)(*(int *)(iVar1 + 0x20) + *(int *)(iVar1 + 0x1c) * 4) = param_2;
      }
      *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
    }
    if (*(int *)(iVar2 + 8) != -1) {
      FUN_00919bb1(*(int *)(iVar2 + 8),param_2,1);
    }
    param_1 = *(int *)(iVar2 + 0x14);
    if (param_1 == -1) break;
    param_3 = 1;
  }
  return;
}


// ==== FUN_00919c3e @ 0x00919c3e ====

undefined4 FUN_00919c3e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint local_c;
  uint local_8;
  
  FUN_009198e4();
  uVar4 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + uVar4 * 4);
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar1 + 0x18) = 0;
      *(undefined4 *)(iVar1 + 0x20) = 0;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    } while (uVar4 < *(uint *)(in_ECX + 0xc));
  }
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + local_8 * 4);
      if ((*(ushort *)(iVar1 + 2) & 0xfff0) != 0) {
        uVar4 = 0;
        if (*(int *)(iVar1 + 0xc) != 0) {
          do {
            FUN_00919bb1(*(undefined4 *)(*(int *)(iVar1 + 0x10) + uVar4 * 4),local_8,0);
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(iVar1 + 0xc));
        }
        uVar4 = 0;
        if (*(int *)(iVar1 + 4) != 0) {
          do {
            iVar3 = *(int *)(*(int *)(iVar1 + 8) + uVar4 * 4);
            if ((iVar3 != -1) &&
               (iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4) + 0x38), iVar2 != -1)
               ) {
              iVar3 = iVar2;
            }
            FUN_00919bb1(iVar3,local_8,1);
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(iVar1 + 4));
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0xc));
  }
  uVar4 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + uVar4 * 4);
      if (*(int *)(iVar1 + 0x14) != 0) {
        iVar3 = FUN_009149da(*(int *)(iVar1 + 0x14));
        *(int *)(iVar1 + 0x18) = iVar3;
        if (iVar3 == 0) {
          return 0x8007000e;
        }
      }
      if (*(int *)(iVar1 + 0x1c) != 0) {
        iVar3 = FUN_009149da(*(int *)(iVar1 + 0x1c));
        *(int *)(iVar1 + 0x20) = iVar3;
        if (iVar3 == 0) {
          return 0x8007000e;
        }
      }
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    } while (uVar4 < *(uint *)(in_ECX + 0xc));
  }
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + local_8 * 4);
      if ((*(ushort *)(iVar1 + 2) & 0xfff0) != 0) {
        uVar4 = 0;
        if (*(int *)(iVar1 + 0xc) != 0) {
          do {
            FUN_00919bb1(*(undefined4 *)(*(int *)(iVar1 + 0x10) + uVar4 * 4),local_8,0);
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(iVar1 + 0xc));
        }
        uVar4 = 0;
        if (*(int *)(iVar1 + 4) != 0) {
          do {
            iVar3 = *(int *)(*(int *)(iVar1 + 8) + uVar4 * 4);
            if ((iVar3 != -1) &&
               (iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4) + 0x38), iVar2 != -1)
               ) {
              iVar3 = iVar2;
            }
            FUN_00919bb1(iVar3,local_8,1);
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(iVar1 + 4));
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0xc));
  }
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + local_c * 4);
      if (*(int *)(iVar1 + 0x14) != 0) {
        FUN_00915b0e(FUN_009157b4,*(undefined4 *)(iVar1 + 0x18),*(int *)(iVar1 + 0x14),0);
        local_8 = 1;
        uVar4 = 1;
        if (1 < *(uint *)(iVar1 + 0x14)) {
          do {
            iVar3 = *(int *)(iVar1 + 0x18);
            iVar2 = *(int *)(iVar3 + uVar4 * 4);
            if (iVar2 != *(int *)(iVar3 + -4 + uVar4 * 4)) {
              *(int *)(iVar3 + local_8 * 4) = iVar2;
              local_8 = local_8 + 1;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(iVar1 + 0x14));
        }
        *(uint *)(iVar1 + 0x14) = local_8;
      }
      if (*(int *)(iVar1 + 0x1c) != 0) {
        FUN_00915b0e(FUN_009157b4,*(undefined4 *)(iVar1 + 0x20),*(int *)(iVar1 + 0x1c),0);
        local_8 = 1;
        uVar4 = 1;
        if (1 < *(uint *)(iVar1 + 0x1c)) {
          do {
            iVar3 = *(int *)(iVar1 + 0x20);
            iVar2 = *(int *)(iVar3 + uVar4 * 4);
            if (iVar2 != *(int *)(iVar3 + -4 + uVar4 * 4)) {
              *(int *)(iVar3 + local_8 * 4) = iVar2;
              local_8 = local_8 + 1;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(iVar1 + 0x1c));
        }
        *(uint *)(iVar1 + 0x1c) = local_8;
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  return 0;
}


// ==== FUN_00919e76 @ 0x00919e76 ====

undefined4 FUN_00919e76(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar1 * 4) + 0x30) = uVar1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(in_ECX + 8));
  }
  return 0;
}


// ==== FUN_00919e8f @ 0x00919e8f ====

undefined4 FUN_00919e8f(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint local_8;
  
  uVar6 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
      if (*(int *)(iVar2 + 8) == -1) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar2 + 8) * 4) + 0x30);
      }
      *(undefined4 *)(iVar2 + 8) = uVar4;
      if (*(int *)(iVar2 + 0x14) == -1) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = *(undefined4 *)
                 (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar2 + 0x14) * 4) + 0x30);
      }
      *(undefined4 *)(iVar2 + 0x14) = uVar4;
      if (*(int *)(iVar2 + 0x38) == -1) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = *(undefined4 *)
                 (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar2 + 0x38) * 4) + 0x30);
      }
      uVar6 = uVar6 + 1;
      *(undefined4 *)(iVar2 + 0x38) = uVar4;
    } while (uVar6 < *(uint *)(in_ECX + 8));
  }
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      piVar3 = *(int **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
      uVar6 = 0;
      if (*piVar3 != 0) {
        if (piVar3[1] != 0) {
          do {
            iVar5 = -1;
            piVar1 = (int *)(piVar3[2] + uVar6 * 4);
            iVar2 = *piVar1;
            if (iVar2 != -1) {
              iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4) + 0x30);
            }
            uVar6 = uVar6 + 1;
            *piVar1 = iVar5;
          } while (uVar6 < (uint)piVar3[1]);
        }
        uVar6 = 0;
        if (piVar3[3] != 0) {
          do {
            iVar5 = -1;
            piVar1 = (int *)(piVar3[4] + uVar6 * 4);
            iVar2 = *piVar1;
            if (iVar2 != -1) {
              iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4) + 0x30);
            }
            uVar6 = uVar6 + 1;
            *piVar1 = iVar5;
          } while (uVar6 < (uint)piVar3[3]);
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0xc));
  }
  return 0;
}


// ==== FUN_00919f6f @ 0x00919f6f ====

void FUN_00919f6f(int param_1,char *param_2,size_t param_3)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  int in_ECX;
  undefined **_Format;
  
  piVar1 = (int *)(param_1 + 4);
  if (*(int *)(param_1 + 0x38) != -1) {
    param_1 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(param_1 + 0x38) * 4);
  }
  pcVar2 = (char *)**(undefined4 **)(*(int *)(in_ECX + 0x10) + *piVar1 * 4);
  if ((*pcVar2 == '\0') || (pcVar2[1] != '\0')) {
    _Format = &PTR_LAB_00a295a8;
  }
  else {
    _Format = (undefined **)&DAT_009d5e14;
  }
  iVar3 = __snprintf(param_2,param_3,(char *)_Format,pcVar2);
  if (*(int *)(param_1 + 0xc) == -1) {
    __snprintf(param_2 + iVar3,param_3 - iVar3,&DAT_009fe048);
  }
  else {
    __snprintf(param_2 + iVar3,param_3 - iVar3,&DAT_00a16908,*(int *)(param_1 + 0xc));
  }
  param_2[param_3 - 1] = '\0';
  return;
}


// ==== FUN_0091a001 @ 0x0091a001 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0091a001(int param_1,int param_2,undefined4 param_3,char *param_4,char param_5)

{
  int iVar1;
  int iVar2;
  char local_108 [255];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  __vsnprintf(local_108,0x100,param_4,&param_5);
  iVar2 = 0;
  local_9 = 0;
  if (param_2 != 0) {
    iVar1 = *(int *)(param_2 + 4);
    if (iVar1 == 3) {
      iVar2 = param_2 + 0x10;
    }
    else if (iVar1 == 6) {
      iVar2 = *(int *)(param_2 + 0x14) + 0x10;
    }
    else if (iVar1 == 0xd) {
      iVar2 = param_2 + 0x30;
    }
  }
  FUN_008bd320(*(undefined4 *)(param_1 + 0xc4),iVar2,param_3,&DAT_009d5e14,local_108);
  *(undefined4 *)(param_1 + 0xd4) = 1;
  return 0;
}


// ==== FUN_0091a096 @ 0x0091a096 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0091a096(int param_1,int param_2,undefined4 param_3,char *param_4,char param_5)

{
  int iVar1;
  int iVar2;
  char local_108 [255];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  __vsnprintf(local_108,0x100,param_4,&param_5);
  iVar2 = 0;
  local_9 = 0;
  if (param_2 != 0) {
    iVar1 = *(int *)(param_2 + 4);
    if (iVar1 == 3) {
      iVar2 = param_2 + 0x10;
    }
    else if (iVar1 == 6) {
      iVar2 = *(int *)(param_2 + 0x14) + 0x10;
    }
    else if (iVar1 == 0xd) {
      iVar2 = param_2 + 0x30;
    }
  }
  FUN_008bd3f7(*(undefined4 *)(param_1 + 0xc4),iVar2,param_3,&DAT_009d5e14,local_108);
  return 0;
}


// ==== FUN_0091a11f @ 0x0091a11f ====

undefined4 FUN_0091a11f(int *param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int in_ECX;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_c;
  int *local_8;
  
  iVar5 = param_2;
  puVar1 = *(uint **)(*(int *)(param_2 + 0x18) + in_ECX * 4);
  puVar2 = *(uint **)(*(int *)(param_2 + 0x18) + (int)param_1 * 4);
  if (*puVar1 < *puVar2) {
LAB_0091a271:
    return 0xffffffff;
  }
  if (*puVar2 < *puVar1) {
    return 1;
  }
  local_8 = (int *)0x0;
  if (puVar1[3] != 0) {
    param_1 = (int *)puVar2[4];
    iVar7 = puVar1[4] - (int)param_1;
    do {
      iVar3 = *(int *)(*(int *)(param_2 + 0x14) + *(int *)(iVar7 + (int)param_1) * 4);
      iVar4 = *(int *)(*(int *)(param_2 + 0x14) + *param_1 * 4);
      if (*(uint *)(iVar3 + 4) < *(uint *)(iVar4 + 4)) goto LAB_0091a271;
      if (*(uint *)(iVar4 + 4) < *(uint *)(iVar3 + 4)) {
        return 1;
      }
      if (*(uint *)(iVar3 + 0x14) < *(uint *)(iVar4 + 0x14)) {
        return 0xffffffff;
      }
      if (*(uint *)(iVar4 + 0x14) < *(uint *)(iVar3 + 0x14)) {
        return 1;
      }
      if (*(int *)(iVar3 + 0x18) < *(int *)(iVar4 + 0x18)) {
        return 0xffffffff;
      }
      if (*(int *)(iVar4 + 0x18) < *(int *)(iVar3 + 0x18)) {
        return 1;
      }
      local_8 = (int *)((int)local_8 + 1);
      param_1 = param_1 + 1;
    } while (local_8 < puVar1[3]);
  }
  iVar7 = FUN_0091464c();
  if (iVar7 == 0) {
    param_2 = 0;
    if (puVar1[1] != 0) {
      piVar8 = (int *)puVar2[2];
      iVar7 = puVar1[2] - (int)piVar8;
      do {
        uVar9 = *(uint *)(*(int *)(*(int *)(iVar5 + 0x14) + *(int *)(iVar7 + (int)piVar8) * 4) +
                         0x30);
        uVar11 = *(uint *)(*(int *)(*(int *)(iVar5 + 0x14) + *piVar8 * 4) + 0x30);
        if (uVar9 < uVar11) {
          return 0xffffffff;
        }
        if (uVar11 < uVar9) {
          return 1;
        }
        param_2 = param_2 + 1;
        piVar8 = piVar8 + 1;
      } while (param_2 < puVar1[1]);
    }
  }
  else {
    uVar9 = *puVar1 & 0xfffff;
    local_c = 0;
    if (uVar9 != 0) {
      local_8 = (int *)puVar2[2];
      iVar5 = *(int *)(param_2 + 0x14);
      piVar8 = local_8 + uVar9;
      iVar7 = puVar1[2] - (int)local_8;
      do {
        param_1 = *(int **)(*(int *)(iVar5 + *(int *)(iVar7 + (int)local_8) * 4) + 0x30);
        uVar11 = *(uint *)(*(int *)(iVar5 + *local_8 * 4) + 0x30);
        uVar10 = *(uint *)(*(int *)(iVar5 + *(int *)(iVar7 + (int)piVar8) * 4) + 0x30);
        uVar6 = *(uint *)(*(int *)(iVar5 + *piVar8 * 4) + 0x30);
        param_2 = (uint)param_1;
        if (param_1 < uVar10) {
LAB_0091a23a:
          param_1 = (int *)uVar10;
        }
        else {
          param_2 = uVar10;
          if (param_1 <= uVar10) goto LAB_0091a23a;
        }
        uVar10 = uVar11;
        if (uVar11 < uVar6) {
LAB_0091a24d:
          uVar11 = uVar6;
        }
        else {
          uVar10 = uVar6;
          if (uVar11 <= uVar6) goto LAB_0091a24d;
        }
        if (param_2 < uVar10) {
          return 0xffffffff;
        }
        if (uVar10 < param_2) {
          return 1;
        }
        if (param_1 < uVar11) {
          return 0xffffffff;
        }
        if (uVar11 < param_1) {
          return 1;
        }
        local_c = local_c + 1;
        local_8 = local_8 + 1;
        piVar8 = piVar8 + 1;
      } while (local_c < uVar9);
    }
  }
  return 0;
}


// ==== FUN_0091a2be @ 0x0091a2be ====

uint FUN_0091a2be(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = FUN_0091a11f(param_2,param_3);
  if (uVar1 == 0) {
    if (param_1 < param_2) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (uint)(param_2 < param_1);
    }
  }
  return uVar1;
}


// ==== FUN_0091a2ea @ 0x0091a2ea ====

void FUN_0091a2ea(byte param_1)

{
  void *in_ECX;
  
  FUN_00915ccb();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0091a30b @ 0x0091a30b ====

int FUN_0091a30b(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  
  if (param_2 == 0) {
    iVar1 = -0x7fffbffb;
  }
  else {
    in_ECX[0x31] = param_2;
    in_ECX[0x32] = param_3;
    in_ECX[0x35] = 0;
    in_ECX[0x36] = 0;
    in_ECX[0x37] = 0;
    in_ECX[0x30] = param_1;
    in_ECX[0x33] = param_4;
    iVar1 = FUN_009152bf(&DAT_00a1fd24,0,0xffffffff,4);
    in_ECX[0x1d] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a1fc7c,0x311,0xffffffff,4);
    in_ECX[0x1e] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a1fc10,0x251,0xffffffff,4);
    in_ECX[0x1f] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a277f4,0x51,0xffffffff,4);
    in_ECX[0x20] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a277a8,0x62,0xffffffff,4);
    in_ECX[0x21] = iVar1;
    iVar1 = FUN_009152bf(&DAT_009fd7f8,3,0xffffffff,4);
    in_ECX[0x22] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a1fd08,6,0xffffffff,4);
    in_ECX[0x23] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a277ac,10,0xffffffff,4);
    in_ECX[0x24] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a1fc84,0x2d1,0xffffffff,4);
    in_ECX[0x25] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a1fc44,0x1003,0xffffffff,4);
    in_ECX[0x26] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a1fc10,0x2251,0xffffffff,4);
    in_ECX[0x27] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a277ac,0x400a,0xffffffff,4);
    in_ECX[0x28] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a295b4,0xc00a,0xffffffff,4);
    in_ECX[0x29] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a295b0,0x10042,0,4);
    in_ECX[0x2a] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a1fd1c,0x20003,0xffffffff,4);
    in_ECX[0x2b] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a1fc44,0x40211,0xffffffff,4);
    in_ECX[0x2c] = iVar1;
    iVar1 = FUN_009152bf(&DAT_009fdf9c,0x2062,0xffffffff,4);
    in_ECX[0x2d] = iVar1;
    iVar1 = FUN_009152bf(&DAT_00a295ac,0x40062,0xffffffff,4);
    in_ECX[0x2e] = iVar1;
    if (in_ECX[1] == 0x12) {
      piVar2 = in_ECX + 10;
      for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar2 = 0;
        piVar2 = piVar2 + 1;
      }
      iVar1 = (**(code **)(*in_ECX + 0xc))();
      if ((-1 < iVar1) && (iVar1 = FUN_00915cfa(0), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = -0x7ff8fff2;
    }
  }
  return iVar1;
}


// ==== FUN_0091a540 @ 0x0091a540 ====

int FUN_0091a540(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  
  iVar1 = FUN_0091557c(param_1);
  if (-1 < iVar1) {
    in_ECX[0x30] = *(int *)(param_1 + 0xc0);
    iVar1 = *(int *)(param_1 + 0xc4);
    in_ECX[0x35] = 0;
    in_ECX[0x36] = 0;
    in_ECX[0x37] = 0;
    in_ECX[0x31] = iVar1;
    in_ECX[0x32] = param_2;
    in_ECX[0x33] = param_3;
    in_ECX[0x1d] = *(int *)(param_1 + 0x74);
    in_ECX[0x1e] = *(int *)(param_1 + 0x78);
    in_ECX[0x1f] = *(int *)(param_1 + 0x7c);
    in_ECX[0x20] = *(int *)(param_1 + 0x80);
    in_ECX[0x21] = *(int *)(param_1 + 0x84);
    in_ECX[0x22] = *(int *)(param_1 + 0x88);
    in_ECX[0x23] = *(int *)(param_1 + 0x8c);
    in_ECX[0x24] = *(int *)(param_1 + 0x90);
    in_ECX[0x25] = *(int *)(param_1 + 0x94);
    in_ECX[0x26] = *(int *)(param_1 + 0x98);
    in_ECX[0x27] = *(int *)(param_1 + 0x9c);
    in_ECX[0x28] = *(int *)(param_1 + 0xa0);
    in_ECX[0x29] = *(int *)(param_1 + 0xa4);
    in_ECX[0x2a] = *(int *)(param_1 + 0xa8);
    in_ECX[0x2b] = *(int *)(param_1 + 0xac);
    in_ECX[0x2c] = *(int *)(param_1 + 0xb0);
    in_ECX[0x2d] = *(int *)(param_1 + 0xb4);
    in_ECX[0x2e] = *(int *)(param_1 + 0xb8);
    piVar2 = in_ECX + 10;
    for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
    iVar1 = (**(code **)(*in_ECX + 0xc))();
    if (-1 < iVar1) {
      iVar1 = FUN_00915cfa(0);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== FUN_0091a689 @ 0x0091a689 ====

undefined4 FUN_0091a689(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  uint local_8;
  
  uVar6 = 0;
  bVar4 = false;
  if (*(int *)(in_ECX + 4) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x10) + uVar6 * 4);
      uVar6 = uVar6 + 1;
      *(undefined4 *)(iVar2 + 0x28) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x24) = 0xffffffff;
    } while (uVar6 < *(uint *)(in_ECX + 4));
  }
  uVar6 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
      uVar6 = uVar6 + 1;
      *(undefined4 *)(iVar2 + 0x54) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x48) = 0xffffffff;
    } while (uVar6 < *(uint *)(in_ECX + 8));
  }
  uVar6 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + uVar6 * 4);
      if ((*(ushort *)(iVar2 + 2) & 0xfff0) != 0) {
        local_8 = 0;
        if (*(int *)(iVar2 + 4) != 0) {
          do {
            iVar5 = *(int *)(*(int *)(in_ECX + 0x14) +
                            *(int *)(*(int *)(iVar2 + 8) + local_8 * 4) * 4);
            if (uVar6 < *(uint *)(iVar5 + 0x54)) {
              *(uint *)(iVar5 + 0x54) = uVar6;
            }
            piVar1 = (int *)(iVar5 + 8);
            iVar7 = *piVar1;
            iVar3 = iVar5;
            while (iVar7 != -1) {
              iVar7 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4);
              if (uVar6 < *(uint *)(iVar7 + 0x28)) {
                *(uint *)(iVar7 + 0x28) = uVar6;
              }
              iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4);
              if (uVar6 < *(uint *)(iVar3 + 0x54)) {
                *(uint *)(iVar3 + 0x54) = uVar6;
              }
              piVar1 = (int *)(iVar3 + 8);
              iVar7 = *piVar1;
            }
            while (*(int *)(iVar5 + 0x14) != -1) {
              iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar5 + 0x14) * 4);
              if (uVar6 < *(uint *)(iVar5 + 0x54)) {
                *(uint *)(iVar5 + 0x54) = uVar6;
              }
            }
            local_8 = local_8 + 1;
          } while (local_8 < *(uint *)(iVar2 + 4));
        }
        local_8 = 0;
        if (*(int *)(iVar2 + 0xc) != 0) {
          do {
            iVar5 = *(int *)(*(int *)(in_ECX + 0x14) +
                            *(int *)(*(int *)(iVar2 + 0x10) + local_8 * 4) * 4);
            if (uVar6 < *(uint *)(iVar5 + 0x48)) {
              *(uint *)(iVar5 + 0x48) = uVar6;
            }
            iVar7 = iVar5;
            if (*(int *)(iVar5 + 8) != -1) {
              iVar7 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar5 + 4) * 4);
              if (uVar6 < *(uint *)(iVar7 + 0x24)) {
                *(uint *)(iVar7 + 0x24) = uVar6;
              }
              iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar5 + 8) * 4);
              if (uVar6 < *(uint *)(iVar7 + 0x54)) {
                *(uint *)(iVar7 + 0x54) = uVar6;
              }
            }
            if (*(int *)(iVar7 + 8) != -1) {
              do {
                iVar3 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4);
                if (uVar6 < *(uint *)(iVar3 + 0x28)) {
                  *(uint *)(iVar3 + 0x28) = uVar6;
                }
                iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar7 + 8) * 4);
                if (uVar6 < *(uint *)(iVar7 + 0x54)) {
                  *(uint *)(iVar7 + 0x54) = uVar6;
                }
              } while (*(int *)(iVar7 + 8) != -1);
            }
            while (*(int *)(iVar5 + 0x14) != -1) {
              iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar5 + 0x14) * 4);
              if (uVar6 < *(uint *)(iVar5 + 0x54)) {
                *(uint *)(iVar5 + 0x54) = uVar6;
              }
            }
            local_8 = local_8 + 1;
          } while (local_8 < *(uint *)(iVar2 + 0xc));
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(in_ECX + 0xc));
  }
  FUN_00919819();
  local_8 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + local_8 * 4);
      iVar5 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + 4) * 4);
      if (*(uint *)(iVar5 + 0x28) < *(uint *)(iVar2 + 0x54)) {
        *(uint *)(iVar2 + 0x54) = *(uint *)(iVar5 + 0x28);
      }
      if (*(uint *)(iVar5 + 0x24) < *(uint *)(iVar2 + 0x48)) {
        *(uint *)(iVar2 + 0x48) = *(uint *)(iVar5 + 0x24);
      }
      uVar6 = *(uint *)(iVar5 + 4);
      if ((((uVar6 & 0x10) == 0) && (*(uint *)(iVar2 + 0x54) != 0xffffffff)) &&
         (*(uint *)(iVar2 + 0x54) <= *(uint *)(iVar2 + 0x48))) {
        iVar2 = *(int *)(iVar2 + 0x60);
        if (((iVar2 == 0) || (*(int *)(iVar2 + 4) != 6)) ||
           ((*(int *)(iVar2 + 0x14) == 0 || (*(int *)(*(int *)(iVar2 + 0x14) + 4) != 3)))) {
LAB_0091a8fa:
          FUN_0091a001();
        }
        else if (*(int *)(iVar2 + 0x28) == 0) {
          FUN_0091a001();
          *(undefined4 *)(iVar2 + 0x28) = 1;
        }
LAB_0091a98b:
        bVar4 = true;
      }
      else {
        if (((uVar6 & 0x20) != 0) && (*(int *)(iVar2 + 0x48) == -1)) goto LAB_0091a980;
        if (((uVar6 & 2) == 0) && (*(int *)(iVar2 + 0x48) != -1)) goto LAB_0091a8fa;
        if (((uVar6 & 0xd) == 0) && (*(int *)(iVar2 + 0x54) != -1)) {
LAB_0091a980:
          FUN_0091a001();
          goto LAB_0091a98b;
        }
        if ((*(int *)(in_ECX + 0xd8) != 0) &&
           ((((uVar6 & 0x10120) == 0 && (*(int *)(iVar2 + 0x54) == -1)) &&
            (((uVar6 & 0x10) != 0 ||
             (((*(int *)(iVar2 + 0x48) != -1 && (iVar5 = FUN_009145ef(), iVar5 == 0)) &&
              ((**(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar2 + 0x48) * 4) & 0xfff00000) !=
               0x20900000)))))))) {
          if (*(int *)(iVar2 + 0x48) != -1) goto LAB_0091a8fa;
          goto LAB_0091a980;
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 8));
    if (bVar4) {
      return 0x80004005;
    }
  }
  return 0;
}


// ==== FUN_0091a9b4 @ 0x0091a9b4 ====

int FUN_0091a9b4(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int *piVar6;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar2 = *(int *)(in_ECX + 8);
  local_8 = 0;
  if (iVar2 != 0) {
    piVar6 = *(int **)(in_ECX + 0x14);
    do {
      uVar3 = *(uint *)(*piVar6 + 0xc);
      if ((local_8 < uVar3) && (uVar3 != 0xffffffff)) {
        local_8 = uVar3;
      }
      piVar6 = piVar6 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  local_8 = local_8 + 1;
  local_10 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + local_10 * 4);
      uVar3 = *(uint *)(iVar2 + 0xc);
      if (uVar3 != 0) {
        piVar6 = *(int **)(iVar2 + 0x10);
        local_14 = uVar3;
        do {
          iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar6 * 4);
          if ((*(int *)(iVar4 + 0x44) == -1) &&
             ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4) & 0x20) !=
              0)) {
            uVar3 = uVar3 - 1;
          }
          piVar6 = piVar6 + 1;
          local_14 = local_14 - 1;
        } while (local_14 != 0);
      }
      if (uVar3 != *(uint *)(iVar2 + 0xc)) {
        local_14 = 0;
        if (uVar3 != 0) {
          iVar4 = FUN_00915378(uVar3 & 0xfffff | 0x10000000,uVar3,uVar3);
          if (iVar4 == -1) {
            return -0x7ff8fff2;
          }
          local_14 = *(int *)(*(int *)(in_ECX + 0x18) + iVar4 * 4);
          FUN_00914593();
        }
        local_c = 0;
        if (*(int *)(iVar2 + 0xc) != 0) {
          local_18 = 0;
          do {
            iVar4 = *(int *)(*(int *)(in_ECX + 0x14) +
                            *(int *)(*(int *)(iVar2 + 0x10) + local_c * 4) * 4);
            iVar1 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4);
            uVar5 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),local_8,
                                 *(undefined4 *)(iVar4 + 0x10),0);
            if ((*(int *)(iVar4 + 0x44) != -1) || ((*(byte *)(iVar1 + 4) & 0x20) == 0)) {
              *(undefined4 *)(local_18 + *(int *)(local_14 + 0x10)) =
                   *(undefined4 *)(*(int *)(iVar2 + 0x10) + local_c * 4);
              *(undefined4 *)(local_18 + *(int *)(local_14 + 8)) = uVar5;
              local_18 = local_18 + 4;
            }
            *(undefined4 *)(*(int *)(iVar2 + 0x10) + local_c * 4) = uVar5;
            local_c = local_c + 1;
          } while (local_c < *(uint *)(iVar2 + 0xc));
        }
        local_8 = local_8 + 1;
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(uint *)(in_ECX + 0xc));
  }
  iVar2 = FUN_009198e4();
  if (-1 < iVar2) {
    uVar3 = 0;
    if (*(int *)(in_ECX + 8) != 0) {
      do {
        iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4);
        if ((*(int *)(iVar2 + 0x48) == -1) && (*(int *)(iVar2 + 0x54) == -1)) {
          *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(in_ECX + 0x74);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(in_ECX + 8));
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_0091ab4a @ 0x0091ab4a ====

void FUN_0091ab4a(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  uint uVar7;
  uint local_24;
  int *local_20;
  int *local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  uint local_c;
  uint local_8;
  
  uVar7 = 0;
  local_10 = (void *)0x0;
  FUN_009198e4();
  local_8 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4);
      if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4) & 0x20) == 0)
      {
        *(uint *)(iVar4 + 0x30) = uVar7;
      }
      else {
        iVar3 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,0,0);
        *(int *)(iVar4 + 0x30) = iVar3;
        if (iVar3 == -1) goto LAB_0091ac46;
        local_8 = local_8 + 1;
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4) + 0x14) =
             *(undefined4 *)(iVar4 + 0x14);
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar4 + 0x30) * 4) + 0x18) =
             *(undefined4 *)(iVar4 + 0x18);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(in_ECX + 8));
    if (local_8 != 0) {
      FUN_00919e8f();
      local_10 = operator_new(local_8 << 2);
      if (local_10 != (void *)0x0) {
        uVar7 = 0;
        local_8 = 0;
        if (*(int *)(in_ECX + 8) != 0) {
          do {
            if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                   *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4) + 4) * 4)
                          + 4) & 0x20) != 0) {
              *(uint *)((int)local_10 + local_8 * 4) = uVar7;
              local_8 = local_8 + 1;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < *(uint *)(in_ECX + 8));
        }
        FUN_00915b0e(FUN_00915726,local_10,local_8,in_ECX);
        local_18 = 0;
        if (local_8 != 0) {
          do {
            piVar5 = (int *)((int)local_10 + local_18 * 4);
            iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar5 * 4);
            local_14 = local_18 + 1;
            local_c = 1;
            if (local_14 < local_8) {
              local_1c = piVar5;
              do {
                local_1c = local_1c + 1;
                iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *local_1c * 4);
                if (((*(int *)(iVar4 + 4) != *(int *)(iVar3 + 4)) ||
                    (*(int *)(iVar4 + 8) != *(int *)(iVar3 + 8))) ||
                   (*(int *)(iVar4 + 0xc) != *(int *)(iVar3 + 0xc))) break;
                local_c = local_c + 1;
                local_14 = local_14 + 1;
              } while (local_14 < local_8);
            }
            iVar4 = FUN_00915378(local_c & 0xfffff | 0x10000000,0xffffffff,0xffffffff);
            if (iVar4 == -1) break;
            iVar4 = *(int *)(*(int *)(in_ECX + 0x18) + iVar4 * 4);
            local_24 = 0;
            if (local_c != 0) {
              local_20 = piVar5;
              do {
                iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *local_20 * 4);
                iVar1 = *(int *)(iVar3 + 0x30);
                iVar3 = *(int *)(iVar3 + 0x48);
                while (iVar3 != -1) {
                  puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar3 * 4);
                  if ((puVar2[0xf] != 0) && (iVar3 = FUN_00914593(), iVar3 < 0)) goto LAB_0091ac46;
                  if ((*puVar2 & 0xfff00000) != 0x10000000) break;
                  uVar7 = 0;
                  if (puVar2[3] != 0) {
                    piVar6 = (int *)puVar2[4];
                    do {
                      if (iVar1 == *piVar6) break;
                      uVar7 = uVar7 + 1;
                      piVar6 = piVar6 + 1;
                    } while (uVar7 < puVar2[3]);
                  }
                  iVar1 = *(int *)(puVar2[2] + uVar7 * 4);
                  iVar3 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar1 * 4) + 0x48);
                }
                if (*(int *)(iVar4 + 0x3c) != 0) break;
                local_24 = local_24 + 1;
                local_20 = local_20 + 1;
              } while (local_24 < local_c);
            }
            uVar7 = 0;
            if (local_c != 0) {
              do {
                *(undefined4 *)(*(int *)(iVar4 + 8) + uVar7 * 4) =
                     *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar5 * 4) + 0x30);
                *(int *)(*(int *)(iVar4 + 0x10) + uVar7 * 4) = *piVar5;
                uVar7 = uVar7 + 1;
                piVar5 = piVar5 + 1;
              } while (uVar7 < local_c);
            }
            local_18 = local_18 + local_c;
          } while (local_18 < local_8);
        }
      }
    }
  }
LAB_0091ac46:
  _free(local_10);
  return;
}


// ==== FUN_0091add2 @ 0x0091add2 ====

void FUN_0091add2(int param_1,uint param_2)

{
  int iVar1;
  int in_ECX;
  
  if (param_2 != 0) {
    do {
      if (param_1 != -1) {
        iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4) + 0x38);
        if (iVar1 != -1) {
          param_1 = iVar1;
        }
      }
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
      if (*(uint *)(iVar1 + 0x54) < param_2) {
        *(uint *)(iVar1 + 0x54) = param_2;
      }
      if (*(int *)(iVar1 + 8) != -1) {
        FUN_0091add2(*(int *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x54));
      }
      param_1 = *(int *)(iVar1 + 0x14);
    } while ((param_1 != -1) && (param_2 = *(uint *)(iVar1 + 0x54), param_2 != 0));
  }
  return;
}


// ==== FUN_0091ae30 @ 0x0091ae30 ====

bool FUN_0091ae30(void)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  bVar3 = false;
  FUN_009198e4();
  uVar6 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
      uVar6 = uVar6 + 1;
      *(uint *)(iVar8 + 0x54) =
           -(uint)((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar8 + 4) * 4) + 4) &
                   0x10020) != 0) & 2;
    } while (uVar6 < *(uint *)(in_ECX + 8));
  }
  iVar8 = *(int *)(in_ECX + 0xc);
  while (uVar6 = 0, iVar8 != 0) {
    iVar8 = iVar8 + -1;
    puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar8 * 4);
    if (((*puVar1 & 0xfff00000) == 0x20900000) && (puVar1[3] != 0)) {
      do {
        iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + uVar6 * 4) * 4);
        if (*(int *)(iVar9 + 0x54) != 2) {
          *(undefined4 *)(iVar9 + 0x54) = 1;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < puVar1[3]);
    }
  }
  do {
    local_10 = *(int *)(in_ECX + 0xc);
    bVar11 = false;
    if (local_10 == 0) break;
    do {
      local_10 = local_10 + -1;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_10 * 4);
      uVar6 = *puVar1;
      if ((uVar6 & 0xfff00000) != 0) {
        if (((uVar6 & 0xf0000000) < 0x10000000) || (0x40000000 < (uVar6 & 0xf0000000))) {
          uVar6 = puVar1[3];
          local_8 = 0;
          if (uVar6 != 0) {
            piVar5 = (int *)puVar1[4];
            local_1c = uVar6;
            do {
              uVar10 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar5 * 4) + 0x54);
              if (local_8 < uVar10) {
                local_8 = uVar10;
              }
              piVar5 = piVar5 + 1;
              local_1c = local_1c - 1;
            } while (local_1c != 0);
            if (local_8 == 1) {
              bVar11 = true;
            }
          }
          uVar10 = 0;
          if (uVar6 != 0) {
            do {
              FUN_0091add2(*(undefined4 *)(puVar1[4] + uVar10 * 4),local_8);
              uVar10 = uVar10 + 1;
            } while (uVar10 < puVar1[3]);
          }
          uVar6 = 0;
          if (puVar1[1] != 0) {
            do {
              FUN_0091add2(*(undefined4 *)(puVar1[2] + uVar6 * 4),local_8);
              uVar6 = uVar6 + 1;
            } while (uVar6 < puVar1[1]);
          }
        }
        else {
          uVar6 = puVar1[1] / (uVar6 & 0xfffff);
          local_8 = 0;
          if (puVar1[3] != 0) {
            do {
              iVar8 = *(int *)(puVar1[4] + local_8 * 4);
              iVar9 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar8 * 4) + 0x54);
              if (iVar9 == 1) {
                bVar11 = true;
              }
              FUN_0091add2(iVar8,iVar9);
              local_c = 0;
              if (uVar6 != 0) {
                do {
                  FUN_0091add2(*(undefined4 *)(puVar1[2] + (puVar1[3] * local_c + local_8) * 4),
                               iVar9);
                  local_c = local_c + 1;
                } while (local_c < uVar6);
              }
              local_8 = local_8 + 1;
            } while (local_8 < puVar1[3]);
          }
        }
      }
    } while (local_10 != 0);
    if (!bVar11) break;
    bVar11 = false;
    local_c = 0;
    if (*(int *)(in_ECX + 0xc) == 0) break;
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      if ((*puVar1 & 0xfff00000) == 0x20900000) {
        uVar6 = puVar1[3];
        local_8 = 0;
        if (uVar6 != 0) {
          do {
            iVar8 = *(int *)(in_ECX + 0x14);
            iVar9 = *(int *)(iVar8 + *(int *)(puVar1[4] + local_8 * 4) * 4);
            if (*(int *)(iVar9 + 0x54) == 1) {
              iVar7 = *(int *)(puVar1[2] + (uVar6 + local_8) * 4);
              if (iVar7 != -1) {
                iVar2 = *(int *)(*(int *)(iVar8 + iVar7 * 4) + 0x38);
                if (iVar2 != -1) {
                  iVar7 = iVar2;
                }
              }
              local_10 = 0;
              iVar2 = *(int *)(*(int *)(in_ECX + 0x18) +
                              *(int *)(*(int *)(iVar8 + iVar7 * 4) + 0x48) * 4);
              if (*(int *)(iVar2 + 0xc) != 0) {
                piVar5 = *(int **)(iVar2 + 0x10);
                do {
                  if (*piVar5 == iVar7) break;
                  local_10 = local_10 + 1;
                  piVar5 = piVar5 + 1;
                } while (local_10 < *(uint *)(iVar2 + 0xc));
              }
              iVar7 = *(int *)(*(int *)(iVar2 + 8) + local_10 * 4);
              if (iVar7 != -1) {
                iVar2 = *(int *)(*(int *)(iVar8 + iVar7 * 4) + 0x38);
                if (iVar2 != -1) {
                  iVar7 = iVar2;
                }
              }
              iVar8 = *(int *)(*(int *)(iVar8 + iVar7 * 4) + 0x54);
              if (iVar8 != 1) {
                *(int *)(iVar9 + 0x54) = iVar8;
                bVar11 = true;
              }
            }
            local_8 = local_8 + 1;
            uVar6 = puVar1[3];
          } while (local_8 < uVar6);
        }
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  } while (bVar11);
  local_14 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_14 * 4);
      uVar6 = *puVar1;
      if ((uVar6 & 0xfff00000) != 0) {
        if (((uVar6 & 0xf0000000) < 0x10000000) || (0x40000000 < (uVar6 & 0xf0000000))) {
          uVar6 = 0;
          bVar11 = puVar1[3] == 0;
          if (puVar1[3] != 0) {
            piVar5 = (int *)puVar1[4];
            do {
              if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar5 * 4) + 0x54) == 2) break;
              uVar6 = uVar6 + 1;
              piVar5 = piVar5 + 1;
            } while (uVar6 < puVar1[3]);
            bVar11 = uVar6 == puVar1[3];
          }
          if (bVar11) {
            uVar6 = 0;
            *puVar1 = 0;
            puVar1[3] = 0;
            goto LAB_0091b258;
          }
        }
        else {
          uVar6 = puVar1[1] / (uVar6 & 0xfffff);
          uVar10 = 0;
          bVar11 = puVar1[3] == 0;
          local_8 = 0;
          if (puVar1[3] != 0) {
            do {
              iVar8 = *(int *)(puVar1[4] + local_8 * 4);
              if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar8 * 4) + 0x54) == 2) {
                local_10 = 0;
                *(int *)(puVar1[4] + uVar10 * 4) = iVar8;
                if (uVar6 != 0) {
                  do {
                    iVar8 = puVar1[3] * local_10;
                    local_10 = local_10 + 1;
                    *(undefined4 *)(puVar1[2] + (iVar8 + uVar10) * 4) =
                         *(undefined4 *)(puVar1[2] + (local_8 + iVar8) * 4);
                  } while (local_10 < uVar6);
                }
                uVar10 = uVar10 + 1;
              }
              local_8 = local_8 + 1;
            } while (local_8 < puVar1[3]);
            bVar11 = uVar10 == puVar1[3];
          }
          if (!bVar11) {
            if (uVar10 == 0) {
              uVar4 = 0;
            }
            else {
              uVar4 = (*puVar1 ^ uVar10) & 0xfffff ^ *puVar1;
            }
            *puVar1 = uVar4;
            local_8 = 1;
            if (1 < uVar6) {
              local_18 = uVar10 << 2;
              do {
                local_10 = 0;
                if (uVar10 != 0) {
                  iVar8 = local_18;
                  do {
                    iVar9 = puVar1[3] * local_8 + local_10;
                    local_10 = local_10 + 1;
                    *(undefined4 *)(iVar8 + puVar1[2]) = *(undefined4 *)(puVar1[2] + iVar9 * 4);
                    iVar8 = iVar8 + 4;
                  } while (local_10 < uVar10);
                }
                local_8 = local_8 + 1;
                local_18 = local_18 + uVar10 * 4;
              } while (local_8 < uVar6);
            }
            uVar6 = uVar10 * uVar6;
            puVar1[3] = uVar10;
LAB_0091b258:
            puVar1[1] = uVar6;
            bVar3 = true;
          }
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < *(uint *)(in_ECX + 0xc));
  }
  uVar6 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
      if ((uVar6 == 0xffffffff) ||
         (uVar10 = *(uint *)(iVar8 + 0x38), *(uint *)(iVar8 + 0x38) == 0xffffffff)) {
        uVar10 = uVar6;
      }
      if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar10 * 4) + 0x54) != 2) {
        iVar9 = *(int *)(iVar8 + 4);
        if (((*(int *)(in_ECX + 0x74) != iVar9) &&
            ((*(int *)(iVar8 + 8) != -1 ||
             ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + iVar9 * 4) + 5) & 4) == 0)))) &&
           ((uVar10 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + iVar9 * 4) + 4),
            (uVar10 & 0x100) == 0 || ((uVar10 & 0x800) == 0)))) {
          *(int *)(iVar8 + 4) = *(int *)(in_ECX + 0x74);
          bVar3 = true;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(in_ECX + 8));
  }
  return !bVar3;
}


// ==== FUN_0091b2e2 @ 0x0091b2e2 ====

void FUN_0091b2e2(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  int *_Memory;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int in_ECX;
  uint *puVar11;
  uint uVar12;
  bool bVar13;
  uint local_50;
  uint local_3c;
  int *local_38;
  int *local_34;
  uint local_2c;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_8;
  
  _Memory = operator_new(*(int *)(in_ECX + 8) << 2);
  if (_Memory == (int *)0x0) {
LAB_0091b782:
    _free(_Memory);
    return;
  }
  do {
    bVar3 = false;
    local_14 = 0;
    FUN_009198e4();
    FUN_00919e76();
    local_8 = 0;
    if (*(int *)(in_ECX + 8) != 0) {
      do {
        iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + local_8 * 4);
        if ((((*(int *)(iVar10 + 8) == -1) && (*(int *)(iVar10 + 0x48) != -1)) &&
            (uVar4 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar10 + 4) * 4) + 4),
            (uVar4 & 2) != 0)) && ((uVar4 & 0x20) == 0)) {
          puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar10 + 0x48) * 4);
          uVar4 = *puVar1;
          if ((0xfffffff < (uVar4 & 0xf0000000)) && ((uVar4 & 0xf0000000) < 0x40000001)) {
            uVar12 = uVar4 & 0xfff00000;
            if (uVar12 < 0x11400001) {
              if ((((uVar12 != 0x11400000) && (uVar12 != 0x10f00000)) && (uVar12 != 0x11100000)) &&
                 (uVar12 != 0x11200000)) {
                bVar13 = uVar12 == 0x11300000;
LAB_0091b402:
                if (!bVar13) {
                  local_20 = 0;
                  if (puVar1[3] != 0) {
                    puVar11 = (uint *)puVar1[4];
                    do {
                      if (local_8 == *puVar11) break;
                      local_20 = local_20 + 1;
                      puVar11 = puVar11 + 1;
                    } while (local_20 < puVar1[3]);
                  }
                  uVar4 = puVar1[1] / (uVar4 & 0xfffff);
                  uVar5 = FUN_0091464c();
                  local_1c = 0;
                  if (uVar4 != 0) {
                    do {
                      iVar6 = FUN_00915d83(puVar1,local_1c,local_20,uVar5);
                      uVar12 = uVar12 * 0x83f + iVar6;
                      local_1c = local_1c + 1;
                    } while (local_1c < uVar4);
                  }
                  *(uint *)(iVar10 + 0x40) = uVar12;
                  _Memory[local_14] = local_8;
                  local_14 = local_14 + 1;
                }
              }
            }
            else if (((uVar12 != 0x11500000) && (uVar12 != 0x20700000)) && (uVar12 != 0x20800000)) {
              bVar13 = uVar12 == 0x20900000;
              goto LAB_0091b402;
            }
          }
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(uint *)(in_ECX + 8));
    }
    FUN_00915b0e(FUN_00915ae0,_Memory,local_14,in_ECX);
    if (local_14 == 0) goto LAB_0091b782;
    local_3c = 1;
    local_50 = local_14;
    local_38 = _Memory;
    do {
      iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + *local_38 * 4);
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar10 + 0x48) * 4);
      if (*(int *)(iVar10 + 0x30) == *local_38) {
        for (local_2c = local_3c; local_2c < local_14; local_2c = local_2c + 1) {
          iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + _Memory[local_2c] * 4);
          if (*(int *)(iVar10 + 0x40) != *(int *)(iVar6 + 0x40)) break;
          if ((((*(int *)(iVar6 + 0x30) == _Memory[local_2c]) &&
               (*(int *)(iVar10 + 0x48) != *(int *)(iVar6 + 0x48))) &&
              ((*(int *)(iVar10 + 4) == *(int *)(iVar6 + 4) &&
               ((*(int *)(iVar10 + 0x14) == *(int *)(iVar6 + 0x14) &&
                (*(int *)(iVar10 + 0x18) == *(int *)(iVar6 + 0x18))))))) &&
             (uVar4 = *puVar1,
             ((**(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar6 + 0x48) * 4) ^ uVar4) &
             0xfff00000) == 0)) {
            uVar4 = puVar1[1] / (uVar4 & 0xfffff);
            uVar5 = FUN_0091464c();
            local_20 = 0;
LAB_0091b575:
            iVar7 = iVar6;
            if (local_20 == 0) {
              iVar7 = iVar10;
            }
            uVar12 = *(uint *)(iVar7 + 0x48);
            iVar7 = iVar10;
            if (local_20 == 0) {
              iVar7 = iVar6;
            }
            puVar2 = *(undefined4 **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar7 + 0x48) * 4);
            iVar7 = *(int *)(*(int *)(in_ECX + 0x18) + uVar12 * 4);
            local_1c = 0;
            if (puVar2[3] != 0) {
              local_34 = (int *)puVar2[4];
              do {
                if (*(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_34 * 4) + 0x54) <= uVar12)
                break;
                local_18 = 0;
                if (*(int *)(iVar7 + 0xc) != 0) {
                  do {
                    local_8 = 0;
                    if (uVar4 != 0) {
                      do {
                        iVar8 = FUN_00915d83(puVar2,local_8,local_1c,uVar5);
                        iVar9 = FUN_00915d83(iVar7,local_8,local_18,uVar5);
                        if (iVar9 != iVar8) break;
                        local_8 = local_8 + 1;
                      } while (local_8 < uVar4);
                    }
                  } while ((local_8 != uVar4) &&
                          (local_18 = local_18 + 1, local_18 < *(uint *)(iVar7 + 0xc)));
                }
                if (local_18 == *(uint *)(iVar7 + 0xc)) break;
                local_1c = local_1c + 1;
                local_34 = local_34 + 1;
              } while (local_1c < (uint)puVar2[3]);
            }
            if (local_1c < (uint)puVar2[3]) goto code_r0x0091b656;
            local_1c = 0;
            if (puVar2[3] != 0) {
              do {
                local_20 = 0;
                if (*(int *)(iVar7 + 0xc) != 0) {
                  do {
                    local_8 = 0;
                    if (uVar4 != 0) {
                      do {
                        iVar6 = FUN_00915d83(iVar7,local_8,local_20,uVar5);
                        iVar8 = FUN_00915d83(puVar2,local_8,local_1c,uVar5);
                        if (iVar6 != iVar8) break;
                        local_8 = local_8 + 1;
                      } while (local_8 < uVar4);
                    }
                  } while ((local_8 != uVar4) &&
                          (local_20 = local_20 + 1, local_20 < *(uint *)(iVar7 + 0xc)));
                }
                iVar6 = local_1c * 4;
                local_1c = local_1c + 1;
                *(undefined4 *)
                 (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar2[4] + iVar6) * 4) + 0x30) =
                     *(undefined4 *)(*(int *)(iVar7 + 0x10) + local_20 * 4);
              } while (local_1c < (uint)puVar2[3]);
            }
            *puVar2 = 0;
            bVar3 = true;
          }
LAB_0091b712:
        }
      }
      local_38 = local_38 + 1;
      local_3c = local_3c + 1;
      local_50 = local_50 - 1;
    } while (local_50 != 0);
    if (!bVar3) goto LAB_0091b782;
    uVar4 = 0;
    if (*(int *)(in_ECX + 8) != 0) {
      iVar10 = *(int *)(in_ECX + 0x14);
      do {
        iVar6 = *(int *)(iVar10 + uVar4 * 4);
        while (*(int *)(iVar6 + 0x30) !=
               *(int *)(*(int *)(iVar10 + *(int *)(iVar6 + 0x30) * 4) + 0x30)) {
          *(undefined4 *)(iVar6 + 0x30) =
               *(undefined4 *)(*(int *)(iVar10 + *(int *)(iVar6 + 0x30) * 4) + 0x30);
          iVar10 = *(int *)(in_ECX + 0x14);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 8));
    }
    FUN_00919e8f();
  } while( true );
code_r0x0091b656:
  local_20 = local_20 + 1;
  if (1 < local_20) goto LAB_0091b712;
  goto LAB_0091b575;
}


// ==== FUN_0091b791 @ 0x0091b791 ====

void FUN_0091b791(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a29594;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0091b7b3 @ 0x0091b7b3 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0091b7b3(void)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  int in_ECX;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int *local_10;
  uint local_c;
  uint local_8;
  
  bVar6 = false;
  bVar5 = false;
  bVar4 = false;
  local_c = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + local_c * 4);
      if ((*(int *)(in_ECX + 0x74) != *(int *)(iVar8 + 4)) &&
         (piVar10 = (int *)(iVar8 + 8), *piVar10 != -1)) {
        if (!bVar4) {
          FUN_009198e4();
          bVar4 = true;
        }
        iVar7 = *piVar10;
        iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7 * 4) + 0x48);
        if ((iVar1 != -1) &&
           (puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar1 * 4),
           (*puVar2 & 0xfff00000) == 0x10000000)) {
          local_8 = 0;
          if (puVar2[3] != 0) {
            piVar10 = (int *)puVar2[4];
            do {
              if (*piVar10 == iVar7) break;
              local_8 = local_8 + 1;
              piVar10 = piVar10 + 1;
            } while (local_8 < puVar2[3]);
          }
          piVar10 = (int *)(puVar2[2] + local_8 * 4);
        }
        iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar10 * 4);
        uVar11 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 4);
        if (((uVar11 & 0x100) == 0) || (*(int *)(iVar1 + 8) != -1)) {
          if (((uVar11 & 2) == 0) ||
             ((*(int *)(iVar1 + 0x48) == -1 ||
              (puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar1 + 0x48) * 4),
              (*puVar2 & 0xfff00000) != 0x20400000)))) goto LAB_0091ba89;
          uVar11 = puVar2[3];
          uVar12 = 0;
          if (uVar11 != 0) {
            piVar9 = (int *)puVar2[4];
            do {
              if (*piVar9 == *piVar10) break;
              uVar12 = uVar12 + 1;
              piVar9 = piVar9 + 1;
            } while (uVar12 < uVar11);
          }
          iVar8 = *(int *)(puVar2[2] + uVar12 * 4);
          iVar1 = *(int *)(puVar2[2] + (uVar11 + uVar12) * 4);
          puVar2 = *(uint **)(*(int *)(in_ECX + 0x14) + iVar8 * 4);
          puVar3 = *(uint **)(*(int *)(in_ECX + 0x14) + iVar1 * 4);
          if (((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar2[1] * 4) + 5) & 1) == 0) ||
               (puVar2[2] != 0xffffffff)) || ((*puVar2 & 4) == 0)) ||
             (((*puVar2 & 2) == 0 && ((*puVar3 & 2) == 0)))) {
            if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar3[1] * 4) + 5) & 1) == 0) ||
                ((puVar3[2] != 0xffffffff || ((*puVar3 & 4) == 0)))) ||
               (((*puVar2 & 2) == 0 && ((*puVar3 & 2) == 0)))) goto LAB_0091ba89;
            local_10 = (int *)__ftol();
          }
          else {
            local_10 = (int *)__ftol();
            iVar8 = iVar1;
          }
          uVar11 = 0;
          if (*piVar10 == iVar7) {
            if (*(int *)(in_ECX + 8) != 0) {
              do {
                iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + uVar11 * 4);
                if (iVar7 == *(int *)(iVar1 + 8)) {
                  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + (int)local_10;
                  *(int *)(iVar1 + 8) = iVar8;
                }
                uVar11 = uVar11 + 1;
              } while (uVar11 < *(uint *)(in_ECX + 8));
            }
          }
          else {
            if (*(int *)(in_ECX + 8) != 0) {
              do {
                iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + uVar11 * 4);
                if (iVar7 == *(int *)(iVar1 + 8)) {
                  piVar9 = (int *)(iVar1 + 0xc);
                  *piVar9 = *piVar9 + (int)local_10;
                }
                uVar11 = uVar11 + 1;
              } while (uVar11 < *(uint *)(in_ECX + 8));
            }
            *piVar10 = iVar8;
          }
        }
        else {
          iVar7 = __ftol();
          local_8 = 0;
          uVar11 = iVar7 + *(int *)(iVar8 + 0xc);
          if (*(uint *)(in_ECX + 8) != 0) {
            local_10 = *(int **)(in_ECX + 0x14);
            do {
              if (((((local_8 != local_c) &&
                    (iVar7 = *local_10, *(int *)(iVar7 + 4) == *(int *)(iVar8 + 4))) &&
                   (*(int *)(iVar7 + 8) == -1)) &&
                  ((*(uint *)(iVar7 + 0xc) == uVar11 &&
                   (*(int *)(iVar7 + 0x10) == *(int *)(iVar8 + 0x10))))) &&
                 ((*(int *)(iVar7 + 0x14) == *(int *)(iVar8 + 0x14) &&
                  (*(int *)(iVar7 + 0x18) == *(int *)(iVar8 + 0x18))))) {
                if (!bVar5) {
                  FUN_00919e76();
                  bVar5 = true;
                }
                *(uint *)(iVar8 + 0x30) = local_8;
                break;
              }
              local_8 = local_8 + 1;
              local_10 = local_10 + 1;
            } while (local_8 < *(uint *)(in_ECX + 8));
          }
          if (local_8 == *(uint *)(in_ECX + 8)) {
            *(undefined4 *)(iVar8 + 8) = 0xffffffff;
            *(uint *)(iVar8 + 0xc) = uVar11;
            if (*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar8 + 4) * 4) + 8) <= uVar11
               ) {
              FUN_0091a001();
              return 0x80004005;
            }
          }
        }
        bVar6 = true;
      }
LAB_0091ba89:
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 8));
    if (bVar6) {
      if (bVar5) {
        FUN_00919e8f();
      }
      return 0;
    }
  }
  return 1;
}


// ==== FUN_0091bab7 @ 0x0091bab7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0091bab7(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint *puVar5;
  bool bVar6;
  undefined8 uVar7;
  bool bVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int in_ECX;
  int iVar13;
  int iVar14;
  int *piVar15;
  undefined4 *puVar16;
  uint uVar17;
  undefined4 *puVar18;
  bool bVar19;
  int local_34;
  uint local_30;
  int local_28;
  uint local_20;
  int *local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  FUN_009198e4();
  local_30 = -1;
  local_34 = -1;
  bVar6 = false;
  local_18 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_18 * 4);
      uVar9 = *puVar1;
      if ((((uVar9 & 0xfff00000) != 0) && (0xfffffff < (uVar9 & 0xf0000000))) &&
         ((uVar9 & 0xf0000000) < 0x40000001)) {
        uVar9 = puVar1[1] / (uVar9 & 0xfffff);
        local_c = 0;
        if (uVar9 != 0) {
          do {
            uVar11 = puVar1[3];
            local_20 = 0;
            local_14 = 0;
            if (uVar11 != 0) {
              do {
                iVar14 = *(int *)(puVar1[2] + (uVar11 * local_c + local_14) * 4);
                iVar12 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + local_14 * 4) * 4);
                if ((**(byte **)(*(int *)(in_ECX + 0x14) + iVar14 * 4) & 1) != 0) {
                  local_28 = *(int *)(iVar12 + 0x18);
                  for (iVar13 = *(int *)(iVar12 + 0x14); iVar13 != -1;
                      iVar13 = *(int *)(iVar13 + 0x14)) {
                    local_10 = 0;
                    iVar10 = *(int *)(*(int *)(in_ECX + 0x18) +
                                     *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar13 * 4) + 0x48)
                                     * 4);
                    if (*(int *)(iVar10 + 0xc) != 0) {
                      local_1c = *(int **)(iVar10 + 0x10);
                      do {
                        if (*local_1c == iVar13) break;
                        local_10 = local_10 + 1;
                        local_1c = local_1c + 1;
                      } while (local_10 < *(uint *)(iVar10 + 0xc));
                    }
                    if (local_28 == 0) {
                      iVar10 = FUN_009169c8(*(undefined4 *)(*(int *)(iVar10 + 8) + local_10 * 4),
                                            iVar14);
                      if (iVar10 != 0) {
                        *(undefined4 *)(iVar12 + 0x40) = 0;
                        goto LAB_0091bc15;
                      }
                    }
                    else {
                      iVar10 = FUN_009169c8(iVar14,*(undefined4 *)
                                                    (*(int *)(iVar10 + 8) + local_10 * 4));
                      if (iVar10 != 0) {
                        *(undefined4 *)(iVar12 + 0x40) = 1;
LAB_0091bc15:
                        local_20 = local_20 + 1;
                        break;
                      }
                    }
                    iVar13 = *(int *)(iVar13 * 4 + *(int *)(in_ECX + 0x14));
                    local_28 = *(int *)(iVar13 + 0x18);
                  }
                }
                local_14 = local_14 + 1;
                uVar11 = puVar1[3];
              } while (local_14 < uVar11);
            }
            uVar17 = 0;
            uVar11 = puVar1[3];
            if ((local_20 == uVar11) && (uVar11 != 0)) {
              do {
                iVar14 = *(int *)(*(int *)(in_ECX + 0x14) +
                                 *(int *)(puVar1[2] + (uVar11 * local_c + uVar17) * 4) * 4);
                iVar12 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar14 + 4) * 4);
                if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + uVar17 * 4) * 4
                                     ) + 0x40) == 0) {
                  if (((*(byte *)(iVar12 + 5) & 1) == 0) ||
                     (_DAT_0099d098 != *(double *)(iVar14 + 0x20))) {
                    uVar11 = local_34;
                    if (local_34 == -1) {
                      uVar11 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,0);
                      local_34 = uVar11;
                    }
                    goto LAB_0091bcd9;
                  }
                }
                else if (((*(byte *)(iVar12 + 5) & 1) == 0) ||
                        (_DAT_0099d0a0 != *(double *)(iVar14 + 0x20))) {
                  uVar11 = local_30;
                  if (local_30 == -1) {
                    uVar11 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,0x3ff0000000000000);
                    local_30 = uVar11;
                  }
LAB_0091bcd9:
                  *(uint *)(puVar1[2] + (puVar1[3] * local_c + uVar17) * 4) = uVar11;
                  bVar6 = true;
                }
                uVar11 = puVar1[3];
                uVar17 = uVar17 + 1;
              } while (uVar17 < uVar11);
            }
            local_c = local_c + 1;
          } while (local_c < uVar9);
        }
      }
      local_18 = local_18 + 1;
    } while (local_18 < *(uint *)(in_ECX + 0xc));
  }
  bVar8 = false;
  FUN_00919e76();
  local_1c = (int *)0x0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_1c * 4);
      if ((*puVar1 & 0xfff00000) != 0) {
        local_14 = 0;
        if (puVar1[3] != 0) {
          do {
            iVar14 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + local_14 * 4) * 4);
            local_18 = *(int *)(iVar14 + 0x18);
            iVar12 = *(int *)(iVar14 + 0x14);
            while (iVar12 != -1) {
              pbVar4 = *(byte **)(*(int *)(in_ECX + 0x14) + iVar12 * 4);
              if ((*pbVar4 & 0x80) == 0) break;
              bVar6 = _DAT_0099d098 == *(double *)(pbVar4 + 0x20);
              if (local_18 == 0) {
                if (bVar6) goto LAB_0091bef6;
LAB_0091bd9a:
                local_18 = 0;
                iVar12 = -1;
              }
              else {
                if (bVar6) goto LAB_0091bd9a;
LAB_0091bef6:
                iVar12 = *(int *)(iVar12 * 4 + *(int *)(in_ECX + 0x14));
                local_18 = *(int *)(iVar12 + 0x18);
                iVar12 = *(int *)(iVar12 + 0x14);
              }
              bVar6 = true;
            }
            local_14 = local_14 + 1;
            *(int *)(iVar14 + 0x14) = iVar12;
            *(uint *)(iVar14 + 0x18) = local_18;
          } while (local_14 < puVar1[3]);
        }
        uVar9 = *puVar1;
        uVar11 = uVar9 & 0xfff00000;
        if ((uVar11 == 0x10f00000) || (uVar11 == 0x11400000)) {
          uVar9 = 0;
          bVar19 = puVar1[3] == 0;
          local_30 = 0;
          local_18 = 0;
          if (puVar1[3] != 0) {
            do {
              iVar14 = local_18 * 4;
              pbVar4 = *(byte **)(*(int *)(in_ECX + 0x14) + *(int *)(iVar14 + puVar1[4]) * 4);
              puVar5 = *(uint **)(*(int *)(in_ECX + 0x14) + *(int *)(iVar14 + puVar1[2]) * 4);
              if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar5[1] * 4) + 5) & 1) == 0) ||
                 (puVar5[2] != 0xffffffff)) {
                if (((*puVar5 & 4) != 0) && ((*puVar5 & 8) != 0)) {
                  *pbVar4 = *pbVar4 | 0x80;
                  goto LAB_0091c137;
                }
                *pbVar4 = *pbVar4 & 0x7f;
              }
              else {
                *pbVar4 = *pbVar4 | 0x80;
                if (_DAT_0099d098 == *(double *)(puVar5 + 8)) {
LAB_0091c137:
                  uVar7 = 0;
                }
                else {
                  uVar7 = 0x3ff0000000000000;
                }
                *(undefined8 *)(pbVar4 + 0x20) = uVar7;
              }
              if ((*pbVar4 & 0x80) == 0) {
                *(undefined4 *)(uVar9 * 4 + puVar1[4]) = *(undefined4 *)(iVar14 + puVar1[4]);
                *(undefined4 *)(uVar9 * 4 + puVar1[2]) = *(undefined4 *)(iVar14 + puVar1[2]);
                uVar9 = local_30 + 1;
                local_30 = uVar9;
              }
              local_18 = local_18 + 1;
            } while (local_18 < puVar1[3]);
            bVar19 = uVar9 == puVar1[3];
          }
          if (!bVar19) {
            uVar11 = -(uint)(uVar9 != 0) & (uVar9 & 0xfffff | 0x10f00000);
            puVar1[1] = uVar9;
            puVar1[3] = uVar9;
LAB_0091c1a7:
            *puVar1 = uVar11;
LAB_0091c1a9:
            bVar6 = true;
          }
        }
        else if ((uVar11 == 0x20700000) || (uVar11 == 0x20800000)) {
          uVar9 = puVar1[1] / (uVar9 & 0xfffff);
          local_10 = 0;
          local_c = 0;
          if (puVar1[3] != 0) {
            do {
              iVar14 = *(int *)(in_ECX + 0x14);
              iVar12 = *(int *)(local_c * 4 + puVar1[4]);
              iVar13 = *(int *)(iVar14 + iVar12 * 4);
              if ((*(int *)(iVar13 + 0x14) != -1) || (*(int *)(iVar13 + 0x18) != 0)) {
                iVar10 = *(int *)(local_c * 4 + puVar1[2]);
                iVar2 = *(int *)(puVar1[2] + (puVar1[3] + local_c) * 4);
                iVar3 = *(int *)(iVar14 + iVar10 * 4);
                if ((*(int *)(iVar3 + 0x14) == -1) && (*(int *)(iVar3 + 0x18) == 0)) {
                  *(undefined4 *)(*(int *)(iVar14 + iVar2 * 4) + 4) = *(undefined4 *)(in_ECX + 0x88)
                  ;
                  *(int *)(iVar13 + 0x30) = iVar2;
                }
                else {
                  iVar14 = *(int *)(iVar14 + iVar2 * 4);
                  if ((*(int *)(iVar14 + 0x14) != -1) || (*(int *)(iVar14 + 0x18) != 0)) {
                    local_18 = 0;
                    *(int *)(puVar1[4] + local_10 * 4) = iVar12;
                    if (uVar9 != 0) {
                      do {
                        iVar14 = puVar1[3] * local_18;
                        local_18 = local_18 + 1;
                        *(undefined4 *)(puVar1[2] + (iVar14 + local_10) * 4) =
                             *(undefined4 *)(puVar1[2] + (local_c + iVar14) * 4);
                      } while (local_18 < uVar9);
                    }
                    local_10 = local_10 + 1;
                    goto LAB_0091c04c;
                  }
                  *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(in_ECX + 0x88);
                  *(int *)(iVar13 + 0x30) = iVar10;
                }
                bVar8 = true;
              }
LAB_0091c04c:
              local_c = local_c + 1;
            } while (local_c < puVar1[3]);
          }
          if (local_10 != puVar1[3]) {
            local_18 = 0;
            if (uVar9 != 0) {
              local_20 = 0;
              do {
                puVar18 = (undefined4 *)(local_20 + puVar1[2]);
                local_20 = local_20 + local_10 * 4;
                puVar16 = (undefined4 *)(puVar1[2] + puVar1[3] * local_18 * 4);
                for (uVar11 = local_10 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *puVar18 = *puVar16;
                  puVar16 = puVar16 + 1;
                  puVar18 = puVar18 + 1;
                }
                local_18 = local_18 + 1;
                for (iVar14 = 0; iVar14 != 0; iVar14 = iVar14 + -1) {
                  *(undefined1 *)puVar18 = *(undefined1 *)puVar16;
                  puVar16 = (undefined4 *)((int)puVar16 + 1);
                  puVar18 = (undefined4 *)((int)puVar18 + 1);
                }
              } while (local_18 < uVar9);
            }
            if (local_10 == 0) {
              uVar11 = 0;
            }
            else {
              uVar11 = (*puVar1 ^ local_10) & 0xfffff ^ *puVar1;
            }
            puVar1[3] = local_10;
            puVar1[1] = uVar9 * local_10;
            goto LAB_0091c1a7;
          }
        }
        else if (((uVar9 & 0xf0000000) < 0x10000000) || (0x40000000 < (uVar9 & 0xf0000000))) {
          uVar9 = puVar1[3];
          if (uVar9 != 0) {
            local_20 = 0;
            if (uVar9 != 0) {
              piVar15 = (int *)puVar1[4];
              do {
                iVar14 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar15 * 4);
                if ((*(int *)(iVar14 + 0x14) != -1) || (*(int *)(iVar14 + 0x18) != 0)) {
                  local_20 = local_20 + 1;
                }
                piVar15 = piVar15 + 1;
                uVar9 = uVar9 - 1;
              } while (uVar9 != 0);
              if (local_20 != 0) goto LAB_0091c1b0;
            }
            uVar11 = 0;
            puVar1[1] = 0;
            puVar1[3] = 0;
            goto LAB_0091c1a7;
          }
        }
        else {
          uVar9 = puVar1[1] / (uVar9 & 0xfffff);
          local_c = 0;
          local_10 = 0;
          if (puVar1[3] != 0) {
            do {
              iVar14 = *(int *)(puVar1[4] + local_10 * 4);
              iVar12 = *(int *)(*(int *)(in_ECX + 0x14) + iVar14 * 4);
              if ((*(int *)(iVar12 + 0x14) != -1) || (*(int *)(iVar12 + 0x18) != 0)) {
                local_18 = 0;
                *(int *)(puVar1[4] + local_c * 4) = iVar14;
                if (uVar9 != 0) {
                  do {
                    iVar14 = puVar1[3] * local_18;
                    local_18 = local_18 + 1;
                    *(undefined4 *)(puVar1[2] + (iVar14 + local_c) * 4) =
                         *(undefined4 *)(puVar1[2] + (local_10 + iVar14) * 4);
                  } while (local_18 < uVar9);
                }
                local_c = local_c + 1;
              }
              local_10 = local_10 + 1;
            } while (local_10 < puVar1[3]);
          }
          if (local_c != puVar1[3]) {
            local_18 = 0;
            if (uVar9 != 0) {
              local_20 = 0;
              do {
                puVar16 = (undefined4 *)(puVar1[2] + puVar1[3] * local_18 * 4);
                puVar18 = (undefined4 *)(local_20 + puVar1[2]);
                for (uVar11 = local_c & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *puVar18 = *puVar16;
                  puVar16 = puVar16 + 1;
                  puVar18 = puVar18 + 1;
                }
                local_18 = local_18 + 1;
                for (iVar14 = 0; iVar14 != 0; iVar14 = iVar14 + -1) {
                  *(undefined1 *)puVar18 = *(undefined1 *)puVar16;
                  puVar16 = (undefined4 *)((int)puVar16 + 1);
                  puVar18 = (undefined4 *)((int)puVar18 + 1);
                }
                local_20 = local_20 + local_c * 4;
              } while (local_18 < uVar9);
            }
            if (local_c == 0) {
              uVar11 = 0;
            }
            else {
              uVar11 = (*puVar1 ^ local_c) & 0xfffff ^ *puVar1;
            }
            *puVar1 = uVar11;
            puVar1[3] = local_c;
            puVar1[1] = uVar9 * local_c;
            goto LAB_0091c1a9;
          }
        }
      }
LAB_0091c1b0:
      local_1c = (int *)((int)local_1c + 1);
    } while (local_1c < *(uint *)(in_ECX + 0xc));
    if (bVar8) {
      FUN_00919e8f();
    }
  }
  return !bVar6;
}


// ==== FUN_0091c1d9 @ 0x0091c1d9 ====

undefined4 FUN_0091c1d9(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  int in_ECX;
  uint uVar13;
  uint uVar14;
  int *local_24;
  int local_1c;
  uint local_18;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if ((*(byte *)(in_ECX + 0x6c) & 1) == 0) {
    bVar8 = false;
    FUN_009198e4();
    iVar9 = *(int *)(in_ECX + 0xc);
    if (iVar9 != 0) {
      do {
        iVar9 = iVar9 + -1;
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar9 * 4);
        if (((*puVar1 & 0xfff00000) == 0x10000000) || ((*puVar1 & 0xfff00000) == 0x20700000)) {
          local_c = 0;
          if (puVar1[3] != 0) {
            piVar10 = (int *)puVar1[4];
            do {
              if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                     *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar10 * 4) + 4)
                                     * 4) + 4) & 0x20) == 0) break;
              local_c = local_c + 1;
              piVar10 = piVar10 + 1;
            } while (local_c < puVar1[3]);
          }
          if (puVar1[3] <= local_c) {
            local_c = 0;
            if (puVar1[1] != 0) {
              piVar10 = (int *)puVar1[2];
              do {
                if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                       *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar10 * 4) + 4
                                               ) * 4) + 4) & 2) == 0) break;
                local_c = local_c + 1;
                piVar10 = piVar10 + 1;
              } while (local_c < puVar1[1]);
            }
            if (puVar1[1] <= local_c) {
              uVar13 = *puVar1 & 0xfffff;
              uVar11 = puVar1[1] / uVar13;
              local_10 = 0;
              if (uVar11 != 0) {
                local_1c = 0;
                do {
                  local_c = 0;
                  if (uVar13 != 0) {
                    local_18 = local_1c;
                    do {
                      iVar2 = *(int *)(*(int *)(in_ECX + 0x18) +
                                      *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                       *(int *)(local_18 + puVar1[2]) * 4) + 0x48) *
                                      4);
                      iVar12 = FUN_009145ef();
                      local_8 = 0;
                      uVar3 = *(uint *)(iVar2 + 0xc);
                      if (uVar3 != 0) {
                        local_24 = *(int **)(iVar2 + 0x10);
                        do {
                          iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *local_24 * 4);
                          if (((1 < *(uint *)(iVar2 + 0x5c)) || (*(int *)(iVar2 + 0x54) != iVar9))
                             || ((iVar12 != 0 &&
                                 (local_8 !=
                                  *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                    *(int *)(puVar1[4] + local_c * 4) * 4) + 0x10)))
                                )) break;
                          local_8 = local_8 + 1;
                          local_24 = local_24 + 1;
                        } while (local_8 < uVar3);
                      }
                      if (local_8 < uVar3) break;
                      local_c = local_c + 1;
                      local_18 = local_18 + 4;
                    } while (local_c < uVar13);
                    if (local_c < uVar13) break;
                  }
                  local_10 = local_10 + 1;
                  local_1c = local_1c + uVar13 * 4;
                } while (local_10 < uVar11);
                if (local_10 < uVar11) goto LAB_0091c474;
              }
              local_10 = 0;
              if (puVar1[3] != 0) {
                do {
                  local_1c = local_10 * 4;
                  puVar4 = *(uint **)(*(int *)(in_ECX + 0x14) + *(int *)(local_1c + puVar1[4]) * 4);
                  if (uVar11 != 0) {
                    local_18 = uVar11;
                    do {
                      puVar5 = *(uint **)(*(int *)(in_ECX + 0x14) +
                                         *(int *)(local_1c + puVar1[2]) * 4);
                      uVar3 = *puVar5;
                      uVar6 = *puVar4;
                      uVar7 = *puVar5;
                      *puVar5 = uVar7 & 0xf1ffffff;
                      uVar14 = uVar6 & 0xe000000;
                      if ((uVar6 & 0xe000000) <= (uVar3 & 0xe000000)) {
                        uVar14 = uVar3 & 0xe000000;
                      }
                      *puVar5 = uVar7 & 0xf1ffffff | uVar14;
                      puVar5[1] = puVar4[1];
                      puVar5[2] = puVar4[2];
                      puVar5[3] = puVar4[3];
                      puVar5[4] = puVar4[4];
                      if (puVar5[0x18] == 0) {
                        puVar5[0x18] = puVar4[0x18];
                        puVar5[0x19] = puVar4[0x19];
                      }
                      puVar5[0x1a] = puVar4[0x1a];
                      puVar5[0x1b] = puVar4[0x1b];
                      puVar5[0x1c] = puVar4[0x1c];
                      local_1c = local_1c + uVar13 * 4;
                      local_18 = local_18 - 1;
                    } while (local_18 != 0);
                  }
                  local_10 = local_10 + 1;
                  puVar4[1] = *(uint *)(in_ECX + 0x74);
                } while (local_10 < puVar1[3]);
              }
              bVar8 = true;
              *puVar1 = 0;
              puVar1[1] = 0;
              puVar1[3] = 0;
            }
          }
        }
LAB_0091c474:
      } while (iVar9 != 0);
      if (bVar8) {
        return 0;
      }
    }
  }
  return 1;
}


// ==== FUN_0091c491 @ 0x0091c491 ====

bool FUN_0091c491(void)

{
  uint uVar1;
  bool bVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  bVar2 = false;
  FUN_009198e4();
  uVar3 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    do {
      iVar5 = *(int *)(*(int *)(in_ECX + 0x10) + uVar3 * 4);
      if (((*(uint *)(iVar5 + 4) & 0x400) != 0) && (*(int *)(iVar5 + 0x28) == -1)) {
        *(uint *)(iVar5 + 4) = *(uint *)(iVar5 + 4) & 0xfffffbff;
        bVar2 = true;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 4));
  }
  iVar5 = 0;
  uVar3 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4);
      uVar1 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4);
      if (((uVar1 & 0x100) != 0) && ((uVar1 & 0x800) != 0)) {
        *(undefined4 *)(iVar4 + 0x54) = 1;
      }
      if ((*(int *)(iVar4 + 0x54) == -1) && (*(int *)(iVar4 + 0x48) == -1)) {
        *(undefined4 *)(iVar4 + 0x30) = 0xffffffff;
      }
      else {
        *(int *)(iVar4 + 0x30) = iVar5;
        iVar5 = iVar5 + 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 8));
  }
  iVar4 = 0;
  if (iVar5 == *(int *)(in_ECX + 8)) {
    bVar2 = !bVar2;
  }
  else {
    FUN_00919e8f();
    uVar3 = 0;
    if (*(int *)(in_ECX + 8) != 0) {
      do {
        iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4);
        if ((*(int *)(iVar5 + 0x54) == -1) && (*(int *)(iVar5 + 0x48) == -1)) {
          FUN_008f61e7(1);
        }
        else {
          *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) = iVar5;
          iVar4 = iVar4 + 1;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(in_ECX + 8));
    }
    puVar6 = (undefined4 *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
    for (uVar3 = *(int *)(in_ECX + 8) - iVar4 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(int *)(in_ECX + 8) = iVar4;
    bVar2 = false;
  }
  return bVar2;
}


// ==== FUN_0091c58a @ 0x0091c58a ====

undefined4 FUN_0091c58a(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  undefined4 *puVar6;
  uint local_10;
  uint local_c;
  uint local_8;
  
  FUN_009198e4();
  uVar5 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x14) + uVar5 * 4);
      iVar3 = *(int *)(*(int *)(in_ECX + 0x10) + puVar1[1] * 4);
      *puVar1 = *puVar1 & 0xffffffdf;
      uVar4 = *(uint *)(iVar3 + 4);
      if (((uVar4 & 0x10) != 0) && ((uVar4 & 0x200) == 0)) {
        *puVar1 = *puVar1 | 0x20;
      }
      if ((*(byte *)(iVar3 + 5) & 8) != 0) {
        *puVar1 = *puVar1 | 0x20;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 8));
  }
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      uVar5 = *puVar1 & 0xfff00000;
      if (uVar5 != 0) {
        if ((((uVar5 == 0x50100000) || (uVar5 == 0x11000000)) || (uVar5 == 0x11200000)) ||
           ((*puVar1 & 0xf0000000) == 0x60000000)) {
          uVar5 = 0;
          if (puVar1[3] != 0) {
            do {
              puVar2 = *(uint **)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + uVar5 * 4) * 4);
              *puVar2 = *puVar2 | 0x20;
              uVar5 = uVar5 + 1;
            } while (uVar5 < puVar1[3]);
          }
        }
        else if (((uVar5 == 0x10f00000) || (uVar5 == 0x11100000)) || (uVar5 == 0x11400000)) {
          uVar5 = 0;
          if (puVar1[3] != 0) {
            do {
              puVar2 = *(uint **)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + uVar5 * 4) * 4);
              *puVar2 = *puVar2 | 0x20;
              uVar5 = uVar5 + 1;
            } while (uVar5 < puVar1[3]);
          }
        }
        else {
          uVar5 = 0;
          if (puVar1[3] != 0) {
            do {
              iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + uVar5 * 4) * 4);
              if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4) + 5) &
                   0x10) != 0) && (iVar3 = FUN_00915e78(*(undefined4 *)(iVar3 + 0x14)), iVar3 != 0))
              {
                puVar2 = *(uint **)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + uVar5 * 4) * 4);
                *puVar2 = *puVar2 | 0x20;
              }
              uVar5 = uVar5 + 1;
            } while (uVar5 < puVar1[3]);
          }
          uVar5 = *puVar1 & 0xf0000000;
          if ((uVar5 < 0x10000000) || (0x40000000 < uVar5)) {
            local_10 = 0;
            if (puVar1[1] != 0) {
              puVar6 = (undefined4 *)puVar1[2];
              do {
                iVar3 = FUN_00915e78(*puVar6);
                if (iVar3 != 0) {
                  uVar5 = 0;
                  if (puVar1[3] != 0) {
                    do {
                      puVar2 = *(uint **)(*(int *)(in_ECX + 0x14) +
                                         *(int *)(puVar1[4] + uVar5 * 4) * 4);
                      *puVar2 = *puVar2 | 0x20;
                      uVar5 = uVar5 + 1;
                    } while (uVar5 < puVar1[3]);
                  }
                  break;
                }
                local_10 = local_10 + 1;
                puVar6 = puVar6 + 1;
              } while (local_10 < puVar1[1]);
            }
          }
          else {
            uVar4 = puVar1[1] / (*puVar1 & 0xfffff);
            local_8 = 0;
            uVar5 = puVar1[3];
            if (uVar5 != 0) {
              do {
                local_10 = 0;
                if (uVar4 != 0) {
                  puVar6 = (undefined4 *)(puVar1[2] + local_8 * 4);
                  do {
                    iVar3 = FUN_00915e78(*puVar6);
                    if (iVar3 != 0) {
                      puVar2 = *(uint **)(*(int *)(in_ECX + 0x14) +
                                         *(int *)(local_8 * 4 + puVar1[4]) * 4);
                      *puVar2 = *puVar2 | 0x20;
                      break;
                    }
                    local_10 = local_10 + 1;
                    puVar6 = puVar6 + uVar5;
                  } while (local_10 < uVar4);
                }
                local_8 = local_8 + 1;
                uVar5 = puVar1[3];
              } while (local_8 < uVar5);
            }
          }
        }
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  uVar5 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x14) + uVar5 * 4);
      if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar1[1] * 4) + 4) & 0x20) != 0) {
        *puVar1 = *puVar1 | 0x20;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 8));
  }
  return 0;
}


// ==== FUN_0091c7f0 @ 0x0091c7f0 ====

undefined4 FUN_0091c7f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  
  iVar1 = param_1;
  if ((*(int *)(param_1 + 0x48) != -1) && (*(int *)(param_2 + 0x14) != -1)) {
    iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(param_2 + 0x14) * 4);
    param_1 = 0;
    if (*(int *)(iVar4 + 0x48) != -1) {
      param_1 = FUN_0091470d();
    }
    iVar2 = FUN_0091494e();
    if ((iVar2 != 0) && (param_1 == 0)) {
      while( true ) {
        *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar4 + 0x14);
        *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar4 + 0x18);
        if (*(int *)(iVar4 + 0x14) == -1) {
          return 0;
        }
        iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar4 + 0x14) * 4);
        if (*(int *)(iVar4 + 0x48) == -1) break;
        iVar2 = FUN_0091470d();
        if (iVar2 != 0) {
          return 0;
        }
      }
      return 0;
    }
  }
  uVar3 = FUN_0091625c(iVar1 + 0x14,iVar1 + 0x18,*(undefined4 *)(param_2 + 0x14),
                       *(undefined4 *)(param_2 + 0x18));
  return uVar3;
}


// ==== FUN_0091c89b @ 0x0091c89b ====

int FUN_0091c89b(uint param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  
  puVar1 = *(uint **)(*(int *)(in_ECX + 0x14) + param_1 * 4);
  puVar2 = *(uint **)(*(int *)(in_ECX + 0x14) + param_2 * 4);
  puVar2[0xc] = param_1;
  iVar4 = FUN_0091c7f0(puVar1,puVar2);
  if (-1 < iVar4) {
    uVar3 = *puVar2;
    uVar7 = *puVar1 & 0xe000000;
    uVar6 = *puVar1 & 0xf1ffffff;
    *puVar1 = uVar6;
    uVar5 = uVar3 & 0xe000000;
    if ((uVar3 & 0xe000000) < uVar7) {
      uVar5 = uVar7;
    }
    *puVar1 = uVar6 | uVar5;
    if (puVar1[0x18] == 0) {
      puVar1[0x18] = puVar2[0x18];
      puVar1[0x19] = puVar2[0x19];
    }
    iVar4 = 0;
  }
  return iVar4;
}


// ==== FUN_0091c8fc @ 0x0091c8fc ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0091c8fc(uint *param_1,uint *param_2,int *param_3)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  float10 fVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  int in_ECX;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  float10 fVar15;
  double dVar16;
  int *local_10;
  int *local_8;
  
  iVar7 = *(int *)(in_ECX + 0x14);
  uVar10 = *(uint *)(*(int *)(iVar7 + (int)param_3 * 4) + 0x30);
  puVar1 = *(uint **)(iVar7 + (int)param_2 * 4);
  puVar2 = *(uint **)(iVar7 + uVar10 * 4);
  uVar14 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar1[1] * 4) + 4);
  if ((uVar14 & 1) == 0) {
    return 0;
  }
  if ((uVar14 & 0x1000) != 0) {
    return 0;
  }
  uVar14 = *puVar2;
  uVar6 = *puVar1;
  uVar12 = uVar6 & 0x40;
  uVar13 = *param_1 & 0xfff00000;
  if (uVar13 == 0x10000000) {
    *puVar1 = uVar6 | uVar14 & 0x1f;
    goto LAB_0091d021;
  }
  uVar5 = uVar14 & 0x40 | uVar6;
  *puVar1 = uVar5;
  if (((uVar6 & 0xe000000) == 0) &&
     ((((uVar13 == 0x10100000 || (uVar13 == 0x10300000)) || (uVar13 == 0x10400000)) ||
      ((uVar13 == 0x10d00000 || (uVar13 == 0x10e00000)))))) {
    *puVar1 = *puVar2 & 0xe000000 | uVar5;
  }
  uVar6 = 4;
  if (uVar13 == 0x10100000) {
    *puVar1 = *puVar1 | (uVar14 & 0x1f) >> 1 & 4 | (uVar14 & 4) << 1 | uVar14 & 0x13;
  }
  else {
    if (uVar13 == 0x10300000) {
      if (((uVar14 & 4) == 0) || ((uVar14 & 8) == 0)) {
        uVar6 = uVar14 & 0xc;
      }
    }
    else if (((uVar13 != 0x10400000) && (uVar13 != 0x10500000)) && (uVar13 != 0x10700000))
    goto LAB_0091ca1d;
    *puVar1 = *puVar1 | uVar6;
  }
LAB_0091ca1d:
  uVar6 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar2[1] * 4) + 4);
  if (((uVar6 & 0x100) == 0) || (puVar2[2] != 0xffffffff)) {
    if ((((uVar14 & 1) == 0) || (uVar13 != 0x10400000)) &&
       (((uVar14 & 2) == 0 || (uVar13 != 0x10400000)))) {
      if ((uVar14 & 8) != 0) {
        if (uVar13 == 0x10600000) {
          if (uVar12 != 0) {
            return 0;
          }
          if ((uVar14 & 4) == 0) {
            FUN_0091a001();
            return 0;
          }
          return 0;
        }
        if (uVar13 == 0x10700000) {
          if (uVar12 != 0) {
            return 0;
          }
          FUN_0091a001();
          dVar16 = 0.0;
          goto LAB_0091d017;
        }
      }
      if (((uVar6 & 0x200) == 0) || ((uVar13 != 0x10d00000 && (uVar13 != 0x10e00000)))) {
        if (uVar12 != 0) {
          return 0;
        }
        if ((uVar6 & 2) == 0) {
          return 0;
        }
        if (((((uVar13 != 0x10100000) ||
              (puVar8 = *(uint **)(*(int *)(in_ECX + 0x18) + puVar2[0x12] * 4),
              (*puVar8 & 0xfff00000) != 0x10100000)) &&
             ((uVar13 != 0x10300000 ||
              (puVar8 = *(uint **)(*(int *)(in_ECX + 0x18) + puVar2[0x12] * 4),
              (*puVar8 & 0xfff00000) != 0x10300000)))) &&
            ((uVar13 != 0x10500000 ||
             (puVar8 = *(uint **)(*(int *)(in_ECX + 0x18) + puVar2[0x12] * 4),
             (*puVar8 & 0xfff00000) != 0x10600000)))) &&
           ((uVar13 != 0x10600000 ||
            (puVar8 = *(uint **)(*(int *)(in_ECX + 0x18) + puVar2[0x12] * 4),
            (*puVar8 & 0xfff00000) != 0x10500000)))) {
LAB_0091ce02:
          if ((uVar13 == 0x10300000) &&
             (puVar8 = *(uint **)(*(int *)(in_ECX + 0x18) + puVar2[0x12] * 4),
             (*puVar8 & 0xfff00000) == 0x20500000)) {
            uVar14 = 0;
            if (puVar8[3] != 0) {
              puVar9 = (uint *)puVar8[4];
              do {
                if (*puVar9 == uVar10) break;
                uVar14 = uVar14 + 1;
                puVar9 = puVar9 + 1;
              } while (uVar14 < puVar8[3]);
            }
            uVar6 = puVar8[3];
            param_2 = (uint *)0x0;
            local_8 = (int *)(puVar8[2] + uVar14 * 4);
            local_10 = (int *)(puVar8[2] + (uVar6 + uVar14) * 4);
            do {
              iVar7 = *local_8;
              iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar7 * 4);
              if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4) + 4) & 2)
                   != 0) &&
                 (puVar8 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar3 + 0x48) * 4),
                 (*puVar8 & 0xfff00000) == 0x10700000)) {
                param_1 = (uint *)0x0;
                if (puVar8[3] != 0) {
                  piVar11 = (int *)puVar8[4];
                  do {
                    if (*piVar11 == iVar7) break;
                    param_1 = (uint *)((int)param_1 + 1);
                    piVar11 = piVar11 + 1;
                  } while (param_1 < puVar8[3]);
                }
                if (*(int *)(puVar8[2] + (int)param_1 * 4) == *local_10) {
                  puVar1[0xc] = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7 * 4) + 0x30);
                  return 0;
                }
              }
              local_8 = local_8 + uVar6;
              param_2 = (uint *)((int)param_2 + 1);
              local_10 = local_10 + -uVar6;
            } while (param_2 < 2);
          }
          if (uVar13 != 0x10500000) {
            return 0;
          }
          puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + puVar2[0x12] * 4);
          if ((*puVar2 & 0xfff00000) != 0x20500000) {
            return 0;
          }
          uVar14 = puVar2[3];
          param_1 = (uint *)0x0;
          if (uVar14 != 0) {
            param_2 = (uint *)puVar2[4];
            do {
              if (*param_2 == uVar10) break;
              param_1 = (uint *)((int)param_1 + 1);
              param_2 = param_2 + 1;
            } while (param_1 < uVar14);
          }
          param_2 = (uint *)0x0;
          iVar7 = *(int *)(in_ECX + 0x14);
          param_3 = (int *)(puVar2[2] + (int)param_1 * 4);
          do {
            iVar3 = *(int *)(iVar7 + *param_3 * 4);
            if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4) + 4) & 2) !=
                 0) && (puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar3 + 0x48) * 4),
                       (*puVar2 & 0xfff00000) == 0x10600000)) {
              param_1 = (uint *)0x0;
              if (puVar2[3] != 0) {
                piVar11 = (int *)puVar2[4];
                do {
                  if (*piVar11 == *param_3) break;
                  param_1 = (uint *)((int)param_1 + 1);
                  piVar11 = piVar11 + 1;
                } while (param_1 < puVar2[3]);
              }
              iVar7 = *(int *)(in_ECX + 0x14);
              uVar10 = **(uint **)(iVar7 + *(int *)(puVar2[2] + (int)param_1 * 4) * 4);
              if (((uVar10 & 4) != 0) && ((uVar10 & 8) != 0)) goto LAB_0091d00c;
            }
            param_3 = param_3 + uVar14;
            param_2 = (uint *)((int)param_2 + 1);
            if (1 < param_2) {
              return 0;
            }
          } while( true );
        }
        param_1 = (uint *)0x0;
        if (puVar8[3] != 0) {
          puVar9 = (uint *)puVar8[4];
          do {
            if (*puVar9 == uVar10) break;
            param_1 = (uint *)((int)param_1 + 1);
            puVar9 = puVar9 + 1;
          } while (param_1 < puVar8[3]);
        }
        if (puVar8[3] <= param_1) goto LAB_0091ce02;
        uVar10 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                   *(int *)(puVar8[2] + (int)param_1 * 4) * 4) + 0x30);
        goto LAB_0091d021;
      }
    }
LAB_0091d00c:
    dVar16 = 0.0;
  }
  else {
    if (uVar13 < 0x10800001) {
      if (uVar13 == 0x10800000) {
        fVar15 = (float10)fsin((float10)*(double *)(puVar2 + 8));
      }
      else if (uVar13 == 0x10100000) {
        fVar15 = -(float10)*(double *)(puVar2 + 8);
      }
      else if (uVar13 == 0x10300000) {
        if ((uVar12 == 0) && (_DAT_0099d098 == *(double *)(puVar2 + 8))) {
LAB_0091cc57:
          fVar15 = (float10)0;
        }
        else {
          fVar15 = (float10)1 / (float10)*(double *)(puVar2 + 8);
        }
      }
      else if (uVar13 == 0x10400000) {
        iVar7 = FUN_00803910(*(undefined8 *)(puVar2 + 8));
        if (iVar7 == 0) goto LAB_0091cc57;
        fVar15 = (float10)FUN_008044f0(*(undefined8 *)(puVar2 + 8));
        fVar15 = (float10)*(double *)(puVar2 + 8) - fVar15;
      }
      else if (uVar13 == 0x10500000) {
        fVar15 = (float10)FUN_00801f40();
      }
      else if (uVar13 == 0x10600000) {
        if ((uVar12 == 0) && (*(double *)(puVar2 + 8) == _DAT_0099d098)) {
          return 0;
        }
        if (*(double *)(puVar2 + 8) < 0.0) goto LAB_0091cc48;
        fVar15 = (float10)log2((float10)*(double *)(puVar2 + 8));
        fVar4 = (float10)log2((float10)_DAT_00a0b350);
        fVar15 = ((float10)0.6931471805599453 * fVar15) / ((float10)0.6931471805599453 * fVar4);
      }
      else {
        if (uVar13 != 0x10700000) {
          return 0;
        }
        if ((uVar12 == 0) && (*(double *)(puVar2 + 8) < 0.0)) {
LAB_0091cc48:
          FUN_0091a001();
          goto LAB_0091cc57;
        }
        fVar15 = (float10)_DAT_0099d0a0 / SQRT((float10)*(double *)(puVar2 + 8));
      }
    }
    else if (uVar13 == 0x10900000) {
      fVar15 = (float10)fcos((float10)*(double *)(puVar2 + 8));
    }
    else if (uVar13 == 0x10a00000) {
      if ((uVar12 == 0) &&
         ((*(double *)(puVar2 + 8) < _DAT_009fd350 || (_DAT_0099d0a0 < *(double *)(puVar2 + 8)))))
      goto LAB_0091cc48;
      fVar15 = (float10)FUN_00801e30();
    }
    else if (uVar13 == 0x10b00000) {
      if ((uVar12 == 0) &&
         ((*(double *)(puVar2 + 8) < _DAT_009fd350 || (_DAT_0099d0a0 < *(double *)(puVar2 + 8)))))
      goto LAB_0091cc48;
      fVar15 = (float10)FUN_00801d60();
    }
    else {
      if (uVar13 != 0x10c00000) {
        if ((uVar13 != 0x10d00000) && (uVar13 != 0x10e00000)) {
          return 0;
        }
        goto LAB_0091cc57;
      }
      fVar15 = (float10)fpatan((float10)*(double *)(puVar2 + 8),(float10)1);
    }
    dVar16 = (double)fVar15;
  }
LAB_0091d017:
  uVar10 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,dVar16);
LAB_0091d021:
  puVar1[0xc] = uVar10;
  return 0;
}


// ==== FUN_0091d02d @ 0x0091d02d ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0091d02d(uint *param_1,int param_2,int param_3,uint param_4)

{
  uint **ppuVar1;
  float10 fVar2;
  bool bVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  int *piVar7;
  uint *puVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  int in_ECX;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  ushort uVar18;
  float10 fVar19;
  undefined4 uVar20;
  double dVar21;
  undefined8 uVar22;
  undefined8 local_50;
  uint *local_48 [5];
  uint *local_34;
  uint *local_30;
  uint *local_2c;
  uint local_28;
  int local_24;
  uint *local_20;
  int local_1c;
  uint *local_18;
  uint *local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_2c = (uint *)*param_1;
  iVar10 = *(int *)(in_ECX + 0x14);
  puVar9 = *(uint **)(*(int *)(iVar10 + param_3 * 4) + 0x30);
  puVar5 = *(uint **)(*(int *)(iVar10 + param_4 * 4) + 0x30);
  puVar14 = *(uint **)(iVar10 + param_2 * 4);
  local_20 = *(uint **)(iVar10 + (int)puVar9 * 4);
  local_18 = *(uint **)(iVar10 + (int)puVar5 * 4);
  uVar12 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar14[1] * 4) + 4);
  if ((uVar12 & 1) == 0) {
    return 0;
  }
  if ((uVar12 & 0x1000) != 0) {
    return 0;
  }
  uVar12 = *local_20;
  uVar16 = *local_18;
  local_8 = uVar12 & 0x1f;
  local_c = uVar16 & 0x1f;
  uVar4 = *puVar14;
  local_28 = uVar4 & 0x40;
  if (((uVar4 & 0xe000000) == 0) &&
     (((((uVar15 = (uint)local_2c & 0xfff00000, uVar15 == 0x20000000 || (uVar15 == 0x20100000)) ||
        (uVar15 == 0x20400000)) || ((uVar15 == 0x20700000 || (uVar15 == 0x20800000)))) ||
      (uVar15 == 0x20900000)))) {
    uVar13 = uVar16 | uVar12;
    uVar15 = 0x8000000;
    if ((((uVar13 & 0x8000000) != 0) || (uVar15 = 0x4000000, (uVar13 & 0x4000000) != 0)) ||
       (uVar15 = 0x2000000, (uVar13 & 0x2000000) != 0)) {
      *puVar14 = uVar4 | uVar15;
    }
  }
  if (((*local_18 | *local_20) & 0x40) != 0) {
    uVar4 = (uint)local_2c & 0xfff00000;
    if (uVar4 < 0x20600001) {
      if ((((uVar4 == 0x20600000) || (uVar4 == 0x20000000)) || (uVar4 == 0x20100000)) ||
         ((uVar4 == 0x20400000 || (uVar4 == 0x20500000)))) goto LAB_0091d16c;
    }
    else if ((uVar4 == 0x20700000) || ((uVar4 == 0x20800000 || (uVar4 == 0x20900000)))) {
LAB_0091d16c:
      *puVar14 = *puVar14 | 0x40;
    }
  }
  local_10 = (uint)local_2c & 0xfff00000;
  if (local_10 < 0x20400001) {
    if (local_10 == 0x20400000) {
      uVar4 = local_c & local_8 & 0xe;
    }
    else if (local_10 == 0x20000000) {
      uVar4 = (local_8 | 8) & local_c | uVar12 & 8;
    }
    else {
      if (local_10 != 0x20100000) {
        if ((local_10 == 0x20200000) || (local_10 == 0x20300000)) {
          *puVar14 = *puVar14 | 0x17;
        }
        goto LAB_0091d2ff;
      }
      uVar4 = (local_8 | 4) & local_c | uVar12 & 4;
    }
LAB_0091d1fd:
    *puVar14 = *puVar14 | uVar4;
  }
  else if (local_10 == 0x20500000) {
    *puVar14 = *puVar14 | local_c & local_8 & 3;
    local_48[4] = (uint *)(uVar12 & 4);
    if (((local_48[4] != (uint *)0x0) && ((uVar16 & 4) != 0)) ||
       (((uVar12 & 8) != 0 && ((uVar16 & 8) != 0)))) {
      *puVar14 = *puVar14 | 4;
    }
    if (((local_48[4] != (uint *)0x0) && ((uVar16 & 8) != 0)) ||
       (((uVar12 & 8) != 0 && ((uVar16 & 4) != 0)))) {
      *puVar14 = *puVar14 | 8;
    }
    if (local_20 == local_18) {
      *puVar14 = *puVar14 | 4;
    }
    else if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + local_20[1] * 4) + 4) & 2) == 0) ||
            (puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) + local_20[0x12] * 4),
            (*puVar6 & 0xfff00000) != 0x10100000)) {
      if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + local_18[1] * 4) + 4) & 2) != 0) &&
         ((puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) + local_18[0x12] * 4),
          (*puVar6 & 0xfff00000) == 0x10100000 && (uVar4 = 0, puVar6[3] != 0)))) {
        puVar8 = (uint *)puVar6[4];
        do {
          if ((uint *)*puVar8 == puVar5) break;
          uVar4 = uVar4 + 1;
          puVar8 = puVar8 + 1;
        } while (uVar4 < puVar6[3]);
        if (uVar4 < puVar6[3]) {
          bVar17 = *(uint **)(puVar6[2] + uVar4 * 4) == puVar9;
          goto LAB_0091d2fa;
        }
      }
    }
    else {
      uVar4 = 0;
      if (puVar6[3] != 0) {
        puVar8 = (uint *)puVar6[4];
        do {
          if ((uint *)*puVar8 == puVar9) break;
          uVar4 = uVar4 + 1;
          puVar8 = puVar8 + 1;
        } while (uVar4 < puVar6[3]);
        if (uVar4 < puVar6[3]) {
          bVar17 = *(uint **)(puVar6[2] + uVar4 * 4) == puVar5;
LAB_0091d2fa:
          if (bVar17) {
            *puVar14 = *puVar14 | 8;
          }
        }
      }
    }
  }
  else if (((local_10 == 0x20700000) || (local_10 == 0x20800000)) || (local_10 == 0x20900000)) {
    uVar4 = local_c & local_8;
    goto LAB_0091d1fd;
  }
LAB_0091d2ff:
  local_14 = puVar14;
  if (local_28 != 0) goto LAB_0091d37b;
  if (((uVar12 & 4) != 0) && ((uVar16 & 8) != 0)) {
    if (local_10 == 0x20000000) goto LAB_0091da92;
    if (local_10 == 0x20100000) goto LAB_0091d34d;
    if (local_10 == 0x20200000) {
      dVar21 = 0.0;
    }
    else {
      if (local_10 != 0x20300000) goto LAB_0091d35d;
      dVar21 = 1.0;
    }
LAB_0091d33a:
    puVar5 = (uint *)FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,dVar21);
LAB_0091da92:
    puVar14[0xc] = (uint)puVar5;
    return 0;
  }
LAB_0091d35d:
  if (((uVar12 & 8) != 0) && ((uVar16 & 4) != 0)) {
    if (local_10 != 0x20000000) {
      if (local_10 == 0x20100000) goto LAB_0091da92;
      goto LAB_0091d37b;
    }
LAB_0091d34d:
    puVar5 = puVar9;
    goto LAB_0091da92;
  }
LAB_0091d37b:
  local_24 = *(int *)(in_ECX + 0x10);
  local_48[4] = *(uint **)(*(int *)(local_24 + local_20[1] * 4) + 4);
  uVar4 = (uint)local_48[4] & 0x100;
  if ((((uVar4 != 0) && (local_20[2] == 0xffffffff)) &&
      ((*(uint *)(*(int *)(local_24 + local_18[1] * 4) + 4) & 0x100) != 0)) &&
     (local_18[2] == 0xffffffff)) {
    fVar19 = (float10)*(double *)(local_20 + 8);
    dVar21 = *(double *)(local_18 + 8);
    if (local_10 == 0x20000000) {
      if ((float10)dVar21 <= fVar19) {
LAB_0091d45b:
        fVar19 = (float10)dVar21;
      }
    }
    else {
      if (local_10 != 0x20100000) {
        if (local_10 == 0x20200000) {
          if (fVar19 < (float10)dVar21) goto LAB_0091d65e;
        }
        else {
          if (local_10 != 0x20300000) {
            if (local_10 == 0x20400000) {
              fVar19 = fVar19 + (float10)dVar21;
            }
            else if (local_10 == 0x20500000) {
              fVar19 = fVar19 * (float10)dVar21;
            }
            else {
              if (local_10 != 0x20600000) {
                return 0;
              }
              fVar19 = (float10)fpatan(fVar19,(float10)dVar21);
            }
            goto LAB_0091d460;
          }
          if ((float10)dVar21 <= fVar19) goto LAB_0091d65e;
        }
        goto LAB_0091d532;
      }
      if (fVar19 < (float10)dVar21) goto LAB_0091d45b;
    }
    goto LAB_0091d460;
  }
  if ((local_28 == 0) &&
     (((uVar4 != 0 && (local_20[2] == 0xffffffff)) ||
      (((*(uint *)(*(int *)(local_24 + local_18[1] * 4) + 4) & 0x100) != 0 &&
       (local_18[2] == 0xffffffff)))))) {
    if ((uVar4 == 0) || (local_20[2] != 0xffffffff)) {
      dVar21 = *(double *)(local_18 + 8);
      uVar12 = local_8;
      puVar6 = puVar9;
    }
    else {
      dVar21 = *(double *)(local_20 + 8);
      uVar12 = local_c;
      puVar6 = puVar5;
    }
    fVar19 = (float10)dVar21;
    if (local_10 == 0x20000000) {
      if (((float10)_DAT_0099d0a0 <= fVar19) && ((uVar12 & 1) != 0)) goto LAB_0091d77a;
      fVar2 = (float10)_DAT_0099d098;
      if ((NAN(fVar19) || NAN(fVar2)) || fVar19 < fVar2 == (fVar19 == fVar2)) {
        return 0;
      }
      if ((uVar12 & 4) == 0) {
        return 0;
      }
    }
    else {
      if (local_10 != 0x20100000) {
        if (local_10 == 0x20200000) {
          fVar2 = (float10)_DAT_0099d098;
          if (puVar6 == puVar5) {
            if ((fVar19 >= fVar2) || ((uVar12 & 4) == 0)) {
              if (((float10)_DAT_0099d098 <= fVar19) && ((uVar12 & 8) != 0)) goto LAB_0091d532;
              dVar21 = _DAT_0099d098;
              if ((float10)_DAT_0099d0a0 <= fVar19) {
joined_r0x0091d687:
                if ((uVar12 & 1) != 0) goto LAB_0091d532;
              }
LAB_0091d68f:
              if (fVar19 != (float10)dVar21) {
                return 0;
              }
              uVar12 = uVar12 & 1;
              goto LAB_0091d6a3;
            }
          }
          else {
            if (((!NAN(fVar19) && !NAN(fVar2)) && fVar19 < fVar2 != (fVar19 == fVar2)) &&
               ((uVar12 & 4) != 0)) goto LAB_0091d532;
            if ((fVar19 <= (float10)_DAT_0099d098) || ((uVar12 & 8) == 0)) {
              uVar18 = (ushort)(fVar19 < (float10)_DAT_0099d0a0) << 8 |
                       (ushort)(fVar19 == (float10)_DAT_0099d0a0) << 0xe;
LAB_0091d723:
              if (uVar18 != 0) {
                return 0;
              }
              if ((uVar12 & 1) == 0) {
                return 0;
              }
            }
          }
          goto LAB_0091d65e;
        }
        if (local_10 == 0x20300000) {
          fVar2 = (float10)_DAT_0099d098;
          if (puVar6 == puVar5) {
            if ((fVar19 >= fVar2) || ((uVar12 & 4) == 0)) {
              if ((fVar19 < (float10)_DAT_0099d098) || ((uVar12 & 8) == 0)) {
                uVar18 = (ushort)(fVar19 < (float10)_DAT_0099d0a0) << 8;
                goto LAB_0091d723;
              }
              goto LAB_0091d65e;
            }
          }
          else {
            if (((!NAN(fVar19) && !NAN(fVar2)) && fVar19 < fVar2 != (fVar19 == fVar2)) &&
               ((uVar12 & 4) != 0)) {
LAB_0091d65e:
              fVar19 = (float10)1;
              goto LAB_0091d460;
            }
            if ((fVar19 <= (float10)_DAT_0099d098) || ((uVar12 & 8) == 0)) {
              dVar21 = _DAT_0099d0a0;
              if ((float10)_DAT_0099d0a0 < fVar19) goto joined_r0x0091d687;
              goto LAB_0091d68f;
            }
          }
          goto LAB_0091d532;
        }
        if (local_10 == 0x20400000) {
          if (fVar19 != (float10)_DAT_0099d098) {
            return 0;
          }
          goto LAB_0091d77a;
        }
        if (local_10 != 0x20500000) {
          if (local_10 != 0x20600000) {
            return 0;
          }
          if (fVar19 != (float10)_DAT_0099d098) {
            return 0;
          }
          if (puVar6 != puVar9) {
            return 0;
          }
LAB_0091d532:
          fVar19 = (float10)0;
          goto LAB_0091d460;
        }
        if (fVar19 == (float10)_DAT_0099d098) goto LAB_0091d532;
        if (fVar19 == (float10)_DAT_0099d0a0) goto LAB_0091d77a;
        if (fVar19 != (float10)_DAT_00a011c0) {
          return 0;
        }
        iVar10 = *(int *)(in_ECX + 0x14);
        iVar11 = *(int *)(iVar10 + (int)puVar6 * 4);
        if ((*(byte *)(*(int *)(local_24 + *(int *)(iVar11 + 4) * 4) + 4) & 2) == 0) {
          return 0;
        }
        puVar9 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar11 + 0x48) * 4);
        if ((*puVar9 & 0xfff00000) != 0x20400000) {
          return 0;
        }
        uVar12 = puVar9[3];
        uVar16 = 0;
        if (uVar12 != 0) {
          puVar5 = (uint *)puVar9[4];
          do {
            if ((uint *)*puVar5 == puVar6) break;
            uVar16 = uVar16 + 1;
            puVar5 = puVar5 + 1;
          } while (uVar16 < uVar12);
        }
        if (uVar12 <= uVar16) {
          return 0;
        }
        uVar4 = puVar9[2];
        if (*(int *)(uVar4 + uVar16 * 4) != *(int *)(uVar4 + (uVar12 + uVar16) * 4)) {
          return 0;
        }
        iVar11 = *(int *)(uVar16 * 4 + uVar4);
LAB_0091d5ee:
        puVar5 = *(uint **)(*(int *)(iVar10 + iVar11 * 4) + 0x30);
        goto LAB_0091df9b;
      }
      if ((fVar19 < (float10)_DAT_0099d0a0) || ((uVar12 & 1) == 0)) {
        fVar2 = (float10)_DAT_0099d098;
        if ((NAN(fVar19) || NAN(fVar2)) || fVar19 < fVar2 == (fVar19 == fVar2)) {
          return 0;
        }
        uVar12 = uVar12 & 4;
LAB_0091d6a3:
        if (uVar12 == 0) {
          return 0;
        }
LAB_0091d77a:
        puVar14[0xc] = (uint)puVar6;
        return 0;
      }
    }
LAB_0091d460:
    dVar21 = (double)fVar19;
    goto LAB_0091d33a;
  }
  if (local_20 == local_18) {
    if ((local_10 != 0x20000000) && (local_10 != 0x20100000)) {
      if (local_10 == 0x20200000) {
        if (local_28 != 0) {
          return 0;
        }
LAB_0091d89d:
        dVar21 = 0.0;
        goto LAB_0091d33a;
      }
      if (local_10 == 0x20300000) {
        if (local_28 != 0) {
          return 0;
        }
        dVar21 = 1.0;
        goto LAB_0091d33a;
      }
      if ((local_10 != 0x20500000) || ((uVar12 & 1) == 0)) goto LAB_0091d7ec;
    }
    goto LAB_0091d34d;
  }
LAB_0091d7ec:
  uVar12 = 0;
  if (local_28 != 0) {
    return 0;
  }
  uVar4 = 0;
  if (local_10 == 0x20400000) {
    if ((((*(byte *)(*(int *)(local_24 + local_18[1] * 4) + 4) & 2) != 0) &&
        (puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) + local_18[0x12] * 4),
        (*puVar6 & 0xfff00000) == 0x10100000)) && (puVar6[3] != 0)) {
      puVar8 = (uint *)puVar6[4];
      do {
        if ((uint *)*puVar8 == puVar5) break;
        uVar12 = uVar12 + 1;
        puVar8 = puVar8 + 1;
      } while (uVar12 < puVar6[3]);
      if ((uVar12 < puVar6[3]) && (puVar9 == *(uint **)(puVar6[2] + uVar12 * 4))) goto LAB_0091d89d;
    }
    if ((((uint)local_48[4] & 2) != 0) &&
       ((puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) + local_20[0x12] * 4),
        (*puVar6 & 0xfff00000) == 0x10100000 && (uVar12 = 0, puVar6[3] != 0)))) {
      puVar8 = (uint *)puVar6[4];
      do {
        if ((uint *)*puVar8 == puVar9) break;
        uVar12 = uVar12 + 1;
        puVar8 = puVar8 + 1;
      } while (uVar12 < puVar6[3]);
      if ((uVar12 < puVar6[3]) && (puVar5 == *(uint **)(puVar6[2] + uVar12 * 4))) goto LAB_0091d89d;
    }
    local_8 = 0;
    local_28 = 0;
    do {
      if ((local_8 & 4) == 0) {
        local_2c = puVar5;
        local_30 = puVar9;
      }
      else {
        local_2c = puVar9;
        local_30 = puVar5;
      }
      local_48[1] = (uint *)(local_8 & 2);
      if (local_48[1] == (uint *)0x0) {
LAB_0091d964:
        iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_30 * 4);
        if (((*(byte *)(*(int *)(local_24 + *(int *)(iVar10 + 4) * 4) + 4) & 2) != 0) &&
           (puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar10 + 0x48) * 4),
           (*puVar6 & 0xfff00000) == 0x20400000)) {
          uVar12 = puVar6[3];
          uVar4 = 0;
          if (uVar12 != 0) {
            puVar8 = (uint *)puVar6[4];
            do {
              if (local_30 == (uint *)*puVar8) {
                uVar15 = puVar6[2];
                if ((local_8 & 1) == 0) {
                  iVar10 = *(int *)(uVar15 + (uVar4 + uVar12) * 4);
                }
                else {
                  iVar10 = *(int *)(uVar15 + uVar4 * 4);
                  uVar4 = uVar4 + uVar12;
                }
                local_48[4] = *(uint **)(*(int *)(*(int *)(in_ECX + 0x14) + iVar10 * 4) + 0x30);
                local_50 = (ulonglong)
                           *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                             *(int *)(uVar15 + uVar4 * 4) * 4) + 0x30) << 0x20;
                break;
              }
              uVar4 = uVar4 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar4 < uVar12);
          }
          if (local_48[1] == (uint *)0x0) {
            iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_48[4] * 4);
            if (((*(byte *)(*(int *)(local_24 + *(int *)(iVar10 + 4) * 4) + 4) & 2) == 0) ||
               (puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar10 + 0x48) * 4),
               (*puVar6 & 0xfff00000) != 0x10100000)) goto LAB_0091da55;
            uVar12 = 0;
            if (puVar6[3] != 0) {
              puVar8 = (uint *)puVar6[4];
              do {
                if (local_48[4] == (uint *)*puVar8) {
                  local_48[4] = *(uint **)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                   *(int *)(puVar6[2] + uVar12 * 4) * 4) + 0x30);
                  break;
                }
                uVar12 = uVar12 + 1;
                puVar8 = puVar8 + 1;
              } while (uVar12 < puVar6[3]);
            }
          }
          if (local_2c == local_48[4]) {
            puVar5 = local_50._4_4_;
            goto LAB_0091da92;
          }
        }
      }
      else {
        iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_2c * 4);
        if (((*(byte *)(*(int *)(local_24 + *(int *)(iVar10 + 4) * 4) + 4) & 2) != 0) &&
           (puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar10 + 0x48) * 4),
           (*puVar6 & 0xfff00000) == 0x10100000)) {
          local_28 = 0;
          if (puVar6[3] != 0) {
            puVar8 = (uint *)puVar6[4];
            do {
              if (local_2c == (uint *)*puVar8) {
                local_2c = *(uint **)(*(int *)(*(int *)(in_ECX + 0x14) +
                                              *(int *)(puVar6[2] + local_28 * 4) * 4) + 0x30);
                break;
              }
              local_28 = local_28 + 1;
              puVar8 = puVar8 + 1;
              local_48[3] = puVar8;
            } while (local_28 < puVar6[3]);
          }
          goto LAB_0091d964;
        }
      }
LAB_0091da55:
      local_8 = local_8 + 1;
      uVar4 = local_28;
    } while (local_8 < 8);
  }
  local_28 = uVar4;
  if (local_10 == 0x20500000) {
    uVar12 = 0;
    local_48[0] = puVar9;
    local_48[1] = puVar5;
    local_30 = (uint *)0x0;
    local_34 = (uint *)0x0;
    local_48[3] = (uint *)0x0;
    local_48[2] = (uint *)0x0;
    do {
      iVar10 = *(int *)((int)local_48 + uVar12);
      while (iVar11 = *(int *)(*(int *)(in_ECX + 0x14) + iVar10 * 4),
            (*(byte *)(*(int *)(local_24 + *(int *)(iVar11 + 4) * 4) + 4) & 2) != 0) {
        puVar14 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar11 + 0x48) * 4);
        if ((*puVar14 & 0xfff00000) == 0x10100000) {
          ppuVar1 = &local_34;
        }
        else {
          if ((*puVar14 & 0xfff00000) != 0x10300000) break;
          ppuVar1 = local_48 + 2;
        }
        *(uint *)((int)ppuVar1 + uVar12) = (uint)(*(uint *)((int)ppuVar1 + uVar12) == 0);
        local_48[4] = (uint *)puVar14[3];
        puVar6 = (uint *)0x0;
        if (local_48[4] != (uint *)0x0) {
          piVar7 = (int *)puVar14[4];
          do {
            if (*piVar7 == iVar10) {
              iVar10 = *(int *)(puVar14[2] + (int)puVar6 * 4);
              break;
            }
            puVar6 = (uint *)((int)puVar6 + 1);
            piVar7 = piVar7 + 1;
          } while (puVar6 < local_48[4]);
        }
        if (local_48[4] <= puVar6) {
          return 0x80004005;
        }
      }
      *(int *)((int)local_48 + uVar12) = iVar10;
      uVar12 = uVar12 + 4;
    } while (uVar12 < 8);
    if ((local_48[0] != local_48[1]) || (local_48[2] == local_48[3])) goto LAB_0091db60;
    if (local_34 == local_30) {
      uVar22 = 0x3ff0000000000000;
    }
    else {
      uVar22 = _DAT_009fd350;
    }
    uVar20 = *(undefined4 *)(in_ECX + 0x78);
  }
  else {
LAB_0091db60:
    if ((((local_10 == 0x20200000) &&
         (iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + (int)puVar9 * 4),
         (*(byte *)(*(int *)(local_24 + *(int *)(iVar10 + 4) * 4) + 4) & 2) != 0)) &&
        ((uVar16 & 1) != 0)) &&
       (puVar14 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar10 + 0x48) * 4),
       (*puVar14 & 0xfff00000) == 0x10100000)) {
      uVar12 = 0;
      if (puVar14[3] != 0) {
        puVar6 = (uint *)puVar14[4];
        do {
          if ((uint *)*puVar6 == puVar9) break;
          uVar12 = uVar12 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar12 < puVar14[3]);
      }
      if (*(uint **)(puVar14[2] + uVar12 * 4) == puVar5) goto LAB_0091df9b;
    }
    iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + (int)puVar9 * 4);
    if ((*(byte *)(*(int *)(local_24 + *(int *)(iVar10 + 4) * 4) + 4) & 2) == 0) {
      return 0;
    }
    if ((*(byte *)(*(int *)(local_24 +
                           *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)puVar5 * 4) + 4) * 4) +
                  4) & 2) == 0) {
      return 0;
    }
    if (((local_10 == 0x20500000) || (local_10 == 0x20200000)) || (local_10 == 0x20300000)) {
      puVar14 = *(uint **)(*(int *)(in_ECX + 0x18) +
                          *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)puVar9 * 4) + 0x48) * 4);
      puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) +
                         *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)puVar5 * 4) + 0x48) * 4);
      if (((*puVar14 & 0xfff00000) == 0x10100000) && ((*puVar6 & 0xfff00000) == 0x10100000)) {
        local_2c = (uint *)0x0;
        if (param_1[3] != 0) {
          piVar7 = (int *)param_1[4];
          do {
            if (param_2 == *piVar7) break;
            local_2c = (uint *)((int)local_2c + 1);
            piVar7 = piVar7 + 1;
          } while (local_2c < param_1[3]);
        }
        uVar12 = 0;
        if (puVar14[3] != 0) {
          puVar8 = (uint *)puVar14[4];
          do {
            if (puVar9 == (uint *)*puVar8) break;
            uVar12 = uVar12 + 1;
            puVar8 = puVar8 + 1;
          } while (uVar12 < puVar14[3]);
        }
        uVar16 = 0;
        if (puVar6[3] != 0) {
          puVar9 = (uint *)puVar6[4];
          do {
            if (puVar5 == (uint *)*puVar9) break;
            uVar16 = uVar16 + 1;
            puVar9 = puVar9 + 1;
          } while (uVar16 < puVar6[3]);
        }
        if (local_10 == 0x20500000) {
          iVar10 = *(int *)(puVar14[2] + uVar12 * 4);
          iVar11 = *(int *)(puVar6[2] + uVar16 * 4);
        }
        else {
          iVar10 = *(int *)(puVar6[2] + uVar16 * 4);
          iVar11 = *(int *)(puVar14[2] + uVar12 * 4);
        }
        *(undefined4 *)(param_1[2] + (int)local_2c * 4) =
             *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar10 * 4) + 0x30);
        *(undefined4 *)(param_1[2] + (param_1[3] + (int)local_2c) * 4) =
             *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4) + 0x30);
        return 0;
      }
    }
    if (local_10 != 0x20500000) {
      return 0;
    }
    if (puVar9 == puVar5) {
      puVar14 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar10 + 0x48) * 4);
      uVar12 = *puVar14 & 0xfff00000;
      if ((uVar12 == 0x10300000) || (uVar12 == 0x10700000)) {
        uVar16 = 0;
        if (puVar14[3] != 0) {
          puVar6 = (uint *)puVar14[4];
          do {
            if ((uint *)*puVar6 == puVar9) break;
            uVar16 = uVar16 + 1;
            puVar6 = puVar6 + 1;
          } while (uVar16 < puVar14[3]);
        }
        iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(uVar16 * 4 + puVar14[2]) * 4);
        if (((*(byte *)(*(int *)(local_24 + *(int *)(iVar10 + 4) * 4) + 4) & 2) != 0) &&
           (*(int *)(iVar10 + 8) == -1)) {
          puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar10 + 0x48) * 4);
          uVar4 = *puVar6 & 0xfff00000;
          if (((uVar4 == 0x10300000) || (uVar4 == 0x10700000)) && (uVar12 != uVar4)) {
            param_4 = 0;
            if (puVar6[3] != 0) {
              uVar12 = puVar6[4];
              do {
                *(undefined4 *)(uVar12 + param_4 * 4) = *(undefined4 *)(uVar16 * 4 + puVar14[2]);
                uVar12 = puVar6[4];
                if (*(int *)(uVar12 + param_4 * 4) != 0) break;
                param_4 = param_4 + 1;
              } while (param_4 < puVar6[3]);
            }
            iVar11 = *(int *)(puVar6[2] + param_4 * 4);
            iVar10 = *(int *)(in_ECX + 0x14);
            goto LAB_0091d5ee;
          }
        }
      }
    }
    local_50._4_4_ = (uint *)(*local_20 & 1);
    local_1c = in_ECX;
    if (((*local_20 & 1) != 0) && (iVar10 = FUN_009169c8(puVar9,puVar5), iVar10 != 0)) {
      goto LAB_0091df9b;
    }
    local_48[3] = (uint *)(*local_18 & 1);
    if ((local_48[3] != (uint *)0x0) && (iVar10 = FUN_009169c8(puVar5,puVar9), iVar10 != 0)) {
      local_14[0xc] = (uint)puVar9;
      return 0;
    }
    bVar17 = false;
    bVar3 = false;
    local_2c = (uint *)0x1;
    local_28 = 1;
    uVar12 = local_14[6];
    uVar16 = local_14[5];
    if (uVar16 == 0xffffffff) {
      return 0;
    }
    do {
      local_48[4] = (uint *)(uVar16 * 4);
      iVar10 = *(int *)(*(int *)(local_1c + 0x18) +
                       *(int *)(*(int *)((int)local_48[4] + *(int *)(local_1c + 0x14)) + 0x48) * 4);
      uVar4 = 0;
      if (*(uint *)(iVar10 + 0xc) != 0) {
        puVar14 = *(uint **)(iVar10 + 0x10);
        do {
          if (*puVar14 == uVar16) break;
          uVar4 = uVar4 + 1;
          puVar14 = puVar14 + 1;
        } while (uVar4 < *(uint *)(iVar10 + 0xc));
      }
      if (local_50._4_4_ != (uint *)0x0) {
        local_48[1] = *(uint **)(*(int *)(iVar10 + 8) + uVar4 * 4);
        uVar16 = FUN_009169c8(puVar9,local_48[1]);
        if ((uVar12 & uVar16) != 0) {
          bVar17 = true;
        }
        if ((uVar12 == 0) && (iVar11 = FUN_009169c8(local_48[1],puVar9), iVar11 != 0)) {
          local_2c = (uint *)0x0;
          bVar17 = true;
        }
      }
      if (local_48[3] == (uint *)0x0) {
        iVar10 = local_1c;
      }
      else {
        uVar20 = *(undefined4 *)(*(int *)(iVar10 + 8) + uVar4 * 4);
        uVar16 = FUN_009169c8(puVar5,uVar20);
        iVar10 = local_1c;
        if ((uVar12 & uVar16) != 0) {
          bVar3 = true;
        }
        if (uVar12 == 0) {
          iVar11 = FUN_009169c8(uVar20,puVar5);
          if (iVar11 != 0) {
            local_28 = 0;
            bVar3 = true;
          }
        }
      }
      iVar11 = *(int *)(*(int *)(iVar10 + 0x14) + (int)local_48[4]);
      uVar12 = *(uint *)(iVar11 + 0x18);
      uVar16 = *(uint *)(iVar11 + 0x14);
    } while (uVar16 != 0xffffffff);
    if (bVar17) {
      if (!bVar3) {
LAB_0091df55:
        if (local_2c != (uint *)0x0) goto LAB_0091df5a;
        goto LAB_0091df64;
      }
      if (local_2c == (uint *)0x0) goto LAB_0091df64;
      if (local_28 == 0) goto LAB_0091df55;
      uVar22 = 0x3ff0000000000000;
    }
    else {
LAB_0091df5a:
      if ((!bVar3) || (local_28 != 0)) {
        if ((bVar17) && (local_2c != (uint *)0x0)) {
          local_14[0xc] = (uint)puVar5;
          return 0;
        }
        if (!bVar3) {
          return 0;
        }
        if (local_28 == 0) {
          return 0;
        }
        puVar5 = puVar9;
        goto LAB_0091df9b;
      }
LAB_0091df64:
      uVar22 = 0;
    }
    uVar20 = *(undefined4 *)(iVar10 + 0x78);
  }
  puVar5 = (uint *)FUN_00915318(uVar20,0,0,uVar22);
LAB_0091df9b:
  local_14[0xc] = (uint)puVar5;
  return 0;
}


// ==== FUN_0091dfaa @ 0x0091dfaa ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0091dfaa(uint *param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  int *piVar7;
  uint *puVar8;
  int iVar9;
  int in_ECX;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  undefined1 local_a4 [8];
  uint *local_9c;
  int *local_94;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24;
  byte *local_20;
  int *local_1c;
  int local_18;
  int local_14;
  uint *local_10;
  int *local_c;
  uint *local_8;
  
  iVar9 = *(int *)(in_ECX + 0x14);
  piVar13 = *(int **)(*(int *)(iVar9 + param_3 * 4) + 0x30);
  piVar1 = *(int **)(*(int *)(iVar9 + param_4 * 4) + 0x30);
  local_20 = *(byte **)(iVar9 + (int)piVar13 * 4);
  local_10 = *(uint **)(iVar9 + (int)piVar1 * 4);
  piVar2 = *(int **)(*(int *)(iVar9 + param_5 * 4) + 0x30);
  puVar3 = *(uint **)(iVar9 + param_2 * 4);
  puVar8 = *(uint **)(iVar9 + (int)piVar2 * 4);
  uVar12 = *puVar3;
  uVar10 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar3[1] * 4) + 4);
  if ((uVar10 & 1) == 0) {
    return 0;
  }
  if ((uVar10 & 0x1000) != 0) {
    return 0;
  }
  if (((uVar12 & 0xe000000) != 0) || ((*param_1 & 0xfff00000) != 0x30000000)) goto LAB_0091e080;
  uVar10 = *puVar8 | *local_10;
  if ((uVar10 & 0x8000000) == 0) {
    if ((uVar10 & 0x4000000) != 0) {
      uVar10 = uVar12 | 0x4000000;
      goto LAB_0091e070;
    }
    if ((uVar10 & 0x2000000) != 0) {
      uVar10 = uVar12 | 0x2000000;
      goto LAB_0091e070;
    }
  }
  else {
    uVar10 = uVar12 | 0x8000000;
LAB_0091e070:
    *puVar3 = uVar10;
  }
  *puVar3 = *puVar3 | *puVar8 & *local_10 & 0x1f;
LAB_0091e080:
  if ((((*puVar8 | *local_10) & 0x40) != 0) && ((*param_1 & 0xfff00000) == 0x30000000)) {
    *puVar3 = *puVar3 | 0x40;
  }
  if ((*param_1 & 0xfff00000) == 0x30000000) {
    *puVar3 = *puVar3 | *puVar8 & *local_10 & 0x1f;
    if ((piVar13 == piVar1) && ((*puVar8 & 4) != 0)) {
      *puVar3 = *puVar3 | 4;
    }
    if ((piVar13 == piVar2) && ((*local_10 & 8) != 0)) {
      *puVar3 = *puVar3 | 8;
    }
  }
  if ((*param_1 & 0xfff00000) != 0x30000000) {
    return 0;
  }
  piVar7 = piVar1;
  if (((uVar12 & 0x40) != 0) || ((*local_20 & 4) == 0)) {
    uVar10 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(local_20 + 4) * 4) + 4);
    if (((uVar10 & 0x100) == 0) || (*(int *)(local_20 + 8) != -1)) {
      if (piVar1 != piVar2) {
        uVar11 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + local_10[1] * 4) + 4) & 0x100;
        if ((((uVar11 == 0) || (local_10[2] != 0xffffffff)) ||
            ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar8[1] * 4) + 5) & 1) == 0)) ||
           ((puVar8[2] != 0xffffffff || (*(double *)(local_10 + 8) != *(double *)(puVar8 + 8))))) {
          if ((uVar12 & 0x40) != 0) {
            return 0;
          }
          if (((((*(int *)(local_20 + 8) == -1) && ((uVar10 & 2) != 0)) &&
               ((puVar4 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(local_20 + 0x48) * 4),
                (*puVar4 & 0xfff00000) == 0x10100000 &&
                (((uVar11 != 0 && (local_10[2] == 0xffffffff)) &&
                 (_DAT_0099d098 == *(double *)(local_10 + 8))))))) &&
              (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar8[1] * 4) + 5) & 1) != 0 &&
               (puVar8[2] == 0xffffffff)))) && (_DAT_0099d0a0 == *(double *)(puVar8 + 8))) {
            uVar12 = 0;
            if (puVar4[3] != 0) {
              local_8 = (uint *)puVar4[4];
              do {
                if ((int *)*local_8 == piVar13) break;
                local_8 = local_8 + 1;
                uVar12 = uVar12 + 1;
              } while (uVar12 < puVar4[3]);
            }
            uVar12 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                       *(int *)(puVar4[2] + uVar12 * 4) * 4) + 0x30);
            if ((**(byte **)(*(int *)(in_ECX + 0x14) + uVar12 * 4) & 1) != 0) {
              puVar3[0xc] = uVar12;
              return 0;
            }
          }
          if (*(int *)(local_20 + 8) != -1) {
            return 0;
          }
          local_24 = in_ECX;
          if ((uVar10 & 2) != 0) {
            puVar4 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(local_20 + 0x48) * 4);
            if (((((*puVar4 & 0xfff00000) == 0x20500000) && (uVar11 != 0)) &&
                ((local_10[2] == 0xffffffff &&
                 (((_DAT_0099d098 == *(double *)(local_10 + 8) &&
                   ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar8[1] * 4) + 5) & 1) != 0)) &&
                  (puVar8[2] == 0xffffffff)))))) && (_DAT_0099d0a0 == *(double *)(puVar8 + 8))) {
              local_8 = (uint *)0x0;
              if (puVar4[3] != 0) {
                puVar6 = (uint *)puVar4[4];
                do {
                  if ((int *)*puVar6 == piVar13) break;
                  local_8 = (uint *)((int)local_8 + 1);
                  puVar6 = puVar6 + 1;
                } while (local_8 < puVar4[3]);
              }
              uVar12 = puVar4[3];
              iVar9 = *(int *)(in_ECX + 0x14);
              local_c = (int *)0x0;
              local_30 = uVar12 * 4;
              local_1c = (int *)(puVar4[2] + (int)local_8 * 4);
              local_8 = (uint *)(puVar4[2] + (uVar12 + (int)local_8) * 4);
              do {
                piVar7 = *(int **)(*(int *)(iVar9 + *local_1c * 4) + 0x30);
                local_24 = *(int *)(iVar9 + *(int *)(*(int *)(iVar9 + *local_8 * 4) + 0x30) * 4);
                if ((((**(byte **)(iVar9 + (int)piVar7 * 4) & 1) != 0) &&
                    ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(local_24 + 4) * 4) + 5)
                     & 1) != 0)) &&
                   ((*(int *)(local_24 + 8) == -1 && (*(double *)(local_24 + 0x20) < _DAT_0099d098))
                   )) goto LAB_0091e443;
                local_c = (int *)((int)local_c + 1);
                local_1c = local_1c + uVar12;
                local_8 = local_8 + -uVar12;
                local_2c = piVar7;
              } while (local_c < 2);
            }
          }
          if (*(int *)(local_20 + 8) != -1) {
            return 0;
          }
          if ((uVar10 & 2) == 0) {
            return 0;
          }
          puVar3 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(local_20 + 0x48) * 4);
          if ((*puVar3 & 0xfff00000) != 0x20400000) {
            return 0;
          }
          local_14 = -1;
          if (((uVar11 != 0) && (local_10[2] == 0xffffffff)) &&
             (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar8[1] * 4) + 5) & 1) != 0 &&
              (puVar8[2] == 0xffffffff)))) {
            if ((_DAT_0099d098 == *(double *)(local_10 + 8)) &&
               (_DAT_0099d0a0 == *(double *)(puVar8 + 8))) {
              local_14 = 0x20200001;
            }
            else if ((_DAT_0099d0a0 == *(double *)(local_10 + 8)) &&
                    (_DAT_0099d098 == *(double *)(puVar8 + 8))) {
              local_14 = 0x20300001;
            }
          }
          uVar12 = 0;
          if (puVar3[3] != 0) {
            puVar8 = (uint *)puVar3[4];
            do {
              if ((int *)*puVar8 == piVar13) break;
              uVar12 = uVar12 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar12 < puVar3[3]);
          }
          uVar10 = puVar3[3];
          param_3 = 0;
          local_28 = uVar10 * 4;
          local_1c = (int *)(puVar3[2] + uVar12 * 4);
          local_8 = (uint *)(puVar3[2] + (uVar10 + uVar12) * 4);
          do {
            iVar9 = *(int *)(in_ECX + 0x14);
            local_c = *(int **)(*(int *)(iVar9 + *local_1c * 4) + 0x30);
            iVar5 = *(int *)(*(int *)(iVar9 + *local_8 * 4) + 0x30);
            iVar9 = *(int *)(iVar9 + iVar5 * 4);
            if (((*(int *)(iVar9 + 8) == -1) &&
                ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar9 + 4) * 4) + 4) & 2) !=
                 0)) && (puVar3 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar9 + 0x48) * 4),
                        (*puVar3 & 0xfff00000) == 0x10100000)) {
              uVar12 = 0;
              if (puVar3[3] != 0) {
                piVar13 = (int *)puVar3[4];
                do {
                  if (*piVar13 == iVar5) break;
                  uVar12 = uVar12 + 1;
                  piVar13 = piVar13 + 1;
                  local_2c = piVar13;
                } while (uVar12 < puVar3[3]);
              }
              piVar13 = *(int **)(*(int *)(*(int *)(in_ECX + 0x14) +
                                          *(int *)(puVar3[2] + uVar12 * 4) * 4) + 0x30);
              local_18 = local_14;
              if (local_14 != -1) {
LAB_0091e584:
                FUN_0091455d();
                iVar9 = FUN_00914a42(local_18,2,1,0);
                if ((-1 < iVar9) && (iVar9 = FUN_00914593(param_1), -1 < iVar9)) {
                  *local_94 = param_2;
                  *local_9c = (uint)local_c;
                  local_9c[1] = (uint)piVar13;
                  iVar9 = FUN_0091d02d(local_a4,param_2,local_c,piVar13);
                }
                FUN_0095cf1d();
                return iVar9;
              }
              if ((piVar1 == piVar13) && (piVar2 == local_c)) {
                local_18 = 0x20000001;
                goto LAB_0091e584;
              }
              if ((piVar1 == local_c) && (piVar2 == piVar13)) {
                local_18 = 0x20100001;
                goto LAB_0091e584;
              }
            }
            local_1c = local_1c + uVar10;
            param_3 = param_3 + 1;
            local_8 = local_8 + -uVar10;
            if (1 < param_3) {
              return 0;
            }
          } while( true );
        }
      }
    }
    else if (*(double *)(local_20 + 0x20) < _DAT_0099d098) {
      piVar7 = piVar2;
    }
  }
LAB_0091e443:
  puVar3[0xc] = (uint)piVar7;
  return 0;
}


// ==== FUN_0091e5fd @ 0x0091e5fd ====

int FUN_0091e5fd(void)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int local_10;
  uint local_8;
  
  FUN_009198e4();
  uVar9 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + uVar9 * 4);
      iVar11 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar6 + 4) * 4);
      *(undefined4 *)(iVar6 + 0x40) = 0;
      if ((*(byte *)(iVar11 + 4) & 0x40) == 0) {
        *(undefined4 *)(iVar6 + 0xc) = 0xffffffff;
        *(undefined4 *)(iVar6 + 0x10) = 0xffffffff;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 8));
  }
  uVar9 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x18) + uVar9 * 4) + 0x24) = 0;
      iVar6 = uVar9 * 4;
      uVar9 = uVar9 + 1;
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x18) + iVar6) + 0x28) = 0;
    } while (uVar9 < *(uint *)(in_ECX + 0xc));
  }
  FUN_009198e4();
  uVar9 = *(uint *)(in_ECX + 0xc);
  uVar5 = uVar9;
  while( true ) {
    do {
      if (uVar5 == 0) {
        uVar5 = *(int *)(in_ECX + 0xc) - uVar9 >> 1;
        local_8 = 0;
        if (uVar5 != 0) {
          local_10 = uVar9 << 2;
          do {
            puVar8 = (undefined4 *)(local_10 + *(int *)(in_ECX + 0x18));
            uVar3 = *puVar8;
            *puVar8 = *(undefined4 *)
                       (*(int *)(in_ECX + 0x18) + -4 + (*(int *)(in_ECX + 0xc) - local_8) * 4);
            iVar6 = *(int *)(in_ECX + 0xc) - local_8;
            local_8 = local_8 + 1;
            *(undefined4 *)(*(int *)(in_ECX + 0x18) + -4 + iVar6 * 4) = uVar3;
            local_10 = local_10 + 4;
          } while (local_8 < uVar5);
        }
        uVar5 = 0;
        if (uVar9 != 0) {
          do {
            iVar6 = uVar5 * 4;
            uVar5 = uVar5 + 1;
            **(undefined4 **)(*(int *)(in_ECX + 0x18) + iVar6) = 0;
          } while (uVar5 < uVar9);
        }
        iVar6 = FUN_00915e19();
        if (-1 < iVar6) {
          uVar9 = 0;
          if (*(int *)(in_ECX + 4) != 0) {
            do {
              iVar6 = *(int *)(*(int *)(in_ECX + 0x10) + uVar9 * 4);
              if ((*(byte *)(iVar6 + 4) & 0x40) == 0) {
                *(undefined4 *)(iVar6 + 0x10) = 0;
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < *(uint *)(in_ECX + 4));
          }
          local_8 = 0;
          if (*(int *)(in_ECX + 0xc) != 0) {
            do {
              iVar6 = *(int *)(*(int *)(in_ECX + 0x18) + local_8 * 4);
              if ((((*(ushort *)(iVar6 + 2) & 0xfff0) != 0) && (*(int *)(iVar6 + 0xc) != 0)) &&
                 (iVar11 = *(int *)(*(int *)(in_ECX + 0x10) +
                                   *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                    **(int **)(iVar6 + 0x10) * 4) + 4) * 4),
                 (*(byte *)(iVar11 + 4) & 0x40) == 0)) {
                uVar9 = 0;
                if (*(int *)(iVar6 + 0xc) != 0) {
                  do {
                    iVar4 = *(int *)(*(int *)(in_ECX + 0x14) +
                                    *(int *)(*(int *)(iVar6 + 0x10) + uVar9 * 4) * 4);
                    uVar3 = *(undefined4 *)(iVar11 + 0x10);
                    *(uint *)(iVar4 + 0x10) = uVar9;
                    uVar9 = uVar9 + 1;
                    *(undefined4 *)(iVar4 + 0xc) = uVar3;
                  } while (uVar9 < *(uint *)(iVar6 + 0xc));
                }
                *(int *)(iVar11 + 0x10) = *(int *)(iVar11 + 0x10) + 1;
              }
              local_8 = local_8 + 1;
            } while (local_8 < *(uint *)(in_ECX + 0xc));
          }
          iVar6 = 0;
        }
        return iVar6;
      }
      uVar5 = uVar5 - 1;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
      uVar10 = *puVar1 & 0xfff00000;
    } while (uVar10 == 0);
    uVar2 = *(uint *)(in_ECX + 0xc);
    uVar7 = *puVar1 & 0xf0000000;
    if ((uVar7 < 0x10000000) || (0x40000000 < uVar7)) {
      if (uVar10 == 0x50000000) {
        iVar6 = FUN_00917870(puVar1);
      }
      else {
        iVar6 = FUN_00917d35(puVar1);
      }
    }
    else {
      iVar6 = FUN_00917482(puVar1);
    }
    if (iVar6 < 0) break;
    uVar7 = *(uint *)(in_ECX + 0xc);
    for (uVar10 = uVar2; uVar10 < uVar7; uVar10 = uVar10 + 1) {
      iVar6 = FUN_00917edb(*(undefined4 *)(*(int *)(in_ECX + 0x18) + uVar10 * 4));
      if (iVar6 < 0) {
        return iVar6;
      }
    }
    local_8 = uVar7 - uVar2 >> 1;
    if (local_8 != 0) {
      iVar11 = uVar2 << 2;
      iVar6 = uVar7 << 2;
      do {
        puVar8 = (undefined4 *)(iVar11 + *(int *)(in_ECX + 0x18));
        uVar3 = *puVar8;
        *puVar8 = *(undefined4 *)(iVar6 + -4 + *(int *)(in_ECX + 0x18));
        *(undefined4 *)(iVar6 + -4 + *(int *)(in_ECX + 0x18)) = uVar3;
        iVar11 = iVar11 + 4;
        iVar6 = iVar6 + -4;
        local_8 = local_8 - 1;
      } while (local_8 != 0);
    }
  }
  return iVar6;
}


// ==== FUN_0091e836 @ 0x0091e836 ====

void FUN_0091e836(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  int in_ECX;
  uint *puVar7;
  int *piVar8;
  int *piVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  bool bVar14;
  undefined8 uVar15;
  longlong lVar16;
  uint auStack_c4 [4];
  uint auStack_b4 [4];
  uint auStack_a4 [4];
  undefined1 local_94 [16];
  uint local_84 [4];
  uint local_74 [12];
  undefined4 *local_44;
  uint *local_40;
  int *local_3c;
  uint *local_38;
  uint *local_34;
  uint *local_30;
  uint local_2c;
  uint *local_28;
  uint *local_24;
  uint local_20;
  uint *local_1c;
  uint *local_18;
  uint *local_14;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  local_8 = (uint *)0x0;
  FUN_009198e4();
  local_28 = (uint *)0x0;
  local_44 = (undefined4 *)0x0;
  if (*(int *)(in_ECX + 8) != 0) {
    piVar8 = *(int **)(in_ECX + 0x14);
    iVar12 = *(int *)(in_ECX + 8);
    do {
      if ((*(int *)(in_ECX + 0x88) == *(int *)(*piVar8 + 4)) &&
         (puVar7 = *(uint **)(*piVar8 + 0xc), local_28 <= puVar7)) {
        local_28 = (uint *)((int)puVar7 + 1);
      }
      piVar8 = piVar8 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  if (((*(byte *)(in_ECX + 0x6c) & 0x20) == 0) &&
     (local_1c = (uint *)0x0, *(int *)(in_ECX + 0xc) != 0)) {
    do {
      local_10 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_1c * 4);
      if (*local_10 == 0x50000002) {
        iVar12 = FUN_00915378(0x20500002,0xffffffff,0xffffffff);
        if (iVar12 == -1) goto LAB_0091fe11;
        iVar2 = FUN_00915378(0x20400001,0xffffffff,0xffffffff);
        puVar7 = local_10;
        if (iVar2 == -1) goto LAB_0091fe11;
        uVar11 = *(uint *)(*(int *)(in_ECX + 0x18) + iVar12 * 4);
        local_8 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar2 * 4);
        local_20 = uVar11;
        FUN_00914593();
        FUN_00914593();
        puVar13 = *(undefined4 **)(uVar11 + 8);
        puVar1 = (undefined4 *)puVar7[2];
        local_14 = (uint *)0x0;
        *puVar13 = *puVar1;
        puVar13[1] = puVar1[1];
        puVar13[2] = puVar1[2];
        puVar13[3] = puVar1[3];
        *(undefined4 *)local_8[4] = *(undefined4 *)local_10[4];
        do {
          uVar11 = local_20;
          iVar12 = (int)local_14 * 4;
          uVar3 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),local_28,local_14,0);
          *(undefined4 *)(iVar12 + local_8[2]) = uVar3;
          *(undefined4 *)(iVar12 + *(int *)(uVar11 + 0x10)) = *(undefined4 *)(iVar12 + local_8[2]);
          if (*(int *)(iVar12 + *(int *)(uVar11 + 0x10)) == -1) goto LAB_0091fe11;
          local_14 = (uint *)((int)local_14 + 1);
          *(undefined4 *)
           (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + *(int *)(local_20 + 0x10)) * 4) +
           0x18) = *(undefined4 *)
                    (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)local_10[4] * 4) + 0x18);
          *(undefined4 *)
           (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + *(int *)(local_20 + 0x10)) * 4) +
           0x14) = *(undefined4 *)
                    (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)local_10[4] * 4) + 0x14);
        } while (local_14 < (uint *)0x2);
        puVar7 = *(uint **)(in_ECX + 0xc);
        while (puVar7 = (uint *)((int)puVar7 + -1), local_1c < puVar7) {
          puVar13 = (undefined4 *)(*(int *)(in_ECX + 0x18) + (int)puVar7 * 4);
          *puVar13 = puVar13[-1];
        }
        *(uint *)(*(int *)(in_ECX + 0x18) + (int)local_1c * 4) = local_20;
        *(uint **)(*(int *)(in_ECX + 0x18) + 4 + (int)local_1c * 4) = local_8;
        FUN_008f4adb();
        *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -1;
        local_28 = (uint *)((int)local_28 + 1);
        local_8 = (uint *)0x1;
      }
      local_1c = (uint *)((int)local_1c + 1);
    } while (local_1c < *(uint **)(in_ECX + 0xc));
    if (local_8 != (uint *)0x0) {
      FUN_009198e4();
    }
  }
  if ((*(byte *)(in_ECX + 0x6c) & 1) != 0) {
    local_2c = *(uint *)(in_ECX + 0xc);
    local_20 = 0;
    if (*(uint *)(in_ECX + 0xc) != 0) {
      do {
        iVar12 = *(int *)(*(int *)(in_ECX + 0x18) + local_20 * 4);
        if ((((*(ushort *)(iVar12 + 2) & 0xfff0) != 0) && (*(uint *)(iVar12 + 0xc) != 0)) &&
           ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                               *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                **(int **)(iVar12 + 0x10) * 4) + 4) * 4) + 4) & 0x20
            ) != 0)) {
          uVar11 = 0;
          bVar14 = *(int *)(iVar12 + 4) == 0;
          if (*(int *)(iVar12 + 4) != 0) {
            local_18 = *(uint **)(iVar12 + 8);
            do {
              if (uVar11 != *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_18 * 4) + 0x10))
              break;
              local_18 = local_18 + 1;
              uVar11 = uVar11 + 1;
            } while (uVar11 < *(uint *)(iVar12 + 4));
            bVar14 = uVar11 == *(uint *)(iVar12 + 4);
          }
          if (!bVar14) {
            iVar2 = FUN_00915378(*(uint *)(iVar12 + 0xc) & 0xfffff | 0x10000000,0xffffffff,
                                 0xffffffff);
            if (iVar2 == -1) goto LAB_0091fe11;
            local_18 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar2 * 4);
            FUN_00914593();
            iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar12 + 0x10) * 4);
            local_14 = (uint *)0x0;
            local_30 = *(uint **)(iVar2 + 0x18);
            local_38 = *(uint **)(iVar2 + 0x14);
            if (*(int *)(iVar12 + 0xc) != 0) {
              do {
                iVar2 = (int)local_14 * 4;
                *(undefined4 *)(iVar2 + local_18[4]) =
                     *(undefined4 *)(iVar2 + *(int *)(iVar12 + 0x10));
                uVar3 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),local_28,local_14,0);
                *(undefined4 *)(iVar2 + *(int *)(iVar12 + 0x10)) = uVar3;
                *(undefined4 *)(iVar2 + local_18[2]) =
                     *(undefined4 *)(iVar2 + *(int *)(iVar12 + 0x10));
                if (*(int *)(iVar2 + local_18[2]) == -1) goto LAB_0091fe11;
                local_14 = (uint *)((int)local_14 + 1);
                *(uint **)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar2 + local_18[2]) * 4) +
                          0x18) = local_30;
                *(uint **)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar2 + local_18[2]) * 4) +
                          0x14) = local_38;
                **(undefined4 **)(*(int *)(in_ECX + 0x14) + *(int *)(iVar2 + local_18[2]) * 4) =
                     **(undefined4 **)(*(int *)(in_ECX + 0x14) + *(int *)(iVar2 + local_18[4]) * 4);
              } while (local_14 < *(uint **)(iVar12 + 0xc));
            }
            local_28 = (uint *)((int)local_28 + 1);
            local_8 = (uint *)0x1;
          }
        }
        local_20 = local_20 + 1;
      } while (local_20 < local_2c);
    }
  }
  if (((*(int *)(in_ECX + 0x4c) != 0) && ((*(byte *)(in_ECX + 0x70) & 0x20) == 0)) &&
     (local_1c = (uint *)0x0, *(int *)(in_ECX + 0xc) != 0)) {
    do {
      local_30 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_1c * 4);
      if ((*local_30 & 0xf0000000) == 0x60000000) {
        local_18 = (uint *)0x1;
        uVar15 = CONCAT44(&local_20,1);
        while (uVar11 = FUN_009145b2(uVar15), uVar11 != 0) {
          uVar5 = 0;
          if (uVar11 != 0) {
            do {
              if (*(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(local_20 + uVar5 * 4) * 4) +
                           0x10) != uVar5) break;
              uVar5 = uVar5 + 1;
            } while (uVar5 < uVar11);
          }
          if (uVar5 != uVar11) {
            iVar12 = *(int *)(in_ECX + 0xc);
            local_10 = (uint *)FUN_00917fc0(local_1c,local_20,uVar11,&local_28);
            if ((int)local_10 < 0) goto LAB_0091f4d7;
            if (*(int *)(in_ECX + 0xc) != iVar12) {
              local_1c = (uint *)((int)local_1c + (*(int *)(in_ECX + 0xc) - iVar12));
              FUN_009198e4();
            }
            local_8 = (uint *)0x1;
          }
          local_18 = (uint *)((int)local_18 + 1);
          uVar15 = CONCAT44(&local_20,local_18);
        }
      }
      local_1c = (uint *)((int)local_1c + 1);
    } while (local_1c < *(uint **)(in_ECX + 0xc));
  }
  if ((*(int *)(in_ECX + 0x4c) != 0) && (local_10 = (uint *)0x0, *(int *)(in_ECX + 0xc) != 0)) {
    do {
      puVar7 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_10 * 4);
      local_1c = puVar7;
      if ((*puVar7 & 0xfff00000) == 0x11000000) {
        if (puVar7[1] == 4) {
          piVar8 = (int *)puVar7[2];
          iVar12 = *(int *)(in_ECX + 0x14);
          if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                 *(int *)(*(int *)(iVar12 + *piVar8 * 4) + 4) * 4) + 5) & 2) == 0) {
            local_18 = (uint *)0x0;
            local_20 = 4;
            do {
              iVar2 = *piVar8;
              piVar8 = piVar8 + 1;
              local_18 = (uint *)((uint)local_18 |
                                 1 << ((byte)*(undefined4 *)(*(int *)(iVar12 + iVar2 * 4) + 0x10) &
                                      0x1f));
              local_20 = local_20 - 1;
            } while (local_20 != 0);
            local_20 = 0;
            if (local_18 == (uint *)0xf) {
              puVar4 = (uint *)puVar7[2];
              local_20 = 4;
              do {
                uVar5 = *puVar4;
                puVar4 = puVar4 + 1;
                uVar11 = local_20 - 1;
                local_20 = uVar11;
                local_74[*(int *)(*(int *)(iVar12 + uVar5 * 4) + 0x10) + 8] = uVar5;
              } while (uVar11 != 0);
              uVar11 = 0;
              do {
                *(undefined4 *)(uVar11 + puVar7[2]) = *(undefined4 *)((int)local_74 + uVar11 + 0x20)
                ;
                uVar11 = uVar11 + 4;
              } while (uVar11 < 0x10);
              goto LAB_0091eee2;
            }
          }
        }
        puVar4 = (uint *)FUN_00915378(0x10000004,0xffffffff,0xffffffff);
        local_30 = puVar4;
        iVar12 = FUN_00915378(0x11000004,0xffffffff,0xffffffff);
        if ((puVar4 == (uint *)0xffffffff) || (iVar12 == -1)) goto LAB_0091fe11;
        iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + (int)puVar4 * 4);
        local_c = *(uint **)(*(int *)(in_ECX + 0x18) + iVar12 * 4);
        FUN_00914593();
        FUN_00914593();
        local_8 = (uint *)0x0;
        while( true ) {
          local_14 = local_8;
          if ((uint *)puVar7[1] <= local_8) {
            local_14 = (uint *)((int)puVar7[1] + -1);
          }
          local_14 = (uint *)((int)local_14 * 4);
          iVar12 = (int)local_8 * 4;
          *(undefined4 *)(iVar12 + *(int *)(iVar2 + 8)) =
               *(undefined4 *)((int)local_14 + local_1c[2]);
          uVar3 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),local_28,local_8,0);
          *(undefined4 *)(iVar12 + *(int *)(iVar2 + 0x10)) = uVar3;
          *(undefined4 *)
           (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + *(int *)(iVar2 + 0x10)) * 4) + 0x14
           ) = *(undefined4 *)
                (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)((int)local_14 + local_1c[4]) * 4) +
                0x14);
          *(undefined4 *)
           (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + *(int *)(iVar2 + 0x10)) * 4) + 0x18
           ) = *(undefined4 *)
                (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)((int)local_14 + local_1c[4]) * 4) +
                0x18);
          if (*(int *)(iVar12 + *(int *)(iVar2 + 0x10)) == -1) goto LAB_0091fe11;
          *(undefined4 *)(iVar12 + local_c[2]) = *(undefined4 *)(iVar12 + *(int *)(iVar2 + 0x10));
          uVar3 = FUN_00915318(*(int *)(in_ECX + 0xa8),
                               *(undefined4 *)
                                (*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0xa8) * 4) + 8
                                ),local_8,0);
          *(undefined4 *)(iVar12 + local_c[4]) = uVar3;
          local_8 = (uint *)((int)local_8 + 1);
          *(undefined4 *)
           (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + local_c[4]) * 4) + 0x14) =
               *(undefined4 *)
                (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)((int)local_14 + local_1c[4]) * 4) +
                0x14);
          *(undefined4 *)
           (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + local_c[4]) * 4) + 0x18) =
               *(undefined4 *)
                (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)((int)local_14 + local_1c[4]) * 4) +
                0x18);
          if ((uint *)0x3 < local_8) break;
          puVar7 = local_1c;
        }
        piVar8 = (int *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0xa8) * 4) + 8);
        *piVar8 = *piVar8 + 1;
        for (puVar7 = local_30; local_10 < puVar7; puVar7 = (uint *)((int)puVar7 + -1)) {
          puVar13 = (undefined4 *)(*(int *)(in_ECX + 0x18) + (int)puVar7 * 4);
          *puVar13 = puVar13[-1];
        }
        *(int *)(*(int *)(in_ECX + 0x18) + (int)local_10 * 4) = iVar2;
        puVar7 = (uint *)((int)local_10 + 1);
        local_10 = puVar7;
        FUN_008f4adb();
        *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -1;
        local_28 = (uint *)((int)local_28 + 1);
        *(uint **)(*(int *)(in_ECX + 0x18) + (int)puVar7 * 4) = local_c;
        local_8 = (uint *)0x1;
      }
LAB_0091eee2:
      local_10 = (uint *)((int)local_10 + 1);
    } while (local_10 < *(uint **)(in_ECX + 0xc));
  }
  if ((*(byte *)(in_ECX + 0x6c) & 6) != 0) {
    local_c = (uint *)0x0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        puVar7 = *(uint **)((int)local_c * 4 + *(int *)(in_ECX + 0x18));
        local_30 = puVar7;
        if (((*puVar7 & 0xfff00000) == 0x10000000) &&
           (iVar12 = *(int *)(in_ECX + 0x14),
           (*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                              *(int *)(*(int *)(iVar12 + *(int *)puVar7[4] * 4) + 4) * 4) + 4) &
           0x20) == 0)) {
          local_14 = (uint *)0x0;
          if (puVar7[3] != 0) {
            piVar8 = (int *)puVar7[2];
            iVar2 = *piVar8;
            do {
              if (*(int *)(*(int *)(iVar12 + iVar2 * 4) + 0x48) !=
                  *(int *)(*(int *)(iVar12 + *piVar8 * 4) + 0x48)) break;
              local_14 = (uint *)((int)local_14 + 1);
              piVar8 = piVar8 + 1;
            } while (local_14 < (uint *)puVar7[3]);
          }
          if (local_14 != (uint *)puVar7[3]) {
            puVar4 = (uint *)puVar7[1];
            local_1c = (uint *)0x0;
            local_8 = (uint *)0x0;
            if (puVar4 != (uint *)0x0) {
              do {
                puVar10 = (uint *)(puVar7[2] + (int)local_8 * 4);
                uVar11 = *puVar10;
                if (uVar11 != 0xffffffff) {
                  local_2c = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar11 * 4) + 0x48);
                  uVar11 = 0;
                  if (local_8 < puVar4) {
                    local_20 = (int)puVar4 - (int)local_8;
                    local_18 = puVar10;
                    do {
                      if ((*local_18 != 0xffffffff) &&
                         (local_2c ==
                          *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_18 * 4) + 0x48))) {
                        uVar11 = uVar11 + 1;
                      }
                      local_18 = local_18 + 1;
                      local_20 = local_20 - 1;
                    } while (local_20 != 0);
                  }
                  iVar12 = FUN_00915378(uVar11 & 0xfffff | 0x10000000,0xffffffff,0xffffffff);
                  if (iVar12 == -1) goto LAB_0091fe11;
                  puVar4 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar12 * 4);
                  local_24 = puVar4;
                  FUN_00914593();
                  local_1c = (uint *)((int)local_1c + 1);
                  local_14 = local_8;
                  if (local_8 < (uint *)puVar7[1]) {
                    local_20 = 0;
                    do {
                      iVar12 = (int)local_14 * 4;
                      if ((*(int *)(iVar12 + puVar7[2]) != -1) &&
                         (local_2c ==
                          *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                            *(int *)(iVar12 + puVar7[2]) * 4) + 0x48))) {
                        *(undefined4 *)(local_20 + puVar4[2]) = *(undefined4 *)(iVar12 + puVar7[2]);
                        *(undefined4 *)(local_20 + local_24[4]) =
                             *(undefined4 *)(iVar12 + puVar7[4]);
                        *(undefined4 *)(iVar12 + puVar7[2]) = 0xffffffff;
                        local_20 = local_20 + 4;
                        puVar4 = local_24;
                      }
                      local_14 = (uint *)((int)local_14 + 1);
                    } while (local_14 < (uint *)puVar7[1]);
                  }
                }
                local_8 = (uint *)((int)local_8 + 1);
                puVar4 = (uint *)puVar7[1];
              } while (local_8 < puVar4);
              if (local_1c != (uint *)0x0) {
                puVar4 = (uint *)(*(int *)(in_ECX + 0x18) +
                                 (*(int *)(in_ECX + 0xc) - (int)local_1c) * 4);
                puVar10 = local_74 + 8;
                for (puVar7 = local_1c; puVar7 != (uint *)0x0; puVar7 = (uint *)((int)puVar7 - 1)) {
                  *puVar10 = *puVar4;
                  puVar4 = puVar4 + 1;
                  puVar10 = puVar10 + 1;
                }
              }
            }
            puVar7 = local_1c;
            puVar4 = (uint *)((*(int *)(in_ECX + 0xc) - (int)local_1c) + -1);
            if (local_c < puVar4) {
              iVar12 = ((int)puVar4 + (int)local_1c) * 4;
              do {
                *(undefined4 *)(*(int *)(in_ECX + 0x18) + -4 + iVar12) =
                     *(undefined4 *)(*(int *)(in_ECX + 0x18) + (int)puVar4 * 4);
                puVar4 = (uint *)((int)puVar4 + -1);
                iVar12 = iVar12 + -4;
              } while (local_c < puVar4);
            }
            local_14 = (uint *)0x0;
            if (local_1c != (uint *)0x0) {
              iVar12 = (int)local_c << 2;
              do {
                puVar4 = local_14 + 2;
                local_14 = (uint *)((int)local_14 + 1);
                *(uint *)(iVar12 + *(int *)(in_ECX + 0x18)) = local_74[(int)puVar4];
                iVar12 = iVar12 + 4;
              } while (local_14 < local_1c);
            }
            FUN_008f4adb();
            *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -1;
            local_c = (uint *)((int)local_c + -1 + (int)puVar7);
            local_8 = (uint *)0x1;
          }
        }
        local_c = (uint *)((int)local_c + 1);
      } while (local_c < *(uint **)(in_ECX + 0xc));
    }
    local_1c = (uint *)0x0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        puVar7 = *(uint **)((int)local_1c * 4 + *(int *)(in_ECX + 0x18));
        local_30 = puVar7;
        if ((*puVar7 & 0xfff00000) == 0x10000000) {
          iVar12 = *(int *)(in_ECX + 0x14);
          if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                 *(int *)(*(int *)(iVar12 + *(int *)puVar7[4] * 4) + 4) * 4) + 4) &
              0x20) == 0) {
            local_24 = (uint *)0x0;
            local_14 = (uint *)0x0;
            local_34 = (uint *)0x0;
            puVar4 = (uint *)0x0;
            if (puVar7[3] != 0) {
              local_3c = (int *)puVar7[2];
              local_c = (uint *)0x0;
              local_18 = (uint *)((int)puVar7[4] - (int)local_3c);
              do {
                if (*(int *)(*(int *)(iVar12 + *(int *)((int)local_18 + (int)local_3c) * 4) + 0x10)
                    == *(int *)(*(int *)(iVar12 + *local_3c * 4) + 0x10)) {
                  local_34 = (uint *)((int)local_34 + 1);
                }
                local_10 = (uint *)0x0;
                if (local_c != (uint *)0x0) {
                  piVar9 = (int *)puVar7[2];
                  piVar8 = (int *)((int)local_c + (int)piVar9);
                  do {
                    if (*(int *)(*(int *)(iVar12 + *piVar9 * 4) + 0x10) ==
                        *(int *)(*(int *)(iVar12 + *piVar8 * 4) + 0x10)) {
                      local_24 = (uint *)((int)local_24 + 1);
                      break;
                    }
                    local_10 = (uint *)((int)local_10 + 1);
                    piVar9 = piVar9 + 1;
                  } while (local_10 < local_14);
                }
                local_14 = (uint *)((int)local_14 + 1);
                puVar4 = (uint *)puVar7[3];
                local_c = local_c + 1;
                local_3c = local_3c + 1;
              } while (local_14 < puVar4);
            }
            if (((local_34 != puVar4) && ((uint *)((int)local_24 + 1) != puVar4)) &&
               (((uint *)0x1 < local_34 || (local_24 != (uint *)0x0)))) {
              local_c = (uint *)0x0;
              if ((uint *)0x1 < local_34) {
                iVar12 = FUN_00915378((uint)local_34 & 0xfffff | 0x10000000,0xffffffff,0xffffffff);
                if (iVar12 == -1) goto LAB_0091fe11;
                local_20 = *(uint *)(*(int *)(in_ECX + 0x18) + iVar12 * 4);
                FUN_00914593();
                local_c = (uint *)0x1;
                local_14 = (uint *)0x0;
                if (puVar7[3] != 0) {
                  local_2c = 0;
                  do {
                    iVar12 = (int)local_14 * 4;
                    if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + puVar7[4]) * 4
                                         ) + 0x10) ==
                        *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + puVar7[2]) * 4
                                         ) + 0x10)) {
                      *(int *)(local_2c + *(int *)(local_20 + 0x10)) = *(int *)(iVar12 + puVar7[4]);
                      *(undefined4 *)(local_2c + *(int *)(local_20 + 8)) =
                           *(undefined4 *)(iVar12 + puVar7[2]);
                      *(undefined4 *)(iVar12 + puVar7[2]) = 0xffffffff;
                      local_2c = local_2c + 4;
                    }
                    local_14 = (uint *)((int)local_14 + 1);
                  } while (local_14 < (uint *)puVar7[3]);
                }
              }
              puVar4 = (uint *)puVar7[1];
              local_8 = (uint *)0x0;
              if (puVar4 != (uint *)0x0) {
                do {
                  puVar10 = (uint *)(puVar7[2] + (int)local_8 * 4);
                  uVar11 = *puVar10;
                  if (uVar11 != 0xffffffff) {
                    local_2c = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar11 * 4) + 0x10);
                    uVar11 = 0;
                    if (local_8 < puVar4) {
                      local_20 = (int)puVar4 - (int)local_8;
                      local_24 = puVar10;
                      do {
                        if ((*local_24 != 0xffffffff) &&
                           (local_2c ==
                            *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_24 * 4) + 0x10))) {
                          uVar11 = uVar11 + 1;
                        }
                        local_24 = local_24 + 1;
                        local_20 = local_20 - 1;
                      } while (local_20 != 0);
                    }
                    iVar12 = FUN_00915378(uVar11 & 0xfffff | 0x10000000,0xffffffff,0xffffffff);
                    if (iVar12 == -1) goto LAB_0091fe11;
                    puVar4 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar12 * 4);
                    local_24 = puVar4;
                    FUN_00914593();
                    local_c = (uint *)((int)local_c + 1);
                    local_14 = local_8;
                    if (local_8 < (uint *)puVar7[1]) {
                      local_20 = 0;
                      do {
                        iVar12 = (int)local_14 * 4;
                        if ((*(int *)(iVar12 + puVar7[2]) != -1) &&
                           (local_2c ==
                            *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                              *(int *)(iVar12 + puVar7[2]) * 4) + 0x10))) {
                          *(undefined4 *)(local_20 + puVar4[4]) =
                               *(undefined4 *)(iVar12 + puVar7[4]);
                          *(undefined4 *)(local_20 + local_24[2]) =
                               *(undefined4 *)(iVar12 + puVar7[2]);
                          *(undefined4 *)(iVar12 + puVar7[2]) = 0xffffffff;
                          local_20 = local_20 + 4;
                          puVar4 = local_24;
                        }
                        local_14 = (uint *)((int)local_14 + 1);
                      } while (local_14 < (uint *)puVar7[1]);
                    }
                  }
                  local_8 = (uint *)((int)local_8 + 1);
                  puVar4 = (uint *)puVar7[1];
                } while (local_8 < puVar4);
              }
              if (local_c != (uint *)0x0) {
                puVar4 = (uint *)(*(int *)(in_ECX + 0x18) +
                                 (*(int *)(in_ECX + 0xc) - (int)local_c) * 4);
                puVar10 = local_74 + 8;
                for (puVar7 = local_c; puVar7 != (uint *)0x0; puVar7 = (uint *)((int)puVar7 - 1)) {
                  *puVar10 = *puVar4;
                  puVar4 = puVar4 + 1;
                  puVar10 = puVar10 + 1;
                }
              }
              puVar7 = (uint *)((*(int *)(in_ECX + 0xc) - (int)local_c) + -1);
              if (local_1c < puVar7) {
                iVar12 = ((int)puVar7 + (int)local_c) * 4;
                do {
                  *(undefined4 *)(*(int *)(in_ECX + 0x18) + -4 + iVar12) =
                       *(undefined4 *)(*(int *)(in_ECX + 0x18) + (int)puVar7 * 4);
                  puVar7 = (uint *)((int)puVar7 + -1);
                  iVar12 = iVar12 + -4;
                } while (local_1c < puVar7);
              }
              puVar7 = (uint *)0x0;
              if (local_c != (uint *)0x0) {
                iVar12 = (int)local_1c << 2;
                do {
                  *(uint *)(iVar12 + *(int *)(in_ECX + 0x18)) = local_74[(int)(puVar7 + 2)];
                  puVar7 = (uint *)((int)puVar7 + 1);
                  iVar12 = iVar12 + 4;
                } while (puVar7 < local_c);
              }
              FUN_008f4adb();
              *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -1;
              local_1c = (uint *)((int)local_1c + -1 + (int)local_c);
              local_8 = (uint *)0x1;
            }
          }
        }
        local_1c = (uint *)((int)local_1c + 1);
      } while (local_1c < *(uint **)(in_ECX + 0xc));
    }
  }
  if (local_8 != (uint *)0x0) {
    FUN_009198e4();
  }
  puVar7 = local_28;
  local_44 = operator_new((int)local_28 << 2);
  if (local_44 == (undefined4 *)0x0) {
LAB_0091fe11:
    local_10 = (uint *)0x8007000e;
  }
  else {
    puVar13 = local_44;
    for (uVar11 = (uint)puVar7 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
      *puVar13 = 0;
      puVar13 = puVar13 + 1;
    }
    uVar11 = 0;
    for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
      *(undefined1 *)puVar13 = 0;
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    if (*(int *)(in_ECX + 8) != 0) {
      do {
        iVar12 = *(int *)(*(int *)(in_ECX + 0x14) + uVar11 * 4);
        *(undefined4 *)(iVar12 + 0x5c) = 0;
        if (*(int *)(in_ECX + 0x88) == *(int *)(iVar12 + 4)) {
          if ((uint)local_44[*(int *)(iVar12 + 0xc)] <= *(uint *)(iVar12 + 0x10)) {
            local_44[*(int *)(iVar12 + 0xc)] = *(uint *)(iVar12 + 0x10) + 1;
          }
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)(in_ECX + 8));
    }
    uVar11 = *(uint *)(in_ECX + 0xc);
    if (*(uint *)(in_ECX + 0xc) != 0) {
      do {
        local_20 = uVar11 - 1;
        puVar7 = *(uint **)(*(int *)(in_ECX + 0x18) + (uVar11 - 1) * 4);
        uVar11 = *puVar7;
        local_14 = puVar7;
        if ((uVar11 & 0xfff00000) != 0) {
          local_10 = (uint *)(uVar11 & 0xfffff);
          local_2c = puVar7[1] / (uint)local_10;
          if (((puVar7[3] != 0) && (0xfffffff < (uVar11 & 0xf0000000))) &&
             ((uVar11 & 0xf0000000) < 0x40000001)) {
            FUN_00919678(puVar7[4],local_94,local_10,1);
            uVar11 = 0;
            if (local_2c != 0) {
              do {
                FUN_00919678(puVar7[2] + puVar7[3] * uVar11 * 4,local_94,local_10,0);
                uVar11 = uVar11 + 1;
              } while (uVar11 < local_2c);
            }
          }
          local_74[4] = 0;
          local_74[5] = 0;
          local_74[6] = 0;
          local_74[7] = 0;
          if ((*puVar7 & 0xfff00000) == 0x10000000) {
            iVar12 = *(int *)(in_ECX + 0x14);
            local_34 = *(uint **)(iVar12 + *(int *)puVar7[4] * 4);
            uVar11 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + local_34[1] * 4) + 4);
            if (((((uVar11 & 4) == 0) &&
                 (((*(byte *)(in_ECX + 0x6c) & 1) == 0 || ((uVar11 & 0x20) == 0)))) &&
                (*(int *)(in_ECX + 0x88) == *(int *)(*(int *)(iVar12 + *(int *)puVar7[2] * 4) + 4)))
               && (local_2c = 0, puVar7[1] != 0)) {
              local_24 = (uint *)((int)puVar7[2] - (int)(local_74 + 4));
              local_30 = (uint *)(*(uint *)(in_ECX + 0xcc) & 4);
              do {
                iVar2 = *(int *)(iVar12 + *(int *)((int)(local_74 + 4) + (int)(local_24 + local_2c))
                                          * 4);
                local_18 = *(uint **)(iVar2 + 0x48);
                local_10 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_18 * 4);
                if (local_30 != (uint *)0x0) {
                  local_38 = (uint *)local_34[0x18];
                  if (((local_38 != (uint *)0x0) && (*(uint **)(iVar2 + 0x60) != (uint *)0x0)) &&
                     (local_38 != *(uint **)(iVar2 + 0x60))) break;
                }
                if ((local_34[6] != *(uint *)(iVar2 + 0x18)) ||
                   (local_34[5] != *(uint *)(iVar2 + 0x14))) break;
                local_8 = (uint *)0x0;
                if (local_10[3] != 0) {
                  local_3c = (int *)local_10[4];
                  do {
                    iVar2 = *(int *)(iVar12 + *local_3c * 4);
                    if ((local_20 != *(uint *)(iVar2 + 0x54)) ||
                       (local_20 != *(uint *)(iVar2 + 0x58))) break;
                    local_8 = (uint *)((int)local_8 + 1);
                    local_3c = local_3c + 1;
                  } while (local_8 < (uint *)local_10[3]);
                }
                if (local_8 != (uint *)local_10[3]) break;
                local_8 = (uint *)0x0;
                if ((uint *)local_10[3] != (uint *)0x0) {
                  piVar8 = (int *)local_10[4];
                  do {
                    iVar2 = *(int *)(*(int *)(iVar12 + *piVar8 * 4) + 0x14);
                    if ((iVar2 != -1) &&
                       (local_18 <= *(uint **)(*(int *)(iVar12 + iVar2 * 4) + 0x48))) break;
                    local_8 = (uint *)((int)local_8 + 1);
                    piVar8 = piVar8 + 1;
                  } while (local_8 < (uint *)local_10[3]);
                }
                if ((local_8 != (uint *)local_10[3]) || ((*local_10 & 0xfff00000) == 0x20700000))
                break;
                local_74[local_2c + 4] = 1;
                local_2c = local_2c + 1;
                if (puVar7[1] <= local_2c) break;
              } while( true );
            }
          }
          if (((*puVar7 & 0xf0000000) < 0x10000000) || (0x40000000 < (*puVar7 & 0xf0000000))) {
            uVar11 = 0;
            do {
              local_84[uVar11] = uVar11;
              uVar11 = uVar11 + 1;
            } while (uVar11 < 4);
          }
          else {
            local_10 = (uint *)0x0;
            if (puVar7[3] != 0) {
              uVar11 = puVar7[4];
              iVar12 = *(int *)(in_ECX + 0x14);
              do {
                iVar2 = (int)local_10 * 4;
                puVar4 = local_84 + (int)local_10;
                local_10 = (uint *)((int)local_10 + 1);
                *puVar4 = *(uint *)(*(int *)(iVar12 + *(int *)(iVar2 + uVar11) * 4) + 0x10);
              } while (local_10 < (uint *)puVar7[3]);
            }
          }
          local_2c = 0;
          lVar16 = ZEXT48(&local_1c) << 0x20;
          while( true ) {
            local_28 = (uint *)FUN_009145b2(lVar16);
            if (local_28 == (uint *)0x0) break;
            local_74[0] = 0;
            local_74[1] = 0;
            local_74[2] = 0;
            local_c = (uint *)0x0;
            local_3c = (int *)0x0;
            local_74[3] = 0;
            local_10 = (uint *)0x0;
            if (local_28 == (uint *)0x0) {
LAB_0091f96a:
              if ((*local_14 & 0xfff00000) != 0x10000000) {
                uVar11 = 0;
                do {
                  if ((uint *)local_74[uVar11] == local_28) {
                    local_c = (uint *)0x1;
                    break;
                  }
                  uVar11 = uVar11 + 1;
                } while (uVar11 < 4);
                if (local_c != (uint *)0x0) goto LAB_0091f9d4;
              }
              if ((local_3c !=
                   (int *)local_44[*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_1c * 4) + 0xc)
                                  ]) && (uVar11 = 0, local_14[3] != 0)) {
                do {
                  if (local_74[uVar11 + 4] == 0) {
                    local_c = (uint *)0x1;
                    break;
                  }
                  uVar11 = uVar11 + 1;
                } while (uVar11 < local_14[3]);
                if (local_c != (uint *)0x0) goto LAB_0091f9d4;
              }
              local_18 = (uint *)0x0;
              if (local_28 != (uint *)0x0) {
                do {
                  puVar4 = local_14;
                  puVar7 = local_18;
                  iVar12 = (int)local_18 * 4;
                  if (local_74[(int)(local_18 + 1)] == 0) {
                    puVar13 = *(undefined4 **)
                               (*(int *)(in_ECX + 0x14) + local_1c[(int)local_18] * 4);
                    if (local_74[puVar13[4]] == 1) {
                      local_74[(int)(local_18 + 2)] = local_1c[(int)local_18];
                      puVar13[4] = local_84[(int)puVar7];
                    }
                    else {
                      uVar11 = FUN_00915318(puVar13[1],puVar13[3],local_84[(int)local_18],0);
                      local_74[(int)(puVar7 + 2)] = uVar11;
                      if (uVar11 == 0xffffffff) goto LAB_0091fe11;
                      iVar12 = uVar11 * 4;
                      FUN_00914f00();
                      **(undefined4 **)(iVar12 + *(int *)(in_ECX + 0x14)) = *puVar13;
                      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar12) + 0x18) =
                           puVar13[6];
                      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar12) + 0x14) =
                           puVar13[5];
                      local_44[puVar13[3]] = local_44[puVar13[3]] + 1;
                      local_74[puVar13[4]] = local_74[puVar13[4]] - 1;
                    }
                  }
                  else {
                    uVar11 = local_14[4];
                    uVar5 = *(uint *)(uVar11 + iVar12);
                    iVar2 = *(int *)(in_ECX + 0x14);
                    local_74[(int)(local_18 + 2)] = uVar5;
                    if (*(int *)(*(int *)(iVar2 + uVar5 * 4) + 0x60) == 0) {
                      *(undefined4 *)(*(int *)(iVar2 + *(uint *)(uVar11 + iVar12) * 4) + 0x60) =
                           *(undefined4 *)
                            (*(int *)(iVar2 + *(int *)(iVar12 + puVar4[2]) * 4) + 0x60);
                      *(undefined4 *)
                       (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + puVar4[4]) * 4) + 100)
                           = *(undefined4 *)
                              (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + puVar4[2]) * 4)
                              + 100);
                    }
                  }
                  local_18 = (uint *)((int)local_18 + 1);
                } while (local_18 < local_28);
              }
              local_38 = (uint *)0x0;
              if (local_28 != (uint *)0x0) {
                do {
                  puVar7 = *(uint **)(*(int *)(in_ECX + 0x14) + local_1c[(int)local_38] * 4);
                  local_30 = puVar7;
                  if (puVar7[0x17] == 0) {
                    local_c = (uint *)0x0;
                    for (puVar4 = local_38; puVar10 = local_c, puVar4 < local_28;
                        puVar4 = (uint *)((int)puVar4 + 1)) {
                      iVar12 = *(int *)(*(int *)(in_ECX + 0x14) + local_1c[(int)puVar4] * 4);
                      if (puVar7[0x12] == *(uint *)(iVar12 + 0x48)) {
                        local_c = (uint *)((int)local_c + 1);
                        auStack_b4[(int)puVar10] = local_1c[(int)puVar4];
                        auStack_a4[(int)puVar10] = local_74[(int)(puVar4 + 2)];
                        *(undefined4 *)(iVar12 + 0x5c) = 1;
                      }
                    }
                    puVar7 = *(uint **)(*(int *)(in_ECX + 0x18) + puVar7[0x12] * 4);
                    uVar11 = *puVar7 & 0xf0000000;
                    if ((uVar11 < 0x10000000) || (0x40000000 < uVar11)) {
                      local_18 = (uint *)0x0;
                      if (puVar7[3] != 0) {
                        do {
                          puVar4 = (uint *)(puVar7[4] + (int)local_18 * 4);
                          puVar10 = (uint *)0x0;
                          do {
                            if (*puVar4 == local_1c[(int)puVar10]) {
                              *puVar4 = local_74[(int)(puVar10 + 2)];
                              break;
                            }
                            puVar10 = (uint *)((int)puVar10 + 1);
                          } while (puVar10 < local_28);
                          local_18 = (uint *)((int)local_18 + 1);
                        } while (local_18 < (uint *)puVar7[3]);
                      }
                    }
                    else {
                      puVar4 = (uint *)0x0;
                      local_34 = (uint *)(puVar7[1] / (*puVar7 & 0xfffff));
                      if (local_c != (uint *)0x0) {
                        puVar10 = (uint *)puVar7[3];
                        do {
                          local_18 = (uint *)0x0;
                          if (puVar10 != (uint *)0x0) {
                            puVar6 = (uint *)puVar7[4];
                            do {
                              if (*puVar6 == auStack_b4[(int)puVar4]) {
                                auStack_c4[(int)puVar4] = (uint)local_18;
                                break;
                              }
                              local_18 = (uint *)((int)local_18 + 1);
                              puVar10 = (uint *)puVar7[3];
                              puVar6 = puVar6 + 1;
                            } while (local_18 < puVar10);
                          }
                          puVar4 = (uint *)((int)puVar4 + 1);
                        } while (puVar4 < local_c);
                      }
                      iVar12 = FUN_009149f7();
                      if (iVar12 == 0) {
                        iVar12 = 0;
                      }
                      else {
                        iVar12 = FUN_0091455d();
                      }
                      if (iVar12 == 0) goto LAB_0091fe11;
                      local_10 = (uint *)FUN_00914a42((*puVar7 ^ (uint)local_c) & 0xfffff ^ *puVar7,
                                                      (int)local_34 * (int)local_c,local_c,0);
                      if (((int)local_10 < 0) ||
                         (local_10 = (uint *)FUN_00914593(), (int)local_10 < 0)) {
                        FUN_008f4adb();
                        goto LAB_0091f4d7;
                      }
                      local_10 = (uint *)0x0;
                      if (local_c != (uint *)0x0) {
                        do {
                          local_18 = (uint *)0x0;
                          *(uint *)((int)local_10 * 4 + *(int *)(iVar12 + 0x10)) =
                               auStack_a4[(int)local_10];
                          if (local_34 != (uint *)0x0) {
                            local_40 = (uint *)auStack_c4[(int)local_10];
                            local_24 = (uint *)((int)local_10 * 4);
                            do {
                              iVar2 = puVar7[3] * (int)local_18;
                              local_18 = (uint *)((int)local_18 + 1);
                              *(undefined4 *)((int)local_24 + *(int *)(iVar12 + 8)) =
                                   *(undefined4 *)(puVar7[2] + (int)(iVar2 + (int)local_40) * 4);
                              local_24 = local_24 + (int)local_c;
                            } while (local_18 < local_34);
                          }
                          local_10 = (uint *)((int)local_10 + 1);
                        } while (local_10 < local_c);
                      }
                      if (*(int *)(*(int *)(in_ECX + 0x18) + local_30[0x12] * 4) != 0) {
                        FUN_008f4adb();
                      }
                      *(int *)(*(int *)(in_ECX + 0x18) + local_30[0x12] * 4) = iVar12;
                    }
                  }
                  local_38 = (uint *)((int)local_38 + 1);
                } while (local_38 < local_28);
              }
              puVar7 = (uint *)0x0;
              if (local_28 != (uint *)0x0) {
                do {
                  local_1c[(int)puVar7] = local_74[(int)(puVar7 + 2)];
                  puVar4 = local_1c + (int)puVar7;
                  puVar7 = (uint *)((int)puVar7 + 1);
                  *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *puVar4 * 4) + 0x5c) = 1;
                } while (puVar7 < local_28);
              }
            }
            else {
              do {
                puVar7 = local_10;
                local_30 = local_1c + (int)local_10;
                iVar12 = *(int *)(*(int *)(in_ECX + 0x14) + local_1c[(int)local_10] * 4);
                if ((*(int *)(in_ECX + 0x88) != *(int *)(iVar12 + 4)) ||
                   (iVar2 = *(int *)(iVar12 + 0x48), iVar2 == -1)) break;
                if (*(int *)(iVar12 + 0x5c) != 0) {
                  local_c = (uint *)0x1;
                }
                local_38 = *(uint **)(iVar12 + 0x10);
                local_40 = local_74 + (int)*(uint **)(iVar12 + 0x10);
                if (local_74[(int)*(uint **)(iVar12 + 0x10)] == 0) {
                  local_3c = (int *)((int)local_3c + 1);
                }
                local_74[*(int *)(iVar12 + 0x10)] = local_74[*(int *)(iVar12 + 0x10)] + 1;
                puVar4 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar2 * 4);
                uVar11 = *puVar4;
                uVar5 = uVar11 & 0xfff00000;
                if (((uVar5 == 0x20700000) || (uVar5 == 0x20800000)) || (uVar5 == 0x20900000)) {
LAB_0091f93f:
                  local_c = (uint *)0x1;
                }
                else if (((uVar11 & 0xf0000000) < 0x10000000) ||
                        (0x40000000 < (uVar11 & 0xf0000000))) {
                  if (((1 < puVar4[3]) && (local_10 != local_38)) || (1 < *local_40))
                  goto LAB_0091f93f;
                }
                else {
                  if ((*(int *)(iVar12 + 0x5c) != 0) &&
                     (local_40 = (uint *)local_84[(int)puVar7], local_40 != local_38)) {
                    local_34 = (uint *)0xffffffff;
                    local_18 = (uint *)0xffffffff;
                    local_8 = (uint *)0x0;
                    if (puVar4[3] != 0) {
                      local_24 = (uint *)puVar4[4];
                      do {
                        if (*local_30 == *local_24) {
                          local_34 = local_8;
                        }
                        if (local_40 ==
                            *(uint **)(*(int *)(*(int *)(in_ECX + 0x14) + *local_24 * 4) + 0x10)) {
                          local_18 = local_8;
                        }
                        local_8 = (uint *)((int)local_8 + 1);
                        local_24 = local_24 + 1;
                      } while (local_8 < (uint *)puVar4[3]);
                      if ((local_34 != (uint *)0xffffffff) && (local_18 != (uint *)0xffffffff)) {
                        local_38 = (uint *)(puVar4[1] / (uVar11 & 0xfffff));
                        local_8 = (uint *)0x0;
                        if (local_38 != (uint *)0x0) {
                          local_24 = (uint *)(puVar4[2] + (int)local_34 * 4);
                          puVar7 = (uint *)(puVar4[2] + (int)local_18 * 4);
                          do {
                            if (*local_24 != *puVar7) break;
                            local_8 = (uint *)((int)local_8 + 1);
                            local_24 = local_24 + puVar4[3];
                            puVar7 = puVar7 + puVar4[3];
                            local_40 = puVar7;
                          } while (local_8 < local_38);
                        }
                        if (local_8 == local_38) {
                          *local_30 = *(uint *)(puVar4[4] + (int)local_18 * 4);
                        }
                      }
                    }
                  }
                  iVar2 = FUN_00914622();
                  if ((iVar2 != 0) && (1 < local_74[*(int *)(iVar12 + 0x10)])) {
                    local_c = (uint *)0x1;
                  }
                }
                local_10 = (uint *)((int)local_10 + 1);
              } while (local_10 < local_28);
              if (local_10 < local_28) {
                local_c = (uint *)0x1;
              }
              if (local_c == (uint *)0x0) goto LAB_0091f96a;
LAB_0091f9d4:
              local_74[4] = 0;
              local_74[5] = 0;
              local_74[6] = 0;
              local_74[7] = 0;
            }
            local_2c = local_2c + 1;
            lVar16 = CONCAT44(&local_1c,local_2c);
          }
          if ((*local_14 & 0xfff00000) == 0x10000000) {
            uVar11 = 0;
            local_2c = 0;
            if (local_14[3] != 0) {
              do {
                if (local_74[local_2c + 4] == 0) {
                  *(undefined4 *)(local_14[4] + uVar11 * 4) =
                       *(undefined4 *)(local_14[4] + local_2c * 4);
                  *(undefined4 *)(local_14[2] + uVar11 * 4) =
                       *(undefined4 *)(local_14[2] + local_2c * 4);
                  uVar11 = uVar11 + 1;
                }
                else {
                  iVar12 = uVar11 * 4;
                  local_40 = *(uint **)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + local_14[4]) * 4
                                       );
                  if (local_40[0x18] == 0) {
                    local_40[0x18] =
                         *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                           *(int *)(iVar12 + local_14[2]) * 4) + 0x60);
                    *(undefined4 *)
                     (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + local_14[4]) * 4) + 100)
                         = *(undefined4 *)
                            (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar12 + local_14[2]) * 4)
                            + 100);
                  }
                }
                local_2c = local_2c + 1;
              } while (local_2c < local_14[3]);
            }
            *local_14 = -(uint)(uVar11 != 0) & (uVar11 & 0xfffff | 0x10000000);
            local_14[1] = uVar11;
            local_14[3] = uVar11;
          }
        }
        if (local_20 == 0) break;
        uVar11 = local_20;
      } while( true );
    }
    local_10 = (uint *)0x0;
  }
LAB_0091f4d7:
  _free(local_44);
  return;
}


// ==== FUN_0091fe2b @ 0x0091fe2b ====

bool FUN_0091fe2b(int param_1)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  int *piVar7;
  int *local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  bVar3 = false;
  local_8 = 0;
  iVar4 = *(int *)(in_ECX + 8);
  if (iVar4 != 0) {
    piVar7 = *(int **)(in_ECX + 0x14);
    do {
      if ((*(int *)(in_ECX + 0x88) == *(int *)(*piVar7 + 4)) &&
         (uVar5 = *(uint *)(*piVar7 + 0xc), local_8 <= uVar5)) {
        local_8 = uVar5 + 1;
      }
      piVar7 = piVar7 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  FUN_009198e4();
  local_18 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_18 * 4);
      if ((*puVar1 & 0xfff00000) != 0) {
        uVar5 = puVar1[1] / (*puVar1 & 0xfffff);
        puVar1[9] = 0;
        local_14 = 0;
        if (uVar5 != 0) {
          do {
            local_10 = FUN_009145b2(local_14,&local_1c);
            iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *local_1c * 4);
            if (*(int *)(in_ECX + 0x88) == *(int *)(iVar4 + 4)) {
              local_c = 1;
              if (1 < local_10) {
                do {
                  iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + local_1c[local_c] * 4);
                  if ((*(int *)(in_ECX + 0x88) == *(int *)(iVar2 + 4)) &&
                     (*(int *)(iVar2 + 0x48) != *(int *)(iVar4 + 0x48))) break;
                  local_c = local_c + 1;
                } while (local_c < local_10);
              }
              if ((local_c != local_10) && (uVar6 = 0, local_10 != 0)) {
                do {
                  iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + local_1c[uVar6] * 4);
                  if (*(int *)(in_ECX + 0x88) == *(int *)(iVar4 + 4)) {
                    *(undefined4 *)
                     (*(int *)(*(int *)(in_ECX + 0x18) + *(int *)(iVar4 + 0x48) * 4) + 0x24) = 1;
                  }
                  uVar6 = uVar6 + 1;
                } while (uVar6 < local_10);
              }
            }
            local_14 = local_14 + 1;
          } while (local_14 < uVar5);
        }
      }
      local_18 = local_18 + 1;
    } while (local_18 < *(uint *)(in_ECX + 0xc));
  }
  local_14 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar4 = *(int *)(*(int *)(in_ECX + 0x18) + local_14 * 4);
      if (((*(ushort *)(iVar4 + 2) & 0xfff0) != 0) && (*(int *)(iVar4 + 0x24) == 0)) {
        local_1c = *(int **)(iVar4 + 0x10);
        iVar2 = *(int *)(in_ECX + 0x14);
        if (*(int *)(in_ECX + 0x88) == *(int *)(*(int *)(iVar2 + *local_1c * 4) + 4)) {
          uVar5 = *(uint *)(iVar4 + 0xc);
          uVar6 = 0;
          if (param_1 == 0) {
            local_18 = 0;
            if (uVar5 != 0) {
              do {
                if (*(int *)(*(int *)(iVar2 + *local_1c * 4) + 0x10) == 0) break;
                local_18 = local_18 + 1;
                local_1c = local_1c + 1;
              } while (local_18 < uVar5);
            }
            if (uVar5 <= local_18) {
              uVar6 = 0;
              if (uVar5 != 0) {
                do {
                  iVar2 = uVar6 * 4;
                  uVar6 = uVar6 + 1;
                  *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                    *(int *)(*(int *)(iVar4 + 0x10) + iVar2) * 4) + 0xc) = local_8;
                } while (uVar6 < *(uint *)(iVar4 + 0xc));
              }
              goto LAB_0092004d;
            }
          }
          else {
            if (uVar5 != 0) {
              do {
                if (uVar6 != *(uint *)(*(int *)(iVar2 + *local_1c * 4) + 0x10)) break;
                local_1c = local_1c + 1;
                uVar6 = uVar6 + 1;
              } while (uVar6 < uVar5);
            }
            if (uVar6 != uVar5) {
              uVar6 = 0;
              if (uVar5 != 0) {
                do {
                  *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                    *(int *)(*(int *)(iVar4 + 0x10) + uVar6 * 4) * 4) + 0xc) =
                       local_8;
                  *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                    *(int *)(*(int *)(iVar4 + 0x10) + uVar6 * 4) * 4) + 0x10) =
                       uVar6;
                  uVar6 = uVar6 + 1;
                } while (uVar6 < *(uint *)(iVar4 + 0xc));
              }
LAB_0092004d:
              local_8 = local_8 + 1;
              bVar3 = true;
            }
          }
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < *(uint *)(in_ECX + 0xc));
  }
  return !bVar3;
}


