#include "course.h"
#include "common.h"

Gfx* func_1C3D00_802C58DC(Gfx*);
void func_1C3D00_802C5D44(void);
void func_1C3D00_802C5E10(void);
Gfx* func_80093C44(Gfx*);

extern s16 D_80228A16;
extern s32 D_802C5EF0;
extern s32 D_801CB350[][4];
extern s32 D_1C3D00_802C5EB0[];
extern s32 D_1C3D00_802C5ED0[];
extern char D_1C3D00_802C5EE0[];
extern char D_1C3D00_802C5EE4[];
extern char D_1C3D00_802C5EE8[];
extern char D_1C3D00_802C5EEC[];

Gfx* func_1C3D00_802C5800(Gfx* gDisplayListHead) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x36) {
            D_802C5EF0 = 0;
            osViBlack(false);
            return func_80093C44(gDisplayListHead);
        }
    }
    D_800DAB2C = 0;
    gDisplayListHead =
        func_1C3D00_802C58DC(Draw_WaterEffects(func_800949B8(func_8008FB74(gDisplayListHead), gCourseID)));
    if (gGameState == 0x36) {
        if (D_80228A16 == 1) {
            func_800C30F8();
        }
        func_1C3D00_802C5D44();
    } else {
        func_1C3D00_802C5E10();
    }
    return gDisplayListHead;
}

Gfx* func_1C3D00_802C58DC(Gfx* gDisplayListHead) {
    s32 i;
    s32* scores;
    char buf[16];
    
    gDisplayListHead = func_80094338(gDisplayListHead, 0, 0x35, 0x26, 0xD6, 0x1A);
    gDisplayListHead = func_80094338(gDisplayListHead, 0, 0x49, 0x49, 0xAE, 0x10);
    gDisplayListHead = func_80094338(gDisplayListHead, 0, 0x49, 0x5A, 0xAE, 0x19);
    
    gDisplayListHead = func_801E946C(gDisplayListHead, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    gDisplayListHead = func_801E3EE0(gDisplayListHead, 2, 0x12, 0x46, 0x2A, 0);
    
    gDisplayListHead = func_801E9858(gDisplayListHead, 2, D_1C3D00_802C5EE0, 0x63, 0x4B);
    gDisplayListHead = func_801E9858(gDisplayListHead, 2, D_1C3D00_802C5EE4, 0xCA, 0x4B);
    gDisplayListHead = func_801E9858(gDisplayListHead, 2, D_1C3D00_802C5EE8, 0x99, 0x5F);
    gDisplayListHead = func_801E3EE0(gDisplayListHead, 0, 0x15, 0x90, 0x4D, 0);
    
    scores = &D_801CB350[10][0];
    
    sprintf(buf, D_1C3D00_802C5EEC, scores[0]);
    gDisplayListHead = func_801E9858(gDisplayListHead, 0, buf, 0xC1, 0x5C);
    
    for (i = 0; i < 4; i++) {
        s16 score = ((s16*)D_1C3D00_802C5EB0)[i * 4];
        
        if (i != D_802C5EF0) {
            gDisplayListHead = func_801E3EE0(gDisplayListHead, 1, score, score + 0x8A, 0x8F, 0);
        }
    }
    
    gDisplayListHead = func_801E946C(gDisplayListHead, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    
    sprintf(buf, D_1C3D00_802C5EEC, scores[D_802C5EF0]);
    gDisplayListHead = func_801E9858(gDisplayListHead, 1, buf, 0xC1, 0x5C);
    
    return gDisplayListHead;
}

void func_1C3D00_802C5C4C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x37;
    D_801CE638 = 0x12;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;

    FadeTransition_SetProps(5, 1, 0);

    if (D_801CE630 == 2) {
        func_800C1F60(0);
        return;
    }
    if (D_801CE630 == 0xA) {
        func_800C1F60(1);
        return;
    }
    if (D_801CE630 == 0x14) {
        func_800C1F60(0xA);
        return;
    }
    if (D_801CE630 == 0x28) {
        func_800C1F60(7);
    }
}

void func_1C3D00_802C5D44(void) {
    if (D_801CE692[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        func_1C3D00_802C5C4C(D_1C3D00_802C5ED0[D_802C5EF0]);
        func_800C37F4(0x11, 0);
        return;
    }

    if (D_801CE692[0].unk0 & U_JPAD) {
        D_802C5EF0--;
        if (D_802C5EF0 < 0) {
            D_802C5EF0 = 3;
        }
        func_800C37F4(0x10, 0);
        return;
    }

    if (D_801CE692[0].unk0 & D_JPAD) {
        D_802C5EF0++;
        if (D_802C5EF0 == 4) {
            D_802C5EF0 = 0;
        }
        func_800C37F4(0x10, 0);
    }
}

void func_1C3D00_802C5E10(void) {
    if (D_80228A16 == 1) {
        switch (D_801CE630) {
            case 2:
                func_801EB180();
                return;
            case 40:
                func_8009345C();
                return;
            case 10:
                func_801EBD28();
                return;
            case 20:
                func_801EBFE4();
                break;
        }
    }
}
