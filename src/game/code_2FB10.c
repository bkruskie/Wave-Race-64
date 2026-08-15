#include "common.h"

extern s32 D_800D48E0;

extern s32 D_801C1FD4;
extern s32 D_801C26C0[];

extern UnkStruct_801AEE20 D_801AEE20[];
extern s32 D_801BB120;
extern UnkStruct_801C2C24 D_801C2938[];

static const char devstr1[] = "dolphin condition full at goal\n";
static const char devstr2[] = "dolphin condition full\n";
static const char devstr3[] = "rank value adjust\n";
static const char devstr4[] = "simultaneously goal !!\n";

s32 func_80075310(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp24 = (s32) arg0;
    sp20 = (s32) arg1;
    sp1C = (s32) arg2;
    sp18 = (s32) arg3;
    if ((sp24 != -1) && ((sp24 == sp1C) || (sp24 == sp18))) {
        return 1;
    }
    if ((sp20 != -1) && ((sp20 == sp1C) || (sp20 == sp18))) {
        return 1;
    }
    return 0;
}

s32 func_80076240(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    func_80074368(arg0, arg1, &sp24, &sp20);
    func_80074368(arg2, arg3, &sp1C, &sp18);
    if ((sp24 != -1) && ((sp24 == sp1C) || (sp24 == sp18))) {
        return 1;
    }
    if ((sp20 != -1) && ((sp20 == sp1C) || (sp20 == sp18))) {
        return 1;
    }
    return 0;
}

void func_800762D0(struct_800762D0* arg0) {
    if (D_801CE638 == 1) {
        if ((gGameModes == GMODE_STUNT) && (arg0->unk2C4 <= 0)) {
            arg0->unk2EC = 2;
        } else if (arg0->unk19C >= 599999) {
            arg0->unk2EC = 2;
        } else {
            arg0->unk2EC = 1;
        }
        if ((gGameModes != GMODE_2P_VS) || (arg0->unk2EC != 2)) {
            arg0->unk32C = D_801C39B4;
            D_801C39B4 += 10000.0f;
        }
    }
}

void func_80076378(void) {
    s32 i;
    UnkStruct_801C2C24 *ptr;
    UnkStruct_801C2C24 *q;
    UnkStruct_801AEE20 *a;
    UnkStruct_801AEE20 *b;
    f32 val;
    f32 route;
    s32 lap;
    f32 new_var2;
    s32 routeIdx;
    UnkStruct_801AEE20 *new_var;
    s32 j;

    if (D_801C1FD4 != 0) {
        return;
    }
    D_801C1FD4 = 1;
    route = 0.0f;
    for (i = 0; i < gRiders; i++) {
        ptr = &D_801C2938[i];
        if ((ptr->unk2F4 == 0) && (ptr->unk2EC == 0)) {
            a = &D_801AEE20[ptr->unkC];
            b = &D_801AEE20[a->unkA8];
            val = ((D_80192690[i].unk44.z - b->unk8) * b->unk74) + ((D_80192690[i].unk44.x - b->unk0) * b->unk70);
            if (val < 0.0f) {
                val = 0.0f;
            }
            val = 1.0f - (val / b->unk88);
            if (val < 0.0f) {
                val = route;
            }
            val *= 20.0f;
            lap = ptr->lapCount;
            new_var2 = 80.0f - ((f32) ptr->racePosition);
            routeIdx = 0;
            b = a;
            do {
                new_var = b;
                if (new_var->unk98 == 3) {
                    if (lap >= D_801CE728[0]) {
                        break;
                    }
                    lap++;
                }
                routeIdx = new_var->unkA0;
                val += new_var->unk88;
                b = &D_801AEE20[routeIdx];
            } while ((b->unk98 != 3) || (lap < D_801CE728[0]));
            ptr->unk19C = (s32) (((f32) ptr->unk19C) + ((val / (new_var2 / 1.8f)) * 50.0f));
        }
    }

    for (i = 0; i < gRiders; i++) {
        ptr = &D_801C2938[i];
        if (ptr->unk19C < 0x927C0) {
            ptr->unk19C = 0x927BF;
        }
        if ((ptr->unk2F4 == 0) && (ptr->unk2EC == 0)) {
            for (j = 0; j < gRiders; j++) {
                q = &D_801C2938[j];
                if (((q->unk2F4 == 0) && (q->unk2EC == 0)) && (j != i)) {
                    if ((ptr->racePosition < q->racePosition) && (q->unk19C < ptr->unk19C)) {
                        s32 k = ptr->racePosition;
                        ptr->racePosition = q->racePosition;
                        q->racePosition = k;
                    }
                }
            }
        }
    }

    if (gCourseID == 0) {
        return;
    }
    for (i = 0; i < gRiders; i++) {
        D_801C26C0[i] = D_801C2938[i].racePosition;
    }
}

