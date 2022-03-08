// n64-playground - Small N64 assembly dev environment.
// Copyright (c) 2022 Cult Of N64

// N64 memory related defines

// Memory region bases
constant  RDRAM_BASE = 0
constant  RAMIO_BASE = 0x3F0
constant  SPMEM_BASE = 0x400
constant  SP_BASE    = 0x404
constant  SP_PC_BASE = 0x408
constant  DPC_BASE   = 0x410
constant  DPS_BASE   = 0x420
constant  MI_BASE    = 0x430
constant  VI_BASE    = 0x440
constant  AI_BASE    = 0x450
constant  PI_BASE    = 0x460
constant  RI_BASE    = 0x470
constant  SI_BASE    = 0x480
constant  CART_BASE  = 0x1000
constant  PIF_BASE   = 0x1FC0

// Memory region sizes
constant  RDRAM_SIZE = 0x400000

// RDRAM I/O registers

// SP memory
constant  SP_DMEM = 0
constant  SP_IMEM = 0x1000

// SP I/O registers
constant  SP_MEM_ADDR  = 0
constant  SP_DRAM_ADDR = 0x04
constant  SP_RD_LEN    = 0x08
constant  SP_WR_LEN    = 0x0C
constant  SP_STATUS    = 0x10
constant  SP_DMA_FULL  = 0x14
constant  SP_DMA_BUSY  = 0x18
constant  SP_SEMAPHORE = 0x1C

// SP PC I/O registers
constant  SP_PC    = 0
constant  SP_IBIST = 0x04

// VI I/O registers
constant  VI_STATUS         = 0
constant  VI_ORIGIN         = 0x04
constant  VI_WIDTH          = 0x08
constant  VI_V_INTR         = 0x0C
constant  VI_V_CURRENT_LINE = 0x10
constant  VI_TIMING         = 0x14
constant  VI_V_SYNC         = 0x18
constant  VI_H_SYNC         = 0x1C
constant  VI_H_SYNC_LEAP    = 0x20
constant  VI_H_VIDEO        = 0x24
constant  VI_V_VIDEO        = 0x28
constant  VI_V_BURST        = 0x2C
constant  VI_X_SCALE        = 0x30
constant  VI_Y_SCALE        = 0x34

// PI I/O registers
constant  PI_DRAM_ADDR = 0
constant  PI_CART_ADDR = 0x04
constant  PI_RD_LEN    = 0x08
constant  PI_WR_LEN    = 0x0C
constant  PI_STATUS    = 0x10

// PIF memory
constant  PIF_ROM = 0
constant  PIF_RAM = 0x7C0
