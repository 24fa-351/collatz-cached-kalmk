#include "fifo_functions.h"
#include "cache_fifo.h"
#include "og_functions.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long collatz_fifo(fifo_cache *object,
                                unsigned long long /*key*/ random_num)
{
    // check if the key is already in the cache
    for (unsigned long long ix = object->front_index; ix != object->rear_index;
         ix = (ix + 1) % object->capacity)
    {
        if (object->cache[ix].key == random_num)
        {
            // printf("Key already in the cache! returning...\n");
            ++global_cache_hits;

            return object->cache[ix].value;
        }
    }
    ++global_cache_misses;

    // if not found, compute
    unsigned long long num_of_steps = collatz_og(random_num);

    // check if cache is full
    if (object->size >= object->capacity)
    {
        pop(object);
    }

    push(object, random_num, num_of_steps);

    return num_of_steps;
}

void output_fifo(fifo_cache *object, unsigned long long num_of_values,
                 unsigned long long min, unsigned long long max)
{
    printf("number, steps\n");
    for (; num_of_values != 0; --num_of_values)
    {
        unsigned long long rn = random_number(min, max);
        unsigned long long steps_took = collatz_fifo(object, rn);
        printf("%llu, %llu\n", rn, steps_took);
    }
}