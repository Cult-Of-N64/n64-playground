// n64-playground - Small N64 assembly dev environment.
// Copyright (c) 2022 Cult Of N64

// Peripheral Interface specific defines

// PIF RAM
constant  PIFRAM_STATUS = 0x3F

// Prevents the N64 from crashing after boot
// Taken from https://github.com/PeterLemon/N64/blob/0ff44a433afe4d9fe1076fbe1c3f029b58e48e70/LIB/N64.INC#L243
macro PIF_SetBootStatus() {
    lui       r1, PIF_BASE
    lli       t0, 8
    sw        t0, PIF_RAM + PIFRAM_STATUS(r1)
}
