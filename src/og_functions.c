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

#include "og_functions.h"
#include "cache_lru.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long random_number(unsigned long long min, unsigned long long max)
{
    return (rand() % (max - min + 1)) + min;
}

void to_lower_case(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        str[i] = tolower(str[i]);
    }
}

unsigned long long collatz_og(unsigned long long random_num)
{
    unsigned long long num_of_steps = 0;

    while (random_num > 1)
    {
        if (random_num % 2 == 0)
        {
            random_num = random_num / 2;
        }
        else
        {
            random_num = random_num * 3 + 1;
        }
        ++num_of_steps;
    }

    return num_of_steps;
}

void output_og(unsigned long long n, unsigned long long min,
               unsigned long long max)
{
    printf("number, steps\n");
    for (; n != 0; --n)
    {
        unsigned long long rn = random_number(min, max);
        unsigned long long steps_took = collatz_og(rn);
        printf("%llu, %llu\n", rn, steps_took);
    }
}

void output_cache_ratio()
{
    double cache_hit_ratio =
        ((double)global_cache_hits / (global_cache_hits + global_cache_misses));

    printf("\nTotal cache hits: %llu\n", global_cache_hits);
    printf("cache hit ratio: %lf\n", cache_hit_ratio);
    printf("CACHE HIT RATIO: %.0lf%%\n", cache_hit_ratio * 100);
}