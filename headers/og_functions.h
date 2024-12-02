#ifndef OG_FUNCTIONS_H
#define OG_FUNCTIONS_H

extern unsigned long long global_cache_hits;
extern unsigned long long global_cache_accesses;
extern unsigned long long global_cache_misses;

unsigned long long random_number(unsigned long long min,
                                 unsigned long long max);

void to_lower_case(char *str);

unsigned long long collatz_og(unsigned long long random_num);

void output_og(unsigned long long num_of_values, unsigned long long min,
               unsigned long long max);

void output_cache_ratio();

#endif