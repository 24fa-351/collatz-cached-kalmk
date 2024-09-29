#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cache_lru.h"
#include "lru_functions.h"
#include "og_functions.h"

// TODO:
//
// 1) implement FIFO.
//
// 2) report cache hit % for both cache types.

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
        // FIFO here
    }

    return 0;
}