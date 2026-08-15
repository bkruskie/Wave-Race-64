#include "global.h"

void func_i3_802C5800(void) {
}

void func_i3_802C5AE8(void) {
}

void func_i3_802C5AF0(void) {
    func_80069798(D_801CE5F8 + 0xA80, D_801CE5F8 + 0x1780, D_801CE5F8 + 0xA40, &D_802C7024, &D_80198310, &D_80198350);
}

void func_i3_802C5B40(void) {
}

void func_i3_802C5D54(void) {
}

void func_i3_802C6344(void) {
}

void func_i3_802C6E9C(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 31;
    D_801CE638 = 8;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 20;
    D_800DAB1C = 0;
    D_800D461C = 3;

    D_i3_802C6FE0 = 1;

    FadeTransition_SetProps(5, 0, 20);
    func_801E6A4C(0, 0);
    func_800C37F4(58, 0);
}
