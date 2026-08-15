# Wave Race 64 Decompilation Progress

## Fidelity Rules

| Level | Opcode Ratio | Status | Action |
|-------|-------------|--------|--------|
| **FULL** | **1.0000** | **COMPLETED** | May delete `.s` |
| **OPCODE** | >=0.90 | INCOMPLETE | Keep `.s`, fix regalloc/sched |
| **NEAR** | 0.88-0.90 | INCOMPLETE | Keep `.s`, permuter candidate |
| **DRAFT** | <0.90 | INCOMPLETE | Keep `.s`, rewrite C code |

Only **FULL (1.0000)** counts as completed. All `.s` files kept until 100% FULL.

---

## Summary

| Metric | Count |
|--------|-------|
| **Total .s files in nonmatchings/** | **393** |
| **Total GLOBAL_ASM in src/** | **235** |
| **Converted to C (have .s + C code)** | **161** |
| **  — Real C implementations** | **~54** |
| **  — Stub functions (empty bodies)** | **~107** |
| **Build status** | **PASSING** (ROM builds, no match) |
| **Functions FULL (1.0000)** | **3** (`func_8006977C`, `func_80067BFC`, `func_801EAF78`) |

### The 393 .s Files Are the True Reference

The `#pragma GLOBAL_ASM` count (235) is lower than .s count (393) because 158 functions were converted from GLOBAL_ASM to C code. Some are real implementations, some are stubs. The .s files in `nonmatchings/` are the authoritative list of all functions needing decompilation.

---

## Completed Functions (FULL 1.0000)

| Function | File | Opcodes | Description |
|----------|------|---------|-------------|
| `func_8006977C` | `game/code_C6C0.c` | 7 | 12-byte struct copy (3 word lw/sw pairs) |
| `func_80067BFC` | `game/code_C6C0.c` | 28 | Display list builder: G_VTX command + conditional offset based on D_80193D5C table |
| `func_801EAF78` | `codeseg/B66E0.c` | 15 | 20-byte struct copy (5 word lw/sw pairs) between D_80226E30 and D_80228A78 |

---

## Per-File Status

### Game Source Files

| File | .s | GLOBAL_ASM | Converted | Notes |
|------|----|-----------|-----------|-------|
| `game/code_52CD0.c` | 33 | 0 | 33 | All converted to C (mix of real + stubs) |
| `game/code_C6C0.c` | 34 | 31 | 3 | 31 still ASM, 3 converted, **2 FULL** |
| `game/water_69D0.c` | 19 | 19 | 0 | All still ASM |
| `game/code_43DA0.c` | 10 | 0 | 10 | **12 verified** (1 FULL, 11 OPCODE at 1.0000) |
| `game/code_24B00.c` | 7 | 0 | 7 | All converted to C |
| `game/code_4F850.c` | 6 | 0 | 6 | All converted to C |
| `game/code_2FB10.c` | 6 | 0 | 6 | All converted to C (real implementations) |
| `game/code_68A10.c` | 5 | 5 | 0 | All still ASM |
| `game/code_2C670.c` | 5 | 1 | 4 | 1 still ASM, 4 converted |
| `game/code_5480.c` | 3 | 3 | 0 | All still ASM; 2 scored (DRAFT: 0.0105, 0.0000) |
| `game/code_383C0.c` | 2 | 2 | 0 | All still ASM |
| `game/code_3A580.c` | 2 | 2 | 0 | All still ASM |
| `game/code_43A60.c` | 2 | 0 | 2 | All converted (regalloc issues) |
| `game/core/wr64_save.c` | 12 | 12 | 0 | All still ASM |
| `game/code_3AC00.c` | 1 | 1 | 0 | Still ASM |
| `game/code_39F00.c` | 0 | 0 | — | C functions only (no .s targets) |

### Codeseg Source Files

| File | .s | GLOBAL_ASM | Converted | Notes |
|------|----|-----------|-----------|-------|
| `codeseg/A95D0.c` | 42 | 42 | 0 | All still ASM |
| `codeseg/B97B0.c` | 35 | 35 | 0 | All still ASM |
| `codeseg/B66E0.c` | 17 | 14 | 3 | 14 ASM + 3 C functions (2 real + 1 calls other C funcs), **1 FULL** |
| `codeseg/AF8C0.c` | 7 | 2 | 5 | 2 ASM, 5 converted |
| `codeseg/B3AA0.c` | 6 | 0 | 6 | All converted (real implementations) |
| `codeseg/C94E0.c` | 3 | 0 | 3 | All converted (mix of stubs + real) |
| `codeseg/B17D0.c` | 2 | 0 | 2 | All converted (stubs) |
| `codeseg/B3290.c` | 2 | 0 | 2 | All converted (stubs) |
| `codeseg/B2A70.c` | 1 | 1 | 0 | Still ASM |
| `codeseg/wr64_fade.c` | 1 | 1 | 0 | Still ASM |
| `codeseg/B2510.c` | 1 | 0 | 1 | Converted (stub) |

### Overlay Source Files

| File | .s | GLOBAL_ASM | Converted | Notes |
|------|----|-----------|-----------|-------|
| `overlays/ovl_i13/ovl_1CBAF0.c` | 18 | 18 | 0 | All still ASM |
| `overlays/ovl_i2/ovl_1B9440.c` | 13 | 13 | 0 | All still ASM |
| `overlays/ovl_i1/ovl_1B55A0.c` | 13 | 0 | 13 | All converted (mix of stubs + real) |
| `overlays/ovl_i5/ovl_1C17E0.c` | 10 | 10 | 0 | All still ASM |
| `overlays/ovl_i8/ovl_1C49A0.c` | 8 | 0 | 8 | All converted (mix of stubs + real) |
| `overlays/ovl_i4/ovl_1BE0B0.c` | 7 | 0 | 7 | All converted (mix) |
| `overlays/ovl_i9/ovl_1C66D0.c` | 6 | 0 | 6 | All converted |
| `overlays/ovl_i5/ovl_1BFF50.c` | 6 | 0 | 6 | All converted |
| `overlays/ovl_i3/ovl_1BC890.c` | 4 | 0 | 4 | All converted |
| `overlays/ovl_i15/ovl_1CFB60.c` | 4 | 4 | 0 | All still ASM |
| `overlays/ovl_i0/ovl_1B3EC0.c` | 4 | 0 | 4 | All converted (mix) |
| `overlays/ovl_i6/ovl_1C2250.c` | 4 | 4 | 0 | All still ASM |
| `overlays/ovl_i10/ovl_1C9150.c` | 3 | 3 | 0 | All still ASM |
| `overlays/ovl_i14/ovl_1CF180.c` | 2 | 0 | 2 | All converted (mix) |
| `overlays/ovl_i12/ovl_1CAE40.c` | 2 | 0 | 2 | All converted (stubs) |
| `overlays/ovl_i11/ovl_1CA480.c` | 2 | 2 | 0 | All still ASM |
| `overlays/ovl_i7/ovl_1C43F0.c` | 1 | 0 | 1 | Converted |

### Audio/Sys/Other Source Files

| File | .s | GLOBAL_ASM | Converted | Notes |
|------|----|-----------|-----------|-------|
| `audio/audio_general.c` | 5 | 5 | 0 | All still ASM |
| `sys/sys_utils.c` | 5 | 1 | 4 | 1 ASM, 4 converted (mix of stubs + real) |
| `sys/sys_main.c` | 1 | 1 | 0 | Still ASM |
| `unused_code_1B1FB0.c` | 10 | 0 | 10 | All converted (mostly stubs) |
| `seg_1C3D00.c` | 1 | 0 | 1 | Converted (real implementation) |

---

## Verified Functions (code_43DA0.c)

| Function | Status | Opcode Ratio | Notes |
|----------|--------|-------------|-------|
| func_800871B4 | FULL | 1.0000 | Verified |
| func_80087464 | OPCODE | 1.0000 | Verified (regalloc only) |
| func_80087488 | OPCODE | 1.0000 | Verified (regalloc only) |
| func_80087648 | OPCODE | 1.0000 | Verified (regalloc only) |
| func_80087748 | OPCODE | 1.0000 | Verified (regalloc only) |
| func_800877A0 | OPCODE | 1.0000 | Verified (regalloc only) |
| func_80087890 | OPCODE | 1.0000 | Verified (regalloc only) |
| func_80087948 | OPCODE | 1.0000 | Verified (regalloc only) |
| func_80087B90 | OPCODE | 1.0000 | Verified (regalloc only) |
| func_8008823C | OPCODE | 1.0000 | Verified (regalloc only) |
| func_80088414 | OPCODE | 1.0000 | Verified (regalloc only) |
| func_80088504 | OPCODE | 1.0000 | Verified (regalloc only) |

---

## Build Fixes Applied

1. **functions.h:98** — Changed `Gfx* func_8008FB74(Gfx* arg0)` to `void func_8008FB74(void)`
2. **functions.h:223** — Changed `Gfx* func_8008BD2C(Gfx*)` to `void func_8008BD2C(void)`
3. **code_43DA0.c:525** — Added missing `#endif` for `#ifdef NEEDS_DATA`

---

## Files with Stub Functions (empty bodies)

These files contain functions with `(void)arg;` pattern — stubs that need real implementations:

| File | Stubs |
|------|-------|
| `codeseg/B17D0.c` | 2 |
| `codeseg/B2510.c` | 1 |
| `codeseg/B3290.c` | 2 |
| `codeseg/C94E0.c` | some |
| `game/code_24B00.c` | some |
| `game/code_52CD0.c` | some |
| `overlays/ovl_i0/ovl_1B3EC0.c` | some |
| `overlays/ovl_i1/ovl_1B55A0.c` | some |
| `overlays/ovl_i12/ovl_1CAE40.c` | 2 |
| `overlays/ovl_i14/ovl_1CF180.c` | some |
| `overlays/ovl_i4/ovl_1BE0B0.c` | some |
| `overlays/ovl_i8/ovl_1C49A0.c` | some |
| `sys/sys_utils.c` | some |
| `unused_code_1B1FB0.c` | most |

---

## What Remains

### Phase 1: Score ALL functions
Run `work/tools/score2.sh` on every function to get opcode ratios.

### Phase 2: Fix non-FULL functions
- OPCODE (>=0.90): Fix register allocation / scheduling
- NEAR (0.88-0.90): Run permuter
- DRAFT (<0.90): Rewrite C code
- Stubs: Write real implementations, then score

### Phase 3: Convert remaining GLOBAL_ASM to C
235 functions still need C code written (the `.s` files are the targets).

### Phase 4: Delete .s files and verify ROM checksum
Only when ALL 393 functions are FULL.

---

*Last updated: 2026-08-14*
*Status: Build passing, 12 functions verified (code_43DA0.c), 393 total functions tracked, 235 GLOBAL_ASM remaining, 158 converted (~51 real, ~107 stubs), 0 FULL scored*
