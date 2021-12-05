// Binomial Coefficient
// Hardik Srivatava
// 199303069

#include <stdio.h>

// C(n, k) = C(n-1, k-1) + C(n-1, k)
// C(n, 0) = C(n, n) = 1
int coeff(int n, int k) {
    // Base Cases
    if (k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    return coeff(n - 1, k - 1) + coeff(n - 1, k);
}

int main() {
    printf("Enter values of n and k: ");
    int n, k;
    scanf("%d %d", &n, &k);
    printf("C(%d, %d) is %d ", n, k, coeff(n, k));
    return 0;
}