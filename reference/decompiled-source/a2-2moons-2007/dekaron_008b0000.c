// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x8b0000-0x8bffff

// ==== FUN_008b00bf @ 0x008b00bf ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b00bf(uint param_1,uint param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  int in_ECX;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ushort in_FPUControlWord;
  float local_50;
  float local_44;
  int local_30;
  int local_24;
  ushort *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_50 = 0.0;
  local_44 = 0.0;
  local_8 = (ushort *)
            (*(int *)(in_ECX + 0x60) * param_1 + (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2
             + *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  uVar6 = param_1 & 3;
  uVar9 = param_2 & 3;
  iVar2 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar13 = 0;
    iVar14 = 1;
    param_2 = 1;
  }
  else {
    iVar13 = *(int *)(in_ECX + 0x68) + -1;
    param_2 = -1;
    iVar14 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  uVar10 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    pfVar7 = param_3;
    do {
      uVar10 = uVar10 + 1;
      *pfVar7 = *pfVar7 * _DAT_009fc7b4 + pfVar7[1] * _DAT_009fc7ac + pfVar7[2] * _DAT_009fc7b0;
      pfVar7 = pfVar7 + 4;
    } while (uVar10 < *(uint *)(in_ECX + 0x68));
  }
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar14 * 0x10;
    iVar8 = iVar13 << 4;
    iVar15 = (iVar14 + iVar13) * 0x10;
    iVar13 = (iVar13 - param_2) * 0x10;
    do {
      fVar5 = DAT_0099d0b0;
      fVar1 = *(float *)(iVar2 + (uVar9 + uVar6 * 8) * 4 + (param_1 & 3) * 4);
      fVar3 = (local_50 + *(float *)((int)param_3 + iVar8)) * DAT_0099d0b8;
      fVar4 = (local_44 + ((float *)((int)param_3 + iVar8))[3]) * DAT_0099d0b8;
      local_30 = (int)ROUND(fVar3 + fVar1);
      local_24 = (int)ROUND(fVar4 + fVar1);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar7 = (float *)(iVar13 + 0x10 + *(int *)(in_ECX + 0x5c));
        local_50 = (fVar3 - (float)local_30) * DAT_0099d0b0;
        *pfVar7 = _DAT_00a171c4 * local_50 + *pfVar7;
        pfVar7 = (float *)(iVar8 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar7 = _DAT_00a171c0 * local_50 + *pfVar7;
        pfVar7 = (float *)(iVar15 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar7 = DAT_009af898 * local_50 + *pfVar7;
        pfVar7 = (float *)(iVar13 + 0x1c + *(int *)(in_ECX + 0x5c));
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar5 = (fVar4 - (float)local_24) * fVar5;
        *pfVar7 = _DAT_00a171c4 * fVar5 + *pfVar7;
        pfVar7 = (float *)(iVar8 + 0x1c + *(int *)(in_ECX + 0x5c));
        *pfVar7 = _DAT_00a171c0 * fVar5 + *pfVar7;
        pfVar7 = (float *)(iVar15 + 0x1c + *(int *)(in_ECX + 0x5c));
        *pfVar7 = DAT_009af898 * fVar5 + *pfVar7;
        local_44 = fVar5 * (float)_DAT_00a171b8;
      }
      iVar12 = local_30;
      if (0xfe < local_30) {
        iVar12 = 0xff;
      }
      if (iVar12 < 1) {
        local_30 = 0;
      }
      else if (0xfe < local_30) {
        local_30 = 0xff;
      }
      iVar12 = local_24;
      if (0xfe < local_24) {
        iVar12 = 0xff;
      }
      if (iVar12 < 1) {
        local_24 = 0;
      }
      else if (0xfe < local_24) {
        local_24 = 0xff;
      }
      iVar8 = iVar8 + iVar11;
      iVar13 = iVar13 + iVar11;
      iVar15 = iVar15 + iVar11;
      *local_8 = (ushort)(byte)local_24 << 8 | (ushort)local_30;
      local_8 = local_8 + iVar14;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b034d @ 0x008b034d ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b034d(uint param_1,uint param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  int in_ECX;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  byte *pbVar14;
  undefined2 in_FPUControlWord;
  float local_54;
  float local_48;
  int local_34;
  int local_c;
  uint local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_54 = 0.0;
  local_48 = 0.0;
  uVar6 = param_1 & 3;
  uVar9 = param_2 & 3;
  pbVar14 = (byte *)((*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) +
                     *(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                    *(int *)(in_ECX + 0x20));
  iVar2 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    param_2 = 0;
    param_1 = 1;
  }
  else {
    param_2 = *(int *)(in_ECX + 0x68) + -1;
    param_1 = -1;
  }
  local_c = CONCAT22(local_c._2_2_,in_FPUControlWord);
  *(int *)(in_ECX + 0x7c) = local_c;
  uVar10 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    pfVar7 = param_3;
    do {
      uVar10 = uVar10 + 1;
      *pfVar7 = pfVar7[1] * _DAT_009fc7ac + *pfVar7 * _DAT_009fc7b4 + pfVar7[2] * _DAT_009fc7b0;
      pfVar7 = pfVar7 + 4;
    } while (uVar10 < *(uint *)(in_ECX + 0x68));
  }
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  local_8 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = param_1 * 0x10;
    local_c = (param_1 + param_2) * 0x10;
    iVar8 = param_2 << 4;
    param_2 = (param_2 - param_1) * 0x10;
    do {
      fVar5 = _DAT_00a171c8;
      fVar1 = *(float *)(iVar2 + (uVar9 + uVar6 * 8) * 4 + (local_8 & 3) * 4);
      fVar3 = (local_54 + *(float *)((int)param_3 + iVar8)) * DAT_009bfa74;
      fVar4 = (local_48 + ((float *)((int)param_3 + iVar8))[3]) * DAT_009bfa74;
      local_34 = (int)ROUND(fVar3 + fVar1);
      iVar12 = (int)ROUND(fVar4 + fVar1);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar7 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + param_2);
        local_54 = (fVar3 - (float)local_34) * _DAT_00a171c8;
        *pfVar7 = _DAT_00a171c4 * local_54 + *pfVar7;
        pfVar7 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar8);
        *pfVar7 = _DAT_00a171c0 * local_54 + *pfVar7;
        pfVar7 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + local_c);
        *pfVar7 = DAT_009af898 * local_54 + *pfVar7;
        pfVar7 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + param_2);
        local_54 = local_54 * (float)_DAT_00a171b8;
        fVar5 = (fVar4 - (float)iVar12) * fVar5;
        *pfVar7 = _DAT_00a171c4 * fVar5 + *pfVar7;
        pfVar7 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar8);
        *pfVar7 = _DAT_00a171c0 * fVar5 + *pfVar7;
        pfVar7 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + local_c);
        *pfVar7 = DAT_009af898 * fVar5 + *pfVar7;
        local_48 = fVar5 * (float)_DAT_00a171b8;
      }
      if (local_34 < 0xf) {
        iVar13 = local_34;
      }
      else {
        iVar13 = 0xf;
      }
      if (iVar13 < 1) {
        local_34 = 0;
      }
      else if (0xe < local_34) {
        local_34 = 0xf;
      }
      if (iVar12 < 0xf) {
        iVar13 = iVar12;
      }
      else {
        iVar13 = 0xf;
      }
      if (iVar13 < 1) {
        iVar12 = 0;
      }
      else if (0xe < iVar12) {
        iVar12 = 0xf;
      }
      *pbVar14 = (char)iVar12 << 4 | (byte)local_34;
      param_2 = param_2 + iVar11;
      pbVar14 = pbVar14 + param_1;
      local_c = local_c + iVar11;
      iVar8 = iVar8 + iVar11;
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b05ee @ 0x008b05ee ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b05ee(uint param_1,uint param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  int iVar12;
  int iVar13;
  ushort in_FPUControlWord;
  float local_38;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_38 = 0.0;
  uVar4 = param_1 & 3;
  uVar7 = param_2 & 3;
  iVar1 = *(int *)(in_ECX + 0x34);
  puVar11 = (undefined2 *)
            (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
             (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2 + *(int *)(in_ECX + 0x20));
  if ((param_1 & 1) == 0) {
    iVar12 = 0;
    param_2 = 1;
  }
  else {
    iVar12 = *(int *)(in_ECX + 0x68) + -1;
    param_2 = -1;
  }
  iVar3 = param_2;
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  uVar8 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    pfVar5 = param_3;
    do {
      uVar8 = uVar8 + 1;
      *pfVar5 = *pfVar5 * _DAT_009fc7b4 + pfVar5[1] * _DAT_009fc7ac + pfVar5[2] * _DAT_009fc7b0;
      pfVar5 = pfVar5 + 4;
    } while (uVar8 < *(uint *)(in_ECX + 0x68));
  }
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar9 = param_2 * 0x10;
    iVar6 = iVar12 << 4;
    iVar10 = (param_2 + iVar12) * 0x10;
    param_2 = (iVar12 - param_2) * 0x10;
    do {
      fVar2 = (local_38 + *(float *)(iVar6 + (int)param_3)) * _DAT_00a16814;
      iVar12 = (int)ROUND(fVar2 + *(float *)(iVar1 + (uVar7 + uVar4 * 8) * 4 + (param_1 & 3) * 4));
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar5 = (float *)(param_2 + 0x10 + *(int *)(in_ECX + 0x5c));
        local_38 = (fVar2 - (float)iVar12) * _DAT_00a171d8;
        *pfVar5 = _DAT_00a171c4 * local_38 + *pfVar5;
        pfVar5 = (float *)(iVar6 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar5 = _DAT_00a171c0 * local_38 + *pfVar5;
        pfVar5 = (float *)(iVar10 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar5 = DAT_009af898 * local_38 + *pfVar5;
        local_38 = local_38 * (float)_DAT_00a171b8;
      }
      iVar13 = iVar12;
      if (0xfffe < iVar12) {
        iVar13 = 0xffff;
      }
      if (iVar13 < 1) {
        iVar12 = 0;
      }
      else if (0xfffe < iVar12) {
        iVar12 = 0xffff;
      }
      *puVar11 = (short)iVar12;
      param_2 = param_2 + iVar9;
      puVar11 = puVar11 + iVar3;
      iVar6 = iVar6 + iVar9;
      iVar10 = iVar10 + iVar9;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b07df @ 0x008b07df ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b07df(uint param_1,uint param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  int iVar8;
  int in_ECX;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  ushort in_FPUControlWord;
  int iVar15;
  float local_50;
  float local_4c;
  int local_30;
  undefined2 *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_50 = 0.0;
  local_4c = 0.0;
  uVar7 = param_1 & 3;
  uVar9 = param_2 & 3;
  local_8 = (undefined2 *)
            (*(int *)(in_ECX + 0x60) * param_1 + (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2
             + *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar12 = 0;
    iVar13 = 1;
    param_2 = 1;
  }
  else {
    iVar12 = *(int *)(in_ECX + 0x68) + -1;
    param_2 = -1;
    iVar13 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar10 = iVar13 * 0x10;
    iVar8 = iVar12 << 4;
    iVar14 = (iVar13 + iVar12) * 0x10;
    iVar12 = (iVar12 - param_2) * 0x10;
    do {
      fVar6 = _DAT_00a171dc;
      fVar2 = *(float *)(iVar3 + (uVar9 + uVar7 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_50 + *(float *)(param_3 + iVar8)) * _DAT_00a171e0;
      fVar5 = (local_4c + ((float *)(param_3 + iVar8))[1]) * _DAT_00a171e0;
      local_30 = (int)ROUND(fVar4 + fVar2);
      iVar15 = (int)ROUND(fVar5 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        local_50 = (fVar4 - (float)local_30) * _DAT_00a171dc;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(iVar8 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar14);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar6 = (fVar5 - (float)iVar15) * fVar6;
        *pfVar1 = _DAT_00a171c4 * fVar6 + *pfVar1;
        pfVar1 = (float *)(iVar8 + 0x14 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = _DAT_00a171c0 * fVar6 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar14);
        *pfVar1 = DAT_009af898 * fVar6 + *pfVar1;
        local_4c = fVar6 * (float)_DAT_00a171b8;
      }
      if (local_30 < 0x7f) {
        iVar11 = local_30;
      }
      else {
        iVar11 = 0x7f;
      }
      if (iVar11 < -0x7e) {
        local_30 = -0x7f;
      }
      else if (0x7e < local_30) {
        local_30 = 0x7f;
      }
      if (iVar15 < 0x7f) {
        iVar11 = iVar15;
      }
      else {
        iVar11 = 0x7f;
      }
      if (iVar11 < -0x7e) {
        iVar15 = -0x7f;
      }
      else if (0x7e < iVar15) {
        iVar15 = 0x7f;
      }
      iVar8 = iVar8 + iVar10;
      iVar12 = iVar12 + iVar10;
      iVar14 = iVar14 + iVar10;
      *local_8 = CONCAT11((char)iVar15,(undefined1)local_30);
      local_8 = local_8 + iVar13;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b0a46 @ 0x008b0a46 ====

void FUN_008b0a46(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x18,1);
  *in_ECX = &PTR_FUN_00a171e4;
  return;
}


// ==== FUN_008b0a67 @ 0x008b0a67 ====

void FUN_008b0a67(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,1);
  *in_ECX = &PTR_FUN_00a171f4;
  return;
}


// ==== FUN_008b0a88 @ 0x008b0a88 ====

void FUN_008b0a88(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,1);
  *in_ECX = &PTR_FUN_00a17204;
  return;
}


// ==== FUN_008b0aa9 @ 0x008b0aa9 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b0aa9(uint param_1,uint param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  ushort in_FPUControlWord;
  uint uVar17;
  float local_58;
  float local_54;
  float local_4c;
  int local_38;
  int local_c;
  ushort *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_58 = 0.0;
  local_54 = 0.0;
  local_4c = 0.0;
  local_8 = (ushort *)
            (*(int *)(in_ECX + 0x60) * param_1 + (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2
             + *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  uVar8 = param_1 & 3;
  uVar11 = param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar12 = 0;
    iVar15 = 1;
    param_2 = 1;
  }
  else {
    iVar12 = *(int *)(in_ECX + 0x68) + -1;
    param_2 = -1;
    iVar15 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar10 = iVar15 * 0x10;
    iVar9 = iVar12 * 0x10;
    iVar16 = (iVar15 + iVar12) * 0x10;
    local_c = (iVar12 - param_2) * 0x10;
    param_3 = (float *)(iVar9 + 0xc + (int)param_3);
    do {
      fVar7 = _DAT_00a171c8;
      fVar2 = *(float *)(iVar3 + (uVar11 + uVar8 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_58 + param_3[-3]) * DAT_009bfa74;
      fVar5 = (local_54 + param_3[-2]) * DAT_009bfa74;
      fVar6 = (local_4c + *param_3) * DAT_00a10a2c;
      local_38 = (int)ROUND(fVar4 + fVar2);
      uVar17 = (uint)ROUND(fVar5 + fVar2);
      iVar12 = (int)ROUND(fVar6 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + local_c);
        local_58 = (fVar4 - (float)local_38) * _DAT_00a171c8;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar16);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + local_c);
        local_58 = local_58 * (float)_DAT_00a171b8;
        fVar7 = (fVar5 - (float)(int)uVar17) * fVar7;
        *pfVar1 = _DAT_00a171c4 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar9);
        *pfVar1 = _DAT_00a171c0 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar16);
        *pfVar1 = DAT_009af898 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + local_c);
        local_54 = fVar7 * (float)_DAT_00a171b8;
        local_4c = (fVar6 - (float)iVar12) * _DAT_00a171a4;
        *pfVar1 = _DAT_00a171c4 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar16);
        *pfVar1 = DAT_009af898 * local_4c + *pfVar1;
        local_4c = local_4c * (float)_DAT_00a171b8;
      }
      iVar14 = local_38;
      if (0xe < local_38) {
        iVar14 = 0xf;
      }
      if (iVar14 < -0xe) {
        local_38 = -0xf;
      }
      else if (0xe < local_38) {
        local_38 = 0xf;
      }
      if ((int)uVar17 < 0xf) {
        uVar13 = uVar17;
      }
      else {
        uVar13 = 0xf;
      }
      if ((int)uVar13 < -0xe) {
        uVar17 = 0xfffffff1;
      }
      else if (0xe < (int)uVar17) {
        uVar17 = 0xf;
      }
      if (iVar12 < 0x3f) {
        iVar14 = iVar12;
      }
      else {
        iVar14 = 0x3f;
      }
      if (iVar14 < -0x3e) {
        iVar12 = -0x3f;
      }
      else if (0x3e < iVar12) {
        iVar12 = 0x3f;
      }
      *local_8 = (ushort)((uVar17 & 0x1f | iVar12 << 5) << 5) | (ushort)local_38 & 0x1f;
      local_8 = local_8 + iVar15;
      param_3 = param_3 + iVar15 * 4;
      local_c = local_c + iVar10;
      iVar9 = iVar9 + iVar10;
      iVar16 = iVar16 + iVar10;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b0dc4 @ 0x008b0dc4 ====

void FUN_008b0dc4(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,1);
  *in_ECX = &PTR_FUN_00a17214;
  return;
}


// ==== FUN_008b0de5 @ 0x008b0de5 ====

void FUN_008b0de5(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,1);
  *in_ECX = &PTR_FUN_00a17224;
  return;
}


// ==== FUN_008b0e06 @ 0x008b0e06 ====

void FUN_008b0e06(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,1);
  *in_ECX = &PTR_FUN_00a17234;
  return;
}


// ==== FUN_008b0e27 @ 0x008b0e27 ====

void FUN_008b0e27(byte param_1)

{
  void *in_ECX;
  
  FUN_008aac3e();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008b0e48 @ 0x008b0e48 ====

void FUN_008b0e48(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,1);
  *in_ECX = &PTR_FUN_00a17244;
  return;
}


// ==== FUN_008b0e69 @ 0x008b0e69 ====

void FUN_008b0e69(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,8,1);
  *in_ECX = &PTR_FUN_00a17254;
  return;
}


// ==== FUN_008b0e8a @ 0x008b0e8a ====

void FUN_008b0e8a(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,8,1);
  *in_ECX = &PTR_FUN_00a17264;
  return;
}


// ==== FUN_008b0eab @ 0x008b0eab ====

void FUN_008b0eab(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,1);
  *in_ECX = &PTR_FUN_00a17274;
  return;
}


// ==== FUN_008b0ecc @ 0x008b0ecc ====

void FUN_008b0ecc(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,1);
  *in_ECX = &PTR_FUN_00a17284;
  return;
}


// ==== FUN_008b0eed @ 0x008b0eed ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b0eed(uint param_1,uint param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  ushort in_FPUControlWord;
  float local_54;
  float local_50;
  float local_48;
  uint local_34;
  uint local_30;
  int local_28;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_54 = 0.0;
  local_50 = 0.0;
  local_48 = 0.0;
  uVar8 = param_1 & 3;
  uVar10 = param_2 & 3;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar14 = 0;
    iVar15 = 1;
    param_2 = 1;
  }
  else {
    iVar14 = *(int *)(in_ECX + 0x68) + -1;
    param_2 = -1;
    iVar15 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar15 * 0x10;
    iVar9 = iVar14 * 0x10;
    param_3 = (float *)(iVar9 + 0xc + (int)param_3);
    iVar16 = (iVar15 + iVar14) * 0x10;
    iVar14 = (iVar14 - param_2) * 0x10;
    do {
      fVar7 = _DAT_00a171dc;
      fVar2 = *(float *)(iVar3 + (uVar10 + uVar8 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_54 + param_3[-3]) * _DAT_00a171e0;
      fVar5 = (local_50 + param_3[-2]) * _DAT_00a171e0;
      fVar6 = (local_48 + *param_3) * DAT_0099d0b8;
      local_34 = (uint)ROUND(fVar4 + fVar2);
      local_30 = (uint)ROUND(fVar5 + fVar2);
      local_28 = (int)ROUND(fVar6 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar14);
        local_54 = (fVar4 - (float)(int)local_34) * _DAT_00a171dc;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar16);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar14);
        local_54 = local_54 * (float)_DAT_00a171b8;
        fVar7 = (fVar5 - (float)(int)local_30) * fVar7;
        *pfVar1 = _DAT_00a171c4 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar9);
        *pfVar1 = _DAT_00a171c0 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar16);
        *pfVar1 = DAT_009af898 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar14);
        local_50 = fVar7 * (float)_DAT_00a171b8;
        local_48 = (fVar6 - (float)local_28) * DAT_0099d0b0;
        *pfVar1 = _DAT_00a171c4 * local_48 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_48 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar16);
        *pfVar1 = DAT_009af898 * local_48 + *pfVar1;
        local_48 = local_48 * (float)_DAT_00a171b8;
      }
      uVar12 = local_34;
      if (0x7e < (int)local_34) {
        uVar12 = 0x7f;
      }
      if ((int)uVar12 < -0x7e) {
        local_34 = 0xffffff81;
      }
      else if (0x7e < (int)local_34) {
        local_34 = 0x7f;
      }
      uVar12 = local_30;
      if (0x7e < (int)local_30) {
        uVar12 = 0x7f;
      }
      if ((int)uVar12 < -0x7e) {
        local_30 = 0xffffff81;
      }
      else if (0x7e < (int)local_30) {
        local_30 = 0x7f;
      }
      iVar13 = local_28;
      if (0xfe < local_28) {
        iVar13 = 0xff;
      }
      if (iVar13 < -0xfe) {
        local_28 = -0xff;
      }
      else if (0xfe < local_28) {
        local_28 = 0xff;
      }
      *local_8 = (uint)CONCAT11((undefined1)local_28,(undefined1)local_30) << 8 | local_34 & 0xff;
      local_8 = local_8 + iVar15;
      param_3 = param_3 + iVar15 * 4;
      iVar9 = iVar9 + iVar11;
      iVar14 = iVar14 + iVar11;
      iVar16 = iVar16 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b1206 @ 0x008b1206 ====

void FUN_008b1206(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,1);
  *in_ECX = &PTR_FUN_00a17294;
  return;
}


// ==== FUN_008b1227 @ 0x008b1227 ====

void FUN_008b1227(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,1);
  *in_ECX = &PTR_FUN_00a172a4;
  return;
}


// ==== FUN_008b1248 @ 0x008b1248 ====

void FUN_008b1248(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,1);
  *in_ECX = &PTR_FUN_00a172b4;
  return;
}


// ==== FUN_008b1269 @ 0x008b1269 ====

void FUN_008b1269(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,1);
  *in_ECX = &PTR_FUN_00a172c4;
  return;
}


// ==== FUN_008b128a @ 0x008b128a ====

void FUN_008b128a(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,1);
  *in_ECX = &PTR_FUN_00a172d4;
  return;
}


// ==== FUN_008b12ab @ 0x008b12ab ====

void FUN_008b12ab(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x40,1);
  *in_ECX = &PTR_FUN_00a172e4;
  return;
}


// ==== FUN_008b12cc @ 0x008b12cc ====

void FUN_008b12cc(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,1);
  *in_ECX = &PTR_FUN_00a172f4;
  return;
}


// ==== FUN_008b12ed @ 0x008b12ed ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b12ed(uint param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  ushort in_FPUControlWord;
  uint uVar18;
  int iVar19;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  uint local_38;
  uint local_34;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_58 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * (int)param_2 + *(int *)(in_ECX + 0x20));
  uVar9 = param_1 & 3;
  uVar13 = (uint)param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar17 = 0;
    iVar14 = 1;
  }
  else {
    iVar17 = *(int *)(in_ECX + 0x68) + -1;
    iVar14 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar14 * 0x10;
    iVar10 = iVar17 * 0x10;
    param_2 = (float *)(iVar10 + 8 + param_3);
    iVar12 = (iVar14 + iVar17) * 0x10;
    iVar17 = (iVar17 - iVar14) * 0x10;
    do {
      fVar8 = _DAT_00a171dc;
      fVar2 = *(float *)(iVar3 + (uVar13 + uVar9 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_58 + param_2[-2]) * _DAT_00a171e0;
      fVar5 = (local_54 + param_2[-1]) * _DAT_00a171e0;
      fVar6 = (local_50 + *param_2) * _DAT_00a171e0;
      fVar7 = (local_4c + param_2[1]) * _DAT_00a171e0;
      local_38 = (uint)ROUND(fVar4 + fVar2);
      local_34 = (uint)ROUND(fVar5 + fVar2);
      uVar18 = (uint)ROUND(fVar6 + fVar2);
      iVar19 = (int)ROUND(fVar7 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar17);
        local_58 = (fVar4 - (float)(int)local_38) * _DAT_00a171dc;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar17);
        local_58 = local_58 * (float)_DAT_00a171b8;
        local_54 = (fVar5 - (float)(int)local_34) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar17);
        local_54 = local_54 * (float)_DAT_00a171b8;
        local_50 = (fVar6 - (float)(int)uVar18) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar12);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar17);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar8 = (fVar7 - (float)iVar19) * fVar8;
        *pfVar1 = _DAT_00a171c4 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar10);
        *pfVar1 = _DAT_00a171c0 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar12);
        *pfVar1 = DAT_009af898 * fVar8 + *pfVar1;
        local_4c = fVar8 * (float)_DAT_00a171b8;
      }
      uVar15 = local_38;
      if (0x7e < (int)local_38) {
        uVar15 = 0x7f;
      }
      if ((int)uVar15 < -0x7e) {
        local_38 = 0xffffff81;
      }
      else if (0x7e < (int)local_38) {
        local_38 = 0x7f;
      }
      uVar15 = local_34;
      if (0x7e < (int)local_34) {
        uVar15 = 0x7f;
      }
      if ((int)uVar15 < -0x7e) {
        local_34 = 0xffffff81;
      }
      else if (0x7e < (int)local_34) {
        local_34 = 0x7f;
      }
      if ((int)uVar18 < 0x7f) {
        uVar15 = uVar18;
      }
      else {
        uVar15 = 0x7f;
      }
      if ((int)uVar15 < -0x7e) {
        uVar18 = 0xffffff81;
      }
      else if (0x7e < (int)uVar18) {
        uVar18 = 0x7f;
      }
      iVar16 = iVar19;
      if (0x7e < iVar19) {
        iVar16 = 0x7f;
      }
      if (iVar16 < -0x7e) {
        iVar19 = -0x7f;
      }
      else if (0x7e < iVar19) {
        iVar19 = 0x7f;
      }
      *local_8 = ((uVar18 & 0xff | iVar19 << 8) << 8 | local_34 & 0xff) << 8 | local_38 & 0xff;
      local_8 = local_8 + iVar14;
      param_2 = param_2 + iVar14 * 4;
      iVar10 = iVar10 + iVar11;
      iVar17 = iVar17 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b1699 @ 0x008b1699 ====

void FUN_008b1699(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,8,1);
  *in_ECX = &PTR_FUN_00a17304;
  return;
}


// ==== FUN_008b16ba @ 0x008b16ba ====

void FUN_008b16ba(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,8,1);
  *in_ECX = &PTR_FUN_00a17314;
  return;
}


// ==== FUN_008b16db @ 0x008b16db ====

void FUN_008b16db(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,1);
  *in_ECX = &PTR_FUN_00a17324;
  return;
}


// ==== FUN_008b16fc @ 0x008b16fc ====

void FUN_008b16fc(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,8,1);
  *in_ECX = &PTR_FUN_00a17334;
  return;
}


// ==== FUN_008b171d @ 0x008b171d ====

void FUN_008b171d(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,1);
  *in_ECX = &PTR_FUN_00a17344;
  return;
}


// ==== FUN_008b173e @ 0x008b173e ====

void FUN_008b173e(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,2);
  *in_ECX = &PTR_FUN_00a17354;
  return;
}


// ==== FUN_008b175f @ 0x008b175f ====

void FUN_008b175f(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,2);
  *in_ECX = &PTR_FUN_00a17364;
  return;
}


// ==== FUN_008b1780 @ 0x008b1780 ====

void FUN_008b1780(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,2);
  *in_ECX = &PTR_FUN_00a17374;
  return;
}


// ==== FUN_008b17a1 @ 0x008b17a1 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b17a1(uint param_1,uint param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  int iVar8;
  int in_ECX;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  ushort in_FPUControlWord;
  float local_44;
  float local_40;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_44 = 0.0;
  local_40 = 0.0;
  uVar7 = param_1 & 3;
  uVar9 = param_2 & 3;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar15 = 0;
    iVar12 = 1;
  }
  else {
    iVar15 = *(int *)(in_ECX + 0x68) + -1;
    iVar12 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar10 = iVar12 * 0x10;
    iVar8 = iVar15 << 4;
    iVar11 = (iVar12 + iVar15) * 0x10;
    param_2 = (iVar15 - iVar12) * 0x10;
    do {
      fVar6 = _DAT_0099d07c;
      fVar2 = *(float *)(iVar3 + (uVar9 + uVar7 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_44 + *(float *)(param_3 + iVar8)) * _DAT_00a17384;
      fVar5 = (local_40 + ((float *)(param_3 + iVar8))[1]) * _DAT_00a17384;
      uVar16 = (uint)ROUND(fVar4 + fVar2);
      iVar15 = (int)ROUND(fVar5 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(param_2 + 0x10 + *(int *)(in_ECX + 0x5c));
        local_44 = (fVar4 - (float)(int)uVar16) * _DAT_0099d07c;
        *pfVar1 = _DAT_00a171c4 * local_44 + *pfVar1;
        pfVar1 = (float *)(iVar8 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = _DAT_00a171c0 * local_44 + *pfVar1;
        pfVar1 = (float *)(iVar11 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = DAT_009af898 * local_44 + *pfVar1;
        pfVar1 = (float *)(param_2 + 0x14 + *(int *)(in_ECX + 0x5c));
        local_44 = local_44 * (float)_DAT_00a171b8;
        fVar6 = (fVar5 - (float)iVar15) * fVar6;
        *pfVar1 = _DAT_00a171c4 * fVar6 + *pfVar1;
        pfVar1 = (float *)(iVar8 + 0x14 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = _DAT_00a171c0 * fVar6 + *pfVar1;
        pfVar1 = (float *)(iVar11 + 0x14 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = DAT_009af898 * fVar6 + *pfVar1;
        local_40 = fVar6 * (float)_DAT_00a171b8;
      }
      uVar13 = uVar16;
      if (0x7ffe < (int)uVar16) {
        uVar13 = 0x7fff;
      }
      if ((int)uVar13 < -0x7ffe) {
        uVar16 = 0xffff8001;
      }
      else if (0x7ffe < (int)uVar16) {
        uVar16 = 0x7fff;
      }
      iVar14 = iVar15;
      if (0x7ffe < iVar15) {
        iVar14 = 0x7fff;
      }
      if (iVar14 < -0x7ffe) {
        iVar15 = -0x7fff;
      }
      else if (0x7ffe < iVar15) {
        iVar15 = 0x7fff;
      }
      *local_8 = iVar15 << 0x10 | uVar16 & 0xffff;
      local_8 = local_8 + iVar12;
      param_2 = param_2 + iVar10;
      iVar8 = iVar8 + iVar10;
      iVar11 = iVar11 + iVar10;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b1a18 @ 0x008b1a18 ====

void FUN_008b1a18(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,3);
  *in_ECX = &PTR_FUN_00a17388;
  return;
}


// ==== FUN_008b1a39 @ 0x008b1a39 ====

void FUN_008b1a39(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,2);
  *in_ECX = &PTR_FUN_00a17398;
  return;
}


// ==== FUN_008b1a5a @ 0x008b1a5a ====

void FUN_008b1a5a(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,2);
  *in_ECX = &PTR_FUN_00a173a8;
  return;
}


// ==== FUN_008b1a7b @ 0x008b1a7b ====

void FUN_008b1a7b(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x40,3);
  *in_ECX = &PTR_FUN_00a173b8;
  return;
}


// ==== FUN_008b1a9c @ 0x008b1a9c ====

void FUN_008b1a9c(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,2);
  *in_ECX = &PTR_FUN_00a173c8;
  return;
}


// ==== FUN_008b1abd @ 0x008b1abd ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b1abd(uint param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  ushort in_FPUControlWord;
  int iVar19;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  uint local_38;
  uint local_34;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_58 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * (int)param_2 + *(int *)(in_ECX + 0x20));
  uVar9 = param_1 & 3;
  uVar13 = (uint)param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar18 = 0;
    iVar15 = 1;
  }
  else {
    iVar18 = *(int *)(in_ECX + 0x68) + -1;
    iVar15 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar15 * 0x10;
    iVar10 = iVar18 * 0x10;
    param_2 = (float *)(iVar10 + 8 + param_3);
    iVar12 = (iVar15 + iVar18) * 0x10;
    iVar18 = (iVar18 - iVar15) * 0x10;
    do {
      fVar8 = _DAT_00a173d8;
      fVar2 = *(float *)(iVar3 + (uVar13 + uVar9 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_58 + param_2[-2]) * _DAT_00a173dc;
      fVar5 = (local_54 + param_2[-1]) * _DAT_00a173dc;
      fVar6 = (local_50 + *param_2) * _DAT_00a173dc;
      fVar7 = (local_4c + param_2[1]) * DAT_009b0300;
      local_38 = (uint)ROUND(fVar4 + fVar2);
      local_34 = (uint)ROUND(fVar5 + fVar2);
      uVar14 = (uint)ROUND(fVar6 + fVar2);
      iVar19 = (int)ROUND(fVar7 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar18);
        local_58 = (fVar4 - (float)(int)local_38) * _DAT_00a173d8;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar18);
        local_58 = local_58 * (float)_DAT_00a171b8;
        local_54 = (fVar5 - (float)(int)local_34) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar18);
        local_54 = local_54 * (float)_DAT_00a171b8;
        fVar8 = (fVar6 - (float)(int)uVar14) * fVar8;
        *pfVar1 = _DAT_00a171c4 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar10);
        *pfVar1 = _DAT_00a171c0 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar12);
        *pfVar1 = DAT_009af898 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar18);
        local_50 = fVar8 * (float)_DAT_00a171b8;
        local_4c = (fVar7 - (float)iVar19) * _DAT_009fc7c8;
        *pfVar1 = _DAT_00a171c4 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar12);
        *pfVar1 = DAT_009af898 * local_4c + *pfVar1;
        local_4c = local_4c * (float)_DAT_00a171b8;
      }
      uVar16 = local_38;
      if (0x1fe < (int)local_38) {
        uVar16 = 0x1ff;
      }
      if ((int)uVar16 < -0x1fe) {
        local_38 = 0xfffffe01;
      }
      else if (0x1fe < (int)local_38) {
        local_38 = 0x1ff;
      }
      uVar16 = local_34;
      if (0x1fe < (int)local_34) {
        uVar16 = 0x1ff;
      }
      if ((int)uVar16 < -0x1fe) {
        local_34 = 0xfffffe01;
      }
      else if (0x1fe < (int)local_34) {
        local_34 = 0x1ff;
      }
      uVar16 = uVar14;
      if (0x1fe < (int)uVar14) {
        uVar16 = 0x1ff;
      }
      if ((int)uVar16 < -0x1fe) {
        uVar14 = 0xfffffe01;
      }
      else if (0x1fe < (int)uVar14) {
        uVar14 = 0x1ff;
      }
      iVar17 = iVar19;
      if (2 < iVar19) {
        iVar17 = 3;
      }
      if (iVar17 < -2) {
        iVar19 = -3;
      }
      else if (2 < iVar19) {
        iVar19 = 3;
      }
      *local_8 = ((uVar14 & 0x3ff | iVar19 << 10) << 10 | local_34 & 0x3ff) << 10 | local_38 & 0x3ff
      ;
      local_8 = local_8 + iVar15;
      param_2 = param_2 + iVar15 * 4;
      iVar10 = iVar10 + iVar11;
      iVar18 = iVar18 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b1e97 @ 0x008b1e97 ====

void FUN_008b1e97(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,4);
  *in_ECX = &PTR_FUN_00a173e0;
  return;
}


// ==== FUN_008b1eb8 @ 0x008b1eb8 ====

void FUN_008b1eb8(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x10,4);
  *in_ECX = &PTR_FUN_00a173f0;
  return;
}


// ==== FUN_008b1ed9 @ 0x008b1ed9 ====

void FUN_008b1ed9(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,4);
  *in_ECX = &PTR_FUN_00a17400;
  return;
}


// ==== FUN_008b1efa @ 0x008b1efa ====

void FUN_008b1efa(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x40,4);
  *in_ECX = &PTR_FUN_00a17410;
  return;
}


// ==== FUN_008b1f1b @ 0x008b1f1b ====

void FUN_008b1f1b(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x40,4);
  *in_ECX = &PTR_FUN_00a17420;
  return;
}


// ==== FUN_008b1f3c @ 0x008b1f3c ====

void FUN_008b1f3c(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x80,4);
  *in_ECX = &PTR_FUN_00a17430;
  return;
}


// ==== FUN_008b1f60 @ 0x008b1f60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b1f60(uint param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  ushort in_FPUControlWord;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_10;
  int local_c;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_60 = 0.0;
  local_5c = 0.0;
  local_58 = 0.0;
  local_54 = 0.0;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 8 +
                     *(int *)(in_ECX + 100) * (int)param_2 + *(int *)(in_ECX + 0x20));
  uVar9 = param_1 & 3;
  uVar12 = (uint)param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar14 = 0;
    iVar13 = 1;
  }
  else {
    iVar14 = *(int *)(in_ECX + 0x68) + -1;
    iVar13 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar10 = iVar13 * 0x10;
    iVar11 = iVar14 * 0x10;
    local_10 = (iVar13 + iVar14) * 0x10;
    local_c = (iVar14 - iVar13) * 0x10;
    param_2 = (float *)(iVar11 + 8 + param_3);
    do {
      fVar8 = _DAT_0099d07c;
      fVar2 = *(float *)(iVar3 + (uVar12 + uVar9 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_60 + param_2[-2]) * _DAT_00a17384;
      fVar5 = (local_5c + param_2[-1]) * _DAT_00a17384;
      fVar6 = (local_58 + *param_2) * _DAT_00a17384;
      fVar7 = (local_54 + param_2[1]) * _DAT_00a17384;
      local_40 = (uint)ROUND(fVar4 + fVar2);
      local_3c = (int)ROUND(fVar5 + fVar2);
      local_38 = (uint)ROUND(fVar6 + fVar2);
      local_34 = (int)ROUND(fVar7 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + local_c);
        local_60 = (fVar4 - (float)(int)local_40) * _DAT_0099d07c;
        *pfVar1 = _DAT_00a171c4 * local_60 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar11);
        *pfVar1 = _DAT_00a171c0 * local_60 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + local_10);
        *pfVar1 = DAT_009af898 * local_60 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + local_c);
        local_60 = local_60 * (float)_DAT_00a171b8;
        local_5c = (fVar5 - (float)local_3c) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_5c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar11);
        *pfVar1 = _DAT_00a171c0 * local_5c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + local_10);
        *pfVar1 = DAT_009af898 * local_5c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + local_c);
        local_5c = local_5c * (float)_DAT_00a171b8;
        local_58 = (fVar6 - (float)(int)local_38) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar11);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + local_10);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + local_c);
        local_58 = local_58 * (float)_DAT_00a171b8;
        fVar8 = (fVar7 - (float)local_34) * fVar8;
        *pfVar1 = _DAT_00a171c4 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar11);
        *pfVar1 = _DAT_00a171c0 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + local_10);
        *pfVar1 = DAT_009af898 * fVar8 + *pfVar1;
        local_54 = fVar8 * (float)_DAT_00a171b8;
      }
      uVar15 = local_40;
      if (0x7ffe < (int)local_40) {
        uVar15 = 0x7fff;
      }
      if ((int)uVar15 < -0x7ffe) {
        local_40 = 0xffff8001;
      }
      else if (0x7ffe < (int)local_40) {
        local_40 = 0x7fff;
      }
      iVar14 = local_3c;
      if (0x7ffe < local_3c) {
        iVar14 = 0x7fff;
      }
      if (iVar14 < -0x7ffe) {
        local_3c = -0x7fff;
      }
      else if (0x7ffe < local_3c) {
        local_3c = 0x7fff;
      }
      uVar15 = local_38;
      if (0x7ffe < (int)local_38) {
        uVar15 = 0x7fff;
      }
      if ((int)uVar15 < -0x7ffe) {
        local_38 = 0xffff8001;
      }
      else if (0x7ffe < (int)local_38) {
        local_38 = 0x7fff;
      }
      iVar14 = local_34;
      if (0x7ffe < local_34) {
        iVar14 = 0x7fff;
      }
      if (iVar14 < -0x7ffe) {
        local_34 = -0x7fff;
      }
      else if (0x7ffe < local_34) {
        local_34 = 0x7fff;
      }
      local_8[1] = local_34 << 0x10 | local_38 & 0xffff;
      *local_8 = local_3c << 0x10 | local_40 & 0xffff;
      local_8 = local_8 + iVar13 * 2;
      param_2 = param_2 + iVar13 * 4;
      local_c = local_c + iVar10;
      local_10 = local_10 + iVar10;
      iVar11 = iVar11 + iVar10;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b2335 @ 0x008b2335 ====

void FUN_008b2335(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x20,1);
  *in_ECX = &PTR_FUN_00a17440;
  return;
}


// ==== FUN_008b2356 @ 0x008b2356 ====

void FUN_008b2356(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008abd0d(param_1,0x30,1);
  *in_ECX = &PTR_FUN_00a17450;
  return;
}


// ==== FUN_008b2377 @ 0x008b2377 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b2377(uint param_1,uint param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int in_ECX;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined2 in_FPUControlWord;
  float local_48;
  float local_44;
  undefined2 *local_c;
  uint local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_48 = 0.0;
  local_44 = 0.0;
  uVar9 = param_1 & 3;
  uVar12 = param_2 & 3;
  local_c = (undefined2 *)
            (*(int *)(in_ECX + 0x60) * param_1 + (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2
             + *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar14 = 0;
    param_1 = 1;
  }
  else {
    iVar14 = *(int *)(in_ECX + 0x68) + -1;
    param_1 = -1;
  }
  iVar8 = param_1;
  param_2 = CONCAT22(param_2._2_2_,in_FPUControlWord);
  *(uint *)(in_ECX + 0x7c) = param_2;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  local_8 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar10 = param_1 * 0x10;
    param_2 = (param_1 + iVar14) * 0x10;
    iVar15 = iVar14 << 4;
    param_1 = (iVar14 - param_1) * 0x10;
    do {
      pfVar1 = (float *)(iVar15 + param_3);
      thunk_FUN_0079e1ba(pfVar1,pfVar1);
      fVar7 = _DAT_00a171dc;
      fVar2 = *(float *)(iVar3 + (uVar12 + uVar9 * 8) * 4 + (local_8 & 3) * 4);
      fVar5 = (local_48 + *pfVar1) * _DAT_00a171e0;
      fVar6 = (local_44 + pfVar1[1]) * _DAT_00a171e0;
      iVar14 = (int)ROUND(fVar5 + fVar2);
      iVar13 = (int)ROUND(fVar6 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + param_1);
        local_48 = (fVar5 - (float)iVar14) * _DAT_00a171dc;
        *pfVar1 = _DAT_00a171c4 * local_48 + *pfVar1;
        pfVar1 = (float *)(iVar15 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = _DAT_00a171c0 * local_48 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + param_2);
        *pfVar1 = DAT_009af898 * local_48 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + param_1);
        local_48 = local_48 * (float)_DAT_00a171b8;
        fVar7 = (fVar6 - (float)iVar13) * fVar7;
        *pfVar1 = _DAT_00a171c4 * fVar7 + *pfVar1;
        pfVar1 = (float *)(iVar15 + 0x14 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = _DAT_00a171c0 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + param_2);
        *pfVar1 = DAT_009af898 * fVar7 + *pfVar1;
        local_44 = fVar7 * (float)_DAT_00a171b8;
      }
      iVar4 = 0x7f;
      iVar11 = iVar14;
      if (0x7e < iVar14) {
        iVar11 = iVar4;
      }
      if (iVar11 < -0x7e) {
        iVar14 = -0x7f;
      }
      else if (0x7e < iVar14) {
        iVar14 = iVar4;
      }
      iVar11 = iVar13;
      if (0x7e < iVar13) {
        iVar11 = iVar4;
      }
      if (iVar11 < -0x7e) {
        iVar13 = -0x7f;
      }
      else if (0x7e < iVar13) {
        iVar13 = iVar4;
      }
      *local_c = CONCAT11((char)iVar13,(char)iVar14);
      local_c = local_c + iVar8;
      param_1 = param_1 + iVar10;
      param_2 = param_2 + iVar10;
      iVar15 = iVar15 + iVar10;
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b25e7 @ 0x008b25e7 ====

void FUN_008b25e7(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int in_ECX;
  uint uVar2;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (undefined4 *)FUN_008ac18d(param_3);
  }
  puVar1 = (undefined4 *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  uVar2 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    do {
      *puVar1 = *param_3;
      puVar1 = puVar1 + 1;
      uVar2 = uVar2 + 1;
      param_3 = param_3 + 4;
    } while (uVar2 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b2634 @ 0x008b2634 ====

void FUN_008b2634(int param_1,int param_2,int param_3)

{
  int in_ECX;
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  iVar2 = *(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
          *(int *)(in_ECX + 0x20);
  if (*(int *)(in_ECX + 0x68) != 0) {
    do {
      thunk_FUN_0079dcfc(iVar2,param_3,1);
      param_3 = param_3 + 0x10;
      iVar2 = iVar2 + 2;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b268c @ 0x008b268c ====

void FUN_008b268c(int param_1,int param_2,int param_3)

{
  int in_ECX;
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  iVar2 = *(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
          *(int *)(in_ECX + 0x20);
  if (*(int *)(in_ECX + 0x68) != 0) {
    do {
      thunk_FUN_0079dcfc(iVar2,param_3,2);
      param_3 = param_3 + 0x10;
      iVar2 = iVar2 + 4;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b26e5 @ 0x008b26e5 ====

void FUN_008b26e5(int param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  thunk_FUN_0079dcfc(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                     *(int *)(in_ECX + 0x20),param_3,*(int *)(in_ECX + 0x68) << 2);
  return;
}


// ==== FUN_008b2726 @ 0x008b2726 ====

void FUN_008b2726(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int in_ECX;
  uint uVar2;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (undefined4 *)FUN_008ac18d(param_3);
  }
  puVar1 = (undefined4 *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  uVar2 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    do {
      *puVar1 = *param_3;
      puVar1[1] = param_3[1];
      puVar1 = puVar1 + 2;
      uVar2 = uVar2 + 1;
      param_3 = param_3 + 4;
    } while (uVar2 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b2779 @ 0x008b2779 ====

void FUN_008b2779(int param_1,int param_2,undefined4 *param_3)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (undefined4 *)FUN_008ac18d(param_3);
  }
  puVar2 = (undefined4 *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  for (iVar1 = (*(uint *)(in_ECX + 0x68) & 0xfffffff) << 2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_3;
    param_3 = param_3 + 1;
    puVar2 = puVar2 + 1;
  }
  for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined1 *)puVar2 = *(undefined1 *)param_3;
    param_3 = (undefined4 *)((int)param_3 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return;
}


// ==== FUN_008b27c5 @ 0x008b27c5 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b27c5(uint param_1,uint param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  float *pfVar8;
  int iVar9;
  int in_ECX;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ushort in_FPUControlWord;
  float local_54;
  float local_48;
  uint local_34;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_54 = 0.0;
  local_48 = 0.0;
  uVar7 = param_1 & 3;
  uVar10 = param_2 & 3;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  iVar2 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar14 = 0;
    param_2 = 1;
  }
  else {
    iVar14 = *(int *)(in_ECX + 0x68) + -1;
    param_2 = -1;
  }
  iVar6 = param_2;
  param_1 = (uint)in_FPUControlWord;
  uVar11 = 0;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x68) != 0) {
    pfVar8 = param_3;
    do {
      uVar11 = uVar11 + 1;
      *pfVar8 = *pfVar8 * _DAT_009fc7b4 + pfVar8[1] * _DAT_009fc7ac + pfVar8[2] * _DAT_009fc7b0;
      pfVar8 = pfVar8 + 4;
    } while (uVar11 < *(uint *)(in_ECX + 0x68));
  }
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar12 = param_2 * 0x10;
    iVar9 = iVar14 << 4;
    iVar13 = (param_2 + iVar14) * 0x10;
    param_2 = (iVar14 - param_2) * 0x10;
    do {
      fVar5 = _DAT_00a171d8;
      fVar1 = *(float *)(iVar2 + (uVar10 + uVar7 * 8) * 4 + (param_1 & 3) * 4);
      fVar3 = (local_54 + *(float *)((int)param_3 + iVar9)) * _DAT_00a16814;
      fVar4 = (local_48 + ((float *)((int)param_3 + iVar9))[3]) * _DAT_00a16814;
      local_34 = (uint)ROUND(fVar3 + fVar1);
      iVar14 = (int)ROUND(fVar4 + fVar1);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar8 = (float *)(param_2 + 0x10 + *(int *)(in_ECX + 0x5c));
        local_54 = (fVar3 - (float)(int)local_34) * _DAT_00a171d8;
        *pfVar8 = _DAT_00a171c4 * local_54 + *pfVar8;
        pfVar8 = (float *)(iVar9 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar8 = _DAT_00a171c0 * local_54 + *pfVar8;
        pfVar8 = (float *)(iVar13 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar8 = DAT_009af898 * local_54 + *pfVar8;
        pfVar8 = (float *)(param_2 + 0x1c + *(int *)(in_ECX + 0x5c));
        local_54 = local_54 * (float)_DAT_00a171b8;
        fVar5 = (fVar4 - (float)iVar14) * fVar5;
        *pfVar8 = _DAT_00a171c4 * fVar5 + *pfVar8;
        pfVar8 = (float *)(iVar9 + 0x1c + *(int *)(in_ECX + 0x5c));
        *pfVar8 = _DAT_00a171c0 * fVar5 + *pfVar8;
        pfVar8 = (float *)(iVar13 + 0x1c + *(int *)(in_ECX + 0x5c));
        *pfVar8 = DAT_009af898 * fVar5 + *pfVar8;
        local_48 = fVar5 * (float)_DAT_00a171b8;
      }
      uVar11 = local_34;
      if (0xfffe < (int)local_34) {
        uVar11 = 0xffff;
      }
      if ((int)uVar11 < 1) {
        local_34 = 0;
      }
      else if (0xfffe < (int)local_34) {
        local_34 = 0xffff;
      }
      iVar15 = iVar14;
      if (0xfffe < iVar14) {
        iVar15 = 0xffff;
      }
      if (iVar15 < 1) {
        iVar14 = 0;
      }
      else if (0xfffe < iVar14) {
        iVar14 = 0xffff;
      }
      *local_8 = iVar14 << 0x10 | local_34;
      local_8 = local_8 + iVar6;
      param_2 = param_2 + iVar12;
      iVar9 = iVar9 + iVar12;
      iVar13 = iVar13 + iVar12;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b2a6d @ 0x008b2a6d ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b2a6d(uint param_1,uint param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined2 *puVar16;
  undefined2 in_FPUControlWord;
  float local_54;
  float local_50;
  float local_4c;
  int local_34;
  int local_30;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  uVar10 = param_1 & 3;
  uVar8 = param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  puVar16 = (undefined2 *)
            (*(int *)(in_ECX + 0x60) * param_1 + (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 6
             + *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  if ((param_1 & 1) == 0) {
    iVar14 = 0;
    iVar13 = 1;
    param_1 = 1;
  }
  else {
    iVar14 = *(int *)(in_ECX + 0x68) + -1;
    param_1 = -1;
    iVar13 = -1;
  }
  param_2 = CONCAT22(param_2._2_2_,in_FPUControlWord);
  *(uint *)(in_ECX + 0x7c) = param_2;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
    iVar13 = param_1;
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar13 * 0x10;
    iVar9 = iVar14 * 0x10;
    iVar12 = (iVar13 + iVar14) * 0x10;
    param_2 = (iVar14 - iVar13) * 0x10;
    param_3 = (float *)(iVar9 + 8 + (int)param_3);
    do {
      fVar7 = _DAT_00a171d8;
      fVar2 = *(float *)(iVar3 + (uVar8 + uVar10 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_54 + param_3[-2]) * _DAT_00a16814;
      fVar5 = (local_50 + param_3[-1]) * _DAT_00a16814;
      fVar6 = (local_4c + *param_3) * _DAT_00a16814;
      local_34 = (int)ROUND(fVar4 + fVar2);
      local_30 = (int)ROUND(fVar5 + fVar2);
      iVar14 = (int)ROUND(fVar6 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + param_2);
        local_54 = (fVar4 - (float)local_34) * _DAT_00a171d8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + param_2);
        local_54 = local_54 * (float)_DAT_00a171b8;
        local_50 = (fVar5 - (float)local_30) * fVar7;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + param_2);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar7 = (fVar6 - (float)iVar14) * fVar7;
        *pfVar1 = _DAT_00a171c4 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar9);
        *pfVar1 = _DAT_00a171c0 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar12);
        *pfVar1 = DAT_009af898 * fVar7 + *pfVar1;
        local_4c = fVar7 * (float)_DAT_00a171b8;
      }
      iVar15 = local_34;
      if (0xfffe < local_34) {
        iVar15 = 0xffff;
      }
      if (iVar15 < 1) {
        local_34 = 0;
      }
      else if (0xfffe < local_34) {
        local_34 = 0xffff;
      }
      iVar15 = local_30;
      if (0xfffe < local_30) {
        iVar15 = 0xffff;
      }
      if (iVar15 < 1) {
        local_30 = 0;
      }
      else if (0xfffe < local_30) {
        local_30 = 0xffff;
      }
      iVar15 = iVar14;
      if (0xfffe < iVar14) {
        iVar15 = 0xffff;
      }
      if (iVar15 < 1) {
        iVar14 = 0;
      }
      else if (0xfffe < iVar14) {
        iVar14 = 0xffff;
      }
      puVar16[1] = (undefined2)local_30;
      puVar16[2] = (undefined2)local_34;
      param_3 = param_3 + iVar13 * 4;
      param_2 = param_2 + iVar11;
      *puVar16 = (short)iVar14;
      puVar16 = puVar16 + iVar13 * 3;
      iVar9 = iVar9 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008b2d70 @ 0x008b2d70 ====

void FUN_008b2d70(int param_1,int param_2,float *param_3)

{
  byte bVar1;
  float fVar2;
  byte *pbVar3;
  int in_ECX;
  int extraout_ECX;
  byte *pbVar4;
  float *pfVar5;
  
  fVar2 = DAT_0099d0b0;
  pbVar3 = (byte *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pbVar4 = pbVar3 + *(int *)(in_ECX + 0x74);
  pfVar5 = param_3;
  if (pbVar3 < pbVar4) {
    do {
      *param_3 = (float)pbVar3[2] * fVar2;
      pfVar5 = param_3 + 4;
      param_3[1] = (float)pbVar3[1] * fVar2;
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + 3;
      param_3[2] = (float)bVar1 * fVar2;
      param_3[3] = 1.0;
      param_3 = pfVar5;
    } while (pbVar3 < pbVar4);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b2e08 @ 0x008b2e08 ====

/* WARNING: Removing unreachable block (ram,0x008b2e64) */

void FUN_008b2e08(int param_1,int param_2,float *param_3)

{
  uint *puVar1;
  float fVar2;
  uint *puVar3;
  uint *puVar4;
  int in_ECX;
  int extraout_ECX;
  float *pfVar5;
  
  fVar2 = DAT_0099d0b0;
  puVar3 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  puVar1 = puVar3 + *(int *)(in_ECX + 0x68);
  pfVar5 = param_3;
  if (puVar3 < puVar1) {
    do {
      *param_3 = (float)*(byte *)((int)puVar3 + 2) * fVar2;
      param_3[1] = (float)*(byte *)((int)puVar3 + 1) * fVar2;
      puVar4 = puVar3 + 1;
      pfVar5 = param_3 + 4;
      param_3[2] = (float)(*puVar3 & 0xff) * fVar2;
      param_3[3] = (float)*(byte *)((int)puVar3 + 3) * fVar2;
      puVar3 = puVar4;
      param_3 = pfVar5;
    } while (puVar4 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b2eba @ 0x008b2eba ====

/* WARNING: Removing unreachable block (ram,0x008b2f16) */

void FUN_008b2eba(int param_1,int param_2,float *param_3)

{
  uint *puVar1;
  uint uVar2;
  float fVar3;
  uint *puVar4;
  int in_ECX;
  int extraout_ECX;
  float *pfVar5;
  
  fVar3 = DAT_0099d0b0;
  puVar4 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  puVar1 = puVar4 + *(int *)(in_ECX + 0x68);
  pfVar5 = param_3;
  if (puVar4 < puVar1) {
    do {
      *param_3 = (float)*(byte *)((int)puVar4 + 2) * fVar3;
      param_3[1] = (float)*(byte *)((int)puVar4 + 1) * fVar3;
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      pfVar5 = param_3 + 4;
      param_3[2] = (float)(uVar2 & 0xff) * fVar3;
      param_3[3] = 1.0;
      param_3 = pfVar5;
    } while (puVar4 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b2f62 @ 0x008b2f62 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b2f62(int param_1,int param_2,float *param_3)

{
  ushort *puVar1;
  float fVar2;
  ushort *puVar3;
  int in_ECX;
  int extraout_ECX;
  
  fVar2 = _DAT_00a171a8;
  puVar3 = (ushort *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  puVar1 = puVar3 + *(int *)(in_ECX + 0x68);
  for (; puVar3 < puVar1; puVar3 = puVar3 + 1) {
    *param_3 = (float)(*puVar3 >> 0xb) * fVar2;
    param_3[1] = (float)(*puVar3 >> 5 & 0x3f) * _DAT_00a171a4;
    param_3[2] = (float)((byte)*puVar3 & 0x1f) * fVar2;
    param_3[3] = 1.0;
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b300f @ 0x008b300f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b300f(int param_1,int param_2,float *param_3)

{
  ushort *puVar1;
  float fVar2;
  ushort *puVar3;
  int in_ECX;
  int extraout_ECX;
  
  fVar2 = _DAT_00a171a8;
  puVar3 = (ushort *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  puVar1 = puVar3 + *(int *)(in_ECX + 0x68);
  for (; puVar3 < puVar1; puVar3 = puVar3 + 1) {
    *param_3 = (float)(*puVar3 >> 10 & 0x1f) * fVar2;
    param_3[1] = (float)(*puVar3 >> 5 & 0x1f) * fVar2;
    param_3[2] = (float)((byte)*puVar3 & 0x1f) * fVar2;
    param_3[3] = 1.0;
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b30b9 @ 0x008b30b9 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b30b9(int param_1,int param_2,float *param_3)

{
  ushort *puVar1;
  float fVar2;
  ushort *puVar3;
  int in_ECX;
  int extraout_ECX;
  
  fVar2 = _DAT_00a171a8;
  puVar3 = (ushort *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  puVar1 = puVar3 + *(int *)(in_ECX + 0x68);
  for (; puVar3 < puVar1; puVar3 = puVar3 + 1) {
    *param_3 = (float)(*puVar3 >> 10 & 0x1f) * fVar2;
    param_3[1] = (float)(*puVar3 >> 5 & 0x1f) * fVar2;
    param_3[2] = (float)((byte)*puVar3 & 0x1f) * fVar2;
    param_3[3] = (float)(*puVar3 >> 0xf);
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3171 @ 0x008b3171 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3171(int param_1,int param_2,float *param_3)

{
  ushort *puVar1;
  float fVar2;
  ushort *puVar3;
  int in_ECX;
  int extraout_ECX;
  
  fVar2 = _DAT_00a171c8;
  puVar3 = (ushort *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  puVar1 = puVar3 + *(int *)(in_ECX + 0x68);
  for (; puVar3 < puVar1; puVar3 = puVar3 + 1) {
    *param_3 = (float)(*(byte *)((int)puVar3 + 1) & 0xf) * fVar2;
    param_3[1] = (float)(byte)((byte)*puVar3 >> 4) * fVar2;
    param_3[2] = (float)((byte)*puVar3 & 0xf) * fVar2;
    param_3[3] = (float)(*puVar3 >> 0xc) * fVar2;
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3228 @ 0x008b3228 ====

/* WARNING: Removing unreachable block (ram,0x008b3288) */
/* WARNING: Removing unreachable block (ram,0x008b326d) */
/* WARNING: Removing unreachable block (ram,0x008b32a4) */
/* WARNING: Removing unreachable block (ram,0x008b32be) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3228(int param_1,int param_2,float *param_3)

{
  uint *puVar1;
  uint uVar2;
  float fVar3;
  uint *puVar4;
  int in_ECX;
  int extraout_ECX;
  float *pfVar5;
  
  fVar3 = _DAT_00a171d0;
  puVar4 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  puVar1 = puVar4 + *(int *)(in_ECX + 0x68);
  pfVar5 = param_3;
  if (puVar4 < puVar1) {
    do {
      *param_3 = (float)(*puVar4 & 0x3ff) * fVar3;
      param_3[1] = (float)(*puVar4 >> 10 & 0x3ff) * fVar3;
      param_3[2] = (float)(*puVar4 >> 0x14 & 0x3ff) * fVar3;
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      pfVar5 = param_3 + 4;
      param_3[3] = (float)(uVar2 >> 0x1e) * _DAT_009fc7c8;
      param_3 = pfVar5;
    } while (puVar4 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b330a @ 0x008b330a ====

/* WARNING: Removing unreachable block (ram,0x008b3349) */

void FUN_008b330a(int param_1,int param_2,float *param_3)

{
  uint *puVar1;
  float fVar2;
  uint *puVar3;
  uint *puVar4;
  int in_ECX;
  int extraout_ECX;
  float *pfVar5;
  
  fVar2 = DAT_0099d0b0;
  puVar3 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  puVar1 = puVar3 + *(int *)(in_ECX + 0x68);
  pfVar5 = param_3;
  if (puVar3 < puVar1) {
    do {
      puVar4 = puVar3 + 1;
      *param_3 = (float)(*puVar3 & 0xff) * fVar2;
      pfVar5 = param_3 + 4;
      param_3[1] = (float)*(byte *)((int)puVar3 + 1) * fVar2;
      param_3[2] = (float)*(byte *)((int)puVar3 + 2) * fVar2;
      param_3[3] = (float)*(byte *)((int)puVar3 + 3) * fVar2;
      puVar3 = puVar4;
      param_3 = pfVar5;
    } while (puVar4 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b33bc @ 0x008b33bc ====

/* WARNING: Removing unreachable block (ram,0x008b33fb) */

void FUN_008b33bc(int param_1,int param_2,float *param_3)

{
  uint *puVar1;
  float fVar2;
  uint *puVar3;
  uint *puVar4;
  int in_ECX;
  int extraout_ECX;
  float *pfVar5;
  
  fVar2 = DAT_0099d0b0;
  puVar3 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  puVar1 = puVar3 + *(int *)(in_ECX + 0x68);
  pfVar5 = param_3;
  if (puVar3 < puVar1) {
    do {
      puVar4 = puVar3 + 1;
      *param_3 = (float)(*puVar3 & 0xff) * fVar2;
      pfVar5 = param_3 + 4;
      param_3[1] = (float)*(byte *)((int)puVar3 + 1) * fVar2;
      param_3[2] = (float)*(byte *)((int)puVar3 + 2) * fVar2;
      param_3[3] = 1.0;
      puVar3 = puVar4;
      param_3 = pfVar5;
    } while (puVar4 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3464 @ 0x008b3464 ====

/* WARNING: Removing unreachable block (ram,0x008b34a3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3464(int param_1,int param_2,float *param_3)

{
  uint *puVar1;
  float fVar2;
  uint *puVar3;
  uint *puVar4;
  int in_ECX;
  int extraout_ECX;
  float *pfVar5;
  
  fVar2 = _DAT_00a171d8;
  puVar3 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  puVar1 = puVar3 + *(int *)(in_ECX + 0x68);
  pfVar5 = param_3;
  if (puVar3 < puVar1) {
    do {
      puVar4 = puVar3 + 1;
      *param_3 = (float)(*puVar3 & 0xffff) * fVar2;
      pfVar5 = param_3 + 4;
      param_3[1] = (float)*(ushort *)((int)puVar3 + 2) * fVar2;
      param_3[2] = 1.0;
      param_3[3] = 1.0;
      puVar3 = puVar4;
      param_3 = pfVar5;
    } while (puVar4 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3502 @ 0x008b3502 ====

/* WARNING: Removing unreachable block (ram,0x008b3565) */
/* WARNING: Removing unreachable block (ram,0x008b354a) */
/* WARNING: Removing unreachable block (ram,0x008b357e) */
/* WARNING: Removing unreachable block (ram,0x008b3598) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3502(int param_1,int param_2,float *param_3)

{
  uint *puVar1;
  uint uVar2;
  float fVar3;
  uint *puVar4;
  int in_ECX;
  int extraout_ECX;
  float *pfVar5;
  
  fVar3 = _DAT_00a171d0;
  puVar4 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  puVar1 = puVar4 + *(int *)(in_ECX + 0x68);
  pfVar5 = param_3;
  if (puVar4 < puVar1) {
    do {
      *param_3 = (float)(*puVar4 >> 0x14 & 0x3ff) * fVar3;
      param_3[1] = (float)(*puVar4 >> 10 & 0x3ff) * fVar3;
      param_3[2] = (float)(*puVar4 & 0x3ff) * fVar3;
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      pfVar5 = param_3 + 4;
      param_3[3] = (float)(uVar2 >> 0x1e) * _DAT_009fc7c8;
      param_3 = pfVar5;
    } while (puVar4 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b35e4 @ 0x008b35e4 ====

/* WARNING: Removing unreachable block (ram,0x008b3650) */
/* WARNING: Removing unreachable block (ram,0x008b362e) */
/* WARNING: Removing unreachable block (ram,0x008b367e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b35e4(int param_1,int param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  ushort uVar3;
  int in_ECX;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  float *pfVar7;
  
  puVar4 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  iVar1 = *(int *)(in_ECX + 0x68);
  if (puVar4 < puVar4 + iVar1 * 2) {
    puVar5 = puVar4;
    pfVar7 = param_3;
    fVar2 = _DAT_00a171d8;
    do {
      *pfVar7 = (float)(*puVar5 & 0xffff) * fVar2;
      pfVar7[1] = (float)(*puVar5 >> 0x10) * fVar2;
      uVar3 = __aullshr();
      fVar2 = _DAT_00a171d8;
      puVar6 = puVar5 + 2;
      param_3 = pfVar7 + 4;
      pfVar7[2] = (float)uVar3 * _DAT_00a171d8;
      pfVar7[3] = (float)*(ushort *)((int)puVar5 + 6) * fVar2;
      puVar5 = puVar6;
      pfVar7 = param_3;
    } while (puVar6 < puVar4 + iVar1 * 2);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b36de @ 0x008b36de ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b36de(int param_1,int param_2,float *param_3)

{
  float fVar1;
  byte *pbVar2;
  int in_ECX;
  int extraout_ECX;
  byte *pbVar3;
  
  fVar1 = _DAT_00a171cc;
  pbVar2 = (byte *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pbVar3 = pbVar2 + *(int *)(in_ECX + 0x68);
  for (; pbVar2 < pbVar3; pbVar2 = pbVar2 + 1) {
    *param_3 = (float)(*pbVar2 >> 5) * fVar1;
    param_3[1] = (float)(*pbVar2 >> 2 & 7) * fVar1;
    param_3[2] = (float)(*pbVar2 & 3) * _DAT_009fc7c8;
    param_3[3] = 1.0;
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3788 @ 0x008b3788 ====

void FUN_008b3788(int param_1,int param_2,undefined4 *param_3)

{
  byte bVar1;
  byte *pbVar2;
  int in_ECX;
  int extraout_ECX;
  byte *pbVar3;
  undefined4 *puVar4;
  
  pbVar2 = (byte *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pbVar3 = pbVar2 + *(int *)(in_ECX + 0x68);
  puVar4 = param_3;
  if (pbVar2 < pbVar3) {
    do {
      *param_3 = 0;
      puVar4 = param_3 + 4;
      param_3[1] = 0;
      param_3[2] = 0;
      bVar1 = *pbVar2;
      pbVar2 = pbVar2 + 1;
      param_3[3] = (float)bVar1 * DAT_0099d0b0;
      param_3 = puVar4;
    } while (pbVar2 < pbVar3);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(puVar4 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(puVar4 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3806 @ 0x008b3806 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3806(int param_1,int param_2,float *param_3)

{
  byte *pbVar1;
  float fVar2;
  byte *pbVar3;
  int in_ECX;
  int extraout_ECX;
  
  fVar2 = _DAT_00a171cc;
  pbVar3 = (byte *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pbVar1 = pbVar3 + *(int *)(in_ECX + 0x68) * 2;
  for (; pbVar3 < pbVar1; pbVar3 = pbVar3 + 2) {
    *param_3 = (float)(*pbVar3 >> 5) * fVar2;
    param_3[1] = (float)(*pbVar3 >> 2 & 7) * fVar2;
    param_3[2] = (float)(*pbVar3 & 3) * _DAT_009fc7c8;
    param_3[3] = (float)pbVar3[1] * DAT_0099d0b0;
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b38c0 @ 0x008b38c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b38c0(int param_1,int param_2,float *param_3)

{
  byte *pbVar1;
  float fVar2;
  byte *pbVar3;
  int in_ECX;
  int extraout_ECX;
  
  fVar2 = _DAT_00a171c8;
  pbVar3 = (byte *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pbVar1 = pbVar3 + *(int *)(in_ECX + 0x68) * 2;
  for (; pbVar3 < pbVar1; pbVar3 = pbVar3 + 2) {
    *param_3 = (float)(pbVar3[1] & 0xf) * fVar2;
    param_3[1] = (float)(*pbVar3 >> 4) * fVar2;
    param_3[2] = (float)(*pbVar3 & 0xf) * fVar2;
    param_3[3] = 1.0;
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3967 @ 0x008b3967 ====

void FUN_008b3967(int param_1,int param_2,undefined4 *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  int in_ECX;
  int extraout_ECX;
  undefined4 *puVar3;
  
  pbVar2 = (byte *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pbVar1 = pbVar2 + *(int *)(in_ECX + 0x68) * 2;
  for (; pbVar2 < pbVar1; pbVar2 = pbVar2 + 2) {
    puVar3 = (undefined4 *)((uint)*pbVar2 * 0x10 + *(int *)(in_ECX + 0x38));
    *param_3 = *puVar3;
    param_3[1] = puVar3[1];
    param_3[2] = puVar3[2];
    param_3[3] = puVar3[3];
    param_3[3] = (float)pbVar2[1] * DAT_0099d0b0;
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b39f7 @ 0x008b39f7 ====

void FUN_008b39f7(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int in_ECX;
  int extraout_ECX;
  byte *pbVar3;
  undefined4 *puVar4;
  
  pbVar2 = (byte *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pbVar3 = pbVar2 + *(int *)(in_ECX + 0x68);
  for (; pbVar2 < pbVar3; pbVar2 = pbVar2 + 1) {
    puVar4 = (undefined4 *)((uint)*pbVar2 * 0x10 + *(int *)(in_ECX + 0x38));
    *param_3 = *puVar4;
    param_3[1] = puVar4[1];
    puVar1 = param_3 + 3;
    param_3[2] = puVar4[2];
    param_3 = param_3 + 4;
    *puVar1 = puVar4[3];
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3a66 @ 0x008b3a66 ====

void FUN_008b3a66(int param_1,int param_2,float *param_3)

{
  byte bVar1;
  float fVar2;
  byte *pbVar3;
  int in_ECX;
  int extraout_ECX;
  byte *pbVar4;
  float *pfVar5;
  
  pbVar3 = (byte *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pbVar4 = pbVar3 + *(int *)(in_ECX + 0x68);
  pfVar5 = param_3;
  if (pbVar3 < pbVar4) {
    do {
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + 1;
      fVar2 = (float)bVar1 * DAT_0099d0b0;
      param_3[2] = fVar2;
      param_3[1] = fVar2;
      *param_3 = fVar2;
      pfVar5 = param_3 + 4;
      param_3[3] = 1.0;
      param_3 = pfVar5;
    } while (pbVar3 < pbVar4);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3ae0 @ 0x008b3ae0 ====

void FUN_008b3ae0(int param_1,int param_2,float *param_3)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  byte *pbVar4;
  int in_ECX;
  int extraout_ECX;
  
  fVar3 = DAT_0099d0b0;
  pbVar4 = (byte *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pbVar1 = pbVar4 + *(int *)(in_ECX + 0x68) * 2;
  for (; pbVar4 < pbVar1; pbVar4 = pbVar4 + 2) {
    fVar2 = (float)*pbVar4 * fVar3;
    param_3[2] = fVar2;
    param_3[1] = fVar2;
    *param_3 = fVar2;
    param_3[3] = (float)pbVar4[1] * fVar3;
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3b71 @ 0x008b3b71 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3b71(int param_1,int param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  byte *pbVar3;
  int in_ECX;
  int extraout_ECX;
  byte *pbVar4;
  
  fVar2 = _DAT_00a171c8;
  pbVar3 = (byte *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pbVar4 = pbVar3 + *(int *)(in_ECX + 0x68);
  for (; pbVar3 < pbVar4; pbVar3 = pbVar3 + 1) {
    fVar1 = (float)(*pbVar3 & 0xf) * fVar2;
    param_3[2] = fVar1;
    param_3[1] = fVar1;
    *param_3 = fVar1;
    param_3[3] = (float)(*pbVar3 >> 4) * fVar2;
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3c02 @ 0x008b3c02 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3c02(int param_1,int param_2,float *param_3)

{
  char *pcVar1;
  char cVar2;
  float fVar3;
  char *pcVar4;
  int in_ECX;
  float *pfVar5;
  
  fVar3 = _DAT_00a171dc;
  pcVar4 = (char *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pcVar1 = pcVar4 + *(int *)(in_ECX + 0x68) * 2;
  pfVar5 = param_3;
  if (pcVar4 < pcVar1) {
    do {
      cVar2 = pcVar4[1];
      *param_3 = (float)(int)(char)((*pcVar4 == -0x80) + *pcVar4) * fVar3;
      pcVar4 = pcVar4 + 2;
      pfVar5 = param_3 + 4;
      param_3[1] = (float)(int)(char)((cVar2 == -0x80) + cVar2) * fVar3;
      param_3[2] = 1.0;
      param_3[3] = 1.0;
      param_3 = pfVar5;
    } while (pcVar4 < pcVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3cb0 @ 0x008b3cb0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3cb0(int param_1,int param_2,float *param_3)

{
  ushort *puVar1;
  ushort uVar2;
  float fVar3;
  ushort *puVar4;
  char cVar5;
  int in_ECX;
  char cVar6;
  float *pfVar7;
  
  fVar3 = _DAT_00a171c8;
  puVar4 = (ushort *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  puVar1 = puVar4 + *(int *)(in_ECX + 0x68);
  pfVar7 = param_3;
  if (puVar4 < puVar1) {
    do {
      cVar6 = (char)((char)*puVar4 << 3) >> 3;
      cVar5 = (char)((char)(*puVar4 >> 5) << 3) >> 3;
      *param_3 = (float)(int)(char)((cVar6 == -0x10) + cVar6) * fVar3;
      pfVar7 = param_3 + 4;
      param_3[1] = (float)(int)(char)((cVar5 == -0x10) + cVar5) * fVar3;
      param_3[2] = 1.0;
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      param_3[3] = (float)(uVar2 >> 10) * _DAT_00a171a4;
      param_3 = pfVar7;
    } while (puVar4 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar7 + *(int *)(in_ECX + 0x68) * -4);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar7 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3d83 @ 0x008b3d83 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3d83(int param_1,int param_2,float *param_3)

{
  char *pcVar1;
  float fVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  int in_ECX;
  float *pfVar6;
  
  fVar2 = _DAT_00a171dc;
  pcVar3 = (char *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pcVar1 = pcVar3 + *(int *)(in_ECX + 0x68) * 4;
  pfVar6 = param_3;
  if (pcVar3 < pcVar1) {
    do {
      cVar5 = (char)((uint)*(undefined4 *)pcVar3 >> 8);
      pcVar4 = pcVar3 + 4;
      *param_3 = (float)(int)(char)((*pcVar3 == -0x80) + *pcVar3) * fVar2;
      pfVar6 = param_3 + 4;
      param_3[1] = (float)(int)(char)((cVar5 == -0x80) + cVar5) * fVar2;
      param_3[2] = 1.0;
      param_3[3] = (float)(byte)pcVar3[2] * DAT_0099d0b0;
      pcVar3 = pcVar4;
      param_3 = pfVar6;
    } while (pcVar4 < pcVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar6 + *(int *)(in_ECX + 0x68) * -4);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar6 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3e42 @ 0x008b3e42 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3e42(int param_1,int param_2,float *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  float fVar4;
  undefined4 *puVar5;
  char cVar6;
  int in_ECX;
  char cVar7;
  float *pfVar8;
  
  fVar4 = _DAT_00a171dc;
  puVar5 = (undefined4 *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  puVar1 = puVar5 + *(int *)(in_ECX + 0x68);
  pfVar8 = param_3;
  if (puVar5 < puVar1) {
    do {
      uVar2 = *puVar5;
      cVar3 = (char)((uint)uVar2 >> 0x10);
      cVar7 = (char)((uint)uVar2 >> 0x18);
      cVar6 = (char)((uint)uVar2 >> 8);
      *param_3 = (float)(int)(char)(((char)uVar2 == -0x80) + (char)uVar2) * fVar4;
      param_3[1] = (float)(int)(char)((cVar6 == -0x80) + cVar6) * fVar4;
      puVar5 = puVar5 + 1;
      pfVar8 = param_3 + 4;
      param_3[2] = (float)(int)(char)((cVar3 == -0x80) + cVar3) * fVar4;
      param_3[3] = (float)(int)(char)((cVar7 == -0x80) + cVar7) * fVar4;
      param_3 = pfVar8;
    } while (puVar5 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar8 + *(int *)(in_ECX + 0x68) * -4);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar8 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3f30 @ 0x008b3f30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3f30(int param_1,int param_2,float *param_3)

{
  short *psVar1;
  short sVar2;
  float fVar3;
  short *psVar4;
  int in_ECX;
  int extraout_ECX;
  
  fVar3 = _DAT_0099d07c;
  psVar4 = (short *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                    *(int *)(in_ECX + 0x20));
  psVar1 = psVar4 + *(int *)(in_ECX + 0x68) * 2;
  for (; psVar4 < psVar1; psVar4 = psVar4 + 2) {
    sVar2 = psVar4[1];
    *param_3 = (float)(int)(short)((ushort)(*psVar4 == -0x8000) + *psVar4) * fVar3;
    param_3[1] = (float)(int)(short)((ushort)(sVar2 == -0x8000) + sVar2) * fVar3;
    param_3[2] = 1.0;
    param_3[3] = 1.0;
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b3fe5 @ 0x008b3fe5 ====

/* WARNING: Removing unreachable block (ram,0x008b40a0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b3fe5(int param_1,int param_2,float *param_3)

{
  uint *puVar1;
  float fVar2;
  uint *puVar3;
  int in_ECX;
  int extraout_ECX;
  short sVar4;
  short sVar5;
  short sVar6;
  
  fVar2 = _DAT_00a173d8;
  puVar3 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  puVar1 = puVar3 + *(int *)(in_ECX + 0x68);
  for (; puVar3 < puVar1; puVar3 = puVar3 + 1) {
    sVar4 = (short)((ushort)(*puVar3 >> 0x14) << 6) >> 6;
    sVar6 = (short)((short)*puVar3 << 6) >> 6;
    sVar5 = (short)((short)(*puVar3 >> 10) << 6) >> 6;
    *param_3 = (float)(int)(short)((ushort)(sVar6 == -0x200) + sVar6) * fVar2;
    param_3[1] = (float)(int)(short)((ushort)(sVar5 == -0x200) + sVar5) * fVar2;
    param_3[2] = (float)(int)(short)((ushort)(sVar4 == -0x200) + sVar4) * fVar2;
    param_3[3] = (float)(*puVar3 >> 0x1e) * _DAT_009fc7c8;
    param_3 = param_3 + 4;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b40f1 @ 0x008b40f1 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b40f1(int param_1,int param_2,float *param_3)

{
  short *psVar1;
  undefined4 uVar2;
  float fVar3;
  short *psVar4;
  int in_ECX;
  int extraout_ECX;
  short sVar5;
  float *pfVar6;
  
  fVar3 = _DAT_0099d07c;
  psVar4 = (short *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                    *(int *)(in_ECX + 0x20));
  psVar1 = psVar4 + *(int *)(in_ECX + 0x68) * 4;
  pfVar6 = param_3;
  if (psVar4 < psVar1) {
    do {
      uVar2 = *(undefined4 *)(psVar4 + 2);
      sVar5 = (short)uVar2;
      param_3._0_2_ = (short)((uint)*(undefined4 *)psVar4 >> 0x10);
      *pfVar6 = (float)(int)(short)((ushort)(*psVar4 == -0x8000) + *psVar4) * fVar3;
      pfVar6[1] = (float)(int)(short)((ushort)((short)param_3 == -0x8000) + (short)param_3) * fVar3;
      param_1._0_2_ = (short)((uint)uVar2 >> 0x10);
      psVar4 = psVar4 + 4;
      param_3 = pfVar6 + 4;
      pfVar6[2] = (float)(int)(short)((ushort)(sVar5 == -0x8000) + sVar5) * fVar3;
      pfVar6[3] = (float)(int)(short)((ushort)((short)param_1 == -0x8000) + (short)param_1) * fVar3;
      pfVar6 = param_3;
    } while (psVar4 < psVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b41fb @ 0x008b41fb ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b41fb(int param_1,int param_2,float *param_3)

{
  char *pcVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int in_ECX;
  char *pcVar6;
  
  fVar5 = _DAT_00a171dc;
  pcVar6 = (char *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  pcVar1 = pcVar6 + *(int *)(in_ECX + 0x68) * 2;
  if (pcVar6 < pcVar1) {
    do {
      cVar2 = pcVar6[1];
      fVar3 = (float)(int)(char)((*pcVar6 == -0x80) + *pcVar6) * fVar5;
      *param_3 = fVar3;
      fVar4 = (float)(int)(char)((cVar2 == -0x80) + cVar2) * fVar5;
      param_3[1] = fVar4;
      fVar3 = (DAT_0099d080 - fVar3 * fVar3) - fVar4 * fVar4;
      if ((NAN(fVar3) || NAN(DAT_0099cdc8)) || fVar3 < DAT_0099cdc8 == (fVar3 == DAT_0099cdc8)) {
        fVar3 = SQRT(fVar3);
      }
      else {
        fVar3 = 0.0;
      }
      param_3[2] = fVar3;
      pcVar6 = pcVar6 + 2;
      param_3[3] = 1.0;
      param_3 = param_3 + 4;
    } while (pcVar6 < pcVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b42cf @ 0x008b42cf ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b42cf(int param_1,int param_2,float *param_3)

{
  ushort *puVar1;
  ushort uVar2;
  float fVar3;
  ushort *puVar4;
  int in_ECX;
  int extraout_ECX;
  float *pfVar5;
  
  puVar4 = (ushort *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  puVar1 = puVar4 + *(int *)(in_ECX + 0x68);
  pfVar5 = param_3;
  if (puVar4 < puVar1) {
    do {
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      fVar3 = (float)uVar2 * _DAT_00a171d8;
      param_3[2] = fVar3;
      param_3[1] = fVar3;
      *param_3 = fVar3;
      pfVar5 = param_3 + 4;
      param_3[3] = 1.0;
      param_3 = pfVar5;
    } while (puVar4 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b434b @ 0x008b434b ====

void FUN_008b434b(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = *(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
          *(int *)(in_ECX + 0x20);
  uVar1 = uVar2 + *(int *)(in_ECX + 0x68) * 2;
  for (; uVar2 < uVar1; uVar2 = uVar2 + 2) {
    thunk_FUN_0079ddb7(param_3,uVar2,1);
    *(undefined4 *)(param_3 + 0xc) = 0x3f800000;
    *(undefined4 *)(param_3 + 8) = 0x3f800000;
    *(undefined4 *)(param_3 + 4) = 0x3f800000;
    param_3 = param_3 + 0x10;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -0x10);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -0x10);
  }
  return;
}


// ==== FUN_008b43cf @ 0x008b43cf ====

void FUN_008b43cf(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = *(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
          *(int *)(in_ECX + 0x20);
  uVar1 = uVar2 + *(int *)(in_ECX + 0x68) * 4;
  for (; uVar2 < uVar1; uVar2 = uVar2 + 4) {
    thunk_FUN_0079ddb7(param_3,uVar2,2);
    *(undefined4 *)(param_3 + 0xc) = 0x3f800000;
    *(undefined4 *)(param_3 + 8) = 0x3f800000;
    param_3 = param_3 + 0x10;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -0x10);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -0x10);
  }
  return;
}


// ==== FUN_008b444f @ 0x008b444f ====

void FUN_008b444f(int param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  
  thunk_FUN_0079ddb7(param_3,*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                             *(int *)(in_ECX + 0x20),*(int *)(in_ECX + 0x68) << 2);
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3);
  }
  return;
}


// ==== FUN_008b449f @ 0x008b449f ====

void FUN_008b449f(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int extraout_ECX;
  undefined4 *puVar4;
  
  puVar3 = (undefined4 *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  puVar1 = puVar3 + *(int *)(in_ECX + 0x68);
  puVar4 = param_3;
  if (puVar3 < puVar1) {
    do {
      uVar2 = *puVar3;
      param_3[3] = 0x3f800000;
      *param_3 = uVar2;
      puVar3 = puVar3 + 1;
      param_3[2] = 0x3f800000;
      puVar4 = param_3 + 4;
      param_3[1] = 0x3f800000;
      param_3 = puVar4;
    } while (puVar3 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(puVar4 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(puVar4 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b4513 @ 0x008b4513 ====

void FUN_008b4513(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int extraout_ECX;
  
  puVar3 = (undefined4 *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  puVar1 = puVar3 + *(int *)(in_ECX + 0x68) * 2;
  if (puVar3 < puVar1) {
    do {
      *param_3 = *puVar3;
      uVar2 = puVar3[1];
      param_3[3] = 0x3f800000;
      param_3[1] = uVar2;
      param_3[2] = 0x3f800000;
      puVar3 = puVar3 + 2;
      param_3 = param_3 + 4;
    } while (puVar3 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b4588 @ 0x008b4588 ====

void FUN_008b4588(int param_1,int param_2,undefined4 *param_3)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  puVar3 = param_3;
  for (iVar1 = (*(uint *)(in_ECX + 0x68) & 0xfffffff) << 2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(param_3);
  }
  return;
}


// ==== FUN_008b45e3 @ 0x008b45e3 ====

/* WARNING: Removing unreachable block (ram,0x008b4622) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b45e3(int param_1,int param_2,float *param_3)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  uint *puVar4;
  uint *puVar5;
  int in_ECX;
  int extraout_ECX;
  float *pfVar6;
  
  fVar3 = _DAT_00a171d8;
  puVar4 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
  puVar1 = puVar4 + *(int *)(in_ECX + 0x68);
  pfVar6 = param_3;
  if (puVar4 < puVar1) {
    do {
      fVar2 = (float)(*puVar4 & 0xffff) * fVar3;
      puVar5 = puVar4 + 1;
      param_3[2] = fVar2;
      param_3[1] = fVar2;
      *param_3 = fVar2;
      pfVar6 = param_3 + 4;
      param_3[3] = (float)*(ushort *)((int)puVar4 + 2) * fVar3;
      puVar4 = puVar5;
      param_3 = pfVar6;
    } while (puVar5 < puVar1);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar6 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar6 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b467d @ 0x008b467d ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b467d(int param_1,int param_2,float *param_3)

{
  ushort uVar1;
  float fVar2;
  ushort *puVar3;
  int in_ECX;
  int extraout_ECX;
  ushort *puVar4;
  float *pfVar5;
  
  fVar2 = _DAT_00a171d8;
  puVar3 = (ushort *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
           *(int *)(in_ECX + 0x20));
  puVar4 = (ushort *)(*(int *)(in_ECX + 0x74) + (int)puVar3);
  pfVar5 = param_3;
  if (puVar3 < puVar4) {
    do {
      *param_3 = (float)puVar3[2] * fVar2;
      pfVar5 = param_3 + 4;
      param_3[1] = (float)puVar3[1] * fVar2;
      uVar1 = *puVar3;
      puVar3 = puVar3 + 3;
      param_3[2] = (float)uVar1 * fVar2;
      param_3[3] = 1.0;
      param_3 = pfVar5;
    } while (puVar3 < puVar4);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_008ac113(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
    in_ECX = extraout_ECX;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar5 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b4715 @ 0x008b4715 ====

void FUN_008b4715(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  int iVar3;
  
  FUN_008abd0d(param_1,0,1);
  uVar1 = in_ECX[0x11] + 1 & 0xfffffffe;
  iVar3 = uVar1 - (in_ECX[0xf] & 0xfffffffe);
  in_ECX[0x23] = uVar1;
  *in_ECX = &PTR_FUN_00a17460;
  in_ECX[0x21] = in_ECX[0xf] & 0xfffffffe;
  in_ECX[0x22] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = iVar3;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 1;
  pvVar2 = operator_new(iVar3 * 0x10);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    FUN_0040d030(pvVar2,0x10,iVar3,FUN_0079e14e);
  }
  in_ECX[0x20] = pvVar2;
  if (pvVar2 == (void *)0x0) {
    in_ECX[0x29] = 0;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 == 0x32595559) {
LAB_008b47ea:
    in_ECX[0x2a] = 0;
    in_ECX[0x2b] = 8;
  }
  else {
    if (iVar3 != 0x42475247) {
      if (iVar3 == 0x47424752) goto LAB_008b47ea;
      if (iVar3 != 0x59565955) {
        return;
      }
    }
    in_ECX[0x2a] = 8;
    in_ECX[0x2b] = 0;
  }
  return;
}


// ==== FUN_008b4803 @ 0x008b4803 ====

void FUN_008b4803(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a17460;
  FUN_008ab181();
  if ((void *)in_ECX[0x20] == (void *)0x0) {
    FUN_008aac3e();
    return;
  }
  _free((void *)in_ECX[0x20]);
  return;
}


// ==== FUN_008b482c @ 0x008b482c ====

void FUN_008b482c(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (undefined4 *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (undefined4 *)FUN_008ac18d(param_3);
  }
  iVar1 = FUN_008ab484(param_1 + *(int *)(in_ECX + 0x40),param_2 + *(int *)(in_ECX + 0x4c),
                       *(int *)(in_ECX + 0x9c) != *(int *)(in_ECX + 0x68));
  if (-1 < iVar1) {
    puVar2 = (undefined4 *)
             ((*(int *)(in_ECX + 0x3c) - *(int *)(in_ECX + 0x84)) * 0x10 + *(int *)(in_ECX + 0x80));
    for (iVar1 = (*(uint *)(in_ECX + 0x68) & 0xfffffff) << 2; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_3;
      param_3 = param_3 + 1;
      puVar2 = puVar2 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)puVar2 = *(undefined1 *)param_3;
      param_3 = (undefined4 *)((int)param_3 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    *(undefined4 *)(in_ECX + 0xa0) = 1;
  }
  return;
}


// ==== FUN_008b48ba @ 0x008b48ba ====

void FUN_008b48ba(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_008ab484(param_1 + *(int *)(in_ECX + 0x40),param_2 + *(int *)(in_ECX + 0x4c),1);
  if (-1 < iVar1) {
    puVar2 = (undefined4 *)
             ((*(int *)(in_ECX + 0x3c) - *(int *)(in_ECX + 0x84)) * 0x10 + *(int *)(in_ECX + 0x80));
    puVar3 = param_3;
    for (iVar1 = (*(uint *)(in_ECX + 0x68) & 0xfffffff) << 2; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    if (*(int *)(in_ECX + 0x18) != 0) {
      FUN_008ac113(param_3);
    }
    if (*(int *)(in_ECX + 0x10) != 0) {
      FUN_008ac380(param_3);
    }
  }
  return;
}


// ==== FUN_008b492f @ 0x008b492f ====

void FUN_008b492f(int param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  
  FUN_008abd0d(param_1,0,1);
  iVar2 = in_ECX[1];
  *in_ECX = &PTR_FUN_00a17194;
  if (iVar2 == 0x31545844) {
    in_ECX[0x22] = 8;
    in_ECX[0x24] = FUN_008f252a;
    in_ECX[0x23] = FUN_008f2225;
  }
  else if (iVar2 == 0x32545844) {
    in_ECX[0x22] = 0x10;
    in_ECX[0x24] = FUN_008f2c9d;
    in_ECX[0x23] = FUN_008f2c51;
  }
  else if (iVar2 == 0x33545844) {
    in_ECX[0x22] = 0x10;
    in_ECX[0x24] = FUN_008f264e;
    in_ECX[0x23] = FUN_008f2367;
  }
  else if (iVar2 == 0x34545844) {
    in_ECX[0x22] = 0x10;
    in_ECX[0x24] = FUN_008f2cd6;
    in_ECX[0x23] = FUN_008f2c77;
  }
  else if (iVar2 == 0x35545844) {
    in_ECX[0x22] = 0x10;
    in_ECX[0x24] = FUN_008f277d;
    in_ECX[0x23] = FUN_008f23ec;
  }
  puVar4 = (uint *)(param_1 + 0x10);
  puVar5 = in_ECX + 0x25;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  in_ECX[0x2b] = in_ECX[0x25] & 0xfffffffc;
  in_ECX[0x2c] = in_ECX[0x26] & 0xfffffffc;
  in_ECX[0x2f] = in_ECX[0x29];
  in_ECX[0x2d] = in_ECX[0x27] + 3 & 0xfffffffc;
  in_ECX[0x3a] = 0xffffffff;
  in_ECX[0x3b] = 0xffffffff;
  in_ECX[0x2e] = in_ECX[0x28] + 3 & 0xfffffffc;
  in_ECX[0x30] = in_ECX[0x2a];
  in_ECX[0x35] = in_ECX[0x13];
  uVar1 = in_ECX[0x11] + 3 & 0xfffffffc;
  in_ECX[0x33] = uVar1;
  uVar3 = in_ECX[0x12] + 3 & 0xfffffffc;
  in_ECX[0x34] = uVar3;
  in_ECX[0x37] = uVar1 - (in_ECX[0xf] & 0xfffffffc) >> 2;
  in_ECX[0x36] = in_ECX[0x14];
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x31] = in_ECX[0xf] & 0xfffffffc;
  in_ECX[0x32] = in_ECX[0x10] & 0xfffffffc;
  in_ECX[0x38] = uVar3 - (in_ECX[0x10] & 0xfffffffc) >> 2;
  in_ECX[0x39] = in_ECX[0x14] - in_ECX[0x13];
  in_ECX[0x3f] = *(undefined4 *)(param_1 + 0x40);
  return;
}


// ==== FUN_008b4b17 @ 0x008b4b17 ====

void FUN_008b4b17(uint param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint local_24 [4];
  void *local_14;
  uint local_10;
  uint local_c;
  uint *local_8;
  
  param_1 = param_1 + *(int *)(in_ECX + 0x40);
  param_2 = param_2 + *(int *)(in_ECX + 0x4c);
  if (*(int *)(in_ECX + 0xf8) == 0) {
    puVar1 = operator_new(*(int *)(in_ECX + 0xe0) * *(int *)(in_ECX + 0xe4) * 8);
    *(undefined4 **)(in_ECX + 0xf8) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    for (iVar4 = (*(int *)(in_ECX + 0xe0) * *(int *)(in_ECX + 0xe4) & 0x1fffffffU) << 1; iVar4 != 0;
        iVar4 = iVar4 + -1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar1 = 0;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
    }
  }
  puVar8 = (uint *)(*(int *)(in_ECX + 0xf8) +
                   ((param_2 - *(int *)(in_ECX + 0xd4)) * *(int *)(in_ECX + 0xe0) +
                   (param_1 - *(int *)(in_ECX + 200) >> 2)) * 8);
  local_8 = puVar8;
  if (puVar8[1] == 0) {
    iVar4 = *(int *)(in_ECX + 0xdc);
    local_14 = operator_new(iVar4 << 8);
    if (local_14 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_0040d030(local_14,0x10,iVar4 << 4,FUN_0079e14e);
      pvVar2 = local_14;
    }
    puVar8[1] = (uint)pvVar2;
    if (pvVar2 == (void *)0x0) {
      return;
    }
    *puVar8 = 0;
    *(int *)(in_ECX + 0xf4) = *(int *)(in_ECX + 0xf4) + 1;
  }
  if (*puVar8 == 0) {
    local_14 = (void *)(param_1 & 0xfffffffc);
    if (((local_14 < *(void **)(in_ECX + 0x40)) &&
        (*(void **)(in_ECX + 0x98) < *(void **)(in_ECX + 0x40))) ||
       ((*(uint *)(in_ECX + 0x48) < (int)local_14 + 4U &&
        (*(uint *)(in_ECX + 0x48) < *(uint *)(in_ECX + 0xa0))))) {
      local_10 = *(uint *)(in_ECX + 0xc4);
      iVar4 = (param_1 >> 2) * *(int *)(in_ECX + 0x60) + (local_10 >> 2) * *(int *)(in_ECX + 0x88) +
              *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20);
      local_c = puVar8[1];
      if (local_10 < *(uint *)(in_ECX + 0xcc)) {
        do {
          (**(code **)(in_ECX + 0x8c))(local_c,iVar4);
          local_10 = local_10 + 4;
          iVar4 = iVar4 + *(int *)(in_ECX + 0x88);
          local_c = local_c + 0x100;
        } while (local_10 < *(uint *)(in_ECX + 0xcc));
      }
    }
    else {
      if ((*(uint *)(in_ECX + 0xc4) < *(uint *)(in_ECX + 0x3c)) &&
         (*(uint *)(in_ECX + 0x94) < *(uint *)(in_ECX + 0x3c))) {
        (**(code **)(in_ECX + 0x8c))
                  (puVar8[1],
                   (*(uint *)(in_ECX + 0xc4) >> 2) * *(int *)(in_ECX + 0x88) +
                   (param_1 >> 2) * *(int *)(in_ECX + 0x60) + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
      }
      if ((*(uint *)(in_ECX + 0x44) < *(uint *)(in_ECX + 0xcc)) &&
         (*(uint *)(in_ECX + 0x44) < *(uint *)(in_ECX + 0x9c))) {
        (**(code **)(in_ECX + 0x8c))
                  (puVar8[1],
                   (*(uint *)(in_ECX + 0xcc) - 4 >> 2) * *(int *)(in_ECX + 0x88) +
                   (param_1 >> 2) * *(int *)(in_ECX + 0x60) + *(int *)(in_ECX + 100) * param_2 +
                   *(int *)(in_ECX + 0x20));
      }
    }
    uVar5 = 0;
    do {
      if ((uVar5 + (int)local_14 < *(uint *)(in_ECX + 0x40)) ||
         (*(uint *)(in_ECX + 0x48) <= uVar5 + (int)local_14)) {
        *puVar8 = *puVar8 | 1 << ((byte)uVar5 & 0x1f);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 4);
  }
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (undefined4 *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (undefined4 *)FUN_008ac18d(param_3);
  }
  uVar5 = *(int *)(in_ECX + 0x3c) - *(int *)(in_ECX + 0xc4);
  iVar4 = *(int *)(in_ECX + 200);
  local_14 = (void *)(*(int *)(in_ECX + 0x68) + uVar5);
  for (; uVar5 < local_14; uVar5 = uVar5 + 1) {
    puVar1 = (undefined4 *)
             (((uVar5 & 0xfffffffc | param_1 - iVar4 & 3) << 2 | uVar5 & 3) * 0x10 + puVar8[1]);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar8 = local_8;
    param_3 = param_3 + 4;
  }
  *puVar8 = *puVar8 | 1 << ((byte)param_1 & 3);
  if (*puVar8 == 0xf) {
    local_c = *(uint *)(in_ECX + 0xc4);
    param_2 = (param_1 >> 2) * *(int *)(in_ECX + 0x60) + (local_c >> 2) * *(int *)(in_ECX + 0x88) +
              *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20);
    param_3 = (undefined4 *)puVar8[1];
    if (local_c < *(uint *)(in_ECX + 0xcc)) {
      local_24[0] = 0;
      local_24[1] = 0;
      local_24[2] = 0;
      local_14 = (void *)(param_1 & 0xfffffffc);
      local_24[3] = 1;
      do {
        uVar5 = *(int *)(in_ECX + 0x9c) - local_c;
        uVar6 = *(int *)(in_ECX + 0xa0) - (int)local_14;
        if (uVar5 < 4) {
          param_1 = 0;
          if (uVar6 != 0) {
            do {
              if (3 < param_1) break;
              uVar7 = uVar5;
              do {
                puVar1 = (undefined4 *)((local_24[uVar7] | param_1 << 2) * 0x10 + (int)param_3);
                puVar9 = (undefined4 *)((param_1 << 2 | uVar7) * 0x10 + (int)param_3);
                uVar7 = uVar7 + 1;
                *puVar9 = *puVar1;
                puVar9[1] = puVar1[1];
                puVar9[2] = puVar1[2];
                puVar9[3] = puVar1[3];
              } while (uVar7 < 4);
              param_1 = param_1 + 1;
              puVar8 = local_8;
            } while (param_1 < uVar6);
          }
        }
        if (uVar6 < 4) {
          do {
            uVar5 = local_24[uVar6];
            uVar7 = 0;
            do {
              puVar9 = (undefined4 *)((uVar6 << 2 | uVar7) * 0x10 + (int)param_3);
              puVar1 = (undefined4 *)((uVar5 << 2 | uVar7) * 0x10 + (int)param_3);
              uVar7 = uVar7 + 1;
              *puVar9 = *puVar1;
              puVar9[1] = puVar1[1];
              puVar9[2] = puVar1[2];
              puVar9[3] = puVar1[3];
            } while (uVar7 < 4);
            uVar6 = uVar6 + 1;
          } while (uVar6 < 4);
          puVar8 = local_8;
        }
        uVar3 = 0;
        if ((*(int *)(in_ECX + 0xfc) != 0) || (*(int *)(in_ECX + 0x5c) != 0)) {
          uVar3 = 1;
        }
        (**(code **)(in_ECX + 0x90))(param_2,param_3,uVar3);
        local_c = local_c + 4;
        param_2 = param_2 + *(int *)(in_ECX + 0x88);
        param_3 = (undefined4 *)((int)param_3 + 0x100);
      } while (local_c < *(uint *)(in_ECX + 0xcc));
    }
    if ((((uint *)(*(int *)(in_ECX + 0xf8) + *(int *)(in_ECX + 0xe4) * *(int *)(in_ECX + 0xe0) * 8)
          <= puVar8 + 2) || (puVar8[2] != 0)) || (puVar8[3] != 0)) {
      _free((void *)puVar8[1]);
      return;
    }
    puVar8[3] = puVar8[1];
    puVar8[1] = 0;
    puVar8[1] = 0;
  }
  return;
}


// ==== FUN_008b4f38 @ 0x008b4f38 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008b4f38(int param_1,int param_2,float *param_3)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  uint uVar7;
  float *pfVar8;
  undefined2 in_FPUControlWord;
  
  uVar7 = param_1 + *(int *)(in_ECX + 0x40);
  param_2 = param_2 + *(int *)(in_ECX + 0x4c);
  if (*(int *)(in_ECX + 0xf0) == 0) {
    iVar1 = *(int *)(in_ECX + 0xdc);
    pvVar2 = operator_new(iVar1 << 8);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_0040d030(pvVar2,0x10,iVar1 << 4,FUN_0079e14e);
    }
    *(void **)(in_ECX + 0xf0) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      return;
    }
  }
  if (((uVar7 & 0xfffffffc) != *(uint *)(in_ECX + 0xe8)) || (param_2 != *(int *)(in_ECX + 0xec))) {
    *(uint *)(in_ECX + 0xe8) = uVar7 & 0xfffffffc;
    uVar3 = *(uint *)(in_ECX + 0xc4);
    param_1 = (uVar7 >> 2) * *(int *)(in_ECX + 0x60) + (uVar3 >> 2) * *(int *)(in_ECX + 0x88) +
              *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20);
    *(int *)(in_ECX + 0xec) = param_2;
    param_2 = *(int *)(in_ECX + 0xf0);
    for (; uVar3 < *(uint *)(in_ECX + 0xcc); uVar3 = uVar3 + 4) {
      (**(code **)(in_ECX + 0x8c))(param_2,param_1);
      param_1 = param_1 + *(int *)(in_ECX + 0x88);
      param_2 = param_2 + 0x100;
    }
  }
  iVar1 = *(int *)(in_ECX + 200);
  uVar3 = *(int *)(in_ECX + 0x3c) - *(int *)(in_ECX + 0xc4);
  uVar4 = *(int *)(in_ECX + 0x68) + uVar3;
  pfVar5 = param_3;
  for (; uVar3 < uVar4; uVar3 = uVar3 + 1) {
    pfVar8 = (float *)(((uVar3 & 0xfffffffc | uVar7 - iVar1 & 3) << 2 | uVar3 & 3) * 0x10 +
                      *(int *)(in_ECX + 0xf0));
    *pfVar5 = *pfVar8;
    pfVar5[1] = pfVar8[1];
    pfVar6 = pfVar5 + 3;
    pfVar5[2] = pfVar8[2];
    pfVar5 = pfVar5 + 4;
    *pfVar6 = pfVar8[3];
  }
  pfVar6 = pfVar5;
  if (*(int *)(in_ECX + 0x18) != 0) {
    param_3 = (float *)CONCAT22(param_3._2_2_,in_FPUControlWord);
    *(float **)(in_ECX + 0x7c) = param_3;
    for (pfVar6 = pfVar5 + *(int *)(in_ECX + 0x68) * -4; pfVar6 < pfVar5; pfVar6 = pfVar6 + 4) {
      if (((((float)(int)ROUND(*pfVar6 * _DAT_00a171ac + DAT_0099d0b4) * _DAT_00a171a8 ==
             *(float *)(in_ECX + 0x24)) &&
           ((float)(int)ROUND(pfVar6[1] * DAT_00a10a2c + DAT_0099d0b4) * _DAT_00a171a4 ==
            *(float *)(in_ECX + 0x28))) &&
          ((float)(int)ROUND(pfVar6[2] * _DAT_00a171ac + DAT_0099d0b4) * _DAT_00a171a8 ==
           *(float *)(in_ECX + 0x2c))) &&
         ((float)(int)ROUND(pfVar6[3] * *(float *)(in_ECX + 0x80) + DAT_0099d0b4) *
          *(float *)(in_ECX + 0x84) == *(float *)(in_ECX + 0x30))) {
        *pfVar6 = 0.0;
        pfVar6[1] = 0.0;
        pfVar6[2] = 0.0;
        pfVar6[3] = 0.0;
      }
    }
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_008ac380(pfVar6 + *(int *)(in_ECX + 0x68) * -4);
  }
  return;
}


// ==== FUN_008b51c3 @ 0x008b51c3 ====

void FUN_008b51c3(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008b4715(param_1);
  *in_ECX = &PTR_FUN_00a17460;
  return;
}


// ==== FUN_008b51e0 @ 0x008b51e0 ====

void FUN_008b51e0(byte param_1)

{
  void *in_ECX;
  
  FUN_008abb0b();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008b5201 @ 0x008b5201 ====

void FUN_008b5201(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008b492f(param_1);
  *in_ECX = &PTR_FUN_00a17194;
  return;
}


// ==== FUN_008b521e @ 0x008b521e ====

int * FUN_008b521e(int param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 < 0x31545845) {
    if (iVar3 == 0x31545844) {
      pvVar1 = operator_new(0x100);
      if (pvVar1 == (void *)0x0) goto LAB_008b5961;
      piVar2 = (int *)FUN_008b5201(param_1);
    }
    else if (iVar3 < 0x33) {
      if (iVar3 == 0x32) {
        pvVar1 = operator_new(0x80);
        if (pvVar1 == (void *)0x0) goto LAB_008b5961;
        piVar2 = (int *)FUN_008b16ba(param_1);
      }
      else {
        switch(iVar3) {
        case 0x14:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) {
LAB_008b5961:
            piVar2 = (int *)0x0;
          }
          else {
            piVar2 = (int *)FUN_008b0a46(param_1);
          }
          break;
        case 0x15:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b0a67(param_1);
          break;
        case 0x16:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b0a88(param_1);
          break;
        case 0x17:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b0dc4(param_1);
          break;
        case 0x18:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b0de5(param_1);
          break;
        case 0x19:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b0e06(param_1);
          break;
        case 0x1a:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b0e48(param_1);
          break;
        case 0x1b:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b0e69(param_1);
          break;
        case 0x1c:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b0e8a(param_1);
          break;
        case 0x1d:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b0eab(param_1);
          break;
        case 0x1e:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b0ecc(param_1);
          break;
        case 0x1f:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b1206(param_1);
          break;
        case 0x20:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b1227(param_1);
          break;
        case 0x21:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b1248(param_1);
          break;
        case 0x22:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b1269(param_1);
          break;
        case 0x23:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b128a(param_1);
          break;
        case 0x24:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b12ab(param_1);
          break;
        default:
          goto LAB_008b5994;
        case 0x28:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b12cc(param_1);
          break;
        case 0x29:
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b1699(param_1);
        }
      }
    }
    else if (iVar3 < 0x52) {
      if (iVar3 == 0x51) {
        pvVar1 = operator_new(0x80);
        if (pvVar1 == (void *)0x0) goto LAB_008b5961;
        piVar2 = (int *)FUN_008b171d(param_1);
      }
      else if (iVar3 < 0x3f) {
        if (iVar3 == 0x3e) {
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b1780(param_1);
        }
        else if (iVar3 == 0x33) {
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b16db(param_1);
        }
        else if (iVar3 == 0x34) {
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b16fc(param_1);
        }
        else if (iVar3 == 0x3c) {
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b173e(param_1);
        }
        else {
          if (iVar3 != 0x3d) {
            return (int *)0x0;
          }
          pvVar1 = operator_new(0x80);
          if (pvVar1 == (void *)0x0) goto LAB_008b5961;
          piVar2 = (int *)FUN_008b175f(param_1);
        }
      }
      else if (iVar3 == 0x3f) {
        pvVar1 = operator_new(0x80);
        if (pvVar1 == (void *)0x0) goto LAB_008b5961;
        piVar2 = (int *)FUN_008b1a18(param_1);
      }
      else if (iVar3 == 0x40) {
        pvVar1 = operator_new(0x80);
        if (pvVar1 == (void *)0x0) goto LAB_008b5961;
        piVar2 = (int *)FUN_008b1a39(param_1);
      }
      else if (iVar3 == 0x43) {
        pvVar1 = operator_new(0x80);
        if (pvVar1 == (void *)0x0) goto LAB_008b5961;
        piVar2 = (int *)FUN_008b1a5a(param_1);
      }
      else {
        if (iVar3 != 0x46) {
          return (int *)0x0;
        }
        pvVar1 = operator_new(0x80);
        if (pvVar1 == (void *)0x0) goto LAB_008b5961;
        piVar2 = (int *)FUN_008b171d(param_1);
      }
    }
    else if (iVar3 < 0x72) {
      if (iVar3 == 0x71) {
        pvVar1 = operator_new(0x80);
        if (pvVar1 == (void *)0x0) goto LAB_008b5961;
        piVar2 = (int *)FUN_008b1efa(param_1);
      }
      else if (iVar3 == 0x52) {
        pvVar1 = operator_new(0x80);
        if (pvVar1 == (void *)0x0) goto LAB_008b5961;
        piVar2 = (int *)FUN_008b1e97(param_1);
      }
      else if (iVar3 == 0x6e) {
        pvVar1 = operator_new(0x80);
        if (pvVar1 == (void *)0x0) goto LAB_008b5961;
        piVar2 = (int *)FUN_008b1a7b(param_1);
      }
      else if (iVar3 == 0x6f) {
        pvVar1 = operator_new(0x80);
        if (pvVar1 == (void *)0x0) goto LAB_008b5961;
        piVar2 = (int *)FUN_008b1eb8(param_1);
      }
      else {
        if (iVar3 != 0x70) {
          return (int *)0x0;
        }
        pvVar1 = operator_new(0x80);
        if (pvVar1 == (void *)0x0) goto LAB_008b5961;
        piVar2 = (int *)FUN_008b1ed9(param_1);
      }
    }
    else if (iVar3 == 0x72) {
      pvVar1 = operator_new(0x80);
      if (pvVar1 == (void *)0x0) goto LAB_008b5961;
      piVar2 = (int *)FUN_008b1e97(param_1);
    }
    else if (iVar3 == 0x73) {
      pvVar1 = operator_new(0x80);
      if (pvVar1 == (void *)0x0) goto LAB_008b5961;
      piVar2 = (int *)FUN_008b1f1b(param_1);
    }
    else if (iVar3 == 0x74) {
      pvVar1 = operator_new(0x80);
      if (pvVar1 == (void *)0x0) goto LAB_008b5961;
      piVar2 = (int *)FUN_008b1f3c(param_1);
    }
    else {
      if (iVar3 != 0x75) {
        return (int *)0x0;
      }
      pvVar1 = operator_new(0x80);
      if (pvVar1 == (void *)0x0) goto LAB_008b5961;
      piVar2 = (int *)FUN_008b1a9c(param_1);
    }
  }
  else if (iVar3 < 0x36314c42) {
    if (iVar3 == 0x36314c41) {
      pvVar1 = operator_new(0x80);
      if (pvVar1 == (void *)0x0) goto LAB_008b5961;
      piVar2 = (int *)FUN_008b2335(param_1);
    }
    else if (iVar3 == 0x32545844) {
      pvVar1 = operator_new(0x100);
      if (pvVar1 == (void *)0x0) goto LAB_008b5961;
      piVar2 = (int *)FUN_008b5201(param_1);
    }
    else if (iVar3 == 0x32595559) {
      pvVar1 = operator_new(0xb0);
      if (pvVar1 == (void *)0x0) goto LAB_008b5961;
      piVar2 = (int *)FUN_008b51c3(param_1);
    }
    else if (iVar3 == 0x33545844) {
      pvVar1 = operator_new(0x100);
      if (pvVar1 == (void *)0x0) goto LAB_008b5961;
      piVar2 = (int *)FUN_008b5201(param_1);
    }
    else if (iVar3 == 0x34545844) {
      pvVar1 = operator_new(0x100);
      if (pvVar1 == (void *)0x0) goto LAB_008b5961;
      piVar2 = (int *)FUN_008b5201(param_1);
    }
    else {
      if (iVar3 != 0x35545844) {
        return (int *)0x0;
      }
      pvVar1 = operator_new(0x100);
      if (pvVar1 == (void *)0x0) goto LAB_008b5961;
      piVar2 = (int *)FUN_008b5201(param_1);
    }
  }
  else if (iVar3 == 0x36315220) {
    pvVar1 = operator_new(0x80);
    if (pvVar1 == (void *)0x0) goto LAB_008b5961;
    piVar2 = (int *)FUN_008b2356(param_1);
  }
  else if (iVar3 == 0x42475247) {
    pvVar1 = operator_new(0xb0);
    if (pvVar1 == (void *)0x0) goto LAB_008b5961;
    piVar2 = (int *)FUN_008b51c3(param_1);
  }
  else if (iVar3 == 0x47424752) {
    pvVar1 = operator_new(0xb0);
    if (pvVar1 == (void *)0x0) goto LAB_008b5961;
    piVar2 = (int *)FUN_008b51c3(param_1);
  }
  else {
    if (iVar3 != 0x59565955) {
      return (int *)0x0;
    }
    pvVar1 = operator_new(0xb0);
    if (pvVar1 == (void *)0x0) goto LAB_008b5961;
    piVar2 = (int *)FUN_008b51c3(param_1);
  }
  if (piVar2 != (int *)0x0) {
    if ((piVar2[7] == 0) || (iVar3 = FUN_008abf5c(param_1), -1 < iVar3)) {
      if (piVar2[6] != 0) {
        (**(code **)(*piVar2 + 0xc))();
      }
      return piVar2;
    }
    (**(code **)*piVar2)(1);
  }
LAB_008b5994:
  return (int *)0x0;
}


// ==== FUN_008b59f2 @ 0x008b59f2 ====

void FUN_008b59f2(byte param_1)

{
  void *in_ECX;
  
  FUN_008b4803();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008b5a13 @ 0x008b5a13 ====

void FUN_008b5a13(uint param_1,int *param_2,double *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  float *pfVar4;
  float10 fVar5;
  float afStack_214 [128];
  float local_10 [3];
  
  uVar1 = 0;
  uVar2 = uVar1;
  if (param_1 != 0) {
    do {
      if (2 < uVar2) goto LAB_008b5a4b;
      uVar1 = uVar2 + 1;
      afStack_214[uVar2 + 0x81] = (float)*(double *)(*param_2 + uVar2 * 8);
      uVar2 = uVar1;
    } while (uVar1 < param_1);
    if (2 < uVar1) goto LAB_008b5a4b;
  }
  pfVar4 = local_10 + uVar1;
  for (iVar3 = 3 - uVar1; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = 0.0;
    pfVar4 = pfVar4 + 1;
  }
LAB_008b5a4b:
  fVar5 = (float10)FUN_007a1446();
  *param_3 = (double)fVar5;
  return;
}


// ==== FUN_008b5a5d @ 0x008b5a5d ====

undefined4 FUN_008b5a5d(uint param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  if (param_1 != 0) {
    do {
      uVar1 = *(uint *)*param_2;
      *param_2 = (int)((uint *)*param_2 + 1);
      if ((uVar1 != 0) && (uVar4 = 0, uVar1 != 0)) {
        do {
          iVar2 = *(int *)*param_2;
          *param_2 = (int)((int *)*param_2 + 2);
          if (iVar2 == 9) {
            return 0x80004005;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
      }
      uVar1 = *(uint *)*param_2;
      *param_2 = (int)((uint *)*param_2 + 2);
      if ((uVar1 == 0) || (9 < uVar1)) {
        return 0x80004005;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_1);
  }
  return 0;
}


// ==== FUN_008b5abd @ 0x008b5abd ====

undefined4 FUN_008b5abd(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  iVar2 = *piVar1;
  *param_1 = (int)(piVar1 + 1);
  if (iVar2 == 0) {
    iVar2 = piVar1[1];
    *param_1 = (int)(piVar1 + 3);
    if ((((iVar2 == 7) || (iVar2 == 4)) || (iVar2 == 5)) || (iVar2 == 6)) {
      return 0;
    }
  }
  return 0x80004005;
}


// ==== FUN_008b5afa @ 0x008b5afa ====

int FUN_008b5afa(uint *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  
  piVar2 = param_2;
  puVar5 = param_1;
  uVar1 = *param_1;
  if ((0x465801ff < uVar1) && ((uVar1 < 0x46580202 || (uVar1 == 0x54580100)))) {
    iVar4 = FUN_008f2d0f(param_1,0x434c5846,param_2,0);
    piVar3 = param_3;
    if ((-1 < iVar4) &&
       ((((iVar4 != 1 && (iVar4 = FUN_008f2d0f(puVar5,0x54494c43,param_3,0), -1 < iVar4)) &&
         (iVar4 != 1)) && ((param_1 = (uint *)*piVar2, param_1 != (uint *)0x0 && (*piVar3 != 0))))))
    {
      uVar1 = *param_1;
      param_1 = param_1 + 1;
      uVar6 = 0;
      if (uVar1 != 0) {
        do {
          puVar5 = param_1 + 1;
          param_1 = param_1 + 2;
          iVar4 = FUN_008b5a5d(*puVar5,&param_1);
          if ((iVar4 < 0) || (iVar4 = FUN_008b5abd(&param_1), iVar4 < 0)) goto LAB_008b5ba3;
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar1);
      }
      iVar4 = 0;
      goto LAB_008b5ba3;
    }
  }
  iVar4 = -0x7fffbffb;
LAB_008b5ba3:
  return iVar4;
}


// ==== FUN_008b5baa @ 0x008b5baa ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_008b5baa(uint *param_1,uint *param_2,int param_3,int param_4,int param_5,int param_6,int param_7
            ,int param_8,uint param_9,uint param_10,uint param_11,uint param_12,uint param_13,
            uint param_14)

{
  double *pdVar1;
  double **ppdVar2;
  double dVar3;
  uint uVar4;
  undefined8 uVar5;
  int iVar6;
  uint uVar7;
  double *pdVar8;
  double *pdVar9;
  uint *puVar10;
  uint *puVar11;
  double **ppdVar12;
  uint uVar13;
  uint uVar14;
  float10 fVar15;
  double adStack_c20 [256];
  double *local_420 [2];
  int local_418;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  double *local_8;
  
  local_c = 0;
  local_14 = *param_2;
  puVar11 = param_1 + 1;
  local_20 = *param_1;
  if (*param_1 == 0) {
    return 0;
  }
  do {
    local_1c = *puVar11;
    puVar10 = puVar11 + 2;
    uVar14 = *puVar11 & 0xfffff;
    uVar13 = 0;
    local_10 = puVar11[1];
    if (puVar11[1] != 0) {
      do {
        puVar11 = puVar10 + 1;
        iVar6 = 0;
        if (*puVar10 != 0) {
          local_18 = *puVar10;
          do {
            uVar7 = *puVar11;
            puVar10 = puVar11 + 1;
            puVar11 = puVar11 + 2;
            iVar6 = *puVar10 + iVar6 * 4;
            if (uVar7 == 7) {
              iVar6 = __ftol();
            }
            if (((((uVar7 == 1) || (uVar7 == 2)) || (uVar7 == 3)) || ((uVar7 == 4 || (uVar7 == 5))))
               || (uVar7 == 6)) {
              iVar6 = __ftol();
            }
            local_18 = local_18 - 1;
          } while (local_18 != 0);
        }
        uVar4 = *puVar11;
        puVar10 = puVar11 + 2;
        uVar7 = puVar11[1] + iVar6 * 4;
        if (uVar4 == 7) {
          pdVar8 = adStack_c20 + (uVar7 & 0xff);
          goto LAB_008b5d28;
        }
        if (uVar4 == 2) {
          uVar7 = uVar7 & param_10;
          iVar6 = param_4;
LAB_008b5d25:
          pdVar8 = (double *)(iVar6 + uVar7 * 8);
LAB_008b5d28:
          local_420[uVar13] = pdVar8;
        }
        else {
          if (uVar4 == 3) {
            uVar7 = uVar7 & param_9;
            iVar6 = param_3;
            goto LAB_008b5d25;
          }
          if (uVar4 == 1) {
            pdVar8 = (double *)(param_2 + (uVar7 % local_14) * 2 + 1);
            goto LAB_008b5d28;
          }
          if (uVar4 == 9) {
            pdVar8 = (double *)(param_5 + (uVar7 & param_11) * 4);
            goto LAB_008b5d28;
          }
          if (uVar4 == 4) {
            uVar7 = uVar7 & param_12;
            iVar6 = param_6;
            goto LAB_008b5d25;
          }
          if (uVar4 == 5) {
            uVar7 = uVar7 & param_14;
            iVar6 = param_8;
            goto LAB_008b5d25;
          }
          if (uVar4 == 6) {
            uVar7 = uVar7 & param_13;
            iVar6 = param_7;
            goto LAB_008b5d25;
          }
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < local_10);
    }
    uVar13 = puVar10[1];
    uVar7 = puVar10[2];
    puVar11 = puVar10 + 3;
    if (uVar13 == 7) {
      local_8 = adStack_c20 + (uVar7 & 0xff);
LAB_008b5d83:
    }
    else {
      if (uVar13 == 4) {
        uVar7 = uVar7 & param_12;
        iVar6 = param_6;
LAB_008b5d80:
        local_8 = (double *)(iVar6 + uVar7 * 8);
        goto LAB_008b5d83;
      }
      if (uVar13 == 5) {
        uVar7 = uVar7 & param_14;
        iVar6 = param_8;
        goto LAB_008b5d80;
      }
      if (uVar13 == 6) {
        uVar7 = uVar7 & param_13;
        iVar6 = param_7;
        goto LAB_008b5d80;
      }
    }
    pdVar8 = local_8;
    if ((int)local_1c < 0) {
      local_1c = local_1c & 0x7ff00000;
      if (local_1c < 0x20400001) {
        if (local_1c == 0x20400000) {
          if (uVar14 != 0) {
            do {
              *pdVar8 = *(double *)(((int)local_420[1] - (int)local_8) + (int)pdVar8) +
                        *local_420[0];
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (local_1c == 0x20000000) {
          if (uVar14 != 0) {
            pdVar8 = local_420[1];
            do {
              if (*pdVar8 <= *local_420[0]) {
                dVar3 = *pdVar8;
              }
              else {
                dVar3 = *local_420[0];
              }
              *(double *)((int)pdVar8 + ((int)local_8 - (int)local_420[1])) = dVar3;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (local_1c == 0x20100000) {
          if (uVar14 != 0) {
            pdVar8 = local_420[1];
            do {
              if (*local_420[0] <= *pdVar8) {
                dVar3 = *pdVar8;
              }
              else {
                dVar3 = *local_420[0];
              }
              *(double *)(((int)local_8 - (int)local_420[1]) + (int)pdVar8) = dVar3;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (local_1c == 0x20200000) {
          if (uVar14 != 0) {
            do {
              if (*(double *)(((int)local_420[1] - (int)local_8) + (int)pdVar8) <= *local_420[0]) {
                dVar3 = 0.0;
              }
              else {
                dVar3 = 1.0;
              }
              *pdVar8 = dVar3;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if ((local_1c == 0x20300000) && (uVar14 != 0)) {
          do {
            if (*local_420[0] < *(double *)(((int)local_420[1] - (int)local_8) + (int)pdVar8)) {
              dVar3 = 0.0;
            }
            else {
              dVar3 = 1.0;
            }
            *pdVar8 = dVar3;
            pdVar8 = pdVar8 + 1;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
        }
      }
      else if (local_1c == 0x20500000) {
        if (uVar14 != 0) {
          do {
            *pdVar8 = *(double *)(((int)local_420[1] - (int)local_8) + (int)pdVar8) * *local_420[0];
            pdVar8 = pdVar8 + 1;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
        }
      }
      else if (local_1c == 0x20600000) {
        if (uVar14 != 0) {
          do {
            fVar15 = (float10)fpatan((float10)*local_420[0],
                                     (float10)*(double *)
                                               (((int)local_420[1] - (int)local_8) + (int)pdVar8));
            *pdVar8 = (double)fVar15;
            pdVar8 = pdVar8 + 1;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
        }
      }
      else if (local_1c == 0x50000000) {
        uVar13 = 0;
        *local_8 = 0.0;
        if (uVar14 != 0) {
          do {
            pdVar9 = local_420[1] + uVar13;
            uVar13 = uVar13 + 1;
            *pdVar8 = *pdVar9 * *local_420[0] + *pdVar8;
          } while (uVar13 < uVar14);
        }
      }
    }
    else {
      uVar13 = local_1c & 0x7ff00000;
      if (uVar13 < 0x10c00001) {
        if (uVar13 == 0x10c00000) {
          if (uVar14 != 0) {
            do {
              fVar15 = (float10)fpatan((float10)*(double *)
                                                 ((int)pdVar8 + ((int)local_420[0] - (int)local_8)),
                                       (float10)1);
              *pdVar8 = (double)fVar15;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (uVar13 < 0x10600001) {
          if (uVar13 == 0x10600000) {
            uVar13 = 0;
            if (uVar14 != 0) {
              do {
                if (*local_420[uVar13] == _DAT_0099d098) {
                  fVar15 = (float10)0;
                }
                else {
                  fVar15 = (float10)log2(ABS((float10)*(double *)
                                                       ((int)pdVar8 +
                                                       ((int)local_420[0] - (int)local_8))));
                  fVar15 = (float10)0.6931471805599453 * fVar15 * (float10)_DAT_00a17470;
                }
                *pdVar8 = (double)fVar15;
                uVar13 = uVar13 + 1;
                pdVar8 = pdVar8 + 1;
              } while (uVar13 < uVar14);
            }
          }
          else if (uVar13 == 0x10000000) {
            pdVar8 = local_420[0];
            pdVar9 = local_8;
            for (iVar6 = uVar14 * 2; iVar6 != 0; iVar6 = iVar6 + -1) {
              *(undefined4 *)pdVar9 = *(undefined4 *)pdVar8;
              pdVar8 = (double *)((int)pdVar8 + 4);
              pdVar9 = (double *)((int)pdVar9 + 4);
            }
          }
          else if (uVar13 == 0x10100000) {
            if (uVar14 != 0) {
              do {
                *pdVar8 = -*(double *)((int)pdVar8 + ((int)local_420[0] - (int)local_8));
                pdVar8 = pdVar8 + 1;
                uVar14 = uVar14 - 1;
              } while (uVar14 != 0);
            }
          }
          else if (uVar13 == 0x10300000) {
            if (uVar14 != 0) {
              do {
                *pdVar8 = 1.0 / *(double *)((int)pdVar8 + ((int)local_420[0] - (int)local_8));
                pdVar8 = pdVar8 + 1;
                uVar14 = uVar14 - 1;
              } while (uVar14 != 0);
            }
          }
          else if (uVar13 == 0x10400000) {
            if (uVar14 != 0) {
              iVar6 = (int)local_8 - (int)local_420[0];
              pdVar8 = local_420[0];
              do {
                fVar15 = (float10)FUN_008044f0();
                *(double *)(iVar6 + (int)pdVar8) = (double)((float10)*pdVar8 - fVar15);
                pdVar8 = pdVar8 + 1;
                uVar14 = uVar14 - 1;
              } while (uVar14 != 0);
            }
          }
          else if ((uVar13 == 0x10500000) && (uVar14 != 0)) {
            do {
              fVar15 = (float10)FUN_00801f40();
              *pdVar8 = (double)fVar15;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (uVar13 == 0x10700000) {
          if (uVar14 != 0) {
            do {
              *pdVar8 = _DAT_0099d0a0 /
                        SQRT(ABS(*(double *)((int)pdVar8 + ((int)local_420[0] - (int)local_8))));
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (uVar13 == 0x10800000) {
          if (uVar14 != 0) {
            do {
              fVar15 = (float10)fsin((float10)*(double *)
                                               ((int)pdVar8 + ((int)local_420[0] - (int)local_8)));
              *pdVar8 = (double)fVar15;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (uVar13 == 0x10900000) {
          if (uVar14 != 0) {
            do {
              fVar15 = (float10)fcos((float10)*(double *)
                                               ((int)pdVar8 + ((int)local_420[0] - (int)local_8)));
              *pdVar8 = (double)fVar15;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (uVar13 == 0x10a00000) {
          if (uVar14 != 0) {
            do {
              fVar15 = (float10)FUN_00801e30();
              *pdVar8 = (double)fVar15;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if ((uVar13 == 0x10b00000) && (uVar14 != 0)) {
          do {
            fVar15 = (float10)FUN_00801d60();
            *pdVar8 = (double)fVar15;
            pdVar8 = pdVar8 + 1;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
        }
      }
      else if (uVar13 < 0x20500001) {
        if (uVar13 == 0x20500000) {
          if (uVar14 != 0) {
            pdVar8 = local_420[1];
            do {
              *(double *)(((int)local_8 - (int)local_420[1]) + (int)pdVar8) =
                   *(double *)(((int)local_420[0] - (int)local_420[1]) + (int)pdVar8) * *pdVar8;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (uVar13 == 0x20000000) {
          if (uVar14 != 0) {
            pdVar8 = local_420[1];
            do {
              if (*pdVar8 <= *(double *)((int)pdVar8 + ((int)local_420[0] - (int)local_420[1]))) {
                dVar3 = *pdVar8;
              }
              else {
                dVar3 = *(double *)((int)pdVar8 + ((int)local_420[0] - (int)local_420[1]));
              }
              *(double *)((int)pdVar8 + ((int)local_8 - (int)local_420[1])) = dVar3;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (uVar13 == 0x20100000) {
          if (uVar14 != 0) {
            pdVar8 = local_420[1];
            do {
              if (*(double *)((int)pdVar8 + ((int)local_420[0] - (int)local_420[1])) <= *pdVar8) {
                dVar3 = *pdVar8;
              }
              else {
                dVar3 = *(double *)((int)pdVar8 + ((int)local_420[0] - (int)local_420[1]));
              }
              *(double *)((int)pdVar8 + ((int)local_8 - (int)local_420[1])) = dVar3;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (uVar13 == 0x20200000) {
          if (uVar14 != 0) {
            pdVar8 = local_420[1];
            do {
              if (*pdVar8 <= *(double *)((int)pdVar8 + ((int)local_420[0] - (int)local_420[1]))) {
                uVar5 = 0;
              }
              else {
                uVar5 = 0x3ff0000000000000;
              }
              *(undefined8 *)((int)pdVar8 + ((int)local_8 - (int)local_420[1])) = uVar5;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if (uVar13 == 0x20300000) {
          if (uVar14 != 0) {
            pdVar8 = local_420[1];
            do {
              if (*(double *)((int)pdVar8 + ((int)local_420[0] - (int)local_420[1])) < *pdVar8) {
                uVar5 = 0;
              }
              else {
                uVar5 = 0x3ff0000000000000;
              }
              *(undefined8 *)((int)pdVar8 + ((int)local_8 - (int)local_420[1])) = uVar5;
              pdVar8 = pdVar8 + 1;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
        }
        else if ((uVar13 == 0x20400000) && (uVar14 != 0)) {
          pdVar8 = local_420[1];
          do {
            *(double *)((int)pdVar8 + ((int)local_8 - (int)local_420[1])) =
                 *(double *)(((int)local_420[0] - (int)local_420[1]) + (int)pdVar8) + *pdVar8;
            pdVar8 = pdVar8 + 1;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
        }
      }
      else if (uVar13 == 0x20600000) {
        if (uVar14 != 0) {
          pdVar8 = local_420[1];
          do {
            fVar15 = (float10)fpatan((float10)*(double *)
                                               (((int)local_420[0] - (int)local_420[1]) +
                                               (int)pdVar8),(float10)*pdVar8);
            *(double *)((int)pdVar8 + ((int)local_8 - (int)local_420[1])) = (double)fVar15;
            pdVar8 = pdVar8 + 1;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
        }
      }
      else if (uVar13 == 0x30000000) {
        if (uVar14 != 0) {
          pdVar8 = local_420[1];
          do {
            if (*(double *)(((int)local_420[0] - (int)local_420[1]) + (int)pdVar8) < _DAT_0099d098)
            {
              dVar3 = *(double *)((local_418 - (int)local_420[1]) + (int)pdVar8);
            }
            else {
              dVar3 = *pdVar8;
            }
            *(double *)((int)pdVar8 + ((int)local_8 - (int)local_420[1])) = dVar3;
            pdVar8 = pdVar8 + 1;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
        }
      }
      else if (uVar13 == 0x50000000) {
        *local_8 = 0.0;
        pdVar8 = local_8;
        if (uVar14 != 0) {
          iVar6 = (int)local_420[0] - (int)local_420[1];
          pdVar9 = local_420[1];
          do {
            pdVar1 = (double *)(iVar6 + (int)pdVar9);
            dVar3 = *pdVar9;
            pdVar9 = pdVar9 + 1;
            uVar14 = uVar14 - 1;
            *pdVar8 = *pdVar1 * dVar3 + *pdVar8;
          } while (uVar14 != 0);
        }
      }
      else if (uVar13 == 0x50200000) {
        FUN_008b5a13(uVar14,local_420,local_8);
      }
      else if (uVar13 == 0x70e00000) {
        *local_8 = 0.0;
        pdVar8 = local_8;
        local_10 = local_10 >> 1;
        uVar13 = 0;
        if (local_10 != 0) {
          ppdVar12 = local_420 + local_10;
          do {
            ppdVar2 = local_420 + uVar13;
            pdVar9 = *ppdVar12;
            uVar13 = uVar13 + 1;
            ppdVar12 = ppdVar12 + 1;
            *pdVar8 = **ppdVar2 * *pdVar9 + *pdVar8;
          } while (uVar13 < local_10);
        }
      }
    }
    local_c = local_c + 1;
    if (local_20 <= local_c) {
      return 0;
    }
  } while( true );
}


// ==== FUN_008b64c2 @ 0x008b64c2 ====

void FUN_008b64c2(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0xffffffff;
  in_ECX[1] = 0xffffffff;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_008b64d4 @ 0x008b64d4 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008b64d4(LPCWSTR param_1,int param_2)

{
  uint cbMultiByte;
  LPCWSTR lpFileName;
  HANDLE pvVar1;
  undefined4 extraout_EAX;
  undefined4 *in_ECX;
  LPCWSTR local_a0;
  _OSVERSIONINFOA local_9c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_a0 = (LPCWSTR)0x0;
  if (param_1 == (LPCWSTR)0x0) {
    return 0x8876086c;
  }
  lpFileName = param_1;
  if (param_2 != 0) {
    local_9c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_9c);
    if (local_9c.dwPlatformId != 2) {
      cbMultiByte = WideCharToMultiByte(0xfde9,0,param_1,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      lpFileName = operator_new(cbMultiByte);
      if (lpFileName == (LPCWSTR)0x0) {
        return 0x8007000e;
      }
      WideCharToMultiByte(0xfde9,0,param_1,-1,(LPSTR)lpFileName,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0)
      ;
      param_2 = 0;
      local_a0 = lpFileName;
    }
    if (param_2 != 0) {
      pvVar1 = CreateFileW(lpFileName,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x10000000,
                           (HANDLE)0x0);
      goto LAB_008b65c9;
    }
  }
  pvVar1 = CreateFileA((LPCSTR)lpFileName,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x10000000,
                       (HANDLE)0x0);
LAB_008b65c9:
  *in_ECX = pvVar1;
  _free(local_a0);
  return extraout_EAX;
}


// ==== FUN_008b663e @ 0x008b663e ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008b663e(LPCWSTR param_1,int param_2)

{
  uint cbMultiByte;
  LPCWSTR lpFileName;
  HANDLE pvVar1;
  undefined4 extraout_EAX;
  undefined4 *in_ECX;
  LPCWSTR local_a0;
  _OSVERSIONINFOA local_9c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_a0 = (LPCWSTR)0x0;
  if (param_1 == (LPCWSTR)0x0) {
    return 0x8876086c;
  }
  lpFileName = param_1;
  if (param_2 != 0) {
    local_9c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_9c);
    if (local_9c.dwPlatformId != 2) {
      cbMultiByte = WideCharToMultiByte(0xfde9,0,param_1,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      lpFileName = operator_new(cbMultiByte);
      if (lpFileName == (LPCWSTR)0x0) {
        return 0x8007000e;
      }
      WideCharToMultiByte(0xfde9,0,param_1,-1,(LPSTR)lpFileName,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0)
      ;
      param_2 = 0;
      local_a0 = lpFileName;
    }
    if (param_2 != 0) {
      pvVar1 = CreateFileW(lpFileName,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
      goto LAB_008b672f;
    }
  }
  pvVar1 = CreateFileA((LPCSTR)lpFileName,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
LAB_008b672f:
  *in_ECX = pvVar1;
  _free(local_a0);
  return extraout_EAX;
}


// ==== FUN_008b6760 @ 0x008b6760 ====

undefined4 FUN_008b6760(void)

{
  undefined4 *in_ECX;
  
  if ((LPCVOID)in_ECX[2] != (LPCVOID)0x0) {
    UnmapViewOfFile((LPCVOID)in_ECX[2]);
    in_ECX[2] = 0;
    in_ECX[3] = 0;
  }
  if ((HANDLE)in_ECX[1] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)in_ECX[1]);
    in_ECX[1] = 0xffffffff;
  }
  if ((HANDLE)*in_ECX != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)*in_ECX);
    *in_ECX = 0xffffffff;
  }
  return 0;
}


// ==== FUN_008b67a3 @ 0x008b67a3 ====

void FUN_008b67a3(void)

{
  int *in_ECX;
  
  if (*in_ECX == -1) {
    return;
  }
  FUN_008b6760();
  return;
}


// ==== FUN_008b67ae @ 0x008b67ae ====

void FUN_008b67ae(void)

{
  undefined4 *in_ECX;
  
  if ((HGDIOBJ)*in_ECX != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)*in_ECX);
  }
  return;
}


// ==== FUN_008b67bc @ 0x008b67bc ====

undefined4 FUN_008b67bc(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  
  iVar1 = 4;
  bVar4 = true;
  piVar2 = param_2;
  piVar3 = &DAT_00a24fac;
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
    piVar2 = &DAT_00a52010;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *param_2 == *piVar2;
      param_2 = param_2 + 1;
      piVar2 = piVar2 + 1;
    } while (bVar4);
    if (!bVar4) {
      *param_3 = 0;
      return 0x80004002;
    }
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


// ==== FUN_008b6808 @ 0x008b6808 ====

undefined4 FUN_008b6808(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x8876086c;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0xc);
    (**(code **)(**(int **)(param_1 + 0xc) + 4))(*(int **)(param_1 + 0xc));
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_008b6832 @ 0x008b6832 ====

undefined4 FUN_008b6832(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x8876086c;
  }
  else {
    puVar3 = *(undefined4 **)(param_1 + 0x70);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_008b685a @ 0x008b685a ====

undefined4 FUN_008b685a(int *param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1[0x2b] == 0) {
    uVar3 = 0x8876086c;
  }
  else {
    if (param_1[0x31] == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (**(code **)(*param_1 + 0x28))(param_1);
    }
    FUN_007a41ff(1);
    if ((*(byte *)(param_1 + 0x2c) & 3) == 0) {
      piVar1 = (int *)param_1[9];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x14))(piVar1);
      }
      (**(code **)(*(int *)param_1[3] + 0x1a0))((int *)param_1[3],param_1[0xf]);
    }
    if ((((param_1[0x2c] & 0x10U) != 0) && ((param_1[0x2c] & 1U) == 0)) &&
       (piVar1 = (int *)param_1[0xb], piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x14))(piVar1);
    }
    uVar2 = param_1[0x2c];
    if ((((uVar2 & 4) == 0) || ((uVar2 & 8) != 0)) &&
       (((uVar2 & 1) == 0 && (piVar1 = (int *)param_1[0xd], piVar1 != (int *)0x0)))) {
      (**(code **)(*piVar1 + 0x14))(piVar1);
    }
    FUN_007a41ff(0);
    param_1[0x2b] = 0;
  }
  return uVar3;
}


// ==== FUN_008b6908 @ 0x008b6908 ====

undefined4 FUN_008b6908(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0xac) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x3c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x28);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x24);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  return 0;
}


// ==== FUN_008b69b2 @ 0x008b69b2 ====

undefined4 FUN_008b69b2(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_34 [8];
  undefined1 local_14 [12];
  undefined4 local_8;
  
  piVar1 = param_1;
  param_1[0x2b] = 0;
  param_1[0x18] = 1;
  iVar2 = (**(code **)(*(int *)param_1[3] + 0x98))((int *)param_1[3],0,&param_1);
  if (-1 < iVar2) {
    (**(code **)(*param_1 + 0x30))(param_1,local_34);
    (**(code **)(*(int *)piVar1[3] + 0x20))((int *)piVar1[3],0,local_14);
    iVar2 = (**(code **)(*(int *)piVar1[2] + 0x28))
                      ((int *)piVar1[2],piVar1[0x11],piVar1[0x10],local_8,0x80001,1,local_34[0]);
    if (iVar2 < 0) {
      piVar1[0x18] = 0;
    }
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  return 0;
}


// ==== FUN_008b6a36 @ 0x008b6a36 ====

uint FUN_008b6a36(uint param_1,uint param_2,int param_3)

{
  if (*(uint *)(*(int *)(param_3 + 0xb8) + param_1 * 4) <=
      *(uint *)(*(int *)(param_3 + 0xb8) + param_2 * 4)) {
    if (*(uint *)(*(int *)(param_3 + 0xb8) + param_1 * 4) <
        *(uint *)(*(int *)(param_3 + 0xb8) + param_2 * 4)) {
      return 1;
    }
    if (param_2 <= param_1) {
      return (uint)(param_2 < param_1);
    }
  }
  return 0xffffffff;
}


// ==== FUN_008b6a7a @ 0x008b6a7a ====

uint FUN_008b6a7a(uint param_1,uint param_2,int param_3)

{
  if (*(float *)(*(int *)(param_3 + 0xbc) + param_2 * 4) <=
      *(float *)(*(int *)(param_3 + 0xbc) + param_1 * 4)) {
    if (*(float *)(*(int *)(param_3 + 0xbc) + param_2 * 4) <
        *(float *)(*(int *)(param_3 + 0xbc) + param_1 * 4)) {
      return 1;
    }
    if (param_2 <= param_1) {
      return (uint)(param_2 < param_1);
    }
  }
  return 0xffffffff;
}


// ==== FUN_008b6ac6 @ 0x008b6ac6 ====

uint FUN_008b6ac6(uint param_1,uint param_2,int param_3)

{
  if (*(float *)(*(int *)(param_3 + 0xbc) + param_1 * 4) <=
      *(float *)(*(int *)(param_3 + 0xbc) + param_2 * 4)) {
    if (*(float *)(*(int *)(param_3 + 0xbc) + param_1 * 4) <
        *(float *)(*(int *)(param_3 + 0xbc) + param_2 * 4)) {
      return 1;
    }
    if (param_2 <= param_1) {
      return (uint)(param_2 < param_1);
    }
  }
  return 0xffffffff;
}


// ==== FUN_008b6b12 @ 0x008b6b12 ====

void FUN_008b6b12(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  piVar1 = (int *)in_ECX[2];
  *in_ECX = &PTR_FUN_00a17498;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[2] = 0;
  }
  piVar1 = (int *)in_ECX[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[3] = 0;
  }
  piVar1 = (int *)in_ECX[4];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[4] = 0;
  }
  piVar1 = (int *)in_ECX[5];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[5] = 0;
  }
  piVar1 = (int *)in_ECX[6];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[6] = 0;
  }
  piVar1 = (int *)in_ECX[0xf];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0xf] = 0;
  }
  piVar1 = (int *)in_ECX[10];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[10] = 0;
  }
  piVar1 = (int *)in_ECX[9];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[9] = 0;
  }
  piVar1 = (int *)in_ECX[0xc];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0xc] = 0;
  }
  piVar1 = (int *)in_ECX[0xb];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0xb] = 0;
  }
  piVar1 = (int *)in_ECX[0xe];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0xe] = 0;
  }
  piVar1 = (int *)in_ECX[0xd];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0xd] = 0;
  }
  iVar2 = in_ECX[0x1c];
  if (iVar2 == 0) {
    _free((void *)in_ECX[0x2d]);
    return;
  }
  _free((void *)(iVar2 - (uint)*(byte *)(iVar2 + -1)));
  return;
}


// ==== FUN_008b6c26 @ 0x008b6c26 ====

int FUN_008b6c26(int *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  byte bVar4;
  int *in_ECX;
  int local_150;
  int local_14c;
  uint local_11c;
  uint local_110;
  int local_e4;
  undefined1 local_20 [12];
  byte local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7789f794;
  }
  else {
    in_ECX[3] = (int)param_1;
    (**(code **)(*param_1 + 4))(param_1);
    iVar1 = (**(code **)(*(int *)in_ECX[3] + 0x18))((int *)in_ECX[3],in_ECX + 2);
    if ((-1 < iVar1) &&
       (iVar1 = (**(code **)(*(int *)in_ECX[3] + 0x158))((int *)in_ECX[3],&DAT_00a17478,in_ECX + 4),
       -1 < iVar1)) {
      (**(code **)(*(int *)in_ECX[3] + 0x1c))((int *)in_ECX[3],&local_150);
      in_ECX[0x10] = local_150;
      in_ECX[0x11] = local_14c;
      in_ECX[0x13] = (local_110 & 0x4000000 | 0x8000000) >> 0x1a;
      in_ECX[0x14] = (local_110 & 0x400 | 0x800) >> 10;
      in_ECX[0x18] = 1;
      in_ECX[0x15] = ((local_110 & 0x20000) != 0) + 1;
      in_ECX[0x16] = local_e4;
      in_ECX[0x17] = local_11c & 0x10;
      (**(code **)(*(int *)in_ECX[3] + 0x24))((int *)in_ECX[3],local_20);
      in_ECX[0x12] = -(uint)((local_14 & 0xa0) != 0) & 2;
      pvVar2 = operator_new(0xd0);
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        bVar4 = 0x10 - ((byte)pvVar2 & 0xf);
        puVar3 = (undefined4 *)((int)pvVar2 + (uint)bVar4);
        *(byte *)((int)puVar3 + -1) = bVar4;
        FUN_0040d030(puVar3,0x40,3,FUN_0079e14e);
      }
      in_ECX[0x1c] = (int)puVar3;
      if (puVar3 == (undefined4 *)0x0) {
        iVar1 = -0x7ff8fff2;
      }
      else {
        in_ECX[0x20] = (int)(puVar3 + 0x10);
        in_ECX[0x24] = (int)(puVar3 + 0x20);
        puVar3[0xe] = 0;
        puVar3[0xd] = 0;
        puVar3[0xc] = 0;
        puVar3[0xb] = 0;
        puVar3[9] = 0;
        puVar3[8] = 0;
        puVar3[7] = 0;
        puVar3[6] = 0;
        puVar3[4] = 0;
        puVar3[3] = 0;
        puVar3[2] = 0;
        puVar3[1] = 0;
        puVar3[0xf] = 0x3f800000;
        puVar3[10] = 0x3f800000;
        puVar3[5] = 0x3f800000;
        *puVar3 = 0x3f800000;
        puVar3 = (undefined4 *)in_ECX[0x20];
        puVar3[0xe] = 0;
        puVar3[0xd] = 0;
        puVar3[0xc] = 0;
        puVar3[0xb] = 0;
        puVar3[9] = 0;
        puVar3[8] = 0;
        puVar3[7] = 0;
        puVar3[6] = 0;
        puVar3[4] = 0;
        puVar3[3] = 0;
        puVar3[2] = 0;
        puVar3[1] = 0;
        puVar3[0xf] = 0x3f800000;
        puVar3[10] = 0x3f800000;
        puVar3[5] = 0x3f800000;
        *puVar3 = 0x3f800000;
        puVar3 = (undefined4 *)in_ECX[0x24];
        puVar3[0xe] = 0;
        puVar3[0xd] = 0;
        puVar3[0xc] = 0;
        puVar3[0xb] = 0;
        puVar3[9] = 0;
        local_8 = 0xbf800000;
        puVar3[8] = 0;
        puVar3[7] = 0;
        puVar3[6] = 0;
        puVar3[4] = 0;
        puVar3[3] = 0;
        puVar3[2] = 0;
        puVar3[1] = 0;
        puVar3[0xf] = 0x3f800000;
        puVar3[10] = 0x3f800000;
        puVar3[5] = 0x3f800000;
        *puVar3 = 0x3f800000;
        local_10 = 0;
        in_ECX[0x19] = 1;
        in_ECX[0x1a] = 1;
        local_c = 0;
        in_ECX[0x25] = 0;
        in_ECX[0x26] = 0;
        in_ECX[0x27] = -0x40800000;
        iVar1 = (**(code **)(*in_ECX + 0x34))();
        if (-1 < iVar1) {
          iVar1 = 0;
        }
      }
    }
  }
  return iVar1;
}


// ==== FUN_008b6ea6 @ 0x008b6ea6 ====

undefined4 FUN_008b6ea6(int param_1,undefined4 *param_2)

{
  float *pfVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar3 = 0x8876086c;
  }
  else {
    if (*(int *)(param_1 + 0xac) != 0) {
      if ((*(int *)(param_1 + 100) == 0) && ((*(byte *)(param_1 + 0xb0) & 8) == 0)) {
        iVar4 = *(int *)(param_1 + 0xcc) * 0x60 + *(int *)(param_1 + 0xc0);
        thunk_FUN_0079e5b9(iVar4,0x18,iVar4,0x18,*(undefined4 *)(param_1 + 0x70),
                           (*(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xcc)) * 4);
      }
      *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0xc4);
    }
    fVar2 = DAT_0099d080;
    puVar5 = *(undefined4 **)(param_1 + 0x70);
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *param_2;
      param_2 = param_2 + 1;
      puVar5 = puVar5 + 1;
    }
    pfVar1 = *(float **)(param_1 + 0x70);
    if (((((*pfVar1 == fVar2) && (pfVar1[1] == DAT_0099cdc8)) && (pfVar1[2] == DAT_0099cdc8)) &&
        (((pfVar1[3] == DAT_0099cdc8 && (pfVar1[4] == DAT_0099cdc8)) &&
         ((pfVar1[5] == DAT_0099d080 && ((pfVar1[6] == DAT_0099cdc8 && (pfVar1[7] == DAT_0099cdc8)))
          ))))) &&
       ((pfVar1[8] == DAT_0099cdc8 &&
        (((((pfVar1[9] == DAT_0099cdc8 && (pfVar1[10] == DAT_0099d080)) &&
           (pfVar1[0xb] == DAT_0099cdc8)) &&
          ((pfVar1[0xc] == DAT_0099cdc8 && (pfVar1[0xd] == DAT_0099cdc8)))) &&
         ((pfVar1[0xe] == DAT_0099cdc8 && (pfVar1[0xf] == DAT_0099d080)))))))) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 100) = uVar3;
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_008b704b @ 0x008b704b ====

undefined4 FUN_008b704b(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  float *pfVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0xac) != 0) {
    return 0x8876086c;
  }
  if (param_2 == (undefined4 *)0x0) {
    param_2 = param_3;
    if (param_3 == (undefined4 *)0x0) {
      puVar3 = *(undefined4 **)(param_1 + 0x80);
      puVar3[0xe] = 0;
      puVar3[0xd] = 0;
      puVar3[0xc] = 0;
      puVar3[0xb] = 0;
      puVar3[9] = 0;
      puVar3[8] = 0;
      puVar3[7] = 0;
      puVar3[6] = 0;
      puVar3[4] = 0;
      puVar3[3] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      puVar3[0xf] = 0x3f800000;
      puVar3[10] = 0x3f800000;
      puVar3[5] = 0x3f800000;
      *puVar3 = 0x3f800000;
      goto LAB_008b70f0;
    }
  }
  else if (param_3 != (undefined4 *)0x0) {
    thunk_FUN_0079ee7b(*(undefined4 *)(param_1 + 0x80),param_2,param_3);
    goto LAB_008b70f0;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x80);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
LAB_008b70f0:
  iVar2 = *(int *)(param_1 + 0x80);
  pfVar1 = (float *)(param_1 + 0x94);
  *pfVar1 = -*(float *)(iVar2 + 8);
  *(float *)(param_1 + 0x98) = -*(float *)(iVar2 + 0x18);
  *(float *)(param_1 + 0x9c) = -*(float *)(iVar2 + 0x28);
  thunk_FUN_0079e1ba(pfVar1,pfVar1);
  *(undefined4 *)(param_1 + 0x68) = 0;
  return 0;
}


// ==== FUN_008b712d @ 0x008b712d ====

undefined4 FUN_008b712d(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(param_1 + 0xac) != 0) {
    return 0x8876086c;
  }
  if (param_2 == (undefined4 *)0x0) {
    param_2 = param_3;
    if (param_3 == (undefined4 *)0x0) {
      puVar2 = *(undefined4 **)(param_1 + 0x80);
      puVar2[0xe] = 0;
      puVar2[0xd] = 0;
      puVar2[0xc] = 0;
      puVar2[0xb] = 0;
      puVar2[9] = 0;
      puVar2[8] = 0;
      puVar2[7] = 0;
      puVar2[6] = 0;
      puVar2[4] = 0;
      puVar2[3] = 0;
      puVar2[2] = 0;
      puVar2[1] = 0;
      puVar2[0xf] = 0x3f800000;
      puVar2[10] = 0x3f800000;
      puVar2[5] = 0x3f800000;
      *puVar2 = 0x3f800000;
      goto LAB_008b71d2;
    }
  }
  else if (param_3 != (undefined4 *)0x0) {
    thunk_FUN_0079ee7b(*(undefined4 *)(param_1 + 0x80),param_2,param_3);
    goto LAB_008b71d2;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x80);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
LAB_008b71d2:
  iVar1 = *(int *)(param_1 + 0x80);
  puVar2 = (undefined4 *)(param_1 + 0x94);
  *puVar2 = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(iVar1 + 0x28);
  thunk_FUN_0079e1ba(puVar2,puVar2);
  *(undefined4 *)(param_1 + 0x68) = 0;
  return 0;
}


// ==== FUN_008b7209 @ 0x008b7209 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008b7209(float param_1,uint param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  float *pfVar8;
  float local_5c [16];
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  fVar4 = param_1;
  if ((*(int *)((int)param_1 + 0xac) == 0) && ((param_2 & 0xffffff00) == 0)) {
    *(uint *)((int)param_1 + 0xb0) = param_2;
    if ((param_2 & 8) != 0) {
      *(uint *)((int)param_1 + 0xb0) = param_2 | 4;
    }
    piVar1 = (int *)((int)param_1 + 0x14);
    if (*piVar1 == 0) {
      iVar5 = (**(code **)(**(int **)((int)param_1 + 0xc) + 0x6c))
                        (*(int **)((int)param_1 + 0xc),0xc000,8,0x65,
                         *(undefined4 *)((int)param_1 + 0x48),piVar1,0);
      if (iVar5 < 0) {
        return iVar5;
      }
      (**(code **)(*(int *)*piVar1 + 0x2c))((int *)*piVar1,0,0,&param_1,0);
      uVar7 = 0;
      iVar5 = 6;
      do {
        sVar6 = (short)uVar7;
        *(short *)(iVar5 + -6 + (int)param_1) = sVar6;
        *(short *)(iVar5 + -4 + (int)param_1) = sVar6 + 1;
        *(short *)(iVar5 + -2 + (int)param_1) = sVar6 + 2;
        *(short *)(iVar5 + (int)param_1) = sVar6 + 2;
        *(short *)(iVar5 + 2 + (int)param_1) = sVar6 + 1;
        *(short *)(iVar5 + 4 + (int)param_1) = sVar6 + 3;
        uVar7 = uVar7 + 4;
        iVar5 = iVar5 + 0xc;
      } while (uVar7 < 0x4000);
      (**(code **)(**(int **)((int)fVar4 + 0x14) + 0x30))(*(int **)((int)fVar4 + 0x14));
    }
    if (*(int *)((int)fVar4 + 0x18U) == 0) {
      iVar5 = (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x68))
                        (*(int **)((int)fVar4 + 0xc),0x60000,0x208,0,
                         *(undefined4 *)((int)fVar4 + 0x48),(int *)((int)fVar4 + 0x18U),0);
      if (iVar5 < 0) {
        return iVar5;
      }
      *(undefined4 *)((int)fVar4 + 0x1c) = 0;
      *(undefined4 *)((int)fVar4 + 0x20) = 0;
    }
    FUN_007a41ff(1);
    if (*(int *)((int)fVar4 + 0x24) == 0) {
      param_1 = 0.0;
      do {
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xf0))(*(int **)((int)fVar4 + 0xc));
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x15c))
                  (*(int **)((int)fVar4 + 0xc),*(undefined4 *)((int)fVar4 + 0x10));
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x170))(*(int **)((int)fVar4 + 0xc),0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x1ac))(*(int **)((int)fVar4 + 0xc),0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),8,3);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),9,2);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x16,1);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x80,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x88,1);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x97,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x98,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x13c))(*(int **)((int)fVar4 + 0xc),0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0xa7,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0xb8,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0xc2,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0xa8,0xf);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x1c,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x30,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x1d,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x34,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x89,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x91,1);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x10c))(*(int **)((int)fVar4 + 0xc),0,1,4);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x10c))(*(int **)((int)fVar4 + 0xc),0,2,2);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x10c))(*(int **)((int)fVar4 + 0xc),0,3,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x10c))(*(int **)((int)fVar4 + 0xc),0,4,4);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x10c))(*(int **)((int)fVar4 + 0xc),0,5,2);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x10c))(*(int **)((int)fVar4 + 0xc),0,6,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x10c))(*(int **)((int)fVar4 + 0xc),0,0xb,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x10c))(*(int **)((int)fVar4 + 0xc),0,0x18,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x10c))(*(int **)((int)fVar4 + 0xc),1,1,1);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x10c))(*(int **)((int)fVar4 + 0xc),1,4,1);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x114))(*(int **)((int)fVar4 + 0xc),0,1,3);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x114))(*(int **)((int)fVar4 + 0xc),0,2,3);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x114))
                  (*(int **)((int)fVar4 + 0xc),0,5,*(undefined4 *)((int)fVar4 + 0x4c));
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x114))
                  (*(int **)((int)fVar4 + 0xc),0,6,*(undefined4 *)((int)fVar4 + 0x50));
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x114))
                  (*(int **)((int)fVar4 + 0xc),0,7,*(undefined4 *)((int)fVar4 + 0x54));
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x114))(*(int **)((int)fVar4 + 0xc),0,8,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x114))(*(int **)((int)fVar4 + 0xc),0,9,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x114))
                  (*(int **)((int)fVar4 + 0xc),0,10,*(undefined4 *)((int)fVar4 + 0x58));
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x114))(*(int **)((int)fVar4 + 0xc),0,0xb,0);
        if (param_1 == 0.0) {
          (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x15c))
                    (*(int **)((int)fVar4 + 0xc),*(undefined4 *)((int)fVar4 + 0x10));
          (**(code **)(**(int **)((int)fVar4 + 0xc) + 400))(*(int **)((int)fVar4 + 0xc),0,0,0,0);
          (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x104))(*(int **)((int)fVar4 + 0xc),0,0);
          iVar5 = (int)fVar4 + 0x24;
        }
        else {
          iVar5 = (int)fVar4 + 0x28;
        }
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xf4))(*(int **)((int)fVar4 + 0xc),iVar5);
        param_1 = (float)((int)param_1 + 1);
      } while ((uint)param_1 < 2);
    }
    if (*(int *)((int)fVar4 + 0x2c) == 0) {
      param_1 = 0.0;
      do {
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xf0))(*(int **)((int)fVar4 + 0xc));
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))
                  (*(int **)((int)fVar4 + 0xc),0xf,*(int *)((int)fVar4 + 0x5c) != 0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))
                  (*(int **)((int)fVar4 + 0xc),0x18,
                   (-(uint)(*(int *)((int)fVar4 + 0x60) != 0) & 0xffffffc1) + 0x3f);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x19,5);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))
                  (*(int **)((int)fVar4 + 0xc),0x1b,*(int *)((int)fVar4 + 0x60) != 0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0xce,0);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x13,5);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0x14,6);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xe4))(*(int **)((int)fVar4 + 0xc),0xab,1);
        iVar5 = (int)fVar4 + 0x30;
        if (param_1 == 0.0) {
          iVar5 = (int)fVar4 + 0x2c;
        }
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xf4))(*(int **)((int)fVar4 + 0xc),iVar5);
        param_1 = (float)((int)param_1 + 1);
      } while ((uint)param_1 < 2);
    }
    if (*(int *)((int)fVar4 + 0x34) == 0) {
      param_1 = 0.0;
      do {
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xf0))(*(int **)((int)fVar4 + 0xc));
        local_5c[0xe] = 0.0;
        local_5c[0xd] = 0.0;
        local_5c[0xc] = 0.0;
        local_5c[0xb] = 0.0;
        local_5c[9] = 0.0;
        local_5c[8] = 0.0;
        local_5c[7] = 0.0;
        local_5c[6] = 0.0;
        local_5c[4] = 0.0;
        local_5c[3] = 0.0;
        local_5c[2] = 0.0;
        local_5c[1] = 0.0;
        local_5c[0xf] = 1.0;
        local_5c[10] = 1.0;
        local_5c[5] = 1.0;
        local_5c[0] = 1.0;
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xb0))
                  (*(int **)((int)fVar4 + 0xc),0x100,local_5c);
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xb0))(*(int **)((int)fVar4 + 0xc),2,local_5c);
        if (param_1 == 0.0) {
          (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xb0))(*(int **)((int)fVar4 + 0xc),3,local_5c)
          ;
          iVar5 = (int)fVar4 + 0x34;
        }
        else {
          iVar5 = (int)fVar4 + 0x38;
        }
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xf4))(*(int **)((int)fVar4 + 0xc),iVar5);
        param_1 = (float)((int)param_1 + 1);
      } while ((uint)param_1 < 2);
    }
    if ((*(uint *)((int)fVar4 + 0xb0) & 2) == 0) {
      if ((*(uint *)((int)fVar4 + 0xb0) & 1) == 0) {
        (**(code **)(**(int **)((int)fVar4 + 0x24) + 0x10))(*(int **)((int)fVar4 + 0x24));
      }
      if ((*(byte *)((int)fVar4 + 0xb0) & 1) == 0) {
        piVar1 = *(int **)((int)fVar4 + 0x3c);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)((int)fVar4 + 0x3c) = 0;
        }
        (**(code **)(**(int **)((int)fVar4 + 0xc) + 0x1a4))
                  (*(int **)((int)fVar4 + 0xc),(int)fVar4 + 0x3c);
      }
      (**(code **)(**(int **)((int)fVar4 + 0x28) + 0x14))(*(int **)((int)fVar4 + 0x28));
    }
    if ((*(uint *)((int)fVar4 + 0xb0) & 0x10) != 0) {
      if ((*(uint *)((int)fVar4 + 0xb0) & 1) == 0) {
        (**(code **)(**(int **)((int)fVar4 + 0x2c) + 0x10))(*(int **)((int)fVar4 + 0x2c));
      }
      (**(code **)(**(int **)((int)fVar4 + 0x30) + 0x14))(*(int **)((int)fVar4 + 0x30));
    }
    uVar7 = *(uint *)((int)fVar4 + 0xb0);
    if ((uVar7 & 4) == 0) {
      if ((uVar7 & 1) == 0) {
        (**(code **)(**(int **)((int)fVar4 + 0x34) + 0x10))(*(int **)((int)fVar4 + 0x34));
      }
      (**(code **)(**(int **)((int)fVar4 + 0x38) + 0x14))(*(int **)((int)fVar4 + 0x38));
      (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xc0))(*(int **)((int)fVar4 + 0xc),&local_1c);
      fVar2 = (float)local_14;
      if (local_14 < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      fVar2 = DAT_0099d080 / fVar2;
      param_1 = (float)local_10;
      if (local_10 < 0) {
        param_1 = param_1 + _DAT_0099d104;
      }
      param_1 = DAT_0099d080 / param_1;
      pfVar8 = local_5c;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *pfVar8 = 0.0;
        pfVar8 = pfVar8 + 1;
      }
      param_2 = local_1c;
      local_5c[0] = fVar2 + fVar2;
      fVar3 = (float)(int)local_1c;
      if ((int)local_1c < 0) {
        fVar3 = fVar3 + _DAT_0099d104;
      }
      local_5c[0xc] = (fVar3 * fVar2 * _DAT_009fc7bc - fVar2) - DAT_0099d080;
      local_5c[5] = param_1 * _DAT_009fc7bc;
      fVar2 = (float)local_18;
      if (local_18 < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      local_5c[0xd] = (fVar2 + fVar2 + DAT_0099d080) * param_1 + DAT_0099d080;
      local_5c[10] = 1.0;
      local_5c[0xf] = 1.0;
      (**(code **)(**(int **)((int)fVar4 + 0xc) + 0xb0))(*(int **)((int)fVar4 + 0xc),3,local_5c);
    }
    else if ((uVar7 & 8) != 0) {
      if ((uVar7 & 1) == 0) {
        (**(code **)(**(int **)((int)fVar4 + 0x34) + 0x10))(*(int **)((int)fVar4 + 0x34));
      }
      (**(code **)(**(int **)((int)fVar4 + 0x38) + 0x14))(*(int **)((int)fVar4 + 0x38));
    }
    FUN_007a41ff(0);
    *(undefined4 *)((int)fVar4 + 0xe0) = 0;
    *(undefined4 *)((int)fVar4 + 0xc4) = 0;
    *(undefined4 *)((int)fVar4 + 0xcc) = 0;
    *(undefined4 *)((int)fVar4 + 0xe4) = 0;
    *(undefined4 *)((int)fVar4 + 0xd0) = 0;
    *(undefined4 *)((int)fVar4 + 0xd4) = 0;
    *(undefined4 *)((int)fVar4 + 0xd8) = 0;
    *(undefined4 *)((int)fVar4 + 0xdc) = 0;
    *(undefined4 *)((int)fVar4 + 0xac) = 1;
    iVar5 = 0;
  }
  else {
    iVar5 = -0x7789f794;
  }
  return iVar5;
}


// ==== FUN_008b7972 @ 0x008b7972 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_008b7972(int param_1,int *param_2,int *param_3,float *param_4,float *param_5,float param_6)

{
  uint uVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  void *pvVar9;
  undefined4 extraout_EAX;
  float *pfVar10;
  float local_3c;
  float local_38;
  float local_34;
  float local_30 [3];
  undefined1 local_24 [16];
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar8 = param_1;
  if ((*(int *)(param_1 + 0xac) == 0) || (param_2 == (int *)0x0)) {
    return 0x8876086c;
  }
  uVar1 = *(uint *)(param_1 + 200);
  if (*(uint *)(param_1 + 0xc4) < uVar1) {
    if (*(int **)(param_1 + 0xd4) != param_2) {
      *(int **)(param_1 + 0xd4) = param_2;
      if (*(int *)(param_1 + 0xc4) != 0) {
        *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + 1;
      }
      (**(code **)(*param_2 + 0x44))(param_2,0,local_24);
      fVar4 = DAT_0099d080;
      fVar3 = (float)local_c;
      *(int *)(param_1 + 0xd8) = local_c;
      *(uint *)(param_1 + 0xdc) = local_8;
      if (local_c < 0) {
        fVar3 = fVar3 + _DAT_0099d104;
      }
      *(float *)(param_1 + 0xe0) = fVar4 / fVar3;
      fVar3 = (float)(int)local_8;
      if ((int)local_8 < 0) {
        fVar3 = fVar3 + _DAT_0099d104;
      }
      *(float *)(param_1 + 0xe4) = fVar4 / fVar3;
    }
    if (param_3 == (int *)0x0) {
      local_c = *(int *)(param_1 + 0xd8);
      local_8 = *(int *)(param_1 + 0xdc);
      local_14 = 0;
      local_10 = 0;
    }
    else {
      local_14 = *param_3;
      local_10 = param_3[1];
      local_c = param_3[2];
      local_8 = param_3[3];
    }
    fVar3 = (float)(local_c - local_14);
    *(undefined4 *)(*(int *)(param_1 + 0xb8) + *(int *)(param_1 + 0xc4) * 4) =
         *(undefined4 *)(param_1 + 0xd4);
    param_2 = (int *)(float)(int)(local_8 - local_10);
    if ((*(byte *)(param_1 + 0xb0) & 8) == 0) {
      if (param_5 == (float *)0x0) {
        param_5 = local_30;
        local_30[0] = 0.0;
        local_30[1] = 0.0;
        local_30[2] = 0.0;
      }
      local_3c = *param_5;
      local_38 = param_5[1];
      local_34 = param_5[2];
      if (param_4 != (float *)0x0) {
        local_3c = local_3c - *param_4;
        local_38 = local_38 - param_4[1];
        local_34 = local_34 - param_4[2];
      }
    }
    else {
      if (*(int *)(param_1 + 0x68) == 0) {
        *(undefined4 *)(param_1 + 0x68) = 1;
        thunk_FUN_0079ee7b(*(undefined4 *)(param_1 + 0x90),*(undefined4 *)(param_1 + 0x70),
                           *(undefined4 *)(param_1 + 0x80));
        pfVar10 = *(float **)(param_1 + 0x90);
        pfVar2 = *(float **)(param_1 + 0x70);
        *(float *)(param_1 + 0xa0) =
             SQRT(pfVar10[2] * pfVar10[2] + pfVar10[1] * pfVar10[1] + *pfVar10 * *pfVar10);
        *(float *)(param_1 + 0xa4) =
             SQRT(pfVar10[6] * pfVar10[6] + pfVar10[5] * pfVar10[5] + pfVar10[4] * pfVar10[4]);
        *(float *)(param_1 + 0xa8) =
             SQRT(pfVar10[10] * pfVar10[10] + pfVar10[9] * pfVar10[9] + pfVar10[8] * pfVar10[8]);
        fVar4 = DAT_0099cdc8;
        if (*pfVar2 < DAT_0099cdc8) {
          *(float *)(param_1 + 0xa0) = -*(float *)(param_1 + 0xa0);
        }
        if (pfVar2[5] < fVar4) {
          *(float *)(param_1 + 0xa4) = -*(float *)(param_1 + 0xa4);
        }
        if (pfVar2[10] < fVar4) {
          *(float *)(param_1 + 0xa8) = -*(float *)(param_1 + 0xa8);
        }
      }
      if (param_5 == (float *)0x0) {
        param_5 = local_30;
        local_30[0] = 0.0;
        local_30[1] = 0.0;
        local_30[2] = 0.0;
      }
      thunk_FUN_0079e5a0(&local_3c,param_5,*(undefined4 *)(param_1 + 0x90));
      fVar3 = fVar3 * *(float *)(param_1 + 0xa0);
      param_2 = (int *)((float)param_2 * *(float *)(param_1 + 0xa4));
      if (param_4 != (float *)0x0) {
        local_3c = local_3c - *param_4 * *(float *)(param_1 + 0xa0);
        local_38 = local_38 - param_4[1] * *(float *)(param_1 + 0xa4);
        local_34 = local_34 - *(float *)(param_1 + 0xa8) * param_4[2];
      }
    }
    fVar4 = (float)local_14 * *(float *)(param_1 + 0xe0);
    fVar5 = (float)local_10 * *(float *)(param_1 + 0xe4);
    fVar6 = (float)local_c * *(float *)(param_1 + 0xe0);
    pfVar10 = (float *)(*(int *)(param_1 + 0xc4) * 0x60 + *(int *)(param_1 + 0xc0));
    fVar7 = (float)(int)local_8 * *(float *)(param_1 + 0xe4);
    *pfVar10 = local_3c;
    pfVar10[1] = local_38;
    pfVar10[2] = local_34;
    pfVar10[4] = fVar4;
    pfVar10[5] = fVar5;
    pfVar10[3] = param_6;
    pfVar10[6] = local_3c;
    pfVar10[7] = local_38 + (float)param_2;
    pfVar10[8] = local_34;
    pfVar10[10] = fVar4;
    pfVar10[0xb] = fVar7;
    pfVar10[9] = param_6;
    pfVar10[0xc] = local_3c + fVar3;
    pfVar10[0xd] = local_38;
    pfVar10[0xe] = local_34;
    pfVar10[0x10] = fVar6;
    pfVar10[0xf] = param_6;
    pfVar10[0x11] = fVar5;
    pfVar10[0x15] = param_6;
    pfVar10[0x12] = local_3c + fVar3;
    pfVar10[0x13] = local_38 + (float)param_2;
    pfVar10[0x14] = local_34;
    pfVar10[0x16] = fVar6;
    pfVar10[0x17] = fVar7;
    *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + 1;
    return 0;
  }
  if (uVar1 == 0) {
    param_1 = 0x40;
  }
  else {
    param_1 = uVar1 * 2;
  }
  local_8 = param_1 << 2;
  pvVar9 = operator_new(local_8);
  if (pvVar9 == (void *)0x0) {
    return 0x8007000e;
  }
  _free(*(void **)(iVar8 + 0xb4));
  return extraout_EAX;
}


// ==== FUN_008b7e75 @ 0x008b7e75 ====

undefined4 FUN_008b7e75(float param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  code *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  float local_8;
  
  iVar2 = (int)param_1;
  if (*(int *)((int)param_1 + 0xac) == 0) {
    return 0x8876086c;
  }
  if ((*(int *)((int)param_1 + 100) == 0) && ((*(byte *)((int)param_1 + 0xb0) & 8) == 0)) {
    iVar5 = *(int *)((int)param_1 + 0xcc) * 0x60 + *(int *)((int)param_1 + 0xc0);
    thunk_FUN_0079e5b9(iVar5,0x18,iVar5,0x18,*(undefined4 *)((int)param_1 + 0x70),
                       (*(int *)((int)param_1 + 0xc4) - *(int *)((int)param_1 + 0xcc)) * 4);
  }
  uVar6 = *(uint *)((int)param_1 + 0xb0);
  iVar5 = *(int *)((int)param_1 + 0xc4);
  *(int *)((int)param_1 + 0xcc) = iVar5;
  local_c = 0;
  if ((uVar6 & 0x20) == 0) {
    if ((uVar6 & 0xc0) == 0) goto LAB_008b80a0;
    local_8 = 3.4028235e+38;
    param_1 = -3.4028235e+38;
    if (((uVar6 & 4) == 0) || ((uVar6 & 8) != 0)) {
      uVar6 = 0;
      if (iVar5 != 0) {
        iVar5 = 0;
        do {
          iVar4 = *(int *)(iVar2 + 0xc0) + iVar5;
          fVar1 = -(*(float *)(iVar4 + 0x50) + *(float *)(iVar4 + 0x38) + *(float *)(iVar4 + 0x20) +
                   *(float *)(iVar4 + 8));
          if (fVar1 < local_8) {
            local_8 = fVar1;
          }
          if (param_1 < fVar1) {
            param_1 = fVar1;
          }
          *(float *)(*(int *)(iVar2 + 0xbc) + uVar6 * 4) = fVar1;
          uVar6 = uVar6 + 1;
          iVar5 = iVar5 + 0x60;
        } while (uVar6 < *(uint *)(iVar2 + 0xc4));
        goto LAB_008b8047;
      }
    }
    else {
      uVar6 = 0;
      if (iVar5 != 0) {
        iVar5 = 0;
        do {
          pfVar3 = (float *)(*(int *)(iVar2 + 0xc0) + iVar5);
          fVar1 = (pfVar3[6] + *pfVar3 + pfVar3[0xc] + pfVar3[0x12]) * *(float *)(iVar2 + 0x94) +
                  (pfVar3[7] + pfVar3[1] + pfVar3[0xd] + pfVar3[0x13]) * *(float *)(iVar2 + 0x98) +
                  (pfVar3[8] + pfVar3[2] + pfVar3[0xe] + pfVar3[0x14]) * *(float *)(iVar2 + 0x9c);
          if (fVar1 < local_8) {
            local_8 = fVar1;
          }
          if (param_1 < fVar1) {
            param_1 = fVar1;
          }
          *(float *)(*(int *)(iVar2 + 0xbc) + uVar6 * 4) = fVar1;
          uVar6 = uVar6 + 1;
          iVar5 = iVar5 + 0x60;
        } while (uVar6 < *(uint *)(iVar2 + 0xc4));
LAB_008b8047:
        if (local_8 == param_1) goto LAB_008b80a0;
      }
    }
    uVar6 = 0;
    if (*(int *)(iVar2 + 0xc4) != 0) {
      do {
        *(uint *)(*(int *)(iVar2 + 0xb4) + uVar6 * 4) = uVar6;
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(iVar2 + 0xc4));
    }
    uVar11 = *(undefined4 *)(iVar2 + 0xc4);
    uVar10 = *(undefined4 *)(iVar2 + 0xb4);
    if ((*(byte *)(iVar2 + 0xb0) & 0x40) == 0) {
      pcVar9 = FUN_008b6ac6;
    }
    else {
      pcVar9 = FUN_008b6a7a;
    }
  }
  else {
    if (*(int *)((int)param_1 + 0xd0) == 0) goto LAB_008b80a0;
    uVar6 = 0;
    if (iVar5 != 0) {
      do {
        *(uint *)(*(int *)((int)param_1 + 0xb4) + uVar6 * 4) = uVar6;
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)((int)param_1 + 0xc4));
    }
    uVar11 = *(undefined4 *)((int)param_1 + 0xc4);
    uVar10 = *(undefined4 *)((int)param_1 + 0xb4);
    pcVar9 = FUN_008b6a36;
  }
  FUN_00915b0e(pcVar9,uVar10,uVar11,iVar2);
  local_c = 1;
LAB_008b80a0:
  (**(code **)(**(int **)(iVar2 + 0xc) + 0x15c))
            (*(int **)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x10));
  (**(code **)(**(int **)(iVar2 + 0xc) + 0x1a0))
            (*(int **)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x14));
  (**(code **)(**(int **)(iVar2 + 0xc) + 400))
            (*(int **)(iVar2 + 0xc),0,*(undefined4 *)(iVar2 + 0x18),0,0x18);
  local_8 = 0.0;
  if (local_c == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = **(uint **)(iVar2 + 0xb4);
  }
  param_1 = -NAN;
  if (*(int *)(iVar2 + 0xc4) != 0) {
    do {
      iVar5 = *(int *)(*(int *)(iVar2 + 0xb8) + uVar6 * 4);
      if (param_1 != (float)iVar5) {
        (**(code **)(**(int **)(iVar2 + 0xc) + 0x104))(*(int **)(iVar2 + 0xc),0,iVar5);
        param_1 = (float)iVar5;
      }
      (**(code **)(**(int **)(iVar2 + 0x18) + 0x2c))
                (*(int **)(iVar2 + 0x18),0,0,&local_18,
                 (-(uint)(*(int *)(iVar2 + 0x20) != 0) & 0xfffff000) + 0x2000);
      local_10 = *(int *)(iVar2 + 0x1c);
      local_14 = *(int *)(iVar2 + 0x20);
      while ((((uint)local_8 < *(uint *)(iVar2 + 0xc4) &&
              (param_1 == (float)*(int *)(*(int *)(iVar2 + 0xb8) + uVar6 * 4))) &&
             (*(uint *)(iVar2 + 0x20) < 0x4000))) {
        puVar7 = (undefined4 *)(uVar6 * 0x60 + *(int *)(iVar2 + 0xc0));
        puVar8 = (undefined4 *)(local_18 + *(uint *)(iVar2 + 0x20) * 0x18);
        for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 4;
        *(int *)(iVar2 + 0x1c) = *(int *)(iVar2 + 0x1c) + 6;
        local_8 = (float)((int)local_8 + 1);
        if (local_c == 0) {
          uVar6 = (uint)local_8;
        }
        else {
          uVar6 = *(uint *)(*(int *)(iVar2 + 0xb4) + (int)local_8 * 4);
        }
      }
      (**(code **)(**(int **)(iVar2 + 0x18) + 0x30))(*(int **)(iVar2 + 0x18));
      (**(code **)(**(int **)(iVar2 + 0xc) + 0x148))
                (*(undefined4 *)(iVar2 + 0xc),4,0,local_14,*(int *)(iVar2 + 0x20) - local_14,
                 local_10,(uint)(*(int *)(iVar2 + 0x1c) - local_10) / 3);
      if (0x3fff < *(uint *)(iVar2 + 0x20)) {
        *(undefined4 *)(iVar2 + 0x20) = 0;
        *(undefined4 *)(iVar2 + 0x1c) = 0;
      }
    } while ((uint)local_8 < *(uint *)(iVar2 + 0xc4));
  }
  *(undefined4 *)(iVar2 + 0xc4) = 0;
  *(undefined4 *)(iVar2 + 0xe0) = 0;
  *(undefined4 *)(iVar2 + 0xcc) = 0;
  *(undefined4 *)(iVar2 + 0xd0) = 0;
  *(undefined4 *)(iVar2 + 0xe4) = 0;
  *(undefined4 *)(iVar2 + 0xd4) = 0;
  *(undefined4 *)(iVar2 + 0xd8) = 0;
  *(undefined4 *)(iVar2 + 0xdc) = 0;
  return 0;
}


// ==== FUN_008b8239 @ 0x008b8239 ====

void FUN_008b8239(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a17498;
  in_ECX[1] = 1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[0xf] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0x19] = 1;
  in_ECX[0x1a] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x32] = 0;
  return;
}


// ==== FUN_008b82ad @ 0x008b82ad ====

undefined4 FUN_008b82ad(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 4);
  if (*piVar1 == 0) {
    FUN_008a1556(1);
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008b82ca @ 0x008b82ca ====

undefined4 FUN_008b82ca(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  
  iVar1 = 4;
  bVar4 = true;
  piVar2 = param_2;
  piVar3 = &DAT_00a24f9c;
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
    piVar2 = &DAT_00a52010;
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


// ==== FUN_008b8310 @ 0x008b8310 ====

undefined4 FUN_008b8310(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x8876086c;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 8);
    (**(code **)(**(int **)(param_1 + 8) + 4))(*(int **)(param_1 + 8));
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_008b833a @ 0x008b833a ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008b833a(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_34;
  byte local_30;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2a;
  undefined1 local_29;
  undefined4 local_28 [8];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  if ((param_2 == (undefined4 *)0x0) ||
     (iVar1 = GetObjectA(*(HANDLE *)(param_1 + 0x14),0x3c,&local_44), iVar1 == 0)) {
    return 0x8876086c;
  }
  *param_2 = local_44;
  param_2[1] = local_40;
  param_2[2] = local_34;
  param_2[3] = *(undefined4 *)(param_1 + 0x4fc);
  param_2[4] = (uint)local_30;
  *(undefined1 *)(param_2 + 5) = local_2d;
  *(undefined1 *)((int)param_2 + 0x15) = local_2c;
  *(undefined1 *)((int)param_2 + 0x16) = local_2a;
  *(undefined1 *)((int)param_2 + 0x17) = local_29;
  puVar2 = local_28;
  puVar3 = param_2 + 6;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return 0;
}


// ==== FUN_008b83c4 @ 0x008b83c4 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008b83c4(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_54;
  byte local_50;
  undefined1 local_4d;
  undefined1 local_4c;
  undefined1 local_4a;
  undefined1 local_49;
  undefined4 local_48 [5];
  undefined4 local_34;
  byte local_30;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2a;
  undefined1 local_29;
  CHAR local_28 [32];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  if (param_2 == (undefined4 *)0x0) {
LAB_008b8455:
    uVar2 = 0x8876086c;
  }
  else {
    if (DAT_00b5de80 == 0) {
      iVar1 = GetObjectA(*(HANDLE *)(param_1 + 0x14),0x3c,local_48 + 1);
      if (iVar1 == 0) goto LAB_008b8455;
      *param_2 = local_48[1];
      param_2[1] = local_48[2];
      param_2[2] = local_34;
      param_2[3] = *(undefined4 *)(param_1 + 0x4fc);
      param_2[4] = (uint)local_30;
      *(undefined1 *)(param_2 + 5) = local_2d;
      *(undefined1 *)((int)param_2 + 0x15) = local_2c;
      *(undefined1 *)((int)param_2 + 0x16) = local_2a;
      *(undefined1 *)((int)param_2 + 0x17) = local_29;
      MultiByteToWideChar(0,0,local_28,-1,(LPWSTR)(param_2 + 6),0x20);
      *(undefined2 *)((int)param_2 + 0x56) = 0;
    }
    else {
      iVar1 = GetObjectW(*(HANDLE *)(param_1 + 0x14),0x5c,&local_64);
      if (iVar1 == 0) goto LAB_008b8455;
      *param_2 = local_64;
      param_2[1] = local_60;
      param_2[2] = local_54;
      param_2[3] = *(undefined4 *)(param_1 + 0x4fc);
      param_2[4] = (uint)local_50;
      *(undefined1 *)(param_2 + 5) = local_4d;
      *(undefined1 *)((int)param_2 + 0x15) = local_4c;
      *(undefined1 *)((int)param_2 + 0x16) = local_4a;
      *(undefined1 *)((int)param_2 + 0x17) = local_49;
      puVar3 = local_48;
      puVar4 = param_2 + 6;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008b84c0 @ 0x008b84c0 ====

void FUN_008b84c0(int param_1,LPTEXTMETRICA param_2)

{
  GetTextMetricsA(*(HDC *)(param_1 + 0x10),param_2);
  return;
}


// ==== FUN_008b84d8 @ 0x008b84d8 ====

undefined4 FUN_008b84d8(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = 0;
  if (param_2 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)(param_1 + 0x30);
    for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_008b84fa @ 0x008b84fa ====

undefined4 FUN_008b84fa(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}


// ==== FUN_008b8509 @ 0x008b8509 ====

int FUN_008b8509(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xc) == 0) ||
     (iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x30))(*(int **)(param_1 + 0xc)), -1 < iVar1)
     ) {
    return 0;
  }
  return iVar1;
}


// ==== FUN_008b852a @ 0x008b852a ====

int FUN_008b852a(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xc) == 0) ||
     (iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x34))(*(int **)(param_1 + 0xc)), -1 < iVar1)
     ) {
    return 0;
  }
  return iVar1;
}


// ==== FUN_008b854b @ 0x008b854b ====

bool FUN_008b854b(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 local_18 [20];
  
  iVar1 = GetGlyphOutline(*(undefined4 *)(in_ECX + 0x10),param_1,0x80,local_18,0,0,&DAT_00a174d0);
  return iVar1 != -1;
}


// ==== FUN_008b857f @ 0x008b857f ====

void FUN_008b857f(int *param_1,void **param_2)

{
  BITMAPINFO *lpbmi;
  int in_ECX;
  uint uVar1;
  int iVar2;
  BITMAPINFO *pBVar3;
  
  uVar1 = *param_1 * param_1[1] * 4 + 0x28;
  lpbmi = operator_new(uVar1);
  if (lpbmi == (BITMAPINFO *)0x0) {
    return;
  }
  pBVar3 = lpbmi;
  for (uVar1 = uVar1 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    (pBVar3->bmiHeader).biSize = 0;
    pBVar3 = (BITMAPINFO *)&(pBVar3->bmiHeader).biWidth;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)&(pBVar3->bmiHeader).biSize = 0;
    pBVar3 = (BITMAPINFO *)((int)&(pBVar3->bmiHeader).biSize + 1);
  }
  (lpbmi->bmiHeader).biSize = 0x28;
  (lpbmi->bmiHeader).biWidth = *param_1;
  (lpbmi->bmiHeader).biHeight = -param_1[1];
  (lpbmi->bmiHeader).biCompression = 0;
  (lpbmi->bmiHeader).biPlanes = 1;
  (lpbmi->bmiHeader).biBitCount = 0x20;
  CreateDIBSection(*(HDC *)(in_ECX + 0x10),lpbmi,0,param_2,(HANDLE)0x0,0);
  _free(lpbmi);
  return;
}


// ==== FUN_008b8605 @ 0x008b8605 ====

undefined4 FUN_008b8605(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 *in_ECX;
  int iVar5;
  undefined4 *puVar6;
  
  uVar2 = param_1;
  uVar1 = in_ECX[1];
  if (uVar1 < param_1) {
    param_1 = uVar1;
    if (uVar1 != 0) goto LAB_008b8626;
    for (param_1 = 0x10; param_1 < uVar2; param_1 = param_1 * 2) {
LAB_008b8626:
    }
    puVar3 = operator_new(param_1 << 4);
    if (puVar3 != (undefined4 *)0x0) {
      if (param_2 == 0) {
        puVar6 = (undefined4 *)*in_ECX;
        for (iVar5 = (in_ECX[1] & 0xfffffff) << 2; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar3 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar3 = puVar3 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined1 *)puVar3 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + 1);
        }
      }
      _free((void *)*in_ECX);
      return extraout_EAX;
    }
    uVar4 = 0x8007000e;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


// ==== FUN_008b8685 @ 0x008b8685 ====

void FUN_008b8685(byte param_1)

{
  void *in_ECX;
  
  FUN_008b9b12();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008b86a6 @ 0x008b86a6 ====

undefined4 FUN_008b86a6(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 *in_ECX;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar4 = param_1;
  uVar1 = in_ECX[1];
  if (uVar1 < param_1) {
    if (uVar1 == 0) {
      param_1 = 0x10;
      goto LAB_008b86c3;
    }
    uVar1 = uVar1 * 2;
    do {
      param_1 = uVar1;
LAB_008b86c3:
      uVar1 = param_1 * 2;
    } while (param_1 < uVar4);
    puVar2 = operator_new(uVar1);
    if (puVar2 != (undefined4 *)0x0) {
      if (param_2 == 0) {
        uVar1 = in_ECX[1];
        puVar6 = (undefined4 *)*in_ECX;
        for (uVar4 = (uVar1 & 0x7fffffff) >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar2 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar2 = puVar2 + 1;
        }
        for (iVar5 = (uVar1 & 1) << 1; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined1 *)puVar2 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar2 = (undefined4 *)((int)puVar2 + 1);
        }
      }
      _free((void *)*in_ECX);
      return extraout_EAX;
    }
    uVar3 = 0x8007000e;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_008b8725 @ 0x008b8725 ====

undefined4 FUN_008b8725(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 *in_ECX;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar1 = param_1;
  uVar4 = in_ECX[1];
  if (uVar4 < param_1) {
    param_1 = uVar4;
    if (uVar4 != 0) goto LAB_008b8746;
    for (param_1 = 0x10; param_1 < uVar1; param_1 = param_1 * 2) {
LAB_008b8746:
    }
    puVar2 = operator_new(param_1 << 2);
    if (puVar2 != (undefined4 *)0x0) {
      if (param_2 == 0) {
        puVar6 = (undefined4 *)*in_ECX;
        for (uVar4 = in_ECX[1] & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar2 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar2 = puVar2 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined1 *)puVar2 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar2 = (undefined4 *)((int)puVar2 + 1);
        }
      }
      _free((void *)*in_ECX);
      return extraout_EAX;
    }
    uVar3 = 0x8007000e;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_008b87a5 @ 0x008b87a5 ====

undefined4 FUN_008b87a5(uint param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 *in_ECX;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar3 = param_1;
  uVar4 = in_ECX[1];
  if (uVar4 < param_1) {
    param_1 = uVar4;
    if (uVar4 != 0) goto LAB_008b87c9;
    for (param_1 = 0x10; param_1 < uVar3; param_1 = param_1 * 2) {
LAB_008b87c9:
    }
    puVar1 = operator_new(param_1);
    if (puVar1 != (undefined4 *)0x0) {
      if (param_2 == 0) {
        uVar4 = in_ECX[1];
        puVar5 = (undefined4 *)*in_ECX;
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar1 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar1 = puVar1 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar1 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar1 = (undefined4 *)((int)puVar1 + 1);
        }
      }
      _free((void *)*in_ECX);
      return extraout_EAX;
    }
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008b8822 @ 0x008b8822 ====

undefined4 FUN_008b8822(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 *in_ECX;
  int iVar5;
  undefined4 *puVar6;
  
  uVar2 = param_1;
  uVar1 = in_ECX[1];
  if (uVar1 < param_1) {
    param_1 = uVar1;
    if (uVar1 != 0) goto LAB_008b8843;
    for (param_1 = 0x10; param_1 < uVar2; param_1 = param_1 * 2) {
LAB_008b8843:
    }
    puVar3 = operator_new(param_1 << 3);
    if (puVar3 != (undefined4 *)0x0) {
      if (param_2 == 0) {
        puVar6 = (undefined4 *)*in_ECX;
        for (iVar5 = (in_ECX[1] & 0x1fffffff) << 1; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar3 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar3 = puVar3 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined1 *)puVar3 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + 1);
        }
      }
      _free((void *)*in_ECX);
      return extraout_EAX;
    }
    uVar4 = 0x8007000e;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


// ==== FUN_008b88a2 @ 0x008b88a2 ====

undefined4 FUN_008b88a2(uint param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 *in_ECX;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  uVar3 = in_ECX[1];
  if (uVar3 < param_1) {
    if (uVar3 == 0) {
      uVar3 = 0x10;
    }
    else {
      uVar3 = uVar3 * 2;
    }
    for (; uVar3 < param_1; uVar3 = uVar3 * 2) {
    }
    puVar1 = operator_new(uVar3 * 0xc);
    if (puVar1 != (undefined4 *)0x0) {
      if (param_2 == 0) {
        puVar5 = (undefined4 *)*in_ECX;
        for (uVar3 = (uint)(in_ECX[1] * 0xc) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar1 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar1 = puVar1 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar1 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar1 = (undefined4 *)((int)puVar1 + 1);
        }
      }
      _free((void *)*in_ECX);
      return extraout_EAX;
    }
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008b8935 @ 0x008b8935 ====

void FUN_008b8935(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  uint uVar2;
  
  piVar1 = (int *)in_ECX[2];
  *in_ECX = &PTR_FUN_00a174e0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[2] = 0;
  }
  piVar1 = (int *)in_ECX[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[3] = 0;
  }
  if (((HDC)in_ECX[4] != (HDC)0x0) && ((HGDIOBJ)in_ECX[6] != (HGDIOBJ)0x0)) {
    SelectObject((HDC)in_ECX[4],(HGDIOBJ)in_ECX[6]);
  }
  if ((HGDIOBJ)in_ECX[5] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)in_ECX[5]);
  }
  if (((HDC)in_ECX[4] != (HDC)0x0) && ((HGDIOBJ)in_ECX[8] != (HGDIOBJ)0x0)) {
    SelectObject((HDC)in_ECX[4],(HGDIOBJ)in_ECX[8]);
  }
  if ((HGDIOBJ)in_ECX[7] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)in_ECX[7]);
  }
  if ((HDC)in_ECX[4] != (HDC)0x0) {
    DeleteDC((HDC)in_ECX[4]);
  }
  if (in_ECX[0x23] != 0) {
    _free((void *)in_ECX[0x24]);
    return;
  }
  uVar2 = 0;
  if (in_ECX[0x126] != 0) {
    do {
      piVar1 = *(int **)(in_ECX[0x127] + uVar2 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)in_ECX[0x126]);
  }
  if (in_ECX[0x1c] != 0) {
    (*DAT_00b5deb8)(in_ECX + 0x1c);
  }
  _free((void *)in_ECX[0x13e]);
  return;
}


// ==== FUN_008b8afa @ 0x008b8afa ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008b8afa(int *param_1,LONG *param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  byte bVar4;
  undefined1 uVar5;
  uint uVar6;
  HMODULE hModule;
  HDC hdc;
  HFONT pHVar7;
  HGDIOBJ pvVar8;
  DWORD DVar9;
  uint uVar10;
  uint uVar11;
  void *pvVar12;
  int in_ECX;
  int iVar13;
  LONG *pLVar14;
  undefined4 *puVar15;
  LONG *pLVar16;
  undefined4 *puVar17;
  LONG *local_a4;
  HMODULE local_a0;
  LONG local_9c [6];
  CHAR local_84 [31];
  undefined1 local_65;
  undefined1 local_64 [36];
  undefined1 local_40 [22];
  byte bStack_2a;
  undefined1 uStack_29;
  LONG local_28 [5];
  undefined4 local_14;
  undefined4 local_10;
  BYTE BStack_c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_a4 = param_2;
  if ((param_1 == (int *)0x0) || (param_2 == (LONG *)0x0)) {
    return -0x7789f794;
  }
  *(int **)(in_ECX + 8) = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  if (DAT_00b5de88 == 0) {
    DAT_00b5de88 = 1;
    FUN_008a1598();
    if ((DAT_00b5de80 != 0) &&
       ((local_a0 = GetModuleHandleA(s_gdi32_dll_00a176a0), local_a0 != (HMODULE)0x0 ||
        (local_a0 = LoadLibraryA(s_gdi32_dll_00a176a0), local_a0 != (HMODULE)0x0)))) {
      DAT_00b5de8c = GetProcAddress(local_a0,s_GetCharABCWidthsI_00a1768c);
      if (DAT_00b5de8c == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5de90 = GetProcAddress(local_a0,s_GetCharWidthI_00a1767c);
      if (DAT_00b5de90 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      _DAT_00b5de94 = GetProcAddress(local_a0,s_GetFontUnicodeRanges_00a17664);
      if (_DAT_00b5de94 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
    }
    hModule = GetModuleHandleA(s_usp10_dll_00a17658);
    if ((hModule != (HMODULE)0x0) ||
       (hModule = LoadLibraryA(s_usp10_dll_00a17658), hModule != (HMODULE)0x0)) {
      DAT_00b5de98 = 1;
      DAT_00b5de9c = GetProcAddress(hModule,s_ScriptItemize_00a17648);
      if (DAT_00b5de9c == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5dea0 = GetProcAddress(hModule,s_ScriptShape_00a1763c);
      if (DAT_00b5dea0 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5dea4 = GetProcAddress(hModule,s_ScriptPlace_00a17630);
      if (DAT_00b5dea4 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5dea8 = GetProcAddress(hModule,s_ScriptBreak_00a17624);
      if (DAT_00b5dea8 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      _DAT_00b5deac = GetProcAddress(hModule,s_ScriptJustify_00a17614);
      if (_DAT_00b5deac == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      _DAT_00b5deb0 = GetProcAddress(hModule,s_ScriptTextOut_00a17604);
      if (_DAT_00b5deb0 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5deb4 = GetProcAddress(hModule,s_ScriptGetProperties_00a175f0);
      if (DAT_00b5deb4 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5deb8 = GetProcAddress(hModule,s_ScriptFreeCache_00a175e0);
      if (DAT_00b5deb8 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5debc = GetProcAddress(hModule,s_ScriptRecordDigitSubstitution_00a175c0);
      if (DAT_00b5debc == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5dec0 = GetProcAddress(hModule,s_ScriptApplyDigitSubstitution_00a175a0);
      if (DAT_00b5dec0 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5dec4 = GetProcAddress(hModule,s_ScriptGetFontProperties_00a17588);
      if (DAT_00b5dec4 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5dec8 = GetProcAddress(hModule,s_ScriptStringAnalyse_00a17574);
      if (DAT_00b5dec8 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5decc = GetProcAddress(hModule,s_ScriptStringOut_00a17564);
      if (DAT_00b5decc == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5ded0 = GetProcAddress(hModule,s_ScriptStringFree_00a17550);
      if (DAT_00b5ded0 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5ded4 = GetProcAddress(hModule,s_ScriptStringCPtoX_00a1753c);
      if (DAT_00b5ded4 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      DAT_00b5ded8 = GetProcAddress(hModule,s_ScriptString_pSize_00a17528);
      if (DAT_00b5ded8 == (FARPROC)0x0) {
        return -0x7ff8fff2;
      }
      (*DAT_00b5deb4)(&DAT_00b5dee8,&local_a0);
      (*DAT_00b5debc)(0x400,&DAT_00b5dedc);
    }
  }
  hdc = CreateCompatibleDC((HDC)0x0);
  *(HDC *)(in_ECX + 0x10) = hdc;
  if (hdc == (HDC)0x0) {
    return -0x7ff8fff2;
  }
  SetMapMode(hdc,1);
  if (DAT_00b5de80 == 0) {
    SetTextAlign(*(HDC *)(in_ECX + 0x10),1);
  }
  if (param_3 != 0) {
    if (DAT_00b5de80 == 0) {
      pLVar14 = param_2;
      pLVar16 = local_9c;
      for (iVar13 = 6; iVar13 != 0; iVar13 = iVar13 + -1) {
        *pLVar16 = *pLVar14;
        pLVar14 = pLVar14 + 1;
        pLVar16 = pLVar16 + 1;
      }
      WideCharToMultiByte(0,0,(LPCWSTR)(param_2 + 6),-1,local_84,0x20,(LPCSTR)0x0,(LPBOOL)0x0);
      param_3 = 0;
      local_a4 = local_9c;
      local_65 = 0;
    }
    if (param_3 != 0) {
      puVar15 = (undefined4 *)local_64;
      for (iVar13 = 0x17; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      local_64._0_4_ = *local_a4;
      local_64._4_4_ = local_a4[1];
      local_64._16_4_ = local_a4[2];
      local_64[0x14] = (BYTE)local_a4[4];
      local_64[0x17] = (BYTE)local_a4[5];
      local_64[0x18] = *(BYTE *)((int)local_a4 + 0x15);
      local_64[0x1a] = *(byte *)((int)local_a4 + 0x16);
      local_64[0x1b] = *(BYTE *)((int)local_a4 + 0x17);
      pLVar14 = local_a4 + 6;
      pLVar16 = (LONG *)(local_64 + 0x1c);
      for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
        *pLVar16 = *pLVar14;
        pLVar14 = pLVar14 + 1;
        pLVar16 = pLVar16 + 1;
      }
      if ((local_64[0x1a] & 7) == 0) {
        local_64[0x1a] = local_64[0x1a] | 4;
      }
      pHVar7 = CreateFontIndirectW((LOGFONTW *)local_64);
      goto LAB_008b8ec0;
    }
  }
  puVar15 = (undefined4 *)(local_64 + 0x20);
  for (iVar13 = 0xf; iVar13 != 0; iVar13 = iVar13 + -1) {
    *puVar15 = 0;
    puVar15 = puVar15 + 1;
  }
  local_64._32_4_ = *local_a4;
  local_40._0_4_ = local_a4[1];
  local_40._12_4_ = local_a4[2];
  local_40[0x10] = (undefined1)local_a4[4];
  local_40[0x13] = (undefined1)local_a4[5];
  stack0xffffffd4 = CONCAT31(stack0xffffffd5,*(undefined1 *)((int)local_a4 + 0x15));
  bVar4 = *(byte *)((int)local_a4 + 0x16);
  bStack_2a = bVar4;
  uVar5 = *(undefined1 *)((int)local_a4 + 0x17);
  stack0xffffffd4 = CONCAT13(uVar5,stack0xffffffd4);
  pLVar14 = local_a4 + 6;
  pLVar16 = local_28;
  for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
    *pLVar16 = *pLVar14;
    pLVar14 = pLVar14 + 1;
    pLVar16 = pLVar16 + 1;
  }
  if ((bVar4 & 7) == 0) {
    stack0xffffffd4 = CONCAT13(uVar5,stack0xffffffd4) | 0x40000;
  }
  pHVar7 = CreateFontIndirectA((LOGFONTA *)(local_64 + 0x20));
LAB_008b8ec0:
  *(HFONT *)(in_ECX + 0x14) = pHVar7;
  if (pHVar7 != (HFONT)0x0) {
    *(LONG *)(in_ECX + 0x4fc) = local_a4[3];
    pvVar8 = SelectObject(*(HDC *)(in_ECX + 0x10),*(HGDIOBJ *)(in_ECX + 0x14));
    *(HGDIOBJ *)(in_ECX + 0x18) = pvVar8;
    DVar9 = GetFontLanguageInfo(*(HDC *)(in_ECX + 0x10));
    *(DWORD *)(in_ECX + 0x6c) = DVar9;
    if (DAT_00b5de80 == 0) {
      GetTextMetricsA(*(HDC *)(in_ECX + 0x10),(LPTEXTMETRICA)local_40);
      *(ushort *)(in_ECX + 0x5c) = (ushort)(byte)local_14;
      *(ushort *)(in_ECX + 0x5e) = (ushort)local_14._1_1_;
      puVar15 = (undefined4 *)local_40;
      puVar17 = (undefined4 *)(in_ECX + 0x30);
      for (iVar13 = 0xb; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar17 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar17 = puVar17 + 1;
      }
      *(undefined4 *)(in_ECX + 100) = local_10;
      *(ushort *)(in_ECX + 0x60) = (ushort)local_14._2_1_;
      *(BYTE *)(in_ECX + 0x68) = BStack_c;
      *(ushort *)(in_ECX + 0x62) = (ushort)local_14._3_1_;
    }
    else {
      GetTextMetricsW(*(HDC *)(in_ECX + 0x10),(LPTEXTMETRICW)(in_ECX + 0x30));
    }
    *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x48);
    *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(in_ECX + 0x30);
    iVar13 = FUN_008b857f((undefined4 *)(in_ECX + 0x24),in_ECX + 0x2c);
    *(int *)(in_ECX + 0x1c) = iVar13;
    if (iVar13 != 0) {
      SetBkMode(*(HDC *)(in_ECX + 0x10),2);
      SetBkColor(*(HDC *)(in_ECX + 0x10),0);
      SetTextColor(*(HDC *)(in_ECX + 0x10),0xffffff);
      pvVar8 = SelectObject(*(HDC *)(in_ECX + 0x10),*(HGDIOBJ *)(in_ECX + 0x1c));
      *(HGDIOBJ *)(in_ECX + 0x20) = pvVar8;
      *(undefined4 *)(in_ECX + 0x8c) = 0;
      puVar15 = (undefined4 *)(in_ECX + 0x90);
      for (iVar13 = 0x100; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      puVar1 = (uint *)(in_ECX + 0x4b4);
      *(undefined4 *)(in_ECX + 0x494) = 0x15;
      *(undefined4 *)(in_ECX + 0x498) = 0;
      *(undefined4 *)(in_ECX + 0x4a4) = 0;
      *(undefined4 *)(in_ECX + 0x4c0) = 0;
      *(undefined4 *)(in_ECX + 0x4ac) = 1;
      *puVar1 = 1;
      if (1 < *(uint *)(in_ECX + 0x30)) {
        do {
          *(int *)(in_ECX + 0x4ac) = *(int *)(in_ECX + 0x4ac) << 1;
          *puVar1 = *puVar1 + 1;
        } while (*(uint *)(in_ECX + 0x4ac) < *(uint *)(in_ECX + 0x30));
      }
      uVar10 = *(uint *)(in_ECX + 0x4ac);
      *(uint *)(in_ECX + 0x4c8) = uVar10;
      *(uint *)(in_ECX + 0x4d0) = *puVar1;
      while (uVar10 < *(uint *)(in_ECX + 0x44)) {
        *(int *)(in_ECX + 0x4ac) = *(int *)(in_ECX + 0x4ac) << 1;
        *puVar1 = *puVar1 + 1;
        uVar10 = *(uint *)(in_ECX + 0x4ac);
      }
      while (*(uint *)(in_ECX + 0x4c8) < *(uint *)(in_ECX + 0x48)) {
        *(int *)(in_ECX + 0x4c8) = *(int *)(in_ECX + 0x4c8) << 1;
        *(int *)(in_ECX + 0x4d0) = *(int *)(in_ECX + 0x4d0) + 1;
      }
      uVar10 = *(uint *)(in_ECX + 0x4ac);
      uVar6 = *(uint *)(in_ECX + 0x4fc);
      uVar11 = uVar10 * uVar10;
      *(uint *)(in_ECX + 0x4b0) = uVar11;
      *(int *)(in_ECX + 0x4cc) = *(int *)(in_ECX + 0x4c8) * *(int *)(in_ECX + 0x4c8);
      if (uVar6 != 0) {
        if (uVar6 < *puVar1) {
          *puVar1 = uVar6;
        }
        if (uVar6 < *(uint *)(in_ECX + 0x4d0)) {
          *(uint *)(in_ECX + 0x4d0) = uVar6;
        }
      }
      local_a0 = (HMODULE)(((uint)*(ushort *)(in_ECX + 0x5e) - (uint)*(ushort *)(in_ECX + 0x5c)) + 1
                          );
      if ((HMODULE)0x80 < local_a0) {
        local_a0 = (HMODULE)0x80;
      }
      puVar2 = (uint *)(in_ECX + 0x4b8);
      *puVar2 = uVar10;
      puVar3 = (uint *)(in_ECX + 0x4d4);
      *puVar3 = *(uint *)(in_ECX + 0x4c8);
      if (uVar11 < uVar11 * (int)local_a0) {
        do {
          if (0xff < *puVar2) break;
          uVar10 = *puVar2 * 2;
          *puVar2 = uVar10;
        } while (uVar10 * uVar10 < (uint)(*(int *)(in_ECX + 0x4b0) * (int)local_a0));
      }
      uVar10 = *puVar2;
      if (*(uint *)(in_ECX + 0x4c8) < uVar10) {
        *puVar3 = uVar10;
      }
      iVar13 = *puVar3 * *puVar3;
      *(int *)(in_ECX + 0x4d8) = iVar13;
      *(int *)(in_ECX + 0x4c4) = iVar13;
      *(uint *)(in_ECX + 0x4bc) = uVar10 * uVar10;
      *(uint *)(in_ECX + 0x4a8) = uVar10 * uVar10;
      iVar13 = FUN_008a063e(*(undefined4 *)(in_ECX + 8),puVar2,puVar2,puVar1,0,in_ECX + 0x494,1);
      if (iVar13 < 0) {
        return iVar13;
      }
      iVar13 = FUN_008a063e(*(undefined4 *)(in_ECX + 8),puVar3,puVar3,in_ECX + 0x4d0,0,
                            in_ECX + 0x494,1);
      if (iVar13 < 0) {
        return iVar13;
      }
      if (((*(int *)(in_ECX + 0x494) != 0x15) || (*puVar2 < *(uint *)(in_ECX + 0x4ac))) ||
         (*puVar3 < *(uint *)(in_ECX + 0x4c8))) {
        return -0x7789f4a7;
      }
      uVar10 = *(uint *)(in_ECX + 0x4d0);
      puVar15 = (undefined4 *)(in_ECX + 0x4a4);
      puVar17 = (undefined4 *)(in_ECX + 0x4dc);
      for (iVar13 = 7; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar17 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar17 = puVar17 + 1;
      }
      if (1 < uVar10) {
        pvVar12 = operator_new(*(int *)(in_ECX + 0x4cc) << 3);
        *(void **)(in_ECX + 0x4f8) = pvVar12;
        if (pvVar12 == (void *)0x0) {
          return -0x7ff8fff2;
        }
      }
      if (DAT_00b5de98 == 0) {
        puVar15 = (undefined4 *)(local_40 + 0x14);
        for (iVar13 = 9; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar15 = 0;
          puVar15 = puVar15 + 1;
        }
        local_14 = in_ECX + 0x7a;
        stack0xffffffd4 = 0x24;
        local_10._0_1_ = '\x01';
        local_10._1_1_ = '\0';
        local_10._2_1_ = '\0';
        local_10._3_1_ = '\0';
        if (DAT_00b5de80 == 0) {
          GetCharacterPlacementA
                    (*(HDC *)(in_ECX + 0x10),(LPCSTR)(in_ECX + 0x60),1,0,
                     (LPGCP_RESULTSA)(local_40 + 0x14),0);
        }
        else {
          GetCharacterPlacementW
                    (*(HDC *)(in_ECX + 0x10),(LPCWSTR)(in_ECX + 0x60),1,0,
                     (LPGCP_RESULTSW)(local_40 + 0x14),0);
        }
        local_14 = in_ECX + 0x78;
        stack0xffffffd4 = 0x24;
        local_10._0_1_ = '\x01';
        local_10._1_1_ = '\0';
        local_10._2_1_ = '\0';
        local_10._3_1_ = '\0';
        if (DAT_00b5de80 == 0) {
          GetCharacterPlacementA
                    (*(HDC *)(in_ECX + 0x10),(LPCSTR)(in_ECX + 0x62),1,0,
                     (LPGCP_RESULTSA)(local_40 + 0x14),0);
        }
        else {
          GetCharacterPlacementW
                    (*(HDC *)(in_ECX + 0x10),(LPCWSTR)(in_ECX + 0x62),1,0,
                     (LPGCP_RESULTSW)(local_40 + 0x14),0);
        }
      }
      else {
        puVar15 = (undefined4 *)(in_ECX + 0x74);
        *puVar15 = 0;
        *(undefined4 *)(in_ECX + 0x78) = 0;
        *(undefined4 *)(in_ECX + 0x7c) = 0;
        *(undefined4 *)(in_ECX + 0x80) = 0;
        *puVar15 = 0x10;
        iVar13 = (*DAT_00b5dec4)(*(undefined4 *)(in_ECX + 0x10),in_ECX + 0x70,puVar15);
        if (iVar13 < 0) {
          return iVar13;
        }
      }
      return 0;
    }
  }
  return -0x7ff8fff2;
}


// ==== FUN_008b9281 @ 0x008b9281 ====

/* WARNING: Removing unreachable block (ram,0x008b94ea) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008b9281(uint param_1,uint param_2,uint param_3,undefined4 *param_4,undefined4 *param_5)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  byte bVar5;
  int iVar6;
  byte bVar7;
  short sVar8;
  int in_ECX;
  short sVar9;
  undefined4 *puVar10;
  short sVar11;
  short sVar12;
  uint uVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined2 in_FPUControlWord;
  float10 fVar16;
  int local_64;
  undefined4 *local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  int local_50;
  float *local_4c;
  int local_48;
  float *local_44;
  undefined4 *local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  float *local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  puVar4 = param_4;
  local_38 = 0;
  if ((uint)param_4[6] < (uint)(param_4[1] + param_4[3])) {
    iVar6 = FUN_008b8725(*(int *)(in_ECX + 0x498) + 1,0);
    if (iVar6 < 0) {
      return iVar6;
    }
    iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x5c))
                      (*(int **)(in_ECX + 8),param_4[5],param_4[5],param_4[4],0,
                       *(undefined4 *)(in_ECX + 0x494),1,
                       *(int *)(in_ECX + 0x49c) + *(int *)(in_ECX + 0x498) * 4,0);
    if (iVar6 < 0) {
      return iVar6;
    }
    param_4[1] = 0;
    *param_4 = *(undefined4 *)(*(int *)(in_ECX + 0x49c) + *(int *)(in_ECX + 0x498) * 4);
    *(int *)(in_ECX + 0x498) = *(int *)(in_ECX + 0x498) + 1;
    local_38 = 1;
  }
  uVar13 = 1;
  puVar1 = param_4 + 5;
  param_4 = (undefined4 *)0x0;
  local_8 = 0;
  bVar7 = 0;
  if (1 < *puVar1) {
    bVar5 = 0;
    do {
      if (((uint)puVar4[1] >> (bVar5 & 0x1f) & 1) != 0) {
        param_4 = (undefined4 *)((uint)param_4 | uVar13);
      }
      if (((uint)puVar4[1] >> (bVar5 + 1 & 0x1f) & 1) != 0) {
        local_8 = local_8 | uVar13;
      }
      bVar7 = bVar7 + 1;
      uVar13 = 1 << (bVar7 & 0x1f);
      bVar5 = bVar5 + 2;
    } while (uVar13 < (uint)puVar4[5]);
  }
  local_c = (int *)*puVar4;
  if (local_38 != 0) {
    local_24 = puVar4[5];
    local_18 = 0;
    if (puVar4[4] != 0) {
      do {
        (**(code **)(*local_c + 0x4c))(local_c,local_18,&local_64,0,0);
        puVar10 = (undefined4 *)(local_64 * local_24 + (int)local_60);
        if (local_60 < puVar10) {
          local_44 = (float *)(local_24 * 4);
          puVar14 = local_60;
          do {
            local_40 = (undefined4 *)(local_64 + (int)puVar14);
            if (puVar14 < (undefined4 *)((int)local_44 + (int)puVar14)) {
              iVar6 = ((uint)((int)local_44 + (int)puVar14 + (-1 - (int)puVar14)) >> 2) + 1;
              for (; iVar6 != 0; iVar6 = iVar6 + -1) {
                *puVar14 = 0xffffff;
                puVar14 = puVar14 + 1;
              }
            }
            puVar14 = local_40;
          } while (local_40 < puVar10);
        }
        (**(code **)(*local_c + 0x50))(local_c,local_18);
        local_24 = local_24 >> 1;
        local_18 = local_18 + 1;
      } while (local_18 < (uint)puVar4[4]);
    }
  }
  if (1 < (uint)puVar4[4]) {
    puVar10 = *(undefined4 **)(in_ECX + 0x4f8);
    for (iVar6 = (puVar4[3] & 0x1fffffff) << 1; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar10 = 0;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
  }
  local_18 = 0xffffffff;
  local_10 = 0xffffffff;
  local_20 = (puVar4[2] - param_3 >> 1) + local_8;
  uVar13 = (puVar4[2] - param_2 >> 1) + (int)param_4;
  local_14 = 0;
  local_1c = 0;
  local_24 = uVar13;
  (**(code **)(*local_c + 0x4c))(local_c,0,&local_5c,0,0);
  local_38 = 0;
  if (param_3 != 0) {
    local_30 = local_20 - local_8;
    do {
      local_40 = (undefined4 *)
                 (*(int *)(in_ECX + 0x4f8) +
                 (((local_30 + local_38) * puVar4[2] - (int)param_4) + uVar13) * 8);
      iVar6 = (local_38 + local_20) * local_5c + local_24 * 4 + local_58;
      local_28 = 0;
      uVar13 = local_38;
      if (param_2 != 0) {
        local_2c = (float *)(*(int *)(in_ECX + 0x2c) +
                             (*(int *)(in_ECX + 0x24) * local_38 + param_1) * 4 + 1);
        do {
          local_44 = (float *)(uint)*(byte *)local_2c;
          if (local_44 != (float *)0x0) {
            if (uVar13 < local_10) {
              local_10 = uVar13;
            }
            if (local_1c < uVar13) {
              local_1c = uVar13;
            }
            if (local_28 < local_18) {
              local_18 = local_28;
            }
            if (local_14 < local_28) {
              local_14 = local_28;
            }
            *(uint *)(iVar6 + local_28 * 4) = (int)local_44 << 0x18 | 0xffffff;
            if (1 < (uint)puVar4[4]) {
              fVar16 = (float10)FUN_008abcc4((float)(int)local_44 * DAT_0099d0b0);
              local_40[local_28 * 2] = (float)fVar16;
              uVar13 = local_38;
            }
          }
          local_2c = local_2c + 1;
          local_28 = local_28 + 1;
        } while (local_28 < param_2);
      }
      local_38 = uVar13 + 1;
      uVar13 = local_24;
    } while (local_38 < param_3);
  }
  (**(code **)(*local_c + 0x50))(local_c,0);
  if ((local_14 < local_18) || (local_1c < local_10)) {
    *param_5 = 0xffffffff;
  }
  else {
    if (1 < (uint)puVar4[4]) {
      param_2 = local_10;
      if (local_10 <= local_1c) {
        local_30 = local_20 - local_8;
        do {
          if (local_18 <= local_14) {
            puVar10 = (undefined4 *)
                      (*(int *)(in_ECX + 0x4f8) +
                       (((local_30 + param_2) * puVar4[2] - (int)param_4) + uVar13) * 8 + 4 +
                      local_18 * 8);
            iVar6 = (local_14 - local_18) + 1;
            do {
              *puVar10 = 0x3f800000;
              puVar10 = puVar10 + 2;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          param_2 = param_2 + 1;
        } while (param_2 <= local_1c);
      }
      param_2 = CONCAT22(param_2._2_2_,in_FPUControlWord);
      local_54 = param_2;
      param_2 = 1;
      if (1 < (uint)puVar4[4]) {
        do {
          bVar7 = (byte)param_2;
          local_38 = (uint)puVar4[2] >> (bVar7 & 0x1f);
          (**(code **)(*local_c + 0x4c))(local_c,param_2,&local_64,0,0);
          param_1 = 0;
          if (local_38 != 0) {
            local_28 = 1;
            local_48 = ((uint)param_4 >> (bVar7 & 0x1f)) << 2;
            local_34 = local_8 >> (bVar7 & 0x1f);
            do {
              puVar10 = local_60;
              local_3c = *(int *)(in_ECX + 0x4f8);
              iVar15 = puVar4[2] * param_1;
              param_3 = 0;
              iVar6 = iVar15 * 0x10 + local_3c;
              local_30 = local_3c + puVar4[2] * local_28 * 8;
              local_3c = local_3c + iVar15 * 8;
              iVar15 = local_34 * local_64 + local_48;
              local_2c = (float *)(local_30 + 4);
              local_44 = (float *)(iVar6 + 8);
              local_30 = local_30 - iVar6;
              do {
                local_4c = (float *)(local_3c + param_3 * 8);
                *local_4c = (*(float *)(local_30 + (int)local_44) + local_44[-2] + local_2c[-1] +
                            *local_44) * DAT_009fc7a0;
                local_40 = (undefined4 *)
                           ((local_44[-1] + local_44[1] + local_2c[2] + *local_2c) * DAT_009fc7a0);
                *(undefined4 **)(local_3c + 4 + param_3 * 8) = local_40;
                if ((float)local_40 != DAT_0099cdc8) {
                  fVar16 = (float10)FUN_008abc72(*local_4c / (float)local_40);
                  local_4c = (float *)(float)(fVar16 * (float10)DAT_0099d0b8 + (float10)DAT_0099d0b4
                                             );
                  local_50 = (int)ROUND((float)local_4c);
                  *(uint *)((int)puVar10 + param_3 * 4 + iVar15) = local_50 << 0x18 | 0xffffff;
                }
                param_3 = param_3 + 1;
                local_2c = local_2c + 4;
                local_44 = local_44 + 4;
              } while (param_3 < local_38);
              param_1 = param_1 + 1;
              local_28 = local_28 + 2;
              local_34 = local_34 + 1;
            } while (param_1 < local_38);
            uVar13 = local_24;
          }
          (**(code **)(*local_c + 0x50))(local_c,param_2);
          param_2 = param_2 + 1;
        } while (param_2 < (uint)puVar4[4]);
      }
    }
    *param_5 = *puVar4;
    uVar2 = local_14 + 1 + uVar13;
    sVar11 = (short)uVar2;
    *(short *)(param_5 + 2) = sVar11;
    uVar3 = local_1c + 1 + local_20;
    *(short *)(param_5 + 3) = (short)local_18;
    *(short *)((int)param_5 + 0xe) = (short)local_10;
    sVar8 = (short)(local_18 + uVar13);
    *(short *)(param_5 + 1) = sVar8;
    sVar9 = (short)(local_20 + local_10);
    *(short *)((int)param_5 + 6) = sVar9;
    sVar12 = (short)uVar3;
    *(short *)((int)param_5 + 10) = sVar12;
    if (param_4 < (local_18 + uVar13 & 0xffff)) {
      *(short *)(param_5 + 1) = sVar8 + -1;
      *(short *)(param_5 + 3) = (short)local_18 + -1;
    }
    if (local_8 < (local_20 + local_10 & 0xffff)) {
      *(short *)((int)param_5 + 6) = sVar9 + -1;
      *(short *)((int)param_5 + 0xe) = (short)local_10 + -1;
    }
    if ((uVar2 & 0xffff) < (uint)(puVar4[2] + (int)param_4)) {
      *(short *)(param_5 + 2) = sVar11 + 1;
    }
    if ((uVar3 & 0xffff) < puVar4[2] + local_8) {
      *(short *)((int)param_5 + 10) = sVar12 + 1;
    }
    puVar4[1] = puVar4[1] + puVar4[3];
  }
  return 0;
}


// ==== FUN_008b97ec @ 0x008b97ec ====

int FUN_008b97ec(uint param_1,uint param_2,uint param_3,uint param_4,int param_5,int *param_6,
                int *param_7)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  byte *pbVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int local_18;
  int local_14;
  uint *local_10;
  uint local_c;
  uint local_8;
  
  if (param_3 < param_4) {
    pbVar5 = (byte *)(*(int *)(in_ECX + 0x508) + -4 + param_4 * 0x10);
    do {
      if ((*pbVar5 & 3) == 0) break;
      param_4 = param_4 - 1;
      pbVar5 = pbVar5 + -0x10;
      param_2 = param_2 - 1;
    } while (param_3 < param_4);
  }
  local_8 = param_2;
  if (param_5 == 0) {
    local_8 = param_1;
  }
  uVar7 = param_3;
  while (uVar3 = uVar7, uVar3 < param_4) {
    iVar9 = *(int *)(in_ECX + 0x508);
    local_10 = (uint *)(uVar3 * 0x10 + 0xc + iVar9);
    uVar2 = *local_10;
    if (param_4 <= uVar3) break;
    local_c = uVar3;
    do {
      if ((~(*local_10 >> 3) & 1) != (uint)((uVar2 & 8) == 0)) break;
      local_c = local_c + 1;
      local_10 = local_10 + 4;
    } while (local_c < param_4);
    uVar7 = local_c;
    if (uVar3 != local_c) {
      uVar8 = *(uint *)(uVar3 * 0x10 + 8 + iVar9);
      local_18 = local_c * 0x10;
      local_10 = *(uint **)(local_18 + 8 + iVar9);
      if (uVar8 < param_1) {
        uVar8 = param_1;
      }
      if (param_2 < local_10) {
        local_10 = (uint *)param_2;
      }
      if (param_5 != 0) {
        local_8 = local_8 + (uVar8 - (int)local_10);
      }
      uVar7 = uVar8;
      if ((uVar2 & 8) == 0) {
        for (; uVar7 < local_10; uVar7 = uVar7 + 1) {
          *(uint *)(*(int *)(in_ECX + 0x528) + local_8 * 4) = uVar7;
          local_8 = local_8 + 1;
        }
      }
      else if (uVar3 < local_c) {
        local_14 = local_c - uVar3;
        do {
          local_18 = local_18 + -0x10;
          iVar9 = local_18 + *(int *)(in_ECX + 0x508);
          uVar7 = *(uint *)(iVar9 + 8);
          puVar6 = *(uint **)(iVar9 + 0x18);
          if (uVar7 < uVar8) {
            uVar7 = uVar8;
          }
          if (local_10 < puVar6) {
            puVar6 = local_10;
          }
          for (; uVar7 < puVar6; uVar7 = uVar7 + 1) {
            *(uint *)(*(int *)(in_ECX + 0x528) + local_8 * 4) = uVar7;
            local_8 = local_8 + 1;
          }
          local_14 = local_14 + -1;
        } while (local_14 != 0);
      }
      uVar7 = local_c;
      if (param_5 != 0) {
        local_8 = local_8 + (uVar8 - (int)local_10);
        uVar7 = local_c;
      }
    }
  }
  iVar9 = 0;
  if (param_5 == 0) {
    if (param_3 < param_4) {
      if ((*(byte *)(param_3 * 0x10 + 0xc + *(int *)(in_ECX + 0x508)) & 8) != 0) {
        uVar7 = param_1;
        while ((uVar7 < param_2 &&
               (iVar4 = *(int *)(*(int *)(in_ECX + 0x528) + uVar7 * 4),
               *(short *)(*(int *)(in_ECX + 0x548) + iVar4 * 2) == *(short *)(in_ECX + 0x78)))) {
          *(undefined4 *)(*(int *)(in_ECX + 0x558) + iVar4 * 4) = 0;
          uVar7 = uVar7 + 1;
        }
      }
      if ((*(byte *)(param_4 * 0x10 + -4 + *(int *)(in_ECX + 0x508)) & 8) == 0) {
        uVar7 = param_2;
        while (param_1 < uVar7) {
          uVar7 = uVar7 - 1;
          iVar4 = *(int *)(*(int *)(in_ECX + 0x528) + uVar7 * 4);
          if (*(short *)(*(int *)(in_ECX + 0x548) + iVar4 * 2) != *(short *)(in_ECX + 0x78)) break;
          *(undefined4 *)(*(int *)(in_ECX + 0x558) + iVar4 * 4) = 0;
        }
      }
    }
  }
  else if (param_3 < param_4) {
    if ((*(byte *)(param_3 * 0x10 + 0xc + *(int *)(in_ECX + 0x508)) & 8) == 0) {
      uVar7 = param_2;
      while (param_1 < uVar7) {
        uVar7 = uVar7 - 1;
        iVar4 = *(int *)(*(int *)(in_ECX + 0x528) + uVar7 * 4);
        if (*(short *)(*(int *)(in_ECX + 0x548) + iVar4 * 2) != *(short *)(in_ECX + 0x78)) break;
        *(undefined4 *)(*(int *)(in_ECX + 0x558) + iVar4 * 4) = 0;
      }
    }
    if ((*(byte *)(param_4 * 0x10 + -4 + *(int *)(in_ECX + 0x508)) & 8) != 0) {
      uVar7 = param_1;
      while ((uVar7 < param_2 &&
             (iVar4 = *(int *)(*(int *)(in_ECX + 0x528) + uVar7 * 4),
             *(short *)(*(int *)(in_ECX + 0x548) + iVar4 * 2) == *(short *)(in_ECX + 0x78)))) {
        *(undefined4 *)(*(int *)(in_ECX + 0x558) + iVar4 * 4) = 0;
        uVar7 = uVar7 + 1;
      }
    }
  }
  if (param_1 < param_2) {
    iVar4 = *(int *)(in_ECX + 0x528);
    uVar7 = param_1;
    do {
      *(int *)(*(int *)(in_ECX + 0x560) + *(int *)(iVar4 + uVar7 * 4) * 4) = iVar9;
      iVar4 = *(int *)(in_ECX + 0x528);
      iVar9 = iVar9 + *(int *)(*(int *)(in_ECX + 0x558) + *(int *)(iVar4 + uVar7 * 4) * 4);
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_2);
  }
  piVar1 = (int *)(in_ECX + 0x57c);
  iVar4 = FUN_008b88a2(*(int *)(in_ECX + 0x578) + 1,0);
  if (-1 < iVar4) {
    *(uint *)(*piVar1 + *(int *)(in_ECX + 0x578) * 0xc) = param_1;
    *(uint *)(*piVar1 + 4 + *(int *)(in_ECX + 0x578) * 0xc) = param_2;
    *(int *)(*piVar1 + 8 + *(int *)(in_ECX + 0x578) * 0xc) = iVar9;
    *(int *)(in_ECX + 0x578) = *(int *)(in_ECX + 0x578) + 1;
    if (*param_6 < iVar9) {
      *param_6 = iVar9;
    }
    *param_7 = *param_7 + *(int *)(in_ECX + 0x30);
    iVar4 = 0;
  }
  return iVar4;
}


// ==== FUN_008b9b12 @ 0x008b9b12 ====

void FUN_008b9b12(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_008b8685(1);
  }
  if (*(int *)(in_ECX + 8) != 0) {
    FUN_008b8685(1);
  }
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_008b9b47 @ 0x008b9b47 ====

void FUN_008b9b47(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a174e0;
  in_ECX[0x127] = 0;
  in_ECX[0x128] = 0;
  in_ECX[0x140] = 0;
  in_ECX[0x141] = 0;
  in_ECX[0x142] = 0;
  in_ECX[0x143] = 0;
  in_ECX[0x144] = 0;
  in_ECX[0x145] = 0;
  in_ECX[0x146] = 0;
  in_ECX[0x147] = 0;
  in_ECX[0x148] = 0;
  in_ECX[0x149] = 0;
  in_ECX[0x14a] = 0;
  in_ECX[0x14b] = 0;
  in_ECX[0x14c] = 0;
  in_ECX[0x14d] = 0;
  in_ECX[0x14e] = 0;
  in_ECX[0x14f] = 0;
  in_ECX[0x150] = 0;
  in_ECX[0x151] = 0;
  in_ECX[0x152] = 0;
  in_ECX[0x153] = 0;
  in_ECX[0x154] = 0;
  in_ECX[0x155] = 0;
  in_ECX[0x156] = 0;
  in_ECX[0x157] = 0;
  in_ECX[0x158] = 0;
  in_ECX[0x159] = 0;
  in_ECX[0x15a] = 0;
  in_ECX[0x15b] = 0;
  in_ECX[0x15c] = 0;
  in_ECX[0x15d] = 0;
  in_ECX[0x15f] = 0;
  in_ECX[0x160] = 0;
  in_ECX[1] = 1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x15e] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x126] = 0;
  in_ECX[0x13e] = 0;
  in_ECX[0x124] = 0;
  return;
}


// ==== FUN_008b9c4a @ 0x008b9c4a ====

undefined4 FUN_008b9c4a(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 4);
  if (*piVar1 == 0) {
    FUN_008a1577(1);
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008b9c67 @ 0x008b9c67 ====

int FUN_008b9c67(int param_1,int param_2,int param_3)

{
  WCHAR *pWVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  int local_30;
  int local_2c;
  tagPOINT local_24;
  uint local_1c;
  WCHAR local_18 [3];
  undefined2 local_12;
  int *local_10;
  int local_c;
  uint local_8;
  
  local_c = 0;
  if (0 < param_2) {
    do {
      pWVar1 = (WCHAR *)(param_1 + local_c * 2);
      local_1c = (uint)*(byte *)((int)pWVar1 + 1);
      local_10 = (int *)(in_ECX + 0x90 + local_1c * 4);
      if (*local_10 == 0) {
        puVar2 = operator_new(0x1000);
        *local_10 = (int)puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          return -0x7ff8fff2;
        }
        for (iVar3 = 0x400; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        if (*(uint *)(in_ECX + 0x8c) <= local_1c) {
          *(uint *)(in_ECX + 0x8c) = local_1c + 1;
        }
      }
      local_10 = (int *)((uint)(byte)*pWVar1 * 0x10 + *local_10);
      if (param_3 != 0) {
        *(int **)(param_3 + local_c * 4) = local_10;
      }
      if (*local_10 == 0) {
        if (DAT_00b5de80 == 0) {
          local_18[1] = 0;
          local_18[0] = *pWVar1;
          MoveToEx(*(HDC *)(in_ECX + 0x10),0,0,(LPPOINT)0x0);
          ExtTextOutA(*(HDC *)(in_ECX + 0x10),0,0,0x12,(RECT *)0x0,(LPCSTR)local_18,1,(INT *)0x0);
          MoveToEx(*(HDC *)(in_ECX + 0x10),0,0,&local_24);
          local_8 = local_24.x;
        }
        else {
          local_12 = 0;
          local_18[2] = *pWVar1;
          ExtTextOutW(*(HDC *)(in_ECX + 0x10),0,0,0x12,(RECT *)0x0,local_18 + 2,1,(INT *)0x0);
          if ((*(byte *)(in_ECX + 0x67) & 4) == 0) {
            (*DAT_00b5de90)(*(undefined4 *)(in_ECX + 0x10),*pWVar1,1,0,&local_8);
          }
          else {
            (*DAT_00b5de8c)(*(undefined4 *)(in_ECX + 0x10),*pWVar1,1,0,&local_30);
            local_8 = local_30 + local_2c;
          }
        }
        if (local_8 == 0) {
          *local_10 = -1;
        }
        else {
          iVar3 = in_ECX + 0x4a4;
          if (*(uint *)(in_ECX + 0x4ac) < local_8) {
            iVar3 = in_ECX + 0x4c0;
          }
          iVar3 = FUN_008b9281(0,local_8,*(undefined4 *)(in_ECX + 0x30),iVar3,local_10);
          if (iVar3 < 0) {
            return iVar3;
          }
        }
      }
      local_c = local_c + 1;
    } while (local_c < param_2);
  }
  return 0;
}


// ==== FUN_008b9df3 @ 0x008b9df3 ====

undefined4
FUN_008b9df3(ushort *param_1,int param_2,ushort *param_3,int *param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  ushort *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  HGDIOBJ pvVar4;
  int iVar5;
  undefined4 extraout_EAX;
  int in_ECX;
  ushort *puVar6;
  void *pvVar7;
  ushort *puVar8;
  bool bVar9;
  ushort *local_34;
  int local_30;
  ushort *local_2c;
  ushort *local_28;
  ushort *local_24;
  int local_20;
  void *local_1c;
  void *local_18;
  ushort *local_14;
  ushort *local_10;
  int local_c;
  ushort *local_8;
  
  local_28 = param_1 + param_2;
  local_14 = (ushort *)(in_ECX + 0x490);
  local_c = 0;
  local_18 = (void *)0x0;
  local_1c = (void *)0x0;
  puVar8 = param_1;
  if (param_1 < local_28) {
    while (local_2c = *(ushort **)local_14, local_2c != (ushort *)0x0) {
      if (*puVar8 == *local_2c) {
        puVar8 = puVar8 + 1;
        if (local_28 <= puVar8) goto LAB_008b9eac;
        local_14 = local_2c + 2;
      }
      else {
        if (*local_2c <= *puVar8) break;
        local_14 = local_2c + 4;
      }
    }
    if (puVar8 < local_28) {
      while( true ) {
        puVar6 = operator_new(0x18);
        if (puVar6 == (ushort *)0x0) {
          puVar6 = (ushort *)0x0;
        }
        else {
          puVar6[2] = 0;
          puVar6[3] = 0;
          puVar6[4] = 0;
          puVar6[5] = 0;
          puVar6[8] = 0;
          puVar6[9] = 0;
          puVar6[10] = 0;
          puVar6[0xb] = 0;
        }
        if (puVar6 == (ushort *)0x0) goto LAB_008ba09a;
        *puVar6 = *puVar8;
        uVar2 = *(undefined4 *)local_14;
        puVar6[6] = 0xffff;
        puVar6[7] = 0xffff;
        *(undefined4 *)(puVar6 + 4) = uVar2;
        puVar1 = puVar6 + 2;
        puVar8 = puVar8 + 1;
        puVar1[0] = 0;
        puVar1[1] = 0;
        *(ushort **)local_14 = puVar6;
        if (local_28 <= puVar8) break;
        local_14 = puVar1;
      }
    }
  }
LAB_008b9eac:
  if (*(int *)(*(int *)local_14 + 0xc) != -1) {
    *param_4 = *(int *)(*(int *)local_14 + 0xc);
    *param_5 = *(undefined4 *)(*(int *)local_14 + 0x10);
    *param_6 = *(undefined4 *)(*(int *)local_14 + 0x14);
    return 0;
  }
  if (DAT_00b5de80 == 0) {
    MoveToEx(*(HDC *)(in_ECX + 0x10),0,0,(LPPOINT)0x0);
    SetTextAlign(*(HDC *)(in_ECX + 0x10),0);
  }
  uVar2 = 0x10a0;
  if (param_3 != (ushort *)0x0) {
    uVar2 = 0x11a0;
  }
  local_20 = (*DAT_00b5dec8)(*(undefined4 *)(in_ECX + 0x10),param_1,param_2,(param_2 * 3) / 2 + 0x10
                             ,0xffffffff,uVar2,0,in_ECX + 0x88,in_ECX + 0x84,0,0,0,&local_c);
  if (local_20 < 0) goto LAB_008ba1de;
  puVar3 = (undefined4 *)(*DAT_00b5ded8)(local_c);
  local_34 = (ushort *)*puVar3;
  iVar5 = *(int *)(in_ECX + 0x28);
  local_30 = iVar5;
  if (*(int *)(in_ECX + 0x24) < (int)local_34) {
    pvVar4 = (HGDIOBJ)FUN_008b857f(&local_34,&param_1);
    if (pvVar4 != (HGDIOBJ)0x0) {
      *(ushort **)(in_ECX + 0x2c) = param_1;
      *(HGDIOBJ *)(in_ECX + 0x1c) = pvVar4;
      *(ushort **)(in_ECX + 0x24) = local_34;
      *(int *)(in_ECX + 0x28) = iVar5;
      pvVar4 = SelectObject(*(HDC *)(in_ECX + 0x10),pvVar4);
      DeleteObject(pvVar4);
      goto LAB_008b9f99;
    }
  }
  else {
LAB_008b9f99:
    if (*(int *)(in_ECX + 0x28) < iVar5) {
      local_30 = *(int *)(in_ECX + 0x28);
    }
    local_20 = (*DAT_00b5decc)(local_c,0,0,2,0,0,0,0);
    if (local_20 < 0) goto LAB_008ba1de;
    param_1 = (ushort *)0x0;
    (*DAT_00b5ded4)(local_c,0,0,&local_8);
    (*DAT_00b5ded4)(local_c,0,0,&local_10);
    param_3 = (ushort *)0x0;
    if (0 < param_2) {
      do {
        (*DAT_00b5ded4)(local_c,param_3,1,&local_2c);
        puVar8 = local_10;
        if (local_2c != local_10) {
          local_8 = local_10;
          bVar9 = (int)local_10 < 0;
          local_10 = local_2c;
          if (bVar9) {
            local_8 = (ushort *)0x0;
          }
          else if ((int)local_34 < (int)puVar8) {
            local_8 = local_34;
          }
          if ((int)local_2c < 0) {
            local_10 = (ushort *)0x0;
          }
          else if ((int)local_34 < (int)local_2c) {
            local_10 = local_34;
          }
          puVar8 = local_10;
          puVar6 = local_8;
          if ((int)local_10 <= (int)local_8) {
            puVar8 = local_8;
            puVar6 = local_10;
          }
          if ((int)puVar6 < (int)puVar8) {
            do {
              iVar5 = (int)puVar8 - (int)puVar6;
              if (*(int *)(in_ECX + 0x4e4) < (int)puVar8 - (int)puVar6) {
                iVar5 = *(int *)(in_ECX + 0x4e4);
              }
              puVar6 = (ushort *)((int)puVar6 + iVar5);
              param_1 = (ushort *)((int)param_1 + 1);
            } while ((int)puVar6 < (int)puVar8);
          }
        }
        param_3 = (ushort *)((int)param_3 + 1);
      } while ((int)param_3 < param_2);
    }
    puVar8 = param_1;
    local_18 = operator_new((int)param_1 << 4);
    if ((local_18 != (void *)0x0) &&
       (local_1c = operator_new((int)puVar8 << 2), local_1c != (void *)0x0)) {
      puVar8 = (ushort *)0x0;
      param_1 = (ushort *)0x0;
      (*DAT_00b5ded4)(local_c,0,0,&local_8);
      (*DAT_00b5ded4)(local_c,0,0,&local_10);
      local_28 = (ushort *)0x0;
      if (0 < param_2) {
        do {
          (*DAT_00b5ded4)(local_c,local_28,1,&local_2c);
          puVar6 = local_10;
          if (local_2c != local_10) {
            bVar9 = (int)local_10 < 0;
            local_8 = local_10;
            local_10 = local_2c;
            if (bVar9) {
              local_8 = (ushort *)0x0;
            }
            else if ((int)local_34 < (int)puVar6) {
              local_8 = local_34;
            }
            if ((int)local_2c < 0) {
              local_10 = (ushort *)0x0;
            }
            else if ((int)local_34 < (int)local_2c) {
              local_10 = local_34;
            }
            if ((int)local_8 < (int)local_10) {
              local_24 = local_10;
              param_3 = local_8;
            }
            else {
              param_3 = local_10;
              local_24 = local_8;
            }
            if ((int)param_3 < (int)local_24) {
              pvVar7 = (void *)((int)puVar8 * 0x10 + (int)local_18);
              do {
                iVar5 = (int)local_24 - (int)param_3;
                if (*(int *)(in_ECX + 0x4e4) < (int)local_24 - (int)param_3) {
                  iVar5 = *(int *)(in_ECX + 0x4e4);
                }
                *(int *)((int)local_1c + (int)param_1 * 4) = iVar5;
                local_20 = FUN_008b9281(param_3,iVar5,local_30,in_ECX + 0x4dc,pvVar7);
                if (local_20 < 0) goto LAB_008ba1de;
                param_3 = (ushort *)((int)param_3 + iVar5);
                puVar8 = (ushort *)((int)param_1 + 1);
                pvVar7 = (void *)((int)pvVar7 + 0x10);
                param_1 = puVar8;
              } while ((int)param_3 < (int)local_24);
            }
          }
          local_28 = (ushort *)((int)local_28 + 1);
        } while ((int)local_28 < param_2);
      }
      *param_4 = (int)puVar8;
      *(ushort **)(*(int *)local_14 + 0xc) = puVar8;
      *param_5 = local_18;
      *(void **)(*(int *)local_14 + 0x10) = local_18;
      *param_6 = local_1c;
      *(void **)(*(int *)local_14 + 0x14) = local_1c;
      local_18 = (void *)0x0;
      local_1c = (void *)0x0;
      local_20 = 0;
      goto LAB_008ba1de;
    }
  }
LAB_008ba09a:
  local_20 = -0x7ff8fff2;
LAB_008ba1de:
  if (local_c != 0) {
    (*DAT_00b5ded0)(&local_c);
  }
  if (DAT_00b5de80 == 0) {
    MoveToEx(*(HDC *)(in_ECX + 0x10),0,0,(LPPOINT)0x0);
    SetTextAlign(*(HDC *)(in_ECX + 0x10),1);
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_008ba228 @ 0x008ba228 ====

int FUN_008ba228(int *param_1,LPCWSTR param_2,uint param_3,int *param_4,uint param_5,
                undefined4 param_6,uint param_7,int *param_8)

{
  LPCWSTR pWVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  short *psVar8;
  byte *pbVar9;
  uint uVar10;
  uint *puVar11;
  WCHAR WVar12;
  int in_ECX;
  int iVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined2 *puVar17;
  tagGCP_RESULTSW *ptVar18;
  undefined4 *puVar19;
  tagGCP_RESULTSW local_ac;
  float local_88;
  float local_84;
  undefined4 local_80;
  int local_7c;
  int local_78;
  uint local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  int local_50;
  int local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_78 = 0;
  if (((param_2 == (LPCWSTR)0x0) && (param_3 != 0)) || ((param_5 & 0xfffdfa80) != 0)) {
    return -0x7789f794;
  }
  local_44 = param_5 & 0x20000;
  uVar15 = param_3;
  if (param_3 == 0xffffffff) {
    uVar15 = 0;
    if (param_7 == 0) {
      cVar2 = (char)*param_2;
      while (cVar2 != '\0') {
        uVar15 = uVar15 + 1;
        cVar2 = *(char *)((int)param_2 + uVar15);
      }
    }
    else {
      WVar12 = *param_2;
      while (WVar12 != L'\0') {
        uVar15 = uVar15 + 1;
        WVar12 = param_2[uVar15];
      }
    }
  }
  local_10 = 0;
  param_3 = 0;
  if (uVar15 != 0) {
    if (DAT_00b5de98 == 0) {
      if ((param_7 != 0) && (DAT_00b5de80 == 0)) {
        param_7 = WideCharToMultiByte(0,0,param_2,uVar15,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
        iVar6 = FUN_008b87a5(param_7,1);
        if (iVar6 < 0) {
          return iVar6;
        }
        WideCharToMultiByte(0,0,param_2,uVar15,*(LPSTR *)(in_ECX + 0x518),param_7,(LPCSTR)0x0,
                            (LPBOOL)0x0);
        uVar15 = param_7;
        param_2 = *(LPCWSTR *)(in_ECX + 0x518);
        param_7 = 0;
      }
      iVar6 = FUN_008b86a6(uVar15,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = FUN_008b8725(uVar15,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = FUN_008b87a5(uVar15,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = FUN_008b8725(uVar15,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      puVar16 = *(undefined4 **)(in_ECX + 0x530);
      for (uVar14 = uVar15 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
        *puVar16 = 0;
        puVar16 = puVar16 + 1;
      }
      for (uVar14 = uVar15 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
        *(undefined1 *)puVar16 = 0;
        puVar16 = (undefined4 *)((int)puVar16 + 1);
      }
      **(char **)(in_ECX + 0x530) = ((local_44 == 0) - 1U & 0xc0) + 0x80;
      ptVar18 = &local_ac;
      for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
        ptVar18->lStructSize = 0;
        ptVar18 = (tagGCP_RESULTSW *)&ptVar18->lpOutString;
      }
      local_ac.lpOrder = *(UINT **)(in_ECX + 0x528);
      local_ac.lpDx = *(int **)(in_ECX + 0x558);
      local_ac.lpClass = *(LPSTR *)(in_ECX + 0x530);
      local_ac.lpGlyphs = *(LPWSTR *)(in_ECX + 0x548);
      uVar14 = *(uint *)(in_ECX + 0x6c) & 0x13a | 0x80000;
      local_ac.lStructSize = 0x24;
      local_ac.nGlyphs = uVar15;
      if (param_7 == 0) {
        GetCharacterPlacementA
                  (*(HDC *)(in_ECX + 0x10),(LPCSTR)param_2,uVar15,0,(LPGCP_RESULTSA)&local_ac,uVar14
                  );
      }
      else {
        GetCharacterPlacementW(*(HDC *)(in_ECX + 0x10),param_2,uVar15,0,&local_ac,uVar14);
      }
      param_3 = local_ac.nGlyphs;
      iVar6 = FUN_008b8822(local_ac.nGlyphs,1);
      uVar15 = param_3;
      if (iVar6 < 0) {
        return iVar6;
      }
      puVar16 = *(undefined4 **)(in_ECX + 0x568);
      for (iVar6 = param_3 * 2; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar16 = 0;
        puVar16 = puVar16 + 1;
      }
      iVar6 = FUN_008b86a6(param_3,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = 0;
      if (0 < (int)uVar15) {
        do {
          iVar13 = *(int *)(*(int *)(in_ECX + 0x528) + iVar6 * 4);
          if (param_7 == 0) {
            WVar12 = (WCHAR)*(char *)(iVar13 + (int)param_2);
          }
          else {
            WVar12 = param_2[iVar13];
          }
          *(WCHAR *)(*(int *)(in_ECX + 0x520) + iVar6 * 2) = WVar12;
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)uVar15);
      }
      iVar6 = 0;
      local_c = 0;
      if (0 < (int)uVar15) {
        param_2 = (LPCWSTR)0x0;
        piVar7 = (int *)(in_ECX + 0x508);
        do {
          local_14 = local_10 + 1;
          iVar13 = FUN_008b8605(local_14,0);
          if (iVar13 < 0) {
            return iVar13;
          }
          *(undefined4 *)((int)param_2 + *piVar7) = 0;
          *(undefined4 *)((int)param_2 + 4 + *piVar7) =
               *(undefined4 *)(*(int *)(in_ECX + 0x528) + iVar6 * 4);
          *(int *)((int)param_2 + 8 + *piVar7) = iVar6;
          *(undefined4 *)((int)param_2 + 0xc + *piVar7) = 0;
          uVar3 = *(ushort *)(*(int *)(in_ECX + 0x520) + iVar6 * 2);
          param_7 = (uint)uVar3;
          if (uVar3 == 0x20) {
LAB_008bacda:
            iVar13 = iVar6 + 1;
            if (iVar13 < (int)param_3) {
              psVar8 = (short *)(*(int *)(in_ECX + 0x520) + 2 + iVar6 * 2);
              do {
                if (*psVar8 != 0x20) break;
                iVar6 = iVar6 + 1;
                psVar8 = psVar8 + 1;
                iVar13 = iVar13 + 1;
              } while (iVar13 < (int)param_3);
            }
          }
          else if (uVar3 == 0xd) {
            puVar11 = (uint *)((int)param_2 + 0xc + *piVar7);
            *puVar11 = *puVar11 | 1;
          }
          else if (uVar3 == 10) {
            puVar11 = (uint *)((int)param_2 + 0xc + *piVar7);
            *puVar11 = *puVar11 | 2;
          }
          else {
            if (uVar3 != 9) {
              if (*(char *)(iVar6 + *(int *)(in_ECX + 0x530)) == '\x02') {
                if ((int)(iVar6 + 1U) < (int)param_3) {
                  param_7 = iVar6 + 1U;
                  do {
                    if ((*(char *)(*(int *)(in_ECX + 0x530) + 1 + iVar6) != '\x02') ||
                       (iVar13 = _iswspace(*(wint_t *)(*(int *)(in_ECX + 0x520) + 2 + iVar6 * 2)),
                       iVar13 != 0)) break;
                    iVar6 = iVar6 + 1;
                    param_7 = param_7 + 1;
                  } while ((int)param_7 < (int)param_3);
                }
                puVar11 = (uint *)((int)param_2 + 0xc + *piVar7);
                *puVar11 = *puVar11 | 8;
                local_c = 1;
              }
              else {
                iVar13 = _iswalpha(uVar3);
                if (iVar13 == 0) {
                  iVar13 = _iswdigit((wint_t)param_7);
                  if (iVar13 == 0) {
                    iVar13 = _iswpunct((wint_t)param_7);
                    if (iVar13 == 0) goto LAB_008bad00;
                    if ((int)(iVar6 + 1U) < (int)param_3) {
                      param_7 = iVar6 + 1U;
                      do {
                        iVar13 = _iswpunct(*(wint_t *)(*(int *)(in_ECX + 0x520) + 2 + iVar6 * 2));
                        if (iVar13 == 0) break;
                        iVar6 = iVar6 + 1;
                        param_7 = param_7 + 1;
                      } while ((int)param_7 < (int)param_3);
                    }
                  }
                  else if ((int)(iVar6 + 1U) < (int)param_3) {
                    param_7 = iVar6 + 1U;
                    do {
                      iVar13 = _iswdigit(*(wint_t *)(*(int *)(in_ECX + 0x520) + 2 + iVar6 * 2));
                      if (iVar13 == 0) break;
                      iVar6 = iVar6 + 1;
                      param_7 = param_7 + 1;
                    } while ((int)param_7 < (int)param_3);
                  }
                }
                else if ((int)(iVar6 + 1U) < (int)param_3) {
                  local_8 = iVar6 + 1U;
                  do {
                    uVar3 = *(ushort *)(*(int *)(in_ECX + 0x520) + 2 + iVar6 * 2);
                    param_7 = (uint)uVar3;
                    iVar13 = _iswalpha(uVar3);
                    if (((iVar13 == 0) && (iVar13 = _iswdigit((wint_t)param_7), iVar13 == 0)) &&
                       ((short)param_7 != 0x5f)) break;
                    iVar6 = iVar6 + 1;
                    local_8 = local_8 + 1;
                  } while ((int)local_8 < (int)param_3);
                }
              }
              goto LAB_008bacda;
            }
            puVar11 = (uint *)((int)param_2 + 0xc + *piVar7);
            *puVar11 = *puVar11 | 4;
          }
LAB_008bad00:
          param_2 = (LPCWSTR)((int)param_2 + 0x10);
          iVar6 = iVar6 + 1;
          local_10 = local_14;
        } while (iVar6 < (int)param_3);
        uVar15 = param_3;
      }
      iVar6 = FUN_008b8605(local_10 + 1,0);
      uVar14 = local_10;
      if (iVar6 < 0) {
        return iVar6;
      }
      *(uint *)(local_10 * 0x10 + 8 + *(int *)(in_ECX + 0x508)) = uVar15;
      if ((local_c != 0) && (param_2 = (LPCWSTR)0x0, 0 < (int)local_10)) {
        do {
          if ((int)param_2 < (int)local_10) {
            pbVar9 = (byte *)((int)param_2 * 0x10 + 0xc + *(int *)(in_ECX + 0x508));
            do {
              if ((*pbVar9 & 8) != 0) break;
              param_2 = (LPCWSTR)((int)param_2 + 1);
              pbVar9 = pbVar9 + 0x10;
            } while ((int)param_2 < (int)local_10);
          }
          local_8 = (uint)param_2;
          if ((int)local_10 <= (int)param_2) break;
          iVar6 = *(int *)(in_ECX + 0x508);
          local_18 = (int)param_2 * 0x10;
          pbVar9 = (byte *)(local_18 + 0xc + iVar6);
          do {
            if ((*pbVar9 & 8) == 0) break;
            param_2 = (LPCWSTR)((int)param_2 + 1);
            pbVar9 = pbVar9 + 0x10;
          } while ((int)param_2 < (int)local_10);
          if ((int)local_8 < (int)param_2) {
            iVar13 = *(int *)(local_18 + 8 + iVar6);
            local_2c = *(uint *)((int)param_2 * 0x10 + 8 + iVar6);
            local_14 = (int)(local_2c - iVar13) / 2;
            local_24 = (int)param_2 - local_8;
            param_7 = local_18;
            local_8 = local_24;
            do {
              uVar15 = param_7 + 0x10;
              iVar6 = param_7 + *(int *)(in_ECX + 0x508);
              local_8 = local_8 + -1;
              *(uint *)(iVar6 + 8) = (local_2c - *(int *)(iVar6 + 0x18)) + iVar13;
              param_7 = uVar15;
            } while (local_8 != 0);
            local_8 = 0;
            if (0 < local_24 / 2) {
              local_20 = (int)param_2 * 0x10 - 0x10;
              param_7 = local_18;
              local_8 = local_24 / 2;
              do {
                iVar6 = *(int *)(in_ECX + 0x508);
                puVar11 = (uint *)(param_7 + iVar6);
                local_64 = *puVar11;
                local_60 = puVar11[1];
                local_5c = puVar11[2];
                local_58 = puVar11[3];
                puVar19 = (undefined4 *)(param_7 + iVar6);
                puVar16 = (undefined4 *)(local_20 + iVar6);
                *puVar19 = *puVar16;
                puVar19[1] = puVar16[1];
                param_7 = param_7 + 0x10;
                puVar19[2] = puVar16[2];
                puVar19[3] = puVar16[3];
                puVar11 = (uint *)(*(int *)(in_ECX + 0x508) + local_20);
                local_20 = local_20 - 0x10;
                local_8 = local_8 - 1;
                *puVar11 = local_64;
                puVar11[1] = local_60;
                puVar11[2] = local_5c;
                puVar11[3] = local_58;
              } while (local_8 != 0);
            }
            if (0 < (int)local_14) {
              local_8 = iVar13 * 2;
              local_c = local_2c * 4 + -4;
              iVar6 = local_2c * 2;
              param_7 = iVar13 << 2;
              local_20 = local_14;
              do {
                iVar6 = iVar6 + -2;
                iVar13 = *(int *)(in_ECX + 0x548);
                puVar17 = (undefined2 *)(local_8 + iVar13);
                uVar4 = *puVar17;
                *puVar17 = *(undefined2 *)(iVar6 + iVar13);
                *(undefined2 *)(iVar6 + *(int *)(in_ECX + 0x548)) = uVar4;
                uVar15 = param_7 + 4;
                iVar13 = *(int *)(in_ECX + 0x558);
                puVar11 = (uint *)(param_7 + iVar13);
                local_14 = *puVar11;
                *puVar11 = *(uint *)(local_c + iVar13);
                local_8 = local_8 + 2;
                *(uint *)(local_c + *(int *)(in_ECX + 0x558)) = local_14;
                local_c = local_c + -4;
                local_20 = local_20 - 1;
                param_7 = uVar15;
              } while (local_20 != 0);
            }
            do {
              iVar13 = local_18 + *(int *)(in_ECX + 0x508);
              iVar6 = *(int *)(iVar13 + 0x18);
              iVar13 = *(int *)(iVar13 + 8);
              uVar15 = (iVar6 - iVar13) / 2;
              if (0 < (int)uVar15) {
                local_c = iVar6 * 4 + -4;
                iVar6 = iVar6 * 2;
                param_7 = iVar13 * 2;
                local_20 = uVar15;
                local_8 = iVar13 << 2;
                do {
                  iVar6 = iVar6 + -2;
                  uVar15 = param_7 + 2;
                  iVar13 = *(int *)(in_ECX + 0x548);
                  puVar17 = (undefined2 *)(param_7 + iVar13);
                  uVar4 = *puVar17;
                  *puVar17 = *(undefined2 *)(iVar6 + iVar13);
                  *(undefined2 *)(iVar6 + *(int *)(in_ECX + 0x548)) = uVar4;
                  uVar10 = local_8 + 4;
                  iVar13 = *(int *)(in_ECX + 0x558);
                  puVar11 = (uint *)(local_8 + iVar13);
                  local_14 = *puVar11;
                  *puVar11 = *(uint *)(local_c + iVar13);
                  *(uint *)(local_c + *(int *)(in_ECX + 0x558)) = local_14;
                  local_c = local_c + -4;
                  local_20 = local_20 - 1;
                  param_7 = uVar15;
                  local_8 = uVar10;
                } while (local_20 != 0);
              }
              local_18 = local_18 + 0x10;
              local_24 = local_24 + -1;
            } while (local_24 != 0);
          }
        } while ((int)param_2 < (int)local_10);
      }
      piVar7 = (int *)(in_ECX + 0x510);
      iVar6 = FUN_008b88a2(local_10,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      if (0 < (int)uVar14) {
        iVar6 = 0;
        param_2 = (LPCWSTR)0x0;
        param_7 = uVar14;
        do {
          *(undefined4 *)(iVar6 + *piVar7) = 0;
          *(undefined4 *)(iVar6 + 4 + *piVar7) = 0;
          *(undefined4 *)(iVar6 + 8 + *piVar7) = 0;
          iVar13 = *(int *)(in_ECX + 0x508) + (int)param_2;
          local_14 = *(uint *)(iVar13 + 0x18);
          for (iVar13 = *(int *)(iVar13 + 8); iVar13 < (int)local_14; iVar13 = iVar13 + 1) {
            piVar5 = (int *)(iVar6 + 4 + *piVar7);
            *piVar5 = *piVar5 + *(int *)(*(int *)(in_ECX + 0x558) + iVar13 * 4);
          }
          param_2 = (LPCWSTR)((int)param_2 + 0x10);
          iVar6 = iVar6 + 0xc;
          param_7 = param_7 - 1;
        } while (param_7 != 0);
      }
      iVar6 = FUN_008b8725(param_3,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = FUN_008b9c67(*(undefined4 *)(in_ECX + 0x548),param_3,*(undefined4 *)(in_ECX + 0x550));
      if (iVar6 < 0) {
        return iVar6;
      }
    }
    else {
      if (param_7 == 0) {
        param_7 = MultiByteToWideChar(0,0,(LPCSTR)param_2,uVar15,(LPWSTR)0x0,0);
        iVar6 = FUN_008b86a6(param_7,1);
        if (iVar6 < 0) {
          return iVar6;
        }
        MultiByteToWideChar(0,0,(LPCSTR)param_2,uVar15,*(LPWSTR *)(in_ECX + 0x520),param_7);
        param_2 = *(LPCWSTR *)(in_ECX + 0x520);
        uVar15 = param_7;
      }
      *(undefined2 *)(in_ECX + 0x84) = 0;
      *(undefined4 *)(in_ECX + 0x88) = 0;
      iVar6 = (*DAT_00b5dec0)(&DAT_00b5dedc,(undefined4 *)(in_ECX + 0x88),
                              (undefined2 *)(in_ECX + 0x84));
      if (iVar6 < 0) {
        return iVar6;
      }
      if (local_44 != 0) {
        *(ushort *)(in_ECX + 0x84) = *(ushort *)(in_ECX + 0x84) & 0xffe1 | 1;
      }
      param_7 = (int)(uVar15 * 3) / 2 + 0x10;
      iVar6 = uVar15 + 1;
      while( true ) {
        iVar6 = FUN_008b8822(iVar6,1);
        if (iVar6 < 0) {
          return iVar6;
        }
        iVar6 = (*DAT_00b5de9c)(param_2,uVar15,*(undefined4 *)(in_ECX + 0x504),in_ECX + 0x88,
                                in_ECX + 0x84,*(undefined4 *)(in_ECX + 0x500),&local_20);
        if (-1 < iVar6) break;
        if (iVar6 != -0x7ff8fff2) {
          return iVar6;
        }
        iVar6 = *(int *)(in_ECX + 0x504) * 2;
      }
      iVar6 = FUN_008b87a5(uVar15,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      local_18 = 0;
      if (0 < (int)local_20) {
        do {
          iVar6 = *(int *)(in_ECX + 0x500);
          iVar13 = local_18 * 8;
          local_8 = *(uint *)(iVar13 + 8 + iVar6);
          local_14 = *(uint *)(iVar13 + iVar6);
          iVar6 = (*DAT_00b5dea8)(param_2 + local_14,local_8 - local_14,iVar6 + 4 + iVar13,
                                  *(int *)(in_ECX + 0x538) + local_14);
          uVar14 = local_14;
          if (iVar6 < 0) {
            return iVar6;
          }
          for (; (int)uVar14 < (int)local_8; uVar14 = uVar14 + 1) {
            if ((uVar14 == local_14) || ((*(byte *)(uVar14 + *(int *)(in_ECX + 0x538)) & 8) != 0)) {
              local_10 = local_10 + 1;
            }
          }
          local_18 = local_18 + 1;
        } while ((int)local_18 < (int)local_20);
      }
      iVar6 = FUN_008b8605(local_10 + 1,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      local_10 = 0;
      local_c = 0;
      if (0 < (int)local_20) {
        do {
          puVar11 = (uint *)(*(int *)(in_ECX + 0x500) + local_c * 8);
          local_14 = *puVar11;
          local_2c = puVar11[2];
          local_8 = local_14;
          if ((int)local_14 < (int)local_2c) {
            iVar6 = local_10 << 4;
            do {
              if ((local_8 == local_14) ||
                 ((*(byte *)(local_8 + *(int *)(in_ECX + 0x538)) & 8) != 0)) {
                piVar7 = (int *)(in_ECX + 0x508);
                *(int *)(iVar6 + *piVar7) = local_c;
                *(uint *)(iVar6 + 4 + *piVar7) = local_8;
                *(undefined4 *)(iVar6 + 0xc + *piVar7) = 0;
                pWVar1 = param_2 + local_8;
                if (*pWVar1 == L'\r') {
                  puVar11 = (uint *)(iVar6 + 0xc + *piVar7);
                  *puVar11 = *puVar11 | 1;
                }
                if (*pWVar1 == L'\n') {
                  puVar11 = (uint *)(iVar6 + 0xc + *piVar7);
                  *puVar11 = *puVar11 | 2;
                }
                if (*pWVar1 == L'\t') {
                  puVar11 = (uint *)(iVar6 + 0xc + *piVar7);
                  *puVar11 = *puVar11 | 4;
                }
                if ((*(byte *)(*(int *)(in_ECX + 0x500) + 5 + local_c * 8) & 8) != 0) {
                  puVar11 = (uint *)(iVar6 + 0xc + *piVar7);
                  *puVar11 = *puVar11 | 8;
                }
                local_10 = local_10 + 1;
                iVar6 = iVar6 + 0x10;
              }
              local_8 = local_8 + 1;
            } while ((int)local_8 < (int)local_2c);
          }
          local_c = local_c + 1;
        } while (local_c < (int)local_20);
      }
      local_4c = local_10 * 0x10;
      *(uint *)(local_4c + 4 + *(int *)(in_ECX + 0x508)) = uVar15;
      iVar6 = FUN_008b87a5(uVar15,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = FUN_008b86a6(uVar15,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = FUN_008b88a2(local_10,1);
      if (iVar6 < 0) {
        return iVar6;
      }
      local_40 = 0;
      uVar15 = param_3;
      if (0 < (int)local_10) {
        local_18 = 0;
        local_24 = 0;
        do {
          piVar7 = (int *)(*(int *)(in_ECX + 0x508) + local_24);
          local_8 = piVar7[1];
          local_c = *piVar7;
          local_30 = piVar7[5];
          piVar7[2] = uVar15;
          local_1c = (uint)(local_c == 0);
          while( true ) {
            iVar6 = FUN_008b86a6(param_7,local_1c);
            if (iVar6 < 0) {
              return iVar6;
            }
            iVar6 = FUN_008b86a6(param_7,local_1c);
            if (iVar6 < 0) {
              return iVar6;
            }
            local_14 = *(uint *)(in_ECX + 0x500);
            iVar6 = (*DAT_00b5dea0)(*(undefined4 *)(in_ECX + 0x10),in_ECX + 0x70,param_2 + local_8,
                                    local_30 - local_8,*(int *)(in_ECX + 0x54c) - uVar15,
                                    local_14 + 4 + local_c * 8,*(int *)(in_ECX + 0x548) + uVar15 * 2
                                    ,*(int *)(in_ECX + 0x540) + local_8 * 2,
                                    *(int *)(in_ECX + 0x570) + uVar15 * 2,&local_48);
            if (iVar6 != -0x7ff8fff2) break;
            param_7 = *(int *)(in_ECX + 0x54c) << 1;
          }
          iVar13 = 0;
          if (iVar6 < 0) {
LAB_008ba79c:
            param_3 = 0;
            local_28 = 0;
            local_34 = 0;
            local_c = 0;
            iVar6 = FUN_008b9df3(param_2 + local_8,local_30 - local_8,local_44,&param_3,&local_28,
                                 &local_34);
            if (iVar6 < 0) {
              return iVar6;
            }
            local_14 = param_3 + uVar15;
            if ((int)param_7 < (int)local_14) {
              param_7 = local_14;
            }
            iVar6 = FUN_008b86a6(param_7,local_1c);
            if (iVar6 < 0) {
              return iVar6;
            }
            iVar6 = FUN_008b8725(param_7,local_1c);
            if (iVar6 < 0) {
              return iVar6;
            }
            iVar6 = FUN_008b8822(param_7,local_1c);
            if (iVar6 < 0) {
              return iVar6;
            }
            iVar6 = FUN_008b8725(param_7,local_1c);
            if (iVar6 < 0) {
              return iVar6;
            }
            local_30 = 0;
            if (param_3 != 0) {
              iVar6 = uVar15 << 3;
              iVar13 = uVar15 << 2;
              local_8 = local_28;
              local_28 = uVar15 * 2;
              do {
                *(undefined2 *)(local_28 + *(int *)(in_ECX + 0x548)) = 0xffff;
                *(uint *)(iVar13 + *(int *)(in_ECX + 0x550)) = local_8;
                local_8 = local_8 + 0x10;
                piVar7 = (int *)(local_34 + local_30 * 4);
                *(int *)(iVar13 + *(int *)(in_ECX + 0x558)) = *piVar7;
                *(undefined4 *)(iVar6 + *(int *)(in_ECX + 0x568)) = 0;
                *(undefined4 *)(*(int *)(in_ECX + 0x568) + 4 + iVar6) = 0;
                local_c = local_c + *piVar7;
                local_30 = local_30 + 1;
                local_28 = local_28 + 2;
                iVar6 = iVar6 + 8;
                iVar13 = iVar13 + 4;
              } while (local_30 < param_3);
            }
            piVar7 = (int *)(in_ECX + 0x510);
            *(undefined4 *)(local_18 + *piVar7) = 0;
            *(int *)(*piVar7 + 4 + local_18) = local_c;
            *(undefined4 *)(*piVar7 + 8 + local_18) = 0;
            uVar15 = local_14;
LAB_008ba8f6:
            param_3 = uVar15;
          }
          else {
            if (0 < local_48) {
              psVar8 = (short *)(*(int *)(in_ECX + 0x548) + uVar15 * 2);
              do {
                if (*psVar8 == *(short *)(in_ECX + 0x7a)) break;
                iVar13 = iVar13 + 1;
                psVar8 = psVar8 + 1;
              } while (iVar13 < local_48);
            }
            if (iVar13 < local_48) goto LAB_008ba79c;
            iVar6 = FUN_008b8725(param_7,local_1c);
            if (iVar6 < 0) {
              return iVar6;
            }
            iVar6 = FUN_008b8822(param_7,local_1c);
            if (iVar6 < 0) {
              return iVar6;
            }
            iVar6 = FUN_008b8725(param_7,local_1c);
            if (iVar6 < 0) {
              return iVar6;
            }
            local_14 = *(uint *)(in_ECX + 0x500);
            local_2c = *(uint *)(in_ECX + 0x548);
            iVar6 = (*DAT_00b5dea4)(*(undefined4 *)(in_ECX + 0x10),in_ECX + 0x70,
                                    local_2c + uVar15 * 2,local_48,
                                    *(int *)(in_ECX + 0x570) + uVar15 * 2,local_14 + 4 + local_c * 8
                                    ,*(int *)(in_ECX + 0x558) + uVar15 * 4,
                                    *(int *)(in_ECX + 0x568) + uVar15 * 8,
                                    local_18 + *(int *)(in_ECX + 0x510));
            if (-1 < iVar6) {
              iVar6 = FUN_008b9c67(*(int *)(in_ECX + 0x548) + uVar15 * 2,local_48,
                                   *(int *)(in_ECX + 0x550) + uVar15 * 4);
              if (iVar6 < 0) {
                return iVar6;
              }
              uVar15 = uVar15 + local_48;
              goto LAB_008ba8f6;
            }
          }
          local_40 = local_40 + 1;
          local_24 = local_24 + 0x10;
          local_18 = local_18 + 0xc;
        } while ((int)local_40 < (int)local_10);
      }
      *(uint *)(local_4c + 8 + *(int *)(in_ECX + 0x508)) = uVar15;
    }
  }
  if (param_8 == (int *)0x0) {
    return 0;
  }
  iVar6 = FUN_008b8725(param_3,1);
  if (iVar6 < 0) {
    return iVar6;
  }
  iVar6 = FUN_008b8725(param_3,1);
  if (iVar6 < 0) {
    return iVar6;
  }
  local_74 = param_5 >> 5 & 1;
  local_1c = 0;
  local_3c = 0;
  *(undefined4 *)(in_ECX + 0x578) = 0;
  local_18 = 0x7fffffff;
  local_14 = 0x7fffffff;
  local_24 = 0;
  if ((param_5 & 0x10) != 0) {
    if (param_4 == (int *)0x0) goto LAB_008bb0e8;
    if ((*param_4 < param_4[2]) && (local_74 == 0)) {
      local_18 = param_4[2] - *param_4;
      local_24 = 1;
    }
  }
  if ((param_4 != (int *)0x0) && ((param_5 & 0x52c) == 0)) {
    local_14 = param_4[3] - param_4[1];
  }
LAB_008bb0e8:
  local_28 = 0;
  local_34 = 0;
  param_2 = (LPCWSTR)0x0;
  param_7 = 0;
  if (0 < (int)local_10) {
    do {
      local_7c = param_7 * 0x10;
      iVar6 = *(int *)(in_ECX + 0x508) + local_7c;
      local_40 = *(uint *)(iVar6 + 0x18);
      uVar15 = *(uint *)(iVar6 + 8);
      if (((*(byte *)(iVar6 + 0xc) & 1) != 0) && (local_74 == 0)) {
        *(undefined4 *)(*(int *)(in_ECX + 0x558) + uVar15 * 4) = 0;
        *(undefined2 *)(*(int *)(in_ECX + 0x548) + uVar15 * 2) = *(undefined2 *)(in_ECX + 0x78);
      }
      uVar14 = *(uint *)(local_7c + 0xc + *(int *)(in_ECX + 0x508));
      if (((uVar14 & 2) == 0) || (local_74 != 0)) {
        if (((uVar14 & 4) == 0) || ((param_5 & 0x40) == 0)) {
          if ((local_24 != 0) && (0 < (int)param_2)) {
            piVar7 = (int *)(*(int *)(in_ECX + 0x510) + param_7 * 0xc);
            if ((int)local_18 < piVar7[2] + piVar7[1] + (int)param_2 + *piVar7) {
              iVar6 = FUN_008b97ec(local_28,uVar15,local_34,param_7,local_44,&local_1c,&local_3c);
              if (iVar6 < 0) {
                return iVar6;
              }
              param_2 = (LPCWSTR)0x0;
              local_34 = param_7;
              local_28 = uVar15;
            }
          }
          local_30 = uVar15;
          if ((int)uVar15 < (int)local_40) {
            local_2c = local_40 - uVar15;
            iVar6 = local_7c;
            do {
              local_38 = *(uint *)(iVar6 + 0xc + *(int *)(in_ECX + 0x508)) & 8;
              if (local_38 == 0) {
                local_4c = *(int *)(*(int *)(in_ECX + 0x558) + local_30 * 4);
              }
              else {
                local_4c = *(int *)(*(int *)(in_ECX + 0x558) + -4 + (uVar15 + local_2c) * 4);
              }
              if ((local_24 != 0) && ((int)local_18 < (int)param_2 + local_4c)) {
                if (local_38 != 0) {
                  uVar10 = local_30 - uVar15;
                  uVar14 = uVar10 + param_3;
                  local_38 = uVar14;
                  iVar6 = FUN_008b8725(uVar14,1);
                  if (iVar6 < 0) {
                    return iVar6;
                  }
                  iVar6 = FUN_008b8725(uVar14,1);
                  if (iVar6 < 0) {
                    return iVar6;
                  }
                  iVar6 = FUN_008b8822(local_38,1);
                  if (iVar6 < 0) {
                    return iVar6;
                  }
                  if (0 < (int)uVar10) {
                    local_50 = param_3 << 3;
                    local_54 = param_3 << 2;
                    local_8 = (local_40 - uVar10) * 8;
                    local_c = (local_40 - uVar10) * 4;
                    local_38 = uVar10;
                    do {
                      *(undefined4 *)(local_54 + *(int *)(in_ECX + 0x550)) =
                           *(undefined4 *)(local_c + *(int *)(in_ECX + 0x550));
                      puVar16 = (undefined4 *)(local_c + *(int *)(in_ECX + 0x558));
                      local_c = local_c + 4;
                      *(undefined4 *)(local_54 + *(int *)(in_ECX + 0x558)) = *puVar16;
                      iVar13 = *(int *)(in_ECX + 0x568);
                      *(undefined4 *)(local_50 + iVar13) = *(undefined4 *)(local_8 + iVar13);
                      iVar6 = local_8 + 4;
                      local_8 = local_8 + 8;
                      *(undefined4 *)(local_50 + 4 + iVar13) = *(undefined4 *)(iVar6 + iVar13);
                      local_54 = local_54 + 4;
                      local_50 = local_50 + 8;
                      local_38 = local_38 - 1;
                    } while (local_38 != 0);
                  }
                  if ((int)local_30 < (int)local_40) {
                    local_8 = (local_40 - uVar10) * 8;
                    local_38 = (local_40 - uVar10) * 4;
                    uVar14 = local_40;
                    do {
                      local_8 = local_8 - 8;
                      local_38 = local_38 - 4;
                      uVar14 = uVar14 - 1;
                      *(undefined4 *)(*(int *)(in_ECX + 0x550) + uVar14 * 4) =
                           *(undefined4 *)(*(int *)(in_ECX + 0x550) + local_38);
                      *(undefined4 *)(*(int *)(in_ECX + 0x558) + uVar14 * 4) =
                           *(undefined4 *)(*(int *)(in_ECX + 0x558) + local_38);
                      iVar6 = *(int *)(in_ECX + 0x568);
                      *(undefined4 *)(iVar6 + uVar14 * 8) = *(undefined4 *)(iVar6 + local_8);
                      *(undefined4 *)(iVar6 + 4 + uVar14 * 8) = *(undefined4 *)(iVar6 + 4 + local_8)
                      ;
                    } while ((int)local_30 < (int)uVar14);
                  }
                  if (0 < (int)uVar10) {
                    local_50 = uVar15 << 3;
                    param_2 = (LPCWSTR)(param_3 << 3);
                    local_38 = uVar15 << 2;
                    iVar6 = param_3 << 2;
                    local_54 = uVar10;
                    do {
                      *(undefined4 *)(*(int *)(in_ECX + 0x550) + local_38) =
                           *(undefined4 *)(*(int *)(in_ECX + 0x550) + iVar6);
                      *(undefined4 *)(*(int *)(in_ECX + 0x558) + local_38) =
                           *(undefined4 *)(*(int *)(in_ECX + 0x558) + iVar6);
                      iVar13 = *(int *)(in_ECX + 0x568);
                      *(undefined4 *)(iVar13 + local_50) = *(undefined4 *)(iVar13 + (int)param_2);
                      puVar16 = (undefined4 *)(iVar13 + 4 + (int)param_2);
                      param_2 = (LPCWSTR)((int)param_2 + 8);
                      *(undefined4 *)(iVar13 + 4 + local_50) = *puVar16;
                      local_38 = local_38 + 4;
                      local_50 = local_50 + 8;
                      iVar6 = iVar6 + 4;
                      local_54 = local_54 - 1;
                    } while (local_54 != 0);
                  }
                  uVar15 = local_30;
                }
                iVar6 = FUN_008b97ec(local_28,local_30,local_34,param_7 + 1,local_44,&local_1c,
                                     &local_3c);
                if (iVar6 < 0) {
                  return iVar6;
                }
                param_2 = (LPCWSTR)0x0;
                local_28 = local_30;
                local_34 = param_7;
                iVar6 = local_7c;
              }
              param_2 = (LPCWSTR)((int)param_2 + local_4c);
              local_30 = local_30 + 1;
              local_2c = local_2c - 1;
            } while ((int)local_30 < (int)local_40);
          }
        }
        else {
          if ((local_24 != 0) && ((int)local_18 <= (int)param_2)) {
            iVar6 = FUN_008b97ec(local_28,uVar15,local_34,param_7,local_44,&local_1c,&local_3c);
            if (iVar6 < 0) {
              return iVar6;
            }
            param_2 = (LPCWSTR)0x0;
            local_34 = param_7;
            local_28 = uVar15;
          }
          iVar6 = *(int *)(in_ECX + 0x44) * 8;
          local_8 = iVar6 - (int)param_2 % iVar6;
          if ((local_24 != 0) && ((int)local_18 < (int)(local_8 + (int)param_2))) {
            local_8 = local_18 - (int)param_2;
          }
          *(uint *)(uVar15 * 4 + *(int *)(in_ECX + 0x558)) = local_8;
          *(undefined2 *)(uVar15 * 2 + *(int *)(in_ECX + 0x548)) = *(undefined2 *)(in_ECX + 0x78);
          iVar6 = FUN_008b9c67(uVar15 * 2 + *(int *)(in_ECX + 0x548),1,
                               uVar15 * 4 + *(int *)(in_ECX + 0x550));
          if (iVar6 < 0) {
            return iVar6;
          }
          param_2 = (LPCWSTR)((int)param_2 + local_8);
        }
      }
      else {
        *(undefined4 *)(*(int *)(in_ECX + 0x558) + uVar15 * 4) = 0;
        *(undefined2 *)(*(int *)(in_ECX + 0x548) + uVar15 * 2) = *(undefined2 *)(in_ECX + 0x78);
        iVar13 = param_7 + 1;
        iVar6 = FUN_008b97ec(local_28,local_40,local_34,iVar13,local_44,&local_1c,&local_3c);
        if (iVar6 < 0) {
          return iVar6;
        }
        param_2 = (LPCWSTR)0x0;
        local_28 = local_40;
        local_34 = iVar13;
      }
    } while ((local_3c <= (int)local_14) && (param_7 = param_7 + 1, (int)param_7 < (int)local_10));
    if ((0 < (int)param_2) &&
       (iVar6 = FUN_008b97ec(local_28,param_3,local_34,local_10,local_44,&local_1c,&local_3c),
       iVar6 < 0)) {
      return iVar6;
    }
  }
  piVar7 = param_4;
  if (param_4 == (int *)0x0) {
    param_2 = (LPCWSTR)0x0;
    param_7 = 0;
    iVar6 = local_3c;
  }
  else {
    if (local_44 != 0) {
      param_5 = param_5 ^ 2;
    }
    if ((param_5 & 1) == 0) {
      if ((param_5 & 2) == 0) {
        param_7 = *param_4;
      }
      else {
        param_7 = param_4[2] - local_1c;
      }
    }
    else {
      param_7 = (int)((param_4[2] - local_1c) + *param_4) / 2;
    }
    if ((param_5 & 4) == 0) {
      if ((param_5 & 8) == 0) {
        param_2 = (LPCWSTR)param_4[1];
      }
      else {
        param_2 = (LPCWSTR)(param_4[3] - local_3c);
      }
    }
    else {
      param_2 = (LPCWSTR)(((param_4[3] + param_4[1]) - local_3c) / 2);
    }
    iVar6 = ((int)param_2 - param_4[1]) + local_3c;
  }
  *param_8 = iVar6;
  if ((param_5 & 0x400) != 0) {
    if (param_4 != (int *)0x0) {
      *param_4 = param_7;
      param_4[1] = (int)param_2;
      param_4[2] = param_7 + local_1c;
      param_4[3] = (int)param_2 + local_3c;
    }
    return 0;
  }
  if (param_1 == (int *)0x0) {
    if ((*(int *)(in_ECX + 0xc) == 0) &&
       (iVar6 = FUN_008a15f7(*(undefined4 *)(in_ECX + 8),in_ECX + 0xc), iVar6 < 0)) {
      return iVar6;
    }
    param_1 = *(int **)(in_ECX + 0xc);
    iVar6 = (**(code **)(*param_1 + 0x20))(param_1,0x30);
    if (iVar6 < 0) {
      return iVar6;
    }
    local_78 = 1;
  }
  local_80 = 0;
  local_68 = 0;
  if ((param_5 & 0x100) != 0) {
    piVar7 = (int *)0x0;
    param_4 = (int *)0x0;
  }
  local_8 = 0;
  if (((piVar7 != (int *)0x0) && (iVar6 = *(int *)(in_ECX + 0x30), iVar6 != 0)) &&
     ((int)param_2 < piVar7[1])) {
    local_8 = (piVar7[1] - (int)param_2) / iVar6;
    param_2 = (LPCWSTR)((int)param_2 + local_8 * iVar6);
  }
  local_c = param_7;
  if (local_8 < *(uint *)(in_ECX + 0x578)) {
    param_3 = local_8 * 0xc;
    while ((piVar7 == (int *)0x0 || ((int)param_2 < piVar7[3]))) {
      if ((param_5 & 1) == 0) {
        param_7 = local_c;
        if ((param_5 & 2) != 0) {
          param_7 = (local_c - *(int *)(*(int *)(in_ECX + 0x57c) + 8 + param_3)) + local_1c;
        }
      }
      else {
        param_7 = (int)(local_1c - *(int *)(*(int *)(in_ECX + 0x57c) + 8 + param_3)) / 2 + local_c;
      }
      puVar11 = (uint *)(*(int *)(in_ECX + 0x57c) + param_3);
      param_8 = (int *)*puVar11;
      if (param_8 < (int *)puVar11[1]) {
        do {
          piVar5 = *(int **)((int)param_8 * 4 + *(int *)(in_ECX + 0x550));
          if (*piVar5 != -1) {
            piVar7 = (int *)(*(int *)(in_ECX + 0x568) + (int)param_8 * 8);
            local_64 = (uint)*(ushort *)(piVar5 + 1);
            local_58 = (uint)*(ushort *)((int)piVar5 + 10);
            uVar15 = (int)(short)piVar5[3] + *(int *)(*(int *)(in_ECX + 0x560) + (int)param_8 * 4) +
                     *piVar7 + param_7;
            local_60 = (uint)*(ushort *)((int)piVar5 + 6);
            local_5c = (uint)*(ushort *)(piVar5 + 2);
            local_4c = (int)*(short *)((int)piVar5 + 0xe) + piVar7[1] + (int)param_2;
            local_20 = local_5c - local_64;
            local_14 = local_58 - local_60;
            local_70 = (float)(int)local_20 * DAT_0099d0b4;
            local_6c = (float)(int)local_14 * DAT_0099d0b4;
            local_88 = (float)(int)uVar15 + local_70;
            local_84 = (float)local_4c + local_6c;
            local_2c = uVar15;
            if (param_4 != (int *)0x0) {
              if ((int)uVar15 < *param_4) {
                local_2c = *param_4 - uVar15;
                local_64 = local_64 + local_2c;
                local_70 = local_70 - (float)(int)local_2c;
              }
              if (param_4[2] < (int)(local_20 + uVar15)) {
                local_5c = local_5c + ((param_4[2] - local_20) - uVar15);
              }
              if (local_4c < param_4[1]) {
                local_2c = param_4[1] - local_4c;
                local_60 = local_60 + local_2c;
                local_6c = local_6c - (float)(int)local_2c;
              }
              if (param_4[3] < (int)(local_14 + local_4c)) {
                local_58 = local_58 + ((param_4[3] - local_14) - local_4c);
              }
            }
            piVar7 = param_4;
            if ((((int)local_64 < (int)local_5c) && ((int)local_60 < (int)local_58)) &&
               (iVar6 = (**(code **)(*param_1 + 0x24))
                                  (param_1,*piVar5,&local_64,&local_70,&local_88,param_6), iVar6 < 0
               )) goto LAB_008bb898;
          }
          param_8 = (int *)((int)param_8 + 1);
        } while (param_8 < *(int **)(param_3 + 4 + *(int *)(in_ECX + 0x57c)));
      }
      param_2 = (LPCWSTR)((int)param_2 + *(int *)(in_ECX + 0x30));
      local_8 = local_8 + 1;
      param_3 = param_3 + 0xc;
      if (*(uint *)(in_ECX + 0x578) <= local_8) break;
    }
  }
  iVar6 = 0;
LAB_008bb898:
  if (local_78 != 0) {
    (**(code **)(*param_1 + 0x2c))(param_1);
  }
  return iVar6;
}


// ==== FUN_008bb8b0 @ 0x008bb8b0 ====

uint FUN_008bb8b0(int param_1,ushort param_2,int *param_3,uint *param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *local_8;
  
  _param_2 = (uint)param_2;
  local_8 = (int *)0x0;
  iVar2 = FUN_008b854b(_param_2);
  if (iVar2 == 0) {
    _param_2 = (uint)*(ushort *)(param_1 + 0x7a);
  }
  uVar3 = FUN_008b9c67(&param_2,1,&local_8);
  piVar1 = local_8;
  if (-1 < (int)uVar3) {
    if ((local_8 == (int *)0x0) || (*local_8 == -1)) {
      if (param_3 != (int *)0x0) {
        *param_3 = 0;
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = 0;
        param_4[1] = 0;
        param_4[2] = 0;
        param_4[3] = 0;
      }
      if (param_5 != (int *)0x0) {
        *param_5 = 0;
        param_5[1] = 0;
      }
    }
    else {
      if (param_3 != (int *)0x0) {
        *param_3 = *local_8;
        (**(code **)(*(int *)*local_8 + 4))((int *)*local_8);
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = (uint)*(ushort *)(piVar1 + 1);
        param_4[1] = (uint)*(ushort *)((int)piVar1 + 6);
        param_4[2] = (uint)*(ushort *)(piVar1 + 2);
        param_4[3] = (uint)*(ushort *)((int)piVar1 + 10);
      }
      if (param_5 != (int *)0x0) {
        *param_5 = (int)(short)piVar1[3];
        param_5[1] = (int)*(short *)((int)piVar1 + 0xe);
      }
    }
    uVar3 = (uint)(iVar2 == 0);
  }
  return uVar3;
}


// ==== FUN_008bb97c @ 0x008bb97c ====

undefined4 FUN_008bb97c(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  void *_Memory;
  int iVar3;
  undefined4 extraout_EAX;
  uint uVar4;
  
  if (0xffff < param_3) {
    param_3 = 0xffff;
  }
  if (param_3 < param_2) {
    uVar1 = 0;
  }
  else {
    uVar2 = (param_3 - param_2) + 1;
    _Memory = operator_new(uVar2 * 2);
    if (_Memory != (void *)0x0) {
      uVar4 = 0;
      if (uVar2 != 0) {
        do {
          iVar3 = FUN_008b854b(param_2 + uVar4);
          if (iVar3 == 0) {
            *(undefined2 *)((int)_Memory + uVar4 * 2) = *(undefined2 *)(param_1 + 0x7a);
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar2);
      }
      FUN_008b9c67(_Memory,uVar2,0);
      _free(_Memory);
      return extraout_EAX;
    }
    uVar1 = 0x8007000e;
  }
  return uVar1;
}


// ==== FUN_008bba0c @ 0x008bba0c ====

undefined4 FUN_008bba0c(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint nCount;
  LPWSTR _Memory;
  LPCWSTR lpString;
  uint uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar3;
  tagGCP_RESULTSW *ptVar4;
  tagGCP_RESULTSW local_28;
  
  if (param_2 < *(ushort *)(param_1 + 0x5c)) {
    param_2 = (uint)*(ushort *)(param_1 + 0x5c);
  }
  if (*(ushort *)(param_1 + 0x5e) < param_3) {
    param_3 = (uint)*(ushort *)(param_1 + 0x5e);
  }
  if ((DAT_00b5de80 == 0) && (0xff < param_3)) {
    param_3 = 0xff;
  }
  if (param_3 < param_2) {
    uVar1 = 0;
  }
  else {
    nCount = (param_3 - param_2) + 1;
    _Memory = operator_new(nCount * 2);
    if (_Memory != (LPWSTR)0x0) {
      ptVar4 = &local_28;
      for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        ptVar4->lStructSize = 0;
        ptVar4 = (tagGCP_RESULTSW *)&ptVar4->lpOutString;
      }
      local_28.lStructSize = 0x24;
      local_28.lpGlyphs = _Memory;
      local_28.nGlyphs = nCount;
      if (DAT_00b5de80 == 0) {
        lpString = operator_new(nCount);
        if (lpString != (LPCWSTR)0x0) {
          uVar2 = 0;
          if (nCount != 0) {
            do {
              *(char *)(uVar2 + (int)lpString) = (char)param_2 + (char)uVar2;
              uVar2 = uVar2 + 1;
            } while (uVar2 < nCount);
          }
          GetCharacterPlacementA
                    (*(HDC *)(param_1 + 0x10),(LPCSTR)lpString,nCount,0,(LPGCP_RESULTSA)&local_28,0)
          ;
          goto LAB_008bbb09;
        }
      }
      else {
        lpString = operator_new(nCount * 2);
        if (lpString != (LPCWSTR)0x0) {
          uVar2 = 0;
          if (nCount != 0) {
            do {
              lpString[uVar2] = (short)param_2 + (short)uVar2;
              uVar2 = uVar2 + 1;
            } while (uVar2 < nCount);
          }
          GetCharacterPlacementW(*(HDC *)(param_1 + 0x10),lpString,nCount,0,&local_28,0);
LAB_008bbb09:
          _free(lpString);
          return extraout_EAX;
        }
      }
      _free(_Memory);
      return extraout_EAX_00;
    }
    uVar1 = 0x8007000e;
  }
  return uVar1;
}


// ==== FUN_008bbb37 @ 0x008bbb37 ====

void FUN_008bbb37(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008ba228(0,param_2,param_3,0,0,0,0,0);
  return;
}


// ==== FUN_008bbb56 @ 0x008bbb56 ====

void FUN_008bbb56(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008ba228(0,param_2,param_3,0,0,0,1,0);
  return;
}


// ==== FUN_008bbb76 @ 0x008bbb76 ====

undefined4
FUN_008bbb76(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = FUN_008ba228(param_2,param_3,param_4,param_5,param_6,param_7,0,&param_7);
  if (iVar1 < 0) {
    param_7 = 0;
  }
  return param_7;
}


// ==== FUN_008bbbaa @ 0x008bbbaa ====

undefined4
FUN_008bbbaa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = FUN_008ba228(param_2,param_3,param_4,param_5,param_6,param_7,1,&param_7);
  if (iVar1 < 0) {
    param_7 = 0;
  }
  return param_7;
}


// ==== FUN_008bbbde @ 0x008bbbde ====

void FUN_008bbbde(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 8) == (void *)0x0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0xc) = *(undefined4 *)(in_ECX + 0xc);
    *(undefined4 *)(*(int *)(in_ECX + 0xc) + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    return;
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_008bbc09 @ 0x008bbc09 ====

void FUN_008bbc09(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *puVar1 = 0;
  *(undefined4 **)(in_ECX + 0x1c) = puVar1;
  *(undefined4 **)(in_ECX + 0x18) = puVar1;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return;
}


// ==== FUN_008bbc1f @ 0x008bbc1f ====

int FUN_008bbc1f(int param_1,int *param_2,int param_3,int *param_4,undefined4 *param_5)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  int *_Str2;
  uint uVar8;
  bool bVar9;
  byte *local_c;
  
  piVar5 = param_4;
  piVar2 = (int *)*param_2;
  piVar3 = (int *)*param_4;
  if (((piVar2[1] == piVar3[1]) && (*piVar2 == *piVar3)) && (piVar2[4] == piVar3[4])) {
    if (*(int *)(piVar2[2] + param_1) == 0) {
      local_c = (byte *)0x0;
    }
    else {
      local_c = (byte *)((int *)(piVar2[2] + param_1) + 1);
    }
    if (*(int *)(piVar3[2] + param_3) == 0) {
      pbVar7 = (byte *)0x0;
    }
    else {
      pbVar7 = (byte *)((int *)(piVar3[2] + param_3) + 1);
    }
    _Str2 = (int *)0x0;
    if (*(int *)(piVar2[3] + param_1) == 0) {
      param_4 = (int *)0x0;
    }
    else {
      param_4 = (int *)(piVar2[3] + param_1) + 1;
    }
    if (*(int *)(piVar3[3] + param_3) != 0) {
      _Str2 = (int *)(piVar3[3] + param_3) + 1;
    }
    if (local_c != (byte *)0x0) {
      if (pbVar7 == (byte *)0x0) {
        return -0x7fffbffb;
      }
      do {
        bVar1 = *local_c;
        bVar9 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_008bbcdf:
          pbVar7 = (byte *)((1 - (uint)bVar9) - (uint)(bVar9 != 0));
          goto joined_r0x008bbce6;
        }
        if (bVar1 == 0) break;
        bVar1 = local_c[1];
        bVar9 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_008bbcdf;
        local_c = local_c + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar1 != 0);
      pbVar7 = (byte *)0x0;
    }
joined_r0x008bbce6:
    if (pbVar7 == (byte *)0x0) {
      if (param_4 != (int *)0x0) {
        if (_Str2 == (int *)0x0) {
          return -0x7fffbffb;
        }
        _Str2 = (int *)__stricmp((char *)param_4,(char *)_Str2);
      }
      if (_Str2 == (int *)0x0) {
        piVar2 = (int *)*param_2;
        iVar6 = piVar2[1];
        if (-1 < iVar6) {
          if (iVar6 < 4) {
            if ((piVar2[5] == *(int *)(*piVar5 + 0x14)) && (piVar2[6] == *(int *)(*piVar5 + 0x18)))
            {
              *param_2 = (int)(piVar2 + 7);
              *piVar5 = *piVar5 + 0x1c;
              return 0;
            }
          }
          else {
            if (iVar6 == 4) {
              iVar6 = *piVar2;
              if ((4 < iVar6) && ((iVar6 < 10 || ((0xe < iVar6 && (iVar6 < 0x11)))))) {
                *param_5 = 1;
              }
              *param_2 = *param_2 + 0x14;
              *piVar5 = *piVar5 + 0x14;
              return 0;
            }
            if ((iVar6 == 5) && (uVar4 = piVar2[5], uVar4 == *(uint *)(*piVar5 + 0x14))) {
              *param_2 = (int)(piVar2 + 6);
              *piVar5 = *piVar5 + 0x18;
              uVar8 = 0;
              if (uVar4 == 0) {
                return 0;
              }
              do {
                iVar6 = FUN_008bbc1f(param_1,param_2,param_3,piVar5,param_5);
                if (iVar6 < 0) {
                  return iVar6;
                }
                uVar8 = uVar8 + 1;
              } while (uVar8 < uVar4);
              return iVar6;
            }
          }
        }
      }
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008bbdba @ 0x008bbdba ====

void FUN_008bbdba(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined1 param_4,
                 undefined4 *param_5)

{
  *param_5 = 0;
  FUN_008bbc1f(param_1,&param_2,param_3,&param_4,param_5);
  return;
}


// ==== FUN_008bbddd @ 0x008bbddd ====

int FUN_008bbddd(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar7 = param_5;
  piVar6 = param_4;
  piVar5 = param_3;
  piVar8 = (int *)*param_2;
  iVar10 = piVar8[1];
  local_c = piVar8[4];
  local_10 = *piVar8;
  local_8 = 0;
  if (local_c == 0) {
    local_c = 1;
  }
  if (*(int *)(piVar8[2] + param_1) == 0) {
    piVar11 = (int *)0x0;
  }
  else {
    piVar11 = (int *)(piVar8[2] + param_1) + 1;
  }
  if (*(int *)(piVar8[3] + param_1) == 0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)(piVar8[3] + param_1) + 1;
  }
  pcVar1 = (char *)((int)piVar11 + 1);
  piVar12 = piVar11;
  do {
    iVar9 = *piVar12;
    piVar12 = (int *)((int)piVar12 + 1);
  } while ((char)iVar9 != '\0');
  cVar4 = (char)piVar11;
  do {
    iVar9 = *piVar11;
    piVar11 = (int *)((int)piVar11 + 1);
  } while ((char)iVar9 != '\0');
  iVar9 = 0;
  if (piVar8 != (int *)0x0) {
    pcVar2 = (char *)((int)piVar8 + 1);
    piVar13 = piVar8;
    do {
      iVar9 = *piVar13;
      piVar13 = (int *)((int)piVar13 + 1);
    } while ((char)iVar9 != '\0');
    cVar3 = (char)piVar8;
    do {
      iVar9 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar9 != '\0');
    iVar9 = (uint)((((char)piVar8 - (cVar3 + '\x01')) + 1U & 3) != 0) +
            ((uint)((int)piVar13 + (1 - (int)pcVar2)) >> 2);
  }
  *param_5 = (((uint)((int)piVar12 + (1 - (int)pcVar1)) >> 2) +
             (uint)((((char)piVar11 - (cVar4 + '\x01')) + 1U & 3) != 0) + iVar9) * 4 + 8;
  *param_4 = 0;
  *param_3 = 0;
  if (iVar10 < 0) {
    return -0x7fffbffb;
  }
  if (iVar10 < 2) {
    local_c = local_c << 2;
  }
  else {
    if (3 < iVar10) {
      if (iVar10 != 4) {
        if (iVar10 != 5) {
          return -0x7fffbffb;
        }
        local_14 = *(uint *)(*param_2 + 0x14);
        param_5 = (int *)0x0;
        *param_2 = *param_2 + 0x18;
        *param_3 = 0x18;
        if (local_14 != 0) {
          local_18 = 5;
          do {
            local_8 = FUN_008bbddd(param_1,param_2,&param_3,&param_4,&local_18);
            if (local_8 < 0) {
              return local_8;
            }
            *piVar6 = *piVar6 + (int)param_4;
            *piVar5 = *piVar5 + (int)param_3;
            *piVar7 = *piVar7 + local_18;
            param_5 = (int *)((int)param_5 + 1);
          } while (param_5 < local_14);
        }
        *piVar6 = *piVar6 * local_c;
        return local_8;
      }
      iVar10 = 0x14;
      *param_3 = 0x14;
      if (local_10 < 4) {
        return -0x7fffbffb;
      }
      if (9 < local_10) {
        if (local_10 < 0xf) {
          return -0x7fffbffb;
        }
        if (0x10 < local_10) {
          return -0x7fffbffb;
        }
      }
      *param_4 = local_c << 2;
      goto LAB_008bbf76;
    }
    local_c = local_c << 4;
  }
  iVar10 = 0x1c;
  *param_4 = local_c;
  *param_3 = 0x1c;
  if (((local_10 != 1) && (local_10 != 2)) && (local_10 != 3)) {
    return -0x7fffbffb;
  }
  *param_4 = *param_4 << 2;
LAB_008bbf76:
  *param_2 = *param_2 + iVar10;
  return 0;
}


// ==== FUN_008bbf93 @ 0x008bbf93 ====

int FUN_008bbf93(int param_1,int *param_2,int *param_3,int param_4,int *param_5,int *param_6,
                int *param_7,int *param_8)

{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  int *local_10;
  int *local_c;
  int local_8;
  
  piVar5 = param_5;
  *(undefined4 *)(*param_6 + 4) = *(undefined4 *)(*param_2 + 4);
  *(undefined4 *)*param_6 = *(undefined4 *)*param_2;
  *(undefined4 *)(*param_6 + 0x10) = *(undefined4 *)(*param_2 + 0x10);
  *(int *)(*param_6 + 8) = *param_5;
  piVar10 = (int *)*param_2;
  iVar8 = piVar10[1];
  iVar2 = *piVar10;
  local_8 = 0;
  bVar3 = false;
  param_5 = (int *)0x1;
  if (piVar10[4] != 0) {
    param_5 = (int *)piVar10[4];
  }
  if (*(int *)(piVar10[2] + param_1) == 0) {
    local_c = (int *)0x0;
  }
  else {
    local_c = (int *)(piVar10[2] + param_1) + 1;
  }
  if (*(int *)(piVar10[3] + param_1) == 0) {
    local_10 = (int *)0x0;
  }
  else {
    local_10 = (int *)(piVar10[3] + param_1) + 1;
  }
  piVar10 = local_c;
  do {
    iVar4 = *piVar10;
    piVar10 = (int *)((int)piVar10 + 1);
  } while ((char)iVar4 != '\0');
  pcVar1 = (char *)((int)piVar10 + (1 - (int)((int)local_c + 1)));
  *(char **)(param_4 + *piVar5) = pcVar1;
  *piVar5 = *piVar5 + 4;
  piVar10 = (int *)(*piVar5 + param_4);
  for (uVar6 = (uint)pcVar1 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *piVar10 = *local_c;
    local_c = local_c + 1;
    piVar10 = piVar10 + 1;
  }
  for (uVar6 = (uint)pcVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(char *)piVar10 = (char)*local_c;
    local_c = (int *)((int)local_c + 1);
    piVar10 = (int *)((int)piVar10 + 1);
  }
  *piVar5 = *piVar5 + ((uint)(((uint)pcVar1 & 3) != 0) + ((uint)pcVar1 >> 2)) * 4;
  *(int *)(*param_6 + 0xc) = *piVar5;
  if (local_10 == (int *)0x0) {
    *(undefined4 *)(param_4 + *piVar5) = 0;
    *piVar5 = *piVar5 + 4;
  }
  else {
    piVar10 = local_10;
    do {
      iVar4 = *piVar10;
      piVar10 = (int *)((int)piVar10 + 1);
    } while ((char)iVar4 != '\0');
    pcVar1 = (char *)((int)piVar10 + (1 - (int)((int)local_10 + 1)));
    *(char **)(param_4 + *piVar5) = pcVar1;
    *piVar5 = *piVar5 + 4;
    piVar10 = (int *)(*piVar5 + param_4);
    for (uVar6 = (uint)pcVar1 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *piVar10 = *local_10;
      local_10 = local_10 + 1;
      piVar10 = piVar10 + 1;
    }
    for (uVar6 = (uint)pcVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(char *)piVar10 = (char)*local_10;
      local_10 = (int *)((int)local_10 + 1);
      piVar10 = (int *)((int)piVar10 + 1);
    }
    *piVar5 = *piVar5 + ((uint)(((uint)pcVar1 & 3) != 0) + ((uint)pcVar1 >> 2)) * 4;
  }
  if (-1 < iVar8) {
    if (1 < iVar8) {
      if (3 < iVar8) {
        if (iVar8 != 4) {
          if (iVar8 != 5) {
            return -0x7fffbffb;
          }
          *(undefined4 *)(*param_6 + 0x14) = *(undefined4 *)(*param_2 + 0x14);
          uVar6 = *(uint *)(*param_2 + 0x14);
          *param_2 = *param_2 + 0x18;
          *param_6 = *param_6 + 0x18;
          iVar8 = *piVar5;
          iVar2 = *param_2;
          iVar4 = *param_6;
          do {
            if (param_5 == (int *)0x0) {
              return local_8;
            }
            local_10 = (int *)0x0;
            *param_2 = iVar2;
            *param_6 = iVar4;
            *piVar5 = iVar8;
            if (uVar6 != 0) {
              do {
                local_8 = FUN_008bbf93(param_1,param_2,param_3,param_4,piVar5,param_6,param_7,
                                       param_8);
                if (local_8 < 0) {
                  return local_8;
                }
                local_10 = (int *)((int)local_10 + 1);
              } while (local_10 < uVar6);
            }
            param_5 = (int *)((int)param_5 + -1);
          } while( true );
        }
        if (iVar2 < 4) {
          return -0x7fffbffb;
        }
        if (9 < iVar2) {
          if (iVar2 < 0xf) {
            return -0x7fffbffb;
          }
          if (0x10 < iVar2) {
            return -0x7fffbffb;
          }
        }
        if (param_5 != (int *)0x0) {
          param_4 = (int)param_5;
          do {
            *(int *)*param_7 = *param_8;
            *param_8 = *param_8 + 1;
            *param_3 = *param_3 + 4;
            *param_7 = *param_7 + 4;
            param_4 = param_4 + -1;
          } while (param_4 != 0);
        }
        *param_2 = *param_2 + 0x14;
        *param_6 = *param_6 + 0x14;
        return 0;
      }
      bVar3 = true;
    }
    *(undefined4 *)(*param_6 + 0x14) = *(undefined4 *)(*param_2 + 0x14);
    *(undefined4 *)(*param_6 + 0x18) = *(undefined4 *)(*param_2 + 0x18);
    if (bVar3) {
      uVar6 = (int)param_5 << 4;
    }
    else {
      uVar6 = (int)param_5 << 2;
    }
    if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 3)) {
      puVar9 = (undefined4 *)*param_3;
      puVar11 = (undefined4 *)*param_7;
      for (uVar7 = uVar6 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      *param_3 = *param_3 + uVar6 * 4;
      *param_7 = *param_7 + uVar6 * 4;
      *param_2 = *param_2 + 0x1c;
      *param_6 = *param_6 + 0x1c;
      return 0;
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008bc245 @ 0x008bc245 ====

void FUN_008bc245(undefined4 param_1,undefined1 param_2,undefined1 param_3,int param_4,int param_5,
                 int param_6,int param_7,undefined4 *param_8)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_8;
  iVar1 = param_4;
  param_4 = param_5 + param_4 + param_6;
  *param_8 = 0;
  param_8 = (undefined4 *)(param_4 + param_7);
  FUN_008bbf93(param_1,&param_2,&param_3,iVar1,&param_5,&param_4,&param_8,puVar2);
  return;
}


// ==== FUN_008bc28a @ 0x008bc28a ====

int FUN_008bc28a(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint local_c;
  int local_8;
  
  piVar5 = param_1;
  local_8 = 0;
  piVar1 = (int *)*param_1;
  iVar2 = *piVar1;
  iVar3 = piVar1[1];
  param_1 = (int *)0x1;
  if (piVar1[4] != 0) {
    param_1 = (int *)piVar1[4];
  }
  if (-1 < iVar3) {
    if (iVar3 < 4) {
      if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 3)) {
        *param_2 = *param_2 + piVar1[6] * piVar1[5] * (int)param_1 * 4;
        *piVar5 = *piVar5 + 0x1c;
        return 0;
      }
    }
    else if (iVar3 == 4) {
      if ((3 < iVar2) && ((iVar2 < 10 || ((0xe < iVar2 && (iVar2 < 0x11)))))) {
        for (; param_1 != (int *)0x0; param_1 = (int *)((int)param_1 + -1)) {
          *(undefined4 *)*param_3 = *(undefined4 *)*param_2;
          *param_3 = *param_3 + 4;
          *param_2 = *param_2 + 4;
        }
        *piVar5 = *piVar5 + 0x14;
        return 0;
      }
    }
    else if (iVar3 == 5) {
      uVar4 = piVar1[5];
      *piVar5 = (int)(piVar1 + 6);
      do {
        if (param_1 == (int *)0x0) {
          return local_8;
        }
        local_c = 0;
        *piVar5 = (int)(piVar1 + 6);
        if (uVar4 != 0) {
          do {
            local_8 = FUN_008bc28a(piVar5,param_2,param_3);
            if (local_8 < 0) {
              return local_8;
            }
            local_c = local_c + 1;
          } while (local_c < uVar4);
        }
        param_1 = (int *)((int)param_1 + -1);
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008bc37a @ 0x008bc37a ====

void FUN_008bc37a(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  FUN_008bc28a(&param_1,&param_2,&param_3);
  return;
}


// ==== FUN_008bc394 @ 0x008bc394 ====

int FUN_008bc394(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  
  piVar2 = param_1;
  piVar1 = (int *)*param_1;
  iVar6 = piVar1[1];
  iVar4 = *piVar1;
  iVar8 = piVar1[4];
  iVar3 = 0;
  if (iVar8 == 0) {
    iVar8 = 1;
  }
  if (-1 < iVar6) {
    if (iVar6 < 4) {
      uVar5 = piVar1[6] * piVar1[5] * iVar8;
      if (((iVar4 == 1) || (iVar4 == 2)) || (iVar4 == 3)) {
        iVar6 = uVar5 * 4;
        puVar7 = (undefined4 *)*param_3;
        puVar9 = (undefined4 *)*param_2;
        for (uVar5 = uVar5 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        *param_2 = *param_2 + iVar6;
        *param_3 = *param_3 + iVar6;
        *param_1 = *param_1 + 0x1c;
        return 0;
      }
    }
    else if (iVar6 == 4) {
      switch(iVar4) {
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 0xf:
      case 0x10:
        *param_2 = *param_2 + iVar8 * 4;
        *param_3 = *param_3 + iVar8 * 4;
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0x11:
      case 0x12:
        *param_1 = *param_1 + 0x14;
        return 0;
      }
    }
    else if (iVar6 == 5) {
      uVar5 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      do {
        if (iVar8 == 0) {
          return iVar3;
        }
        param_1 = (int *)0x0;
        *piVar2 = (int)(piVar1 + 6);
        if (uVar5 != 0) {
          do {
            iVar3 = FUN_008bc394(piVar2,param_2,param_3);
            if (iVar3 < 0) {
              return iVar3;
            }
            param_1 = (int *)((int)param_1 + 1);
          } while (param_1 < uVar5);
        }
        iVar8 = iVar8 + -1;
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008bc4a4 @ 0x008bc4a4 ====

void FUN_008bc4a4(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  FUN_008bc394(&param_1,&param_2,&param_3);
  return;
}


// ==== FUN_008bc4be @ 0x008bc4be ====

int FUN_008bc4be(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  uint local_c;
  int local_8;
  
  piVar1 = (int *)*param_1;
  local_8 = 0;
  iVar4 = piVar1[1];
  iVar2 = *piVar1;
  local_c = piVar1[4];
  if (local_c == 0) {
    local_c = 1;
  }
  if (-1 < iVar4) {
    if (iVar4 < 4) {
      if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 3)) {
        *param_2 = *param_2 + piVar1[6] * piVar1[5] * local_c * 4;
        *param_1 = *param_1 + 0x1c;
        return 0;
      }
      return -0x7fffbffb;
    }
    if (iVar4 != 4) {
      if (iVar4 != 5) {
        return -0x7fffbffb;
      }
      uVar3 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      iVar4 = local_c;
      do {
        if (iVar4 == 0) {
          return local_8;
        }
        local_c = 0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar3 != 0) {
          do {
            local_8 = FUN_008bc4be(param_1,param_2,param_3,param_4);
            if (local_8 < 0) {
              return local_8;
            }
            local_c = local_c + 1;
          } while (local_c < uVar3);
        }
        iVar4 = iVar4 + -1;
      } while( true );
    }
    if (iVar2 < 0x10) {
      if (iVar2 == 0xf) {
        if (local_c != 0) {
          do {
            iVar4 = *(int *)(*param_4 + 0x18) + *(int *)(*(int *)*param_2 * 4 + param_4[2]) * 0x18;
            iVar2 = *(int *)(*param_3 + 0x18) + *(int *)(*(int *)*param_2 * 4 + param_3[2]) * 0x18;
            if (*(int *)(iVar2 + 4) != 0) {
              (**(code **)(**(int **)(iVar2 + 4) + 4))(*(int **)(iVar2 + 4));
            }
            if (*(int *)(iVar2 + 8) != 0) {
              (**(code **)(**(int **)(iVar2 + 8) + 4))(*(int **)(iVar2 + 8));
            }
            piVar1 = *(int **)(iVar4 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar4 + 4) = 0;
            }
            piVar1 = *(int **)(iVar4 + 8);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar4 + 8) = 0;
            }
            *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar2 + 4);
            *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar2 + 8);
            *(uint *)(iVar4 + 0x14) =
                 *(uint *)(iVar4 + 0x14) ^
                 ((*(int *)(iVar2 + 0x14) << 0x1e) >> 0x1e ^ *(uint *)(iVar4 + 0x14)) & 2;
            *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
            *param_2 = *param_2 + 4;
            local_c = local_c + -1;
          } while (local_c != 0);
        }
        goto LAB_008bc7d5;
      }
      if (iVar2 == 4) {
        if (local_c != 0) {
          do {
            iVar4 = *(int *)(*param_4 + 0x18) + *(int *)(*(int *)*param_2 * 4 + param_4[2]) * 0x18;
            iVar2 = *(int *)(*param_3 + 0x18) + *(int *)(*(int *)*param_2 * 4 + param_3[2]) * 0x18;
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
            local_c = local_c + -1;
          } while (local_c != 0);
        }
        goto LAB_008bc7d5;
      }
      if (iVar2 < 5) {
        return -0x7fffbffb;
      }
      if (iVar2 < 10) {
        if (local_c != 0) {
          do {
            iVar4 = *(int *)(*param_4 + 0x18) + *(int *)(*(int *)*param_2 * 4 + param_4[2]) * 0x18;
            iVar2 = *(int *)(*param_3 + 0x18) + *(int *)(*(int *)*param_2 * 4 + param_3[2]) * 0x18;
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
            local_c = local_c + -1;
          } while (local_c != 0);
        }
        goto LAB_008bc7d5;
      }
      bVar6 = SBORROW4(iVar2,0xe);
      iVar4 = iVar2 + -0xe;
      bVar5 = iVar2 == 0xe;
    }
    else {
      if (iVar2 == 0x10) {
        if (local_c != 0) {
          do {
            iVar4 = *(int *)(*param_4 + 0x18) + *(int *)(*(int *)*param_2 * 4 + param_4[2]) * 0x18;
            iVar2 = *(int *)(*param_3 + 0x18) + *(int *)(*(int *)*param_2 * 4 + param_3[2]) * 0x18;
            if (*(int *)(iVar2 + 4) != 0) {
              (**(code **)(**(int **)(iVar2 + 4) + 4))(*(int **)(iVar2 + 4));
            }
            if (*(int *)(iVar2 + 8) != 0) {
              (**(code **)(**(int **)(iVar2 + 8) + 4))(*(int **)(iVar2 + 8));
            }
            piVar1 = *(int **)(iVar4 + 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar4 + 4) = 0;
            }
            piVar1 = *(int **)(iVar4 + 8);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)(iVar4 + 8) = 0;
            }
            *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar2 + 4);
            *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar2 + 8);
            *(uint *)(iVar4 + 0x14) =
                 *(uint *)(iVar4 + 0x14) ^
                 ((*(int *)(iVar2 + 0x14) << 0x1e) >> 0x1e ^ *(uint *)(iVar4 + 0x14)) & 2;
            *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
            *param_2 = *param_2 + 4;
            local_c = local_c + -1;
          } while (local_c != 0);
        }
        goto LAB_008bc7d5;
      }
      if (iVar2 < 0x11) {
        return -0x7fffbffb;
      }
      bVar6 = SBORROW4(iVar2,0x12);
      iVar4 = iVar2 + -0x12;
      bVar5 = iVar2 == 0x12;
    }
    if (bVar5 || bVar6 != iVar4 < 0) {
LAB_008bc7d5:
      *param_1 = *param_1 + 0x14;
      return 0;
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008bc804 @ 0x008bc804 ====

undefined4 FUN_008bc804(undefined1 param_1,undefined1 param_2,int *param_3,int *param_4)

{
  undefined4 uVar1;
  
  if ((param_3 == param_4) || (*param_3 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_008bc4be(&param_1,&param_2,param_4,param_3);
  }
  return uVar1;
}


// ==== FUN_008bc82f @ 0x008bc82f ====

undefined4 FUN_008bc82f(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  for (iVar1 = *(int *)(in_ECX + 0x1c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
    for (iVar2 = *(int *)(iVar1 + 0x1c); iVar2 != iVar1 + 0xc; iVar2 = *(int *)(iVar2 + 0x10)) {
      **(int **)(iVar2 + 4) = (*(int **)(iVar2 + 4))[0xc] + *(int *)(in_ECX + 0x10);
    }
  }
  return 0;
}


// ==== FUN_008bc860 @ 0x008bc860 ====

void FUN_008bc860(byte param_1)

{
  void *in_ECX;
  
  FUN_008bbbde();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008bc881 @ 0x008bc881 ====

int FUN_008bc881(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  int extraout_EAX;
  void *pvVar4;
  int *piVar5;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int local_20;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = param_2;
  local_c = param_2[0xb] + *(int *)(param_1 + 0x20);
  local_18 = param_2[0xc] + *(int *)(param_1 + 0x20);
  for (piVar5 = *(int **)(in_ECX + 0x1c); piVar5 != (int *)0x0; piVar5 = (int *)piVar5[8]) {
    iVar2 = FUN_008bbdba(*(undefined4 *)(param_1 + 0x20),local_c,*(int *)(in_ECX + 0x10),
                         *piVar5 + *(int *)(in_ECX + 0x10),&local_14);
    if (-1 < iVar2) {
      if (((local_14 != 0) && (*(int *)piVar5[7] != 0)) &&
         (*(int *)(param_1 + 0xc) != *(int *)(*(int *)piVar5[7] + 0xc))) {
        return -0x7fffbffb;
      }
      if ((piVar5 + 3 == (int *)piVar5[7]) &&
         (local_8 = FUN_008bc4a4(local_c,piVar5[1] + *(int *)(in_ECX + 0x10),local_18), local_8 < 0)
         ) {
        return local_8;
      }
      goto LAB_008bca69;
    }
  }
  local_8 = local_c;
  local_8 = FUN_008bbddd(*(undefined4 *)(param_1 + 0x20),&local_8,&local_14,&local_1c,&local_10);
  if (local_8 < 0) {
    return local_8;
  }
  puVar3 = (undefined1 *)((int)local_1c + local_10 + *(int *)(in_ECX + 0x14) + local_14);
  if (*(undefined1 **)(in_ECX + 0x18) < puVar3) {
    uVar7 = (int)*(undefined1 **)(in_ECX + 0x18) * 2;
    uVar6 = 0x10000;
    if (0xffff < uVar7) {
      uVar6 = uVar7;
    }
    *(uint *)(in_ECX + 0x18) = uVar6;
    local_1c = operator_new(uVar6);
    if (local_1c == (undefined4 *)0x0) {
      return -0x7ff8fff2;
    }
    uVar7 = *(uint *)(in_ECX + 0x14);
    if (uVar7 != 0) {
      puVar8 = *(undefined4 **)(in_ECX + 0x10);
      puVar9 = local_1c;
      for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
    }
    uVar6 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14);
    puVar8 = (undefined4 *)(*(int *)(in_ECX + 0x14) + (int)local_1c);
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar8 = 0;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    if (*(void **)(in_ECX + 0x10) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x10));
      return extraout_EAX;
    }
    *(undefined4 **)(in_ECX + 0x10) = local_1c;
    FUN_008bc82f();
  }
  local_8 = FUN_008bc245(*(undefined4 *)(param_1 + 0x20),local_c,local_18,
                         *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14),local_10,
                         local_14,&local_20);
  if (local_8 < 0) {
    return local_8;
  }
  pvVar4 = operator_new(0x24);
  if (pvVar4 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_008bbc09();
  }
  if (piVar5 == (int *)0x0) {
    return -0x7ff8fff2;
  }
  *piVar5 = *(int *)(in_ECX + 0x14) + local_10;
  piVar5[1] = *(int *)(in_ECX + 0x14) + local_14 + local_10;
  piVar5[2] = local_20;
  piVar5[8] = *(int *)(in_ECX + 0x1c);
  *(int **)(in_ECX + 0x1c) = piVar5;
  *(undefined1 **)(in_ECX + 0x14) = puVar3;
LAB_008bca69:
  param_2 = operator_new(0x14);
  if (param_2 == (int *)0x0) {
    param_2 = (int *)0x0;
  }
  else {
    param_2[2] = 0;
    *param_2 = 0;
    param_2[4] = (int)param_2;
    param_2[3] = (int)param_2;
  }
  if (param_2 == (int *)0x0) {
    return -0x7ff8fff2;
  }
  if (piVar5[2] != 0) {
    pvVar4 = operator_new(piVar5[2] << 2);
    param_2[2] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) {
      local_8 = -0x7ff8fff2;
      goto LAB_008bcb2c;
    }
    local_8 = FUN_008bc37a(local_c,local_18,pvVar4);
    if (local_8 < 0) goto LAB_008bcb2c;
  }
  *param_2 = param_1;
  param_2[1] = (int)piVar1;
  *(int **)(piVar5[7] + 0xc) = param_2;
  param_2[3] = (int)(piVar5 + 3);
  param_2[4] = piVar5[7];
  piVar5[7] = (int)param_2;
  piVar1[0x10] = (int)param_2;
  piVar1[0xb] = *piVar5;
  piVar1[0xc] = piVar5[1];
  param_2 = (int *)0x0;
  piVar1[1] = *(int *)(in_ECX + 0x10) + *piVar5;
  *piVar1 = *(int *)(in_ECX + 0x10) + piVar5[1];
  local_8 = FUN_008bc804(piVar1[0xb] + *(int *)(in_ECX + 0x10),piVar1[0xc] + *(int *)(in_ECX + 0x10)
                         ,piVar1[0x10],piVar5[6]);
LAB_008bcb2c:
  if (param_2 == (int *)0x0) {
    return local_8;
  }
  FUN_008bc860(1);
  return local_8;
}


// ==== FUN_008bcb44 @ 0x008bcb44 ====

void FUN_008bcb44(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 1;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  return;
}


// ==== FUN_008bcb64 @ 0x008bcb64 ====

void FUN_008bcb64(void)

{
  int *in_ECX;
  
  if (*in_ECX == 0) {
    _free((void *)in_ECX[6]);
    return;
  }
  _free((void *)*in_ECX);
  return;
}


// ==== FUN_008bcb95 @ 0x008bcb95 ====

void FUN_008bcb95(uint param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  uVar1 = *(uint *)(in_ECX + 0x14);
  uVar8 = 0;
  uVar3 = uVar1 >> 1;
  uVar5 = uVar1;
  if (uVar1 == 0) {
LAB_008bcbdf:
    if (uVar1 == (~uVar1 + 1 & uVar1)) {
      if (uVar1 == 0) {
        iVar6 = 1;
      }
      else {
        iVar6 = uVar1 * 2;
      }
      puVar4 = operator_new(iVar6 << 2);
      if (puVar4 != (undefined4 *)0x0) {
        puVar7 = *(undefined4 **)(in_ECX + 0x1c);
        for (uVar8 = *(uint *)(in_ECX + 0x14) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar4 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar4 = puVar4 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar4 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        _free(*(void **)(in_ECX + 0x1c));
        return;
      }
      goto LAB_008bccc6;
    }
    for (uVar8 = *(uint *)(in_ECX + 0x14); uVar3 < uVar8; uVar8 = uVar8 - 1) {
      puVar4 = (undefined4 *)(*(int *)(in_ECX + 0x18) + uVar8 * 4);
      *puVar4 = puVar4[-1];
      puVar4 = (undefined4 *)(*(int *)(in_ECX + 0x1c) + uVar8 * 4);
      *puVar4 = puVar4[-1];
    }
    *(uint *)(*(int *)(in_ECX + 0x18) + uVar3 * 4) = param_1;
    *(undefined4 *)(*(int *)(in_ECX + 0x1c) + uVar3 * 4) = 1;
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  }
  else {
    do {
      uVar2 = *(uint *)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      if (uVar2 < param_1) {
        uVar8 = uVar3 + 1;
      }
      else {
        if (uVar2 <= param_1) break;
        uVar5 = uVar3;
      }
      uVar3 = uVar5 + uVar8 >> 1;
    } while (uVar8 < uVar5);
    if (uVar5 <= uVar8) goto LAB_008bcbdf;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar3;
  }
LAB_008bccc6:
  _free((void *)0x0);
  return;
}


// ==== FUN_008bccd8 @ 0x008bccd8 ====

undefined4 FUN_008bccd8(void)

{
  uint *puVar1;
  undefined4 extraout_EAX;
  int *in_ECX;
  uint uVar2;
  
  if (*in_ECX != 0) {
    _free((void *)*in_ECX);
    return extraout_EAX;
  }
  uVar2 = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  if (in_ECX[5] != 0) {
    do {
      puVar1 = (uint *)(in_ECX[7] + uVar2 * 4);
      *puVar1 = *puVar1 & 0xffffffdf;
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)in_ECX[5]);
  }
  return 0;
}


// ==== FUN_008bcd1b @ 0x008bcd1b ====

undefined4 FUN_008bcd1b(char *param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 *in_ECX;
  uint uVar6;
  
  pcVar1 = param_1 + 1;
  pcVar3 = param_1;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  pcVar4 = operator_new((uint)(pcVar3 + (5 - (int)pcVar1)));
  if (pcVar4 == (char *)0x0) {
    uVar5 = 0x8007000e;
  }
  else {
    *(undefined4 *)pcVar4 = *in_ECX;
    in_ECX[1] = pcVar3 + (in_ECX[1] - (int)pcVar1);
    *in_ECX = pcVar4;
    for (uVar6 = (uint)(pcVar3 + (1 - (int)pcVar1)) >> 2; pcVar4 = pcVar4 + 4, uVar6 != 0;
        uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)param_1;
      param_1 = param_1 + 4;
    }
    for (uVar6 = (uint)(pcVar3 + (1 - (int)pcVar1)) & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar4 = *param_1;
      param_1 = param_1 + 1;
      pcVar4 = pcVar4 + 1;
    }
    uVar5 = 0;
  }
  return uVar5;
}


// ==== FUN_008bcd75 @ 0x008bcd75 ====

int FUN_008bcd75(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *in_ECX;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  
  if (param_1 != (undefined4 *)0x0) {
    if (in_ECX[1] == 0) {
      *param_1 = 0;
    }
    else {
      iVar3 = FUN_008eb37d(in_ECX[1] + 1,param_1);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = (**(code **)(*(int *)*param_1 + 0xc))((int *)*param_1);
      pcVar4 = (char *)(iVar3 + in_ECX[1]);
      *pcVar4 = '\0';
      for (puVar2 = (undefined4 *)*in_ECX; puVar2 != (undefined4 *)0x0;
          puVar2 = (undefined4 *)*puVar2) {
        pcVar5 = (char *)(puVar2 + 1);
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        uVar6 = (int)pcVar5 - ((int)puVar2 + 5);
        pcVar4 = pcVar4 + -uVar6;
        pcVar5 = (char *)(puVar2 + 1);
        pcVar8 = pcVar4;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar8 = pcVar8 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar8 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar8 = pcVar8 + 1;
        }
      }
    }
  }
  return 0;
}


// ==== FUN_008bcde3 @ 0x008bcde3 ====

undefined4 FUN_008bcde3(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_008bcde7 @ 0x008bcde7 ====

void FUN_008bcde7(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 1;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_008bce01 @ 0x008bce01 ====

undefined4
FUN_008bce01(char *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6
            )

{
  char cVar1;
  char *pcVar2;
  undefined4 *in_ECX;
  
  if ((param_5 != 0) && (param_6 != 0)) {
    if (param_2 == -1) {
      if (param_1 == (char *)0x0) {
        param_2 = 0;
      }
      else {
        pcVar2 = param_1;
        do {
          cVar1 = *pcVar2;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        param_2 = (int)pcVar2 - (int)(param_1 + 1);
      }
    }
    if ((param_1 != (char *)0x0) || (param_2 == 0)) {
      *in_ECX = param_1;
      in_ECX[6] = param_3;
      in_ECX[7] = param_4;
      in_ECX[0xb] = param_5;
      in_ECX[1] = param_1 + param_2;
      in_ECX[0xc] = param_6;
      return 0;
    }
  }
  return 0x80004005;
}


// ==== FUN_008bce6b @ 0x008bce6b ====

undefined4 FUN_008bce6b(void)

{
  char *pcVar1;
  char *pcVar2;
  undefined4 *in_ECX;
  
  pcVar1 = (char *)in_ECX[1];
  if ((char *)*in_ECX < pcVar1) {
    do {
      pcVar2 = (char *)*in_ECX;
      if (*pcVar2 == '\n') {
        return 1;
      }
      if (*pcVar2 == '\\') {
        if ((pcVar2 + 1 < pcVar1) && (pcVar2[1] == '\n')) {
          pcVar2 = pcVar2 + 2;
        }
        else {
          if ((pcVar1 <= pcVar2 + 2) || ((pcVar2[1] != '\r' || (pcVar2[2] != '\n'))))
          goto LAB_008bceb4;
          pcVar2 = pcVar2 + 3;
        }
        in_ECX[7] = in_ECX[7] + 1;
      }
      else {
LAB_008bceb4:
        pcVar2 = pcVar2 + 1;
      }
      *in_ECX = pcVar2;
    } while (pcVar2 < (char *)in_ECX[1]);
  }
  return 0;
}


// ==== FUN_008bcec6 @ 0x008bcec6 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

int FUN_008bcec6(char *param_1,double *param_2)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  double dVar8;
  undefined4 uStackY_1c;
  
  bVar1 = false;
  if (param_1 < *(char **)(in_ECX + 4)) {
    uStackY_1c = 0x8bcee6;
    iVar2 = _isdigit((int)*param_1);
    pcVar4 = param_1;
    if (iVar2 == 0) goto LAB_008bceeb;
    do {
      pcVar5 = pcVar4;
      pcVar4 = pcVar5 + 1;
      if (*(char **)(in_ECX + 4) <= pcVar4) break;
      uStackY_1c = 0x8bcf20;
      iVar2 = _isdigit((int)*pcVar4);
    } while (iVar2 != 0);
    if ((pcVar4 < *(char **)(in_ECX + 4)) && (*pcVar4 == '.')) {
      pcVar4 = pcVar5 + 2;
      if (pcVar4 < *(char **)(in_ECX + 4)) {
        do {
          uStackY_1c = 0x8bcf45;
          iVar2 = _isdigit((int)*pcVar4);
          if (iVar2 == 0) break;
          pcVar4 = pcVar4 + 1;
        } while (pcVar4 < *(char **)(in_ECX + 4));
      }
    }
    else {
      bVar1 = true;
    }
LAB_008bcf6f:
    pcVar5 = pcVar4 + 1;
    if (pcVar5 < *(char **)(in_ECX + 4)) {
      uStackY_1c = 0x8bcf80;
      iVar2 = _tolower((int)*pcVar4);
      if (iVar2 != 0x65) goto LAB_008bcfae;
      uStackY_1c = 0x8bcf8f;
      iVar2 = _isdigit((int)*pcVar5);
      if (iVar2 == 0) goto LAB_008bcfae;
      for (pcVar4 = pcVar4 + 2; pcVar4 < *(char **)(in_ECX + 4); pcVar4 = pcVar4 + 1) {
        uStackY_1c = 0x8bcfa1;
        iVar2 = _isdigit((int)*pcVar4);
        if (iVar2 == 0) break;
      }
    }
    else {
LAB_008bcfae:
      if (pcVar4 + 2 < *(char **)(in_ECX + 4)) {
        uStackY_1c = 0x8bcfbf;
        iVar2 = _tolower((int)*pcVar4);
        if ((iVar2 == 0x65) && (*pcVar5 == '-')) {
          uStackY_1c = 0x8bcfd4;
          iVar2 = _isdigit((int)pcVar4[2]);
          if (iVar2 != 0) {
            for (pcVar4 = pcVar4 + 3; pcVar4 < *(char **)(in_ECX + 4); pcVar4 = pcVar4 + 1) {
              uStackY_1c = 0x8bcfe7;
              iVar2 = _isdigit((int)*pcVar4);
              if (iVar2 == 0) break;
            }
            goto LAB_008bcffa;
          }
        }
      }
      if (bVar1) goto LAB_008bd045;
    }
LAB_008bcffa:
    if (param_2 != (double *)0x0) {
      uVar6 = (int)pcVar4 - (int)param_1;
      iVar2 = -(uVar6 + 4 & 0xfffffffc);
      pcVar5 = param_1;
      pcVar7 = (char *)((int)register0x00000010 + iVar2 + -0x14);
      for (uVar3 = uVar6 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar3 = uVar6 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar7 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar7 = pcVar7 + 1;
      }
      *(int *)((int)register0x00000010 + iVar2 + -0x18) = (int)register0x00000010 + iVar2 + -0x14;
      *(undefined1 *)((int)register0x00000010 + uVar6 + iVar2 + -0x14) = 0;
      *(undefined4 *)((int)&uStackY_1c + iVar2) = 0x8bd038;
      dVar8 = _atof(*(char **)((int)register0x00000010 + iVar2 + -0x18));
      *param_2 = dVar8;
    }
    iVar2 = (int)pcVar4 - (int)param_1;
  }
  else {
LAB_008bceeb:
    if ((param_1 + 1 < *(char **)(in_ECX + 4)) && (*param_1 == '.')) {
      uStackY_1c = 0x8bcf09;
      iVar2 = _isdigit((int)param_1[1]);
      if (iVar2 != 0) {
        for (pcVar4 = param_1 + 2; pcVar4 < *(char **)(in_ECX + 4); pcVar4 = pcVar4 + 1) {
          uStackY_1c = 0x8bcf64;
          iVar2 = _isdigit((int)*pcVar4);
          if (iVar2 == 0) break;
        }
        goto LAB_008bcf6f;
      }
    }
LAB_008bd045:
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_008bd051 @ 0x008bd051 ====

uint FUN_008bd051(char *param_1,undefined4 *param_2)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  
  if ((param_1 < *(char **)(in_ECX + 4)) &&
     ((iVar1 = _isalpha((int)*param_1), pcVar3 = param_1, iVar1 != 0 || (*param_1 == '_')))) {
    do {
      pcVar3 = pcVar3 + 1;
      if (*(char **)(in_ECX + 4) <= pcVar3) break;
      iVar1 = _isalnum((int)*pcVar3);
    } while ((iVar1 != 0) || (*pcVar3 == '_'));
    uVar4 = (int)pcVar3 - (int)param_1;
    pcVar3 = (char *)FUN_008f33e7(uVar4 + 1,1);
    if (pcVar3 != (char *)0x0) {
      pcVar5 = pcVar3;
      for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)param_1;
        param_1 = param_1 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar2 = uVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar5 = *param_1;
        param_1 = param_1 + 1;
        pcVar5 = pcVar5 + 1;
      }
      pcVar3[uVar4] = '\0';
      *param_2 = pcVar3;
      return uVar4;
    }
  }
  return 0;
}


// ==== FUN_008bd0d5 @ 0x008bd0d5 ====

undefined4 FUN_008bd0d5(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  int in_ECX;
  
  param_2[0] = '\0';
  param_2[1] = '\0';
  param_2[2] = '\0';
  param_2[3] = '\0';
  *param_2 = *param_1;
  pcVar1 = param_1 + 1;
  if (*(char **)(in_ECX + 4) <= pcVar1) {
    return 1;
  }
  cVar2 = *param_1;
  if ((cVar2 == '#') && ((cVar3 = *pcVar1, cVar3 == '#' || (cVar3 == '@')))) {
    param_2[1] = cVar3;
    return 2;
  }
  cVar3 = *pcVar1;
  if (cVar2 != cVar3) {
    if (cVar3 == '=') {
      if (cVar2 < '0') {
        if (((cVar2 != '/') && (cVar2 != '!')) &&
           ((cVar2 < '%' || (('&' < cVar2 && ((cVar2 < '*' || (('+' < cVar2 && (cVar2 != '-'))))))))
           )) {
          return 1;
        }
      }
      else if ((((cVar2 != '<') && (cVar2 != '>')) && (cVar2 != '^')) && (cVar2 != '|')) {
        return 1;
      }
      param_2[1] = '=';
      return 2;
    }
    if (cVar2 != '-') {
      return 1;
    }
    if (cVar3 == '>') {
      param_2[1] = '>';
      return 2;
    }
    return 1;
  }
  if (cVar2 < ';') {
    if ((((cVar2 != ':') && (cVar2 != '&')) && (cVar2 != '+')) && (cVar2 != '-')) {
      if (cVar2 != '.') {
        return 1;
      }
      param_1 = param_1 + 2;
      if (*(char **)(in_ECX + 4) <= param_1) {
        return 1;
      }
      if (*param_1 == '.') {
        param_2[1] = cVar3;
        param_2[2] = *param_1;
        return 3;
      }
      return 1;
    }
  }
  else {
    if (cVar2 == '<') {
LAB_008bd166:
      param_2[1] = cVar3;
      if (*(char **)(in_ECX + 4) <= param_1 + 2) {
        return 2;
      }
      if (param_1[2] == '=') {
        param_2[2] = '=';
        return 3;
      }
      return 2;
    }
    if (cVar2 != '=') {
      if (cVar2 == '>') goto LAB_008bd166;
      if (cVar2 != '|') {
        return 1;
      }
    }
  }
  param_2[1] = cVar3;
  return 2;
}


// ==== FUN_008bd1e3 @ 0x008bd1e3 ====

int FUN_008bd1e3(char *param_1,undefined4 *param_2)

{
  int iVar1;
  int in_ECX;
  char *pcVar2;
  undefined4 uVar3;
  
  uVar3 = 5;
  if (*(char **)(in_ECX + 4) <= param_1) {
    return 0;
  }
  iVar1 = _tolower((int)*param_1);
  if (iVar1 == 0x66) {
    uVar3 = 7;
  }
  else {
    pcVar2 = param_1;
    if (iVar1 != 0x68) goto LAB_008bd219;
    uVar3 = 6;
  }
  pcVar2 = param_1 + 1;
LAB_008bd219:
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar3;
  }
  return (int)pcVar2 - (int)param_1;
}


// ==== FUN_008bd22d @ 0x008bd22d ====

int FUN_008bd22d(char *param_1,undefined4 *param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int in_ECX;
  char *pcVar4;
  
  bVar2 = false;
  bVar1 = false;
  pcVar4 = param_1;
  if (param_1 < *(char **)(in_ECX + 4)) {
    do {
      if (bVar1) {
LAB_008bd268:
        if (bVar2) break;
        iVar3 = _tolower((int)*pcVar4);
        if (iVar3 != 0x6c) break;
        bVar2 = true;
      }
      else {
        iVar3 = _tolower((int)*pcVar4);
        if (iVar3 != 0x75) goto LAB_008bd268;
        bVar1 = true;
      }
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 < *(char **)(in_ECX + 4));
  }
  if (param_2 != (undefined4 *)0x0) {
    if (bVar1) {
      *param_2 = 4;
    }
    else if (bVar2) {
      *param_2 = 3;
    }
  }
  return (int)pcVar4 - (int)param_1;
}


// ==== FUN_008bd2b6 @ 0x008bd2b6 ====

void FUN_008bd2b6(int param_1,uint param_2)

{
  int iVar1;
  int in_ECX;
  uint *puVar2;
  
  iVar1 = FUN_008bcb95(param_1,&param_1);
  if (-1 < iVar1) {
    if (param_2 == 0xff) {
      puVar2 = (uint *)(*(int *)(in_ECX + 0x1c) + param_1 * 4);
      *puVar2 = *puVar2 & 0x20;
      puVar2 = (uint *)(param_1 * 4 + *(int *)(in_ECX + 0x1c));
      *puVar2 = *puVar2 | 1;
    }
    else if (param_2 == 0x10) {
      puVar2 = (uint *)(*(int *)(in_ECX + 0x1c) + param_1 * 4);
      *puVar2 = *puVar2 | 0x10;
    }
    else {
      puVar2 = (uint *)(*(int *)(in_ECX + 0x1c) + param_1 * 4);
      *puVar2 = *puVar2 & 0xfffffff0;
      puVar2 = (uint *)(param_1 * 4 + *(int *)(in_ECX + 0x1c));
      *puVar2 = *puVar2 | param_2 & 0xf;
    }
  }
  return;
}


// ==== FUN_008bd320 @ 0x008bd320 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008bd320(int param_1,int param_2,int param_3,char *param_4,char param_5)

{
  int iVar1;
  size_t sVar2;
  char *_Dest;
  size_t _Count;
  char local_1008 [4096];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  _Dest = local_1008;
  _Count = 0xffe;
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x10) != 0) {
      iVar1 = __snprintf(_Dest,0xffe,&DAT_009d5e14,*(int *)(param_2 + 0x10));
      if (iVar1 < 0) {
        iVar1 = 0xffe;
      }
      _Dest = local_1008 + iVar1;
      _Count = 0xffe - iVar1;
    }
    iVar1 = *(int *)(param_2 + 0x14);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    sVar2 = __snprintf(_Dest,_Count,s___u___00a176c0,iVar1);
    if ((int)sVar2 < 0) {
      sVar2 = _Count;
    }
    _Dest = _Dest + sVar2;
    _Count = _Count - sVar2;
  }
  if (param_3 != 0) {
    sVar2 = __snprintf(_Dest,_Count,s_<error_X_u:_00a176b3 + 1,param_3);
    if ((int)sVar2 < 0) {
      sVar2 = _Count;
    }
    _Dest = _Dest + sVar2;
    _Count = _Count - sVar2;
  }
  sVar2 = __vsnprintf(_Dest,_Count,param_4,&param_5);
  if ((int)sVar2 < 0) {
    sVar2 = _Count;
  }
  _Dest[sVar2] = '\n';
  (_Dest + sVar2)[1] = '\0';
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  FUN_008bcd1b(local_1008);
  return;
}


// ==== FUN_008bd3f7 @ 0x008bd3f7 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008bd3f7(int param_1,int param_2,int param_3,char *param_4,char param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  size_t sVar5;
  char *_Dest;
  size_t _Count;
  char *local_1010;
  int *local_100c;
  char local_1008 [4096];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  _Dest = local_1008;
  _Count = 0xffe;
  iVar2 = FUN_008bcb95(param_3,&local_100c);
  if (-1 < iVar2) {
    iVar2 = (int)local_100c * 4;
    uVar1 = *(uint *)(iVar2 + *(int *)(param_1 + 0x1c));
    uVar3 = uVar1 & 0xf;
    if (uVar3 == 0xf) {
      local_100c = (int *)(param_1 + 8);
      local_1010 = s_error_009fdc5c;
    }
    else {
      local_100c = (int *)(param_1 + 0xc);
      local_1010 = s_warning_00a176d4;
      if ((((*(uint *)(param_1 + 0x10) == 0) || (uVar3 == 0)) || (*(uint *)(param_1 + 0x10) < uVar3)
          ) || (((uVar1 & 0x10) != 0 && ((uVar1 & 0x20) != 0)))) {
        return 0;
      }
      puVar4 = (uint *)(*(int *)(param_1 + 0x1c) + iVar2);
      *puVar4 = *puVar4 | 0x20;
    }
    if (param_2 != 0) {
      if (*(int *)(param_2 + 0x10) != 0) {
        iVar2 = __snprintf(local_1008,0xffe,&DAT_009d5e14,*(int *)(param_2 + 0x10));
        if (iVar2 < 0) {
          iVar2 = 0xffe;
        }
        _Dest = local_1008 + iVar2;
        _Count = 0xffe - iVar2;
      }
      iVar2 = *(int *)(param_2 + 0x14);
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      sVar5 = __snprintf(_Dest,_Count,s___u___00a176c0,iVar2);
      if ((int)sVar5 < 0) {
        sVar5 = _Count;
      }
      _Dest = _Dest + sVar5;
      _Count = _Count - sVar5;
    }
    if (param_3 != 0) {
      sVar5 = __snprintf(_Dest,_Count,s__s_X_u__00a176c8,local_1010,param_3);
      if ((int)sVar5 < 0) {
        sVar5 = _Count;
      }
      _Dest = _Dest + sVar5;
      _Count = _Count - sVar5;
    }
    sVar5 = __vsnprintf(_Dest,_Count,param_4,&param_5);
    if ((int)sVar5 < 0) {
      sVar5 = _Count;
    }
    _Dest[sVar5] = '\n';
    (_Dest + sVar5)[1] = '\0';
    *local_100c = *local_100c + 1;
    iVar2 = FUN_008bcd1b(local_1008);
  }
  return iVar2;
}


// ==== FUN_008bd585 @ 0x008bd585 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008bd585(undefined4 param_1,undefined4 *param_2)

{
  char *pcVar1;
  undefined8 uVar2;
  char local_108 [256];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  switch(*param_2) {
  case 0:
    pcVar1 = s_version_token_00a17798;
    break;
  case 1:
    goto LAB_008bd632;
  case 2:
    pcVar1 = s_integer___u__00a17788;
    goto LAB_008bd637;
  case 3:
    pcVar1 = s_integer___dl__00a17778;
    goto LAB_008bd637;
  case 4:
    pcVar1 = s_integer___uul__00a17768;
    goto LAB_008bd637;
  case 5:
    uVar2 = *(undefined8 *)(param_2 + 2);
    pcVar1 = s_float___g__00a1775c;
    goto LAB_008bd619;
  case 6:
    uVar2 = *(undefined8 *)(param_2 + 2);
    pcVar1 = s_float___gh__00a17750;
    goto LAB_008bd619;
  case 7:
    uVar2 = *(undefined8 *)(param_2 + 2);
    pcVar1 = s_float___gf__00a17744;
    goto LAB_008bd619;
  case 8:
    uVar2 = *(undefined8 *)(param_2 + 2);
    pcVar1 = s_float___gl__00a17738;
LAB_008bd619:
    __snprintf(local_108,0x100,pcVar1,uVar2);
    goto LAB_008bd67b;
  case 9:
LAB_008bd632:
    pcVar1 = s_token___s__00a1772c;
LAB_008bd637:
    __snprintf(local_108,0x100,pcVar1);
    goto LAB_008bd67b;
  case 10:
    pcVar1 = s_string_constant_00a1771c;
    break;
  default:
    pcVar1 = s_token_00a176fc;
    break;
  case 0xc:
    pcVar1 = s_end_of_line_00a17710;
    break;
  case 0xd:
    pcVar1 = s_end_of_file_00a17704;
  }
  __snprintf(local_108,0x100,pcVar1);
LAB_008bd67b:
  FUN_008bd320();
  return;
}


// ==== FUN_008bd6da @ 0x008bd6da ====

undefined4 FUN_008bd6da(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint *in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (*in_ECX < in_ECX[1]) {
    do {
      pcVar3 = (char *)*in_ECX;
      cVar1 = *pcVar3;
      if (cVar1 == '\n') {
        pcVar3 = pcVar3 + 1;
        in_ECX[7] = in_ECX[7] + 1;
        local_8 = 1;
LAB_008bd7ef:
        *in_ECX = (uint)pcVar3;
      }
      else {
        if ((cVar1 == ' ') || (('\b' < cVar1 && (cVar1 < '\x0e')))) {
          pcVar3 = pcVar3 + 1;
          goto LAB_008bd7ef;
        }
        if (cVar1 == '/') {
          if ((pcVar3 + 1 < (char *)in_ECX[1]) && (pcVar3[1] == '/')) goto LAB_008bd738;
          pcVar2 = (char *)in_ECX[1];
          if ((pcVar2 <= pcVar3 + 1) || (pcVar3[1] != '*')) goto LAB_008bd7ac;
          *in_ECX = (uint)(pcVar3 + 2);
          if (pcVar3 + 2 < pcVar2) {
            do {
              pcVar3 = (char *)*in_ECX;
              if (((*pcVar3 == '*') && (pcVar3 + 1 < pcVar2)) && (pcVar3[1] == '/')) break;
              if (*pcVar3 == '\n') {
                in_ECX[7] = in_ECX[7] + 1;
              }
              *in_ECX = (uint)(pcVar3 + 1);
            } while (pcVar3 + 1 < (char *)in_ECX[1]);
          }
          if ((char *)*in_ECX < pcVar2) {
            pcVar3 = (char *)*in_ECX + 2;
            goto LAB_008bd7ef;
          }
          FUN_008bd320(in_ECX[0xc],in_ECX + 2,0x3e9,s_comment_continues_past_end_of_fi_00a177a8);
        }
        else {
LAB_008bd7ac:
          if (((in_ECX[10] & 2) == 0) || (cVar1 != ';')) {
            if (cVar1 != '\\') {
              return local_8;
            }
            if ((pcVar3 + 1 < (char *)in_ECX[1]) && (pcVar3[1] == '\n')) {
              pcVar3 = pcVar3 + 2;
            }
            else {
              if ((char *)in_ECX[1] <= pcVar3 + 2) {
                return local_8;
              }
              if (pcVar3[1] != '\r') {
                return local_8;
              }
              if (pcVar3[2] != '\n') {
                return local_8;
              }
              pcVar3 = pcVar3 + 3;
            }
            in_ECX[7] = in_ECX[7] + 1;
            goto LAB_008bd7ef;
          }
LAB_008bd738:
          FUN_008bce6b();
        }
      }
    } while (*in_ECX < in_ECX[1]);
  }
  return local_8;
}


// ==== FUN_008bd803 @ 0x008bd803 ====

int FUN_008bd803(char *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  char *pcVar4;
  
  pcVar4 = param_1 + 2;
  if ((((*(char **)(in_ECX + 4) <= pcVar4) || (*param_1 != '0')) || (param_1[1] != 'x')) ||
     (iVar2 = _isxdigit((int)*pcVar4), iVar2 == 0)) {
    return 0;
  }
  iVar2 = 0;
  while ((pcVar4 < *(char **)(in_ECX + 4) && (iVar3 = _isxdigit((int)*pcVar4), iVar3 != 0))) {
    cVar1 = *pcVar4;
    iVar2 = iVar2 * 0x10;
    if (cVar1 < 'a') {
      if (cVar1 < 'A') {
        iVar2 = iVar2 + -0x30 + (int)cVar1;
      }
      else {
        iVar2 = iVar2 + -0x37 + (int)cVar1;
      }
    }
    else {
      iVar2 = iVar2 + -0x57 + (int)cVar1;
    }
    pcVar4 = pcVar4 + 1;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar2;
  }
  if (10 < (int)pcVar4 - (int)param_1) {
    FUN_008bd320(*(undefined4 *)(in_ECX + 0x30),in_ECX + 8,0x3ea,
                 s_hex_value_truncated_to_32bits_00a177cc);
  }
  return (int)pcVar4 - (int)param_1;
}


// ==== FUN_008bd8a7 @ 0x008bd8a7 ====

int FUN_008bd8a7(char *param_1,uint *param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  char *pcVar5;
  
  if ((param_1 < *(char **)(in_ECX + 4)) && (*param_1 == '0')) {
    uVar3 = 0;
    bVar2 = false;
    pcVar5 = param_1;
    while (((pcVar5 = pcVar5 + 1, pcVar5 < *(char **)(in_ECX + 4) && (cVar1 = *pcVar5, '/' < cVar1))
           && (cVar1 < '8'))) {
      if ((uVar3 & 0xe0000000) != 0) {
        bVar2 = true;
      }
      uVar3 = cVar1 + -0x30 + uVar3 * 8;
    }
    if (param_2 != (uint *)0x0) {
      *param_2 = uVar3;
    }
    if (bVar2) {
      FUN_008bd320(*(undefined4 *)(in_ECX + 0x30),in_ECX + 8,0x3eb,
                   s_octal_value_truncated_to_32bits_00a177ec);
    }
    iVar4 = (int)pcVar5 - (int)param_1;
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}


// ==== FUN_008bd925 @ 0x008bd925 ====

int FUN_008bd925(char *param_1,uint *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  char *pcVar4;
  uint uVar5;
  
  if ((*(char **)(in_ECX + 4) <= param_1) || (iVar2 = _isdigit((int)*param_1), iVar2 == 0)) {
    return 0;
  }
  uVar5 = 0;
  bVar1 = false;
  pcVar4 = param_1;
  if (param_1 < *(char **)(in_ECX + 4)) {
    do {
      iVar2 = _isdigit((int)*pcVar4);
      if (iVar2 == 0) break;
      if (0x19999999 < uVar5) {
        bVar1 = true;
      }
      uVar3 = uVar5 * 10;
      uVar5 = *pcVar4 + -0x30 + uVar3;
      if (uVar5 < uVar3) {
        bVar1 = true;
      }
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 < *(char **)(in_ECX + 4));
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar5;
  }
  if (bVar1) {
    FUN_008bd320(*(undefined4 *)(in_ECX + 0x30),in_ECX + 8,0x3ec,
                 s_decimal_value_truncated_to_32bit_00a1780c);
  }
  return (int)pcVar4 - (int)param_1;
}


// ==== FUN_008bd9c8 @ 0x008bd9c8 ====

int FUN_008bd9c8(char *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (*(char **)(in_ECX + 4) <= param_1) {
    return 0;
  }
  cVar1 = *param_1;
  if ((cVar1 == '\\') && ((*(byte *)(in_ECX + 0x28) & 4) == 0)) {
    pcVar4 = param_1 + 1;
    if (*(char **)(in_ECX + 4) <= pcVar4) {
      FUN_008bd320(*(undefined4 *)(in_ECX + 0x30),in_ECX + 8,0x3ef,
                   s_character_continues_past_end_of_f_00a17830);
    }
    cVar1 = *pcVar4;
    if (cVar1 == 'a') {
      *param_2 = 7;
    }
    else if (cVar1 == 'b') {
      *param_2 = 8;
    }
    else if (cVar1 == 'f') {
      *param_2 = 0xc;
    }
    else if (cVar1 == 'n') {
      *param_2 = 10;
    }
    else if (cVar1 == 'r') {
      *param_2 = 0xd;
    }
    else if (cVar1 == 't') {
      *param_2 = 9;
    }
    else {
      if (cVar1 != 'v') {
        if (('/' < cVar1) && (cVar1 < '8')) {
          pcVar5 = *(char **)(in_ECX + 4);
          if (param_1 + 4 < *(char **)(in_ECX + 4)) {
            pcVar5 = param_1 + 4;
          }
          iVar3 = 0;
          for (; ((pcVar4 < pcVar5 && (cVar1 = *pcVar4, '/' < cVar1)) && (cVar1 < '8'));
              pcVar4 = pcVar4 + 1) {
            iVar3 = cVar1 + -0x30 + iVar3 * 8;
          }
          *param_2 = iVar3;
          pcVar5 = pcVar4;
          goto LAB_008bdb56;
        }
        if ((cVar1 == 'x') &&
           ((pcVar5 = param_1 + 2, pcVar5 < *(char **)(in_ECX + 4) &&
            (iVar3 = _isxdigit((int)*pcVar5), iVar3 != 0)))) {
          iVar3 = 0;
          while ((pcVar5 < *(char **)(in_ECX + 4) && (iVar2 = _isxdigit((int)*pcVar5), iVar2 != 0)))
          {
            cVar1 = *pcVar5;
            iVar3 = iVar3 * 0x10;
            if (cVar1 < 'a') {
              if (cVar1 < 'A') {
                iVar3 = iVar3 + -0x30 + (int)cVar1;
              }
              else {
                iVar3 = iVar3 + -0x37 + (int)cVar1;
              }
            }
            else {
              iVar3 = iVar3 + -0x57 + (int)cVar1;
            }
            pcVar5 = pcVar5 + 1;
          }
          *param_2 = iVar3;
          goto LAB_008bdb56;
        }
        cVar1 = *pcVar4;
        pcVar5 = param_1 + 2;
        goto LAB_008bdb51;
      }
      *param_2 = 0xb;
    }
    pcVar5 = param_1 + 2;
  }
  else {
    pcVar5 = param_1 + 1;
LAB_008bdb51:
    *param_2 = (int)cVar1;
  }
LAB_008bdb56:
  return (int)pcVar5 - (int)param_1;
}


// ==== FUN_008bdb61 @ 0x008bdb61 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_008bdb61(char *param_1,undefined4 *param_2)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 local_40 [4];
  undefined4 local_3c;
  char *local_34;
  undefined4 *local_30;
  uint local_2c;
  char local_28 [4];
  char acStack_24 [28];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_34 = param_1;
  local_30 = param_2;
  if ((*(byte *)(in_ECX + 0x28) & 2) == 0) {
    return (char *)0x0;
  }
  if ((((param_1 + 1 < *(char **)(in_ECX + 4)) && (iVar1 = _isalpha((int)*param_1), iVar1 != 0)) &&
      (iVar1 = _isalpha((int)param_1[1]), iVar1 != 0)) &&
     ((param_1 + 2 < *(char **)(in_ECX + 4) && (param_1[2] == '.')))) {
    iVar1 = FUN_008bd925(param_1 + 3,&local_2c);
    if (((iVar1 != 0) &&
        ((local_2c < 0x100 && (pcVar4 = param_1 + 3 + iVar1, pcVar4 < *(char **)(in_ECX + 4))))) &&
       (*pcVar4 == '.')) {
      pcVar4 = pcVar4 + 1;
      iVar1 = FUN_008bd925(pcVar4,&local_2c);
      if (iVar1 == 0) {
        iVar1 = FUN_008bd051(pcVar4,&local_2c);
        if (iVar1 == 0) {
          return (char *)0x0;
        }
        local_2c = 0;
      }
      if ((local_2c < 0x100) && (pcVar4 = pcVar4 + (iVar1 - (int)local_34), pcVar4 < (char *)0x20))
      {
        pcVar3 = local_34;
        pcVar5 = local_28;
        for (uVar2 = (uint)pcVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined4 *)pcVar5 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar5 = pcVar5 + 4;
        }
        for (uVar2 = (uint)pcVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *pcVar5 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        }
        local_28[(int)pcVar4] = '\0';
        iVar1 = FUN_008f31ff(local_28,1,local_40);
        if (-1 < iVar1) {
          *local_30 = local_3c;
          return pcVar4;
        }
      }
    }
  }
  return (char *)0x0;
}


// ==== FUN_008bdc7f @ 0x008bdc7f ====

char * FUN_008bdc7f(char *param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  char *pcVar2;
  
  if ((param_1 < *(char **)(in_ECX + 4)) && (*param_1 == '\'')) {
    iVar1 = FUN_008bd9c8(param_1 + 1,param_2);
    if ((iVar1 != 0) &&
       ((pcVar2 = param_1 + 1 + iVar1, pcVar2 < *(char **)(in_ECX + 4) && (*pcVar2 == '\'')))) {
      return pcVar2 + (1 - (int)param_1);
    }
  }
  return (char *)0x0;
}


// ==== FUN_008bdcc2 @ 0x008bdcc2 ====

int FUN_008bdcc2(char *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  int in_ECX;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 uVar10;
  
  pcVar2 = param_1;
  if (*(char **)(in_ECX + 4) <= param_1) {
    return 0;
  }
  if (*param_1 == '\"') {
    param_1._3_1_ = '\"';
  }
  else {
    if (*param_1 != '<') {
      return 0;
    }
    if ((*(byte *)(in_ECX + 0x28) & 8) == 0) {
      return 0;
    }
    param_1._3_1_ = '>';
  }
  pcVar9 = pcVar2 + 1;
  pcVar8 = pcVar9;
  if (pcVar9 < *(char **)(in_ECX + 4)) {
    pcVar6 = pcVar2 + 2;
    do {
      cVar1 = *pcVar8;
      if ((param_1._3_1_ == cVar1) || (cVar1 == '\n')) break;
      pcVar5 = pcVar6;
      pcVar7 = pcVar8;
      if ((cVar1 == '\\') && ((*(byte *)(in_ECX + 0x28) & 4) == 0)) {
        pcVar7 = pcVar8 + 1;
        pcVar5 = pcVar6 + 1;
        if (pcVar7 < *(char **)(in_ECX + 4)) {
          if (*pcVar7 != '\n') {
            if (((*pcVar7 != '\r') || (*(char **)(in_ECX + 4) <= pcVar5)) || (*pcVar5 != '\n'))
            goto LAB_008bdd40;
            pcVar7 = pcVar8 + 2;
            pcVar5 = pcVar6 + 2;
          }
          *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
        }
      }
LAB_008bdd40:
      pcVar8 = pcVar7 + 1;
      pcVar6 = pcVar5 + 1;
    } while (pcVar8 < *(char **)(in_ECX + 4));
  }
  if (pcVar8 < *(char **)(in_ECX + 4)) {
    if (*pcVar8 != '\n') goto LAB_008bdd7a;
    pcVar6 = s_string_continues_past_end_of_lin_00a17858;
    uVar10 = 0x3ed;
  }
  else {
    pcVar6 = s_string_continues_past_end_of_fil_00a1787c;
    uVar10 = 0x3ee;
    pcVar8 = *(char **)(in_ECX + 4);
  }
  FUN_008bd320(*(undefined4 *)(in_ECX + 0x30),in_ECX + 8,uVar10,pcVar6);
LAB_008bdd7a:
  puVar3 = (undefined1 *)FUN_008f33e7((int)pcVar8 - (int)pcVar2,1);
  if (puVar3 == (undefined1 *)0x0) {
    return 0;
  }
  *param_2 = puVar3;
  do {
    pcVar6 = pcVar9 + 1;
    if (pcVar6 < pcVar8) {
      pcVar5 = pcVar9 + 2;
      do {
        if ((*pcVar9 != '\\') || ((*(byte *)(in_ECX + 0x28) & 4) != 0)) break;
        if (*pcVar6 == '\n') {
          pcVar9 = pcVar9 + 2;
          pcVar5 = pcVar5 + 2;
          pcVar6 = pcVar6 + 2;
        }
        else {
          if (((*pcVar6 != '\r') || (pcVar8 <= pcVar5)) || (*pcVar5 != '\n')) break;
          pcVar9 = pcVar9 + 3;
          pcVar5 = pcVar5 + 3;
          pcVar6 = pcVar6 + 3;
        }
      } while (pcVar6 < pcVar8);
    }
    if (pcVar8 <= pcVar9) {
      *puVar3 = 0;
      return ((int)pcVar8 - (int)pcVar2) + 1;
    }
    iVar4 = FUN_008bd9c8(pcVar9,&param_2);
    pcVar9 = pcVar9 + iVar4;
    *puVar3 = param_2._0_1_;
    puVar3 = puVar3 + 1;
  } while( true );
}


// ==== FUN_008bde0c @ 0x008bde0c ====

undefined4 FUN_008bde0c(int param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int *in_ECX;
  int iVar4;
  
  in_ECX[10] = param_1;
  param_2[4] = in_ECX[6];
  iVar4 = 0;
  param_2[5] = in_ECX[7];
  iVar3 = FUN_008bd6da();
  if (iVar3 != 0) {
    *param_2 = 0xc;
    goto LAB_008bdfbc;
  }
  param_2[4] = in_ECX[6];
  param_2[5] = in_ECX[7];
  pcVar2 = (char *)*in_ECX;
  if ((char *)in_ECX[1] <= pcVar2) {
    *param_2 = 0xd;
    goto LAB_008bdfbc;
  }
  cVar1 = *pcVar2;
  if (((cVar1 < '0') || ('9' < cVar1)) && (cVar1 != '.')) {
    if (cVar1 == '\'') {
      iVar4 = FUN_008bdc7f(pcVar2,param_2 + 2);
      if (iVar4 != 0) {
        *param_2 = 2;
        goto LAB_008bdfbc;
      }
    }
    else if (cVar1 == '\"') {
      iVar4 = FUN_008bdcc2(pcVar2,param_2 + 2);
      if (iVar4 != 0) {
        *param_2 = 10;
        goto LAB_008bdfbc;
      }
    }
    else if (((*(byte *)(in_ECX + 10) & 4) == 0) || (cVar1 != '<')) {
      iVar3 = _isalpha((int)cVar1);
      if ((iVar3 != 0) || (*(char *)*in_ECX == '_')) {
        if (((*(byte *)(in_ECX + 10) & 2) != 0) &&
           (iVar4 = FUN_008bdb61(*in_ECX,param_2 + 2), iVar4 != 0)) {
          *param_2 = 0;
          goto LAB_008bdfbc;
        }
        iVar4 = FUN_008bd051(*in_ECX,param_2 + 2);
        if (iVar4 != 0) {
          *param_2 = 9;
          goto LAB_008bdfbc;
        }
      }
    }
    else {
      iVar4 = FUN_008bdcc2(pcVar2,param_2 + 2);
      if (iVar4 != 0) {
        *param_2 = 0xb;
        goto LAB_008bdfbc;
      }
    }
LAB_008bdfa7:
    iVar4 = FUN_008bd0d5(*in_ECX,param_2 + 2);
    *param_2 = 1;
  }
  else {
    iVar4 = FUN_008bcec6(pcVar2,param_2 + 2);
    if (iVar4 == 0) {
      iVar4 = FUN_008bd803(*in_ECX,param_2 + 2);
      if (((iVar4 == 0) && (iVar4 = FUN_008bd8a7(*in_ECX,param_2 + 2), iVar4 == 0)) &&
         (iVar4 = FUN_008bd925(*in_ECX,param_2 + 2), iVar4 == 0)) goto LAB_008bdfa7;
      *param_2 = 2;
      iVar3 = FUN_008bd22d(*in_ECX + iVar4,param_2);
    }
    else {
      *param_2 = 5;
      iVar3 = FUN_008bd1e3(*in_ECX + iVar4,param_2);
    }
    iVar4 = iVar4 + iVar3;
  }
LAB_008bdfbc:
  param_2[6] = *in_ECX;
  param_2[7] = iVar4;
  *in_ECX = *in_ECX + iVar4;
  return 0;
}


// ==== FUN_008bdfcf @ 0x008bdfcf ====

void FUN_008bdfcf(void)

{
  LONG LVar1;
  
  while( true ) {
    LVar1 = InterlockedCompareExchange((LONG *)&DAT_00b5eae4,1,0);
    if (LVar1 != 1) break;
    Sleep(1);
  }
  if (DAT_00b5eae0 == 0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00b5eac8);
  }
  DAT_00b5eae0 = DAT_00b5eae0 + 1;
  InterlockedExchange((LONG *)&DAT_00b5eae4,0);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00b5eac8);
  return;
}


// ==== FUN_008be024 @ 0x008be024 ====

void FUN_008be024(void)

{
  LONG LVar1;
  
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00b5eac8);
  while( true ) {
    LVar1 = InterlockedCompareExchange((LONG *)&DAT_00b5eae4,1,0);
    if (LVar1 != 1) break;
    Sleep(1);
  }
  DAT_00b5eae0 = DAT_00b5eae0 + -1;
  if (DAT_00b5eae0 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00b5eac8);
  }
  InterlockedExchange((LONG *)&DAT_00b5eae4,0);
  return;
}


// ==== FUN_008be075 @ 0x008be075 ====

void FUN_008be075(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  return;
}


// ==== FUN_008be099 @ 0x008be099 ====

void FUN_008be099(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  return;
}


// ==== FUN_008be0b7 @ 0x008be0b7 ====

void FUN_008be0b7(void)

{
  void *_Memory;
  int in_ECX;
  
  _Memory = *(void **)(in_ECX + 0xc);
  if (_Memory == (void *)0x0) {
    return;
  }
  FUN_008be0b7();
  _free(_Memory);
  return;
}


// ==== FUN_008be0d1 @ 0x008be0d1 ====

void FUN_008be0d1(byte param_1)

{
  void *in_ECX;
  
  FUN_008be0b7();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008be0f2 @ 0x008be0f2 ====

void FUN_008be0f2(void)

{
  int in_ECX;
  
  FUN_008bcde7();
  FUN_008b64c2();
  FUN_008a68b8();
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  return;
}


// ==== FUN_008be127 @ 0x008be127 ====

void FUN_008be127(void)

{
  void *_Memory;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) != 0) {
    FUN_008be0d1(1);
  }
  _Memory = *(void **)(in_ECX + 0x6c);
  if (_Memory != (void *)0x0) {
    FUN_008be127();
    _free(_Memory);
    return;
  }
  if ((*(int *)(in_ECX + 0x58) != 0) && (*(int *)(in_ECX + 100) != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x58) + 4))(*(int **)(in_ECX + 0x58),*(int *)(in_ECX + 100));
  }
  FUN_008b67ae();
  FUN_008b67a3();
  FUN_0095cf1d();
  return;
}


// ==== FUN_008be180 @ 0x008be180 ====

void FUN_008be180(byte param_1)

{
  void *in_ECX;
  
  FUN_008be127();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008be1a1 @ 0x008be1a1 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_008be1a1(LPCWSTR param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8)

{
  char *pcVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  undefined4 *puVar4;
  DWORD nBufferLength;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  LPSTR local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  uint local_114;
  WCHAR *local_110;
  WCHAR local_10c [130];
  undefined4 local_8;
  
  local_118 = param_3;
  local_120 = param_4;
  local_8 = DAT_00b49670;
  local_11c = param_5;
  local_110 = param_1;
  local_114 = param_8;
  *(int *)(in_ECX + 0x58) = param_6;
  if (param_2 != 0) {
    WideCharToMultiByte(0xfde9,0,param_1,-1,(LPSTR)local_10c,0x104,(LPCSTR)0x0,(LPBOOL)0x0);
    local_110 = local_10c;
  }
  if (param_6 == 0) {
    nBufferLength = GetFullPathNameA((LPCSTR)local_110,0,(LPSTR)0x0,(LPSTR *)0x0);
    local_114 = nBufferLength + 1;
    iVar5 = FUN_008f33e7(local_114,1);
    *(int *)(in_ECX + 0x60) = iVar5;
    if (iVar5 != 0) {
      iVar5 = FUN_008f33e7(local_114,1);
      *(int *)(in_ECX + 0x5c) = iVar5;
      if (iVar5 != 0) {
        GetFullPathNameA((LPCSTR)local_110,nBufferLength,*(LPSTR *)(in_ECX + 0x60),&local_124);
        *(undefined1 *)(nBufferLength + *(int *)(in_ECX + 0x60)) = 0;
        puVar4 = *(undefined4 **)(in_ECX + 0x60);
        puVar7 = *(undefined4 **)(in_ECX + 0x5c);
        for (uVar6 = local_114 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar7 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar6 = local_114 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar4;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        if (local_124 != (LPSTR)0x0) {
          *local_124 = '\0';
        }
        uVar6 = FUN_008b64d4(*(undefined4 *)(in_ECX + 0x5c),0);
        if ((int)uVar6 < 0) {
          FUN_008bd320(local_11c,local_120,0x5e3,s_failed_to_open_source_file____s__00a178a4,
                       local_110);
          return uVar6;
        }
        *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(in_ECX + 0x44);
        *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(in_ECX + 0x48);
        goto LAB_008be3a4;
      }
    }
  }
  else {
    pWVar3 = local_110;
    do {
      WVar2 = *pWVar3;
      pWVar3 = (WCHAR *)((int)pWVar3 + 1);
    } while ((char)WVar2 != '\0');
    pcVar1 = (char *)((int)pWVar3 + (1 - ((int)local_110 + 1)));
    puVar4 = (undefined4 *)FUN_008f33e7(pcVar1,1);
    *(undefined4 **)(in_ECX + 0x5c) = puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      pWVar3 = local_110;
      for (uVar6 = (uint)pcVar1 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar4 = *(undefined4 *)pWVar3;
        pWVar3 = pWVar3 + 2;
        puVar4 = puVar4 + 1;
      }
      for (uVar6 = (uint)pcVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(char *)puVar4 = (char)*pWVar3;
        pWVar3 = (WCHAR *)((int)pWVar3 + 1);
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      local_114 = (**(code **)**(undefined4 **)(in_ECX + 0x58))
                            (*(undefined4 **)(in_ECX + 0x58),param_7,*(undefined4 *)(in_ECX + 0x5c),
                             local_114,in_ECX + 100,in_ECX + 0x68);
      if ((int)local_114 < 0) {
        FUN_008bd320(local_11c,local_120,0x5e3,s_failed_to_open_source_file____s__00a178a4,local_110
                    );
        return local_114;
      }
LAB_008be3a4:
      uVar6 = FUN_008bce01(*(undefined4 *)(in_ECX + 100),*(undefined4 *)(in_ECX + 0x68),
                           *(undefined4 *)(in_ECX + 0x5c),1,local_118,local_11c);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      return 0;
    }
  }
  return 0x8007000e;
}


// ==== FUN_008be3d5 @ 0x008be3d5 ====

int FUN_008be3d5(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int in_ECX;
  
  if ((param_2 == 0) || (param_1 != 0)) {
    *(int *)(in_ECX + 100) = param_1;
    *(int *)(in_ECX + 0x68) = param_2;
    iVar1 = FUN_008bce01(param_1,param_2,0,1,param_3,param_4);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = -0x7789f794;
  }
  return iVar1;
}


// ==== FUN_008be410 @ 0x008be410 ====

void FUN_008be410(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = 0;
  *in_ECX = param_1;
  in_ECX[2] = 1;
  return;
}


// ==== FUN_008be42b @ 0x008be42b ====

void FUN_008be42b(void)

{
  void *_Memory;
  int in_ECX;
  
  _Memory = *(void **)(in_ECX + 4);
  if (_Memory == (void *)0x0) {
    return;
  }
  FUN_008be42b();
  _free(_Memory);
  return;
}


// ==== FUN_008be445 @ 0x008be445 ====

void FUN_008be445(byte param_1)

{
  void *in_ECX;
  
  FUN_008be42b();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008be466 @ 0x008be466 ====

void FUN_008be466(void)

{
  void *_Memory;
  int in_ECX;
  
  _Memory = *(void **)(in_ECX + 0x28);
  if (_Memory == (void *)0x0) {
    return;
  }
  FUN_008be466();
  _free(_Memory);
  return;
}


// ==== FUN_008be480 @ 0x008be480 ====

void FUN_008be480(byte param_1)

{
  void *in_ECX;
  
  FUN_008be466();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008be4a1 @ 0x008be4a1 ====

undefined4 FUN_008be4a1(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined8 uVar4;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    uVar4 = FUN_008be410(param_1);
    param_1 = (undefined4)((ulonglong)uVar4 >> 0x20);
    iVar2 = (int)uVar4;
  }
  if (iVar2 == 0) {
    uVar3 = 0x8007000e;
  }
  else {
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(in_ECX + 0x68);
    *(int *)(in_ECX + 0x68) = iVar2;
    *(undefined4 *)(in_ECX + 0x298) = param_1;
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_008be4e5 @ 0x008be4e5 ====

undefined4 FUN_008be4e5(undefined4 *param_1,undefined4 *param_2)

{
  int in_ECX;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)(*(int *)(in_ECX + 0x26c) + 0x18);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(*(int *)(in_ECX + 0x26c) + 0x1c);
  }
  return 0;
}


// ==== FUN_008be514 @ 0x008be514 ====

undefined4 FUN_008be514(uint *param_1,int *param_2)

{
  uint *puVar1;
  int in_ECX;
  
  puVar1 = *(uint **)(in_ECX + 0x268);
  while ((uint *)puVar1[0x1b] != (uint *)0x0) {
    puVar1 = (uint *)puVar1[0x1b];
  }
  if (param_1 != (uint *)0x0) {
    *param_1 = *puVar1;
  }
  if (param_2 != (int *)0x0) {
    if (puVar1[1] < *puVar1) {
      *param_2 = 0;
    }
    else {
      *param_2 = puVar1[1] - *puVar1;
    }
  }
  return 0;
}


// ==== FUN_008be554 @ 0x008be554 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008be554(int param_1,char *param_2,char param_3)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  char local_108 [255];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  *(undefined4 *)(param_1 + 0x44) = 1;
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar1 = 0xd;
    bVar4 = true;
    pcVar2 = param_2;
    pcVar3 = s_syntax_error_009fea30;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      if ((*(int *)(param_1 + 0x4c) == 0) || (*(int *)(param_1 + 0x278) != 9)) {
        FUN_008bd585(0x5dc,param_1 + 0x278);
      }
      else {
        FUN_008bd320(param_1 + 0x18,(int *)(param_1 + 0x278),0x5e0,
                     s_invalid_preprocessor_command___s_00a178c8,*(undefined4 *)(param_1 + 0x280));
      }
    }
    else {
      __vsnprintf(local_108,0x100,param_2,&param_3);
      local_9 = 0;
      FUN_008bd320(param_1 + 0x18,param_1 + 0x278,0,&DAT_009d5e14,local_108);
    }
  }
  return;
}


// ==== FUN_008be61e @ 0x008be61e ====

undefined4 FUN_008be61e(undefined4 param_1,int param_2)

{
  int *piVar1;
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 0x26c) + 0x1c) = param_1;
  if (*(int *)(in_ECX + 0x278) != 0xc) {
    piVar1 = (int *)(*(int *)(in_ECX + 0x26c) + 0x1c);
    *piVar1 = *piVar1 + -1;
  }
  if (param_2 != 0) {
    *(int *)(*(int *)(in_ECX + 0x26c) + 0x18) = param_2;
  }
  return 0;
}


// ==== FUN_008be657 @ 0x008be657 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008be657(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  void *pvVar4;
  int in_ECX;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  undefined4 uVar8;
  char *pcVar9;
  LPSTR local_220;
  undefined4 local_21c;
  int local_218;
  byte *local_214;
  char local_210 [260];
  byte local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  iVar2 = FUN_008bde0c(*(uint *)(in_ECX + 0x298) | 0xc,(int *)(in_ECX + 0x278));
  uVar5 = 0;
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = *(int *)(in_ECX + 0x278);
  if (iVar2 == 10) {
    local_218 = 0;
  }
  else {
    if (iVar2 != 0xb) {
      FUN_008be554();
      return -0x7fffbffb;
    }
    local_218 = 1;
  }
  local_214 = *(byte **)(in_ECX + 0x280);
  if ((*(int *)(in_ECX + 0x270) == 0) && (*(int *)(*(int *)(in_ECX + 0x26c) + 0x18) == 0)) {
    pcVar9 = s_include_interface_required_to_su_00a17908;
    uVar8 = 0x5e1;
LAB_008be71d:
    FUN_008bd320(in_ECX + 0x18,in_ECX + 0x278,uVar8,pcVar9);
    *(undefined4 *)(in_ECX + 0x48) = 1;
    *(undefined4 *)(in_ECX + 0x44) = 1;
    return -0x7fffbffb;
  }
  iVar2 = *(int *)(in_ECX + 0x268);
  if (iVar2 != 0) {
    do {
      iVar2 = *(int *)(iVar2 + 0x6c);
      uVar5 = uVar5 + 1;
    } while (iVar2 != 0);
    if (0x1f < uVar5) {
      pcVar9 = s_too_many_nested__includes_00a178ec;
      uVar8 = 0x5e2;
      goto LAB_008be71d;
    }
  }
  if (*(int *)(in_ECX + 0x270) == 0) {
    GetFullPathNameA((LPCSTR)local_214,0x104,(LPSTR)local_10c,&local_220);
    pbVar3 = local_10c;
    pbVar6 = local_214;
    do {
      bVar1 = *pbVar6;
      bVar7 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) {
LAB_008be78a:
        iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_008be78f;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar6[1];
      bVar7 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) goto LAB_008be78a;
      pbVar6 = pbVar6 + 2;
      pbVar3 = pbVar3 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_008be78f:
    if (iVar2 != 0) {
      __snprintf(local_210,0x104,&DAT_009ff01c,*(undefined4 *)(*(int *)(in_ECX + 0x268) + 0x60),
                 local_214);
      GetFullPathNameA(local_210,0x104,(LPSTR)local_10c,&local_220);
    }
    local_214 = local_10c;
  }
  iVar2 = *(int *)(in_ECX + 0x268);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x58) == 0)) {
    local_21c = 0;
  }
  else {
    local_21c = *(undefined4 *)(iVar2 + 100);
  }
  pvVar4 = operator_new(0x70);
  if (pvVar4 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_008be0f2();
  }
  if (iVar2 == 0) {
    return -0x7ff8fff2;
  }
  local_218 = FUN_008be1a1(local_214,0,in_ECX,in_ECX + 0x278,in_ECX + 0x18,
                           *(undefined4 *)(in_ECX + 0x270),local_218,local_21c);
  if (local_218 < 0) {
    *(undefined4 *)(in_ECX + 0x48) = 1;
    *(undefined4 *)(in_ECX + 0x44) = 1;
    FUN_008be180(1);
    return local_218;
  }
  *(undefined4 *)(iVar2 + 0x6c) = *(undefined4 *)(in_ECX + 0x268);
  *(int *)(in_ECX + 0x268) = iVar2;
  return 0;
}


// ==== FUN_008be893 @ 0x008be893 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008be893(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int in_ECX;
  char *pcVar4;
  char *pcVar5;
  uint local_10c;
  char local_108 [256];
  undefined4 local_8;
  
  pcVar5 = (char *)**(undefined4 **)(in_ECX + 0x26c);
  local_8 = DAT_00b49670;
  FUN_008bce6b();
  if (*(int *)(in_ECX + 0x50) != 0) {
    for (; (pcVar5 < (char *)**(uint **)(in_ECX + 0x26c) && ((*pcVar5 == ' ' || (*pcVar5 == '\t'))))
        ; pcVar5 = pcVar5 + 1) {
    }
    local_10c = 0;
    pcVar4 = pcVar5 + 2;
    pcVar3 = pcVar5 + 1;
    do {
      pcVar2 = (char *)**(undefined4 **)(in_ECX + 0x26c);
      if (pcVar2 <= pcVar5) break;
      cVar1 = *pcVar5;
      if (cVar1 == '\\') {
        if ((pcVar3 < pcVar2) && (*pcVar3 == '\n')) {
          pcVar5 = pcVar5 + 2;
          pcVar3 = pcVar3 + 2;
          pcVar4 = pcVar4 + 2;
        }
        else {
          if ((pcVar2 <= pcVar4) || ((*pcVar3 != '\r' || (*pcVar4 != '\n')))) goto LAB_008be928;
          pcVar5 = pcVar5 + 3;
          pcVar3 = pcVar3 + 3;
          pcVar4 = pcVar4 + 3;
        }
      }
      else {
LAB_008be928:
        if (cVar1 != '\r') {
          local_108[local_10c] = cVar1;
          local_10c = local_10c + 1;
        }
        pcVar5 = pcVar5 + 1;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      }
    } while (local_10c < 0xff);
    local_108[local_10c] = '\0';
    FUN_008bd320(in_ECX + 0x18,in_ECX + 0x278,0,s_error___s_00a17950,local_108);
    *(undefined4 *)(in_ECX + 0x48) = 1;
    *(undefined4 *)(in_ECX + 0x44) = 1;
  }
  return 0;
}


// ==== FUN_008be996 @ 0x008be996 ====

undefined4 FUN_008be996(int param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_008be099(param_1,*(undefined4 *)(in_ECX + 0x50));
  }
  if (iVar2 == 0) {
    uVar3 = 0x8007000e;
  }
  else {
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(in_ECX + 0x268) + 0x38);
    *(int *)(*(int *)(in_ECX + 0x268) + 0x38) = iVar2;
    if ((*(int *)(in_ECX + 0x50) == 0) || (param_1 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    *(undefined4 *)(in_ECX + 0x54) = uVar3;
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_008be9f6 @ 0x008be9f6 ====

undefined4 FUN_008be9f6(int param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 uVar2;
  char *pcVar3;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x268) + 0x38);
  if (piVar1 == (int *)0x0) {
    pcVar3 = s_unexpected__elif_00a17980;
    uVar2 = 0x5e4;
  }
  else {
    if (piVar1[2] == 0) {
      if (((param_1 == 0) || (*piVar1 != 0)) || (piVar1[1] == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      *(undefined4 *)(in_ECX + 0x54) = uVar2;
      if (param_1 != 0) {
        *piVar1 = 1;
      }
      return 0;
    }
    pcVar3 = s_unexpected__elif_following__else_00a1795c;
    uVar2 = 0x5e9;
  }
  FUN_008bd320(in_ECX + 0x18,in_ECX + 0x278,uVar2,pcVar3);
  *(undefined4 *)(in_ECX + 0x44) = 1;
  return 0x80004005;
}


// ==== FUN_008bea73 @ 0x008bea73 ====

undefined4 FUN_008bea73(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 uVar2;
  char *pcVar3;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x268) + 0x38);
  uVar2 = 0;
  if (piVar1 == (int *)0x0) {
    pcVar3 = s_unexpected__else_00a179b8;
    uVar2 = 0x5e5;
  }
  else {
    if (piVar1[2] == 0) {
      if ((*piVar1 == 0) && (piVar1[1] != 0)) {
        uVar2 = 1;
      }
      *(undefined4 *)(in_ECX + 0x54) = uVar2;
      *piVar1 = 1;
      piVar1[2] = 1;
      return 0;
    }
    pcVar3 = s_unexpected__else_following__else_00a17994;
    uVar2 = 0x5ea;
  }
  FUN_008bd320(in_ECX + 0x18,in_ECX + 0x278,uVar2,pcVar3);
  *(undefined4 *)(in_ECX + 0x44) = 1;
  return 0x80004005;
}


// ==== FUN_008beadd @ 0x008beadd ====

undefined4 FUN_008beadd(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x268) + 0x38);
  if (iVar1 == 0) {
    FUN_008bd320(in_ECX + 0x18,in_ECX + 0x278,0x5e6,s_unexpected__endif_00a179cc);
    *(undefined4 *)(in_ECX + 0x44) = 1;
    return 0x80004005;
  }
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(iVar1 + 4);
  *(undefined4 *)(*(int *)(in_ECX + 0x268) + 0x38) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(iVar1 + 0xc) = 0;
  FUN_008be0d1(1);
  return 0;
}


// ==== FUN_008beb35 @ 0x008beb35 ====

int FUN_008beb35(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  char *local_8;
  
  iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
  if (iVar2 < 0) goto LAB_008bec69;
  iVar2 = *(int *)(in_ECX + 0x278);
  if (iVar2 == 1) {
    iVar3 = 2;
    bVar6 = true;
    pcVar4 = (char *)(in_ECX + 0x280);
    pcVar5 = &DAT_00a179fc;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) goto LAB_008bec51;
    piVar1 = (int *)(in_ECX + 0x278);
    iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),piVar1);
    if (iVar2 < 0) goto LAB_008bec69;
    if (*piVar1 == 9) {
      local_8 = *(char **)(in_ECX + 0x280);
      iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),piVar1);
      if (iVar2 < 0) goto LAB_008bec69;
    }
    else {
      local_8 = (char *)0x0;
    }
    iVar2 = *piVar1;
    if (iVar2 != 1) goto LAB_008bec51;
    iVar3 = 2;
    bVar6 = true;
    pcVar4 = (char *)(in_ECX + 0x280);
    pcVar5 = &DAT_00a00254;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) goto LAB_008bec51;
    iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
    if (iVar2 < 0) goto LAB_008bec69;
    iVar2 = *(int *)(in_ECX + 0x278);
    if ((iVar2 != 0xc) && (iVar2 != 0xd)) goto LAB_008bec51;
    if (local_8 == (char *)0x0) {
      *(undefined4 *)(in_ECX + 0x38) = 0;
    }
    else {
      iVar3 = 10;
      bVar6 = true;
      pcVar4 = local_8;
      pcVar5 = s_row_major_00a179f0;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        *(undefined4 *)(in_ECX + 0x38) = 0x400;
      }
      else {
        iVar3 = 0xd;
        bVar6 = true;
        pcVar4 = s_column_major_00a179e0;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar6 = *local_8 == *pcVar4;
          local_8 = local_8 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar6);
        if (!bVar6) goto LAB_008bec51;
        *(undefined4 *)(in_ECX + 0x38) = 0x800;
      }
    }
  }
  else {
LAB_008bec51:
    if ((iVar2 != 0xc) && (iVar2 != 0xd)) {
      FUN_008bce6b();
    }
  }
  iVar2 = 0;
LAB_008bec69:
  *(undefined4 *)(in_ECX + 0x40) = 1;
  return iVar2;
}


// ==== FUN_008bec74 @ 0x008bec74 ====

void FUN_008bec74(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  uint local_18;
  uint local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  uint local_8;
  
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  iVar1 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
  if (-1 < iVar1) {
    if (*(int *)(in_ECX + 0x278) == 1) {
      iVar1 = 2;
      bVar7 = true;
      pcVar5 = (char *)(in_ECX + 0x280);
      pcVar4 = &DAT_00a179fc;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar7 = *pcVar5 == *pcVar4;
        pcVar5 = pcVar5 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar7);
      if (bVar7) {
        iVar1 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),in_ECX + 0x278);
        if (iVar1 < 0) goto LAB_008befc0;
        local_8 = 0;
        do {
          do {
            do {
              iVar1 = *(int *)(in_ECX + 0x278);
              if (iVar1 == 1) {
                iVar3 = 2;
                bVar7 = true;
                pcVar5 = (char *)(in_ECX + 0x280);
                pcVar4 = &DAT_00a00254;
                do {
                  if (iVar3 == 0) break;
                  iVar3 = iVar3 + -1;
                  bVar7 = *pcVar5 == *pcVar4;
                  pcVar5 = pcVar5 + 1;
                  pcVar4 = pcVar4 + 1;
                } while (bVar7);
                if (bVar7) {
                  iVar1 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
                  if (iVar1 < 0) goto LAB_008befc0;
                  iVar1 = *(int *)(in_ECX + 0x278);
                  if ((iVar1 == 0xc) || (iVar1 == 0xd)) {
                    local_18 = 0;
                    if (local_8 != 0) goto LAB_008bf02c;
                    goto LAB_008befc0;
                  }
                  goto LAB_008befa3;
                }
              }
              if (iVar1 == 9) {
                pcVar5 = *(char **)(in_ECX + 0x280);
                iVar1 = 5;
                bVar7 = true;
                pcVar4 = pcVar5;
                pcVar6 = &DAT_00a17a14;
                do {
                  if (iVar1 == 0) break;
                  iVar1 = iVar1 + -1;
                  bVar7 = *pcVar4 == *pcVar6;
                  pcVar4 = pcVar4 + 1;
                  pcVar6 = pcVar6 + 1;
                } while (bVar7);
                if (bVar7) {
                  local_14 = 0x10;
                }
                else {
                  iVar1 = 6;
                  bVar7 = true;
                  pcVar4 = pcVar5;
                  pcVar6 = s_error_009fdc5c;
                  do {
                    if (iVar1 == 0) break;
                    iVar1 = iVar1 + -1;
                    bVar7 = *pcVar4 == *pcVar6;
                    pcVar4 = pcVar4 + 1;
                    pcVar6 = pcVar6 + 1;
                  } while (bVar7);
                  if (bVar7) {
                    local_14 = 0xf;
                  }
                  else {
                    iVar1 = 8;
                    bVar7 = true;
                    pcVar4 = pcVar5;
                    pcVar6 = s_disable_00a17a0c;
                    do {
                      if (iVar1 == 0) break;
                      iVar1 = iVar1 + -1;
                      bVar7 = *pcVar4 == *pcVar6;
                      pcVar4 = pcVar4 + 1;
                      pcVar6 = pcVar6 + 1;
                    } while (bVar7);
                    if (bVar7) {
                      local_14 = 0;
                    }
                    else {
                      iVar1 = 8;
                      bVar7 = true;
                      pcVar4 = s_default_00a17a04;
                      do {
                        if (iVar1 == 0) break;
                        iVar1 = iVar1 + -1;
                        bVar7 = *pcVar5 == *pcVar4;
                        pcVar5 = pcVar5 + 1;
                        pcVar4 = pcVar4 + 1;
                      } while (bVar7);
                      if (!bVar7) goto LAB_008befa3;
                      local_14 = 0xff;
                    }
                  }
                }
              }
              else if ((((iVar1 != 2) && (iVar1 != 3)) && (iVar1 != 4)) ||
                      ((local_14 = *(uint *)(in_ECX + 0x280), local_14 == 0 || (4 < local_14))))
              goto LAB_008befa3;
              iVar1 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
              if (iVar1 < 0) goto LAB_008befc0;
              if (*(int *)(in_ECX + 0x278) != 1) goto LAB_008befa3;
              iVar1 = 2;
              bVar7 = true;
              pcVar5 = (char *)(in_ECX + 0x280);
              pcVar4 = &DAT_00a17a00;
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar7 = *pcVar5 == *pcVar4;
                pcVar5 = pcVar5 + 1;
                pcVar4 = pcVar4 + 1;
              } while (bVar7);
              if (!bVar7) goto LAB_008befa3;
              iVar1 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),in_ECX + 0x278);
              if (iVar1 < 0) goto LAB_008befc0;
              do {
                do {
                  iVar1 = *(int *)(in_ECX + 0x278);
                  if (((iVar1 != 2) && (iVar1 != 3)) && (iVar1 != 4)) goto LAB_008befa3;
                  if (local_8 == (~local_8 + 1 & local_8)) {
                    if (local_8 == 0) {
                      iVar1 = 1;
                    }
                    else {
                      iVar1 = local_8 * 2;
                    }
                    puVar2 = operator_new(iVar1 << 2);
                    if (puVar2 != (undefined4 *)0x0) {
                      for (local_8 = local_8 & 0x3fffffff; local_8 != 0; local_8 = local_8 - 1) {
                        *puVar2 = *local_c;
                        local_c = local_c + 1;
                        puVar2 = puVar2 + 1;
                      }
                      for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                        *(undefined1 *)puVar2 = *(undefined1 *)local_c;
                        local_c = (undefined4 *)((int)local_c + 1);
                        puVar2 = (undefined4 *)((int)puVar2 + 1);
                      }
                      _free((void *)0x0);
                      return;
                    }
                    goto LAB_008befc0;
                  }
                  *(undefined4 *)(local_8 * 4) = *(undefined4 *)(in_ECX + 0x280);
                  *(uint *)(local_8 * 4) = local_14;
                  local_8 = local_8 + 1;
                  iVar1 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
                  if (iVar1 < 0) goto LAB_008befc0;
                } while (*(int *)(in_ECX + 0x278) != 1);
                iVar1 = 2;
                bVar7 = true;
                pcVar5 = (char *)(in_ECX + 0x280);
                pcVar4 = &DAT_00a05ccc;
                do {
                  if (iVar1 == 0) break;
                  iVar1 = iVar1 + -1;
                  bVar7 = *pcVar5 == *pcVar4;
                  pcVar5 = pcVar5 + 1;
                  pcVar4 = pcVar4 + 1;
                } while (bVar7);
                if (bVar7) break;
                iVar1 = 2;
                bVar7 = true;
                pcVar5 = (char *)(in_ECX + 0x280);
                pcVar4 = &DAT_00a00254;
                do {
                  if (iVar1 == 0) break;
                  iVar1 = iVar1 + -1;
                  bVar7 = *pcVar5 == *pcVar4;
                  pcVar5 = pcVar5 + 1;
                  pcVar4 = pcVar4 + 1;
                } while (bVar7);
              } while (!bVar7);
              iVar1 = 2;
              bVar7 = true;
              pcVar5 = (char *)(in_ECX + 0x280);
              pcVar4 = &DAT_00a05ccc;
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar7 = *pcVar5 == *pcVar4;
                pcVar5 = pcVar5 + 1;
                pcVar4 = pcVar4 + 1;
              } while (bVar7);
            } while (!bVar7);
            iVar1 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
            if (iVar1 < 0) goto LAB_008befc0;
          } while (*(int *)(in_ECX + 0x278) != 1);
          iVar1 = 2;
          bVar7 = true;
          pcVar5 = (char *)(in_ECX + 0x280);
          pcVar4 = &DAT_00a00254;
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar7 = *pcVar5 == *pcVar4;
            pcVar5 = pcVar5 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar7);
        } while (!bVar7);
      }
    }
LAB_008befa3:
    if ((*(int *)(in_ECX + 0x278) != 0xc) && (*(int *)(in_ECX + 0x278) != 0xd)) {
      FUN_008bce6b();
    }
  }
  goto LAB_008befc0;
  while( true ) {
    local_18 = local_18 + 1;
    local_10 = local_10 + 1;
    if (local_8 <= local_18) break;
LAB_008bf02c:
    iVar1 = FUN_008bd2b6(*local_10,*local_10);
    if (iVar1 < 0) break;
  }
LAB_008befc0:
  _free((void *)0x0);
  return;
}


// ==== FUN_008bf05c @ 0x008bf05c ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008bf05c(void)

{
  double dVar1;
  int iVar2;
  double *pdVar3;
  int in_ECX;
  char *pcVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 *puVar7;
  bool bVar8;
  double local_38 [4];
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 *local_8;
  
  iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
  if (iVar2 < 0) goto LAB_008bf36a;
  if (*(int *)(in_ECX + 0x278) == 1) {
    iVar2 = 2;
    bVar8 = true;
    pcVar4 = (char *)(in_ECX + 0x280);
    pcVar6 = &DAT_00a179fc;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar8 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar8);
    if (!bVar8) goto LAB_008bf34c;
    iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
    if (iVar2 < 0) goto LAB_008bf36a;
    if (*(int *)(in_ECX + 0x278) != 9) goto LAB_008bf34c;
    local_10 = *(undefined4 *)(in_ECX + 0x280);
    iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
    if (iVar2 < 0) goto LAB_008bf36a;
    if (*(int *)(in_ECX + 0x278) != 1) goto LAB_008bf34c;
    iVar2 = 2;
    bVar8 = true;
    pcVar4 = (char *)(in_ECX + 0x280);
    pcVar6 = &DAT_00a00258;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar8 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar8);
    if (!bVar8) goto LAB_008bf34c;
    iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
    if (iVar2 < 0) goto LAB_008bf36a;
    if (*(int *)(in_ECX + 0x278) != 9) goto LAB_008bf34c;
    local_14 = *(undefined4 *)(in_ECX + 0x280);
    local_8 = (undefined4 *)0x0;
    do {
      local_c = 0;
      iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
      if (iVar2 < 0) goto LAB_008bf36a;
      if (*(int *)(in_ECX + 0x278) != 1) goto LAB_008bf34c;
      iVar2 = 2;
      bVar8 = true;
      pcVar4 = (char *)(in_ECX + 0x280);
      pcVar6 = &DAT_00a00258;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar8 = *pcVar4 == *pcVar6;
        pcVar4 = pcVar4 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar8);
      if (!bVar8) goto LAB_008bf34c;
      iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
      if (iVar2 < 0) goto LAB_008bf36a;
      if (*(int *)(in_ECX + 0x278) == 1) {
        iVar2 = 2;
        bVar8 = true;
        pcVar4 = (char *)(in_ECX + 0x280);
        pcVar6 = &DAT_00a17a1c;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar8 = *pcVar4 == *pcVar6;
          pcVar4 = pcVar4 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar8);
        if (bVar8) {
          local_c = 1;
          iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),in_ECX + 0x278);
          if (iVar2 < 0) goto LAB_008bf36a;
        }
      }
      iVar2 = *(int *)(in_ECX + 0x278);
      if (iVar2 == 2) {
LAB_008bf234:
        dVar1 = (double)*(int *)(in_ECX + 0x280);
        pdVar3 = local_38 + (int)local_8;
        if (*(int *)(in_ECX + 0x280) < 0) {
          dVar1 = dVar1 + _DAT_009c2f50;
        }
      }
      else if (iVar2 == 3) {
        dVar1 = (double)*(int *)(in_ECX + 0x280);
        pdVar3 = local_38 + (int)local_8;
      }
      else {
        if (iVar2 == 4) goto LAB_008bf234;
        if ((iVar2 < 5) || (8 < iVar2)) goto LAB_008bf34c;
        dVar1 = *(double *)(in_ECX + 0x280);
        pdVar3 = local_38 + (int)local_8;
      }
      bVar8 = local_c != 0;
      *pdVar3 = dVar1;
      if (bVar8) {
        *pdVar3 = -*pdVar3;
      }
      local_8 = (undefined4 *)((int)local_8 + 1);
    } while (local_8 < 4);
    iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
    if (iVar2 < 0) goto LAB_008bf36a;
    if (*(int *)(in_ECX + 0x278) != 1) goto LAB_008bf34c;
    iVar2 = 2;
    bVar8 = true;
    pcVar4 = (char *)(in_ECX + 0x280);
    pcVar6 = &DAT_00a00254;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar8 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar8);
    if (!bVar8) goto LAB_008bf34c;
    iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
    if (iVar2 < 0) goto LAB_008bf36a;
    iVar2 = *(int *)(in_ECX + 0x278);
    if ((iVar2 != 0xc) && (iVar2 != 0xd)) goto LAB_008bf34c;
    local_8 = operator_new(0x30);
    if (local_8 == (undefined4 *)0x0) {
      local_8 = (undefined4 *)0x0;
    }
    else {
      local_8[10] = 0;
    }
    if (local_8 == (undefined4 *)0x0) {
      iVar2 = -0x7ff8fff2;
      goto LAB_008bf36a;
    }
    *local_8 = local_10;
    local_8[1] = local_14;
    pdVar3 = local_38;
    puVar7 = local_8 + 2;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *(undefined4 *)pdVar3;
      pdVar3 = (double *)((int)pdVar3 + 4);
      puVar7 = puVar7 + 1;
    }
    piVar5 = (int *)(in_ECX + 0x3c);
    iVar2 = *piVar5;
    if (iVar2 != 0) {
      do {
        iVar2 = __stricmp(*(char **)(iVar2 + 4),(char *)local_8[1]);
        if (-1 < iVar2) break;
        piVar5 = (int *)(*piVar5 + 0x28);
        iVar2 = *piVar5;
      } while (iVar2 != 0);
    }
    local_8[10] = *piVar5;
    *piVar5 = (int)local_8;
  }
  else {
LAB_008bf34c:
    if ((*(int *)(in_ECX + 0x278) != 0xc) && (*(int *)(in_ECX + 0x278) != 0xd)) {
      FUN_008bce6b();
    }
  }
  iVar2 = 0;
LAB_008bf36a:
  *(undefined4 *)(in_ECX + 0x40) = 1;
  return iVar2;
}


// ==== FUN_008bf375 @ 0x008bf375 ====

uint FUN_008bf375(char *param_1)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = 0x632d80f;
  if ((param_1 == (char *)0x0) || (cVar2 = *param_1, cVar2 == '\0')) {
    uVar1 = 0;
  }
  else {
    do {
      uVar1 = uVar1 * 0x13 + (int)cVar2;
      param_1 = param_1 + 1;
      cVar2 = *param_1;
    } while (cVar2 != '\0');
    uVar1 = uVar1 % 0x7f;
  }
  return uVar1;
}


// ==== FUN_008bf3ac @ 0x008bf3ac ====

undefined4 FUN_008bf3ac(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  
  pbVar3 = (byte *)*param_1;
  pbVar9 = (byte *)*param_2;
  do {
    bVar1 = *pbVar3;
    bVar10 = bVar1 < *pbVar9;
    if (bVar1 != *pbVar9) {
LAB_008bf3e3:
      iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      goto LAB_008bf3e8;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar10 = bVar1 < pbVar9[1];
    if (bVar1 != pbVar9[1]) goto LAB_008bf3e3;
    pbVar3 = pbVar3 + 2;
    pbVar9 = pbVar9 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_008bf3e8:
  if (iVar4 == 0) {
    iVar4 = param_1[1];
    iVar2 = param_2[1];
    iVar5 = iVar4;
    iVar8 = iVar2;
    iVar6 = iVar2;
    if (iVar4 != 0) {
      do {
        iVar6 = 0;
        if (iVar8 == 0) break;
        iVar5 = *(int *)(iVar5 + 0xc);
        iVar8 = *(int *)(iVar8 + 0xc);
        iVar6 = iVar8;
      } while (iVar5 != 0);
      if (iVar5 != 0) {
        return 0;
      }
    }
    if (iVar6 == 0) {
      iVar5 = param_1[2];
      iVar8 = param_2[2];
LAB_008bf5ff:
      if (iVar5 != 0) {
        if ((iVar8 == 0) || (iVar6 = *(int *)(iVar5 + 0x10), iVar6 != *(int *)(iVar8 + 0x10)))
        goto LAB_008bf48b;
        if (8 < iVar6) {
          if (iVar6 == 9) {
            bVar10 = false;
            param_1 = (undefined4 *)0x1;
            for (iVar6 = iVar4; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xc)) {
              pbVar3 = *(byte **)(iVar6 + 0x18);
              pbVar9 = *(byte **)(iVar5 + 0x18);
              do {
                bVar1 = *pbVar9;
                bVar11 = bVar1 < *pbVar3;
                if (bVar1 != *pbVar3) {
LAB_008bf538:
                  iVar7 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
                  goto LAB_008bf53d;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar9[1];
                bVar11 = bVar1 < pbVar3[1];
                if (bVar1 != pbVar3[1]) goto LAB_008bf538;
                pbVar9 = pbVar9 + 2;
                pbVar3 = pbVar3 + 2;
              } while (bVar1 != 0);
              iVar7 = 0;
LAB_008bf53d:
              if (iVar7 == 0) {
                bVar10 = true;
                break;
              }
              param_1 = (undefined4 *)((int)param_1 + 1);
            }
            for (iVar6 = iVar2; param_1 = (undefined4 *)((int)param_1 + -1), iVar6 != 0;
                iVar6 = *(int *)(iVar6 + 0xc)) {
              pbVar3 = *(byte **)(iVar6 + 0x18);
              pbVar9 = *(byte **)(iVar8 + 0x18);
              do {
                bVar1 = *pbVar9;
                bVar11 = bVar1 < *pbVar3;
                if (bVar1 != *pbVar3) {
LAB_008bf584:
                  iVar7 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
                  goto LAB_008bf589;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar9[1];
                bVar11 = bVar1 < pbVar3[1];
                if (bVar1 != pbVar3[1]) goto LAB_008bf584;
                pbVar9 = pbVar9 + 2;
                pbVar3 = pbVar3 + 2;
              } while (bVar1 != 0);
              iVar7 = 0;
LAB_008bf589:
              if (iVar7 == 0) {
                bVar10 = true;
                break;
              }
            }
            if (bVar10) {
              bVar10 = param_1 == (undefined4 *)0x0;
              goto LAB_008bf5f1;
            }
            pbVar3 = *(byte **)(iVar8 + 0x18);
            pbVar9 = *(byte **)(iVar5 + 0x18);
            do {
              bVar1 = *pbVar9;
              bVar10 = bVar1 < *pbVar3;
              if (bVar1 != *pbVar3) goto LAB_008bf5e0;
              if (bVar1 == 0) break;
              bVar1 = pbVar9[1];
              bVar10 = bVar1 < pbVar3[1];
              if (bVar1 != pbVar3[1]) goto LAB_008bf5e0;
              pbVar9 = pbVar9 + 2;
              pbVar3 = pbVar3 + 2;
            } while (bVar1 != 0);
          }
          else {
            if ((iVar6 < 10) || (0xb < iVar6)) goto LAB_008bf5f9;
            pbVar3 = *(byte **)(iVar8 + 0x18);
            pbVar9 = *(byte **)(iVar5 + 0x18);
            do {
              bVar1 = *pbVar9;
              bVar10 = bVar1 < *pbVar3;
              if (bVar1 != *pbVar3) goto LAB_008bf5e0;
              if (bVar1 == 0) break;
              bVar1 = pbVar9[1];
              bVar10 = bVar1 < pbVar3[1];
              if (bVar1 != pbVar3[1]) goto LAB_008bf5e0;
              pbVar9 = pbVar9 + 2;
              pbVar3 = pbVar3 + 2;
            } while (bVar1 != 0);
          }
          iVar6 = 0;
          goto LAB_008bf5e5;
        }
        if (iVar6 < 5) {
          if (iVar6 != 0) {
            if (iVar6 == 1) {
              if ((((*(char *)(iVar5 + 0x18) != *(char *)(iVar8 + 0x18)) ||
                   (*(char *)(iVar5 + 0x19) != *(char *)(iVar8 + 0x19))) ||
                  (*(char *)(iVar5 + 0x1a) != *(char *)(iVar8 + 0x1a))) ||
                 (*(char *)(iVar5 + 0x1b) != *(char *)(iVar8 + 0x1b))) goto LAB_008bf48b;
            }
            else if ((1 < iVar6) && (iVar6 < 5)) goto LAB_008bf457;
            goto LAB_008bf5f9;
          }
LAB_008bf457:
          bVar10 = *(int *)(iVar5 + 0x18) == *(int *)(iVar8 + 0x18);
          goto LAB_008bf5f1;
        }
        if (*(double *)(iVar5 + 0x18) != *(double *)(iVar8 + 0x18)) goto LAB_008bf48b;
        goto LAB_008bf5f9;
      }
LAB_008bf493:
      if (iVar8 == 0) {
        return 1;
      }
    }
  }
  return 0;
LAB_008bf5e0:
  iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
LAB_008bf5e5:
  bVar10 = iVar6 == 0;
LAB_008bf5f1:
  if (!bVar10) {
LAB_008bf48b:
    if (iVar5 != 0) {
      return 0;
    }
    goto LAB_008bf493;
  }
LAB_008bf5f9:
  iVar5 = *(int *)(iVar5 + 0xc);
  iVar8 = *(int *)(iVar8 + 0xc);
  goto LAB_008bf5ff;
}


// ==== FUN_008bf618 @ 0x008bf618 ====

bool FUN_008bf618(byte *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  byte *pbVar6;
  bool bVar7;
  
  iVar2 = FUN_008bf375(param_1);
  puVar5 = *(undefined4 **)(in_ECX + 0x6c + iVar2 * 4);
  do {
    if (puVar5 == (undefined4 *)0x0) {
      return false;
    }
    pbVar3 = (byte *)*puVar5;
    pbVar6 = param_1;
    do {
      bVar1 = *pbVar6;
      bVar7 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) {
LAB_008bf657:
        iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_008bf65c;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar6[1];
      bVar7 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) goto LAB_008bf657;
      pbVar6 = pbVar6 + 2;
      pbVar3 = pbVar3 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_008bf65c:
    if (iVar2 < 0) {
      return false;
    }
    if (iVar2 == 0) {
      if (puVar5[4] != 0) {
        return true;
      }
      iVar2 = puVar5[2];
      puVar5[4] = 1;
      while ((iVar2 != 0 &&
             ((*(int *)(iVar2 + 0x10) != 9 ||
              (iVar4 = FUN_008bf618(*(undefined4 *)(iVar2 + 0x18)), iVar4 == 0))))) {
        iVar2 = *(int *)(iVar2 + 0xc);
      }
      puVar5[4] = 0;
      return iVar2 != 0;
    }
    puVar5 = (undefined4 *)puVar5[3];
  } while( true );
}


// ==== FUN_008bf6b1 @ 0x008bf6b1 ====

undefined4 FUN_008bf6b1(byte *param_1,undefined4 *param_2,undefined4 *param_3)

{
  byte bVar1;
  int iVar2;
  int in_ECX;
  byte *pbVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  bool bVar6;
  
  iVar2 = FUN_008bf618(param_1);
  if (iVar2 == 0) {
    iVar2 = FUN_008bf375(param_1);
    for (puVar4 = *(undefined4 **)(in_ECX + 0x6c + iVar2 * 4); puVar4 != (undefined4 *)0x0;
        puVar4 = (undefined4 *)puVar4[3]) {
      pbVar3 = (byte *)*puVar4;
      pbVar5 = param_1;
      do {
        bVar1 = *pbVar5;
        bVar6 = bVar1 < *pbVar3;
        if (bVar1 != *pbVar3) {
LAB_008bf701:
          iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_008bf706;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar6 = bVar1 < pbVar3[1];
        if (bVar1 != pbVar3[1]) goto LAB_008bf701;
        pbVar5 = pbVar5 + 2;
        pbVar3 = pbVar3 + 2;
      } while (bVar1 != 0);
      iVar2 = 0;
LAB_008bf706:
      if (iVar2 < 0) {
        return 0;
      }
      if (iVar2 == 0) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = puVar4[1];
        }
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = puVar4[2];
        }
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_008bf738 @ 0x008bf738 ====

void FUN_008bf738(undefined4 param_1)

{
  FUN_008f33e7(param_1,0x10);
  return;
}


// ==== FUN_008bf751 @ 0x008bf751 ====

void FUN_008bf751(char *param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar1 = false;
  bVar2 = false;
  if (param_2 != 0) {
    do {
      if (*param_1 == '\"') {
        if (param_3 != 0) {
          *(undefined1 *)(iVar3 + param_3) = 0x5c;
        }
        iVar3 = iVar3 + 1;
        if (!bVar1) {
          bVar2 = !bVar2;
        }
      }
      bVar1 = false;
      if ((bVar2) && (*param_1 == '\\')) {
        if (param_3 != 0) {
          *(undefined1 *)(iVar3 + param_3) = 0x5c;
        }
        iVar3 = iVar3 + 1;
        bVar1 = true;
      }
      if (param_3 != 0) {
        *(char *)(iVar3 + param_3) = *param_1;
      }
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_008bf7b8 @ 0x008bf7b8 ====

int FUN_008bf7b8(int param_1)

{
  int in_ECX;
  
  if (param_1 == 0) {
    if (*(int *)(in_ECX + 0x44) == 0) {
      FUN_008bd320(in_ECX + 0x18,in_ECX + 0x278,0,s_internal_error__production_faile_00a17a20);
      *(undefined4 *)(in_ECX + 0x44) = 1;
    }
    param_1 = 0;
  }
  return param_1;
}


// ==== FUN_008bf7f3 @ 0x008bf7f3 ====

void FUN_008bf7f3(void)

{
  void *_Memory;
  int in_ECX;
  
  _Memory = *(void **)(in_ECX + 0xc);
  if (_Memory == (void *)0x0) {
    return;
  }
  FUN_008bf7f3();
  _free(_Memory);
  return;
}


// ==== FUN_008bf80d @ 0x008bf80d ====

void FUN_008bf80d(byte param_1)

{
  void *in_ECX;
  
  FUN_008bf7f3();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008bf82e @ 0x008bf82e ====

void FUN_008bf82e(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_008bdfcf();
  *(undefined4 *)(in_ECX + 0x2a4) = 1;
  iVar1 = in_ECX;
  *(int *)(in_ECX + 0x2a8) = DAT_00b5f6cc;
  DAT_00b5f6cc = iVar1;
  return;
}


// ==== FUN_008bf855 @ 0x008bf855 ====

void FUN_008bf855(void)

{
  int in_ECX;
  
  DAT_00b5f6cc = *(undefined4 *)(in_ECX + 0x2a8);
  *(undefined4 *)(in_ECX + 0x2a4) = 0;
  FUN_008be024();
  return;
}


// ==== FUN_008bf86c @ 0x008bf86c ====

undefined4 FUN_008bf86c(byte *param_1)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int in_ECX;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  iVar3 = FUN_008bf375(param_1);
  piVar1 = (int *)(in_ECX + 0x6c + iVar3 * 4);
  iVar3 = *piVar1;
  do {
    if (iVar3 == 0) {
      return 0;
    }
    pbVar4 = *(byte **)*piVar1;
    pbVar5 = param_1;
    do {
      bVar2 = *pbVar5;
      bVar6 = bVar2 < *pbVar4;
      if (bVar2 != *pbVar4) {
LAB_008bf8b0:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_008bf8b5;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar5[1];
      bVar6 = bVar2 < pbVar4[1];
      if (bVar2 != pbVar4[1]) goto LAB_008bf8b0;
      pbVar5 = pbVar5 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar2 != 0);
    iVar3 = 0;
LAB_008bf8b5:
    if (iVar3 < 0) {
      return 0;
    }
    if (iVar3 == 0) {
      iVar3 = *piVar1;
      *piVar1 = *(int *)(iVar3 + 0xc);
      *(undefined4 *)(iVar3 + 0xc) = 0;
      FUN_008bf80d(1);
      return 0;
    }
    piVar1 = (undefined4 *)*piVar1 + 3;
    iVar3 = *piVar1;
  } while( true );
}


// ==== FUN_008bf8e0 @ 0x008bf8e0 ====

int FUN_008bf8e0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  iVar1 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
  if (-1 < iVar1) {
    iVar1 = *(int *)(in_ECX + 0x278);
    if (iVar1 == 9) {
      pcVar4 = *(char **)(in_ECX + 0x280);
      iVar2 = 0xc;
      bVar6 = true;
      pcVar3 = pcVar4;
      pcVar5 = s_pack_matrix_00a17a48;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        iVar1 = FUN_008beb35();
        return iVar1;
      }
      iVar2 = 8;
      bVar6 = true;
      pcVar3 = pcVar4;
      pcVar5 = s_warning_00a176d4;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        iVar1 = FUN_008bec74();
        return iVar1;
      }
      iVar2 = 4;
      bVar6 = true;
      pcVar3 = &DAT_00a17a44;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar3;
        pcVar4 = pcVar4 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar6);
      if (bVar6) {
        iVar1 = FUN_008bf05c();
        return iVar1;
      }
    }
    if ((iVar1 != 0xc) && (iVar1 != 0xd)) {
      FUN_008bce6b();
    }
    iVar1 = 0;
  }
  *(undefined4 *)(in_ECX + 0x40) = 1;
  return iVar1;
}


// ==== FUN_008bf987 @ 0x008bf987 ====

undefined4 FUN_008bf987(undefined4 *param_1)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int in_ECX;
  byte *pbVar5;
  bool bVar6;
  
  iVar3 = FUN_008bf375(*param_1);
  piVar1 = (int *)(in_ECX + 0x6c + iVar3 * 4);
  iVar3 = *piVar1;
  do {
    if (iVar3 == 0) {
LAB_008bfa2f:
      param_1[3] = *piVar1;
      *piVar1 = (int)param_1;
      return 0;
    }
    pbVar4 = *(byte **)*piVar1;
    pbVar5 = (byte *)*param_1;
    do {
      bVar2 = *pbVar5;
      bVar6 = bVar2 < *pbVar4;
      if (bVar2 != *pbVar4) {
LAB_008bf9d4:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_008bf9d9;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar5[1];
      bVar6 = bVar2 < pbVar4[1];
      if (bVar2 != pbVar4[1]) goto LAB_008bf9d4;
      pbVar5 = pbVar5 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar2 != 0);
    iVar3 = 0;
LAB_008bf9d9:
    if (iVar3 < 0) goto LAB_008bfa2f;
    if (iVar3 == 0) {
      iVar3 = FUN_008bf3ac(*piVar1,param_1);
      if (iVar3 == 0) {
        FUN_008bd3f7(in_ECX + 0x18,in_ECX + 0x278,0x5ef,s___s____macro_redefinition_00a17a54,
                     *param_1);
      }
      iVar3 = *piVar1;
      *piVar1 = *(int *)(iVar3 + 0xc);
      *(undefined4 *)(iVar3 + 0xc) = 0;
      FUN_008bf80d(1);
      goto LAB_008bfa2f;
    }
    piVar1 = (undefined4 *)*piVar1 + 3;
    iVar3 = *piVar1;
  } while( true );
}


// ==== FUN_008bfa3e @ 0x008bfa3e ====

undefined4 FUN_008bfa3e(char *param_1)

{
  int in_ECX;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  int local_8;
  
  iVar1 = 9;
  bVar4 = true;
  pcVar2 = s___LINE___00a17aec;
  pcVar3 = param_1;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return *(undefined4 *)(in_ECX + 0x28c);
  }
  local_8 = in_ECX;
  iVar1 = FUN_008bf6b1(param_1,&param_1,&local_8);
  if (iVar1 != 0) {
    if (param_1 != (char *)0x0) {
      FUN_008bd320(in_ECX + 0x18,in_ECX + 0x278,0x5ed,s_functional_defines_in_preprocess_00a17aa8);
      return 1;
    }
    if ((((local_8 != 0) && (*(int *)(local_8 + 0xc) == 0)) && (1 < *(int *)(local_8 + 0x10))) &&
       (*(int *)(local_8 + 0x10) < 5)) {
      return *(undefined4 *)(local_8 + 0x18);
    }
    FUN_008bd320(in_ECX + 0x18,in_ECX + 0x278,0x5ee,s_invalid_or_unsupported_integer_c_00a17a70);
  }
  return 0;
}


// ==== FUN_008bfae5 @ 0x008bfae5 ====

undefined4 FUN_008bfae5(int *param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  uint uVar11;
  int *piVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  int *piVar15;
  char *pcVar16;
  byte *pbVar17;
  undefined4 *puVar18;
  bool bVar19;
  undefined1 local_44 [32];
  int *local_24;
  int local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_20 = 0;
  local_10 = 0;
  local_8 = in_ECX;
  if (param_2 == 0) {
    piVar4 = &local_10;
    if (param_3 != 0) {
      do {
        iVar2 = FUN_008bf738(0x30);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_008f378b(param_3 + 0x10);
        }
        *piVar4 = iVar2;
        if (iVar2 == 0) {
          return 0;
        }
        param_3 = *(int *)(param_3 + 0xc);
        piVar4 = (int *)(iVar2 + 0xc);
      } while (param_3 != 0);
      in_ECX = local_8;
    }
    *piVar4 = *(int *)(in_ECX + 100);
    *(int *)(in_ECX + 100) = local_10;
  }
  else {
    iVar2 = *(int *)(in_ECX + 100);
    if (iVar2 == 0) {
      pcVar3 = (char *)**(undefined4 **)(in_ECX + 0x26c);
      pcVar16 = (char *)(*(undefined4 **)(in_ECX + 0x26c))[1];
      if (pcVar3 < pcVar16) {
        do {
          cVar10 = *pcVar3;
          if ((cVar10 != ' ') && ((cVar10 < '\t' || ('\r' < cVar10)))) break;
          pcVar3 = pcVar3 + 1;
        } while (pcVar3 < *(char **)(*(int *)(in_ECX + 0x26c) + 4));
        if ((pcVar3 < pcVar16) && (*pcVar3 != '(')) {
          return 0;
        }
      }
      piVar4 = (int *)(in_ECX + 0x278);
      local_14 = piVar4;
      iVar2 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),piVar4);
      if (iVar2 < 0) {
        return 0;
      }
      if (*piVar4 != 1) {
        return 0;
      }
      local_1c = (int *)(local_8 + 0x280);
      iVar2 = 2;
      bVar19 = true;
      pcVar3 = (char *)local_1c;
      pcVar16 = &DAT_00a179fc;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar19 = *pcVar3 == *pcVar16;
        pcVar3 = pcVar3 + 1;
        pcVar16 = pcVar16 + 1;
      } while (bVar19);
      if (!bVar19) {
        return 0;
      }
    }
    else {
      local_14 = (int *)(in_ECX + 0x278);
      piVar4 = (int *)(iVar2 + 0x10);
      piVar12 = local_14;
      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar12 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar12 = piVar12 + 1;
      }
      if (*local_14 != 1) {
        return 0;
      }
      local_1c = (int *)(in_ECX + 0x280);
      iVar6 = 2;
      bVar19 = true;
      pcVar3 = (char *)local_1c;
      pcVar16 = &DAT_00a179fc;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar19 = *pcVar3 == *pcVar16;
        pcVar3 = pcVar3 + 1;
        pcVar16 = pcVar16 + 1;
      } while (bVar19);
      if (!bVar19) {
        return 0;
      }
      *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(iVar2 + 0xc);
      *(undefined4 *)(iVar2 + 0xc) = 0;
    }
    local_18 = (int *)0x0;
    local_24 = &local_20;
    local_c = 1;
    iVar2 = local_8;
    do {
      piVar4 = local_14;
      iVar6 = *(int *)(iVar2 + 100);
      if (iVar6 == 0) {
        iVar2 = FUN_008bde0c(*(undefined4 *)(iVar2 + 0x298),local_14);
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = local_8;
      }
      else {
        piVar12 = (int *)(iVar6 + 0x10);
        piVar15 = local_14;
        for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar15 = *piVar12;
          piVar12 = piVar12 + 1;
          piVar15 = piVar15 + 1;
        }
        *(undefined4 *)(iVar2 + 100) = *(undefined4 *)(iVar6 + 0xc);
        *(undefined4 *)(iVar6 + 0xc) = 0;
      }
      piVar12 = local_24;
      if (*piVar4 == 0xd) {
        FUN_008bd320(iVar2 + 0x18,param_1,0x5eb,s_unexpected_end_of_file_in_macro_e_00a17b2c);
        return 0;
      }
      if (*local_24 == 0) {
        iVar2 = FUN_008bf738(0x14);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_008f3584(0,0,&DAT_00a17b5c);
        }
        *piVar12 = iVar2;
        if (iVar2 == 0) {
          return 0;
        }
        local_18 = (int *)(iVar2 + 8);
        iVar2 = local_8;
      }
      if ((((local_c == 1) && (*piVar4 == 1)) &&
          (((char)*local_1c == ',' || ((char)*local_1c == ')')))) &&
         (*(char *)(iVar2 + 0x281) == '\0')) {
        local_24 = (int *)(*piVar12 + 0xc);
      }
      else {
        iVar2 = FUN_008bf738(0x30);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_008f378b(piVar4);
        }
        *local_18 = iVar2;
        if (iVar2 == 0) {
          return 0;
        }
        local_18 = (int *)(iVar2 + 0xc);
        iVar2 = local_8;
      }
      if ((*piVar4 == 1) && (*(char *)(iVar2 + 0x281) == '\0')) {
        cVar10 = (char)*local_1c;
        if (cVar10 == '(') {
LAB_008bfd45:
          local_c = local_c + 1;
        }
        else {
          if (cVar10 != ')') {
            if (cVar10 == '[') goto LAB_008bfd45;
            if (cVar10 != ']') {
              if (cVar10 == '{') goto LAB_008bfd45;
              if (cVar10 != '}') goto LAB_008bfd48;
            }
          }
          local_c = local_c + -1;
        }
      }
LAB_008bfd48:
    } while (local_c != 0);
    iVar7 = local_20;
    iVar6 = param_2;
    do {
      if ((iVar7 == 0) || (*(int *)(iVar7 + 8) == 0)) break;
      iVar6 = *(int *)(iVar6 + 0xc);
      iVar7 = *(int *)(iVar7 + 0xc);
    } while (iVar6 != 0);
    if ((iVar6 != 0) || (iVar7 != 0)) {
      FUN_008bd320(iVar2 + 0x18,param_1,0x5ec,s_not_enough_actual_parameters_for_00a17af8,
                   *(undefined4 *)((int)param_1 + 8));
      return 0;
    }
    param_1 = &local_10;
    local_c = 0;
    local_14 = (int *)0x0;
    local_1c = (int *)0x0;
    local_24 = (int *)param_3;
    if (param_3 != 0) {
      do {
        piVar4 = (int *)((int)local_24 + 0x10);
        local_18 = param_1;
        if ((local_c == 0) && (local_14 == (int *)0x0)) {
          if (*piVar4 != 1) {
LAB_008bfdf2:
            if (*piVar4 == 1) {
              iVar2 = 3;
              bVar19 = true;
              pcVar3 = (char *)((int)local_24 + 0x18);
              pcVar16 = &DAT_00a17b28;
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar19 = *pcVar3 == *pcVar16;
                pcVar3 = pcVar3 + 1;
                pcVar16 = pcVar16 + 1;
              } while (bVar19);
              if (bVar19) {
                local_14 = (int *)0x1;
                local_1c = piVar4;
                goto LAB_008c000e;
              }
            }
            goto LAB_008bfe12;
          }
          iVar2 = 2;
          bVar19 = true;
          pcVar3 = (char *)((int)local_24 + 0x18);
          pcVar16 = &DAT_00a17b58;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar19 = *pcVar3 == *pcVar16;
            pcVar3 = pcVar3 + 1;
            pcVar16 = pcVar16 + 1;
          } while (bVar19);
          if (!bVar19) goto LAB_008bfdf2;
          local_c = 1;
          local_1c = piVar4;
        }
        else {
LAB_008bfe12:
          if (*piVar4 == 9) {
            param_3 = local_20;
            iVar2 = param_2;
            do {
              pbVar17 = *(byte **)((int)local_24 + 0x18);
              pbVar13 = *(byte **)(iVar2 + 0x18);
              do {
                bVar1 = *pbVar13;
                bVar19 = bVar1 < *pbVar17;
                if (bVar1 != *pbVar17) {
LAB_008bfe4c:
                  iVar6 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
                  goto LAB_008bfe51;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar13[1];
                bVar19 = bVar1 < pbVar17[1];
                if (bVar1 != pbVar17[1]) goto LAB_008bfe4c;
                pbVar13 = pbVar13 + 2;
                pbVar17 = pbVar17 + 2;
              } while (bVar1 != 0);
              iVar6 = 0;
LAB_008bfe51:
              if (iVar6 == 0) break;
              iVar2 = *(int *)(iVar2 + 0xc);
              param_3 = *(int *)(param_3 + 0xc);
            } while (iVar2 != 0);
            if (iVar2 == 0) goto LAB_008bfea7;
            for (iVar2 = *(int *)(param_3 + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
              iVar6 = FUN_008bf738(0x30);
              if (iVar6 == 0) {
                iVar6 = 0;
              }
              else {
                iVar6 = FUN_008f378b(iVar2 + 0x10);
              }
              *param_1 = iVar6;
              if (iVar6 == 0) {
                return 0;
              }
              param_1 = (int *)(iVar6 + 0xc);
            }
          }
          else {
LAB_008bfea7:
            iVar2 = FUN_008bf738(0x30);
            if (iVar2 == 0) {
              iVar2 = 0;
            }
            else {
              iVar2 = FUN_008f378b(piVar4);
            }
            *param_1 = iVar2;
            if (iVar2 == 0) {
              return 0;
            }
            param_1 = (int *)(iVar2 + 0xc);
          }
          if ((local_c != 0) || (local_14 != (int *)0x0)) {
            iVar6 = 0;
            iVar7 = 1;
            for (iVar2 = *local_18; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
              if ((iVar6 != 0) && (iVar6 != *(int *)(iVar2 + 0x28))) {
                iVar7 = iVar7 + 1;
              }
              iVar6 = FUN_008bf751(*(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x2c),0);
              iVar7 = iVar7 + iVar6;
              iVar6 = *(int *)(iVar2 + 0x28) + *(int *)(iVar2 + 0x2c);
            }
            pcVar3 = (char *)FUN_008f33e7(iVar7 + 1,1);
            if (pcVar3 == (char *)0x0) {
              return 0;
            }
            iVar7 = 0;
            param_3 = 1;
            cVar10 = ((local_c == 0) - 1U & 0xfb) + 0x27;
            *pcVar3 = cVar10;
            iVar2 = param_3;
            for (iVar6 = *local_18; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xc)) {
              param_3 = iVar2;
              if ((iVar7 != 0) && (iVar7 != *(int *)(iVar6 + 0x28))) {
                param_3 = iVar2 + 1;
                pcVar3[iVar2] = ' ';
              }
              iVar2 = FUN_008bf751(*(undefined4 *)(iVar6 + 0x28),*(undefined4 *)(iVar6 + 0x2c),
                                   pcVar3 + param_3);
              iVar2 = param_3 + iVar2;
              iVar7 = *(int *)(iVar6 + 0x2c) + *(int *)(iVar6 + 0x28);
            }
            pcVar3[iVar2] = cVar10;
            FUN_008bcde7();
            iVar6 = local_8;
            iVar2 = FUN_008bce01(pcVar3,iVar2 + 1,local_1c[4],local_1c[5],local_8,local_8 + 0x18);
            if ((iVar2 < 0) ||
               (iVar2 = FUN_008bde0c(*(undefined4 *)(iVar6 + 0x298),local_44), iVar2 < 0))
            goto LAB_008c017d;
            iVar2 = FUN_008bf738(0x30);
            if (iVar2 == 0) {
              iVar2 = 0;
            }
            else {
              iVar2 = FUN_008f378b(local_44);
            }
            *local_18 = iVar2;
            if (iVar2 == 0) goto LAB_008c017d;
            local_14 = (int *)0x0;
            local_c = 0;
            param_1 = (int *)(iVar2 + 0xc);
            FUN_0095cf1d();
          }
        }
LAB_008c000e:
        local_24 = *(int **)((int)local_24 + 0xc);
      } while (local_24 != (int *)0x0);
      iVar2 = local_8;
    }
    param_1 = &local_10;
    if (local_10 != 0) {
      do {
        iVar2 = *param_1;
        iVar6 = *(int *)(iVar2 + 0xc);
        if (iVar6 == 0) {
          local_20 = 0;
        }
        else {
          local_20 = *(int *)(iVar6 + 0xc);
        }
        piVar4 = (int *)(-(uint)(iVar6 != 0) & iVar6 + 0x10U);
        uVar11 = -(uint)(local_20 != 0) & local_20 + 0x10U;
        if (((iVar6 != 0) && (local_20 != 0)) && (*piVar4 == 1)) {
          iVar6 = 3;
          bVar19 = true;
          piVar4 = piVar4 + 2;
          pcVar3 = &DAT_00a17b24;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar19 = (char)*piVar4 == *pcVar3;
            piVar4 = (int *)((int)piVar4 + 1);
            pcVar3 = pcVar3 + 1;
          } while (bVar19);
          if (bVar19) {
            local_24 = (int *)(*(int *)(iVar2 + 0x2c) + *(int *)(uVar11 + 0x1c));
            puVar5 = (undefined4 *)FUN_008f33e7(local_24,1);
            if (puVar5 == (undefined4 *)0x0) {
              return 0;
            }
            uVar9 = *(uint *)(iVar2 + 0x2c);
            puVar14 = *(undefined4 **)(iVar2 + 0x28);
            puVar18 = puVar5;
            for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar18 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar18 = puVar18 + 1;
            }
            for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined1 *)puVar18 = *(undefined1 *)puVar14;
              puVar14 = (undefined4 *)((int)puVar14 + 1);
              puVar18 = (undefined4 *)((int)puVar18 + 1);
            }
            uVar9 = *(uint *)(uVar11 + 0x1c);
            puVar14 = *(undefined4 **)(uVar11 + 0x18);
            puVar18 = (undefined4 *)(*(int *)(iVar2 + 0x2c) + (int)puVar5);
            for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar18 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar18 = puVar18 + 1;
            }
            for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined1 *)puVar18 = *(undefined1 *)puVar14;
              puVar14 = (undefined4 *)((int)puVar14 + 1);
              puVar18 = (undefined4 *)((int)puVar18 + 1);
            }
            FUN_008bcde7();
            iVar6 = FUN_008bce01(puVar5,local_24,*(undefined4 *)(iVar2 + 0x20),
                                 *(undefined4 *)(iVar2 + 0x24),local_8,local_8 + 0x18);
            if ((iVar6 < 0) ||
               (iVar6 = FUN_008bde0c(*(undefined4 *)(local_8 + 0x298),iVar2 + 0x10), iVar6 < 0)) {
LAB_008c017d:
              FUN_0095cf1d();
              return 0;
            }
            *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(local_20 + 0xc);
            *(undefined4 *)(local_20 + 0xc) = 0;
            FUN_0095cf1d();
          }
        }
        param_1 = (int *)(*param_1 + 0xc);
      } while (*param_1 != 0);
      iVar2 = local_8;
    }
    *param_1 = *(int *)(iVar2 + 100);
    *(int *)(iVar2 + 100) = local_10;
  }
  return 1;
}


