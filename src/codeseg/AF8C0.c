#include "global.h"

extern s32 D_800D461C;
extern s32 D_800DAB1C;
extern s32 D_801CE630;
extern s32 gPrevGameState;
extern s32 D_801CE638;
extern s32 D_801CE63C;
extern s32 D_801CE640;
extern s32 D_801CE644;

void func_801E1290(s32 arg0) {
    D_800D461C = arg0;
}

void func_801E1BA8(s32 arg0) {
    D_800DAB1C = arg0;
}

void func_801E1E8C(s32 arg0) {
    D_801CE630 = arg0;
}

void func_801E2058(s32 arg0) {
    gPrevGameState = arg0;
}

void func_801E229C(s32 arg0) {
    D_801CE638 = arg0;
}
void func_801E2530(s32 arg0) {
    D_801CE63C = arg0;
}

void func_801E2C14(s32 arg0) {
    D_801CE640 = arg0;
}
const char D_80226210[] = "A";
const char D_80226214[] = "B";
const char D_80226218[] = "C";
const char D_8022621C[] = "D";
const char D_80226220[] = "E";
const char D_80226224[] = "F";
const char D_80226228[] = "G";
const char D_8022622C[] = "H";
const char D_80226230[] = "I";
const char D_80226234[] = "J";
const char D_80226238[] = "K";
const char D_8022623C[] = "L";
const char D_80226240[] = "M";
const char D_80226244[] = "N";
const char D_80226248[] = "O";
const char D_8022624C[] = "P";
const char D_80226250[] = "Q";
const char D_80226254[] = "R";
const char D_80226258[] = "S";
const char D_8022625C[] = "T";
const char D_80226260[] = "U";
const char D_80226264[] = "V";
const char D_80226268[] = "W";
const char D_8022626C[] = "X";
const char D_80226270[] = "Y";
const char D_80226274[] = "Z";
const char D_80226278[] = "-";
const char D_8022627C[] = ".";
const char D_80226280[] = " ";

void func_801E2B8C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = GAME_STATE_65;
    D_801CE638 = 6;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 0xE, 0x14);
}
