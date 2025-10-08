#include <stdio.h>
#include <time.h>

#define N 40

long long int fibonacci_recursive(int n) {
    if (n == 0 || n == 1) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}


long long int fibonacci_dynamic(int n) {
    if (n < 2) return 1;

    int u0 = 1, u1 = 1;
    int result = 1;
    for (int i = 2; i < n; i++) {
        result = u0 + u1;
        u0 = u1;
        u1 = result;
    }

    return result;
}


int main() {
    clock_t begin_one = clock();
    long long int fib_one = fibonacci_recursive(N);
    clock_t end_one = clock();

    clock_t begin_two = clock();
    long long int fib_two = fibonacci_dynamic(N);
    clock_t end_two = clock();

    unsigned long time_one = (end_one -  begin_one) * 1000 / CLOCKS_PER_SEC;
    unsigned long time_two = (end_two -  begin_two) * 1000 / CLOCKS_PER_SEC;

    printf("Fib recursive time: %ld\nFib dynamic time: %ld\n", time_one, time_two);

    return 0;
}
