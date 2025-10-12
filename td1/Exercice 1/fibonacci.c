#include "fibonacci.h"

long long int fibonacci_recursive(int n) {
    if (n == 0 || n == 1) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}


long long int fibonacci_dynamic(int n) {
    if (n < 2) return 1;

    long long int u0 = 1, u1 = 1;
    for (int i = 2; i < n + 1; i++) {
        u1 = u1 + u0; // Un = Un-1 + Un-2
        u0 = u1 - u0; // Un-2 = Un-1
    }

    return u1;
}
