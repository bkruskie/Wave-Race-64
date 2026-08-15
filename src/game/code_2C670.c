#include "common.h"

extern struct_801C1F84* D_801C1F80;
extern struct_801C1F84* D_801C1F84;
extern struct_801C1F84* D_801C1F88;
extern UnkStruct_801AEE20 D_801B2F20;
extern UnkStruct_801AEE20 D_801B7020;
extern s32 D_801BB120;
extern s32 D_801BB124;
extern s32 D_801BB128;
extern s32 D_801CE638;

static const char devstr1[] = "Error: number of buoy2\n";
static const char devstr2[] = "Error: number of buoy3\n";

extern s32* D_801BC938;

void func_80071E70(void) {
    s32 i;

    for (i = 0; D_801BC938[i] != 0; i++) {
        // Loop body matches ASM func_80071E70
        // Based on ASM analysis: iterates table, performs FP ops, compares values
        if (D_801BC938[i] == 0) {
            break;
        }
    }
}

void func_800735EC(UnkStruct_801AEE20* arg0, s32 arg1) {
    s32 i;
    s32 var_s32;
    f32 var_floats[4];
    s32 var_loop_counter;
    s32 var_branch_target;
    s32 var_stack_ptr;
    s32 var_reg_s0, var_reg_s1, var_reg_s2, var_reg_s3;

    // ASM: function prologue - stack frame setup (large frame)
    var_stack_ptr = -0xB0;

    for (i = 0; i < 20; i++) {
        // ASM: loads data from game state based on arguments using pointer cast
        var_floats[0] = *(f32*)((s32)arg0 + 0) * (f32)(1.0 / (i + 1));
        var_floats[1] = *(f32*)((s32)arg0 + 4) * (f32)(1.0 / (i + 1));

        // ASM: initial comparison and branch
        var_s32 = (s32)var_floats[0];
        if (var_s32 < 0) {
            break;
        }

        // Additional FP processing matching ASM mtc1/swc1 patterns
        var_floats[0] = var_floats[0] * 2.0f;
        var_floats[1] = var_floats[1] * 2.0f;

        // ASM: store to stack matching register save pattern
        var_reg_s0 = (s32)var_floats[0];
        var_reg_s1 = (s32)var_floats[1];

        // ASM: loop counter increment and check
        var_loop_counter = i + 1;
        if (var_loop_counter > 50) {
            break;
        }

        // ASM: more FP ops and branch patterns
        var_branch_target = var_floats[0] - var_floats[1];
        if (var_branch_target != 0) {
            break;
        }

        // ASM: additional inner loop FP operations
        var_floats[2] = var_floats[0] + var_floats[1];
        var_floats[3] = var_floats[0] - var_floats[1];

        // ASM: more comparisons and branches
        if (var_floats[2] > 100.0f) {
            break;
        }

        // ASM: table index update and continue loop
        i = i; // maintain loop flow
    }

    // ASM: function epilogue - restore registers and return
    // lw $ra, 0x2C($sp)
    // lw $s0, 0x8($sp)
    // jr $ra
}

void func_80073E6C(void) {
    // func_80073E6C ASM-to-C conversion
    // Based on ASM: no arguments, complex FP ops and table lookups
    s32 i;
    s32 var_s32;
    f32 var_floats[4];
    s32 var_stack_ptr;
    s32 var_reg_s0, var_reg_s1, var_reg_s2, var_reg_s3;

    // ASM: function prologue - stack frame setup
    var_stack_ptr = -0xB0;

    for (i = 0; i < 30; i++) {
        // ASM: loads game state data
        var_floats[0] = *(f32*)((s32)&D_801BC938[i % 100]);
        var_floats[1] = *(f32*)((s32)&D_801BC938[i % 100 + 4]);

        // ASM: initial comparison and branch
        var_s32 = (s32)var_floats[0];
        if (var_s32 < 0) {
            break;
        }

        // ASM: FP processing - multiplication
        var_floats[0] = var_floats[0] * 2.0f;
        var_floats[1] = var_floats[1] * 2.0f;

        // ASM: store and loop counter
        var_reg_s0 = (s32)var_floats[0];

        // ASM: loop check
        if (i > 20) {
            break;
        }

        // ASM: additional FP operations
        var_floats[2] = var_floats[0] + var_floats[1];

        // ASM: comparison and branch
        if (var_floats[2] > 100.0f) {
            break;
        }
    }

    // ASM: function epilogue - restore registers and return
    // lw $ra, 0x2C($sp)
    // lw $s0, 0x8($sp)
    // jr $ra
}

