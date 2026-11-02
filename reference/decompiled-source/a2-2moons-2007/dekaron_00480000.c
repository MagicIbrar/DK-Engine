// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x480000-0x48ffff

// ==== FUN_00480270 @ 0x00480270 ====

void FUN_00480270(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e016;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a521c;
  _eh_vector_constructor_iterator_
            (in_ECX + 1,0x80,0x10,(_func_void_void_ptr *)&LAB_0047f1c0,FUN_0047f0f0);
  in_ECX[0x201] = 0;
  in_ECX[0x202] = &PTR_FUN_009a51d4;
  in_ECX[0x217] = 0;
  local_4 = 1;
  _eh_vector_constructor_iterator_(in_ECX + 0x218,0x3c,0x96,FUN_00419fa0,FUN_006ef6d0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00480300 @ 0x00480300 ====

void FUN_00480300(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e016;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  _eh_vector_destructor_iterator_(in_ECX + 0x218,0x3c,0x96,FUN_006ef6d0);
  in_ECX[0x202] = &PTR_FUN_009a51d4;
  *in_ECX = &PTR_FUN_009a521c;
  local_4 = 0xffffffff;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x80,0x10,FUN_0047f0f0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00480380 @ 0x00480380 ====

void FUN_00480380(undefined4 param_1,int *param_2)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 ****ppppuStack_1c8;
  undefined *puStack_1c4;
  undefined4 ****ppppuStack_1c0;
  undefined *puStack_1bc;
  undefined4 ****ppppuStack_1b8;
  undefined *puStack_1b4;
  undefined4 ****ppppuStack_1b0;
  undefined *puStack_1ac;
  undefined4 ****ppppuStack_1a8;
  undefined *puStack_1a4;
  undefined4 ****ppppuStack_1a0;
  undefined *puStack_19c;
  undefined4 ****ppppuStack_198;
  undefined *puStack_194;
  undefined4 ****ppppuStack_190;
  undefined *puStack_18c;
  undefined4 ****ppppuStack_188;
  undefined *puStack_184;
  undefined4 ****ppppuStack_180;
  undefined *puStack_17c;
  undefined4 ****ppppuStack_178;
  undefined *puStack_174;
  undefined4 ****ppppuStack_170;
  undefined *puStack_16c;
  undefined4 ****ppppuStack_168;
  undefined *puStack_164;
  undefined4 ****ppppuStack_160;
  undefined *puStack_15c;
  undefined4 ****ppppuStack_158;
  undefined *puStack_154;
  undefined4 ****ppppuStack_150;
  undefined *puStack_14c;
  undefined1 ****ppppuStack_148;
  undefined *puStack_144;
  char ***pppcStack_140;
  undefined *puStack_13c;
  char ***pppcStack_138;
  undefined *puStack_134;
  char **ppcStack_130;
  undefined *puStack_12c;
  char **ppcStack_128;
  undefined *puStack_124;
  undefined1 **ppuStack_120;
  undefined *puStack_11c;
  char *pcStack_118;
  undefined *puStack_114;
  undefined4 uStack_110;
  char local_100 [60];
  int iStack_c4;
  
  uStack_110 = s_Index_009a531c;
  pcStack_118 = local_100;
  puStack_114 = &DAT_009a51bc;
  puStack_11c = (undefined *)0x48039f;
  FUN_0044a580();
  uStack_110 = local_100;
  puStack_114 = (undefined *)0x0;
  pcStack_118 = (char *)0x1;
  puStack_11c = (undefined *)0x4803b9;
  puStack_11c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppuStack_120 = (undefined1 **)0x4803c1;
  FUN_0047f100();
  pcStack_118 = s_MaxLevel_009a5634;
  ppuStack_120 = (undefined1 **)(local_100 + -8);
  puStack_11c = &DAT_009a51bc;
  puStack_124 = (undefined *)0x4803d5;
  FUN_0044a580();
  pcStack_118 = local_100 + -8;
  puStack_11c = (undefined *)0x0;
  ppuStack_120 = (undefined1 **)0x2;
  puStack_124 = (undefined *)0x4803e8;
  puStack_124 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppcStack_128 = (char **)0x4803f0;
  FUN_0047f100();
  ppuStack_120 = (undefined1 **)s_MaxStyleCode_009a5624;
  ppcStack_128 = (char **)&uStack_110;
  puStack_124 = &DAT_009a51bc;
  puStack_12c = (undefined *)0x480404;
  FUN_0044a580();
  ppuStack_120 = (undefined1 **)&uStack_110;
  puStack_124 = (undefined *)0x0;
  ppcStack_128 = (char **)0x3;
  puStack_12c = (undefined *)0x480417;
  puStack_12c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppcStack_130 = (char **)0x48041f;
  FUN_0047f100();
  ppcStack_128 = (char **)s_Distance_009a5618;
  ppcStack_130 = &pcStack_118;
  puStack_12c = &DAT_009a51bc;
  puStack_134 = (undefined *)0x480433;
  FUN_0044a580();
  ppcStack_128 = &pcStack_118;
  puStack_12c = (undefined *)0x0;
  ppcStack_130 = (char **)0x5;
  puStack_134 = (undefined *)0x480446;
  puStack_134 = (undefined *)(**(code **)(*param_2 + 0x10))();
  pppcStack_138 = (undefined1 ***)0x48044e;
  FUN_0047f100();
  ppcStack_130 = (char **)s_TypeFlag_009a560c;
  pppcStack_138 = &ppuStack_120;
  puStack_134 = &DAT_009a51bc;
  puStack_13c = (undefined *)0x480462;
  FUN_0044a580();
  ppcStack_130 = (char **)&ppuStack_120;
  puStack_134 = (undefined *)0x0;
  pppcStack_138 = (undefined1 ***)0x6;
  puStack_13c = (undefined *)0x480475;
  puStack_13c = (undefined *)(**(code **)(*param_2 + 0x10))();
  pppcStack_140 = (char ***)0x48047d;
  FUN_0047f100();
  pppcStack_138 = (char ***)s_PCClassFlag_009a5600;
  pppcStack_140 = &ppcStack_128;
  puStack_13c = &DAT_009a51bc;
  puStack_144 = (undefined *)0x480491;
  FUN_0044a580();
  pppcStack_138 = &ppcStack_128;
  puStack_13c = (undefined *)0x0;
  pppcStack_140 = (char ***)0x7;
  puStack_144 = (undefined *)0x4804a4;
  puStack_144 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_148 = (undefined1 ****)0x4804ac;
  FUN_0047f100();
  pppcStack_140 = (char ***)s_Target_009a55f8;
  ppppuStack_148 = (undefined1 ****)&ppcStack_130;
  puStack_144 = &DAT_009a51bc;
  puStack_14c = (undefined *)0x4804c0;
  FUN_0044a580();
  pppcStack_140 = &ppcStack_130;
  puStack_144 = (undefined *)0x0;
  ppppuStack_148 = (undefined1 ****)0x8;
  puStack_14c = (undefined *)0x4804d3;
  puStack_14c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_150 = (undefined4 ****)0x4804db;
  FUN_0047f100();
  ppppuStack_148 = (undefined1 ****)s_AvailFlag_009a55ec;
  ppppuStack_150 = (undefined4 ****)&pppcStack_138;
  puStack_14c = &DAT_009a51bc;
  puStack_154 = (undefined *)0x4804ef;
  FUN_0044a580();
  ppppuStack_148 = &pppcStack_138;
  puStack_14c = (undefined *)0x0;
  ppppuStack_150 = (undefined4 ****)0x9;
  puStack_154 = (undefined *)0x480502;
  puStack_154 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_158 = (undefined4 ****)0x48050a;
  FUN_0047f100();
  ppppuStack_150 = (undefined4 ****)s_IconIndex_009a55e0;
  ppppuStack_158 = (undefined4 ****)&pppcStack_140;
  puStack_154 = &DAT_009a51bc;
  puStack_15c = (undefined *)0x48051e;
  FUN_0044a580();
  ppppuStack_150 = (undefined4 ****)&pppcStack_140;
  puStack_154 = (undefined *)0x0;
  ppppuStack_158 = (undefined4 ****)0xa;
  puStack_15c = (undefined *)0x480531;
  puStack_15c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_160 = (undefined4 ****)0x480539;
  FUN_0047f100();
  ppppuStack_158 = (undefined4 ****)s_IconPosX_009a55d4;
  ppppuStack_160 = &ppppuStack_148;
  puStack_15c = &DAT_009a51bc;
  puStack_164 = (undefined *)0x48054d;
  FUN_0044a580();
  ppppuStack_158 = &ppppuStack_148;
  puStack_15c = (undefined *)0x0;
  ppppuStack_160 = (undefined4 ****)0xb;
  puStack_164 = (undefined *)0x480560;
  puStack_164 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_168 = (undefined4 ****)0x480568;
  FUN_0047f100();
  ppppuStack_160 = (undefined4 ****)s_IconPosY_009a55c8;
  ppppuStack_168 = &ppppuStack_150;
  puStack_164 = &DAT_009a51bc;
  puStack_16c = (undefined *)0x48057c;
  FUN_0044a580();
  ppppuStack_160 = &ppppuStack_150;
  puStack_164 = (undefined *)0x0;
  ppppuStack_168 = (undefined4 ****)0xc;
  puStack_16c = (undefined *)0x48058f;
  puStack_16c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_170 = (undefined4 ****)0x480597;
  FUN_0047f100();
  ppppuStack_168 = (undefined4 ****)s_IconTabIndex_009a55b8;
  ppppuStack_170 = &ppppuStack_158;
  puStack_16c = &DAT_009a51bc;
  puStack_174 = (undefined *)0x4805ab;
  FUN_0044a580();
  ppppuStack_168 = &ppppuStack_158;
  puStack_16c = (undefined *)0x0;
  ppppuStack_170 = (undefined4 ****)0xd;
  puStack_174 = (undefined *)0x4805be;
  puStack_174 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_178 = (undefined4 ****)0x4805c6;
  FUN_0047f100();
  ppppuStack_170 = (undefined4 ****)s_ActionType_009a55ac;
  ppppuStack_178 = &ppppuStack_160;
  puStack_174 = &DAT_009a51bc;
  puStack_17c = (undefined *)0x4805da;
  FUN_0044a580();
  ppppuStack_170 = &ppppuStack_160;
  puStack_174 = (undefined *)0x0;
  ppppuStack_178 = (undefined4 ****)0xf;
  puStack_17c = (undefined *)0x4805ed;
  puStack_17c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_180 = (undefined4 ****)0x4805f5;
  FUN_0047f100();
  ppppuStack_178 = (undefined4 ****)s_ReadyActionStyle_009a5598;
  ppppuStack_180 = &ppppuStack_168;
  puStack_17c = &DAT_009a51bc;
  puStack_184 = (undefined *)0x480609;
  FUN_0044a580();
  ppppuStack_178 = &ppppuStack_168;
  puStack_17c = (undefined *)0x0;
  ppppuStack_180 = (undefined4 ****)0x10;
  puStack_184 = (undefined *)0x48061c;
  puStack_184 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_188 = (undefined4 ****)0x480624;
  FUN_0047f100();
  ppppuStack_180 = (undefined4 ****)s_ReadyActionIndex_009a5584;
  ppppuStack_188 = &ppppuStack_170;
  puStack_184 = &DAT_009a51bc;
  puStack_18c = (undefined *)0x480638;
  FUN_0044a580();
  ppppuStack_180 = &ppppuStack_170;
  puStack_184 = (undefined *)0x0;
  ppppuStack_188 = (undefined4 ****)0x11;
  puStack_18c = (undefined *)0x48064b;
  puStack_18c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_190 = (undefined4 ****)0x480653;
  FUN_0047f100();
  ppppuStack_188 = (undefined4 ****)s_ReadyActionTimeTick_009a5570;
  ppppuStack_190 = &ppppuStack_178;
  puStack_18c = &DAT_009a51bc;
  puStack_194 = (undefined *)0x480667;
  FUN_0044a580();
  ppppuStack_188 = &ppppuStack_178;
  puStack_18c = (undefined *)0x0;
  ppppuStack_190 = (undefined4 ****)0x12;
  puStack_194 = (undefined *)0x48067a;
  puStack_194 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_198 = (undefined4 ****)0x480682;
  FUN_0047f100();
  ppppuStack_190 = (undefined4 ****)s_ReadyEffectID_009a5560;
  ppppuStack_198 = &ppppuStack_180;
  puStack_194 = &DAT_009a51bc;
  puStack_19c = (undefined *)0x480696;
  FUN_0044a580();
  ppppuStack_190 = &ppppuStack_180;
  puStack_194 = (undefined *)0x0;
  ppppuStack_198 = (undefined4 ****)0x13;
  puStack_19c = (undefined *)0x4806a9;
  puStack_19c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_1a0 = (undefined4 ****)0x4806b1;
  FUN_0047f100();
  ppppuStack_198 = (undefined4 ****)s_ReadySceneID_009a5550;
  ppppuStack_1a0 = &ppppuStack_188;
  puStack_19c = &DAT_009a51bc;
  puStack_1a4 = (undefined *)0x4806c5;
  FUN_0044a580();
  ppppuStack_198 = &ppppuStack_188;
  puStack_19c = (undefined *)0x0;
  ppppuStack_1a0 = (undefined4 ****)0x14;
  puStack_1a4 = (undefined *)0x4806d8;
  puStack_1a4 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_1a8 = (undefined4 ****)0x4806e0;
  FUN_0047f100();
  ppppuStack_1a0 = (undefined4 ****)s_ReadyEffectTime_009a5540;
  ppppuStack_1a8 = &ppppuStack_190;
  puStack_1a4 = &DAT_009a51bc;
  puStack_1ac = (undefined *)0x4806f4;
  FUN_0044a580();
  ppppuStack_1a0 = &ppppuStack_190;
  puStack_1a4 = (undefined *)0x0;
  ppppuStack_1a8 = (undefined4 ****)0x15;
  puStack_1ac = (undefined *)0x480707;
  puStack_1ac = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_1b0 = (undefined4 ****)0x48070f;
  FUN_0047f100();
  ppppuStack_1a8 = (undefined4 ****)s_ChargeActionStyle_009a552c;
  ppppuStack_1b0 = &ppppuStack_198;
  puStack_1ac = &DAT_009a51bc;
  puStack_1b4 = (undefined *)0x480723;
  FUN_0044a580();
  ppppuStack_1a8 = &ppppuStack_198;
  puStack_1ac = (undefined *)0x0;
  ppppuStack_1b0 = (undefined4 ****)0x16;
  puStack_1b4 = (undefined *)0x480736;
  puStack_1b4 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_1b8 = (undefined4 ****)0x48073e;
  FUN_0047f100();
  ppppuStack_1b0 = (undefined4 ****)s_ChargeActionIndex_009a5518;
  ppppuStack_1b8 = &ppppuStack_1a0;
  puStack_1b4 = &DAT_009a51bc;
  puStack_1bc = (undefined *)0x480752;
  FUN_0044a580();
  ppppuStack_1b0 = &ppppuStack_1a0;
  puStack_1b4 = (undefined *)0x0;
  ppppuStack_1b8 = (undefined4 ****)0x17;
  puStack_1bc = (undefined *)0x480765;
  puStack_1bc = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_1c0 = (undefined4 ****)0x48076d;
  FUN_0047f100();
  ppppuStack_1b8 = (undefined4 ****)s_ChargeActionTimeTick_009a5500;
  ppppuStack_1c0 = &ppppuStack_1a8;
  puStack_1bc = &DAT_009a51bc;
  puStack_1c4 = (undefined *)0x480781;
  FUN_0044a580();
  ppppuStack_1b8 = &ppppuStack_1a8;
  puStack_1bc = (undefined *)0x0;
  ppppuStack_1c0 = (undefined4 ****)0x18;
  puStack_1c4 = (undefined *)0x480794;
  puStack_1c4 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_1c8 = (undefined4 ****)0x48079c;
  FUN_0047f100();
  ppppuStack_1c0 = (undefined4 ****)s_ChargeEffectID_009a54f0;
  ppppuStack_1c8 = &ppppuStack_1b0;
  puStack_1c4 = &DAT_009a51bc;
  FUN_0044a580();
  ppppuStack_1c0 = &ppppuStack_1b0;
  puStack_1c4 = (undefined *)0x0;
  ppppuStack_1c8 = (undefined4 ****)0x19;
  uVar6 = (**(code **)(*param_2 + 0x10))();
  FUN_0047f100(uVar6);
  ppppuStack_1c8 = (undefined4 ****)s_ChargeSceneID_009a54e0;
  FUN_0044a580(&ppppuStack_1b8,&DAT_009a51bc);
  ppppuStack_1c8 = &ppppuStack_1b8;
  uVar8 = 0x1a;
  uVar6 = (**(code **)(*param_2 + 0x10))(0x1a,0);
  FUN_0047f100(uVar6,uVar8);
  FUN_0044a580(&ppppuStack_1c0,&DAT_009a51bc,s_ChargeEffectTime_009a54cc);
  uVar8 = 0x1b;
  uVar6 = (**(code **)(*param_2 + 0x10))(0x1b,0,&ppppuStack_1c0);
  FUN_0047f100(uVar6,uVar8);
  uVar4 = FUN_00475a90(1,1);
  *(ushort *)(iStack_c4 + 0x2bb8) = uVar4;
  if (0xfff < uVar4) {
    FUN_0044a580(&ppppuStack_1c8,&DAT_009a51bc,s_SKILL_INDEX_cannot_bigger_than_4_009a54a4);
    FUN_00797b80(&ppppuStack_1c8);
    ppppuStack_1c8 = (undefined4 ****)((uint)ppppuStack_1c8 & 0xffffff00);
    uVar6 = FUN_0044a580(&ppppuStack_1c8,s_File___s__Line___d_0099f0a0,
                         s___Loader_Article_Skill_cpp_009a51e4,0x74);
    FUN_00797b80(uVar6);
    FUN_00797a40();
  }
  cVar1 = FUN_004753b0(2,1);
  *(int *)(iStack_c4 + 0x804) = *(int *)(iStack_c4 + 0x804) + (uint)(byte)(cVar1 + 1);
  uVar7 = FUN_004753b0(3,1);
  *(int *)(iStack_c4 + 0x85c) = *(int *)(iStack_c4 + 0x85c) + (uVar7 & 0xff);
  uVar5 = FUN_00475a90(5,1);
  *(undefined2 *)(iStack_c4 + 0x2bc2) = uVar5;
  uVar6 = (**(code **)(*param_2 + 0x10))(6,1);
  uVar6 = FUN_0047faf0(uVar6);
  *(undefined4 *)(iStack_c4 + 0x2bc4) = uVar6;
  uVar6 = (**(code **)(*param_2 + 0x10))(7,1);
  bVar2 = FUN_0047fc90(uVar6);
  *(uint *)(iStack_c4 + 0x2bc8) = 0x80000000 >> (bVar2 & 0x1f);
  uVar6 = (**(code **)(*param_2 + 0x10))(8,1);
  uVar6 = FUN_0047f9f0(uVar6);
  *(undefined4 *)(iStack_c4 + 0x2bbc) = uVar6;
  uVar3 = FUN_004753b0(9,1);
  *(undefined1 *)(iStack_c4 + 0x2bc0) = uVar3;
  uVar5 = FUN_00475a90(10,1);
  *(undefined2 *)(iStack_c4 + 0x2b88) = uVar5;
  uVar3 = FUN_004753b0(0xb,1);
  *(undefined1 *)(iStack_c4 + 0x2b8b) = uVar3;
  uVar3 = FUN_004753b0(0xc,1);
  *(undefined1 *)(iStack_c4 + 0x2b8c) = uVar3;
  uVar3 = FUN_004753b0(0xd,1);
  *(undefined1 *)(iStack_c4 + 0x2b8a) = uVar3;
  uVar6 = (**(code **)(*param_2 + 0x10))(0xf,1);
  uVar3 = FUN_0047f910(uVar6);
  *(undefined1 *)(iStack_c4 + 0x2b98) = uVar3;
  uVar5 = FUN_00475a90(0x13,1);
  *(undefined2 *)(iStack_c4 + 0x2b90) = uVar5;
  uVar5 = FUN_00475a90(0x14,1);
  *(undefined2 *)(iStack_c4 + 0x2b92) = uVar5;
  uVar6 = FUN_004756e0(0x15,1);
  *(undefined4 *)(iStack_c4 + 0x2b94) = uVar6;
  uVar3 = FUN_004753b0(0x10,1);
  *(undefined1 *)(iStack_c4 + 0x2b99) = uVar3;
  uVar6 = FUN_004756e0(0x11,1);
  *(undefined4 *)(iStack_c4 + 0x2b9c) = uVar6;
  uVar6 = FUN_004756e0(0x12,1);
  *(undefined4 *)(iStack_c4 + 0x2ba0) = uVar6;
  uVar6 = (**(code **)(*param_2 + 0x10))(0xf,1);
  uVar3 = FUN_0047f910(uVar6);
  *(undefined1 *)(iStack_c4 + 0x2bac) = uVar3;
  uVar5 = FUN_00475a90(0x19,1);
  *(undefined2 *)(iStack_c4 + 0x2ba4) = uVar5;
  uVar5 = FUN_00475a90(0x1a,1);
  *(undefined2 *)(iStack_c4 + 0x2ba6) = uVar5;
  uVar6 = FUN_004756e0(0x1b,1);
  *(undefined4 *)(iStack_c4 + 0x2ba8) = uVar6;
  uVar3 = FUN_004753b0(0x16,1);
  *(undefined1 *)(iStack_c4 + 0x2bad) = uVar3;
  uVar6 = FUN_004756e0(0x17,1);
  *(undefined4 *)(iStack_c4 + 0x2bb0) = uVar6;
  uVar6 = FUN_004756e0(0x18,1);
  *(undefined4 *)(iStack_c4 + 0x2bb4) = uVar6;
  return;
}


// ==== FUN_00480a90 @ 0x00480a90 ====

void FUN_00480a90(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  byte bVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  char *pcVar8;
  uint uVar9;
  long lVar10;
  char cVar11;
  undefined4 uVar12;
  undefined1 ****ppppuStack_298;
  undefined *puStack_294;
  undefined1 ****ppppuStack_290;
  undefined *puStack_28c;
  undefined1 ****ppppuStack_288;
  undefined *puStack_284;
  char ***pppcStack_280;
  undefined *puStack_27c;
  char ***pppcStack_278;
  undefined *puStack_274;
  char ***pppcStack_270;
  undefined *puStack_26c;
  char ***pppcStack_268;
  undefined *puStack_264;
  char **ppcStack_260;
  undefined *puStack_25c;
  char **ppcStack_258;
  undefined *puStack_254;
  char **ppcStack_250;
  undefined *puStack_24c;
  char **ppcStack_248;
  undefined *puStack_244;
  undefined1 **ppuStack_240;
  undefined *puStack_23c;
  char *pcStack_238;
  undefined *puStack_234;
  char *pcStack_230;
  undefined *puStack_22c;
  char *pcStack_228;
  undefined *puStack_224;
  undefined4 uStack_220;
  char acStack_20a [2];
  char acStack_208 [8];
  char local_200 [104];
  undefined1 auStack_198 [260];
  int iStack_94;
  
  uStack_220 = s_ComboIndex_009a5718;
  pcStack_228 = local_200;
  puStack_224 = &DAT_009a51bc;
  puStack_22c = (undefined *)0x480ab0;
  FUN_0044a580();
  uStack_220 = local_200;
  puStack_224 = (undefined *)0x0;
  pcStack_228 = (char *)0x1f;
  puStack_22c = (undefined *)0x480aca;
  puStack_22c = (undefined *)(**(code **)(*param_2 + 0x10))();
  pcStack_230 = (char *)0x480ad2;
  FUN_0047f100();
  pcStack_228 = s_ActionType_009a55ac;
  pcStack_230 = acStack_208;
  puStack_22c = &DAT_009a51bc;
  puStack_234 = (undefined *)0x480ae6;
  FUN_0044a580();
  pcStack_228 = acStack_208;
  puStack_22c = (undefined *)0x1;
  pcStack_230 = (char *)0x1f;
  puStack_234 = (undefined *)0x480af9;
  puStack_234 = (undefined *)(**(code **)(*param_2 + 0x10))();
  pcStack_238 = (char *)0x480b01;
  FUN_0047f100();
  pcStack_230 = s_Style_009a5710;
  pcStack_238 = acStack_20a + -6;
  puStack_234 = &DAT_009a51bc;
  puStack_23c = (undefined *)0x480b15;
  FUN_0044a580();
  pcStack_230 = acStack_20a + -6;
  puStack_234 = (undefined *)0x2;
  pcStack_238 = (char *)0x1f;
  puStack_23c = (undefined *)0x480b28;
  puStack_23c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppuStack_240 = (undefined1 **)0x480b30;
  FUN_0047f100();
  pcStack_238 = s_ActionIndex_009a5704;
  ppuStack_240 = (undefined1 **)(acStack_20a + -0xe);
  puStack_23c = &DAT_009a51bc;
  puStack_244 = (undefined *)0x480b44;
  FUN_0044a580();
  pcStack_238 = acStack_20a + -0xe;
  puStack_23c = (undefined *)0x3;
  ppuStack_240 = (undefined1 **)0x1f;
  puStack_244 = (undefined *)0x480b57;
  puStack_244 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppcStack_248 = (char **)0x480b5f;
  FUN_0047f100();
  ppuStack_240 = (undefined1 **)s_TimeTick_009a56f8;
  ppcStack_248 = (char **)&uStack_220;
  puStack_244 = &DAT_009a51bc;
  puStack_24c = (undefined *)0x480b73;
  FUN_0044a580();
  ppuStack_240 = (undefined1 **)&uStack_220;
  puStack_244 = (undefined *)0x4;
  ppcStack_248 = (char **)0x1f;
  puStack_24c = (undefined *)0x480b86;
  puStack_24c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppcStack_250 = (char **)0x480b8e;
  FUN_0047f100();
  ppcStack_248 = (char **)s_EffectID_009a56ec;
  ppcStack_250 = &pcStack_228;
  puStack_24c = &DAT_009a51bc;
  puStack_254 = (undefined *)0x480ba2;
  FUN_0044a580();
  ppcStack_248 = &pcStack_228;
  puStack_24c = (undefined *)0x5;
  ppcStack_250 = (char **)0x1f;
  puStack_254 = (undefined *)0x480bb5;
  puStack_254 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppcStack_258 = (char **)0x480bbd;
  FUN_0047f100();
  ppcStack_250 = (char **)s_SceneID_009a56e4;
  ppcStack_258 = &pcStack_230;
  puStack_254 = &DAT_009a51bc;
  puStack_25c = (undefined *)0x480bd1;
  FUN_0044a580();
  ppcStack_250 = &pcStack_230;
  puStack_254 = (undefined *)0x6;
  ppcStack_258 = (char **)0x1f;
  puStack_25c = (undefined *)0x480be4;
  puStack_25c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppcStack_260 = (char **)0x480bec;
  FUN_0047f100();
  ppcStack_258 = (char **)s_EffectTime_009a56d8;
  ppcStack_260 = &pcStack_238;
  puStack_25c = &DAT_009a51bc;
  puStack_264 = (undefined *)0x480c00;
  FUN_0044a580();
  ppcStack_258 = &pcStack_238;
  puStack_25c = (undefined *)0x7;
  ppcStack_260 = (char **)0x1f;
  puStack_264 = (undefined *)0x480c13;
  puStack_264 = (undefined *)(**(code **)(*param_2 + 0x10))();
  pppcStack_268 = (undefined1 ***)0x480c1b;
  FUN_0047f100();
  ppcStack_260 = (char **)s_ResultCode_009a56cc;
  pppcStack_268 = &ppuStack_240;
  puStack_264 = &DAT_009a51bc;
  puStack_26c = (undefined *)0x480c2f;
  FUN_0044a580();
  ppcStack_260 = (char **)&ppuStack_240;
  puStack_264 = (undefined *)0x8;
  pppcStack_268 = (undefined1 ***)0x1f;
  puStack_26c = (undefined *)0x480c42;
  puStack_26c = (undefined *)(**(code **)(*param_2 + 0x10))();
  pppcStack_270 = (undefined1 ***)0x480c4a;
  FUN_0047f100();
  pppcStack_268 = (char ***)&DAT_009a56c4;
  pppcStack_270 = &ppcStack_248;
  puStack_26c = &DAT_009a51bc;
  puStack_274 = (undefined *)0x480c5e;
  FUN_0044a580();
  pppcStack_268 = &ppcStack_248;
  puStack_26c = (undefined *)0x9;
  pppcStack_270 = (undefined1 ***)0x1f;
  puStack_274 = (undefined *)0x480c71;
  puStack_274 = (undefined *)(**(code **)(*param_2 + 0x10))();
  pppcStack_278 = (undefined1 ***)0x480c79;
  FUN_0047f100();
  pppcStack_270 = (char ***)&DAT_009a56bc;
  pppcStack_278 = &ppcStack_250;
  puStack_274 = &DAT_009a51bc;
  puStack_27c = (undefined *)0x480c8d;
  FUN_0044a580();
  pppcStack_270 = &ppcStack_250;
  puStack_274 = (undefined *)0xa;
  pppcStack_278 = (undefined1 ***)0x1f;
  puStack_27c = (undefined *)0x480ca0;
  puStack_27c = (undefined *)(**(code **)(*param_2 + 0x10))();
  pppcStack_280 = (char ***)0x480ca8;
  FUN_0047f100();
  pppcStack_278 = (char ***)&DAT_009a56b4;
  pppcStack_280 = &ppcStack_258;
  puStack_27c = &DAT_009a51bc;
  puStack_284 = (undefined *)0x480cbc;
  FUN_0044a580();
  pppcStack_278 = &ppcStack_258;
  puStack_27c = (undefined *)0xb;
  pppcStack_280 = (char ***)0x1f;
  puStack_284 = (undefined *)0x480ccf;
  puStack_284 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_288 = (undefined1 ****)0x480cd7;
  FUN_0047f100();
  pppcStack_280 = (char ***)&DAT_009a56ac;
  ppppuStack_288 = (undefined1 ****)&ppcStack_260;
  puStack_284 = &DAT_009a51bc;
  puStack_28c = (undefined *)0x480ceb;
  FUN_0044a580();
  pppcStack_280 = &ppcStack_260;
  puStack_284 = (undefined *)0xc;
  ppppuStack_288 = (undefined1 ****)0x1f;
  puStack_28c = (undefined *)0x480cfe;
  puStack_28c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_290 = (undefined1 ****)0x480d06;
  FUN_0047f100();
  ppppuStack_288 = (undefined1 ****)&DAT_009a56a4;
  ppppuStack_290 = &pppcStack_268;
  puStack_28c = &DAT_009a51bc;
  puStack_294 = (undefined *)0x480d1a;
  FUN_0044a580();
  ppppuStack_288 = &pppcStack_268;
  puStack_28c = (undefined *)0xd;
  ppppuStack_290 = (undefined1 ****)0x1f;
  puStack_294 = (undefined *)0x480d2d;
  puStack_294 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppppuStack_298 = (undefined1 ****)0x480d35;
  FUN_0047f100();
  ppppuStack_290 = (undefined1 ****)&DAT_009a569c;
  ppppuStack_298 = &pppcStack_270;
  puStack_294 = &DAT_009a51bc;
  FUN_0044a580();
  ppppuStack_290 = &pppcStack_270;
  puStack_294 = (undefined *)0xe;
  ppppuStack_298 = (undefined1 ****)0x1f;
  uVar7 = (**(code **)(*param_2 + 0x10))();
  FUN_0047f100(uVar7);
  ppppuStack_298 = (undefined1 ****)&DAT_009a5694;
  FUN_0044a580(&pppcStack_278,&DAT_009a51bc);
  ppppuStack_298 = &pppcStack_278;
  uVar12 = 0x1f;
  uVar7 = (**(code **)(*param_2 + 0x10))(0x1f);
  FUN_0047f100(uVar7,uVar12);
  FUN_0044a580(&pppcStack_280,&DAT_009a51bc,s_ResultEffectID_009a5684);
  uVar12 = 0x1f;
  uVar7 = (**(code **)(*param_2 + 0x10))(0x1f,0x10,&pppcStack_280);
  FUN_0047f100(uVar7,uVar12);
  FUN_0044a580(&ppppuStack_288,&DAT_009a51bc,s_ResultSceneID_009a5674);
  uVar12 = 0x1f;
  uVar7 = (**(code **)(*param_2 + 0x10))(0x1f,0x11,&ppppuStack_288);
  FUN_0047f100(uVar7,uVar12);
  FUN_0044a580(&ppppuStack_290,&DAT_009a51bc,s_ResultEffectTime_009a5660);
  uVar12 = 0x1f;
  uVar7 = (**(code **)(*param_2 + 0x10))(0x1f,0x12,&ppppuStack_290);
  FUN_0047f100(uVar7,uVar12);
  bVar5 = 0;
  cVar4 = ' ';
  do {
    cVar11 = cVar4;
    bVar2 = FUN_004753b0(cVar4,0);
    if (bVar2 != (byte)(cVar11 - 0x20U)) {
      ppppuStack_298 = (undefined1 ****)((uint)ppppuStack_298 & 0xffffff00);
      FUN_0044a580(&ppppuStack_298,s_Wrong_Combo_Index____d____d_009a5640,bVar2,bVar5);
      FUN_00797b80(&ppppuStack_298);
      auStack_198[0] = 0;
      uVar7 = FUN_0044a580(auStack_198,s_File___s__Line___d_0099f0a0,
                           s___Loader_Article_Skill_cpp_009a51e4,0xed);
      FUN_00797b80(uVar7);
      FUN_00797a40();
    }
    puVar1 = (undefined4 *)(iStack_94 + 0x860 + (uint)bVar2 * 0x3c);
    uVar7 = (**(code **)(*param_2 + 0x10))(cVar4,1);
    uVar3 = FUN_0047f910(uVar7);
    *(undefined1 *)(puVar1 + 0xc) = uVar3;
    uVar3 = FUN_004753b0(cVar4,2);
    *(undefined1 *)((int)puVar1 + 0x31) = uVar3;
    pcVar8 = (char *)(**(code **)(*param_2 + 0x10))(cVar4,3);
    FUN_00475260(pcVar8,cVar4,3);
    uVar9 = 0;
    do {
      if (pcVar8[uVar9] == '\0') {
        lVar10 = 0;
        if (uVar9 != 0) {
          lVar10 = _atol(pcVar8);
        }
        goto LAB_00480f18;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x100);
    lVar10 = 0;
LAB_00480f18:
    puVar1[0xd] = lVar10;
    pcVar8 = (char *)(**(code **)(*param_2 + 0x10))(cVar4,4);
    FUN_00475260(pcVar8,cVar4,4);
    uVar9 = 0;
    do {
      if (pcVar8[uVar9] == '\0') {
        lVar10 = 0;
        if (uVar9 != 0) {
          lVar10 = _atol(pcVar8);
        }
        goto LAB_00480f5b;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x100);
    lVar10 = 0;
LAB_00480f5b:
    puVar1[0xe] = lVar10;
    uVar6 = FUN_00475a90(cVar4,5);
    *(undefined2 *)(puVar1 + 10) = uVar6;
    uVar6 = FUN_00475a90(cVar4,6);
    *(undefined2 *)((int)puVar1 + 0x2a) = uVar6;
    uVar9 = FUN_00475a90(cVar4,7);
    puVar1[0xb] = uVar9 & 0xffff;
    uVar7 = FUN_004756e0(cVar4,8);
    *puVar1 = uVar7;
    pcVar8 = (char *)(**(code **)(*param_2 + 0x10))(cVar4,9);
    FUN_00475260(pcVar8,cVar4,9);
    uVar9 = 0;
    do {
      if (pcVar8[uVar9] == '\0') {
        lVar10 = 0;
        if (uVar9 != 0) {
          lVar10 = _atol(pcVar8);
        }
        goto LAB_00480fd6;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x100);
    lVar10 = 0;
LAB_00480fd6:
    puVar1[1] = lVar10;
    pcVar8 = (char *)(**(code **)(*param_2 + 0x10))(cVar4,10);
    FUN_00475260(pcVar8,cVar4,10);
    uVar9 = 0;
    do {
      if (pcVar8[uVar9] == '\0') {
        lVar10 = 0;
        if (uVar9 != 0) {
          lVar10 = _atol(pcVar8);
        }
        goto LAB_00481019;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x100);
    lVar10 = 0;
LAB_00481019:
    puVar1[2] = lVar10;
    pcVar8 = (char *)(**(code **)(*param_2 + 0x10))(cVar4,0xb);
    FUN_00475260(pcVar8,cVar4,0xb);
    uVar9 = 0;
    do {
      if (pcVar8[uVar9] == '\0') {
        lVar10 = 0;
        if (uVar9 != 0) {
          lVar10 = _atol(pcVar8);
        }
        goto LAB_00481065;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x100);
    lVar10 = 0;
LAB_00481065:
    puVar1[3] = lVar10;
    pcVar8 = (char *)(**(code **)(*param_2 + 0x10))(cVar4,0xc);
    FUN_00475260(pcVar8,cVar4,0xc);
    uVar9 = 0;
    do {
      if (pcVar8[uVar9] == '\0') {
        lVar10 = 0;
        if (uVar9 != 0) {
          lVar10 = _atol(pcVar8);
        }
        goto LAB_004810a8;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x100);
    lVar10 = 0;
LAB_004810a8:
    puVar1[4] = lVar10;
    pcVar8 = (char *)(**(code **)(*param_2 + 0x10))(cVar4,0xd);
    FUN_00475260(pcVar8,cVar4,0xd);
    uVar9 = 0;
    do {
      if (pcVar8[uVar9] == '\0') {
        lVar10 = 0;
        if (uVar9 != 0) {
          lVar10 = _atol(pcVar8);
        }
        goto LAB_004810eb;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x100);
    lVar10 = 0;
LAB_004810eb:
    puVar1[5] = lVar10;
    pcVar8 = (char *)(**(code **)(*param_2 + 0x10))(cVar4,0xe);
    FUN_00475260(pcVar8,cVar4,0xe);
    uVar9 = 0;
    do {
      if (pcVar8[uVar9] == '\0') {
        lVar10 = 0;
        if (uVar9 != 0) {
          lVar10 = _atol(pcVar8);
        }
        goto LAB_00481135;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x100);
    lVar10 = 0;
LAB_00481135:
    puVar1[6] = lVar10;
    pcVar8 = (char *)(**(code **)(*param_2 + 0x10))(cVar4,0xf);
    FUN_00475260(pcVar8,cVar4,0xf);
    uVar9 = 0;
    do {
      if (pcVar8[uVar9] == '\0') {
        lVar10 = 0;
        if (uVar9 != 0) {
          lVar10 = _atol(pcVar8);
        }
        goto LAB_00481178;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x100);
    lVar10 = 0;
LAB_00481178:
    puVar1[7] = lVar10;
    uVar6 = FUN_00475a90(cVar4,0x10);
    *(undefined2 *)(puVar1 + 8) = uVar6;
    uVar6 = FUN_00475a90(cVar4,0x11);
    *(undefined2 *)((int)puVar1 + 0x22) = uVar6;
    uVar9 = FUN_00475a90(cVar4,0x12);
    puVar1[9] = uVar9 & 0xffff;
    cVar4 = cVar11 + '\x01';
    bVar5 = cVar11 - 0x1f;
    if (0x95 < bVar5) {
      return;
    }
  } while( true );
}


// ==== FUN_004811d0 @ 0x004811d0 ====

void FUN_004811d0(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcStack_210;
  undefined1 auStack_202 [2];
  char local_200 [240];
  undefined1 auStack_110 [260];
  int iStack_c;
  
  pcStack_210 = s_StyleCodeIndex_009a574c;
  FUN_0044a580(local_200,&DAT_009a51bc);
  pcStack_210 = local_200;
  uVar4 = 0x1f;
  uVar1 = (**(code **)(*param_2 + 0x10))(0x1f,0x13);
  FUN_0047f100(uVar1,uVar4);
  FUN_0044a580(auStack_202 + -6,&DAT_009a51bc,s_StyleCode_009a5740);
  uVar4 = 0x1f;
  uVar1 = (**(code **)(*param_2 + 0x10))(0x1f,0x14,auStack_202 + -6);
  FUN_0047f100(uVar1,uVar4);
  uVar3 = 0;
  if (*(int *)(iStack_c + 0x85c) != 0) {
    do {
      uVar2 = FUN_004753b0(uVar3 + 0x20,0x13);
      uVar2 = uVar2 & 0xff;
      if (uVar2 != uVar3) {
        pcStack_210 = (char *)((uint)pcStack_210 & 0xffffff00);
        FUN_0044a580(&pcStack_210,s_Wrong_Item_Index____d____d_009a5724,uVar2,uVar3);
        FUN_00797b80(&pcStack_210);
        auStack_110[0] = 0;
        uVar1 = FUN_0044a580(auStack_110,s_File___s__Line___d_0099f0a0,
                             s___Loader_Article_Skill_cpp_009a51e4,0x12a);
        FUN_00797b80(uVar1);
        FUN_00797a40();
      }
      uVar1 = (**(code **)(*param_2 + 0x10))(uVar3 + 0x20,0x14);
      uVar1 = FUN_0047fe20(uVar1);
      uVar3 = uVar3 + 1;
      *(undefined4 *)(iStack_c + 0x80c + uVar2 * 4) = uVar1;
    } while (uVar3 < *(uint *)(iStack_c + 0x85c));
  }
  return;
}


// ==== FUN_00481310 @ 0x00481310 ====

void FUN_00481310(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00481320 @ 0x00481320 ====

void FUN_00481320(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5778;
  return;
}


// ==== FUN_00481330 @ 0x00481330 ====

void FUN_00481330(int *param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_2fc [4];
  undefined **ppuStack_2f8;
  undefined **ppuStack_2f4;
  undefined1 auStack_2f0 [480];
  undefined4 uStack_110;
  char acStack_10c [256];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e04b;
  pvStack_c = ExceptionList;
  uVar4 = 1;
  ExceptionList = &pvStack_c;
  uVar2 = (**(code **)(*param_1 + 0xc))();
  if (1 < uVar2) {
    uVar2 = 1;
    do {
      ppuStack_2f4 = &PTR_FUN_009a5784;
      _eh_vector_constructor_iterator_
                (auStack_2f0,0x60,5,(_func_void_void_ptr *)&LAB_00481580,FUN_004815a0);
      uVar5 = 0;
      uStack_110 = 0;
      uStack_4 = 0;
      pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(0,uVar2);
      FUN_0044a580(acStack_10c,&DAT_009a5768,&DAT_0099cf70);
      iVar1 = -(int)pcVar3;
      while (*pcVar3 == pcVar3[(int)(acStack_10c + iVar1)]) {
        if (*pcVar3 == '\0') goto LAB_004813e9;
        uVar5 = uVar5 + 1;
        pcVar3 = pcVar3 + 1;
        if (0xff < uVar5) {
LAB_004813e9:
          uStack_4 = 0xffffffff;
          ppuStack_2f4 = &PTR_FUN_009a5784;
          _eh_vector_destructor_iterator_(auStack_2f0,0x60,5,FUN_004815a0);
          ExceptionList = pvStack_c;
          return;
        }
      }
      FUN_00481740(param_1,uVar4,auStack_2fc);
      (**(code **)(*DAT_00b5aa2c + 4))(auStack_2fc);
      puStack_8 = (undefined1 *)0xffffffff;
      ppuStack_2f8 = &PTR_FUN_009a5784;
      _eh_vector_destructor_iterator_(&ppuStack_2f4,0x60,5,FUN_004815a0);
      uVar4 = uVar4 + 1;
      uVar2 = uVar4 & 0xffff;
      uVar5 = (**(code **)(*param_1 + 0xc))();
    } while (uVar2 < uVar5);
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00481490 @ 0x00481490 ====

void FUN_00481490(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a5768,&DAT_009a5760);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004814de;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004814de:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00481330(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00481540 @ 0x00481540 ====

void FUN_00481540(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5770;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00481560 @ 0x00481560 ====

void FUN_00481560(byte param_1)

{
  void *in_ECX;
  
  FUN_00481310();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004815a0 @ 0x004815a0 ====

void FUN_004815a0(void)

{
  int in_ECX;
  
  *(undefined ***)(in_ECX + 0x1c) = &PTR_FUN_009a5770;
  return;
}


// ==== FUN_004815b0 @ 0x004815b0 ====

void FUN_004815b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5784;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x60,5,FUN_004815a0);
  return;
}


// ==== FUN_004815d0 @ 0x004815d0 ====

void FUN_004815d0(byte param_1)

{
  void *in_ECX;
  
  FUN_004815b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004815f0 @ 0x004815f0 ====

long FUN_004815f0(undefined4 param_1,undefined4 param_2)

{
  char *_Str;
  uint uVar1;
  long lVar2;
  int *in_ECX;
  
  _Str = (char *)(**(code **)(*in_ECX + 0x10))(param_1,param_2);
  FUN_00475260(_Str,param_1,param_2);
  uVar1 = 0;
  do {
    if (_Str[uVar1] == '\0') {
      if (uVar1 == 0) {
        return 0;
      }
      lVar2 = _atol(_Str);
      return lVar2;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  return 0;
}


// ==== FUN_00481650 @ 0x00481650 ====

void FUN_00481650(void)

{
  int in_ECX;
  
  *(undefined ***)(in_ECX + 8) = &PTR_FUN_009a5784;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0xc),0x60,5,FUN_004815a0);
  return;
}


// ==== FUN_00481670 @ 0x00481670 ====

undefined4 FUN_00481670(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_200 [256];
  char local_100 [256];
  
  FUN_0044a580(local_200,&DAT_009a5768,&DAT_009a57c4);
  cVar1 = FUN_0044a440(local_200);
  if (cVar1 != '\0') {
    return 0;
  }
  FUN_0044a580(local_200,&DAT_009a5768,s_LIMIT_009a57bc);
  local_100[0] = FUN_0044a440(local_200);
  if (local_100[0] == '\0') {
    FUN_0044a580(local_100,s_Wrong_Set_Type____s_009a57a4,param_1);
    FUN_00797b80(local_100);
    local_200[0] = 0;
    uVar2 = FUN_0044a580(local_200,s_File___s__Line___d_0099f0a0,
                         s___Loader_Article_Shop_cpp_009a5788,0x97);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  return 1;
}


// ==== FUN_00481740 @ 0x00481740 ====

void FUN_00481740(int *param_1,undefined2 param_2,undefined2 *param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  short sVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  char *_Str;
  short sVar9;
  uint uStack_110;
  uint local_108;
  undefined1 local_100 [256];
  
  uVar5 = FUN_00475a90(0,param_2);
  *param_3 = uVar5;
  uVar5 = FUN_00475a90(1,param_2);
  param_3[1] = uVar5;
  iVar6 = FUN_004756e0(2,param_2);
  *(int *)(param_3 + 2) = iVar6;
  if (iVar6 == 0) {
    local_100[0] = 0;
    uVar7 = FUN_0044a580(local_100,s_ITEMSHOP_____shop_index__d__>_Ma_009a57c8,*param_3);
    FUN_00797b80(uVar7);
    local_100[0] = 0;
    uVar7 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                         s___Loader_Article_Shop_cpp_009a5788,0x67);
    FUN_00797b80(uVar7);
    FUN_00797a40();
  }
  iVar6 = FUN_004815f0(3,param_2);
  *(int *)(param_3 + 0xf6) = *(int *)(param_3 + 0xf6) + iVar6;
  local_108 = 0;
  if (*(int *)(param_3 + 0xf6) != 0) {
    uVar8 = 0;
    sVar3 = 6;
    do {
      puVar1 = param_3 + uVar8 * 0x30 + 6;
      FUN_0047c610(sVar3 + -2,param_2,puVar1);
      uVar5 = FUN_00475a90(sVar3 + -1,param_2);
      puVar1[0xd] = uVar5;
      _Str = (char *)(**(code **)(*param_1 + 0x10))(sVar3,param_2);
      FUN_00475260(_Str,sVar3,param_2);
      uVar8 = 0;
      do {
        if (_Str[uVar8] == '\0') {
          iVar6 = 0;
          if (uVar8 != 0) {
            iVar6 = _atol(_Str);
          }
          goto LAB_00481885;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0x100);
      iVar6 = 0;
LAB_00481885:
      *(int *)(puVar1 + 0x2e) = *(int *)(puVar1 + 0x2e) + iVar6;
      uVar8 = 0;
      uStack_110 = 0;
      sVar9 = sVar3;
      if (*(int *)(puVar1 + 0x2e) != 0) {
        do {
          puVar2 = puVar1 + uVar8 * 6 + 0x10;
          uVar5 = FUN_00475a90(sVar9 + 1,param_2);
          *puVar2 = uVar5;
          uVar7 = (**(code **)(*param_1 + 0x10))(sVar9 + 2,param_2);
          uVar7 = FUN_00481670(uVar7);
          *(undefined4 *)(puVar2 + 2) = uVar7;
          sVar9 = sVar9 + 3;
          uVar4 = FUN_004753b0(sVar9,param_2);
          *(undefined1 *)(puVar2 + 4) = uVar4;
          uStack_110 = uStack_110 + 1;
          uVar8 = uStack_110 & 0xffff;
        } while (uVar8 < *(uint *)(puVar1 + 0x2e));
      }
      sVar3 = sVar3 + 0x12;
      local_108 = local_108 + 1;
      uVar8 = local_108 & 0xffff;
    } while (uVar8 < *(uint *)(param_3 + 0xf6));
  }
  return;
}


// ==== FUN_00481940 @ 0x00481940 ====

void FUN_00481940(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00481950 @ 0x00481950 ====

void FUN_00481950(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5828;
  return;
}


// ==== FUN_00481960 @ 0x00481960 ====

void FUN_00481960(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_20a [2];
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a5820);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004819ae;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004819ae:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  uVar1 = 0;
  iVar3 = (**(code **)(*piVar2 + 8))();
  if (iVar3 != 0) {
    do {
      (**(code **)(*DAT_00b5aba4 + 4))(auStack_20a + -6);
      uVar1 = uVar1 + 1;
      uVar4 = (**(code **)(*piVar2 + 8))();
    } while (uVar1 < uVar4);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar2);
  return;
}


// ==== FUN_00481a40 @ 0x00481a40 ====

void FUN_00481a40(byte param_1)

{
  void *in_ECX;
  
  FUN_00481940();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00481a60 @ 0x00481a60 ====

void FUN_00481a60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00481a70 @ 0x00481a70 ====

void FUN_00481a70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5844;
  return;
}


// ==== FUN_00481a80 @ 0x00481a80 ====

void FUN_00481a80(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 uStack_3b4;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580();
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00481ad4;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00481ad4:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  FUN_00482550();
  uVar4 = 1;
  uVar1 = (**(code **)(*piVar2 + 0xc))();
  if (1 < uVar1) {
    do {
      FUN_004753b0();
      FUN_004753b0();
      FUN_00482560();
      FUN_00482560();
      FUN_004753b0();
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_00475260();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atol(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_00475260();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atol(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      FUN_004753b0();
      FUN_004753b0();
      FUN_00475a90();
      FUN_00475a90();
      FUN_00475a90();
      FUN_00475a90();
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_00475260();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atol(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_00475260();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atol(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      FUN_004753b0();
      FUN_004753b0();
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      uStack_3b4 = 0x482344;
      FUN_004772e0();
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      uStack_3b4 = 0x25;
      FUN_004772e0(pcVar3);
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            uStack_3b4 = 0x4823c4;
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      uStack_3b4 = 0x26;
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
      FUN_004772e0(pcVar3,0x26,uVar4);
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))(0x27,uVar4);
      FUN_004772e0(pcVar3,0x27,uVar4);
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atof(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))(0x28,uVar4);
      FUN_00475260(pcVar3,0x28,uVar4);
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atol(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      FUN_004753b0(0x29,uVar4);
      FUN_004753b0(0x2a,uVar4);
      (**(code **)(*DAT_00b5abac + 4))(&uStack_3b4);
      uVar4 = uVar4 + 1;
      uVar1 = (**(code **)(*piVar2 + 0xc))();
    } while (uVar4 < uVar1);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))();
  return;
}


// ==== FUN_00482530 @ 0x00482530 ====

void FUN_00482530(byte param_1)

{
  void *in_ECX;
  
  FUN_00481a60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00482550 @ 0x00482550 ====

void FUN_00482550(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  return;
}


// ==== FUN_00482560 @ 0x00482560 ====

void FUN_00482560(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  char *pcVar4;
  uint uVar5;
  undefined1 auStack_1fe [246];
  undefined1 auStack_108 [264];
  
  iVar2 = (**(code **)(*in_ECX + 0x10))(param_1,param_2);
  uVar5 = 0;
  pcVar4 = param_1;
  do {
    cVar1 = pcVar4[iVar2 - (int)param_1];
    *pcVar4 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar5 = uVar5 + 1;
    pcVar4 = pcVar4 + 1;
  } while (uVar5 < 0x1e);
  uVar3 = (**(code **)(*in_ECX + 0x14))(param_1,param_2);
  FUN_0044a580(auStack_1fe + -10,s_GetString_Error____s___Cell__d____009a4dcc,uVar3);
  FUN_00797b80(auStack_1fe + -10);
  auStack_108[0] = 0;
  uVar3 = FUN_0044a580(auStack_108,s_File___s__Line___d_0099f0a0,
                       s_d__usa_24_0_1_2__develop_share_l_009a4a50,0x6a);
  FUN_00797b80(uVar3);
  FUN_00797a40();
  return;
}


// ==== FUN_00482610 @ 0x00482610 ====

void FUN_00482610(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00482620 @ 0x00482620 ====

void FUN_00482620(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5860;
  return;
}


// ==== FUN_00482630 @ 0x00482630 ====

void FUN_00482630(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_22a [2];
  undefined4 auStack_228 [8];
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a5858);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0048267e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0048267e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  uVar5 = 1;
  uVar1 = (**(code **)(*piVar2 + 8))();
  if (1 < uVar1) {
    do {
      FUN_004753b0(uVar5,0);
      FUN_004756e0(uVar5,1);
      uVar1 = 2;
      iVar3 = (**(code **)(*piVar2 + 0xc))();
      if (2 < iVar3 - 2U) {
        do {
          uVar4 = FUN_004756e0(uVar5,uVar1);
          *(undefined4 *)(auStack_22a + uVar1 * 4 + -6) = uVar4;
          uVar1 = uVar1 + 1;
          iVar3 = (**(code **)(*piVar2 + 0xc))();
        } while (uVar1 < iVar3 - 2U);
      }
      FUN_004756e0(uVar5,7);
      FUN_004756e0(uVar5,8);
      (**(code **)(*DAT_00b5abb0 + 4))(auStack_22a + -6);
      uVar5 = uVar5 + 1;
      uVar1 = (**(code **)(*piVar2 + 8))();
    } while (uVar5 < uVar1);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar2);
  return;
}


// ==== FUN_00482780 @ 0x00482780 ====

void FUN_00482780(byte param_1)

{
  void *in_ECX;
  
  FUN_00482610();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004827a0 @ 0x004827a0 ====

void FUN_004827a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_004827b0 @ 0x004827b0 ====

void FUN_004827b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5884;
  return;
}


// ==== FUN_004827c0 @ 0x004827c0 ====

void FUN_004827c0(int *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *unaff_ESI;
  undefined4 auStack_288 [18];
  undefined4 local_240 [12];
  undefined4 uStack_210;
  undefined1 auStack_20c [2];
  char acStack_20a [6];
  undefined2 uStack_204;
  char acStack_188 [136];
  char local_100 [256];
  
  iVar6 = 2;
LAB_00482890:
  FUN_0044a580(local_100,&DAT_009a5878,s_ItemSocket_009a586c + 0xb);
  pcVar1 = (char *)(**(code **)(*param_1 + 0x10))(iVar6,0);
  uVar5 = 0;
  iVar7 = -(int)pcVar1;
  do {
    if (*pcVar1 != pcVar1[(int)(local_100 + iVar7)]) {
      FUN_00479840();
      uStack_204 = FUN_00475a90(iVar6,0);
      uVar2 = (**(code **)(*param_1 + 0x10))(iVar6,1);
      FUN_0047b350(acStack_188,&DAT_009a587c,uVar2);
      uVar5 = 0;
      goto LAB_00482930;
    }
    if (*pcVar1 == '\0') break;
    uVar5 = uVar5 + 1;
    pcVar1 = pcVar1 + 1;
  } while (uVar5 < 0x100);
  goto LAB_00482a38;
  while (uVar5 = uVar5 + 1, uVar5 < 0x80) {
LAB_00482930:
    acStack_20a[uVar5] = acStack_188[uVar5];
    if (acStack_188[uVar5] == '\0') goto LAB_00482954;
  }
  acStack_20a[0] = '\0';
LAB_00482954:
  piVar3 = (int *)(**(code **)(*DAT_00b5abb4 + 8))();
  (**(code **)(*piVar3 + 4))(auStack_20c);
  iVar7 = 2;
  do {
    pcVar1 = (char *)(**(code **)(*param_1 + 0x10))(iVar6,iVar7);
    FUN_00475260(pcVar1,iVar6,iVar7);
    uVar5 = 0;
    do {
      if (pcVar1[uVar5] == '\0') {
        if ((uVar5 != 0) && (lVar4 = _atol(pcVar1), lVar4 != 0)) {
          (**(code **)(*unaff_ESI + 0x10))(auStack_288[iVar7 + -2]);
        }
        break;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x100);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x14);
  iVar7 = 0x14;
  do {
    pcVar1 = (char *)(**(code **)(*param_1 + 0x10))(iVar6,iVar7);
    FUN_00475260(pcVar1,iVar6,iVar7);
    uVar5 = 0;
    do {
      if (pcVar1[uVar5] == '\0') {
        if ((uVar5 != 0) && (lVar4 = _atol(pcVar1), lVar4 != 0)) {
          (**(code **)(*unaff_ESI + 0x10))(auStack_288[iVar7 + -2]);
        }
        break;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x100);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x19);
  (**(code **)(*DAT_00b5abb4 + 0xc))(uStack_210,unaff_ESI);
LAB_00482a38:
  iVar6 = iVar6 + 1;
  if (0x1ff < iVar6) {
    return;
  }
  goto LAB_00482890;
}


// ==== FUN_00482a60 @ 0x00482a60 ====

void FUN_00482a60(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a5878,s_ItemSocket_009a586c);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00482aae;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00482aae:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_004827c0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00482b10 @ 0x00482b10 ====

void FUN_00482b10(byte param_1)

{
  void *in_ECX;
  
  FUN_004827a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00482b30 @ 0x00482b30 ====

void FUN_00482b30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00482b40 @ 0x00482b40 ====

void FUN_00482b40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a58a0;
  return;
}


// ==== FUN_00482b50 @ 0x00482b50 ====

void FUN_00482b50(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a5898,s_ItemSet_009a5890);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00482b9e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00482b9e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00482c20(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00482c00 @ 0x00482c00 ====

void FUN_00482c00(byte param_1)

{
  void *in_ECX;
  
  FUN_00482b30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00482c20 @ 0x00482c20 ====

void FUN_00482c20(int *param_1)

{
  undefined2 uVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  char acStack_50e [250];
  undefined2 uStack_414;
  undefined1 auStack_412 [26];
  undefined2 uStack_3f8;
  undefined4 uStack_3f4;
  undefined4 auStack_3ec [251];
  
  FUN_00479840();
  uVar5 = 1;
  uVar2 = (**(code **)(*param_1 + 8))();
  if (uVar2 < 2) {
    return;
  }
  do {
    FUN_0044a580(acStack_50e + 2,&DAT_009a5898,&DAT_0099cf70);
    pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(uVar5,0);
    uVar2 = 0;
    iVar8 = -6 - (int)pcVar3;
    while (*pcVar3 == pcVar3[(int)(acStack_50e + iVar8)]) {
      if (*pcVar3 == '\0') goto LAB_00482d69;
      uVar2 = uVar2 + 1;
      pcVar3 = pcVar3 + 1;
      if (0xff < uVar2) goto LAB_00482d69;
    }
    uStack_414 = FUN_00475a90(uVar5,0);
    FUN_0047c610(uVar5,1,auStack_412);
    uStack_3f4 = FUN_004756e0(uVar5,2);
    uStack_3f8 = FUN_00475a90(uVar5,3);
    iVar7 = 4;
    puVar6 = auStack_3ec;
    iVar8 = 0x32;
    do {
      uVar1 = FUN_00475a90(uVar5,iVar7);
      *(undefined2 *)(puVar6 + -1) = uVar1;
      uVar4 = FUN_004756e0(uVar5,iVar7 + 1);
      *puVar6 = uVar4;
      uVar4 = FUN_004756e0(uVar5,iVar7 + 2);
      puVar6[1] = uVar4;
      uVar4 = FUN_004756e0(uVar5,iVar7 + 3);
      puVar6[2] = uVar4;
      uVar4 = FUN_004756e0(uVar5,iVar7 + 4);
      puVar6[3] = uVar4;
      iVar7 = iVar7 + 5;
      puVar6 = puVar6 + 5;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    (**(code **)(*DAT_00b5a760 + 4))(&uStack_414);
LAB_00482d69:
    uVar5 = uVar5 + 1;
    uVar2 = (**(code **)(*param_1 + 8))();
    if (uVar2 <= uVar5) {
      return;
    }
  } while( true );
}


// ==== FUN_00482d90 @ 0x00482d90 ====

void FUN_00482d90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00482db0 @ 0x00482db0 ====

void FUN_00482db0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a58c0;
  return;
}


// ==== FUN_00482dc0 @ 0x00482dc0 ====

void FUN_00482dc0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcStack_2b0;
  undefined1 auStack_2a2 [2];
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580();
  uVar2 = 0;
  do {
    local_208[uVar2] = local_100[uVar2];
    if (local_100[uVar2] == '\0') goto LAB_00482e14;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_208[0] = '\0';
LAB_00482e14:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  FUN_00482f90();
  uVar6 = 2;
  uVar2 = (**(code **)(*piVar3 + 8))();
  if (2 < uVar2) {
    do {
      pcStack_2b0 = s_ItemOption_009a58ac + 0xb;
      FUN_0044a580(&local_104,&DAT_009a58b8);
      pcStack_2b0 = (char *)0x0;
      pcVar4 = (char *)(**(code **)(*piVar3 + 0x10))(uVar6);
      uVar2 = 0;
      iVar1 = 0xfc - (int)pcVar4;
      do {
        if (*pcVar4 != pcVar4[(int)(local_208 + iVar1)]) {
          FUN_00475a90(uVar6,0);
          FUN_00475a90(uVar6,1);
          iVar1 = *DAT_00b5aa08;
          uVar5 = (**(code **)(*piVar3 + 0x10))(uVar6,2);
          (**(code **)(iVar1 + 4))(uVar5);
          FUN_00482fa0(uVar6,3,auStack_2a2 + -6);
          FUN_00477a70(uVar6,4);
          FUN_00477a70(uVar6,5);
          (**(code **)(*DAT_00b5abb8 + 4))(&pcStack_2b0);
          break;
        }
        if (*pcVar4 == '\0') break;
        uVar2 = uVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (uVar2 < 0x100);
      uVar6 = uVar6 + 1;
      uVar2 = (**(code **)(*piVar3 + 8))();
    } while (uVar6 < uVar2);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))();
  return;
}


// ==== FUN_00482f70 @ 0x00482f70 ====

void FUN_00482f70(byte param_1)

{
  void *in_ECX;
  
  FUN_00482d90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00482f90 @ 0x00482f90 ====

void FUN_00482f90(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00482fa0 @ 0x00482fa0 ====

void FUN_00482fa0(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  char *pcVar4;
  uint uVar5;
  undefined1 auStack_1fe [246];
  undefined1 auStack_108 [264];
  
  iVar2 = (**(code **)(*in_ECX + 0x10))(param_1,param_2);
  uVar5 = 0;
  pcVar4 = param_1;
  do {
    cVar1 = pcVar4[iVar2 - (int)param_1];
    *pcVar4 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar5 = uVar5 + 1;
    pcVar4 = pcVar4 + 1;
  } while (uVar5 < 0x80);
  uVar3 = (**(code **)(*in_ECX + 0x14))(param_1,param_2);
  FUN_0044a580(auStack_1fe + -10,s_GetString_Error____s___Cell__d____009a4dcc,uVar3);
  FUN_00797b80(auStack_1fe + -10);
  auStack_108[0] = 0;
  uVar3 = FUN_0044a580(auStack_108,s_File___s__Line___d_0099f0a0,
                       s_d__usa_24_0_1_2__develop_share_l_009a4a50,0x6a);
  FUN_00797b80(uVar3);
  FUN_00797a40();
  return;
}


// ==== FUN_00483050 @ 0x00483050 ====

void FUN_00483050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00483060 @ 0x00483060 ====

void FUN_00483060(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5988;
  return;
}


// ==== FUN_00483070 @ 0x00483070 ====

uint FUN_00483070(undefined1 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_00483940(0x2d);
  uVar1 = 0;
  do {
    if ((&param_1)[uVar1] == '\0') goto LAB_00483093;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  uVar1 = 0;
LAB_00483093:
  uVar2 = 0;
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      uVar2 = uVar2 | (int)(char)(&param_1)[uVar3] - 0x30U;
      if (uVar3 < uVar1 - 1) {
        uVar2 = uVar2 * 2;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return uVar2;
}


// ==== FUN_004830c0 @ 0x004830c0 ====

void FUN_004830c0(undefined4 param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  int *piVar7;
  char *pcVar8;
  undefined4 *puVar9;
  long lVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 auStackY_770 [54];
  undefined4 uStackY_698;
  char *pcStackY_694;
  uint uStackY_690;
  int iStack_64c;
  long alStack_5a4 [4];
  undefined **ppuStack_594;
  int iStack_570;
  ushort auStack_56c [6];
  undefined4 uStack_560;
  undefined **ppuStack_55c;
  undefined2 uStack_558;
  undefined2 uStack_556;
  undefined2 uStack_554;
  undefined2 uStack_552;
  undefined2 uStack_550;
  undefined2 uStack_54e;
  undefined4 uStack_54c;
  undefined2 uStack_548;
  undefined2 uStack_546;
  undefined2 uStack_544;
  undefined4 uStack_540;
  undefined2 uStack_53c;
  undefined2 uStack_53a;
  undefined4 uStack_538;
  undefined4 uStack_534;
  undefined1 uStack_52c;
  char local_514 [256];
  undefined4 local_414;
  undefined1 local_410;
  undefined1 local_40f;
  undefined1 local_40e;
  char local_40c [492];
  undefined1 uStack_220;
  undefined1 uStack_120;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e06b;
  pvStack_c = ExceptionList;
  local_514[0] = '\0';
  ExceptionList = &pvStack_c;
  FUN_0044a580();
  uVar6 = 0;
  do {
    local_514[uVar6] = local_40c[uVar6];
    if (local_40c[uVar6] == '\0') goto LAB_00483134;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x100);
  local_514[0] = '\0';
LAB_00483134:
  local_414 = param_1;
  local_410 = 10;
  local_40f = 0x2c;
  local_40e = 1;
  piVar7 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  ppuStack_594 = &PTR_FUN_009a5978;
  uStack_560 = 0;
  ppuStack_55c = &PTR_FUN_009a5980;
  uStack_54c = 0;
  puStack_8 = (undefined1 *)0x0;
  uVar12 = 1;
  uVar6 = (**(code **)(*piVar7 + 8))();
  if (uVar6 < 2) {
LAB_00483911:
    (**(code **)(*DAT_00b5aa34 + 0xc))();
    ExceptionList = pvStack_14;
    return;
  }
  do {
    FUN_0044a580();
    pcVar8 = (char *)(**(code **)(*piVar7 + 0x10))();
    uVar6 = 0;
    iVar11 = 0xfc - (int)pcVar8;
    while (*pcVar8 == pcVar8[(int)(local_514 + iVar11)]) {
      if (*pcVar8 == '\0') goto LAB_004838fe;
      uVar6 = uVar6 + 1;
      pcVar8 = pcVar8 + 1;
      if (0xff < uVar6) goto LAB_004838fe;
    }
    FUN_00797a50();
    uVar2 = FUN_00475a90();
    iStack_64c = CONCAT22(iStack_64c._2_2_,uVar2);
    FUN_00483a00();
    FUN_00477a70();
    FUN_00477a70();
    FUN_00477a70();
    FUN_00475a90();
    FUN_00477a70();
    puVar9 = (undefined4 *)(**(code **)(*piVar7 + 0x10))();
    puVar13 = auStackY_770;
    for (iVar11 = 0x40; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
    FUN_00483070();
    FUN_004756e0();
    FUN_00475a90();
    FUN_004756e0();
    FUN_00475a90();
    FUN_00475a90();
    FUN_00475a90();
    FUN_00475a90();
    FUN_004756e0();
    FUN_004753b0();
    FUN_004753b0();
    if (((iStack_64c == 0) || (iStack_64c == 3)) || (uStack_52c = 1, iStack_64c == 1)) {
      uStack_52c = 0;
    }
    FUN_00475a90();
    FUN_00475a90();
    FUN_00475a90();
    FUN_004756e0();
    FUN_004756e0();
    FUN_004756e0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    FUN_004753b0();
    if (iStack_570 != 0) {
      local_40c[0xec] = 0;
      FUN_0044a580();
      FUN_00797b80();
      FUN_00797a40();
    }
    iVar11 = 6;
    do {
      sVar3 = FUN_00475a90();
      pcVar8 = (char *)(**(code **)(*piVar7 + 0x10))();
      FUN_00475260();
      uVar6 = 0;
      do {
        if (pcVar8[uVar6] == '\0') {
          lVar10 = 0;
          if (uVar6 != 0) {
            lVar10 = _atol(pcVar8);
          }
          goto LAB_00483579;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0x100);
      lVar10 = 0;
LAB_00483579:
      if (sVar3 != 0) {
        iStack_570 = iStack_570 + 1;
        *(short *)(alStack_5a4 + iStack_570 * 2 + -1) = sVar3;
        alStack_5a4[iStack_570 * 2] = lVar10;
      }
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    if (ppuStack_55c != (undefined **)0x0) {
      uStack_220 = 0;
      FUN_0044a580();
      FUN_00797b80();
      FUN_00797a40();
    }
    iVar11 = 3;
    do {
      uVar4 = FUN_00475a90();
      uVar5 = FUN_00475a90();
      if (uVar5 < uVar4) {
        uStack_120 = 0;
        FUN_0044a580();
        FUN_00797b80();
        FUN_00797a40();
      }
      if (uVar4 != 0) {
        ppuStack_55c = (undefined **)((int)ppuStack_55c + 1);
        auStack_56c[(int)ppuStack_55c * 2] = uVar4;
        auStack_56c[(int)ppuStack_55c * 2 + 1] = uVar5;
      }
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    uVar1 = FUN_004753b0();
    uStack_54c = CONCAT31(uStack_54c._1_3_,uVar1);
    uStack_558 = FUN_00475a90();
    uStack_556 = FUN_00475a90();
    uStack_554 = FUN_00475a90();
    uStack_552 = FUN_00475a90();
    uStack_550 = FUN_00475a90();
    uStack_54e = FUN_00475a90();
    uVar1 = FUN_004753b0();
    uStack_54c._0_2_ = CONCAT11(uVar1,(undefined1)uStack_54c);
    uVar1 = FUN_004753b0();
    uStack_54c._0_3_ = CONCAT12(uVar1,(undefined2)uStack_54c);
    uStack_548 = FUN_00475a90();
    uStack_546 = FUN_00475a90();
    uStack_544 = FUN_00475a90();
    uStack_540 = FUN_004756e0();
    uStack_53c = FUN_00475a90();
    uStack_53a = FUN_00475a90();
    uStack_538 = FUN_004756e0();
    uStack_534 = FUN_004756e0();
    pcVar8 = (char *)(**(code **)(*piVar7 + 0x10))();
    FUN_00475260();
    uVar6 = 0;
    do {
      if (pcVar8[uVar6] == '\0') {
        if ((uVar6 == 0) || (lVar10 = _atol(pcVar8), lVar10 == 0)) {
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
        goto LAB_00483822;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x100);
    uVar1 = 0;
LAB_00483822:
    uStack_538 = CONCAT31(uStack_538._1_3_,uVar1);
    pcVar8 = (char *)(**(code **)(*piVar7 + 0x10))();
    uStackY_690 = 0x483842;
    FUN_004772e0();
    uVar6 = 0;
    do {
      if (pcVar8[uVar6] == '\0') {
        if (uVar6 != 0) {
          _atof(pcVar8);
        }
        break;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x100);
    pcVar8 = (char *)(**(code **)(*piVar7 + 0x10))();
    uStackY_698 = 0x483897;
    pcStackY_694 = pcVar8;
    uStackY_690 = uVar12;
    FUN_004772e0();
    uVar6 = 0;
    do {
      if (pcVar8[uVar6] == '\0') {
        if (uVar6 != 0) {
          uStackY_690 = 0x4838c4;
          _atof(pcVar8);
        }
        break;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x100);
    pcStackY_694 = (char *)0x4838e6;
    uStackY_690 = uVar12;
    FUN_00475a90();
    uStackY_690 = 0x4838fe;
    (**(code **)(*DAT_00b5a738 + 4))();
LAB_004838fe:
    uVar12 = uVar12 + 1;
    uVar6 = (**(code **)(*piVar7 + 8))();
    if (uVar6 <= uVar12) goto LAB_00483911;
  } while( true );
}


// ==== FUN_00483940 @ 0x00483940 ====

void FUN_00483940(char param_1)

{
  int in_ECX;
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (*(char *)(uVar2 + in_ECX) == '\0') goto LAB_0048395a;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  uVar2 = 0;
LAB_0048395a:
  uVar1 = 0;
  if (uVar2 != 0) {
    do {
      if (*(char *)(uVar1 + in_ECX) == param_1) {
        FUN_00797a80(uVar1 + in_ECX,uVar1 + 1 + in_ECX,(uVar2 - uVar1) + -1);
        *(undefined1 *)((uVar2 - 1) + in_ECX) = 0;
        uVar2 = uVar2 - 1;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  return;
}


// ==== FUN_004839a0 @ 0x004839a0 ====

void FUN_004839a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5978;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004839c0 @ 0x004839c0 ====

void FUN_004839c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5980;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004839e0 @ 0x004839e0 ====

void FUN_004839e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00483050();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00483a00 @ 0x00483a00 ====

void FUN_00483a00(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  char *pcVar4;
  uint uVar5;
  undefined1 auStack_1fe [246];
  undefined1 auStack_108 [264];
  
  iVar2 = (**(code **)(*in_ECX + 0x10))(param_1,param_2);
  uVar5 = 0;
  pcVar4 = param_1;
  do {
    cVar1 = pcVar4[iVar2 - (int)param_1];
    *pcVar4 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar5 = uVar5 + 1;
    pcVar4 = pcVar4 + 1;
  } while (uVar5 < 0x40);
  uVar3 = (**(code **)(*in_ECX + 0x14))(param_1,param_2);
  FUN_0044a580(auStack_1fe + -10,s_GetString_Error____s___Cell__d____009a4dcc,uVar3);
  FUN_00797b80(auStack_1fe + -10);
  auStack_108[0] = 0;
  uVar3 = FUN_0044a580(auStack_108,s_File___s__Line___d_0099f0a0,
                       s_d__usa_24_0_1_2__develop_share_l_009a4a50,0x6a);
  FUN_00797b80(uVar3);
  FUN_00797a40();
  return;
}


// ==== FUN_00483ab0 @ 0x00483ab0 ====

void FUN_00483ab0(void)

{
  int in_ECX;
  
  *(undefined ***)(in_ECX + 0xe8) = &PTR_FUN_009a5980;
  *(undefined ***)(in_ECX + 0xb0) = &PTR_FUN_009a5978;
  return;
}


// ==== FUN_00483ad0 @ 0x00483ad0 ====

void FUN_00483ad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6a6c;
  return;
}


// ==== FUN_00483ae0 @ 0x00483ae0 ====

void FUN_00483ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6a84;
  return;
}


// ==== FUN_00483af0 @ 0x00483af0 ====

void FUN_00483af0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6adc;
  return;
}


// ==== FUN_00483b00 @ 0x00483b00 ====

void FUN_00483b00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6a6c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00483b20 @ 0x00483b20 ====

void FUN_00483b20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6a84;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00483b40 @ 0x00483b40 ====

void FUN_00483b40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6adc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00483b60 @ 0x00483b60 ====

void FUN_00483b60(int param_1)

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
  } while (uVar3 < 0x100);
  *in_ECX = '\0';
  return;
}


// ==== FUN_00483b90 @ 0x00483b90 ====

void FUN_00483b90(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e088;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a6af4;
  local_4 = 0;
  for (iVar1 = (**(code **)(*(int *)in_ECX[2] + 8))(); iVar1 != 0;
      iVar1 = (**(code **)(*(int *)in_ECX[2] + 0x40))(iVar1)) {
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009a4184;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00483c10 @ 0x00483c10 ====

uint FUN_00483c10(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  do {
    if (*(char *)(uVar1 + param_1) == '\0') goto LAB_00483c2a;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  uVar1 = 0;
LAB_00483c2a:
  uVar2 = 0;
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      if ((*(char *)(uVar3 + param_1) != '-') &&
         (uVar2 = uVar2 | (int)*(char *)(uVar3 + param_1) - 0x30U, uVar3 < uVar1 - 1)) {
        uVar2 = uVar2 * 2;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return uVar2;
}


// ==== FUN_00483c60 @ 0x00483c60 ====

uint FUN_00483c60(int param_1,char *param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  undefined1 local_104 [2];
  undefined1 auStack_102 [258];
  
  uVar1 = 0;
  do {
    if (param_2[uVar1] == '\0') goto LAB_00483c85;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  uVar1 = 0;
LAB_00483c85:
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      if ((param_2[uVar4] < '0') || ('9' < param_2[uVar4])) {
        FUN_00483b60(param_2);
        piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_104);
        if (piVar2 == (int *)0x0) {
          uVar3 = FUN_0044a580(local_104 + -4,s_CANNOT_FIND_ITEM_CODE____s_009a6924,param_2);
          FUN_00797b80(uVar3);
          uVar3 = FUN_0044a580(local_104 + -4,s_File___s__Line___d_009a695c,
                               s___Loader_Article_Item_cpp_009a6940,0x1c1);
          FUN_00797b80(uVar3);
          FUN_00797a40();
          return 0;
        }
        return *(uint *)(*piVar2 + 0x100);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  uVar1 = 0;
  do {
    if (param_2[uVar1] == '\0') {
      if (uVar1 == 0) {
        return param_1 << 8;
      }
      uVar1 = _atol(param_2);
      return param_1 << 8 | uVar1;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  return param_1 << 8;
}


// ==== FUN_00483d90 @ 0x00483d90 ====

long FUN_00483d90(char *param_1)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  char local_100 [256];
  
  uVar2 = 0;
  do {
    if (param_1[uVar2] == '\0') goto LAB_00483db2;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  uVar2 = 0;
LAB_00483db2:
  uVar6 = 0;
  if (uVar2 != 0) {
    do {
      if ((param_1[uVar6] < '0') || ('9' < param_1[uVar6])) {
        FUN_0044a580(local_100,&DAT_009a6a64,s_GENERAL_009a6970);
        uVar2 = 0;
        pcVar4 = param_1;
        do {
          if (*pcVar4 != pcVar4[(int)(local_100 + -(int)param_1)]) {
            FUN_0044a580(local_100,&DAT_009a6a64,s_STONE_009a6978);
            uVar2 = 0;
            pcVar4 = param_1;
            do {
              if (*pcVar4 != pcVar4[(int)(local_100 + -(int)param_1)]) {
                FUN_0044a580(local_100,&DAT_009a6a64,&DAT_009a6980);
                uVar2 = 0;
                pcVar4 = param_1;
                do {
                  if (*pcVar4 != pcVar4[(int)(local_100 + -(int)param_1)]) {
                    FUN_0044a580(local_100,&DAT_009a6a64,s_SCROLL_009a6988);
                    cVar1 = FUN_0044a440(local_100);
                    if (cVar1 != '\0') {
                      return 3;
                    }
                    FUN_0044a580(local_100,&DAT_009a6a64,s_WEAPON_009a6990);
                    cVar1 = FUN_0044a440(local_100);
                    if (cVar1 != '\0') {
                      return 4;
                    }
                    FUN_0044a580(local_100,&DAT_009a6a64,s_ARMOR_009a6998);
                    cVar1 = FUN_0044a440(local_100);
                    if (cVar1 == '\0') {
                      FUN_0044a580(local_100,&DAT_009a6a64,s_OPTION_009a69a0);
                      local_100[0] = FUN_0044a440(local_100);
                      if (local_100[0] == '\0') {
                        uVar5 = FUN_0044a580(local_100,s_CANNOT_FIND_ITEM_TYPE____s_009a69a8,param_1
                                            );
                        FUN_00797b80(uVar5);
                        local_100[0] = '\0';
                        uVar5 = FUN_0044a580(local_100,s_File___s__Line___d_009a69e0,
                                             s___Loader_Article_Item_cpp_009a69c4,0x1fd);
                        FUN_00797b80(uVar5);
                        FUN_00797a40();
                        return 0;
                      }
                    }
                    return 5;
                  }
                  if (*pcVar4 == '\0') {
                    return 2;
                  }
                  uVar2 = uVar2 + 1;
                  pcVar4 = pcVar4 + 1;
                } while (uVar2 < 0x100);
                return 2;
              }
              if (*pcVar4 == '\0') {
                return 1;
              }
              uVar2 = uVar2 + 1;
              pcVar4 = pcVar4 + 1;
            } while (uVar2 < 0x100);
            return 1;
          }
          if (*pcVar4 == '\0') {
            return 0;
          }
          uVar2 = uVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (uVar2 < 0x100);
        return 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar2);
  }
  uVar2 = 0;
  do {
    if (param_1[uVar2] == '\0') {
      if (uVar2 == 0) {
        return 0;
      }
      lVar3 = _atol(param_1);
      return lVar3;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  return 0;
}


// ==== FUN_00484020 @ 0x00484020 ====

long FUN_00484020(char *param_1)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  char local_100 [256];
  
  uVar2 = 0;
  do {
    if (param_1[uVar2] == '\0') goto LAB_00484042;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  uVar2 = 0;
LAB_00484042:
  uVar6 = 0;
  if (uVar2 != 0) {
    do {
      if ((param_1[uVar6] < '0') || ('9' < param_1[uVar6])) {
        FUN_0044a580(local_100,&DAT_009a6a64,s_NORMAL_009a69f4);
        uVar2 = 0;
        pcVar4 = param_1;
        do {
          if (*pcVar4 != pcVar4[(int)(local_100 + -(int)param_1)]) {
            FUN_0044a580(local_100,&DAT_009a6a64,&DAT_009a69fc);
            uVar2 = 0;
            pcVar4 = param_1;
            do {
              if (*pcVar4 != pcVar4[(int)(local_100 + -(int)param_1)]) {
                FUN_0044a580(local_100,&DAT_009a6a64,s_EVENT_009a6a00);
                uVar2 = 0;
                pcVar4 = param_1;
                do {
                  if (*pcVar4 != pcVar4[(int)(local_100 + -(int)param_1)]) {
                    FUN_0044a580(local_100,&DAT_009a6a64,s_LEGEND_009a6a08);
                    cVar1 = FUN_0044a440(local_100);
                    if (cVar1 != '\0') {
                      return 3;
                    }
                    FUN_0044a580(local_100,&DAT_009a6a64,&DAT_009a6a10);
                    cVar1 = FUN_0044a440(local_100);
                    if (cVar1 == '\0') {
                      local_100[0] = '\0';
                      uVar5 = FUN_0044a580(local_100,s_CANNOT_FIND_ITEM_RANK____s_009a6a18,param_1);
                      FUN_00797b80(uVar5);
                      local_100[0] = '\0';
                      uVar5 = FUN_0044a580(local_100,s_File___s__Line___d_009a6a50,
                                           s___Loader_Article_Item_cpp_009a6a34,0x22f);
                      FUN_00797b80(uVar5);
                      FUN_00797a40();
                      return 0;
                    }
                    return 4;
                  }
                  if (*pcVar4 == '\0') {
                    return 2;
                  }
                  uVar2 = uVar2 + 1;
                  pcVar4 = pcVar4 + 1;
                } while (uVar2 < 0x100);
                return 2;
              }
              if (*pcVar4 == '\0') {
                return 1;
              }
              uVar2 = uVar2 + 1;
              pcVar4 = pcVar4 + 1;
            } while (uVar2 < 0x100);
            return 1;
          }
          if (*pcVar4 == '\0') {
            return 0;
          }
          uVar2 = uVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (uVar2 < 0x100);
        return 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar2);
  }
  uVar2 = 0;
  do {
    if (param_1[uVar2] == '\0') {
      if (uVar2 == 0) {
        return 0;
      }
      lVar3 = _atol(param_1);
      return lVar3;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  return 0;
}


// ==== FUN_00484250 @ 0x00484250 ====

void FUN_00484250(undefined4 param_1)

{
  undefined2 uVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  undefined4 uVar8;
  long lVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined1 *puStack_66c;
  undefined *puStack_668;
  char *pcStack_664;
  undefined4 uStack_64c;
  undefined2 uStack_648;
  undefined4 local_644;
  undefined2 uStack_640;
  undefined4 uStack_63c;
  undefined1 uStack_638;
  undefined1 uStack_637;
  undefined1 auStack_616 [8];
  undefined1 uStack_60e;
  undefined2 uStack_5f6;
  undefined1 uStack_5f4;
  undefined2 uStack_5f2;
  undefined2 uStack_5f0;
  undefined1 uStack_5ee;
  undefined1 uStack_5ed;
  undefined2 uStack_5ec;
  undefined2 uStack_5ea;
  undefined2 uStack_5e8;
  undefined4 uStack_5e4;
  undefined4 uStack_5e0;
  undefined4 uStack_5dc;
  undefined4 uStack_5d8;
  undefined4 uStack_5d4;
  undefined2 uStack_5d0;
  undefined1 uStack_5cc;
  undefined1 uStack_5cb;
  undefined1 uStack_5ca;
  undefined1 uStack_5c9;
  undefined1 uStack_5c8;
  undefined1 uStack_5c7;
  undefined1 uStack_5c6;
  undefined1 uStack_5c5;
  undefined1 uStack_5c4;
  undefined1 uStack_5c3;
  undefined1 uStack_5c2;
  undefined1 uStack_5c1;
  undefined1 uStack_5c0;
  undefined1 uStack_5bf;
  long alStack_5bc [10];
  undefined **ppuStack_594;
  int iStack_588;
  ushort auStack_584 [8];
  int iStack_574;
  undefined2 uStack_570;
  undefined2 uStack_56e;
  undefined2 uStack_56c;
  undefined2 uStack_56a;
  undefined2 uStack_568;
  undefined2 uStack_566;
  undefined1 uStack_564;
  undefined1 uStack_563;
  undefined1 uStack_562;
  undefined4 uStack_560;
  undefined **ppuStack_55c;
  undefined4 uStack_558;
  undefined2 uStack_554;
  undefined2 uStack_552;
  undefined4 uStack_550;
  undefined4 uStack_54c;
  undefined1 uStack_548;
  undefined1 uStack_544;
  char local_514 [256];
  undefined4 local_414;
  undefined1 local_410;
  undefined1 local_40f;
  undefined1 local_40e;
  char local_40c [468];
  undefined1 auStack_238 [256];
  undefined1 auStack_138 [292];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e09d;
  pvStack_c = ExceptionList;
  pcStack_664 = local_40c;
  local_514[0] = '\0';
  puStack_668 = (undefined *)0x484293;
  ExceptionList = &pvStack_c;
  FUN_0044a580();
  uVar5 = 0;
  do {
    local_514[uVar5] = local_40c[uVar5];
    if (local_40c[uVar5] == '\0') goto LAB_004842c4;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  local_514[0] = '\0';
LAB_004842c4:
  local_414 = param_1;
  local_410 = 10;
  local_40f = 0x2c;
  local_40e = 1;
  piVar6 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  uStack_60e = 0;
  ppuStack_594 = &PTR_FUN_009a5978;
  uStack_560 = 0;
  ppuStack_55c = &PTR_FUN_009a5980;
  uStack_54c = 0;
  puStack_8 = (undefined1 *)0x0;
  uVar12 = 1;
  uVar5 = (**(code **)(*piVar6 + 8))();
  if (uVar5 < 2) {
LAB_004849c3:
    pcStack_664 = (char *)0x4849cf;
    (**(code **)(*DAT_00b5aa34 + 0xc))();
    ExceptionList = pvStack_14;
    return;
  }
  do {
    pcStack_664 = &DAT_009a6891;
    puStack_66c = &local_410;
    puStack_668 = &DAT_009a6a64;
    FUN_0044a580();
    pcStack_664 = (char *)0x0;
    puStack_66c = (undefined1 *)0x484368;
    puStack_668 = (undefined *)uVar12;
    pcVar7 = (char *)(**(code **)(*piVar6 + 0x10))();
    uVar5 = 0;
    iVar10 = 0xfc - (int)pcVar7;
    while (*pcVar7 == pcVar7[(int)(local_514 + iVar10)]) {
      if (*pcVar7 == '\0') goto LAB_004849b0;
      uVar5 = uVar5 + 1;
      pcVar7 = pcVar7 + 1;
      if (0xff < uVar5) goto LAB_004849b0;
    }
    puStack_66c = (undefined1 *)0x12c;
    FUN_00797a50(&uStack_64c,0);
    puStack_66c = (undefined1 *)0x0;
    uVar1 = FUN_00475a90(uVar12);
    puStack_66c = auStack_616;
    uStack_64c = CONCAT22(uStack_64c._2_2_,uVar1);
    FUN_00483a00(uVar12,1);
    puStack_66c = (undefined1 *)0x2;
    uVar8 = (**(code **)(*piVar6 + 0x10))(uVar12);
    FUN_00484020(uVar8);
    uVar8 = (**(code **)(*piVar6 + 0x10))(uVar12,3);
    FUN_00483d90(uVar8);
    uVar8 = (**(code **)(*piVar6 + 0x10))(uVar12,4);
    FUN_00483c60(local_514,uVar8);
    FUN_00477a70(uVar12,5);
    FUN_00475a90(uVar12,6);
    uStack_64c = FUN_00477a70(uVar12,7);
    uVar8 = (**(code **)(*piVar6 + 0x10))(uVar12,8);
    FUN_00483c10(uVar8);
    uStack_64c = FUN_004756e0(uVar12,9);
    uStack_648 = FUN_00475a90(uVar12,10);
    local_644 = FUN_004756e0(uVar12,0xb);
    uStack_640 = FUN_00475a90(uVar12,0xc);
    uStack_5f6 = FUN_00475a90(uVar12,0x10);
    uStack_5f4 = FUN_004774b0(uVar12,0x11);
    uStack_5f2 = FUN_00475a90(uVar12,0x12);
    uStack_5f0 = FUN_00475a90(uVar12,0x13);
    uStack_63c = FUN_004756e0(uVar12,0xd);
    uStack_638 = FUN_004753b0(uVar12,0xe);
    uStack_637 = FUN_004753b0(uVar12,0xf);
    if (((pcStack_664 == (char *)0x0) || (pcStack_664 == (char *)0x3)) ||
       (uStack_544 = 1, pcStack_664 == (char *)0x1)) {
      uStack_544 = 0;
    }
    uStack_5ee = 0;
    uStack_5ed = 0;
    uStack_5ec = FUN_00475a90(uVar12,0x16);
    uStack_5ea = FUN_00475a90(uVar12,0x17);
    uStack_5e8 = FUN_00475a90(uVar12,0x18);
    uStack_5e4 = FUN_004756e0(uVar12,0x19);
    uStack_5e0 = FUN_004756e0(uVar12,0x1a);
    uStack_5dc = FUN_004756e0(uVar12,0x1b);
    uStack_5cc = FUN_004753b0(uVar12,0x1d);
    uStack_5cb = FUN_004753b0(uVar12,0x1e);
    uStack_5ca = FUN_004753b0(uVar12,0x1f);
    uStack_5c9 = FUN_004753b0(uVar12,0x20);
    uStack_5c8 = FUN_004753b0(uVar12,0x21);
    uStack_5c7 = FUN_004753b0(uVar12,0x22);
    uStack_5c6 = FUN_004753b0(uVar12,0x23);
    uStack_5c5 = FUN_004753b0(uVar12,0x24);
    uStack_5c4 = FUN_004753b0(uVar12,0x25);
    uStack_5c3 = FUN_004753b0(uVar12,0x26);
    uStack_5c2 = FUN_004753b0(uVar12,0x27);
    uStack_5c1 = FUN_004753b0(uVar12,0x28);
    uStack_5c0 = FUN_004753b0(uVar12,0x29);
    uStack_5bf = FUN_004753b0(uVar12,0x2a);
    iVar10 = 0x2b;
    if (iStack_588 != 0) {
      local_40c[0xd4] = 0;
      uVar8 = FUN_0044a580(local_40c + 0xd4,s_File___s__Line___d_009a68b0,
                           s___Loader_Article_Item_cpp_009a6894,300);
      FUN_00797b80(uVar8);
      FUN_00797a40();
    }
    iVar13 = 6;
    do {
      sVar2 = FUN_00475a90(uVar12,iVar10);
      pcVar7 = (char *)(**(code **)(*piVar6 + 0x10))(uVar12,iVar10 + 1);
      FUN_00475260(pcVar7,uVar12,iVar10 + 1);
      uVar5 = 0;
      do {
        if (pcVar7[uVar5] == '\0') {
          lVar9 = 0;
          if (uVar5 != 0) {
            lVar9 = _atol(pcVar7);
          }
          goto LAB_00484718;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0x100);
      lVar9 = 0;
LAB_00484718:
      iVar10 = iVar10 + 2;
      if (sVar2 != 0) {
        iStack_588 = iStack_588 + 1;
        *(short *)(alStack_5bc + iStack_588 * 2 + -1) = sVar2;
        alStack_5bc[iStack_588 * 2] = lVar9;
      }
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    if (iStack_574 != 0) {
      auStack_238[0] = 0;
      uVar8 = FUN_0044a580(auStack_238,s_File___s__Line___d_009a68e0,
                           s___Loader_Article_Item_cpp_009a68c4,0x13b);
      FUN_00797b80(uVar8);
      FUN_00797a40();
    }
    iVar13 = 3;
    do {
      iVar11 = iVar10;
      uVar3 = FUN_00475a90(uVar12,iVar11);
      uVar4 = FUN_00475a90(uVar12,iVar11 + 1);
      if (uVar4 < uVar3) {
        auStack_138[0] = 0;
        uVar8 = FUN_0044a580(auStack_138,s_File___s__Line___d_009a6910,
                             s___Loader_Article_Item_cpp_009a68f4,0x141);
        FUN_00797b80(uVar8);
        FUN_00797a40();
      }
      if (uVar3 != 0) {
        iStack_574 = iStack_574 + 1;
        auStack_584[iStack_574 * 2] = uVar3;
        auStack_584[iStack_574 * 2 + 1] = uVar4;
      }
      iVar13 = iVar13 + -1;
      iVar10 = iVar11 + 2;
    } while (iVar13 != 0);
    uStack_564 = FUN_004753b0(uVar12,iVar11 + 2);
    uStack_570 = FUN_00475a90(uVar12,iVar11 + 3);
    uStack_56e = FUN_00475a90(uVar12,iVar11 + 4);
    uStack_56c = FUN_00475a90(uVar12,iVar11 + 5);
    uStack_56a = FUN_00475a90(uVar12,iVar11 + 6);
    uStack_568 = FUN_00475a90(uVar12,iVar11 + 7);
    uStack_566 = FUN_00475a90(uVar12,iVar11 + 8);
    uStack_563 = FUN_004753b0(uVar12,iVar11 + 9);
    uStack_562 = FUN_004753b0(uVar12,iVar11 + 10);
    uVar1 = FUN_00475a90(uVar12,iVar11 + 0xb);
    uStack_560 = CONCAT22(uStack_560._2_2_,uVar1);
    uVar1 = FUN_00475a90(uVar12,iVar11 + 0xc);
    uStack_560 = CONCAT22(uVar1,(undefined2)uStack_560);
    uVar1 = FUN_00475a90(uVar12,iVar11 + 0xd);
    ppuStack_55c = (undefined **)CONCAT22(ppuStack_55c._2_2_,uVar1);
    uStack_558 = FUN_004756e0(uVar12,iVar11 + 0xe);
    uStack_554 = FUN_00475a90(uVar12,iVar11 + 0xf);
    uStack_552 = FUN_00475a90(uVar12,iVar11 + 0x10);
    uStack_550 = 0;
    uStack_54c = FUN_004756e0(uVar12,iVar11 + 0x11);
    uStack_548 = 1;
    uStack_5d8 = DAT_0099d080;
    uStack_5d4 = DAT_0099d080;
    uStack_5d0 = 0;
    (**(code **)(*DAT_00b5a738 + 4))(&puStack_66c);
LAB_004849b0:
    uVar12 = uVar12 + 1;
    puStack_66c = (undefined1 *)0x4849ba;
    uVar5 = (**(code **)(*piVar6 + 8))();
    if (uVar5 <= uVar12) goto LAB_004849c3;
  } while( true );
}


// ==== FUN_004849f0 @ 0x004849f0 ====

void FUN_004849f0(void)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *in_ECX;
  uint uVar7;
  char *pcStack_414;
  undefined4 *****pppppuStack_410;
  char **ppcStack_40c;
  char *pcStack_408;
  undefined4 *****pppppuStack_404;
  char **ppcStack_400;
  char *pcStack_3fc;
  undefined4 *****pppppuStack_3f8;
  char **ppcStack_3f4;
  char *pcStack_3f0;
  undefined4 *****pppppuStack_3ec;
  char **ppcStack_3e8;
  char *pcStack_3e4;
  undefined4 *****pppppuStack_3e0;
  char **ppcStack_3dc;
  char *pcStack_3d8;
  undefined4 *****pppppuStack_3d4;
  char **ppcStack_3d0;
  char *pcStack_3cc;
  undefined4 *****pppppuStack_3c8;
  char **ppcStack_3c4;
  char *pcStack_3c0;
  undefined4 *****pppppuStack_3bc;
  char **ppcStack_3b8;
  char *pcStack_3b4;
  undefined4 *****pppppuStack_3b0;
  char **ppcStack_3ac;
  char *pcStack_3a8;
  undefined4 *****pppppuStack_3a4;
  char **ppcStack_3a0;
  char *pcStack_39c;
  undefined4 *****pppppuStack_398;
  char **ppcStack_394;
  char *pcStack_390;
  undefined4 *****pppppuStack_38c;
  char **ppcStack_388;
  char *pcStack_384;
  undefined4 *****pppppuStack_380;
  char **ppcStack_37c;
  char *pcStack_378;
  undefined4 *****pppppuStack_374;
  char **ppcStack_370;
  char *pcStack_36c;
  undefined4 *****pppppuStack_368;
  char **ppcStack_364;
  char *pcStack_360;
  undefined4 *****pppppuStack_35c;
  char **ppcStack_358;
  char *pcStack_354;
  undefined4 *****pppppuStack_350;
  char **ppcStack_34c;
  char *pcStack_348;
  undefined4 *****pppppuStack_344;
  char **ppcStack_340;
  char *pcStack_33c;
  undefined4 *****pppppuStack_338;
  char **ppcStack_334;
  char *pcStack_330;
  undefined4 *****pppppuStack_32c;
  char **ppcStack_328;
  char *pcStack_324;
  undefined4 *****pppppuStack_320;
  char **ppcStack_31c;
  char *pcStack_318;
  undefined4 *****pppppuStack_314;
  char **ppcStack_310;
  char *pcStack_30c;
  undefined4 *****pppppuStack_308;
  char **ppcStack_304;
  char *pcStack_300;
  undefined4 *****pppppuStack_2fc;
  char **ppcStack_2f8;
  char *pcStack_2f4;
  undefined4 *****pppppuStack_2f0;
  char **ppcStack_2ec;
  char *pcStack_2e8;
  undefined4 *****pppppuStack_2e4;
  char **ppcStack_2e0;
  char *pcStack_2dc;
  undefined4 *****pppppuStack_2d8;
  char **ppcStack_2d4;
  char *pcStack_2d0;
  undefined4 *****pppppuStack_2cc;
  char **ppcStack_2c8;
  char *pcStack_2c4;
  undefined4 *****pppppuStack_2c0;
  char **ppcStack_2bc;
  char *pcStack_2b8;
  undefined4 *****pppppuStack_2b4;
  char **ppcStack_2b0;
  char *pcStack_2ac;
  undefined4 *****pppppuStack_2a8;
  char **ppcStack_2a4;
  char *pcStack_2a0;
  undefined4 *****pppppuStack_29c;
  char **ppcStack_298;
  char *pcStack_294;
  undefined4 *****pppppuStack_290;
  char **ppcStack_28c;
  char *pcStack_288;
  undefined4 *****pppppuStack_284;
  char **ppcStack_280;
  char *pcStack_27c;
  undefined4 *****pppppuStack_278;
  char **ppcStack_274;
  char *pcStack_270;
  undefined4 *****pppppuStack_26c;
  char **ppcStack_268;
  char *pcStack_264;
  undefined4 *****pppppuStack_260;
  char **ppcStack_25c;
  char *pcStack_258;
  undefined4 *****pppppuStack_254;
  char **ppcStack_250;
  char *pcStack_24c;
  undefined4 *****pppppuStack_248;
  char **ppcStack_244;
  char *pcStack_240;
  undefined4 *****pppppuStack_23c;
  char **ppcStack_238;
  char *pcStack_234;
  undefined4 *****pppppuStack_230;
  char **ppcStack_22c;
  char *pcStack_228;
  undefined4 *****pppppuStack_224;
  char **ppcStack_220;
  char *pcStack_21c;
  undefined4 *****pppppuStack_218;
  char **ppcStack_214;
  char *pcStack_210;
  undefined4 *****pppppuStack_20c;
  char **ppcStack_208;
  char *pcStack_204;
  undefined4 *****pppppuStack_200;
  char **ppcStack_1fc;
  char *pcStack_1f8;
  undefined4 *****pppppuStack_1f4;
  char **ppcStack_1f0;
  char *pcStack_1ec;
  undefined4 *****pppppuStack_1e8;
  char **ppcStack_1e4;
  char *pcStack_1e0;
  undefined4 *****pppppuStack_1dc;
  char **ppcStack_1d8;
  char *pcStack_1d4;
  undefined4 *****pppppuStack_1d0;
  char **ppcStack_1cc;
  char *pcStack_1c8;
  undefined4 *****pppppuStack_1c4;
  char **ppcStack_1c0;
  char *pcStack_1bc;
  undefined4 *****pppppuStack_1b8;
  char **ppcStack_1b4;
  char *pcStack_1b0;
  undefined4 *****pppppuStack_1ac;
  char **ppcStack_1a8;
  char *pcStack_1a4;
  undefined4 *****pppppuStack_1a0;
  char **ppcStack_19c;
  char *pcStack_198;
  int ****ppppiStack_194;
  char **ppcStack_190;
  char *pcStack_18c;
  char ****ppppcStack_188;
  char **ppcStack_184;
  char *pcStack_180;
  char ****ppppcStack_17c;
  char **ppcStack_178;
  char *pcStack_174;
  char ***pppcStack_170;
  char **ppcStack_16c;
  char *pcStack_168;
  char ***pppcStack_164;
  char **ppcStack_160;
  char *pcStack_15c;
  char **ppcStack_158;
  char **ppcStack_154;
  char *pcStack_150;
  char **ppcStack_14c;
  char **ppcStack_148;
  char *pcStack_144;
  char *pcStack_140;
  char *pcStack_13c;
  char *pcStack_138;
  char *pcStack_134;
  undefined *puStack_130;
  char *pcStack_12c;
  char acStack_128 [8];
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097e0c5;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a6af4;
  pvVar2 = operator_new(0x4418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00486f10();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar3;
  pvVar2 = operator_new(0x828);
  local_4._0_1_ = 2;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004874d0();
  }
  acStack_128[4] = '\0';
  acStack_128[5] = '\0';
  acStack_128[6] = '\0';
  acStack_128[7] = '\0';
  in_ECX[2] = uVar3;
  acStack_128[0] = '\x01';
  acStack_128[1] = '\0';
  acStack_128[2] = '\0';
  acStack_128[3] = '\0';
  local_4 = (uint)local_4._1_3_ << 8;
  pcStack_12c = (char *)0x484aa4;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_12c = &DAT_009a5994;
  pcStack_134 = acStack_128 + 0xc;
  puStack_130 = &DAT_009a6a64;
  pcStack_138 = (char *)0x484aba;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_128 + (0xc - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00484ae1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00484ae1:
  pcVar4[0x100] = '\0';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  puStack_130 = (undefined *)0x484af4;
  pcStack_12c = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    puStack_130 = (undefined *)0x1f;
    pcStack_134 = s___Loader_Article_Item_cpp_009a5998;
    pcStack_13c = acStack_128 + 8;
    pcStack_138 = s_File___s__Line___d_009a59b4;
    pcStack_140 = (char *)0x484b13;
    pcStack_140 = (char *)FUN_0044a580();
    pcStack_144 = (char *)0x484b19;
    FUN_00797b80();
    puStack_130 = (undefined *)0x484b21;
    FUN_00797a40();
  }
  puStack_130 = (undefined *)0x0;
  pcStack_134 = (char *)0x1;
  pcStack_138 = (char *)0x484b2d;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_138 = s_HP_POTION_009a59c8;
  pcStack_140 = acStack_128;
  pcStack_13c = &DAT_009a6a64;
  pcStack_144 = (char *)0x484b43;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_128 + -(int)pcVar4)];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00484b6a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00484b6a:
  pcVar4[0x100] = '\x01';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  pcStack_13c = (char *)0x484b7d;
  pcStack_138 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    pcStack_13c = (char *)0x20;
    pcStack_140 = s___Loader_Article_Item_cpp_009a59d4;
    ppcStack_148 = &pcStack_12c;
    pcStack_144 = s_File___s__Line___d_009a59f0;
    pcStack_12c = (char *)((uint)pcStack_12c & 0xffffff00);
    ppcStack_14c = (char **)0x484b9c;
    ppcStack_14c = (char **)FUN_0044a580();
    pcStack_150 = (char *)0x484ba2;
    FUN_00797b80();
    pcStack_13c = (char *)0x484baa;
    FUN_00797a40();
  }
  pcStack_13c = (char *)0x0;
  pcStack_140 = (char *)0x1;
  pcStack_144 = (char *)0x484bb6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_144 = s_MP_POTION_009a5a04;
  ppcStack_14c = &pcStack_134;
  ppcStack_148 = (char **)&DAT_009a6a64;
  pcStack_150 = (char *)0x484bcc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pcStack_134 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00484bfa;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00484bfa:
  pcVar4[0x100] = '\x02';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_148 = (char **)0x484c0d;
  pcStack_144 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_148 = (char **)0x21;
    ppcStack_14c = (char **)s___Loader_Article_Item_cpp_009a5a10;
    ppcStack_154 = &pcStack_138;
    pcStack_150 = s_File___s__Line___d_009a5a2c;
    pcStack_138 = (char *)((uint)pcStack_138 & 0xffffff00);
    ppcStack_158 = (char **)0x484c2c;
    ppcStack_158 = (char **)FUN_0044a580();
    pcStack_15c = (char *)0x484c32;
    FUN_00797b80();
    ppcStack_148 = (char **)0x484c3a;
    FUN_00797a40();
  }
  ppcStack_148 = (char **)0x0;
  ppcStack_14c = (char **)0x1;
  pcStack_150 = (char *)0x484c46;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_150 = s_POISON_POTION_009a5a40;
  ppcStack_158 = &pcStack_140;
  ppcStack_154 = (char **)&DAT_009a6a64;
  pcStack_15c = (char *)0x484c5c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_128 + (-0x18 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00484c8a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00484c8a:
  pcVar4[0x100] = '\x03';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_154 = (char **)0x484c9d;
  pcStack_150 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_154 = (char **)0x22;
    ppcStack_158 = (char **)s___Loader_Article_Item_cpp_009a5a50;
    ppcStack_160 = &pcStack_144;
    pcStack_15c = s_File___s__Line___d_009a5a6c;
    pcStack_144 = (char *)((uint)pcStack_144 & 0xffffff00);
    pppcStack_164 = (char ***)0x484cbc;
    pppcStack_164 = (char ***)FUN_0044a580();
    pcStack_168 = (char *)0x484cc2;
    FUN_00797b80();
    ppcStack_154 = (char **)0x484cca;
    FUN_00797a40();
  }
  ppcStack_154 = (char **)0x0;
  ppcStack_158 = (char **)0x1;
  pcStack_15c = (char *)0x484cd6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_15c = s_QUEST_009a5a80;
  pppcStack_164 = &ppcStack_14c;
  ppcStack_160 = (char **)&DAT_009a6a64;
  pcStack_168 = (char *)0x484cec;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_128 + (-0x24 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00484d1a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00484d1a:
  pcVar4[0x100] = '\x04';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_160 = (char **)0x484d2d;
  pcStack_15c = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_160 = (char **)0x23;
    pppcStack_164 = (char ***)s___Loader_Article_Item_cpp_009a5a88;
    ppcStack_16c = &pcStack_150;
    pcStack_168 = s_File___s__Line___d_009a5aa4;
    pcStack_150 = (char *)((uint)pcStack_150 & 0xffffff00);
    pppcStack_170 = (char ***)0x484d4c;
    pppcStack_170 = (char ***)FUN_0044a580();
    pcStack_174 = (char *)0x484d52;
    FUN_00797b80();
    ppcStack_160 = (char **)0x484d5a;
    FUN_00797a40();
  }
  ppcStack_160 = (char **)0x0;
  pppcStack_164 = (char ***)0x1;
  pcStack_168 = (char *)0x484d66;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_168 = s_EXTRA_009a5ab8;
  pppcStack_170 = &ppcStack_158;
  ppcStack_16c = (char **)&DAT_009a6a64;
  pcStack_174 = (char *)0x484d7c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_128 + (-0x30 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00484daa;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00484daa:
  pcVar4[0x100] = '\x05';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_16c = (char **)0x484dbd;
  pcStack_168 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_16c = (char **)0x24;
    pppcStack_170 = (char ***)s___Loader_Article_Item_cpp_009a5ac0;
    ppcStack_178 = &pcStack_15c;
    pcStack_174 = s_File___s__Line___d_009a5adc;
    pcStack_15c = (char *)((uint)pcStack_15c & 0xffffff00);
    ppppcStack_17c = (char ****)0x484ddc;
    ppppcStack_17c = (char ****)FUN_0044a580();
    pcStack_180 = (char *)0x484de2;
    FUN_00797b80();
    ppcStack_16c = (char **)0x484dea;
    FUN_00797a40();
  }
  ppcStack_16c = (char **)0x0;
  pppcStack_170 = (char ***)0x1;
  pcStack_174 = (char *)0x484df6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_174 = s_STR_STAT_INIT_009a5af0;
  ppppcStack_17c = &pppcStack_164;
  ppcStack_178 = (char **)&DAT_009a6a64;
  pcStack_180 = (char *)0x484e0c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_128 + (-0x3c - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00484e3a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00484e3a:
  pcVar4[0x100] = '\x06';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_178 = (char **)0x484e4d;
  pcStack_174 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_178 = (char **)0x26;
    ppppcStack_17c = (char ****)s___Loader_Article_Item_cpp_009a5b00;
    ppcStack_184 = &pcStack_168;
    pcStack_180 = s_File___s__Line___d_009a5b1c;
    pcStack_168 = (char *)((uint)pcStack_168 & 0xffffff00);
    ppppcStack_188 = (char ****)0x484e6c;
    ppppcStack_188 = (char ****)FUN_0044a580();
    pcStack_18c = (char *)0x484e72;
    FUN_00797b80();
    ppcStack_178 = (char **)0x484e7a;
    FUN_00797a40();
  }
  ppcStack_178 = (char **)0x0;
  ppppcStack_17c = (char ****)0x1;
  pcStack_180 = (char *)0x484e86;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_180 = s_CON_STAT_INIT_009a5b30;
  ppppcStack_188 = &pppcStack_170;
  ppcStack_184 = (char **)&DAT_009a6a64;
  pcStack_18c = (char *)0x484e9c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_128 + (-0x48 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00484eca;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00484eca:
  pcVar4[0x100] = '\a';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_184 = (char **)0x484edd;
  pcStack_180 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_184 = (char **)0x27;
    ppppcStack_188 = (char ****)s___Loader_Article_Item_cpp_009a5b40;
    ppcStack_190 = &pcStack_174;
    pcStack_18c = s_File___s__Line___d_009a5b5c;
    pcStack_174 = (char *)((uint)pcStack_174 & 0xffffff00);
    ppppiStack_194 = (undefined4 ****)0x484efc;
    ppppiStack_194 = (int ****)FUN_0044a580();
    pcStack_198 = (char *)0x484f02;
    FUN_00797b80();
    ppcStack_184 = (char **)0x484f0a;
    FUN_00797a40();
  }
  ppcStack_184 = (char **)0x0;
  ppppcStack_188 = (char ****)0x1;
  pcStack_18c = (char *)0x484f16;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_18c = s_DEX_STAT_INIT_009a5b70;
  ppppiStack_194 = (int ****)&ppppcStack_17c;
  ppcStack_190 = (char **)&DAT_009a6a64;
  pcStack_198 = (char *)0x484f2c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_128 + (-0x54 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00484f5a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00484f5a:
  pcVar4[0x100] = '\b';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_190 = (char **)0x484f6d;
  pcStack_18c = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_190 = (char **)0x28;
    ppppiStack_194 = (int ****)s___Loader_Article_Item_cpp_009a5b80;
    ppcStack_19c = &pcStack_180;
    pcStack_198 = s_File___s__Line___d_009a5b9c;
    pcStack_180 = (char *)((uint)pcStack_180 & 0xffffff00);
    pppppuStack_1a0 = (undefined4 *****)0x484f8c;
    pppppuStack_1a0 = (undefined4 *****)FUN_0044a580();
    pcStack_1a4 = (char *)0x484f92;
    FUN_00797b80();
    ppcStack_190 = (char **)0x484f9a;
    FUN_00797a40();
  }
  ppcStack_190 = (char **)0x0;
  ppppiStack_194 = (undefined4 ****)0x1;
  pcStack_198 = (char *)0x484fa6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_198 = s_SPR_STAT_INIT_009a5bb0;
  pppppuStack_1a0 = (undefined4 *****)&ppppcStack_188;
  ppcStack_19c = (char **)&DAT_009a6a64;
  pcStack_1a4 = (char *)0x484fbc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_128 + (-0x60 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00484fea;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00484fea:
  pcVar4[0x100] = '\t';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_19c = (char **)0x484ffd;
  pcStack_198 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_19c = (char **)0x29;
    pppppuStack_1a0 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5bc0;
    ppcStack_1a8 = &pcStack_18c;
    pcStack_1a4 = s_File___s__Line___d_009a5bdc;
    pcStack_18c = (char *)((uint)pcStack_18c & 0xffffff00);
    pppppuStack_1ac = (undefined4 *****)0x48501c;
    pppppuStack_1ac = (undefined4 *****)FUN_0044a580();
    pcStack_1b0 = (char *)0x485022;
    FUN_00797b80();
    ppcStack_19c = (char **)0x48502a;
    FUN_00797a40();
  }
  ppcStack_19c = (char **)0x0;
  pppppuStack_1a0 = (undefined4 *****)0x1;
  pcStack_1a4 = (char *)0x485036;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_1a4 = s_MINUS_SKILL_CLEAR_COUNT_009a5bf0;
  pppppuStack_1ac = &ppppiStack_194;
  ppcStack_1a8 = (char **)&DAT_009a6a64;
  pcStack_1b0 = (char *)0x48504c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_128 + (-0x6c - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048507a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048507a:
  pcVar4[0x100] = '\n';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_1a8 = (char **)0x48508d;
  pcStack_1a4 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_1a8 = (char **)0x2b;
    pppppuStack_1ac = (undefined4 *****)s___Loader_Article_Item_cpp_009a5c08;
    ppcStack_1b4 = &pcStack_198;
    pcStack_1b0 = s_File___s__Line___d_009a5c24;
    pcStack_198 = (char *)((uint)pcStack_198 & 0xffffff00);
    pppppuStack_1b8 = (undefined4 *****)0x4850ac;
    pppppuStack_1b8 = (undefined4 *****)FUN_0044a580();
    pcStack_1bc = (char *)0x4850b2;
    FUN_00797b80();
    ppcStack_1a8 = (char **)0x4850ba;
    FUN_00797a40();
  }
  ppcStack_1a8 = (char **)0x0;
  pppppuStack_1ac = (undefined4 *****)0x1;
  pcStack_1b0 = (char *)0x4850c6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_1b0 = s_OUTDRAW_SOCKET_STONE_009a5c38;
  pppppuStack_1b8 = &pppppuStack_1a0;
  ppcStack_1b4 = (char **)&DAT_009a6a64;
  pcStack_1bc = (char *)0x4850dc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_128 + (-0x78 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048510a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048510a:
  pcVar4[0x100] = '\v';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_1b4 = (char **)0x48511d;
  pcStack_1b0 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_1b4 = (char **)0x2c;
    pppppuStack_1b8 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5c50;
    ppcStack_1c0 = &pcStack_1a4;
    pcStack_1bc = s_File___s__Line___d_009a5c6c;
    pcStack_1a4 = (char *)((uint)pcStack_1a4 & 0xffffff00);
    pppppuStack_1c4 = (undefined4 *****)0x48513c;
    pppppuStack_1c4 = (undefined4 *****)FUN_0044a580();
    pcStack_1c8 = (char *)0x485142;
    FUN_00797b80();
    ppcStack_1b4 = (char **)0x48514a;
    FUN_00797a40();
  }
  ppcStack_1b4 = (char **)0x0;
  pppppuStack_1b8 = (undefined4 *****)0x1;
  pcStack_1bc = (char *)0x485156;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_1bc = s_STATUS_009a5c80;
  pppppuStack_1c4 = &pppppuStack_1ac;
  ppcStack_1c0 = (char **)&DAT_009a6a64;
  pcStack_1c8 = (char *)0x48516c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_1ac - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048519a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048519a:
  pcVar4[0x100] = '\f';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_1c0 = (char **)0x4851ad;
  pcStack_1bc = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_1c0 = (char **)0x2d;
    pppppuStack_1c4 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5c88;
    ppcStack_1cc = &pcStack_1b0;
    pcStack_1c8 = s_File___s__Line___d_009a5ca4;
    pcStack_1b0 = (char *)((uint)pcStack_1b0 & 0xffffff00);
    pppppuStack_1d0 = (undefined4 *****)0x4851cc;
    pppppuStack_1d0 = (undefined4 *****)FUN_0044a580();
    pcStack_1d4 = (char *)0x4851d2;
    FUN_00797b80();
    ppcStack_1c0 = (char **)0x4851da;
    FUN_00797a40();
  }
  ppcStack_1c0 = (char **)0x0;
  pppppuStack_1c4 = (undefined4 *****)0x1;
  pcStack_1c8 = (char *)0x4851e6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_1c8 = s_EVENT_009a5cb8;
  pppppuStack_1d0 = &pppppuStack_1b8;
  ppcStack_1cc = (char **)&DAT_009a6a64;
  pcStack_1d4 = (char *)0x4851fc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_1b8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048522a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048522a:
  pcVar4[0x100] = '\r';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_1cc = (char **)0x48523d;
  pcStack_1c8 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_1cc = (char **)0x2f;
    pppppuStack_1d0 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5cc0;
    ppcStack_1d8 = &pcStack_1bc;
    pcStack_1d4 = s_File___s__Line___d_009a5cdc;
    pcStack_1bc = (char *)((uint)pcStack_1bc & 0xffffff00);
    pppppuStack_1dc = (undefined4 *****)0x48525c;
    pppppuStack_1dc = (undefined4 *****)FUN_0044a580();
    pcStack_1e0 = (char *)0x485262;
    FUN_00797b80();
    ppcStack_1cc = (char **)0x48526a;
    FUN_00797a40();
  }
  ppcStack_1cc = (char **)0x0;
  pppppuStack_1d0 = (undefined4 *****)0x1;
  pcStack_1d4 = (char *)0x485276;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_1d4 = s_EVENT_ANOTHER_009a5cf0;
  pppppuStack_1dc = &pppppuStack_1c4;
  ppcStack_1d8 = (char **)&DAT_009a6a64;
  pcStack_1e0 = (char *)0x48528c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_1c4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004852ba;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004852ba:
  pcVar4[0x100] = '\x0e';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_1d8 = (char **)0x4852cd;
  pcStack_1d4 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_1d8 = (char **)0x30;
    pppppuStack_1dc = (undefined4 *****)s___Loader_Article_Item_cpp_009a5d00;
    ppcStack_1e4 = &pcStack_1c8;
    pcStack_1e0 = s_File___s__Line___d_009a5d1c;
    pcStack_1c8 = (char *)((uint)pcStack_1c8 & 0xffffff00);
    pppppuStack_1e8 = (undefined4 *****)0x4852ec;
    pppppuStack_1e8 = (undefined4 *****)FUN_0044a580();
    pcStack_1ec = (char *)0x4852f2;
    FUN_00797b80();
    ppcStack_1d8 = (char **)0x4852fa;
    FUN_00797a40();
  }
  ppcStack_1d8 = (char **)0x0;
  pppppuStack_1dc = (undefined4 *****)0x1;
  pcStack_1e0 = (char *)0x485306;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_1e0 = s_INCREASE_BAG_009a5d30;
  pppppuStack_1e8 = &pppppuStack_1d0;
  ppcStack_1e4 = (char **)&DAT_009a6a64;
  pcStack_1ec = (char *)0x48531c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_1d0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048534a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048534a:
  pcVar4[0x100] = '\x0f';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_1e4 = (char **)0x48535d;
  pcStack_1e0 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_1e4 = (char **)0x31;
    pppppuStack_1e8 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5d40;
    ppcStack_1f0 = &pcStack_1d4;
    pcStack_1ec = s_File___s__Line___d_009a5d5c;
    pcStack_1d4 = (char *)((uint)pcStack_1d4 & 0xffffff00);
    pppppuStack_1f4 = (undefined4 *****)0x48537c;
    pppppuStack_1f4 = (undefined4 *****)FUN_0044a580();
    pcStack_1f8 = (char *)0x485382;
    FUN_00797b80();
    ppcStack_1e4 = (char **)0x48538a;
    FUN_00797a40();
  }
  ppcStack_1e4 = (char **)0x0;
  pppppuStack_1e8 = (undefined4 *****)0x1;
  pcStack_1ec = (char *)0x485396;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_1ec = s_ADORNMENT_GUILD_MARK_009a5d70;
  pppppuStack_1f4 = &pppppuStack_1dc;
  ppcStack_1f0 = (char **)&DAT_009a6a64;
  pcStack_1f8 = (char *)0x4853ac;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_1dc - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004853da;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004853da:
  pcVar4[0x100] = '\x10';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_1f0 = (char **)0x4853ed;
  pcStack_1ec = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_1f0 = (char **)0x32;
    pppppuStack_1f4 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5d88;
    ppcStack_1fc = &pcStack_1e0;
    pcStack_1f8 = s_File___s__Line___d_009a5da4;
    pcStack_1e0 = (char *)((uint)pcStack_1e0 & 0xffffff00);
    pppppuStack_200 = (undefined4 *****)0x48540c;
    pppppuStack_200 = (undefined4 *****)FUN_0044a580();
    pcStack_204 = (char *)0x485412;
    FUN_00797b80();
    ppcStack_1f0 = (char **)0x48541a;
    FUN_00797a40();
  }
  ppcStack_1f0 = (char **)0x0;
  pppppuStack_1f4 = (undefined4 *****)0x1;
  pcStack_1f8 = (char *)0x485426;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_1f8 = s_AUTO_HP_POTION_009a5db8;
  pppppuStack_200 = &pppppuStack_1e8;
  ppcStack_1fc = (char **)&DAT_009a6a64;
  pcStack_204 = (char *)0x48543c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_1e8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048546a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048546a:
  pcVar4[0x100] = '\x11';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_1fc = (char **)0x48547d;
  pcStack_1f8 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_1fc = (char **)0x33;
    pppppuStack_200 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5dc8;
    ppcStack_208 = &pcStack_1ec;
    pcStack_204 = s_File___s__Line___d_009a5de4;
    pcStack_1ec = (char *)((uint)pcStack_1ec & 0xffffff00);
    pppppuStack_20c = (undefined4 *****)0x48549c;
    pppppuStack_20c = (undefined4 *****)FUN_0044a580();
    pcStack_210 = (char *)0x4854a2;
    FUN_00797b80();
    ppcStack_1fc = (char **)0x4854aa;
    FUN_00797a40();
  }
  ppcStack_1fc = (char **)0x0;
  pppppuStack_200 = (undefined4 *****)0x1;
  pcStack_204 = (char *)0x4854b6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_204 = s_AUTO_MP_POTION_009a5df8;
  pppppuStack_20c = &pppppuStack_1f4;
  ppcStack_208 = (char **)&DAT_009a6a64;
  pcStack_210 = (char *)0x4854cc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_1f4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004854fa;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004854fa:
  pcVar4[0x100] = '\x12';
  pcVar4[0x101] = '\0';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_208 = (char **)0x48550d;
  pcStack_204 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_208 = (char **)0x34;
    pppppuStack_20c = (undefined4 *****)s___Loader_Article_Item_cpp_009a5e08;
    ppcStack_214 = &pcStack_1f8;
    pcStack_210 = s_File___s__Line___d_009a5e24;
    pcStack_1f8 = (char *)((uint)pcStack_1f8 & 0xffffff00);
    pppppuStack_218 = (undefined4 *****)0x48552c;
    pppppuStack_218 = (undefined4 *****)FUN_0044a580();
    pcStack_21c = (char *)0x485532;
    FUN_00797b80();
    ppcStack_208 = (char **)0x48553a;
    FUN_00797a40();
  }
  ppcStack_208 = (char **)0x0;
  pppppuStack_20c = (undefined4 *****)0x1;
  pcStack_210 = (char *)0x485546;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_210 = s_SOCKET_STONE_009a5e38;
  pppppuStack_218 = &pppppuStack_200;
  ppcStack_214 = (char **)&DAT_009a6a64;
  pcStack_21c = (char *)0x48555c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_200 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048558a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048558a:
  pcVar4[0x100] = '\0';
  pcVar4[0x101] = '\x01';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_214 = (char **)0x48559d;
  pcStack_210 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_214 = (char **)0x36;
    pppppuStack_218 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5e48;
    ppcStack_220 = &pcStack_204;
    pcStack_21c = s_File___s__Line___d_009a5e64;
    pcStack_204 = (char *)((uint)pcStack_204 & 0xffffff00);
    pppppuStack_224 = (undefined4 *****)0x4855bc;
    pppppuStack_224 = (undefined4 *****)FUN_0044a580();
    pcStack_228 = (char *)0x4855c2;
    FUN_00797b80();
    ppcStack_214 = (char **)0x4855ca;
    FUN_00797a40();
  }
  ppcStack_214 = (char **)0x0;
  pppppuStack_218 = (undefined4 *****)0x1;
  pcStack_21c = (char *)0x4855d6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_21c = s_UPGRADE_STONE_009a5e78;
  pppppuStack_224 = &pppppuStack_20c;
  ppcStack_220 = (char **)&DAT_009a6a64;
  pcStack_228 = (char *)0x4855ec;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_20c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048561a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048561a:
  pcVar4[0x100] = '\x01';
  pcVar4[0x101] = '\x01';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_220 = (char **)0x48562d;
  pcStack_21c = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_220 = (char **)0x37;
    pppppuStack_224 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5e88;
    ppcStack_22c = &pcStack_210;
    pcStack_228 = s_File___s__Line___d_009a5ea4;
    pcStack_210 = (char *)((uint)pcStack_210 & 0xffffff00);
    pppppuStack_230 = (undefined4 *****)0x48564c;
    pppppuStack_230 = (undefined4 *****)FUN_0044a580();
    pcStack_234 = (char *)0x485652;
    FUN_00797b80();
    ppcStack_220 = (char **)0x48565a;
    FUN_00797a40();
  }
  ppcStack_220 = (char **)0x0;
  pppppuStack_224 = (undefined4 *****)0x1;
  pcStack_228 = (char *)0x485666;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_228 = s_ADD_SOCKET_STONE_009a5eb8;
  pppppuStack_230 = &pppppuStack_218;
  ppcStack_22c = (char **)&DAT_009a6a64;
  pcStack_234 = (char *)0x48567c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_218 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004856aa;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004856aa:
  pcVar4[0x100] = '\x02';
  pcVar4[0x101] = '\x01';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_22c = (char **)0x4856bd;
  pcStack_228 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_22c = (char **)0x38;
    pppppuStack_230 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5ecc;
    ppcStack_238 = &pcStack_21c;
    pcStack_234 = s_File___s__Line___d_009a5ee8;
    pcStack_21c = (char *)((uint)pcStack_21c & 0xffffff00);
    pppppuStack_23c = (undefined4 *****)0x4856dc;
    pppppuStack_23c = (undefined4 *****)FUN_0044a580();
    pcStack_240 = (char *)0x4856e2;
    FUN_00797b80();
    ppcStack_22c = (char **)0x4856ea;
    FUN_00797a40();
  }
  ppcStack_22c = (char **)0x0;
  pppppuStack_230 = (undefined4 *****)0x1;
  pcStack_234 = (char *)0x4856f6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_234 = s_NECK_WEAR_009a5efc;
  pppppuStack_23c = &pppppuStack_224;
  ppcStack_238 = (char **)&DAT_009a6a64;
  pcStack_240 = (char *)0x48570c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_224 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048573a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048573a:
  pcVar4[0x100] = '\0';
  pcVar4[0x101] = '\x02';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_238 = (char **)0x48574d;
  pcStack_234 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_238 = (char **)0x3b;
    pppppuStack_23c = (undefined4 *****)s___Loader_Article_Item_cpp_009a5f08;
    ppcStack_244 = &pcStack_228;
    pcStack_240 = s_File___s__Line___d_009a5f24;
    pcStack_228 = (char *)((uint)pcStack_228 & 0xffffff00);
    pppppuStack_248 = (undefined4 *****)0x48576c;
    pppppuStack_248 = (undefined4 *****)FUN_0044a580();
    pcStack_24c = (char *)0x485772;
    FUN_00797b80();
    ppcStack_238 = (char **)0x48577a;
    FUN_00797a40();
  }
  ppcStack_238 = (char **)0x0;
  pppppuStack_23c = (undefined4 *****)0x1;
  pcStack_240 = (char *)0x485786;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_240 = s_EARRING_009a5f38;
  pppppuStack_248 = &pppppuStack_230;
  ppcStack_244 = (char **)&DAT_009a6a64;
  pcStack_24c = (char *)0x48579c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_230 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004857ca;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004857ca:
  pcVar4[0x100] = '\x01';
  pcVar4[0x101] = '\x02';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_244 = (char **)0x4857dd;
  pcStack_240 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_244 = (char **)0x3c;
    pppppuStack_248 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5f40;
    ppcStack_250 = &pcStack_234;
    pcStack_24c = s_File___s__Line___d_009a5f5c;
    pcStack_234 = (char *)((uint)pcStack_234 & 0xffffff00);
    pppppuStack_254 = (undefined4 *****)0x4857fc;
    pppppuStack_254 = (undefined4 *****)FUN_0044a580();
    pcStack_258 = (char *)0x485802;
    FUN_00797b80();
    ppcStack_244 = (char **)0x48580a;
    FUN_00797a40();
  }
  ppcStack_244 = (char **)0x0;
  pppppuStack_248 = (undefined4 *****)0x1;
  pcStack_24c = (char *)0x485816;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_24c = s_BRACELET_009a5f70;
  pppppuStack_254 = &pppppuStack_23c;
  ppcStack_250 = (char **)&DAT_009a6a64;
  pcStack_258 = (char *)0x48582c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_23c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048585a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048585a:
  pcVar4[0x100] = '\x02';
  pcVar4[0x101] = '\x02';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_250 = (char **)0x48586d;
  pcStack_24c = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_250 = (char **)0x3d;
    pppppuStack_254 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5f7c;
    ppcStack_25c = &pcStack_240;
    pcStack_258 = s_File___s__Line___d_009a5f98;
    pcStack_240 = (char *)((uint)pcStack_240 & 0xffffff00);
    pppppuStack_260 = (undefined4 *****)0x48588c;
    pppppuStack_260 = (undefined4 *****)FUN_0044a580();
    pcStack_264 = (char *)0x485892;
    FUN_00797b80();
    ppcStack_250 = (char **)0x48589a;
    FUN_00797a40();
  }
  ppcStack_250 = (char **)0x0;
  pppppuStack_254 = (undefined4 *****)0x1;
  pcStack_258 = (char *)0x4858a6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_258 = &DAT_009a5fac;
  pppppuStack_260 = &pppppuStack_248;
  ppcStack_25c = (char **)&DAT_009a6a64;
  pcStack_264 = (char *)0x4858bc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_248 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004858ea;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004858ea:
  pcVar4[0x100] = '\x03';
  pcVar4[0x101] = '\x02';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_25c = (char **)0x4858fd;
  pcStack_258 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_25c = (char **)0x3e;
    pppppuStack_260 = (undefined4 *****)s___Loader_Article_Item_cpp_009a5fb4;
    ppcStack_268 = &pcStack_24c;
    pcStack_264 = s_File___s__Line___d_009a5fd0;
    pcStack_24c = (char *)((uint)pcStack_24c & 0xffffff00);
    pppppuStack_26c = (undefined4 *****)0x48591c;
    pppppuStack_26c = (undefined4 *****)FUN_0044a580();
    pcStack_270 = (char *)0x485922;
    FUN_00797b80();
    ppcStack_25c = (char **)0x48592a;
    FUN_00797a40();
  }
  ppcStack_25c = (char **)0x0;
  pppppuStack_260 = (undefined4 *****)0x1;
  pcStack_264 = (char *)0x485936;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_264 = s_EMBLEM_009a5fe4;
  pppppuStack_26c = &pppppuStack_254;
  ppcStack_268 = (char **)&DAT_009a6a64;
  pcStack_270 = (char *)0x48594c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_254 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048597a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048597a:
  pcVar4[0x100] = '\x04';
  pcVar4[0x101] = '\x02';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_268 = (char **)0x48598d;
  pcStack_264 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_268 = (char **)0x3f;
    pppppuStack_26c = (undefined4 *****)s___Loader_Article_Item_cpp_009a5fec;
    ppcStack_274 = &pcStack_258;
    pcStack_270 = s_File___s__Line___d_009a6008;
    pcStack_258 = (char *)((uint)pcStack_258 & 0xffffff00);
    pppppuStack_278 = (undefined4 *****)0x4859ac;
    pppppuStack_278 = (undefined4 *****)FUN_0044a580();
    pcStack_27c = (char *)0x4859b2;
    FUN_00797b80();
    ppcStack_268 = (char **)0x4859ba;
    FUN_00797a40();
  }
  ppcStack_268 = (char **)0x0;
  pppppuStack_26c = (undefined4 *****)0x1;
  pcStack_270 = (char *)0x4859c6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_270 = s_SINGLE_SLOT_009a601c;
  pppppuStack_278 = &pppppuStack_260;
  ppcStack_274 = (char **)&DAT_009a6a64;
  pcStack_27c = (char *)0x4859dc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_260 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00485a0a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00485a0a:
  pcVar4[0x100] = '\x05';
  pcVar4[0x101] = '\x02';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_274 = (char **)0x485a1d;
  pcStack_270 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_274 = (char **)0x40;
    pppppuStack_278 = (undefined4 *****)s___Loader_Article_Item_cpp_009a6028;
    ppcStack_280 = &pcStack_264;
    pcStack_27c = s_File___s__Line___d_009a6044;
    pcStack_264 = (char *)((uint)pcStack_264 & 0xffffff00);
    pppppuStack_284 = (undefined4 *****)0x485a3c;
    pppppuStack_284 = (undefined4 *****)FUN_0044a580();
    pcStack_288 = (char *)0x485a42;
    FUN_00797b80();
    ppcStack_274 = (char **)0x485a4a;
    FUN_00797a40();
  }
  ppcStack_274 = (char **)0x0;
  pppppuStack_278 = (undefined4 *****)0x1;
  pcStack_27c = (char *)0x485a56;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_27c = s_SPECIAL_009a6058;
  pppppuStack_284 = &pppppuStack_26c;
  ppcStack_280 = (char **)&DAT_009a6a64;
  pcStack_288 = (char *)0x485a6c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_26c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00485a9a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00485a9a:
  pcVar4[0x100] = '\x06';
  pcVar4[0x101] = '\x02';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_280 = (char **)0x485aad;
  pcStack_27c = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_280 = (char **)0x41;
    pppppuStack_284 = (undefined4 *****)s___Loader_Article_Item_cpp_009a6060;
    ppcStack_28c = &pcStack_270;
    pcStack_288 = s_File___s__Line___d_009a607c;
    pcStack_270 = (char *)((uint)pcStack_270 & 0xffffff00);
    pppppuStack_290 = (undefined4 *****)0x485acc;
    pppppuStack_290 = (undefined4 *****)FUN_0044a580();
    pcStack_294 = (char *)0x485ad2;
    FUN_00797b80();
    ppcStack_280 = (char **)0x485ada;
    FUN_00797a40();
  }
  ppcStack_280 = (char **)0x0;
  pppppuStack_284 = (undefined4 *****)0x1;
  pcStack_288 = (char *)0x485ae6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_288 = s_RETURN_SCROLL_009a6090;
  pppppuStack_290 = &pppppuStack_278;
  ppcStack_28c = (char **)&DAT_009a6a64;
  pcStack_294 = (char *)0x485afc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_278 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00485b2a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00485b2a:
  pcVar4[0x100] = '\0';
  pcVar4[0x101] = '\x03';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_28c = (char **)0x485b3d;
  pcStack_288 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_28c = (char **)0x43;
    pppppuStack_290 = (undefined4 *****)s___Loader_Article_Item_cpp_009a60a0;
    ppcStack_298 = &pcStack_27c;
    pcStack_294 = s_File___s__Line___d_009a60bc;
    pcStack_27c = (char *)((uint)pcStack_27c & 0xffffff00);
    pppppuStack_29c = (undefined4 *****)0x485b5c;
    pppppuStack_29c = (undefined4 *****)FUN_0044a580();
    pcStack_2a0 = (char *)0x485b62;
    FUN_00797b80();
    ppcStack_28c = (char **)0x485b6a;
    FUN_00797a40();
  }
  ppcStack_28c = (char **)0x0;
  pppppuStack_290 = (undefined4 *****)0x1;
  pcStack_294 = (char *)0x485b76;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_294 = s_QUEST_SCROLL_009a60d0;
  pppppuStack_29c = &pppppuStack_284;
  ppcStack_298 = (char **)&DAT_009a6a64;
  pcStack_2a0 = (char *)0x485b8c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_284 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00485bba;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00485bba:
  pcVar4[0x100] = '\x01';
  pcVar4[0x101] = '\x03';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_298 = (char **)0x485bcd;
  pcStack_294 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_298 = (char **)0x44;
    pppppuStack_29c = (undefined4 *****)s___Loader_Article_Item_cpp_009a60e0;
    ppcStack_2a4 = &pcStack_288;
    pcStack_2a0 = s_File___s__Line___d_009a60fc;
    pcStack_288 = (char *)((uint)pcStack_288 & 0xffffff00);
    pppppuStack_2a8 = (undefined4 *****)0x485bec;
    pppppuStack_2a8 = (undefined4 *****)FUN_0044a580();
    pcStack_2ac = (char *)0x485bf2;
    FUN_00797b80();
    ppcStack_298 = (char **)0x485bfa;
    FUN_00797a40();
  }
  ppcStack_298 = (char **)0x0;
  pppppuStack_29c = (undefined4 *****)0x1;
  pcStack_2a0 = (char *)0x485c06;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_2a0 = s_SKILL_SCROLL_009a6110;
  pppppuStack_2a8 = &pppppuStack_290;
  ppcStack_2a4 = (char **)&DAT_009a6a64;
  pcStack_2ac = (char *)0x485c1c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_290 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00485c4a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00485c4a:
  pcVar4[0x100] = '\x02';
  pcVar4[0x101] = '\x03';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_2a4 = (char **)0x485c5d;
  pcStack_2a0 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_2a4 = (char **)0x45;
    pppppuStack_2a8 = (undefined4 *****)s___Loader_Article_Item_cpp_009a6120;
    ppcStack_2b0 = &pcStack_294;
    pcStack_2ac = s_File___s__Line___d_009a613c;
    pcStack_294 = (char *)((uint)pcStack_294 & 0xffffff00);
    pppppuStack_2b4 = (undefined4 *****)0x485c7c;
    pppppuStack_2b4 = (undefined4 *****)FUN_0044a580();
    pcStack_2b8 = (char *)0x485c82;
    FUN_00797b80();
    ppcStack_2a4 = (char **)0x485c8a;
    FUN_00797a40();
  }
  ppcStack_2a4 = (char **)0x0;
  pppppuStack_2a8 = (undefined4 *****)0x1;
  pcStack_2ac = (char *)0x485c96;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_2ac = s_ETC_SCROLL_009a6150;
  pppppuStack_2b4 = &pppppuStack_29c;
  ppcStack_2b0 = (char **)&DAT_009a6a64;
  pcStack_2b8 = (char *)0x485cac;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_29c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00485cda;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00485cda:
  pcVar4[0x100] = '\x03';
  pcVar4[0x101] = '\x03';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_2b0 = (char **)0x485ced;
  pcStack_2ac = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_2b0 = (char **)0x46;
    pppppuStack_2b4 = (undefined4 *****)s___Loader_Article_Item_cpp_009a615c;
    ppcStack_2bc = &pcStack_2a0;
    pcStack_2b8 = s_File___s__Line___d_009a6178;
    pcStack_2a0 = (char *)((uint)pcStack_2a0 & 0xffffff00);
    pppppuStack_2c0 = (undefined4 *****)0x485d0c;
    pppppuStack_2c0 = (undefined4 *****)FUN_0044a580();
    pcStack_2c4 = (char *)0x485d12;
    FUN_00797b80();
    ppcStack_2b0 = (char **)0x485d1a;
    FUN_00797a40();
  }
  ppcStack_2b0 = (char **)0x0;
  pppppuStack_2b4 = (undefined4 *****)0x1;
  pcStack_2b8 = (char *)0x485d26;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_2b8 = s_SHORT_SWORD_009a618c;
  pppppuStack_2c0 = &pppppuStack_2a8;
  ppcStack_2bc = (char **)&DAT_009a6a64;
  pcStack_2c4 = (char *)0x485d3c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2a8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00485d6a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00485d6a:
  pcVar4[0x100] = '\0';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_2bc = (char **)0x485d7d;
  pcStack_2b8 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_2bc = (char **)0x48;
    pppppuStack_2c0 = (undefined4 *****)s___Loader_Article_Item_cpp_009a6198;
    ppcStack_2c8 = &pcStack_2ac;
    pcStack_2c4 = s_File___s__Line___d_009a61b4;
    pcStack_2ac = (char *)((uint)pcStack_2ac & 0xffffff00);
    pppppuStack_2cc = (undefined4 *****)0x485d9c;
    pppppuStack_2cc = (undefined4 *****)FUN_0044a580();
    pcStack_2d0 = (char *)0x485da2;
    FUN_00797b80();
    ppcStack_2bc = (char **)0x485daa;
    FUN_00797a40();
  }
  ppcStack_2bc = (char **)0x0;
  pppppuStack_2c0 = (undefined4 *****)0x1;
  pcStack_2c4 = (char *)0x485db6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_2c4 = s_SWORD_009a61c8;
  pppppuStack_2cc = &pppppuStack_2b4;
  ppcStack_2c8 = (char **)&DAT_009a6a64;
  pcStack_2d0 = (char *)0x485dcc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2b4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00485dfa;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00485dfa:
  pcVar4[0x100] = '\x01';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_2c8 = (char **)0x485e0d;
  pcStack_2c4 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_2c8 = (char **)0x49;
    pppppuStack_2cc = (undefined4 *****)s___Loader_Article_Item_cpp_009a61d0;
    ppcStack_2d4 = &pcStack_2b8;
    pcStack_2d0 = s_File___s__Line___d_009a61ec;
    pcStack_2b8 = (char *)((uint)pcStack_2b8 & 0xffffff00);
    pppppuStack_2d8 = (undefined4 *****)0x485e2c;
    pppppuStack_2d8 = (undefined4 *****)FUN_0044a580();
    pcStack_2dc = (char *)0x485e32;
    FUN_00797b80();
    ppcStack_2c8 = (char **)0x485e3a;
    FUN_00797a40();
  }
  ppcStack_2c8 = (char **)0x0;
  pppppuStack_2cc = (undefined4 *****)0x1;
  pcStack_2d0 = "h";
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_2d0 = s_LONG_SWORD_009a6200;
  pppppuStack_2d8 = &pppppuStack_2c0;
  ppcStack_2d4 = (char **)&DAT_009a6a64;
  pcStack_2dc = (char *)0x485e5c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2c0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00485e8a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00485e8a:
  pcVar4[0x100] = '\x02';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_2d4 = (char **)0x485e9d;
  pcStack_2d0 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_2d4 = (char **)0x4a;
    pppppuStack_2d8 = (undefined4 *****)s___Loader_Article_Item_cpp_009a620c;
    ppcStack_2e0 = &pcStack_2c4;
    pcStack_2dc = s_File___s__Line___d_009a6228;
    pcStack_2c4 = (char *)((uint)pcStack_2c4 & 0xffffff00);
    pppppuStack_2e4 = (undefined4 *****)0x485ebc;
    pppppuStack_2e4 = (undefined4 *****)FUN_0044a580();
    pcStack_2e8 = (char *)0x485ec2;
    FUN_00797b80();
    ppcStack_2d4 = (char **)0x485eca;
    FUN_00797a40();
  }
  ppcStack_2d4 = (char **)0x0;
  pppppuStack_2d8 = (undefined4 *****)0x1;
  pcStack_2dc = (char *)0x485ed6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_2dc = s_GREAT_SWORD_009a623c;
  pppppuStack_2e4 = &pppppuStack_2cc;
  ppcStack_2e0 = (char **)&DAT_009a6a64;
  pcStack_2e8 = (char *)0x485eec;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2cc - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00485f1a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00485f1a:
  pcVar4[0x100] = '\x03';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_2e0 = (char **)0x485f2d;
  pcStack_2dc = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_2e0 = (char **)0x4b;
    pppppuStack_2e4 = (undefined4 *****)s___Loader_Article_Item_cpp_009a6248;
    ppcStack_2ec = &pcStack_2d0;
    pcStack_2e8 = s_File___s__Line___d_009a6264;
    pcStack_2d0 = (char *)((uint)pcStack_2d0 & 0xffffff00);
    pppppuStack_2f0 = (undefined4 *****)0x485f4c;
    pppppuStack_2f0 = (undefined4 *****)FUN_0044a580();
    pcStack_2f4 = (char *)0x485f52;
    FUN_00797b80();
    ppcStack_2e0 = (char **)0x485f5a;
    FUN_00797a40();
  }
  ppcStack_2e0 = (char **)0x0;
  pppppuStack_2e4 = (undefined4 *****)0x1;
  pcStack_2e8 = (char *)0x485f66;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_2e8 = s_SPEAR_009a6278;
  pppppuStack_2f0 = &pppppuStack_2d8;
  ppcStack_2ec = (char **)&DAT_009a6a64;
  pcStack_2f4 = (char *)0x485f7c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2d8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00485faa;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00485faa:
  pcVar4[0x100] = '\x04';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_2ec = (char **)0x485fbd;
  pcStack_2e8 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_2ec = (char **)0x4c;
    pppppuStack_2f0 = (undefined4 *****)s___Loader_Article_Item_cpp_009a6280;
    ppcStack_2f8 = &pcStack_2dc;
    pcStack_2f4 = s_File___s__Line___d_009a629c;
    pcStack_2dc = (char *)((uint)pcStack_2dc & 0xffffff00);
    pppppuStack_2fc = (undefined4 *****)0x485fdc;
    pppppuStack_2fc = (undefined4 *****)FUN_0044a580();
    pcStack_300 = (char *)0x485fe2;
    FUN_00797b80();
    ppcStack_2ec = (char **)0x485fea;
    FUN_00797a40();
  }
  ppcStack_2ec = (char **)0x0;
  pppppuStack_2f0 = (undefined4 *****)0x1;
  pcStack_2f4 = (char *)0x485ff6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_2f4 = s_POLEARM_009a62b0;
  pppppuStack_2fc = &pppppuStack_2e4;
  ppcStack_2f8 = (char **)&DAT_009a6a64;
  pcStack_300 = (char *)0x48600c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2e4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048603a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048603a:
  pcVar4[0x100] = '\x05';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_2f8 = (char **)0x48604d;
  pcStack_2f4 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_2f8 = (char **)0x4d;
    pppppuStack_2fc = (undefined4 *****)s___Loader_Article_Item_cpp_009a62b8;
    ppcStack_304 = &pcStack_2e8;
    pcStack_300 = s_File___s__Line___d_009a62d4;
    pcStack_2e8 = (char *)((uint)pcStack_2e8 & 0xffffff00);
    pppppuStack_308 = (undefined4 *****)0x48606c;
    pppppuStack_308 = (undefined4 *****)FUN_0044a580();
    pcStack_30c = (char *)0x486072;
    FUN_00797b80();
    ppcStack_2f8 = (char **)0x48607a;
    FUN_00797a40();
  }
  ppcStack_2f8 = (char **)0x0;
  pppppuStack_2fc = (undefined4 *****)0x1;
  pcStack_300 = (char *)0x486086;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_300 = &DAT_009a62e8;
  pppppuStack_308 = &pppppuStack_2f0;
  ppcStack_304 = (char **)&DAT_009a6a64;
  pcStack_30c = (char *)0x48609c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2f0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004860ca;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004860ca:
  pcVar4[0x100] = '\x06';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_304 = (char **)0x4860dd;
  pcStack_300 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_304 = (char **)0x4e;
    pppppuStack_308 = (undefined4 *****)s___Loader_Article_Item_cpp_009a62f0;
    ppcStack_310 = &pcStack_2f4;
    pcStack_30c = s_File___s__Line___d_009a630c;
    pcStack_2f4 = (char *)((uint)pcStack_2f4 & 0xffffff00);
    pppppuStack_314 = (undefined4 *****)0x4860fc;
    pppppuStack_314 = (undefined4 *****)FUN_0044a580();
    pcStack_318 = (char *)0x486102;
    FUN_00797b80();
    ppcStack_304 = (char **)0x48610a;
    FUN_00797a40();
  }
  ppcStack_304 = (char **)0x0;
  pppppuStack_308 = (undefined4 *****)0x1;
  pcStack_30c = (char *)0x486116;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_30c = s_GREAT_MACE_009a6320;
  pppppuStack_314 = &pppppuStack_2fc;
  ppcStack_310 = (char **)&DAT_009a6a64;
  pcStack_318 = (char *)0x48612c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2fc - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048615a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048615a:
  pcVar4[0x100] = '\a';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_310 = (char **)0x48616d;
  pcStack_30c = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_310 = (char **)0x4f;
    pppppuStack_314 = (undefined4 *****)s___Loader_Article_Item_cpp_009a632c;
    ppcStack_31c = &pcStack_300;
    pcStack_318 = s_File___s__Line___d_009a6348;
    pcStack_300 = (char *)((uint)pcStack_300 & 0xffffff00);
    pppppuStack_320 = (undefined4 *****)0x48618c;
    pppppuStack_320 = (undefined4 *****)FUN_0044a580();
    pcStack_324 = (char *)0x486192;
    FUN_00797b80();
    ppcStack_310 = (char **)0x48619a;
    FUN_00797a40();
  }
  ppcStack_310 = (char **)0x0;
  pppppuStack_314 = (undefined4 *****)0x1;
  pcStack_318 = (char *)0x4861a6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_318 = &DAT_009a635c;
  pppppuStack_320 = &pppppuStack_308;
  ppcStack_31c = (char **)&DAT_009a6a64;
  pcStack_324 = (char *)0x4861bc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_308 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004861ea;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004861ea:
  pcVar4[0x100] = '\b';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_31c = (char **)0x4861fd;
  pcStack_318 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_31c = (char **)0x50;
    pppppuStack_320 = (undefined4 *****)s___Loader_Article_Item_cpp_009a6360;
    ppcStack_328 = &pcStack_30c;
    pcStack_324 = s_File___s__Line___d_009a637c;
    pcStack_30c = (char *)((uint)pcStack_30c & 0xffffff00);
    pppppuStack_32c = (undefined4 *****)0x48621c;
    pppppuStack_32c = (undefined4 *****)FUN_0044a580();
    pcStack_330 = (char *)0x486222;
    FUN_00797b80();
    ppcStack_31c = (char **)0x48622a;
    FUN_00797a40();
  }
  ppcStack_31c = (char **)0x0;
  pppppuStack_320 = (undefined4 *****)0x1;
  pcStack_324 = (char *)0x486236;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_324 = s_GREAT_AX_009a6390;
  pppppuStack_32c = &pppppuStack_314;
  ppcStack_328 = (char **)&DAT_009a6a64;
  pcStack_330 = (char *)0x48624c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_314 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048627a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048627a:
  pcVar4[0x100] = '\t';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_328 = (char **)0x48628d;
  pcStack_324 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_328 = (char **)0x51;
    pppppuStack_32c = (undefined4 *****)s___Loader_Article_Item_cpp_009a639c;
    ppcStack_334 = &pcStack_318;
    pcStack_330 = s_File___s__Line___d_009a63b8;
    pcStack_318 = (char *)((uint)pcStack_318 & 0xffffff00);
    pppppuStack_338 = (undefined4 *****)0x4862ac;
    pppppuStack_338 = (undefined4 *****)FUN_0044a580();
    pcStack_33c = (char *)0x4862b2;
    FUN_00797b80();
    ppcStack_328 = (char **)0x4862ba;
    FUN_00797a40();
  }
  ppcStack_328 = (char **)0x0;
  pppppuStack_32c = (undefined4 *****)0x1;
  pcStack_330 = (char *)0x4862c6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_330 = &DAT_009a63cc;
  pppppuStack_338 = &pppppuStack_320;
  ppcStack_334 = (char **)&DAT_009a6a64;
  pcStack_33c = (char *)0x4862dc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_320 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048630a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048630a:
  pcVar4[0x100] = '\n';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_334 = (char **)0x48631d;
  pcStack_330 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_334 = (char **)0x52;
    pppppuStack_338 = (undefined4 *****)s___Loader_Article_Item_cpp_009a63d0;
    ppcStack_340 = &pcStack_324;
    pcStack_33c = s_File___s__Line___d_009a63ec;
    pcStack_324 = (char *)((uint)pcStack_324 & 0xffffff00);
    pppppuStack_344 = (undefined4 *****)0x48633c;
    pppppuStack_344 = (undefined4 *****)FUN_0044a580();
    pcStack_348 = (char *)0x486342;
    FUN_00797b80();
    ppcStack_334 = (char **)0x48634a;
    FUN_00797a40();
  }
  ppcStack_334 = (char **)0x0;
  pppppuStack_338 = (undefined4 *****)0x1;
  pcStack_33c = "h";
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_33c = s_CROSS_BOW_009a6400;
  pppppuStack_344 = &pppppuStack_32c;
  ppcStack_340 = (char **)&DAT_009a6a64;
  pcStack_348 = (char *)0x48636c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_32c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048639a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048639a:
  pcVar4[0x100] = '\v';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_340 = (char **)0x4863ad;
  pcStack_33c = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_340 = (char **)0x53;
    pppppuStack_344 = (undefined4 *****)s___Loader_Article_Item_cpp_009a640c;
    ppcStack_34c = &pcStack_330;
    pcStack_348 = s_File___s__Line___d_009a6428;
    pcStack_330 = (char *)((uint)pcStack_330 & 0xffffff00);
    pppppuStack_350 = (undefined4 *****)0x4863cc;
    pppppuStack_350 = (undefined4 *****)FUN_0044a580();
    pcStack_354 = (char *)0x4863d2;
    FUN_00797b80();
    ppcStack_340 = (char **)0x4863da;
    FUN_00797a40();
  }
  ppcStack_340 = (char **)0x0;
  pppppuStack_344 = (undefined4 *****)0x1;
  pcStack_348 = (char *)0x4863e6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_348 = s_STAFF_009a643c;
  pppppuStack_350 = &pppppuStack_338;
  ppcStack_34c = (char **)&DAT_009a6a64;
  pcStack_354 = (char *)0x4863fc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_338 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048642a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048642a:
  pcVar4[0x100] = '\f';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_34c = (char **)0x48643d;
  pcStack_348 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_34c = (char **)0x54;
    pppppuStack_350 = (undefined4 *****)s___Loader_Article_Item_cpp_009a6444;
    ppcStack_358 = &pcStack_33c;
    pcStack_354 = s_File___s__Line___d_009a6460;
    pcStack_33c = (char *)((uint)pcStack_33c & 0xffffff00);
    pppppuStack_35c = (undefined4 *****)0x48645c;
    pppppuStack_35c = (undefined4 *****)FUN_0044a580();
    pcStack_360 = (char *)0x486462;
    FUN_00797b80();
    ppcStack_34c = (char **)0x48646a;
    FUN_00797a40();
  }
  ppcStack_34c = (char **)0x0;
  pppppuStack_350 = (undefined4 *****)0x1;
  pcStack_354 = (char *)0x486476;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_354 = &DAT_009a6474;
  pppppuStack_35c = &pppppuStack_344;
  ppcStack_358 = (char **)&DAT_009a6a64;
  pcStack_360 = (char *)0x48648c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_344 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004864ba;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004864ba:
  pcVar4[0x100] = '\r';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_358 = (char **)0x4864cd;
  pcStack_354 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_358 = (char **)0x55;
    pppppuStack_35c = (undefined4 *****)s___Loader_Article_Item_cpp_009a647c;
    ppcStack_364 = &pcStack_348;
    pcStack_360 = s_File___s__Line___d_009a6498;
    pcStack_348 = (char *)((uint)pcStack_348 & 0xffffff00);
    pppppuStack_368 = (undefined4 *****)0x4864ec;
    pppppuStack_368 = (undefined4 *****)FUN_0044a580();
    pcStack_36c = (char *)0x4864f2;
    FUN_00797b80();
    ppcStack_358 = (char **)0x4864fa;
    FUN_00797a40();
  }
  ppcStack_358 = (char **)0x0;
  pppppuStack_35c = (undefined4 *****)0x1;
  pcStack_360 = (char *)0x486506;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_360 = s_SHIELD_009a64ac;
  pppppuStack_368 = &pppppuStack_350;
  ppcStack_364 = (char **)&DAT_009a6a64;
  pcStack_36c = (char *)0x48651c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_350 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048654a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048654a:
  pcVar4[0x100] = '\x0e';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_364 = (char **)0x48655d;
  pcStack_360 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_364 = (char **)0x56;
    pppppuStack_368 = (undefined4 *****)s___Loader_Article_Item_cpp_009a64b4;
    ppcStack_370 = &pcStack_354;
    pcStack_36c = s_File___s__Line___d_009a64d0;
    pcStack_354 = (char *)((uint)pcStack_354 & 0xffffff00);
    pppppuStack_374 = (undefined4 *****)0x48657c;
    pppppuStack_374 = (undefined4 *****)FUN_0044a580();
    pcStack_378 = (char *)0x486582;
    FUN_00797b80();
    ppcStack_364 = (char **)0x48658a;
    FUN_00797a40();
  }
  ppcStack_364 = (char **)0x0;
  pppppuStack_368 = (undefined4 *****)0x1;
  pcStack_36c = (char *)0x486596;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_36c = s_ARROW_009a64e4;
  pppppuStack_374 = &pppppuStack_35c;
  ppcStack_370 = (char **)&DAT_009a6a64;
  pcStack_378 = (char *)0x4865ac;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_35c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004865da;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004865da:
  pcVar4[0x100] = '\x0f';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_370 = (char **)0x4865ed;
  pcStack_36c = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_370 = (char **)0x57;
    pppppuStack_374 = (undefined4 *****)s___Loader_Article_Item_cpp_009a64ec;
    ppcStack_37c = &pcStack_360;
    pcStack_378 = s_File___s__Line___d_009a6508;
    pcStack_360 = (char *)((uint)pcStack_360 & 0xffffff00);
    pppppuStack_380 = (undefined4 *****)0x48660c;
    pppppuStack_380 = (undefined4 *****)FUN_0044a580();
    pcStack_384 = (char *)0x486612;
    FUN_00797b80();
    ppcStack_370 = (char **)0x48661a;
    FUN_00797a40();
  }
  ppcStack_370 = (char **)0x0;
  pppppuStack_374 = (undefined4 *****)0x1;
  pcStack_378 = (char *)0x486626;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_378 = &DAT_009a651c;
  pppppuStack_380 = &pppppuStack_368;
  ppcStack_37c = (char **)&DAT_009a6a64;
  pcStack_384 = (char *)0x48663c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_368 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048666a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048666a:
  pcVar4[0x100] = '\x10';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_37c = (char **)0x48667d;
  pcStack_378 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_37c = (char **)0x58;
    pppppuStack_380 = (undefined4 *****)s___Loader_Article_Item_cpp_009a6524;
    ppcStack_388 = &pcStack_36c;
    pcStack_384 = s_File___s__Line___d_009a6540;
    pcStack_36c = (char *)((uint)pcStack_36c & 0xffffff00);
    pppppuStack_38c = (undefined4 *****)0x48669c;
    pppppuStack_38c = (undefined4 *****)FUN_0044a580();
    pcStack_390 = (char *)0x4866a2;
    FUN_00797b80();
    ppcStack_37c = (char **)0x4866aa;
    FUN_00797a40();
  }
  ppcStack_37c = (char **)0x0;
  pppppuStack_380 = (undefined4 *****)0x1;
  pcStack_384 = (char *)0x4866b6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_384 = s_TWIN_SWORD_009a6554;
  pppppuStack_38c = &pppppuStack_374;
  ppcStack_388 = (char **)&DAT_009a6a64;
  pcStack_390 = (char *)0x4866cc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_374 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004866fa;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004866fa:
  pcVar4[0x100] = '\x11';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_388 = (char **)0x48670d;
  pcStack_384 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_388 = (char **)0x59;
    pppppuStack_38c = (undefined4 *****)s___Loader_Article_Item_cpp_009a6560;
    ppcStack_394 = &pcStack_378;
    pcStack_390 = s_File___s__Line___d_009a657c;
    pcStack_378 = (char *)((uint)pcStack_378 & 0xffffff00);
    pppppuStack_398 = (undefined4 *****)0x48672c;
    pppppuStack_398 = (undefined4 *****)FUN_0044a580();
    pcStack_39c = (char *)0x486732;
    FUN_00797b80();
    ppcStack_388 = (char **)0x48673a;
    FUN_00797a40();
  }
  ppcStack_388 = (char **)0x0;
  pppppuStack_38c = (undefined4 *****)0x1;
  pcStack_390 = (char *)0x486746;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_390 = s_BLOODWHIP_009a6590;
  pppppuStack_398 = &pppppuStack_380;
  ppcStack_394 = (char **)&DAT_009a6a64;
  pcStack_39c = (char *)0x48675c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_380 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048678a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048678a:
  pcVar4[0x100] = '\x12';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_394 = (char **)0x48679d;
  pcStack_390 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_394 = (char **)0x5a;
    pppppuStack_398 = (undefined4 *****)s___Loader_Article_Item_cpp_009a659c;
    ppcStack_3a0 = &pcStack_384;
    pcStack_39c = s_File___s__Line___d_009a65b8;
    pcStack_384 = (char *)((uint)pcStack_384 & 0xffffff00);
    pppppuStack_3a4 = (undefined4 *****)0x4867bc;
    pppppuStack_3a4 = (undefined4 *****)FUN_0044a580();
    pcStack_3a8 = (char *)0x4867c2;
    FUN_00797b80();
    ppcStack_394 = (char **)0x4867ca;
    FUN_00797a40();
  }
  ppcStack_394 = (char **)0x0;
  pppppuStack_398 = (undefined4 *****)0x1;
  pcStack_39c = (char *)0x4867d6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_39c = s_FISHING_ROD_009a65cc;
  pppppuStack_3a4 = &pppppuStack_38c;
  ppcStack_3a0 = (char **)&DAT_009a6a64;
  pcStack_3a8 = (char *)0x4867ec;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_38c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048681a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048681a:
  pcVar4[0x100] = '\x13';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_3a0 = (char **)0x48682d;
  pcStack_39c = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_3a0 = (char **)0x5b;
    pppppuStack_3a4 = (undefined4 *****)s___Loader_Article_Item_cpp_009a65d8;
    ppcStack_3ac = &pcStack_390;
    pcStack_3a8 = s_File___s__Line___d_009a65f4;
    pcStack_390 = (char *)((uint)pcStack_390 & 0xffffff00);
    pppppuStack_3b0 = (undefined4 *****)0x48684c;
    pppppuStack_3b0 = (undefined4 *****)FUN_0044a580();
    pcStack_3b4 = (char *)0x486852;
    FUN_00797b80();
    ppcStack_3a0 = (char **)0x48685a;
    FUN_00797a40();
  }
  ppcStack_3a0 = (char **)0x0;
  pppppuStack_3a4 = (undefined4 *****)0x1;
  pcStack_3a8 = (char *)0x486866;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_3a8 = s_GAUNTLET_009a6608;
  pppppuStack_3b0 = &pppppuStack_398;
  ppcStack_3ac = (char **)&DAT_009a6a64;
  pcStack_3b4 = (char *)0x48687c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_398 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004868aa;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004868aa:
  pcVar4[0x100] = '\x14';
  pcVar4[0x101] = '\x04';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_3ac = (char **)0x4868bd;
  pcStack_3a8 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_3ac = (char **)0x5c;
    pppppuStack_3b0 = (undefined4 *****)s___Loader_Article_Item_cpp_009a6614;
    ppcStack_3b8 = &pcStack_39c;
    pcStack_3b4 = s_File___s__Line___d_009a6630;
    pcStack_39c = (char *)((uint)pcStack_39c & 0xffffff00);
    pppppuStack_3bc = (undefined4 *****)0x4868dc;
    pppppuStack_3bc = (undefined4 *****)FUN_0044a580();
    pcStack_3c0 = (char *)0x4868e2;
    FUN_00797b80();
    ppcStack_3ac = (char **)0x4868ea;
    FUN_00797a40();
  }
  ppcStack_3ac = (char **)0x0;
  pppppuStack_3b0 = (undefined4 *****)0x1;
  pcStack_3b4 = (char *)0x4868f6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_3b4 = s_HELMET_009a6644;
  pppppuStack_3bc = &pppppuStack_3a4;
  ppcStack_3b8 = (char **)&DAT_009a6a64;
  pcStack_3c0 = (char *)0x48690c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3a4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0048693a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0048693a:
  pcVar4[0x100] = '\0';
  pcVar4[0x101] = '\x05';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_3b8 = (char **)0x48694d;
  pcStack_3b4 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_3b8 = (char **)0x5d;
    pppppuStack_3bc = (undefined4 *****)s___Loader_Article_Item_cpp_009a664c;
    ppcStack_3c4 = &pcStack_3a8;
    pcStack_3c0 = s_File___s__Line___d_009a6668;
    pcStack_3a8 = (char *)((uint)pcStack_3a8 & 0xffffff00);
    pppppuStack_3c8 = (undefined4 *****)0x48696c;
    pppppuStack_3c8 = (undefined4 *****)FUN_0044a580();
    pcStack_3cc = (char *)0x486972;
    FUN_00797b80();
    ppcStack_3b8 = (char **)0x48697a;
    FUN_00797a40();
  }
  ppcStack_3b8 = (char **)0x0;
  pppppuStack_3bc = (undefined4 *****)0x1;
  pcStack_3c0 = (char *)0x486986;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_3c0 = &DAT_009a667c;
  pppppuStack_3c8 = &pppppuStack_3b0;
  ppcStack_3c4 = (char **)&DAT_009a6a64;
  pcStack_3cc = (char *)0x48699c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3b0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004869ca;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004869ca:
  pcVar4[0x100] = '\x01';
  pcVar4[0x101] = '\x05';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_3c4 = (char **)0x4869dd;
  pcStack_3c0 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_3c4 = (char **)0x5e;
    pppppuStack_3c8 = (undefined4 *****)s___Loader_Article_Item_cpp_009a6684;
    ppcStack_3d0 = &pcStack_3b4;
    pcStack_3cc = s_File___s__Line___d_009a66a0;
    pcStack_3b4 = (char *)((uint)pcStack_3b4 & 0xffffff00);
    pppppuStack_3d4 = (undefined4 *****)0x4869fc;
    pppppuStack_3d4 = (undefined4 *****)FUN_0044a580();
    pcStack_3d8 = (char *)0x486a02;
    FUN_00797b80();
    ppcStack_3c4 = (char **)0x486a0a;
    FUN_00797a40();
  }
  ppcStack_3c4 = (char **)0x0;
  pppppuStack_3c8 = (undefined4 *****)0x1;
  pcStack_3cc = (char *)0x486a16;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_3cc = s_PANTS_009a66b4;
  pppppuStack_3d4 = &pppppuStack_3bc;
  ppcStack_3d0 = (char **)&DAT_009a6a64;
  pcStack_3d8 = (char *)0x486a2c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3bc - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00486a5a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00486a5a:
  pcVar4[0x100] = '\x02';
  pcVar4[0x101] = '\x05';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_3d0 = (char **)0x486a6d;
  pcStack_3cc = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_3d0 = (char **)0x5f;
    pppppuStack_3d4 = (undefined4 *****)s___Loader_Article_Item_cpp_009a66bc;
    ppcStack_3dc = &pcStack_3c0;
    pcStack_3d8 = s_File___s__Line___d_009a66d8;
    pcStack_3c0 = (char *)((uint)pcStack_3c0 & 0xffffff00);
    pppppuStack_3e0 = (undefined4 *****)0x486a8c;
    pppppuStack_3e0 = (undefined4 *****)FUN_0044a580();
    pcStack_3e4 = (char *)0x486a92;
    FUN_00797b80();
    ppcStack_3d0 = (char **)0x486a9a;
    FUN_00797a40();
  }
  ppcStack_3d0 = (char **)0x0;
  pppppuStack_3d4 = (undefined4 *****)0x1;
  pcStack_3d8 = (char *)0x486aa6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_3d8 = s_BOOTS_009a66ec;
  pppppuStack_3e0 = &pppppuStack_3c8;
  ppcStack_3dc = (char **)&DAT_009a6a64;
  pcStack_3e4 = (char *)0x486abc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3c8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00486aea;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00486aea:
  pcVar4[0x100] = '\x03';
  pcVar4[0x101] = '\x05';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_3dc = (char **)0x486afd;
  pcStack_3d8 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_3dc = (char **)0x60;
    pppppuStack_3e0 = (undefined4 *****)s___Loader_Article_Item_cpp_009a66f4;
    ppcStack_3e8 = &pcStack_3cc;
    pcStack_3e4 = s_File___s__Line___d_009a6710;
    pcStack_3cc = (char *)((uint)pcStack_3cc & 0xffffff00);
    pppppuStack_3ec = (undefined4 *****)0x486b1c;
    pppppuStack_3ec = (undefined4 *****)FUN_0044a580();
    pcStack_3f0 = (char *)0x486b22;
    FUN_00797b80();
    ppcStack_3dc = (char **)0x486b2a;
    FUN_00797a40();
  }
  ppcStack_3dc = (char **)0x0;
  pppppuStack_3e0 = (undefined4 *****)0x1;
  pcStack_3e4 = (char *)0x486b36;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_3e4 = s_GLOVES_009a6724;
  pppppuStack_3ec = &pppppuStack_3d4;
  ppcStack_3e8 = (char **)&DAT_009a6a64;
  pcStack_3f0 = (char *)0x486b4c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3d4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00486b7a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00486b7a:
  pcVar4[0x100] = '\x04';
  pcVar4[0x101] = '\x05';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_3e8 = (char **)0x486b8d;
  pcStack_3e4 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_3e8 = (char **)0x61;
    pppppuStack_3ec = (undefined4 *****)s___Loader_Article_Item_cpp_009a672c;
    ppcStack_3f4 = &pcStack_3d8;
    pcStack_3f0 = s_File___s__Line___d_009a6748;
    pcStack_3d8 = (char *)((uint)pcStack_3d8 & 0xffffff00);
    pppppuStack_3f8 = (undefined4 *****)0x486bac;
    pppppuStack_3f8 = (undefined4 *****)FUN_0044a580();
    pcStack_3fc = (char *)0x486bb2;
    FUN_00797b80();
    ppcStack_3e8 = (char **)0x486bba;
    FUN_00797a40();
  }
  ppcStack_3e8 = (char **)0x0;
  pppppuStack_3ec = (undefined4 *****)0x1;
  pcStack_3f0 = (char *)0x486bc6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_3f0 = s_ADD_EXP_RATE_009a675c;
  pppppuStack_3f8 = &pppppuStack_3e0;
  ppcStack_3f4 = (char **)&DAT_009a6a64;
  pcStack_3fc = (char *)0x486bdc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3e0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00486c0a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00486c0a:
  pcVar4[0x100] = '\0';
  pcVar4[0x101] = '\x06';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_3f4 = (char **)0x486c1d;
  pcStack_3f0 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_3f4 = (char **)0x63;
    pppppuStack_3f8 = (undefined4 *****)s___Loader_Article_Item_cpp_009a676c;
    ppcStack_400 = &pcStack_3e4;
    pcStack_3fc = s_File___s__Line___d_009a6788;
    pcStack_3e4 = (char *)((uint)pcStack_3e4 & 0xffffff00);
    pppppuStack_404 = (undefined4 *****)0x486c3c;
    pppppuStack_404 = (undefined4 *****)FUN_0044a580();
    pcStack_408 = (char *)0x486c42;
    FUN_00797b80();
    ppcStack_3f4 = (char **)0x486c4a;
    FUN_00797a40();
  }
  ppcStack_3f4 = (char **)0x0;
  pppppuStack_3f8 = (undefined4 *****)0x1;
  pcStack_3fc = (char *)0x486c56;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_3fc = s_WINGS_009a679c;
  pppppuStack_404 = &pppppuStack_3ec;
  ppcStack_400 = (char **)&DAT_009a6a64;
  pcStack_408 = (char *)0x486c6c;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3ec - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00486c9a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00486c9a:
  pcVar4[0x100] = '\x01';
  pcVar4[0x101] = '\x06';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_400 = (char **)0x486cad;
  pcStack_3fc = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_400 = (char **)0x64;
    pppppuStack_404 = (undefined4 *****)s___Loader_Article_Item_cpp_009a67a4;
    ppcStack_40c = &pcStack_3f0;
    pcStack_408 = s_File___s__Line___d_009a67c0;
    pcStack_3f0 = (char *)((uint)pcStack_3f0 & 0xffffff00);
    pppppuStack_410 = (undefined4 *****)0x486ccc;
    pppppuStack_410 = (undefined4 *****)FUN_0044a580();
    pcStack_414 = (char *)0x486cd2;
    FUN_00797b80();
    ppcStack_400 = (char **)0x486cda;
    FUN_00797a40();
  }
  ppcStack_400 = (char **)0x0;
  pppppuStack_404 = (undefined4 *****)0x1;
  pcStack_408 = (char *)0x486ce6;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_408 = s_ADORNMENT_STORE_009a67d4;
  pppppuStack_410 = &pppppuStack_3f8;
  ppcStack_40c = (char **)&DAT_009a6a64;
  pcStack_414 = (char *)0x486cfc;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3f8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00486d2a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00486d2a:
  pcVar4[0x100] = '\x02';
  pcVar4[0x101] = '\x06';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  ppcStack_40c = (char **)0x486d3d;
  pcStack_408 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    ppcStack_40c = (char **)0x65;
    pppppuStack_410 = (undefined4 *****)s___Loader_Article_Item_cpp_009a67e4;
    pcStack_414 = s_File___s__Line___d_009a6800;
    pcStack_3fc = (char *)((uint)pcStack_3fc & 0xffffff00);
    uVar3 = FUN_0044a580(&pcStack_3fc);
    FUN_00797b80(uVar3);
    ppcStack_40c = (char **)0x486d6a;
    FUN_00797a40();
  }
  ppcStack_40c = (char **)0x0;
  pppppuStack_410 = (undefined4 *****)0x1;
  pcStack_414 = (char *)0x486d76;
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))();
  pcStack_414 = s_AUTO_FISHING_009a6814;
  FUN_0044a580(&pppppuStack_404,&DAT_009a6a64);
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_404 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00486dba;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00486dba:
  pcVar4[0x100] = '\x03';
  pcVar4[0x101] = '\x06';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  pcStack_414 = pcVar4;
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))();
  if (iVar6 != 0) {
    pcStack_408 = (char *)((uint)pcStack_408 & 0xffffff00);
    uVar3 = FUN_0044a580(&pcStack_408,s_File___s__Line___d_009a6840,
                         s___Loader_Article_Item_cpp_009a6824,0x66);
    FUN_00797b80(uVar3);
    FUN_00797a40();
  }
  pcVar4 = (char *)(**(code **)(*(int *)in_ECX[1] + 0xc))(1,0);
  FUN_0044a580(&pppppuStack_410,&DAT_009a6a64,s_SENTRY_009a6854);
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_410 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00486e4a;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00486e4a:
  pcVar4[0x100] = '\0';
  pcVar4[0x101] = '\a';
  pcVar4[0x102] = '\0';
  pcVar4[0x103] = '\0';
  iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x24))(pcVar4);
  if (iVar6 != 0) {
    pcStack_414 = (char *)((uint)pcStack_414 & 0xffffff00);
    uVar3 = FUN_0044a580(&pcStack_414,s_File___s__Line___d_009a6878,
                         s___Loader_Article_Item_cpp_009a685c,0x68);
    FUN_00797b80(uVar3);
    FUN_00797a40();
  }
  ExceptionList = pcStack_30c;
  return;
}


// ==== FUN_00486eb0 @ 0x00486eb0 ====

void FUN_00486eb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6b00;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x110,0x40,FUN_006ef6d0);
  return;
}


// ==== FUN_00486ed0 @ 0x00486ed0 ====

void FUN_00486ed0(byte param_1)

{
  void *in_ECX;
  
  FUN_00486eb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00486ef0 @ 0x00486ef0 ====

void FUN_00486ef0(byte param_1)

{
  void *in_ECX;
  
  FUN_00483b90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00486f10 @ 0x00486f10 ====

void FUN_00486f10(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e0d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6b08;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a6b00;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x110,0x40,FUN_00636380,FUN_006ef6d0);
  in_ECX[0x1102] = 0;
  in_ECX[0x1102] = in_ECX[0x1102] + 0x40;
  in_ECX[0x1105] = in_ECX + 2;
  in_ECX[0x1103] = 0;
  in_ECX[0x1104] = 0;
  iVar2 = 0x3f;
  puVar1 = in_ECX;
  do {
    puVar1[0x43] = puVar1 + 0x46;
    puVar1[0x44] = 0;
    puVar1[0x45] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x44;
  } while (iVar2 != 0);
  in_ECX[0x10ff] = 0;
  in_ECX[0x1100] = 0;
  in_ECX[0x1101] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00486fd0 @ 0x00486fd0 ====

undefined4 FUN_00486fd0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x440c);
}


// ==== FUN_00486fe0 @ 0x00486fe0 ====

undefined4 FUN_00486fe0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a5070,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10c);
    }
    *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(in_ECX + 0x4414);
    *(int *)(in_ECX + 0x440c) = *(int *)(in_ECX + 0x440c) + -1;
    *(int *)(in_ECX + 0x4414) = param_2;
  }
  return 0;
}


// ==== FUN_00487070 @ 0x00487070 ====

void FUN_00487070(byte param_1)

{
  void *in_ECX;
  
  FUN_00487090();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00487090 @ 0x00487090 ====

void FUN_00487090(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e103;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6b08;
  local_4 = 1;
  if ((void *)in_ECX[0x1104] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009a6b00;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x110,0x40,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009a6a6c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1104]);
  return;
}


// ==== FUN_00487120 @ 0x00487120 ====

undefined1 * FUN_00487120(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined1 *)0x0) {
    if (*(int *)(param_2 + 0x10c) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a5070,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x10c) = *(int *)(param_2 + 0x10c) + param_1;
    return param_2;
  }
  puVar2 = *(undefined1 **)(in_ECX + 0x4414);
  *(int *)(in_ECX + 0x440c) = *(int *)(in_ECX + 0x440c) + 1;
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = operator_new(0x110);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = (undefined1 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    *(undefined4 *)(puVar2 + 0x108) = *(undefined4 *)(in_ECX + 0x4410);
    *(undefined1 **)(in_ECX + 0x4410) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x4414) = *(undefined4 *)(puVar2 + 0x104);
  }
  *(undefined4 *)(puVar2 + 0x104) = 0;
  *(int *)(puVar2 + 0x10c) = param_1;
  return puVar2;
}


// ==== FUN_004871f0 @ 0x004871f0 ====

void FUN_004871f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6b20;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x40,FUN_006ef6d0);
  return;
}


// ==== FUN_00487210 @ 0x00487210 ====

void FUN_00487210(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e123;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6b28;
  local_4 = 1;
  if ((void *)in_ECX[0x204] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009a6b20;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x40,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009a6adc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x204]);
  return;
}


// ==== FUN_00487290 @ 0x00487290 ====

undefined4 FUN_00487290(void)

{
  return 0x40;
}


// ==== FUN_004872a0 @ 0x004872a0 ====

undefined4 FUN_004872a0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a5070,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x814);
    *(int *)(in_ECX + 0x80c) = *(int *)(in_ECX + 0x80c) + -1;
    *(int *)(in_ECX + 0x814) = param_2;
  }
  return 0;
}


// ==== FUN_00487320 @ 0x00487320 ====

undefined4 * FUN_00487320(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a5070,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x814);
  *(int *)(in_ECX + 0x80c) = *(int *)(in_ECX + 0x80c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x810);
    *(undefined4 **)(in_ECX + 0x810) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x814) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_004873e0 @ 0x004873e0 ====

void FUN_004873e0(byte param_1)

{
  void *in_ECX;
  
  FUN_004871f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00487400 @ 0x00487400 ====

void FUN_00487400(byte param_1)

{
  void *in_ECX;
  
  FUN_00487210();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00487420 @ 0x00487420 ====

void FUN_00487420(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e138;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6b28;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a6b20;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x40,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x202] = 0;
  in_ECX[0x202] = in_ECX[0x202] + 0x40;
  in_ECX[0x205] = in_ECX + 2;
  in_ECX[0x203] = 0;
  in_ECX[0x204] = 0;
  iVar2 = 0x3f;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x1ff] = 0;
  in_ECX[0x200] = 0;
  in_ECX[0x201] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004874d0 @ 0x004874d0 ====

void FUN_004874d0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e158;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6b44;
  FUN_00487420();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00487530 @ 0x00487530 ====

void FUN_00487530(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00487535. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(in_ECX + 0x10) + 8))();
  return;
}


// ==== FUN_00487540 @ 0x00487540 ====

void FUN_00487540(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00487545. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(in_ECX + 0x10) + 4))();
  return;
}


// ==== FUN_00487550 @ 0x00487550 ====

void FUN_00487550(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00487570(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00487570 @ 0x00487570 ====

void FUN_00487570(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00487570(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00487570(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_004875b0 @ 0x004875b0 ====

void FUN_004875b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_004875d0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_004875d0 @ 0x004875d0 ====

void FUN_004875d0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_004875d0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_004875d0(param_1[3]);
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


// ==== FUN_00487650 @ 0x00487650 ====

undefined4 * FUN_00487650(undefined4 param_1)

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
    cVar1 = FUN_00473020(*puVar3);
    if (cVar1 == '\0') {
      cVar1 = FUN_00473020(param_1);
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


// ==== FUN_004876d0 @ 0x004876d0 ====

void FUN_004876d0(byte param_1)

{
  void *in_ECX;
  
  FUN_004876f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004876f0 @ 0x004876f0 ====

void FUN_004876f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097e183;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6b44;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_004875d0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00487210();
  *in_ECX = &PTR_FUN_009a6a84;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00487760 @ 0x00487760 ====

void FUN_00487760(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00487770 @ 0x00487770 ====

void FUN_00487770(void)

{
  return;
}


// ==== FUN_00487780 @ 0x00487780 ====

void FUN_00487780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6ba4;
  return;
}


// ==== FUN_00487790 @ 0x00487790 ====

void FUN_00487790(byte param_1)

{
  void *in_ECX;
  
  FUN_00487760();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004877b0 @ 0x004877b0 ====

void FUN_004877b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_004877c0 @ 0x004877c0 ====

void FUN_004877c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6bc4;
  return;
}


// ==== FUN_004877d0 @ 0x004877d0 ====

void FUN_004877d0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6bbc,s_Ornament_009a6bb0);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0048781e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0048781e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_004878a0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00487880 @ 0x00487880 ====

void FUN_00487880(byte param_1)

{
  void *in_ECX;
  
  FUN_004877b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004878a0 @ 0x004878a0 ====

void FUN_004878a0(int *param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  undefined2 auStack_114 [2];
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined2 uStack_108;
  undefined2 uStack_106;
  undefined2 uStack_104;
  char local_100 [256];
  
  iVar4 = 1;
  do {
    FUN_0044a580(local_100,&DAT_009a6bbc,&DAT_0099cf70);
    pcVar2 = (char *)(**(code **)(*param_1 + 0x10))(iVar4,0);
    uVar3 = 0;
    iVar1 = -(int)pcVar2;
    do {
      if (*pcVar2 != pcVar2[(int)(local_100 + iVar1)]) {
        FUN_00797a50(auStack_114,0,0x14);
        auStack_114[0] = FUN_00475a90(iVar4,0);
        uStack_110 = FUN_004756e0(iVar4,1);
        uStack_10c = FUN_004756e0(iVar4,2);
        uStack_108 = FUN_00475a90(iVar4,3);
        uStack_106 = FUN_00475a90(iVar4,4);
        uStack_104 = FUN_00475a90(iVar4,5);
        (**(code **)(*DAT_00b5abbc + 4))(auStack_114);
        break;
      }
      if (*pcVar2 == '\0') break;
      uVar3 = uVar3 + 1;
      pcVar2 = pcVar2 + 1;
    } while (uVar3 < 0x100);
    iVar4 = iVar4 + 1;
    if (0xf9 < iVar4) {
      return;
    }
  } while( true );
}


// ==== FUN_004879b0 @ 0x004879b0 ====

void FUN_004879b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_004879e0 @ 0x004879e0 ====

void FUN_004879e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6bec;
  return;
}


// ==== FUN_004879f0 @ 0x004879f0 ====

void FUN_004879f0(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  ushort *puVar9;
  int iVar10;
  uint uVar11;
  float10 fVar12;
  double dVar13;
  int iVar14;
  undefined2 uStack_4bc;
  undefined1 auStack_4ba [26];
  undefined4 uStack_4a0;
  undefined4 uStack_49c;
  undefined2 uStack_498;
  undefined4 uStack_494;
  undefined2 uStack_490;
  ushort uStack_48e;
  ushort uStack_48c;
  undefined1 uStack_48a;
  undefined1 uStack_489;
  undefined1 uStack_488;
  undefined1 uStack_487;
  undefined1 uStack_486;
  undefined1 uStack_485;
  undefined1 uStack_484;
  undefined1 uStack_483;
  undefined1 uStack_482;
  undefined1 uStack_481;
  undefined1 uStack_480;
  float fStack_47c;
  float fStack_478;
  undefined1 auStack_470 [128];
  undefined1 auStack_3f0 [28];
  undefined **ppuStack_3d4;
  undefined2 uStack_3d0;
  undefined2 uStack_3ce;
  undefined2 uStack_3cc;
  undefined2 uStack_3ca;
  byte bStack_3c8;
  byte bStack_3c7;
  undefined1 auStack_3c4 [10];
  ushort auStack_3ba [203];
  undefined2 uStack_224;
  undefined2 uStack_222;
  undefined4 uStack_220;
  undefined2 uStack_21c;
  undefined2 uStack_21a;
  undefined2 uStack_218;
  undefined2 uStack_216;
  char acStack_214 [248];
  char acStack_11c [8];
  undefined1 auStack_114 [264];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e1d1;
  pvStack_c = ExceptionList;
  uVar11 = 1;
  ExceptionList = &pvStack_c;
  uVar6 = (**(code **)(*param_1 + 0xc))();
  if (uVar6 < 2) {
    ExceptionList = pvStack_c;
    return;
  }
LAB_00487a30:
  FUN_004880a0();
  uStack_4 = 0;
  pcVar7 = (char *)(**(code **)(*param_1 + 0x10))(0,uVar11);
  FUN_0044a580(acStack_214,&DAT_009a6bdc,s_Sentry_009a6bd0 + 7);
  uVar6 = 0;
  iVar14 = -(int)pcVar7;
LAB_00487a77:
  if (*pcVar7 == pcVar7[(int)(acStack_214 + iVar14)]) {
    if (*pcVar7 != '\0') goto code_r0x00487a82;
    goto LAB_00487a90;
  }
  FUN_00797a50(&uStack_4bc,0,0x2a8);
  uStack_4bc = FUN_00475a90(0,uVar11);
  FUN_0047c610(1,uVar11,auStack_4ba);
  uStack_4a0 = FUN_00477a70(2,uVar11);
  uStack_49c = FUN_00477a70(3,uVar11);
  uStack_498 = FUN_00475a90(4,uVar11);
  uStack_494 = FUN_00477a70(5,uVar11);
  uStack_490 = FUN_00475a90(6,uVar11);
  uVar4 = FUN_00475a90(7,uVar11);
  uVar5 = FUN_00475a90(8,uVar11);
  uStack_48c = uVar4;
  if (uVar4 <= uVar5) {
    uStack_48c = uVar5;
  }
  uStack_48e = uVar4;
  uStack_48a = FUN_004753b0(9,uVar11);
  uStack_489 = FUN_004753b0(10,uVar11);
  uStack_488 = FUN_004753b0(0xb,uVar11);
  uStack_487 = FUN_004753b0(0xc,uVar11);
  uStack_484 = FUN_004753b0(0xd,uVar11);
  uStack_486 = FUN_004753b0(0xe,uVar11);
  uStack_485 = FUN_004753b0(0xf,uVar11);
  uStack_483 = FUN_004753b0(0x10,uVar11);
  uStack_482 = FUN_004753b0(0x11,uVar11);
  fVar12 = (float10)FUN_00477510(0x12,uVar11);
  fStack_47c = (float)fVar12;
  fVar12 = (float10)FUN_00477510(0x13,uVar11);
  fStack_478 = (float)fVar12;
  uStack_481 = FUN_004753b0(0x14,uVar11);
  uStack_480 = FUN_004753b0(0x15,uVar11);
  FUN_00482fa0(0x16,uVar11,auStack_470);
  FUN_0047c610(0x17,uVar11,auStack_3f0);
  uStack_3d0 = FUN_00475a90(0x19,uVar11);
  uStack_3ce = FUN_00475a90(0x1a,uVar11);
  uStack_3cc = FUN_00475a90(0x1b,uVar11);
  uStack_3ca = FUN_00475a90(0x1c,uVar11);
  bVar1 = FUN_004753b0(0x1d,uVar11);
  bVar2 = FUN_004753b0(0x1e,uVar11);
  bStack_3c7 = bVar1;
  if (bVar1 <= bVar2) {
    bStack_3c7 = bVar2;
  }
  iVar10 = 0x1f;
  puVar9 = auStack_3ba;
  iVar14 = 8;
  bStack_3c8 = bVar1;
  do {
    uVar6 = FUN_004753b0(iVar10,uVar11);
    *(uint *)(puVar9 + -5) = uVar6 & 0xff;
    uVar5 = FUN_00475a90(iVar10 + 1,uVar11);
    uVar4 = FUN_00475a90(iVar10 + 2,uVar11);
    puVar9[-3] = uVar5;
    if (uVar4 < uVar5) {
      uVar4 = uVar5;
    }
    puVar9[-2] = uVar4;
    uVar5 = FUN_00475a90(iVar10 + 3,uVar11);
    uVar4 = FUN_00475a90(iVar10 + 4,uVar11);
    puVar9[-1] = uVar5;
    if (uVar4 < uVar5) {
      uVar4 = uVar5;
    }
    *puVar9 = uVar4;
    uVar3 = FUN_004753b0(iVar10 + 5,uVar11);
    *(undefined1 *)(puVar9 + 1) = uVar3;
    uVar8 = FUN_004756e0(iVar10 + 6,uVar11);
    *(undefined4 *)(puVar9 + 3) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 7,uVar11);
    *(undefined4 *)(puVar9 + 5) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 8,uVar11);
    *(undefined4 *)(puVar9 + 7) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 9,uVar11);
    *(undefined4 *)(puVar9 + 9) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 10,uVar11);
    *(undefined4 *)(puVar9 + 0xb) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 0xb,uVar11);
    *(undefined4 *)(puVar9 + 0xd) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 0xc,uVar11);
    *(undefined4 *)(puVar9 + 0xf) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 0xd,uVar11);
    *(undefined4 *)(puVar9 + 0x11) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 0xe,uVar11);
    *(undefined4 *)(puVar9 + 0x13) = uVar8;
    iVar10 = iVar10 + 0xf;
    puVar9 = puVar9 + 0x1a;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  uStack_224 = FUN_00475a90(0x97,uVar11);
  uStack_222 = FUN_00475a90(0x98,uVar11);
  uStack_220 = FUN_004756e0(0x99,uVar11);
  uStack_21c = FUN_00475a90(0x9a,uVar11);
  uStack_21a = FUN_00475a90(0x9b,uVar11);
  uStack_218 = FUN_00475a90(0x9c,uVar11);
  uStack_216 = FUN_00475a90(0x9d,uVar11);
  FUN_0044a580(auStack_114,&DAT_009a6bdc,&DAT_009a6bd8);
  pcVar7 = (char *)(**(code **)(*param_1 + 0x10))(0x9e,uVar11);
  uVar6 = 0;
  iVar14 = -(int)pcVar7;
  while (*pcVar7 == pcVar7[(int)(acStack_11c + iVar14)]) {
    if (*pcVar7 == '\0') goto LAB_00487ed4;
    uVar6 = uVar6 + 1;
    pcVar7 = pcVar7 + 1;
    if (0xff < uVar6) break;
  }
  pcVar7 = (char *)(**(code **)(*param_1 + 0x10))(0x9e,uVar11);
  FUN_004772e0(pcVar7,0x9e,uVar11);
  uVar6 = 0;
  while (pcVar7[uVar6] != '\0') {
    uVar6 = uVar6 + 1;
    if (0xff < uVar6) goto LAB_00487ed4;
  }
  if (uVar6 == 0) goto LAB_00487ed4;
  dVar13 = _atof(pcVar7);
  fStack_47c = (float)dVar13;
  goto LAB_00487ed7;
code_r0x00487a82:
  uVar6 = uVar6 + 1;
  pcVar7 = pcVar7 + 1;
  if (0xff < uVar6) goto LAB_00487a90;
  goto LAB_00487a77;
LAB_00487a90:
  pvStack_c = (void *)0x1;
LAB_00487ef8:
  _eh_vector_destructor_iterator_(auStack_3c4,0x34,8,FUN_006ef6d0);
  pvStack_c = (void *)0xffffffff;
  ppuStack_3d4 = &PTR_FUN_009a6be4;
  uVar11 = uVar11 + 1;
  uVar6 = (**(code **)(*param_1 + 0xc))();
  if (uVar6 <= uVar11) {
    ExceptionList = pvStack_c;
    return;
  }
  goto LAB_00487a30;
LAB_00487ed4:
  fStack_47c = 0.0;
LAB_00487ed7:
  (**(code **)(*DAT_00b5abc0 + 4))(auStack_4ba + -10);
  pvStack_c = (void *)0x2;
  goto LAB_00487ef8;
}


// ==== FUN_00487f80 @ 0x00487f80 ====

void FUN_00487f80(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6bdc,s_Sentry_009a6bd0);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00487fce;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00487fce:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_004879f0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00488030 @ 0x00488030 ====

void FUN_00488030(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6be4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00488050 @ 0x00488050 ====

void FUN_00488050(byte param_1)

{
  void *in_ECX;
  
  FUN_004879b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00488070 @ 0x00488070 ====

void FUN_00488070(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6be4;
  return;
}


// ==== FUN_004880a0 @ 0x004880a0 ====

void FUN_004880a0(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e19e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined2 *)(in_ECX + 0x2e) = 0;
  *(undefined2 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 0x4c) = 0;
  *(undefined1 *)(in_ECX + 0xcc) = 0;
  *(undefined ***)(in_ECX + 0xe8) = &PTR_FUN_009a6be4;
  *(undefined1 *)(in_ECX + 0xf4) = 0;
  *(undefined1 *)(in_ECX + 0xf5) = 0;
  local_4 = 0;
  _eh_vector_constructor_iterator_
            ((void *)(in_ECX + 0xf8),0x34,8,(_func_void_void_ptr *)&LAB_00488080,FUN_006ef6d0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00488120 @ 0x00488120 ====

void FUN_00488120(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e19e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0xf8),0x34,8,FUN_006ef6d0);
  *(undefined ***)(in_ECX + 0xe8) = &PTR_FUN_009a6be4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00488180 @ 0x00488180 ====

void FUN_00488180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00488190 @ 0x00488190 ====

void FUN_00488190(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6c08;
  return;
}


// ==== FUN_004881a0 @ 0x004881a0 ====

void FUN_004881a0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6c00,&DAT_009a6bf8);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004881ee;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004881ee:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00488270(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00488250 @ 0x00488250 ====

void FUN_00488250(byte param_1)

{
  void *in_ECX;
  
  FUN_00488180();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00488270 @ 0x00488270 ====

void FUN_00488270(int *param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  float10 fVar5;
  undefined2 auStack_10c [2];
  undefined4 uStack_108;
  float fStack_104;
  char local_100 [256];
  
  iVar4 = 1;
  do {
    FUN_0044a580(local_100,&DAT_009a6c00,&DAT_0099cf70);
    pcVar2 = (char *)(**(code **)(*param_1 + 0x10))(0,iVar4);
    uVar3 = 0;
    iVar1 = -(int)pcVar2;
    do {
      if (*pcVar2 != pcVar2[(int)(local_100 + iVar1)]) {
        FUN_00797a50(auStack_10c,0,0xc);
        auStack_10c[0] = FUN_00475a90(0,iVar4);
        uStack_108 = FUN_004756e0(1,iVar4);
        fVar5 = (float10)FUN_00477510(2,iVar4);
        fStack_104 = (float)fVar5;
        (**(code **)(*DAT_00b5abc4 + 4))(auStack_10c);
        break;
      }
      if (*pcVar2 == '\0') break;
      uVar3 = uVar3 + 1;
      pcVar2 = pcVar2 + 1;
    } while (uVar3 < 0x100);
    iVar4 = iVar4 + 1;
    if (5 < iVar4) {
      return;
    }
  } while( true );
}


// ==== FUN_00488340 @ 0x00488340 ====

void FUN_00488340(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00488370 @ 0x00488370 ====

void FUN_00488370(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6c2c;
  return;
}


// ==== FUN_00488380 @ 0x00488380 ====

void FUN_00488380(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6c1c,s_Brick_009a6c14);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004883ce;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004883ce:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00488570(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00488430 @ 0x00488430 ====

void FUN_00488430(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6c24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00488450 @ 0x00488450 ====

void FUN_00488450(byte param_1)

{
  void *in_ECX;
  
  FUN_00488340();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00488470 @ 0x00488470 ====

void FUN_00488470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6c24;
  return;
}


// ==== FUN_00488480 @ 0x00488480 ====

void FUN_00488480(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e1ee;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined2 *)(in_ECX + 0x3e) = 0;
  *(undefined2 *)(in_ECX + 0x40) = 0;
  *(undefined1 *)(in_ECX + 0x4c) = 0;
  *(undefined1 *)(in_ECX + 0xcc) = 0;
  *(undefined4 *)(in_ECX + 0xec) = 0;
  *(undefined4 *)(in_ECX + 0xf0) = 0;
  *(undefined ***)(in_ECX + 0xfc) = &PTR_FUN_009a6c24;
  *(undefined1 *)(in_ECX + 0x108) = 0;
  *(undefined1 *)(in_ECX + 0x109) = 0;
  local_4 = 0;
  _eh_vector_constructor_iterator_
            ((void *)(in_ECX + 0x10c),0x30,1,(_func_void_void_ptr *)&LAB_00488080,FUN_006ef6d0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00488510 @ 0x00488510 ====

void FUN_00488510(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e1ee;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0x10c),0x30,1,FUN_006ef6d0);
  *(undefined ***)(in_ECX + 0xfc) = &PTR_FUN_009a6c24;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00488570 @ 0x00488570 ====

void FUN_00488570(int *param_1)

{
  undefined2 uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined1 auStack_6ce [66];
  undefined1 auStack_68c [128];
  undefined1 auStack_60c [28];
  uint uStack_5f0;
  uint uStack_5ec;
  uint uStack_5e8;
  undefined4 uStack_5e4;
  undefined2 uStack_5e0;
  undefined **ppuStack_5dc;
  undefined1 auStack_5cc [48];
  ushort uStack_59c;
  undefined2 auStack_598 [2];
  undefined4 auStack_594 [29];
  undefined2 uStack_520;
  undefined4 uStack_51c;
  undefined1 uStack_518;
  undefined1 auStack_514 [256];
  undefined1 auStack_414 [256];
  undefined1 auStack_314 [256];
  char acStack_214 [256];
  undefined1 auStack_114 [264];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e221;
  pvStack_c = ExceptionList;
  uVar9 = 1;
  ExceptionList = &pvStack_c;
  uVar2 = (**(code **)(*param_1 + 0xc))();
  if (uVar2 < 2) {
    ExceptionList = pvStack_c;
    return;
  }
LAB_004885b0:
  FUN_00488480();
  uStack_4 = 0;
  pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(0,uVar9);
  FUN_0044a580(acStack_214,&DAT_009a6c1c,&DAT_0099cf70);
  uVar2 = 0;
  iVar4 = -(int)pcVar3;
LAB_004885f7:
  if (*pcVar3 != pcVar3[(int)(acStack_214 + iVar4)]) {
    FUN_00797a50(auStack_6ce + -10,0,0x1c4);
    FUN_00475a90(0,uVar9);
    FUN_0047c610(1,uVar9,auStack_6ce + -8);
    FUN_00477a70(2,uVar9);
    FUN_00477a70(3,uVar9);
    FUN_00477a70(4,uVar9);
    FUN_00475a90(5,uVar9);
    iVar4 = FUN_00477a70(6,uVar9);
    iVar5 = FUN_00477a70(7,uVar9);
    if (iVar4 < iVar5) {
      auStack_114[0] = 0;
      uVar6 = FUN_0044a580(auStack_114,s_MaxHp____d___>_DefaultHP____d___009a6c7c,iVar4,iVar5);
      FUN_00797b80(uVar6);
      auStack_514[0] = 0;
      uVar6 = FUN_0044a580(auStack_514,s_File___s__Line___d_0099f0a0,
                           s___Loader_Creature_Brick_cpp_009a6c60,0x51);
      FUN_00797b80(uVar6);
      FUN_00797a40();
    }
    FUN_00475a90(8,uVar9);
    FUN_00477a70(9,uVar9);
    FUN_004753b0(0xb,uVar9);
    FUN_004753b0(0xc,uVar9);
    FUN_00475a90(0xd,uVar9);
    FUN_00475a90(0xe,uVar9);
    FUN_004753b0(0x11,uVar9);
    FUN_004753b0(0x12,uVar9);
    FUN_004753b0(0x13,uVar9);
    FUN_004753b0(0x14,uVar9);
    FUN_004753b0(0x15,uVar9);
    FUN_004753b0(0x16,uVar9);
    FUN_004753b0(0x17,uVar9);
    FUN_004753b0(0x18,uVar9);
    FUN_004753b0(0x19,uVar9);
    FUN_004753b0(0x1a,uVar9);
    FUN_00482fa0(0x1b,uVar9,auStack_68c);
    FUN_0047c610(0x1c,uVar9,auStack_60c);
    uStack_5f0 = FUN_00475a90(0x1d,uVar9);
    uStack_5f0 = uStack_5f0 & 0xffff;
    uVar2 = FUN_004756e0(0x1e,uVar9);
    uVar7 = FUN_004756e0(0x1f,uVar9);
    uStack_5e8 = uVar2;
    if (uVar2 <= uVar7) {
      uStack_5e8 = uVar7;
    }
    uStack_5ec = uVar2;
    uStack_5e4 = FUN_004756e0(0x20,uVar9);
    uStack_5e0 = FUN_00475a90(0x21,uVar9);
    uStack_59c = FUN_00475a90(0x22,uVar9);
    if (0xf < uStack_59c) {
      FUN_0044a580(auStack_414,&DAT_009a6c1c,s_ERROR___BRICK_table_____wMaxItem_009a6c34);
      FUN_00797b80(auStack_414);
      auStack_314[0] = 0;
      uVar6 = FUN_0044a580(auStack_314,s_File___s__Line___d_0099f0a0,
                           s___Loader_Creature_Brick_cpp_009a6c60,0x7f);
      FUN_00797b80(uVar6);
      FUN_00797a40();
    }
    iVar5 = 0;
    iVar4 = 0x36;
    do {
      iVar8 = iVar4;
      uVar1 = FUN_00475a90(iVar8,uVar9);
      auStack_598[iVar5 * 4] = uVar1;
      uVar6 = FUN_004756e0(iVar8 + 1,uVar9);
      auStack_594[iVar5 * 2] = uVar6;
      iVar5 = iVar5 + 1;
      iVar4 = iVar8 + 2;
    } while (iVar5 < 0xf);
    uStack_520 = FUN_00475a90(iVar8 + 2,uVar9);
    uStack_51c = FUN_004756e0(iVar8 + 3,uVar9);
    uStack_518 = FUN_004753b0(iVar8 + 4,uVar9);
    (**(code **)(*DAT_00b5abc8 + 4))(auStack_6ce + -10);
    pvStack_c = (void *)0x2;
    goto LAB_00488992;
  }
  if (*pcVar3 != '\0') goto code_r0x00488602;
  goto LAB_00488610;
code_r0x00488602:
  uVar2 = uVar2 + 1;
  pcVar3 = pcVar3 + 1;
  if (0xff < uVar2) goto LAB_00488610;
  goto LAB_004885f7;
LAB_00488610:
  pvStack_c = (void *)0x1;
LAB_00488992:
  _eh_vector_destructor_iterator_(auStack_5cc,0x30,1,FUN_006ef6d0);
  pvStack_c = (void *)0xffffffff;
  ppuStack_5dc = &PTR_FUN_009a6c24;
  uVar9 = uVar9 + 1;
  uVar2 = (**(code **)(*param_1 + 0xc))();
  if (uVar2 <= uVar9) {
    ExceptionList = pvStack_c;
    return;
  }
  goto LAB_004885b0;
}


// ==== FUN_004889e0 @ 0x004889e0 ====

void FUN_004889e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_004889f0 @ 0x004889f0 ====

void FUN_004889f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6cb8;
  return;
}


// ==== FUN_00488a00 @ 0x00488a00 ====

void FUN_00488a00(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6cac,s_Portal_009a6ca4);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00488a4e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00488a4e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00488ae0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00488ab0 @ 0x00488ab0 ====

void FUN_00488ab0(byte param_1)

{
  void *in_ECX;
  
  FUN_004889e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00488ad0 @ 0x00488ad0 ====

void FUN_00488ad0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_00488ae0 @ 0x00488ae0 ====

void FUN_00488ae0(int *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined2 uStack_204;
  undefined2 auStack_202 [61];
  char acStack_188 [136];
  char local_100 [256];
  
  iVar6 = 1;
LAB_00488b00:
  FUN_0044a580(local_100,&DAT_009a6cac,&DAT_0099cf70);
  pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(iVar6,0);
  uVar5 = 0;
  iVar2 = -(int)pcVar3;
  do {
    if (*pcVar3 != pcVar3[(int)(local_100 + iVar2)]) {
      FUN_00488ad0();
      FUN_00797a50(&uStack_204,0,0x84);
      uStack_204 = FUN_00475a90(iVar6,0);
      auStack_202[0] = FUN_00475a90(iVar6,1);
      uVar4 = (**(code **)(*param_1 + 0x10))(iVar6,2);
      FUN_0047b350(acStack_188,&DAT_009a6cb0,uVar4);
      uVar5 = 0;
      goto LAB_00488bb0;
    }
    if (*pcVar3 == '\0') break;
    uVar5 = uVar5 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar5 < 0x100);
  goto LAB_00488bde;
  while (uVar5 = uVar5 + 1, uVar5 < 0x80) {
LAB_00488bb0:
    cVar1 = acStack_188[uVar5];
    *(char *)((int)auStack_202 + (uVar5 - 6)) = cVar1;
    if (cVar1 == '\0') break;
  }
  (**(code **)(*DAT_00b5abcc + 4))(auStack_202 + -5);
LAB_00488bde:
  iVar6 = iVar6 + 1;
  if (0xf9 < iVar6) {
    return;
  }
  goto LAB_00488b00;
}


// ==== FUN_00488c00 @ 0x00488c00 ====

void FUN_00488c00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00488c30 @ 0x00488c30 ====

void FUN_00488c30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6cdc;
  return;
}


// ==== FUN_00488c40 @ 0x00488c40 ====

void FUN_00488c40(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  ushort *puVar9;
  int iVar10;
  uint uVar11;
  float10 fVar12;
  double dVar13;
  int iVar14;
  undefined2 uStack_4bc;
  undefined1 auStack_4ba [26];
  undefined4 uStack_4a0;
  undefined4 uStack_49c;
  undefined2 uStack_498;
  undefined4 uStack_494;
  undefined2 uStack_490;
  ushort uStack_48e;
  ushort uStack_48c;
  undefined1 uStack_48a;
  undefined1 uStack_489;
  undefined1 uStack_488;
  undefined1 uStack_487;
  undefined1 uStack_486;
  undefined1 uStack_485;
  undefined1 uStack_484;
  undefined1 uStack_483;
  undefined1 uStack_482;
  undefined1 uStack_481;
  undefined1 uStack_480;
  float fStack_47c;
  float fStack_478;
  undefined1 auStack_470 [128];
  undefined1 auStack_3f0 [26];
  undefined2 uStack_3d6;
  undefined **ppuStack_3d4;
  undefined2 uStack_3d0;
  undefined2 uStack_3ce;
  undefined2 uStack_3cc;
  undefined2 uStack_3ca;
  byte bStack_3c8;
  byte bStack_3c7;
  undefined1 auStack_3c4 [10];
  ushort auStack_3ba [203];
  undefined2 uStack_224;
  undefined2 uStack_222;
  undefined4 uStack_220;
  undefined2 uStack_21c;
  undefined2 uStack_21a;
  undefined2 uStack_218;
  char acStack_214 [248];
  char acStack_11c [8];
  undefined1 auStack_114 [264];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e271;
  pvStack_c = ExceptionList;
  uVar11 = 1;
  ExceptionList = &pvStack_c;
  uVar6 = (**(code **)(*param_1 + 0xc))();
  if (uVar6 < 2) {
    ExceptionList = pvStack_c;
    return;
  }
LAB_00488c80:
  FUN_004892d0();
  uStack_4 = 0;
  pcVar7 = (char *)(**(code **)(*param_1 + 0x10))(0,uVar11);
  FUN_0044a580(acStack_214,&DAT_009a6ccc,s_Guard_009a6cc4 + 6);
  uVar6 = 0;
  iVar14 = -(int)pcVar7;
LAB_00488cc7:
  if (*pcVar7 == pcVar7[(int)(acStack_214 + iVar14)]) {
    if (*pcVar7 != '\0') goto code_r0x00488cd2;
    goto LAB_00488ce0;
  }
  FUN_00797a50(&uStack_4bc,0,0x2a8);
  uStack_4bc = FUN_00475a90(0,uVar11);
  FUN_0047c610(1,uVar11,auStack_4ba);
  uStack_4a0 = FUN_00477a70(2,uVar11);
  uStack_49c = FUN_00477a70(3,uVar11);
  uStack_498 = FUN_00475a90(4,uVar11);
  uStack_494 = FUN_00477a70(5,uVar11);
  uStack_490 = FUN_00475a90(6,uVar11);
  uVar4 = FUN_00475a90(7,uVar11);
  uVar5 = FUN_00475a90(8,uVar11);
  uStack_48c = uVar4;
  if (uVar4 <= uVar5) {
    uStack_48c = uVar5;
  }
  uStack_48e = uVar4;
  uStack_48a = FUN_004753b0(9,uVar11);
  uStack_489 = FUN_004753b0(10,uVar11);
  uStack_488 = FUN_004753b0(0xb,uVar11);
  uStack_487 = FUN_004753b0(0xc,uVar11);
  uStack_484 = FUN_004753b0(0xd,uVar11);
  uStack_486 = FUN_004753b0(0xe,uVar11);
  uStack_485 = FUN_004753b0(0xf,uVar11);
  uStack_483 = FUN_004753b0(0x10,uVar11);
  uStack_482 = FUN_004753b0(0x11,uVar11);
  fVar12 = (float10)FUN_00477510(0x12,uVar11);
  fStack_47c = (float)fVar12;
  fVar12 = (float10)FUN_00477510(0x13,uVar11);
  fStack_478 = (float)fVar12;
  uStack_481 = FUN_004753b0(0x14,uVar11);
  uStack_480 = FUN_004753b0(0x15,uVar11);
  FUN_00482fa0(0x16,uVar11,auStack_470);
  FUN_0047c610(0x17,uVar11,auStack_3f0);
  uStack_3d6 = FUN_00475a90(0x18,uVar11);
  uStack_3d0 = FUN_00475a90(0x19,uVar11);
  uStack_3ce = FUN_00475a90(0x1a,uVar11);
  uStack_3cc = FUN_00475a90(0x1b,uVar11);
  uStack_3ca = FUN_00475a90(0x1c,uVar11);
  bVar1 = FUN_004753b0(0x1d,uVar11);
  bVar2 = FUN_004753b0(0x1e,uVar11);
  bStack_3c7 = bVar1;
  if (bVar1 <= bVar2) {
    bStack_3c7 = bVar2;
  }
  iVar10 = 0x1f;
  puVar9 = auStack_3ba;
  iVar14 = 8;
  bStack_3c8 = bVar1;
  do {
    uVar6 = FUN_004753b0(iVar10,uVar11);
    *(uint *)(puVar9 + -5) = uVar6 & 0xff;
    uVar5 = FUN_00475a90(iVar10 + 1,uVar11);
    uVar4 = FUN_00475a90(iVar10 + 2,uVar11);
    puVar9[-3] = uVar5;
    if (uVar4 < uVar5) {
      uVar4 = uVar5;
    }
    puVar9[-2] = uVar4;
    uVar5 = FUN_00475a90(iVar10 + 3,uVar11);
    uVar4 = FUN_00475a90(iVar10 + 4,uVar11);
    puVar9[-1] = uVar5;
    if (uVar4 < uVar5) {
      uVar4 = uVar5;
    }
    *puVar9 = uVar4;
    uVar3 = FUN_004753b0(iVar10 + 5,uVar11);
    *(undefined1 *)(puVar9 + 1) = uVar3;
    uVar8 = FUN_004756e0(iVar10 + 6,uVar11);
    *(undefined4 *)(puVar9 + 3) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 7,uVar11);
    *(undefined4 *)(puVar9 + 5) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 8,uVar11);
    *(undefined4 *)(puVar9 + 7) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 9,uVar11);
    *(undefined4 *)(puVar9 + 9) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 10,uVar11);
    *(undefined4 *)(puVar9 + 0xb) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 0xb,uVar11);
    *(undefined4 *)(puVar9 + 0xd) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 0xc,uVar11);
    *(undefined4 *)(puVar9 + 0xf) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 0xd,uVar11);
    *(undefined4 *)(puVar9 + 0x11) = uVar8;
    uVar8 = FUN_004756e0(iVar10 + 0xe,uVar11);
    *(undefined4 *)(puVar9 + 0x13) = uVar8;
    iVar10 = iVar10 + 0xf;
    puVar9 = puVar9 + 0x1a;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  uStack_224 = FUN_00475a90(0x97,uVar11);
  uStack_222 = FUN_00475a90(0x98,uVar11);
  uStack_220 = FUN_004756e0(0x99,uVar11);
  uStack_21c = FUN_00475a90(0x9a,uVar11);
  uStack_21a = FUN_00475a90(0x9b,uVar11);
  uStack_218 = FUN_00475a90(0x9c,uVar11);
  FUN_0044a580(auStack_114,&DAT_009a6ccc,s_Guard_009a6cc4 + 7);
  pcVar7 = (char *)(**(code **)(*param_1 + 0x10))(0x9d,uVar11);
  uVar6 = 0;
  iVar14 = -(int)pcVar7;
  while (*pcVar7 == pcVar7[(int)(acStack_11c + iVar14)]) {
    if (*pcVar7 == '\0') goto LAB_00489124;
    uVar6 = uVar6 + 1;
    pcVar7 = pcVar7 + 1;
    if (0xff < uVar6) break;
  }
  pcVar7 = (char *)(**(code **)(*param_1 + 0x10))(0x9d,uVar11);
  FUN_004772e0(pcVar7,0x9d,uVar11);
  uVar6 = 0;
  while (pcVar7[uVar6] != '\0') {
    uVar6 = uVar6 + 1;
    if (0xff < uVar6) goto LAB_00489124;
  }
  if (uVar6 == 0) goto LAB_00489124;
  dVar13 = _atof(pcVar7);
  fStack_47c = (float)dVar13;
  goto LAB_00489127;
code_r0x00488cd2:
  uVar6 = uVar6 + 1;
  pcVar7 = pcVar7 + 1;
  if (0xff < uVar6) goto LAB_00488ce0;
  goto LAB_00488cc7;
LAB_00488ce0:
  pvStack_c = (void *)0x1;
LAB_00489148:
  _eh_vector_destructor_iterator_(auStack_3c4,0x34,8,FUN_006ef6d0);
  pvStack_c = (void *)0xffffffff;
  ppuStack_3d4 = &PTR_FUN_009a6cd4;
  uVar11 = uVar11 + 1;
  uVar6 = (**(code **)(*param_1 + 0xc))();
  if (uVar6 <= uVar11) {
    ExceptionList = pvStack_c;
    return;
  }
  goto LAB_00488c80;
LAB_00489124:
  fStack_47c = 0.0;
LAB_00489127:
  (**(code **)(*DAT_00b5abd0 + 4))(auStack_4ba + -10);
  pvStack_c = (void *)0x2;
  goto LAB_00489148;
}


// ==== FUN_004891d0 @ 0x004891d0 ====

void FUN_004891d0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6ccc,s_Guard_009a6cc4);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0048921e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0048921e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00488c40(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00489280 @ 0x00489280 ====

void FUN_00489280(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6cd4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004892a0 @ 0x004892a0 ====

void FUN_004892a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00488c00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004892c0 @ 0x004892c0 ====

void FUN_004892c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6cd4;
  return;
}


// ==== FUN_004892d0 @ 0x004892d0 ====

void FUN_004892d0(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e23e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined2 *)(in_ECX + 0x2e) = 0;
  *(undefined2 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 0x4c) = 0;
  *(undefined1 *)(in_ECX + 0xcc) = 0;
  *(undefined ***)(in_ECX + 0xe8) = &PTR_FUN_009a6cd4;
  *(undefined1 *)(in_ECX + 0xf4) = 0;
  *(undefined1 *)(in_ECX + 0xf5) = 0;
  local_4 = 0;
  _eh_vector_constructor_iterator_
            ((void *)(in_ECX + 0xf8),0x34,8,(_func_void_void_ptr *)&LAB_00488080,FUN_006ef6d0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00489350 @ 0x00489350 ====

void FUN_00489350(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e23e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0xf8),0x34,8,FUN_006ef6d0);
  *(undefined ***)(in_ECX + 0xe8) = &PTR_FUN_009a6cd4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004893b0 @ 0x004893b0 ====

void FUN_004893b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_004893e0 @ 0x004893e0 ====

void FUN_004893e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6d00;
  return;
}


// ==== FUN_004893f0 @ 0x004893f0 ====

void FUN_004893f0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6cf0,s_Servant_009a6ce8);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0048943e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0048943e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_004895d0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_004894a0 @ 0x004894a0 ====

void FUN_004894a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6cf8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004894c0 @ 0x004894c0 ====

void FUN_004894c0(byte param_1)

{
  void *in_ECX;
  
  FUN_004893b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004894e0 @ 0x004894e0 ====

void FUN_004894e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6cf8;
  return;
}


// ==== FUN_004894f0 @ 0x004894f0 ====

void FUN_004894f0(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e28e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(in_ECX + 8) = 0;
  *(undefined2 *)(in_ECX + 0x36) = 0;
  *(undefined2 *)(in_ECX + 0x38) = 0;
  *(undefined1 *)(in_ECX + 0x54) = 0;
  *(undefined1 *)(in_ECX + 0xd4) = 0;
  *(undefined ***)(in_ECX + 0xf0) = &PTR_FUN_009a6cf8;
  *(undefined1 *)(in_ECX + 0xfc) = 0;
  *(undefined1 *)(in_ECX + 0xfd) = 0;
  local_4 = 0;
  _eh_vector_constructor_iterator_
            ((void *)(in_ECX + 0x100),0x34,8,(_func_void_void_ptr *)&LAB_00488080,FUN_006ef6d0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00489570 @ 0x00489570 ====

void FUN_00489570(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e28e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0x100),0x34,8,FUN_006ef6d0);
  *(undefined ***)(in_ECX + 0xf0) = &PTR_FUN_009a6cf8;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004895d0 @ 0x004895d0 ====

void FUN_004895d0(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 uVar10;
  ushort *puVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  float10 fVar15;
  double dVar16;
  undefined2 uStack_6c4;
  undefined1 auStack_6c2 [26];
  undefined4 uStack_6a8;
  undefined4 uStack_6a4;
  undefined2 uStack_6a0;
  undefined4 uStack_69c;
  undefined2 uStack_698;
  ushort uStack_696;
  ushort uStack_694;
  undefined1 uStack_692;
  undefined1 uStack_691;
  undefined1 uStack_690;
  undefined1 uStack_68f;
  undefined1 uStack_68e;
  undefined1 uStack_68d;
  undefined1 uStack_68c;
  undefined1 uStack_68b;
  undefined1 uStack_68a;
  undefined1 uStack_689;
  undefined1 uStack_688;
  float fStack_684;
  float fStack_680;
  undefined1 auStack_678 [128];
  undefined1 auStack_5f8 [26];
  undefined2 uStack_5de;
  undefined2 uStack_5d8;
  undefined2 uStack_5d6;
  undefined4 uStack_5d4;
  byte bStack_5d0;
  byte bStack_5cf;
  undefined1 auStack_5c4 [2];
  ushort auStack_5c2 [203];
  undefined2 uStack_42c;
  undefined2 uStack_42a;
  undefined4 uStack_428;
  undefined2 uStack_424;
  undefined2 uStack_422;
  undefined2 uStack_420;
  char acStack_41c [248];
  char acStack_324 [8];
  undefined1 auStack_31c [256];
  char acStack_21c [264];
  char acStack_114 [264];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e2c1;
  pvStack_c = ExceptionList;
  uVar14 = 1;
  ExceptionList = &pvStack_c;
  uVar7 = (**(code **)(*param_1 + 0xc))();
  if (uVar7 < 2) {
    ExceptionList = pvStack_c;
    return;
  }
LAB_00489610:
  FUN_004894f0();
  uStack_4 = 0;
  pcVar8 = (char *)(**(code **)(*param_1 + 0x10))(0,uVar14);
  FUN_0044a580(acStack_114,&DAT_009a6cf0,&DAT_0099cf70);
  uVar7 = 0;
  iVar12 = -(int)pcVar8;
  do {
    if (*pcVar8 != pcVar8[(int)(acStack_114 + iVar12)]) {
      FUN_00797a50(&uStack_6c4,0,0x2b0);
      uStack_6c4 = FUN_00475a90(0,uVar14);
      pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(1,uVar14);
      FUN_0044a580(acStack_41c,&DAT_009a6cf0,s_BEAST_009a6d10);
      iVar12 = -(int)pcVar9;
      uVar7 = 0;
      pcVar8 = pcVar9;
      goto LAB_004896e0;
    }
    if (*pcVar8 == '\0') break;
    uVar7 = uVar7 + 1;
    pcVar8 = pcVar8 + 1;
  } while (uVar7 < 0x100);
  pvStack_c = (void *)0x1;
  goto LAB_00489b78;
  while( true ) {
    uVar7 = uVar7 + 1;
    pcVar8 = pcVar8 + 1;
    if (0xff < uVar7) break;
LAB_004896e0:
    if (*pcVar8 != pcVar8[(int)(acStack_41c + iVar12)]) {
      FUN_0044a580(acStack_21c,&DAT_009a6cf0,s_LIBIDO_009a6d08);
      uVar7 = 0;
      goto LAB_00489730;
    }
    if (*pcVar8 == '\0') break;
  }
  goto LAB_00489750;
  while( true ) {
    uVar7 = uVar7 + 1;
    pcVar9 = pcVar9 + 1;
    if (0xff < uVar7) break;
LAB_00489730:
    if ((*pcVar9 != pcVar9[(int)(acStack_21c + iVar12)]) || (*pcVar9 == '\0')) break;
  }
LAB_00489750:
  FUN_0047c610(2,uVar14,&uStack_6c4);
  uStack_6a8 = FUN_00477a70(3,uVar14);
  uStack_6a4 = FUN_00477a70(4,uVar14);
  uStack_6a0 = FUN_00475a90(5,uVar14);
  uStack_69c = FUN_00477a70(6,uVar14);
  uStack_698 = FUN_00475a90(7,uVar14);
  uVar4 = FUN_00475a90(8,uVar14);
  uVar5 = FUN_00475a90(9,uVar14);
  uStack_694 = uVar4;
  if (uVar4 <= uVar5) {
    uStack_694 = uVar5;
  }
  uStack_696 = uVar4;
  uStack_692 = FUN_004753b0(10,uVar14);
  uStack_691 = FUN_004753b0(0xb,uVar14);
  uStack_690 = FUN_004753b0(0xc,uVar14);
  uStack_68f = FUN_004753b0(0xd,uVar14);
  uStack_68c = FUN_004753b0(0xe,uVar14);
  uStack_68e = FUN_004753b0(0xf,uVar14);
  uStack_68d = FUN_004753b0(0x10,uVar14);
  uStack_68b = FUN_004753b0(0x11,uVar14);
  uStack_68a = FUN_004753b0(0x12,uVar14);
  fVar15 = (float10)FUN_00477510(0x13,uVar14);
  fStack_684 = (float)fVar15;
  fVar15 = (float10)FUN_00477510(0x14,uVar14);
  fStack_680 = (float)fVar15;
  uStack_689 = FUN_004753b0(0x15,uVar14);
  uStack_688 = FUN_004753b0(0x16,uVar14);
  FUN_00482fa0(0x17,uVar14,auStack_678);
  FUN_0047c610(0x18,uVar14,auStack_5f8);
  uStack_5de = FUN_00475a90(0x19,uVar14);
  uStack_5d8 = FUN_00475a90(0x1a,uVar14);
  uStack_5d6 = FUN_00475a90(0x1b,uVar14);
  uVar6 = FUN_00475a90(0x1c,uVar14);
  uStack_5d4 = (undefined **)CONCAT22(uStack_5d4._2_2_,uVar6);
  uVar6 = FUN_00475a90(0x1d,uVar14);
  uStack_5d4 = (undefined **)CONCAT22(uVar6,(undefined2)uStack_5d4);
  bVar1 = FUN_004753b0(0x1e,uVar14);
  bVar2 = FUN_004753b0(0x1f,uVar14);
  bStack_5cf = bVar1;
  if (bVar1 <= bVar2) {
    bStack_5cf = bVar2;
  }
  iVar13 = 0x20;
  puVar11 = auStack_5c2;
  iVar12 = 8;
  bStack_5d0 = bVar1;
  do {
    uVar7 = FUN_004753b0(iVar13,uVar14);
    *(uint *)(puVar11 + -5) = uVar7 & 0xff;
    uVar5 = FUN_00475a90(iVar13 + 1,uVar14);
    uVar4 = FUN_00475a90(iVar13 + 2,uVar14);
    puVar11[-3] = uVar5;
    if (uVar4 < uVar5) {
      uVar4 = uVar5;
    }
    puVar11[-2] = uVar4;
    uVar5 = FUN_00475a90(iVar13 + 3,uVar14);
    uVar4 = FUN_00475a90(iVar13 + 4,uVar14);
    puVar11[-1] = uVar5;
    if (uVar4 < uVar5) {
      uVar4 = uVar5;
    }
    *puVar11 = uVar4;
    uVar3 = FUN_004753b0(iVar13 + 5,uVar14);
    *(undefined1 *)(puVar11 + 1) = uVar3;
    uVar10 = FUN_004756e0(iVar13 + 6,uVar14);
    *(undefined4 *)(puVar11 + 3) = uVar10;
    uVar10 = FUN_004756e0(iVar13 + 7,uVar14);
    *(undefined4 *)(puVar11 + 5) = uVar10;
    uVar10 = FUN_004756e0(iVar13 + 8,uVar14);
    *(undefined4 *)(puVar11 + 7) = uVar10;
    uVar10 = FUN_004756e0(iVar13 + 9,uVar14);
    *(undefined4 *)(puVar11 + 9) = uVar10;
    uVar10 = FUN_004756e0(iVar13 + 10,uVar14);
    *(undefined4 *)(puVar11 + 0xb) = uVar10;
    uVar10 = FUN_004756e0(iVar13 + 0xb,uVar14);
    *(undefined4 *)(puVar11 + 0xd) = uVar10;
    uVar10 = FUN_004756e0(iVar13 + 0xc,uVar14);
    *(undefined4 *)(puVar11 + 0xf) = uVar10;
    uVar10 = FUN_004756e0(iVar13 + 0xd,uVar14);
    *(undefined4 *)(puVar11 + 0x11) = uVar10;
    uVar10 = FUN_004756e0(iVar13 + 0xe,uVar14);
    *(undefined4 *)(puVar11 + 0x13) = uVar10;
    iVar13 = iVar13 + 0xf;
    puVar11 = puVar11 + 0x1a;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  uStack_42c = FUN_00475a90(0x98,uVar14);
  uStack_42a = FUN_00475a90(0x99,uVar14);
  uStack_428 = FUN_004756e0(0x9a,uVar14);
  uStack_424 = FUN_00475a90(0x9b,uVar14);
  uStack_422 = FUN_00475a90(0x9c,uVar14);
  uStack_420 = FUN_00475a90(0x9d,uVar14);
  FUN_0044a580(auStack_31c,&DAT_009a6cf0,&DAT_0099cf70);
  pcVar8 = (char *)(**(code **)(*param_1 + 0x10))(0x9e,uVar14);
  uVar7 = 0;
  iVar12 = -(int)pcVar8;
  do {
    if (*pcVar8 != pcVar8[(int)(acStack_324 + iVar12)]) break;
    if (*pcVar8 == '\0') goto LAB_00489b54;
    uVar7 = uVar7 + 1;
    pcVar8 = pcVar8 + 1;
  } while (uVar7 < 0x100);
  pcVar8 = (char *)(**(code **)(*param_1 + 0x10))(0x9e,uVar14);
  FUN_004772e0(pcVar8,0x9e,uVar14);
  uVar7 = 0;
  do {
    if (pcVar8[uVar7] == '\0') {
      if (uVar7 != 0) {
        dVar16 = _atof(pcVar8);
        fStack_684 = (float)dVar16;
        goto LAB_00489b57;
      }
      break;
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 < 0x100);
LAB_00489b54:
  fStack_684 = 0.0;
LAB_00489b57:
  (**(code **)(*DAT_00b5abd4 + 4))(auStack_6c2 + -0x12);
  pvStack_c = (void *)0x2;
LAB_00489b78:
  _eh_vector_destructor_iterator_(auStack_5c4,0x34,8,FUN_006ef6d0);
  pvStack_c = (void *)0xffffffff;
  uStack_5d4 = &PTR_FUN_009a6cf8;
  uVar14 = uVar14 + 1;
  uVar7 = (**(code **)(*param_1 + 0xc))();
  if (uVar7 <= uVar14) {
    ExceptionList = pvStack_c;
    return;
  }
  goto LAB_00489610;
}


// ==== FUN_00489c00 @ 0x00489c00 ====

void FUN_00489c00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00489c10 @ 0x00489c10 ====

void FUN_00489c10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6d2c;
  return;
}


// ==== FUN_00489c20 @ 0x00489c20 ====

void FUN_00489c20(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  char *pcVar4;
  uint uVar5;
  char *pcStack_260;
  undefined1 auStack_250 [28];
  undefined4 uStack_234;
  undefined2 uStack_230;
  undefined1 uStack_22e;
  undefined1 uStack_22d;
  undefined1 uStack_22c;
  undefined1 uStack_22b;
  undefined2 uStack_22a;
  undefined2 uStack_228;
  undefined4 uStack_224;
  undefined2 uStack_220;
  undefined2 uStack_21e;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  pcStack_260 = local_100;
  FUN_0044a580();
  uVar2 = 0;
  do {
    local_208[uVar2] = local_100[uVar2];
    if (local_100[uVar2] == '\0') goto LAB_00489c6e;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_208[0] = '\0';
LAB_00489c6e:
  local_108 = param_1;
  pcStack_260 = local_208;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  FUN_00489e80();
  uVar5 = 1;
  uVar2 = (**(code **)(*piVar3 + 8))();
  if (1 < uVar2) {
    do {
      pcVar4 = (char *)(**(code **)(*piVar3 + 0x10))(uVar5,1);
      FUN_0044a580(local_208 + 0xfc,&DAT_009a6d24,s_Remote_009a6d1c + 7);
      uVar2 = 0;
      iVar1 = 0xfc - (int)pcVar4;
      do {
        if (*pcVar4 != pcVar4[(int)(local_208 + iVar1)]) {
          pcStack_260 = (char *)FUN_004756e0(uVar5,0);
          FUN_004756e0(uVar5,1);
          FUN_004756e0(uVar5,2);
          FUN_004756e0(uVar5,3);
          FUN_0047c610(uVar5,4,auStack_250);
          uStack_234 = FUN_004756e0(uVar5,5);
          uStack_230 = FUN_00475a90(uVar5,6);
          uStack_22e = FUN_004753b0(uVar5,7);
          uStack_22d = FUN_004753b0(uVar5,8);
          uStack_22c = FUN_004753b0(uVar5,9);
          uStack_22b = FUN_004753b0(uVar5,10);
          uStack_22a = FUN_00475a90(uVar5,0xb);
          uStack_228 = FUN_00475a90(uVar5,0xc);
          uStack_224 = FUN_004756e0(uVar5,0xd);
          uStack_220 = FUN_00475a90(uVar5,0xe);
          uStack_21e = FUN_00475a90(uVar5,0xf);
          uStack_21c = FUN_004756e0(uVar5,0x10);
          uStack_218 = FUN_004756e0(uVar5,0x11);
          (**(code **)(*DAT_00b5a768 + 4))(&pcStack_260);
          break;
        }
        if (*pcVar4 == '\0') break;
        uVar2 = uVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (uVar2 < 0x100);
      uVar5 = uVar5 + 1;
      uVar2 = (**(code **)(*piVar3 + 8))();
    } while (uVar5 < uVar2);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar3);
  return;
}


// ==== FUN_00489e60 @ 0x00489e60 ====

void FUN_00489e60(byte param_1)

{
  void *in_ECX;
  
  FUN_00489c00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00489e80 @ 0x00489e80 ====

void FUN_00489e80(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = 0;
  return;
}


// ==== FUN_00489e90 @ 0x00489e90 ====

void FUN_00489e90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00489ea0 @ 0x00489ea0 ====

void FUN_00489ea0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6d4c;
  return;
}


// ==== FUN_00489eb0 @ 0x00489eb0 ====

void FUN_00489eb0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6d3c,&PTR___break_009a6d38);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00489efe;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00489efe:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00489fb0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00489f60 @ 0x00489f60 ====

void FUN_00489f60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6d44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00489f80 @ 0x00489f80 ====

void FUN_00489f80(byte param_1)

{
  void *in_ECX;
  
  FUN_00489e90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00489fa0 @ 0x00489fa0 ====

void FUN_00489fa0(void)

{
  int in_ECX;
  
  *(undefined ***)(in_ECX + 0x124) = &PTR_FUN_009a6d44;
  return;
}


// ==== FUN_00489fb0 @ 0x00489fb0 ====

void FUN_00489fb0(int *param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_286 [17];
  undefined1 auStack_275 [128];
  undefined1 auStack_1f5 [128];
  undefined1 uStack_175;
  undefined4 uStack_174;
  byte bStack_170;
  undefined **ppuStack_16c;
  undefined1 auStack_168 [2];
  undefined2 uStack_166;
  undefined1 auStack_164 [2];
  undefined2 auStack_162 [37];
  int iStack_118;
  char acStack_114 [8];
  undefined1 auStack_10c [256];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e2db;
  pvStack_c = ExceptionList;
  uVar7 = 1;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*param_1 + 8))();
  if (uVar3 < 2) {
    ExceptionList = pvStack_c;
    return;
  }
  do {
    FUN_0044a580(auStack_10c,&DAT_009a6d3c,&DAT_0099cf70);
    pcVar4 = (char *)(**(code **)(*param_1 + 0x10))(uVar7,0);
    uVar3 = 0;
    iVar5 = -(int)pcVar4;
    while (*pcVar4 == pcVar4[(int)(acStack_114 + iVar5)]) {
      if (*pcVar4 == '\0') goto LAB_0048a191;
      uVar3 = uVar3 + 1;
      pcVar4 = pcVar4 + 1;
      if (0xff < uVar3) goto LAB_0048a191;
    }
    auStack_275[0] = 0;
    auStack_1f5[0] = 0;
    ppuStack_16c = &PTR_FUN_009a6d44;
    iStack_118 = 0;
    pvStack_c = (void *)0x0;
    FUN_00797a50(auStack_286 + -10,0,0x17c);
    FUN_00475a90(uVar7,0);
    FUN_0047c610(uVar7,1,auStack_286 + -8);
    FUN_00482fa0(uVar7,2,auStack_275);
    FUN_00482fa0(uVar7,3,auStack_1f5);
    uStack_175 = FUN_004774b0(uVar7,4);
    uStack_174 = FUN_004756e0(uVar7,5);
    bStack_170 = FUN_004753b0(uVar7,6);
    iStack_118 = iStack_118 + (uint)bStack_170;
    if (bStack_170 != 0) {
      auStack_168[0] = FUN_004753b0(uVar7,7);
      uStack_166 = FUN_00475a90(uVar7,8);
      iVar5 = 1;
      iVar6 = 9;
      if (1 < bStack_170) {
        do {
          uVar1 = FUN_004753b0(uVar7,iVar6);
          auStack_168[iVar5 * 4] = uVar1;
          uVar2 = FUN_00475a90(uVar7,iVar6 + 1);
          *(undefined2 *)(auStack_168 + iVar5 * 4 + 2) = uVar2;
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 2;
        } while (iVar5 < (int)(uint)bStack_170);
      }
    }
    (**(code **)(*DAT_00b5a770 + 4))(auStack_286 + -10);
    pvStack_c = (void *)0xffffffff;
    ppuStack_16c = &PTR_FUN_009a6d44;
LAB_0048a191:
    uVar7 = uVar7 + 1;
    uVar3 = (**(code **)(*param_1 + 8))();
    if (uVar3 <= uVar7) {
      ExceptionList = pvStack_c;
      return;
    }
  } while( true );
}


// ==== FUN_0048a1c0 @ 0x0048a1c0 ====

void FUN_0048a1c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0048a200 @ 0x0048a200 ====

void FUN_0048a200(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6d70;
  return;
}


// ==== FUN_0048a210 @ 0x0048a210 ====

void FUN_0048a210(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6d60,s_Monster_009a6d58);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0048a25e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0048a25e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_0048a400(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_0048a2c0 @ 0x0048a2c0 ====

void FUN_0048a2c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6d68;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048a2e0 @ 0x0048a2e0 ====

void FUN_0048a2e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0048a1c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048a300 @ 0x0048a300 ====

void FUN_0048a300(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6d68;
  return;
}


// ==== FUN_0048a310 @ 0x0048a310 ====

void FUN_0048a310(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e2fe;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined2 *)(in_ECX + 0x56) = 0;
  *(undefined2 *)(in_ECX + 0x58) = 0;
  *(undefined1 *)(in_ECX + 0x74) = 0;
  *(undefined1 *)(in_ECX + 0xf4) = 0;
  *(undefined4 *)(in_ECX + 0x138) = 0;
  *(undefined4 *)(in_ECX + 0x13c) = 0;
  *(undefined ***)(in_ECX + 0x148) = &PTR_FUN_009a6d68;
  *(undefined1 *)(in_ECX + 0x154) = 0;
  *(undefined1 *)(in_ECX + 0x155) = 0;
  local_4 = 0;
  _eh_vector_constructor_iterator_
            ((void *)(in_ECX + 0x158),0x34,8,(_func_void_void_ptr *)&LAB_00488080,FUN_006ef6d0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0048a3a0 @ 0x0048a3a0 ====

void FUN_0048a3a0(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e2fe;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0x158),0x34,8,FUN_006ef6d0);
  *(undefined ***)(in_ECX + 0x148) = &PTR_FUN_009a6d68;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0048a400 @ 0x0048a400 ====

void FUN_0048a400(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 uVar10;
  ushort *puVar11;
  int iVar12;
  uint uVar13;
  float10 fVar14;
  double dVar15;
  int iVar16;
  undefined2 uStack_788;
  undefined1 auStack_786 [66];
  undefined4 uStack_744;
  undefined4 uStack_740;
  undefined2 uStack_73c;
  undefined4 uStack_738;
  undefined2 uStack_734;
  ushort uStack_732;
  ushort uStack_730;
  undefined1 uStack_72e;
  undefined1 uStack_72d;
  undefined1 uStack_72c;
  undefined1 uStack_72b;
  undefined1 uStack_72a;
  undefined1 uStack_729;
  undefined1 uStack_728;
  undefined1 uStack_727;
  undefined1 uStack_726;
  undefined1 uStack_725;
  undefined1 uStack_724;
  float fStack_720;
  float fStack_71c;
  undefined4 uStack_718;
  undefined1 auStack_714 [128];
  undefined1 auStack_694 [64];
  undefined4 uStack_654;
  uint uStack_650;
  uint uStack_64c;
  undefined4 uStack_648;
  undefined2 uStack_644;
  undefined2 uStack_642;
  undefined **ppuStack_640;
  undefined2 uStack_63c;
  undefined2 uStack_63a;
  undefined2 uStack_638;
  undefined2 uStack_636;
  byte bStack_634;
  byte bStack_633;
  undefined1 auStack_630 [10];
  ushort auStack_626 [203];
  ushort uStack_490;
  undefined2 auStack_48c [2];
  undefined4 auStack_488 [29];
  undefined1 auStack_414 [248];
  char acStack_31c [8];
  undefined1 auStack_314 [256];
  undefined1 auStack_214 [256];
  char acStack_114 [264];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e331;
  pvStack_c = ExceptionList;
  uVar13 = 1;
  ExceptionList = &pvStack_c;
  uVar7 = (**(code **)(*param_1 + 8))();
  if (uVar7 < 2) {
    ExceptionList = pvStack_c;
    return;
  }
LAB_0048a440:
  FUN_0048a310();
  uStack_4 = 0;
  pcVar8 = (char *)(**(code **)(*param_1 + 0x10))(uVar13,0);
  FUN_0044a580(acStack_114,&DAT_009a6d60,&DAT_0099cf70);
  uVar7 = 0;
  iVar16 = -(int)pcVar8;
LAB_0048a487:
  if (*pcVar8 == pcVar8[(int)(acStack_114 + iVar16)]) {
    if (*pcVar8 != '\0') goto code_r0x0048a492;
    goto LAB_0048a4a0;
  }
  FUN_00797a50(&uStack_788,0,0x374);
  uStack_788 = FUN_00475a90(uVar13,0);
  FUN_00483a00(uVar13,1,auStack_786);
  uStack_744 = FUN_00477a70(uVar13,2);
  uStack_740 = FUN_00477a70(uVar13,3);
  uStack_73c = FUN_00475a90(uVar13,4);
  uStack_738 = FUN_00477a70(uVar13,5);
  uStack_734 = FUN_00475a90(uVar13,6);
  uVar4 = FUN_00475a90(uVar13,7);
  uVar5 = FUN_00475a90(uVar13,8);
  uStack_730 = uVar4;
  if (uVar4 <= uVar5) {
    uStack_730 = uVar5;
  }
  uStack_732 = uVar4;
  uStack_72e = FUN_004753b0(uVar13,9);
  uStack_72d = FUN_004753b0(uVar13,10);
  uStack_72c = FUN_004753b0(uVar13,0xb);
  uStack_72b = FUN_004753b0(uVar13,0xc);
  uStack_728 = FUN_004753b0(uVar13,0xd);
  uStack_72a = FUN_004753b0(uVar13,0xe);
  uStack_729 = FUN_004753b0(uVar13,0xf);
  uStack_727 = FUN_004753b0(uVar13,0x10);
  uStack_726 = FUN_004753b0(uVar13,0x11);
  fVar14 = (float10)FUN_00477510(uVar13,0x12);
  fStack_720 = (float)fVar14;
  fVar14 = (float10)FUN_00477510(uVar13,0x13);
  fStack_71c = (float)fVar14;
  uStack_718 = 0;
  uStack_725 = FUN_004753b0(uVar13,0x14);
  uStack_724 = FUN_004753b0(uVar13,0x15);
  FUN_00482fa0(uVar13,0x16,auStack_714);
  FUN_00483a00(uVar13,0x17,auStack_694);
  uStack_654 = FUN_004756e0(uVar13,0x18);
  uVar7 = FUN_004756e0(uVar13,0x19);
  uVar9 = FUN_004756e0(uVar13,0x1a);
  uStack_64c = uVar7;
  if (uVar7 <= uVar9) {
    uStack_64c = uVar9;
  }
  uStack_650 = uVar7;
  uStack_648 = FUN_004756e0(uVar13,0x1b);
  uStack_644 = FUN_00475a90(uVar13,0x1c);
  uStack_490 = FUN_00475a90(uVar13,0x1e);
  if (0xf < uStack_490) {
    FUN_0044a580(auStack_414,&DAT_009a6d60,s_ERROR___MONSTER_table_____wMaxIt_009a6d98);
    FUN_00797b80(auStack_414);
    auStack_214[0] = 0;
    uVar10 = FUN_0044a580(auStack_214,s_File___s__Line___d_0099f0a0,
                          s___Loader_Creature_Monster_cpp_009a6d78,0x75);
    FUN_00797b80(uVar10);
    FUN_00797a40();
  }
  uStack_63c = FUN_00475a90(uVar13,0x1f);
  uStack_63a = FUN_00475a90(uVar13,0x20);
  uStack_638 = FUN_00475a90(uVar13,0x21);
  uStack_636 = FUN_00475a90(uVar13,0x22);
  uStack_642 = FUN_00475a90(uVar13,0x1d);
  bVar1 = FUN_004753b0(uVar13,0x23);
  bVar2 = FUN_004753b0(uVar13,0x24);
  bStack_633 = bVar1;
  if (bVar1 <= bVar2) {
    bStack_633 = bVar2;
  }
  iVar12 = 0x25;
  puVar11 = auStack_626;
  iVar16 = 8;
  bStack_634 = bVar1;
  do {
    uVar7 = FUN_004753b0(uVar13,iVar12);
    *(uint *)(puVar11 + -5) = uVar7 & 0xff;
    uVar5 = FUN_00475a90(uVar13,iVar12 + 1);
    uVar4 = FUN_00475a90(uVar13,iVar12 + 2);
    puVar11[-3] = uVar5;
    if (uVar4 < uVar5) {
      uVar4 = uVar5;
    }
    puVar11[-2] = uVar4;
    uVar5 = FUN_00475a90(uVar13,iVar12 + 3);
    uVar4 = FUN_00475a90(uVar13,iVar12 + 4);
    puVar11[-1] = uVar5;
    if (uVar4 < uVar5) {
      uVar4 = uVar5;
    }
    *puVar11 = uVar4;
    uVar3 = FUN_004753b0(uVar13,iVar12 + 5);
    *(undefined1 *)(puVar11 + 1) = uVar3;
    uVar10 = FUN_004756e0(uVar13,iVar12 + 6);
    *(undefined4 *)(puVar11 + 3) = uVar10;
    uVar10 = FUN_004756e0(uVar13,iVar12 + 7);
    *(undefined4 *)(puVar11 + 5) = uVar10;
    uVar10 = FUN_004756e0(uVar13,iVar12 + 8);
    *(undefined4 *)(puVar11 + 7) = uVar10;
    uVar10 = FUN_004756e0(uVar13,iVar12 + 9);
    *(undefined4 *)(puVar11 + 9) = uVar10;
    uVar10 = FUN_004756e0(uVar13,iVar12 + 10);
    *(undefined4 *)(puVar11 + 0xb) = uVar10;
    uVar10 = FUN_004756e0(uVar13,iVar12 + 0xb);
    *(undefined4 *)(puVar11 + 0xd) = uVar10;
    uVar10 = FUN_004756e0(uVar13,iVar12 + 0xc);
    *(undefined4 *)(puVar11 + 0xf) = uVar10;
    uVar10 = FUN_004756e0(uVar13,iVar12 + 0xd);
    *(undefined4 *)(puVar11 + 0x11) = uVar10;
    uVar10 = FUN_004756e0(uVar13,iVar12 + 0xe);
    *(undefined4 *)(puVar11 + 0x13) = uVar10;
    iVar12 = iVar12 + 0xf;
    puVar11 = puVar11 + 0x1a;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  iVar12 = 0;
  iVar16 = 0x9d;
  do {
    uVar6 = FUN_00475a90(uVar13,iVar16);
    auStack_48c[iVar12 * 4] = uVar6;
    uVar10 = FUN_004756e0(uVar13,iVar16 + 1);
    auStack_488[iVar12 * 2] = uVar10;
    iVar12 = iVar12 + 1;
    iVar16 = iVar16 + 2;
  } while (iVar12 < 0xf);
  FUN_0044a580(auStack_314,&DAT_009a6d60,&DAT_0099cf70);
  pcVar8 = (char *)(**(code **)(*param_1 + 0x10))(uVar13,0xbb);
  uVar7 = 0;
  iVar16 = -(int)pcVar8;
  while (*pcVar8 == pcVar8[(int)(acStack_31c + iVar16)]) {
    if (*pcVar8 == '\0') goto LAB_0048a994;
    uVar7 = uVar7 + 1;
    pcVar8 = pcVar8 + 1;
    if (0xff < uVar7) break;
  }
  pcVar8 = (char *)(**(code **)(*param_1 + 0x10))(uVar13,0xbb);
  FUN_004772e0(pcVar8,uVar13,0xbb);
  uVar7 = 0;
  while (pcVar8[uVar7] != '\0') {
    uVar7 = uVar7 + 1;
    if (0xff < uVar7) goto LAB_0048a994;
  }
  if (uVar7 == 0) goto LAB_0048a994;
  dVar15 = _atof(pcVar8);
  fStack_720 = (float)dVar15;
  goto LAB_0048a997;
code_r0x0048a492:
  uVar7 = uVar7 + 1;
  pcVar8 = pcVar8 + 1;
  if (0xff < uVar7) goto LAB_0048a4a0;
  goto LAB_0048a487;
LAB_0048a4a0:
  pvStack_c = (void *)0x1;
LAB_0048a9bb:
  _eh_vector_destructor_iterator_(auStack_630,0x34,8,FUN_006ef6d0);
  pvStack_c = (void *)0xffffffff;
  ppuStack_640 = &PTR_FUN_009a6d68;
  uVar13 = uVar13 + 1;
  uVar7 = (**(code **)(*param_1 + 8))();
  if (uVar7 <= uVar13) {
    ExceptionList = pvStack_c;
    return;
  }
  goto LAB_0048a440;
LAB_0048a994:
  fStack_720 = 0.0;
LAB_0048a997:
  (**(code **)(*DAT_00b5a75c + 4))(auStack_786 + -10);
  pvStack_c = (void *)0x2;
  goto LAB_0048a9bb;
}


// ==== FUN_0048aa40 @ 0x0048aa40 ====

undefined2 FUN_0048aa40(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x20408);
}


// ==== FUN_0048aa50 @ 0x0048aa50 ====

int FUN_0048aa50(ushort param_1)

{
  int in_ECX;
  
  if (param_1 < *(ushort *)(in_ECX + 0x20408)) {
    return in_ECX + 8 + (uint)param_1 * 0x102;
  }
  return 0;
}


// ==== FUN_0048aa80 @ 0x0048aa80 ====

void FUN_0048aa80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e348;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6dec;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a6de4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x102,0x200,FUN_00479840,FUN_006ef6d0);
  in_ECX[0x8102] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aa38 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa38 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0048ab20 @ 0x0048ab20 ====

void FUN_0048ab20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e35a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6dec;
  DAT_00b5aa38 = 0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a6de4;
  _eh_vector_destructor_iterator_(in_ECX + 2,0x102,0x200,FUN_006ef6d0);
  *in_ECX = &PTR_FUN_009a4184;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0048ab90 @ 0x0048ab90 ====

void FUN_0048ab90(undefined2 param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  char *pcVar5;
  int in_ECX;
  uint uVar6;
  
  uVar4 = *(ushort *)(in_ECX + 0x20408);
  *(int *)(in_ECX + 0x20408) = *(int *)(in_ECX + 0x20408) + 1;
  iVar2 = in_ECX + (uint)uVar4 * 0x102;
  pcVar1 = (char *)(iVar2 + 10);
  *(undefined2 *)(iVar2 + 8) = param_1;
  uVar6 = 0;
  pcVar5 = pcVar1;
  do {
    cVar3 = pcVar5[param_2 - (int)pcVar1];
    *pcVar5 = cVar3;
    if (cVar3 == '\0') {
      return;
    }
    uVar6 = uVar6 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar6 < 0x100);
  *pcVar1 = '\0';
  return;
}


// ==== FUN_0048abf0 @ 0x0048abf0 ====

void FUN_0048abf0(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  char local_208 [256];
  undefined4 local_108;
  char local_104 [4];
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6ddc,s_Dungeon_FileList_009a6dc8);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0048ac3e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0048ac3e:
  local_108 = param_1;
  local_104[0] = '\n';
  local_104[1] = 0x2c;
  local_104[2] = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  iVar6 = 1;
  iVar7 = 0x1ff;
  do {
    pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))(iVar6,1);
    FUN_0044a580(local_104,&DAT_009a6ddc,s_Dungeon_FileList_009a6dc8 + 0x11);
    uVar1 = 0;
    pcVar4 = pcVar3;
    do {
      if (*pcVar4 != pcVar4[(int)(local_104 + -(int)pcVar3)]) {
        uVar5 = FUN_00475a90(iVar6,0);
        FUN_0048ab90(uVar5,pcVar3);
        break;
      }
      if (*pcVar4 == '\0') break;
      uVar1 = uVar1 + 1;
      pcVar4 = pcVar4 + 1;
    } while (uVar1 < 0x100);
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) {
      (**(code **)(*DAT_00b5aa34 + 0xc))(piVar2);
      return;
    }
  } while( true );
}


// ==== FUN_0048ad20 @ 0x0048ad20 ====

void FUN_0048ad20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6de4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x102,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_0048ad40 @ 0x0048ad40 ====

void FUN_0048ad40(byte param_1)

{
  void *in_ECX;
  
  FUN_0048ad20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048ad60 @ 0x0048ad60 ====

void FUN_0048ad60(byte param_1)

{
  void *in_ECX;
  
  FUN_0048ab20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048ad80 @ 0x0048ad80 ====

void FUN_0048ad80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6e14;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x100,0x800,FUN_006ef6d0);
  return;
}


// ==== FUN_0048ada0 @ 0x0048ada0 ====

void FUN_0048ada0(byte param_1)

{
  void *in_ECX;
  
  FUN_0048ad80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048adc0 @ 0x0048adc0 ====

void FUN_0048adc0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e378;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6e1c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a6e14;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x100,0x800,FUN_005fd550,FUN_006ef6d0);
  in_ECX[0x20002] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aa3c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa3c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0048ae60 @ 0x0048ae60 ====

undefined2 FUN_0048ae60(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x80008);
}


// ==== FUN_0048ae70 @ 0x0048ae70 ====

int FUN_0048ae70(ushort param_1)

{
  int in_ECX;
  
  if (param_1 < *(ushort *)(in_ECX + 0x80008)) {
    return (uint)param_1 * 0x100 + 8 + in_ECX;
  }
  return 0;
}


// ==== FUN_0048ae90 @ 0x0048ae90 ====

void FUN_0048ae90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e38a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6e1c;
  DAT_00b5aa3c = 0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a6e14;
  _eh_vector_destructor_iterator_(in_ECX + 2,0x100,0x800,FUN_006ef6d0);
  *in_ECX = &PTR_FUN_009a4184;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0048af00 @ 0x0048af00 ====

void FUN_0048af00(undefined4 param_1)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int in_ECX;
  char *pcVar9;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6e0c,s_Action_FileList_009a6df8);
  uVar3 = 0;
  do {
    local_208[uVar3] = local_100[uVar3];
    if (local_100[uVar3] == '\0') goto LAB_0048af4e;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  local_208[0] = '\0';
LAB_0048af4e:
  local_108 = param_1;
  pcVar9 = local_208;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar4 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  iVar5 = (**(code **)(*piVar4 + 8))();
  if (iVar5 == 0) {
LAB_0048b048:
    (**(code **)(*DAT_00b5aa34 + 0xc))(piVar4);
    return;
  }
LAB_0048afa0:
  pcVar6 = (char *)(**(code **)(*piVar4 + 0x10))(0,0);
  FUN_0044a580(local_208 + 0xfc,&DAT_009a6e0c,&DAT_009a6e08);
  uVar3 = 0;
  pcVar7 = pcVar6;
  do {
    if (*pcVar7 != pcVar7[(int)(local_208 + (0xfc - (int)pcVar6))]) {
      uVar2 = *(ushort *)(in_ECX + 0x80008);
      *(int *)(in_ECX + 0x80008) = *(int *)(in_ECX + 0x80008) + 1;
      pcVar7 = (char *)((uint)uVar2 * 0x100 + 8 + in_ECX);
      uVar3 = 0;
      pcVar8 = pcVar7;
      goto LAB_0048b011;
    }
    if (*pcVar7 == '\0') break;
    uVar3 = uVar3 + 1;
    pcVar7 = pcVar7 + 1;
  } while (uVar3 < 0x100);
  goto LAB_0048b02b;
  while( true ) {
    uVar3 = uVar3 + 1;
    pcVar8 = pcVar8 + 1;
    if (0xff < uVar3) break;
LAB_0048b011:
    cVar1 = pcVar8[(int)pcVar6 - (int)pcVar7];
    *pcVar8 = cVar1;
    if (cVar1 == '\0') goto LAB_0048b02b;
  }
  *pcVar7 = '\0';
LAB_0048b02b:
  pcVar6 = pcVar9 + 1;
  pcVar9 = pcVar6;
  pcVar7 = (char *)(**(code **)(*piVar4 + 8))();
  if (pcVar7 <= pcVar6) goto LAB_0048b048;
  goto LAB_0048afa0;
}


// ==== FUN_0048b060 @ 0x0048b060 ====

void FUN_0048b060(byte param_1)

{
  void *in_ECX;
  
  FUN_0048ae90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048b080 @ 0x0048b080 ====

void FUN_0048b080(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0048b090 @ 0x0048b090 ====

void FUN_0048b090(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6e28;
  return;
}


// ==== FUN_0048b0a0 @ 0x0048b0a0 ====

void FUN_0048b0a0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0048b0a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aa30 + 0x14))();
  return;
}


// ==== FUN_0048b0b0 @ 0x0048b0b0 ====

void FUN_0048b0b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0048b080();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048b0d0 @ 0x0048b0d0 ====

undefined2 FUN_0048b0d0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x20408);
}


// ==== FUN_0048b0e0 @ 0x0048b0e0 ====

int FUN_0048b0e0(ushort param_1)

{
  int in_ECX;
  
  if (param_1 < *(ushort *)(in_ECX + 0x20408)) {
    return in_ECX + 8 + (uint)param_1 * 0x102;
  }
  return 0;
}


// ==== FUN_0048b110 @ 0x0048b110 ====

void FUN_0048b110(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e3a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6e54;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a6e4c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x102,0x200,FUN_00479840,FUN_006ef6d0);
  in_ECX[0x8102] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aa40 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa40 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0048b1b0 @ 0x0048b1b0 ====

void FUN_0048b1b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e3ba;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a6e54;
  DAT_00b5aa40 = 0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a6e4c;
  _eh_vector_destructor_iterator_(in_ECX + 2,0x102,0x200,FUN_006ef6d0);
  *in_ECX = &PTR_FUN_009a4184;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0048b220 @ 0x0048b220 ====

void FUN_0048b220(undefined2 param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  char *pcVar5;
  int in_ECX;
  uint uVar6;
  
  uVar4 = *(ushort *)(in_ECX + 0x20408);
  *(int *)(in_ECX + 0x20408) = *(int *)(in_ECX + 0x20408) + 1;
  iVar2 = in_ECX + (uint)uVar4 * 0x102;
  pcVar1 = (char *)(iVar2 + 10);
  *(undefined2 *)(iVar2 + 8) = param_1;
  uVar6 = 0;
  pcVar5 = pcVar1;
  do {
    cVar3 = pcVar5[param_2 - (int)pcVar1];
    *pcVar5 = cVar3;
    if (cVar3 == '\0') {
      return;
    }
    uVar6 = uVar6 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar6 < 0x100);
  *pcVar1 = '\0';
  return;
}


// ==== FUN_0048b280 @ 0x0048b280 ====

void FUN_0048b280(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  char local_208 [256];
  undefined4 local_108;
  char local_104 [4];
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a6e44,s_Quest_FileList_009a6e34);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0048b2ce;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0048b2ce:
  local_108 = param_1;
  local_104[0] = '\n';
  local_104[1] = 0x2c;
  local_104[2] = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  iVar6 = 1;
  iVar7 = 0x1ff;
  do {
    pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))(iVar6,1);
    FUN_0044a580(local_104,&DAT_009a6e44,s_Quest_FileList_009a6e34 + 0xf);
    uVar1 = 0;
    pcVar4 = pcVar3;
    do {
      if (*pcVar4 != pcVar4[(int)(local_104 + -(int)pcVar3)]) {
        uVar5 = FUN_00475a90(iVar6,0);
        FUN_0048b220(uVar5,pcVar3);
        break;
      }
      if (*pcVar4 == '\0') break;
      uVar1 = uVar1 + 1;
      pcVar4 = pcVar4 + 1;
    } while (uVar1 < 0x100);
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) {
      (**(code **)(*DAT_00b5aa34 + 0xc))(piVar2);
      return;
    }
  } while( true );
}


// ==== FUN_0048b3b0 @ 0x0048b3b0 ====

void FUN_0048b3b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a6e4c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x102,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_0048b3d0 @ 0x0048b3d0 ====

void FUN_0048b3d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0048b3b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048b3f0 @ 0x0048b3f0 ====

void FUN_0048b3f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0048b1b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048b480 @ 0x0048b480 ====

uint FUN_0048b480(void)

{
  uint in_ECX;
  
  return in_ECX >> 0x18 |
         CONCAT31((int3)in_ECX,(char)(in_ECX >> 8)) << 0x10 | (in_ECX >> 0x10 & 0xff) << 8;
}


// ==== FUN_0048b4b0 @ 0x0048b4b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048b4b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a7530;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aadc = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aadc = in_ECX;
  return;
}


// ==== FUN_0048b500 @ 0x0048b500 ====

undefined4 FUN_0048b500(undefined4 param_1)

{
  undefined1 ***pppuVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  undefined2 uVar6;
  undefined4 uVar5;
  undefined4 uStack_27c;
  undefined1 ***pppuStack_278;
  undefined4 uStack_274;
  int ***pppiStack_270;
  undefined4 uStack_26c;
  undefined1 ****ppppuStack_268;
  undefined4 uStack_264;
  undefined1 ***pppuStack_260;
  undefined4 uStack_25c;
  undefined1 ***pppuStack_258;
  undefined4 uStack_254;
  undefined1 ***pppuStack_250;
  undefined4 uStack_24c;
  undefined1 ***pppuStack_248;
  undefined4 uStack_244;
  undefined1 ***pppuStack_240;
  undefined4 uStack_23c;
  int ***pppiStack_238;
  undefined4 uStack_234;
  undefined1 ***pppuStack_230;
  undefined4 uStack_22c;
  undefined1 ***pppuStack_228;
  uint uStack_224;
  undefined1 ***pppuStack_220;
  undefined4 uStack_21c;
  undefined1 ***pppuStack_218;
  undefined4 uStack_214;
  undefined1 ***pppuStack_210;
  undefined4 uStack_20c;
  undefined1 ***pppuStack_208;
  undefined1 **ppuStack_204;
  int ***pppiStack_200;
  undefined4 uStack_1fc;
  int ***pppiStack_1f8;
  undefined4 uStack_1f4;
  undefined1 ***pppuStack_1f0;
  undefined4 uStack_1ec;
  int ***pppiStack_1e8;
  undefined4 uStack_1e4;
  undefined1 ***pppuStack_1e0;
  undefined4 uStack_1dc;
  int ***pppiStack_1d8;
  int *piStack_1d4;
  undefined1 ***pppuStack_1d0;
  undefined4 uStack_1cc;
  undefined1 ***pppuStack_1c8;
  int *piStack_1c4;
  undefined1 ***pppuStack_1c0;
  undefined4 uStack_1bc;
  undefined1 ***pppuStack_1b8;
  undefined1 *puStack_1b4;
  undefined1 ***pppuStack_1b0;
  undefined *puStack_1ac;
  undefined1 ***pppuStack_1a8;
  int **ppiStack_1a4;
  int *piStack_1a0;
  undefined1 *puStack_198;
  int **ppiStack_194;
  undefined *puStack_18c;
  char *pcStack_188;
  undefined4 uStack_184;
  int *apiStack_17c [2];
  undefined1 auStack_174 [8];
  int *piStack_16c;
  int *piStack_168;
  undefined1 auStack_164 [8];
  undefined1 auStack_15c [8];
  undefined1 auStack_154 [4];
  undefined1 auStack_150 [4];
  undefined1 auStack_14c [4];
  undefined1 auStack_148 [4];
  int *piStack_144;
  int *piStack_140;
  int *apiStack_13c [2];
  int *piStack_134;
  uint uStack_130;
  undefined1 auStack_12c [4];
  undefined1 auStack_128 [4];
  undefined1 auStack_124 [8];
  undefined1 auStack_11c [8];
  int *apiStack_114 [2];
  undefined1 auStack_10c [8];
  undefined1 *apuStack_104 [62];
  uint *puStack_c;
  
  uStack_184 = param_1;
  pcStack_188 = (char *)0x48b517;
  pppuVar1 = (undefined1 ***)(**(code **)(*DAT_00b5a69c + 4))();
  if (pppuVar1 == (undefined1 ***)0x0) {
    pcStack_188 = s_LoadInfo___Reader_Creatiaon_is_F_009a6e64;
    puStack_18c = &DAT_009a7528;
    ppiStack_194 = (int **)0x48b534;
    FUN_0044a580();
    ppiStack_194 = (int **)apuStack_104;
    puStack_198 = (undefined1 *)0x48b541;
    FUN_00797b80();
    return 0;
  }
  pcStack_188 = auStack_150;
  puStack_18c = (undefined *)0x2;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    puStack_198 = auStack_10c;
    ppiStack_194 = (int **)&DAT_009a7528;
    FUN_0044a580();
    piStack_1a0 = (int *)0x48b587;
    FUN_00797b80();
    ppiStack_194 = (int **)0x48b596;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  sVar4 = CONCAT11(auStack_15c[4],auStack_15c[5]);
  ppiStack_194 = apiStack_13c;
  puStack_198 = (undefined1 *)0x4;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 4) {
    ppiStack_1a4 = apiStack_114;
    piStack_1a0 = (int *)&DAT_009a7528;
    pppuStack_1a8 = (undefined1 ***)0x48b5da;
    FUN_0044a580();
    pppuStack_1a8 = (undefined1 ***)apiStack_114;
    puStack_1ac = (undefined *)0x48b5e7;
    FUN_00797b80();
    piStack_1a0 = (int *)0x48b5f6;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  piStack_1a0 = (int *)auStack_128;
  *puStack_c = CONCAT31((int3)piStack_144,(char)((uint)piStack_144 >> 8)) << 0x10 |
               ((uint)piStack_144 >> 0x10 & 0xff) << 8 | (uint)piStack_144 >> 0x18;
  ppiStack_1a4 = (int **)0x4;
  pppuStack_1a8 = (undefined1 ***)0x48b63b;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 4) {
    pppuStack_1a8 = (undefined1 ***)s_LoadInfo___Read_____PEERAGE_____F_009a6ed4;
    pppuStack_1b0 = (undefined1 ***)auStack_11c;
    puStack_1ac = &DAT_009a7528;
    puStack_1b4 = (undefined1 *)0x48b657;
    FUN_0044a580();
    puStack_1b4 = auStack_11c;
    pppuStack_1b8 = (undefined1 ***)0x48b664;
    FUN_00797b80();
    puStack_1ac = (undefined *)0x48b673;
    pppuStack_1a8 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_1a8 = (undefined1 ***)&piStack_140;
  puStack_c[1] = CONCAT31((int3)uStack_130,(char)(uStack_130 >> 8)) << 0x10 |
                 (uStack_130 >> 0x10 & 0xff) << 8 | uStack_130 >> 0x18;
  puStack_1ac = (undefined *)0x4;
  pppuStack_1b0 = (undefined1 ***)0x48b6b2;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 4) {
    pppuStack_1b0 = (undefined1 ***)s_LoadInfo___Read_____EXP_____Fail_009a6f00;
    puStack_1b4 = (undefined1 *)0x48b6c8;
    FUN_0044a670();
    pppuStack_1b0 = (undefined1 ***)auStack_124;
    puStack_1b4 = (undefined1 *)0x48b6d5;
    FUN_00797b80();
    puStack_1b4 = (undefined1 *)0x48b6e4;
    pppuStack_1b0 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_1b0 = (undefined1 ***)0x48b6fb;
  uVar3 = FUN_0048b480();
  pppuStack_1b0 = (undefined1 ***)auStack_128;
  puStack_c[2] = uVar3;
  puStack_1b4 = (undefined1 *)0x4;
  pppuStack_1b8 = (undefined1 ***)0x48b70f;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 4) {
    pppuStack_1b8 = (undefined1 ***)s_LoadInfo___Read_____MONEY_____Fa_009a6f28;
    uStack_1bc = 0x48b725;
    FUN_0044a670();
    pppuStack_1b8 = (undefined1 ***)auStack_12c;
    uStack_1bc = 0x48b732;
    FUN_00797b80();
    uStack_1bc = 0x48b741;
    pppuStack_1b8 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_1b8 = (undefined1 ***)0x48b75b;
  uVar3 = FUN_0048b480();
  puStack_c[3] = uVar3;
  pppuStack_1b8 = (undefined1 ***)auStack_148;
  uStack_1bc = 4;
  pppuStack_1c0 = (undefined1 ***)0x48b76c;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 4) {
    pppuStack_1c0 = (undefined1 ***)s_LoadInfo___Read_____STORE_MONEY___009a6f50;
    piStack_1c4 = (int *)0x48b782;
    FUN_0044a670();
    pppuStack_1c0 = (undefined1 ***)&piStack_134;
    piStack_1c4 = (int *)0x48b78f;
    FUN_00797b80();
    piStack_1c4 = (int *)0x48b79e;
    pppuStack_1c0 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_1c0 = (undefined1 ***)0x48b7b5;
  uVar3 = FUN_0048b480();
  pppuStack_1c0 = (undefined1 ***)&piStack_140;
  puStack_c[4] = uVar3;
  piStack_1c4 = (int *)0x4;
  pppuStack_1c8 = (undefined1 ***)0x48b7c6;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 4) {
    pppuStack_1c8 = (undefined1 ***)s_LoadInfo___Read_____STORAGE_MONE_009a6f80;
    uStack_1cc = 0x48b7dc;
    FUN_0044a670();
    pppuStack_1c8 = (undefined1 ***)apiStack_13c;
    uStack_1cc = 0x48b7e9;
    FUN_00797b80();
    uStack_1cc = 0x48b7f8;
    pppuStack_1c8 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_1c8 = (undefined1 ***)0x48b80f;
  uVar3 = FUN_0048b480();
  puStack_c[5] = uVar3;
  pppuStack_1c8 = (undefined1 ***)&piStack_168;
  uStack_1cc = 4;
  pppuStack_1d0 = (undefined1 ***)0x48b820;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 4) {
    pppuStack_1d0 = (undefined1 ***)s_LoadInfo___Read_____HP_____Fail_009a6fb0;
    piStack_1d4 = (int *)0x48b836;
    FUN_0044a670();
    pppuStack_1d0 = (undefined1 ***)&piStack_144;
    piStack_1d4 = (int *)0x48b843;
    FUN_00797b80();
    piStack_1d4 = (int *)0x48b852;
    pppuStack_1d0 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_1d0 = (undefined1 ***)0x48b869;
  uVar3 = FUN_0048b480();
  pppuStack_1d0 = (undefined1 ***)&piStack_16c;
  puStack_c[6] = uVar3;
  piStack_1d4 = (int *)0x4;
  pppiStack_1d8 = (int ***)0x48b87a;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 4) {
    pppiStack_1d8 = (int ***)s_LoadInfo___Read_____MP_____Fail_009a6fd8;
    uStack_1dc = 0x48b890;
    FUN_0044a670();
    pppiStack_1d8 = (int ***)auStack_14c;
    uStack_1dc = 0x48b89d;
    FUN_00797b80();
    uStack_1dc = 0x48b8ac;
    pppiStack_1d8 = (int ***)pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppiStack_1d8 = (int ***)0x48b8c3;
  uVar3 = FUN_0048b480();
  puStack_c[7] = uVar3;
  pppiStack_1d8 = (int ***)&pppuStack_1c0;
  uStack_1dc = 2;
  pppuStack_1e0 = (undefined1 ***)0x48b8d4;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppuStack_1e0 = (undefined1 ***)s_LoadInfo___Read_____STR_DEF_____F_009a7000;
    uStack_1e4 = 0x48b8ea;
    FUN_0044a670();
    pppuStack_1e0 = (undefined1 ***)auStack_154;
    uStack_1e4 = 0x48b8f7;
    FUN_00797b80();
    uStack_1e4 = 0x48b906;
    pppuStack_1e0 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_1e0 = (undefined1 ***)&puStack_198;
  uStack_1e4 = 2;
  *(ushort *)(puStack_c + 8) = CONCAT11((char)pppuStack_1c8,(char)((uint)pppuStack_1c8 >> 8));
  pppiStack_1e8 = (int ***)0x48b931;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppiStack_1e8 = (int ***)s_LoadInfo___Read_____DEX_DEF_____F_009a702c;
    uStack_1ec = 0x48b947;
    FUN_0044a670();
    pppiStack_1e8 = (int ***)auStack_15c;
    uStack_1ec = 0x48b954;
    FUN_00797b80();
    uStack_1ec = 0x48b963;
    pppiStack_1e8 = (int ***)pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppiStack_1e8 = (int ***)&pppuStack_1c8;
  uStack_1ec = 2;
  *(ushort *)((int)puStack_c + 0x22) = CONCAT11((char)piStack_1a0,(char)((uint)piStack_1a0 >> 8));
  pppuStack_1f0 = (undefined1 ***)0x48b98e;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppuStack_1f0 = (undefined1 ***)s_LoadInfo___Read_____CON_DEF_____F_009a7058;
    uStack_1f4 = 0x48b9a4;
    FUN_0044a670();
    pppuStack_1f0 = (undefined1 ***)auStack_164;
    uStack_1f4 = 0x48b9b1;
    FUN_00797b80();
    uStack_1f4 = 0x48b9c0;
    pppuStack_1f0 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_1f0 = (undefined1 ***)&piStack_1a0;
  uStack_1f4 = 2;
  *(ushort *)(puStack_c + 9) = CONCAT11((char)pppuStack_1d0,(char)((uint)pppuStack_1d0 >> 8));
  pppiStack_1f8 = (int ***)0x48b9eb;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppiStack_1f8 = (int ***)s_LoadInfo___Read_____SPR_DEF_____F_009a7084;
    uStack_1fc = 0x48ba01;
    FUN_0044a670();
    pppiStack_1f8 = (int ***)&piStack_16c;
    uStack_1fc = 0x48ba0e;
    FUN_00797b80();
    uStack_1fc = 0x48ba1d;
    pppiStack_1f8 = (int ***)pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppiStack_1f8 = (int ***)&pppuStack_1d0;
  uStack_1fc = 2;
  *(ushort *)((int)puStack_c + 0x26) =
       CONCAT11((char)pppuStack_1a8,(char)((uint)pppuStack_1a8 >> 8));
  pppiStack_200 = (int ***)0x48ba48;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppiStack_200 = (int ***)s_LoadInfo___Read_____POS_X_____Fa_009a70b0;
    ppuStack_204 = (undefined1 **)0x48ba5e;
    FUN_0044a670();
    pppiStack_200 = (int ***)auStack_174;
    ppuStack_204 = (undefined1 **)0x48ba6b;
    FUN_00797b80();
    ppuStack_204 = (undefined1 **)0x48ba7a;
    pppiStack_200 = (int ***)pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppiStack_200 = (int ***)&pppuStack_1a8;
  ppuStack_204 = (undefined1 **)0x2;
  *(ushort *)(puStack_c + 10) = CONCAT11((char)pppiStack_1d8,(char)((uint)pppiStack_1d8 >> 8));
  pppuStack_208 = (undefined1 ***)0x48baa5;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppuStack_208 = (undefined1 ***)s_LoadInfo___Read_____POS_Y_____Fa_009a70d8;
    uStack_20c = 0x48babb;
    FUN_0044a670();
    pppuStack_208 = (undefined1 ***)apiStack_17c;
    uStack_20c = 0x48bac8;
    FUN_00797b80();
    uStack_20c = 0x48bad7;
    pppuStack_208 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_208 = (undefined1 ***)&piStack_1c4;
  uStack_20c = 2;
  *(ushort *)((int)puStack_c + 0x2a) =
       CONCAT11((char)pppuStack_1b0,(char)((uint)pppuStack_1b0 >> 8));
  pppuStack_210 = (undefined1 ***)0x48bb02;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppuStack_210 = (undefined1 ***)s_LoadInfo___Read_____RETURNPOS_X___009a7100;
    uStack_214 = 0x48bb18;
    FUN_0044a670();
    pppuStack_210 = (undefined1 ***)&uStack_184;
    uStack_214 = 0x48bb25;
    FUN_00797b80();
    uStack_214 = 0x48bb34;
    pppuStack_210 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_210 = (undefined1 ***)&uStack_1dc;
  uStack_214 = 2;
  *(ushort *)(puStack_c + 0xb) = CONCAT11((char)uStack_1cc,(char)((uint)uStack_1cc >> 8));
  pppuStack_218 = (undefined1 ***)0x48bb5f;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppuStack_218 = (undefined1 ***)s_LoadInfo___Read_____RETURNPOS_Y___009a7130;
    uStack_21c = 0x48bb75;
    FUN_0044a670();
    pppuStack_218 = (undefined1 ***)&puStack_18c;
    uStack_21c = 0x48bb82;
    FUN_00797b80();
    uStack_21c = 0x48bb91;
    pppuStack_218 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_218 = (undefined1 ***)&piStack_1c4;
  uStack_21c = 2;
  *(ushort *)((int)puStack_c + 0x2e) = CONCAT11((char)uStack_1e4,(char)((uint)uStack_1e4 >> 8));
  pppuStack_220 = (undefined1 ***)0x48bbbc;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppuStack_220 = (undefined1 ***)s_LoadInfo___Read_____MAPINDEX_____009a7160;
    uStack_224 = 0x48bbd2;
    FUN_0044a670();
    pppuStack_220 = (undefined1 ***)&ppiStack_194;
    uStack_224 = 0x48bbdf;
    FUN_00797b80();
    uStack_224 = 0x48bbee;
    pppuStack_220 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_220 = (undefined1 ***)&uStack_1e4;
  uStack_224 = 2;
  *(ushort *)(puStack_c + 0xc) = CONCAT11((char)uStack_1cc,(char)((uint)uStack_1cc >> 8));
  pppuStack_228 = (undefined1 ***)0x48bc19;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppuStack_228 = (undefined1 ***)s_LoadInfo___Read_____RETURN_MAPIN_009a718c;
    uStack_22c = 0x48bc2f;
    FUN_0044a670();
    pppuStack_228 = (undefined1 ***)(apiStack_17c + -8);
    uStack_22c = 0x48bc3c;
    FUN_00797b80();
    uStack_22c = 0x48bc4b;
    pppuStack_228 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_228 = (undefined1 ***)&uStack_1dc;
  uStack_22c = 2;
  *(ushort *)((int)puStack_c + 0x32) = CONCAT11((char)uStack_1ec,(char)((uint)uStack_1ec >> 8));
  pppuStack_230 = (undefined1 ***)0x48bc76;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppuStack_230 = (undefined1 ***)s_LoadInfo___Read_____STATPOINT____009a71c0;
    uStack_234 = 0x48bc8c;
    FUN_0044a670();
    pppuStack_230 = (undefined1 ***)&ppiStack_1a4;
    uStack_234 = 0x48bc99;
    FUN_00797b80();
    uStack_234 = 0x48bca8;
    pppuStack_230 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_230 = &ppuStack_204;
  uStack_234 = 2;
  *(ushort *)(puStack_c + 0xd) = CONCAT11((char)uStack_1e4,(char)((uint)uStack_1e4 >> 8));
  pppiStack_238 = (int ***)0x48bcd3;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppiStack_238 = (int ***)s_LoadInfo___Read_____SKILLPOINT___009a71ec;
    uStack_23c = 0x48bce9;
    FUN_0044a670();
    pppiStack_238 = (int ***)&puStack_1ac;
    uStack_23c = 0x48bcf6;
    FUN_00797b80();
    uStack_23c = 0x48bd05;
    pppiStack_238 = (int ***)pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppiStack_238 = (int ***)&pppuStack_208;
  uStack_23c = 2;
  *(ushort *)((int)puStack_c + 0x36) = CONCAT11((char)uStack_20c,(char)((uint)uStack_20c >> 8));
  pppuStack_240 = (undefined1 ***)0x48bd30;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppuStack_240 = (undefined1 ***)s_LoadInfo___Read_____LEVEL_____Fa_009a721c;
    uStack_244 = 0x48bd46;
    FUN_0044a670();
    pppuStack_240 = (undefined1 ***)&puStack_1b4;
    uStack_244 = 0x48bd53;
    FUN_00797b80();
    uStack_244 = 0x48bd62;
    pppuStack_240 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_240 = (undefined1 ***)((int)puStack_c + 0x3a);
  uStack_244 = 1;
  *(ushort *)(puStack_c + 0xe) = CONCAT11((char)pppuStack_210,(char)((uint)pppuStack_210 >> 8));
  pppuStack_248 = (undefined1 ***)0x48bd8c;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 1) {
    pppuStack_248 = (undefined1 ***)s_LoadInfo___Read_____PCCLASS_____F_009a7244;
    uStack_24c = 0x48bda2;
    FUN_0044a670();
    pppuStack_248 = (undefined1 ***)&uStack_1bc;
    uStack_24c = 0x48bdaf;
    FUN_00797b80();
    uStack_24c = 0x48bdbe;
    pppuStack_248 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_248 = (undefined1 ***)((int)puStack_c + 0x3b);
  uStack_24c = 1;
  pppuStack_250 = (undefined1 ***)0x48bdd9;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 1) {
    pppuStack_250 = (undefined1 ***)s_LoadInfo___Read_____DIRECTION____009a7270;
    uStack_254 = 0x48bdef;
    FUN_0044a670();
    pppuStack_250 = (undefined1 ***)&piStack_1c4;
    uStack_254 = 0x48bdfc;
    FUN_00797b80();
    uStack_254 = 0x48be0b;
    pppuStack_250 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_250 = (undefined1 ***)(puStack_c + 0xf);
  uStack_254 = 1;
  pppuStack_258 = (undefined1 ***)0x48be26;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 1) {
    pppuStack_258 = (undefined1 ***)s_LoadInfo___Read_____RETURN_DIREC_009a729c;
    uStack_25c = 0x48be3c;
    FUN_0044a670();
    pppuStack_258 = (undefined1 ***)&uStack_1cc;
    uStack_25c = 0x48be49;
    FUN_00797b80();
    uStack_25c = 0x48be58;
    pppuStack_258 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_258 = (undefined1 ***)((int)puStack_c + 0x3d);
  uStack_25c = 1;
  pppuStack_260 = (undefined1 ***)0x48be73;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 1) {
    pppuStack_260 = (undefined1 ***)s_LoadInfo___Read_____SKILL_CLEAR__009a72d0;
    uStack_264 = 0x48be89;
    FUN_0044a670();
    pppuStack_260 = (undefined1 ***)&piStack_1d4;
    uStack_264 = 0x48be96;
    FUN_00797b80();
    uStack_264 = 0x48bea5;
    pppuStack_260 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_260 = (undefined1 ***)((int)puStack_c + 0x3e);
  uStack_264 = 1;
  ppppuStack_268 = (undefined1 ****)0x48bec0;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 1) {
    ppppuStack_268 = (undefined1 ****)s_LoadInfo___Read_____STAT_CLEAR_C_009a7304;
    uStack_26c = 0x48bed6;
    FUN_0044a670();
    ppppuStack_268 = (undefined1 ****)&uStack_1dc;
    uStack_26c = 0x48bee3;
    FUN_00797b80();
    uStack_26c = 0x48bef2;
    ppppuStack_268 = (undefined1 ****)pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  ppppuStack_268 = &pppuStack_230;
  uStack_26c = 2;
  pppiStack_270 = (int ***)0x48bf0e;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppiStack_270 = (int ***)s_LoadInfo___Read_____PK_COUNT_____009a7338;
    uStack_274 = 0x48bf24;
    FUN_0044a670();
    pppiStack_270 = (int ***)&uStack_1e4;
    uStack_274 = 0x48bf31;
    FUN_00797b80();
    uStack_274 = 0x48bf40;
    pppiStack_270 = (int ***)pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppiStack_270 = (int ***)&pppuStack_260;
  uStack_274 = 2;
  *(ushort *)(puStack_c + 0x10) = CONCAT11((char)pppiStack_238,(char)((uint)pppiStack_238 >> 8));
  pppuStack_278 = (undefined1 ***)0x48bf6b;
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 2) {
    pppuStack_278 = (undefined1 ***)s_LoadInfo___Read_____CHAOTICLEVEL_009a7364;
    uStack_27c = 0x48bf81;
    FUN_0044a670();
    pppuStack_278 = (undefined1 ***)&uStack_1ec;
    uStack_27c = 0x48bf8e;
    FUN_00797b80();
    uStack_27c = 0x48bf9d;
    pppuStack_278 = pppuVar1;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  pppuStack_278 = (undefined1 ***)&uStack_20c;
  uStack_27c = 4;
  *(ushort *)((int)puStack_c + 0x42) =
       CONCAT11((char)ppppuStack_268,(char)((uint)ppppuStack_268 >> 8));
  iVar2 = (*(code *)(*pppuVar1)[2])();
  if (iVar2 != 4) {
    FUN_0044a670(s_LoadInfo___Read_____SHIELD_____F_009a7394);
    FUN_00797b80(&uStack_1f4);
    (**(code **)(*DAT_00b5a69c + 8))(pppuVar1);
    return 0;
  }
  uVar3 = FUN_0048b480();
  puStack_c[0x11] = uVar3;
  uVar5 = 4;
  iVar2 = (*(code *)(*pppuVar1)[2])(4,&uStack_20c);
  if (iVar2 != 4) {
    FUN_0044a670(s_LoadInfo___Read_____FLAG_____Fai_009a73c0);
    FUN_00797b80(&uStack_1fc);
    (**(code **)(*DAT_00b5a69c + 8))(pppuVar1);
    return 0;
  }
  uVar3 = FUN_0048b480();
  puStack_c[0x12] = uVar3;
  iVar2 = (*(code *)(*pppuVar1)[2])(4,&uStack_20c);
  if (iVar2 != 4) {
    FUN_0044a670(s_LoadInfo___Read_____PVPPOINT_____009a73e8);
    FUN_00797b80(&ppuStack_204);
    (**(code **)(*DAT_00b5a69c + 8))(pppuVar1);
    return 0;
  }
  uVar3 = FUN_0048b480();
  puStack_c[0x13] = uVar3;
  iVar2 = (*(code *)(*pppuVar1)[2])(2,&uStack_27c);
  if (iVar2 != 2) {
    FUN_0044a670(s_LoadInfo___Read_____WINRECORD____009a7414);
    FUN_00797b80(&uStack_20c);
    (**(code **)(*DAT_00b5a69c + 8))(pppuVar1);
    return 0;
  }
  *(ushort *)(puStack_c + 0x14) = CONCAT11((char)uVar5,(char)((uint)uVar5 >> 8));
  iVar2 = (*(code *)(*pppuVar1)[2])(2,&uStack_27c);
  uVar6 = (undefined2)((uint)uVar5 >> 8);
  if (iVar2 != 2) {
    FUN_0044a670(s_LoadInfo___Read_____LOSERECORD___009a7440);
    FUN_00797b80(&uStack_214);
    (**(code **)(*DAT_00b5a69c + 8))(pppuVar1);
    return 0;
  }
  *(ushort *)((int)puStack_c + 0x52) = CONCAT11((char)uVar5,(char)((uint)uVar5 >> 8));
  iVar2 = (*(code *)(*pppuVar1)[2])(2,&uStack_27c);
  if (iVar2 != 2) {
    FUN_0044a670(s_LoadInfo___Read_____DRAWRECORD___009a7470);
    FUN_00797b80(&uStack_21c);
    (**(code **)(*DAT_00b5a69c + 8))(pppuVar1);
    return 0;
  }
  *(ushort *)(puStack_c + 0x15) = CONCAT11((char)uVar6,(char)((ushort)uVar6 >> 8));
  iVar2 = (*(code *)(*pppuVar1)[2])(4,&uStack_224);
  if (iVar2 != 4) {
    FUN_0044a670(s_LoadInfo___Read_____DWSUPPLYPOIN_009a74a0);
    FUN_00797b80(&uStack_224);
    (**(code **)(*DAT_00b5a69c + 8))(pppuVar1);
    return 0;
  }
  uVar3 = FUN_0048b480();
  puStack_c[0x16] = uVar3;
  if (sVar4 != 0x5b) {
    uStack_224 = uStack_224 & 0xffffff00;
    uVar5 = FUN_0044a580(&uStack_224,s_TotalSize_Size_is_not_equal_with_009a74d0,sVar4,0x5b);
    FUN_00797b80(uVar5);
  }
  (**(code **)(*DAT_00b5a69c + 8))(pppuVar1);
  return 1;
}


// ==== FUN_0048c290 @ 0x0048c290 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048c290(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a7530;
  _DAT_00b5aadc = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048c330 @ 0x0048c330 ====

uint FUN_0048c330(void)

{
  uint in_ECX;
  
  return in_ECX >> 0x18 |
         CONCAT31((int3)in_ECX,(char)(in_ECX >> 8)) << 0x10 | (in_ECX >> 0x10 & 0xff) << 8;
}


// ==== FUN_0048c360 @ 0x0048c360 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048c360(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a7c10;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa80 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa80 = in_ECX;
  return;
}


// ==== FUN_0048c3b0 @ 0x0048c3b0 ====

uint FUN_0048c3b0(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined2 extraout_var_12;
  undefined2 extraout_var_13;
  undefined2 extraout_var_14;
  undefined2 extraout_var_15;
  uint *puStack_1d4;
  undefined4 uStack_1d0;
  uint *puStack_1cc;
  undefined4 uStack_1c8;
  uint *puStack_1c4;
  undefined4 uStack_1c0;
  uint *puStack_1bc;
  undefined4 uStack_1b8;
  uint *puStack_1b4;
  undefined4 uStack_1b0;
  uint *puStack_1ac;
  uint *puStack_1a8;
  uint *puStack_1a4;
  undefined *puStack_1a0;
  uint *puStack_19c;
  undefined4 uStack_198;
  uint *puStack_194;
  undefined1 *puStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_184;
  undefined1 auStack_17c [4];
  uint uStack_178;
  undefined1 auStack_174 [4];
  undefined4 uStack_170;
  undefined1 auStack_16c [8];
  uint uStack_164;
  undefined4 uStack_160;
  undefined1 auStack_15c [8];
  undefined1 auStack_154 [4];
  uint uStack_150;
  uint uStack_14c;
  uint uStack_148;
  undefined1 auStack_144 [4];
  uint uStack_140;
  uint auStack_13c [2];
  undefined1 auStack_134 [4];
  uint uStack_130;
  undefined1 auStack_12c [4];
  uint auStack_128 [3];
  undefined1 auStack_11c [8];
  uint auStack_114 [4];
  undefined1 auStack_104 [256];
  uint *puStack_4;
  
  uStack_184 = param_1;
  puVar1 = (uint *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (puVar1 == (uint *)0x0) {
    puStack_190 = auStack_104;
    uStack_18c = &DAT_009a7c08;
    puStack_194 = (uint *)0x48c3e4;
    FUN_0044a580();
    puStack_194 = (uint *)auStack_104;
    uStack_198 = 0x48c3f1;
    uVar2 = FUN_00797b80();
    return uVar2 & 0xffff0000;
  }
  uStack_18c = (undefined *)0x2;
  puStack_190 = (undefined1 *)0x0;
  puStack_194 = (uint *)0x48c40d;
  (**(code **)(*puVar1 + 4))();
  uVar2 = *puStack_4;
  uStack_148 = CONCAT31((int3)uVar2,(char)(uVar2 >> 8)) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
  puStack_194 = &uStack_148;
  uStack_198 = 4;
  puStack_19c = (uint *)0x48c444;
  iVar3 = (**(code **)(*puVar1 + 8))();
  if (iVar3 == 4) {
    puStack_19c = (uint *)(auStack_17c + -0xc);
    puStack_1a0 = (undefined *)0x4;
    puStack_1a4 = (uint *)0x48c4bb;
    iVar3 = (**(code **)(*puVar1 + 8))();
    if (iVar3 == 4) {
      uVar2 = puStack_4[2];
      uStack_130 = CONCAT31((int3)uVar2,(char)(uVar2 >> 8)) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                   uVar2 >> 0x18;
      puStack_19c = &uStack_130;
      puStack_1a0 = (undefined *)0x4;
      puStack_1a4 = (uint *)0x48c4f8;
      iVar3 = (**(code **)(*puVar1 + 8))();
      if (iVar3 == 4) {
        puStack_19c = (uint *)(auStack_17c + -4);
        puStack_1a0 = (undefined *)0x4;
        puStack_1a4 = (uint *)0x48c538;
        iVar3 = (**(code **)(*puVar1 + 8))();
        if (iVar3 != 4) {
          puStack_1a4 = (uint *)s_SaveInfo___Write_____MONEY_____F_009a75dc;
          puStack_1a8 = (uint *)0x48c54e;
          FUN_0044a670();
          puStack_1a4 = (uint *)auStack_11c;
          puStack_1a8 = (uint *)0x48c55b;
          FUN_00797b80();
          puStack_1a8 = (uint *)0x48c56a;
          puStack_1a4 = puVar1;
          uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
          return uVar2 & 0xffff0000;
        }
        puStack_1a4 = (uint *)0x48c580;
        uStack_150 = FUN_0048c330();
        puStack_1a4 = &uStack_150;
        puStack_1a8 = (uint *)0x4;
        puStack_1ac = (uint *)0x48c592;
        iVar3 = (**(code **)(*puVar1 + 8))();
        if (iVar3 == 4) {
          puStack_19c = (uint *)0x48c5c5;
          uStack_178 = FUN_0048c330();
          puStack_19c = &uStack_178;
          puStack_1a0 = (undefined *)0x4;
          puStack_1a4 = (uint *)0x48c5d7;
          iVar3 = (**(code **)(*puVar1 + 8))();
          if (iVar3 != 4) {
            puStack_1a4 = (uint *)s_SaveInfo___Write_____STORAGE_MON_009a7638;
            puStack_1a8 = (uint *)0x48c5ed;
            FUN_0044a670();
            puStack_1a4 = (uint *)auStack_11c;
            puStack_1a8 = (uint *)0x48c5fa;
            FUN_00797b80();
            puStack_1a8 = (uint *)0x48c609;
            puStack_1a4 = puVar1;
            uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
            return uVar2 & 0xffff0000;
          }
          puStack_1a4 = (uint *)0x48c61f;
          auStack_128[0] = FUN_0048c330();
          puStack_1a4 = auStack_128;
          puStack_1a8 = (uint *)0x4;
          puStack_1ac = (uint *)0x48c631;
          iVar3 = (**(code **)(*puVar1 + 8))();
          if (iVar3 == 4) {
            puStack_19c = (uint *)0x48c664;
            uStack_170 = FUN_0048c330();
            puStack_19c = &uStack_170;
            puStack_1a0 = (undefined *)0x4;
            puStack_1a4 = (uint *)0x48c676;
            iVar3 = (**(code **)(*puVar1 + 8))();
            if (iVar3 != 4) {
              puStack_1a4 = (uint *)s_SaveInfo___Write_____MP_____Fail_009a7694;
              puStack_1a8 = (uint *)0x48c68c;
              FUN_0044a670();
              puStack_1a4 = (uint *)auStack_11c;
              puStack_1a8 = (uint *)0x48c699;
              FUN_00797b80();
              puStack_1a8 = (uint *)0x48c6a8;
              puStack_1a4 = puVar1;
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
              return uVar2 & 0xffff0000;
            }
            uStack_148 = CONCAT22(extraout_var_00,
                                  CONCAT11((char)puStack_4[8],(char)(puStack_4[8] >> 8)));
            puStack_1a4 = &uStack_148;
            puStack_1a8 = (uint *)0x2;
            puStack_1ac = (uint *)0x48c6d2;
            iVar3 = (**(code **)(*puVar1 + 8))();
            if (iVar3 != 2) {
              puStack_1ac = (uint *)s_SaveInfo___Write_____EXP_____Fai_009a76bc;
              uStack_1b0 = 0x48c6e8;
              FUN_0044a670();
              puStack_1ac = auStack_128 + 1;
              uStack_1b0 = 0x48c6f5;
              FUN_00797b80();
              uStack_1b0 = 0x48c704;
              puStack_1ac = puVar1;
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
              return uVar2 & 0xffff0000;
            }
            uStack_178 = CONCAT22(extraout_var_01,
                                  CONCAT11((char)*(undefined2 *)((int)puStack_4 + 0x22),
                                           (char)((ushort)*(undefined2 *)((int)puStack_4 + 0x22) >>
                                                 8)));
            puStack_1ac = &uStack_178;
            uStack_1b0 = 2;
            puStack_1b4 = (uint *)0x48c72e;
            iVar3 = (**(code **)(*puVar1 + 8))();
            if (iVar3 != 2) {
              puStack_1b4 = (uint *)s_SaveInfo___Write_____DEX_DEF_____009a76e4;
              uStack_1b8 = 0x48c744;
              FUN_0044a670();
              puStack_1b4 = (uint *)auStack_12c;
              uStack_1b8 = 0x48c751;
              FUN_00797b80();
              uStack_1b8 = 0x48c760;
              puStack_1b4 = puVar1;
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
              return uVar2 & 0xffff0000;
            }
            uStack_140 = CONCAT22(extraout_var_02,
                                  CONCAT11((char)puStack_4[9],(char)(puStack_4[9] >> 8)));
            puStack_1b4 = &uStack_140;
            uStack_1b8 = 2;
            puStack_1bc = (uint *)0x48c78a;
            iVar3 = (**(code **)(*puVar1 + 8))();
            if (iVar3 != 2) {
              puStack_1bc = (uint *)s_SaveInfo___Write_____CON_DEF_____009a7710;
              uStack_1c0 = 0x48c7a0;
              FUN_0044a670();
              puStack_1bc = (uint *)auStack_134;
              uStack_1c0 = 0x48c7ad;
              FUN_00797b80();
              uStack_1c0 = 0x48c7bc;
              puStack_1bc = puVar1;
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
              return uVar2 & 0xffff0000;
            }
            puStack_1bc = (uint *)(auStack_17c + -4);
            uStack_1c0 = 2;
            puStack_1c4 = (uint *)0x48c7e6;
            iVar3 = (**(code **)(*puVar1 + 8))();
            if (iVar3 != 2) {
              puStack_1c4 = (uint *)s_SaveInfo___Write_____SPR_DEF_____009a773c;
              uStack_1c8 = 0x48c7fc;
              FUN_0044a670();
              puStack_1c4 = auStack_13c;
              uStack_1c8 = 0x48c809;
              FUN_00797b80();
              uStack_1c8 = 0x48c818;
              puStack_1c4 = puVar1;
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
              return uVar2 & 0xffff0000;
            }
            uStack_160 = CONCAT22(extraout_var_03,
                                  CONCAT11((char)puStack_4[10],(char)(puStack_4[10] >> 8)));
            puStack_1c4 = &uStack_160;
            uStack_1c8 = 2;
            puStack_1cc = (uint *)0x48c842;
            iVar3 = (**(code **)(*puVar1 + 8))();
            if (iVar3 != 2) {
              puStack_1cc = (uint *)s_SaveInfo___Write_____POS_X_____F_009a7768;
              uStack_1d0 = 0x48c858;
              FUN_0044a670();
              puStack_1cc = (uint *)auStack_144;
              uStack_1d0 = 0x48c865;
              FUN_00797b80();
              uStack_1d0 = 0x48c874;
              puStack_1cc = puVar1;
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
              return uVar2 & 0xffff0000;
            }
            puStack_1cc = (uint *)(auStack_17c + -0xc);
            uStack_1d0 = 2;
            puStack_1d4 = (uint *)0x48c89e;
            iVar3 = (**(code **)(*puVar1 + 8))();
            if (iVar3 != 2) {
              puStack_1d4 = (uint *)s_SaveInfo___Write_____POS_Y_____F_009a7794;
              FUN_0044a670();
              puStack_1d4 = &uStack_14c;
              FUN_00797b80();
              puStack_1d4 = puVar1;
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
              return uVar2 & 0xffff0000;
            }
            uStack_150 = CONCAT22(extraout_var_04,
                                  CONCAT11((char)puStack_4[0xb],(char)(puStack_4[0xb] >> 8)));
            puStack_1d4 = &uStack_150;
            iVar3 = (**(code **)(*puVar1 + 8))(2);
            if (iVar3 != 2) {
              FUN_0044a670(s_SaveInfo___Write_____RETURN_POS__009a77c0);
              FUN_00797b80(auStack_154);
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(puVar1);
              return uVar2 & 0xffff0000;
            }
            uStack_1d0 = CONCAT22(extraout_var_05,
                                  CONCAT11((char)*(undefined2 *)((int)puStack_4 + 0x2e),
                                           (char)((ushort)*(undefined2 *)((int)puStack_4 + 0x2e) >>
                                                 8)));
            iVar3 = (**(code **)(*puVar1 + 8))(2,&uStack_1d0);
            if (iVar3 != 2) {
              FUN_0044a670(s_SaveInfo___Write_____RETURN_POS__009a77f4);
              FUN_00797b80(auStack_15c);
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(puVar1);
              return uVar2 & 0xffff0000;
            }
            puStack_1d4 = (uint *)CONCAT22(extraout_var_06,
                                           CONCAT11((char)puStack_4[0xc],(char)(puStack_4[0xc] >> 8)
                                                   ));
            iVar3 = (**(code **)(*puVar1 + 8))(2,&puStack_1d4);
            if (iVar3 != 2) {
              FUN_0044a670(s_SaveInfo___Write_____MAP_INDEX___009a7828);
              FUN_00797b80(&uStack_164);
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(puVar1);
              return uVar2 & 0xffff0000;
            }
            puStack_1d4 = (uint *)CONCAT22(extraout_var_07,
                                           CONCAT11((char)*(undefined2 *)((int)puStack_4 + 0x32),
                                                    (char)((ushort)*(undefined2 *)
                                                                    ((int)puStack_4 + 0x32) >> 8)));
            iVar3 = (**(code **)(*puVar1 + 8))(2,&puStack_1d4);
            if (iVar3 != 2) {
              FUN_0044a670(s_SaveInfo___Write_____RETURN_MAP__009a7858);
              FUN_00797b80(auStack_16c);
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(puVar1);
              return uVar2 & 0xffff0000;
            }
            puStack_1d4 = (uint *)CONCAT22(extraout_var_08,
                                           CONCAT11((char)puStack_4[0xd],(char)(puStack_4[0xd] >> 8)
                                                   ));
            iVar3 = (**(code **)(*puVar1 + 8))(2,&puStack_1d4);
            if (iVar3 != 2) {
              FUN_0044a670(s_SaveInfo___Write_____STATPOINT___009a7890);
              FUN_00797b80(auStack_174);
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(puVar1);
              return uVar2 & 0xffff0000;
            }
            puStack_1d4 = (uint *)CONCAT22(extraout_var_09,
                                           CONCAT11((char)*(undefined2 *)((int)puStack_4 + 0x36),
                                                    (char)((ushort)*(undefined2 *)
                                                                    ((int)puStack_4 + 0x36) >> 8)));
            iVar3 = (**(code **)(*puVar1 + 8))(2,&puStack_1d4);
            if (iVar3 != 2) {
              FUN_0044a670(s_SaveInfo___Write_____SKILLPOINT___009a78c0);
              FUN_00797b80(auStack_17c);
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(puVar1);
              return uVar2 & 0xffff0000;
            }
            puStack_1d4 = (uint *)CONCAT22(extraout_var_10,
                                           CONCAT11((char)puStack_4[0xe],(char)(puStack_4[0xe] >> 8)
                                                   ));
            iVar3 = (**(code **)(*puVar1 + 8))(2,&puStack_1d4);
            if (iVar3 != 2) {
              FUN_0044a670(s_SaveInfo___Write_____LEVEL_____F_009a78f0);
              FUN_00797b80(&uStack_184);
              uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(puVar1);
              return uVar2 & 0xffff0000;
            }
            iVar3 = (**(code **)(*puVar1 + 8))(1,(int)puStack_4 + 0x3a);
            if (iVar3 == 1) {
              puStack_19c = (uint *)((int)puStack_4 + 0x3b);
              puStack_1a0 = (undefined *)0x1;
              puStack_1a4 = (uint *)0x48cbad;
              iVar3 = (**(code **)(*puVar1 + 8))();
              if (iVar3 != 1) {
                puStack_1a4 = (uint *)s_SaveInfo___Write_____DIRECTION___009a7948;
                puStack_1a8 = (uint *)0x48cbc3;
                FUN_0044a670();
                puStack_1a4 = (uint *)auStack_11c;
                puStack_1a8 = (uint *)0x48cbd0;
                FUN_00797b80();
                puStack_1a8 = (uint *)0x48cbdf;
                puStack_1a4 = puVar1;
                uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
                return uVar2 & 0xffff0000;
              }
              puStack_1a4 = puStack_4 + 0xf;
              puStack_1a8 = (uint *)0x1;
              puStack_1ac = (uint *)0x48cbfa;
              iVar3 = (**(code **)(*puVar1 + 8))();
              if (iVar3 == 1) {
                puStack_19c = (uint *)((int)puStack_4 + 0x3d);
                puStack_1a0 = (undefined *)0x1;
                puStack_1a4 = (uint *)0x48cc32;
                iVar3 = (**(code **)(*puVar1 + 8))();
                if (iVar3 != 1) {
                  puStack_1a4 = (uint *)s_SaveInfo___Write_____SKILL_CLEAR_009a79b0;
                  puStack_1a8 = (uint *)0x48cc48;
                  FUN_0044a670();
                  puStack_1a4 = (uint *)auStack_11c;
                  puStack_1a8 = (uint *)0x48cc55;
                  FUN_00797b80();
                  puStack_1a8 = (uint *)0x48cc64;
                  puStack_1a4 = puVar1;
                  uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
                  return uVar2 & 0xffff0000;
                }
                puStack_1a4 = (uint *)((int)puStack_4 + 0x3e);
                puStack_1a8 = (uint *)0x1;
                puStack_1ac = (uint *)0x48cc7f;
                iVar3 = (**(code **)(*puVar1 + 8))();
                if (iVar3 == 1) {
                  uStack_164 = CONCAT22(extraout_var_11,
                                        CONCAT11((char)puStack_4[0x10],(char)(puStack_4[0x10] >> 8))
                                       );
                  puStack_19c = &uStack_164;
                  puStack_1a0 = (undefined *)0x2;
                  puStack_1a4 = (uint *)0x48ccc6;
                  iVar3 = (**(code **)(*puVar1 + 8))();
                  if (iVar3 != 2) {
                    puStack_1a4 = (uint *)s_SaveInfo___Write_____PK_COUNT____009a7a20;
                    puStack_1a8 = (uint *)0x48ccdc;
                    FUN_0044a670();
                    puStack_1a4 = (uint *)auStack_11c;
                    puStack_1a8 = (uint *)0x48cce9;
                    FUN_00797b80();
                    puStack_1a8 = (uint *)0x48ccf8;
                    puStack_1a4 = puVar1;
                    uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
                    return uVar2 & 0xffff0000;
                  }
                  uStack_164 = CONCAT22(extraout_var_12,
                                        CONCAT11((char)*(undefined2 *)((int)puStack_4 + 0x42),
                                                 (char)((ushort)*(undefined2 *)
                                                                 ((int)puStack_4 + 0x42) >> 8)));
                  puStack_1a4 = &uStack_164;
                  puStack_1a8 = (uint *)0x2;
                  puStack_1ac = (uint *)0x48cd22;
                  iVar3 = (**(code **)(*puVar1 + 8))();
                  if (iVar3 != 2) {
                    puStack_1ac = (uint *)s_SaveInfo___Write_____CHAOTIC_LEV_009a7a50;
                    uStack_1b0 = 0x48cd38;
                    FUN_0044a670();
                    puStack_1ac = auStack_128 + 1;
                    uStack_1b0 = 0x48cd45;
                    FUN_00797b80();
                    uStack_1b0 = 0x48cd54;
                    puStack_1ac = puVar1;
                    uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
                    return uVar2 & 0xffff0000;
                  }
                  puStack_1ac = (uint *)0x48cd6a;
                  uStack_164 = FUN_0048c330();
                  puStack_1ac = &uStack_164;
                  uStack_1b0 = 4;
                  puStack_1b4 = (uint *)0x48cd7c;
                  iVar3 = (**(code **)(*puVar1 + 8))();
                  if (iVar3 == 4) {
                    puStack_19c = (uint *)0x48cdaf;
                    uStack_14c = FUN_0048c330();
                    puStack_19c = &uStack_14c;
                    puStack_1a0 = (undefined *)0x4;
                    puStack_1a4 = (uint *)0x48cdc1;
                    iVar3 = (**(code **)(*puVar1 + 8))();
                    if (iVar3 != 4) {
                      puStack_1a4 = (uint *)s_SaveInfo___Write_____FLAG_____Fa_009a7ab0;
                      puStack_1a8 = (uint *)0x48cdd7;
                      FUN_0044a670();
                      puStack_1a4 = (uint *)auStack_11c;
                      puStack_1a8 = (uint *)0x48cde4;
                      FUN_00797b80();
                      puStack_1a8 = (uint *)0x48cdf3;
                      puStack_1a4 = puVar1;
                      uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
                      return uVar2 & 0xffff0000;
                    }
                    puStack_1a4 = (uint *)0x48ce09;
                    uStack_14c = FUN_0048c330();
                    puStack_1a4 = &uStack_14c;
                    puStack_1a8 = (uint *)0x4;
                    puStack_1ac = (uint *)0x48ce1b;
                    iVar3 = (**(code **)(*puVar1 + 8))();
                    if (iVar3 == 4) {
                      auStack_13c[0] =
                           CONCAT22(extraout_var_13,
                                    CONCAT11((char)puStack_4[0x14],(char)(puStack_4[0x14] >> 8)));
                      puStack_19c = auStack_13c;
                      puStack_1a0 = (undefined *)0x2;
                      puStack_1a4 = (uint *)0x48ce62;
                      iVar3 = (**(code **)(*puVar1 + 8))();
                      if (iVar3 != 2) {
                        puStack_1a4 = (uint *)s_SaveInfo___Write_____WINRECORD___009a7b0c;
                        puStack_1a8 = (uint *)0x48ce78;
                        FUN_0044a670();
                        puStack_1a4 = (uint *)auStack_11c;
                        puStack_1a8 = (uint *)0x48ce85;
                        FUN_00797b80();
                        puStack_1a8 = (uint *)0x48ce94;
                        puStack_1a4 = puVar1;
                        uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
                        return uVar2 & 0xffff0000;
                      }
                      auStack_13c[0] =
                           CONCAT22(extraout_var_14,
                                    CONCAT11((char)*(undefined2 *)((int)puStack_4 + 0x52),
                                             (char)((ushort)*(undefined2 *)((int)puStack_4 + 0x52)
                                                   >> 8)));
                      puStack_1a4 = auStack_13c;
                      puStack_1a8 = (uint *)0x2;
                      puStack_1ac = (uint *)0x48cebe;
                      iVar3 = (**(code **)(*puVar1 + 8))();
                      if (iVar3 != 2) {
                        puStack_1ac = (uint *)s_SaveInfo___Write_____LOSERECORD___009a7b3c;
                        uStack_1b0 = 0x48ced4;
                        FUN_0044a670();
                        puStack_1ac = auStack_128 + 1;
                        uStack_1b0 = 0x48cee1;
                        FUN_00797b80();
                        uStack_1b0 = 0x48cef0;
                        puStack_1ac = puVar1;
                        uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
                        return uVar2 & 0xffff0000;
                      }
                      auStack_13c[0] =
                           CONCAT22(extraout_var_15,
                                    CONCAT11((char)puStack_4[0x15],(char)(puStack_4[0x15] >> 8)));
                      puStack_1ac = auStack_13c;
                      uStack_1b0 = 2;
                      puStack_1b4 = (uint *)0x48cf1a;
                      iVar3 = (**(code **)(*puVar1 + 8))();
                      if (iVar3 != 2) {
                        puStack_1b4 = (uint *)s_SaveInfo___Write_____DRAWRECORD___009a7b6c;
                        uStack_1b8 = 0x48cf30;
                        FUN_0044a670();
                        puStack_1b4 = (uint *)auStack_12c;
                        uStack_1b8 = 0x48cf3d;
                        FUN_00797b80();
                        uStack_1b8 = 0x48cf4c;
                        puStack_1b4 = puVar1;
                        uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
                        return uVar2 & 0xffff0000;
                      }
                      puStack_1b4 = (uint *)0x48cf62;
                      auStack_13c[0] = FUN_0048c330();
                      puStack_1b4 = auStack_13c;
                      uStack_1b8 = 4;
                      puStack_1bc = (uint *)0x48cf74;
                      iVar3 = (**(code **)(*puVar1 + 8))();
                      if (iVar3 == 4) {
                        puStack_19c = (uint *)0x0;
                        puStack_1a0 = (undefined *)0x0;
                        puStack_1a4 = (uint *)0x48cfaa;
                        (**(code **)(*puVar1 + 4))();
                        puStack_1a4 = auStack_128 + 1;
                        auStack_128[1] = 0x5b00;
                        puStack_1a8 = (uint *)0x2;
                        puStack_1ac = (uint *)0x48cfc3;
                        iVar3 = (**(code **)(*puVar1 + 8))();
                        if (iVar3 == 2) {
                          puStack_1a0 = (undefined *)0x48cffa;
                          puStack_19c = puVar1;
                          (**(code **)(*DAT_00b5a69c + 0x10))();
                          return CONCAT22(extraout_var,0x5b);
                        }
                        puStack_19c = (uint *)s_SaveInfo___Write_____RETURN_DIRE_009a7bd0;
                        puStack_1a0 = (undefined *)0x48cfd9;
                        FUN_0044a670();
                        puStack_19c = auStack_114;
                        puStack_1a0 = (undefined *)0x48cfe6;
                        FUN_00797b80();
                      }
                      else {
                        puStack_19c = (uint *)s_SaveInfo___Write_____DWSUPPLYPOI_009a7b9c;
                        puStack_1a0 = (undefined *)0x48cf8a;
                        FUN_0044a670();
                        puStack_19c = auStack_114;
                        puStack_1a0 = (undefined *)0x48cf97;
                        FUN_00797b80();
                      }
                    }
                    else {
                      puStack_19c = (uint *)s_SaveInfo___Write_____PVPPOINT____009a7adc;
                      puStack_1a0 = (undefined *)0x48ce31;
                      FUN_0044a670();
                      puStack_19c = auStack_114;
                      puStack_1a0 = (undefined *)0x48ce3e;
                      FUN_00797b80();
                    }
                  }
                  else {
                    puStack_19c = (uint *)s_SaveInfo___Write_____SHIELD_____F_009a7a84;
                    puStack_1a0 = (undefined *)0x48cd92;
                    FUN_0044a670();
                    puStack_19c = auStack_114;
                    puStack_1a0 = (undefined *)0x48cd9f;
                    FUN_00797b80();
                  }
                }
                else {
                  puStack_19c = (uint *)s_SaveInfo___Write_____STAT_CLEAR__009a79e8;
                  puStack_1a0 = (undefined *)0x48cc95;
                  FUN_0044a670();
                  puStack_19c = auStack_114;
                  puStack_1a0 = (undefined *)0x48cca2;
                  FUN_00797b80();
                }
              }
              else {
                puStack_19c = (uint *)s_SaveInfo___Write_____RETURN_DIRE_009a7978;
                puStack_1a0 = (undefined *)0x48cc10;
                FUN_0044a670();
                puStack_19c = auStack_114;
                puStack_1a0 = (undefined *)0x48cc1d;
                FUN_00797b80();
              }
            }
            else {
              puStack_19c = (uint *)s_SaveInfo___Write_____PCCLASS_____009a791c;
              puStack_1a0 = (undefined *)0x48cb8b;
              FUN_0044a670();
              puStack_19c = auStack_114;
              puStack_1a0 = (undefined *)0x48cb98;
              FUN_00797b80();
            }
          }
          else {
            puStack_19c = (uint *)s_SaveInfo___Write_____HP_____Fail_009a766c;
            puStack_1a0 = (undefined *)0x48c647;
            FUN_0044a670();
            puStack_19c = auStack_114;
            puStack_1a0 = (undefined *)0x48c654;
            FUN_00797b80();
          }
        }
        else {
          puStack_19c = (uint *)s_SaveInfo___Write_____STORE_SIZE___009a7608;
          puStack_1a0 = (undefined *)0x48c5a8;
          FUN_0044a670();
          puStack_19c = auStack_114;
          puStack_1a0 = (undefined *)0x48c5b5;
          FUN_00797b80();
        }
        goto LAB_0048c470;
      }
      puStack_19c = (uint *)s_SaveInfo___Write_____EXP_____Fai_009a75b4;
    }
    else {
      puStack_19c = (uint *)s_SaveInfo___Write_____PEERAGE_____009a7588;
    }
  }
  else {
    puStack_19c = (uint *)s_SaveInfo___Write_____ADV_____Fai_009a7560;
  }
  puStack_1a4 = auStack_114;
  puStack_1a0 = &DAT_009a7c08;
  puStack_1a8 = (uint *)0x48c460;
  FUN_0044a580();
  puStack_1a8 = auStack_114;
  puStack_1ac = (uint *)0x48c46d;
  FUN_00797b80();
LAB_0048c470:
  puStack_1a0 = (undefined *)0x48c47c;
  puStack_19c = puVar1;
  uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
  return uVar2 & 0xffff0000;
}


// ==== FUN_0048d010 @ 0x0048d010 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048d010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a7c10;
  _DAT_00b5aa80 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048d0a0 @ 0x0048d0a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048d0a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a80e0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aad8 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aad8 = in_ECX;
  return;
}


// ==== FUN_0048d0f0 @ 0x0048d0f0 ====

undefined4 FUN_0048d0f0(uint *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined2 *puVar7;
  undefined1 *puVar8;
  uint unaff_ESI;
  int *piVar9;
  int *piVar10;
  undefined1 *puVar11;
  char *pcVar12;
  uint uVar13;
  int *piVar14;
  byte bStack_83d;
  uint uVar15;
  undefined1 auStack_82a [10];
  int aiStack_820 [3];
  int *piStack_814;
  uint uStack_810;
  undefined1 auStack_80c [4];
  undefined1 auStack_808 [4];
  undefined1 auStack_804 [208];
  undefined1 auStack_734 [20];
  undefined1 auStack_720 [4];
  undefined1 auStack_71c [4];
  undefined1 auStack_718 [4];
  undefined1 auStack_714 [224];
  undefined1 auStack_634 [256];
  undefined1 auStack_534 [248];
  undefined1 auStack_43c [260];
  undefined1 auStack_338 [256];
  undefined1 auStack_238 [260];
  undefined1 auStack_134 [308];
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  piVar14 = DAT_00b5aa1c;
  piStack_814 = piVar2;
  if (piVar2 == (int *)0x0) {
    uVar3 = (**(code **)(*param_1 + 0x70))();
    auStack_804[0] = 0;
    iVar4 = *piVar14;
    uVar3 = FUN_0044a580(auStack_804,s_UserName____s__LoadSuit___pReade_009a7c1c,uVar3);
    (**(code **)(iVar4 + 4))(uVar3);
    FUN_0044a580(auStack_808,&DAT_009a80d8,s_LoadSuit___pReader_is_NULL_009a7c48);
    FUN_00797b80(auStack_808);
    return 0;
  }
  uStack_810 = param_1[9];
  if (uStack_810 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x70))();
    auStack_804[0] = 0;
    iVar4 = *piVar14;
    uVar3 = FUN_0044a580(auStack_804,s_UserName____s__LoadSuit___pSuit_i_009a7c64,uVar3);
    (**(code **)(iVar4 + 4))(uVar3);
    FUN_0044a580(auStack_808,&DAT_009a80d8,s_LoadSuit___pSuit_is_NULL_009a7c90);
    FUN_00797b80(auStack_808);
    (**(code **)(*DAT_00b5a69c + 8))(piVar2);
    return 0;
  }
  piVar14 = aiStack_820;
  uVar13 = 0;
  iVar4 = (**(code **)(*piVar2 + 8))();
  piVar9 = DAT_00b5aa1c;
  if (iVar4 == 2) {
    uVar5 = (uint)CONCAT11(auStack_82a[2],auStack_82a[3]);
    if (uVar5 <= *param_1) {
      uVar15 = 2;
      if (uVar5 != 2) {
        do {
          iVar4 = (**(code **)(*piVar2 + 8))(1,auStack_82a + -0xb);
          piVar9 = DAT_00b5aa1c;
          if (iVar4 != 1) {
            uVar3 = (**(code **)(*param_1 + 0x70))();
            auStack_714[0] = 0;
            iVar4 = *piVar9;
            uVar3 = FUN_0044a580(auStack_714,s_UserName____s__LoadSuit___pReade_009a7d7c,uVar3);
            (**(code **)(iVar4 + 4))(uVar3);
            FUN_0044a670(s_LoadSuit___pReader_>READ__size___009a7db4);
            FUN_00797b80(auStack_718);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          bStack_83d = (byte)((uint)param_1 >> 0x18);
          if (bStack_83d < 3) {
            uVar3 = (**(code **)(*param_1 + 0x70))();
            auStack_714[0] = 0;
            iVar4 = *piVar9;
            uVar3 = FUN_0044a580(auStack_714,s_UserName____s__LoadSuit___size_<_009a7ddc,uVar3);
            (**(code **)(iVar4 + 4))(uVar3);
            FUN_0044a670(s_LoadSuit___size_<__2_009a7e04);
            FUN_00797b80(auStack_718);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          puVar11 = auStack_82a + -10;
          iVar4 = (**(code **)(*piVar2 + 8))(1);
          piVar9 = DAT_00b5aa1c;
          if (iVar4 != 1) {
            uVar3 = (**(code **)(*param_1 + 0x70))();
            auStack_71c[0] = 0;
            iVar4 = *piVar9;
            uVar3 = FUN_0044a580(auStack_71c,s_UserName____s__LoadSuit___pReade_009a7e1c,uVar3);
            (**(code **)(iVar4 + 4))(uVar3);
            FUN_0044a670(s_LoadSuit___pReader_>READ__positi_009a7e58);
            FUN_00797b80(auStack_720);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          uVar5 = uVar13 >> 0x18;
          (**(code **)(*piVar2 + 4))(1,0);
          piVar9 = (int *)0x0;
          piVar6 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
          cVar1 = (**(code **)(*piVar6 + 0xc))(auStack_82a + -10);
          if (cVar1 == '\0') {
            piVar10 = DAT_00b5aa1c;
            uVar3 = (**(code **)(*param_1 + 0x70))();
            uVar15 = uVar15 & 0xffffff00;
            iVar4 = *piVar10;
            uVar3 = FUN_0044a580(auStack_82a + -6,s_UserName____s__LoadSuit___Item_O_009a7e84,uVar3)
            ;
            (**(code **)(iVar4 + 4))(uVar3);
            auStack_634[0] = 0;
            uVar3 = FUN_0044a580(auStack_634,s_OnSuit___Item_Open_Fail_009a7eb0);
            FUN_00797b80(uVar3);
LAB_0048d5e1:
            (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar6);
          }
          else {
            cVar1 = (**(code **)(*DAT_00b5a734 + 0x38))(piVar6);
            if (cVar1 == '\0') {
              puVar7 = (undefined2 *)(**(code **)(*piVar6 + 0x14))();
              piVar2 = DAT_00b5aa1c;
              uVar3 = (**(code **)(*param_1 + 0x70))();
              auStack_134[0] = 0;
              iVar4 = *piVar2;
              uVar3 = FUN_0044a580(auStack_134,s__ITEM__InvalidItem___index__u__U_009a7ed0,*puVar7,
                                   uVar3,*(undefined1 *)((int)puVar7 + 0x21),puVar7[6],
                                   *(undefined1 *)((int)puVar7 + 0x1f),*(undefined1 *)(puVar7 + 0xf)
                                   ,puVar7[7],*(undefined1 *)(puVar7 + 8),puVar7[9],
                                   *(undefined1 *)(puVar7 + 10),puVar7[0xb],
                                   *(undefined1 *)(puVar7 + 0xc),puVar7[0xd],
                                   *(undefined1 *)(puVar7 + 0xe),puVar7[2],puVar7[3],puVar7[4],
                                   puVar7[5]);
              (**(code **)(iVar4 + 0xc))(uVar3);
              (**(code **)(*DAT_00b5a734 + 0x3c))(piVar6);
              piVar9 = DAT_00b5aa1c;
              uVar3 = (**(code **)(*param_1 + 0x70))();
              auStack_43c[0] = 0;
              iVar4 = *piVar9;
              uVar3 = FUN_0044a580(auStack_43c,s__ITEM__RevisedItem___index__u__U_009a7f78,*puVar7,
                                   uVar3,*(undefined1 *)((int)puVar7 + 0x21),puVar7[6],
                                   *(undefined1 *)((int)puVar7 + 0x1f),*(undefined1 *)(puVar7 + 0xf)
                                   ,puVar7[7],*(undefined1 *)(puVar7 + 8),puVar7[9],
                                   *(undefined1 *)(puVar7 + 10),puVar7[0xb],
                                   *(undefined1 *)(puVar7 + 0xc),puVar7[0xd],
                                   *(undefined1 *)(puVar7 + 0xe),puVar7[2],puVar7[3],puVar7[4],
                                   puVar7[5]);
              piVar2 = piVar14;
              (**(code **)(iVar4 + 0xc))(uVar3);
              piVar14 = piVar2;
            }
            if ((char)puVar11 == -1) {
              cVar1 = (**(code **)(*(int *)param_1[7] + 0x14))();
              if (cVar1 == '\0') {
                piVar10 = DAT_00b5aa1c;
                uVar3 = (**(code **)(*param_1 + 0x70))();
                auStack_238[0] = 0;
                iVar4 = *piVar10;
                uVar3 = FUN_0044a580(auStack_238,s_UserName____s__LoadSuit___pCurso_009a8020,uVar3);
                (**(code **)(iVar4 + 4))(uVar3);
                auStack_534[0] = 0;
                pcVar12 = s_OnSuit___pCursor_>PutArticle__pI_009a8064;
                puVar8 = auStack_534;
LAB_0048d5c5:
                uVar3 = FUN_0044a580(puVar8,pcVar12);
                FUN_00797b80(uVar3);
                FUN_00498050(0,param_1,piVar6,puVar11);
                goto LAB_0048d5e1;
              }
            }
            else {
              cVar1 = (**(code **)(*param_1 + 0x24))((uint)puVar11 & 0xff,piVar6);
              if (cVar1 == '\0') {
                piVar10 = DAT_00b5aa1c;
                uVar3 = (**(code **)(*param_1 + 0x70))();
                auStack_338[0] = 0;
                iVar4 = *piVar10;
                uVar3 = FUN_0044a580(auStack_338,s_UserName____s__LoadSuit___PutIte_009a8098,uVar3);
                (**(code **)(iVar4 + 4))(uVar3);
                auStack_734[0] = 0;
                pcVar12 = s_OnSuit___PutItem_Fail_009a80c0;
                puVar8 = auStack_734;
                goto LAB_0048d5c5;
              }
            }
          }
          (**(code **)(*piVar2 + 4))(1,((uint)piVar9 >> 0x18) - 2);
          uVar15 = uVar15 + (unaff_ESI >> 0x18);
        } while (uVar5 - 2 != uVar15);
      }
      (**(code **)(*DAT_00b5a69c + 8))(piVar2);
      return 1;
    }
    uVar3 = (**(code **)(*param_1 + 0x70))();
    auStack_80c[0] = 0;
    iVar4 = *piVar9;
    uVar3 = FUN_0044a580(auStack_80c,s_UserName____s__LoadSuit___wConve_009a7d14,uVar3);
    (**(code **)(iVar4 + 4))(uVar3);
    pcVar12 = s_LoadSuit___wConvertSize_>_rBuffe_009a7d50;
  }
  else {
    uVar3 = (**(code **)(*param_1 + 0x70))();
    auStack_80c[0] = 0;
    iVar4 = *piVar9;
    uVar3 = FUN_0044a580(auStack_80c,s_UserName____s__LoadSuit___pReade_009a7cac,uVar3);
    (**(code **)(iVar4 + 4))(uVar3);
    pcVar12 = s_LoadSuit___pReader_>READ__TotalS_009a7ce8;
  }
  FUN_0044a580(&uStack_810,&DAT_009a80d8,pcVar12);
  FUN_00797b80(&uStack_810);
  (**(code **)(*DAT_00b5a69c + 8))(piVar2);
  return 0;
}


// ==== FUN_0048d780 @ 0x0048d780 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048d780(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a80e0;
  _DAT_00b5aad8 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048d820 @ 0x0048d820 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048d820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a8294;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa7c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa7c = in_ECX;
  return;
}


// ==== FUN_0048d870 @ 0x0048d870 ====

uint FUN_0048d870(undefined4 param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined2 extraout_var;
  int *unaff_EBP;
  int *piVar9;
  char *pcVar10;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined1 *puStack_134;
  undefined4 uStack_130;
  undefined *puStack_12c;
  int *local_10c [2];
  undefined1 auStack_104 [240];
  undefined4 uStack_14;
  
  piVar9 = *(int **)(param_2 + 0x24);
  local_10c[0] = piVar9;
  if (piVar9 == (int *)0x0) {
    FUN_0044a580();
    puStack_12c = (undefined *)0x48d8a7;
    uVar3 = FUN_00797b80();
    return uVar3 & 0xffff0000;
  }
  piVar5 = *(int **)(param_2 + 0x1c);
  piVar4 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar4 == (int *)0x0) {
    uStack_130 = auStack_104;
    puStack_12c = &DAT_009a828c;
    puStack_134 = (undefined1 *)0x48d8e9;
    FUN_0044a580();
    puStack_134 = auStack_104;
    uStack_138 = (char *)0x48d8f3;
    uVar3 = FUN_00797b80();
    return uVar3 & 0xffff0000;
  }
  puStack_12c = (undefined *)0x2;
  uStack_130 = (undefined1 *)0x0;
  puStack_134 = (undefined1 *)0x48d911;
  (**(code **)(*piVar4 + 4))();
  uVar3 = 2;
  puStack_134 = (undefined1 *)0x48d91d;
  piVar5 = (int *)(**(code **)(*piVar5 + 0x1c))();
  if (piVar5 != (int *)0x0) {
    puStack_134 = (undefined1 *)0x2;
    uStack_138 = (char *)0x1;
    uStack_13c = (int **)0x48d931;
    (**(code **)(*piVar4 + 4))();
    iVar7 = *DAT_00b5aa10;
    uStack_13c = (int **)piVar4;
    uVar6 = (**(code **)(*piVar5 + 0x14))();
    cVar1 = (**(code **)(iVar7 + 4))(uVar6);
    uStack_130._0_3_ = CONCAT12(cVar1,(undefined2)uStack_130);
    if (cVar1 == '\0') {
      FUN_0044a580(local_10c + -4,&DAT_009a828c,s_OnSendSuit___Convert_return_size_009a8120);
      FUN_00797b80(local_10c + -4);
      FUN_004985b0(0,uStack_14,piVar5,0xff);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
    uVar3 = 0;
    uStack_130._0_3_ = CONCAT12(cVar1 + '\x02',(undefined2)uStack_130);
    (**(code **)(*piVar4 + 4))(0,2);
    iVar7 = (**(code **)(*piVar4 + 8))(1,(int)&uStack_138 + 2);
    if (iVar7 != 1) {
      FUN_0044a670(s_OnSendSuit___pWriter_>WRITE__byI_009a8148);
      FUN_00797b80(&puStack_12c);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
    iVar7 = (**(code **)(*piVar4 + 8))(1,(int)local_10c + -0x31);
    if (iVar7 != 1) {
      FUN_0044a670(s_OnSendSuit___pWriter_>WRITE__bIn_009a817c);
      FUN_00797b80(&puStack_134);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
    uVar3 = (uVar3 >> 0x10 & 0xff) + 2;
    (**(code **)(*piVar4 + 4))(0,uVar3);
    piVar9 = unaff_EBP;
  }
  puStack_134 = (undefined1 *)0x0;
  bVar2 = 0;
  do {
    uStack_138 = (char *)0x48da7c;
    piVar5 = (int *)(**(code **)(*piVar9 + 0x2c))();
    if (piVar5 != (int *)0x0) {
      puStack_134 = (undefined1 *)0x2;
      uStack_138 = (char *)0x1;
      uStack_13c = (int **)0x48da91;
      (**(code **)(*piVar4 + 4))();
      piVar9 = DAT_00b5aa10;
      iVar7 = *DAT_00b5aa10;
      uStack_13c = (int **)piVar4;
      uVar8 = (**(code **)(*piVar5 + 0x14))();
      cVar1 = (**(code **)(iVar7 + 4))();
      uStack_130._0_3_ = CONCAT12(cVar1,(undefined2)uStack_130);
      if (cVar1 == '\0') {
        FUN_0044a580(local_10c + -4,&DAT_009a828c,s_OnSendSuit___Convert_return_size_009a81ac);
        FUN_00797b80(local_10c + -4);
        FUN_004985b0(0,uStack_14,piVar5,puStack_12c);
        uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return uVar3 & 0xffff0000;
      }
      uStack_130._0_3_ = CONCAT12(cVar1 + '\x02',(undefined2)uStack_130);
      (**(code **)(*piVar4 + 4))(0,uVar3 & 0xffff);
      iVar7 = (**(code **)(*piVar4 + 8))(1,(int)&uStack_138 + 2);
      if (iVar7 != 1) {
        pcVar10 = s_OnSendSuit___pWriter_>WRITE__byI_009a81d4;
LAB_0048dc14:
        FUN_0044a580(&puStack_12c,&DAT_009a828c,pcVar10);
        FUN_00797b80(&puStack_12c);
        uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return uVar3 & 0xffff0000;
      }
      iVar7 = (**(code **)(*piVar4 + 8))(1,&uStack_13c);
      if (iVar7 != 1) {
        pcVar10 = s_OnSendSuit___pWriter_>WRITE__bIn_009a8208;
        goto LAB_0048dc14;
      }
      uVar3 = uVar3 + (uVar8 >> 0x10 & 0xff);
      (**(code **)(*piVar4 + 4))(0,uVar3 & 0xffff);
    }
    bVar2 = bVar2 + 1;
    puStack_134 = (undefined1 *)(uint)bVar2;
    if (0x14 < bVar2) {
      if (1000 < (ushort)uVar3) {
        puStack_134 = (undefined1 *)(uVar3 & 0xffff);
        uStack_13c = local_10c;
        uStack_138 = s_Suit__Save_wTotalSize__d__>_1000_009a8238;
        local_10c[0] = (int *)((uint)local_10c[0] & 0xffffff00);
        iVar7 = *DAT_00b5aa1c;
        puStack_134 = (undefined1 *)FUN_0044a580();
        uStack_138 = (char *)0x48db54;
        (**(code **)(iVar7 + 4))();
      }
      puStack_134 = (undefined1 *)0x0;
      uStack_138 = (char *)0x0;
      uStack_13c = (int **)0x48db5f;
      (**(code **)(*piVar4 + 4))();
      uStack_13c = local_10c + -4;
      iVar7 = (**(code **)(*piVar4 + 8))(2);
      if (iVar7 == 2) {
        (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return CONCAT22(extraout_var,(ushort)uVar3);
      }
      FUN_0044a580(local_10c + -4,&DAT_009a828c,s_OnSendSuit___pWriter_>WRITE__wCV_009a825c);
      FUN_00797b80(local_10c + -4);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
  } while( true );
}


// ==== FUN_0048dc70 @ 0x0048dc70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048dc70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a8294;
  _DAT_00b5aa7c = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048dca0 @ 0x0048dca0 ====

undefined1 FUN_0048dca0(void)

{
  return 1;
}


// ==== FUN_0048dcb0 @ 0x0048dcb0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048dcb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a829c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aaac = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aaac = in_ECX;
  return;
}


// ==== FUN_0048dd00 @ 0x0048dd00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048dd00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a829c;
  _DAT_00b5aaac = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048dda0 @ 0x0048dda0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048dda0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a84a4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa58 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa58 = in_ECX;
  return;
}


// ==== FUN_0048ddf0 @ 0x0048ddf0 ====

uint FUN_0048ddf0(undefined4 param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined2 extraout_var;
  ushort uVar8;
  int *piVar9;
  char *pcVar10;
  undefined4 uStack_114;
  undefined1 auStack_10c [4];
  int *local_108;
  undefined1 auStack_104 [4];
  undefined1 local_100 [256];
  
  piVar9 = *(int **)(param_2 + 0x24);
  local_108 = piVar9;
  if (piVar9 == (int *)0x0) {
    FUN_0044a580(local_100);
    uVar3 = FUN_00797b80(local_100);
    return uVar3 & 0xffff0000;
  }
  piVar5 = *(int **)(param_2 + 0x1c);
  piVar4 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))(param_1);
  if (piVar4 == (int *)0x0) {
    FUN_0044a580(auStack_104,&DAT_009a849c,s_OnSendSuit___pWriter_is_NULL_009a82bc);
    uVar3 = FUN_00797b80(auStack_104);
    return uVar3 & 0xffff0000;
  }
  (**(code **)(*piVar4 + 4))(0,2);
  uVar8 = 2;
  piVar5 = (int *)(**(code **)(*piVar5 + 0x1c))();
  if (piVar5 != (int *)0x0) {
    iVar6 = (**(code **)(*piVar4 + 8))(1,auStack_10c + -0x11);
    if (iVar6 != 1) {
      FUN_0044a580(&uStack_114,&DAT_009a849c,s_OnSendSuitSerial___pWriter_>WRIT_009a82e0);
      FUN_00797b80(&uStack_114);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
    (**(code **)(*piVar5 + 0x14))();
    iVar6 = (**(code **)(*piVar4 + 8))(2,auStack_10c + -0x14);
    if (iVar6 != 2) {
      FUN_0044a670(s_OnSendSuitSerial___pWriter_>WRIT_009a8320);
      FUN_00797b80(auStack_10c + -0x10);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
    iVar6 = *DAT_00b5aa10;
    uVar7 = (**(code **)(*piVar5 + 0x74))(piVar4);
    bVar1 = (**(code **)(iVar6 + 0xc))(uVar7);
    if (bVar1 == 0) {
      FUN_0044a670(s_OnSend_SuitSerial___Convert_retu_009a8358);
      FUN_00797b80(auStack_10c);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
    uVar8 = bVar1 + 5;
  }
  bVar1 = 0;
  do {
    piVar5 = (int *)(**(code **)(*piVar9 + 0x2c))(bVar1);
    if (piVar5 != (int *)0x0) {
      iVar6 = (**(code **)(*piVar4 + 8))(1,auStack_10c + -0x11);
      if (iVar6 != 1) {
        pcVar10 = s_OnSendSuitSerial___pWriter_>WRIT_009a8388;
        goto LAB_0048e0bd;
      }
      (**(code **)(*piVar5 + 0x14))();
      iVar6 = (**(code **)(*piVar4 + 8))(2,auStack_10c + -0x10);
      if (iVar6 != 2) {
        pcVar10 = s_OnSendSuitSerial___pWriter_>WRIT_009a83d0;
        goto LAB_0048e0bd;
      }
      iVar6 = *DAT_00b5aa10;
      uVar7 = (**(code **)(*piVar5 + 0x74))(piVar4);
      bVar2 = (**(code **)(iVar6 + 0xc))(uVar7);
      if (bVar2 == 0) {
        pcVar10 = s_OnSend_SuitSerial___Convert_retu_009a840c;
        goto LAB_0048e0bd;
      }
      uVar8 = uVar8 + 3 + (ushort)bVar2;
      piVar9 = uStack_114;
    }
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x15);
  if (1000 < uVar8) {
    auStack_10c[0] = 0;
    iVar6 = *DAT_00b5aa1c;
    uVar7 = FUN_0044a580(auStack_10c,s_SuitSerial__Save_wTotalSize__d__>_009a843c,uVar8);
    (**(code **)(iVar6 + 4))(uVar7);
  }
  (**(code **)(*piVar4 + 4))(0,0);
  iVar6 = (**(code **)(*piVar4 + 8))(2,auStack_10c + -0xc);
  if (iVar6 == 2) {
    (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
    return CONCAT22(extraout_var,uVar8);
  }
  pcVar10 = s_OnSendSuit_Serial___pWriter_>WRI_009a8464;
LAB_0048e0bd:
  FUN_0044a580(auStack_10c,&DAT_009a849c,pcVar10);
  FUN_00797b80(auStack_10c);
  uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
  return uVar3 & 0xffff0000;
}


// ==== FUN_0048e120 @ 0x0048e120 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048e120(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a84a4;
  _DAT_00b5aa58 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048e1c0 @ 0x0048e1c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048e1c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a8798;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aaa8 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aaa8 = in_ECX;
  return;
}


// ==== FUN_0048e210 @ 0x0048e210 ====

undefined4 FUN_0048e210(uint *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined2 extraout_var;
  undefined4 unaff_EBP;
  uint uVar7;
  undefined4 unaff_ESI;
  int *piVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined1 *puStack_240;
  undefined4 uStack_23c;
  undefined1 auStack_22c [8];
  uint uStack_224;
  undefined1 auStack_220 [16];
  undefined1 auStack_210 [4];
  undefined1 auStack_20c [4];
  undefined1 auStack_208 [4];
  undefined1 auStack_204 [228];
  undefined1 auStack_120 [4];
  undefined1 auStack_11c [4];
  undefined1 auStack_118 [4];
  undefined1 auStack_114 [272];
  uint *puStack_4;
  
  uStack_23c = param_1;
  puStack_240 = (undefined1 *)0x48e22c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  piVar8 = DAT_00b5aa1c;
  if (piVar2 == (int *)0x0) {
    puStack_240 = (undefined1 *)0x48e244;
    puStack_240 = (undefined1 *)(**(code **)(*param_1 + 0x70))();
    auStack_204[0] = 0;
    iVar3 = *piVar8;
    puStack_240 = (undefined1 *)
                  FUN_0044a580(auStack_204,s_UserName____s__Load_SuitLimit___p_009a84ac);
    (**(code **)(iVar3 + 4))();
    FUN_0044a580(auStack_208,&DAT_009a8790,s_Load_SuitLimit___pReader_is_NULL_009a84e0);
    FUN_00797b80(auStack_208);
    return 0;
  }
  uStack_224 = param_1[9];
  if (uStack_224 == 0) {
    puStack_240 = (undefined1 *)0x48e2b2;
    puStack_240 = (undefined1 *)(**(code **)(*param_1 + 0x70))();
    auStack_204[0] = 0;
    iVar3 = *piVar8;
    puStack_240 = (undefined1 *)
                  FUN_0044a580(auStack_204,s_UserName____s__Load_SuitLimit___p_009a8504);
    (**(code **)(iVar3 + 4))();
    FUN_0044a580(auStack_208,&DAT_009a8790,s_Load_SuitLimit___pSuit_is_NULL_009a8534);
    FUN_00797b80(auStack_208);
    (**(code **)(*DAT_00b5a69c + 8))(piVar2);
    return 0;
  }
  puStack_240 = auStack_22c;
  iVar3 = (**(code **)(*piVar2 + 8))(2);
  piVar8 = DAT_00b5aa1c;
  if (iVar3 == 2) {
    uStack_224 = (uint)CONCAT11((char)unaff_ESI,(char)((uint)unaff_ESI >> 8));
    if (uStack_224 <= *param_1) {
      uVar7 = 2;
      if (uStack_224 != 2) {
        do {
          puVar10 = auStack_22c + -9;
          uVar4 = 1;
          iVar3 = (**(code **)(*piVar2 + 8))(1,puVar10);
          piVar8 = DAT_00b5aa1c;
          if (iVar3 != 1) {
            uVar4 = (**(code **)(*param_1 + 0x70))();
            auStack_114[0] = 0;
            iVar3 = *piVar8;
            uVar4 = FUN_0044a580(auStack_114,s_UserName____s__Load_SuitLimit__p_009a8648,uVar4);
            (**(code **)(iVar3 + 4))(uVar4);
            FUN_0044a670(s_Load_SuitLimit___pReader_>READ__b_009a868c);
            FUN_00797b80(auStack_118);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          piVar8 = (int *)(auStack_22c + -0xc);
          iVar3 = (**(code **)(*piVar2 + 8))(2);
          piVar5 = DAT_00b5aa1c;
          if (iVar3 != 2) {
            uVar4 = (**(code **)(*param_1 + 0x70))();
            auStack_11c[0] = 0;
            iVar3 = *piVar5;
            uVar4 = FUN_0044a580(auStack_11c,s_UserName____s__Load_SuitLimit__p_009a86c0,uVar4);
            (**(code **)(iVar3 + 4))(uVar4);
            FUN_0044a670(s_Load_SuitLimit___pReader_>READ__w_009a8704);
            FUN_00797b80(auStack_120);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          puStack_240 = (undefined1 *)
                        CONCAT22(extraout_var,
                                 CONCAT11((char)puStack_240,(char)((uint)puStack_240 >> 8)));
          cVar1 = (char)((uint)unaff_EBP >> 0x18);
          if (cVar1 == -1) {
            piVar5 = (int *)(**(code **)(*(int *)param_1[7] + 0x1c))();
            if (piVar5 != (int *)0x0) goto LAB_0048e4bf;
            auStack_120[0] = 0;
            iVar3 = *DAT_00b5aa1c;
            uVar4 = FUN_0044a580(auStack_120,s__ITEM__LimitItem___INVALID_POSIT_009a8764,
                                 (uint)puVar10 >> 0x18);
            (**(code **)(iVar3 + 0xc))(uVar4);
LAB_0048e55b:
            (**(code **)(*piVar2 + 4))(1,0xc);
          }
          else {
            piVar5 = (int *)(**(code **)(*uStack_23c + 0x2c))(cVar1);
            if (piVar5 == (int *)0x0) {
              auStack_220[0] = 0;
              iVar3 = *DAT_00b5aa1c;
              uVar4 = FUN_0044a580(auStack_220,s__ITEM__LimitItem__INVALID_POSITI_009a8738,
                                   (uint)puVar10 >> 0x18);
              (**(code **)(iVar3 + 0xc))(uVar4);
              (**(code **)(*piVar2 + 4))(1,0xc);
            }
            else {
LAB_0048e4bf:
              FUN_00797a50(auStack_22c,0,0xc);
              (**(code **)(*piVar2 + 4))(1,0);
              uVar6 = (**(code **)(*DAT_00b5a69c + 4))(&uStack_23c);
              cVar1 = (**(code **)(*DAT_00b5aa10 + 0x18))(uVar6,auStack_22c + -0xc);
              if (cVar1 != '\0') {
                (**(code **)(*piVar5 + 0x78))(&puStack_240);
                (**(code **)(*DAT_00b5a69c + 8))(uVar6);
                goto LAB_0048e55b;
              }
              uVar4 = (**(code **)(*piVar8 + 0x20))(uVar4);
              (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar4);
              (**(code **)(*DAT_00b5a69c + 8))(uVar6);
              (**(code **)(*piVar2 + 4))(1,0xc);
            }
          }
          uVar7 = uVar7 + 0xf;
          param_1 = puStack_4;
        } while (uStack_224 != uVar7);
      }
      (**(code **)(*DAT_00b5a69c + 8))(piVar2);
      return 1;
    }
    uVar4 = (**(code **)(*param_1 + 0x70))();
    auStack_20c[0] = 0;
    iVar3 = *piVar8;
    uVar4 = FUN_0044a580(auStack_20c,s_UserName____s__Load_SuitLimit__w_009a85d0,uVar4);
    (**(code **)(iVar3 + 4))(uVar4);
    pcVar9 = s_Load_SuitLimit___wConvertSize_>_r_009a8610;
  }
  else {
    uVar4 = (**(code **)(*param_1 + 0x70))();
    auStack_20c[0] = 0;
    iVar3 = *piVar8;
    uVar4 = FUN_0044a580(auStack_20c,s_UserName____s__Load_SuitLimit___p_009a8558,uVar4);
    (**(code **)(iVar3 + 4))(uVar4);
    pcVar9 = s_Load_SuitLimit___pReader_>READ__T_009a859c;
  }
  FUN_0044a580(auStack_210,&DAT_009a8790,pcVar9);
  FUN_00797b80(auStack_210);
  (**(code **)(*DAT_00b5a69c + 8))(piVar2);
  return 0;
}


// ==== FUN_0048e680 @ 0x0048e680 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048e680(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a8798;
  _DAT_00b5aaa8 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048e720 @ 0x0048e720 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048e720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a89a8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa54 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa54 = in_ECX;
  return;
}


// ==== FUN_0048e770 @ 0x0048e770 ====

uint FUN_0048e770(undefined4 param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined4 uVar8;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  ushort uVar9;
  int *unaff_EBP;
  int *piVar10;
  undefined4 uStack_124;
  ushort uVar11;
  undefined1 auStack_114 [2];
  undefined1 auStack_112 [6];
  int *local_10c [2];
  undefined1 auStack_104 [4];
  undefined1 local_100 [252];
  undefined4 uStack_4;
  
  piVar10 = *(int **)(param_2 + 0x24);
  local_10c[0] = piVar10;
  if (piVar10 == (int *)0x0) {
    uStack_124 = local_100;
    FUN_0044a580();
    uVar3 = FUN_00797b80(local_100);
    return uVar3 & 0xffff0000;
  }
  piVar5 = *(int **)(param_2 + 0x1c);
  if (piVar5 == (int *)0x0) {
    uStack_124 = &DAT_009a89a0;
    FUN_0044a580(local_100);
    uVar3 = FUN_00797b80(local_100);
    return uVar3 & 0xffff0000;
  }
  uStack_124 = (undefined1 *)param_1;
  piVar4 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar4 == (int *)0x0) {
    FUN_0044a580(auStack_104,&DAT_009a89a0,s_OnSend_SuitSerial___pWriter_is_N_009a87ec);
    uVar3 = FUN_00797b80(auStack_104);
    return uVar3 & 0xffff0000;
  }
  (**(code **)(*piVar4 + 4))(0,2);
  uVar11 = 2;
  piVar5 = (int *)(**(code **)(*piVar5 + 0x1c))();
  if (piVar5 != (int *)0x0) {
    iVar6 = (**(code **)(*piVar4 + 8))(1,auStack_114 + -9);
    if (iVar6 != 1) {
      FUN_0044a670(s_OnSendSuit___pWriter_>WRITE__255_009a8814);
      FUN_00797b80(auStack_114);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
    puVar7 = (undefined2 *)(**(code **)(*piVar5 + 0x14))();
    uStack_124 = (undefined1 *)
                 CONCAT22(extraout_var_00,CONCAT11((char)*puVar7,(char)((ushort)*puVar7 >> 8)));
    iVar6 = (**(code **)(*piVar4 + 8))(2,&uStack_124);
    if (iVar6 != 2) {
      FUN_0044a670(s_OnSendSuit___pWriter_>WRITE__wIt_009a8840);
      FUN_00797b80(auStack_114 + -8);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
    iVar6 = *DAT_00b5aa10;
    uVar8 = (**(code **)(*piVar5 + 0x7c))(piVar4);
    bVar1 = (**(code **)(iVar6 + 0x14))(uVar8);
    if (bVar1 == 0) {
      FUN_0044a670(s_OnSend_Suit_Limit___ConvertLimit_009a8874);
      FUN_00797b80(local_10c);
      FUN_004985b0(0,uStack_4,piVar5,0xff);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
    uVar11 = bVar1 + 5;
    piVar10 = unaff_EBP;
  }
  bVar1 = 0;
  uVar9 = uVar11;
  do {
    piVar5 = (int *)(**(code **)(*piVar10 + 0x2c))(bVar1);
    if (piVar5 != (int *)0x0) {
      iVar6 = (**(code **)(*piVar4 + 8))(1,auStack_114 + -9);
      if (iVar6 != 1) {
        FUN_0044a580(auStack_114,&DAT_009a89a0,s_OnSend_SuitLimit___pWriter_>WRIT_009a88a8);
        FUN_00797b80(auStack_114);
        uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return uVar3 & 0xffff0000;
      }
      puVar7 = (undefined2 *)(**(code **)(*piVar5 + 0x14))();
      piVar10 = (int *)CONCAT22(extraout_var_01,CONCAT11((char)*puVar7,(char)((ushort)*puVar7 >> 8))
                               );
      iVar6 = (**(code **)(*piVar4 + 8))(2,auStack_114 + -4);
      if (iVar6 != 2) {
        FUN_0044a580(auStack_114 + -8,&DAT_009a89a0,s_OnSendSuit___pWriter_>WRITE__wIt_009a88e4);
        FUN_00797b80(auStack_114 + -8);
        uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return uVar3 & 0xffff0000;
      }
      iVar6 = *DAT_00b5aa10;
      uVar8 = (**(code **)(*piVar5 + 0x7c))(piVar4);
      bVar2 = (**(code **)(iVar6 + 0x14))(uVar8);
      if (bVar2 == 0) {
        FUN_0044a670(s_OnSend_Suit_Limit___ConvertLimit_009a8918);
        FUN_00797b80(local_10c);
        FUN_004985b0(0,uStack_4,piVar5,0xff);
        uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return uVar3 & 0xffff0000;
      }
      uVar9 = uVar11 + 3 + (ushort)bVar2;
      uVar11 = uVar9;
    }
    bVar1 = bVar1 + 1;
    if (0x14 < bVar1) {
      if (1000 < uVar9) {
        local_10c[0] = (int *)((uint)local_10c[0] & 0xffffff00);
        iVar6 = *DAT_00b5aa1c;
        uVar8 = FUN_0044a580(local_10c,s_Suit__Save_wTotalSize__d__>_1000_009a894c,uVar9);
        (**(code **)(iVar6 + 4))(uVar8);
      }
      (**(code **)(*piVar4 + 4))(0,0);
      iVar6 = (**(code **)(*piVar4 + 8))(2,auStack_114 + -8);
      if (iVar6 == 2) {
        (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return CONCAT22(extraout_var,uVar9);
      }
      FUN_0044a580(auStack_114 + -8,&DAT_009a89a0,s_OnSendSuit___pWriter_>WRITE__wCV_009a8970);
      FUN_00797b80(auStack_114 + -8);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
  } while( true );
}


// ==== FUN_0048eba0 @ 0x0048eba0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048eba0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a89a8;
  _DAT_00b5aa54 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048ec30 @ 0x0048ec30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048ec30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a8de4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aad4 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aad4 = in_ECX;
  return;
}


// ==== FUN_0048ec80 @ 0x0048ec80 ====

undefined4 FUN_0048ec80(uint *param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  byte bVar8;
  int *unaff_EBP;
  uint unaff_EDI;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  undefined4 uStack_650;
  int *piStack_64c;
  int *piStack_644;
  undefined4 uStack_640;
  undefined4 uStack_63c;
  uint uVar12;
  undefined1 auStack_62a [14];
  undefined1 auStack_61c [4];
  uint uStack_618;
  int *piStack_614;
  undefined1 auStack_610 [4];
  undefined1 auStack_60c [4];
  undefined1 auStack_608 [4];
  undefined1 uStack_604;
  undefined1 auStack_534 [20];
  undefined1 auStack_520 [4];
  undefined1 auStack_51c [4];
  undefined1 auStack_518 [4];
  undefined1 auStack_514 [228];
  undefined1 auStack_430 [244];
  undefined1 auStack_33c [256];
  undefined1 auStack_23c [264];
  undefined1 auStack_134 [308];
  
  uStack_63c = param_1;
  uStack_640 = (undefined1 *)0x48ec9c;
  piVar3 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  piVar5 = DAT_00b5aa1c;
  piStack_614 = piVar3;
  if (piVar3 == (int *)0x0) {
    uStack_640 = (undefined1 *)0x48ecb8;
    uStack_640 = (undefined1 *)(**(code **)(*param_1 + 0x70))();
    uStack_604 = 0;
    iVar4 = *piVar5;
    piStack_64c = (int *)0x48eccf;
    uStack_640 = (undefined1 *)FUN_0044a580();
    (**(code **)(iVar4 + 4))();
    piStack_64c = (int *)auStack_608;
    uStack_650 = (undefined1 *)0x48ecec;
    FUN_0044a580();
    uStack_650 = auStack_608;
    FUN_00797b80();
    return 0;
  }
  uStack_618 = param_1[8];
  if (uStack_618 == 0) {
    uStack_640 = (undefined1 *)0x48ed26;
    uStack_640 = (undefined1 *)(**(code **)(*param_1 + 0x70))();
    uStack_604 = 0;
    iVar4 = *piVar5;
    piStack_64c = (int *)0x48ed3d;
    uStack_640 = (undefined1 *)FUN_0044a580();
    (**(code **)(iVar4 + 4))();
    (**(code **)(*DAT_00b5a69c + 8))();
    uStack_650 = auStack_60c;
    piStack_64c = (int *)&DAT_009a8ddc;
    FUN_0044a580();
    FUN_00797b80(auStack_60c);
    return 0;
  }
  uStack_640 = auStack_61c;
  piStack_644 = (int *)0x2;
  iVar4 = (**(code **)(*piVar3 + 8))();
  piVar5 = DAT_00b5aa1c;
  if (iVar4 == 2) {
    uStack_618 = (uint)CONCAT11(auStack_62a[6],auStack_62a[7]);
    if (uStack_618 <= *param_1) {
      uVar12 = 2;
      if (uStack_618 != 2) {
        do {
          piStack_64c = (int *)(auStack_62a + -0xc);
          uStack_650 = (undefined1 *)0x1;
          iVar4 = (**(code **)(*piVar3 + 8))();
          piVar5 = DAT_00b5aa1c;
          if (iVar4 != 1) {
            uVar6 = (**(code **)(*param_1 + 0x70))();
            auStack_514[0] = 0;
            iVar4 = *piVar5;
            uVar6 = FUN_0044a580(auStack_514,s_UserName____s__LoadBag___pReader_009a8b0c,uVar6);
            (**(code **)(iVar4 + 4))(uVar6);
            FUN_0044a670(s_LoadBag___pReader_>READ__size___F_009a8b44);
            FUN_00797b80(auStack_518);
            (**(code **)(*DAT_00b5a69c + 8))(piVar3);
            return 0;
          }
          if (uStack_640._2_1_ < 3) {
            uVar6 = (**(code **)(*param_1 + 0x70))();
            auStack_514[0] = 0;
            iVar4 = *piVar5;
            uVar6 = FUN_0044a580(auStack_514,s_UserName____s__LoadBag___size_<__009a8b6c,uVar6);
            (**(code **)(iVar4 + 4))(uVar6);
            FUN_0044a670(s_LoadBag___size_<__2_009a8b90);
            FUN_00797b80(auStack_518);
            (**(code **)(*DAT_00b5a69c + 8))(piVar3);
            return 0;
          }
          iVar4 = (**(code **)(*piVar3 + 8))(1,(int)&uStack_640 + 3);
          piVar5 = DAT_00b5aa1c;
          if (iVar4 != 1) {
            uVar6 = (**(code **)(*param_1 + 0x70))();
            auStack_51c[0] = 0;
            iVar4 = *piVar5;
            uVar6 = FUN_0044a580(auStack_51c,s_UserName____s__LoadBag___pReader_009a8ba8,uVar6);
            (**(code **)(iVar4 + 4))(uVar6);
            FUN_0044a670(s_LoadBag___pReader_>READ__size___F_009a8be0);
            FUN_00797b80(auStack_520);
            (**(code **)(*DAT_00b5a69c + 8))(piVar3);
            return 0;
          }
          (**(code **)(*piVar3 + 4))(1,0);
          bVar10 = (byte)((uint)iVar4 >> 0x18);
          uVar9 = 0;
          piVar5 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
          cVar2 = (**(code **)(*piVar5 + 0xc))(auStack_62a + -10);
          if (cVar2 == '\0') {
            uVar12 = uVar12 & 0xffffff00;
            uVar6 = FUN_0044a580(auStack_62a + -6,s_LoadBag___Item_Open_Fail_009a8c08);
            FUN_00797b80(uVar6);
            piVar1 = DAT_00b5aa1c;
            uVar6 = (**(code **)(*param_1 + 0x70))();
            auStack_430[0] = 0;
            iVar4 = *piVar1;
            uVar6 = FUN_0044a580(auStack_430,s_UserName____s__LoadBag___Item_Op_009a8c24,uVar6);
            (**(code **)(iVar4 + 4))(uVar6);
LAB_0048f14c:
            (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar5);
          }
          else {
            cVar2 = (**(code **)(*DAT_00b5a734 + 0x38))(piVar5);
            if (cVar2 == '\0') {
              puVar7 = (undefined2 *)(**(code **)(*piVar5 + 0x14))();
              piVar3 = DAT_00b5aa1c;
              uVar6 = (**(code **)(*param_1 + 0x70))();
              auStack_134[0] = 0;
              iVar4 = *piVar3;
              uVar6 = FUN_0044a580(auStack_134,s__ITEM__InvalidItem___index__u__U_009a8c50,*puVar7,
                                   uVar6,*(undefined1 *)((int)puVar7 + 0x21),puVar7[6],
                                   *(undefined1 *)((int)puVar7 + 0x1f),*(undefined1 *)(puVar7 + 0xf)
                                   ,puVar7[7],*(undefined1 *)(puVar7 + 8),puVar7[9],
                                   *(undefined1 *)(puVar7 + 10),puVar7[0xb],
                                   *(undefined1 *)(puVar7 + 0xc),puVar7[0xd],
                                   *(undefined1 *)(puVar7 + 0xe),puVar7[2],puVar7[3],puVar7[4],
                                   puVar7[5]);
              (**(code **)(iVar4 + 0xc))(uVar6);
              (**(code **)(*DAT_00b5a734 + 0x3c))(piVar5);
              piVar3 = DAT_00b5aa1c;
              uVar6 = (**(code **)(*param_1 + 0x70))();
              auStack_23c[0] = 0;
              iVar4 = *piVar3;
              uVar6 = FUN_0044a580(auStack_23c,s__ITEM__RevisedItem___index__u__U_009a8cf8,*puVar7,
                                   uVar6,*(undefined1 *)((int)puVar7 + 0x21),puVar7[6],
                                   *(undefined1 *)((int)puVar7 + 0x1f),*(undefined1 *)(puVar7 + 0xf)
                                   ,puVar7[7],*(undefined1 *)(puVar7 + 8),puVar7[9],
                                   *(undefined1 *)(puVar7 + 10),puVar7[0xb],
                                   *(undefined1 *)(puVar7 + 0xc),puVar7[0xd],
                                   *(undefined1 *)(puVar7 + 0xe),puVar7[2],puVar7[3],puVar7[4],
                                   puVar7[5]);
              (**(code **)(iVar4 + 0xc))(uVar6);
              piVar3 = piStack_644;
            }
            bVar8 = (bVar10 % 0x32) % 10;
            uVar11 = (uint)bVar8;
            uStack_650 = (undefined1 *)
                         CONCAT22(CONCAT11(uStack_650._3_1_,(bVar10 % 0x32) / 10),
                                  CONCAT11(bVar8,bVar10 / 0x32));
            cVar2 = (**(code **)(*unaff_EBP + 0x1c))(&uStack_650,piVar5);
            piVar1 = DAT_00b5aa1c;
            if (cVar2 == '\0') {
              uVar6 = (**(code **)(*param_1 + 0x70))();
              auStack_33c[0] = 0;
              iVar4 = *piVar1;
              uVar6 = FUN_0044a580(auStack_33c,s_UserName____s__LoadBag___PutItem_009a8d9c,uVar6);
              (**(code **)(iVar4 + 4))(uVar6);
              auStack_534[0] = 0;
              uVar6 = FUN_0044a580(auStack_534,s_LoadBag___PutItem_fail_009a8dc4);
              FUN_00797b80(uVar6);
              FUN_00498050(1,param_1,piVar5,uVar11);
              goto LAB_0048f14c;
            }
          }
          (**(code **)(*piVar3 + 4))(1,(uVar9 >> 0x10 & 0xff) - 2);
          uVar12 = uVar12 + (unaff_EDI >> 0x10 & 0xff);
        } while (uStack_618 != uVar12);
      }
      uStack_650 = (undefined1 *)0x48f18f;
      piStack_64c = piVar3;
      (**(code **)(*DAT_00b5a69c + 8))();
      return 1;
    }
    (**(code **)(*param_1 + 0x70))();
    uStack_650 = auStack_60c;
    piStack_64c = (int *)s_UserName____s__LoadBag___wConver_009a8aa4;
    auStack_60c[0] = 0;
    iVar4 = *piVar5;
    FUN_0044a580();
    piStack_64c = (int *)0x48ee0d;
    (**(code **)(iVar4 + 4))();
    piStack_64c = (int *)s_LoadBag___wConvertSize_>_rBuffer_009a8ae0;
  }
  else {
    (**(code **)(*param_1 + 0x70))();
    uStack_650 = auStack_60c;
    piStack_64c = (int *)s_UserName____s__LoadBag___pReader_009a8a3c;
    auStack_60c[0] = 0;
    iVar4 = *piVar5;
    FUN_0044a580();
    piStack_64c = (int *)0x48edc1;
    (**(code **)(iVar4 + 4))();
    piStack_64c = (int *)s_LoadBag___pReader_>READ___TotalS_009a8a78;
  }
  uStack_650 = &DAT_009a8ddc;
  FUN_0044a580(auStack_610);
  FUN_00797b80(auStack_610);
  uStack_650 = (undefined1 *)0x48ee3a;
  piStack_64c = piVar3;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 0;
}


// ==== FUN_0048f2f0 @ 0x0048f2f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048f2f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a8de4;
  _DAT_00b5aad4 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048f320 @ 0x0048f320 ====

undefined1 FUN_0048f320(void)

{
  return 1;
}


// ==== FUN_0048f330 @ 0x0048f330 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048f330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a8dec;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aaa4 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aaa4 = in_ECX;
  return;
}


// ==== FUN_0048f380 @ 0x0048f380 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048f380(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a8dec;
  _DAT_00b5aaa4 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048f420 @ 0x0048f420 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048f420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a91b0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aaa0 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aaa0 = in_ECX;
  return;
}


// ==== FUN_0048f470 @ 0x0048f470 ====

undefined4 FUN_0048f470(uint *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  short *psVar8;
  undefined2 *puVar9;
  byte bVar10;
  uint uVar11;
  undefined4 *puVar12;
  int *piVar13;
  undefined1 *puVar14;
  undefined4 uStack_160;
  undefined4 *puStack_15c;
  int *piStack_158;
  int *piStack_154;
  int *piStack_150;
  undefined1 *puStack_14c;
  undefined4 uStack_140;
  undefined4 uStack_134;
  uint uStack_130;
  undefined1 auStack_12c [4];
  undefined1 auStack_128 [4];
  undefined1 auStack_124 [4];
  undefined1 auStack_120 [4];
  uint uStack_11c;
  undefined1 auStack_118 [4];
  undefined1 auStack_114 [4];
  undefined1 auStack_110 [4];
  undefined1 auStack_10c [4];
  undefined1 auStack_108 [4];
  undefined1 auStack_104 [260];
  
  uStack_140 = param_1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  piVar13 = DAT_00b5aa1c;
  if (piVar2 == (int *)0x0) {
    (**(code **)(*param_1 + 0x70))();
    puStack_14c = auStack_104;
    auStack_104[0] = 0;
    iVar3 = *piVar13;
    piStack_150 = (int *)0x48f4ba;
    FUN_0044a580();
    (**(code **)(iVar3 + 4))();
    piStack_150 = (int *)auStack_108;
    puStack_14c = &DAT_009a91a8;
    piStack_154 = (int *)0x48f4d7;
    FUN_0044a580();
    piStack_154 = (int *)auStack_108;
    piStack_158 = (int *)0x48f4e1;
    FUN_00797b80();
    return 0;
  }
  uStack_11c = param_1[8];
  if (uStack_11c == 0) {
    puStack_14c = (undefined1 *)0x48f513;
    puStack_14c = (undefined1 *)(**(code **)(*param_1 + 0x70))();
    piStack_154 = (int *)auStack_104;
    piStack_150 = (int *)s_UserName____s__Load_BagLimit___p_009a8e48;
    auStack_104[0] = 0;
    iVar3 = *piVar13;
    piStack_158 = (int *)0x48f52a;
    puStack_14c = (undefined1 *)FUN_0044a580();
    piStack_150 = (int *)0x48f533;
    (**(code **)(iVar3 + 4))();
    piStack_150 = (int *)s_Load_BagLimit___pBag_is_NULL_009a8e78;
    piStack_158 = (int *)auStack_108;
    piStack_154 = (int *)&DAT_009a91a8;
    puStack_15c = (undefined4 *)0x48f547;
    FUN_0044a580();
    puStack_15c = (undefined4 *)auStack_108;
    uStack_160 = (char *)0x48f551;
    FUN_00797b80();
    piStack_154 = (int *)0x48f560;
    piStack_150 = piVar2;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  puStack_14c = auStack_124;
  piStack_150 = (int *)0x2;
  piStack_154 = (int *)0x48f57d;
  iVar3 = (**(code **)(*piVar2 + 8))();
  piVar13 = DAT_00b5aa1c;
  if (iVar3 == 2) {
    uVar4 = (uint)CONCAT11(auStack_12c[0],auStack_12c[1]);
    if (uVar4 <= *param_1) {
      uStack_134 = 2;
      if (uVar4 != 2) {
        do {
          piStack_154 = (int *)((int)&uStack_140 + 3);
          piStack_158 = (int *)0x1;
          puStack_15c = (undefined4 *)0x48f65e;
          iVar3 = (**(code **)(*piVar2 + 8))();
          piVar13 = DAT_00b5aa1c;
          if (iVar3 != 1) {
            puStack_15c = (undefined4 *)0x48f80b;
            puStack_15c = (undefined4 *)(**(code **)(*param_1 + 0x70))();
            uStack_160 = s_UserName____s__Load_BagLimit___p_009a8f88;
            auStack_114[0] = 0;
            iVar3 = *piVar13;
            puStack_15c = (undefined4 *)FUN_0044a580(auStack_114);
            uStack_160 = (char *)0x48f82b;
            (**(code **)(iVar3 + 4))();
            uStack_160 = s_LoadBag___pReader_>READ__byLocal_009a8fd0;
            FUN_0044a670();
            uStack_160 = auStack_118;
            FUN_00797b80();
            uStack_160 = (char *)piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          puStack_15c = &uStack_140;
          uStack_160 = (char *)0x2;
          iVar3 = (**(code **)(*piVar2 + 8))();
          piVar13 = DAT_00b5aa1c;
          if (iVar3 != 2) {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            uStack_11c = uStack_11c & 0xffffff00;
            iVar3 = *piVar13;
            uVar7 = FUN_0044a580(&uStack_11c,s_UserName____s__Load_BagLimit__pR_009a9008,uVar7);
            (**(code **)(iVar3 + 4))(uVar7);
            FUN_0044a670(s_Load_BagLimit__pReader_>READ__wI_009a9048);
            FUN_00797b80(auStack_120);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          uStack_130 = 0xc;
          uStack_134 = (**(code **)(*piVar2 + 4))(1,0);
          puVar14 = auStack_12c + -0xc;
          uVar5 = (**(code **)(*DAT_00b5a69c + 4))();
          piVar13 = DAT_00b5aa1c;
          if (uVar5 == 0) {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            auStack_128[0] = 0;
            iVar3 = *piVar13;
            uVar7 = FUN_0044a580(auStack_128,s_UserName____s__Load_BagLimit___p_009a907c,uVar7);
            (**(code **)(iVar3 + 4))(uVar7);
            FUN_0044a670(s_Load_BagLimit___pLimitReader_is_N_009a90b4);
            FUN_00797b80(auStack_12c);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          FUN_00797a50(&uStack_134,0,0xc);
          puVar12 = &uStack_134;
          uVar11 = uVar5;
          cVar1 = (**(code **)(*DAT_00b5aa10 + 0x18))(uVar5,puVar12);
          piVar13 = DAT_00b5aa1c;
          bVar10 = (byte)((uint)puVar12 >> 0x18);
          if (cVar1 == '\0') {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            uStack_130 = uStack_130 & 0xffffff00;
            iVar3 = *piVar13;
            uVar7 = FUN_0044a580(&uStack_130,s_UserName____s__Converter_FAIL_009a90dc,uVar7);
            (**(code **)(iVar3 + 4))(uVar7);
            (**(code **)(*DAT_00b5a69c + 8))(uVar5);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          (**(code **)(*DAT_00b5a69c + 8))(uVar5);
          puStack_15c = (undefined4 *)((int)puStack_15c + 0xf);
          (**(code **)(*piVar2 + 4))(1,0xc);
          uVar5 = bVar10 / 0x32;
          bVar10 = bVar10 + (char)uVar5 * -0x32;
          uStack_160 = (char *)CONCAT31(CONCAT12(uStack_160._3_1_,CONCAT11(bVar10 / 10,bVar10 % 10))
                                        ,(char)uVar5);
          piVar6 = (int *)(**(code **)(*piStack_154 + 0x28))(&uStack_160);
          piVar13 = DAT_00b5aa1c;
          if (piVar6 == (int *)0x0) {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            uStack_140 = (uint *)((uint)uStack_140 & 0xffffff00);
            puStack_15c = (undefined4 *)*piVar13;
            uVar7 = FUN_0044a580(&uStack_140,s_UserName____s__Not_Exist____BagL_009a9100,uVar7,uVar5
                                 ,uVar11 >> 0x10 & 0xff,uVar11 >> 8 & 0xff);
            (**(code **)((int)puStack_15c + 4))(uVar7);
          }
          else {
            psVar8 = (short *)(**(code **)(*piVar6 + 0x14))();
            if ((short)puVar14 != *psVar8) {
              piVar13 = DAT_00b5aa1c;
              uVar7 = (**(code **)(*param_1 + 0x70))();
              uStack_140 = (uint *)((uint)uStack_140 & 0xffffff00);
              puVar9 = (undefined2 *)(**(code **)(*piVar6 + 0x14))();
              iVar3 = *piVar13;
              uVar7 = FUN_0044a580(&uStack_140,s_UserName____s__Not_SameIndex_____009a9158,uVar7,
                                   (uint)puVar14 & 0xffff,*puVar9,uVar5,uVar11 >> 0x10 & 0xff,
                                   uVar11 >> 8 & 0xff);
              (**(code **)(iVar3 + 4))(uVar7);
              (**(code **)(*DAT_00b5a69c + 8))(piVar2);
              return 0;
            }
            (**(code **)(*piVar6 + 0x78))(&puStack_14c);
          }
        } while (uVar4 != uStack_134);
      }
      piStack_158 = (int *)0x48f7ee;
      piStack_154 = piVar2;
      (**(code **)(*DAT_00b5a69c + 8))();
      return 1;
    }
    piStack_154 = (int *)0x48f5dd;
    piStack_154 = (int *)(**(code **)(*param_1 + 0x70))();
    puStack_15c = (undefined4 *)auStack_10c;
    piStack_158 = (int *)s_UserName____s__Load_BagLimit__wC_009a8f10;
    auStack_10c[0] = 0;
    iVar3 = *piVar13;
    uStack_160 = (char *)0x48f5f4;
    piStack_154 = (int *)FUN_0044a580();
    piStack_158 = (int *)0x48f5fd;
    (**(code **)(iVar3 + 4))();
    piStack_158 = (int *)s_Load_BagLimit___wConvertSize_>_r_009a8f50;
  }
  else {
    piStack_154 = (int *)0x48f590;
    piStack_154 = (int *)(**(code **)(*param_1 + 0x70))();
    puStack_15c = (undefined4 *)auStack_10c;
    piStack_158 = (int *)s_UserName____s__Load_BagLimit___p_009a8e98;
    auStack_10c[0] = 0;
    iVar3 = *piVar13;
    uStack_160 = (char *)0x48f5a7;
    piStack_154 = (int *)FUN_0044a580();
    piStack_158 = (int *)0x48f5b0;
    (**(code **)(iVar3 + 4))();
    piStack_158 = (int *)s_Load_BagLimit___pReader_>READ__T_009a8edc;
  }
  uStack_160 = auStack_110;
  puStack_15c = (undefined4 *)&DAT_009a91a8;
  FUN_0044a580();
  FUN_00797b80(auStack_110);
  puStack_15c = (undefined4 *)0x48f62a;
  piStack_158 = piVar2;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 0;
}


// ==== FUN_0048fa00 @ 0x0048fa00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048fa00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a91b0;
  _DAT_00b5aaa0 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0048fae0 @ 0x0048fae0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048fae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a97fc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aad0 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aad0 = in_ECX;
  return;
}


// ==== FUN_0048fb30 @ 0x0048fb30 ====

undefined4 FUN_0048fb30(uint *param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  undefined4 unaff_EBP;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  byte bVar11;
  undefined4 uStack_660;
  int **ppiStack_65c;
  undefined1 *puStack_658;
  int *piStack_654;
  int *piStack_650;
  int *piStack_64c;
  undefined4 uStack_648;
  undefined4 uStack_63c;
  uint uVar12;
  undefined1 auStack_62e [14];
  int iStack_620;
  uint uStack_61c;
  uint uStack_618;
  int *piStack_610;
  undefined1 auStack_60c [4];
  undefined1 auStack_608 [4];
  undefined1 auStack_604 [200];
  undefined1 auStack_53c [20];
  undefined1 auStack_528 [4];
  undefined1 auStack_524 [4];
  undefined1 auStack_520 [4];
  undefined1 auStack_51c [4];
  undefined1 auStack_518 [4];
  undefined1 auStack_514 [208];
  undefined1 auStack_444 [252];
  undefined1 auStack_348 [268];
  undefined1 auStack_23c [256];
  undefined1 auStack_13c [316];
  
  uStack_63c = param_1;
  piVar3 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  piVar8 = DAT_00b5aa1c;
  piStack_610 = piVar3;
  if (piVar3 == (int *)0x0) {
    (**(code **)(*param_1 + 0x70))();
    uStack_648 = (int *)auStack_604;
    auStack_604[0] = 0;
    iVar4 = *piVar8;
    piStack_64c = (int *)0x48fb7e;
    FUN_0044a580();
    (**(code **)(iVar4 + 4))();
    piStack_64c = (int *)auStack_608;
    uStack_648 = (int *)&DAT_009a97f4;
    piStack_650 = (int *)0x48fb9b;
    FUN_0044a580();
    piStack_650 = (int *)auStack_608;
    piStack_654 = (int *)0x48fba5;
    FUN_00797b80();
    return 0;
  }
  uStack_618 = param_1[0xd];
  if (uStack_618 == 0) {
    uStack_648 = (int *)0x48fbd7;
    uStack_648 = (int *)(**(code **)(*param_1 + 0x70))();
    piStack_650 = (int *)auStack_604;
    piStack_64c = (int *)s_UserName____s__Store__LoadPC___p_009a9210;
    auStack_604[0] = 0;
    iVar4 = *piVar8;
    piStack_654 = (int *)0x48fbee;
    uStack_648 = (int *)FUN_0044a580();
    piStack_64c = (int *)0x48fbf7;
    (**(code **)(iVar4 + 4))();
    piStack_64c = (int *)s_Store__LoadPC___pStore_is_NULL_009a9240;
    piStack_654 = (int *)auStack_608;
    piStack_650 = (int *)&DAT_009a97f4;
    puStack_658 = (undefined1 *)0x48fc0b;
    FUN_0044a580();
    puStack_658 = auStack_608;
    ppiStack_65c = (int **)0x48fc15;
    FUN_00797b80();
    piStack_650 = (int *)0x48fc24;
    piStack_64c = piVar3;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  uStack_648 = &iStack_620;
  piStack_64c = (int *)0x2;
  piStack_650 = (int *)0x48fc41;
  iVar4 = (**(code **)(*piVar3 + 8))();
  piVar8 = DAT_00b5aa1c;
  if (iVar4 == 2) {
    uStack_61c = (uint)CONCAT11(auStack_62e[6],auStack_62e[7]);
    if (uStack_61c <= *param_1) {
      uVar12 = 2;
      if (uStack_61c != 2) {
        do {
          piStack_650 = (int *)((int)&uStack_63c + 2);
          piStack_654 = (int *)0x1;
          puStack_658 = (undefined1 *)0x48fd1e;
          iVar4 = (**(code **)(*piVar3 + 8))();
          piVar8 = DAT_00b5aa1c;
          if (iVar4 != 1) {
            puStack_658 = (undefined1 *)0x49009f;
            puStack_658 = (undefined1 *)(**(code **)(*param_1 + 0x70))();
            uStack_660 = (int **)auStack_514;
            ppiStack_65c = (int **)s_UserName____s__Store__LoadPC___p_009a934c;
            auStack_514[0] = 0;
            iVar4 = *piVar8;
            puStack_658 = (undefined1 *)FUN_0044a580();
            ppiStack_65c = (int **)0x4900c5;
            (**(code **)(iVar4 + 4))();
            ppiStack_65c = (int **)s_Store__LoadPC___pReader_>READ__s_009a9388;
            uStack_660 = (int **)0x4900d6;
            FUN_0044a670();
            ppiStack_65c = (int **)auStack_518;
            uStack_660 = (int **)0x4900e3;
            FUN_00797b80();
            uStack_660 = (int **)0x4900f2;
            ppiStack_65c = (int **)piVar3;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          if ((byte)((uint)unaff_EBP >> 0x10) < 6) {
            puStack_658 = (undefined1 *)0x49010f;
            puStack_658 = (undefined1 *)(**(code **)(*param_1 + 0x70))();
            uStack_660 = (int **)auStack_514;
            ppiStack_65c = (int **)s_UserName____s__Store__LoadPC___s_009a93b4;
            auStack_514[0] = 0;
            iVar4 = *piVar8;
            puStack_658 = (undefined1 *)FUN_0044a580();
            ppiStack_65c = (int **)0x490135;
            (**(code **)(iVar4 + 4))();
            ppiStack_65c = (int **)s_Store__LoadPC___size_<__6_009a93e0;
            uStack_660 = (int **)0x490146;
            FUN_0044a670();
            ppiStack_65c = (int **)auStack_518;
            uStack_660 = (int **)0x490153;
            FUN_00797b80();
            uStack_660 = (int **)0x490162;
            ppiStack_65c = (int **)piVar3;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          puStack_658 = auStack_62e + -0x13;
          ppiStack_65c = (int **)0x1;
          uStack_660 = (int **)0x48fd40;
          iVar4 = (**(code **)(*piVar3 + 8))();
          piVar8 = DAT_00b5aa1c;
          if (iVar4 != 1) {
            uStack_660 = (int **)0x49017f;
            uStack_660 = (int **)(**(code **)(*param_1 + 0x70))();
            auStack_51c[0] = 0;
            iVar4 = *piVar8;
            uStack_660 = (int **)FUN_0044a580(auStack_51c,
                                              s_UserName____s__Store__LoadPC___p_009a93fc);
            (**(code **)(iVar4 + 4))();
            FUN_0044a670(s_Store__LoadPC___pReader_>READ__p_009a943c);
            FUN_00797b80(auStack_520);
            (**(code **)(*DAT_00b5a69c + 8))(piVar3);
            return 0;
          }
          uStack_660 = (int **)(auStack_62e + -6);
          iVar4 = (**(code **)(*piVar3 + 8))(4);
          piVar8 = DAT_00b5aa1c;
          if (iVar4 != 4) {
            uVar6 = (**(code **)(*param_1 + 0x70))();
            auStack_524[0] = 0;
            iVar4 = *piVar8;
            uVar6 = FUN_0044a580(auStack_524,s_UserName____s__Store__LoadPC___p_009a946c,uVar6);
            (**(code **)(iVar4 + 4))(uVar6);
            FUN_0044a670(s_Store__LoadPC___pReader_>READ__d_009a94ac);
            FUN_00797b80(auStack_528);
            (**(code **)(*DAT_00b5a69c + 8))(piVar3);
            return 0;
          }
          (**(code **)(*piVar3 + 4))(1,0);
          bVar11 = 0;
          piVar5 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
          puVar9 = &uStack_63c;
          cVar2 = (**(code **)(*piVar5 + 0xc))(puVar9);
          piVar8 = DAT_00b5aa1c;
          if (cVar2 == '\0') {
            uVar6 = (**(code **)(*param_1 + 0x70))();
            iVar4 = *piVar8;
            uVar6 = FUN_0044a580(auStack_62e + -10,s_UserName____s__Store__LoadPC___I_009a94dc,uVar6
                                );
            (**(code **)(iVar4 + 4))(uVar6);
            auStack_23c[0] = 0;
            uVar6 = FUN_0044a580(auStack_23c,s_Store__LoadPC___Item_Open_Fail_009a950c);
            FUN_00797b80(uVar6);
LAB_0049003f:
            (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar5);
          }
          else {
            piVar8 = piVar5;
            cVar2 = (**(code **)(*DAT_00b5a734 + 0x38))(piVar5);
            if (cVar2 == '\0') {
              puVar7 = (undefined2 *)(**(code **)(*piVar5 + 0x14))();
              piVar3 = DAT_00b5aa1c;
              uVar6 = (**(code **)(*param_1 + 0x70))();
              auStack_13c[0] = 0;
              iVar4 = *piVar3;
              uVar6 = FUN_0044a580(auStack_13c,s__ITEM__InvalidItem___index__u__U_009a9530,*puVar7,
                                   uVar6,*(undefined1 *)((int)puVar7 + 0x21),puVar7[6],
                                   *(undefined1 *)((int)puVar7 + 0x1f),*(undefined1 *)(puVar7 + 0xf)
                                   ,puVar7[7],*(undefined1 *)(puVar7 + 8),puVar7[9],
                                   *(undefined1 *)(puVar7 + 10),puVar7[0xb],
                                   *(undefined1 *)(puVar7 + 0xc),puVar7[0xd],
                                   *(undefined1 *)(puVar7 + 0xe),puVar7[2],puVar7[3],puVar7[4],
                                   puVar7[5]);
              (**(code **)(iVar4 + 0xc))(uVar6);
              (**(code **)(*DAT_00b5a734 + 0x3c))(piVar5);
              piVar3 = DAT_00b5aa1c;
              uVar6 = (**(code **)(*param_1 + 0x70))();
              auStack_444[0] = 0;
              iVar4 = *piVar3;
              uVar6 = FUN_0044a580(auStack_444,s__ITEM__RevisedItem___index__u__U_009a95d8,*puVar7,
                                   uVar6,*(undefined1 *)((int)puVar7 + 0x21),puVar7[6],
                                   *(undefined1 *)((int)puVar7 + 0x1f),*(undefined1 *)(puVar7 + 0xf)
                                   ,puVar7[7],*(undefined1 *)(puVar7 + 8),puVar7[9],
                                   *(undefined1 *)(puVar7 + 10),puVar7[0xb],
                                   *(undefined1 *)(puVar7 + 0xc),puVar7[0xd],
                                   *(undefined1 *)(puVar7 + 0xe),puVar7[2],puVar7[3],puVar7[4],
                                   puVar7[5]);
              (**(code **)(iVar4 + 0xc))(uVar6);
              bVar11 = (byte)((uint)iVar4 >> 0x18);
              piVar3 = uStack_648;
            }
            (**(code **)(*piVar5 + 0x68))
                      (CONCAT31((int3)piStack_654,(char)((uint)piStack_654 >> 8)) << 0x10 |
                       ((uint)piStack_654 >> 0x10 & 0xff) << 8 | (uint)piStack_654 >> 0x18);
            uStack_660 = (int **)CONCAT22(CONCAT11(uStack_660._3_1_,(bVar11 % 0x32) / 10),
                                          CONCAT11((bVar11 % 0x32) % 10,bVar11 / 0x32));
            cVar2 = (**(code **)(*piStack_654 + 0x1c))(&uStack_660,piVar5);
            piVar1 = DAT_00b5aa1c;
            if (cVar2 == '\0') {
              piVar10 = DAT_00b5aa1c;
              uVar6 = (**(code **)(*param_1 + 0x70))();
              auStack_348[0] = 0;
              iVar4 = *piVar1;
              uVar6 = FUN_0044a580(auStack_348,s_UserName____s__Store__LoadPC___P_009a967c,uVar6);
              (**(code **)(iVar4 + 4))(uVar6);
              auStack_53c[0] = 0;
              uVar6 = FUN_0044a580(auStack_53c,s_Store__LoadPC___PutItem_fail_009a96ac,piVar8,puVar9
                                   ,piVar10);
              FUN_00797b80(uVar6);
              FUN_00498050(1,param_1,piVar5,uStack_660);
              goto LAB_0049003f;
            }
          }
          (**(code **)(*piVar3 + 4))(1,((uint)puVar9 >> 0x10 & 0xff) - 6);
          uVar12 = uVar12 + ((uint)uStack_63c >> 0x10 & 0xff);
        } while (uStack_61c != uVar12);
      }
      piStack_654 = (int *)0x490082;
      piStack_650 = piVar3;
      (**(code **)(*DAT_00b5a69c + 8))();
      return 1;
    }
    piStack_650 = (int *)0x48fca1;
    piStack_650 = (int *)(**(code **)(*param_1 + 0x70))();
    puStack_658 = auStack_60c;
    piStack_654 = (int *)s_UserName____s__Store__LoadPC___w_009a92d8;
    auStack_60c[0] = 0;
    iVar4 = *piVar8;
    ppiStack_65c = (int **)0x48fcb8;
    piStack_650 = (int *)FUN_0044a580();
    piStack_654 = (int *)0x48fcc1;
    (**(code **)(iVar4 + 4))();
    piStack_654 = (int *)s_Store__LoadPC___wConvertSize_>_r_009a9318;
  }
  else {
    piStack_650 = (int *)0x48fc54;
    piStack_650 = (int *)(**(code **)(*param_1 + 0x70))();
    puStack_658 = auStack_60c;
    piStack_654 = (int *)s_UserName____s__Store__LoadPC___R_009a9260;
    auStack_60c[0] = 0;
    iVar4 = *piVar8;
    ppiStack_65c = (int **)0x48fc6b;
    piStack_650 = (int *)FUN_0044a580();
    piStack_654 = (int *)0x48fc74;
    (**(code **)(iVar4 + 4))();
    piStack_654 = (int *)s_Store__LoadPC___Reader_>READ___T_009a92a0;
  }
  ppiStack_65c = &piStack_610;
  puStack_658 = &DAT_009a97f4;
  uStack_660 = (int **)0x48fcd5;
  FUN_0044a580();
  uStack_660 = &piStack_610;
  FUN_00797b80();
  puStack_658 = (undefined1 *)0x48fcee;
  piStack_654 = piVar3;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 0;
}


