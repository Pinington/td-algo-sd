#include "primes.h"

int prime_brute(int n) {
    if (n < 2) return 0;
    int primes = n - 1; // Assumes all numbers are prime (except 1)
    for (int i = 2; i < n + 1; i++) {
        for(int j = 2; j * j < i + 1; j++) {
            if (i % j == 0) {
                // If a number is found not to be prime, decrements primes
                primes--;
                break;
            }
        }
    }
    return primes;
}


// Could have been a long since O( n*log(log(n)) ) 
int prime_dynamic(int n) {
    int primes_list[n + 1];
    for (int i = 0; i < n + 1; i++) {
        primes_list[i] = 1;
    }
    primes_list[0] = 0;
    primes_list[1] = 0;

    for (int i = 2; i * i < n + 1; i++) { // Breaks loop if i**2 (puissance) is out of the list
        int square = i * i;
        for (int j = square; j < n + 1; j += i) {
            // Sets all multiples of a prime to 0
            primes_list[j] = 0; 
        }
    }

    // Count primes
    int total_primes = 0;
    for(int i = 0; i < n + 1; i++) { 
        // Could have decremented a counter like with brute, but counting makes code clearer and is only O(n)
        if (primes_list[i]) total_primes++; 
    }

    return total_primes;
}

/*  Answer to question 3: Here the complexity is nlog(log) because for each prime number we find, we loop 
    through all it's multiples and set them as non-prime. For each prime p, there are n/p multiples in the
    list, so in total we have n / 2 + n / 3 + ... = sum(n/p) for p < n. sum(1/p) for p < n is bound by 
    log(log(n)), meaning sum(n/p) is bound by n*log(log(n)). That is why the complexity is O( nlog(log(n)) )*/