int climbStairs(int n){
    int *method = (int *)malloc((n + 1) * sizeof(int));
    int i;

    if (n == 0) {
        return 0;
    }
    method[0] = 1;
    method[1] = 1;
    for (i = 2; i <= n; i++) {
        method[i] = method[i - 1] + method[i - 2];
    }
    return method[n];
}