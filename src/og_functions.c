#include "og_functions.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cache_lru.h"

unsigned long long random_number(unsigned long long min, unsigned long long max)
{
    return (rand() % (max - min + 1)) + min;
}

void to_lower_case(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

unsigned long long collatz_og(unsigned long long random_num)
{
    unsigned long long num_of_steps = 0;

    while (random_num > 1)
    {
        if (random_num % 2 == 0)
        {
            random_num = random_num / 2;
        }
        else
        {
            random_num = random_num * 3 + 1;
        }
        ++num_of_steps;
    }

    return num_of_steps;
}

void output_og(unsigned long long n, unsigned long long min,
               unsigned long long max)
{
    for (; n != 0; --n)
    {
        unsigned long long rn = random_number(min, max);
        unsigned long long steps_took = collatz_og(rn);
        printf("number: %llu, steps: %llu\n", rn, steps_took);
    }
}