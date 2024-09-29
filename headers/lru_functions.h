#ifndef LRU_FUNCTIONS_H
#define LRU_FUNCTIONS_H

#include "cache_lru.h"

unsigned long long collatz_lru(lru_cache *cache, unsigned long long random_num);

void output_lru(lru_cache *cache, unsigned long long n, unsigned long long min,
                unsigned long long max);

#endif