#include "global.h"
#include "rider.h"

struct unk_D_801C3C60 {
    struct unk_D_801C3C58* unk0;
    char pad[0x4C];
    int unk5C;
    char pad1[0x94];
};

struct UnkStruct_801C2C70 {
    s32 unk0;
    char pad[0x374];
};

struct UnkStruct_801CB058 {
    char pad[0xC0];
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    char padCC[0x3C];
    f32 unk108;
};

void func_800890B4(void);

extern s32 D_800D48DC;
extern s32 D_801C26C0[];
extern struct unk_D_801C3C60 D_801C3C60[];
extern s32 D_801C4100[];
extern s32 D_800D476C;
extern s32 D_800D4770;
extern s8 D_800D9888;
extern s32 D_800D98CC;
extern s32 D_800D98D0;
extern s32 D_800D98D4;
extern u8 D_800E5150[2][4];
extern struct UnkStruct_801C2C70 D_801C2C70[];
extern struct UnkStruct_801CB058 D_801CB058;
extern UnkStruct_801BC940 D_801BC940[];
extern s32 D_801BFA40;
extern s32 D_801C4110;
extern s32 D_801C4118[];
extern u8 D_801C4698;
extern u8 D_801C46C8;
extern u8 D_801C4000;

void func_80088EA0(void) {
}

void func_80088EA8(void) {
    s32 var_s4;
    s32 var_s6;
    s32 rand_seed;

    for (var_s4 = 0; var_s4 < gRiders; var_s4++) {
        D_801C4100[D_801C26C0[var_s4]] = var_s4;
    }
    for (var_s4 = 0; var_s4 < gRiders; var_s4++) {
        D_801C3C58->unk60 = 1.0f;
    }
    for (var_s4 = 0; var_s4 < gRiders; var_s4++) {
        D_801C3C58 = (struct_801C3C58*) &D_801C3C60[var_s4];
        D_801C3C58->unk5C = -1;
    }
    for (var_s6 = var_s4 = 0; var_s4 < (gRiders - 1); var_s6++, var_s4++) {
        rand_seed = (SysUtils_Rand(), SysUtils_Rand() / 256) % 4;

        while (D_801C3C58 = (struct_801C3C58*) &D_801C3C60[rand_seed],
               D_801C3C58->unk5C != -1 || rand_seed == D_800D48DC) {
            rand_seed = (rand_seed % gRiders) + 1;
        }
        D_801C3C58->unk5C = var_s6;
    }
}

void func_800890B4(void) {
s32 i;
    s32 j;
struct unk_D_801C3C60* tmpc60;
    u8* base1;
    u8* base2;

    for (i = 0; 1; ) {
        D_801C3C50 = (struct UnkStruct_801C3C50*) &D_80192690[i];
        D_801C3C58 = (struct_801C3C58*) &D_801C3C60[i];
        D_801C3C58->unk0 = i;
        D_801C3C58->currentRider = D_801C3C50->unkB68;
        D_801C3C58->unk74 = 1;
        D_801C3C58->unk8C = 0;
        D_801C3C58->unkAC = 0;
        D_801C3C58->unkB0 = 0;
        D_801C3C58->unkB4 = 1;
        D_801C3C58->pad58 = 0;
        D_801C3C58->unkA0 = 0;
        D_801C3C58->unkD8 = 0;
        D_801C3C58->unkDC[0] = 0;
        switch (D_801C3C50->unkB64) {
            case 0:
            case 1:
            case 2:
                D_801C3C58->unk64 = 32.0f;
                break;
            case 3:
                D_801C3C58->unk64 = 24.0f;
                break;
        }
        if (++i < 4) {
            continue;
        }
        break;
    }
    func_80088EA8();

    tmpc60 = &D_801C3C60[0];
    do {
        D_801C3C58 = (struct_801C3C58*) tmpc60;
        for (j = 0; j < 3; j++) {
            D_801C3C58->unk80[j] = 0;
        }
        tmpc60++;
    } while ((u8*) tmpc60 < (u8*) &D_801C4000);

    for (i = 0; i < 3; i++) {
        if (((SysUtils_Rand(), SysUtils_Rand() / 256) % 4) != 0) {
            continue;
        }
        D_801C3C58 = (struct_801C3C58*) &D_801C3C60[((SysUtils_Rand(), SysUtils_Rand() / 256) % 4)];
        D_801C3C58->unk80[i] = 1;
    }

    *(struct_801C3C58**) 0x801C3C58 = (struct_801C3C58*) &D_801C3C60[3];
    for (i = 1; i != 3; i++) {
    }

    base1 = &D_801C4698;
    base2 = &D_801C46C8;
    do {
        for (i = 0; i < 3; i++) {
            u8* p = base1 + (i << 4);
            p[0xC] = 0xFF;
            p[0xD] = 0;
            p[0xE] = 0;
            p[0xF] = 0xFF;
        }
        for (i = 0; i < 4; i++) {
            u8* p = base2 + (i << 4);
            *(s16*) (p + 2) = 0;
            p[0xC] = 0xFF;
            p[0xD] = 0xFF;
            p[0xE] = 0xFF;
        }
        base2 += 0x3630;
        D_801C4110 = 0;
        for (i = 0; i < D_801BFA40; i++) {
            if (D_801BC940[i].unk4C == 1) {
                D_801C4118[D_801C4110] = i;
                D_801C4110++;
            }
        }
        base1 += 0x3630;
    } while (base2 != (u8*) &D_801CB328);
}

void func_800893A8(void) {
    func_800890B4();
    D_800D476C = D_801CB058.unkC4;
    D_800D4770 = D_801CB058.unkC8;
    if (gCourseID == DRAKE_LAKE) {
        D_800D9888 = 1;
        D_801CB058.unk108 = 0.0f;
    } else {
        D_800D9888 = 0;
    }
    switch (D_800E5150[gDifficulty][D_801C2C70[D_800D48DC].unk0]) {
        case 0x8F:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x90:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x91:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x92:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x93:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x316;
            D_800D98D4 = 0x33E;
            return;
        case 0x94:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x316;
            D_800D98D4 = 0x33E;
            return;
        case 0x95:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x316;
            D_800D98D4 = 0x33E;
        default:
            break;
    }
}
