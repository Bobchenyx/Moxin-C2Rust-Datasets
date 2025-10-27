int climbStairs(int n){
    int *plan = NULL;
    int i;

    if (n == 1) {
        return 1;
    }

    plan = (int *)malloc(sizeof(int) * (n + 1));

    plan[1] = 1;
    plan[2] = 2;

    for (i = 3; i <= n; i++) {
        plan[i] = plan[i - 1] + plan[i - 2];
    }
    return plan[n];
}