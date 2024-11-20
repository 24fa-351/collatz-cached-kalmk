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