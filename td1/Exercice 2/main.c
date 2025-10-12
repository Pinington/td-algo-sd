#include <stdio.h>
#include <time.h>
#include "primes.h"

#define n 40000  // Primes test case 

int main() {
    clock_t begin_one, begin_two;
    clock_t end_one, end_two;
    double time_one, time_two;

    begin_one = clock();
    int primes_one = prime_brute(n);
    end_one = clock();

    begin_two = clock();
    int primes_two = prime_dynamic(n);
    end_two = clock();

    time_one = (double)(end_one -  begin_one) / CLOCKS_PER_SEC;
    time_two = (double)(end_two -  begin_two) / CLOCKS_PER_SEC;

    printf("Primes recursive time: %lf seconds\n ~Result: %i\nPrimes dynamic time: %lf seconds\n ~Result: %i\n", time_one, primes_one, time_two, primes_two);

    return 0;
}
