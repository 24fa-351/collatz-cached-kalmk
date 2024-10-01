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

#include "cache_lru.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lru_cache *lru_cache_init(unsigned long long capacity)
{
    lru_cache *lru_cache_object = malloc(sizeof(lru_cache));

    // object->cache is an "array of nodes" and each node can store key-value
    // pair.
    // example: object->cache[0], object->cache[1] ...
    lru_cache_object->cache = malloc(sizeof(node_lru) * capacity);

    lru_cache_object->capacity = capacity;
    lru_cache_object->size = 0;

    return lru_cache_object;
}

unsigned long long lru_cache_get(lru_cache *object, unsigned long long key)
{
    for (unsigned long long i = 0; i < object->size; ++i)
    {
        // select a node and check its key
        if (object->cache[i].key == key)
        {
            // since found, move the node to the end to mark as most recently
            // used and return the value (shift all elements to the left to
            // remove the node that was found) and then place it in the last
            node_lru found_node = object->cache[i];
            for (unsigned long long j = i; j < object->size - 1; ++j)
            {
                object->cache[j] = object->cache[j + 1];
            }
            object->cache[object->size - 1] = found_node;

            return found_node.value;
        }
    }

    // key not found
    return -1;
}

void lru_cache_put(lru_cache *object, unsigned long long key,
                   unsigned long long value)
{
    // if using this function, it means that the key doesnt exist in the array.
    // if the cache is full, remove the least recently used node (index 0)
    //  (a.k.a shifting all the elements in the array to the left by one) and
    //  then insert the new later
    if (object->size == object->capacity)
    {
        // printf("array is full! changing...\n");
        for (unsigned long long i = 0; i < object->size - 1; ++i)
        {
            object->cache[i] = object->cache[i + 1];
        }
        --object->size;
    }

    // insert the new key-value pair at the end (most recently used)
    object->cache[object->size].key = key;
    object->cache[object->size].value = value;
    ++object->size;
}

void lru_cache_free(lru_cache *object)
{
    free(object->cache);
    free(object);
}