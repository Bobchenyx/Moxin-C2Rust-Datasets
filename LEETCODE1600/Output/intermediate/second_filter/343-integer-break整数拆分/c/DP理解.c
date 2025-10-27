#include <stdlib.h>
#include <stdio.h>
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
int integerBreak(int n){
    int *D = (int *)malloc(sizeof(int) * (n + 1));
    if (D == NULL) {
        return -1;
    }
    memset(D, 0x0, sizeof(D));
    D[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            D[i] = MAX(D[i], MAX(D[j], j) * MAX(D[i - j], i - j));
        }
    }

    int ret = D[n];
    free(D);
    return ret;
}