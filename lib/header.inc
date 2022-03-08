// n64-playground - Small N64 assembly dev environment.
// Copyright (c) 2022 Cult Of N64

// N64 ROM header
// Values taken from https://github.com/PeterLemon/N64/blob/master/LIB/N64_HEADER.ASM

// Initial PI_BSD_DOM1 value
dw        0x80371240

// Initial clock rate
dw        0xF

// Entry point
dw        Entry
dw        0x1444

// Checksums
db        "CRC1"
db        "CRC2"

// Program name (27 characters)
db        "N64 PLAYGROUND             "

// Developer ID
db        0

// Cartridge ID
db        0

// Unused
db        0

// Region ID
db        0

// Unused
db        0