void func_8007687C(void) {
    s32 i;
    s32 j;
    UnkStruct_801C2C24 *ptr;
    UnkStruct_801C2C24 *q;
    s32 k;
    s32 lap;
    f32 var_fv0;
    UnkStruct_801AEE20 *temp_a0;

    for (i = 0; i < gRiders; i++) {
        ptr = &D_801C2938[i];
        if (ptr->unk2F4 == 0) {
            if (D_801CE638 == 1) {
                if ((gGameModes == GMODE_STUNT) && (ptr->unk2C4 <= 0)) {
                    ptr->unk2EC = 2;
                } else if (ptr->unk19C >= 599999) {
                    ptr->unk2EC = 2;
                } else {
                    ptr->unk2EC = 1;
                }
                if ((gGameModes != GMODE_2P_VS) || (ptr->unk2EC != 2)) {
                    ptr->unk32C = D_801C39B4;
                    D_801C39B4 += 10000.0f;
                }
            }
            if (ptr->unk19C < 0x927C0) {
                ptr->unk19C = 0x927BF;
            }
            if ((ptr->unk2F4 == 0) && (ptr->unk2EC == 0)) {
                for (j = 0; j < gRiders; j++) {
                    q = &D_801C2938[j];
                    if (((q->unk2F4 == 0) && (q->unk2EC == 0)) && (j != i)) {
                        if ((ptr->racePosition < q->racePosition) && (q->unk19C < ptr->unk19C)) {
                            k = ptr->racePosition;
                            ptr->racePosition = q->racePosition;
                            q->racePosition = k;
                        }
                    }
                }
            }
        }
    }

    if (gCourseID == 0) {
        return;
    }
    for (i = 0; i < gRiders; i++) {
        D_801C26C0[i] = D_801C2938[i].racePosition;
    }
}

void func_80077F5C(void) {
    s32 i;
    UnkStruct_801AEE20 *new_var;
    s32 j;
    s32 k;
    UnkStruct_801C2C24 *ptr;
    UnkStruct_801C2C24 *q;
    UnkStruct_801AEE20 *a;
    UnkStruct_801AEE20 *b;
    f32 val;
    f32 route;
    s32 lap;
    float new_var2;
    s32 routeIdx;
    if (D_801C1FD4 != 0) {
        return;
    }
    D_801C1FD4 = 1;
    route = 0.0f;
    for (i = 0; i < gRiders; i++) {
        ptr = &D_801C2938[i];
        if ((ptr->unk2F4 == 0) && (ptr->unk2EC == 0)) {
            a = &D_801AEE20[ptr->unkC];
            b = &D_801AEE20[a->unkA8];
            val = ((D_80192690[i].unk44.z - b->unk8) * b->unk74) + ((D_80192690[i].unk44.x - b->unk0) * b->unk70);
            if (val < 0.0f) {
                val = 0.0f;
            }
            val = 1.0f - (val / b->unk88);
            if (val < 0.0f) {
                val = route;
            }
            val *= 20.0f;
            lap = ptr->lapCount;
            new_var2 = 80.0f - ((f32) ptr->racePosition);
            routeIdx = 0;
            b = a;
            do {
                new_var = b;
                if (new_var->unk98 == 3) {
                    if (lap >= D_801CE728[0]) {
                        break;
                    }
                    lap++;
                }
                routeIdx = new_var->unkA0;
                val += new_var->unk88;
                b = &D_801AEE20[routeIdx];
            } while ((b->unk98 != 3) || (lap < D_801CE728[0]));
            ptr->unk19C = (s32) (((f32) ptr->unk19C) + ((val / (new_var2 / 1.8f)) * 50.0f));
        }
    }

    for (i = 0; i < gRiders; i++) {
        ptr = &D_801C2938[i];
        if (ptr->unk19C < 0x927C0) {
            ptr->unk19C = 0x927BF;
        }
        if ((ptr->unk2F4 == 0) && (ptr->unk2EC == 0)) {
            for (j = 0; j < gRiders; j++) {
                q = &D_801C2938[j];
                if (((q->unk2F4 == 0) && (q->unk2EC == 0)) && (j != i)) {
                    if ((ptr->racePosition < q->racePosition) && (q->unk19C < ptr->unk19C)) {
                        k = ptr->racePosition;
                        ptr->racePosition = q->racePosition;
                        q->racePosition = k;
                    }
                }
            }
        }
    }

    if (gCourseID == 0) {
        return;
    }
    for (i = 0; i < gRiders; i++) {
        D_801C26C0[i] = D_801C2938[i].racePosition;
    }
}

