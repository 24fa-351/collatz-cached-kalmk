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
    if (argc != 6)
    {
        printf("Usage: %s <num_of_values> <min> <max> <cache_policy> <cache_size>\n", argv[0]);
        return 1;
    }
    srand(time(NULL));

    unsigned long long num_of_values = atoi(argv[1]);
    unsigned long long min = atoi(argv[2]);
    unsigned long long max = atoi(argv[3]);
    char cache_policy[10];
    strcpy(cache_policy, argv[4]);
    int cache_size = atoi(argv[5]);
    to_lower_case(cache_policy);

    if (strcmp(cache_policy, "none") == 0)
    {
        output_og(num_of_values, min, max);
    }
    else if (strcmp(cache_policy, "lru") == 0)
    {
        lru_cache *cache = lru_cache_init(cache_size);
        output_lru(cache, num_of_values, min, max);
        lru_cache_free(cache);
    }
    else if (strcmp(cache_policy, "fifo") == 0)
    {
        fifo_cache *cache = fifo_cache_init(cache_size);
        output_fifo(cache, num_of_values, min, max);
        fifo_cache_free(cache);
    }

    output_cache_ratio();

    return 0;
}
