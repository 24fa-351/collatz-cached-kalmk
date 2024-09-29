// Copyright (C) 2024 Ju Yeong Kim
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License version 3 as published by the
// Free Software Foundation. This program is distributed in the hope that it
// will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
// Public License for more details. A copy of the GNU General Public License v3
// is available here:  <https://www.gnu.org/licenses/>.
//
//=================================================================================================
// Name:
//     Ju Yeong Kim
//
//
// Course ID:
//     CPSC 351
//
//
// Name of the program:
//     Collatz-Cached
//
//
// OS of the computer where the program was developed:
//     Ubuntu 22.04 WSL
//
//
// OS of the computer where the program was tested:
//     Ubuntu 22.04 WSL
//=================================================================================================
//
//
//
//=======Begin code area

#ifndef FIFO_FUNCTIONS_H
#define FIFO_FUNCTIONS_H

#include "cache_fifo.h"

extern unsigned long long global_cache_hits;
extern unsigned long long global_cache_accesses;
extern unsigned long long global_cache_misses;

unsigned long long collatz_fifo(fifo_cache *cache,
                                unsigned long long random_num);

void output_fifo(fifo_cache *object, unsigned long long n,
                 unsigned long long min, unsigned long long max);

#endif