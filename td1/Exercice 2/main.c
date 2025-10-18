#include <stdio.h>
#include <time.h>
#include "primes.h"

#define n 40000  // Primes test case 

int main() {
    clock_t begin, end;
    double time_one, time_two;

    // Brute Force
    begin = clock();
    int primes_one = prime_brute(n);
    end = clock();

    time_one = (double)(end -  begin) / CLOCKS_PER_SEC;

    printf("Primes recursive time: %lf seconds\n ~Result: %i\n", time_one, primes_one);

    // Dynamic Programming
    begin = clock();
    int primes_two = prime_dynamic(n);
    end = clock();

    time_two = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Primes dynamic time: %lf seconds\n ~Result: %i\n", time_two, primes_two);

    return 0;
}
