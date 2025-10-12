#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

#define N 40   // Fibonacci test case

int main() {
    clock_t begin_one, begin_two;
    clock_t end_one, end_two;
    double time_one, time_two;

    begin_one = clock();
    long long int fib_one = fibonacci_recursive(N);
    end_one = clock();

    begin_two = clock();
    long long int fib_two = fibonacci_dynamic(N);
    end_two = clock();

    time_one = (double)(end_one -  begin_one) / CLOCKS_PER_SEC;
    time_two = (double)(end_two -  begin_two) / CLOCKS_PER_SEC;

    printf("Fib recursive time: %lf seconds\n ~Result: %lli\nFib dynamic time: %lf seconds\n ~Result: %lli\n",
         time_one, fib_one, time_two, fib_two);

    return 0;
}
