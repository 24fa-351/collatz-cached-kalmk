#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// returns random number from min to max.
unsigned long long random_number(unsigned long long min,
                                 unsigned long long max);

// returns number of steps took to reach 1.
unsigned long long calc_collatz(unsigned long long random_num);

void output_csv(unsigned long long n, unsigned long long min,
                unsigned long long max);

#endif  // FUNCTIONS_H