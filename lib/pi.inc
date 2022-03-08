// n64-playground - Small N64 assembly dev environment.
// Copyright (c) 2022 Cult Of N64

// Parallel Interface specific defines

// Starts PI DMA (ROM->RAM)
macro PI_DMA(dst, src, length) {
    lui       r1, KSEG1 + PI_BASE

    PI_DMA_WAIT:
        // Wait until PI DMA is not busy
        lw        t0, PI_STATUS(r1)
        andi      t0, 3
        bnez      t0, PI_DMA_WAIT
        nop
    
    // Set destination address (in RAM, physical!)
    li        t0, {dst} & 0x7FFFFF
    sw        t0, PI_DRAM_ADDR(r1)

    // Set source address (in ROM)
    li        t0, (CART_BASE << 16) + ({src} & 0x3FFFFFF)
    sw        t0, PI_CART_ADDR(r1)

    // Set length and start PI DMA
    li        t0, {length} - 1
    sw        t0, PI_WR_LEN(r0)
}
