int lastRemaining(int n, int m) {
    int i;
    int *flag = malloc((n + 1) * sizeof(int));

    flag[1] = 0;
    for (i = 2; i <= n; i++)
        flag[i] = (flag[i -1] + m)%i;

    return flag[n];
}