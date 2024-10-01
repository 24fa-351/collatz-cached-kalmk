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

#ifndef CACHE_LRU_H
#define CACHE_LRU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern unsigned long long global_cache_hits;
extern unsigned long long global_cache_accesses;
extern unsigned long long global_cache_misses;

typedef struct node_lru
{
    unsigned long long key;
    unsigned long long value;
} node_lru;

typedef struct lru_cache
{
    node_lru *cache;
    unsigned long long capacity;
    unsigned long long size;
} lru_cache;

lru_cache *lru_cache_init(unsigned long long capacity);

unsigned long long lru_cache_get(lru_cache *object, unsigned long long key);

void lru_cache_put(lru_cache *object, unsigned long long key,
                   unsigned long long value);

void lru_cache_free(lru_cache *object);

#endif