#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

#define N 40  // Fibonacci test case

int main() {
    clock_t begin, end;
    double time_one, time_two, time_three;

    // Recursive
    begin = clock();
    long long int fib_one = fibonacci_recursive(N);
    end = clock();

    time_one = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Fib recursive time: %lf seconds\n ~Result: %lli\n", time_one, fib_one);

    // Dynamic
    begin = clock();
    long long int fib_two = fibonacci_dynamic(N);
    end = clock();

    time_two = (double)(end -  begin) / CLOCKS_PER_SEC;

    printf("Fib dynamic time: %lf seconds\n ~Result: %lli\n", time_two, fib_two);

    // Diagonalization
    begin = clock();
    long long int fib_three = fibonacci_matrix(N);
    end = clock();

    time_three = (double)(end -  begin) / CLOCKS_PER_SEC;

        // Slower because N isn't big enough
    printf("Fib matrix time: %lf seconds\n ~Result: %lli\n", time_three, fib_three); 

    return 0;
}
