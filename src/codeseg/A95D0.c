#include "common.h"

typedef struct UnkStruct_801DB024 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} UnkStruct_801DB024;

typedef struct UnkStruct_801DB0E4_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC[3];
    f32 unk14[3];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
} UnkStruct_801DB0E4_arg0;

typedef struct UnkStruct_801DB0E4_arg1 {
    f32 unk0[3];
    f32 unk4[3];
    f32 unk18;
    s32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
} UnkStruct_801DB0E4_arg1;

typedef struct UnkStruct_801DBF68_s0 {
    s32 unk0;
    s32 unk4;
    struct UnkStruct_801DB0E4_arg1* unk8;
    s8 pad[0x1C];
} UnkStruct_801DBF68_s0;

typedef struct UnkStruct_801DBF68 {
    UnkStruct_801DBF68_s0 unk0[4];
} UnkStruct_801DBF68;

extern struct UnkStruct_801DBF68 D_80225CF4;

void func_800AB92C(void);

#define ANG_NORMALIZE_1(x) (x < 0.0f ? 360.0f : 0.0f)
#define ANG_NORMALIZE_2(x) (x > 360.0f ? -360.0f : 0.0f)

#define SIGNF(x) (x >= 0 ? 1.0f : -1.0f)

extern s32 D_80228110;
extern struct UnkStruct_801DB0E4_arg0 D_80228190;
extern s32 D_802287A8;
extern s32 D_802287AC;

typedef struct UnkStruct_801DF008 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
} UnkStruct_801DF008;

typedef struct UnkStruct_801DF5F0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
} UnkStruct_801DF5F0;
void func_801DEA94(s32* arg0, s32 arg1);

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DEA94.s")

void func_801DEB08(void* arg0, void* arg1, void* arg2);
void func_801DEC00(void* arg0, void* arg1, void* arg2);
void func_801DEEC4(void);
void func_801DEF84(void);
void func_801DF008(UnkStruct_801DF008* dest, UnkStruct_801DF008* src, s32 count);
void func_801DF08C(s32 arg0, s32* arg1, s32* arg2, s32* arg3, s32* arg4);
void func_801DF128(void);
void func_801DF1F8(void);
void func_801DF278(s32* dest, s32 val, s32* src, s32 count);
void func_801DF2F8(s32* dest, s32* src1, s32* src2, s32* src3, s32* src4);
void func_801DF38C(void);
void func_801DF578(void);
void func_801DF5F0(UnkStruct_801DF5F0* dest, UnkStruct_801DF5F0* src, s32 count);
void func_801DF668(void);
void func_801DF744(void);
void func_801DFCB8(void);
void func_801DFE80(void);
void func_801E0304(void);
void func_801E0454(void);
void func_801E05A4(void);
void func_801E06F8(void);
void func_801E084C(void);
void func_801E0A18(void);
void func_801E0BE8(void);
void func_801E0DB8(void);
void func_801E0FF0(void);
void func_801E11B4(void);

// TODO: Improve these matches
void func_801DAFA0(void** arg0, s32 arg1) {
    *(f32*) (((u8*) (*arg0)) + 0x50) = 3.0f;
}

void func_801DAFB8(void* arg0) {
    u32 randVal;
    u32 result;
    void* savedArg0 = arg0;

    randVal = SysUtils_Rand();
    if ((randVal & 7) != 0) {
        result = SysUtils_Rand();
        *(u32*) ((u8*) savedArg0 + 8) = result % 15;
        return;
    }

    result = SysUtils_Rand();
    *(u32*) ((u8*) savedArg0 + 8) = (result % 19) + 0x19;
}

