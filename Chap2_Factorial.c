#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n = 10;
    unsigned long long result = factorial(n);
    printf("Factorial of %d is %llu\n", n, result);
    return 0;
}