void func_80078264(void) {
    UnkStruct_801C2C24* temp_a0;
    UnkStruct_801C2C24* temp_v1;
    s32 var_v0;
    f32 var_fv0;
    s32 lapCount;
    s32 lapCount2;
    s32 var_a3;
    s32 var_t0;

    var_v0 = D_801BB120;
    var_fv0 = 0.0f;
    temp_v1 = &D_801C2938[D_800D48DC];
    temp_a0 = &D_801C2938[D_800D48E0];
    lapCount = temp_v1->lapCount;
    lapCount2 = temp_a0->lapCount;
    var_a3 = temp_v1->unkC;
    var_t0 = temp_a0->unkC;

    if (temp_a0->racePosition >= temp_v1->racePosition) {
        if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
            while (var_v0-- > 0) {
                var_fv0 += D_801AEE20[var_t0].unk88;
                if (D_801AEE20[var_t0].unk98 == 3) {
                    lapCount2++;
                }
                var_t0 = D_801AEE20[var_t0].unkA0;
                if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
                    continue;
                } else {
                    break;
                }
            }
        }
        temp_v1->unk330 = -var_fv0;
        temp_a0->unk330 = var_fv0;
    } else {
        if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
            while (var_v0-- > 0) {
                var_fv0 += D_801AEE20[var_a3].unk88;
                if (D_801AEE20[var_a3].unk98 == 3) {
                    lapCount++;
                }
                var_a3 = D_801AEE20[var_a3].unkA0;
                if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
                    continue;
                } else {
                    break;
                }
            }
        }

        temp_v1->unk330 = var_fv0;
        temp_a0->unk330 = -var_fv0;
    }
}

void func_800783AC(void) {
    UnkStruct_801C2C24* temp_a0;
    UnkStruct_801C2C24* temp_v1;
    s32 var_v0;
    f32 var_fv0;
    s32 lapCount;
    s32 lapCount2;
    s32 var_a3;
    s32 var_t0;

    var_v0 = D_801BB120;
    var_fv0 = 0.0f;
    temp_v1 = &D_801C2938[D_800D48DC];
    temp_a0 = &D_801C2938[D_800D48E0];
    lapCount = temp_v1->lapCount;
    lapCount2 = temp_a0->lapCount;
    var_a3 = temp_v1->unkC;
    var_t0 = temp_a0->unkC;

    if (temp_a0->racePosition >= temp_v1->racePosition) {
        if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
            while (var_v0-- > 0) {
                var_fv0 += D_801AEE20[var_t0].unk88;
                if (D_801AEE20[var_t0].unk98 == 3) {
                    lapCount2++;
                }
                var_t0 = D_801AEE20[var_t0].unkA0;
                if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
                    continue;
                } else {
                    break;
                }
            }
        }
        temp_v1->unk330 = -var_fv0;
        temp_a0->unk330 = var_fv0;
    } else {
        if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
            while (var_v0-- > 0) {
                var_fv0 += D_801AEE20[var_a3].unk88;
                if (D_801AEE20[var_a3].unk98 == 3) {
                    lapCount++;
                }
                var_a3 = D_801AEE20[var_a3].unkA0;
                if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
                    continue;
                } else {
                    break;
                }
            }
        }

        temp_v1->unk330 = var_fv0;
        temp_a0->unk330 = -var_fv0;
    }
}

void func_80079528(void) {
    s32 i;

    for (i = 0; i < gRiders; i++) {
        D_801C2938[i].unk19C = 0;
        D_801C2938[i].racePosition = 0;
    }
    D_801C1FD4 = 0;
}