void func_801DB024(struct UnkStruct_801DB0E4_arg0* arg0) {
    if ((arg0->unk8 >= 0) && (((arg0->unk8 < 0x10)))) {
        arg0->unk8 += 2;
        if (arg0->unk8 >= 0x10) {
            if (SysUtils_Rand() & 7) {
                arg0->unk8 = 0;
            } else {
                arg0->unk8 = 0x10;
            }
        }
    } else {
        if ((arg0->unk8 >= 0x19) && (((arg0->unk8 < 0x2D)))) {
            arg0->unk8++;
            if (arg0->unk8 >= 0x2D) {
                if (SysUtils_Rand() & 0xF) {
                    arg0->unk8 = 0x2D;
                    return;
                }
                arg0->unk8 = 0x19;
            }
        } else {
            arg0->unk8++;
            if (arg0->unk8 >= 0x37) {
                arg0->unk8 = 0;
            }
        }
    }
}

void func_801DB0E4(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, s32* arg2) {
    f32 vec[3];
    f32 magnitud;
    s32 i;

    arg0->unk0 = 3;
    arg0->unk4 = 0;

    func_801DAFB8(arg0);

    for (i = 0; i < 3; i++) {
        arg0->unkC[i] = arg1->unk0[i];
        vec[i] = arg1->unk4[i] - arg1->unk0[i];
    }

    magnitud = sqrtf(SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]));

    for (i = 0; i < 3; i++) {
        arg0->unk14[i] = vec[i] / magnitud;
    }

    arg0->unk24 = 0.0f;
    arg0->unk28 = 1.0f;
    arg0->unk2C = 0.0f;
    arg0->unk30 = 0.1f;

    *arg2 = arg1->unk1C;
}

void func_801DB1DC(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, s32* arg2) {
    s32 i;

    func_801DB024(arg0);

    if (*arg2 > 0) {
        for (i = 0; i < 3; i++) {
            arg0->unkC[i] += arg0->unk14[i] * arg1->unk18;
        }
        return;
    }

    arg0->unk0 = 0;
}

void func_801DB284(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, f32 arg2[1][2],
                   s32 arg3) {
    s32 var_s1;
    s32 var_s6;

    for (var_s6 = 0; var_s6 < arg3; var_s6++, arg0++) {
        arg0->unk0 = 3;
        arg0->unk4 = 0;

        func_801DAFB8(arg0);

        for (var_s1 = 0; var_s1 < 3; var_s1++) {
            arg0->unkC[var_s1] = ((arg1->unk0[var_s1] + arg1->unk4[var_s1]) - (arg1->unk4[var_s1 + 3] * 0.5f)) +
                                 (((f32) (SysUtils_Rand() % 256) / 256) * arg1->unk4[var_s1 + 3]);
        }

        arg0->unk30 = 0.1f;
        arg2[var_s6][0] = SysUtils_Rand() % 360;
        arg2[var_s6][1] = SysUtils_Rand() % 360;
    }
}

void func_801DB430(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, f32 arg2[1][2],
                   s32 arg3) {
    f32 magnitude; // f20
    s32 i;
    f32 vec[3];
    s32 j;

    for (i = 0; i < arg3; i++, arg0++) {
        func_801DB024(arg0);
        vec[0] = COS((s32) ((arg2[i][0] * 4096.0f) / 360.0f));
        vec[2] = SIN((s32) ((arg2[i][0] * 4096.0f) / 360.0f));
        vec[1] =
            (SIN((s32) ((arg2[i][1] * 4096.0f) / 360.0f)) * arg1->unk30) * (1.0f - ((SysUtils_Rand() & 3) / 20.0f));

        if (vec[1] * ((arg1->unk0[1] - arg0->unkC[1])) > 0) {
            vec[1] *= 1.2f;
        }

        magnitude = sqrtf(SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]));

        for (j = 0; j < 3; j++) {
            arg0->unk14[j] = vec[j] / magnitude;
            arg0->unkC[j] += arg0->unk14[j] * (arg1->unk24 + (f32) (SysUtils_Rand() & 1));
        }

        vec[0] = arg1->unk0[0] - arg0->unkC[0];

        vec[2] = arg1->unk0[2] - arg0->unkC[2];

        magnitude = sqrtf(SQ(vec[0]) + SQ(vec[2]));

        if (magnitude > 0.0f) {
            magnitude = 1 / magnitude;
        }

        vec[0] *= magnitude * 3.0f;
        vec[2] *= magnitude * 3.0f;
        vec[1] = arg1->unk24 / arg1->unk28;

        magnitude = sqrtf(SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]));

        arg0->unk24 = vec[0] / magnitude;
        arg0->unk28 = vec[1] / magnitude;
        arg0->unk2C = vec[2] / magnitude;

        magnitude = (arg0->unk14[0] * vec[2]) - (arg0->unk14[2] * vec[0]);

        arg2[i][0] += (SIGNF(magnitude) * (arg1->unk28 + (SysUtils_Rand() % 31U * 0.125f)));
        arg2[i][0] += ANG_NORMALIZE_2(arg2[i][0]) + ANG_NORMALIZE_1(arg2[i][0]);
        arg2[i][1] += ((arg1->unk2C * (0.9f + ((f32) (SysUtils_Rand() & 3) / 20.0f))));
        arg2[i][1] += ANG_NORMALIZE_2(arg2[i][1]);
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DB8F0.s")