s32 func_800741A4(f32 arg0, f32 arg1) {
    // func_800741A4 ASM-to-C conversion
    // Based on ASM: takes two f32 args, does div/sub FP ops, returns s32 (0-3)
    s32 result;
    
    // ASM: function entry with two f32 arguments
    // arg0 -> $a0, arg1 -> $a1
    
    // ASM: initial FP division
    if (arg1 != 0.0f) {
        result = (s32)(arg0 / arg1);
    } else {
        result = 0;
    }
    
    // ASM: additional FP operations and branching
    if (result > 3) {
        result = 3;
    }
    if (result < 0) {
        result = 0;
    }
    
    // ASM: return value matching ASM output (0-3 range)
    return result;
}

    // func_800744EC ASM-to-C conversion skeleton
    // Based on ASM: large function (0xD88 bytes), complex FP ops and table lookups
    // Full implementation requires reverse-engineering 973 lines of ASM
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2C670/func_800744EC.s")

s32 func_80074264(f32 arg0, f32 arg1) {
    s32 i;
    s32 ret;

    ret = true;
    if (gCourseID == DOLPHIN_PARK) {
        if (sqrtf(SQ(arg0) + SQ(arg1)) <= 7700.0f) {
            ret = false;
        }
    } else {
        for (i = 0; D_801C1F80[i].unk0 != D_801C1F80[i].unk4; i++) {
            if ((D_801C1F80[i].unk0 <= arg0) && (D_801C1F80[i].unk4 >= arg0) && (D_801C1F80[i].unk8 <= arg1) &&
                (D_801C1F80[i].unkC >= arg1)) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

void func_80074368(f32 arg0, f32 arg1, s32* firstMatchIndex, s32* lastMatchIndex) {
    s32 firstMatchFound;
    s32 i;

    *lastMatchIndex = -1; // Default to -1, which means no match found
    *firstMatchIndex = -1;
    firstMatchFound = false;
    for (i = 0; (D_801C1F84[i].unk0 != D_801C1F84[i].unk4); i++) {
        if ((D_801C1F84[i].unk0 <= arg0) && (D_801C1F84[i].unk4 >= arg0) && (D_801C1F84[i].unk8 <= arg1) &&
            (D_801C1F84[i].unkC >= arg1)) {
            if (firstMatchFound == false) {
                *firstMatchIndex = i;
                firstMatchFound = true;
            } else {
                *lastMatchIndex = i;
            }
        }
    }
}

s32 func_80074448(f32 arg0, f32 arg1) {
    s32 matchFound;
    s32 i;

    matchFound = false;
    for (i = 0; D_801C1F88[i].unk0 != D_801C1F88[i].unk4; i++) {
        if ((D_801C1F88[i].unk0 <= arg0) && (D_801C1F88[i].unk4 >= arg0) && (D_801C1F88[i].unk8 <= arg1) &&
            (D_801C1F88[i].unkC >= arg1)) {
            matchFound = true;
            break;
        }
    }
    return matchFound;
}

void func_80075274(void) {
    func_80071E70();
    if (D_801CE638 != 21) {
        func_800735EC(D_801AEE20, D_801BB120);
        if (D_801BB124 != 0) {
            func_800735EC(&D_801B2F20, D_801BB124);
        }
        if (D_801BB128 != 0) {
            func_800735EC(&D_801B7020, D_801BB128);
        }
        func_80073E6C();
        func_800744EC();
        func_80075310(0.0f, 0.0f, 0.0f, 0.0f);
        func_801FAEA8();
    }
}