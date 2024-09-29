#include "lru_functions.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cache_lru.h"
#include "og_functions.h"

unsigned long long collatz_lru(lru_cache *cache, unsigned long long random_num)
{
    // check if the random_num is already in the cache
    unsigned long long cached_value = lru_cache_get(cache, /*key*/ random_num);

    if (cached_value != -1)
    {
        printf("already exist! returning...\n");
        return cached_value;
    }

    unsigned long long num_of_steps = collatz_og(random_num);
    lru_cache_put(cache, random_num, num_of_steps);

    return num_of_steps;
}

void output_lru(lru_cache *cache, unsigned long long n, unsigned long long min,
                unsigned long long max)
{
    printf("number, steps\n");
    for (; n != 0; --n)
    {
        unsigned long long rn = random_number(min, max);
        unsigned long long steps_took = collatz_lru(cache, rn);
        printf("%llu, %llu\n", rn, steps_took);
    }
}