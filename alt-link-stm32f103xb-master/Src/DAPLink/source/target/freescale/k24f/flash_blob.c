/**
 * @file    flash_blob.c
 * @brief   Flash algorithm for the k24f
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "flash_blob.h"

const uint32_t K24F256_FLM[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0xb510482d, 0x5120f24c, 0xf64d81c1, 0x81c11128, 0xf0218801, 0x80010101, 0x44484828, 0xf8a4f000,
    0xd0002800, 0xbd102001, 0x47702000, 0xb5104823, 0x44484923, 0xf884f000, 0x4820b920, 0x44482100,
    0xf94cf000, 0x684a491f, 0x0270f442, 0xbd10604a, 0x4604b510, 0x48194601, 0x22014b19, 0xf0004448,
    0xb930f833, 0x23004815, 0x46212201, 0xf0004448, 0x4914f8fd, 0xf442684a, 0x604a0270, 0xb5febd10,
    0x460b460c, 0x46014606, 0x4615480c, 0xf0004448, 0xb958f8bb, 0x21012000, 0x1000e9cd, 0x48079002,
    0x4622462b, 0x44484631, 0xf924f000, 0x684a4905, 0x0270f442, 0xbdfe604a, 0x40052000, 0x00000004,
    0x6b65666b, 0x4001f000, 0x4df0e92d, 0x46164607, 0x4618460c, 0xf881f000, 0xd1282800, 0x46322310,
    0x46384621, 0xf861f000, 0xd1200005, 0x68f84426, 0xfbb61e76, 0xfb00f1f0, 0xb1126211, 0x43481c49,
    0xf8df1e46, 0x44f88034, 0xb030f8df, 0x0a09f04f, 0xd80b42b4, 0x0000f8d8, 0xf88b6004, 0xf000a007,
    0x4605f921, 0xb10069b8, 0xb1154780, 0xe8bd4628, 0x68f88df0, 0xe7eb4404, 0x000002e6, 0x40020000,
    0x4604b510, 0xf0004608, 0x2800f848, 0xb134d108, 0x20444904, 0xe8bd71c8, 0xf0004010, 0x2004b903,
    0x0000bd10, 0x40020000, 0x4924b1a8, 0x4a246cc9, 0x6103f3c1, 0xf832447a, 0x03091011, 0x2200d00d,
    0x2100e9c0, 0x60812101, 0xe9c00309, 0x61421203, 0x46106182, 0x20044770, 0x20644770, 0xb1104770,
    0x20006181, 0x20044770, 0xb5104770, 0x1e5bb118, 0xd1044219, 0x2004e001, 0x421abd10, 0x2065d001,
    0x6803bd10, 0xd804428b, 0x44116840, 0x42884418, 0x2066d201, 0x2000bd10, 0x490abd10, 0xd0014288,
    0x4770206b, 0x47702000, 0x290fb118, 0x2a04d801, 0x2004d001, 0x20004770, 0x00004770, 0x40048000,
    0x00000258, 0x6b65666b, 0x4df0e92d, 0x0015461e, 0x4680460f, 0x2304d020, 0xf7ff4632, 0x0004ffc6,
    0xf8dfd118, 0x44faa040, 0x0b06f04f, 0xf8dab18e, 0x600f1000, 0x0000f8da, 0x6041cd02, 0xf881490a,
    0xf000b007, 0x4604f88f, 0x0018f8d8, 0x4780b100, 0x4620b124, 0x8df0e8bd, 0xe7fb2004, 0x1f361d3f,
    0x0000e7e4, 0x000001c6, 0x40020000, 0x47f0e92d, 0x4615469a, 0x4604460f, 0xf7ff2310, 0x2800ff96,
    0xe9d4d125, 0xfbb00101, 0x4279f8f1, 0x0000f1c8, 0x424e4001, 0xd10042be, 0xb1bd4446, 0x42ac1bf4,
    0x462cd900, 0x0920490b, 0x68094479, 0x490a600f, 0x71ca2201, 0x72ca0a02, 0xf8817288, 0xf000a009,
    0x2800f851, 0x1b2dd103, 0xe7e54427, 0xe8bd2000, 0x000087f0, 0x00000144, 0x40020000, 0x4804b128,
    0x71c22240, 0xf0007181, 0x2004b83d, 0x00004770, 0x40020000, 0x4df0e92d, 0xe9dd001c, 0xf8dd8709,
    0x4616a020, 0xd023460d, 0xf7ff2304, 0x2800ff4e, 0xf8dfd11c, 0x44fbb048, 0xd0172e00, 0x0000f8db,
    0x480f6005, 0x71c12102, 0xa00bf880, 0x1000f8db, 0x60886820, 0xf816f000, 0xf1b8b160, 0xd0010f00,
    0x5000f8c8, 0xd0012f00, 0x60392100, 0x8df0e8bd, 0xe7fb2004, 0x1d241f36, 0xe7dd1d2d, 0x000000d6,
    0x40020000, 0x2170480a, 0x21807001, 0x78017001, 0xd5fc0609, 0x06817800, 0x2067d501, 0x06c14770,
    0x2068d501, 0x07c04770, 0x2069d0fc, 0x00004770, 0x40020000, 0xb13ab140, 0xd2172908, 0xf001e8df,
    0x0c0a0a06, 0x1412100e, 0x47702004, 0x601068c0, 0x47702000, 0xe7fa6840, 0xe7f86880, 0xe7f66800,
    0xe7f42000, 0xe7f26900, 0xe7f06940, 0x4770206a, 0x00000000, 0x00080000, 0x00100000, 0x00200000,
    0x00400000, 0x00800000, 0x01000000, 0x01000000, 0x40020004, 0x00000000,
};

static const program_target_t flash = {
    0x20000021, // Init
    0x20000049, // UnInit
    0x2000004D, // EraseChip
    0x20000071, // EraseSector
    0x2000009F, // ProgramPage

    // breakpoint = RAM start + 1
    // RSB : base address is address of Execution Region PrgData in map file
    //       to access global/static data
    // RSP : Initial stack pointer
    {
        0x20000001, // breakpoint instruction address
        0x20000000 + 0x20 + 0x3f4,  // static base register value (image start + header + static base offset)
        0x20000800  // initial stack pointer
    },

    0x20001000, // program_buffer, any valid RAM location with +512 bytes of headroom
    0x20000000, // algo_start, start of RAM
    sizeof(K24F256_FLM), // algo_size, size of array above
    K24F256_FLM,  // image, flash algo instruction array
    512        // ram_to_flash_bytes_to_be_written
};
