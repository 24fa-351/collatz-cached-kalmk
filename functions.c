#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long random_number(unsigned long long min,
                                 unsigned long long max) {
    return (rand() % (max - min + 1)) + min;
}

unsigned long long calc_collatz(unsigned long long random_num) {
    unsigned long long num_of_steps = 0;

    while (random_num > 1) {
        if (random_num % 2 == 0) {  // for even numbers
            ++num_of_steps;
            random_num = random_num / 2;
        } else {  // for odd numbers
            ++num_of_steps;
            random_num = random_num * 3 + 1;
        }
    }

    return num_of_steps;
}

void output_csv(unsigned long long n, unsigned long long min,
                unsigned long long max) {
    FILE *file = fopen("result.csv", "w");

    if (file == NULL) printf("Check if file exist.\n");

    fprintf(file, "number,number of steps took\n");

    for (; n != 0; --n) {
        unsigned long long rn = random_number(min, max);
        unsigned long long steps_took = calc_collatz(rn);
        fprintf(file, "%llu,%llu\n", rn, steps_took);
    }

    fclose(file);
}