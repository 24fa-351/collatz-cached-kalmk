#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

int main(int argc, char *argv[]) {
    unsigned long long n = atoi(argv[1]);    // n is number of values to test
    unsigned long long min = atoi(argv[2]);  // min is smallest value to test
    unsigned long long max = atoi(argv[3]);  // max is largest value to test

    srand(time(NULL));

    output_csv(n, min, max);

    return 0;
}
