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

#include "cache_fifo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

fifo_cache *fifo_cache_init(unsigned long long capacity)
{
    fifo_cache *object = malloc(sizeof(fifo_cache));
    object->cache = malloc(capacity * sizeof(node_fifo));

    object->capacity = capacity;
    object->size = 0;
    object->front_index = 0;
    object->rear_index = 0;
    object->is_empty = 1;

    return object;
}

void push(fifo_cache *object, unsigned long long key, unsigned long long value)
{
    // this function used in mind that the size is less than capacity

    object->cache[object->rear_index].key = key;
    object->cache[object->rear_index].value = value;
    // circular increment
    object->rear_index = (object->rear_index + 1) % object->capacity;
    ++object->size;
    // printf("object size inside push: %llu\n", object->size);
    object->is_empty = 0;
}

node_fifo pop(fifo_cache *object)
{
    node_fifo item = object->cache[object->front_index];

    // circular increment
    object->front_index = (object->front_index + 1) % object->capacity;
    --object->size;

    if (object->size == 0)
    {
        object->is_empty = 1;
    }

    return item;
}

void fifo_cache_free(fifo_cache *object)
{
    free(object->cache);
    free(object);
}
