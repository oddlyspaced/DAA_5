// Dynamic Fibonacci using Memoization
// Hardik Srivastava
// 199303069
// https://medium.com/geekculture/how-to-solve-fibonacci-sequence-using-dynamic-programming-b7cd784ee10d

#include<stdio.h>

int memo[20];

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main() {
    int i;
    for (i = 0; i < 20; i++) {
        memo[i] = -1;
    }

    for (i = 0; i < 20; i++) {
        printf("%d\n", fib(i));
    }
}