#ifndef CACHE_LRU_H
#define CACHE_LRU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    unsigned long long key;
    unsigned long long value;
} Node;

typedef struct lru_cache
{
    Node *cache;
    unsigned long long capacity;
    unsigned long long size;
} lru_cache;

lru_cache *lru_cache_init(unsigned long long capacity);
unsigned long long lru_cache_get(lru_cache *object, unsigned long long key);
void lru_cache_put(lru_cache *object, unsigned long long key,
                   unsigned long long value);
void lru_cache_free(lru_cache *object);

#endif