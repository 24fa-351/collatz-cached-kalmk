#ifndef LRU_FUNCTIONS_H
#define LRU_FUNCTIONS_H

#include "cache_lru.h"

extern unsigned long long global_cache_hits;
extern unsigned long long global_cache_accesses;
extern unsigned long long global_cache_misses;

unsigned long long collatz_lru(lru_cache *object,
                               unsigned long long random_num);

void output_lru(lru_cache *object, unsigned long long n, unsigned long long min,
                unsigned long long max);

#endif