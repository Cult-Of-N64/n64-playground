// n64-playground - Small N64 assembly dev environment.
// Copyright (c) 2022 Cult Of N64

// Video Interface specific defines

// Pixel formats
constant  VI_RGBA0    = 0
constant  VI_RGBA5551 = 2
constant  VI_RGBA8888 = 3

// Initializes an NTSC screen
// Taken from https://github.com/PeterLemon/N64/blob/0ff44a433afe4d9fe1076fbe1c3f029b58e48e70/LIB/N64_GFX.INC#L38
macro VI_InitScreen(width, height, status, origin) {
    lui       s8, VI_BASE

    // Set status
    li        t0, {status}
    sw        t0, VI_STATUS(r1)

    // Set framebuffer address
    li        t0, {origin}
    sw        t0, VI_ORIGIN(r1)

    // Set screen width
    lli       t0, {width}
    sw        t0, VI_WIDTH(r1)

    // Set VBLANK interrupt halfline
    lli       t0, 2 * {width}
    sw        t0, VI_V_INTR(r1)

    // Reset current halfline
    lli       t0, 0
    sw        t0, VI_V_CURRENT_LINE(r1)

    // Set start of color burst
    li        t0, 0x3E52239
    sw        t0, VI_TIMING(r1)

    // Set vertical sync
    lli       t0, 0x20D
    sw        t0, VI_V_SYNC(r1)

    // Set horizonzal sync
    lli       t0, 0xC15
    sw        t0, VI_H_SYNC(r1)

    // Set horizontal sync leap
    li        t0, 0xC150C15
    sw        t0, VI_H_SYNC_LEAP(r1)

    // Set horizontal video
    li        t0, 0x6C02EC
    sw        t0, VI_H_VIDEO(r1)

    // Set vertical video
    li        t0, 0x2501FF
    sw        t0, VI_V_VIDEO(r1)

    // Set vertical burst
    li        t0, 0xE0204
    sw        t0, VI_V_BURST(r1)

    // Set X scale
    lli       t0, ((0x100 * {width}) / 160)
    sw        t0, VI_X_SCALE(r1)
    
    // Set Y scale
    lli       t0, ((0x100 * {height}) / 60)
    sw        t0, VI_Y_SCALE(r1)
}
