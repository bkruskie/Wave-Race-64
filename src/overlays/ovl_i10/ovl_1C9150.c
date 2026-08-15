#include "common.h"

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i10/ovl_1C9150/func_i10_802C5800.s")

Gfx* func_i10_802C5968(Gfx* gfxP) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 68) {
            return func_80093C44(gfxP);
        }
    }

    D_800DAB2C = 0;

    gfxP = func_i10_802C6200(gfxP);

    if (gGameState == 68) {
        func_i10_802C5A10();
    } else if (D_80228A16 == 1) {
        func_8007C50C();
        func_801EC304();
    }

    return gfxP;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i10/ovl_1C9150/func_i10_802C5A10.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i10/ovl_1C9150/func_i10_802C6200.s")

void func_i10_802C6A00(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x45;
    D_801CE638 = 0xE;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 4, 0);
    func_801E6A4C(0, 0);
}
