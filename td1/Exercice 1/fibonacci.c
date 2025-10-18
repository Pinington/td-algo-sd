#include "fibonacci.h"
#include <math.h> // For matrix version

long long int fibonacci_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}


long long int fibonacci_dynamic(int n) {
    if (n < 2) return 1;

    long long int u0 = 0, u1 = 1;
    for (int i = 2; i < n + 1; i++) {
        u1 = u0 + u1; // Un = Un-1 + Un-2
        u0 = u1 - u0; // Un-2 = Un-1
    }

    return u1;
}


long long int fibonacci_matrix(int n) {
    // Eigenvalues
    const double sqrt5 = sqrt(5.0);
    const double phi = (1.0 + sqrt5) / 2.0;
    const double psi = (1.0 - sqrt5) / 2.0;

    // After diagonalizing and applying the formula
    double result = (pow(phi, n) - pow(psi, n)) / sqrt5;

    return (long long)llround(result); // ChatGPT said it's one off after Fib(70) because of rouding in pow
}

