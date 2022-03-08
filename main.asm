// n64-playground - Small N64 assembly dev environment.
// Copyright (c) 2022 Cult Of N64

// Main

arch      n64.cpu
fill      0x1000

// Definitions
include   "lib/memory.inc"
include   "lib/mips.inc"
include   "lib/pi.inc"
include   "lib/pif.inc"
include   "lib/vi.inc"

origin    0
base      KSEG0 + RDRAM_BASE

include   "lib/header.inc"
insert    "lib/bootcode.bin"

constant  FRAMEBUFFER_ADDR = KSEG1 + RDRAM_BASE + 0x100000

Entry:
    // Set stack pointer
    li        sp, RDRAM_BASE + RDRAM_SIZE

    // This is necessary to stop the console from crashing
    // See https://github.com/PeterLemon/N64/blob/0ff44a433afe4d9fe1076fbe1c3f029b58e48e70/LIB/N64.INC#L243
    PIF_SetBootStatus()

    // Set up NTSC screen, 320x240, RGBA5551 (16BPP)
    VI_InitScreen(320, 240, VI_RGBA8888, FRAMEBUFFER_ADDR)

    // Jump to Main
    jal       Main
    nop

    -
        b         -
        nop

Main:
    // Push return address
    sw        ra, -4(sp)
    subiu     sp, 4

    // Copy image to framebuffer
    // PI_DMA(FRAMEBUFFER_ADDR, Image, Image.size)

    // Pop return address
    lw        ra, 0(sp)
    addiu     sp, 4

    jr        ra
    nop

// TODO: add a bitmap
// insert Image, "Image.bin"
