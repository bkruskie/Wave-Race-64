# Legacy Port Audit (2026-08-18)

Cross-check of the old repo (`WaveRaceNew`, remote: github.com/bkruskie/Wave-Race)
against the LLONSIT fork (this repo) to find legacy C implementations worth merging.

## Method

1. **Leftovers**: every function still unimplemented in this repo — 326 `.s` files under
   `asm/us/rev1/nonmatchings` (referenced by `#pragma GLOBAL_ASM` stubs in `src/`).
2. **Cross-reference**: scan the legacy repo's `src/**/*.c` for real C definitions
   (definitions only: `name(...) {`, call sites excluded). Result: **13 candidates**.
3. **Verification**: compile each legacy C file with the legacy IDO toolchain
   (`make -C WaveRaceNew build/src/...`), objdump the `.o`, and compare the
   instruction stream against this repo's reference `.s` using a canonicalized
   comparator (IDO float-register names, hex/decimal immediates, binary float
   constants, `%hi`/`%lo` vs relocation lines, branch target positions).

## Verification history

The FIRST attempt scored "FULL" on several functions using an object produced
from a translation unit that still carried `#pragma GLOBAL_ASM` for the function
under test — a circular check (the pragma embeds the reference assembly into the
`.o`). Those verdicts were RETRACTED and that merge was reverted.

**Corrected acceptance test**: compile a TU where the pragma is actually removed,
then canonical-diff the symbol against the freshly re-extracted `.s` reference.
The comparator is repeatable and documented in the operator's tooling
(`try_match.py`).

## 2026-08-18 LATER: 4 conversions MERGED (verified FULL matches)

Using the corrected acceptance test (pragma removed, genuine IDO recompile,
canonical diff vs freshly re-extracted reference), the following functions were
converted from `#pragma GLOBAL_ASM` to C and verified FULL matches
(opcode=1.0000, full=1.0000):

| Function | VRAM | Size | Notes |
|---|---|---|---|
| `func_8009A1CC` | 0x8009A1CC | 70 insns | clamps `2t/7` to [1..2], drives `unk90` event, calls `func_80099AD8` twice |
| `func_8009C814` | 0x8009C814 | 85 insns | resets a wave-raider entry; zeroes arrays, initializes vectors |
| `func_8009CD50` | 0x8009CD50 | ~full | ported legacy C; per-racer state machine via `func_8009CB70`, SIN/COS orientation, `func_80099D94`/`func_80099BBC` callbacks |
| `func_8009934C` | 0x8009934C | 114 insns | cubic B-spline basis weights; pure float math |

Supporting changes:

- `include/structs.h`: `UnkStruct_8009A04C` upgraded from a pad blob to the full
  named field layout (offsets unchanged: `unk4` .. `unk94`) so `func_8009C814`
  and `func_8009CD50` can address fields directly. Layout-identical, so
  previously matched functions recompile identically.
- `include/functions.h`: fixed `func_8009CD50` prototype (was `void(void)`,
  now `u8(UnkStruct_func_8009CCE8*)`).
- `src/game/code_52CD0.c`: added `extern s16 D_801CEA9C[]`; `func_8009CCE8`
  now calls `func_8009CD50` with its actual argument.
- The four nonmatching `.s` files were deleted; `make extract` does not
  regenerate them (C definitions exist).

## KNOWN ISSUE: full ROM link fails in this environment (pre-existing)

`make finalrom` / `make build/waverace64.us.rev1.elf` fails with 900+ undefined
references of the form `.Li7_802C59xx` / `.L80048044`: the current
splat/spimdisasm (1.42.4) extracts ovl_i7 `[0x1C4970, rodata]` jump table
(`jtbl_i7_802C5D80`) referencing `.Li7_*` labels that are no longer defined
since those functions are C (`ovl_1C43F0.c`). Verified pre-existing: at HEAD
(all four merges stashed) the same undefined references occur.

Expected fix: remove `- [0x1C4970, rodata]` from `waverace64.us.rev1.yaml`
(the C build already emits the jtbl into the object's rodata). Audit needed
across ALL overlays: any rodata/data subsegment referencing `.L<i7/other>_...`
labels has the same failure mode (e.g. `0x1C4970` style jtbls in ovl_i8 etc.).