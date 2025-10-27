int *sumZero(int n, int *returnSize)
{
    if (n <= 0) {
        *returnSize = 0;
        return NULL;
    }
    int *res = malloc(n * sizeof(int));
    int total = 0;

    memset(res, 0, n *sizeof(int));
    for (int i = 1; i <= n / 2; i++) {
        res[total++] = i;
        res[total++] = -i;
    }
    if (n % 2) {
        res[total++] = 0;
    }
    *returnSize = total;
    return res;
}