void func_801DBF68(struct UnkStruct_801DB0E4_arg0* arg0) {
    s32 var_s2;
    UnkStruct_801DBF68 sp4C = D_80225CF4;
    s32 i;

    if (arg0->unk8 == 0) {
        func_800AB92C();
    }

    for (var_s2 = 0; var_s2 < D_802287AC; var_s2++) {
        if ((arg0->unk8 >= sp4C.unk0[var_s2].unk0) && (arg0->unk8 < sp4C.unk0[var_s2].unk4)) {
            D_802287A8 = 1;

            if (arg0->unk8 == sp4C.unk0[var_s2].unk0) {
                func_801DB0E4(&D_80228190, (UnkStruct_801DB0E4_arg1*) &sp4C.unk0[var_s2].unk8, &D_80228110);
            }
            func_801DB1DC(&D_80228190, (UnkStruct_801DB0E4_arg1*) &sp4C.unk0[var_s2].unk8, &D_80228110);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC0AC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC274.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC404.s")

extern s32 D_80223F7C;

void func_800AB95C(s32, s32);

void func_801DC5A8(void* arg0) {
    s32 index = (*(s32*)((s8*)arg0 + 4) - (s32)&D_80223F7C) / 0xC;
    if (index == 2) {
        if (*(s32*)((s8*)arg0 + 8) == 1) {
            func_800AB92C();
            func_800AB95C(1, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC60C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DCD34.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DD2D0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DD6B4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DD85C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DDA24.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DDAB8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DDE48.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DDEDC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DE3CC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DE690.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DEB08.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DEC00.s")

void func_801DED44(void* arg0, void* arg1, void* arg2) {
    func_801DEC00(arg0, arg1, arg2);
    func_801DEC00((s8*) arg0 + 0xC, (s8*) arg1 + 0x8, (s8*) arg2 + 0x14);
}

void func_801DED88(void* arg0, void* arg1, void* arg2) {
    func_801DEC00(arg0, arg1, arg2);
    func_801DEC00((s8*) arg0 + 0xC, (s8*) arg1 + 0x8, (s8*) arg2 + 0x14);
    func_801DEC00((s8*) arg0 + 0x18, (s8*) arg1 + 0x10, (s8*) arg2 + 0x28);
}

void func_801DEDE8(void* arg0, void* arg1, void* arg2) {
    func_801DEC00(arg0, arg1, arg2);
    func_801DEC00((s8*) arg0 + 0xC, (s8*) arg1 + 0x8, (s8*) arg2 + 0x14);
    func_801DEB08((s8*) arg0 + 0x18, (s8*) arg1 + 0x10, (s8*) arg2 + 0x28);
}

void func_801DEE48(void* arg0, void* arg1, void* arg2) {
    func_801DEC00(arg0, arg1, arg2);
    func_801DEC00((s8*) arg0 + 0xC, (s8*) arg1 + 0x8, (s8*) arg2 + 0x14);
    func_801DEC00((s8*) arg0 + 0x18, (s8*) arg1 + 0x10, (s8*) arg2 + 0x28);
    func_801DEB08((s8*) arg0 + 0x24, (s8*) arg1 + 0x18, (s8*) arg2 + 0x3C);
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DEEC4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DEF84.s")

void func_801DF008(UnkStruct_801DF008* dest, UnkStruct_801DF008* src, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        ((s32*)dest)[i * 3 + 0] = ((s32*)src)[i * 3 + 0];
        ((s32*)dest)[i * 3 + 1] = ((s32*)src)[i * 3 + 1];
        ((s32*)dest)[i * 3 + 2] = ((s32*)src)[i * 3 + 2];
    }
    // Copy 7 additional fields at offsets 0x58..0x74
    for (i = 0; i < 7; i++) {
        ((s32*)dest)[7 + i] = ((s32*)src)[7 + i];
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF08C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF128.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF1F8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF278.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF2F8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF38C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF578.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF5F0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF668.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF744.s")

void func_801DF128(void);
void func_801DF38C(void);
void func_801DF744(void);

void func_801DFC48(void* arg0) {
    switch (*(s32*)arg0) {
        case 1:
            func_801DF128();
            break;
        case 2:
        case 3:
            func_801DF38C();
            break;
        case 5:
            func_801DF744();
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DFCB8.s")

void func_801DFD8C(void* arg0, s32 arg1) {
    *(s32*) arg0 = arg1;
}

void func_801DFD94(void* arg0, s32 arg1) {
    *(s32*) ((s8*) arg0 + 4) = arg1;
    *(s32*) ((s8*) arg0 + 8) = 0;
}

void func_801DFDA0(void* arg0, s32 arg1) {
    *(s32*) ((s8*) arg0 + 0xC) = arg1;
}

void func_801DFDA8(void* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    *(s32*) ((s8*) arg0 + 0x10) = arg1;
    *(s32*) ((s8*) arg0 + 0x14) = arg2;
    *(s32*) ((s8*) arg0 + 0x18) = arg3;
    *(s32*) ((s8*) arg0 + 0x1C) = arg4;
    *(s32*) ((s8*) arg0 + 0x20) = arg5;
    *(s32*) ((s8*) arg0 + 0x24) = arg6;
    *(s32*) ((s8*) arg0 + 0x28) = arg7;
    *(s32*) ((s8*) arg0 + 0x2C) = arg8;
    *(s32*) ((s8*) arg0 + 0x30) = arg9;
    *(s32*) ((s8*) arg0 + 0x34) = argA;
}

void func_801DFDF0(void* arg0) {
    func_801DEA94((s32*)(*(s32*)((s8*)arg0 + 0xC)), 0);
}

void func_801DFE10(void* arg0) {
    func_801DF008((UnkStruct_801DF008*)(*(s32*)arg0), (UnkStruct_801DF008*)(*(s32*)((s8*)arg0 + 4)), (*(s32*)((s8*)arg0 + 8)));
}

void func_801DFE30(void* arg0, s32 arg1) {
    func_801DF278((s32*)(*(s32*)arg0), 2, (s32*)(*(s32*)((s8*)arg0 + 4)), (*(s32*)((s8*)arg0 + 8)));
}

void func_801DFE58(void* arg0, s32 arg1) {
    func_801DF278((s32*)(*(s32*)arg0), 3, (s32*)(*(s32*)((s8*)arg0 + 4)), (*(s32*)((s8*)arg0 + 8)));
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DFE80.s")

void func_801DFF5C(void* arg0, s32 arg1) {
    s32 buf[6];
    func_801DED44(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF08C(*(s32*)arg0, buf, buf + 3, 0, 0);
}

void func_801DFFA8(void* arg0, s32 arg1) {
    s32 buf[9];
    func_801DED88(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF08C(*(s32*)arg0, buf, buf + 3, buf + 6, 0);
}

void func_801DFFF4(void* arg0, s32 arg1) {
    s32 buf[7];
    func_801DEDE8(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF08C(*(s32*)arg0, buf, buf + 3, 0, buf + 6);
}

void func_801E0044(void* arg0, s32 arg1) {
    s32 buf[10];
    func_801DEE48(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF08C(*(s32*)arg0, buf, buf + 3, buf + 6, buf + 9);
}

void func_801E0094(void* arg0, s32 arg1) {
    s32 buf[6];
    func_801DED44(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF2F8(*(s32*)arg0, buf, buf + 3, 0, 0);
}

void func_801E00E0(void* arg0, s32 arg1) {
    s32 buf[9];
    func_801DED88(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF2F8(*(s32*)arg0, buf, buf + 3, buf + 6, 0);
}

void func_801E012C(void* arg0, s32 arg1) {
    s32 buf[7];
    func_801DEDE8(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF2F8(*(s32*)arg0, buf, buf + 3, 0, buf + 6);
}

void func_801E017C(void* arg0, s32 arg1) {
    s32 buf[10];
    func_801DEE48(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF2F8(*(s32*)arg0, buf, buf + 3, buf + 6, buf + 9);
}

void func_801E01CC(void* arg0, s32 arg1) {
    s32 buf[6];
    func_801DED44(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF2F8(*(s32*)arg0, buf + 3, buf, 0, 0);
}

void func_801E0218(void* arg0, s32 arg1) {
    s32 buf[9];
    func_801DED88(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF2F8(*(s32*)arg0, buf + 3, buf, buf + 6, 0);
}

void func_801E0264(void* arg0, s32 arg1) {
    s32 buf[7];
    func_801DEDE8(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF2F8(*(s32*)arg0, buf + 3, buf, 0, buf + 6);
}

void func_801E02B4(void* arg0, s32 arg1) {
    s32 buf[10];
    func_801DEE48(buf, *(void**)((s8*)arg0 + 0xC), (void*)arg1);
    func_801DF2F8(*(s32*)arg0, buf + 3, buf, buf + 6, buf + 9);
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0304.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0454.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E05A4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E06F8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E084C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0A18.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0BE8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0DB8.s")

void func_801E0F8C(void* arg0, void* arg1) {
    *(f32*)((s8*)arg0 + 0x4C) = *(f32*)((s8*)arg1 + 0x10);
    *(f32*)((s8*)arg0 + 0x50) = *(f32*)((s8*)arg1 + 0x14);
    *(f32*)((s8*)arg0 + 0x54) = *(f32*)((s8*)arg1 + 0x18);
    *(f32*)((s8*)arg0 + 0x7C) = *(f32*)((s8*)arg1 + 0x04);
    *(f32*)((s8*)arg0 + 0x80) = *(f32*)((s8*)arg1 + 0x08);
    *(f32*)((s8*)arg0 + 0x84) = *(f32*)((s8*)arg1 + 0x0C);
    *(f32*)((s8*)arg0 + 0x70) = *(f32*)((s8*)arg1 + 0x1C);
    *(f32*)((s8*)arg0 + 0x74) = *(f32*)((s8*)arg1 + 0x20);
    *(f32*)((s8*)arg0 + 0x78) = *(f32*)((s8*)arg1 + 0x24);
    *(f32*)((s8*)arg0 + 0x88) = *(f32*)((s8*)arg1 + 0x38);
    *(f32*)((s8*)arg0 + 0x94) = *(f32*)((s8*)arg1 + 0x44);
    *(f32*)((s8*)arg0 + 0x98) = *(f32*)((s8*)arg1 + 0x48);
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0FF0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E11B4.s")
