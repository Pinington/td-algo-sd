#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 10000

int prime_brute(int n) {
    if (n < 2) return 0;
    int primes = 0;
    for (int i = 2; i < n; i++) {
        primes++;
        int square_root = (int)(sqrt(i) + 1.0);
        for(int j = 2; j < square_root; j++) {
            if (i % j == 0) {
                primes--;
                break;
            }
        }
    }
    return primes;
}


int prime_dynamic(int n) {
    int primes_list[n + 1];
    for (int i = 0; i < n + 1; i++) {
        primes_list[i] = 1;
    }
    primes_list[0] = 0;
    primes_list[1] = 0;

    for (int i = 2; i < n + 1; i++) {
        int square = i * i;
        for (int j = square; j < n + 1; j += i) {
            primes_list[j] = 0;
        }
    }

    int total_primes = 0;
    for(int i = 0; i < n + 1; i++) {
        if (primes_list[i]) total_primes++;
    }

    return total_primes;
}


int main() {
    clock_t begin_one = clock();
    int primes_one = prime_brute(N);
    clock_t end_one = clock();

    clock_t begin_two = clock();
    int primes_two = prime_dynamic(N);
    clock_t end_two = clock();

    unsigned long time_one = (end_one -  begin_one) * 1000 / CLOCKS_PER_SEC;
    unsigned long time_two = (end_two -  begin_two) * 1000 / CLOCKS_PER_SEC;

    printf("Fib recursive time: %ld\nFib dynamic time: %ld\n", time_one, time_two);

    return 0;
}



