#include "common.h"

void func_i8_802C5800(void) {
}

void func_i8_802C5D3C(s32 arg0) {
    (void)arg0;
}

void func_i8_802C5EB8(void) {
}

void func_i8_802C63E4(s32 arg0) {
    (void)arg0;
}

void func_i8_802C6ADC(s32 arg0) {
    (void)arg0;
}

void func_i8_802C6D58(s32 arg0) {
    (void)arg0;
}

void func_i8_802C6DA8(s32 arg0) {
    (void)arg0;
}

void func_i8_802C6E00(void) {
    if ((D_802C7548) != 0) {
        func_i8_802C6FD4(&D_802C7548, (s8*) &D_801CB298[D_i8_802C74F8[D_i8_802C7040]].unk_0, 11);
    }
    D_802C756C = 1;
}

void func_i8_802C6E68(void* arg0) {
    func_i8_802C6FD4(arg0, &D_802C7548, 0xB);
    D_802C7564 = Strlen2(&D_802C7548);
    if (D_802C7564 >= 9) {
        D_802C7564 = 9;
    }
}

void func_i8_802C6EB8(s32 arg0) {
    (void)arg0;
}

void func_i8_802C6F4C(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x3F;
    D_801CE638 = 0xA;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;
    FadeTransition_SetProps(1, 4, 0);
}

void func_i8_802C6FD4(s8* src, s8* dest, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        *dest++ = *src++;
    }
}
