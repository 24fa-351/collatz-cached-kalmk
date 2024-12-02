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
    for (int ix = 0; str[ix] != '\0'; ++ix)
    {
        str[ix] = tolower(str[ix]);
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

void output_og(unsigned long long num_of_values, unsigned long long min,
               unsigned long long max)
{
    printf("number, steps\n");
    for (; num_of_values != 0; --num_of_values)
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