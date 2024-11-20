#ifndef CACHE_FIFO_H
#define CACHE_FIFO_H

extern unsigned long long global_cache_hits;
extern unsigned long long global_cache_accesses;
extern unsigned long long global_cache_misses;

typedef struct node_fifo
{
    unsigned long long key;
    unsigned long long value;
} node_fifo;

typedef struct fifo_cache
{
    node_fifo *cache;
    unsigned long long capacity;
    unsigned long long size;
    unsigned long long front_index;
    unsigned long long rear_index;
    int is_empty;
} fifo_cache;

fifo_cache *fifo_cache_init(unsigned long long capacity);

void push(fifo_cache *object, unsigned long long key, unsigned long long value);

node_fifo pop(fifo_cache *object);

void fifo_cache_free(fifo_cache *object);

#endif