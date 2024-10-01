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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cache_fifo.h"
#include "cache_lru.h"
#include "fifo_functions.h"
#include "lru_functions.h"
#include "og_functions.h"

unsigned long long global_cache_hits;
unsigned long long global_cache_accesses;
unsigned long long global_cache_misses;

int main(int argc, char *argv[])
{
    srand(time(NULL));

    unsigned long long n = atoi(argv[1]);
    unsigned long long min = atoi(argv[2]);
    unsigned long long max = atoi(argv[3]);
    char cache_policy[10];
    strcpy(cache_policy, argv[4]);
    int cache_size = atoi(argv[5]);
    to_lower_case(cache_policy);

    if (strcmp(cache_policy, "none") == 0)
    {
        output_og(n, min, max);
    }
    else if (strcmp(cache_policy, "lru") == 0)
    {
        lru_cache *cache = lru_cache_init(cache_size);
        output_lru(cache, n, min, max);
        lru_cache_free(cache);
    }
    else if (strcmp(cache_policy, "fifo") == 0)
    {
        fifo_cache *cache = fifo_cache_init(cache_size);
        output_fifo(cache, n, min, max);
        fifo_cache_free(cache);
    }

    output_cache_ratio();

    return 0;
}
